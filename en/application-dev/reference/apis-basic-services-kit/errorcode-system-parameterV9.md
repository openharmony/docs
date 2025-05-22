# System Parameter Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 14700101 Failure to Query the System Parameter

**Error Message**

System parameter not found.

**Description**

This error code is reported when the parameter does not exist in the workspace or no key has been set for the parameter.

**Possible Causes**

The parameter is not set or fails to be set.

**Solution**

Set the parameter correctly.

## 14700102 Invalid System Parameter Value

**Error Message**

Invalid system parameter value.

**Description**

This error code is reported when the value of the system parameter is invalid.

**Possible Causes**

The value of the system parameter is empty, is out of range, or contains special characters, for example, **const.param.xxx**.

**Solution**

Set the value to a valid string.

## 14700103 Permission Denial for the Operation on the System Permission

**Error Message**

The operation on the system permission is denied.

**Description**

This error code is reported when the system parameter does not have the discretionary access control (DAC) or mandatory access control (MAC) permission.

**Possible Causes**

The DAC or MAC permission is not configured.

**Solution**

Add the DAC or MAC permission as needed.

## 14700104 Internal System Error, Including Out of Memory and Deadlock

**Error Message**

System internal error such as out memory or deadlock.

**Description**

This error code is reported when the attempt to modify the **const** attribute settings, the socket connection, or the memory copy fails.

**Possible Causes**

The socket connection is abnormal, or the node fails to be added or obtained.

**Solution**

1. Analyze the memory usage of the entire process and eliminate memory leak.
2. If you are in a multi-thread scenario, check the error stack for deadlock.
