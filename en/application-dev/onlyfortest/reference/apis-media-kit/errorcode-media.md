# Media error code

> **NOTE:**
> The following describes only the specific error codes of this module. For details about common error codes, see the Common Error Code Description.

## 5400101 Memory allocation failure

**Error information**

No memory.

**Error Description**

Failed to allocate memory.

**Possible Causes**

1. The number of instances exceeds 16.
2. The new or malloc process fails, resulting in a null pointer.

**Processing Procedure**

Destroy the current instance and create it again. If the instance fails to be created, stop related operations.

## 5400102 The current state machine does not support this operation.

**Error information**

Operation not allowed.

**Error Description**

The current operation is not allowed.

**Possible Causes**

The current state machine does not support this operation.

**Processing Procedure**

Check whether the current status supports the current operation, switch the instance to the correct status, and perform the correct operation.

## 5400103 An I/O error occurs.

**Error information**

I/O error.

**Error Description**

An IO error has occurred.

**Possible Causes**

The data interaction between the media and other modules is abnormal. (Graphics, Audio, Network, HDI, Camera).

**Processing Procedure**

Check whether the network connection is normal. Destroy the current instance and create it again. If the instance fails to be created again, stop related operations.

## 5400104 Operation Timeout

**Error information**

Operation timeout.

**Error Description**

Operation timed out.

**Possible Causes**

1. The network times out. The default network timeout interval is 15 seconds. The timer starts when the cached event is reported. After the timer expires, the error message is reported.
2. Access to other modules times out.

**Processing Procedure**

1. Check whether the network is normal.
2. Destroy the current instance and create it again. If the instance fails to be created again, stop related operations.

## 5400105 Playback Service Dead

**Error information**

Service died.

**Error Description**

Playback service is dead.

**Possible Causes**

Playback service is dead.

**Processing Procedure**

Destroy the current instance and create it again. If the instance fails to be created, stop related operations.

## Specifications Not Supported by 5400106

**Error information**

Unsupport format.

**Error Description**

The specification is not supported.

**Possible Causes**

The file or format is not supported.

**Processing Procedure**

The current format is not supported. You need to switch to a supported format.

## 5400107 Audio Focus Conflict

**Error information**

Audio interrupted

**Error Description**

Recording Failure Due to Audio Focus Conflict

**Possible Causes**

Another process occupies the audio focus. As a result, the audio focus cannot be obtained.

**Processing Procedure**

Destroy the current instance and check whether other processes are recording. If you can stop the occupation of other processes, you can create them again.