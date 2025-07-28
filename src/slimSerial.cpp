
#include <slimSerial.h>
#include "stdio.h"
#include "cmsis_os.h"
#include <type_traits>



#include "main.h"




#if ENABLE_SLIMSERIAL_USART1==1
#define USART1_TX_QUEUE_SIZE SLIMSERIAL_DEFAULT_TX_QUEUE_SIZE
#define USART1_RX_CIRCULAR_BUFFER_SIZE USART1_RX_FRAME_MAX_SIZE*2
#if USART1_9_BITS_MODE == 0
uint8_t USART1_TX_QUEUE_BUFFER[USART1_TX_FRAME_MAX_SIZE*USART1_TX_QUEUE_SIZE];
uint8_t USART1_RX_CIRCULAR_BUFFER[USART1_RX_CIRCULAR_BUFFER_SIZE];
#elif USART1_9_BITS_MODE == 1
uint16_t USART1_TX_QUEUE_BUFFER[USART1_TX_FRAME_MAX_SIZE*USART1_TX_QUEUE_SIZE];
uint16_t USART1_RX_CIRCULAR_BUFFER[USART1_RX_CIRCULAR_BUFFER_SIZE];
#endif
uint8_t USART1_RX_FRAME_BUFFER[USART1_RX_FRAME_MAX_SIZE];

#if USART1_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_0_ANY
#ifndef SLIMSERIAL_FRAME_TYPE_0_ANY_USED
	#define SLIMSERIAL_FRAME_TYPE_0_ANY_USED 1
#endif
#elif USART1_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_1
#ifndef SLIMSERIAL_FRAME_TYPE_1_USED
	#define SLIMSERIAL_FRAME_TYPE_1_USED 1
#endif
#elif USART1_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_2
#ifndef SLIMSERIAL_FRAME_TYPE_2_USED
	#define SLIMSERIAL_FRAME_TYPE_2_USED 1
#endif
#elif USART1_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED 1
#endif
#elif USART1_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED 1
#endif
#endif

SlimSerial slimSerial1(&huart1,
		(uint16_t *)(USART1_TX_QUEUE_BUFFER),USART1_TX_FRAME_MAX_SIZE,USART1_TX_QUEUE_SIZE,
		(uint16_t *)USART1_RX_CIRCULAR_BUFFER,USART1_RX_CIRCULAR_BUFFER_SIZE,
		USART1_RX_FRAME_BUFFER,USART1_RX_FRAME_MAX_SIZE,
		USART1_FRAME_TYPE,
		USART1_485_Tx_EN_GPIO_Port,
		USART1_485_Tx_EN_GPIO_Pin,
		USART1_TX_MODE,
		USART1_RX_MODE,
		USART1_9_BITS_MODE,
		USART1_TIMEOUT_TIMER_INDEX);
#endif

#if ENABLE_SLIMSERIAL_USART2==1
#define USART2_TX_QUEUE_SIZE SLIMSERIAL_DEFAULT_TX_QUEUE_SIZE
#define USART2_RX_CIRCULAR_BUFFER_SIZE USART2_RX_FRAME_MAX_SIZE*2
#if USART2_9_BITS_MODE == 0
uint8_t USART2_TX_QUEUE_BUFFER[USART2_TX_FRAME_MAX_SIZE*USART2_TX_QUEUE_SIZE];
uint8_t USART2_RX_CIRCULAR_BUFFER[USART2_RX_CIRCULAR_BUFFER_SIZE];
#elif USART2_9_BITS_MODE == 1
uint16_t USART2_TX_QUEUE_BUFFER[USART2_TX_FRAME_MAX_SIZE*USART2_TX_QUEUE_SIZE];
uint16_t USART2_RX_CIRCULAR_BUFFER[USART2_RX_CIRCULAR_BUFFER_SIZE];
#endif

uint8_t USART2_RX_FRAME_BUFFER[USART2_RX_FRAME_MAX_SIZE];

#if USART2_FRAME_TYPE==SLIMSERIAL_FRAME_TYPE_0_ANY
#ifndef SLIMSERIAL_FRAME_TYPE_0_ANY_USED
	#define SLIMSERIAL_FRAME_TYPE_0_ANY_USED 1
#endif
#elif USART2_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_1
#ifndef SLIMSERIAL_FRAME_TYPE_1_USED
	#define SLIMSERIAL_FRAME_TYPE_1_USED 1
#endif
#elif USART2_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_2
#ifndef SLIMSERIAL_FRAME_TYPE_2_USED
	#define SLIMSERIAL_FRAME_TYPE_2_USED 1
#endif
#elif USART2_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED 1
#endif
#elif USART2_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED 1
#endif
#endif

SlimSerial slimSerial2(&huart2,
		(uint16_t *)USART2_TX_QUEUE_BUFFER,USART2_TX_FRAME_MAX_SIZE,USART2_TX_QUEUE_SIZE,
		(uint16_t *)USART2_RX_CIRCULAR_BUFFER,USART2_RX_CIRCULAR_BUFFER_SIZE,
		USART2_RX_FRAME_BUFFER,USART2_RX_FRAME_MAX_SIZE,
		USART2_FRAME_TYPE,
		USART2_485_Tx_EN_GPIO_Port,
		USART2_485_Tx_EN_GPIO_Pin,
		USART2_TX_MODE,
		USART2_RX_MODE,
		USART2_9_BITS_MODE,
		USART2_TIMEOUT_TIMER_INDEX);
#endif

#if ENABLE_SLIMSERIAL_USART3==1
#define USART3_TX_QUEUE_SIZE SLIMSERIAL_DEFAULT_TX_QUEUE_SIZE
#define USART3_RX_CIRCULAR_BUFFER_SIZE USART3_RX_FRAME_MAX_SIZE*2
#if USART3_9_BITS_MODE == 0
uint8_t USART3_TX_QUEUE_BUFFER[USART3_TX_FRAME_MAX_SIZE*USART3_TX_QUEUE_SIZE];
uint8_t USART3_RX_CIRCULAR_BUFFER[USART3_RX_CIRCULAR_BUFFER_SIZE];
#elif USART3_9_BITS_MODE == 1
uint16_t USART3_TX_QUEUE_BUFFER[USART3_TX_FRAME_MAX_SIZE*USART3_TX_QUEUE_SIZE];
uint16_t USART3_RX_CIRCULAR_BUFFER[USART3_RX_CIRCULAR_BUFFER_SIZE];
#endif
uint8_t USART3_RX_FRAME_BUFFER[USART3_RX_FRAME_MAX_SIZE];

#if USART3_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_0_ANY
#ifndef SLIMSERIAL_FRAME_TYPE_0_ANY_USED
	#define SLIMSERIAL_FRAME_TYPE_0_ANY_USED 1
#endif
#elif USART3_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_1
#ifndef SLIMSERIAL_FRAME_TYPE_1_USED
	#define SLIMSERIAL_FRAME_TYPE_1_USED 1
#endif
#elif USART3_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_2
#ifndef SLIMSERIAL_FRAME_TYPE_2_USED
	#define SLIMSERIAL_FRAME_TYPE_2_USED 1
#endif
#elif USART3_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED 1
#endif
#elif USART3_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED 1
#endif
#endif

SlimSerial slimSerial3(&huart3,
		(uint16_t *)USART3_TX_QUEUE_BUFFER,USART3_TX_FRAME_MAX_SIZE,USART3_TX_QUEUE_SIZE,
		(uint16_t *)USART3_RX_CIRCULAR_BUFFER,USART3_RX_CIRCULAR_BUFFER_SIZE,
		USART3_RX_FRAME_BUFFER,USART3_RX_FRAME_MAX_SIZE,USART3_FRAME_TYPE,
		USART3_485_Tx_EN_GPIO_Port,
		USART3_485_Tx_EN_GPIO_Pin,
		USART3_TX_MODE,
		USART3_RX_MODE,
		USART3_9_BITS_MODE,
		USART3_TIMEOUT_TIMER_INDEX);
#endif

#if ENABLE_SLIMSERIAL_USART4==1
#define USART4_TX_QUEUE_SIZE SLIMSERIAL_DEFAULT_TX_QUEUE_SIZE
#define USART4_RX_CIRCULAR_BUFFER_SIZE USART4_RX_FRAME_MAX_SIZE*2
#if USART4_9_BITS_MODE == 0
uint8_t USART4_TX_QUEUE_BUFFER[USART4_TX_FRAME_MAX_SIZE*USART4_TX_QUEUE_SIZE];
uint8_t USART4_RX_CIRCULAR_BUFFER[USART4_RX_CIRCULAR_BUFFER_SIZE];
#elif USART4_9_BITS_MODE == 1
uint16_t USART4_TX_QUEUE_BUFFER[USART4_TX_FRAME_MAX_SIZE*USART4_TX_QUEUE_SIZE];
uint16_t USART4_RX_CIRCULAR_BUFFER[USART4_RX_CIRCULAR_BUFFER_SIZE];
#endif

uint8_t USART4_RX_FRAME_BUFFER[USART4_RX_FRAME_MAX_SIZE];

#if USART4_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_0_ANY
#ifndef SLIMSERIAL_FRAME_TYPE_0_ANY_USED
	#define SLIMSERIAL_FRAME_TYPE_0_ANY_USED 1
#endif
#elif USART4_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_1
#ifndef SLIMSERIAL_FRAME_TYPE_1_USED
	#define SLIMSERIAL_FRAME_TYPE_1_USED 1
#endif
#elif USART4_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_2
#ifndef SLIMSERIAL_FRAME_TYPE_2_USED
	#define SLIMSERIAL_FRAME_TYPE_2_USED 1
#endif
#elif USART4_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED 1
#endif
#elif USART4_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED 1
#endif
#endif

SlimSerial slimSerial4(&huart4,
		(uint16_t *)USART4_TX_QUEUE_BUFFER,USART4_TX_FRAME_MAX_SIZE,USART4_TX_QUEUE_SIZE,
		(uint16_t *)USART4_RX_CIRCULAR_BUFFER,USART4_RX_CIRCULAR_BUFFER_SIZE,
		USART4_RX_FRAME_BUFFER,USART4_RX_FRAME_MAX_SIZE,USART4_FRAME_TYPE,
		USART4_485_Tx_EN_GPIO_Port,
		USART4_485_Tx_EN_GPIO_Pin,
		USART4_TX_MODE,
		USART4_RX_MODE,
		USART4_9_BITS_MODE,
		USART4_TIMEOUT_TIMER_INDEX);
#endif
#if ENABLE_SLIMSERIAL_USART5==1
#define USART5_TX_QUEUE_SIZE SLIMSERIAL_DEFAULT_TX_QUEUE_SIZE
#define USART5_RX_CIRCULAR_BUFFER_SIZE USART5_RX_FRAME_MAX_SIZE*2
#if USART5_9_BITS_MODE == 0
uint8_t USART5_TX_QUEUE_BUFFER[USART5_TX_FRAME_MAX_SIZE*USART5_TX_QUEUE_SIZE];
uint8_t USART5_RX_CIRCULAR_BUFFER[USART5_RX_CIRCULAR_BUFFER_SIZE];
#elif USART5_9_BITS_MODE == 1
uint16_t USART5_TX_QUEUE_BUFFER[USART5_TX_FRAME_MAX_SIZE*USART5_TX_QUEUE_SIZE];
uint16_t USART5_RX_CIRCULAR_BUFFER[USART5_RX_CIRCULAR_BUFFER_SIZE];
#endif

uint8_t USART5_RX_FRAME_BUFFER[USART5_RX_FRAME_MAX_SIZE];

#if USART5_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_0_ANY
#ifndef SLIMSERIAL_FRAME_TYPE_0_ANY_USED
	#define SLIMSERIAL_FRAME_TYPE_0_ANY_USED 1
#endif
#elif USART5_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_1
#ifndef SLIMSERIAL_FRAME_TYPE_1_USED
	#define SLIMSERIAL_FRAME_TYPE_1_USED 1
