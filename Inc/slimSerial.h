#ifndef SLIM_SERIAL_H_
#define SLIM_SERIAL_H_
#pragma once
#include <main.h>
#include "stdio.h"
#include "usart.h"

#include "math.h"
#include "cmsis_os.h"
#include <functional>
#include <slimCircularBuffer.hpp>
#include "static_queue.hpp"
#include "slimSerialDefines.h"
#include "slimSerial_Configs.h"

#define INTERNAL_MAX_FRAME_SIZE 2048
#define SLIMSERIAL_RX_TASK_BUFFER_SIZE_MINIMAL 128

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
  SLIMSERIAL_TXRX_NORMAL = 0,
  SLIMSERIAL_TXRX_TRANSPARENT = 1
}SLIMSERIAL_PROXY_MODE;
 

#if ENABLE_PROXY==1
	enum PROXY_FUNCODE_INTERNAL {
    	FUNC_DISABLE_PROXY_INTERNAL = 0xD0,
    	FUNC_ENABLE_PROXY_INTERNAL = 0xD1,
    	FUNC_ACK_PROXY_INTERNAL = 0xD2
    };
#endif

#define ANY_TIMEOUT_TIMER_USED (USART1_TIMEOUT_TIMER_INDEX || \
		USART1_TIMEOUT_TIMER_INDEX || \
		USART2_TIMEOUT_TIMER_INDEX || \
		USART3_TIMEOUT_TIMER_INDEX || \
		USART4_TIMEOUT_TIMER_INDEX || \
		USART5_TIMEOUT_TIMER_INDEX || \
		USART6_TIMEOUT_TIMER_INDEX || \
		USART7_TIMEOUT_TIMER_INDEX || \
		USART8_TIMEOUT_TIMER_INDEX)

#define SLIMSERIAL_NOTIFICATION_BIT_FRAME 	0x01
#define SLIMSERIAL_NOTIFICATION_BIT_RESTART 0x40
#define SLIMSERIAL_NOTIFICATION_BIT_TIMEOUT 0x80


#if ANY_TIMEOUT_TIMER_USED
#include "tim.h"
_Static_assert(USE_HAL_TIM_REGISTER_CALLBACKS==1,"requires HAL_TIM_RegisterCallback to be enabled in ioc file");
#endif

typedef uint8_t (*PayloadFunc)(uint8_t *pPayload,bool is9bitsMode);

constexpr TIM_HandleTypeDef* getTimerHandle(uint8_t timer_index);

class SlimSerial{

public:

	SlimSerial(UART_HandleTypeDef *uartHandle,
			uint16_t   *tx_circular_buf,
			uint16_t  tx_circular_buf_size,
			uint16_t   *rx_circular_buf,
			uint16_t  rx_circular_buf_size,
			uint8_t  *rx_frame,
			uint16_t rx_frame_size,
			uint8_t rx_frame_type,
			GPIO_TypeDef* tx_485_En_Port,
			uint16_t tx_485_En_Pin,
			uint8_t tx_method,
			uint8_t rx_method,
			uint8_t nine_bits_mode,
			uint8_t timeout_timer_index);

