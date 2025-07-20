#ifndef SLIMSERIAL_DEFINES_H_
#define SLIMSERIAL_DEFINES_H_


//SlimSerial Tx Mode
// 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define SLIMSERIAL_TX_MODE_BLOCK 0
#define SLIMSERIAL_TX_MODE_DMA   1
#define SLIMSERIAL_TX_MODE_IT    2


//SlimSerial Rx Mode
// 0: disable rx ;  1:enable rx in task;  2:enable rx in interrupt.
#define SLIMSERIAL_RX_MODE_OFF   0
#define SLIMSERIAL_RX_MODE_TASK  1
#define SLIMSERIAL_RX_MODE_INT   2

//SlimSerial Rx Frame Type
/*
SLIMSERIAL_FRAME_TYPE_0_ANY:  	receive any rx and trigger a rx callback based on idle line dectection.
SLIMSERIAL_FRAME_TYPE_1:  		Frame: Header1 Header2 Src Len Func  + payloads + crc16.  Trigger a rx callback for a valid frame
SLIMSERIAL_FRAME_TYPE_2:  		Frame: Header1 Header2 Len Func  + payloads + crc16. Trigger a rx callback for a valid frame
SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM: Frame: MODBUS SERVER frame.  Trigger a rx callback for a valid frame
SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM: Frame: MODBUS CLIENT frame.  Trigger a rx callback for a valid frame
SLIMSERIAL_FRAME_TYPE_NONE:  	receive any rx without triggering rx callback.  Read rx by actively call readBuffer()
*/
#define SLIMSERIAL_FRAME_TYPE_0_ANY 			0
#define SLIMSERIAL_FRAME_TYPE_1 				1
#define SLIMSERIAL_FRAME_TYPE_2					2
#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM 3
#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM 4
#define SLIMSERIAL_FRAME_TYPE_NONE 				99










#endif /* SLIMSERIAL_DEFINES_H_ */