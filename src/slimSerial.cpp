
#include <slimSerial.h>
#include "stdio.h"
#include "cmsis_os.h"
#include <type_traits>
#include <format>
#include "RTT_LOG.h"

#if ENABLE_SLIMSERIAL_USART1==1
#define USART1_TX_CIRCULAR_BUFFER_SIZE USART1_TX_FRAME_MAX_SIZE*2
#define USART1_RX_CIRCULAR_BUFFER_SIZE USART1_RX_FRAME_MAX_SIZE*2
#if USART1_9_BITS_MODE == 0
uint8_t USART1_TX_CIRCULAR_BUFFER[USART1_TX_CIRCULAR_BUFFER_SIZE];
uint8_t USART1_RX_CIRCULAR_BUFFER[USART1_RX_CIRCULAR_BUFFER_SIZE];
#elif USART1_9_BITS_MODE == 1
uint16_t USART1_TX_CIRCULAR_BUFFER[USART1_TX_CIRCULAR_BUFFER_SIZE];
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
#define SLIMSERIAL1_RX_TASK_BUFFER_SIZE SLIMSERIAL_RX_TASK_BUFFER_SIZE

SlimSerial slimSerial1(&huart1,
		(uint16_t *)USART1_TX_CIRCULAR_BUFFER,USART1_TX_CIRCULAR_BUFFER_SIZE,
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
#define USART2_TX_CIRCULAR_BUFFER_SIZE USART2_TX_FRAME_MAX_SIZE*2
#define USART2_RX_CIRCULAR_BUFFER_SIZE USART2_RX_FRAME_MAX_SIZE*2
#if USART2_9_BITS_MODE == 0
uint8_t USART2_TX_CIRCULAR_BUFFER[USART2_TX_CIRCULAR_BUFFER_SIZE];
uint8_t USART2_RX_CIRCULAR_BUFFER[USART2_RX_CIRCULAR_BUFFER_SIZE];
#elif USART2_9_BITS_MODE == 1
uint16_t USART2_TX_CIRCULAR_BUFFER[USART2_TX_CIRCULAR_BUFFER_SIZE];
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
#define SLIMSERIAL2_RX_TASK_BUFFER_SIZE SLIMSERIAL_RX_TASK_BUFFER_SIZE

SlimSerial slimSerial2(&huart2,
		(uint16_t *)USART2_TX_CIRCULAR_BUFFER,USART2_TX_CIRCULAR_BUFFER_SIZE,
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
#define USART3_TX_CIRCULAR_BUFFER_SIZE USART3_TX_FRAME_MAX_SIZE*2
#define USART3_RX_CIRCULAR_BUFFER_SIZE USART3_RX_FRAME_MAX_SIZE*2
#if USART3_9_BITS_MODE == 0
uint8_t USART3_TX_CIRCULAR_BUFFER[USART3_TX_CIRCULAR_BUFFER_SIZE];
uint8_t USART3_RX_CIRCULAR_BUFFER[USART3_RX_CIRCULAR_BUFFER_SIZE];
#elif USART3_9_BITS_MODE == 1
uint16_t USART3_TX_CIRCULAR_BUFFER[USART3_TX_CIRCULAR_BUFFER_SIZE];
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
#define SLIMSERIAL3_RX_TASK_BUFFER_SIZE SLIMSERIAL_RX_TASK_BUFFER_SIZE

SlimSerial slimSerial3(&huart3,
		(uint16_t *)USART3_TX_CIRCULAR_BUFFER,USART3_TX_CIRCULAR_BUFFER_SIZE,
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
#define USART4_TX_CIRCULAR_BUFFER_SIZE USART4_TX_FRAME_MAX_SIZE*2
#define USART4_RX_CIRCULAR_BUFFER_SIZE USART4_RX_FRAME_MAX_SIZE*2
#if USART4_9_BITS_MODE == 0
uint8_t USART4_TX_CIRCULAR_BUFFER[USART4_TX_CIRCULAR_BUFFER_SIZE];
uint8_t USART4_RX_CIRCULAR_BUFFER[USART4_RX_CIRCULAR_BUFFER_SIZE];
#elif USART4_9_BITS_MODE == 1
uint16_t USART4_TX_CIRCULAR_BUFFER[USART4_TX_CIRCULAR_BUFFER_SIZE];
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
#define SLIMSERIAL4_RX_TASK_BUFFER_SIZE SLIMSERIAL_RX_TASK_BUFFER_SIZE

SlimSerial slimSerial4(&huart4,
		(uint16_t *)USART4_TX_CIRCULAR_BUFFER,USART4_TX_CIRCULAR_BUFFER_SIZE,
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
#define USART5_TX_CIRCULAR_BUFFER_SIZE USART5_TX_FRAME_MAX_SIZE*2
#define USART5_RX_CIRCULAR_BUFFER_SIZE USART5_RX_FRAME_MAX_SIZE*2
#if USART5_9_BITS_MODE == 0
uint8_t USART5_TX_CIRCULAR_BUFFER[USART5_TX_CIRCULAR_BUFFER_SIZE];
uint8_t USART5_RX_CIRCULAR_BUFFER[USART5_RX_CIRCULAR_BUFFER_SIZE];
#elif USART5_9_BITS_MODE == 1
uint16_t USART5_TX_CIRCULAR_BUFFER[USART5_TX_CIRCULAR_BUFFER_SIZE];
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
#define SLIMSERIAL5_RX_TASK_BUFFER_SIZE SLIMSERIAL_RX_TASK_BUFFER_SIZE
SlimSerial slimSerial5(&huart5,
		(uint16_t *)USART5_TX_CIRCULAR_BUFFER,USART5_TX_CIRCULAR_BUFFER_SIZE,
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
#define USART6_TX_CIRCULAR_BUFFER_SIZE USART6_TX_FRAME_MAX_SIZE*2
#define USART6_RX_CIRCULAR_BUFFER_SIZE USART6_RX_FRAME_MAX_SIZE*2
#if USART6_9_BITS_MODE == 0
uint8_t USART6_TX_CIRCULAR_BUFFER[USART6_TX_CIRCULAR_BUFFER_SIZE];
uint8_t USART6_RX_CIRCULAR_BUFFER[USART6_RX_CIRCULAR_BUFFER_SIZE];
#elif USART6_9_BITS_MODE == 1
uint16_t USART6_TX_CIRCULAR_BUFFER[USART6_TX_CIRCULAR_BUFFER_SIZE];
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
#define SLIMSERIAL6_RX_TASK_BUFFER_SIZE SLIMSERIAL_RX_TASK_BUFFER_SIZE

SlimSerial slimSerial6(&huart6,
		(uint16_t *)USART6_TX_CIRCULAR_BUFFER,USART6_TX_CIRCULAR_BUFFER_SIZE,
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
#define USART7_TX_CIRCULAR_BUFFER_SIZE USART7_TX_FRAME_MAX_SIZE*2
#define USART7_RX_CIRCULAR_BUFFER_SIZE USART7_RX_FRAME_MAX_SIZE*2
#if USART7_9_BITS_MODE == 0
uint8_t USART7_TX_CIRCULAR_BUFFER[USART7_TX_CIRCULAR_BUFFER_SIZE];
uint8_t USART7_RX_CIRCULAR_BUFFER[USART7_RX_CIRCULAR_BUFFER_SIZE];
#elif USART7_9_BITS_MODE == 1
uint16_t USART7_TX_CIRCULAR_BUFFER[USART7_TX_CIRCULAR_BUFFER_SIZE];
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
#define SLIMSERIAL7_RX_TASK_BUFFER_SIZE SLIMSERIAL_RX_TASK_BUFFER_SIZE

SlimSerial slimSerial7(&huart7,
		(uint16_t *)USART7_TX_CIRCULAR_BUFFER,USART7_TX_CIRCULAR_BUFFER_SIZE,
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
#define USART8_TX_C
#define USART8_RX_CIRCULAR_BUFFER_SIZE USART8_RX_FRAME_MAX_SIZE*2
#if USART8_9_BITS_MODE == 0
uint8_t USART8_TX_CIRCULAR_BUFFER[USART8_TX_CIRCULAR_BUFFER_SIZE];
uint8_t USART8_RX_CIRCULAR_BUFFER[USART8_RX_CIRCULAR_BUFFER_SIZE];
#elif USART8_9_BITS_MODE == 1
uint16_t USART8_TX_CIRCULAR_BUFFER[USART8_TX_CIRCULAR_BUFFER_SIZE];
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
#define SLIMSERIAL8_RX_TASK_BUFFER_SIZE SLIMSERIAL_RX_TASK_BUFFER_SIZE

SlimSerial slimSerial8(&huart8,
		(uint16_t *)USART8_TX_CIRCULAR_BUFFER,USART8_TX_CIRCULAR_BUFFER_SIZE,
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
#define  SLIMSERIAL_PROXY_CIRCULAR_BUFFER_SIZE 2048
uint16_t SLIMSERIAL_PROXY_CIRCULAR_BUFFER[SLIMSERIAL_PROXY_CIRCULAR_BUFFER_SIZE]; //capable of holding maximum YModem frame size of 1029 even in 9 bits mode
SLIM_CURCULAR_BUFFER SlimSerial::m_proxy_circular_buffer={(uint8_t *)SLIMSERIAL_PROXY_CIRCULAR_BUFFER,SLIMSERIAL_PROXY_CIRCULAR_BUFFER_SIZE,0};
#endif

static uint8_t getSlimSerialIndex(UART_HandleTypeDef *huart);

SlimSerial::SlimSerial(UART_HandleTypeDef *uartHandle,
			uint16_t   *tx_circular_buf,
			uint16_t  tx_circular_buf_size,
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
 m_tx_circular_buf((uint8_t *)tx_circular_buf,tx_circular_buf_size,bits_9_mode),
 m_rx_circular_buf((uint8_t *)rx_circular_buf,rx_circular_buf_size,bits_9_mode)
 {

	m_huart = uartHandle;
	m_slimSerialIndex = getSlimSerialIndex(m_huart);



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

	m_9bits_mode_original = bits_9_mode; //original 9 bits mode when the SlimSerial object is created


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
	rxThreadID = NULL;
	txrxThreadID = NULL;

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


 	m_txrxMutex = xSemaphoreCreateMutexStatic(&m_txrxMutexBuffer);

 	m_txMutex = xSemaphoreCreateMutexStatic(&m_txMutexBuffer);

 	m_writeLocked = false; //tx mutex is not locked at the beginning


	/* definition and creation of PCInTask */
	if(m_rx_mode!=SLIMSERIAL_RX_MODE_OFF){
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


static inline uint8_t getSlimSerialIndex(UART_HandleTypeDef *huart){
#if ENABLE_SLIMSERIAL_USART1
	if(huart==&huart1){return 1;}
#endif
#if ENABLE_SLIMSERIAL_USART2
	if(huart==&huart2){return 2;}
	#endif
#if ENABLE_SLIMSERIAL_USART3
	if(huart==&huart3){return 3;}
#endif
#if ENABLE_SLIMSERIAL_USART4
	if(huart==&huart4){return 4;}
#endif
#if ENABLE_SLIMSERIAL_USART5
	if(huart==&huart5){return 5;}
#endif
#if ENABLE_SLIMSERIAL_USART6
	if(huart==&huart6){return 6;}
#endif
#if ENABLE_SLIMSERIAL_USART7
	if(huart==&huart7){return 7;}
#endif
#if ENABLE_SLIMSERIAL_USART8
	if(huart==&huart8){return 8;}
#endif

	//if not found, return NULL
	return 0;

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

#if USE_HAL_TIM_REGISTER_CALLBACKS==1
	HAL_TIM_RegisterCallback(m_timeout_htim, HAL_TIM_PERIOD_ELAPSED_CB_ID, [](TIM_HandleTypeDef *htim){getSlimSerial(htim)->txrxTimeoutCallback();});
#endif
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

SD_USART_StatusTypeDef SlimSerial::config9bitMode(uint8_t enable_9bits_mode){

 	//check 9bit mode bit is set
	m_9bits_mode = enable_9bits_mode;

	//set rx circular buffer 9bits mode
	m_rx_circular_buf.clear(); //clear the circular buffer first
	m_rx_circular_buf.setU16Mdoe(m_9bits_mode);

	//set tx circular buffer 9bits mode
	m_tx_circular_buf.clear(); //clear the circular buffer first
	m_tx_circular_buf.setU16Mdoe(m_9bits_mode);

	//set proxy circular buffer 9bits mode
	#if ENABLE_PROXY==1
	m_proxy_circular_buffer.clear(); //clear the circular buffer first
	m_proxy_circular_buffer.setU16Mdoe(m_9bits_mode);
	#endif

 	if(enable_9bits_mode==1){

 			//otherwise, set to 9bit mode
 			m_huart->Init.WordLength = UART_WORDLENGTH_9B;
 			if (HAL_UART_Init(m_huart) != HAL_OK)
 			{
 				//error handling
 				m_9bits_mode_error = 1;
 				return SD_USART_ERROR;
 			}


 		//check tx DMA to be 16bit
 		if(m_tx_mode==SLIMSERIAL_TX_MODE_DMA){
// 			if(m_huart->hdmatx->Init.MemDataAlignment != DMA_MDATAALIGN_HALFWORD ||
// 			   m_huart->hdmatx->Init.PeriphDataAlignment != DMA_PDATAALIGN_HALFWORD
// 			   ){
				if(m_huart->hdmatx->State==HAL_DMA_STATE_BUSY){
					HAL_DMA_Abort(m_huart->hdmatx);
				}
				HAL_UART_AbortTransmit(m_huart);

 				m_huart->hdmatx->Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
 				m_huart->hdmatx->Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;


 				if (HAL_DMA_Init(m_huart->hdmatx) != HAL_OK)
 				{
 					//error handling
 					m_9bits_mode_error = 1;
 					return SD_USART_ERROR;
 				}

// 			}
 		}


 		//check rx DMA to be 16bit
 		//if rx is enabled, it must use DMA
 		if(m_rx_mode!=SLIMSERIAL_RX_MODE_OFF){
// 			if(m_huart->hdmarx->Init.MemDataAlignment != DMA_MDATAALIGN_HALFWORD ||
// 			   m_huart->hdmarx->Init.PeriphDataAlignment != DMA_PDATAALIGN_HALFWORD
// 			   ){
				if(m_huart->hdmarx->State==HAL_DMA_STATE_BUSY){
					HAL_DMA_Abort(m_huart->hdmarx);
				}
				HAL_UART_AbortReceive(m_huart);
 				//otherwise, set to 16bit mode
 				m_huart->hdmarx->Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
 				m_huart->hdmarx->Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;


 				if (HAL_DMA_Init(m_huart->hdmarx) != HAL_OK)
 				{
 					//error handling
 					m_9bits_mode_error = 1;
 					return SD_USART_ERROR;
 				}
// 			}
 		}
 	}
 	else{
// 		if(m_huart->Init.WordLength != UART_WORDLENGTH_8B){

			//otherwise, set to 9bit mode
			m_huart->Init.WordLength = UART_WORDLENGTH_8B;
			if (HAL_UART_Init(m_huart) != HAL_OK)
			{
				//error handling
				m_9bits_mode_error = 1;
				return SD_USART_ERROR;
			}
//		}

 		//check tx DMA to be 8bit
 		if(m_tx_mode==SLIMSERIAL_TX_MODE_DMA){
// 			if(m_huart->hdmatx->Init.MemDataAlignment != DMA_MDATAALIGN_BYTE ||
// 			   m_huart->hdmatx->Init.PeriphDataAlignment != DMA_PDATAALIGN_BYTE
// 			   ){
				if(m_huart->hdmatx->State==HAL_DMA_STATE_BUSY){
					HAL_DMA_Abort(m_huart->hdmatx);
				}
				HAL_UART_AbortTransmit(m_huart);

 				m_huart->hdmatx->Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
 				m_huart->hdmatx->Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
 				if (HAL_DMA_Init(m_huart->hdmatx) != HAL_OK)
 				{
 					//error handling
 					m_9bits_mode_error = 1;
 					return SD_USART_ERROR;
 				}
// 			}
 		}

 		//check rx DMA to be 8bit
 		//if rx is enabled, it must use DMA
 		if(m_rx_mode!=SLIMSERIAL_RX_MODE_OFF){
// 			if(m_huart->hdmarx->Init.MemDataAlignment != DMA_MDATAALIGN_BYTE ||
// 			   m_huart->hdmarx->Init.PeriphDataAlignment != DMA_PDATAALIGN_BYTE
// 			   ){
				if(m_huart->hdmarx->State==HAL_DMA_STATE_BUSY){
					HAL_DMA_Abort(m_huart->hdmarx);
				}
				HAL_UART_AbortReceive(m_huart);
 				//otherwise, set to 8bit mode
 				m_huart->hdmarx->Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
 				m_huart->hdmarx->Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

 				if (HAL_DMA_Init(m_huart->hdmarx) != HAL_OK)
 				{
 					//error handling
 					m_9bits_mode_error = 1;
 					return SD_USART_ERROR;
 				}
// 			}
 		}
 	}

 	start_Rx_DMA_Idle_Circular(); //restart the rx DMA in idle circular mode

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


#if ENABLE_SLIMSERIAL_USART1
	if(m_huart==&huart1){

		osThreadStaticDef_modified(rx1Task, rxTaskFuncImpl, osPriorityHigh, 0, SLIMSERIAL1_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx1Task), &slimSerial1);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART2
	if(m_huart==&huart2){
		osThreadStaticDef_modified(rx2Task, rxTaskFuncImpl, osPriorityHigh, 0, SLIMSERIAL2_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx2Task), &slimSerial2);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART3
	if(m_huart==&huart3){
		osThreadStaticDef_modified(rx3Task, rxTaskFuncImpl, osPriorityHigh, 0, SLIMSERIAL3_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx3Task), &slimSerial3);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART4
	if(m_huart==&huart4){
		osThreadStaticDef_modified(rx4Task, rxTaskFuncImpl, osPriorityHigh, 0, SLIMSERIAL4_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx4Task), &slimSerial4);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART5
	if(m_huart==&huart5){
		osThreadStaticDef_modified(rx5Task, rxTaskFuncImpl, osPriorityAboveNormal, 0, SLIMSERIAL5_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx5Task), &slimSerial5);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART6
	if(m_huart==&huart6){
		osThreadStaticDef_modified(rx6Task, rxTaskFuncImpl, osPriorityAboveNormal, 0, SLIMSERIAL6_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx6Task), &slimSerial6);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART7
	if(m_huart==&huart7){
		osThreadStaticDef_modified(rx7Task, rxTaskFuncImpl, osPriorityAboveNormal, 0, SLIMSERIAL7_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx7Task), &slimSerial7);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART8
	if(m_huart==&huart8){
		osThreadStaticDef_modified(rx8Task, rxTaskFuncImpl, osPriorityAboveNormal, 0, SLIMSERIAL8_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
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

SD_USART_StatusTypeDef SlimSerial::transmitFrame(uint16_t address,uint16_t fcode,PayloadFunc payloadFunc){
	if(getProxyMode()==SLIMSERIAL_TXRX_NORMAL){
		//assemble tx frame in internal buffer,not queued
		SD_BUF_INFO sd_buf_info = bufferTxFrame(address,fcode,payloadFunc);

		//enqueue the buffered data
		m_tx_queue_meta.push(sd_buf_info);

		//enqueue and transmit
		return transmitLL_try();
	}
	else{
		return SD_USART_ERROR;
	}

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

	//buffer data into internal m_tx_circular_buffer, with frame_prefix and crc added
	SD_BUF_INFO sd_buf_info = bufferTxFrame(address,fcode,payload,payloadBytes);

	//enqueue the buffered data
	m_tx_queue_meta.push(sd_buf_info);

	//enqueue and transmit
	return transmitLL_try();
}

SD_USART_StatusTypeDef SlimSerial::transmitDataLL(uint8_t *pdata,uint16_t dataBytes){

	//buffer data into internal m_tx_circular_buffer
	SD_BUF_INFO sd_buf_info=bufferTxData(pdata,dataBytes);

	//enqueue the buffered data
	m_tx_queue_meta.push(sd_buf_info);

	//enqueue and try to trigger a transmit
	return transmitLL_try();
}

uint32_t SlimSerial::readBuffer(uint8_t *pdata,uint16_t dataBytes,uint32_t timeout){

	uint32_t readN=0;
	uint32_t leftN=dataBytes;
	uint32_t thisN=0;

	uint32_t timeoutPoint= HAL_GetTick()+timeout+1;
	while( leftN >0 ){
		thisN = m_rx_circular_buf.out((uint8_t *)(&pdata[readN]), leftN);
		readN +=thisN;
		leftN -=thisN;
		if(HAL_GetTick() >= timeoutPoint){
			break;
		}

	}
	return readN;


}

inline SD_USART_StatusTypeDef SlimSerial::transmitLL_try(){
	if (!m_writeLocked) {
		//if get the mutex, try to transmit
		m_writeLocked=true;
		m_writeLock_last_true_time_us = currentTime_us();
		return transmitLL();
	}
	else{

		//if the write lock is taken for more than 500ms, may encounter a tx deadlock. reset the lock
		if(currentTime_us() - m_writeLock_last_true_time_us > m_writeLock_last_reset_time_threshold_us){

			//should not happen, but if it does, reset the lock
			m_writeLocked=true;
			m_writeLock_last_true_time_us = currentTime_us();

			//
			m_writeLock_reset_count++;
			return transmitLL();
		}
		m_writeLock_busy_count++;
		m_writeLock_busy_elapsed_us = currentTime_us() - m_writeLock_last_true_time_us;
		return SD_USART_BUSY; //if the mutex is not taken, return busy
	}

}

SD_USART_StatusTypeDef SlimSerial::transmitLL(){

	//try to trigger a transmit one the queue's back. This will not take effect is the Tx is already ongoing
	m_tx_time_start = currentTime_us();

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
//buffer data to a circular buffer, with address byte in 9-bit mode if the circular buffer is in U16 mode
SD_BUF_INFO SlimSerial::bufferTxData(SLIM_CURCULAR_BUFFER &tx_circular_buf,uint8_t *pSrc,uint16_t datalen) {

	SD_BUF_INFO sd_buf_info;

	//if not enough continuous space in the circular buffer, add a dummy data to the circular buffer to ensure the next in() will be at the new head position
	if((datalen+1u)>tx_circular_buf.unusedContinuousSpace()){//one additional byte for the address byte in 9-bit mode
		tx_circular_buf.in_dummy_with_new_masked_head(0);
	}

	sd_buf_info.pdata = tx_circular_buf.getHeadMasked();
	sd_buf_info.dataBytes = datalen;

	//for 9-bit mode, add address byte with 9's bit set first
	if(tx_circular_buf.m_U16_mode){
		uint16_t addressU16 = (uint16_t)((m_9bits_mode_address_tx&0x0F) | 0x100); //set the 9th bit
		tx_circular_buf.in((uint16_t *)(&addressU16),1);
	}

	//add the data
	tx_circular_buf.in(pSrc,datalen);

	return sd_buf_info;
}

//buffer data to internal tx circular buffer, use current m_9bits_mode_address_tx
SD_BUF_INFO SlimSerial::bufferTxData(uint8_t *pSrc,uint16_t datalen) {
	return bufferTxData(m_tx_circular_buf, pSrc, datalen);
}

SD_BUF_INFO SlimSerial::bufferTxFrame(uint8_t address,uint8_t fcode,PayloadFunc payloadFunc) {

	SD_BUF_INFO sd_buf_info;
	uint8_t payloadBytes=0;

	//if not enough continuous space in the circular buffer, add a dummy data to the circular buffer to ensure the next in() will be at the new head position
	if(m_tx_circular_buf.unusedContinuousSpace()<m_tx_circular_buf.bufferSize/2){//less than half of the buffer is available
		m_tx_circular_buf.in_dummy_with_new_masked_head(0);
	}

	sd_buf_info.pdata = m_tx_circular_buf.getHeadMasked();


	//for 9-bit mode, add address byte with 9's bit set first
	if(m_9bits_mode){
		uint16_t addressU16 = (uint16_t)((address&0x0F) | 0x100); //set the 9th bit
		m_tx_circular_buf.in((uint16_t *)(&addressU16),1);
	}

	//add frame prefix with 0 payloadBytes
	std::array<uint8_t,5> frame_prefix = {0x5A, 0xA5, address, payloadBytes, fcode};
	m_tx_circular_buf.in((uint8_t *)(&frame_prefix[0]), sizeof(frame_prefix)); //add the frame_prefix

	//add the payload
	if(m_9bits_mode){
		payloadBytes = payloadFunc((uint8_t *)(((uint16_t *)sd_buf_info.pdata)+6), true); //it is the payload function's responsiblity to correctly fill the payload bytes with U8 or U16 data
	}
	else{
		payloadBytes = payloadFunc(((uint8_t *)sd_buf_info.pdata)+5, false);
	}
	m_tx_circular_buf.in_dummy(payloadBytes); //add the payload bytes

	//update the payload bytes in the frame prefix
	if(m_9bits_mode){
		((uint16_t *)sd_buf_info.pdata)[4] = payloadBytes; //update the payload bytes in the frame prefix
	}
	else{
		sd_buf_info.pdata[3] = payloadBytes; //update the payload bytes in the frame prefix
	}

	//add CRC (not including the 9-bit address)
	uint16_t crcU16= m_9bits_mode?SD_CRC_Calculate_U16LB(((uint16_t *)sd_buf_info.pdata)+1, payloadBytes + 5):SD_CRC_Calculate(sd_buf_info.pdata, payloadBytes + 5);
	m_tx_circular_buf.in((uint8_t *)(&crcU16),2); //add the CRC bytes

	sd_buf_info.dataBytes = payloadBytes + 7;

	return sd_buf_info;
}


SD_BUF_INFO SlimSerial::bufferTxFrame(uint8_t address,uint8_t fcode,uint8_t *payload,uint16_t payloadBytes) {
	SD_BUF_INFO sd_buf_info;
	uint16_t frameBytes = payloadBytes + 7; //7 bytes for the frame prefix and CRC

	//if not enough continuous space in the circular buffer, add a dummy data to the circular buffer to ensure the next in() will be at the new head position
	if((frameBytes+1u)>m_tx_circular_buf.unusedContinuousSpace()){//one additional byte for the address byte in 9-bit mode
		m_tx_circular_buf.in_dummy_with_new_masked_head(0);
	}

	sd_buf_info.pdata = m_tx_circular_buf.getHeadMasked();
	sd_buf_info.dataBytes = frameBytes;

	//for 9-bit mode, add address byte with 9's bit set first
	if(m_9bits_mode){
		uint16_t addressU16 = (uint16_t)((address&0x0F) | 0x100); //set the 9th bit
		m_tx_circular_buf.in((uint16_t *)(&addressU16),1);
	}

	//add frame prefix
	std::array<uint8_t,5> frame_prefix = {0x5A, 0xA5, address, (uint8_t)payloadBytes, fcode};
	m_tx_circular_buf.in((uint8_t *)(&frame_prefix[0]), sizeof(frame_prefix)); //add the frame_prefix

	//add the payload
	m_tx_circular_buf.in(payload,payloadBytes);

	//add CRC (not including the 9-bit address)
	uint16_t crcU16= m_9bits_mode?SD_CRC_Calculate_U16LB(((uint16_t *)sd_buf_info.pdata)+1, payloadBytes + 5):SD_CRC_Calculate(sd_buf_info.pdata, payloadBytes + 5);
	m_tx_circular_buf.in((uint8_t *)(&crcU16),2); //add the CRC bytes


	return sd_buf_info;
}



SD_BUF_INFO &SlimSerial::transmitReceiveData(uint8_t *pData,uint16_t dataBytes,float timeout_ms, bool frameTypeFilterOn){
	if(getProxyMode()==SLIMSERIAL_TXRX_TRANSPARENT){
		m_rx_status = SD_USART_ERROR;
		m_rx_last.dataBytes=0;
		return  m_rx_last;
	}

	//need txrxmutex
	uint32_t t1 = currentTime_us();
	if(xSemaphoreTake(m_txrxMutex, std::lround(timeout_ms)) != pdTRUE){
		m_rx_status = SD_USART_TIMEOUT;
		m_rx_last.dataBytes=0;
		m_txrxMutex_aquire_time_us= std::lround(timeout_ms)*1000;
		m_txrxMutex_aquire_failed_count++;
		return  m_rx_last;
	}
	m_txrxMutex_aquire_time_us= currentTime_us() - t1;

	timeout_ms-= m_txrxMutex_aquire_time_us/1000.0f; //reduce the timeout by the time taken to acquire the mutex

	//record txrx threadID
	m_rx_status = SD_USART_BUSY;

	//record current frame type
	uint8_t rxFrameType_temp = m_rx_frame_type;

	//temporarily switch off frame type check
	if(frameTypeFilterOn==false)
		m_rx_frame_type = SLIMSERIAL_FRAME_TYPE_0_ANY;

	txrxThreadID = (uint32_t *) osThreadGetId();
	//clear previous nofification value that every valid frame would trigger
	xTaskNotifyStateClear((TaskHandle_t)(txrxThreadID));

	//setup accurate timeout timer ifconfigured
#if ANY_TIMEOUT_TIMER_USED
	setTimeout(timeout_ms);
#endif

	//start a tx frame
	transmitData(pData, dataBytes);

	//1ms timeout cannot be guaranteed by freeRTOS, so add 1ms to it.
	uint32_t ulTaskNotifyRet = ulTaskNotifyTake(pdTRUE,std::max(2l,std::lround(timeout_ms)));


	if(ulTaskNotifyRet & SLIMSERIAL_NOTIFICATION_BIT_FRAME){
		m_rx_status = SD_USART_OK;
	}
	else{//ulTaskNotifyRet==0 || (ulTaskNotifyRet & SLIMSERIAL_NOTIFICATION_BIT_TIMEOUT) || (ulTaskNotifyRet & SLIMSERIAL_NOTIFICATION_BIT_RESTART)
		m_rx_last.dataBytes=0;
		m_txrx_time_cost = currentTime_us()-m_tx_time_start;
		if (m_rx_status==SD_USART_BUSY){
			m_rx_status = SD_USART_TIMEOUT;
		}
	}

#if ANY_TIMEOUT_TIMER_USED
	stopTimeout(); //stop the timer
#endif

	//restore frame type
	m_rx_frame_type = rxFrameType_temp;

	//clear txrx threadID
	txrxThreadID = nullptr;

	//release txrx mutex
	xSemaphoreGive(m_txrxMutex);

	return m_rx_last;
}


SD_BUF_INFO &SlimSerial::transmitReceiveFrame(uint16_t address,uint16_t fcode,uint8_t *payload,uint16_t payloadBytes,float timeout_ms){
	if(getProxyMode()==SLIMSERIAL_TXRX_TRANSPARENT){
		m_rx_status = SD_USART_ERROR;
		m_rx_last.dataBytes=0;
		return  m_rx_last;
	}

	//need txrxmutex
	uint32_t t1 = currentTime_us();
	if(xSemaphoreTake(m_txrxMutex, std::lround(timeout_ms)) != pdTRUE){
		m_rx_status = SD_USART_TIMEOUT;
		m_rx_last.dataBytes=0;
		m_txrxMutex_aquire_time_us= std::lround(timeout_ms)*1000;
		return  m_rx_last;
	}
	m_txrxMutex_aquire_time_us= currentTime_us() - t1;

	timeout_ms-= m_txrxMutex_aquire_time_us/1000.0f; //reduce the timeout by the time taken to acquire the mutex

	//record txrx threadID
	m_rx_status = SD_USART_BUSY;

	txrxThreadID = (uint32_t *) osThreadGetId();
	//clear previous nofification value that every valid frame would trigger
	xTaskNotifyStateClear((TaskHandle_t)(txrxThreadID));

	//setup accurate timeout timer ifconfigured
#if ANY_TIMEOUT_TIMER_USED
	setTimeout(timeout_ms);
#endif

	//start a tx frame
	transmitFrame(address, fcode, payload, payloadBytes);

	//1ms timeout cannot be guaranteed by freeRTOS, so add 1ms to it.
	uint32_t ulTaskNotifyRet = ulTaskNotifyTake(pdTRUE,std::max(2l,std::lround(timeout_ms)));


	if(ulTaskNotifyRet & SLIMSERIAL_NOTIFICATION_BIT_FRAME){
		m_rx_status = SD_USART_OK;
	}
	else{//ulTaskNotifyRet==0 || (ulTaskNotifyRet & SLIMSERIAL_NOTIFICATION_BIT_TIMEOUT) || (ulTaskNotifyRet & SLIMSERIAL_NOTIFICATION_BIT_RESTART)
		m_rx_last.dataBytes=0;
		m_txrx_time_cost = currentTime_us()-m_tx_time_start;
		if (m_rx_status==SD_USART_BUSY){
			m_rx_status = SD_USART_TIMEOUT;
		}
	}

#if ANY_TIMEOUT_TIMER_USED
	stopTimeout(); //stop the timer
#endif

	//clear txrx threadID
	txrxThreadID = nullptr;

	//release txrx mutex
	xSemaphoreGive(m_txrxMutex);

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
#if ANY_TIMEOUT_TIMER_USED
	stopTimeout(); //stop the timeout timer if it is running
#endif
	if(m_huart->hdmarx->State==HAL_DMA_STATE_BUSY){
		HAL_DMA_Abort(m_huart->hdmarx);
	}
	HAL_UART_AbortReceive(m_huart);
	while(Slim_UARTEx_ReceiveToIdle_DMA(m_huart, m_rx_circular_buf.buffer, m_rx_circular_buf.bufferSize) != HAL_OK)
	{
		m_huart->hdmarx->State=HAL_DMA_STATE_BUSY;//to make sure the next HAL_DMA_Abort
		HAL_DMA_Abort(m_huart->hdmarx);
		HAL_UART_AbortReceive(m_huart);

		if(m_huart->hdmarx->Lock == HAL_LOCKED){
			m_huart->hdmarx->Lock = HAL_UNLOCKED;
			m_huart->hdmarx->State =  HAL_DMA_STATE_READY;
		}
	}
	//we don't need half-transfer interrupt.
	__HAL_DMA_DISABLE_IT(m_huart->hdmarx, DMA_IT_HT);

	//We do need the DMA_IT_TC, otherwise we will miss certain rxcallback in STM32F0 series because of the inconsistant behavior of HAL's HAL_UART_IRQHandler() between F0 and F4.(We won't miss any data, since we are in circular mode)
	//
}


SD_BUF_INFO &SlimSerial::modbusRead(uint8_t des, uint16_t reg_address,uint16_t reg_count,uint16_t timeoutMS){
	std::array<uint8_t,8> readFrame={des,0x03,(uint8_t)(reg_address>>8),(uint8_t)(reg_address&0xFF),(uint8_t)(reg_count>>8),(uint8_t)(reg_count&0xFF),0,0};
	uint16_t crc = SD_CRC_Calculate(&readFrame[0], 6);
	readFrame[6] = (uint8_t) (crc &0xFF);
	readFrame[7] = (uint8_t)(crc >> 8)&0xFF;

	return transmitReceiveData(&readFrame[0],sizeof(readFrame),timeoutMS);
}

SD_BUF_INFO &SlimSerial::modbusWrite(uint8_t des, uint16_t reg_address,uint16_t reg_data,uint16_t timeoutMS){
	std::array<uint8_t,8> writeFrame={des,0x06,(uint8_t)(reg_address>>8),(uint8_t)(reg_address&0xFF),(uint8_t)(reg_data>>8),(uint8_t)(reg_data&0xFF),0,0};
	uint16_t crc = SD_CRC_Calculate(&writeFrame[0], 6);
	writeFrame[6] = (uint8_t) (crc &0xFF);
	writeFrame[7] = (uint8_t)(crc >> 8)&0xFF;

	return transmitReceiveData(&writeFrame[0],sizeof(writeFrame),timeoutMS);
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

	//record the max used size of the tx queue
	m_tx_queue_max_used_size = m_tx_queue_meta.size()>m_tx_queue_max_used_size? m_tx_queue_meta.size() : m_tx_queue_max_used_size;

	//dequeue the last tx info
	m_tx_queue_meta.pop();



	//trigger another tx if tx queue is not empty. Don't access back() if the queue is empty.
	if(!m_tx_queue_meta.empty()){
		transmitLL(); //transmit the next frame without taking the mutex, since we are already in the transmit context
	}
	else{
		// Give the mutex back. if no more data to transmit, we can release the mutex
//		xSemaphoreGiveFromISR(m_txMutex,NULL);
		m_writeLocked=false;
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
	uint32_t dlen = m_rx_circular_buf.in_dummy_with_new_masked_head(exactHead); //dummy in to update the circular buffer size
	m_totalRxBytes += dlen;

	if(rxThreadID != NULL) {
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xTaskGenericNotifyFromISR((TaskHandle_t)(rxThreadID),SLIMSERIAL_NOTIFICATION_BIT_FRAME,eSetBits,NULL,&xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}
}

void SlimSerial::errorCallback()
{
	//normally this is all about rx error.
	//clear rx error flag
	__HAL_UART_CLEAR_PEFLAG(m_huart);

	restartRxFromISR();
}

#if ANY_TIMEOUT_TIMER_USED
void SlimSerial::txrxTimeoutCallback(){

	stopTimeout(); //stop the timer if use half complete callback

	//notify the txrx thread that a timeout has occurred by setting the notification value bit SLIMSERIAL_NOTIFICATION_BIT_TIMEOUT
   if (txrxThreadID != NULL) {
	   BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	   xTaskGenericNotifyFromISR((TaskHandle_t)(txrxThreadID),SLIMSERIAL_NOTIFICATION_BIT_TIMEOUT,eSetBits,NULL,&xHigherPriorityTaskWoken);
	   portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
   }
};
#endif

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


void SlimSerial::rxHandlerThread() {
	uint32_t ulTaskNotifyValue = 0;
	 /*get ready for receive*/
	rxThreadID = (uint32_t *)osThreadGetId();

	configRxDMACircularMode();

#if ANY_TIMEOUT_TIMER_USED
	configTimeoutTimer();
#endif

	osDelay(20);

	config9bitMode(m_9bits_mode_original);
//	start_Rx_DMA_Idle_Circular();//already called in config9bitMode()

	/* Infinite loop */
	for (;;) {

		//get notification value and clear it
		ulTaskNotifyValue = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		if(ulTaskNotifyValue & SLIMSERIAL_NOTIFICATION_BIT_RESTART) {
			start_Rx_DMA_Idle_Circular();
			continue;
		}

		frameParser();
	}
}

//frame parser shouldn't care about the 9 bits mode, since it is already handled in lower transmission layer
void SlimSerial::frameParser(){

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
			if (txrxThreadID != NULL) {
				xTaskGenericNotify((TaskHandle_t)(txrxThreadID),SLIMSERIAL_NOTIFICATION_BIT_FRAME,eSetBits,NULL);
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
											if (txrxThreadID != NULL) {
												xTaskGenericNotify((TaskHandle_t)(txrxThreadID),SLIMSERIAL_NOTIFICATION_BIT_FRAME,eSetBits,NULL);
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
							if (txrxThreadID != NULL) {
								xTaskGenericNotify((TaskHandle_t)(txrxThreadID),SLIMSERIAL_NOTIFICATION_BIT_FRAME,eSetBits,NULL);
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
								if (txrxThreadID != NULL) {
									xTaskGenericNotify((TaskHandle_t)(txrxThreadID),SLIMSERIAL_NOTIFICATION_BIT_FRAME,eSetBits,NULL);
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
								if (txrxThreadID != NULL) {
									xTaskGenericNotify((TaskHandle_t)(txrxThreadID),SLIMSERIAL_NOTIFICATION_BIT_FRAME,eSetBits,NULL);
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




uint32_t SlimSerial::getRxIdleTimeUs(){
	return currentTime_us()- m_rx_time_end;
}
uint32_t SlimSerial::getRxFrameIdleTimeUs(){
	return currentTime_us()- m_rx_time_validFrame;
}

void SlimSerial::restartRxFromISR(){
	if(rxThreadID != NULL) {
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xTaskGenericNotifyFromISR((TaskHandle_t)(rxThreadID),SLIMSERIAL_NOTIFICATION_BIT_RESTART,eSetBits,NULL,&xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}
}

SLIMSERIAL_PROXY_MODE SlimSerial::getProxyMode() {

    return m_proxy_mode;

}
#if ENABLE_PROXY==1

void SlimSerial::proxyDelegateMessage(uint8_t *pData,uint16_t databytes){
	SD_BUF_INFO sd_buf_info;
	if((databytes+1u)>m_proxy_port->m_tx_circular_buf.bufferSize){
		sd_buf_info = bufferTxData(m_proxy_circular_buffer, pData, databytes);
		LOG_INFO("Serial%d -> Serial%d, databytes = %d bytes, index= %d",m_slimSerialIndex,m_proxy_port->m_slimSerialIndex,sd_buf_info.dataBytes);
		if(databytes==1){
			LOG_ARRAY_BLUE(sd_buf_info.pdata,sd_buf_info.dataBytes,0);
		}
	}
	else{
		//buffer data into internal m_tx_circular_buffer
		sd_buf_info=m_proxy_port->bufferTxData(pData,databytes);
		LOG_INFO("Serial%d -> Serial%d, databytes = %d bytes:",m_slimSerialIndex,m_proxy_port->m_slimSerialIndex,sd_buf_info.dataBytes);
		if(databytes==1){
			LOG_ARRAY_GREEN(sd_buf_info.pdata,sd_buf_info.dataBytes,0);
		}
	}
	//enqueue the buffered data
	m_proxy_port->m_tx_queue_meta.push(sd_buf_info);

	//enqueue and transmit
	m_proxy_port->transmitLL_try();


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
			disableProxy(false);//disable previous proxy without ack
		}

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

		//configure the proxy port's 9 bits mode according to the enable_9bits_proxy. This needs to be restored when disabling proxy
		m_proxy_port->config9bitMode(m_enable_9bits_proxy);

		//send acknowledgment
		ackProxy();

	}

}
void SlimSerial::disableProxy(bool ackFlag){


	if(m_proxy_port!=NULL){

		//disable in chain
 		//TODO: Send the disable command to the proxy network with m_9bits_mode_original or m_9bits_mode?
		m_proxy_port->transmitFrameLL(0x00,FUNC_DISABLE_PROXY_INTERNAL,NULL,0);

		HAL_Delay(2);//wait for 2ms to let the command be sent out

		//restore proxy port's original 9bits mode
		m_proxy_port->config9bitMode(m_proxy_port->m_9bits_mode_original);

		//restore baudrate if necessary
		m_proxy_port->setBaudrate();

		m_proxy_port->m_proxy_mode = SLIMSERIAL_TXRX_NORMAL;
		m_proxy_port->m_proxy_port = NULL;

		m_proxy_port->m_enable_9bits_proxy = 0;

	}


	m_proxy_mode = SLIMSERIAL_TXRX_NORMAL;
	m_proxy_port = NULL;
	m_enable_9bits_proxy = 0;

	//send  acknowledgment
	if(ackFlag){
		ackProxy();
	}
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
//int _write(int file, char *pSrc, int len){
//	return PRINTF_SERIAL.transmitData((uint8_t *)pSrc,len);
//}
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
		slimSerialDev->errorCallback();

	}
}
void Slim_USART_IRQHandler(UART_HandleTypeDef *huart) {

#if defined(__STM32F0xx_HAL_H)
	uint32_t isrflags   = READ_REG(huart->Instance->ISR);
	uint32_t errorflags = (isrflags & (uint32_t)(USART_ISR_PE | USART_ISR_FE | USART_ISR_ORE | USART_ISR_NE));
#elif defined(__STM32F4xx_HAL_H)
	uint32_t isrflags   = READ_REG(huart->Instance->SR);
	uint32_t errorflags = (isrflags & (uint32_t)(USART_SR_PE | USART_SR_FE | USART_SR_ORE | USART_SR_NE));
#endif
	uint32_t cr3its     = READ_REG(huart->Instance->CR3);

	if ((errorflags != RESET) && ((cr3its & USART_CR3_EIE) == RESET)){
	  /* If error interrupt is not enabled, clear the error flags */
	  __HAL_UART_CLEAR_PEFLAG(huart);
	}
}
}
