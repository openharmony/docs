# Audio Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 6800101 Invalid Parameter

**Error Message**

Invalid parameter.

**Description**

A parameter passed in the API is invalid.

**Possible Causes**

The parameter is invalid. For example, the parameter value is not within the range supported.

**Solution**

Pass the correct parameters in the API.

## 6800102 Memory Allocation Failure

**Error Message**

Memory allocation failed.

**Description**

When the API is called, the memory fails to be allocated or a null pointer occurs.

**Possible Causes**

1. The system does not have sufficient memory for mapping.
2. Invalid instances are not destroyed in time to release the memory.

**Solution**

1. Destroy the existing instances.
2. Create a new instance. If the creation fails, stop related operations.

## 6800103 Unsupported State

**Error Message**

Operation not permitted at current state.

**Description**

The current state of the object does not support this operation.

**Possible Causes**

The operation is not supported in the current state of the object, for example, attempting to play data without starting the stream.

**Solution**

1. Check whether this operation is supported in the current state.
2. Transition the object to the correct state before performing the operation.

<!--Del-->
## 6800104 Unsupported Parameter Value

**Error Message**

Unsupported option.

**Description**

The parameter value is not supported.

**Possible Causes**

The value of the input parameter is not within the range supported.

**Solution**

1. Check the enums or other input parameters supported by the API.
2. Use a supported value.
<!--DelEnd-->

## 6800105 Processing Timeout

**Error Message**

Timeout.

**Description**

The processing times out.

**Possible Causes**

1. An internal exception occurs in the system, triggering a timeout check of an internal interface.
2. The system relies on timely callback processing by the application. If the application fails to return promptly, the system reports a timeout.

**Solution**

1. For internal system timeouts, the application can only report the error.
2. For interface implementations that depend on timely callback processing by the application, the application should check the callback execution and ensure prompt returns to avoid disrupting subsequent system processes.

## 6800201 Too Many Audio Streams

**Error Message**

Too many audio streams.

**Description**

The number of audio streams reaches the upper limit.

**Possible Causes**

Excess audio streams are not released in a timely manner.

**Solution**

1. Release unused audio stream resources and retry.
2. If the system limit is reached due to other applications, report an error message to the user, asking them to close other applications.

## 6800301 System Error

**Error Message**

System error.

**Description**

The system processing is abnormal.

**Possible Causes**

The system processing is abnormal, for example, system service restart or IPC exceptions.

**Solution**

This is a general internal system error with unclear circumstances. You are advised to try re-creating the service process or directly report a system error.
