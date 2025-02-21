# usb_serial_ddk_types.h


## 概述

提供USB Serial DDK中的枚举变量、结构体定义与宏定义。

**库：** libusb_serial.z.so

**引用文件：**&lt;serial/usb_serial_ddk_types.h&gt;

**系统能力：** SystemCapability.Driver.SERIAL.Extension

**起始版本：** 16

**相关模块：**[Serial DDK](_serial_ddk.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[UsbSerial_Params](_usb_serial___params.md) | 定义USB Serial DDK使用的USB串口参数. | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle)[UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) | USB串口设备数据结构（不透明）。 | 
| typedef struct [UsbSerial_Params](_usb_serial___params.md) __attribute__((aligned(8))) [UsbSerial_Params](_usb_serial___params.md) | USB Serial DDK使用的USB串口参数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [UsbSerial_DdkRetCode](_serial_ddk.md#usbserial_ddkretcode) {<br/>USB_SERIAL_DDK_NO_PERM = 201, USB_SERIAL_DDK_INVALID_PARAMETER = 401, USB_SERIAL_DDK_SUCCESS = 31600000, USB_SERIAL_DDK_INVALID_OPERATION = 31600001, USB_SERIAL_DDK_INIT_ERROR = 31600002, USB_SERIAL_DDK_SERVICE_ERROR = 31600003, USB_SERIAL_DDK_MEMORY_ERROR = 31600004, USB_SERIAL_DDK_IO_ERROR = 31600005, USB_SERIAL_DDK_DEVICE_NOT_FOUND = 31600006<br/>} | 定义USB Serial DDK使用的返回码。 | 
| [UsbSerial_FlowControl](_serial_ddk.md#usbserial_flowcontrol) { USB_SERIAL_NO_FLOW_CONTROL = 0, USB_SERIAL_SOFTWARE_FLOW_CONTROL = 1, USB_SERIAL_HARDWARE_FLOW_CONTROL = 2 } | 定义USB Serial DDK中的流量控制。 | 
| [UsbSerial_Parity](_serial_ddk.md#usbserial_parity) { USB_SERIAL_PARITY_NONE = 0, USB_SERIAL_PARITY_ODD = 1, USB_SERIAL_PARITY_EVEN = 2 } | 定义USB Serial DDK使用的校验参数枚举。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [baudRate](#baudrate) | 波特率。 | 
| uint8_t [nDataBits](#ndatabits) | 数据传输位数。 | 
| uint8_t [nStopBits](#nstopbits) | 数据停止位数。 | 
| uint8_t [parity](#parity) | 校验参数设置。 | 


## 变量说明


### baudRate

```
uint32_t baudRate
```

**描述**

波特率。


### nDataBits

```
uint8_t nDataBits
```

**描述**

数据传输位数。


### nStopBits

```
uint8_t nStopBits
```

**描述**

数据停止位数。


### parity

```
uint8_t parity
```

**描述**

校验参数设置。
