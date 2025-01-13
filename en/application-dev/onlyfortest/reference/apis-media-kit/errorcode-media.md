# Media Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

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

Operation not allowed.

**Description**

This operation is not allowed.

**Possible Causes**

This operation is not allowed in the current state.

**Solution**

Switch the instance to the correct state and perform the operation.

## 5400103 I/O Error

**Error Message**

I/O error.

**Description**

An I/O error occurs.

**Possible Causes**

The data interaction between the media and other modules (graphics, audio, network, HDI, and camera) is abnormal.

**Solution**

Ensure that the network is normal, destroy this instance, and re-create it. If the re-creation fails, stop related operations.

## 5400104 Operation Timeout

**Error Message**

Operation timeout.

**Description**

The operation timed out.

**Possible Causes**
<!--RP2-->
1. The network connection times out. (The default network timeout period is 15 seconds, and the timer starts after the buffered event is reported.)
2. Accessing other modules times out.
<!--RP2End-->

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

Unsupported format.

**Description**

The format is not supported.

**Possible Causes**

The file format is not supported.

**Solution**

Use a supported format.

## 5400107 Audio Focus Conflict

**Error Message**

Audio interrupted.

**Description**

Recording fails due to audio focus conflicts.

**Possible Causes**

Another process occupies the audio focus.

**Solution**

Destroy the current instance and check whether another process is recording. If you can stop the other process, you can create the current instance again.
