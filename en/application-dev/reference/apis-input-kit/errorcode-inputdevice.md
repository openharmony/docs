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