#endif
#elif USART5_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_2
#ifndef SLIMSERIAL_FRAME_TYPE_2_USED
	#define SLIMSERIAL_FRAME_TYPE_2_USED 1
#endif
#elif USART5_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED 1
#endif
#elif USART5_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED 1
#endif
#endif

SlimSerial slimSerial5(&huart5,
		(uint16_t *)USART5_TX_QUEUE_BUFFER,USART5_TX_FRAME_MAX_SIZE,USART5_TX_QUEUE_SIZE,
		(uint16_t *)USART5_RX_CIRCULAR_BUFFER,USART5_RX_CIRCULAR_BUFFER_SIZE,
		USART5_RX_FRAME_BUFFER,USART5_RX_FRAME_MAX_SIZE,USART5_FRAME_TYPE,
		USART5_485_Tx_EN_GPIO_Port,
		USART5_485_Tx_EN_GPIO_Pin,
		USART5_TX_MODE,
		USART5_RX_MODE,
		USART5_9_BITS_MODE,
		USART5_TIMEOUT_TIMER_INDEX);
#endif
#if ENABLE_SLIMSERIAL_USART6==1
#define USART6_TX_QUEUE_SIZE SLIMSERIAL_DEFAULT_TX_QUEUE_SIZE
#define USART6_RX_CIRCULAR_BUFFER_SIZE USART6_RX_FRAME_MAX_SIZE*2
#if USART6_9_BITS_MODE == 0
uint8_t USART6_TX_QUEUE_BUFFER[USART6_TX_FRAME_MAX_SIZE*USART6_TX_QUEUE_SIZE];
uint8_t USART6_RX_CIRCULAR_BUFFER[USART6_RX_CIRCULAR_BUFFER_SIZE];
#elif USART6_9_BITS_MODE == 1
uint16_t USART6_TX_QUEUE_BUFFER[USART6_TX_FRAME_MAX_SIZE*USART6_TX_QUEUE_SIZE];
uint16_t USART6_RX_CIRCULAR_BUFFER[USART6_RX_CIRCULAR_BUFFER_SIZE];
#endif

uint8_t USART6_RX_FRAME_BUFFER[USART6_RX_FRAME_MAX_SIZE];
#if USART6_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_0_ANY
#ifndef SLIMSERIAL_FRAME_TYPE_0_ANY_USED
	#define SLIMSERIAL_FRAME_TYPE_0_ANY_USED 1
#endif
#elif USART6_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_1
#ifndef SLIMSERIAL_FRAME_TYPE_1_USED
	#define SLIMSERIAL_FRAME_TYPE_1_USED 1
#endif
#elif USART6_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_2
#ifndef SLIMSERIAL_FRAME_TYPE_2_USED
	#define SLIMSERIAL_FRAME_TYPE_2_USED 1
#endif
#elif USART6_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED 1
#endif
#elif USART6_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED 1
#endif
#endif

SlimSerial slimSerial6(&huart6,
		(uint16_t *)USART6_TX_QUEUE_BUFFER,USART6_TX_FRAME_MAX_SIZE,USART6_TX_QUEUE_SIZE,
		(uint16_t *)USART6_RX_CIRCULAR_BUFFER,USART6_RX_CIRCULAR_BUFFER_SIZE,
		USART6_RX_FRAME_BUFFER,USART6_RX_FRAME_MAX_SIZE,USART6_FRAME_TYPE,
		USART6_485_Tx_EN_GPIO_Port,
		USART6_485_Tx_EN_GPIO_Pin,
		USART6_TX_MODE,
		USART6_RX_MODE,
		USART6_9_BITS_MODE,
		USART6_TIMEOUT_TIMER_INDEX);
#endif
#if ENABLE_SLIMSERIAL_USART7==1
#define USART7_TX_QUEUE_SIZE SLIMSERIAL_DEFAULT_TX_QUEUE_SIZE
#define USART7_RX_CIRCULAR_BUFFER_SIZE USART7_RX_FRAME_MAX_SIZE*2
#if USART7_9_BITS_MODE == 0
uint8_t USART7_TX_QUEUE_BUFFER[USART7_TX_FRAME_MAX_SIZE*USART7_TX_QUEUE_SIZE];
uint8_t USART7_RX_CIRCULAR_BUFFER[USART7_RX_CIRCULAR_BUFFER_SIZE];
#elif USART7_9_BITS_MODE == 1
uint16_t USART7_TX_QUEUE_BUFFER[USART7_TX_FRAME_MAX_SIZE*USART7_TX_QUEUE_SIZE];
uint16_t USART7_RX_CIRCULAR_BUFFER[USART7_RX_CIRCULAR_BUFFER_SIZE];
#endif

uint8_t USART7_RX_FRAME_BUFFER[USART7_RX_FRAME_MAX_SIZE];
#if USART7_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_0_ANY
#ifndef SLIMSERIAL_FRAME_TYPE_0_ANY_USED
	#define SLIMSERIAL_FRAME_TYPE_0_ANY_USED 1
#endif
#elif USART7_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_1
#ifndef SLIMSERIAL_FRAME_TYPE_1_USED
	#define SLIMSERIAL_FRAME_TYPE_1_USED 1
#endif
#elif USART7_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_2
#ifndef SLIMSERIAL_FRAME_TYPE_2_USED
	#define SLIMSERIAL_FRAME_TYPE_2_USED 1
#endif
#elif USART7_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED 1
#endif
#elif USART7_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED 1
#endif
#endif

SlimSerial slimSerial7(&huart7,
		(uint16_t *)USART7_TX_QUEUE_BUFFER,USART7_TX_FRAME_MAX_SIZE,USART7_TX_QUEUE_SIZE,
		(uint16_t *)USART7_RX_CIRCULAR_BUFFER,USART7_RX_CIRCULAR_BUFFER_SIZE,
		USART7_RX_FRAME_BUFFER,USART7_RX_FRAME_MAX_SIZE,USART7_FRAME_TYPE,
		USART7_485_Tx_EN_GPIO_Port,
		USART7_485_Tx_EN_GPIO_Pin,
		USART7_TX_MODE,
		USART7_RX_MODE,
		USART7_9_BITS_MODE,
		USART7_TIMEOUT_TIMER_INDEX);
#endif
#if ENABLE_SLIMSERIAL_USART8==1
#define USART8_TX_QUEUE_SIZE SLIMSERIAL_DEFAULT_TX_QUEUE_SIZE
#define USART8_RX_CIRCULAR_BUFFER_SIZE USART8_RX_FRAME_MAX_SIZE*2
#if USART8_9_BITS_MODE == 0
uint8_t USART8_TX_QUEUE_BUFFER[USART8_TX_FRAME_MAX_SIZE*USART8_TX_QUEUE_SIZE];
uint8_t USART8_RX_CIRCULAR_BUFFER[USART8_RX_CIRCULAR_BUFFER_SIZE];
#elif USART8_9_BITS_MODE == 1
uint16_t USART8_TX_QUEUE_BUFFER[USART8_TX_FRAME_MAX_SIZE*USART8_TX_QUEUE_SIZE];
uint16_t USART8_RX_CIRCULAR_BUFFER[USART8_RX_CIRCULAR_BUFFER_SIZE];
#endif

uint8_t USART8_RX_FRAME_BUFFER[USART8_RX_FRAME_MAX_SIZE];
#if USART8_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_0_ANY
#ifndef SLIMSERIAL_FRAME_TYPE_0_ANY_USED
	#define SLIMSERIAL_FRAME_TYPE_0_ANY_USED 1
#endif
#elif USART8_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_1
#ifndef SLIMSERIAL_FRAME_TYPE_1_USED
	#define SLIMSERIAL_FRAME_TYPE_1_USED 1
#endif
#elif USART8_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_2
#ifndef SLIMSERIAL_FRAME_TYPE_2_USED
	#define SLIMSERIAL_FRAME_TYPE_2_USED 1
#endif
#elif USART8_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED 1
#endif
#elif USART8_FRAME_TYPE == SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM
#ifndef SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED
	#define SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED 1
#endif
#endif

SlimSerial slimSerial8(&huart8,
		(uint16_t *)USART8_TX_QUEUE_BUFFER,USART8_TX_FRAME_MAX_SIZE,USART8_TX_QUEUE_SIZE,
		(uint16_t *)USART8_RX_CIRCULAR_BUFFER,USART8_RX_CIRCULAR_BUFFER_SIZE,
		USART8_RX_FRAME_BUFFER,USART8_RX_FRAME_MAX_SIZE,USART8_FRAME_TYPE,
		USART8_485_Tx_EN_GPIO_Port,
		USART8_485_Tx_EN_GPIO_Pin,
		USART8_TX_MODE,
		USART8_RX_MODE,
		USART8_9_BITS_MODE,
		USART8_TIMEOUT_TIMER_INDEX);
#endif

#if ENABLE_PROXY==1
uint16_t SlimSerial::m_proxy_buffer[SLIMSERIAL_PROXY_BUFFER_SIZE]={}; //capable of holding maximum YModem frame size of 1029 even in 9 bits mode
#endif



SlimSerial::SlimSerial(UART_HandleTypeDef *uartHandle,
			uint16_t 		*tx_queue_buf,
			uint16_t 		tx_queue_buf_single_size,
			uint16_t		 tx_queue_size,
			uint16_t   *rx_circular_buf,
			uint16_t rx_circular_buf_size,
			uint8_t  *rx_frame_buf,
			uint16_t rx_frame_buf_size,
			uint8_t rx_frame_type,
			GPIO_TypeDef* tx_485_En_Port,
			uint16_t tx_485_En_Pin,
			uint8_t tx_method,
			uint8_t rx_method,
			uint8_t bits_9_mode,
			uint8_t timeout_timer_index
			)
:m_frameCallbackFuncArray{},
 m_rx_circular_buf((uint8_t *)rx_circular_buf,rx_circular_buf_size,bits_9_mode)
 {

	m_huart = uartHandle;

	//tx buffer
	m_tx_queue_buf = tx_queue_buf;
	m_tx_queue_buf_single_size = tx_queue_buf_single_size;
	m_tx_queue_size = tx_queue_size;
	m_tx_buf_ind = 0;


	//rx data
	m_rx_frame_buf = rx_frame_buf;
	m_rx_frame_buf_size=rx_frame_buf_size;


	//485 tx enable pin
	Tx_EN_Port = tx_485_En_Port;
	Tx_EN_Pin = tx_485_En_Pin;

	//
	m_rx_mode = rx_method;
	m_rx_last.pdata = m_rx_frame_buf;
	m_rx_last.dataBytes=0;
	m_rx_frame_type = rx_frame_type;
	m_rx_frame_type_ori = SLIMSERIAL_FRAME_TYPE_NONE;

	m_totalTxBytes=0;
	m_totalRxBytes=0;
	m_totalTxFrames=0;
	m_totalRxFrames=0;

	m_9bits_mode = bits_9_mode;

	m_enable_rx_wake_up = false;
  
	//header filter
	addHeaderFilter(0x5A,0xA5);
	addHeaderFilter(0xFF,0xFF);


	//address whitelist. disabled by default
	toggleAddressFilter(false);

	//add funcode filter
	toggleFuncodeFilter(false);

	//
	lengthFilterOn=true;
	m_tx_mode = tx_method;


	//
	m_frameCallbackFuncNumber=0;
	m_frameCallbackFuncNumber_C=0;
	m_frameCallbackFuncNumber_all=0;
	for(int i=0;i<SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN;i++){
		m_frameCallbackFuncArray[i]=std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes)>{};
		m_frameCallbackFuncArray_C[i]=NULL;
	}


	//mutex
//	writeMtx = xSemaphoreCreateMutexStatic( &writeMtxBuffer );
//	readMtx = xSemaphoreCreateMutexStatic( &readMtxBuffer );

	//thread
	rxThreadID = 0;
	txrxThreadID = 0;

	debugOutputEnable=1;

	//proxy
	m_proxy_mode = SLIMSERIAL_TXRX_NORMAL;
