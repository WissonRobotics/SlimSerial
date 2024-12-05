#ifndef SLIM_SERIAL_H_
#define SLIM_SERIAL_H_
#pragma once
#include <main.h>
#include "stdio.h"
#include "usart.h"
#include "cmsis_os.h"
#include <functional>
#include <slimCircularBuffer.hpp>
#include "static_queue.hpp"
#include "slimSerial_Configs.h"

#define INTERNAL_MAX_FRAME_SIZE 1024

typedef struct SLIMSERIAL_FRAME_TYPE_0_TAG {
	union {
		uint8_t data8[INTERNAL_MAX_FRAME_SIZE];
		int16_t data16[INTERNAL_MAX_FRAME_SIZE/2];
		uint16_t dataU16[INTERNAL_MAX_FRAME_SIZE/2];
	} payload;

} __attribute__((packed)) SLIMSERIAL_FRAME_STRUCT_TYPE_ANY;

typedef struct SLIMSERIAL_FRAME_TYPE_1_TAG {

	uint8_t header[2];
	uint8_t src;
	uint8_t payloadBytes;
	uint8_t funcode;
	union {
		uint8_t data8[INTERNAL_MAX_FRAME_SIZE];
		int16_t data16[INTERNAL_MAX_FRAME_SIZE/2];
		uint16_t dataU16[INTERNAL_MAX_FRAME_SIZE/2];
	} payload;

} __attribute__((packed)) SLIMSERIAL_FRAME_STRUCT_TYPE_1;


typedef struct SLIMSERIAL_FRAME_TYPE_2_TAG {

	uint8_t header[2];
	uint8_t payloadBytes;
	uint8_t funcode;
	union {
		uint8_t data8[INTERNAL_MAX_FRAME_SIZE];
		int16_t data16[INTERNAL_MAX_FRAME_SIZE/2];
		uint16_t dataU16[INTERNAL_MAX_FRAME_SIZE/2];
	} payload;

} __attribute__((packed)) SLIMSERIAL_FRAME_STRUCT_TYPE_2;

typedef struct SLIMSERIAL_FRAME_TYPE_3_MODBUS_TAG {

	uint8_t address;
	uint8_t funcode;
	union {
		uint8_t data8[INTERNAL_MAX_FRAME_SIZE];
		int16_t data16[INTERNAL_MAX_FRAME_SIZE/2];
		uint16_t dataU16[INTERNAL_MAX_FRAME_SIZE/2];
	} payload;

} __attribute__((packed)) SLIMSERIAL_FRAME_STRUCT_TYPE_3;



typedef enum
{
  SD_USART_OK       = 0x00U,
  SD_USART_BAD_FRAME,
  SD_USART_TIMEOUT,
  SD_USART_BUSY,
  SD_USART_ERROR,
} SD_USART_StatusTypeDef;


typedef struct SD_BUF_TAG{
	uint8_t *pdata;
	uint16_t dataBytes;
}SD_BUF_INFO;

typedef enum
{
  SLIMSERIAL_FRAME_TYPE_0_ANY	=0,
  SLIMSERIAL_FRAME_TYPE_1 		=1,
  SLIMSERIAL_FRAME_TYPE_2 		=2,
  SLIMSERIAL_FRAME_TYPE_MODBUS_SERVER_NUM =3,
  SLIMSERIAL_FRAME_TYPE_MODBUS_CLIENT_NUM =4,

  SLIMSERIAL_FRAME_TYPE_NONE = 99
}SLIMSERIAL_FRAME_TYPE_ENUM;
;
typedef enum
{
  SLIMSERIAL_TXRX_NORMAL = 0,
  SLIMSERIAL_TXRX_TRANSPARENT = 1
}SLIMSERIAL_PROXY_MODE;
 
class SlimSerial{

public:

	SlimSerial(UART_HandleTypeDef *uartHandle,
			uint8_t 		*tx_queue_buf,
			uint16_t 		tx_queue_buf_single_size,
			uint8_t		 tx_queue_meta_size,
			uint8_t   *rx_pingpong_buf,
			uint16_t   rx_pingpong_buf_half_size,
			uint8_t   *rx_circular_buf,
			uint16_t  rx_circular_buf_size,
			uint8_t  *rx_frame,
			uint16_t rx_frame_size,
			uint8_t rx_frame_type= 1,
			GPIO_TypeDef* tx_485_En_Port = NULL,
			uint16_t tx_485_En_Pin = 0,
			uint8_t tx_method = 1,
			uint8_t rx_enable = 1);

	SD_USART_StatusTypeDef transmitFrameLL(uint16_t address,uint16_t fcode,uint8_t *payload=0,uint16_t payloadBytes=0);

	SD_USART_StatusTypeDef transmitDataLL(uint8_t *pdata,uint16_t dataBytes);

