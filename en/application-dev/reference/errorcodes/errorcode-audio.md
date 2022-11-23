#  Audio Error Codes

## 6800101 Invalid Parameter

**Error Message**

invalid parameter.

**Description**

A parameter passed in the API is invalid.

**Possible Causes**

The parameter is invalid. For example, the parameter value is not within the range supported.

**Solution**

Pass the correct parameters in the API.

## 6800102 Memory Allocation Failure

**Error Message**

allocate memory failed.

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

Operation not permit at current state.

**Description**

This operation is not allowed in the current state.

**Possible Causes**

The operation is not supported in the current state. For example, data is played before streams are started.

**Solution**

1. Check whether this operation is supported in the current state.
2. Switch the instance to the correct state and perform the operation.

## 6800104 Unsupported Parameter Value

**Error Message**

unsupported operation.

**Description**

The parameter value is not supported.

**Possible Causes**

The value of the input parameter is not within the range supported.

**Solution**

1. Check the enums or other input parameters supported by the API.
2. Use a supported value.

## 6800105 Processing Timeout

**Error Message**

time out.

**Description**

Waiting for external processing times out.

**Possible Causes**

Waiting for external processing times out. For example, waiting for the application to fill in audio data times out.

**Solution**

Control the time of the write operation, for example, adding delayed processing.

## 6800201 Too Many Audio Streams

**Error Message**

stream number limited.

**Description**

The number of audio streams reaches the upper limit.

**Possible Causes**

Invalid audio streams are not released in time.

**Solution**

Release audio streams that are no longer used.

## 6800301 System Error

**Error Message**

system error.

**Description**

The system processing is abnormal.

**Possible Causes**

The system processing is abnormal, for example, system service restart or IPC exceptions.

**Solution**

Create the service again.
