# SCSI Peripheral DDK


## Overview

The SCSI Peripheral DDK is a suite dedicated to SCSI device driver development at the application layer. It provides APIs for initializing the DDK, releasing the DDK, enabling and disabling devices, and reading data from and writing data to devices. It also declares the macros, enum variables, and data structures required by the SCSI Peripheral DDK APIs.

**System capability**: SystemCapability.Driver.SCSI.Extension

**Since**: 18


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [scsi_peripheral_api.h](scsi__peripheral__api_8h.md) | Declares the SCSI Peripheral DDK APIs used by the host to access the SCSI device.| 
| [scsi_peripheral_types.h](scsi__peripheral__types_8h.md) | Provides the enum variables, structures, and macros used in the SCSI Peripheral DDK APIs.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) | Device memory mapping created by calling **OH_ScsiPeripheral_CreateDeviceMemMap**. The buffer that uses the device memory mapping can provide better performance.| 
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
| [SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE](#scsiperipheral_min_descriptor_format_sense)&nbsp;&nbsp;&nbsp;8 | Minimum length of the sense data descriptor format.| 
| [SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE](#scsiperipheral_min_fixed_format_sense)&nbsp;&nbsp;&nbsp;18 | Minimum length of the fixed format of sense data.| 
| [SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN](#scsiperipheral_max_cmd_desc_block_len)&nbsp;&nbsp;&nbsp;16 | Maximum length of a command descriptor block (CDB).| 
| [SCSIPERIPHERAL_MAX_SENSE_DATA_LEN](#scsiperipheral_max_sense_data_len)&nbsp;&nbsp;&nbsp;252 | Maximum length of sense data. In the SCSI protocol, the maximum length of sense data is usually 252 bytes.| 
| [SCSIPERIPHERAL_VENDOR_ID_LEN](#scsiperipheral_vendor_id_len)&nbsp;&nbsp;&nbsp;8 | Maximum length of the vendor ID.| 
| [SCSIPERIPHERAL_PRODUCT_ID_LEN](#scsiperipheral_product_id_len)&nbsp;&nbsp;&nbsp;16 | Maximum length of the product ID.| 
| [SCSIPERIPHERAL_PRODUCT_REV_LEN](#scsiperipheral_product_rev_len)&nbsp;&nbsp;&nbsp;4 | Maximum length of the product version.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [ScsiPeripheral_Device](#scsiperipheral_device) [ScsiPeripheral_Device](#scsiperipheral_device) | Opaque SCSI device structure.| 
| typedef struct [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) [ScsiPeripheral_DeviceMemMap](#scsiperipheral_devicememmap) | Device memory mapping created by calling **OH_ScsiPeripheral_CreateDeviceMemMap**. The buffer that uses the device memory mapping can provide better performance.| 
| typedef struct [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) [ScsiPeripheral_IORequest](#scsiperipheral_iorequest) | Read/write operation request.| 
| typedef struct [ScsiPeripheral_Request](_scsi_peripheral___request.md) [ScsiPeripheral_Request](#scsiperipheral_request) | Request structure.| 
| typedef struct [ScsiPeripheral_Response](_scsi_peripheral___response.md) [ScsiPeripheral_Response](#scsiperipheral_response) | Response structure.| 
| typedef struct [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) [ScsiPeripheral_TestUnitReadyRequest](#scsiperipheral_testunitreadyrequest) | Request structure of the **test unit ready** command.| 
| typedef struct [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) [ScsiPeripheral_InquiryRequest](#scsiperipheral_inquiryrequest) | Request structure of the **inquiry** command.| 
| typedef struct [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) [ScsiPeripheral_InquiryInfo](#scsiperipheral_inquiryinfo) | SCSI inquiry data.| 
| typedef struct [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) [ScsiPeripheral_ReadCapacityRequest](#scsiperipheral_readcapacityrequest) | Request structure of the **read capacity** command.| 
| typedef struct [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) [ScsiPeripheral_CapacityInfo](#scsiperipheral_capacityinfo) | SCSI read capacity.| 
| typedef struct [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) [ScsiPeripheral_RequestSenseRequest](#scsiperipheral_requestsenserequest) | Request structure of the **request sense** command.| 
| typedef struct [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) [ScsiPeripheral_BasicSenseInfo](#scsiperipheral_basicsenseinfo) | Basic information about the sense data.| 
| typedef struct [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) [ScsiPeripheral_VerifyRequest](#scsiperipheral_verifyrequest) | Request structure of the **verify** command.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ScsiPeripheral_DdkErrCode](#scsiperipheral_ddkerrcode) {<br>SCSIPERIPHERAL_DDK_NO_PERM = 201, SCSIPERIPHERAL_DDK_INVALID_PARAMETER = 401, SCSIPERIPHERAL_DDK_SUCCESS = 31700000, SCSIPERIPHERAL_DDK_MEMORY_ERROR = 31700001, SCSIPERIPHERAL_DDK_INVALID_OPERATION = 31700002, SCSIPERIPHERAL_DDK_IO_ERROR = 31700003, SCSIPERIPHERAL_DDK_TIMEOUT = 31700004, SCSIPERIPHERAL_DDK_INIT_ERROR = 31700005, SCSIPERIPHERAL_DDK_SERVICE_ERROR = 31700006, SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND = 31700007<br>} | SCSI Peripheral DDK error codes.| 
| [ScsiPeripheral_Status](#scsiperipheral_status) {<br>SCSIPERIPHERAL_STATUS_GOOD = 0x00, SCSIPERIPHERAL_STATUS_CHECK_CONDITION_NEEDED = 0x02, SCSIPERIPHERAL_STATUS_CONDITION_MET = 0x04, SCSIPERIPHERAL_STATUS_BUSY = 0x08, SCSIPERIPHERAL_STATUS_RESERVATION_CONFLICT = 0x18, SCSIPERIPHERAL_STATUS_TASK_SET_FULL = 0x28, SCSIPERIPHERAL_STATUS_ACA_ACTIVE = 0x30, SCSIPERIPHERAL_STATUS_TASK_ABORTED = 0x40<br>} | SCSI status used for the response.| 


### Function

| Name| Description| 
| -------- | -------- |
| int32_t [OH_ScsiPeripheral_Init](#oh_scsiperipheral_init) (void) | Initializes the SCSI Peripheral DDK.| 
| int32_t [OH_ScsiPeripheral_Release](#oh_scsiperipheral_release) (void) | Releases the SCSI Peripheral DDK.| 
| int32_t [OH_ScsiPeripheral_Open](#oh_scsiperipheral_open) (uint64_t deviceId, uint8_t interfaceIndex, [ScsiPeripheral_Device](#scsiperipheral_device) \*\*dev) | Opens the SCSI device specified by **deviceId** and **interfaceIndex**.| 
| int32_t [OH_ScsiPeripheral_Close](#oh_scsiperipheral_close) ([ScsiPeripheral_Device](#scsiperipheral_device) \*\*dev) | Disables the SCSI device.| 
| int32_t [OH_ScsiPeripheral_TestUnitReady](#oh_scsiperipheral_testunitready) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Checks whether the logical units are ready.| 
| int32_t [OH_ScsiPeripheral_Inquiry](#oh_scsiperipheral_inquiry) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) \*request, [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) \*inquiryInfo, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Queries basic information about the SCSI device.| 
| int32_t [OH_ScsiPeripheral_ReadCapacity10](#oh_scsiperipheral_readcapacity10) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) \*request, [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) \*capacityInfo, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Obtains the capacity information about the SCSI device.| 
| int32_t [OH_ScsiPeripheral_RequestSense](#oh_scsiperipheral_requestsense) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Obtains sense data, that is, information returned by the SCSI device to the host to report the device status, error information, and diagnosis information.| 
| int32_t [OH_ScsiPeripheral_Read10](#oh_scsiperipheral_read10) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Reads data from a specified logical block.| 
| int32_t [OH_ScsiPeripheral_Write10](#oh_scsiperipheral_write10) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Writes data to a specified logical block of a device.| 
| int32_t [OH_ScsiPeripheral_Verify10](#oh_scsiperipheral_verify10) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Verifies a specified logical block.| 
| int32_t [OH_ScsiPeripheral_SendRequestByCdb](#oh_scsiperipheral_sendrequestbycdb) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, [ScsiPeripheral_Request](_scsi_peripheral___request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Sends SCSI commands in CDB mode.| 
| int32_t [OH_ScsiPeripheral_CreateDeviceMemMap](#oh_scsiperipheral_createdevicememmap) ([ScsiPeripheral_Device](#scsiperipheral_device) \*dev, size_t size, [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \*\*devMmap) | Creates a buffer. To avoid memory leakage, use [OH_ScsiPeripheral_DestroyDeviceMemMap](#oh_scsiperipheral_destroydevicememmap) to destroy a buffer after use.| 
| int32_t [OH_ScsiPeripheral_DestroyDeviceMemMap](#oh_scsiperipheral_destroydevicememmap) ([ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \*devMmap) | Destroys a buffer. To avoid resource leakage, destroy a buffer in time after use.| 
| int32_t [OH_ScsiPeripheral_ParseBasicSenseInfo](#oh_scsiperipheral_parsebasicsenseinfo) (uint8_t \*senseData, uint8_t senseDataLen, [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) \*senseInfo) | Parses basic sense data, including the **Information**, **Command specific information**, and **Sense key specific** fields.| 


## Macro Description


### SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN

```
#define SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN   16
```

**Description**

Maximum length of a CDB.

**Since**: 18


### SCSIPERIPHERAL_MAX_SENSE_DATA_LEN

```
#define SCSIPERIPHERAL_MAX_SENSE_DATA_LEN   252
```

**Description**

Maximum length of sense data. In the SCSI protocol, the maximum length of sense data is usually 252 bytes.

**Since**: 18


### SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE

```
#define SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE   8
```

**Description**

Minimum length of the sense data descriptor format.

**Since**: 18


### SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE

```
#define SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE   18
```

**Description**

Minimum length of the fixed format of sense data.

**Since**: 18


### SCSIPERIPHERAL_PRODUCT_ID_LEN

```
#define SCSIPERIPHERAL_PRODUCT_ID_LEN   16
```

**Description**

Maximum length of the product ID.

**Since**: 18


### SCSIPERIPHERAL_PRODUCT_REV_LEN

```
#define SCSIPERIPHERAL_PRODUCT_REV_LEN   4
```

**Description**

Maximum length of the product version.

**Since**: 18


### SCSIPERIPHERAL_VENDOR_ID_LEN

```
#define SCSIPERIPHERAL_VENDOR_ID_LEN   8
```

**Description**

Maximum length of the vendor ID.

**Since**: 18


## Type Description


### ScsiPeripheral_BasicSenseInfo

```
typedef struct ScsiPeripheral_BasicSenseInfo ScsiPeripheral_BasicSenseInfo
```

**Description**

Basic information about the sense data.

**Since**: 18


### ScsiPeripheral_CapacityInfo

```
typedef struct ScsiPeripheral_CapacityInfo ScsiPeripheral_CapacityInfo
```

**Description**

SCSI read capacity.

**Since**: 18


### ScsiPeripheral_Device

```
typedef struct ScsiPeripheral_Device ScsiPeripheral_Device
```

**Description**

Opaque SCSI device structure.

**Since**: 18


### ScsiPeripheral_DeviceMemMap

```
typedef struct ScsiPeripheral_DeviceMemMap ScsiPeripheral_DeviceMemMap
```

**Description**

Device memory mapping created by calling **OH_ScsiPeripheral_CreateDeviceMemMap**. The buffer that uses the device memory mapping can provide better performance.

**Since**: 18


### ScsiPeripheral_InquiryInfo

```
typedef struct ScsiPeripheral_InquiryInfo ScsiPeripheral_InquiryInfo
```

**Description**

SCSI inquiry data.

**Since**: 18


### ScsiPeripheral_InquiryRequest

```
typedef struct ScsiPeripheral_InquiryRequest ScsiPeripheral_InquiryRequest
```

**Description**

Request structure of the **inquiry** command.

**Since**: 18


### ScsiPeripheral_IORequest

```
typedef struct ScsiPeripheral_IORequest ScsiPeripheral_IORequest
```

**Description**

Read/write operation request.

**Since**: 18


### ScsiPeripheral_ReadCapacityRequest

```
typedef struct ScsiPeripheral_ReadCapacityRequest ScsiPeripheral_ReadCapacityRequest
```

**Description**

Request structure of the **read capacity** command.

**Since**: 18


### ScsiPeripheral_Request

```
typedef struct ScsiPeripheral_Request ScsiPeripheral_Request
```

**Description**

Request structure.

**Since**: 18


### ScsiPeripheral_RequestSenseRequest

```
typedef struct ScsiPeripheral_RequestSenseRequest ScsiPeripheral_RequestSenseRequest
```

**Description**

Request structure of the **request sense** command.

**Since**: 18


### ScsiPeripheral_Response

```
typedef struct ScsiPeripheral_Response ScsiPeripheral_Response
```

**Description**

Response structure.

**Since**: 18


### ScsiPeripheral_TestUnitReadyRequest

```
typedef struct ScsiPeripheral_TestUnitReadyRequest ScsiPeripheral_TestUnitReadyRequest
```

**Description**

Request structure of the **test unit ready** command.

**Since**: 18


### ScsiPeripheral_VerifyRequest

```
typedef struct ScsiPeripheral_VerifyRequest ScsiPeripheral_VerifyRequest
```

**Description**

Request structure of the **verify** command.

**Since**: 18


## Enum Description


### ScsiPeripheral_DdkErrCode

```
enum ScsiPeripheral_DdkErrCode
```

**Description**

SCSI Peripheral DDK error codes.

**Since**: 18

| Value| Description| 
| -------- | -------- |
| SCSIPERIPHERAL_DDK_NO_PERM | Permission denied.| 
| SCSIPERIPHERAL_DDK_INVALID_PARAMETER | Invalid parameter.| 
| SCSIPERIPHERAL_DDK_SUCCESS | Operation succeeded.| 
| SCSIPERIPHERAL_DDK_MEMORY_ERROR | Memory-related errors, such as insufficient memory, memory data replication failure, or memory request failure.| 
| SCSIPERIPHERAL_DDK_INVALID_OPERATION | Invalid operation.| 
| SCSIPERIPHERAL_DDK_IO_ERROR | Device input/output operation failure.| 
| SCSIPERIPHERAL_DDK_TIMEOUT | Transfer timeout.| 
| SCSIPERIPHERAL_DDK_INIT_ERROR | DDK initialization error, or DDK uninitialized.| 
| SCSIPERIPHERAL_DDK_SERVICE_ERROR | Failed to communicate with the SCSI Peripheral DDK.| 
| SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND | Device not found.| 


### ScsiPeripheral_Status

```
enum ScsiPeripheral_Status
```

**Description**

SCSI status used for the response.

**Since**: 18

| Value| Description| 
| -------- | -------- |
| SCSIPERIPHERAL_STATUS_GOOD | Normal state.| 
| SCSIPERIPHERAL_STATUS_CHECK_CONDITION_NEEDED | Status check required.| 
| SCSIPERIPHERAL_STATUS_CONDITION_MET | Conditions met.| 
| SCSIPERIPHERAL_STATUS_BUSY | Occupying.| 
| SCSIPERIPHERAL_STATUS_RESERVATION_CONFLICT | Resource reservation conflict.| 
| SCSIPERIPHERAL_STATUS_TASK_SET_FULL | Task set already full.| 
| SCSIPERIPHERAL_STATUS_ACA_ACTIVE | ACA activity status.| 
| SCSIPERIPHERAL_STATUS_TASK_ABORTED | Task aborted.| 


## Function Description


### OH_ScsiPeripheral_Close()

```
int32_t OH_ScsiPeripheral_Close (ScsiPeripheral_Device ** dev)
```

**Description**

Disables the SCSI device.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: empty dev.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.


### OH_ScsiPeripheral_CreateDeviceMemMap()

```
int32_t OH_ScsiPeripheral_CreateDeviceMemMap (ScsiPeripheral_Device * dev, size_t size, ScsiPeripheral_DeviceMemMap ** devMmap )
```

**Description**

Creates a buffer. To avoid memory leakage, use [OH_ScsiPeripheral_DestroyDeviceMemMap](#oh_scsiperipheral_destroydevicememmap) to destroy a buffer after use.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 
| size | Buffer size.| 
| devMmap | Device memory mapping used to return the created buffer to the caller. For details, see [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev or devMmap.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.


### OH_ScsiPeripheral_DestroyDeviceMemMap()

```
int32_t OH_ScsiPeripheral_DestroyDeviceMemMap (ScsiPeripheral_DeviceMemMap * devMmap)
```

**Description**

Destroys a buffer. To avoid resource leakage, destroy a buffer in time after use.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| devMmap | Buffer to be destroyed, which is created by calling **OH_ScsiPeripheral_CreateDeviceMemMa**. For details, see [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty devMmap.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.


### OH_ScsiPeripheral_Init()

```
int32_t OH_ScsiPeripheral_Init (void )
```

**Description**

Initializes the SCSI Peripheral DDK.

**Since**: 18

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK initialization error.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.


### OH_ScsiPeripheral_Inquiry()

```
int32_t OH_ScsiPeripheral_Inquiry (ScsiPeripheral_Device * dev, ScsiPeripheral_InquiryRequest * request, ScsiPeripheral_InquiryInfo * inquiryInfo, ScsiPeripheral_Response * response )
```

**Description**

Queries basic information about the SCSI device.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 
| request | Request of the **inquiry** command. For details, see [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md).| 
| inquiryInfo | Query result returned by the **inquiry** command. For details, see [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md).| 
| response | Original response returned by the **inquiry** command. For details, see [ScsiPeripheral_Response](_scsi_peripheral___response.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev, request, inquiryInfo, inquiryInfo->data, or response.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.

- SCSIPERIPHERAL_DDK_TIMEOUT: Transfer timeout.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.


### OH_ScsiPeripheral_Open()

```
int32_t OH_ScsiPeripheral_Open (uint64_t deviceId, uint8_t interfaceIndex, ScsiPeripheral_Device ** dev )
```

**Description**

Opens the SCSI device specified by **deviceId** and **interfaceIndex**.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | Device ID.| 
| interfaceIndex | Interface index for the API of the SCSI device.| 
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: empty dev.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O operation error.

- SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND: Device not found based on deviceId and interfaceIndex.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.


### OH_ScsiPeripheral_ParseBasicSenseInfo()

```
int32_t OH_ScsiPeripheral_ParseBasicSenseInfo (uint8_t * senseData, uint8_t senseDataLen, ScsiPeripheral_BasicSenseInfo * senseInfo )
```

**Description**

Parses basic sense data, including the **Information**, **Command specific information**, and **Sense key specific** fields.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| senseData | Sense data to be parsed.| 
| senseDataLen | Length of sense data.| 
| senseInfo | Stores parsed basic information. For details, see [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: senseData or senseDataLen error. (senseData is not a descriptor or is not of the fixed format, or senseDataLen is smaller than SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE or SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE.)


### OH_ScsiPeripheral_Read10()

```
int32_t OH_ScsiPeripheral_Read10 (ScsiPeripheral_Device * dev, ScsiPeripheral_IORequest * request, ScsiPeripheral_Response * response )
```

**Description**

Reads data from a specified logical block.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 
| request | Request of the **read** command. For details, see [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md).| 
| response | Response returned by the **read** command. For details, see [ScsiPeripheral_Response](_scsi_peripheral___response.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev, request, request->data, or response.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.

- SCSIPERIPHERAL_DDK_TIMEOUT: Transfer timeout.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.


### OH_ScsiPeripheral_ReadCapacity10()

```
int32_t OH_ScsiPeripheral_ReadCapacity10 (ScsiPeripheral_Device * dev, ScsiPeripheral_ReadCapacityRequest * request, ScsiPeripheral_CapacityInfo * capacityInfo, ScsiPeripheral_Response * response )
```

**Description**

Obtains the capacity information about the SCSI device.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 
| request | Request of the **read capacity** command. For details, see [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md).| 
| capacityInfo | Capacity information returned by the **read capacity** command. For details, see [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md).| 
| response | Original response returned by the **read capacity** command. For details, see [ScsiPeripheral_Response](_scsi_peripheral___response.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev, request, capacityInfo, or response.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.

- SCSIPERIPHERAL_DDK_TIMEOUT: Transfer timeout.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.


### OH_ScsiPeripheral_Release()

```
int32_t OH_ScsiPeripheral_Release (void )
```

**Description**

Releases the SCSI Peripheral DDK.

**Since**: 18

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.


### OH_ScsiPeripheral_RequestSense()

```
int32_t OH_ScsiPeripheral_RequestSense (ScsiPeripheral_Device * dev, ScsiPeripheral_RequestSenseRequest * request, ScsiPeripheral_Response * response )
```

**Description**

Obtains sense data, that is, information returned by the SCSI device to the host to report the device status, error information, and diagnosis information.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 
| request | Request of the **request sense** command. For details, see [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md).| 
| response | Response returned by the **request sense** command. For details, see [ScsiPeripheral_Response](_scsi_peripheral___response.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev, request, or response.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.

- SCSIPERIPHERAL_DDK_TIMEOUT: Transfer timeout.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.


### OH_ScsiPeripheral_SendRequestByCdb()

```
int32_t OH_ScsiPeripheral_SendRequestByCdb (ScsiPeripheral_Device * dev, ScsiPeripheral_Request * request, ScsiPeripheral_Response * response )
```

**Description**

Sends SCSI commands in command descriptor block (CDB) mode.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device] (#scsiperipheral_device).| 
| request | Request. For details, see [ScsiPeripheral_Request](_scsi_peripheral___request.md).| 
| response | Response. For details, see [ScsiPeripheral_Response](_scsi_peripheral___response.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev, request, request->data, or response, or invalid request->cdbLength value (0).

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.

- SCSIPERIPHERAL_DDK_TIMEOUT: Transfer timeout.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.


### OH_ScsiPeripheral_TestUnitReady()

```
int32_t OH_ScsiPeripheral_TestUnitReady (ScsiPeripheral_Device * dev, ScsiPeripheral_TestUnitReadyRequest * request, ScsiPeripheral_Response * response )
```

**Description**

Checks whether the logical units are ready.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 
| request | Request of the **test unit ready** command. For details, see [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md).| 
| response | Response returned by the **test unit ready** command. For details, see [ScsiPeripheral_Response](_scsi_peripheral___response.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev, request, or response.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.

- SCSIPERIPHERAL_DDK_TIMEOUT: Transfer timeout.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.


### OH_ScsiPeripheral_Verify10()

```
int32_t OH_ScsiPeripheral_Verify10 (ScsiPeripheral_Device * dev, ScsiPeripheral_VerifyRequest * request, ScsiPeripheral_Response * response )
```

**Description**

Verifies a specified logical block.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 
| request | Request of the **verify** command. For details, see [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md).| 
| response | Response returned by the **verify** command. For details, see [ScsiPeripheral_Response](_scsi_peripheral___response.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev, request, or response.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.

- SCSIPERIPHERAL_DDK_TIMEOUT: Transfer timeout.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.


### OH_ScsiPeripheral_Write10()

```
int32_t OH_ScsiPeripheral_Write10 (ScsiPeripheral_Device * dev, ScsiPeripheral_IORequest * request, ScsiPeripheral_Response * response )
```

**Description**

Writes data to a specified logical block of a device.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | Device handle. For details, see [ScsiPeripheral_Device](#scsiperipheral_device).| 
| request | Request of the **write** command. For details, see [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md).| 
| response | Response returned by the **write** command. For details, see [ScsiPeripheral_Response](_scsi_peripheral___response.md).| 

**Required Permissions**

ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Returns**

- SCSIPERIPHERAL_DDK_SUCCESS: Operation succeeded.

- SCSIPERIPHERAL_DDK_NO_PERM: Permission verification failed.

- SCSIPERIPHERAL_DDK_INIT_ERROR: DDK not initialized.

- SCSIPERIPHERAL_DDK_INVALID_PARAMETER: Empty dev, request, request->data, or response.

- SCSIPERIPHERAL_DDK_SERVICE_ERROR: DDK service communication error.

- SCSIPERIPHERAL_DDK_MEMORY_ERROR: Memory operation error.

- SCSIPERIPHERAL_DDK_IO_ERROR: DDK I/O error.

- SCSIPERIPHERAL_DDK_TIMEOUT: Transfer timeout.

- SCSIPERIPHERAL_DDK_INVALID_OPERATION: Operation not supported.

<!--no_check-->