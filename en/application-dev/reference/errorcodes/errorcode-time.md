# Time and Time Zone Service Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## -1 Screen Unlock Error

**Error Message**

The parameter check failed or permission denied or system error.

**Description**

This error code is reported when a parameter check failure, permission verification failure, or system operation error occurs.

**Possible Cause**


1. The input parameter is invalid.
2. The required permission is not configured. For example, **ohos.permission.SET_TIME** is not configured for setting the time or **ohos.permission.SET_TIME_ZONE** is not configured for setting the time zone.
3. The system is not running properly due to a common kernel error, such as a memory allocation and multi-thread processing error.

**Solution**

1.  Make sure input parameters are passed in as required.
2. Configure the **ohos.permission.SET_TIME** permission for setting the time and the **ohos.permission.SET_TIME_ZONE** permission for setting the time zone.
3.  Make sure the memory is sufficient.

