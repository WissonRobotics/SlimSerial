# SlimSerial 通用串口通讯库

# SlimSerial 简介

SlimSerial 是一个基于 FreeRTOS 的 STM32 通用串口收发库，内置接收帧的检测和回调，保证数据传输可靠性，简化串口收发逻辑。

 
# 配置

需要额外提供 配置文件  slimSerial_Configs.h   （参考  slimSerial_Configs_template.h ）

1. 启用某串口的SlimSerial驱动
```
#define ENABLE_SLIMSERIAL_USART1 1
#define ENABLE_SLIMSERIAL_USART2 1
#define ENABLE_SLIMSERIAL_USART3 1
#define ENABLE_SLIMSERIAL_USART4 1 
#define ENABLE_SLIMSERIAL_USART5 1 
#define ENABLE_SLIMSERIAL_USART6 1
#define ENABLE_SLIMSERIAL_USART7 0 
#define ENABLE_SLIMSERIAL_USART8 0 
```

2. 配置发送帧最大长度
```
#define USART1_TX_FRAME_MAX_SIZE   64                      //to be 2^n,  Max bytes of Tx frame
```
3. 配置接受帧最大长度
```
#define USART1_RX_FRAME_MAX_SIZE   32                      //to be 2^n,  Max bytes of Rx frame
```
4. 配置接受帧类型
```
#define USART1_FRAME_TYPE          SLIMSERIAL_FRAME_TYPE_1 //0: any rx  1:5+N+2  2:4+N+2   3:MODBUS
```

5. 配置485发送使能口（如果有）
```
#define USART1_485_Tx_EN_GPIO_Port RS485_EN1_GPIO_Port     //NULL if not used
#define USART1_485_Tx_EN_GPIO_Pin  RS485_EN1_Pin           //NULL if not used
```

6. 配置发送模式
```
#define USART1_TX_MODE             SLIMSERIAL_TX_MODE_DMA  // 0: Tx_blocking;	1:Tx_DMA; 		2: Tx_IT
```

7. 配置接受模式
```
#define USART1_RX_MODE             SLIMSERIAL_RX_MODE_TASK // 0: disable rx ;  1:enable rx frame parse in task; 2: enable rx frame parse in interrupt
```

8. 配置是否启用9bit模式
```
#define USART1_9_BITS_MODE         0                       // 0: 8 bits mode; 1: 9 bits mode
```