#if ENABLE_PROXY==1
	m_proxy_port = NULL;
 	m_last_baudrate = 0;

#endif

 	//timeout timer
 	m_timeout_htim_index = timeout_timer_index;
 	m_timeout_htim = getTimerHandle(m_timeout_htim_index);



	/* definition and creation of PCInTask */
	if(m_rx_mode>0){
		createRxTasks();
	}

}

inline SlimSerial *getSlimSerial(UART_HandleTypeDef *huart){
#if ENABLE_SLIMSERIAL_USART1
	if(huart==&huart1){return &slimSerial1;}
#endif
#if ENABLE_SLIMSERIAL_USART2
	if(huart==&huart2){return &slimSerial2;}
	#endif
#if ENABLE_SLIMSERIAL_USART3
	if(huart==&huart3){return &slimSerial3;}
#endif
#if ENABLE_SLIMSERIAL_USART4
	if(huart==&huart4){return &slimSerial4;}
#endif
#if ENABLE_SLIMSERIAL_USART5
	if(huart==&huart5){return &slimSerial5;}
#endif
#if ENABLE_SLIMSERIAL_USART6
	if(huart==&huart6){return &slimSerial6;}
#endif
#if ENABLE_SLIMSERIAL_USART7
	if(huart==&huart7){return &slimSerial7;}
#endif
#if ENABLE_SLIMSERIAL_USART8
	if(huart==&huart8){return &slimSerial8;}
#endif

	//if not found, return NULL
	return NULL;
	
}



inline SlimSerial *getSlimSerial(TIM_HandleTypeDef *htim){
	#if ENABLE_SLIMSERIAL_USART1 && (USART1_TIMEOUT_TIMER_INDEX !=0)
	if(htim==slimSerial1.m_timeout_htim){return &slimSerial1;}
	#endif
	#if ENABLE_SLIMSERIAL_USART2 && (USART2_TIMEOUT_TIMER_INDEX !=0)
	if(htim==slimSerial2.m_timeout_htim){return &slimSerial2;}
	#endif
	#if ENABLE_SLIMSERIAL_USART3 && (USART3_TIMEOUT_TIMER_INDEX !=0)
	if(htim==slimSerial3.m_timeout_htim){return &slimSerial3;}
	#endif
	#if ENABLE_SLIMSERIAL_USART4 && (USART4_TIMEOUT_TIMER_INDEX !=0)
	if(htim==slimSerial4.m_timeout_htim){return &slimSerial4;}
	#endif
	#if ENABLE_SLIMSERIAL_USART5 && (USART5_TIMEOUT_TIMER_INDEX !=0)
	if(htim==slimSerial5.m_timeout_htim){return &slimSerial5;}
	#endif
	#if ENABLE_SLIMSERIAL_USART6 && (USART6_TIMEOUT_TIMER_INDEX !=0)
	if(htim==slimSerial6.m_timeout_htim){return &slimSerial6;}
	#endif
	#if ENABLE_SLIMSERIAL_USART7 && (USART7_TIMEOUT_TIMER_INDEX !=0)
	if(htim==slimSerial7.m_timeout_htim){return &slimSerial7;}
	#endif
	#if ENABLE_SLIMSERIAL_USART8 && (USART8_TIMEOUT_TIMER_INDEX !=0)
	if(htim==slimSerial8.m_timeout_htim){return &slimSerial8;}
	#endif
	//if not found, return NULL
	return NULL;
}

#if ANY_TIMEOUT_TIMER_USED
void SlimSerial::configTimeoutTimer(){
	//if timeout timer is not set, use TIM6
	if(m_timeout_htim_index==0){
		return;
	}

	RCC_ClkInitTypeDef    clkconfig;
	uint32_t              uwTimclock;
	uint32_t              pFLatency;

	/* Get clock configuration */
	HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);

#if defined(__STM32F0xx_HAL_H)
	//APB1 for all TIMs (TIM1,TIM3,TIM6,TIM7,TIM14,TIM15,TIM16,TIM17)
	if(m_timeout_htim_index>0){
#elif defined(__STM32F1xx_HAL_H)
	//TODO: add F1 support

#elif defined(__STM32F4xx_HAL_H)
	//APB1 for TIM2, TIM3, TIM4, TIM5,TIM6,TIM7, TIM12, TIM13, TIM14
	if((m_timeout_htim_index>=2 && m_timeout_htim_index<=7) || (m_timeout_htim_index>=12 && m_timeout_htim_index<=14)){
#endif
		if (clkconfig.APB1CLKDivider == RCC_HCLK_DIV1)
		{
			uwTimclock = HAL_RCC_GetPCLK1Freq();
		}
		else
		{
			uwTimclock = 2UL * HAL_RCC_GetPCLK1Freq();
		}
	}
	else{//APB2 for TIM1, TIM8, TIM9, TIM10, TIM11
#if defined(__STM32F4xx_HAL_H)
		if (clkconfig.APB2CLKDivider == RCC_HCLK_DIV1)
		{
			uwTimclock = HAL_RCC_GetPCLK2Freq();
		}
		else
		{
			uwTimclock = 2UL * HAL_RCC_GetPCLK2Freq();
		}
#endif
	}

	m_timeout_htim->Init.Prescaler = (uint32_t) ((uwTimclock / 1000000U) - 1U);
	m_timeout_htim->Init.Period = (1000000U / 1000U) - 1U;
	m_timeout_htim->Init.ClockDivision = 0;
	m_timeout_htim->Init.CounterMode = TIM_COUNTERMODE_UP;
	m_timeout_htim->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	if (HAL_TIM_Base_Init(m_timeout_htim) != HAL_OK)
	{
	  Error_Handler();
	}


	HAL_TIM_RegisterCallback(m_timeout_htim, HAL_TIM_PERIOD_ELAPSED_CB_ID, [](TIM_HandleTypeDef *htim){getSlimSerial(htim)->txrxTimeoutCallback();});

}

void SlimSerial::setTimeout(float timeout_ms){

	if(m_timeout_htim!=NULL){

		HAL_TIM_Base_Stop_IT(m_timeout_htim); //stop the timer in case  it is running

		__HAL_TIM_SET_COUNTER(m_timeout_htim,0); //reset the timer counter

		__HAL_TIM_SET_AUTORELOAD(m_timeout_htim, std::lround(timeout_ms*1000)); //convert ms to us

		HAL_TIM_Base_Start_IT(m_timeout_htim); //start the timer to measure tx rx timeout
	}
}

void SlimSerial::stopTimeout(){

	if(m_timeout_htim!=NULL){
		HAL_TIM_Base_Stop_IT(m_timeout_htim); //stop the timer in case  it is running
	}
}

#endif //ANY_TIMEOUT_TIMER_USED

SD_USART_StatusTypeDef SlimSerial::config9bitMode(){
 	//check 9bit mode bit is set
 	if(m_9bits_mode==1){
 		if(m_huart->Init.WordLength != UART_WORDLENGTH_9B){

 			//otherwise, set to 9bit mode
 			m_huart->Init.WordLength = UART_WORDLENGTH_9B;
 			if (HAL_UART_Init(m_huart) != HAL_OK)
 			{
 				//error handling
 				m_9bits_mode_error = 1;
 				return SD_USART_ERROR;
 			}
 		}

 		//check tx DMA to be 16bit
 		if(m_tx_mode==SLIMSERIAL_TX_MODE_DMA){
 			if(m_huart->hdmatx->Init.MemDataAlignment != DMA_MDATAALIGN_HALFWORD ||
 			   m_huart->hdmatx->Init.PeriphDataAlignment != DMA_PDATAALIGN_HALFWORD
 			   ){
 				m_huart->hdmatx->Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
 				m_huart->hdmatx->Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;


 				if (HAL_DMA_Init(m_huart->hdmatx) != HAL_OK)
 				{
 					//error handling
 					m_9bits_mode_error = 1;
 					return SD_USART_ERROR;
 				}

 			}
 		}


 		//check rx DMA to be 16bit
 		//if rx is enabled, it must use DMA
 		if(m_rx_mode!=SLIMSERIAL_RX_MODE_OFF){
 			if(m_huart->hdmarx->Init.MemDataAlignment != DMA_MDATAALIGN_HALFWORD ||
 			   m_huart->hdmarx->Init.PeriphDataAlignment != DMA_PDATAALIGN_HALFWORD
 			   ){

 				//otherwise, set to 16bit mode
 				m_huart->hdmarx->Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
 				m_huart->hdmarx->Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;


 				if (HAL_DMA_Init(m_huart->hdmarx) != HAL_OK)
 				{
 					//error handling
 					m_9bits_mode_error = 1;
 					return SD_USART_ERROR;
 				}
 			}
 		}
 	}
 	else{
 		if(m_huart->Init.WordLength != UART_WORDLENGTH_8B){

			//otherwise, set to 9bit mode
			m_huart->Init.WordLength = UART_WORDLENGTH_8B;
			if (HAL_UART_Init(m_huart) != HAL_OK)
			{
				//error handling
				m_9bits_mode_error = 1;
				return SD_USART_ERROR;
			}
		}

 		//check tx DMA to be 8bit
 		if(m_tx_mode==SLIMSERIAL_TX_MODE_DMA){
 			if(m_huart->hdmatx->Init.MemDataAlignment != DMA_MDATAALIGN_BYTE ||
 			   m_huart->hdmatx->Init.PeriphDataAlignment != DMA_PDATAALIGN_BYTE
 			   ){
 				m_huart->hdmatx->Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
 				m_huart->hdmatx->Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
 				if (HAL_DMA_Init(m_huart->hdmatx) != HAL_OK)
 				{
 					//error handling
 					m_9bits_mode_error = 1;
 					return SD_USART_ERROR;
 				}
 			}
 		}

 		//check rx DMA to be 8bit
 		//if rx is enabled, it must use DMA
 		if(m_rx_mode!=SLIMSERIAL_RX_MODE_OFF){
 			if(m_huart->hdmarx->Init.MemDataAlignment != DMA_MDATAALIGN_BYTE ||
 			   m_huart->hdmarx->Init.PeriphDataAlignment != DMA_PDATAALIGN_BYTE
 			   ){

 				//otherwise, set to 8bit mode
 				m_huart->hdmarx->Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
 				m_huart->hdmarx->Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

 				if (HAL_DMA_Init(m_huart->hdmarx) != HAL_OK)
 				{
 					//error handling
 					m_9bits_mode_error = 1;
 					return SD_USART_ERROR;
 				}
 			}
 		}
 	}
 	return SD_USART_OK;
}

//only support 4bit address
SD_USART_StatusTypeDef SlimSerial::config9bitRxAddress(uint8_t rx_address){


	//
	m_9bits_mode_address_rx = rx_address & 0x0F; 			//mask to 4 bits

	if (HAL_MultiProcessor_Init(m_huart,m_9bits_mode_address_rx,UART_WAKEUPMETHOD_ADDRESSMARK) != HAL_OK)
	{
		//error handling
		m_9bits_mode_error = 1;
		Error_Handler();
	}

	m_9bits_mode_error = 0;
#if defined(__STM32F0xx_HAL_H)
	HAL_MultiProcessor_EnableMuteMode(m_huart);
#endif
	HAL_MultiProcessor_EnterMuteMode(m_huart);

	m_enable_rx_wake_up = true;

	return SD_USART_OK;

}

