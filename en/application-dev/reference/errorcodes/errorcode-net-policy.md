# Policy Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 2100001 Invalid Parameters

**Error Information**

Invalid parameter value.

**Description**

This error code is reported if any input parameter value is incorrect.

**Possible Causes**

The end time is earlier than the start time.

**Solution**

Check whether the start time and end time are properly set.


## 2100002 Service Connection Failure

**Error Information**

Operation failed. Cannot connect to service.

**Description**

This error code is reported if a service connection failure occurs.

**Possible Causes**

The service is abnormal.

**Solution**

Check whether system services are running properly.

## 2100003 System Internal Error

**Error Information**

System internal error.

**Description**

This error code is reported if an internal system error occurs.

**Possible Causes**

1. The memory is abnormal.

2. A null pointer is present.

**Solution**

1. Check whether the memory space is sufficient. If not, clear the memory and try again.

2. Check whether the system is normal. If not, try again later or restart the device.
