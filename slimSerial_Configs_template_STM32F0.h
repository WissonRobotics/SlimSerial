

#ifndef SLIMSERIAL_CONFIGS_H_
#define SLIMSERIAL_CONFIGS_H_

/****************************** User define Zone Begin***********************/
#define PC_USART     	  huart5 // PC UI,  PC Command

/****************************** SlimSerial Configuration Zone Begin***********************/
//define which usart to use this driver
#define ENABLE_SLIMSERIAL_USART1 0 // 1: use this driver for USART 1    0:dont use this driver for USART 1
#define ENABLE_SLIMSERIAL_USART2 0
#define ENABLE_SLIMSERIAL_USART3 0
#define ENABLE_SLIMSERIAL_USART4 0 //
#define ENABLE_SLIMSERIAL_USART5 1 //
#define ENABLE_SLIMSERIAL_USART6 0
#define ENABLE_SLIMSERIAL_USART7 0 //
#define ENABLE_SLIMSERIAL_USART8 0 //

enum
{
    SLIMSERIAL_TX_MODE_BLOCK = 0,
    SLIMSERIAL_TX_MODE_DMA   = 1,
    SLIMSERIAL_TX_MODE_IT    = 2
};

enum
{
    SLIMSERIAL_RX_MODE_OFF 	  = 0,
    SLIMSERIAL_RX_MODE_TASK   = 1,
    SLIMSERIAL_RX_MODE_INT     = 2
};

/*
SLIMSERIAL_FRAME_TYPE_0_ANY:  	receive any rx and trigger a rx callback based on idle line dectection.
SLIMSERIAL_FRAME_TYPE_1:  		Frame: Header1 Header2 Src Len Func  + payloads + crc16.  Trigger a rx callback for a valid frame
SLIMSERIAL_FRAME_TYPE_2:  		Frame: Header1 Header2 Len Func  + payloads + crc16. Trigger a rx callback for a valid frame
SLIMSERIAL_FRAME_TYPE_3_MODBUS: Frame: MODBUS frame.  Trigger a rx callback for a valid frame
SLIMSERIAL_FRAME_TYPE_4_NONE:  	receive any rx without triggering rx callback.  Read rx by actively call readBuffer()
*/
//define the usart's tx rx frame max size, need to be 2^n, and the 485Tx enable pin
#if ENABLE_SLIMSERIAL_USART1 == 1
#define USART1_TX_FRAME_MAX_SIZE   32                      //to be 2^n,  Max bytes of Tx frame
#define USART1_RX_FRAME_MAX_SIZE   16                      //to be 2^n,  Max bytes of Rx frame
#define USART1_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_1 //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
#define USART1_485_Tx_EN_GPIO_Port RS485_EN1_GPIO_Port     //NULL if not used
#define USART1_485_Tx_EN_GPIO_Pin  RS485_EN1_Pin           //NULL if not used
#define USART1_TX_MODE             SLIMSERIAL_TX_MODE_DMA  // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define USART1_RX_MODE             SLIMSERIAL_RX_MODE_TASK // 0: disable rx ;  1:enable rx frame parse in task; 2: enable rx frame parse in interrupt
#endif

#if ENABLE_SLIMSERIAL_USART2 == 1
#define USART2_TX_FRAME_MAX_SIZE   4                         //to be 2^n,  Max bytes of Tx frame
#define USART2_RX_FRAME_MAX_SIZE   8                         //to be 2^n,  Max bytes of Rx frame
#define USART2_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_0_ANY //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
#define USART2_485_Tx_EN_GPIO_Port RS485_EN2_GPIO_Port         //set to NULL if not used
#define USART2_485_Tx_EN_GPIO_Pin  RS485_EN2_Pin               //set to NULL if not used
#define USART2_TX_MODE             SLIMSERIAL_TX_MODE_BLOCK      // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define USART2_RX_MODE             SLIMSERIAL_RX_MODE_TASK                           // 0: disable rx ;  1:enable rx;
#endif

#if ENABLE_SLIMSERIAL_USART3 == 1
#define USART3_TX_FRAME_MAX_SIZE   16                      //to be 2^n,  Max bytes of Tx frame
#define USART3_RX_FRAME_MAX_SIZE   32                      //to be 2^n,  Max bytes of Rx frame
#define USART3_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_1 //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
#define USART3_485_Tx_EN_GPIO_Port NULL                    //set to NULL if not used
#define USART3_485_Tx_EN_GPIO_Pin  0                       //set to NULL if not used
#define USART3_TX_MODE             SLIMSERIAL_TX_MODE_DMA  // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define USART3_RX_MODE             SLIMSERIAL_RX_MODE_TASK                       // 0: disable rx ;  1:enable rx;
#endif

