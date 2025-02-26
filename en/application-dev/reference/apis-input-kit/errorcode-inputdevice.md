# Input Device Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 3900001 Device Not Exist

**Error Message**

The specified device does not exist.

**Description**

This error code is generated if the specified device ID cannot be found in the multimodal device list.

**Possible Causes**

1. The ID of the input device has changed.
2. The physical connection of the input device is disconnected.

**Procedure**

1. Call the [inputDevice.getDeviceList](js-apis-inputdevice.md) API to query the device ID and use the correct device ID to perform operations.

## 3900002 Keyboard Not Connected

**Error Message**

There is currently no keyboard device connected.

**Description**

No keyboard is connected.

**Possible Causes**

The physical connection of the input device is disconnected.

**Procedure**

Check whether the keyboard cable is disconnected.

## 3900003 API Call Failed for a Non-Input Application

**Error Message**

it is prohibited for non-input applications.

**Description**

Non-input applications are not allowed to call this API.

**Possible Causes**

This API is called by a third-party application or a non-input system application.

**Procedure**

Use an input application to call this API.
