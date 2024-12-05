
#include <slimSerial.h>
#include "stdio.h"
#include "cmsis_os.h"
#include <type_traits> 
#include "slimRegister.h"



#if ENABLE_SLIMSERIAL_USART1==1
#if PRINTF_USART == huart1
#define USART1_TX_QUEUE_SIZE 2
#else
#define USART1_TX_QUEUE_SIZE 2
#endif
uint8_t USART1_TX_QUEUE_BUFFER[USART1_TX_FRAME_MAX_SIZE*USART1_TX_QUEUE_SIZE];
uint8_t USART1_RX_PINGPONG_BUFFER[USART1_RX_FRAME_MAX_SIZE*2];
uint8_t USART1_RX_CIRCULAR_BUFFER[USART1_RX_FRAME_MAX_SIZE*2];
uint8_t USART1_RX_FRAME_BUFFER[USART1_RX_FRAME_MAX_SIZE];

SlimSerial slimSerial1(&huart1,
		USART1_TX_QUEUE_BUFFER,USART1_TX_FRAME_MAX_SIZE,USART1_TX_QUEUE_SIZE,
		USART1_RX_PINGPONG_BUFFER,USART1_RX_FRAME_MAX_SIZE,
		USART1_RX_CIRCULAR_BUFFER,sizeof(USART1_RX_CIRCULAR_BUFFER),
		USART1_RX_FRAME_BUFFER,USART1_RX_FRAME_MAX_SIZE,USART1_FRAME_TYPE,
		USART1_485_Tx_EN_GPIO_Port,
		USART1_485_Tx_EN_GPIO_Pin,
		USART1_TX_MODE,
		USART1_RX_ENABLE);
#endif
#if ENABLE_SLIMSERIAL_USART2==1
#if PRINTF_USART == huart2
#define USART2_TX_QUEUE_SIZE 2
#else
#define USART2_TX_QUEUE_SIZE 2
#endif
uint8_t USART2_TX_QUEUE_BUFFER[USART2_TX_FRAME_MAX_SIZE*USART2_TX_QUEUE_SIZE];
uint8_t USART2_RX_PINGPONG_BUFFER[USART2_RX_FRAME_MAX_SIZE*2];
uint8_t USART2_RX_CIRCULAR_BUFFER[USART2_RX_FRAME_MAX_SIZE*2];
uint8_t USART2_RX_FRAME_BUFFER[USART2_RX_FRAME_MAX_SIZE];
SlimSerial slimSerial2(&huart2,
		USART2_TX_QUEUE_BUFFER,USART2_TX_FRAME_MAX_SIZE,USART2_TX_QUEUE_SIZE,
		USART2_RX_PINGPONG_BUFFER,USART2_RX_FRAME_MAX_SIZE,
		USART2_RX_CIRCULAR_BUFFER,sizeof(USART2_RX_CIRCULAR_BUFFER),
		USART2_RX_FRAME_BUFFER,USART2_RX_FRAME_MAX_SIZE,USART2_FRAME_TYPE,
		USART2_485_Tx_EN_GPIO_Port,
		USART2_485_Tx_EN_GPIO_Pin,
		USART2_TX_MODE,
		USART2_RX_ENABLE);
#endif
#if ENABLE_SLIMSERIAL_USART3==1
#if PRINTF_USART == huart3
#define USART3_TX_QUEUE_SIZE 2
#else
#define USART3_TX_QUEUE_SIZE 2
#endif
uint8_t USART3_TX_QUEUE_BUFFER[USART3_TX_FRAME_MAX_SIZE*USART3_TX_QUEUE_SIZE];
uint8_t USART3_RX_PINGPONG_BUFFER[USART3_RX_FRAME_MAX_SIZE*2];
uint8_t USART3_RX_CIRCULAR_BUFFER[USART3_RX_FRAME_MAX_SIZE*2];
uint8_t USART3_RX_FRAME_BUFFER[USART3_RX_FRAME_MAX_SIZE];
SlimSerial slimSerial3(&huart3,
		USART3_TX_QUEUE_BUFFER,USART3_TX_FRAME_MAX_SIZE,USART3_TX_QUEUE_SIZE,
		USART3_RX_PINGPONG_BUFFER,USART3_RX_FRAME_MAX_SIZE,
		USART3_RX_CIRCULAR_BUFFER,sizeof(USART3_RX_CIRCULAR_BUFFER),
		USART3_RX_FRAME_BUFFER,USART3_RX_FRAME_MAX_SIZE,USART3_FRAME_TYPE,
		USART3_485_Tx_EN_GPIO_Port,
		USART3_485_Tx_EN_GPIO_Pin,
		USART3_TX_MODE,
		USART3_RX_ENABLE);
#endif
#if ENABLE_SLIMSERIAL_USART4==1
#if PRINTF_USART == huart4
#define USART4_TX_QUEUE_SIZE 2
#else
#define USART4_TX_QUEUE_SIZE 2
#endif
uint8_t USART4_TX_QUEUE_BUFFER[USART4_TX_FRAME_MAX_SIZE*USART4_TX_QUEUE_SIZE];
uint8_t USART4_RX_PINGPONG_BUFFER[USART4_RX_FRAME_MAX_SIZE*2];
uint8_t USART4_RX_CIRCULAR_BUFFER[USART4_RX_FRAME_MAX_SIZE*2];
uint8_t USART4_RX_FRAME_BUFFER[USART4_RX_FRAME_MAX_SIZE];
SlimSerial slimSerial4(&huart4,
		USART4_TX_QUEUE_BUFFER,USART4_TX_FRAME_MAX_SIZE,USART4_TX_QUEUE_SIZE,
		USART4_RX_PINGPONG_BUFFER,USART4_RX_FRAME_MAX_SIZE,
		USART4_RX_CIRCULAR_BUFFER,sizeof(USART4_RX_CIRCULAR_BUFFER),
		USART4_RX_FRAME_BUFFER,USART4_RX_FRAME_MAX_SIZE,USART4_FRAME_TYPE,
		USART4_485_Tx_EN_GPIO_Port,
		USART4_485_Tx_EN_GPIO_Pin,
		USART4_TX_MODE,
		USART4_RX_ENABLE);
