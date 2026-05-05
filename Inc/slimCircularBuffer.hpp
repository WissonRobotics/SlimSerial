/**
 * @brief this is a simplified version of kfifo from linux kernal
 * 1. the storage should always be 2^n bytes. Here we statically make it 512 bytes
 */

#ifndef SLIM_CURCULAR_BUFFER_H_
#define SLIM_CURCULAR_BUFFER_H_

#pragma once

#include "main.h"
#include <stdint.h>
#include <string.h>
#include "stdio.h"
#include "slimCRC.h"


//concepts to restrict the template type to uint8_t or uint16_t
#include <concepts>

template<typename T>
concept IsUint8OrUint16 = std::is_same_v<T, uint8_t> || std::is_same_v<T, uint16_t>;


// C++ version
class SLIM_CURCULAR_BUFFER {

public:
	SLIM_CURCULAR_BUFFER(uint8_t *pBuf, uint16_t bufzise,uint8_t u16Mode) {
		init(pBuf, bufzise, u16Mode);
	}



	void init(uint8_t *pBuf, uint16_t bufzise,uint8_t u16Mode){
		if(pBuf){
			if (!is_power_of_2(bufzise)) {
				bufzise = shrinkTo_power_of_2(bufzise);
			}
			buffer = (uint8_t *)pBuf;
			bufferU16 = (uint16_t *)pBuf;
			bufferSize = bufzise;
			mask = bufferSize - 1;
		}
		else{
			buffer = 0;
			bufferU16 = 0;
			bufferSize = 0;
			mask = 0;
		}
		head = 0;
		tail = 0;
		setU16Mode(u16Mode);
	}

	/**
	 * @brief set the buffer to use uint16_t mode
	 * in this mode, the buffer will be treated as an array of uint16_t
	 */
	void setU16Mode(uint8_t u16Mode){
		m_U16_mode = u16Mode;
	}

	void clear() {
		head = 0;
		tail = 0;
	}

	uint32_t availableData() const {
		return (head - tail);
	}

	// Lossy write path. Prefer tryIn/tryInDummy for strict producer/consumer usage.
	template<typename  T>
	requires IsUint8OrUint16<T>
	uint32_t in(const T* pSrc, uint32_t len) {
		return writeLossy(pSrc, len);
	}

	template<typename  T>
	requires IsUint8OrUint16<T>
	uint32_t writeLossy(const T* pSrc, uint32_t len) {
		uint32_t ltemp = unusedSpace();


		copy_in( pSrc, len, head);
		head += len;

		uint32_t loverflow = (len > ltemp) ? len - ltemp : 0;
		tail += loverflow;

		return len;
	}


	uint32_t in_dummy(uint32_t len) {
		return advanceWriteLossy(len);
	}

	uint32_t advanceWriteLossy(uint32_t len) {
		uint32_t ltemp = unusedSpace();

		head += len;

		uint32_t loverflow = (len > ltemp) ? len - ltemp : 0;
		tail += loverflow;

		return len;
	}

	template<typename  T>
	requires IsUint8OrUint16<T>
	bool tryIn(const T* pSrc, uint32_t len) {
		if (len > unusedSpace()) {
			return false;
		}

		copy_in(pSrc, len, head);
		head += len;
		return true;
	}

	bool tryInDummy(uint32_t len) {
		if (len > unusedSpace()) {
			return false;
		}

		head += len;
		return true;
	}

	uint32_t syncExternalWriteHeadMaskedLossy(uint32_t inNewHeadMasked) {
		uint32_t lastHeadMasked = head & mask;

		//determine new arrived data len
		uint32_t len=0;

		//if the new head is larger than the last head, no wrap around
		if(inNewHeadMasked>=lastHeadMasked){
			//no wrap around
			len =  inNewHeadMasked - lastHeadMasked;
		}
		else{
			len = (bufferSize - lastHeadMasked) + inNewHeadMasked;
		}


		uint32_t lavail = availableData();
		uint32_t ltemp = unusedSpace();

		//if overflow,hardcode the buffer head and tail
		if (len >= ltemp) {
			head = inNewHeadMasked;
			tail =  head-bufferSize;
        }
		else{

			uint32_t newHeadMasked = (head+len) & mask;
			if (newHeadMasked != inNewHeadMasked) {
				//if the new head does not match the current head, we better discard certain reinitialize the buffer
				head = inNewHeadMasked;
				tail = head - len - lavail;

			}
			else{//normal case, just update the head and tail
				head += len;

				uint32_t loverflow = (len > ltemp) ? len - ltemp : 0;
				tail += loverflow;
			}
		}

		return len;
	}



