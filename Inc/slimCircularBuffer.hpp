/**
 * @brief this is a simplified version of kfifo from linux kernal
 * 1. the storage should always be 2^n bytes. Here we statically make it 512 bytes
 */

#ifndef SLIM_CURCULAR_BUFFER_H_
#define SLIM_CURCULAR_BUFFER_H_

#pragma once

#include "main.h"
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
		setU16Mdoe(u16Mode);
	}

	/**
	 * @brief set the buffer to use uint16_t mode
	 * in this mode, the buffer will be treated as an array of uint16_t
	 */
	void setU16Mdoe(uint8_t u16Mode){
		m_U16_Mode = u16Mode;
	}

	void clear() {
		head = 0;
		tail = 0;
	}
 

	uint32_t availableData() {
		return (uint32_t)(head - tail);
	}

	//enable overflow wrap
	template<typename  T>
	requires IsUint8OrUint16<T>
	uint32_t in(const T* pSrc, uint32_t len) {
		uint32_t ltemp = unusedSpace();


		copy_in( pSrc, len, head);
		head += len;

		uint32_t loverflow = (len > ltemp) ? len - ltemp : 0;
		tail += loverflow;

		return len;
	}


	uint32_t in_dummyU16_with_new_head(uint32_t inNewHeadMasked) {
		uint32_t lastHeadMasked = head & mask;

		//determine new arrived data len
		uint32_t len=0;

		//If two interrupts are triggered together, IDLE line and DMA_IT_TC callback. we ignore one.
		if(inNewHeadMasked==0 && lastHeadMasked==0){
            return 0;
        }

        //if the new head is larger than the last head, no wrap around
		if(inNewHeadMasked>lastHeadMasked){
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

		//discard the data if the 9th bit address byte if set
		if(m_U16_Mode && ((bufferU16[tail & mask]>>8) & 0x01)==1){
			tail++;
			len--;
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
		if (m_U16_Mode) {
            return (uint8_t)(bufferU16[(tail + index) & mask] & 0xFF);
        }
		else{
			return buffer[(tail + index) & mask];
		}
	}

	//always return U8. if in U16 mode, only the lower byte is returned
	inline uint8_t peekAt_HB(uint32_t index) {
		if (m_U16_Mode) {
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

	inline uint32_t unusedSpace() {
		return (uint32_t)(bufferSize - (head - tail));
	}

	inline uint32_t isEmpty() {
		return (uint32_t)(head == tail);
	}

	inline uint32_t isFull() {
		return ((head - tail) > mask);
	}

	uint32_t unusedContinuousSpace() {
		uint32_t off = tail & mask;

		return (uint32_t)(bufferSize - off);
	}


	//in U16 mode, only the lower byte is used for CRC calculation
	uint16_t calculateCRC(uint32_t datasize) {

		uint16_t crc=0xFFFF;
		int j=0;
		while (datasize--)
			crc = crc16_table[(crc ^ peekAt(j++)) & 0xFF] ^ (crc >> 8);

		return crc;

	}

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

	uint8_t		*buffer;
	uint16_t	*bufferU16;
	uint32_t	bufferSize;
	uint8_t     m_U16_Mode=0;

private:

	uint32_t	head;
	uint32_t	tail;
	
	uint32_t	mask;

	template<typename  T>
	requires IsUint8OrUint16<T>
	void copy_in(const T* pSrc, uint32_t len, uint32_t off)
	{

		uint32_t ltemp;

		off &= mask;

		uint32_t tm = bufferSize - off;

		ltemp = len < tm ? len : tm;

		if (m_U16_Mode) {
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

		if (m_U16_Mode) {
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