//only support 4bit address
void SlimSerial::config9bitTxAddress(uint8_t tx_address){

	m_9bits_mode_address_tx = tx_address & 0x0F; 			//mask to 4 bits
}

 HAL_StatusTypeDef SlimSerial::createRxTasks(){

/********* prevent name conversion warning by changing thread name from char* to const char*    ****************/
 typedef struct os_thread_def_modified  {
   const char                   *name;        ///< Thread name
   os_pthread             pthread;      ///< start address of thread function
   osPriority             tpriority;    ///< initial thread priority
   uint32_t               instances;    ///< maximum number of instances of that thread function
   uint32_t               stacksize;    ///< stack size requirements in bytes; 0 is default stack size
 #if( configSUPPORT_STATIC_ALLOCATION == 1 )
   uint32_t               *buffer;      ///< stack buffer for static allocation; NULL for dynamic allocation
   osStaticThreadDef_t    *controlblock;     ///< control block to hold thread's data for static allocation; NULL for dynamic allocation
 #endif
 } osThreadDef_t_modified;

 #define osThreadStaticDef_modified(name, thread, priority, instances, stacksz, buffer, control)  \
 const osThreadDef_t_modified os_thread_def_##name = \
 { #name, (thread), (priority), (instances), (stacksz), (buffer), (control) }

 uint16_t rxTasksize=(m_rx_mode==1?SLIMSERIAL_RX_TASK_BUFFER_SIZE:SLIMSERIAL_RX_TASK_BUFFER_SIZE_MINIMAL);

#if ENABLE_SLIMSERIAL_USART1
	if(m_huart==&huart1){

		osThreadStaticDef_modified(rx1Task, rxTaskFuncImpl, osPriorityAboveNormal, 0, rxTasksize, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx1Task), &slimSerial1);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART2
	if(m_huart==&huart2){
		osThreadStaticDef_modified(rx2Task, rxTaskFuncImpl, osPriorityLow, 0, rxTasksize, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx2Task), &slimSerial2);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART3
	if(m_huart==&huart3){
		osThreadStaticDef_modified(rx3Task, rxTaskFuncImpl, osPriorityHigh, 0, rxTasksize, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx3Task), &slimSerial3);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART4
	if(m_huart==&huart4){
		osThreadStaticDef_modified(rx4Task, rxTaskFuncImpl, osPriorityHigh, 0, rxTasksize, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx4Task), &slimSerial4);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART5
	if(m_huart==&huart5){
		osThreadStaticDef_modified(rx5Task, rxTaskFuncImpl, osPriorityAboveNormal, 0, rxTasksize, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx5Task), &slimSerial5);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART6
	if(m_huart==&huart6){
		osThreadStaticDef_modified(rx6Task, rxTaskFuncImpl, osPriorityNormal, 0, rxTasksize, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx6Task), &slimSerial6);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART7
	if(m_huart==&huart7){
		osThreadStaticDef_modified(rx7Task, rxTaskFuncImpl, osPriorityHigh, 0, rxTasksize, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx7Task), &slimSerial7);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART8
	if(m_huart==&huart8){
		osThreadStaticDef_modified(rx8Task, rxTaskFuncImpl, osPriorityHigh, 0, rxTasksize, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx8Task), &slimSerial8);
		return HAL_OK;
	}
#endif



	return HAL_ERROR;
}









void SlimSerial::addRxFrameCallback(std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes)> &frameCallbackFunc){
	m_frameCallbackFuncArray[m_frameCallbackFuncNumber++] = frameCallbackFunc;
	m_frameCallbackFuncNumber_all++;
	if(m_frameCallbackFuncNumber_all>SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN-1){
		m_frameCallbackFuncNumber_all=SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN-1;
		m_frameCallbackFuncNumber--;
	}
};
void SlimSerial::addRxFrameCallback(void (*frameCallbackFunc)(SlimSerial *,uint8_t *,uint16_t )){
	m_frameCallbackFuncArray_C[m_frameCallbackFuncNumber_C++] = frameCallbackFunc;
	m_frameCallbackFuncNumber_all++;
	if(m_frameCallbackFuncNumber_all>SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN-1){
		m_frameCallbackFuncNumber_all=SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN-1;
		m_frameCallbackFuncNumber_C--;
	}
};


void SlimSerial::addHeaderFilter(uint8_t h1,uint8_t h2){
	 headerFilter[headerFilter_num][0]=h1;
	 headerFilter[headerFilter_num][1]=h2;
	 if(headerFilter_num<SLIMSERIAL_HEADER_FILTER_MAX_LEN){
		 headerFilter_num++;
	 }
	 toggleHeaderFilter(true);
}
void SlimSerial::toggleHeaderFilter(bool filterOn){
	headerFilterOn = filterOn;
}

bool SlimSerial::applyHeaderFilter(uint8_t h1In,uint8_t h2In){
	if(!headerFilterOn)
		return true;

	for(int i=0;i<headerFilter_num;i++){
		if(h1In==headerFilter[i][0] && h2In==headerFilter[i][1])
			return true;
	}
	return false;
}


void SlimSerial::addAddressFilter(uint8_t address){
	 addressFilter[addressFilter_num]=address;
	 if(addressFilter_num<SLIMSERIAL_ADDRESS_FILTER_MAX_LEN){
		 addressFilter_num++;
	 }
	 m_address = address; //set the address to be the last added address

	 toggleAddressFilter(true);

}
void SlimSerial::toggleAddressFilter(bool filterOn){
	addressFilterOn = filterOn;
}
bool SlimSerial::applyAddressFilter(uint8_t addressIn){
	if(!addressFilterOn)
		return true;

	/*add custom address filter here*/

	//internal address whitelist
	for(int i=0;i<addressFilter_num;i++){
		if(addressIn==addressFilter[i])
			return true;
	}

	return false;
}


void SlimSerial::addFuncodeFilter(uint8_t funcodeIn){
	funcodeFilter[funcodeFilter_num]=funcodeIn;
		 if(funcodeFilter_num<SLIMSERIAL_FUNCODE_FILTER_MAX_LEN){
			 funcodeFilter_num++;
		 }
		 toggleFuncodeFilter(true);
}
void SlimSerial::toggleFuncodeFilter(bool filterOn){
	funcodeFilterOn = filterOn;
}
bool SlimSerial::applyFuncodeFilter(uint8_t funcodeIn){
	if(!funcodeFilterOn)
		return true;

	/*add custom address filter here*/



	//internal address whitelist
	for(int i=0;i<funcodeFilter_num;i++){
		if(funcodeIn==funcodeFilter[i])
			return true;
	}

	return false;
}


void SlimSerial::toggle485Tx(bool txOn){
	if(Tx_EN_Port)
		HAL_GPIO_WritePin(Tx_EN_Port,Tx_EN_Pin,(txOn?GPIO_PIN_SET:GPIO_PIN_RESET));
}

SD_BUF_INFO &SlimSerial::getRxFrame(){
	return m_rx_last;
};


void SlimSerial::clearRxFrame(){
	memset(m_rx_last.pdata, 0, m_rx_last.dataBytes);
};

SD_USART_StatusTypeDef &SlimSerial::getRxStatus(){
	return m_rx_status;
};

void SlimSerial::setRxFrameType(uint8_t rx_frame_type){
	m_rx_frame_type=rx_frame_type;
}
uint8_t SlimSerial::getRxFrameType(){
	return m_rx_frame_type;
}



SD_USART_StatusTypeDef SlimSerial::transmitFrame(uint16_t address,uint16_t fcode,uint8_t *payload,uint16_t payloadBytes){

	if(getProxyMode()==SLIMSERIAL_TXRX_NORMAL){
		return transmitFrameLL(address,fcode,payload,payloadBytes);
	}
	else{
		return SD_USART_ERROR;
	}
}


//this function will be executed in an async thread
SD_USART_StatusTypeDef SlimSerial::transmitData(uint8_t *pdata,uint16_t dataBytes){
	if(getProxyMode()==SLIMSERIAL_TXRX_NORMAL){
		return transmitDataLL(pdata,dataBytes);
	}
	else{
		return SD_USART_ERROR;
	}
}

//this function will be executed in an async thread
SD_USART_StatusTypeDef SlimSerial::transmitFrameLL(uint16_t address,uint16_t fcode,uint8_t *payload,uint16_t payloadBytes){

	//assemble tx frame in internal buffer,not queued
	SD_BUF_INFO sd_buf_info = bufferTxFrame(address,fcode,payload,payloadBytes);

	//enqueue the buffered data
	m_tx_queue_meta.push(sd_buf_info);

	//enqueue and transmit
	return transmitLL();
}
//this function will be executed in an async thread
SD_USART_StatusTypeDef SlimSerial::transmitDataLL(uint8_t *pdata,uint16_t dataBytes){

	//buffer data into internal buffer, not queued
	SD_BUF_INFO sd_buf_info=bufferTxData(pdata,dataBytes);

	//enqueue the buffered data
	m_tx_queue_meta.push(sd_buf_info);

	//enqueue and transmit
	return transmitLL();
}

uint32_t SlimSerial::readBuffer(uint8_t *pdata,uint16_t dataBytes,uint32_t timeout){

	uint32_t readN=0;
	uint32_t leftN=dataBytes;
	uint32_t thisN=0;

	uint32_t timeoutPoint= HAL_GetTick()+timeout+1;
	while( leftN >0 ){
		thisN = m_rx_circular_buf.out(&pdata[readN], leftN);
		readN +=thisN;
		leftN -=thisN;
		if(HAL_GetTick() >= timeoutPoint){
			break;
		}

	}
	return readN;


}
SD_USART_StatusTypeDef SlimSerial::transmitLL(){

	//try to trigger a transmit one the queue's back. This will not take effect is the Tx is already ongoing
	m_tx_time_start = currentTime_us();

	m_tx_once++;

	toggle485Tx(true);
	HAL_StatusTypeDef ret=HAL_OK;

	if(m_9bits_mode){
			uint16_t *pbuf=(uint16_t*)(m_tx_queue_meta.back().pdata);
			uint16_t databytes=m_tx_queue_meta.back().dataBytes + 1; //for 9-bit mode, the address byte is not included in the tx dataBytes
		 if(m_tx_mode==SLIMSERIAL_TX_MODE_BLOCK){
			//ret=HAL_UART_Transmit(m_huart,m_tx_queue_meta.back().pdata,m_tx_queue_meta.back().dataBytes,1000);//too slow to alter Tx_En. changed for faster Tx_En toggle
			USART_TypeDef *uart = m_huart->Instance;


			while(databytes-->0){
	#if defined(__STM32F0xx_HAL_H)
				uart->TDR =  *pbuf;
	#elif defined(__STM32F4xx_HAL_H) || defined(__STM32F1xx_HAL_H)
				uart->DR =  *pbuf;
	#endif
				pbuf++;
				while(!__HAL_UART_GET_FLAG(m_huart, UART_FLAG_TC));
			}


			if(Tx_EN_Port){
					Tx_EN_Port->BSRR = (uint32_t)Tx_EN_Pin << 16U;
			}
			txCpltCallback();

		}
		else if(m_tx_mode==SLIMSERIAL_TX_MODE_DMA){
			ret=HAL_UART_Transmit_DMA(m_huart,(const uint8_t *)pbuf,databytes);
		}
		else if(m_tx_mode==SLIMSERIAL_TX_MODE_IT){
			ret=HAL_UART_Transmit_IT(m_huart,(const uint8_t *)pbuf,databytes);
		}
	}
	else{
		uint8_t *pbuf=m_tx_queue_meta.back().pdata;
		uint16_t databytes=m_tx_queue_meta.back().dataBytes;
		 if(m_tx_mode==SLIMSERIAL_TX_MODE_BLOCK){
			//ret=HAL_UART_Transmit(m_huart,m_tx_queue_meta.back().pdata,m_tx_queue_meta.back().dataBytes,1000);//too slow to alter Tx_En. changed for faster Tx_En toggle
			USART_TypeDef *uart = m_huart->Instance;

			while(databytes-->0){
 #if defined(__STM32F0xx_HAL_H)
				uart->TDR =  *pbuf;
 #elif defined(__STM32F4xx_HAL_H) || defined(__STM32F1xx_HAL_H)
				uart->DR =  *pbuf;
 #endif
				pbuf++;
				while(!__HAL_UART_GET_FLAG(m_huart, UART_FLAG_TC));
			}

			if(Tx_EN_Port){
					Tx_EN_Port->BSRR = (uint32_t)Tx_EN_Pin << 16U;
			}
		txCpltCallback();

		}
		else if(m_tx_mode==SLIMSERIAL_TX_MODE_DMA){
			ret=HAL_UART_Transmit_DMA(m_huart,pbuf,databytes);
		}
		else if(m_tx_mode==SLIMSERIAL_TX_MODE_IT){
			ret=HAL_UART_Transmit_IT(m_huart,pbuf,databytes);
		}
	}

	if(ret==HAL_OK || (ret==HAL_BUSY && !m_tx_queue_meta.empty())){

		return SD_USART_OK;
	}
	else{
		return SD_USART_ERROR;
	}
}

