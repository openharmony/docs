# scsi_peripheral_api.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

声明用于主机侧访问SCSI设备的SCSI Peripheral DDK接口。该模块基于SCSI协议标准，通过DDK驱动服务提供SCSI设备访问能力。

**引用文件：** <scsi_peripheral/scsi_peripheral_api.h>

**库：** libscsi.z.so

**系统能力：** SystemCapability.Driver.SCSI.Extension

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_ScsiPeripheral_Init(void)](#oh_scsiperipheral_init) | 初始化SCSI Peripheral DDK。必须在调用其他所有SCSI Peripheral DDK方法之前调用此方法。使用完毕后必须调用OH_ScsiPeripheral_Release释放资源，否则会导致资源泄漏。 |
| [int32_t OH_ScsiPeripheral_Release(void)](#oh_scsiperipheral_release) | 释放SCSI Peripheral DDK。必须先通过OH_ScsiPeripheral_Init初始化，并在不再使用SCSI Peripheral DDK方法后释放，以避免资源泄漏。 |
| [int32_t OH_ScsiPeripheral_Open(uint64_t deviceId, uint8_t interfaceIndex, ScsiPeripheral_Device **dev)](#oh_scsiperipheral_open) | 打开deviceId和interfaceIndex指定的SCSI设备。其中，deviceId可以通过USB设备的总线编号左移32位后，同其设备地址进行或运算得到，interfaceIndex为需要打开的USB接口的索引值。在使用完设备后，须调用OH_ScsiPeripheral_Close关闭设备并释放资源，否则会导致资源泄漏。 |
| [int32_t OH_ScsiPeripheral_Close(ScsiPeripheral_Device **dev)](#oh_scsiperipheral_close) | 关闭SCSI设备，释放设备句柄资源并使其失效。与OH_ScsiPeripheral_Open配对使用，在设备使用完毕后必须调用此方法关闭设备并释放资源，否则会导致资源泄漏。 |
| [int32_t OH_ScsiPeripheral_TestUnitReady(ScsiPeripheral_Device *dev, ScsiPeripheral_TestUnitReadyRequest *request, ScsiPeripheral_Response *response)](#oh_scsiperipheral_testunitready) | 检查逻辑单元是否已经准备好（逻辑单元是SCSI设备中可独立寻址的I/O操作实体）。 |
| [int32_t OH_ScsiPeripheral_Inquiry(ScsiPeripheral_Device *dev, ScsiPeripheral_InquiryRequest *request, ScsiPeripheral_InquiryInfo *inquiryInfo, ScsiPeripheral_Response *response)](#oh_scsiperipheral_inquiry) | 查询SCSI设备的基本信息。 |
| [int32_t OH_ScsiPeripheral_ReadCapacity10(ScsiPeripheral_Device *dev, ScsiPeripheral_ReadCapacityRequest *request, ScsiPeripheral_CapacityInfo *capacityInfo, ScsiPeripheral_Response *response)](#oh_scsiperipheral_readcapacity10) | 获取SCSI设备的容量信息。 |
| [int32_t OH_ScsiPeripheral_RequestSense(ScsiPeripheral_Device *dev, ScsiPeripheral_RequestSenseRequest *request, ScsiPeripheral_Response *response)](#oh_scsiperipheral_requestsense) | 获取Sense Data（SCSI设备返回给主机的信息，用于报告设备的状态、错误信息以及诊断信息）。 |
| [int32_t OH_ScsiPeripheral_Read10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request, ScsiPeripheral_Response *response)](#oh_scsiperipheral_read10) | 从指定逻辑块读取数据。 |
| [int32_t OH_ScsiPeripheral_Write10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request, ScsiPeripheral_Response *response)](#oh_scsiperipheral_write10) | 写数据到设备的指定逻辑块。 |
| [int32_t OH_ScsiPeripheral_Verify10(ScsiPeripheral_Device *dev, ScsiPeripheral_VerifyRequest *request, ScsiPeripheral_Response *response)](#oh_scsiperipheral_verify10) | 校验指定逻辑块。 |
| [int32_t OH_ScsiPeripheral_SendRequestByCdb(ScsiPeripheral_Device *dev, ScsiPeripheral_Request *request, ScsiPeripheral_Response *response)](#oh_scsiperipheral_sendrequestbycdb) | 以CDB（Command Descriptor Block，命令描述符块）方式发送SCSI命令。 |
| [int32_t OH_ScsiPeripheral_CreateDeviceMemMap(ScsiPeripheral_Device *dev, size_t size, ScsiPeripheral_DeviceMemMap **devMmap)](#oh_scsiperipheral_createdevicememmap) | 创建缓冲区。请在缓冲区使用完后，调用[OH_ScsiPeripheral_DestroyDeviceMemMap](#oh_scsiperipheral_destroydevicememmap)销毁缓冲区，否则会造成资源泄漏。 |
| [int32_t OH_ScsiPeripheral_DestroyDeviceMemMap(ScsiPeripheral_DeviceMemMap *devMmap)](#oh_scsiperipheral_destroydevicememmap) | 销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄漏。 |
| [int32_t OH_ScsiPeripheral_ParseBasicSenseInfo(uint8_t *senseData, uint8_t senseDataLen, ScsiPeripheral_BasicSenseInfo *senseInfo)](#oh_scsiperipheral_parsebasicsenseinfo) | 解析基本的Sense Data，包括Information、Command specific information、Sense key specific字段。 |

## 函数说明

### OH_ScsiPeripheral_Init()

```c
int32_t OH_ScsiPeripheral_Init(void)
```

**描述**

初始化SCSI Peripheral DDK。必须在调用其他所有SCSI Peripheral DDK方法之前调用此方法。使用完毕后必须调用OH_ScsiPeripheral_Release释放资源，否则会导致资源泄漏。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 初始化DDK失败。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。 |

### OH_ScsiPeripheral_Release()

```c
int32_t OH_ScsiPeripheral_Release(void)
```

**描述**

释放SCSI Peripheral DDK。必须先通过OH_ScsiPeripheral_Init初始化，并在不再使用SCSI Peripheral DDK方法后释放，以避免资源泄漏。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK或DDK初始化失败。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。 |

### OH_ScsiPeripheral_Open()

```c
int32_t OH_ScsiPeripheral_Open(uint64_t deviceId, uint8_t interfaceIndex, ScsiPeripheral_Device **dev)
```

**描述**

打开deviceId和interfaceIndex指定的SCSI设备。其中，deviceId可以通过USB设备的总线编号左移32位后，同其设备地址进行或运算得到，interfaceIndex为需要打开的USB接口的索引值。在使用完设备后，须调用OH_ScsiPeripheral_Close关闭设备并释放资源，否则会导致资源泄漏。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                             | 描述 |
|---------------------------------| -- |
| uint64_t deviceId               | 设备ID，代表要操作的设备，可通过[OH_Usb_GetDevices](capi-usb-ddk-api-h.md#oh_usb_getdevices)查询获取。 |
| uint8_t interfaceIndex          |  接口索引，为需要打开的SCSI设备对应USB接口的索引值。 |
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) **dev | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空或*dev为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 通过deviceId和interfaceIndex找不到设备。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。|

### OH_ScsiPeripheral_Close()

```c
int32_t OH_ScsiPeripheral_Close(ScsiPeripheral_Device **dev)
```

**描述**

关闭SCSI设备，释放设备句柄资源并使其失效。与OH_ScsiPeripheral_Open配对使用，在设备使用完毕后必须调用此方法关闭设备并释放资源，否则会导致资源泄漏。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) **dev | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空或*dev为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。 |

### OH_ScsiPeripheral_TestUnitReady()

```c
int32_t OH_ScsiPeripheral_TestUnitReady(ScsiPeripheral_Device *dev, ScsiPeripheral_TestUnitReadyRequest *request, ScsiPeripheral_Response *response)
```

**描述**

检查逻辑单元是否已经准备好（逻辑单元是SCSI设备中可独立寻址的I/O操作实体）。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                                                                                         | 描述                                                                                                                     |
|---------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                                  | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。                                                                                |
| [ScsiPeripheral_TestUnitReadyRequest](capi-scsiperipheralddk-scsiperipheral-testunitreadyrequest.md) *request | 逻辑单元检查命令（test unit ready）的请求信息，详情参见[ScsiPeripheral_TestUnitReadyRequest](capi-scsiperipheralddk-scsiperipheral-testunitreadyrequest.md)。 |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response      | 逻辑单元检查命令（test unit ready）的响应信息，详情参见[ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)。       |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、request为空或者response为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 传输超时。请检查设备状态、或适当增加超时时间。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。 |

### OH_ScsiPeripheral_Inquiry()

```c
int32_t OH_ScsiPeripheral_Inquiry(ScsiPeripheral_Device *dev, ScsiPeripheral_InquiryRequest *request, ScsiPeripheral_InquiryInfo *inquiryInfo, ScsiPeripheral_Response *response)
```

**描述**

查询SCSI设备的基本信息。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                                                                                    | 描述                                                                                                   |
|----------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                             | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。                                                              |
| [ScsiPeripheral_InquiryRequest](capi-scsiperipheralddk-scsiperipheral-inquiryrequest.md) *request        | inquiry命令的请求信息，详情参见[ScsiPeripheral_InquiryRequest](capi-scsiperipheralddk-scsiperipheral-inquiryrequest.md)。           |
| [ScsiPeripheral_InquiryInfo](capi-scsiperipheralddk-scsiperipheral-inquiryinfo.md) *inquiryInfo          | inquiry命令返回的查询信息，详情参见[ScsiPeripheral_InquiryInfo](capi-scsiperipheralddk-scsiperipheral-inquiryinfo.md)。               |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response | inquiry命令返回的原始响应信息，详情参见[ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、 request为空、inquiryInfo为空、inquiryInfo->data或者response为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 传输超时。请检查设备状态、或适当增加超时时间。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。 |

### OH_ScsiPeripheral_ReadCapacity10()

```c
int32_t OH_ScsiPeripheral_ReadCapacity10(ScsiPeripheral_Device *dev, ScsiPeripheral_ReadCapacityRequest *request, ScsiPeripheral_CapacityInfo *capacityInfo, ScsiPeripheral_Response *response)
```

**描述**

获取SCSI设备的容量信息。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                                                                                       | 描述                                                                                                         |
|-------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                                | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。                                                                    |
| [ScsiPeripheral_ReadCapacityRequest](capi-scsiperipheralddk-scsiperipheral-readcapacityrequest.md) *request | read capacity命令的请求信息，详情参见[ScsiPeripheral_ReadCapacityRequest](capi-scsiperipheralddk-scsiperipheral-readcapacityrequest.md)。 |
| [ScsiPeripheral_CapacityInfo](capi-scsiperipheralddk-scsiperipheral-capacityinfo.md) *capacityInfo          | read capacity命令返回的容量信息，详情参见[ScsiPeripheral_CapacityInfo](capi-scsiperipheralddk-scsiperipheral-capacityinfo.md)。             |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response    | read capacity命令返回的原始响应信息，详情参见[ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、 request为空、capacityInfo为空或者response为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 传输超时。请检查设备状态、或适当增加超时时间。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。 |

### OH_ScsiPeripheral_RequestSense()

```c
int32_t OH_ScsiPeripheral_RequestSense(ScsiPeripheral_Device *dev, ScsiPeripheral_RequestSenseRequest *request, ScsiPeripheral_Response *response)
```

**描述**

获取Sense Data（SCSI设备返回给主机的信息，用于报告设备的状态、错误信息以及诊断信息）。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                                                                                       | 描述                                                                                                         |
|-------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                                | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。                                                                    |
| [ScsiPeripheral_RequestSenseRequest](capi-scsiperipheralddk-scsiperipheral-requestsenserequest.md) *request | Request Sense命令的请求信息，详情参见[ScsiPeripheral_RequestSenseRequest](capi-scsiperipheralddk-scsiperipheral-requestsenserequest.md)。 |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response    | Request Sense命令返回的响应信息，详情参见[ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)。   |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、 request为空或者response为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 传输超时。请检查设备状态、或适当增加超时时间。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。 |

### OH_ScsiPeripheral_Read10()

```c
int32_t OH_ScsiPeripheral_Read10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request, ScsiPeripheral_Response *response)
```

**描述**

从指定逻辑块读取数据。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                                                                                     | 描述                                                                                              |
|-----------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                              | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。                                                         |
| [ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md) *request | read命令的请求信息，详情参见[ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md)。 |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response  | read命令返回的响应信息，详情参见[ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、 request为空、request->data或者response为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 传输超时。请检查设备状态、或适当增加超时时间。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。 |

### OH_ScsiPeripheral_Write10()

```c
int32_t OH_ScsiPeripheral_Write10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request, ScsiPeripheral_Response *response)
```

**描述**

写数据到设备的指定逻辑块。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                                                                                     | 描述                                                                                               |
|-----------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                              | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。                                                          |
| [ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md) *request | write命令的请求信息，详情参见[ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md)。 |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response  | write命令返回的响应信息，详情参见[ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、 request为空、request->data为空或者response为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 传输超时。请检查设备状态、或适当增加超时时间。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。 |

### OH_ScsiPeripheral_Verify10()

```c
int32_t OH_ScsiPeripheral_Verify10(ScsiPeripheral_Device *dev, ScsiPeripheral_VerifyRequest *request, ScsiPeripheral_Response *response)
```

**描述**

校验指定逻辑块。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                                                                                    | 描述                                                                                                |
|----------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                             | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。                                                           |
| [ScsiPeripheral_VerifyRequest](capi-scsiperipheralddk-scsiperipheral-verifyrequest.md) *request          | verify命令的请求信息，详情参见[ScsiPeripheral_VerifyRequest](capi-scsiperipheralddk-scsiperipheral-verifyrequest.md)。           |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response | verify命令返回的响应信息，详情参见[ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、request为空或者response为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 传输超时。请检查设备状态、或适当增加超时时间。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。 |

### OH_ScsiPeripheral_SendRequestByCdb()

```c
int32_t OH_ScsiPeripheral_SendRequestByCdb(ScsiPeripheral_Device *dev, ScsiPeripheral_Request *request, ScsiPeripheral_Response *response)
```

**描述**

以CDB（Command Descriptor Block，命令描述符块）方式发送SCSI命令。

**需要权限：** ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**起始版本：** 18


**参数：**

| 参数项                                                                                    | 描述                                                                                   |
|----------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                             | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。                                              |
| [ScsiPeripheral_Request](capi-scsiperipheralddk-scsiperipheral-request.md) *request    | CDB请求，详情参见[ScsiPeripheral_Request](capi-scsiperipheralddk-scsiperipheral-request.md)。调用时需确保data字段不为空、cdbLength字段不为0。   |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response | CDB响应，详情参见[ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 权限校验失败。请确保应用已正确获取 ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL 权限。<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 未初始化DDK。请先调用OH_ScsiPeripheral_Init进行初始化。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、 request为空、request->data为<br>         空、request->cdbLength为0或者response为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 与DDK服务通信失败。请检查DDK服务是否初始化并正常运行。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) DDK发生I/O错误。请检查设备状态是否正常、参数是否正确。<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 传输超时。请检查设备状态、或适当增加超时时间。<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 不支持该操作。请检查设备规格和状态。 |

### OH_ScsiPeripheral_CreateDeviceMemMap()

```c
int32_t OH_ScsiPeripheral_CreateDeviceMemMap(ScsiPeripheral_Device *dev, size_t size, ScsiPeripheral_DeviceMemMap **devMmap)
```

**描述**

创建缓冲区。请在缓冲区使用完后，调用[OH_ScsiPeripheral_DestroyDeviceMemMap](#oh_scsiperipheral_destroydevicememmap)销毁缓冲区，否则会造成资源泄漏。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
|------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev  | 设备句柄，详情参见[ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)。   |
| size_t size | 缓冲区的大小，单位：字节。|
| [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md) **devMmap | 创建的缓冲区通过该参数返回给调用者，详情参见[ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) dev为空、devMmap为空或*devMmap为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。 |

### OH_ScsiPeripheral_DestroyDeviceMemMap()

```c
int32_t OH_ScsiPeripheral_DestroyDeviceMemMap(ScsiPeripheral_DeviceMemMap *devMmap)
```

**描述**

销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄漏。

**起始版本：** 18


**参数：**

| 参数项                                                                                           | 描述                                                                                                                                                                                |
|-----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md) *devMmap | 待销毁的缓冲区指针，该缓冲区由[OH_ScsiPeripheral_CreateDeviceMemMap](#oh_scsiperipheral_createdevicememmap)创建。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) devMmap为空。请检查指针参数是否正确。<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 内存操作失败。请检查内存状态以及是否存在越界操作。 |

### OH_ScsiPeripheral_ParseBasicSenseInfo()

```c
int32_t OH_ScsiPeripheral_ParseBasicSenseInfo(uint8_t *senseData, uint8_t senseDataLen, ScsiPeripheral_BasicSenseInfo *senseInfo)
```

**描述**

解析基本的Sense Data，包括Information、Command specific information、Sense key specific字段。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *senseData | 待解析的Sense Data。 |
| uint8_t senseDataLen | Sense Data长度，即senseData参数指向的数据长度，单位：字节。 |
| [ScsiPeripheral_BasicSenseInfo](capi-scsiperipheralddk-scsiperipheral-basicsenseinfo.md) *senseInfo | 用于保存解析后的基本信息，详情参见[ScsiPeripheral_BasicSenseInfo](capi-scsiperipheralddk-scsiperipheral-basicsenseinfo.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) 调用接口成功。<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode) senseData格式不是描述符或固定格式、senseDataLen小于<br>         [SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE](capi-scsi-peripheral-types-h.md#scsiperipheral_min_descriptor_format_sense)或者senseDataLen小于[SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE](capi-scsi-peripheral-types-h.md#scsiperipheral_min_fixed_format_sense)。 |


