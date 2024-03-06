# Screen Lock Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 13200002 Screen Lock Management Service Is Abnormal

**Error Message**

The screenlock management service is abnormal.

**Description**

This error code is reported when the screen lock management service is not working correctly.

**Possible Causes**

 
1. The service stops running due to unknown errors and is not automatically restored.
2. The service is running but does not respond due to unknown errors.

**Solution**

Run the **ps -ef** command to check whether the service is running.

1. If the service is not running, restart the system.
2. If the service is running, close the service process and wait for automatic recovery. If the issue persists, perform step 1.

## 13200003 Invalid Use

**Error Message**

illegal use.

**Description**

This error code is reported when the API is not called by the application in focus.

**Possible Causes**

The **unlock()** API is called by an application not in focus.


**Solution**

Check whether the application that calls **unlock()** is in focus.
