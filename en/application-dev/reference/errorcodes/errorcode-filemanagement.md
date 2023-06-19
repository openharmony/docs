# File Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

The error codes of the file management subsystem include the following:

- [Basic File IO Error Codes](#basic-file-io-error-codes)
- [User Data Management Error Codes](#user-data-management-error-code)
- [User File Access Error Codes](#user-file-access-error-codes)
- [Space Statistics Error Codes](#space-statistics-error-codes)

## Basic File IO Error Codes

### 13900001 Operation Not Permitted

**Error Message**

Operation not permitted

**Possible Causes**

The current operation on the file is not allowed.

**Solution**

Check the permission for the file.

### 13900002 File or Directory Not Exist

**Error Message**

No such file or directory

**Possible Causes**

The file or directory does not exist.

**Solution**

Check whether the file directory exists.

### 13900003 Process Not Exist

**Error Message**

No such process

**Possible Causes**

The process does not exist.

**Solution**

1. Check whether the process is killed unexpectedly.

2. Check whether the service related to the process has started.

### 13900004 System Call Interrupted

**Error Message**

Interrupted system call

**Possible Causes**

The system call is interrupted by another thread.

**Solution**

1. Check the multi-thread code logic.

2. Invoke the system call again.

### 13900005 I/O Error

**Error Message**

I/O error

**Possible Causes**

The I/O request is invalid.

**Solution**

Initiate the I/O request again.

### 13900006 Device or Address Not Exist

**Error Message**

No such device or address

**Possible Causes**

The device information or address is incorrect.

**Solution**

Check that the device information or address is correct.

### 13900007 Long Parameter List

**Error Message**

Arg list too long

**Possible Causes**

The parameter list is too long.

**Solution**

Reduce the number of parameters.

### 13900008 Invalid File Descriptor

**Error Message**

Bad file descriptor

**Possible Causes**

This file descriptor is closed.

**Solution**

Check whether the file descriptor is closed.

### 13900009 Child Process Not Exist

**Error Message**

No child processes

**Possible Causes**

The child process cannot be created.

**Solution**

Check the maximum number of processes in the system.

### 13900010 Resource Unavailable

**Error Message**

Try again

**Possible Causes**

The resources are blocked.

**Solution**

Request resources.

### 13900011 Memory Overflow

**Error Message**

Out of memory

**Possible Causes**

A memory overflow occurs.

**Solution**

1. Check the memory overhead.

2. Control the memory overhead.

### 13900012 Permission Denied

**Error Message**

Permission denied

**Possible Causes**

1. You do not have the permission to operate the file.

2. The file sandbox path is incorrect.

**Solution**

1. Check that the required permission is available.

2. Check that the file sandbox path is correct.

### 13900013 Incorrect Address

**Error Message**

Bad address

**Possible Causes**

The address is incorrect.

**Solution**

Check that the address is correct.

### 13900014 Device or Resource Not Available

**Error Message**

Device or resource busy

**Possible Causes**

The requested resource is unavailable.

**Solution**

Request the resource again.

### 13900015 File Already Exists

**Error Message**

File exists

**Possible Causes**

The file to be created already exists.

**Solution**

Check whether the file path is correct.

### 13900016 Invalid Cross-Device Link

**Error Message**

Cross-device link

**Possible Causes**

The link between devices is incorrect.

**Solution**

Check the devices and create the link correctly.

### 13900017 Device Not Exist

**Error Message**

No such device

**Possible Causes**

The device is not identified.

**Solution**

Check the connection to the target device.

### 13900018 Invalid Directory

**Error Message**

Not a directory

**Possible Causes**

The specified directory is invalid.

**Solution**

Check that the directory is correct.

### 13900019 The Specified Object Is a Directory

**Error Message**

Is a directory

**Possible Causes**

The specified object is a directory.

**Solution**

Check that the specified data is correct.

### 13900020 Invalid Parameter

**Error Message**

Invalid argument

**Possible Causes**

Invalid input parameter is detected.

**Solution**

Check that the input parameters are valid.

### 13900021 Too Many File Descriptors Opened

**Error Message**

File table overflow

**Possible Causes**

The number of file descriptors opened has reached the limit.

**Solution**

Close the file descriptors that are no longer required.

### 13900022 Too Many Files Opened

**Error Message**

Too many open files

**Possible Causes**

The number of files opened has reached the limit.

**Solution**

Close the files that are not required.

### 13900023 Text File Not Respond

**Error Message**

Text file busy

**Possible Causes**

The executable file of the program is in use.

**Solution**

Close the program that is being debugged.

### 13900024 File Oversized

**Error Message**

File too large

**Possible Causes**

The file size exceeds the limit.

**Solution**

Check whether the file size exceeds the limit.

### 13900025 Insufficient Space on the Device

**Error Message**

No space left on device

**Possible Causes**

The device storage space is insufficient.

**Solution**

Clear the space of the device.

### 13900026 Invalid Shift

**Error Message**

Illegal seek

**Possible Causes**

Seek is used in pipe or FIFO.

**Solution**

Check the use of **seek()**.

### 13900027 Read-Only File System

**Error Message**

Read-only file system

**Possible Causes**

The file system allows read operations only.

**Solution**

Check whether the file is read-only.

### 13900028 Links Reach the Limit

**Error Message**

Too many links

**Possible Causes**

The number of links to the file has reached the limit.

**Solution**

Delete the links that are no longer required.

### 13900029 Resource Deadlock

**Error Message**

Resource deadlock would occur

**Possible Causes**

Resource deadlock occurs.

**Solution**

Terminate the deadlock process.

### 13900030 Long File Name

**Error Message**

Filename too Long

**Possible Causes**

The length of the path or file name exceeds the limit.

**Solution**

Modify the path or file name.

### 13900031 Function Not Implemented

**Error Message**

Function not implemented

**Possible Causes**

The function is not supported by the system.

**Solution**

Check the system version and update the system if required.

### 13900032 Directory Not Empty

**Error Message**

Directory not empty

**Possible Causes**

The specified directory is not empty.

**Solution**

1. Check the directory.

2. Ensure that the directory is empty.

### 13900033 Too Many Symbol Links

**Error Message**

Too many symbolic links

**Possible Causes**

There are too many symbolic links.

**Solution**

Delete unnecessary symbol links.

### 13900034 Operation Blocked

**Error Message**

Operation would block

**Possible Causes**

The operation is blocked.

**Solution**

Perform the operation again.

### 13900035 Invalid File Descriptor

**Error Message**

Invalid request descriptor

**Possible Causes**

The requested file descriptor is invalid.

**Solution**

Check that the file descriptor is valid.

### 13900036 Target Is Not a Character Stream Device

**Error Message**

Device not a stream

**Possible Causes**

The device pointed to by the file descriptor is not a character stream device.

**Solution**

Check whether the file descriptor points to a stream.

### 13900037 No Data Available

**Error Message**

No data available

**Possible Causes**

The required data is not available.

**Solution**

Request the data again.

### 13900038 Value Mismatches the Data Type

**Error Message**

Value too large for defined data type

**Possible Causes**

The specified value is out of the range defined for the data type.

**Solution**

Modify the data type.

### 13900039 File Descriptor Corrupted

**Error Message**

File descriptor in bad state

**Possible Causes**

The file descriptor is corrupted.

**Solution**

Check that the file descriptor is valid.

### 13900040 System Call Interrupted

**Error Message**

Interrupted system call should be restarted

**Possible Causes**

The system call is interrupted.

**Solution**

Invoke the system call again.

### 13900041 Disk Quota Exceeded

**Error Message**

Quota exceeded

**Possible Causes**

The disk space is insufficient.

**Solution**

Clear disk space.

### 13900042 Unknown Error

**Error Message**

Unknown error

**Possible Causes**

The error is unidentified.

**Solution**

1. Call the API again.

2. Restart the service.

## User Data Management Error Codes

### 14000001 Invalid File Name

**Error Message**

Invalid display name

**Possible Causes**

The file name contains invalid characters.

**Solution**

Modify the file name.

### 14000002 Invalid URI

**Error Message**

Invalid uri

**Possible Causes**

The URI is invalid.

**Solution**

Use the obtained URI.

### 14000003 Invalid File Name Extension

**Error Message**

Invalid file name extension

**Possible Causes**

The file name extension is incorrect.

**Solution**

Modify the file name extension.

### 14000004 File in Recycle Bin

**Error Message**

File has been put into trash bin

**Possible Causes**

The file is moved to the Recycle Bin.

**Solution**

Check whether the file is in the Recycle Bin.

## Space Statistics Error Codes

### 13600001 IPC Failed

**Error Message**

IPC error

**Possible Causes**

The called service does not exist.

**Solution**

Check whether the service is started.

### 13600002 File System Not Supported

**Error Message**

Not supported filesystem

**Possible Causes**

The file system is not supported.

**Solution**

Use a supported file system.

### 13600003 Mount Failed

**Error Message**

Failed to mount

**Possible Causes**

The **mount** command fails.

**Solution**

Remove the card and run the **mount** command again.

### 13600004 Unmount Failed

**Error Message**

Failed to unmount

**Possible Causes**

The device does not respond.

**Solution**

Check whether the file is being used. If yes, kill the thread that uses the file.

### 13600005 Incorrect Volume State

**Error Message**

Incorrect volume state

**Possible Causes**

The volume state is incorrect.

**Solution**

Check whether the current volume state is correct.

### 13600006 Failed to Create a Directory or Node

**Error Message**

Prepare directory or node error

**Possible Causes**

The directory or node to be created already exists.

**Solution**

Check whether the directory or node to be created already exists.

### 13600007 Failed to Delete a Directory or Node

**Error Message**

Delete directory or node error

**Possible Causes**

The specified directory or node has been deleted.

**Solution**

Check whether the specified directory or node exists.

### 13600008 Object Not Exist

**Error Message**

No such object

**Possible Causes**

1. The specified volume ID is incorrect.

2. The specified bundle name is incorrect.

**Solution**

1. Check whether the specified volume exists.

2. Check whether the specified bundle name exists.

### 13600009 Invalid User ID

**Error Message**

User id out of range

**Possible Causes**

The specified user ID is incorrect.

**Solution**

Check that the user ID is correct.

## User File Access Error Codes

### 14300001 IPC Failed

**Error Message**

IPC error

**Possible Causes**

1. The server service does not exist.

2. The extension mechanism is abnormal.

**Solution**

Check that the server service exists.

### 14300002 Incorrect URI Format

**Error Message**

Invalid uri

**Possible Causes**

The URI is invalid.

**Solution**

Check that the URI is in correct format.

### 14300003 Failed to Obtain the Server Ability Information

**Error Message**

Fail to get fileextension info

**Possible Causes**

The BMS interface is abnormal.

**Solution**

Check for basic system capability errors.

### 14300004 Incorrect Result Returned by js-server

**Error Message**

Get wrong result

**Possible Causes**

The data returned by the server is incorrect.

**Solution**

Check the data returned by the server.

### 14300005 Failed to Register Notify

**Error Message**

Fail to register notification

**Possible Causes**

1. The server service does not exist.

2. The extension mechanism is abnormal.

**Solution**

Check that the server service exists.

### 14300006 Failed to Unregister Notify

**Error Message**

Fail to remove notification

**Possible Causes**

1. The server service does not exist.

2. The extension mechanism is abnormal.

**Solution**

Check that the server service exists.

### 14300007 Failed to Initialize the Notify Agent

**Error Message**

Fail to init notification agent

**Possible Causes**

The specified Notify agent has not been registered.

**Solution**

Check whether the specified Notify agent is registered.

### 14300008 Failed to Notify the Agent

**Error Message**

Fail to notify agent

**Possible Causes**

1. The service does not exist.

2. The extension mechanism is abnormal.

**Solution**

Check whether the client is normal.