	/* Configuration functions */
	void addRxFrameCallback(std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes)> &frameCallbackFunc);

	void addRxFrameCallback(void (*frameCallbackFunc)(SlimSerial *,uint8_t *,uint16_t ));

	SD_USART_StatusTypeDef config9bitRxAddress(uint8_t address);

	void config9bitTxAddress(uint8_t address);

    void addHeaderFilter(uint8_t h1,uint8_t h2);

    void addAddressFilter(uint8_t address);

    void addFuncodeFilter(uint8_t funcode);

    /* Transmission functions */

    SD_USART_StatusTypeDef transmitFrame(uint16_t address,uint16_t fcode,PayloadFunc payloadFunc);
	SD_USART_StatusTypeDef transmitFrame(uint16_t address,uint16_t fcode,uint8_t *payload=0,uint16_t payloadBytes=0);

	SD_USART_StatusTypeDef transmitData(uint8_t *pdata,uint16_t dataBytes);

	SD_BUF_INFO &transmitReceiveFrame(uint16_t address,uint16_t fcode,uint8_t *payload=NULL,uint16_t payloadBytes=0,float timeout=20);

	SD_BUF_INFO &transmitReceiveData(uint8_t *pdata,uint16_t dataBytes,float timeout,bool frameTypeFilterOn=true);

	SD_BUF_INFO &modbusRead(uint8_t des, uint16_t reg_address,uint16_t reg_count,uint16_t timeoutMS=20);
	SD_BUF_INFO &modbusWrite(uint8_t des, uint16_t reg_address,uint16_t reg_data,uint16_t timeoutMS=20);

	uint32_t readBuffer(uint8_t *pdata,uint16_t dataBytes,uint32_t timeout);


	SD_BUF_INFO &getRxFrame();
	void clearRxFrame();

	SD_USART_StatusTypeDef &getRxStatus();

	void setRxFrameType(uint8_t rx_frame_type_num);
	uint8_t getRxFrameType();


	void toggleHeaderFilter(bool filterOn);
    void toggleAddressFilter(bool filterOn);
	void toggleFuncodeFilter(bool filterOn);

    void toggle485Tx(bool txOn);

	uint32_t getRxIdleTimeUs();
	uint32_t getRxFrameIdleTimeUs();




	//usart
	UART_HandleTypeDef *m_huart;

	//timeout timer
	TIM_HandleTypeDef *m_timeout_htim;
	uint8_t m_timeout_htim_index; //index of the timeout timer, used to get the timer handle

	//rx time record
	uint32_t m_rx_time_start;
	uint32_t m_rx_time_end;
	uint32_t m_rx_time_cost;
	uint32_t m_rx_time_validFrame;
	uint32_t m_rx_time_validFrame_cost;
	uint32_t m_rx_time_callback_enter;
	uint32_t m_rx_time_callback_cost;

	//tx time record
	uint32_t m_tx_time_start;
	uint32_t m_tx_time_end;
	uint32_t m_tx_time_cost;

	//txrx time record
	uint32_t m_txrx_time_cost;
	uint32_t m_tx_once;

	//bits 9 mode
	uint8_t m_9bits_mode; 				//0: 8 bits mode; 1: 9 bits mode. This value may be changed during runtime, for example, when the proxy mode is enabled, the 9 bits mode may be toggled on or off.
	uint8_t m_9bits_mode_original; 		//0: 8 bits mode; 1: 9 bits mode, this is the original mode when the SlimSerial object is created

	void start_Rx_DMA_Idle_Circular();
	void txCpltCallback();
	void rxCpltCallback(uint16_t data_len);
	void txrxTimeoutCallback();
	void restartRxFromISR();

	//proxy
	SLIMSERIAL_PROXY_MODE getProxyMode();
	SLIMSERIAL_PROXY_MODE m_proxy_mode;

	//debug output
	int8_t debugOutputEnable;

#if ENABLE_PROXY==1
	void enableProxy(uint8_t proxy_port_index,uint32_t proxy_port_baudrate,uint8_t enable_node_address,uint8_t node_address);
	void disableProxy(bool ackFlag = true);
	void ackProxy();
	void proxyDelegateMessage(uint8_t *pData,uint16_t databytes);
	void setBaudrate(uint32_t baudrate=0);
	uint8_t m_enable_9bits_proxy=0; //Indicates the 9 bits mode of the proxy ports. This is differnt from the 9 bits mode of the current port, which is indicated by m_9bits_mode.
	uint8_t m_proxy_9bit_address=0; //only used when m_enable_9bits_proxy is true, this is the address of the proxy port in 9 bits mode.
	SlimSerial *m_proxy_port;
	uint32_t m_last_baudrate;  
	static SLIM_CURCULAR_BUFFER m_proxy_circular_buffer; //capable of holding maximum YModem frame size of 1029 even in 9 bits mode
#endif

