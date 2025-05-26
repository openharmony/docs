# USB Serial DDK

## 概述

USB Serial DDK是为开发者提供的USB Serial DDK设备驱动程序开发套件，此模块提供USB Serial DDK接口，包括枚举类型和USB Serial DDK API使用的数据结构。

在工业用途场景以及一些老旧设备上，常会使用到串口通信，如：发卡机、身份证读卡器等。通过USB Serial DDK提供的接口，开发者可以开发非标外设扩展驱动，实现USB串口设备的扩展功能。

**系统能力：** SystemCapability.Driver.UsbSerial.Extension

**起始版本：** 18


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [usb_serial_api.h](usb__serial__ddk__api_8h.md) | 声明用于主机侧访问串口设备的USB Serial DDK接口。<br/>引用文件：&lt;serial/usb_serial_api.h&gt;<br/>库： libusb_serial.z.so | 
| [usb_serial_types.h](usb__serial__ddk__types_8h.md) | 提供USB Serial DDK中的枚举变量、结构体定义与宏定义。<br/>引用文件：&lt;serial/usb_serial_types.h&gt;<br/>库： libusb_serial.z.so | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[UsbSerial_Params](_usb_serial___params.md) | 定义USB Serial DDK使用的USB串口参数。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [UsbSerial_DeviceHandle](#usbserial_devicehandle) [UsbSerial_DeviceHandle](#usbserial_devicehandle) | USB串口设备数据结构（不透明）。 | 
| typedef struct [UsbSerial_Params](_usb_serial___params.md) \__attribute\__((aligned(8))) [UsbSerial_Params](_usb_serial___params.md) | USB Serial DDK使用的USB串口参数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [UsbSerial_DdkRetCode](#usbserial_ddkretcode) {<br/>USB_SERIAL_DDK_NO_PERM = 201, USB_SERIAL_DDK_INVALID_PARAMETER = 401, USB_SERIAL_DDK_SUCCESS = 31600000, USB_SERIAL_DDK_INVALID_OPERATION = 31600001, USB_SERIAL_DDK_INIT_ERROR = 31600002, USB_SERIAL_DDK_SERVICE_ERROR = 31600003, USB_SERIAL_DDK_MEMORY_ERROR = 31600004, USB_SERIAL_DDK_IO_ERROR = 31600005, USB_SERIAL_DDK_DEVICE_NOT_FOUND = 31600006<br/>} | 定义USB Serial DDK使用的返回码。 | 
| [UsbSerial_FlowControl](#usbserial_flowcontrol) { USB_SERIAL_NO_FLOW_CONTROL = 0, USB_SERIAL_SOFTWARE_FLOW_CONTROL = 1, USB_SERIAL_HARDWARE_FLOW_CONTROL = 2 } | 定义USB Serial DDK中的流量控制。 | 
| [UsbSerial_Parity](#usbserial_parity) { USB_SERIAL_PARITY_NONE = 0, USB_SERIAL_PARITY_ODD = 1, USB_SERIAL_PARITY_EVEN = 2 } | 定义USB Serial DDK使用的校验参数枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_UsbSerial_Init](#oh_usbserial_init) (void) | 初始化USB Serial DDK。 | 
| int32_t [OH_UsbSerial_Release](#oh_usbserial_release) (void) | 释放USB Serial DDK。 | 
| int32_t [OH_UsbSerial_Open](#oh_usbserial_open) (uint64_t deviceId, uint8_t interfaceIndex, [UsbSerial_DeviceHandle](#usbserial_devicehandle) \*\*dev) | 通过deviceId和interfaceIndex打开USB串口设备。 | 
| int32_t [OH_UsbSerial_Close](#oh_usbserial_close) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev) | 关闭USB串口设备。 | 
| int32_t [OH_UsbSerial_Read](#oh_usbserial_read) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, uint8_t \*buff, uint32_t bufferSize, uint32_t \*bytesRead) | 从USB串口设备读入数据到缓冲区。 | 
| int32_t [OH_UsbSerial_Write](#oh_usbserial_write) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, uint8_t \*buff, uint32_t bufferSize, uint32_t \*bytesWritten) | 将buff中的数据写入USB串口设备。 | 
| int32_t [OH_UsbSerial_SetBaudRate](#oh_usbserial_setbaudrate) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, uint32_t [baudRate](usb__serial__ddk__types_8h.md#baudrate)) | 设置USB串口设备的波特率。 如果USB串口设备的参数为默认值（数据位为8，停止位为1，数据传输无校验），则只需要调用该接口设置波特率。 | 
| int32_t [OH_UsbSerial_SetParams](#oh_usbserial_setparams) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, [UsbSerial_Params](_usb_serial___params.md) \*params) | 设置USB串口设备的参数。 如果USB串口设备的参数不为默认值（数据位默认为8，停止位默认为1，数据传输默认无校验），则需要调用该接口进行参数设置。 | 
| int32_t [OH_UsbSerial_SetTimeout](#oh_usbserial_settimeout) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, int timeout) | 设置读取USB串口设备上报数据的超时时间（毫秒）。 在不调用此函数的情况下，超时值默认为0，表示不管是否读取到数据都立即返回。如果需要等待一定的时间或者必须读取到数据，则调用该接口。 | 
| int32_t [OH_UsbSerial_SetFlowControl](#oh_usbserial_setflowcontrol) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev, [UsbSerial_FlowControl](#usbserial_flowcontrol) flowControl) | 设置流控参数。 USB串口设备通信中的流控用于管理数据传输的速率，以确保发送方不会发送超过接收方处理能力的数据量。<br/>如果USB串口设备实现了流控处理，则需要调用此接口。如果不调用此接口，默认为无流控。 | 
| int32_t [OH_UsbSerial_Flush](#oh_usbserial_flush) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev) | 写入完成后清空输入和输出缓冲区。 在向USB串口设备发送数据时，可能会有大量数据缓冲在内核中等待发送。如果应用程序关闭文件描述符或者退出之前没有等待这些数据被实际发送出去，那么部分数据可能会丢失。调用该接口可以确保所有的数据都被发送完毕再继续执行后续操作。 | 
| int32_t [OH_UsbSerial_FlushInput](#oh_usbserial_flushinput) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev) | 刷新输入缓冲区，缓冲区中的数据会被立刻清空。 在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况。<br/>调用该接口可以帮助清理这些异常状况，使通信恢复正常。 | 
| int32_t [OH_UsbSerial_FlushOutput](#oh_usbserial_flushoutput) ([UsbSerial_DeviceHandle](#usbserial_devicehandle) \*dev) | 刷新输出缓冲区，缓冲区中的数据会被立刻清空。 在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况。<br/>调用该接口可以帮助清理这些异常状况，使通信恢复正常。 | 


## 类型定义说明


### UsbSerial_DeviceHandle

```
typedef struct UsbSerial_DeviceHandle UsbSerial_DeviceHandle
```

**描述**

USB串口设备数据结构（不透明）。

**起始版本：** 18


### UsbSerial_Params

```
typedef struct UsbSerial_Params \__attribute\__((aligned(8))) UsbSerial_Params
```

**描述**

定义USB Serial DDK使用的USB串口参数。

**起始版本：** 18


## 枚举类型说明


### UsbSerial_DdkRetCode

```
enum UsbSerial_DdkRetCode
```

**描述**

定义USB Serial DDK使用的返回码。

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| USB_SERIAL_DDK_NO_PERM | 权限被拒绝。 | 
| USB_SERIAL_DDK_INVALID_PARAMETER | 无效参数。 | 
| USB_SERIAL_DDK_SUCCESS | 操作成功。 | 
| USB_SERIAL_DDK_INVALID_OPERATION | 无效操作。 | 
| USB_SERIAL_DDK_INIT_ERROR | 初始化失败。 | 
| USB_SERIAL_DDK_SERVICE_ERROR | 服务错误。 | 
| USB_SERIAL_DDK_MEMORY_ERROR | 内存相关错误，例如内存不足、内存数据复制失败或内存应用程序故障。 | 
| USB_SERIAL_DDK_IO_ERROR | I/O 错误。 | 
| USB_SERIAL_DDK_DEVICE_NOT_FOUND | 未找到设备。 | 


### UsbSerial_FlowControl

```
enum UsbSerial_FlowControl
```

**描述**

定义USB Serial DDK中的流量控制。

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| USB_SERIAL_NO_FLOW_CONTROL | 无流量控制。 | 
| USB_SERIAL_SOFTWARE_FLOW_CONTROL | 软件流控。 | 
| USB_SERIAL_HARDWARE_FLOW_CONTROL | 硬件流控。 | 


### UsbSerial_Parity

```
enum UsbSerial_Parity
```

**描述**

定义USB Serial DDK使用的校验参数枚举。

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| USB_SERIAL_PARITY_NONE | 无校验。 | 
| USB_SERIAL_PARITY_ODD | 奇校验。 | 
| USB_SERIAL_PARITY_EVEN | 偶校验。 | 


## 函数说明


### OH_UsbSerial_Close()

```
int32_t OH_UsbSerial_Close (UsbSerial_DeviceHandle * dev)
```

**描述**

关闭USB串口设备。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：dev为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_Flush()

```
int32_t OH_UsbSerial_Flush (UsbSerial_DeviceHandle * dev)
```

**描述**

写入完成后清空输入和输出缓冲区。

在向USB串口设备发送数据时，可能会有大量数据缓冲在内核中等待发送。如果应用程序关闭文件描述符或者退出之前没有等待这些数据被实际发送出去，那么部分数据可能会丢失。调用该接口可以确保所有的数据都被发送完毕再继续执行后续操作。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：dev为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_FlushInput()

```
int32_t OH_UsbSerial_FlushInput (UsbSerial_DeviceHandle * dev)
```

**描述**

刷新输入缓冲区，缓冲区中的数据会被立刻清空。 在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况。

调用该接口可以帮助清理这些异常状况，使通信恢复正常。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：dev为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_FlushOutput()

```
int32_t OH_UsbSerial_FlushOutput (UsbSerial_DeviceHandle * dev)
```

**描述**

刷新输出缓冲区，缓冲区中的数据会被立刻清空。 在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况。

调用该接口可以帮助清理这些异常状况，使通信恢复正常。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：dev为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_Init()

```
int32_t OH_UsbSerial_Init (void)
```

**描述**

初始化USB Serial DDK。

**起始版本：** 18

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INIT_ERROR 初始化DDK失败。


### OH_UsbSerial_Open()

```
int32_t OH_UsbSerial_Open (uint64_t deviceId, uint8_t interfaceIndex, UsbSerial_DeviceHandle ** dev)
```

**描述**

通过deviceId和interfaceIndex打开USB串口设备。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceId | 设备ID，代表要操作的设备。 | 
| interfaceIndex | 接口索引，对应USB协议中的[bInterfaceNumber](usb__ddk__types_8h.md#binterfacenumber)。 | 
| dev | 设备句柄。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因为：dev为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_MEMORY_ERROR 内存不足。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_DEVICE_NOT_FOUND 找不到设备或接口。


### OH_UsbSerial_Read()

```
int32_t OH_UsbSerial_Read (UsbSerial_DeviceHandle * dev, uint8_t * buff, uint32_t bufferSize, uint32_t * bytesRead)
```

**描述**

从USB串口设备读入数据到缓冲区。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 
| buff | 保存从USB串口设备读取数据的缓冲区。 | 
| bufferSize | 缓冲区的大小。 | 
| bytesRead | 实际读取的字节数，如果设置了阻塞模式，则实际读取到的数据等于bufferSize后才会返回，<br/>详见[OH_UsbSerial_SetTimeout](#oh_usbserial_settimeout)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：1. dev为空指针；2. buff为空指针；3. bufferSize等于0；4. bytesRead为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_MEMORY_ERROR buff地址无效。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_Release()

```
int32_t OH_UsbSerial_Release (void)
```

**描述**

释放USB Serial DDK。

**起始版本：** 18

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。


### OH_UsbSerial_SetBaudRate()

```
int32_t OH_UsbSerial_SetBaudRate (UsbSerial_DeviceHandle * dev, uint32_t baudRate)
```

**描述**

设置USB串口设备的波特率。 如果USB串口设备的参数为默认值（数据位为8，停止位为1，数据传输无校验），则只需要调用该接口设置波特率。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 
| baudRate | USB串口设备的波特率。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：dev为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_SetFlowControl()

```
int32_t OH_UsbSerial_SetFlowControl (UsbSerial_DeviceHandle * dev, UsbSerial_FlowControl flowControl)
```

**描述**

设置流控参数。 USB串口设备通信中的流控用于管理数据传输的速率，以确保发送方不会发送超过接收方处理能力的数据量。

如果USB串口设备实现了流控处理，则需要调用此接口。如果不调用此接口，默认为无流控。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 
| flowControl | 流控方式，详见[UsbSerial_FlowControl](#usbserial_flowcontrol)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：dev为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_SetParams()

```
int32_t OH_UsbSerial_SetParams (UsbSerial_DeviceHandle * dev, UsbSerial_Params * params)
```

**描述**

设置USB串口设备的参数。 如果USB串口设备的参数不为默认值（数据位默认为8，停止位默认为1，数据传输默认无校验），则需要调用该接口进行参数设置。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 
| params | 待设置的USB串口设备参数，详见[UsbSerial_Params](_usb_serial___params.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：1. dev为空指针；2. params为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_SetTimeout()

```
int32_t OH_UsbSerial_SetTimeout (UsbSerial_DeviceHandle * dev, int timeout)
```

**描述**

设置读取USB串口设备上报数据的超时时间（毫秒）。

在不调用此函数的情况下，超时值默认为0，表示不管是否读取到数据都立即返回。如果需要等待一定的时间或者必须读取到数据，则调用该接口。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 
| timeout | 读取USB串口设备的超时时间，其取值范围为：<br/>- (0, 25500]：以毫秒为单位的时间值，将其四舍五入为最接近的100毫秒后，作为实际的超时时间。 例如，输入12321，实际生效的超时时间为12300。<br/>- 0：表示立即返回数据，不等待。<br/>- -1：表示以阻塞方式读取数据，即读取数据时，只有读到指定长度的数据后才返回，详见[OH_UsbSerial_Read](#oh_usbserial_read)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：1. dev为空指针；2. timeout &lt;-1或timeout &gt;25500。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。


### OH_UsbSerial_Write()

```
int32_t OH_UsbSerial_Write (UsbSerial_DeviceHandle * dev, uint8_t * buff, uint32_t bufferSize, uint32_t * bytesWritten)
```

**描述**

将buff中的数据写入USB串口设备。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄。 | 
| buff | 写入USB串口设备数据的缓冲区。 | 
| bufferSize | 缓冲区的大小。 | 
| bytesWritten | 实际写入的字节数。 | 

**Permission：**

ohos.permission.ACCESS_DDK_USB_SERIAL

**返回：**

- USB_SERIAL_DDK_SUCCESS 调用接口成功。

- USB_SERIAL_DDK_NO_PERM 权限校验失败。

- USB_SERIAL_DDK_INVALID_PARAMETER 参数检查失败。可能原因：1. dev为空指针；2. buff为空指针；3. bufferSize等于0；4. bytesWritten为空指针。

- USB_SERIAL_DDK_INIT_ERROR 未初始化DDK。

- USB_SERIAL_DDK_SERVICE_ERROR DDK服务通信失败。

- USB_SERIAL_DDK_IO_ERROR DDK发生I/O错误。

- USB_SERIAL_DDK_INVALID_OPERATION 无效操作。