	SD_USART_StatusTypeDef transmitFrame(uint16_t address,uint16_t fcode,uint8_t *payload=0,uint16_t payloadBytes=0);

	SD_USART_StatusTypeDef transmitData(uint8_t *pdata,uint16_t dataBytes);

	SD_BUF_INFO &transmitReceiveFrame(uint16_t address,uint16_t fcode,uint8_t *payload=NULL,uint16_t payloadBytes=0,uint16_t timeout=20);

	SD_BUF_INFO &transmitReceiveData(uint8_t *pdata,uint16_t dataBytes,uint16_t timeout,bool frameTypeFilterOn=true);

	void addRxFrameCallback(std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes)> &frameCallbackFunc);
	void addRxFrameCallback(void (*frameCallbackFunc)(SlimSerial *,uint8_t *,uint16_t ));

	SD_BUF_INFO &getRxFrame();
	void clearRxFrame();

	uint32_t readBuffer(uint8_t *pdata,uint16_t dataBytes,uint32_t timeout);

	SD_USART_StatusTypeDef &getRxStatus();

	void setRxFrameType(uint8_t rx_frame_type_num);
	uint8_t getRxFrameType();

    void addHeaderFilter(uint8_t h1,uint8_t h2);
    void addAddressFilter(uint8_t address);
    void addFuncodeFilter(uint8_t funcode);

	void toggleHeaderFilter(bool filterOn=true);
    void toggleAddressFilter(bool filterOn=false);
	void toggleFuncodeFilter(bool filterOn=false);

    void toggle485Tx(bool txOn=true){
    	if(Tx_EN_Port)
    		HAL_GPIO_WritePin(Tx_EN_Port,Tx_EN_Pin,(txOn?GPIO_PIN_SET:GPIO_PIN_RESET));
    }


	int8_t debugOutputEnable;

	//usart
	UART_HandleTypeDef *m_huart;

	//rx time record
	uint32_t m_rx_time_start;
	uint32_t m_rx_time_end;
	uint32_t m_rx_time_cost;

	//tx time record
	uint32_t m_tx_time_start;
	uint32_t m_tx_time_end;
	uint32_t m_tx_time_cost;

	void start_Rx_DMA_Idle();
	void txCpltCallback();
	void rxCpltCallback(uint16_t);

	uint8_t rxNeedRestart;

	void restartRxFromISR();

	//proxy
	void proxyDelegateMessage(uint8_t *pData,uint16_t databytes);
	void enableProxy(uint8_t proxy_port_index,uint32_t proxy_port_baudrate);
	void disableProxy();
	void ackProxy();
	void setBaudrate(uint32_t baudrate=0);
	SLIMSERIAL_PROXY_MODE getProxyMode();
	SlimSerial *m_proxy_port;
	SLIMSERIAL_PROXY_MODE m_proxy_mode; 
	uint32_t m_last_baudrate;  
	uint8_t *m_original_rx_pingpong_buf;
	uint16_t m_original_rx_pingpong_buf_half_size;
 
	uint8_t *m_original_rx_frame_buf;
	uint16_t m_original_rx_frame_buf_size;

	uint8_t *m_original_rx_circular_buf;
	uint16_t m_original_rx_circular_buf_size;

	uint32_t m_txrx_time_cost;
	uint32_t m_tx_once;

