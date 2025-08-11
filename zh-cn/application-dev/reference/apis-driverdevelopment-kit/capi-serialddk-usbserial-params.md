# UsbSerial_Params
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--SE: @w00373942-->
<!--TSE: @dong-dongzhen-->

## 概述

定义USB SERIAL DDK使用的USB串口参数.

**起始版本：** 18

**相关模块：** [SerialDdk](capi-serialddk.md)

**所在头文件：** [usb_serial_types.h](capi-usb-serial-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t baudRate | 波特率。 |
| uint8_t nDataBits | 数据传输位数。 |
| uint8_t nStopBits | 数据停止位数。 |
| uint8_t parity | 校验参数设置。 |