private:
	HAL_StatusTypeDef createRxTasks();

	void rxHandlerThread();

	static void rxTaskFuncImpl(const void* parm){
		 ((SlimSerial *)(parm))->rxHandlerThread();
	}

	HAL_StatusTypeDef Slim_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

	void frameParser();

	bool getACK(){return  receivedACK;};


	void configRxDMACircularMode();

	SD_USART_StatusTypeDef config9bitMode(uint8_t enable_9bits_mode);


	SD_BUF_INFO bufferTxFrame(uint8_t address,uint8_t fcode,PayloadFunc payloadFunc);
	SD_BUF_INFO bufferTxFrame(uint8_t address,uint8_t fcode,uint8_t *payload,uint16_t payloadBytes);

	SD_BUF_INFO bufferTxData(SLIM_CURCULAR_BUFFER &tx_circular_buf,uint8_t *pSrc,uint16_t datalen);
	SD_BUF_INFO bufferTxData(uint8_t *pSrc,uint16_t datalen);

	SD_USART_StatusTypeDef transmitLL();

	SD_USART_StatusTypeDef transmitFrameLL(uint16_t address,uint16_t fcode,uint8_t *payload=0,uint16_t payloadBytes=0);

	SD_USART_StatusTypeDef transmitDataLL(uint8_t *pdata,uint16_t dataBytes);

    bool applyHeaderFilter(uint8_t h1In,uint8_t h2In);
    bool applyAddressFilter(uint8_t addressIn);
    bool applyFuncodeFilter(uint8_t funcode);

	std::array<std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes)>, SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN> m_frameCallbackFuncArray;
	void (*m_frameCallbackFuncArray_C[SLIMSERIAL_RX_CALLBACK_ARRAY_MAX_LEN])(SlimSerial *,uint8_t *,uint16_t );
	void callRxCallbackArray(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databytes);

	static uint32_t currentTime_us();

#if ANY_TIMEOUT_TIMER_USED
	void configTimeoutTimer();
	void setTimeout(float timeout_ms);
	void stopTimeout();
#endif

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

	//Tx circular buffer
	SLIM_CURCULAR_BUFFER m_tx_circular_buf;

	//rx circular buffer
	SLIM_CURCULAR_BUFFER m_rx_circular_buf;

	//tx data
	static_queue<SD_BUF_INFO, 20> m_tx_queue_meta;
	SD_BUF_INFO m_tx_last;

	//rx frame data
	SD_BUF_INFO m_rx_last;
	uint8_t  *m_rx_frame_buf;
	uint16_t m_rx_frame_buf_size;

	//rx status record
	SD_USART_StatusTypeDef m_rx_status;

	uint8_t m_address;  				//address in frame


	uint8_t m_9bits_mode_address_rx; 	//rx address for 9 bits mode
	uint8_t m_9bits_mode_address_tx; 	//tx address for 9 bits mode
	uint8_t m_9bits_mode_error;
	bool m_enable_rx_wake_up;

	//tx rx statistics
	int m_totalTxFrames = 0;
	int m_totalRxFrames = 0;
	int m_totalTxBytes = 0;
	int m_totalRxBytes = 0;

	//parsing
	int32_t m_parse_remainingBytes;

	//callback function members
	uint8_t m_frameCallbackFuncNumber;
	uint8_t m_frameCallbackFuncNumber_C;
	uint8_t m_frameCallbackFuncNumber_all;

    //rx ack
	bool receivedACK;

	//rx enable
	uint8_t m_rx_mode; //0: no rx; 1:handle rx frame in task;  2:handle rx frame in interrupt.

	//485 tx enable ping
	GPIO_TypeDef* Tx_EN_Port;
	uint16_t Tx_EN_Pin;

    //tx method.
    uint8_t m_tx_mode;//0: Tx_blocking;  1:Tx_DMA; 2: Tx_IT

	//rx frame type
	uint8_t m_rx_frame_type;
	uint8_t m_rx_frame_type_ori;

	//synchronization tools
	bool writeLocked = false;

    bool txrxLocked = false;

	//txrx task ID
	uint32_t *txrxThreadID;

	//rx handling task ID
	uint32_t *rxThreadID;
	osThreadId rxTaskHandle;

	//rx task buffer
	uint32_t rxTaskBuffer[ SLIMSERIAL_RX_TASK_BUFFER_SIZE ];
	osStaticThreadDef_t rxTaskControlBlock;



};


//global function to get SlimSerial instance by UART_HandleTypeDef
extern SlimSerial *getSlimSerial(UART_HandleTypeDef *huart);
extern SlimSerial *getSlimSerial(TIM_HandleTypeDef *htim);


//global SlimSerial instances
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