SD_BUF_INFO SlimSerial::bufferDataToU16withAddress(uint16_t *pDes,uint8_t *pSrc,uint16_t datalen,uint8_t prefix_address) {
	SD_BUF_INFO sd_buf_info;

	uint16_t *pBuf_U16 = (uint16_t *)pDes;

	//add the address byte with the 9's bit set
	*pBuf_U16++ =  (uint16_t)(prefix_address | 0x100); //set the 9th bit

	//copy data from U8 to U16 buffer
	for(int i=0;i<datalen;i++){
		*pBuf_U16++ = *pSrc++;
	}

	sd_buf_info.pdata = (uint8_t *)pDes;
	sd_buf_info.dataBytes= datalen;   //for 9-bit mode, the address byte is not included in the tx dataBytes


	return sd_buf_info;
}


SD_BUF_INFO SlimSerial::bufferDataTo(uint8_t *pDes,uint8_t *pSrc,uint16_t datalen) {
	SD_BUF_INFO sd_buf_info;

	uint8_t *pBuf_U8 =(uint8_t *)pDes;

	//directly copy data from U8 to U8 buffer
	memcpy(pBuf_U8, pSrc, datalen);

	sd_buf_info.pdata = pDes;
	sd_buf_info.dataBytes= datalen;

	return sd_buf_info;
}


SD_BUF_INFO SlimSerial::bufferTxData(uint8_t *pdata,uint16_t datalen) {

	//internal next buffer bank
	m_tx_buf_ind++;
	if(m_tx_buf_ind>=m_tx_queue_size){
		m_tx_buf_ind = 0;
	}

	//copy data
	int ind = m_tx_buf_ind*m_tx_queue_buf_single_size;

	if(m_9bits_mode){
		uint16_t *pBuf_U16 = ((uint16_t *)m_tx_queue_buf) + ind;
		return bufferDataToU16withAddress(pBuf_U16, pdata, datalen,m_9bits_mode_address_tx);
	}
	else{
		uint8_t *pBuf_U8 =((uint8_t *)m_tx_queue_buf) + ind;
		return bufferDataTo(pBuf_U8, pdata, datalen);

	}
}

SD_BUF_INFO SlimSerial::bufferTxFrame(uint16_t address,uint16_t fcode,uint8_t *payload,uint16_t payloadBytes) {
	SD_BUF_INFO sd_buf_info;
	//next buffer bank
	m_tx_buf_ind++;
	if(m_tx_buf_ind>=m_tx_queue_size){
		m_tx_buf_ind = 0;
	}

	//assemble data
	int ind = m_tx_buf_ind*m_tx_queue_buf_single_size;
	if(m_9bits_mode){
		uint16_t *pBuf_U16 = ((uint16_t *)m_tx_queue_buf) + ind;
		sd_buf_info.pdata = (uint8_t *)pBuf_U16;

		//add the address byte with the 9's bit set
		*pBuf_U16++ = (uint16_t)((address&0x0F) | 0x100);

		//add the header address and payload bytes
		*pBuf_U16++ = 0x5A;
		*pBuf_U16++ = 0xA5;
		*pBuf_U16++ = address;
		*pBuf_U16++ = payloadBytes;
		*pBuf_U16++ = fcode;
		
		//copy data from U8 to U16 buffer
		for(int i=0;i<payloadBytes;i++){
			*pBuf_U16++ = *payload++;
		}

		//calculate CRC (not including the 9-bit address)
		uint16_t crc = SD_CRC_Calculate_U16LB(((uint16_t *)sd_buf_info.pdata)+1, payloadBytes + 5);
		*pBuf_U16++ = (uint16_t) (crc &0xFF);
		*pBuf_U16++ = (uint16_t) ((crc >> 8)&0xFF);

		sd_buf_info.dataBytes= payloadBytes + 7;  //for 9-bit mode, the address byte is not included in the tx dataBytes

	}
	else{
		uint8_t *pBuf_U8 =((uint8_t *)m_tx_queue_buf) + ind;
		sd_buf_info.pdata =pBuf_U8;

		//add the header address and payload bytes
		*pBuf_U8++ = 0x5A;
		*pBuf_U8++ = 0xA5;
		*pBuf_U8++ = address;
		*pBuf_U8++ = payloadBytes;
		*pBuf_U8++ = fcode;

		//copy data from U8 to U8 buffer
		memcpy(pBuf_U8,payload,payloadBytes);
		pBuf_U8 += payloadBytes;

		//calculate CRC
		uint16_t crc = SD_CRC_Calculate(sd_buf_info.pdata, payloadBytes + 5);
		*pBuf_U8++ = (uint8_t) (crc &0xFF);
		*pBuf_U8++ = (uint8_t)(crc >> 8)&0xFF;

		sd_buf_info.dataBytes= payloadBytes + 7;

	}

	return sd_buf_info;
}





SD_BUF_INFO &SlimSerial::transmitReceiveData(uint8_t *pData,uint16_t dataBytes,float timeout_ms, bool frameTypeFilterOn){
	if(getProxyMode()==SLIMSERIAL_TXRX_TRANSPARENT){
		m_rx_status = SD_USART_ERROR;
		m_rx_last.dataBytes=0;
		return  m_rx_last;
	}
	//record txrx threadID
	m_rx_status = SD_USART_BUSY;

	//record current frame type
	uint8_t rxFrameType_temp = m_rx_frame_type;

	//temporarily switch off frame type check
	if(frameTypeFilterOn==false)
		m_rx_frame_type = SLIMSERIAL_FRAME_TYPE_0_ANY;


	//only if not in the same thread
	if(rxThreadID !=  (uint32_t *) osThreadGetId()){
		txrxThreadID = (uint32_t *) osThreadGetId();
		//clear previous nofification value that every valid frame would trigger
		xTaskNotifyStateClear((TaskHandle_t)(txrxThreadID));//ulTaskNotifyValueClear((TaskHandle_t)(txrxThreadID),0xffffffff);
	}

	//setup accurate timeout timer ifconfigured
#if ANY_TIMEOUT_TIMER_USED
	setTimeout(timeout_ms);
#endif
	//start a tx frame
	transmitData(pData, dataBytes);

	//only wait for rx nofification if not in the same thread
	if(txrxThreadID != rxThreadID){
		uint32_t temp =  std::lround(timeout_ms);
		uint32_t timeoutMS = (temp==1) ? temp+1: temp; //1ms timeout cannot be guaranteed by freeRTOS, so add 1ms to it.
		uint32_t ulTaskNotifyRet = ulTaskNotifyTake(pdTRUE,timeoutMS);//we are waiting for the setTimer timeout to notify a value SLIMSERIAL_TIMEOUT_NOTIFICATION_BIT.

		//timout from ulTask timeout or  from the timer
		if(ulTaskNotifyRet==0 || (ulTaskNotifyRet & SLIMSERIAL_TIMEOUT_NOTIFICATION_BIT)!=0){
			m_rx_last.dataBytes=0;
			m_txrx_time_cost = currentTime_us()-m_tx_time_start;
			if (m_rx_status==SD_USART_BUSY){
				m_rx_status = SD_USART_TIMEOUT;
			}
		}
		else {//from rx frame notification give(increment by 1)
			m_rx_status = SD_USART_OK;

		}
	}
	else{
		HAL_Delay(10);

	}

#if ANY_TIMEOUT_TIMER_USED
	stopTimeout(); //stop the timer
#endif

	//restore frame type
	m_rx_frame_type = rxFrameType_temp;

	return m_rx_last;
}


SD_BUF_INFO &SlimSerial::transmitReceiveFrame(uint16_t address,uint16_t fcode,uint8_t *payload,uint16_t payloadBytes,float timeout_ms){
	if(getProxyMode()==SLIMSERIAL_TXRX_TRANSPARENT){
		m_rx_status = SD_USART_ERROR;
		m_rx_last.dataBytes=0;
		return  m_rx_last;
	}
 
	//record txrx threadID
	m_rx_status = SD_USART_BUSY;

	//only if not in the same thread
	if(rxThreadID !=  (uint32_t *) osThreadGetId()){
		txrxThreadID = (uint32_t *) osThreadGetId();
		//clear previous nofification value that every valid frame would trigger
		xTaskNotifyStateClear((TaskHandle_t)(txrxThreadID));//ulTaskNotifyValueClear((TaskHandle_t)(txrxThreadID),0xffffffff);
	}

	//setup accurate timeout timer ifconfigured
#if ANY_TIMEOUT_TIMER_USED
	setTimeout(timeout_ms);
#endif

	//start a tx frame
	transmitFrame(address, fcode,payload,payloadBytes);

	//only wait for rx nofification if not in the same thread
	if(txrxThreadID != rxThreadID){
		uint32_t temp =  std::lround(timeout_ms);
		uint32_t timeoutMS = (temp==1) ? temp+1: temp; //1ms timeout cannot be guaranteed by freeRTOS, so add 1ms to it.
		uint32_t ulTaskNotifyRet = ulTaskNotifyTake(pdTRUE,timeoutMS);
		//timout
		if(ulTaskNotifyRet==0 || (ulTaskNotifyRet & SLIMSERIAL_TIMEOUT_NOTIFICATION_BIT)!=0){
			m_rx_last.dataBytes=0;
			m_txrx_time_cost = currentTime_us()-m_tx_time_start;
			if (m_rx_status==SD_USART_BUSY){
				m_rx_status = SD_USART_TIMEOUT;
			}
		}
		else {//from rx frame notification give(increment by 1)
			m_rx_status = SD_USART_OK;

		}
	}
	else{
		HAL_Delay(10);
	}

#if ANY_TIMEOUT_TIMER_USED
	stopTimeout(); //stop the timer
#endif

	return m_rx_last;

}


HAL_StatusTypeDef SlimSerial::Slim_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
	HAL_StatusTypeDef status;
	int locked=0;
	if(m_huart->Lock == HAL_LOCKED){
		locked=1;
		m_huart->Lock = HAL_UNLOCKED;
	}
	status = HAL_UARTEx_ReceiveToIdle_DMA(huart,pData,Size);
	if(locked){
		m_huart->Lock = HAL_LOCKED;
	}
	return status;
}

void SlimSerial::start_Rx_DMA_Idle_Circular(){
	toggle485Tx(false);
	m_rx_circular_buf.clear(); //clear the circular buffer before starting a new receive
	while(Slim_UARTEx_ReceiveToIdle_DMA(m_huart, m_rx_circular_buf.buffer, m_rx_circular_buf.bufferSize) != HAL_OK)
	{
		HAL_UART_AbortReceive(m_huart);
//		HAL_UART_Abort
//		if(m_huart->hdmarx->Lock == HAL_LOCKED){
//			m_huart->hdmarx->Lock = HAL_UNLOCKED;
//			m_huart->hdmarx->State =  HAL_DMA_STATE_READY;
//		}
	}

	__HAL_DMA_DISABLE_IT(m_huart->hdmarx, DMA_IT_HT); // we don't need half-transfer interrupt
	__HAL_DMA_DISABLE_IT(m_huart->hdmarx, DMA_IT_TC); // we don't need transfer complete interrupt

}


