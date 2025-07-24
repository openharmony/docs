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

Incorrect input parameter, such as providing a tone path for an alarm instead of a notification tone.

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

Call the API based on the device capability.

## 20700004 Data Size Exceeds the Upper Limit

**Error Message**

Data size exceeds the limit.

**Description**

This error code is reported if the data size exceeds the upper limit.

**Possible Causes**

The size of the custom video tone file is too large.

**Solution**

Verify the file size and ensure that the file size does not exceed the upper limit.

## 20700005 File Count Exceeds the Upper Limit

**Error Message**

The number of files exceeds the limit.

**Description**

This error code is reported if the number of files exceeds the upper limit.

**Possible Causes**

Too many custom video tone files are added.

**Solution**

Ask the user to delete some existing video tones before adding new custom tones.

## 20700006 Insufficient ROM Space

**Error Message**

Insufficient ROM space.

**Description**

This error code is reported if the available ROM storage space is insufficient.

**Possible Causes**

The ROM space of the user is insufficient.

**Solution**

Ask the user to delete other data before using the feature.

## 20700007 Invalid Parameter

**Error Message**

Invalid parameter.

**Description**

This error code is reported if an input parameter is invalid.

**Possible Causes**

The input parameter to the function is invalid, such as being too long.

**Solution**

Verify the input parameters before calling the function.
