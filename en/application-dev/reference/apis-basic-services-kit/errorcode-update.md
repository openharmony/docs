# Update Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 11500104 IPC Error

**Error Message**

IPC error.

**Description**

This error code is reported if an exception is thrown during an IPC call.

**Possible causes**

An IPC API call failed.

**Solution**

1. Check whether the update system ability has started. If not, start it.
2. Check whether IPC data conversion is normal. If not, check the conversion process.