SD_BUF_INFO &SlimSerial::modbusRead(uint8_t des, uint16_t reg_address,uint16_t reg_count,uint16_t timeoutMS){
	std::array<uint8_t,8> readFrame={des,0x03,(uint8_t)(reg_address>>8),(uint8_t)(reg_address&0xFF),(uint8_t)(reg_count>>8),(uint8_t)(reg_count&0xFF),0,0};
	uint16_t crc = SD_CRC_Calculate(&readFrame[0], 6);
	readFrame[6] = (uint8_t) (crc &0xFF);
	readFrame[7] = (uint8_t)(crc >> 8)&0xFF;

	return transmitReceiveData(&readFrame[0],sizeof(readFrame),timeoutMS);
}



void SlimSerial::txCpltCallback()
{
	//fast toggle rx
	toggle485Tx(false);


	//record transfer time
	m_tx_time_end = currentTime_us();
	m_tx_time_cost = m_tx_time_end - m_tx_time_start;


	//record the last tx info
	m_tx_last= m_tx_queue_meta.back();
	m_totalTxBytes += m_tx_last.dataBytes;
	m_totalTxFrames ++;

	//dequeue the last tx info
	m_tx_queue_meta.pop();


	//trigger another tx if tx queue is not empty. Don't access back() if the queue is empty.
	if(!m_tx_queue_meta.empty()){
		transmitLL();
	}
}

//In circular mode, this callback is called when
//1. the circular buffer is full, which means the NDTR is 0, but the frame is not complete yet
//2. a full frame with idle line detected, which means the NDTR is not 0, but the idle line is detected
void SlimSerial::rxCpltCallback(uint16_t data_len)
{

	m_rx_time_start = currentTime_us();
	m_tx_once=0;
	

	//get current buffer index based on current NDTR
	//NDTR   N 	 	N-1 	N-2 	N-3 	N-4    	...	  	1
	//head   0		1		2		3	    4	 	...		N-1

	uint32_t exactHead = m_rx_circular_buf.bufferSize - (uint16_t)__HAL_DMA_GET_COUNTER(m_huart->hdmarx);
	uint32_t dlen = m_rx_circular_buf.in_dummyU16_with_new_head(exactHead); //dummy in to update the circular buffer size
	m_totalRxBytes += dlen;

	if(m_rx_mode==1){
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;

		vTaskNotifyGiveFromISR((TaskHandle_t)(rxThreadID),&xHigherPriorityTaskWoken);

		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}
	else if(m_rx_mode==2){
		frameParser();
	}

}

void SlimSerial::txrxTimeoutCallback(){
	//notify the txrx thread that a timeout has occurred by setting the notification value bit SLIMSERIAL_TIMEOUT_NOTIFICATION_BIT
   if (txrxThreadID != NULL) {
	   uint32_t pulPreviousNotificationValue=0;
	   BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	   xTaskGenericNotifyFromISR((TaskHandle_t)(txrxThreadID),SLIMSERIAL_TIMEOUT_NOTIFICATION_BIT,eSetBits,&pulPreviousNotificationValue,&xHigherPriorityTaskWoken);
	   portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
   }
};

void SlimSerial::callRxCallbackArray(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes){
	m_rx_time_callback_enter = currentTime_us();
	for(int i=0;i<m_frameCallbackFuncNumber;i++){
		m_frameCallbackFuncArray[i](slimSerialDev,pdata,databytes);
	}
	for(int i=0;i<m_frameCallbackFuncNumber_C;i++){
		m_frameCallbackFuncArray_C[i](slimSerialDev,pdata,databytes);
	}
	m_rx_time_callback_cost = currentTime_us() - m_rx_time_callback_enter;
};


