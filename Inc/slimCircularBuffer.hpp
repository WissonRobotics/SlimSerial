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
class CURCULAR_BUFFER {

public:
	CURCULAR_BUFFER(uint8_t *pBuf, uint16_t bufzise) {

		if (!is_power_of_2(bufzise)) {

			bufzise = shrinkTo_power_of_2(bufzise);

		}
		buffer = pBuf;
		bufferSize = bufzise;
		mask = bufferSize - 1;

		reset();
	}

	void reset() {
		head = 0;
		tail = 0;
	}

	uint32_t out(uint8_t* pDes, uint32_t len) {
		uint32_t peekedLen = peek(pDes, len);
		tail += peekedLen;

		return peekedLen;
	}

	uint32_t out(uint32_t len) {

		uint32_t ltemp = availableData();

		len = (len > ltemp) ? ltemp : len;

		tail += len;

		return len;
	}

	inline uint8_t peekAt(uint32_t index) {
		return buffer[(tail + index) & mask];
	}

	uint32_t peek(uint8_t* pDes, uint32_t len) {
		uint32_t ltemp;

		ltemp = availableData();

		len = (len > ltemp) ? ltemp : len;

		copy_out( pDes, len, tail);

		return len;
	}

	uint32_t in(const uint8_t* pSrc, uint32_t len) {
		uint32_t ltemp = unusedSpace();
		len = (len > ltemp) ? ltemp : len;

		copy_in( pSrc, len, head);
		head += len;
		return len;
	}

	uint32_t in_overwrite(const uint8_t* pSrc, uint32_t len) {
		uint32_t ltemp = unusedSpace();


		copy_in( pSrc, len, head);
		head += len;

		uint32_t loverflow = (len > ltemp) ? len - ltemp : 0;
		tail += loverflow;

		return len;
	}

	uint32_t availableData() {
		return (uint32_t)(head - tail);
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

	uint16_t peekAt_U16(int index){
		return (uint16_t)((uint16_t)(peekAt(index)) | (uint16_t)((uint16_t)(peekAt(index + 1) << 8)));

	}




private:
	uint8_t		*buffer;
	uint32_t	head;
	uint32_t	tail;
	uint32_t	bufferSize;
	uint32_t	mask;
	void copy_in(const uint8_t* pSrc, uint32_t len, uint32_t off)
	{

		uint32_t ltemp;

		off &= mask;

		uint32_t tm = bufferSize - off;

		ltemp = len < tm ? len : tm;

		memcpy(buffer + off, pSrc, ltemp);
		memcpy(buffer, pSrc + ltemp, len - ltemp);

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
