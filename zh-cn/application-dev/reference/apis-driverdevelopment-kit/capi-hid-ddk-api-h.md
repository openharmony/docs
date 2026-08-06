# hid_ddk_api.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

声明主机侧访问输入设备的HID DDK（Driver Development Kit，驱动开发工具包）接口。该模块提供了创建、打开、读写HID设备的能力，支持设备管理和事件注入，支持两种使用模式：一是虚拟HID设备的创建与事件注入，适用于模拟键盘、鼠标、触摸屏输入等场景；二是真实HID设备的访问与通信，支持打开、读写设备报告以及获取设备信息，适用于与HID设备进行数据交互的场景。

**引用文件：** <hid/hid_ddk_api.h>

**库：** libhid.z.so

**系统能力：** SystemCapability.Driver.HID.Extension

**起始版本：** 11

**相关模块：** [HidDdk](capi-hidddk.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_Hid_CreateDevice(Hid_Device *hidDevice, Hid_EventProperties *hidEventProperties)](#oh_hid_createdevice) | 创建设备。适用于需要模拟虚拟HID输入设备的场景，如模拟键盘、鼠标等输入设备进行自动化测试。必须与[OH_Hid_DestroyDevice](#oh_hid_destroydevice)成对使用。 |
| [int32_t OH_Hid_EmitEvent(int32_t deviceId, const Hid_EmitItem items[], uint16_t length)](#oh_hid_emitevent) | 向指定设备发送事件列表，事件通过[OH_Hid_CreateDevice](#oh_hid_createdevice)创建的虚拟设备注入到系统中，系统将其作为真实输入事件进行处理。适用于模拟用户输入事件的场景，如模拟按键、鼠标移动、点击等操作进行自动化测试或远程控制。 |
| [int32_t OH_Hid_DestroyDevice(int32_t deviceId)](#oh_hid_destroydevice) | 销毁设备。必须与[OH_Hid_CreateDevice](#oh_hid_createdevice)成对使用，只能销毁由当前调用者创建的设备。 |
| [int32_t OH_Hid_Init(void)](#oh_hid_init) | 初始化HID DDK。必须在使用其他所有HID DDK方法之前调用此方法。不再使用任何HID DDK功能时，必须调用[OH_Hid_Release](#oh_hid_release)释放资源。 |
| [int32_t OH_Hid_Release(void)](#oh_hid_release) | 释放HID DDK。必须与[OH_Hid_Init](#oh_hid_init)成对使用。 |
| [int32_t OH_Hid_Open(uint64_t deviceId, uint8_t interfaceIndex, Hid_DeviceHandle **dev)](#oh_hid_open) | 打开deviceId和interfaceIndex指定的设备。在使用完毕后调用[OH_Hid_Close](#oh_hid_close)释放设备资源。 |
| [int32_t OH_Hid_Close(Hid_DeviceHandle **dev)](#oh_hid_close) | 关闭设备。必须与[OH_Hid_Open](#oh_hid_open)成对使用，适用于不再需要与HID设备通信时，释放设备资源的场景。 |
| [int32_t OH_Hid_Write(Hid_DeviceHandle *dev, uint8_t *data, uint32_t length, uint32_t *bytesWritten)](#oh_hid_write) | 向设备写入HID报告。 |
| [int32_t OH_Hid_ReadTimeout(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize, int timeout, uint32_t *bytesRead)](#oh_hid_readtimeout) | 在指定的超时时间内从设备读取报告。 |
| [int32_t OH_Hid_Read(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize, uint32_t *bytesRead)](#oh_hid_read) | 从设备读取报告，默认为阻塞模式（阻塞等待直到有数据可读取），可以调用[OH_Hid_SetNonBlocking](capi-hid-ddk-api-h.md#oh_hid_setnonblocking)改变模式。 |
| [int32_t OH_Hid_SetNonBlocking(Hid_DeviceHandle *dev, int nonBlock)](#oh_hid_setnonblocking) | 设置设备读取模式为非阻塞。 |
| [int32_t OH_Hid_GetRawInfo(Hid_DeviceHandle *dev, Hid_RawDevInfo *rawDevInfo)](#oh_hid_getrawinfo) | 获取设备原始信息。 |
| [int32_t OH_Hid_GetRawName(Hid_DeviceHandle *dev, char *data, uint32_t bufSize)](#oh_hid_getrawname) | 获取设备原始名称。 |
| [int32_t OH_Hid_GetPhysicalAddress(Hid_DeviceHandle *dev, char *data, uint32_t bufSize)](#oh_hid_getphysicaladdress) | 获取设备物理地址。 |
| [int32_t OH_Hid_GetRawUniqueId(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize)](#oh_hid_getrawuniqueid) | 获取设备原始唯一标识符。 |
| [int32_t OH_Hid_SendReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, const uint8_t *data, uint32_t length)](#oh_hid_sendreport) | 向设备发送指定类型的HID报告。 |
| [int32_t OH_Hid_GetReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, uint8_t *data, uint32_t bufSize)](#oh_hid_getreport) | 从设备获取指定类型的HID报告。 |
| [int32_t OH_Hid_GetReportDescriptor(Hid_DeviceHandle *dev, uint8_t *buf, uint32_t bufSize, uint32_t *bytesRead)](#oh_hid_getreportdescriptor) | 获取设备报告描述符。 |

## 函数说明

### OH_Hid_CreateDevice()

```c
int32_t OH_Hid_CreateDevice(Hid_Device *hidDevice, Hid_EventProperties *hidEventProperties)
```

**描述**

创建设备。适用于需要模拟虚拟HID输入设备的场景，如模拟键盘、鼠标等输入设备进行自动化测试。必须与[OH_Hid_DestroyDevice](#oh_hid_destroydevice)成对使用。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 11


**参数：**

| 参数项                                                                           | 描述 |
|-------------------------------------------------------------------------------| -- |
| [Hid_Device](capi-hidddk-hid-device.md) *hidDevice                            | 创建设备需要的基本信息，包括设备名、厂商ID、产品ID等。 |
| [Hid_EventProperties](capi-hidddk-hid-eventproperties.md) *hidEventProperties | 创建的设备关注的事件，包括事件类型、按键事件属性、绝对坐标事件属性、相对坐标事件属性等。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | deviceID（一个非负整数）成功创建设备的ID。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 连接HID DDK服务失败。可能原因：DDK服务未初始化。请调用OH_Hid_Init完成初始化。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能的原因：1. 入参hidDevice为空指针；<br>         2. 入参hidEventProperties为空指针；3. properties的长度超过7；4. hidEventTypes的长度超过5；<br>         5. hidKeys的长度超过100；6. hidAbs的长度超过26；7.hidRelBits的长度超过13；<br>         8. hidMiscellaneous的长度超过6。<br>         [HID_DDK_FAILURE](capi-hid-ddk-types-h.md#hid_ddkerrcode) 设备数量达到最大值200。 |

### OH_Hid_EmitEvent()

```c
int32_t OH_Hid_EmitEvent(int32_t deviceId, const Hid_EmitItem items[], uint16_t length)
```

**描述**

向指定设备发送事件列表，事件通过[OH_Hid_CreateDevice](#oh_hid_createdevice)创建的虚拟设备注入到系统中，系统将其作为真实输入事件进行处理。适用于模拟用户输入事件的场景，如模拟按键、鼠标移动、点击等操作进行自动化测试或远程控制。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t deviceId | 设备ID，必须是当前调用者通过[OH_Hid_CreateDevice](#oh_hid_createdevice)创建的设备，取值为非负数。 |
| const [Hid_EmitItem](capi-hidddk-hid-emititem.md) items[] | 发送的事件列表，事件包括类型（取值来源事件类型Hid_EventType）、编码（取值来源同步事件编码Hid_SynEvent、键值编码Hid_KeyCode、绝对坐标编码Hid_AbsAxes、相对坐标编码Hid_RelAxes、其他类型的输入事件编码Hid_MscEvent）、值（根据实际设备输入决定）。发送的事件将被注入到指定设备，模拟设备产生相应的输入行为。 |
| uint16_t length | 发送事件列表长度（一次发送事件个数），取值范围为[1, 7]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 调用接口成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 连接HID DDK服务失败或者调用方不是设备的创建者。请确保调用了OH_Hid_Init完成初始化，且调用方是设备的创建者。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能的原因：1.设备ID小于0；2.入参length长度超过7；3.入参items为空指针。请检查参数有效性。<br>         [HID_DDK_NULL_PTR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 对应设备的注入为空。请确保使用OH_Hid_CreateDevice返回的有效设备ID，且设备未被销毁。 |

### OH_Hid_DestroyDevice()

```c
int32_t OH_Hid_DestroyDevice(int32_t deviceId)
```

**描述**

销毁设备。适用于不再需要使用虚拟HID设备时，释放系统资源的场景。必须与[OH_Hid_CreateDevice](#oh_hid_createdevice)成对使用，只能销毁由当前调用者创建的设备。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t deviceId | 设备ID，必须是当前调用者创建的设备，取值为非负数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 调用接口成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 连接HID DDK服务失败或者调用方不是设备的创建者。请确保调用了OH_Hid_Init完成初始化，且调用方是设备的创建者。<br>         [HID_DDK_NULL_PTR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 设备不存在。请确保使用OH_Hid_CreateDevice返回的有效设备ID，且设备未被销毁。 |

### OH_Hid_Init()

```c
int32_t OH_Hid_Init(void)
```

**描述**

初始化HID DDK。必须在使用其他所有HID DDK方法之前调用此方法。不再使用任何HID DDK功能时，必须调用[OH_Hid_Release](#oh_hid_release)释放资源。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 初始化DDK失败。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。 |

### OH_Hid_Release()

```c
int32_t OH_Hid_Release(void)
```

**描述**

释放HID DDK。必须与[OH_Hid_Init](#oh_hid_init)成对使用。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。 |

### OH_Hid_Open()

```c
int32_t OH_Hid_Open(uint64_t deviceId, uint8_t interfaceIndex, Hid_DeviceHandle **dev)
```

**描述**

打开deviceId和interfaceIndex指定的设备。适用于需要与特定HID设备进行通信的场景，在使用完毕后调用[OH_Hid_Close](#oh_hid_close)释放设备资源。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项                        | 描述 |
|----------------------------| -- |
| uint64_t deviceId          | 操作设备的ID，可通过[OH_Usb_GetDevices](capi-usb-ddk-api-h.md#oh_usb_getdevices)查询获取。 |
| uint8_t interfaceIndex     | 接口索引，对应HID设备的接口。 |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) **dev | 设备操作句柄，输出参数。接口执行成功后会被赋值，表示打开的HID设备。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) dev内存申请失败。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) dev为空或*dev为空。<br>         [HID_DDK_DEVICE_NOT_FOUND](capi-hid-ddk-types-h.md#hid_ddkerrcode) 根据deviceId和interfaceIndex找不到设备。 |

### OH_Hid_Close()

```c
int32_t OH_Hid_Close(Hid_DeviceHandle **dev)
```

**描述**

关闭设备。必须与[OH_Hid_Open](#oh_hid_open)成对使用，适用于不再需要与HID设备通信时，释放设备资源的场景。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) **dev | 设备操作句柄，须通过[OH_Hid_Open](#oh_hid_open)打开并获取，接口调用成功后会释放资源并置空。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) dev为空或*dev为空。 |

### OH_Hid_Write()

```c
int32_t OH_Hid_Write(Hid_DeviceHandle *dev, uint8_t *data, uint32_t length, uint32_t *bytesWritten)
```

**描述**

向设备写入HID报告。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| uint8_t *data | 待写入的数据。 |
| uint32_t length | 写入数据的字节长度，大于0且最大不超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |
| uint32_t *bytesWritten | 实际写入的数据字节数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. data为空；3. length为0；4. length超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)；<br>             5. bytesWritten为空。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。 |

### OH_Hid_ReadTimeout()

```c
int32_t OH_Hid_ReadTimeout(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize, int timeout, uint32_t *bytesRead)
```

**描述**

在指定的超时时间内从设备读取报告。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| uint8_t *data | 存放读取数据的缓冲区。 |
| uint32_t bufSize | 存放读取数据的缓冲区大小，大于0且最大不超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |
| int timeout | 超时时间（毫秒），取值说明：大于0时，表示阻塞等待的毫秒数；等于0时表示立即返回；设置为-1时表示阻塞等待直至读出数据，不会返回超时。 |
| uint32_t *bytesRead | 读取的字节数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. data为空；3. bufSize为0；4. bufSize超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)；<br>             5. bytesRead为空。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 内存数据拷贝失败。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_TIMEOUT](capi-hid-ddk-types-h.md#hid_ddkerrcode) 读取超时。 |

### OH_Hid_Read()

```c
int32_t OH_Hid_Read(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize, uint32_t *bytesRead)
```

**描述**

从设备读取报告，默认为阻塞模式（阻塞等待直到有数据可读取），可以调用[OH_Hid_SetNonBlocking](capi-hid-ddk-api-h.md#oh_hid_setnonblocking)改变模式。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| uint8_t *data | 存放读取数据的缓冲区。 |
| uint32_t bufSize | 存放读取数据的缓冲区大小，大于0且最大不超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |
| uint32_t *bytesRead | 读取的字节数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. data为空；3. bufSize为0；4. bufSize超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)；<br>             5. bytesRead为空。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 内存数据拷贝失败。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_TIMEOUT](capi-hid-ddk-types-h.md#hid_ddkerrcode) 读取超时。 |

### OH_Hid_SetNonBlocking()

```c
int32_t OH_Hid_SetNonBlocking(Hid_DeviceHandle *dev, int nonBlock)
```

**描述**

设置设备读取模式为非阻塞。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| int nonBlock | 是否启用非阻塞模式读取数据。1：启用非阻塞模式，调用[OH_Hid_Read](capi-hid-ddk-api-h.md#oh_hid_read)接口时，如果设备有可读的数据，读取并返回[HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode)，<br>                 如果设备没有数据可读，则返回[HID_DDK_TIMEOUT](capi-hid-ddk-types-h.md#hid_ddkerrcode)。0：禁用非阻塞模式，启用阻塞模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. nonBlock不是1或0。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。 |

### OH_Hid_GetRawInfo()

```c
int32_t OH_Hid_GetRawInfo(Hid_DeviceHandle *dev, Hid_RawDevInfo *rawDevInfo)
```

**描述**

获取设备原始信息。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项                                                         | 描述 |
|-------------------------------------------------------------| -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| [Hid_RawDevInfo](capi-hidddk-hid-rawdevinfo.md) *rawDevInfo | 设备原始信息，包含厂商ID、产品ID和总线类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. rawDevInfo为空。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 不支持此操作。 |

### OH_Hid_GetRawName()

```c
int32_t OH_Hid_GetRawName(Hid_DeviceHandle *dev, char *data, uint32_t bufSize)
```

**描述**

获取设备原始名称。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| char *data | 存放读取数据的缓冲区。 |
| uint32_t bufSize | 存放读取数据的缓冲区大小，大于0且最大不超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. data为空；3. bufSize为0；4. bufSize超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 内存数据拷贝失败。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 不支持此操作。 |

### OH_Hid_GetPhysicalAddress()

```c
int32_t OH_Hid_GetPhysicalAddress(Hid_DeviceHandle *dev, char *data, uint32_t bufSize)
```

**描述**

获取设备物理地址。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| char *data | 存放读取数据的缓冲区。 |
| uint32_t bufSize | 存放读取数据的缓冲区大小，大于0且最大不超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. data为空；3. bufSize为0；4. bufSize超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 内存数据拷贝失败。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 不支持此操作。 |

### OH_Hid_GetRawUniqueId()

```c
int32_t OH_Hid_GetRawUniqueId(Hid_DeviceHandle *dev, uint8_t *data, uint32_t bufSize)
```

**描述**

获取设备原始唯一标识符。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| uint8_t *data | 存放读取数据的缓冲区。 |
| uint32_t bufSize | 存放读取数据的缓冲区大小，大于0且最大不超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. data为空；3. bufSize为0；4. bufSize超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 内存数据拷贝失败。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 不支持此操作。 |

### OH_Hid_SendReport()

```c
int32_t OH_Hid_SendReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, const uint8_t *data, uint32_t length)
```

**描述**

向设备发送指定类型的HID报告。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- |---------------------------------------------------------------------------------------------------|
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| [Hid_ReportType](capi-hid-ddk-types-h.md#hid_reporttype) reportType | 报告类型，可指定为输入报告、输出报告或特性报告。 |
| const uint8_t *data | 待发送的数据。 |
| uint32_t length | 发送数据的字节长度，大于0且最大不超过 [HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. data为空；3. length为0；4. length超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 不支持此操作。 |

### OH_Hid_GetReport()

```c
int32_t OH_Hid_GetReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, uint8_t *data, uint32_t bufSize)
```

**描述**

从设备获取指定类型的HID报告。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| [Hid_ReportType](capi-hid-ddk-types-h.md#hid_reporttype) reportType | 报告类型。 |
| uint8_t *data | 存放读取数据的缓冲区。 |
| uint32_t bufSize | 存放读取数据的缓冲区大小，大于0且最大不超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. data为空；3. bufSize为0；4. bufSize超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 内存数据拷贝失败。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 不支持此操作。 |

### OH_Hid_GetReportDescriptor()

```c
int32_t OH_Hid_GetReportDescriptor(Hid_DeviceHandle *dev, uint8_t *buf, uint32_t bufSize, uint32_t *bytesRead)
```

**描述**

获取设备报告描述符。

**需要权限：** ohos.permission.ACCESS_DDK_HID

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Hid_DeviceHandle](capi-hidddk-hid-devicehandle.md) *dev | 设备操作句柄，使用前须通过[OH_Hid_Open](#oh_hid_open)打开并获取。 |
| uint8_t *buf | 存放描述符的缓冲区。 |
| uint32_t bufSize | 缓冲区的字节大小，大于0且最大不超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)，否则无法通过参数校验。 |
| uint32_t *bytesRead | 读取的字节数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [HID_DDK_SUCCESS](capi-hid-ddk-types-h.md#hid_ddkerrcode) 操作成功。<br>         [HID_DDK_NO_PERM](capi-hid-ddk-types-h.md#hid_ddkerrcode) 权限校验失败。请确保应用已声明ohos.permission.ACCESS_DDK_HID权限。<br>         [HID_DDK_INVALID_PARAMETER](capi-hid-ddk-types-h.md#hid_ddkerrcode) 参数校验失败。可能原因：1. dev为空；<br>             2. buf为空；3. bufSize为0；4. bufSize超过[HID_MAX_REPORT_BUFFER_SIZE](capi-hid-ddk-types-h.md#hid_max_report_buffer_size)；<br>             5. bytesRead为空。<br>         [HID_DDK_INIT_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) DDK未初始化，请确保已调用[OH_Hid_Init](#oh_hid_init)完成初始化。<br>         [HID_DDK_SERVICE_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 与DDK服务通信失败。可能原因：服务内部错误。请检查当前操作和设备状态。<br>         [HID_DDK_MEMORY_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) 内存数据拷贝失败。<br>         [HID_DDK_IO_ERROR](capi-hid-ddk-types-h.md#hid_ddkerrcode) I/O操作失败。可能原因：设备状态异常、数据传输错误等。请检查设备状态和参数。<br>         [HID_DDK_INVALID_OPERATION](capi-hid-ddk-types-h.md#hid_ddkerrcode) 不支持此操作。 |


