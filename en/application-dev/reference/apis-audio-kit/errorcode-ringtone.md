# Ringtone Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 20700001

**Error Message**

Tone type mismatch.

**Description**

This error code is reported if the tone type passed in the API does not match the expected type.

**Possible Causes**

Invalid parameter, such as providing a tone path for an alarm instead of a notification tone.

**Solution**

Pass the correct tone path in the API.

## 20700002 Parameter Check Failed

**Error Message**

Parameter check error.

**Description**

This error code is reported if a certain parameter passed in the API is invalid.

**Possible Causes**

The parameter is invalid. For example, the parameter value is not within the range supported.

**Solution**

Pass the correct parameters in the API.

## 20700003 Operation Not Supported

**Error Message**

Unsupported operation.

**Description**

This error code is reported if the current operation is not supported when the API is called.

**Possible Causes**

The device does not support the capability, such as lacking vibration support.

**Solution**

Refer to the device capability documentation.
