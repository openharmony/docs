# Network Connection Management Error Codes

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2100001 Invalid Parameter Value

**Error Message**

Invalid parameter value.

**Description**

This error code is reported if the parameter value is invalid.

**Cause**

The input parameter value is not within the valid value range.

**Procedure**

Check whether the input parameter value is within the valid value range.

## 2100002 Service Connection Failure

**Error Message**

Failed to connect to the service.

**Description**

This error code is reported if a service connection failure occurs.

**Cause**

The service is abnormal.

**Procedure**

Check whether system services are running properly.

## 2100003 System Internal Error

**Error Message**

System internal error.

**Description**

This error code is reported if a system internal error occurs.

**Cause**

1. The memory is abnormal.

2. A null pointer is present.

**Procedure**

1. Check whether the memory space is sufficient. If not, clear the memory and try again.

2. Check whether the system is normal. If not, try again later or restart the device.

## 2101007 Callback Not Exist

**Error Message**

The callback does not exist.

**Description**

This error code is reported if a **callback** object to be unregistered does not exist.

**Cause**

The **callback** object has not been registered for activating a network or listening to network status changes.

**Procedure**

Before unregistering a **callback** object, make sure that it has been registered for activating a network or listening to network status changes.

## 2101008 Callback Already Exists

**Error Message**

The callback already exists.

**Description**

This error code is reported if the same callback already exists.

**Cause**

The **callback** object has been registered for activating a network or listening to network status changes.

**Procedure**

1. Check whether the **callback** object has been registered.

2. If the **callback** object has been registered, use the registered **callback** object.


## 2101022 Number of Requests Exceeding the Maximum

**Error Message**

The number of requests exceeded the maximum allowed.

**Description**

This error code is reported if the number of network requests exceeds the maximum.

**Cause**

- The number of requests for activating a network or listening to network status changes has reached the maximum value.

- The maximum number of 2.NetConnection.register interfaces has been reached.

**Procedure**

1. Locate the fault based on the "Over the max request number" log record.

2. After using **NetConnection.register**, call **NetConnection.unregister** to cancel the registered listener in a timely manner.
