# DRM Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 24700101 Unknown Error

**Error Message**

Unknown error.

**Description**

An unknown error occurs.

**Possible Causes**

The input parameter format or data type is incorrect. As a result, data fails to be obtained or converted.

**Procedure**

Obtain the exception description, check the system error logs, and rectify the fault based on the exception description and error description in the logs.

## 24700103 Too Many MediaKeySystem Instances

**Error Message**

Too many MediaKeySystem instances.

**Description**

The number of **MediaKeySystem** instances reaches the upper limit (64).

**Possible Causes**

Invalid **MediaKeySystem** instances are not released in time.

**Procedure**

Release **MediaKeySystem** instances that are no longer used.

## 24700104 Too Many MediaKeySession Instances

**Error Message**

Too many MediaKeySession instances.

**Description**

The number of **MediaKeySession** instances reaches the upper limit (64).

**Possible Causes**

Invalid **MediaKeySession** instances are not released in time.

**Procedure**

Release **MediaKeySession** instances that are no longer used.

## 24700201 Service Error

**Error Message**

Service error. For example, the service crashed.

**Description**

A DRM service error occurs.

**Possible Causes**

1. An error occurs during the DRM solution plugin execution.

2. DRM services are suspended.

**Procedure**

Obtain the exception description, check the system error logs, and rectify the fault based on the exception description and error description in the logs.