//frame parser shouldn't care about the 9 bits mode, since it is already handled in lower transmission layer
void SlimSerial::frameParser(){

	////discard the 9th bit address byte if necessary
	if(m_9bits_mode && m_rx_circular_buf.peekAt_HB(0)==1){
		m_rx_circular_buf.discardN(1);
	}

	m_parse_remainingBytes=m_rx_circular_buf.availableData();

	if(m_parse_remainingBytes<=0){
		return ;
	}
#if SLIMSERIAL_FRAME_TYPE_0_ANY_USED==1
	if(m_rx_frame_type == SLIMSERIAL_FRAME_TYPE_0_ANY){

		//temperory change to frame type 1 if got 5A A5 header
		if(m_parse_remainingBytes>=2 && m_rx_circular_buf.peekAt(0) == 0x5A && m_rx_circular_buf.peekAt(1)== 0xA5){
			m_rx_frame_type_ori = m_rx_frame_type;
			m_rx_frame_type=SLIMSERIAL_FRAME_TYPE_1;
		}
		else{
			m_rx_circular_buf.out(m_rx_last.pdata, m_parse_remainingBytes);

			m_rx_last.dataBytes = m_parse_remainingBytes;

			receivedACK = true;

			m_totalRxFrames++;
			m_rx_time_validFrame = currentTime_us();
			m_rx_time_validFrame_cost = m_rx_time_validFrame - m_rx_time_start;

			callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);

			//notify potential txrx thread
			if(m_rx_mode==1){
				if (txrxThreadID != NULL) {
					xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
				}
			}
			else if(m_rx_mode==2){
				if (txrxThreadID != NULL) {
					BaseType_t xHigherPriorityTaskWoken = pdFALSE;
					xTaskNotifyFromISR((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite,&xHigherPriorityTaskWoken);
				}
			}

			m_rx_status = SD_USART_OK;
		}

	}
#endif //SLIMSERIAL_FRAME_TYPE_0_ANY_USED==1

	if(m_rx_frame_type==SLIMSERIAL_FRAME_TYPE_1){
		//std::unique_lock<std::mutex> lk_decode(decodeMtx);
		//5+N+2
		//Header1 + Header2 + Src + dataBytes +  Funcode  + data + crc16
		// dataBytes =   sizeof(data)
		if(getProxyMode()==SLIMSERIAL_TXRX_NORMAL){
			while (m_parse_remainingBytes >= 7) {



				//check header, current support 5A A5 and FF FF
				uint8_t header[2]={m_rx_circular_buf.peekAt(0),m_rx_circular_buf.peekAt(1)};
				if (applyHeaderFilter(header[0], header[1])) {

					//check address. disabled by default. Call toggleAddressFilter(True) to enable
					uint8_t addressIn = m_rx_circular_buf.peekAt(2);
					if(applyAddressFilter(addressIn)){

						//check funcode. disabled by default. Call toggleFuncodeFilter(True) to enable
						uint8_t funcodeIn = m_rx_circular_buf.peekAt(4);
						if(applyFuncodeFilter(funcodeIn)){

							//total frame length
							uint16_t expectedFrameBytes;
							if(lengthFilterOn){
								expectedFrameBytes = m_rx_circular_buf.peekAt(3) + 7;
							}
							else{
								expectedFrameBytes=m_parse_remainingBytes;
							}
							//check length
							if (expectedFrameBytes <= m_rx_frame_buf_size){

								if (expectedFrameBytes <= m_parse_remainingBytes) {

									//valid CRC
									uint16_t crc1 = m_rx_circular_buf.calculateCRC(expectedFrameBytes - 2);
									uint16_t crc2 = (uint16_t)m_rx_circular_buf.peekAt(expectedFrameBytes - 2) | ((uint16_t)m_rx_circular_buf.peekAt(expectedFrameBytes - 1))<<8;

									if (crc1 == crc2) {

										//read out one valid frame from ring buffer to m_rx_last
										m_rx_circular_buf.out(m_rx_last.pdata, expectedFrameBytes);
										m_rx_last.dataBytes = expectedFrameBytes;
										m_parse_remainingBytes -= expectedFrameBytes;
										//process frame

										receivedACK = true;

										m_totalRxFrames++;

										m_rx_time_validFrame = currentTime_us();
										m_rx_time_validFrame_cost = m_rx_time_validFrame - m_rx_time_start;
#if ENABLE_PROXY==1
										if(funcodeIn == FUNC_ENABLE_PROXY_INTERNAL){
											//enable proxy
											if(m_rx_last.dataBytes==14){
												uint8_t proxyPortIndex =  m_rx_last.pdata[5] ;
												uint32_t proxyPortBaudrate= m_rx_last.pdata[6] | ((uint32_t)m_rx_last.pdata[7])<<8 | ((uint32_t)m_rx_last.pdata[8])<<16 | ((uint32_t)m_rx_last.pdata[9])<<24;
												uint8_t enable_9bits_proxy = m_rx_last.pdata[10];
												uint8_t proxy_9bit_address = m_rx_last.pdata[11];
												enableProxy(proxyPortIndex,proxyPortBaudrate,enable_9bits_proxy,proxy_9bit_address);
											}

										}
										else if(funcodeIn == FUNC_DISABLE_PROXY_INTERNAL){
											//should take no effect. Anyway, we respond to the request
											disableProxy();
											ackProxy();
										}
										else{
#endif
											callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);
												//notify potential txrx thread
											if(m_rx_mode==1){
												if (txrxThreadID != NULL) {
													xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
												}
											}
											else if(m_rx_mode==2){
												if (txrxThreadID != NULL) {
													BaseType_t xHigherPriorityTaskWoken = pdFALSE;
													xTaskNotifyFromISR((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite,&xHigherPriorityTaskWoken);
												}
											}

											m_rx_status = SD_USART_OK;

											//after getting a valid frame 1, if the original type is frame_type_0, change it back
											if(m_rx_frame_type_ori==SLIMSERIAL_FRAME_TYPE_0_ANY){
												m_rx_frame_type = m_rx_frame_type_ori;
											}
											continue;
#if ENABLE_PROXY==1
										}
#endif
									}

									else {
										//bad crc
										  int discardN = m_rx_circular_buf.discardUntilNext(0x5A);
										  m_parse_remainingBytes -= discardN;
										m_rx_status = SD_USART_ERROR;
										continue;
									}

								} else {
									//unfinished frame
									m_rx_status = SD_USART_BUSY;
									break;

								}
							}
							else{//invalid length
								int discardN = m_rx_circular_buf.discardUntilNext(0x5A);
								m_parse_remainingBytes -= discardN;
								m_rx_status = SD_USART_ERROR;
								continue;
							}
						}
						else{//invalid funcode
							int discardN = m_rx_circular_buf.discardUntilNext(0x5A);
							m_parse_remainingBytes -= discardN;
							m_rx_status = SD_USART_ERROR;
							continue;
						}
					}
					else{//invalid address
						int discardN = m_rx_circular_buf.discardUntilNext(0x5A);
						m_parse_remainingBytes -= discardN;
						m_rx_status = SD_USART_ERROR;
						continue;
					}
				} else {//invalid header
					int discardN = m_rx_circular_buf.discardUntilNext(0x5A);
					m_parse_remainingBytes -= discardN;
					m_rx_status = SD_USART_ERROR;
					continue;
				}

			}
		}
#if ENABLE_PROXY==1
		else if(getProxyMode()==SLIMSERIAL_TXRX_TRANSPARENT){
			m_rx_circular_buf.out(m_rx_last.pdata, m_parse_remainingBytes);
			m_rx_last.dataBytes = m_parse_remainingBytes;
			m_totalRxFrames++;

			//In transparent mode, only FUNC_DISABLE_PROXY_INTERNAL is check.
			//further FUNC_ENABLE_PROXY_INTERNAL will be routed like normal data, enabling chained proxies.
			if( m_rx_last.dataBytes>=7 &&
				m_rx_last.pdata[0]==0x5A &&
				m_rx_last.pdata[1]==0xA5 &&
//				m_rx_last.pdata[2]==0x00 &&	//ignore source address
//				m_rx_last.pdata[3]==0x00 && //ignore data bytes
				m_rx_last.pdata[4]==((uint8_t)FUNC_DISABLE_PROXY_INTERNAL)
				){
				uint16_t crc1 = SD_CRC_Calculate(&(m_rx_last.pdata[0]), 5);
				uint16_t crc2 = m_rx_last.pdata[5] | ((uint16_t)m_rx_last.pdata[6])<<8 ;
				if(crc1 == crc2){
					//disable proxy
					disableProxy();
					ackProxy();
				}
			}
			else{

				proxyDelegateMessage(m_rx_last.pdata, m_rx_last.dataBytes);
			}
		}
#endif
	}
#if SLIMSERIAL_FRAME_TYPE_2_USED==1
	else if (m_rx_frame_type == SLIMSERIAL_FRAME_TYPE_2){
		//std::unique_lock<std::mutex> lk_decode(decodeMtx);

		//2+N+2
		//Header1 + Header2 + databytes + data + crc16
		//databytes = 1 + sizeof(data)
		while (m_parse_remainingBytes >= 4) {

			//check header, current support 5A A5 and FF FF
			uint8_t header[2]={m_rx_circular_buf.peekAt(0),m_rx_circular_buf.peekAt(1)};
			if (applyHeaderFilter(header[0], header[1])) {

				//total frame length
				uint16_t expectedFrameBytes;
				if(lengthFilterOn){
					expectedFrameBytes = m_rx_circular_buf.peekAt(2) + 4;
				}
				else{
					expectedFrameBytes=m_parse_remainingBytes;
				}
				//check length
				if (expectedFrameBytes <= m_rx_frame_buf_size){

					if (expectedFrameBytes <= m_parse_remainingBytes) {

						//valid CRC
						uint16_t crc1 = m_rx_circular_buf.calculateCRC(expectedFrameBytes - 2);
						uint16_t crc2 = (uint16_t)m_rx_circular_buf.peekAt(expectedFrameBytes - 2) | ((uint16_t)m_rx_circular_buf.peekAt(expectedFrameBytes - 1))<<8;

						if (crc1 == crc2) {

							//read out one valid frame from ring buffer to m_rx_last
							m_rx_circular_buf.out(m_rx_last.pdata, expectedFrameBytes);
							m_rx_last.dataBytes = expectedFrameBytes;
							m_parse_remainingBytes -= expectedFrameBytes;
							//process frame

							receivedACK = true;

							m_totalRxFrames++;
							m_rx_time_validFrame = currentTime_us();
							m_rx_time_validFrame_cost = m_rx_time_validFrame - m_rx_time_start;

							callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);



							//notify potential txrx thread
							if(m_rx_mode==1){
								if (txrxThreadID != NULL) {
									xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
								}
							}
							else if(m_rx_mode==2){
								if (txrxThreadID != NULL) {
									BaseType_t xHigherPriorityTaskWoken = pdFALSE;
									xTaskNotifyFromISR((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite,&xHigherPriorityTaskWoken);
								}
							}

							m_rx_status = SD_USART_OK;
							continue;

						}

						else {
							//bad crc
							int discardN = m_rx_circular_buf.discardUntilNext(0xFF);
							m_parse_remainingBytes -= discardN;
							m_rx_status = SD_USART_ERROR;
							continue;
						}

					} else {
						//unfinished frame
						m_rx_status = SD_USART_BUSY;
						break;

					}
				}
				else{//invalid length
					int discardN = m_rx_circular_buf.discardUntilNext(0xFF);
					m_parse_remainingBytes -= discardN;
					m_rx_status = SD_USART_ERROR;
					continue;
				}

			} else {//invalid header
				int discardN = m_rx_circular_buf.discardUntilNext(0xFF);
				m_parse_remainingBytes -= discardN;
				m_rx_status = SD_USART_ERROR;
				continue;
			}
		}
	}
#endif
#if SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM_USED==1
	else if(m_rx_frame_type==SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM){

		//std::unique_lock<std::mutex> lk_decode(decodeMtx);

		//modbus frame
		//src + funcode + data + crc16
		while (m_parse_remainingBytes >= 8) {

			//check address. disabled by default. Call toggleAddressFilter(True) to enable
			uint8_t addressIn = m_rx_circular_buf.peekAt(0);
			if(applyAddressFilter(addressIn)){

				//check funcode
				uint16_t funcodeIn = m_rx_circular_buf.peekAt(1);
				if(applyFuncodeFilter(funcodeIn)){

					uint16_t expectedFrameBytes =0 ;
					if (funcodeIn == 0x03) {
					  expectedFrameBytes  = 8;
					}
					else if(funcodeIn == 0x06){
					  expectedFrameBytes  =  m_rx_circular_buf.availableData();//special treatment for 0x06
					}
					else if (funcodeIn == 0x10) {
					  expectedFrameBytes  =  (uint16_t)(m_rx_circular_buf.peekAt(6)) + 9;
					}

					// got enough rx bytes
					if (m_parse_remainingBytes >= expectedFrameBytes) {
							//valid CRC
							uint16_t crc1 = m_rx_circular_buf.calculateCRC(expectedFrameBytes - 2);
							uint16_t crc2 = (uint16_t)m_rx_circular_buf.peekAt(expectedFrameBytes - 2) | ((uint16_t)m_rx_circular_buf.peekAt(expectedFrameBytes - 1))<<8;

							if (crc1 == crc2) {

								//read out one valid frame from ring buffer to m_rx_last
								m_rx_circular_buf.out(m_rx_last.pdata, expectedFrameBytes);
								m_rx_last.dataBytes = expectedFrameBytes;
								m_parse_remainingBytes -= expectedFrameBytes;
								//process frame

								receivedACK = true;

								m_totalRxFrames++;
								m_rx_time_validFrame = currentTime_us();
								m_rx_time_validFrame_cost = m_rx_time_validFrame - m_rx_time_start;

								callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);



								//notify potential txrx thread
								if(m_rx_mode==1){
									if (txrxThreadID != NULL) {
										xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
									}
								}
								else if(m_rx_mode==2){
									if (txrxThreadID != NULL) {
										BaseType_t xHigherPriorityTaskWoken = pdFALSE;
										xTaskNotifyFromISR((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite,&xHigherPriorityTaskWoken);
									}
								}
								m_rx_status = SD_USART_OK;
								continue;

							}

							else {
								//bad crc
								 if(funcodeIn == 0x06 && m_rx_circular_buf.availableData()<256){//special treatment for 0x06
								  m_rx_status = SD_USART_BUSY;
								  break;
								}
								else{
								  int discardN = m_rx_circular_buf.availableData();
								  m_rx_circular_buf.discardN(discardN);
								  m_parse_remainingBytes -= discardN;

								  continue;
								}

								m_rx_circular_buf.discardN(1);
								m_parse_remainingBytes--;
								m_rx_status = SD_USART_ERROR;
								continue;
							}
					} else {//unfinished frame
					  m_rx_status = SD_USART_BUSY;
					  break;
					}
				} else {
					//bad funcode
					m_rx_circular_buf.discardN(1);
					m_parse_remainingBytes--;
					m_rx_status = SD_USART_ERROR;
					continue;

				}
			}
			else{
				//bad address
				m_rx_circular_buf.discardN(1);
				m_parse_remainingBytes--;
				m_rx_status = SD_USART_ERROR;
				continue;
			}
		}
	}
#endif
#if SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM_USED==1
	else if(m_rx_frame_type==SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM){

			//std::unique_lock<std::mutex> lk_decode(decodeMtx);

			//modbus frame
			//src + funcodeIn + data + crc16
			while (m_parse_remainingBytes >= 5) {

				//check address. disabled by default. Call toggleAddressFilter(True) to enable
				uint8_t addressIn = m_rx_circular_buf.peekAt(0);
				if(applyAddressFilter(addressIn)){


					//check funcode
					uint16_t funcodeIn = m_rx_circular_buf.peekAt(1);
					if(applyFuncodeFilter(funcodeIn)){

//					if (funcodeIn == 0x03 || funcodeIn == 0x06 || funcodeIn == 0x10 || funcodeIn == (0x83) || funcodeIn == 0x86 || funcodeIn == 0x90) {

						 uint16_t expectedFrameBytes=0;
						if (funcodeIn == 0x03) {
						  expectedFrameBytes  = (uint8_t)(m_rx_circular_buf.peekAt(2)) + 5;
						}
						else if(funcodeIn == 0x06){
						  expectedFrameBytes  =  m_rx_circular_buf.availableData();//special treatment for 0x06
						}
						else if (funcodeIn == 0x10) {
						  expectedFrameBytes  =  8;
						}
						else{
							expectedFrameBytes = 5;//error reply frame
						}

						 if (m_parse_remainingBytes >= expectedFrameBytes) {
							//valid CRC
							uint16_t crc1 = m_rx_circular_buf.calculateCRC(expectedFrameBytes - 2);
							uint16_t crc2 = (uint16_t)m_rx_circular_buf.peekAt(expectedFrameBytes - 2) | ((uint16_t)m_rx_circular_buf.peekAt(expectedFrameBytes - 1))<<8;

							if (crc1 == crc2) {

								//read out one valid frame from ring buffer to m_rx_last
								m_rx_circular_buf.out(m_rx_last.pdata, expectedFrameBytes);
								m_rx_last.dataBytes = expectedFrameBytes;
								m_parse_remainingBytes -= expectedFrameBytes;
								//process frame

								receivedACK = true;

								m_totalRxFrames++;
								m_rx_time_validFrame = currentTime_us();
								m_rx_time_validFrame_cost = m_rx_time_validFrame - m_rx_time_start;

								callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);



								//notify potential txrx thread
								if(m_rx_mode==1){
									if (txrxThreadID != NULL) {
										xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
									}
								}
								else if(m_rx_mode==2){
									if (txrxThreadID != NULL) {
										BaseType_t xHigherPriorityTaskWoken = pdFALSE;
										xTaskNotifyFromISR((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite,&xHigherPriorityTaskWoken);
									}
								}

								m_rx_status = SD_USART_OK;
								continue;

							}

							else {
								//bad crc
								 if(funcodeIn == 0x06 && m_rx_circular_buf.availableData()<256){//special treatment for 0x06
								  m_rx_status = SD_USART_BUSY;
								  break;
								}
								else{
								  int discardN = m_rx_circular_buf.availableData();
								  m_rx_circular_buf.discardN(discardN);
								  m_parse_remainingBytes -= discardN;

								  continue;
								}
							}
						} else {  // not rx finished
							m_rx_status = SD_USART_BUSY;
						  break;
						}
					}
					else {
						//bad funcode
						m_rx_circular_buf.discardN(1);
						m_parse_remainingBytes--;
						m_rx_status = SD_USART_ERROR;
						continue;

					}
				}
				else{
					//bad address
					m_rx_circular_buf.discardN(1);
					m_parse_remainingBytes--;
					m_rx_status = SD_USART_ERROR;
					continue;

				}
			}
		}
#endif
	else if(m_rx_frame_type==SLIMSERIAL_FRAME_TYPE_NONE){

	}
	m_rx_time_end = currentTime_us();
	m_rx_time_cost = m_rx_time_end-m_rx_time_start;
	m_txrx_time_cost = m_rx_time_end-m_tx_time_start;
}

void SlimSerial::configRxDMACircularMode() {
	//if rx is enabled, ensure a rx DMA circular mode is set
	if(m_rx_mode!=SLIMSERIAL_RX_MODE_OFF){
		if(m_huart->hdmarx->Init.Mode != DMA_CIRCULAR){
			m_huart->hdmarx->Init.Mode = DMA_CIRCULAR;
			if (HAL_DMA_Init(m_huart->hdmarx) != HAL_OK)
			{
				//error handling
				Error_Handler();
			}
		}
	}
}

void SlimSerial::rxHandlerThread() {
	uint32_t ulTaskNotifyRet = 0;
	 /*get ready for receive*/
	rxThreadID = (uint32_t *)osThreadGetId();

	configRxDMACircularMode();

	config9bitMode();

#if ANY_TIMEOUT_TIMER_USED
	configTimeoutTimer();
#endif

	osDelay(20);

	start_Rx_DMA_Idle_Circular();

	/* Infinite loop */
	for (;;) {

		ulTaskNotifyRet = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		if(rxNeedRestart){
			rxNeedRestart=0;
			start_Rx_DMA_Idle_Circular();
			continue;
		}

		if (!(ulTaskNotifyRet && m_rx_circular_buf.availableData()>0))
			continue;

		if(m_rx_mode==1){
			frameParser();
		}


	}
}