private:

	bool getACK(){
		return  receivedACK;
	};



    bool applyHeaderFilter(uint8_t h1In,uint8_t h2In);
    bool applyAddressFilter(uint8_t addressIn);
    bool applyFuncodeFilter(uint8_t funcode);

	void callRxCallbackArray(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes){
		for(int i=0;i<m_frameCallbackFuncNumber;i++){
			m_frameCallbackFuncArray[i](slimSerialDev,pdata,databytes);
		}
		for(int i=0;i<m_frameCallbackFuncNumber_C;i++){
			m_frameCallbackFuncArray_C[i](slimSerialDev,pdata,databytes);
		}
	};

	//
	uint8_t headerFilter[SLIMSERIAL_HEADER_FILTER_MAX_LEN][2];
	bool headerFilterOn;
	uint8_t headerFilter_num;

	uint8_t addressFilter[SLIMSERIAL_ADDRESS_FILTER_MAX_LEN];
	bool addressFilterOn;
	uint8_t addressFilter_num;

	uint8_t funcodeFilter[SLIMSERIAL_FUNCODE_FILTER_MAX_LEN];
	bool funcodeFilterOn;
	uint8_t funcodeFilter_num;

	bool lengthFilterOn;


	//Tx queue buffer
	uint8_t  *m_tx_queue_buf;
	uint16_t  m_tx_queue_buf_single_size;
	uint8_t	 m_tx_queue_size;
	uint16_t m_tx_buf_ind;
	static_queue<SD_BUF_INFO, 5> m_tx_queue_meta;
	SD_BUF_INFO m_tx_last;

	//Rx ping pong buffer
	uint8_t  *m_rx_pingpong_buf;
	uint16_t  m_rx_pingpong_buf_half_size;
	SD_BUF_INFO m_rx_pingpong_last;
	uint16_t m_rx_pingpong_receiving_ind;

	//rx circular buffer
	CURCULAR_BUFFER m_rx_circular_buf;

	//rx data
	SD_BUF_INFO m_rx_last;
	uint8_t  *m_rx_frame_buf;
	uint16_t m_rx_frame_buf_size;

	//rx status record
	SD_USART_StatusTypeDef m_rx_status;



	//
	int m_totalTxFrames = 0;
	int m_totalRxFrames = 0;
	int m_totalTxBytes = 0;
	int m_totalRxBytes = 0;

    //rx ack
	bool receivedACK;

	//rx enable
	uint8_t m_rx_enable;


	//485 tx enable ping
	GPIO_TypeDef* Tx_EN_Port;
	uint16_t Tx_EN_Pin;

    //tx method.
    uint8_t m_TX_Method;//0: Tx_blocking;  1:Tx_DMA; 2: Tx_IT


	//frame type
	/*
	0:  Any Rx format
	1:  Header1 Header2 Src Len Func  + payloads + crc16
	2:  Header1 Header2 Len  + payloads + crc16
	3:  MODBUS frame
	*/
	uint8_t m_rx_frame_type;

	//synchronization tools
	bool writeLocked = false;
	SemaphoreHandle_t writeMtx;
	StaticSemaphore_t writeMtxBuffer;
	SemaphoreHandle_t readMtx;
	StaticSemaphore_t readMtxBuffer;

//    std::mutex txrxMtx;
//    std::mutex ackMtx;
//    std::mutex decodeMtx;
//	std::condition_variable ackCV;
//    std::condition_variable txrxCV;
    bool txrxLocked = false;



	std::array<std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes)>, SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN> m_frameCallbackFuncArray;
	uint8_t m_frameCallbackFuncNumber;

	void (*m_frameCallbackFuncArray_C[SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN])(SlimSerial *,uint8_t *,uint16_t );
	uint8_t m_frameCallbackFuncNumber_C;

	uint8_t m_frameCallbackFuncNumber_all;

	HAL_StatusTypeDef createRxTasks();

	SD_USART_StatusTypeDef transmitLL();

	SD_BUF_INFO bufferTxFrame(uint16_t address,uint16_t fcode,uint8_t *payload,uint16_t payloadBytes);

	SD_BUF_INFO bufferTxData(uint8_t *pdata,uint16_t dataBytes);
	SD_BUF_INFO queueTxData(uint8_t *pdata,uint16_t dataBytes);
  
	//txrx task
	uint32_t *txrxThreadID;

	//rx handling task
	uint32_t *rxThreadID;
	osThreadId rxTaskHandle;

	HAL_StatusTypeDef Slim_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);


	uint32_t rxTaskBuffer[ SLIMSERIAL_RX_TASK_BUFFER_SIZE ];
	osStaticThreadDef_t rxTaskControlBlock;
	static void rxTaskFuncImpl(const void* parm){
		 ((SlimSerial *)(parm))->rxHandlerThread();
	}

	void rxHandlerThread();

#if ENABLE_SLIMSERIAL_MICRO_SECONDS
	static uint32_t currentTime_us()
	{
		return (HAL_GetTick()*1000)+HAL_TICK_TIM->CNT;
	}
#else
	static uint32_t currentTime_us()
	{
		return (HAL_GetTick()*1000);
	}
#endif
};

extern SlimSerial *getSlimSerial(UART_HandleTypeDef *huart=NULL);


#if ENABLE_SLIMSERIAL_USART1
extern SlimSerial slimSerial1;
#endif
#if ENABLE_SLIMSERIAL_USART2
extern SlimSerial slimSerial2;
#endif
#if ENABLE_SLIMSERIAL_USART3
extern SlimSerial slimSerial3;
#endif
#if ENABLE_SLIMSERIAL_USART4
extern SlimSerial slimSerial4;
#endif
#if ENABLE_SLIMSERIAL_USART5
extern SlimSerial slimSerial5;
#endif
#if ENABLE_SLIMSERIAL_USART6
extern SlimSerial slimSerial6;
#endif
#if ENABLE_SLIMSERIAL_USART7
extern SlimSerial slimSerial7;
#endif
#if ENABLE_SLIMSERIAL_USART8
extern SlimSerial slimSerial8;
#endif


#endif /* SLIM_SERIAL_H_ */
