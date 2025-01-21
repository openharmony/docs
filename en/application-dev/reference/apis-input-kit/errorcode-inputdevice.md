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
   
## 3900002 Keyboard device no connected.

**Error Message**

There is currently no keyboard device inserted for connection.

**Description**

This error code is generated if currently no keyboard device connected.

**Possible Causes**

The physical keyboard device is disconnected.

**Procedure**

Check if the physical connection of the device is disconnected.

## 3900003 Non-input applications call

**Error Message**

it is prohibited for non-input applications.

**Description**

Prohibit non input method applications from calling this interface.

**Possible Causes**

Third party applications or non input method system applications call this interface.

**Procedure**

Please use input method application to call this interface.
