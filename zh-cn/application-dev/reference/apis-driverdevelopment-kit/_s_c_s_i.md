# SCSI Peripheral DDK


## 概述

SCSI Peripheral DDK是为开发者提供专门用于开发SCSI设备驱动程序的套件， 提供了初始化DDK、释放DDK、打开关闭设备、读写设备等接口，并声明了SCSI Peripheral DDK API所需的宏、枚举变量和数据结构，用于在应用层进行SCSI设备驱动的开发。

**系统能力**：SystemCapability.Driver.SCSI.Extension

**起始版本：** 18


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [scsi_peripheral_api.h](scsi__peripheral__api_8h.md) | 声明用于主机侧访问SCSI设备的SCSI Peripheral DDK接口。 | 
| [scsi_peripheral_types.h](scsi__peripheral__types_8h.md) | 提供在SCSI Peripheral DDK（驱动开发工具包）API中使用的枚举变量、结构体和宏。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) | 通过调用OH_ScsiPeripheral_CreateDeviceMemMap创建的设备内存映射。 使用该设备内存映射的缓冲区可以提供更好的性能。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) | 读/写操作的请求参数。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_Request](_scsi_peripheral___request.md) | 请求参数结构体。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_Response](_scsi_peripheral___response.md) | 响应参数结构体。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) | 命令（test unit ready）的请求结构体。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) | SCSI命令（inquiry）的请求结构体。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) | SCSI inquiry 数据。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) | SCSI命令（read capacity）的请求结构体。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) | SCSI read capacity 数据。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) | SCSI命令（request sense）的请求结构体。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) | sense data的基本信息。 | 
| struct&nbsp;&nbsp;[ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) | SCSI命令（verify）的请求结构体。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE](#scsiperipheral_min_descriptor_format_sense)&nbsp;&nbsp;&nbsp;8 | sense data描述符格式长度最小值。 | 
| [SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE](#scsiperipheral_min_fixed_format_sense)&nbsp;&nbsp;&nbsp;18 | sense data固定格式长度最小值。 | 
| [SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN](#scsiperipheral_max_cmd_desc_block_len)&nbsp;&nbsp;&nbsp;16 | 命令描述符块的最大长度。 | 
| [SCSIPERIPHERAL_MAX_SENSE_DATA_LEN](#scsiperipheral_max_sense_data_len)&nbsp;&nbsp;&nbsp;252 | 在SCSI协议中，Sense Data（感应数据）的最大长度通常为252字节。 | 
| [SCSIPERIPHERAL_VENDOR_ID_LEN](#scsiperipheral_vendor_id_len)&nbsp;&nbsp;&nbsp;8 | vendor id的最大长度。 | 
| [SCSIPERIPHERAL_PRODUCT_ID_LEN](#scsiperipheral_product_id_len)&nbsp;&nbsp;&nbsp;18 | product id的最大长度。 | 
| [SCSIPERIPHERAL_PRODUCT_REV_LEN](#scsiperipheral_product_rev_len)&nbsp;&nbsp;&nbsp;4 | 产品版本的最大长度。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ScsiPeripheral_Device](#scsiperipheral_device) [ScsiPeripheral_Device](#scsiperipheral_device) | 不透明的SCSI设备结构体。 | 
| typedef struct [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) [ScsiPeripheral_DeviceMemMap](#scsiperipheral_devicememmap) | 通过调用OH_ScsiPeripheral_CreateDeviceMemMap创建的设备内存映射。 使用该设备内存映射的缓冲区可以提供更好的性能。 | 
| typedef struct [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) [ScsiPeripheral_IORequest](#scsiperipheral_iorequest) | 读/写操作的请求参数。 | 
| typedef struct [ScsiPeripheral_Request](_scsi_peripheral___request.md) [ScsiPeripheral_Request](#scsiperipheral_request) | 请求参数结构体。 | 
| typedef struct [ScsiPeripheral_Response](_scsi_peripheral___response.md) [ScsiPeripheral_Response](#scsiperipheral_response) | 响应参数结构体。 | 
| typedef struct [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) [ScsiPeripheral_TestUnitReadyRequest](#scsiperipheral_testunitreadyrequest) | 命令（test unit ready）的请求结构体。 | 
| typedef struct [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) [ScsiPeripheral_InquiryRequest](#scsiperipheral_inquiryrequest) | SCSI命令（inquiry）的请求结构体。 | 
| typedef struct [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) [ScsiPeripheral_InquiryInfo](#scsiperipheral_inquiryinfo) | SCSI inquiry 数据。 | 
| typedef struct [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) [ScsiPeripheral_ReadCapacityRequest](#scsiperipheral_readcapacityrequest) | SCSI命令（read capacity）的请求结构体。 | 
| typedef struct [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) [ScsiPeripheral_CapacityInfo](#scsiperipheral_capacityinfo) | SCSI read capacity 数据。 | 
| typedef struct [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) [ScsiPeripheral_RequestSenseRequest](#scsiperipheral_requestsenserequest) | SCSI命令（request sense）的请求结构体。 | 
| typedef struct [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) [ScsiPeripheral_BasicSenseInfo](#scsiperipheral_basicsenseinfo) | sense data的基本信息。 | 
| typedef struct [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) [ScsiPeripheral_VerifyRequest](#scsiperipheral_verifyrequest) | SCSI命令（verify）的请求结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ScsiPeripheral_DdkErrCode](#scsiperipheral_ddkerrcode) {<br/>SCSIPERIPHERAL_DDK_NO_PERM = 201, SCSIPERIPHERAL_DDK_INVALID_PARAMETER = 401, SCSIPERIPHERAL_DDK_SUCCESS = 31700000, SCSIPERIPHERAL_DDK_MEMORY_ERROR = 31700001, SCSIPERIPHERAL_DDK_INVALID_OPERATION = 31700002, SCSIPERIPHERAL_DDK_IO_ERROR = 31700003, SCSIPERIPHERAL_DDK_TIMEOUT = 31700004, SCSIPERIPHERAL_DDK_INIT_ERROR = 31700005, SCSIPERIPHERAL_DDK_SERVICE_ERROR = 31700006, SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND = 31700007<br/>} | SCSI Peripheral DDK错误码。 | 
| [ScsiPeripheral_Status](#scsiperipheral_status) {<br/>SCSIPERIPHERAL_STATUS_GOOD = 0x00, SCSIPERIPHERAL_STATUS_CHECK_CONDITION_NEEDED = 0x02, SCSIPERIPHERAL_STATUS_CONDITION_MET = 0x04, SCSIPERIPHERAL_STATUS_BUSY = 0x08, SCSIPERIPHERAL_STATUS_RESERVATION_CONFLICT = 0x18, SCSIPERIPHERAL_STATUS_TASK_SET_FULL = 0x28, SCSIPERIPHERAL_STATUS_ACA_ACTIVE = 0x30, SCSIPERIPHERAL_STATUS_TASK_ABORTED = 0x40<br/>} | 定义用于响应的SCSI状态。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ScsiPeripheral_Init](#oh_scsiperipheral_init) (void) | 初始化SCSI Peripheral DDK。 | 
| int32_t [OH_ScsiPeripheral_Release](#oh_scsiperipheral_release) (void) | 释放SCSI Peripheral DDK。 | 
| int32_t [OH_ScsiPeripheral_Open](#oh_scsiperipheral_open) (uint64_t deviceId, uint8_t interfaceIndex, [ScsiPeripheral_Device](#scsiperipheral_device) \*\*dev) | 打开deviceId和interfaceIndex指定的SCSI设备。 | 
| int32_t [OH_ScsiPeripheral_Close](#oh_scsiperipheral_close) ([ScsiPeripheral_Device](#scsiperipheral_device) \*\*dev) | 关闭SCSI设备。 | 
| int32_t [OH_ScsiPeripheral_TestUnitReady](#oh_scsiperipheral_testunitready) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 检查逻辑单元是否已经准备好。 | 
| int32_t [OH_ScsiPeripheral_Inquiry](#oh_scsiperipheral_inquiry) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) \*request, [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) \*inquiryInfo, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 查询SCSI设备的基本信息。 | 
| int32_t [OH_ScsiPeripheral_ReadCapacity10](#oh_scsiperipheral_readcapacity10) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) \*request, [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) \*capacityInfo, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 获取SCSI设备的容量信息。 | 
| int32_t [OH_ScsiPeripheral_RequestSense](#oh_scsiperipheral_requestsense) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 获取sense data（SCSI设备返回给主机的信息，用于报告设备的状态、错误信息以及诊断信息）。 | 
| int32_t [OH_ScsiPeripheral_Read10](#oh_scsiperipheral_read10) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 从指定逻辑块读取数据。 | 
| int32_t [OH_ScsiPeripheral_Write10](#oh_scsiperipheral_write10) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 写数据到设备的指定逻辑块。 | 
| int32_t [OH_ScsiPeripheral_Verify10](#oh_scsiperipheral_verify10) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 校验指定逻辑块。 | 
| int32_t [OH_ScsiPeripheral_SendRequestByCdb](#oh_scsiperipheral_sendrequestbycdb) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_Request](_scsi_peripheral___request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 以CDB（Command Descriptor Block）方式发送SCSI命令。 | 
| int32_t [OH_ScsiPeripheral_CreateDeviceMemMap](#oh_scsiperipheral_createdevicememmap) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, size_t size, [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \*\*devMmap) | 创建缓冲区。请在缓冲区使用完后，调用[OH_ScsiPeripheral_DestroyDeviceMemMap](#oh_scsiperipheral_destroydevicememmap)销毁缓冲区，否则会造成资源泄露。 | 
| int32_t [OH_ScsiPeripheral_DestroyDeviceMemMap](#oh_scsiperipheral_destroydevicememmap) ([ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \*devMmap) | 销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。 | 
| int32_t [OH_ScsiPeripheral_ParseBasicSenseInfo](#oh_scsiperipheral_parsebasicsenseinfo) (uint8_t \*senseData, uint8_t senseDataLen, [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) \*senseInfo) | 解析基本的sense data，包括Information、Command specific information、Sense key specific字段。 | 


## 宏定义说明


### SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN

```
#define SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN   16
```

**描述**

命令描述符块的最大长度。

**起始版本：** 18


### SCSIPERIPHERAL_MAX_SENSE_DATA_LEN

```
#define SCSIPERIPHERAL_MAX_SENSE_DATA_LEN   252
```

**描述**

在SCSI协议中，Sense Data（感应数据）的最大长度通常为252字节。

**起始版本：** 18


### SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE

```
#define SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE   8
```

**描述**

sense data描述符格式长度最小值。

**起始版本：** 18


### SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE

```
#define SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE   18
```

**描述**

sense data固定格式长度最小值。

**起始版本：** 18


### SCSIPERIPHERAL_PRODUCT_ID_LEN

```
#define SCSIPERIPHERAL_PRODUCT_ID_LEN   18
```

**描述**

product id的最大长度。

**起始版本：** 18


### SCSIPERIPHERAL_PRODUCT_REV_LEN

```
#define SCSIPERIPHERAL_PRODUCT_REV_LEN   4
```

**描述**

产品版本的最大长度。

**起始版本：** 18


### SCSIPERIPHERAL_VENDOR_ID_LEN

```
#define SCSIPERIPHERAL_VENDOR_ID_LEN   8
```

**描述**

vendor id的最大长度。

**起始版本：** 18


## 类型定义说明


### ScsiPeripheral_BasicSenseInfo

```
typedef struct ScsiPeripheral_BasicSenseInfo ScsiPeripheral_BasicSenseInfo
```

**描述**

sense data的基本信息。

**起始版本：** 18


### ScsiPeripheral_CapacityInfo

```
typedef struct ScsiPeripheral_CapacityInfo ScsiPeripheral_CapacityInfo
```

**描述**

SCSI read capacity 数据。

**起始版本：** 18


### ScsiPeripheral_Device

```
typedef struct ScsiPeripheral_Device ScsiPeripheral_Device
```

**描述**

不透明的SCSI设备结构体。

**起始版本：** 18


### ScsiPeripheral_DeviceMemMap

```
typedef struct ScsiPeripheral_DeviceMemMap ScsiPeripheral_DeviceMemMap
```

**描述**

通过调用OH_ScsiPeripheral_CreateDeviceMemMap创建的设备内存映射。 使用该设备内存映射的缓冲区可以提供更好的性能。

**起始版本：** 18


### ScsiPeripheral_InquiryInfo

```
typedef struct ScsiPeripheral_InquiryInfo ScsiPeripheral_InquiryInfo
```

**描述**

SCSI inquiry 数据。

**起始版本：** 18


### ScsiPeripheral_InquiryRequest

```
typedef struct ScsiPeripheral_InquiryRequest ScsiPeripheral_InquiryRequest
```

**描述**

SCSI命令（inquiry）的请求结构体。

**起始版本：** 18


### ScsiPeripheral_IORequest

```
typedef struct ScsiPeripheral_IORequest ScsiPeripheral_IORequest
```

**描述**

读/写操作的请求参数。

**起始版本：** 18


### ScsiPeripheral_ReadCapacityRequest

```
typedef struct ScsiPeripheral_ReadCapacityRequest ScsiPeripheral_ReadCapacityRequest
```

**描述**

SCSI命令（read capacity）的请求结构体。

**起始版本：** 18


### ScsiPeripheral_Request

```
typedef struct ScsiPeripheral_Request ScsiPeripheral_Request
```

**描述**

请求参数结构体。

**起始版本：** 18


### ScsiPeripheral_RequestSenseRequest

```
typedef struct ScsiPeripheral_RequestSenseRequest ScsiPeripheral_RequestSenseRequest
```

**描述**

SCSI命令（request sense）的请求结构体。

**起始版本：** 18


### ScsiPeripheral_Response

```
typedef struct ScsiPeripheral_Response ScsiPeripheral_Response
```

**描述**

响应参数结构体。

**起始版本：** 18


### ScsiPeripheral_TestUnitReadyRequest

```
typedef struct ScsiPeripheral_TestUnitReadyRequest ScsiPeripheral_TestUnitReadyRequest
```

**描述**

命令（test unit ready）的请求结构体。

**起始版本：** 18


### ScsiPeripheral_VerifyRequest

```
typedef struct ScsiPeripheral_VerifyRequest ScsiPeripheral_VerifyRequest
```

**描述**

SCSI命令（verify）的请求结构体。

**起始版本：** 18


## 枚举类型说明


### ScsiPeripheral_DdkErrCode

```
enum ScsiPeripheral_DdkErrCode
```

**描述**

SCSI Peripheral DDK错误码。

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| SCSIPERIPHERAL_DDK_NO_PERM | 没有权限。 | 
| SCSIPERIPHERAL_DDK_INVALID_PARAMETER | 非法参数。 | 
| SCSIPERIPHERAL_DDK_SUCCESS | 操作成功。 | 
| SCSIPERIPHERAL_DDK_MEMORY_ERROR | 与内存相关的错误，例如，内存不足、内存数据复制失败或内存申请失败。 | 
| SCSIPERIPHERAL_DDK_INVALID_OPERATION | 非法操作。 | 
| SCSIPERIPHERAL_DDK_IO_ERROR | 设备输入/输出操作失败。 | 
| SCSIPERIPHERAL_DDK_TIMEOUT | 传输超时。 | 
| SCSIPERIPHERAL_DDK_INIT_ERROR | DDK初始化错误，或者DDK未初始化。 | 
| SCSIPERIPHERAL_DDK_SERVICE_ERROR | 与SCSI Peripheral DDK服务的通信失败。 | 
| SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND | 设备未找到。 | 


### ScsiPeripheral_Status

```
enum ScsiPeripheral_Status
```

**描述**

定义用于响应的SCSI状态。

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| SCSIPERIPHERAL_STATUS_GOOD | 正常状态。 | 
| SCSIPERIPHERAL_STATUS_CHECK_CONDITION_NEEDED | 需要状态检查。 | 
| SCSIPERIPHERAL_STATUS_CONDITION_MET | 条件满足。 | 
| SCSIPERIPHERAL_STATUS_BUSY | 占用中。 | 
| SCSIPERIPHERAL_STATUS_RESERVATION_CONFLICT | 资源保留冲突。 | 
| SCSIPERIPHERAL_STATUS_TASK_SET_FULL | 任务集已满。 | 
| SCSIPERIPHERAL_STATUS_ACA_ACTIVE | ACA活动状态。 | 
| SCSIPERIPHERAL_STATUS_TASK_ABORTED | 任务已终止。 | 


## 函数说明


### OH_ScsiPeripheral_Close()

```
int32_t OH_ScsiPeripheral_Close (ScsiPeripheral_Device ** dev)
```

**描述**

关闭SCSI设备。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。


### OH_ScsiPeripheral_CreateDeviceMemMap()

```
int32_t OH_ScsiPeripheral_CreateDeviceMemMap (ScsiPeripheral_Device * dev, size_t size, ScsiPeripheral_DeviceMemMap ** devMmap )
```

**描述**

创建缓冲区。请在缓冲区使用完后，调用[OH_ScsiPeripheral_DestroyDeviceMemMap](#oh_scsiperipheral_destroydevicememmap)销毁缓冲区，否则会造成资源泄露。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| size | 缓冲区的大小。 | 
| devMmap | 创建的缓冲区通过该参数返回给调用者，详情参见[ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空或devMmap为空。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。


### OH_ScsiPeripheral_DestroyDeviceMemMap()

```
int32_t OH_ScsiPeripheral_DestroyDeviceMemMap (ScsiPeripheral_DeviceMemMap * devMmap)
```

**描述**

销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devMmap | 待销毁的由**OH_ScsiPeripheral_CreateDeviceMemMa**创建的缓冲区，详情参见[ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER devMmap为空。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。


### OH_ScsiPeripheral_Init()

```
int32_t OH_ScsiPeripheral_Init (void )
```

**描述**

初始化SCSI Peripheral DDK。

**起始版本：** 18

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 初始化DDK失败。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。


### OH_ScsiPeripheral_Inquiry()

```
int32_t OH_ScsiPeripheral_Inquiry (ScsiPeripheral_Device * dev, ScsiPeripheral_InquiryRequest * request, ScsiPeripheral_InquiryInfo * inquiryInfo, ScsiPeripheral_Response * response )
```

**描述**

查询SCSI设备的基本信息。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| request | inquiry命令的请求信息，详情参见[ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md)。 | 
| inquiryInfo | inquiry命令返回的查询信息，详情参见[ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md)。 | 
| response | inquiry命令返回的原始响应信息，详情参见[ScsiPeripheral_Response](_scsi_peripheral___response.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空、 request为空、inquiryInfo 为空、inquiryInfo-&gt;data或者response为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。


### OH_ScsiPeripheral_Open()

```
int32_t OH_ScsiPeripheral_Open (uint64_t deviceId, uint8_t interfaceIndex, ScsiPeripheral_Device ** dev )
```

**描述**

打开deviceId和interfaceIndex指定的SCSI设备。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceId | 设备ID，代表要操作的设备。 | 
| interfaceIndex | 接口索引，对应SCSI设备的接口。 | 
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生IO错误。

- SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND 通过deviceId和interfaceIndex找不到设备。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

### OH_ScsiPeripheral_ParseBasicSenseInfo()

```
int32_t OH_ScsiPeripheral_ParseBasicSenseInfo (uint8_t * senseData, uint8_t senseDataLen, ScsiPeripheral_BasicSenseInfo * senseInfo )
```

**描述**

解析基本的sense data，包括Information、Command specific information、Sense key specific字段。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| senseData | 待解析的sense data。 | 
| senseDataLen | sense data长度。 | 
| senseInfo | 用于保存解析后的基本信息，详情参见[ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER senseData格式不是描述符或固定格式、senseDataLen小于SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE或者senseDataLen小于SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE。


### OH_ScsiPeripheral_Read10()

```
int32_t OH_ScsiPeripheral_Read10 (ScsiPeripheral_Device * dev, ScsiPeripheral_IORequest * request, ScsiPeripheral_Response * response )
```

**描述**

从指定逻辑块读取数据。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| request | read命令的请求信息，详情参见[ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md)。 | 
| response | read命令返回的响应信息，详情参见[ScsiPeripheral_Response](_scsi_peripheral___response.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空、 request为空、request-&gt;data或者response为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。


### OH_ScsiPeripheral_ReadCapacity10()

```
int32_t OH_ScsiPeripheral_ReadCapacity10 (ScsiPeripheral_Device * dev, ScsiPeripheral_ReadCapacityRequest * request, ScsiPeripheral_CapacityInfo * capacityInfo, ScsiPeripheral_Response * response )
```

**描述**

获取SCSI设备的容量信息。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| request | read capacity命令的请求信息，详情参见[ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md)。 | 
| capacityInfo | read capacity命令返回的容量信息，详情参见[ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md)。 | 
| response | read capacity命令返回的原始响应信息，详情参见[ScsiPeripheral_Response](_scsi_peripheral___response.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空、 request为空、capacityInfo为空或者response为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。


### OH_ScsiPeripheral_Release()

```
int32_t OH_ScsiPeripheral_Release (void )
```

**描述**

释放SCSI Peripheral DDK。

**起始版本：** 18

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。


### OH_ScsiPeripheral_RequestSense()

```
int32_t OH_ScsiPeripheral_RequestSense (ScsiPeripheral_Device * dev, ScsiPeripheral_RequestSenseRequest * request, ScsiPeripheral_Response * response )
```

**描述**

获取sense data（SCSI设备返回给主机的信息，用于报告设备的状态、错误信息以及诊断信息）。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| request | request sense命令的请求信息，详情参见[ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md)。 | 
| response | request sense命令返回的响应信息，详情参见[ScsiPeripheral_Response](_scsi_peripheral___response.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空、 request为空或者response为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。


### OH_ScsiPeripheral_SendRequestByCdb()

```
int32_t OH_ScsiPeripheral_SendRequestByCdb (ScsiPeripheral_Device * dev, ScsiPeripheral_Request * request, ScsiPeripheral_Response * response )
```

**描述**

以CDB（Command Descriptor Block）方式发送SCSI命令。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| request | 请求，详情参见[ScsiPeripheral_Request](_scsi_peripheral___request.md)。 | 
| response | 响应，详情参见[ScsiPeripheral_Response](_scsi_peripheral___response.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空、 request为空、request-&gt;data为空、request-&gt;cdbLength为0或者response为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。


### OH_ScsiPeripheral_TestUnitReady()

```
int32_t OH_ScsiPeripheral_TestUnitReady (ScsiPeripheral_Device * dev, ScsiPeripheral_TestUnitReadyRequest * request, ScsiPeripheral_Response * response )
```

**描述**

检查逻辑单元是否已经准备好。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| request | 逻辑单元检查命令（test unit ready）的请求信息，详情参见[ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md)。 | 
| response | 逻辑单元检查命令（test unit ready）的响应信息，详情参见[ScsiPeripheral_Response](_scsi_peripheral___response.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空、request为空或者response为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。


### OH_ScsiPeripheral_Verify10()

```
int32_t OH_ScsiPeripheral_Verify10 (ScsiPeripheral_Device * dev, ScsiPeripheral_VerifyRequest * request, ScsiPeripheral_Response * response )
```

**描述**

校验指定逻辑块。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| request | verify命令的请求信息，详情参见[ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md)。 | 
| response | verify命令返回的响应信息，详情参见[ScsiPeripheral_Response](_scsi_peripheral___response.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空、request为空或者response为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。


### OH_ScsiPeripheral_Write10()

```
int32_t OH_ScsiPeripheral_Write10 (ScsiPeripheral_Device * dev, ScsiPeripheral_IORequest * request, ScsiPeripheral_Response * response )
```

**描述**

写数据到设备的指定逻辑块。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dev | 设备句柄，详情参见[ScsiPeripheral_Device](#scsiperipheral_device)。 | 
| request | write命令的请求信息，详情参见[ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md)。 | 
| response | write命令返回的响应信息，详情参见[ScsiPeripheral_Response](_scsi_peripheral___response.md)。 | 

**Permission：**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**返回：**

- SCSIPERIPHERAL_DDK_SUCCESS 调用接口成功。

- SCSIPERIPHERAL_DDK_NO_PERM 权限校验失败。

- SCSIPERIPHERAL_DDK_INIT_ERROR 未初始化DDK。

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER dev为空、 request为空、request-&gt;data为空或者response为空。

- SCSIPERIPHERAL_DDK_SERVICE_ERROR 与DDK服务通信失败。

- SCSIPERIPHERAL_DDK_MEMORY_ERROR 内存操作失败。

- SCSIPERIPHERAL_DDK_IO_ERROR DDK发生I/O错误。

- SCSIPERIPHERAL_DDK_TIMEOUT 传输超时。

- SCSIPERIPHERAL_DDK_INVALID_OPERATION 不支持该操作。
