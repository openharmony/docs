# Update Error Codes
<!--Kit: Basic Services Kit-->
<!--Subsystem: Update-->
<!--Owner: @RainyDay_005; @huangsiping3-->
<!--Designer: @zhangzhengxue; @jackd320-->
<!--Tester: @mamba-ting-->
<!--Adviser: @zhang_yixin13-->

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