	template<typename  T>
	requires IsUint8OrUint16<T>
	uint32_t out(T* pDes, uint32_t len) {
		uint32_t peekedLen = peek(pDes, len);
		tail += peekedLen;

		return peekedLen;
	}

	template<typename  T>
	requires IsUint8OrUint16<T>
	uint32_t peek(T* pDes, uint32_t len) {
		uint32_t ltemp;

		ltemp = availableData();

		len = (len > ltemp) ? ltemp : len;

        copy_out( pDes, len, tail);

		return len;
	}


	//always return U8. if in U16 mode, only the lower byte is returned
	inline uint8_t peekAt(uint32_t index) {
		if (m_U16_mode) {
            return (uint8_t)(bufferU16[(tail + index) & mask] & 0xFF);
        }
		else{
			return buffer[(tail + index) & mask];
		}
	}

	//always return U8. if in U16 mode, only the lower byte is returned
	inline uint8_t peekAt_HB(uint32_t index) {
		if (m_U16_mode) {
            return (uint8_t)(bufferU16[(tail + index) & mask]>>8 & 0xFF);
        }
		else{
			return buffer[(tail + index) & mask];
		}
	}

	//compare U8. if in U16 mode, only the lower byte is compared
	uint32_t discardUntilNext(uint8_t targetChar)
	{
		int remainingElementNum = availableData();

		for (int i = 0; i < remainingElementNum; i++) {
			if (targetChar == peekAt(i)) {
				if (i == 0)//ignore the current char
					continue;
				discardN(i);
				return (i);
			}
		}
		discardN(remainingElementNum);
		return remainingElementNum;
	}

	uint32_t discardN(uint32_t len)
	{
		if (len == 0) {
			return 0;
		}

		uint32_t ltemp;

		ltemp = availableData();

		len = (len > ltemp) ? ltemp : len;

		tail += len;

		return len;
	}

	inline uint32_t unusedSpace() const {
		return (uint32_t)(bufferSize - (head - tail));
	}

	inline uint32_t isEmpty() const {
		return (uint32_t)(head == tail);
	}

	inline uint32_t isFull() const {
		return ((head - tail) > mask);
	}

	inline uint32_t unusedContinuousSpace() const {
		uint32_t off = head & mask;
		uint32_t contiguousToEnd = (uint32_t)(bufferSize - off);
		uint32_t freeBytes = unusedSpace();

		return (contiguousToEnd < freeBytes) ? contiguousToEnd : freeBytes;
	}

	inline bool isU16Mode() const {
		return m_U16_mode != 0u;
	}

	inline uint8_t *data() {
		return buffer;
	}

	inline const uint8_t *data() const {
		return buffer;
	}

	inline uint32_t capacity() const {
		return bufferSize;
	}

	inline uint32_t writeIndexMasked() const {
		return head & mask;
	}


	//calculate CRC16 for the data [tail, tail+dataSize].
	uint16_t calculateCRC(uint32_t datasize) {
		//in U16 mode, only the lower byte is used for CRC calculation
		uint16_t crc=0xFFFF;
		int j=0;
		while (datasize--)
			crc = crc16_table[(crc ^ peekAt(j++)) & 0xFF] ^ (crc >> 8);

		return crc;

	}

	//calculate CRC16 for the data [maskedStart, maskedStart+dataSize].
//	uint16_t calculateCRC(uint32_t maskedStart,uint32_t datasize) {
//
//		uint16_t crc=0xFFFF;
//		int j=0;
//		while (datasize--)
//			crc = crc16_table[(crc ^ peekAt(j++)) & 0xFF] ^ (crc >> 8);
//
//		return crc;
//
//	}