#endif
#if ENABLE_SLIMSERIAL_USART5==1
#if PRINTF_USART == huart5
#define USART5_TX_QUEUE_SIZE 2
#else
#define USART5_TX_QUEUE_SIZE 2
#endif
uint8_t USART5_TX_QUEUE_BUFFER[USART5_TX_FRAME_MAX_SIZE*USART5_TX_QUEUE_SIZE];
uint8_t USART5_RX_PINGPONG_BUFFER[USART5_RX_FRAME_MAX_SIZE*2];
uint8_t USART5_RX_CIRCULAR_BUFFER[USART5_RX_FRAME_MAX_SIZE*2];
uint8_t USART5_RX_FRAME_BUFFER[USART5_RX_FRAME_MAX_SIZE];
SlimSerial slimSerial5(&huart5,
		USART5_TX_QUEUE_BUFFER,USART5_TX_FRAME_MAX_SIZE,USART5_TX_QUEUE_SIZE,
		USART5_RX_PINGPONG_BUFFER,USART5_RX_FRAME_MAX_SIZE,
		USART5_RX_CIRCULAR_BUFFER,sizeof(USART5_RX_CIRCULAR_BUFFER),
		USART5_RX_FRAME_BUFFER,USART5_RX_FRAME_MAX_SIZE,USART5_FRAME_TYPE,
		USART5_485_Tx_EN_GPIO_Port,
		USART5_485_Tx_EN_GPIO_Pin,
		USART5_TX_MODE,
		USART5_RX_ENABLE);
#endif
#if ENABLE_SLIMSERIAL_USART6==1
#if PRINTF_USART == huart6
#define USART6_TX_QUEUE_SIZE 2
#else
#define USART6_TX_QUEUE_SIZE 2
#endif
uint8_t USART6_TX_QUEUE_BUFFER[USART6_TX_FRAME_MAX_SIZE*USART6_TX_QUEUE_SIZE];
uint8_t USART6_RX_PINGPONG_BUFFER[USART6_RX_FRAME_MAX_SIZE*2];
uint8_t USART6_RX_CIRCULAR_BUFFER[USART6_RX_FRAME_MAX_SIZE*2];
uint8_t USART6_RX_FRAME_BUFFER[USART6_RX_FRAME_MAX_SIZE];
SlimSerial slimSerial6(&huart6,
		USART6_TX_QUEUE_BUFFER,USART6_TX_FRAME_MAX_SIZE,USART6_TX_QUEUE_SIZE,
		USART6_RX_PINGPONG_BUFFER,USART6_RX_FRAME_MAX_SIZE,
		USART6_RX_CIRCULAR_BUFFER,sizeof(USART6_RX_CIRCULAR_BUFFER),
		USART6_RX_FRAME_BUFFER,USART6_RX_FRAME_MAX_SIZE,USART6_FRAME_TYPE,
		USART6_485_Tx_EN_GPIO_Port,
		USART6_485_Tx_EN_GPIO_Pin,
		USART6_TX_MODE,
		USART6_RX_ENABLE);
#endif
#if ENABLE_SLIMSERIAL_USART7==1
#if PRINTF_USART == huart7
#define USART7_TX_QUEUE_SIZE 2
#else
#define USART7_TX_QUEUE_SIZE 2
#endif
uint8_t USART7_TX_QUEUE_BUFFER[USART7_TX_FRAME_MAX_SIZE*USART7_TX_QUEUE_SIZE];
uint8_t USART7_RX_PINGPONG_BUFFER[USART7_RX_FRAME_MAX_SIZE*2];
uint8_t USART7_RX_CIRCULAR_BUFFER[USART7_RX_FRAME_MAX_SIZE*2];
uint8_t USART7_RX_FRAME_BUFFER[USART7_RX_FRAME_MAX_SIZE];
SlimSerial slimSerial7(&huart7,
		USART7_TX_QUEUE_BUFFER,USART7_TX_FRAME_MAX_SIZE,USART7_TX_QUEUE_SIZE,
		USART7_RX_PINGPONG_BUFFER,USART7_RX_FRAME_MAX_SIZE,
		USART7_RX_CIRCULAR_BUFFER,sizeof(USART7_RX_CIRCULAR_BUFFER),
		USART7_RX_FRAME_BUFFER,USART7_RX_FRAME_MAX_SIZE,USART7_FRAME_TYPE,
		USART7_485_Tx_EN_GPIO_Port,
		USART7_485_Tx_EN_GPIO_Pin,
		USART7_TX_MODE,
		USART7_RX_ENABLE);
#endif
#if ENABLE_SLIMSERIAL_USART8==1
#if PRINTF_USART == huart8
#define USART8_TX_QUEUE_SIZE 2
#else
#define USART8_TX_QUEUE_SIZE 2
#endif
uint8_t USART8_TX_QUEUE_BUFFER[USART8_TX_FRAME_MAX_SIZE*USART8_TX_QUEUE_SIZE];
uint8_t USART8_RX_PINGPONG_BUFFER[USART8_RX_FRAME_MAX_SIZE*2];
uint8_t USART8_RX_CIRCULAR_BUFFER[USART8_RX_FRAME_MAX_SIZE*2];
uint8_t USART8_RX_FRAME_BUFFER[USART8_RX_FRAME_MAX_SIZE];
SlimSerial slimSerial8(&huart8,
		USART8_TX_QUEUE_BUFFER,USART8_TX_FRAME_MAX_SIZE,USART8_TX_QUEUE_SIZE,
		USART8_RX_PINGPONG_BUFFER,USART8_RX_FRAME_MAX_SIZE,
		USART8_RX_CIRCULAR_BUFFER,sizeof(USART8_RX_CIRCULAR_BUFFER),
		USART8_RX_FRAME_BUFFER,USART8_RX_FRAME_MAX_SIZE,USART8_FRAME_TYPE,
		USART8_485_Tx_EN_GPIO_Port,
		USART8_485_Tx_EN_GPIO_Pin,
		USART8_TX_MODE,
		USART8_RX_ENABLE);
#endif
 
std::array<uint8_t,1029*2> USART_PROXY_RX_PINGPONG_BUFFER;
std::array<uint8_t,4096> USART_PROXY_RX_CIRCULAR_BUFFER;
std::array<uint8_t,1029> USART_PROXY_RX_FRAME_BUFFER;


