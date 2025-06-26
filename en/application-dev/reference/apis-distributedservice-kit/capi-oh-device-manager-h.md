# oh_device_manager.h

## Overview

Provides APIs to obtain information about trusted devices and local devices.

**File to include**: <distributedhardware/device_manager/oh_device_manager.h>

**Library:** libdevicemanager_ndk.so

**System capability**: SystemCapability.DistributedHardware.DeviceManager

**Since**: 20

**Related module**: [DeviceManager](capi-devicemanager.md)

## Summary

### Function

| Name| Description|
| -- | -- |
| [int32_t OH_DeviceManager_GetLocalDeviceName(char **localDeviceName, unsigned int &len)](#oh_devicemanager_getlocaldevicename) | Obtains the display name of the local device.<br>The device display name involves user privacy. You need to provide a privacy statement to declare the purpose of the device display name.|

## Function Description

### OH_DeviceManager_GetLocalDeviceName()

```
int32_t OH_DeviceManager_GetLocalDeviceName(char **localDeviceName, unsigned int &len)
```

**Description**

Obtains the display name of the local device.<br>The device display name involves user privacy. You need to provide a privacy statement to declare the purpose of the device display name.

**Required permissions**: ohos.permission.READ_LOCAL_DEVICE_NAME

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| char **localDeviceName | Pointer to the display name of the local device. After using this API, you need to manually release resources to free up space. If the application has the **ohos.permission.READ_LOCAL_DEVICE_NAME** permission, the device display name is returned. Otherwise, the default device name is returned.|
| unsigned int &len | Length of the display name of the local device.|

**Return value**

| Type| Description                                                                                                                                                                                                                                                                                                                                                                          |
| -- |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| int32_t | Error code. For details about the error code definitions, see [DeviceManager_ErrorCode](capi-oh-device-manager-err-code-h.md#devicemanager_errorcode).<br>         [ERR_OK](capi-oh-device-manager-err-code-h.md#devicemanager_errorcode) is returned if the execution is successful.<br>         [DM_ERR_FAILED](capi-oh-device-manager-err-code-h.md#devicemanager_errorcode) is returned if the function fails to be executed.<br>         [DM_ERR_OBTAIN_SERVICE](capi-oh-device-manager-err-code-h.md#devicemanager_errorcode) is returned if the device management service fails to be obtained.<br>         [DM_ERR_OBTAIN_BUNDLE_NAME](capi-oh-device-manager-err-code-h.md#devicemanager_errorcode) is returned if the bundle name fails to be obtained.|
