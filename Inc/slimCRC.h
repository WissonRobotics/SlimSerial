/**  
* @Title: slimCRC.h
* @Description: TODO(用一句话描述该文件做什么)
* @author Xiaojiao Chen
* @email yii402072495@gmail.com
* @date Aug 18, 2023 3:20:09 PM
* @version V1.0  
*/
#ifndef SLIMDRIVE_INC_SLIMCRC_H_
#define SLIMDRIVE_INC_SLIMCRC_H_
#ifdef __cplusplus
 extern "C" {
#endif

#include "stdint.h"
 extern const uint16_t crc16_table[256];
 extern uint16_t SD_CRC_Calculate(uint8_t *buffer, uint16_t datasize);


#ifdef __cplusplus
}
#endif
#endif /* SLIMDRIVE_INC_SLIMCRC_H_ */