	/**
	 * slim_memcpy will copy
	 * - uint8_t to uint8_t
	 * - uint16_t to uint16_t
	 * - uint8_t to uint16_t
	 * - uint16_t to uint8_t (only the lower byte is copied)
	 */
	template<typename  T1,typename  T2>
	requires (IsUint8OrUint16<T1> && IsUint8OrUint16<T2>)
	static void slim_memcpy(T1 *des, const T2 *src, size_t len){
         if constexpr (std::is_same_v<T1, uint8_t> && std::is_same_v<T2, uint16_t>) {
        	 for(size_t i=0;i<len;i++){
			   des[i] = (uint8_t)(src[i] & 0xFF);
			 }
         }
         else{
        	 /**
        	  * suit all other cases, including uint8_t to uint8_t, uint16_t to uint16_t, uint8_t to uint16_t
        	  */
        	 for(size_t i=0;i<len;i++){
			   des[i] = src[i];
			  }
              return;
         }
    }

	inline uint8_t *getHeadMasked() {
        return m_U16_mode?(uint8_t *)((bufferU16 + (head & mask))):(uint8_t *)((buffer + (head & mask)));
    }

	inline uint8_t *getTailMasked() {
        return m_U16_mode?(uint8_t *)((bufferU16 + (tail & mask))):(uint8_t *)((buffer + (tail & mask)));
    }

	bool containsPointer(const uint8_t* ptr) const {
		if (ptr == nullptr || buffer == nullptr) {
			return false;
		}

		const uintptr_t start = reinterpret_cast<uintptr_t>(buffer);
		const uintptr_t span = static_cast<uintptr_t>(bufferSize) * (m_U16_mode ? sizeof(uint16_t) : sizeof(uint8_t));
		const uintptr_t end = start + span;
		const uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
		return value >= start && value < end;
	}

	uint32_t distanceFromTail(const uint8_t* ptr) const {
		if (!containsPointer(ptr)) {
			return 0;
		}

		const uint32_t tailIndex = tail & mask;
		if (m_U16_mode) {
			const uintptr_t start = reinterpret_cast<uintptr_t>(bufferU16);
			const uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
			const uint32_t ptrIndex = static_cast<uint32_t>((value - start) / sizeof(uint16_t));
			return (ptrIndex >= tailIndex) ? (ptrIndex - tailIndex) : (bufferSize - tailIndex + ptrIndex);
		}

		const uintptr_t start = reinterpret_cast<uintptr_t>(buffer);
		const uintptr_t value = reinterpret_cast<uintptr_t>(ptr);
		const uint32_t ptrIndex = static_cast<uint32_t>(value - start);
		return (ptrIndex >= tailIndex) ? (ptrIndex - tailIndex) : (bufferSize - tailIndex + ptrIndex);
	}
private:
	uint8_t		*buffer;
	uint16_t	*bufferU16;
	uint32_t	bufferSize;
	uint8_t     m_U16_mode=0;



	uint32_t	mask;
	uint32_t	head;
	uint32_t	tail;


	template<typename  T>
	requires IsUint8OrUint16<T>
	void copy_in(const T* pSrc, uint32_t len, uint32_t off)
	{

		uint32_t ltemp;

		off &= mask;

		uint32_t tm = bufferSize - off;

		ltemp = len < tm ? len : tm;

		if (m_U16_mode) {
            slim_memcpy(bufferU16 + off, pSrc, ltemp);
            slim_memcpy(bufferU16, pSrc + ltemp, len - ltemp);
            return;
        }
		else{
            slim_memcpy(buffer + off, pSrc, ltemp);
            slim_memcpy(buffer, pSrc + ltemp, len - ltemp);
		}

	}

	template<typename  T>
	requires (IsUint8OrUint16<T>)
	void copy_out(T* pDes, uint32_t len, uint32_t off)
	{
		uint32_t ltemp;

		off &= mask;

		uint32_t tm = bufferSize - off;

		ltemp = len < tm ? len : tm;

		if (m_U16_mode) {
            slim_memcpy(pDes, bufferU16 + off, ltemp);
            slim_memcpy(pDes + ltemp, bufferU16, len - ltemp);
            return;
        }
		else{
			slim_memcpy(pDes, buffer + off, ltemp);
			slim_memcpy(pDes + ltemp, buffer, len - ltemp);
		}
	}


	uint8_t is_power_of_2(unsigned long n)
	{
		return (n != 0 && ((n & (n - 1)) == 0));
	}

	uint16_t shrinkTo_power_of_2(unsigned long n)
	{
		for(int i=15;i>=0;i--){
			uint16_t ntemp = n & (1<<i);
			if(ntemp){
				return ntemp;
			}
		}
		return 0;
	}


};


#endif /* SLIM_CURCULAR_BUFFER_H_ */
