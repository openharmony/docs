# UsbSerial_Params


## 概述

定义USB Serial DDK使用的USB串口参数。

**起始版本：** 18

**相关模块：**[USB Serial DDK](_serial_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [baudRate](#baudrate) | 波特率。 | 
| uint8_t [nDataBits](#ndatabits) | 数据传输位数。 | 
| uint8_t [nStopBits](#nstopbits) | 数据停止位数。 | 
| uint8_t [parity](#parity) | 校验参数设置。 | 


## 结构体成员变量说明


### baudRate

```
uint32_t UsbSerial_Params::baudRate
```

**描述**

波特率。


### nDataBits

```
uint8_t UsbSerial_Params::nDataBits
```

**描述**

数据传输位数。


### nStopBits

```
uint8_t UsbSerial_Params::nStopBits
```

**描述**

数据停止位数。


### parity

```
uint8_t UsbSerial_Params::parity
```

**描述**

校验参数设置。