inline constexpr uint16_t SLIM_SERIAL_TOTAL_NUM=(ENABLE_SLIMSERIAL_USART1+ENABLE_SLIMSERIAL_USART2+ENABLE_SLIMSERIAL_USART3+ENABLE_SLIMSERIAL_USART4+ENABLE_SLIMSERIAL_USART5+ENABLE_SLIMSERIAL_USART6+ENABLE_SLIMSERIAL_USART7+ENABLE_SLIMSERIAL_USART8);




SlimSerial *slimSerialDevices[SLIM_SERIAL_TOTAL_NUM]={
#if ENABLE_SLIMSERIAL_USART1
		&slimSerial1,
#endif
#if ENABLE_SLIMSERIAL_USART2
		&slimSerial2,
#endif
#if ENABLE_SLIMSERIAL_USART3
		&slimSerial3,
#endif
#if ENABLE_SLIMSERIAL_USART4
		&slimSerial4,
#endif
#if ENABLE_SLIMSERIAL_USART5
		&slimSerial5,
#endif
#if ENABLE_SLIMSERIAL_USART6
		&slimSerial6,
#endif
#if ENABLE_SLIMSERIAL_USART7
		&slimSerial7,
#endif
#if ENABLE_SLIMSERIAL_USART8
		&slimSerial8,
#endif
};

// std::unordered_map<UART_HandleTypeDef *,SlimSerial *> slimSerialMap={
// #if ENABLE_SLIMSERIAL_USART1
// 		{&huart1,&slimSerial1},
// #endif
// #if ENABLE_SLIMSERIAL_USART2
// 		{&huart2,&slimSerial2},
// #endif
// #if ENABLE_SLIMSERIAL_USART3
// 		{&huart3,&slimSerial3},
// #endif
// #if ENABLE_SLIMSERIAL_USART4
// 		{&huart4,&slimSerial4},
// #endif
// #if ENABLE_SLIMSERIAL_USART5
// 		{&huart5,&slimSerial5},
// #endif
// #if ENABLE_SLIMSERIAL_USART6
// 		{&huart6,&slimSerial6},
// #endif
// #if ENABLE_SLIMSERIAL_USART7
// 		{&huart7,&slimSerial7},
// #endif
// #if ENABLE_SLIMSERIAL_USART8
// 		{&huart8,&slimSerial8},
// #endif
// };

UART_HandleTypeDef *usartHandles[SLIM_SERIAL_TOTAL_NUM]={
#if ENABLE_SLIMSERIAL_USART1
		&huart1,
#endif
#if ENABLE_SLIMSERIAL_USART2
		&huart2,
#endif
#if ENABLE_SLIMSERIAL_USART3
		&huart3,
#endif
#if ENABLE_SLIMSERIAL_USART4
		&huart4,
#endif
#if ENABLE_SLIMSERIAL_USART5
		&huart5,
#endif
#if ENABLE_SLIMSERIAL_USART6
		&huart6,
#endif
#if ENABLE_SLIMSERIAL_USART7
		&huart7,
#endif
#if ENABLE_SLIMSERIAL_USART8
		&huart8
#endif
};

SlimSerial::SlimSerial(UART_HandleTypeDef *uartHandle,
			uint8_t 		*tx_queue_buf,
			uint16_t 		tx_queue_buf_single_size,
			uint8_t		 tx_queue_size,
			uint8_t   *rx_pingpong_buf,
			uint16_t   rx_pingpong_buf_half_size,
			uint8_t   *rx_circular_buf,
			uint16_t rx_circular_buf_size,
			uint8_t  *rx_frame_buf,
			uint16_t rx_frame_buf_size,
			uint8_t rx_frame_type,
			GPIO_TypeDef* tx_485_En_Port,
			uint16_t tx_485_En_Pin,
			uint8_t tx_method,
			uint8_t rx_enable)
:m_rx_circular_buf(rx_circular_buf,rx_circular_buf_size),
 m_frameCallbackFuncArray{}{

	m_huart = uartHandle;

	//tx buffer
	m_tx_queue_buf = tx_queue_buf;
	m_tx_queue_buf_single_size = tx_queue_buf_single_size;
	m_tx_queue_size = tx_queue_size;
	m_tx_buf_ind = 0;

	//rx pingpong buf
	m_rx_pingpong_buf = rx_pingpong_buf;
	m_rx_pingpong_buf_half_size = rx_pingpong_buf_half_size;

	//rx data
	m_rx_frame_buf = rx_frame_buf;
	m_rx_frame_buf_size=rx_frame_buf_size;


	//485 tx enable pin
	Tx_EN_Port = tx_485_En_Port;
	Tx_EN_Pin = tx_485_En_Pin;

	//
	m_rx_enable = rx_enable;
	m_rx_last.pdata = m_rx_frame_buf;
	m_rx_last.dataBytes=0;
	m_rx_frame_type = rx_frame_type;

	m_totalTxBytes=0;
	m_totalRxBytes=0;
	m_totalTxFrames=0;
	m_totalRxFrames=0;
  
	//header whitelist    5A A5   or FF FF
	addHeaderFilter(0x5A,0xA5);
	addHeaderFilter(0xFF,0xFF);
	toggleHeaderFilter(true);

	//address whitelist. disabled by default
	addAddressFilter(0xFF);
	toggleAddressFilter(false);


	//add funcode filter
	addFuncodeFilter(0x00);
	toggleAddressFilter(false);

	//
	lengthFilterOn=true;
	m_TX_Method = tx_method;


	//
	m_frameCallbackFuncNumber=0;
	m_frameCallbackFuncNumber_C=0;
	m_frameCallbackFuncNumber_all=0;
	for(int i=0;i<SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN;i++){
		m_frameCallbackFuncArray[i]=std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes)>{};
		m_frameCallbackFuncArray_C[i]=NULL;
	}


	//mutex
	writeMtx = xSemaphoreCreateMutexStatic( &writeMtxBuffer );
	readMtx = xSemaphoreCreateMutexStatic( &readMtxBuffer );

	//thread
	rxThreadID = 0;
	txrxThreadID = 0;

	debugOutputEnable=1;

	//proxy
	m_proxy_port = NULL;
	m_proxy_mode = SLIMSERIAL_TXRX_NORMAL;
 	m_last_baudrate = 0;
 
	m_original_rx_pingpong_buf = m_rx_pingpong_buf;
	m_original_rx_pingpong_buf_half_size = m_rx_pingpong_buf_half_size;
 
	m_original_rx_frame_buf = m_rx_frame_buf;
	m_original_rx_frame_buf_size=m_rx_frame_buf_size;
    
 
	m_original_rx_circular_buf = m_rx_circular_buf.buffer;
	m_original_rx_circular_buf_size = m_rx_circular_buf.bufferSize;


	//init rx state
	toggle485Tx(false);

	/* definition and creation of PCInTask */
	if(m_rx_enable){
		createRxTasks();
	}

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
		osThreadStaticDef_modified(rx1Task, rxTaskFuncImpl, osPriorityAboveNormal, 0, SLIMSERIAL_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx1Task), &slimSerial1);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART2
	if(m_huart==&huart2){
		osThreadStaticDef_modified(rx2Task, rxTaskFuncImpl, osPriorityLow, 0, SLIMSERIAL_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx2Task), &slimSerial2);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART3
	if(m_huart==&huart3){
		osThreadStaticDef_modified(rx3Task, rxTaskFuncImpl, osPriorityHigh, 0, SLIMSERIAL_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx3Task), &slimSerial3);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART4
	if(m_huart==&huart4){
		osThreadStaticDef_modified(rx4Task, rxTaskFuncImpl, osPriorityHigh, 0, SLIMSERIAL_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx4Task), &slimSerial4);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART5
	if(m_huart==&huart5){
		osThreadStaticDef_modified(rx5Task, rxTaskFuncImpl, osPriorityAboveNormal, 0, SLIMSERIAL_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx5Task), &slimSerial5);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART6
	if(m_huart==&huart6){
		osThreadStaticDef_modified(rx6Task, rxTaskFuncImpl, osPriorityNormal, 0, SLIMSERIAL_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx6Task), &slimSerial6);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART7
	if(m_huart==&huart7){
		osThreadStaticDef_modified(rx7Task, rxTaskFuncImpl, osPriorityHigh, 0, SLIMSERIAL_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx7Task), &slimSerial7);
		return HAL_OK;
	}
