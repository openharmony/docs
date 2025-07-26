# scsi_peripheral_types.h

## Overview

Provides the enum variables, structures, and macros used in the SCSI Peripheral DDK APIs.

**File to include**: &lt;scsi_peripheral/scsi_peripheral_types.h&gt;

**Library**: libscsi.z.so

**System capability**: SystemCapability.Driver.SCSI.Extension

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

## Summary

### Structs

| Name                                                                                  | typedef Keyword| Description|
|--------------------------------------------------------------------------------------| -- | -- |
| [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md) | ScsiPeripheral_DeviceMemMap | Represents the device memory mapping created by calling **OH_ScsiPeripheral_CreateDeviceMemMap**. The buffer that uses the device memory mapping can provide better performance.|
| [ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md)       | ScsiPeripheral_IORequest | Read/write operation request.|
| [ScsiPeripheral_Request](capi-scsiperipheralddk-scsiperipheral-request.md)           | ScsiPeripheral_Request | Request structure.|
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md)         | ScsiPeripheral_Response | Response structure.|
| [ScsiPeripheral_TestUnitReadyRequest](capi-scsiperipheralddk-scsiperipheral-testunitreadyrequest.md) | ScsiPeripheral_TestUnitReadyRequest | Request structure of the **test unit ready** command.|
| [ScsiPeripheral_InquiryRequest](capi-scsiperipheralddk-scsiperipheral-inquiryrequest.md)            | ScsiPeripheral_InquiryRequest | Request structure of the **inquiry** command.|
| [ScsiPeripheral_InquiryInfo](capi-scsiperipheralddk-scsiperipheral-inquiryinfo.md)                  | ScsiPeripheral_InquiryInfo | SCSI inquiry data.|
| [ScsiPeripheral_ReadCapacityRequest](capi-scsiperipheralddk-scsiperipheral-readcapacityrequest.md)  | ScsiPeripheral_ReadCapacityRequest | Request structure of the **read capacity** command.|
| [ScsiPeripheral_CapacityInfo](capi-scsiperipheralddk-scsiperipheral-capacityinfo.md)                | ScsiPeripheral_CapacityInfo | SCSI read capacity.|
| [ScsiPeripheral_RequestSenseRequest](capi-scsiperipheralddk-scsiperipheral-requestsenserequest.md)  | ScsiPeripheral_RequestSenseRequest | Request structure of the **request sense** command.|
| [ScsiPeripheral_BasicSenseInfo](capi-scsiperipheralddk-scsiperipheral-basicsenseinfo.md)            | ScsiPeripheral_BasicSenseInfo | Basic information about the sense data.|
| [ScsiPeripheral_VerifyRequest](capi-scsiperipheralddk-scsiperipheral-verifyrequest.md)              | ScsiPeripheral_VerifyRequest | Request structure of the **verify** command.|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md)                            | ScsiPeripheral_Device | Opaque SCSI device structure.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ScsiPeripheral_DdkErrCode](#scsiperipheral_ddkerrcode) | ScsiPeripheral_DdkErrCode | SCSI Peripheral DDK error codes.|
| [ScsiPeripheral_Status](#scsiperipheral_status) | ScsiPeripheral_Status | SCSI status used for the response.|

## Enum Description

### ScsiPeripheral_DdkErrCode

```
enum ScsiPeripheral_DdkErrCode
```

**Description**

SCSI Peripheral DDK error codes.

**Since**: 18

| Enum| Description|
| -- | -- |
| SCSIPERIPHERAL_DDK_NO_PERM = 201 | Permission denied.|
| SCSIPERIPHERAL_DDK_INVALID_PARAMETER = 401 | Invalid parameter.|
| SCSIPERIPHERAL_DDK_SUCCESS = 31700000 | Operation success.|
| SCSIPERIPHERAL_DDK_MEMORY_ERROR = 31700001 | Memory-related errors, such as insufficient memory, memory data replication failure, or memory request failure.|
| SCSIPERIPHERAL_DDK_INVALID_OPERATION = 31700002 | Invalid operation.|
| SCSIPERIPHERAL_DDK_IO_ERROR = 31700003 | Device input/output operation failed.|
| SCSIPERIPHERAL_DDK_TIMEOUT = 31700004 | Transfer timeout.|
| SCSIPERIPHERAL_DDK_INIT_ERROR = 31700005 | DDK initialization error, or DDK uninitialized.|
| SCSIPERIPHERAL_DDK_SERVICE_ERROR = 31700006 | Communication with the SCSI Peripheral DDK failed.|
| SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND = 31700007 | Device not found.|

### ScsiPeripheral_Status

```
enum ScsiPeripheral_Status
```

**Description**

Enumerates the SCSI status codes used for the response.

**Since**: 18

| Enum| Description|
| -- | -- |
| SCSIPERIPHERAL_STATUS_GOOD = 0x00 | Normal state.|
| SCSIPERIPHERAL_STATUS_CHECK_CONDITION_NEEDED = 0x02 | Status check required.|
| SCSIPERIPHERAL_STATUS_CONDITION_MET = 0x04 | Conditions met.|
| SCSIPERIPHERAL_STATUS_BUSY = 0x08 | Occupying.|
| SCSIPERIPHERAL_STATUS_RESERVATION_CONFLICT = 0x18 | Resource reservation conflict.|
| SCSIPERIPHERAL_STATUS_TASK_SET_FULL = 0x28 | Task set already full.|
| SCSIPERIPHERAL_STATUS_ACA_ACTIVE = 0x30 | ACA activity status.|
| SCSIPERIPHERAL_STATUS_TASK_ABORTED = 0x40 | Task aborted.|
