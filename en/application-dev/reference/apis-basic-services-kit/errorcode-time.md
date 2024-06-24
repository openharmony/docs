# Time and Time Zone Service Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## -1 Time and Time Zone Service Error

**Error Message**

Parameter check failed, permission denied, or system error.

**Description**

The time and time zone service is abnormal.

**Possible Cause**

The system is not running properly due to a common kernel error, such as a memory allocation and multi-thread processing error.

**Solution**

The system is not running properly due to insufficient memory.

## 201 Permission Error

**Error Message**

Permission verification failed. The application does not have the permission required to call the API.

**Description**

The permission to call the API for setting the time or time zone is insufficient.

**Possible Cause**

This error code indicates that the permission to call the API is insufficient.

**Solution**

Check whether you have the permission to call the API.

## 202 System App Error

**Error Message**

System application error.

**Description**

A non-system app calls a system API.

**Possible Cause**

This error code indicates that the API is called by a non-system app.

**Solution**

Check whether the API is called by a system app.

## 401 System App Error

**Error Message**

Parameter error.

**Description**

The input parameter is incorrect.

**Possible Cause**

1. The number of parameters is inconsistent with that of the API.
2. The parameter type is incorrect.
3. Failed to verify the parameter value.

**Solution**

The input parameter is invalid. Make sure input parameters are passed in as required.
