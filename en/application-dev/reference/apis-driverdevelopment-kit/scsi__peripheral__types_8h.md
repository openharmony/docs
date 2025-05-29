# scsi_peripheral_types.h


## Overview

Provides the enum variables, structures, and macros used in the SCSI Peripheral DDK APIs.

**File to include**: &lt;scsi_peripheral/scsi_peripheral_types.h&gt;

**Library**: libscsi.z.so

**System capability**: SystemCapability.Driver.SCSI.Extension

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) | Device memory mapping created by calling [OH_ScsiPeripheral_CreateDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_createdevicememmap). The buffer that uses the device memory mapping can provide better performance.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) | Read/write operation request.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_Request](_scsi_peripheral___request.md) | Request structure.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_Response](_scsi_peripheral___response.md) | Response structure.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) | Request structure of the **test unit ready** command.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) | Request structure of the **inquiry** command.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) | SCSI inquiry data.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) | Request structure of the **read capacity** command.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) | SCSI read capacity.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) | Request structure of the **request sense** command.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) | Basic information about the sense data.| 
| struct&nbsp;&nbsp;[ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) | Request structure of the **verify** command.| 


### Macros

| Name| Description| 
| -------- | -------- |
| [SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE](_s_c_s_i.md#scsiperipheral_min_descriptor_format_sense)&nbsp;&nbsp;&nbsp;8 | Minimum length of the sense data descriptor format.| 
| [SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE](_s_c_s_i.md#scsiperipheral_min_fixed_format_sense)&nbsp;&nbsp;&nbsp;18 | Minimum length of the fixed format of sense data.| 
| [SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN](_s_c_s_i.md#scsiperipheral_max_cmd_desc_block_len)&nbsp;&nbsp;&nbsp;16 | Maximum length of a command descriptor block (CDB).| 
| [SCSIPERIPHERAL_MAX_SENSE_DATA_LEN](_s_c_s_i.md#scsiperipheral_max_sense_data_len)&nbsp;&nbsp;&nbsp;252 | Maximum length of sense data. In the SCSI protocol, the maximum length of sense data is usually 252 bytes.| 
| [SCSIPERIPHERAL_VENDOR_ID_LEN](_s_c_s_i.md#scsiperipheral_vendor_id_len)&nbsp;&nbsp;&nbsp;8 | Maximum length of the vendor ID.| 
| [SCSIPERIPHERAL_PRODUCT_ID_LEN](_s_c_s_i.md#scsiperipheral_product_id_len)&nbsp;&nbsp;&nbsp;18 | Maximum length of the product ID.| 
| [SCSIPERIPHERAL_PRODUCT_REV_LEN](_s_c_s_i.md#scsiperipheral_product_rev_len)&nbsp;&nbsp;&nbsp;4 | Maximum length of the product version.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) [ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) | Opaque SCSI device structure.| 
| typedef struct [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) [ScsiPeripheral_DeviceMemMap](_s_c_s_i.md#scsiperipheral_devicememmap) | Device memory mapping created by calling [OH_ScsiPeripheral_CreateDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_createdevicememmap). The buffer that uses the device memory mapping can provide better performance.| 
| typedef struct [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) [ScsiPeripheral_IORequest](_s_c_s_i.md#scsiperipheral_iorequest) | Read/write operation request.| 
| typedef struct [ScsiPeripheral_Request](_scsi_peripheral___request.md) [ScsiPeripheral_Request](_s_c_s_i.md#scsiperipheral_request) | Request structure.| 
| typedef struct [ScsiPeripheral_Response](_scsi_peripheral___response.md) [ScsiPeripheral_Response](_s_c_s_i.md#scsiperipheral_response) | Response structure.| 
| typedef struct [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) [ScsiPeripheral_TestUnitReadyRequest](_s_c_s_i.md#scsiperipheral_testunitreadyrequest) | Request structure of the **test unit ready** command.| 
| typedef struct [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) [ScsiPeripheral_InquiryRequest](_s_c_s_i.md#scsiperipheral_inquiryrequest) | Request structure of the **inquiry** command.| 
| typedef struct [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) [ScsiPeripheral_InquiryInfo](_s_c_s_i.md#scsiperipheral_inquiryinfo) | SCSI inquiry data.| 
| typedef struct [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) [ScsiPeripheral_ReadCapacityRequest](_s_c_s_i.md#scsiperipheral_readcapacityrequest) | Request structure of the **read capacity** command.| 
| typedef struct [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) [ScsiPeripheral_CapacityInfo](_s_c_s_i.md#scsiperipheral_capacityinfo) | SCSI read capacity.| 
| typedef struct [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) [ScsiPeripheral_RequestSenseRequest](_s_c_s_i.md#scsiperipheral_requestsenserequest) | Request structure of the **request sense** command.| 
| typedef struct [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) [ScsiPeripheral_BasicSenseInfo](_s_c_s_i.md#scsiperipheral_basicsenseinfo) | Basic information about the sense data.| 
| typedef struct [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) [ScsiPeripheral_VerifyRequest](_s_c_s_i.md#scsiperipheral_verifyrequest) | Request structure of the **verify** command.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ScsiPeripheral_DdkErrCode](_s_c_s_i.md#scsiperipheral_ddkerrcode) {<br>SCSIPERIPHERAL_DDK_NO_PERM = 201, SCSIPERIPHERAL_DDK_INVALID_PARAMETER = 401, SCSIPERIPHERAL_DDK_SUCCESS = 31700000, SCSIPERIPHERAL_DDK_MEMORY_ERROR = 31700001, SCSIPERIPHERAL_DDK_INVALID_OPERATION = 31700002, SCSIPERIPHERAL_DDK_IO_ERROR = 31700003, SCSIPERIPHERAL_DDK_TIMEOUT = 31700004, SCSIPERIPHERAL_DDK_INIT_ERROR = 31700005, SCSIPERIPHERAL_DDK_SERVICE_ERROR = 31700006, SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND = 31700007<br>} | SCSI Peripheral DDK error codes.| 
| [ScsiPeripheral_Status](_s_c_s_i.md#scsiperipheral_status) {<br>SCSIPERIPHERAL_STATUS_GOOD = 0x00, SCSIPERIPHERAL_STATUS_CHECK_CONDITION_NEEDED = 0x02, SCSIPERIPHERAL_STATUS_CONDITION_MET = 0x04, SCSIPERIPHERAL_STATUS_BUSY = 0x08, SCSIPERIPHERAL_STATUS_RESERVATION_CONFLICT = 0x18, SCSIPERIPHERAL_STATUS_TASK_SET_FULL = 0x28, SCSIPERIPHERAL_STATUS_ACA_ACTIVE = 0x30, SCSIPERIPHERAL_STATUS_TASK_ABORTED = 0x40<br>} | SCSI status used for the response.| 