uint32_t SlimSerial::getRxIdleTimeUs(){
	return currentTime_us()- m_rx_time_end;
}
uint32_t SlimSerial::getRxFrameIdleTimeUs(){
	return currentTime_us()- m_rx_time_validFrame;
}



void SlimSerial::restartRxFromISR(){
	rxNeedRestart=1;
	if(rxThreadID != NULL) {
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		vTaskNotifyGiveFromISR((TaskHandle_t)(rxThreadID),&xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}

}

SLIMSERIAL_PROXY_MODE SlimSerial::getProxyMode() {

    return m_proxy_mode;

}
#if ENABLE_PROXY==1
void SlimSerial::proxyDelegateMessage(uint8_t *pData,uint16_t databytes){
	//if proxy port is in 8 bit mode, we just transmit the data directly. pData is always 8 bits data in m_rx_last.pdata
	if(!m_enable_9bits_proxy){
		m_proxy_port->transmitDataLL(pData,databytes);
	}
	else{//otherwise, we may need to use a static larger buffer to support large frame size of YModem
		SD_BUF_INFO sd_buf_info = bufferDataToU16withAddress((uint16_t *)m_proxy_buffer, pData, databytes,m_proxy_9bit_address);

		//enqueue the buffered data
		m_proxy_port->m_tx_queue_meta.push(sd_buf_info);

		m_proxy_port->transmitLL();
	}
}

void SlimSerial::ackProxy(){
	transmitFrameLL(0x00,FUNC_ACK_PROXY_INTERNAL,NULL,0);
}
 


void SlimSerial::enableProxy(uint8_t proxy_port_index,uint32_t proxy_port_baudrate,uint8_t enable_9bits_proxy,uint8_t proxy_9bit_address){
	SlimSerial *proxy_port_=NULL;
	switch(proxy_port_index){
			#if ENABLE_SLIMSERIAL_USART1
			case 1:
				proxy_port_ = &slimSerial1;
				break;
			#endif
			#if ENABLE_SLIMSERIAL_USART2
			case 2:
				proxy_port_ = &slimSerial2;
				break;
			#endif
			#if ENABLE_SLIMSERIAL_USART3
			case 3:
				proxy_port_ = &slimSerial3;
				break;
			#endif
			#if ENABLE_SLIMSERIAL_USART4
			case 4:
				proxy_port_ = &slimSerial4;
				break;
			#endif
			#if ENABLE_SLIMSERIAL_USART5
			case 5:
				proxy_port_ = &slimSerial5;
				break;
			#endif
			#if ENABLE_SLIMSERIAL_USART6
			case 6:
				proxy_port_ = &slimSerial6;
				break;
			#endif
			#if ENABLE_SLIMSERIAL_USART7
			case 7:
				proxy_port_ = &slimSerial7;
				break;
			#endif
			#if ENABLE_SLIMSERIAL_USART8
			case 8:
				proxy_port_ = &slimSerial8;
				break;
			#endif
			default:
				proxy_port_ = NULL;
				break;
		}


	//fail if already previous proxy chain
	if(proxy_port_){

		if(m_proxy_port!=NULL && m_proxy_port!=proxy_port_){
			disableProxy();
		}

		ackProxy();

 		HAL_Delay(2);

		//change settings of current serial port
		m_proxy_port = proxy_port_;
		m_proxy_mode = SLIMSERIAL_TXRX_TRANSPARENT; 


		//change settings of  proxy serial port		
		m_proxy_port->m_proxy_port = this;
		m_proxy_port->m_proxy_mode = SLIMSERIAL_TXRX_TRANSPARENT;

		//change baudrate of  proxy serial port	
		if(proxy_port_baudrate == 0 || proxy_port_baudrate==1000000 || proxy_port_baudrate==115200 || proxy_port_baudrate==921600){
			m_proxy_port->setBaudrate(proxy_port_baudrate);
		}


		//set the proxy serial port to be 8 bits or 9 bits mode
		m_enable_9bits_proxy = enable_9bits_proxy;
		if(m_enable_9bits_proxy){
			m_proxy_9bit_address = proxy_9bit_address;
			m_proxy_port->config9bitTxAddress(m_proxy_9bit_address);
		}

		m_proxy_port->m_enable_9bits_proxy = false;//upstream port is always 8 bits mode



	}

}
void SlimSerial::disableProxy(){


	if(m_proxy_port!=NULL){

		//disable in chain
		ackProxy();
 		HAL_Delay(2);

		m_proxy_port->transmitFrameLL(0x00,FUNC_DISABLE_PROXY_INTERNAL,NULL,0);
		HAL_Delay(10);

		//restore baudrate if necessary
		m_proxy_port->setBaudrate();

		m_proxy_port->m_proxy_mode = SLIMSERIAL_TXRX_NORMAL;
		m_proxy_port->m_proxy_port = NULL;

		m_proxy_port->m_enable_9bits_proxy = false;

	}
	m_proxy_mode = SLIMSERIAL_TXRX_NORMAL;
	m_proxy_port = NULL;
	m_enable_9bits_proxy = false;
}


//0 for original baudrate
void SlimSerial::setBaudrate(uint32_t baudrate){
	if(baudrate!=m_last_baudrate){
		uint32_t pclk;
		UART_HandleTypeDef *huart = m_huart;
		#if defined(USART6) && defined(UART9) && defined(UART10)
			if ((huart->Instance == USART1) || (huart->Instance == USART6) || (huart->Instance == UART9) || (huart->Instance == UART10))
			{
			pclk = HAL_RCC_GetPCLK2Freq();
			}
		#elif defined(USART6)
			if ((huart->Instance == USART1) || (huart->Instance == USART6))
			{
			pclk = HAL_RCC_GetPCLK2Freq();
			}
		#else
			if (huart->Instance == USART1)
			{
			pclk = HAL_RCC_GetPCLK2Freq();
			}
		#endif /* USART6 */
			else
			{
			pclk = HAL_RCC_GetPCLK1Freq();
			}
		/*-------------------------- USART BRR Configuration ---------------------*/
	
		m_last_baudrate = baudrate;
		if(m_last_baudrate == 0){
			baudrate = huart->Init.BaudRate;
		}
		__HAL_UART_DISABLE(huart);
		if (huart->Init.OverSampling == UART_OVERSAMPLING_8)
		{
			huart->Instance->BRR = UART_BRR_SAMPLING8(pclk, baudrate);
		}
		else
		{
			huart->Instance->BRR = UART_BRR_SAMPLING16(pclk, baudrate);
		}
		__HAL_UART_ENABLE(huart);
	}
	
  
}
#endif

#define ANY_TIMEOUT_TIMER_USED (USART1_TIMEOUT_TIMER_INDEX && \
		USART1_TIMEOUT_TIMER_INDEX && \
		USART2_TIMEOUT_TIMER_INDEX && \
		USART3_TIMEOUT_TIMER_INDEX && \
		USART4_TIMEOUT_TIMER_INDEX && \
		USART5_TIMEOUT_TIMER_INDEX && \
		USART6_TIMEOUT_TIMER_INDEX && \
		USART7_TIMEOUT_TIMER_INDEX && \
		USART8_TIMEOUT_TIMER_INDEX)

#define ANY_TIMEOUT_TIMER_INDEX_EQUAL(index) \
	(SLIMSERIAL_HAL_TICK_TIMER_INDEX == index || \
	USART1_TIMEOUT_TIMER_INDEX == index || \
	USART2_TIMEOUT_TIMER_INDEX == index || \
	USART3_TIMEOUT_TIMER_INDEX == index || \
	USART4_TIMEOUT_TIMER_INDEX == index || \
	USART5_TIMEOUT_TIMER_INDEX == index || \
	USART6_TIMEOUT_TIMER_INDEX == index || \
	USART7_TIMEOUT_TIMER_INDEX == index || \
	USART8_TIMEOUT_TIMER_INDEX == index)

constexpr TIM_HandleTypeDef* getTimerHandle(uint8_t timer_index) {
#if SLIMSERIAL_HAL_TICK_TIMER_INDEX==1
extern TIM_HandleTypeDef        htim1;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==2
extern TIM_HandleTypeDef        htim2;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==3
extern TIM_HandleTypeDef        htim3;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==4
extern TIM_HandleTypeDef        htim4;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==5
extern TIM_HandleTypeDef        htim5;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==6
extern TIM_HandleTypeDef        htim6;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==7
extern TIM_HandleTypeDef        htim7;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==8
extern TIM_HandleTypeDef        htim8;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==9
extern TIM_HandleTypeDef        htim9;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==10
extern TIM_HandleTypeDef        htim10;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==11
extern TIM_HandleTypeDef        htim11;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==12
extern TIM_HandleTypeDef        htim12;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==13
extern TIM_HandleTypeDef        htim13;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==14
extern TIM_HandleTypeDef        htim14;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==15
extern TIM_HandleTypeDef        htim15;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==16
extern TIM_HandleTypeDef        htim16;
#elif SLIMSERIAL_HAL_TICK_TIMER_INDEX==17
extern TIM_HandleTypeDef        htim17;
#endif
	//time_index ranges from 0 to 17
	switch (timer_index) {
	case 0:
		return NULL; //no timer
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(1)
		case 1:
			return &htim1;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(2)
		case 2:
			return &htim2;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(3)
		case 3:
			return &htim3;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(4)
		case 4:
			return &htim4;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(5)
		case 5:
			return &htim5;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(6)
		case 6:
			return &htim6;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(7)
		case 7:
			return &htim7;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(8)
		case 8:
			return &htim8;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(9)
		case 9:
			return &htim9;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(10)
		case 10:
			return &htim10;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(11)
		case 11:
			return &htim11;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(12)
		case 12:
			return &htim12;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(13)
		case 13:
			return &htim13;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(14)
		case 14:
			return &htim14;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(15)
		case 15:
			return &htim15;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(16)
		case 16:
			return &htim16;
#endif
#if ANY_TIMEOUT_TIMER_INDEX_EQUAL(17)
		case 17:
			return &htim17;
#endif
	default:
		return NULL; //invalid timer index
	}
}

uint32_t SlimSerial::currentTime_us()
{
#if SLIMSERIAL_HAL_TICK_TIMER_INDEX!=0
	return (HAL_GetTick()*1000)+__HAL_TIM_GET_COUNTER(getTimerHandle(SLIMSERIAL_HAL_TICK_TIMER_INDEX));
#else
	return (HAL_GetTick()*1000);
#endif
}



/************************************							*************************************/
/************************************	overwrite HAL functions *************************************/
/************************************							************************************/
extern "C" {

/*Redirect printf() by implementing _write  or  fputc based on different compiler*/
#if defined(__GNUC__) && defined(PRINTF_SERIAL)
int _write(int file, char *pSrc, int len){
	return PRINTF_SERIAL.transmitData((uint8_t *)pSrc,len);
}
#elif defined (__CC_ARM)
int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&(PRINTF_SERIAL.m_huart), (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}
#endif




/*this function would overwrite HAL's weak HAL_UART_TxCpltCallback for all usart*/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	SlimSerial *slimSerialDev=getSlimSerial(huart);
	if(slimSerialDev){
		slimSerialDev->txCpltCallback();
	}
}


/*this function would overwrite HAL's weak HAL_UARTEx_RxEventCallback for all usart*/
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t data_len)
{
	SlimSerial *slimSerialDev=getSlimSerial(huart);
	if(slimSerialDev){
			slimSerialDev->rxCpltCallback(data_len);
	}

}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

	//restart
	SlimSerial *slimSerialDev=getSlimSerial(huart);
	if(slimSerialDev){

		//clear rx error flag
		__HAL_UART_CLEAR_PEFLAG(huart);

		slimSerialDev->restartRxFromISR();
	}

}

}
