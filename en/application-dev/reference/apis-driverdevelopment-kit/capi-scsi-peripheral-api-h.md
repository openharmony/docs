# scsi_peripheral_api.h

## Overview

Declares the SCSI Peripheral DDK APIs used by the host to access the SCSI device.

**File to include**: <scsi_peripheral/scsi_peripheral_api.h>

**System capability**: SystemCapability.Driver.SCSI.Extension

**Since**: 18

**Related module**: [SCSIPeripheralDDK](capi-scsiperipheralddk.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [int32_t OH_ScsiPeripheral_Init(void)](#oh_scsiperipheral_init) | Initializes the SCSI Peripheral DDK.|
| [int32_t OH_ScsiPeripheral_Release(void)](#oh_scsiperipheral_release) | Releases the SCSI Peripheral DDK.|
| [int32_t OH_ScsiPeripheral_Open(uint64_t deviceId, uint8_t interfaceIndex, ScsiPeripheral_Device **dev)](#oh_scsiperipheral_open) | Opens the SCSI device specified by **deviceId** and **interfaceIndex**.|
| [int32_t OH_ScsiPeripheral_Close(ScsiPeripheral_Device **dev)](#oh_scsiperipheral_close) | Disables the SCSI device.|
| [int32_t OH_ScsiPeripheral_TestUnitReady(ScsiPeripheral_Device *dev, ScsiPeripheral_TestUnitReadyRequest *request,ScsiPeripheral_Response *response)](#oh_scsiperipheral_testunitready) | Checks whether the logical units are ready.|
| [int32_t OH_ScsiPeripheral_Inquiry(ScsiPeripheral_Device *dev, ScsiPeripheral_InquiryRequest *request,ScsiPeripheral_InquiryInfo *inquiryInfo, ScsiPeripheral_Response *response)](#oh_scsiperipheral_inquiry) | Queries basic information about the SCSI device.|
| [int32_t OH_ScsiPeripheral_ReadCapacity10(ScsiPeripheral_Device *dev, ScsiPeripheral_ReadCapacityRequest *request,ScsiPeripheral_CapacityInfo *capacityInfo, ScsiPeripheral_Response *response)](#oh_scsiperipheral_readcapacity10) | Obtains the capacity information about the SCSI device.|
| [int32_t OH_ScsiPeripheral_RequestSense(ScsiPeripheral_Device *dev, ScsiPeripheral_RequestSenseRequest *request,ScsiPeripheral_Response *response)](#oh_scsiperipheral_requestsense) | Obtains sense data, that is, information returned by the SCSI device to the host to report the device status, error information, and diagnosis information.|
| [int32_t OH_ScsiPeripheral_Read10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request,ScsiPeripheral_Response *response)](#oh_scsiperipheral_read10) | Reads data from a specified logical block.|
| [int32_t OH_ScsiPeripheral_Write10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request,ScsiPeripheral_Response *response)](#oh_scsiperipheral_write10) | Writes data to a specified logical block of a device.|
| [int32_t OH_ScsiPeripheral_Verify10(ScsiPeripheral_Device *dev, ScsiPeripheral_VerifyRequest *request,ScsiPeripheral_Response *response)](#oh_scsiperipheral_verify10) | Verifies a specified logical block.|
| [int32_t OH_ScsiPeripheral_SendRequestByCdb(ScsiPeripheral_Device *dev, ScsiPeripheral_Request *request,ScsiPeripheral_Response *response)](#oh_scsiperipheral_sendrequestbycdb) | Sends SCSI commands in CDB mode.|
| [int32_t OH_ScsiPeripheral_CreateDeviceMemMap(ScsiPeripheral_Device *dev, size_t size,ScsiPeripheral_DeviceMemMap **devMmap)](#oh_scsiperipheral_createdevicememmap) | Creates a buffer. To avoid resource leakage, use [OH_ScsiPeripheral_DestroyDeviceMemMap](capi-scsi-peripheral-api-h.md#oh_scsiperipheral_destroydevicememmap) to destroy a buffer after use.|
| [int32_t OH_ScsiPeripheral_DestroyDeviceMemMap(ScsiPeripheral_DeviceMemMap *devMmap)](#oh_scsiperipheral_destroydevicememmap) | Destroys a buffer. To avoid resource leakage, destroy a buffer in time after use.|
| [int32_t OH_ScsiPeripheral_ParseBasicSenseInfo(uint8_t *senseData, uint8_t senseDataLen,ScsiPeripheral_BasicSenseInfo *senseInfo)](#oh_scsiperipheral_parsebasicsenseinfo) | Parses basic sense data, including the **Information**, **Command specific information**, and **Sense key specific** fields.|

## Function Description

### OH_ScsiPeripheral_Init()

```
int32_t OH_ScsiPeripheral_Init(void)
```

**Description**

Initializes the SCSI Peripheral DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK initialization fails.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.|

### OH_ScsiPeripheral_Release()

```
int32_t OH_ScsiPeripheral_Release(void)
```

**Description**

Releases the SCSI Peripheral DDK.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.|

### OH_ScsiPeripheral_Open()

```
int32_t OH_ScsiPeripheral_Open(uint64_t deviceId, uint8_t interfaceIndex, ScsiPeripheral_Device **dev)
```

**Description**

Opens the SCSI device specified by **deviceId** and **interfaceIndex**.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                            | Description|
|---------------------------------| -- |
| uint64_t deviceId               | Device ID.|
| uint8_t interfaceIndex          |  Interface index for the API of the SCSI device.|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) **dev | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_DEVICE_NOT_FOUND](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): No device is found based on the specified **deviceId** and **interfaceIndex**.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_Close()

```
int32_t OH_ScsiPeripheral_Close(ScsiPeripheral_Device **dev)
```

**Description**

Disables the SCSI device.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) **dev | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.|

### OH_ScsiPeripheral_TestUnitReady()

```
int32_t OH_ScsiPeripheral_TestUnitReady(ScsiPeripheral_Device *dev, ScsiPeripheral_TestUnitReadyRequest *request,ScsiPeripheral_Response *response)
```

**Description**

Checks whether the logical units are ready.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                        | Description                                                                                                                    |
|---------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                                  | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                                                               |
| [ScsiPeripheral_TestUnitReadyRequest](capi-scsiperipheralddk-scsiperipheral-testunitreadyrequest.md) *request | Request of the **test unit ready** command. For details, see [ScsiPeripheral_TestUnitReadyRequest](capi-scsiperipheralddk-scsiperipheral-testunitreadyrequest.md).|
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response      | Response returned by the **test unit ready** command. For details, see [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md).      |

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev**, **request**, or **response** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The transmission times out.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_Inquiry()

```
int32_t OH_ScsiPeripheral_Inquiry(ScsiPeripheral_Device *dev, ScsiPeripheral_InquiryRequest *request,ScsiPeripheral_InquiryInfo *inquiryInfo, ScsiPeripheral_Response *response)
```

**Description**

Queries basic information about the SCSI device.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                   | Description                                                                                                  |
|----------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                             | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                                             |
| [ScsiPeripheral_InquiryRequest](capi-scsiperipheralddk-scsiperipheral-inquiryrequest.md) *request        | Request of the **inquiry** command. For details, see [ScsiPeripheral_InquiryRequest](capi-scsiperipheralddk-scsiperipheral-inquiryrequest.md).          |
| [ScsiPeripheral_InquiryInfo](capi-scsiperipheralddk-scsiperipheral-inquiryinfo.md) *inquiryInfo          | Query result returned by the **inquiry** command. For details, see [ScsiPeripheral_InquiryInfo](capi-scsiperipheralddk-scsiperipheral-inquiryinfo.md).              |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response | Raw response returned by the inquiry command. For details, see [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev**, **request**, **inquiryInfo**, **inquiryInfo > data**, or **response** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The transmission times out.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_ReadCapacity10()

```
int32_t OH_ScsiPeripheral_ReadCapacity10(ScsiPeripheral_Device *dev, ScsiPeripheral_ReadCapacityRequest *request,ScsiPeripheral_CapacityInfo *capacityInfo, ScsiPeripheral_Response *response)
```

**Description**

Obtains the capacity information about the SCSI device.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                      | Description                                                                                                        |
|-------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                                | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                                                   |
| [ScsiPeripheral_ReadCapacityRequest](capi-scsiperipheralddk-scsiperipheral-readcapacityrequest.md) *request | Request of the **read capacity** command. For details, see [ScsiPeripheral_ReadCapacityRequest](capi-scsiperipheralddk-scsiperipheral-readcapacityrequest.md).|
| [ScsiPeripheral_CapacityInfo](capi-scsiperipheralddk-scsiperipheral-capacityinfo.md) *capacityInfo          | Capacity information returned by the **read capacity** command. For details, see [ScsiPeripheral_CapacityInfo](capi-scsiperipheralddk-scsiperipheral-capacityinfo.md).            |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response    | Original response returned by the **read capacity** command. For details, see [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev**, **request**, **capacityInfo**, or **response** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The transmission times out.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_RequestSense()

```
int32_t OH_ScsiPeripheral_RequestSense(ScsiPeripheral_Device *dev, ScsiPeripheral_RequestSenseRequest *request,ScsiPeripheral_Response *response)
```

**Description**

Obtains sense data, that is, information returned by the SCSI device to the host to report the device status, error information, and diagnosis information.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                      | Description                                                                                                        |
|-------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                                | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                                                   |
| [ScsiPeripheral_RequestSenseRequest](capi-scsiperipheralddk-scsiperipheral-requestsenserequest.md) *request | Request of the **request sense** command. For details, see [ScsiPeripheral_RequestSenseRequest](capi-scsiperipheralddk-scsiperipheral-requestsenserequest.md).|
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response    | Response returned by the **request sense** command. For details, see [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md).  |

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev**, **request**, or **response** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The transmission times out.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_Read10()

```
int32_t OH_ScsiPeripheral_Read10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request,ScsiPeripheral_Response *response)
```

**Description**

Reads data from a specified logical block.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                    | Description                                                                                             |
|-----------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                              | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                                        |
| [ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md) *request | Request of the **read** command. For details, see [ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md).|
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response  | Response returned by the **read** command. For details, see [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev**, **request**, **request > data**, or **response** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The transmission times out.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_Write10()

```
int32_t OH_ScsiPeripheral_Write10(ScsiPeripheral_Device *dev, ScsiPeripheral_IORequest *request,ScsiPeripheral_Response *response)
```

**Description**

Writes data to a specified logical block of a device.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                    | Description                                                                                              |
|-----------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                              | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                                         |
| [ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md) *request | Request of the **write** command. For details, see [ScsiPeripheral_IORequest](capi-scsiperipheralddk-scsiperipheral-iorequest.md).|
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response  | Response returned by the **write** command. For details, see [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev**, **request**, **request > data**, or **response** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The transmission times out.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_Verify10()

```
int32_t OH_ScsiPeripheral_Verify10(ScsiPeripheral_Device *dev, ScsiPeripheral_VerifyRequest *request,ScsiPeripheral_Response *response)
```

**Description**

Verifies a specified logical block.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                   | Description                                                                                               |
|----------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                             | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                                          |
| [ScsiPeripheral_VerifyRequest](capi-scsiperipheralddk-scsiperipheral-verifyrequest.md) *request          | Request of the **verify** command. For details, see [ScsiPeripheral_VerifyRequest](capi-scsiperipheralddk-scsiperipheral-verifyrequest.md).          |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response | Response returned by the **verify** command. For details, see [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev**, **request**, or **response** is empty.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The transmission times out.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_SendRequestByCdb()

```
int32_t OH_ScsiPeripheral_SendRequestByCdb(ScsiPeripheral_Device *dev, ScsiPeripheral_Request *request,ScsiPeripheral_Response *response)
```

**Description**

Sends SCSI commands in CDB mode.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                   | Description                                                                                  |
|----------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                             | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                             |
| [ScsiPeripheral_Request](capi-scsiperipheralddk-scsiperipheral-request.md) *request    | Request. For details, see [ScsiPeripheral_Request](capi-scsiperipheralddk-scsiperipheral-request.md).  |
| [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md) *response | Response. For details, see [ScsiPeripheral_Response](capi-scsiperipheralddk-scsiperipheral-response.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_NO_PERM](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The permission verification fails.<br>         [SCSIPERIPHERAL_DDK_INIT_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The DDK is not initialized.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev**, **request**, **request > data**, or **response**<br>         is empty, or **request > cdbLength** is 0.<br>         [SCSIPERIPHERAL_DDK_SERVICE_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The communication with the DDK service fails.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.<br>         [SCSIPERIPHERAL_DDK_IO_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): An I/O error occurs.<br>         [SCSIPERIPHERAL_DDK_TIMEOUT](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The transmission times out.<br>         [SCSIPERIPHERAL_DDK_INVALID_OPERATION](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The operation is not supported.|

### OH_ScsiPeripheral_CreateDeviceMemMap()

```
int32_t OH_ScsiPeripheral_CreateDeviceMemMap(ScsiPeripheral_Device *dev, size_t size,ScsiPeripheral_DeviceMemMap **devMmap)
```

**Description**

Creates a buffer. To avoid resource leakage, use [OH_ScsiPeripheral_DestroyDeviceMemMap](capi-scsi-peripheral-api-h.md#oh_scsiperipheral_destroydevicememmap) to destroy a buffer after use.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                           | Description                                                                                                         |
|------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md) *dev                                                                     | Device handle. For details, see [ScsiPeripheral_Device](capi-scsiperipheralddk-scsiperipheral-device.md).                                                                    |
| size_t size                                                                                    | Buffer size.                                                                                                    |
| [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md) **devMmap | Device memory mapping used to return the created buffer to the caller. For details, see [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **dev** or **devMmap** is empty.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.|

### OH_ScsiPeripheral_DestroyDeviceMemMap()

```
int32_t OH_ScsiPeripheral_DestroyDeviceMemMap(ScsiPeripheral_DeviceMemMap *devMmap)
```

**Description**

Destroys a buffer. To avoid resource leakage, destroy a buffer in time after use.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name                                                                                          | Description                                                                                                                                                                               |
|-----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md) *devMmap | Buffer to be destroyed, which is created by calling [OH_ScsiPeripheral_CreateDeviceMemMap](#oh_scsiperipheral_createdevicememmap). For details, see [ScsiPeripheral_DeviceMemMap](capi-scsiperipheralddk-scsiperipheral-devicememmap.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **devMmap** is empty.<br>         [SCSIPERIPHERAL_DDK_MEMORY_ERROR](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The memory operation fails.|

### OH_ScsiPeripheral_ParseBasicSenseInfo()

```
int32_t OH_ScsiPeripheral_ParseBasicSenseInfo(uint8_t *senseData, uint8_t senseDataLen,ScsiPeripheral_BasicSenseInfo *senseInfo)
```

**Description**

Parses basic sense data, including the **Information**, **Command specific information**, and **Sense key specific** fields.

**Required permissions**: ohos.permission.ACCESS_DDK_SCSI_PERIPHERAL

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| uint8_t *senseData | Sense data to be parsed.|
| uint8_t senseDataLen | Length of sense data.|
| [ScsiPeripheral_BasicSenseInfo](capi-scsiperipheralddk-scsiperipheral-basicsenseinfo.md) *senseInfo | Basic sense data after parsing. For details, see [ScsiPeripheral_BasicSenseInfo](capi-scsiperipheralddk-scsiperipheral-basicsenseinfo.md).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | [SCSIPERIPHERAL_DDK_SUCCESS](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The API call is successful.<br>         [SCSIPERIPHERAL_DDK_INVALID_PARAMETER](capi-scsi-peripheral-types-h.md#scsiperipheral_ddkerrcode): The input **senseData** is not a descriptor or is not of the fixed format, or **senseDataLen** is smaller than<br>         **SCSIPERIPHERAL_MIN_DESCRIPTOR_FORMAT_SENSE** or **SCSIPERIPHERAL_MIN_FIXED_FORMAT_SENSE**.|
