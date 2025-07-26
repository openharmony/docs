# Upload and Download Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 13400001 File Operation Error

**Error Message**

Invalid file or file system error.

**Description**

This error code is reported when the **uploadFile** or **downloadFile** API fails to be invoked to upload or download a file.

**Possible Causes**

The file permission is insufficient.

**Solution**

Make sure you have the required permission on the target files.

## 13400002 File Path Error

**Error Message**

File path not supported or invalid.

**Description**

This error code is reported when a file path error occurs in invoking the **uploadFile** or **downloadFile** API.

**Possible Causes**

The file path is incorrect or the file already exists in the path.

**Solution**

Verify the file path.

## 13400003 Service Error

**Error Message**

Task service ability error.

**Description**

This error code is reported when a task manager service error occurs in invoking the **downloadFile** API.

**Possible Causes**

The task fails to be created.

**Solution**

Verify the task settings.

## 13499999 Other Error

**Error Message**

Other error.

**Description**

This error code is reported when other error occurs in invoking the **uploadFile** or **downloadFile** API.

**Possible Causes**

The task fails to be created.

**Solution**

Verify the task settings.


## 21900004 Application Task Queue Full

**Error Message**

The application task queue is full.

**Description**

This error code is reported when the application task queue is full.

**Possible Causes**

The application fails to create a background task (resources are preempted by foreground tasks, where no task queue is involved).

**Solution**

1. Obtain all background tasks of the application through the query API.

2. Proactively remove tasks not needed to release the quota.

3. Create a background task again.

## 21900005 Task Mode Error

**Error Message**

Operation with wrong task mode.

**Description**

This error code is reported when a task mode error occurs.

**Possible Causes**

The application attempts to create a foreground task when it is not running in the foreground.

**Solution**

1. Register and deregister an event listener for a foreground application.

2. Follow the instructions in the API reference document.

## 21900006 Task Not Found

**Error Message**

Task removed or not found.

**Description**

This error code is reported when the task does not exist.

**Possible Causes**

The task to remove or query does not exist.

**Solution**

1. Query existing tasks through the query API.

2. Check whether the target task exists. (The system periodically deletes junk tasks.)

3. Verify the task ID and try again.

## 21900007 Operation Not Supported by the Task State

**Error Message**

Operation with wrong task state.

**Description**

This error code is reported when an operation is not supported by the task state.

**Possible Causes**

1. The task to start has been deleted.

2. The task to start has not been initialized.

3. The task to pause is not being executed.

4. The task to resume is not paused.

5. The task to stop is not being executed.

**Solution**

1. Query the task state.

2. Perform the operation supported by the current task state.

## 21900008 Task Group Not Found or Deleted

**Error Message**

Group deleted or not found.

**Description**

This error code is reported when a task group does not exist or has been deleted.

**Possible Causes**

1. Delete a task group that has been deleted or does not exist.

2. Add a task to a group that has been deleted or does not exist.

**Solution**

Check whether the target group has been deleted.
