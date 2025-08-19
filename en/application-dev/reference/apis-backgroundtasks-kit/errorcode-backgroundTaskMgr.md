# backgroundTaskManager Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 9800001 Memory Operation Failure

**Error Message**

Memory operation failed.

**Description**

This error code is reported when a memory operation fails.

**Possible Causes**

1. A memory leak occurs.
2. The system memory is insufficient.

**Solution**

1. Release the memory.
2. Check whether memory leak occurs.

## 9800002 Parcel Operation Failure

**Error Message**

Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory.

**Description**

When an API related to a continuous task is called, the read or write operation fails during IPC.

**Possible Causes**

1. The data object fails to be read or written during IPC.
2. The memory fails to be allocated for the read or write operation.
<br>During RPC, the sender can use the **write()** method provided by **MessageParcel** to write data in specific format to a **MessageParcel** object. The receiver can use the **read()** method provided by **MessageParcel** to read data in specific format from a **MessageParcel** object.

**Solution**

Try again later or restart the device.

## 9800003 IPC Failure

**Error Message**

Internal transaction failed.

**Description**

This error code is reported when IPC fails.

**Possible Causes**

IPC fails.

**Solution**

Try again later or restart the device.

## 9800004 System Service Failure

**Error Message**

System service operation failed.

**Description**

When an API related to a continuous task is called, the client process fails to obtain the system service.

**Possible Causes**

1. The system service is not started.
2. The system service is abnormal.

**Solution**

Try again later or restart the device.

## 9800005 Continuous Task Verification Failure

**Error Message**

Continuous task verification failed.

**Description**

This error code is reported when continuous task verification fails.

**Possible Causes**

1. The application repeatedly requests a continuous task.
2. The application repeatedly cancels a continuous task.
3. The value of **bgMode** is invalid because no continuous task type is configured for **backgroundModes** in the application's configuration file.
4. Only <!--RP1-->specific devices<!--RP1End--> can request continuous tasks of the KEEPING_TASK type.

**Solution**

1. Check the application code.
2. Check whether the application has the system permissions.
3. Check the type of the device where the application is located.
4. Check the value of **backgroundModes**.

## 9800006 Notification Verification Failure for a Continuous Task

**Error Message**

Notification verification failed for a continuous task.

**Description**

This error code is reported when notification verification in a continuous task fails.

**Possible Causes**

1. The continuous task resources cached in the resource subsystem fail to be loaded.
2. The notification subsystem functions abnormally.

**Solution**

1. Check for the continuous task resources **ohos.backgroundtaskmgr.resources**.
2. Try again later or restart the device.

## 9800007 Continuous Task Storage Failure

**Error Message**

Continuous task storage failed.

**Description**

This error code is reported when information storage in a continuous task fails. 

**Possible Causes**

1. Failed to create a file to store the task information.
2. Failed to obtain the file path.
3. Failed to open the file that stores the task information.

**Solution**

1. Check the **/data/service/el1/public/background_task_mgr/running_task** file.
2. Try again later or restart the device.

## 9900001 Caller Information Verification Failure for a Transient Task

**Error Message**

Caller information verification failed for a transient task.

**Description**

This error code is reported when caller information verification in a transient task fails.

**Possible Causes**

1. Failed to obtain the UID or PID of the caller.
2. Failed to obtain the bundle name of the caller.
3. The request ID passed in the API used to cancel the transient task is invalid.

**Solution**

1. Check whether the application UID exists.
2. Check whether the application has requested a transient task.
3. Try again later or restart the device.

## 9900002 Transient Task Verification Failure

**Error Message**

Transient task verification failed.

**Description**

This error code is reported when transient task verification fails.

**Possible Causes**

1. The callback passed in **requestSuspendDelay()** already exists.
2. The callback passed in **cancelSuspendDelay()** does not exist.
3. The application attempts to request a transient task 5 seconds after it switches to the background.
4. The application has already requested three transient tasks.
5. The application's daily quota for transient tasks is used up.

**Solution**

1. Check the application code.
2. The application should cancel transient tasks immediately after they are complete.

## 9900003 Parcel Operation Failure

**Error Message**

Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory.

**Description**

When an API related to a transient task is called, the read or write operation fails during IPC.

**Possible Causes**

1. The data object fails to be read or written during IPC.
2. The memory fails to be allocated for the read or write operation.
<br>During RPC, the sender can use the **write()** method provided by **MessageParcel** to write data in specific format to a **MessageParcel** object. The receiver can use the **read()** method provided by **MessageParcel** to read data in specific format from a **MessageParcel** object.

**Solution**

Try again later or restart the device.

## 9900004 System Service Failure

**Error Message**

System service operation failed.

**Description**

When an API related to a transient task is called, the client process fails to obtain the system service.

**Possible Causes**

1. The system service is not started.
2. The system service is abnormal.

**Solution**

Try again later or restart the device.
<!--Del-->
## 18700001 Caller Information Verification Failure for an Energy Resource Request

**Error Message**

Caller information verification failed for an energy resource request.

**Description**

This error code is reported when caller information verification in an energy resource request fails.

**Possible Causes**

1. Failed to obtain the UID or PID of the caller.
2. The value of **resourceTypes** for requesting energy resources exceeds the upper limit.

**Solution**

Check the input parameters.

## 18700002 Parcel Operation Failure

**Error Message**

Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory.

**Description**

When an API related to efficiency resources is called, the read or write operation fails during IPC.

**Possible Causes**

1. The data object fails to be read or written during IPC.
2. The memory fails to be allocated for the read or write operation.
<br>During RPC, the sender can use the **write()** method provided by **MessageParcel** to write data in specific format to a **MessageParcel** object. The receiver can use the **read()** method provided by **MessageParcel** to read data in specific format from a **MessageParcel** object.

**Solution**

Try again later or restart the device.

## 18700004 System Service Failure

**Error Message**

System service operation failed.

**Description**

When an API related to efficiency resources is called, the client process fails to obtain the system service.

**Possible Causes**

1. The system service is not started.
2. The system service is abnormal.

**Solution**

Try again later or restart the device.
<!--DelEnd-->
