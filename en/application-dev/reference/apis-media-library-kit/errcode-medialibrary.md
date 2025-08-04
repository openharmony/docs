# Media Library Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

<!--Del-->
## 23800107 Context Is Empty or Invalid

**Error Message**

Context is invalid.

**Description**

This error code is reported if the context object does not exist or is empty.

**Possible causes**

The context object does not exist.

**Solution**

Use the correct context.
<!--DelEnd-->

## 23800301 System Internal Error

**Error Message**

System inner fail.

**Description**

This error code is reported if an internal error occurs in the media library.

**Possible causes**

1. The database is abnormal.

2. The file system is abnormal.

3. The IPC message times out.

**Solution**

Clear the background or restart the device.

## 23800151 Failed to Verify Scene Parameters

**Error Message**

Scene parameter validation failed.

**Description**

This error code is reported if a parameter is abnormal.

**Possible causes**

1. Mandatory parameters do not meet the specified range.

2. The provided record already exists.

3. The number of provided records exceeds the maximum allowed.

**Solution**

Check the parameter values and ensure they meet the required criteria.
