# Media-errorcode

api-info == null

## Overview

The following describes only the specific error codes of this module. For details about common error codes, see the Common Error Code Description.

**Since：** 9

## 5400101

**Error information**

No memory.

**Error Description**

Failed to allocate memory.

**Possible Causes**

1.The number of instances exceeds 16.
2.The new or malloc process fails, resulting in a null pointer.

**Handling Procedure**

Destroy the current instance and create it again. If the instance fails to be created again, stop related operations.

## 5400102 The current state machine does not support this operation.

**Error information**

Operation not allowed.

**Error Description**

The current operation is not allowed.

**Possible Causes**

The current state machine does not support this operation..

**Handling Procedure**

Check whether the current status supports the current operation, switch the instance to the correct status, and perform the correct operation.

## 5400103 An IO error occurred

**Error information**

I/O error.

**Error Description**

An IO error occurred.

**Possible Causes**

The data interaction between the media and other modules is abnormal. (Graphics, Audio, Network, HDI, Camera).

**Handling Procedure**

Check whether the network is normal. and Destroy the current instance and create it again. If the instance fails to be created again, stop related operations.

## 5400104 Operation timed out

**Error information**

Operation timeout.

**Error Description**

Operation timed out.