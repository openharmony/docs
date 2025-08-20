# User Status Awareness Error Codes
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @zou_ye-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 33900001 Service Exception

**Error Message**

Service exception. Possible causes:
<br>&emsp;1. System error, such as a null pointer and container-related exception. 
<br>&emsp;2. Node-API invocation exception, such as invalid Node-API status.

**Description**

This error code is reported if a service exception occurs when the **on** or **off** API of the userStatus module is called.

**Possible Causes**

The service status is abnormal.

**Solution**

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the retry. During this period, you can preferentially obtain the device list to check for device availability.



## 33900002 Subscription Failed

**Error Message**

Subscription failed. Possible causes: 
<br>&emsp;1. Callback registration failed.
<br>&emsp;2. Failed to bind the native object to the JS wrapper.
<br>&emsp;3. Node-API invocation exception, such as invalid Node-API status.
<br>&emsp;4. IPC request exception.

**Description**

This error code is reported if subscription fails when the **on** API of the userStatus module is called.

**Possible Causes**

Subscription to status change events has failed.

**Solution**

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the retry. 



## 33500003 Unsubscription Failed

**Error Message**

Unsubscription failed. Possible causes: 
<br>&emsp;1. Callback failure.
<br>&emsp;2. Node-API invocation exception, such as invalid Node-API status.
<br>&emsp;3. IPC request exception.

**Description**

This error code is reported if unsubscription fails when the **off** API of the userStatus module is called.

**Possible Causes**

Unsubscription from status change events has failed.

**Solution**

1. Retry the operation at a specified interval (for example, 1s) or at an exponential increase interval.
2. If the operation fails for three consecutive times, stop the retry. 