#endif
#if ENABLE_SLIMSERIAL_USART8
	if(m_huart==&huart8){
		osThreadStaticDef_modified(rx8Task, rxTaskFuncImpl, osPriorityHigh, 0, SLIMSERIAL_RX_TASK_BUFFER_SIZE, rxTaskBuffer, &rxTaskControlBlock);
		rxTaskHandle = osThreadCreate((const osThreadDef_t *)osThread(rx8Task), &slimSerial8);
		return HAL_OK;
	}
#endif



	return HAL_ERROR;
}



SlimSerial *getSlimSerial(UART_HandleTypeDef *huart){

    // std::unordered_map<UART_HandleTypeDef *,SlimSerial *>::iterator it = slimSerialMap.find(huart);
    // return (it == slimSerialMap.end()?NULL:it->second);


#if ENABLE_SLIMSERIAL_USART1
    if(huart==&huart1){
    	return &slimSerial1;
    }
#endif
#if ENABLE_SLIMSERIAL_USART2
    if(huart==&huart2){
    	return &slimSerial2;
    }
#endif
#if ENABLE_SLIMSERIAL_USART3
	if(huart==&huart3){
		return &slimSerial3;
	}
#endif
#if ENABLE_SLIMSERIAL_USART4
	if(huart==&huart4){
		return &slimSerial4;
	}
#endif
#if ENABLE_SLIMSERIAL_USART5
	if(huart==&huart5){
		return &slimSerial5;
	}
#endif
#if ENABLE_SLIMSERIAL_USART6
	if(huart==&huart6){
		return &slimSerial6;
	}
#endif
#if ENABLE_SLIMSERIAL_USART7
	if(huart==&huart7){
		return &slimSerial7;
	}
#endif
#if ENABLE_SLIMSERIAL_USART8
	if(huart==&huart8){
		return &slimSerial8;
	}
#endif
	return NULL;
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
	 if(headerFilter_num<SLIMSERIAL_HEADER_FILTER_MAX_LEN-1){
		 headerFilter_num++;
	 }
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
void SlimSerial::toggleHeaderFilter(bool filterOn){
	headerFilterOn = filterOn;
}



void SlimSerial::addAddressFilter(uint8_t address){
	 addressFilter[addressFilter_num]=address;
	 if(addressFilter_num<SLIMSERIAL_ADDRESS_FILTER_MAX_LEN-1){
		 addressFilter_num++;
	 }
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


void SlimSerial::toggleAddressFilter(bool filterOn){
	addressFilterOn = filterOn;
}


void SlimSerial::addFuncodeFilter(uint8_t funcodeIn){
	funcodeFilter[funcodeFilter_num]=funcodeIn;
		 if(funcodeFilter_num<SLIMSERIAL_FUNCODE_FILTER_MAX_LEN-1){
			 funcodeFilter_num++;
		 }
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
void SlimSerial::toggleFuncodeFilter(bool filterOn){
	funcodeFilterOn = filterOn;
}

//void SlimSerial::toggle485Tx(bool txOn){
//	if(Tx_EN_Port)
//		HAL_GPIO_WritePin(Tx_EN_Port,Tx_EN_Pin,(txOn?GPIO_PIN_SET:GPIO_PIN_RESET));
//}


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
};

uint8_t SlimSerial::getRxFrameType(){
	return m_rx_frame_type;
}

//this function will be executed in an async thread
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

	uint32_t timeoutPoint= HAL_GetTick()+timeout;
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
	uint8_t *pbuf=m_tx_queue_meta.back().pdata;
	uint16_t databytes=m_tx_queue_meta.back().dataBytes;

	 if(m_TX_Method==SLIMSERIAL_TX_MODE_BLOCK){
		//ret=HAL_UART_Transmit(m_huart,m_tx_queue_meta.back().pdata,m_tx_queue_meta.back().dataBytes,1000);//too slow to alter Tx_En. changed for faster Tx_En toggle
		USART_TypeDef *uart = m_huart->Instance;
		while(databytes-->0){
#if defined(__STM32F0xx_HAL_H)
				uart->TDR =  (uint8_t)*pbuf&0xFF;
#elif defined(__STM32F4xx_HAL_H) || defined(__STM32F1xx_HAL_H)
				uart->DR =  (uint8_t)*pbuf&0xFF;
#endif
				pbuf++;
				while(!__HAL_UART_GET_FLAG(m_huart, UART_FLAG_TC));
		}
		if(Tx_EN_Port){
				Tx_EN_Port->BSRR = (uint32_t)Tx_EN_Pin << 16U;
		}
		txCpltCallback();

	}
	else if(m_TX_Method==SLIMSERIAL_TX_MODE_DMA){
		ret=HAL_UART_Transmit_DMA(m_huart,pbuf,databytes);
	}
	else if(m_TX_Method==SLIMSERIAL_TX_MODE_IT){
		ret=HAL_UART_Transmit_IT(m_huart,pbuf,databytes);
	}


	if(ret==HAL_OK || (ret==HAL_BUSY && !m_tx_queue_meta.empty())){

		return SD_USART_OK;
	}
	else{
		return SD_USART_ERROR;
	}
}
 

SD_BUF_INFO SlimSerial::bufferTxData(uint8_t *pdata,uint16_t dataBytes) {
	//next buffer bank
	m_tx_buf_ind++;
	if(m_tx_buf_ind>=m_tx_queue_size){
		m_tx_buf_ind = 0;
	}

	//copy data
	if(pdata!=&m_tx_queue_buf[m_tx_buf_ind*m_tx_queue_buf_single_size]){
		memcpy(&m_tx_queue_buf[m_tx_buf_ind*m_tx_queue_buf_single_size],pdata,dataBytes);
	}

	//enqueue meta data
	SD_BUF_INFO sd_buf_info;
	sd_buf_info.pdata = &m_tx_queue_buf[m_tx_buf_ind*m_tx_queue_buf_single_size];
	sd_buf_info.dataBytes= dataBytes;

	return sd_buf_info;

}

SD_BUF_INFO SlimSerial::bufferTxFrame(uint16_t address,uint16_t fcode,uint8_t *payload,uint16_t payloadBytes) {
	//next buffer bank
	m_tx_buf_ind++;
	if(m_tx_buf_ind>=m_tx_queue_size){
		m_tx_buf_ind = 0;
	}

	//assemble data
	uint8_t *pTxFrame = &m_tx_queue_buf[m_tx_buf_ind*m_tx_queue_buf_single_size];
	pTxFrame[0] = 0x5A;
	pTxFrame[1] = 0xA5;
	pTxFrame[2] = address;
	pTxFrame[3] = payloadBytes;
	pTxFrame[4] = fcode;
	memcpy(&pTxFrame[5],payload,payloadBytes);
	uint16_t crc = SD_CRC_Calculate(pTxFrame, payloadBytes + 5);
	pTxFrame[5+payloadBytes] = (uint8_t) (crc &0xFF);
	pTxFrame[5+payloadBytes+1] = (uint8_t)(crc >> 8)&0xFF;

	//enqueue meta data
	SD_BUF_INFO sd_buf_info;
	sd_buf_info.pdata = pTxFrame;
	sd_buf_info.dataBytes= payloadBytes + 7;

	return sd_buf_info;

}

SD_BUF_INFO &SlimSerial::transmitReceiveData(uint8_t *pData,uint16_t dataBytes,uint16_t timeout,bool frameTypeFilterOn){
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


	//start a tx frame
	transmitData(pData, dataBytes);

	//only wait for rx nofification if not in the same thread
	if(txrxThreadID != rxThreadID){
		uint32_t ulTaskNotifyRet = ulTaskNotifyTake(pdTRUE,timeout);//50ms timeout



		if(ulTaskNotifyRet){

			m_rx_status = SD_USART_OK;
		}
		else{
			m_rx_last.dataBytes=0;

			if (m_rx_status==SD_USART_BUSY){
				m_rx_status = SD_USART_TIMEOUT;
			}

		}
	}
	else{
		HAL_Delay(20);

	}

	//restore frame type
	m_rx_frame_type = rxFrameType_temp;

	return m_rx_last;
}


SD_BUF_INFO &SlimSerial::transmitReceiveFrame(uint16_t address,uint16_t fcode,uint8_t *payload,uint16_t payloadBytes,uint16_t timeout){
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


	//start a tx frame
	transmitFrame(address, fcode,payload,payloadBytes);

	//only wait for rx nofification if not in the same thread
	if(txrxThreadID != rxThreadID){
		uint32_t ulTaskNotifyRet = ulTaskNotifyTake(pdTRUE,timeout);//50ms timeout
		if(ulTaskNotifyRet){
			m_rx_status = SD_USART_OK;

		}
		else{
			// no valid frame within timeout
			m_rx_last.dataBytes=0;

			if (m_rx_status==SD_USART_BUSY){
				m_rx_status = SD_USART_TIMEOUT;
			}
		}
	}
	else{
		HAL_Delay(20);
	}

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

void SlimSerial::start_Rx_DMA_Idle(){
	toggle485Tx(false);
	while(Slim_UARTEx_ReceiveToIdle_DMA(m_huart, &(m_rx_pingpong_buf[m_rx_pingpong_receiving_ind]), m_rx_pingpong_buf_half_size) != HAL_OK)
	{
		HAL_UART_AbortReceive_IT(m_huart);



	}
	__HAL_DMA_DISABLE_IT(m_huart->hdmarx, DMA_IT_HT); // we don't need half-transfer interrupt

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


void SlimSerial::rxCpltCallback(uint16_t bytes_received)
{

	m_rx_time_start = currentTime_us();
	m_tx_once=0;
	m_rx_pingpong_last.pdata  = &(m_rx_pingpong_buf[m_rx_pingpong_receiving_ind]);
	m_rx_pingpong_last.dataBytes = bytes_received;
	m_totalRxBytes += bytes_received;


	//one producer, no need to lock
	m_rx_circular_buf.in(m_rx_pingpong_last.pdata, m_rx_pingpong_last.dataBytes);

	m_rx_pingpong_receiving_ind += m_rx_pingpong_buf_half_size;

	m_rx_pingpong_receiving_ind = m_rx_pingpong_receiving_ind>=(m_rx_pingpong_buf_half_size*2)?0:m_rx_pingpong_buf_half_size;

	/* @note  Lock treatment in interrupt callback.
	*
	* 		The reason is to avoid lock competetion in a Rx Interrupt callback triggered during the middle of a Tx configuration, where the lock is already on.
	* 		The successive call of HAL_UARTEx_ReceiveToIdle_DMA in the Rx Interrupt callback will never get the lock, and would either hang there or miss the re-armed Rx process.
	*
	* @note   1. One solution is to delay the successive call to  HAL_UARTEx_ReceiveToIdle_DMA in the handling thread other than in the interrupt callback.
	* 		But this still needs to carefully design the Rx thread considering teh necessary context switching waiting for the lock.
	*
	* 		2. A second solution is to remove the Rx lock inside the interrupt call, which is most of the time reasonable, since it is only called here, and the related content is
	* 		isolated with Tx settings.
	*
	* 		3. (Used here) A third solultion is to temperarily get the lock and release it after the successive call of HAL_UARTEx_ReceiveToIdle_DMA in the Rx interruput callback.
	*/
	int locked=0;
	if(m_huart->Lock == HAL_LOCKED){
		locked=1;
		m_huart->Lock = HAL_UNLOCKED;
	}
	start_Rx_DMA_Idle();
	if(locked){
		m_huart->Lock = HAL_LOCKED;
	}

	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	vTaskNotifyGiveFromISR((TaskHandle_t)(rxThreadID),&xHigherPriorityTaskWoken);

	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}


//uint8_t serialTemp[128];

void SlimSerial::rxHandlerThread() {
	uint32_t ulTaskNotifyRet = 0;
	 /*get ready for receive*/
	rxThreadID = (uint32_t *)osThreadGetId();

	osDelay(50);
	start_Rx_DMA_Idle();

	/* Infinite loop */
	for (;;) {

		ulTaskNotifyRet = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		if(rxNeedRestart){
			rxNeedRestart=0;
			start_Rx_DMA_Idle();
		}

		//un
		if (!(ulTaskNotifyRet && m_rx_pingpong_last.dataBytes>0))
			continue;

		uint16_t remainingBytes=m_rx_circular_buf.availableData();

		if(m_rx_frame_type == SLIMSERIAL_FRAME_TYPE_0_ANY){

			m_rx_circular_buf.out(m_rx_last.pdata, remainingBytes);

			m_rx_last.dataBytes = remainingBytes;

			receivedACK = true;

			m_totalRxFrames++;

			callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);

			//notify potential txrx thread
			if (txrxThreadID != NULL) {
				xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
			}

			m_rx_status = SD_USART_OK;
			continue;
		}
		else if(m_rx_frame_type==SLIMSERIAL_FRAME_TYPE_1){
			//std::unique_lock<std::mutex> lk_decode(decodeMtx);
			//5+N+2
			//Header1 + Header2 + Src + dataBytes +  Funcode  + data + crc16
			// dataBytes =   sizeof(data)
			if(getProxyMode()==SLIMSERIAL_TXRX_NORMAL){
				while (remainingBytes >= 7) {

					//check header, current support 5A A5 and FF FF
					uint8_t header[2]={m_rx_circular_buf.peekAt(0),m_rx_circular_buf.peekAt(1)};
					if (applyHeaderFilter(header[0], header[1])) {

						//check address. disabled by default. Call toggleAddressFilter(True) to enable
						uint8_t addressIn = m_rx_circular_buf.peekAt(2);
						if(applyAddressFilter(addressIn)){

							//check address. disabled by default. Call toggleFuncodeFilter(True) to enable
							uint8_t funcodeIn = m_rx_circular_buf.peekAt(4);
							if(applyFuncodeFilter(funcodeIn)){

								//total frame length
								uint16_t expectedFrameBytes;
								if(lengthFilterOn){
									expectedFrameBytes = m_rx_circular_buf.peekAt(3) + 7;
								}
								else{
									expectedFrameBytes=remainingBytes;
								}
								//check length
								if (expectedFrameBytes <= m_rx_pingpong_buf_half_size){

									if (expectedFrameBytes <= remainingBytes) {

										//valid CRC
										uint16_t crc1 = m_rx_circular_buf.calculateCRC(expectedFrameBytes - 2);
										uint16_t crc2 = m_rx_circular_buf.peekAt_U16(expectedFrameBytes - 2);

										if (crc1 == crc2) {

											//read out one valid frame from ring buffer to m_rx_last
											m_rx_circular_buf.out(m_rx_last.pdata, expectedFrameBytes);
											m_rx_last.dataBytes = expectedFrameBytes;
											remainingBytes -= expectedFrameBytes;
											//process frame

											receivedACK = true;

											m_totalRxFrames++;
											
											if(funcodeIn == FUNC_ENABLE_PROXY){
												//enable proxy
												uint8_t proxyPortIndex_ =  m_rx_last.pdata[5] ;
												uint32_t proxyPortBaudrate_= m_rx_last.pdata[6] | ((uint32_t)m_rx_last.pdata[7])<<8 | ((uint32_t)m_rx_last.pdata[8])<<16 | ((uint32_t)m_rx_last.pdata[9])<<24;
												enableProxy(proxyPortIndex_,proxyPortBaudrate_);
												ackProxy();
											}
											else if(funcodeIn == FUNC_DISABLE_PROXY){
												//should take no effect. Anyway, we respond to the request
												disableProxy();
												ackProxy();
											}
											else{
												callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);
													//notify potential txrx thread
												if (txrxThreadID != NULL) {
													xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
												}

												m_rx_status = SD_USART_OK;
												continue;
											}
										}

										else {
											//bad crc
											m_rx_circular_buf.out(1);
											remainingBytes--;
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
									m_rx_circular_buf.out(1);
									remainingBytes--;
									m_rx_status = SD_USART_ERROR;
									continue;
								}
							}
							else{//invalid funcode
								m_rx_circular_buf.out(1);
								remainingBytes--;
								m_rx_status = SD_USART_ERROR;
								continue;
							}
						}
						else{//invalid address
							m_rx_circular_buf.out(1);
							remainingBytes--;
							m_rx_status = SD_USART_ERROR;
							continue;
						}
					} else {//invalid header
						m_rx_circular_buf.out(1);
						remainingBytes--;
						m_rx_status = SD_USART_ERROR;
						continue;
					}

				}
			}
			else if(getProxyMode()==SLIMSERIAL_TXRX_TRANSPARENT){
				m_rx_circular_buf.out(m_rx_last.pdata, remainingBytes);
				m_rx_last.dataBytes = remainingBytes;
				m_totalRxFrames++;

				//in transparent mode, only check FUNC_DISABLE_PROXY to disable proxy
				if( m_rx_last.dataBytes>=7 &&
				 	m_rx_last.pdata[0]==0x5A &&
					m_rx_last.pdata[1]==0xA5 &&
					m_rx_last.pdata[2]==0x00 &&
					m_rx_last.pdata[3]==0x00 &&
					m_rx_last.pdata[4]==((uint8_t)FUNC_DISABLE_PROXY)
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
		}
		else if (m_rx_frame_type == SLIMSERIAL_FRAME_TYPE_2){
			//std::unique_lock<std::mutex> lk_decode(decodeMtx);

			//2+N+2
			//Header1 + Header2 + databytes + data + crc16
			//databytes = 1 + sizeof(data)
			while (remainingBytes >= 4) {

				//check header, current support 5A A5 and FF FF
				uint8_t header[2]={m_rx_circular_buf.peekAt(0),m_rx_circular_buf.peekAt(1)};
				if (applyHeaderFilter(header[0], header[1])) {

					//total frame length
					uint16_t expectedFrameBytes;
					if(lengthFilterOn){
						expectedFrameBytes = m_rx_circular_buf.peekAt(2) + 4;
					}
					else{
						expectedFrameBytes=remainingBytes;
					}
					//check length
					if (expectedFrameBytes <= m_rx_pingpong_buf_half_size){

						if (expectedFrameBytes <= remainingBytes) {

							//valid CRC
							uint16_t crc1 = m_rx_circular_buf.calculateCRC(expectedFrameBytes - 2);
							uint16_t crc2 = m_rx_circular_buf.peekAt_U16(expectedFrameBytes - 2);

							if (crc1 == crc2) {

								//read out one valid frame from ring buffer to m_rx_last
								m_rx_circular_buf.out(m_rx_last.pdata, expectedFrameBytes);
								m_rx_last.dataBytes = expectedFrameBytes;
								remainingBytes -= expectedFrameBytes;
								//process frame

								receivedACK = true;

								m_totalRxFrames++;

								callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);



								//notify potential txrx thread
								if (txrxThreadID != NULL) {
									xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
								}

								m_rx_status = SD_USART_OK;
								continue;

							}

							else {
								//bad crc
								m_rx_circular_buf.out(1);
								remainingBytes--;
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
						m_rx_circular_buf.out(1);
						remainingBytes--;
						m_rx_status = SD_USART_ERROR;
						continue;
					}

				} else {//invalid header
					m_rx_circular_buf.out(1);
					remainingBytes--;
					m_rx_status = SD_USART_ERROR;
					continue;
				}
			}
		}
		else if(m_rx_frame_type==SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM){

			//std::unique_lock<std::mutex> lk_decode(decodeMtx);

			//modbus frame
			//src + funcode + data + crc16
			while (remainingBytes >= 8) {

				//check address. disabled by default
				//uint8_t addressIn = m_rx_circular_buf.peekAt(0);


				//check funcode
				uint16_t funcode = m_rx_circular_buf.peekAt(1);

				if (funcode == 0x03 || funcode == 0x06 || funcode == 0x10) {

					uint16_t expectedFrameBytes =0 ;
					if (funcode == 0x03) {
					  expectedFrameBytes  = 8;
					}
					else if(funcode == 0x06){
					  expectedFrameBytes  =  m_rx_circular_buf.availableData();//special treatment for 0x06
					}
					else if (funcode == 0x10) {
					  expectedFrameBytes  =  (uint16_t)(m_rx_circular_buf.peekAt(6)) + 9;
					}

		            // got enough rx bytes
		            if (remainingBytes >= expectedFrameBytes) {
							//valid CRC
							uint16_t crc1 = m_rx_circular_buf.calculateCRC(expectedFrameBytes - 2);
							uint16_t crc2 = m_rx_circular_buf.peekAt_U16(expectedFrameBytes - 2);

							if (crc1 == crc2) {

								//read out one valid frame from ring buffer to m_rx_last
								m_rx_circular_buf.out(m_rx_last.pdata, expectedFrameBytes);
								m_rx_last.dataBytes = expectedFrameBytes;
								remainingBytes -= expectedFrameBytes;
								//process frame

								receivedACK = true;

								m_totalRxFrames++;

								callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);



								//notify potential txrx thread
								if (txrxThreadID != NULL) {
									xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
								}

								m_rx_status = SD_USART_OK;
								continue;

							}

							else {
								//bad crc
								 if(funcode == 0x06 && m_rx_circular_buf.availableData()<256){//special treatment for 0x06
								  m_rx_status = SD_USART_BUSY;
								  break;
								}
								else{
								  int discardN = m_rx_circular_buf.availableData();
								  m_rx_circular_buf.out(discardN);
								  remainingBytes -= discardN;

								  continue;
								}

								m_rx_circular_buf.out(1);
								remainingBytes--;
								m_rx_status = SD_USART_ERROR;
								continue;
							}
		            } else {//unfinished frame
		              m_rx_status = SD_USART_BUSY;
		              break;
		            }
				} else {
					//bad funcode
					m_rx_circular_buf.out(1);
					remainingBytes--;
					m_rx_status = SD_USART_ERROR;
					continue;

				}
			}
		}
		else if(m_rx_frame_type==SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM){

				//std::unique_lock<std::mutex> lk_decode(decodeMtx);

				//modbus frame
				//src + funcode + data + crc16
				while (remainingBytes >= 5) {

					//check address. disabled by default
					//uint8_t addressIn = m_rx_circular_buf.peekAt(0);


					//check funcode
					uint16_t funcode = m_rx_circular_buf.peekAt(1);

					if (funcode == 0x03 || funcode == 0x06 || funcode == 0x10 || funcode == (0x83) || funcode == 0x86 || funcode == 0x90) {

						 uint16_t expectedFrameBytes=0;
						if (funcode == 0x03) {
						  expectedFrameBytes  = (uint8_t)(m_rx_circular_buf.peekAt(2)) + 5;
						}
						else if(funcode == 0x06){
						  expectedFrameBytes  =  m_rx_circular_buf.availableData();//special treatment for 0x06
						}
						else if (funcode == 0x10) {
						  expectedFrameBytes  =  8;
						}
						else{
							expectedFrameBytes = 5;//error reply frame
						}

						 if (remainingBytes >= expectedFrameBytes) {
							//valid CRC
							uint16_t crc1 = m_rx_circular_buf.calculateCRC(expectedFrameBytes - 2);
							uint16_t crc2 = m_rx_circular_buf.peekAt_U16(expectedFrameBytes - 2);

							if (crc1 == crc2) {

								//read out one valid frame from ring buffer to m_rx_last
								m_rx_circular_buf.out(m_rx_last.pdata, expectedFrameBytes);
								m_rx_last.dataBytes = expectedFrameBytes;
								remainingBytes -= expectedFrameBytes;
								//process frame

								receivedACK = true;

								m_totalRxFrames++;

								callRxCallbackArray(this,m_rx_last.pdata, m_rx_last.dataBytes);



								//notify potential txrx thread
								if (txrxThreadID != NULL) {
									xTaskNotify((TaskHandle_t )txrxThreadID, 1, eSetValueWithOverwrite);
								}

								m_rx_status = SD_USART_OK;
								continue;

							}

							else {
								//bad crc
								 if(funcode == 0x06 && m_rx_circular_buf.availableData()<256){//special treatment for 0x06
								  m_rx_status = SD_USART_BUSY;
								  break;
								}
								else{
								  int discardN = m_rx_circular_buf.availableData();
								  m_rx_circular_buf.out(discardN);
								  remainingBytes -= discardN;

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
						m_rx_circular_buf.out(1);
						remainingBytes--;
						m_rx_status = SD_USART_ERROR;
						continue;

					}
				}
			}

		else if(m_rx_frame_type==SLIMSERIAL_FRAME_TYPE_NONE){

		}
		m_rx_time_end = currentTime_us();
		m_rx_time_cost = m_rx_time_end-m_rx_time_start;
		m_txrx_time_cost = m_rx_time_end-m_tx_time_start;

	}
}


void SlimSerial::restartRxFromISR(){
	rxNeedRestart=1;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	vTaskNotifyGiveFromISR((TaskHandle_t)(rxThreadID),&xHigherPriorityTaskWoken);
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void SlimSerial::proxyDelegateMessage(uint8_t *pData,uint16_t databytes){
  
	//direct enqueue without buffering to tx
	SD_BUF_INFO sd_buf_info={pdata,databytes}; 

	//enqueue the buffered data
	m_tx_queue_meta.push(sd_buf_info);
 
	m_proxy_port->transmitLL();
}

void SlimSerial::ackProxy(){
	transmitFrameLL(0x00,FUNC_ACK_PROXY,NULL,0);
}
 
SLIMSERIAL_PROXY_MODE SlimSerial::getProxyMode() {

    return m_proxy_mode;

}

void SlimSerial::enableProxy(uint8_t proxy_port_index,uint32_t proxy_port_baudrate){
	SlimSerial *proxy_port_;
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



	if(proxy_port_){
 

		if(m_proxy_port!=NULL && m_proxy_port!=proxy_port_){//stop previous proxy chain
			disableProxy();
		}

		//change settings of current serial port
		m_proxy_port = proxy_port_;
		m_proxy_mode = SLIMSERIAL_TXRX_TRANSPARENT; 

		//change rx buffer of current serial port to dedicated buffer
		m_rx_circular_buf.reset(&USART_PROXY_RX_CIRCULAR_BUFFER[0],USART_PROXY_RX_CIRCULAR_BUFFER.size());
		m_rx_pingpong_buf = &USART_PROXY_RX_PINGPONG_BUFFER[0];
		m_rx_pingpong_buf_half_size = USART_PROXY_RX_PINGPONG_BUFFER.size()/2;
		m_rx_pingpong_receiving_ind = 0;
		m_rx_frame_buf =  &USART_PROXY_RX_FRAME_BUFFER[0];
		m_rx_frame_buf_size = USART_PROXY_RX_FRAME_BUFFER.size();
		m_rx_last.pdata = m_proxy_port->m_rx_frame_buf;
		m_rx_last.dataBytes = 0;


		//change settings of  proxy serial port		
		m_proxy_port->m_proxy_port = this;
		m_proxy_port->m_proxy_mode = SLIMSERIAL_TXRX_TRANSPARENT;

		//change baudrate of  proxy serial port	
		if(proxy_port_baudrate == 0 || proxy_port_baudrate==1000000 || proxy_port_baudrate==115200 || proxy_port_baudrate==921600){
			m_proxy_port->setBaudrate(proxy_port_baudrate);
		}

 

	}

}
void SlimSerial::disableProxy(){
	if(m_proxy_port!=NULL){

		//disable in chain
		m_proxy_port->transmitFrameLL(0x00,FUNC_DISABLE_PROXY,NULL,0);

		//restore baudrate if necessary
		m_proxy_port->setBaudrate();

		m_proxy_port->m_proxy_mode = SLIMSERIAL_TXRX_NORMAL;
		m_proxy_port->m_proxy_port = NULL;

		//restore rx buffer of current serial port
		m_rx_circular_buf.reset(m_original_rx_circular_buf,m_original_rx_circular_buf_size);
		m_rx_pingpong_buf = m_original_rx_pingpong_buf;
		m_rx_pingpong_buf_half_size = m_original_rx_pingpong_buf_half_size;
		m_rx_pingpong_receiving_ind = 0;
		m_rx_frame_buf =  m_original_rx_frame_buf;
		m_rx_frame_buf_size = m_original_rx_frame_buf_size;
		m_rx_last.pdata = m_rx_frame_buf;
		m_rx_last.dataBytes = 0;
	}
	m_proxy_mode = SLIMSERIAL_TXRX_NORMAL;
	m_proxy_port = NULL;
}
//0 for original baudrate
void SlimSerial::setBaudrate(uint32_t baudrate){
	if(baudrate!=m_last_baudrate){
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





/************************************							*************************************/
/************************************	overwrite HAL functions *************************************/
/************************************							************************************/
extern "C" {

/*Redirect printf() by implementing _write  or  fputc based on different compiler*/
#if defined(__GNUC__) && defined(PRINTF_USART)
int _write(int file, char *pSrc, int len){
	SlimSerial *slimSerialDev=getSlimSerial(&PRINTF_USART);
	if(slimSerialDev){
		return slimSerialDev->transmitData((uint8_t *)pSrc,len);
	}
	else
		return 0;
}
#elif defined (__CC_ARM)
int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&PRINTF_USART, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
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
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t bytes_received)
{
	SlimSerial *slimSerialDev=getSlimSerial(huart);
	if(slimSerialDev){
		slimSerialDev->rxCpltCallback(bytes_received);
	}

}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

	//restart
	SlimSerial *slimSerialDev=getSlimSerial(huart);
	if(slimSerialDev){
		slimSerialDev->restartRxFromISR();
	}

}
}
