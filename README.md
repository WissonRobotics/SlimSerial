# SlimSerial 通用串口通讯库

# SlimSerial 简介

SlimSerial 是一个基于 FreeRTOS 的 STM32 通用串口收发库，内置接收帧的检测和回调，保证数据传输可靠性，简化串口收发逻辑。

 
# 教程
[SlimSerial飞书](https://syv4suaelo.feishu.cn/docx/P6uFdvs3qozQ99xl3ZwcTGCInmL?from=from_copylink)


SlimSerial 通用串口通讯库
## SlimSerial简介
SlimSerial是一个基于FreeRTOS的STM32通用串口收发库，内置接收帧的检测和回调，保证数据传输
可靠性，简化串口收发逻辑。
a. 提供接受帧的回调函数，简化帧收发过程。
b. 提供同步非阻塞的收发函数，简化程序逻辑。

## 安装
1. 下载到本地
git clone https://github.com/WissonRobotics/SlimSerial.git
2. 将所需头文件和源文件加入工程，并添加相应 头文件目录和源文件目录
3. 串口配置
3.1 配置CubeMX
a. 启用串口, 配置波特率
b. 添加 Tx DMA 和 Rx DMA
c. 添加 Interrupt
d. 设置FreeRTOS 的内存分配为 static 或者 static/dynamic
3.2 配置串口数目
在头文件 slimSerial_config.h 中
//slimSerial_config.h
//define which usart to use with this driver
#define ENABLE_USART1 1 // 1: use this driver for USART 1
#define ENABLE_USART2 1
#define ENABLE_USART3 1
#define ENABLE_USART4 1
#define ENABLE_USART5 1
#define ENABLE_USART6 1
#define ENABLE_USART7 0
#define ENABLE_USART8 0

3.3 配置最大单帧字节长度（16/32/64/128/256/512）
//define the usart's tx rx frame max size, need to be 2^n
#define USART1_TX_FRAME_MAX_SIZE 256//need to be 2^n, Max byte
#define USART1_RX_FRAME_MAX_SIZE 256//need to be 2^n, Max byte

必须是2^n ， 大于等于【可能的单帧长度】。库内部将根据该大小分配合适的缓冲区。
💡 大小必须为2^n, 例如 16/32/64/128/256/512
3.4 配置接收帧类型
#define USART1_FRAME_TYPE RX_FRAME_TYPE_1 1 //default type 1.
目前内置了三种基本帧类型, RX_FRAME_TYPE_0 / 1 /2 。 默认使用FRAME_TYPE_1
1. 帧类型0 - 无类型 (RX_FRAME_TYPE_0)
不进行接收帧检测，任何新收到的数据都将触发注册的回调函数
2. 帧类型1 （RX_FRAME_TYPE_1）
进行接收帧类型1检测，只有合法的帧类型1 ，才会触发注册的回调函数
3. 帧类型2（RX_FRAME_TYPE_2）
进行接收帧类型2检测，只有合法的帧 ，才会触发注册的回调函数
💡 帧类型只规定了帧的结构组成，对每一项的内容没有规定。
内置合法帧头： 0xFF, 0xFF 或 0x5A 0xA5
3.5 配置485 Tx使能引脚
#define USART1_485_Tx_EN_GPIO_Port GPIOA //NULL if not us
#define USART1_485_Tx_EN_GPIO_Pin GPIO_PIN_11 //0 if not used

✍ 不需要的该引脚的话，需要设置为NULL / 0
3.6 配置 printf 串口
设置哪一个串口为printf串口
#define DEBUG_PRINTF_USART huart2 1 //use printf
4. 使用说明
4.1 在头文件 slimSerial_config.h 中进行串口配置
4.2 注册接收回调函数
对每一个slimSerialX, 注册接收回调函数。当接收到符合类型的帧时，就会调用该函数
4.2.1 C回调函数
C回调函数原型为：
1 void (*frameCallbackFunc)(SlimSerial *,uint8_t *,uint16_t )
C注册回调示例：
所注册的回调函数将会按照注册顺序执行
//user callback example
void userRxCallback1(SlimSerial *slimSerialDev,uint8_t *pData,uint16_t dataBytes
SLIMSERIAL_FRAME_TYPE_1 *pMsg=(SLIMSERIAL_FRAME_TYPE_1 *)pData;
switch (pMsg->funcode) {
case FUNC_START:{
//do FUNC_START
break;
}
case FUNC_STOP:{
//do FUNC_STOP
break;
}
default:{
break;
}
}
}
void userRxCallback2(SlimSerial *slimSerialDev,uint8_t *pData,uint16_t dataBytes
}
//register C callback
slimSerial1.addRxFrameCallback(userRxCallback1);
slimSerial1.addRxFrameCallback(userRxCallback2);

4.2.2 C++回调函数
回调函数原型为：
std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,1 uint16_t databytes)>
类成员函数作为回调函数时，需要通过std::function和std::bind 进行一下包装
示例：
class SomeClass{
public:
 
SomeClass(){
//bind member function to a std::function
userRxCallbackFunc = std::bind(&someClass::rxCallbackImp, this, std::placeho
}
//actual callback function
void rxCallbackImp(SlimSerial *slimSerialDev,uint8_t *pData,uint16_t dataByt
// same as C
SLIMSERIAL_FRAME_TYPE_1 *pMsg=(SLIMSERIAL_FRAME_TYPE_1 *)pData;
switch (pMsg->funcode) {
case FUNC_START:{
//do FUNC_START
break;
}
case FUNC_STOP:{
//do FUNC_STOP
togglePin();
slimSerialDev->transmitFrame(0xFF,0x01);
break;
}
default:{
break;
}
}
}
//function wrapper
std::function<void(SlimSerial *slimSerialDev,uint8_t *pdata,uint16_t databyt
}
SomeClass someclass;
//register c++ member function as callback
slimSerial1.addRxFrameCallback(someclass.userRxCallbackFunc );

4.3 Rx 帧检测的设置
4.3.1 进行Rx帧检测（默认）
💡 只有满足了条件的帧，才会触发Rx 回调函数，适合接收符合内置格式的帧数据
a. 帧头过滤
b. 帧地址过滤
c. CRC校验
4.3.2 不进行Rx帧检测
💡 任何新接收到的数据都会触发一次 Rx 回调函数，用于自由处理接收数据
a. 一直不进行帧检测
在配置接受帧类型中，将Rx_frame_type 设置为 RX_FRAME_TYPE_0， 意思是不进行帧检测
b. 单次发送接收不进行帧检测
在使用函数transmitReceiveData时，额外加入参数，检测帧为false（默认不加时为true)
transmitReceiveData(pData,dataBytes,1 timeout, False );
5. 收发过程
5.1 异步收发函数 (transmitData / transmitFrame)
Tx 后 ，通过注册的Rx回调函数处理 Rx
5.2 同步收发函数 (transmitReceiveData / transmitReceiveFrame)
Tx后，在当前线程等待Rx完成 (或超时), 并继续处理 Rx。 (等待过程不占用cpu)
💡 在使用同步收发函数时，也可同时注册Rx回调函数。 此时会先调用Rx回调函数, 然后再返回
到当前任务。
因此可以自行选择 Rx帧 是在回调函数中处理 或是 在当前线程中处理 。
6. 常见用法
6.1 主站
6.1.1 只发送
1. 使用 transmitData 发送任何Data. （可自行组装帧）
//transmitData
uint8_t query_frame[11]={0x5A，0xA5， 0x20， 0x04， 0x02， 0x76，0x02，0x00，0x
SD_BUF_INFO rxFrame= slimSerial1.transmitData(query_frame, 11);
 
2. 或者 直接使用 transmitFrame 发送帧数据
//transmitFrame
uint8_t query_data[4]={0x76，0x02，0x00，0x00};
SD_BUF_INFO rxFrame= slimSerial1.transmitFrame(0x20, 0x02,query_data,4);
// 地址, funcode,数据地址，数据长度
 
6.1.2 发送后，在回调函数中处理Rx
1. 注册Rx回调函数
2. 发送数据
3. 在回调函数中处理Rx frame
6.1.3 发送后，在当前线程处理Rx
推荐使用同步收发函数 (transmitReceiveData / transmitReceiveFrame）
//发送数据帧
// 帧头5A,A5 地址 数据长度 funcode
uint8_t query_frame[11]={0x5A，0xA5， 0x20， 0x04， 0x02， 0x76，0x02，0x00，0x
uint8_t timeoutMS = 20;
SD_BUF_INFO rxFrame= slimSerial.transmitReceiveData(query_frame, 11,timeoutMS);
//接收处理数据
int16_t pressure[4];
if (rxFrame.dataBytes != 0) {
for (int i = 0; i < 4; i++) {
pressure [i] = rxFrame.pdata[4] + (rxFrame.pdata[5] << 8);
}
}
else {//time out
}

💡 Tip: 发送部分，可以通过使用transmitReceiveFrame函数，只关心核心数据，不需要关心帧
组装，简化数据发送，例如：
//要发送的具体数据
uint8_t query_data[4]={0x76，0x02，0x00，0x00};
uint8_t timeoutMS = 20;
// 地址, funcode,数据地址，数据长
SD_BUF_INFO rxFrame= slimSerial.transmitReceiveFrame(0x20, 0x02,query_data,4,tim
 
💡 Tip: 接收部分， 可以通过 帧结构指针 简化 数据读取, 例如：
if (rxFrame.dataBytes != 0) {
SLIMSERIAL_FRAME_TYPE_1 *pMsg = (SLIMSERIAL_FRAME_TYPE_1*)(rxFrame.pdata);
for (int i = 0; i < 4; i++) {
pressure[i] = pMsg->payload.data16[i];
}
}
else {//time out
}
 
6.2 从站
6.2.1 在回调函数中 处理Rx 后，再发送数据返回
1. 注册回调函数
2. 在回调函数中，处理命令，并发送数据返回
7. 常用概念详解
7.1 slimSerial与huart
对于使能的每个串口的，都会生成一个全局变量 slimSerial1， slimSerial2, .... slimSerial8,
分别对应 huart1, huart2,... huart8
可以通过以下方法相互链接：
//get slimSerial_X from huart_X
SlimSerial *slimSerialDev = getSlimSerial(&huart3);
1
2
////get huart_X from slimSerial_X
slimSerial3.huart
1
2
7.3 实现框图
check valid frame circular buffer
Tx Queue
Rx Ping Pong Buffer
Rx
Tx
Rx Task
User Functioncallback
handling Rx frame
printf transmitData
usart1Device
transmitFrame
transmitReceiveData
transmitReceiveFrame