#if ENABLE_SLIMSERIAL_USART4 == 1
#define USART4_TX_FRAME_MAX_SIZE   256                     //to be 2^n,  Max bytes of Tx frame
#define USART4_RX_FRAME_MAX_SIZE   256                     //to be 2^n,  Max bytes of Rx frame
#define USART4_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_1 //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
#define USART4_485_Tx_EN_GPIO_Port RS485_EN4_GPIO_Port     //set to NULL if not used
#define USART4_485_Tx_EN_GPIO_Pin  RS485_EN4_Pin           //set to NULL if not used
#define USART4_TX_MODE             SLIMSERIAL_TX_MODE_DMA  // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define USART4_RX_MODE             SLIMSERIAL_RX_MODE_TASK                       // 0: disable rx ;  1:enable rx;
#endif

#if ENABLE_SLIMSERIAL_USART5 == 1
#define USART5_TX_FRAME_MAX_SIZE   64                     //to be 2^n,  Max bytes of Tx frame
#define USART5_RX_FRAME_MAX_SIZE   64                      //to be 2^n,  Max bytes of Rx frame
#define USART5_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_1 //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
#define USART5_485_Tx_EN_GPIO_Port NULL                    //set to NULL if not used
#define USART5_485_Tx_EN_GPIO_Pin  0                       //set to NULL if not used
#define USART5_TX_MODE             SLIMSERIAL_TX_MODE_DMA  // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define USART5_RX_MODE             SLIMSERIAL_RX_MODE_TASK                       // 0: disable rx ;  1:enable rx;
#endif

#if ENABLE_SLIMSERIAL_USART6 == 1
#define USART6_TX_FRAME_MAX_SIZE   256                     //to be 2^n,  Max bytes of Tx frame
#define USART6_RX_FRAME_MAX_SIZE   256                     //to be 2^n,  Max bytes of Rx frame
#define USART6_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_1 //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
#define USART6_485_Tx_EN_GPIO_Port RS485_EN6_GPIO_Port     //set to NULL if not used
#define USART6_485_Tx_EN_GPIO_Pin  RS485_EN6_Pin           //set to NULL if not used
#define USART6_TX_MODE             SLIMSERIAL_TX_MODE_DMA  // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define USART6_RX_MODE             SLIMSERIAL_RX_MODE_TASK                       // 0: disable rx ;  1:enable rx;
#endif

#if ENABLE_SLIMSERIAL_USART7 == 1
#define USART7_TX_FRAME_MAX_SIZE   256                     //to be 2^n,  Max bytes of Tx frame
#define USART7_RX_FRAME_MAX_SIZE   256                     //to be 2^n,  Max bytes of Rx frame
#define USART7_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_1 //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
#define USART7_485_Tx_EN_GPIO_Port NULL                    //set to NULL if not used
#define USART7_485_Tx_EN_GPIO_Pin  0                       //set to NULL if not used
#define USART7_TX_MODE             SLIMSERIAL_TX_MODE_DMA  // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define USART7_RX_MODE             SLIMSERIAL_RX_MODE_TASK                      // 0: disable rx ;  1:enable rx;
#endif

#if ENABLE_SLIMSERIAL_USART8 == 1
#define USART8_TX_FRAME_MAX_SIZE   256                     //to be 2^n,  Max bytes of Tx frame
#define USART8_RX_FRAME_MAX_SIZE   256                     //to be 2^n,  Max bytes of Rx frame
#define USART8_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_1 //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
#define USART8_485_Tx_EN_GPIO_Port NULL                    //set to NULL if not used
#define USART8_485_Tx_EN_GPIO_Pin  0                       //set to NULL if not used
#define USART8_TX_MODE             SLIMSERIAL_TX_MODE_DMA  // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
#define USART8_RX_MODE             SLIMSERIAL_RX_MODE_TASK                      // 0: disable rx ;  1:enable rx;
#endif

//enable recording the tx time cost with micro seconds.
#define ENABLE_SLIMSERIAL_MICRO_SECONDS 1
#if ENABLE_SLIMSERIAL_MICRO_SECONDS
#define HAL_TICK_TIM TIM6 //The timer used for HAL_Tick()
#endif

#define ENABLE_PROXY 0

//default Enable rx address filter

#define DEFAULT_RX_HEADER_1_BYTE1 0x5A
#define DEFAULT_RX_HEADER_1_BYTE2 0xA5

#define DEFAULT_RX_HEADER_2_BYTE1 0xFF
#define DEFAULT_RX_HEADER_2_BYTE2 0xFF

//default DISable rx address filter

#define DEFAULT_RX_ADDRESS_WHITE_LIST 0xFF

//default DISable rx address filter

#define DEFAULT_RX_FUNCODE_WHITE_LIST 0xA2

//advanced config
#define SLIMSERIAL_RX_TASK_BUFFER_SIZE       256 // rx task stack size
#define SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN 2    //number of callbacks that can attach to one serial
#define SLIMSERIAL_HEADER_FILTER_MAX_LEN     3
#define SLIMSERIAL_ADDRESS_FILTER_MAX_LEN    3
#define SLIMSERIAL_FUNCODE_FILTER_MAX_LEN    3

#endif /* SLIMSERIAL_CONFIGS_H_ */
