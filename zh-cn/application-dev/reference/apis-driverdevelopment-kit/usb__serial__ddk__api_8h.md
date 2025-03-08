# usb_serial_ddk_api.h


## 概述

声明用于主机侧访问串口设备的USB Serial DDK接口。

**库：** libusb_serial.z.so

**引用文件：**&lt;serial/usb_serial_ddk_api.h&gt;

**系统能力：** SystemCapability.Driver.SERIAL.Extension

**起始版本：** 18

**相关模块：**[USB Serial DDK](_serial_ddk.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_UsbSerial_Init](_serial_ddk.md#oh_usbserial_init) (void) | 初始化USB Serial DDK。 | 
| int32_t [OH_UsbSerial_Release](_serial_ddk.md#oh_usbserial_release) (void) | 释放USB Serial DDK。 | 
| int32_t [OH_UsbSerial_Open](_serial_ddk.md#oh_usbserial_open) (uint64_t deviceId, uint8_t interfaceIndex, [UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*\*dev) | 通过deviceId和interfaceIndex打开USB串口设备。 | 
| int32_t [OH_UsbSerial_Close](_serial_ddk.md#oh_usbserial_close) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev) | 关闭USB串口设备。 | 
| int32_t [OH_UsbSerial_Read](_serial_ddk.md#oh_usbserial_read) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, uint8_t \*buff, uint32_t bufferSize, uint32_t \*bytesRead) | 从USB串口设备读入数据到缓冲区。 | 
| int32_t [OH_UsbSerial_Write](_serial_ddk.md#oh_usbserial_write) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, uint8_t \*buff, uint32_t bufferSize, uint32_t \*bytesWritten) | 将buff中的数据写入USB串口设备。 | 
| int32_t [OH_UsbSerial_SetBaudRate](_serial_ddk.md#oh_usbserial_setbaudrate) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, uint32_t [baudRate](usb__serial__ddk__types_8h.md#baudrate)) | 设置USB串口设备的波特率。 如果USB串口设备的参数为默认值（数据位为8，停止位为1，数据传输无校验），则只需要调用该接口设置波特率。 | 
| int32_t [OH_UsbSerial_SetParams](_serial_ddk.md#oh_usbserial_setparams) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, [UsbSerial_Params](_usb_serial___params.md) \*params) | 设置USB串口设备的参数。 如果USB串口设备的参数不为默认值（数据位默认为8，停止位默认为1，数据传输默认无校验），则需要调用该接口进行参数设置。 | 
| int32_t [OH_UsbSerial_SetTimeout](_serial_ddk.md#oh_usbserial_settimeout) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, int timeout) | 设置读取USB串口设备上报数据的超时时间（毫秒）。 在不调用此函数的情况下，超时值默认为0，表示不管是否读取到数据都立即返回。如果需要等待一定的时间或者必须读取到数据，则调用该接口。 | 
| int32_t [OH_UsbSerial_SetFlowControl](_serial_ddk.md#oh_usbserial_setflowcontrol) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev, [UsbSerial_FlowControl](_serial_ddk.md#usbserial_flowcontrol) flowControl) | 设置流控参数。 USB串口设备通信中的流控用于管理数据传输的速率，以确保发送方不会发送超过接收方处理能力的数据量。<br/>如果USB串口设备实现了流控处理，则需要调用此接口。如果不调用此接口，默认为无流控。 | 
| int32_t [OH_UsbSerial_Flush](_serial_ddk.md#oh_usbserial_flush) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev) | 写入完成后清空输入和输出缓冲区。 在向USB串口设备发送数据时，可能会有大量数据缓冲在内核中等待发送。如果应用程序关闭文件描述符或者退出之前<br/>没有等待这些数据被实际发送出去，那么部分数据可能会丢失。调用该接口可以确保所有的数据都被发送完毕再继续执行后续操作。 | 
| int32_t [OH_UsbSerial_FlushInput](_serial_ddk.md#oh_usbserial_flushinput) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev) | 刷新输入缓冲区，缓冲区中的数据会被立刻清空。 在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况。<br/>调用该接口可以帮助清理这些异常状况，使通信恢复正常。 | 
| int32_t [OH_UsbSerial_FlushOutput](_serial_ddk.md#oh_usbserial_flushoutput) ([UsbSerial_DeviceHandle](_serial_ddk.md#usbserial_devicehandle) \*dev) | 刷新输出缓冲区，缓冲区中的数据会被立刻清空。 在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况。<br/>调用该接口可以帮助清理这些异常状况，使通信恢复正常。 | 
