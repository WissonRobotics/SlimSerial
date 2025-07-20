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


// C++ version
class SLIM_CURCULAR_BUFFER {

public:
	SLIM_CURCULAR_BUFFER(uint8_t *pBuf, uint16_t bufzise) {

		reset(pBuf, bufzise);
	}
	void reset(uint8_t *pBuf=NULL, uint16_t bufzise=0) {

		if(pBuf){
			if (!is_power_of_2(bufzise)) {
				bufzise = shrinkTo_power_of_2(bufzise);
			}
			buffer = pBuf;
			bufferSize = bufzise;
			mask = bufferSize - 1;
		}
		else{
			buffer = 0;
			bufferSize = 0;
			mask = 0;
		}
		head = 0;
		tail = 0;
	}
 

	uint32_t availableData() {
		return (uint32_t)(head - tail);
	}





	uint32_t peek(uint8_t* pDes, uint32_t len) {
		uint32_t ltemp;

		ltemp = availableData();

		len = (len > ltemp) ? ltemp : len;

		copy_out( pDes, len, tail);

		return len;
	}
	inline uint8_t peekAt(uint32_t index) {
		return buffer[(tail + index) & mask];
	}

	uint16_t peekAt_U16(int index){
		return (uint16_t)((uint16_t)(peekAt(index)) | (uint16_t)((uint16_t)(peekAt(index + 1) << 8)));

	}
	uint32_t in(const uint8_t* pSrc, uint32_t len) {
		uint32_t ltemp = unusedSpace();
		len = (len > ltemp) ? ltemp : len;

		copy_in( pSrc, len, head);
		head += len;
		return len;
	}
	uint32_t in_U16LB(const uint16_t* pSrc, uint32_t len) {
		uint32_t ltemp = unusedSpace();
		len = (len > ltemp) ? ltemp : len;

		copy_in_U16LB( pSrc, len, head);
		head += len;
		return len;
	}
	uint32_t out(uint8_t* pDes, uint32_t len) {
		uint32_t peekedLen = peek(pDes, len);
		tail += peekedLen;

		return peekedLen;
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

	uint32_t discardUntilNext(uint8_t targetChar)
	{
		int allbytes = availableData();

		if (allbytes == 0) {
			return 0;
		}

		for (int i = 0; i < allbytes; i++) {
			if (targetChar == peekAt(i)) {
				if (i == 0)//ignore the current char
					continue;
				discardN(i);
				return (i);
			}
		}
		discardN(allbytes);
		return allbytes;
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


	//check table
	uint16_t calculateCRC(uint32_t datasize) {

		uint16_t crc=0xFFFF;
		int j=0;
		while (datasize--)
			crc = crc16_table[(crc ^ peekAt(j++)) & 0xFF] ^ (crc >> 8);

		return crc;

	}

	static void memcpy_U16LB_2_U8(uint8_t *des, const uint16_t *src, size_t len){
       for(size_t i=0;i<len;i++){
    	   des[i] = (uint8_t)(src[i] & 0xFF);
       }
    }

	static void memcpy_U8_2_U16LB(uint16_t *des, const uint8_t *src, size_t len){
       for(size_t i=0;i<len;i++){
    	   des[i] = src[i];
       }
    }

	uint8_t		*buffer;
	uint32_t	bufferSize;

private:

	uint32_t	head;
	uint32_t	tail;
	
	uint32_t	mask;



	uint32_t in_overwrite(const uint8_t* pSrc, uint32_t len) {
		uint32_t ltemp = unusedSpace();


		copy_in( pSrc, len, head);
		head += len;

		uint32_t loverflow = (len > ltemp) ? len - ltemp : 0;
		tail += loverflow;

		return len;
	}

	void copy_in(const uint8_t* pSrc, uint32_t len, uint32_t off)
	{

		uint32_t ltemp;

		off &= mask;

		uint32_t tm = bufferSize - off;

		ltemp = len < tm ? len : tm;

		memcpy(buffer + off, pSrc, ltemp);
		memcpy(buffer, pSrc + ltemp, len - ltemp);

	}
	void copy_in_U16LB(const uint16_t* pSrc, uint32_t len, uint32_t off)
	{

		uint32_t ltemp;

		off &= mask;

		uint32_t tm = bufferSize - off;

		ltemp = len < tm ? len : tm;

		memcpy_U16LB_2_U8(buffer + off, pSrc, ltemp);
		memcpy_U16LB_2_U8(buffer, pSrc + ltemp, len - ltemp);

	}
	void copy_out(uint8_t* pDes, uint32_t len, uint32_t off)
	{
		uint32_t ltemp;

		off &= mask;

		uint32_t tm = bufferSize - off;

		ltemp = len < tm ? len : tm;


		memcpy(pDes, buffer + off, ltemp);
		memcpy(pDes + ltemp, buffer, len - ltemp);
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
