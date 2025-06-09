# scsi_peripheral_types.h


## 概述

提供在SCSI Peripheral DDK（驱动开发工具包）API中使用的枚举变量、结构体和宏。

**引用文件：** &lt;scsi_peripheral/scsi_peripheral_types.h&gt;

**库：** libscsi.z.so

**系统能力：** SystemCapability.Driver.SCSI.Extension

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) | 通过调用[OH_ScsiPeripheral_CreateDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_createdevicememmap)创建的设备内存映射。 使用该设备内存映射的缓冲区可以提供更好的性能。 | 
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
| [SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE](_s_c_s_i.md#scsiperipheral_min_descriptor_format_sense)&nbsp;&nbsp;&nbsp;8 | sense data描述符格式长度最小值。 | 
| [SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE](_s_c_s_i.md#scsiperipheral_min_fixed_format_sense)&nbsp;&nbsp;&nbsp;18 | sense data固定格式长度最小值。 | 
| [SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN](_s_c_s_i.md#scsiperipheral_max_cmd_desc_block_len)&nbsp;&nbsp;&nbsp;16 | 命令描述符块的最大长度。 | 
| [SCSIPERIPHERAL_MAX_SENSE_DATA_LEN](_s_c_s_i.md#scsiperipheral_max_sense_data_len)&nbsp;&nbsp;&nbsp;252 | 在SCSI协议中，Sense Data（感应数据）的最大长度通常为252字节。 | 
| [SCSIPERIPHERAL_VENDOR_ID_LEN](_s_c_s_i.md#scsiperipheral_vendor_id_len)&nbsp;&nbsp;&nbsp;8 | vendor id的最大长度。 | 
| [SCSIPERIPHERAL_PRODUCT_ID_LEN](_s_c_s_i.md#scsiperipheral_product_id_len)&nbsp;&nbsp;&nbsp;18 | product id的最大长度。 | 
| [SCSIPERIPHERAL_PRODUCT_REV_LEN](_s_c_s_i.md#scsiperipheral_product_rev_len)&nbsp;&nbsp;&nbsp;4 | 产品版本的最大长度。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) [ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) | 不透明的SCSI设备结构体。 | 
| typedef struct [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) [ScsiPeripheral_DeviceMemMap](_s_c_s_i.md#scsiperipheral_devicememmap) | 通过调用[OH_ScsiPeripheral_CreateDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_createdevicememmap)创建的设备内存映射。 使用该设备内存映射的缓冲区可以提供更好的性能。 | 
| typedef struct [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) [ScsiPeripheral_IORequest](_s_c_s_i.md#scsiperipheral_iorequest) | 读/写操作的请求参数。 | 
| typedef struct [ScsiPeripheral_Request](_scsi_peripheral___request.md) [ScsiPeripheral_Request](_s_c_s_i.md#scsiperipheral_request) | 请求参数结构体。 | 
| typedef struct [ScsiPeripheral_Response](_scsi_peripheral___response.md) [ScsiPeripheral_Response](_s_c_s_i.md#scsiperipheral_response) | 响应参数结构体。 | 
| typedef struct [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) [ScsiPeripheral_TestUnitReadyRequest](_s_c_s_i.md#scsiperipheral_testunitreadyrequest) | 命令（test unit ready）的请求结构体。 | 
| typedef struct [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) [ScsiPeripheral_InquiryRequest](_s_c_s_i.md#scsiperipheral_inquiryrequest) | SCSI命令（inquiry）的请求结构体。 | 
| typedef struct [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) [ScsiPeripheral_InquiryInfo](_s_c_s_i.md#scsiperipheral_inquiryinfo) | SCSI inquiry 数据。 | 
| typedef struct [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) [ScsiPeripheral_ReadCapacityRequest](_s_c_s_i.md#scsiperipheral_readcapacityrequest) | SCSI命令（read capacity）的请求结构体。 | 
| typedef struct [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) [ScsiPeripheral_CapacityInfo](_s_c_s_i.md#scsiperipheral_capacityinfo) | SCSI read capacity 数据。 | 
| typedef struct [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) [ScsiPeripheral_RequestSenseRequest](_s_c_s_i.md#scsiperipheral_requestsenserequest) | SCSI命令（request sense）的请求结构体。 | 
| typedef struct [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) [ScsiPeripheral_BasicSenseInfo](_s_c_s_i.md#scsiperipheral_basicsenseinfo) | sense data的基本信息。 | 
| typedef struct [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) [ScsiPeripheral_VerifyRequest](_s_c_s_i.md#scsiperipheral_verifyrequest) | SCSI命令（verify）的请求结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ScsiPeripheral_DdkErrCode](_s_c_s_i.md#scsiperipheral_ddkerrcode) {<br/>SCSIPERIPHERAL_DDK_NO_PERM = 201, SCSIPERIPHERAL_DDK_INVALID_PARAMETER = 401, SCSIPERIPHERAL_DDK_SUCCESS = 31700000, SCSIPERIPHERAL_DDK_MEMORY_ERROR = 31700001, SCSIPERIPHERAL_DDK_INVALID_OPERATION = 31700002, SCSIPERIPHERAL_DDK_IO_ERROR = 31700003, SCSIPERIPHERAL_DDK_TIMEOUT = 31700004, SCSIPERIPHERAL_DDK_INIT_ERROR = 31700005, SCSIPERIPHERAL_DDK_SERVICE_ERROR = 31700006, SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND = 31700007<br/>} | SCSI Peripheral DDK错误码。 | 
| [ScsiPeripheral_Status](_s_c_s_i.md#scsiperipheral_status) {<br/>SCSIPERIPHERAL_STATUS_GOOD = 0x00, SCSIPERIPHERAL_STATUS_CHECK_CONDITION_NEEDED = 0x02, SCSIPERIPHERAL_STATUS_CONDITION_MET = 0x04, SCSIPERIPHERAL_STATUS_BUSY = 0x08, SCSIPERIPHERAL_STATUS_RESERVATION_CONFLICT = 0x18, SCSIPERIPHERAL_STATUS_TASK_SET_FULL = 0x28, SCSIPERIPHERAL_STATUS_ACA_ACTIVE = 0x30, SCSIPERIPHERAL_STATUS_TASK_ABORTED = 0x40<br/>} | 定义用于响应的SCSI状态。 | 
