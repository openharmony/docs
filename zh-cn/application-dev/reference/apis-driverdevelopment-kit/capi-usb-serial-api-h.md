# usb_serial_api.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

声明用于主机侧通过USB接口访问串口设备的USB Serial DDK接口，提供串口读写操作和参数配置的能力，适用于工业控制、嵌入式设备通信等需要通过USB访问串口设备的场景。

**引用文件：** <usb_serial/usb_serial_api.h>

**库：** libusb_serial_ndk.z.so

**系统能力：** SystemCapability.Driver.UsbSerial.Extension

**起始版本：** 18

**相关模块：** [USBSerialDDK](capi-serialddk.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_UsbSerial_Init(void)](#oh_usbserial_init) | 初始化USB Serial DDK。必须在调用其他所有USB Serial DDK方法之前调用该接口，该接口会建立与DDK服务的通信连接，并加载必要的驱动资源。请在使用完毕后调用[OH_UsbSerial_Release](#oh_usbserial_release)释放DDK，以避免资源泄漏。|
| [int32_t OH_UsbSerial_Release(void)](#oh_usbserial_release) | 释放USB Serial DDK。需和[OH_UsbSerial_Init](#oh_usbserial_init)配对使用，释放后不可再调用其他USB Serial DDK方法。 |
| [int32_t OH_UsbSerial_Open(uint64_t deviceId, uint8_t interfaceIndex, UsbSerial_Device **dev)](#oh_usbserial_open) | 通过deviceId和interfaceIndex打开USB串口设备。该接口会建立与指定USB串口设备的连接，并返回设备句柄用于后续操作。使用完毕后请调用[OH_UsbSerial_Close](#oh_usbserial_close)关闭设备，否则可能导致设备资源无法正确释放。 |
| [int32_t OH_UsbSerial_Close(UsbSerial_Device **dev)](#oh_usbserial_close) | 关闭USB串口设备。该接口会释放设备占用的资源，需和[OH_UsbSerial_Open](#oh_usbserial_open)配对使用。 |
| [int32_t OH_UsbSerial_Read(UsbSerial_Device *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesRead)](#oh_usbserial_read) | 从USB串口设备读入数据到缓冲区。 |
| [int32_t OH_UsbSerial_Write(UsbSerial_Device *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesWritten)](#oh_usbserial_write) | 将buff中的数据写入USB串口设备。 |
| [int32_t OH_UsbSerial_SetBaudRate(UsbSerial_Device *dev, uint32_t baudRate)](#oh_usbserial_setbaudrate) | 设置USB串口设备的波特率。如果USB串口设备的参数为默认值（数据位为8，停止位为1，数据传输无校验），则只需要调用该接口设置波特率。 |
| [int32_t OH_UsbSerial_SetParams(UsbSerial_Device *dev, UsbSerial_Params *params)](#oh_usbserial_setparams) | 设置USB串口设备的参数。如果USB串口设备的参数不为默认值（数据位默认为8，停止位默认为1，数据传输默认无校验），则需要调用该接口进行参数设置。 |
| [int32_t OH_UsbSerial_SetTimeout(UsbSerial_Device *dev, int timeout)](#oh_usbserial_settimeout) | 设置读取USB串口设备上报数据的超时时间（毫秒）。在不调用此函数的情况下，超时值默认为0，表示不管是否读取到数据都立即返回。如果需要等待一定的时间或者必须读取到数据，则调用该接口。 |
| [int32_t OH_UsbSerial_SetFlowControl(UsbSerial_Device *dev, UsbSerial_FlowControl flowControl)](#oh_usbserial_setflowcontrol) | 设置流控参数。USB串口设备通信中的流控用于管理数据传输的速率，以确保发送方不会发送超过接收方处理能力的数据量。如果USB串口设备实现了流控处理，则需要调用此接口。未调用此接口时，默认为无流控。 |
| [int32_t OH_UsbSerial_Flush(UsbSerial_Device *dev)](#oh_usbserial_flush) | 清空输入和输出缓冲区（会等待输出缓冲区的数据发送完毕）。在向USB串口设备发送数据时，可能会有大量数据缓冲在内核中等待发送。如果应用程序关闭设备或者退出之前没有等待这些数据被实际发送出去，那么部分数据可能会丢失。调用该接口可以确保所有的数据都被发送完毕再继续执行后续操作。 |
| [int32_t OH_UsbSerial_FlushInput(UsbSerial_Device *dev)](#oh_usbserial_flushinput) | 清空输入缓冲区，缓冲区中的数据会被立刻清空。在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况，此时可以用该接口清理接收端的异常状况，使通信恢复正常。此接口不影响输出缓冲区中的待发送数据。 |
| [int32_t OH_UsbSerial_FlushOutput(UsbSerial_Device *dev)](#oh_usbserial_flushoutput) | 清空输出缓冲区，缓冲区中的数据会被立刻清空。在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况，可以用该接口清理发送端的异常状况，使通信恢复正常。此接口不影响输入缓冲区中的已接收数据。 |

## 函数说明

### OH_UsbSerial_Init()

```c
int32_t OH_UsbSerial_Init(void)
```

**描述**

初始化USB Serial DDK。必须在调用其他所有USB Serial DDK方法之前调用该接口，该接口会建立与DDK服务的通信连接，并加载必要的驱动资源。请在使用完毕后调用[OH_UsbSerial_Release](#oh_usbserial_release)释放DDK，以避免资源泄漏。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18

**返回：**

| 类型 | 说明                                                                                                                                                                                                                                |
| -- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 初始化DDK失败。 |

### OH_UsbSerial_Release()

```c
int32_t OH_UsbSerial_Release(void)
```

**描述**

释放USB Serial DDK。需和[OH_UsbSerial_Init](#oh_usbserial_init)配对使用，释放后不可再调用其他USB Serial DDK方法。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK未初始化或已释放。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查设备状态。 |

### OH_UsbSerial_Open()

```c
int32_t OH_UsbSerial_Open(uint64_t deviceId, uint8_t interfaceIndex, UsbSerial_Device **dev)
```

**描述**

通过deviceId和interfaceIndex打开USB串口设备。该接口会建立与指定USB串口设备的连接，并返回设备句柄用于后续操作。使用完毕后请调用[OH_UsbSerial_Close](#oh_usbserial_close)关闭设备，否则可能导致设备资源无法正确释放。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项                              | 描述                                         |
|----------------------------------|--------------------------------------------|
| uint64_t deviceId                | 设备ID，代表要操作的设备，可通过[OH_Usb_GetDevices](capi-usb-ddk-api-h.md#oh_usb_getdevices)查询获取。                             |
| uint8_t interfaceIndex           | 接口索引，对应USB协议中的bInterfaceNumber。 |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) **dev | 设备句柄，输出参数，用于返回打开后的USB串口设备句柄，使用完毕后需调用[OH_UsbSerial_Close](#oh_usbserial_close)释放。 |

**返回：**

| 类型 | 说明 |
| -- |--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因为：dev为空指针或*dev为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_MEMORY_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 内存不足。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_DEVICE_NOT_FOUND](capi-usb-serial-types-h.md#usbserial_ddkretcode) 找不到设备或接口。 |

### OH_UsbSerial_Close()

```c
int32_t OH_UsbSerial_Close(UsbSerial_Device **dev)
```

**描述**

关闭USB串口设备。该接口会释放设备占用的资源，需和[OH_UsbSerial_Open](#oh_usbserial_open)配对使用。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) **dev | 设备句柄，输入输出参数，关闭后该指针会置空。 |

**返回：**

| 类型 | 说明 |
| -- |----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：dev为空指针或*dev为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_Read()

```c
int32_t OH_UsbSerial_Read(UsbSerial_Device *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesRead)
```

**描述**

从USB串口设备读入数据到缓冲区。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |
| uint8_t *buff | 从USB串口设备读取数据的缓冲区，需由调用方分配且容量不小于bufferSize。 |
| uint32_t bufferSize | 缓冲区的大小。 |
| uint32_t *bytesRead | 实际读取的字节数，如果设置了阻塞模式，则实际读取到的数据等于bufferSize后才会返回；如果设置了超时，则返回值可能小于bufferSize。<br>                  详见[OH_UsbSerial_SetTimeout](#oh_usbserial_settimeout)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：1. dev为空指针；<br>         2. buff为空指针; 3. bufferSize等于0; 4. bytesRead为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_MEMORY_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) buff地址无效。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_Write()

```c
int32_t OH_UsbSerial_Write(UsbSerial_Device *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesWritten)
```

**描述**

将buff中的数据写入USB串口设备。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |
| uint8_t *buff | 写入USB串口设备数据的缓冲区，需由调用方分配且容量不小于bufferSize。 |
| uint32_t bufferSize | 缓冲区的大小。 |
| uint32_t *bytesWritten | 实际写入的字节数。仅在接口返回成功时有效，且可能小于bufferSize。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：1. dev为空指针；<br>         2. buff为空指针; 3. bufferSize等于0; 4. bytesWritten为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>[USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_SetBaudRate()

```c
int32_t OH_UsbSerial_SetBaudRate(UsbSerial_Device *dev, uint32_t baudRate)
```

**描述**

设置USB串口设备的波特率。如果USB串口设备的参数为默认值（数据位为8，停止位为1，数据传输无校验），则只需要调用该接口设置波特率。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |
| uint32_t baudRate | USB串口设备的波特率，单位：波特。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode)参数检查失败。可能原因：dev为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_SetParams()

```c
int32_t OH_UsbSerial_SetParams(UsbSerial_Device *dev, UsbSerial_Params *params)
```

**描述**

设置USB串口设备的参数。如果USB串口设备的参数不为默认值（数据位默认为8，停止位默认为1，数据传输默认无校验），则需要调用该接口进行参数设置。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项                                                                     | 描述 |
|-------------------------------------------------------------------------| -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |
| [UsbSerial_Params](capi-serialddk-usbserial-params.md) *params                                            | 待设置的USB串口设备参数，详见[UsbSerial_Params](capi-serialddk-usbserial-params.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：1. dev为空指针；<br>         2. params为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_SetTimeout()

```c
int32_t OH_UsbSerial_SetTimeout(UsbSerial_Device *dev, int timeout)
```

**描述**

设置读取USB串口设备上报数据的超时时间（毫秒）。在不调用此函数的情况下，超时值默认为0，表示不管是否读取到数据都立即返回。如果需要等待一定的时间或者必须读取到数据，则调用该接口。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |
| int timeout | 读取USB串口设备的超时时间。其取值范围为(0, 25500]时，表示以毫秒为单位的时间值，将其四舍五入为最接近的100毫秒后，作为实际的超时时间，例如输入12321时，实际生效的超时时间为12300；取值为0时，表示立即返回数据，不等待；取值为-1时，表示以阻塞方式读取数据，即读取数据时，只有读到指定长度的数据后才返回，详见[OH_UsbSerial_Read](#oh_usbserial_read)。建议在轮询场景使用0，需要超时控制的场景使用(0, 25500]，必须读取完整数据的场景使用-1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：1. dev为空指针；<br>         2. timeout < -1 或 timeout > 25500。请检查参数有效性和超时时间。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_SetFlowControl()

```c
int32_t OH_UsbSerial_SetFlowControl(UsbSerial_Device *dev, UsbSerial_FlowControl flowControl)
```

**描述**

设置流控参数。USB串口设备通信中的流控用于管理数据传输的速率，以确保发送方不会发送超过接收方处理能力的数据量。如果USB串口设备实现了流控处理，则需要调用此接口。未调用此接口时，默认为无流控。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项                                                                                   | 描述 |
|---------------------------------------------------------------------------------------| -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev               | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |
| [UsbSerial_FlowControl](capi-usb-serial-types-h.md#usbserial_flowcontrol) flowControl | 流控方式，详见[UsbSerial_FlowControl](capi-usb-serial-types-h.md#usbserial_flowcontrol)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：dev为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_Flush()

```c
int32_t OH_UsbSerial_Flush(UsbSerial_Device *dev)
```

**描述**

清空输入和输出缓冲区（会等待输出缓冲区的数据发送完毕）。在向USB串口设备发送数据时，可能会有大量数据缓冲在内核中等待发送。如果应用程序关闭设备或者退出之前没有等待这些数据被实际发送出去，那么部分数据可能会丢失。调用该接口可以确保所有的数据都被发送完毕再继续执行后续操作。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：dev为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_FlushInput()

```c
int32_t OH_UsbSerial_FlushInput(UsbSerial_Device *dev)
```

**描述**

清空输入缓冲区，缓冲区中的数据会被立刻清空。在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况，此时可以用该接口清理接收端的异常状况，使通信恢复正常。此接口不影响输出缓冲区中的待发送数据。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：dev为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |

### OH_UsbSerial_FlushOutput()

```c
int32_t OH_UsbSerial_FlushOutput(UsbSerial_Device *dev)
```

**描述**

清空输出缓冲区，缓冲区中的数据会被立刻清空。在和USB串口设备通信过程中，特别是在调试阶段，有时会遇到乱序的数据包或者其他异常情况，可以用该接口清理发送端的异常状况，使通信恢复正常。此接口不影响输入缓冲区中的已接收数据。

**需要权限：** ohos.permission.ACCESS_DDK_USB_SERIAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [UsbSerial_Device](capi-serialddk-usbserial-devicehandle.md) *dev | 设备句柄，需调用[OH_UsbSerial_Open](#oh_usbserial_open)接口打开设备并获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [USB_SERIAL_DDK_SUCCESS](capi-usb-serial-types-h.md#usbserial_ddkretcode) 调用接口成功。<br>         [USB_SERIAL_DDK_NO_PERM](capi-usb-serial-types-h.md#usbserial_ddkretcode) 权限校验失败。请检查应用是否正确获取了ohos.permission.ACCESS_DDK_USB_SERIAL权限。<br>         [USB_SERIAL_DDK_INVALID_PARAMETER](capi-usb-serial-types-h.md#usbserial_ddkretcode) 参数检查失败。可能原因：dev为空指针。请检查参数的有效性。<br>         [USB_SERIAL_DDK_INIT_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) 未初始化DDK。请先调用[OH_UsbSerial_Init](#oh_usbserial_init)初始化DDK。<br>         [USB_SERIAL_DDK_SERVICE_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK服务执行失败。请检查参数和设备状态。<br>         [USB_SERIAL_DDK_IO_ERROR](capi-usb-serial-types-h.md#usbserial_ddkretcode) DDK发生I/O错误。请检查设备规格和参数。<br>         [USB_SERIAL_DDK_INVALID_OPERATION](capi-usb-serial-types-h.md#usbserial_ddkretcode) 无效操作。请确保设备已正常打开。 |


