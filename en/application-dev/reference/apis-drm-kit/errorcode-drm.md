# DRM Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 24700101 Unknown Error

**Error Message**

All unknown errors.

**Description**

An unknown error is returned when the API is called.

**Possible Causes**

The plug-in returns an undefined or custom error.

**Procedure**

Refer to the plug-in document to rectify the fault.

## 24700102 Memory Allocation Failure

**Error Message**

Memory allocation failure.

**Description**

This error code is reported if a memory allocation failure or null pointer occurs when an API is called.

**Possible Causes**

1. The system does not have sufficient memory for mapping.
2. Invalid instances are not destroyed in time to release the memory.

**Procedure**

1. Destroy the existing instances.
2. Create a new instance. If the creation fails, stop related operations.

## 24700103 Unsupported State

**Error Message**

Unsupported state.

**Description**

This operation is not allowed in the current state.

**Possible Causes**

The status of the device certificate or media key is abnormal.

**Procedure**

1. Check whether this operation is supported in the current state.
2. Call the API to request a device certificate or media key in the correct state.

## 24700104 Too Many MediaKeySystem Instances

**Error Message**

Too many MediaKeySystem streams.

**Description**

The number of **MediaKeySystem** instances reaches the upper limit.

**Possible Causes**

Invalid **MediaKeySystem** instances are not released in time.

**Procedure**

Release **MediaKeySystem** instances that are no longer used.

## 24700105 Too Many MediaKeySession Instances

**Error Message**

Too many MediaKeySession streams.

**Description**

The number of **MediaKeySession** instances reaches the upper limit.

**Possible Causes**

Invalid **MediaKeySession** instances are not released in time.

**Procedure**

Release **MediaKeySession** instances that are no longer used.

## 24700201 Service Error

**Error Message**

Fatal service error, for example, service died.

**Description**

The IPC service is abnormal.

**Possible Causes**

The system processing is abnormal, for example, system service restart or IPC exceptions.

**Procedure**

Create the service again.
