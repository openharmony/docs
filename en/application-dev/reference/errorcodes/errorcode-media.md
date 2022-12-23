#  Media Error Codes

## 5400101 Memory Allocation Failed

**Error Message**

No memory.

**Description**

Failed to allocate memory.

**Possible Causes**

1. The number of instances exceeds 16.
2. The new or malloc process fails, causing a null pointer.

**Solution**

Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400102 Unsupported Operation

**Error Message**

Operate not permit.

**Description**

This operation is not allowed.

**Possible Causes**

This operation is not allowed in the current state.

**Solution**

Switch the instance to the correct state and perform the operation.

## 5400103 I/O Error

**Error Message**

IO error.

**Description**

An I/O error occurs.

**Possible Causes**

The data interaction between the media and other modules (graphics, audio, network, HDI, and camera) is abnormal.

**Solution**

Ensure that the network is normal, destroy this instance, and re-create it. If the re-creation fails, stop related operations.

## 5400104 Operation Timeout

**Error Message**

Time out.

**Description**

The operation timed out.

**Possible Causes**

1. The network connection times out.
2. Accessing other modules times out.

**Solution**

1. Check whether the network is normal.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400105 Play Service Dead

**Error Message**

Service died.

**Description**

The playback service is dead.

**Possible Causes**

The playback service is dead.

**Solution**

Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400106 Format Not Supported

**Error Message**

Unsupport format.

**Description**

The format is not supported.

**Possible Causes**

The file format is not supported.

**Solution**

Use a supported format.
