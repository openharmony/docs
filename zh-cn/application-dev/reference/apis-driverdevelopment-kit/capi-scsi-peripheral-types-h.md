# scsi_peripheral_types.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

提供在SCSI Peripheral DDK（驱动开发工具包）API中使用的枚举变量、结构体和宏。

**引用文件：** <scsi_peripheral/scsi_peripheral_types.h>

**库：** libscsi.z.so

**系统能力：** SystemCapability.Driver.SCSI.Extension

**起始版本：** 18

**相关模块：** [ScsiPeripheralDDK](capi-scsiperipheralddk.md)

## 汇总

### 结构体

| 名称                                                                                   | typedef关键字 | 描述 |
|--------------------------------------------------------------------------------------| -- | -- |
| [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md) | ScsiPeripheral_DeviceMemMap | 通过调用[OH_ScsiPeripheral_CreateDeviceMemMap](capi-scsi-peripheral-api-h.md#oh_scsiperipheral_createdevicememmap)创建的设备内存映射。使用该设备内存映射的缓冲区可以提供更好的性能。 |
| [ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md)       | ScsiPeripheral_IORequest | 读/写操作的请求参数。该结构体定义了SCSI外设进行读/写操作时所需的请求参数，包括逻辑块起始地址、传输长度、控制信息等。 |
| [ScsiPeripheral_Request](capi-scsiperipheralddk-scsiperipheral-request.md)           | ScsiPeripheral_Request | SCSI请求参数结构体，用于构造与SCSI设备交互的请求参数，支持配置命令描述符块、数据缓冲区、超时时间等。 |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)         | ScsiPeripheral_Response | SCSI响应参数结构体，包含状态、错误诊断数据、传输结果等，用于接收SCSI设备响应数据、判断命令是否成功。 |
| [ScsiPeripheral_TestUnitReadyRequest](capi-scsiperipheralddk-scsiperipheral-testunitreadyrequest.md) | ScsiPeripheral_TestUnitReadyRequest | SCSI命令（TEST UNIT READY）的请求结构体，通常用于确认逻辑单元是否就绪（逻辑单元是SCSI设备中可独立寻址的I/O操作实体）。 |
| [ScsiPeripheral_InquiryRequest](capi-scsiperipheralddk-scsiperipheral-inquiryrequest.md)            | ScsiPeripheral_InquiryRequest | SCSI命令（INQUIRY）的请求结构体，通常用于查询设备的基本信息。 |
| [ScsiPeripheral_InquiryInfo](capi-scsiperipheralddk-scsiperipheral-inquiryinfo.md)                  | ScsiPeripheral_InquiryInfo | SCSI INQUIRY 数据，用于存储SCSI外设的INQUIRY命令查询结果。 |
| [ScsiPeripheral_ReadCapacityRequest](capi-scsiperipheralddk-scsiperipheral-readcapacityrequest.md)  | ScsiPeripheral_ReadCapacityRequest | SCSI命令（READ CAPACITY）的请求结构体，用于发送读取存储容量的命令，可帮助获取设备的逻辑块大小和总块数。 |
| [ScsiPeripheral_CapacityInfo](capi-scsiperipheralddk-scsiperipheral-capacityinfo.md)                | ScsiPeripheral_CapacityInfo | SCSI READ CAPACITY结构体。用于在开发SCSI设备驱动时获取设备的存储容量信息，支持进行分区管理、可用空间检查和存储资源分配等操作。 |
| [ScsiPeripheral_RequestSenseRequest](capi-scsiperipheralddk-scsiperipheral-requestsenserequest.md)  | ScsiPeripheral_RequestSenseRequest | SCSI命令（REQUEST SENSE）的请求结构体，该命令通常用于获取设备的错误信息。 |
| [ScsiPeripheral_BasicSenseInfo](capi-scsiperipheralddk-scsiperipheral-basicsenseinfo.md)            | ScsiPeripheral_BasicSenseInfo | SCSI Sense Data的基本信息结构体，用于封装SCSI命令执行后返回的sense数据。该结构体包含响应码、状态标志位以及各类信息字段，用于驱动程序获取和分析SCSI设备的错误状态和命令执行结果。 |
| [ScsiPeripheral_VerifyRequest](capi-scsiperipheralddk-scsiperipheral-verifyrequest.md)              | ScsiPeripheral_VerifyRequest | SCSI命令（VERIFY）的请求结构体，该命令通常用于校验逻辑块的数据完整性。 |
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)                            | ScsiPeripheral_Device | 不透明的SCSI设备结构体，用于表示与SCSI外设交互的设备句柄。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ScsiPeripheral_DdkErrCode](#scsiperipheral_ddkerrcode) | ScsiPeripheral_DdkErrCode | SCSI Peripheral DDK错误码。 |
| [ScsiPeripheral_Status](#scsiperipheral_status) | ScsiPeripheral_Status | 定义用于响应的SCSI状态。 |

## 枚举类型说明

### ScsiPeripheral_DdkErrCode

```c
enum ScsiPeripheral_DdkErrCode
```

**描述**

SCSI Peripheral DDK错误码。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| SCSIPERIPHERAL_DDK_NO_PERM = 201 | 没有权限。请确保应用已正确声明所需的权限。 |
| SCSIPERIPHERAL_DDK_INVALID_PARAMETER = 401 | 非法参数。请检查参数是否符合要求。 |
| SCSIPERIPHERAL_DDK_SUCCESS = 31700000 | 操作成功。 |
| SCSIPERIPHERAL_DDK_MEMORY_ERROR = 31700001 | 与内存相关的错误，例如，内存不足、内存数据复制失败或内存申请失败。请检查内存状态和相关参数。 |
| SCSIPERIPHERAL_DDK_INVALID_OPERATION = 31700002 | 非法操作。请检查操作逻辑是否正确。 |
| SCSIPERIPHERAL_DDK_IO_ERROR = 31700003 | 设备输入/输出操作失败。请检查传输参数和设备规格。 |
| SCSIPERIPHERAL_DDK_TIMEOUT = 31700004 | 传输超时。请检查超时参数和设备状态。 |
| SCSIPERIPHERAL_DDK_INIT_ERROR = 31700005 | DDK初始化错误，或者DDK未初始化。请先初始化DDK服务。 |
| SCSIPERIPHERAL_DDK_SERVICE_ERROR = 31700006 | 与SCSI Peripheral DDK服务的通信失败。请检查DDK服务是否正常运行。 |
| SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND = 31700007 | 设备未找到。请确保传入的设备信息正确。 |

### ScsiPeripheral_Status

```c
enum ScsiPeripheral_Status
```

**描述**

定义用于响应的SCSI状态。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| SCSIPERIPHERAL_STATUS_GOOD = 0x00 | 正常状态。 |
| SCSIPERIPHERAL_STATUS_CHECK_CONDITION_NEEDED = 0x02 | 需要状态检查。 |
| SCSIPERIPHERAL_STATUS_CONDITION_MET = 0x04 | 条件满足。 |
| SCSIPERIPHERAL_STATUS_BUSY = 0x08 | 占用中。 |
| SCSIPERIPHERAL_STATUS_RESERVATION_CONFLICT = 0x18 | 资源保留冲突。 |
| SCSIPERIPHERAL_STATUS_TASK_SET_FULL = 0x28 | 任务集已满。 |
| SCSIPERIPHERAL_STATUS_ACA_ACTIVE = 0x30 | ACA活动状态。 |
| SCSIPERIPHERAL_STATUS_TASK_ABORTED = 0x40 | 任务已中止。 |

### SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE

```c
SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE 8
```

**描述**

描述符格式感知数据的最小长度。

**起始版本：** 18

### SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE

```c
SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE 18
```

**描述**

固定格式感知数据的最小长度。

**起始版本：** 18

### SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN

```c
SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN 16
```

**描述**

命令描述符块的最大长度。

**起始版本：** 18

### SCSIPERIPHERAL_MAX_SENSE_DATA_LEN

```c
SCSIPERIPHERAL_MAX_SENSE_DATA_LEN 252
```

**描述**

感知数据的最大长度。

**起始版本：** 18

### SCSIPERIPHERAL_VENDOR_ID_LEN

```c
SCSIPERIPHERAL_VENDOR_ID_LEN 8
```

**描述**

厂商标识符的长度。

**起始版本：** 18

### SCSIPERIPHERAL_PRODUCT_ID_LEN

```c
SCSIPERIPHERAL_PRODUCT_ID_LEN 16
```

**描述**

产品标识符的长度。

**起始版本：** 18

### SCSIPERIPHERAL_PRODUCT_REV_LEN

```c
SCSIPERIPHERAL_PRODUCT_REV_LEN 4
```

**描述**

产品修订版本号的长度。

**起始版本：** 18
