# oh_device_manager_err_code.h

## Overview

Declares the error codes of the distributed device management module.

**File to include**: <distributedhardware/device_manager/oh_device_manager_err_code.h> 

**Library**: libdevicemanager_ndk.so

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Since**: 20

**Related module**: [DeviceManager](capi-devicemanager.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [DeviceManager_ErrorCode](#devicemanager_errorcode) | DeviceManager_ErrorCode | Error code information of distributed device management module.|

## Enum Description

### DeviceManager_ErrorCode

```
enum DeviceManager_ErrorCode
```

**Description**

Error codes of the distributed device management module.

**Since**: 20

| Enum| Description|
| -- | -- |
| ERR_OK = 0 | Operation success.|
| ERR_PERMISSION_ERROR = 201 | Permission verification failed.|
| ERR_INVALID_PARAMETER = 401 | Invalid parameter.|
| DM_ERR_FAILED = 11600101 | Function execution failed.|
| DM_ERR_OBTAIN_SERVICE = 11600102 | Failed to obtain the device management service.|
| DM_ERR_OBTAIN_BUNDLE_NAME = 11600109 | Failed to obtain the bundle name.|
