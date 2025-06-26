# File Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

The error codes of the file management subsystem include the following:<br>- [Basic File IO Error Codes](#basic-file-io-error-codes)<br>- [User Data Management Error Codes](#user-data-management-error-codes)<br>- [User File Access Error Codes](#user-file-access-error-codes)<br>- [Space Statistics Error Codes](#space-statistics-error-codes)<br>- [Device-Cloud Synchronization Error Codes](#device-cloud-synchronization-error-codes)

## Basic File IO Error Codes

### 13900001 Operation Not Permitted

**Error Message**

Operation not permitted

**Possible Causes**

The caller does not have the permission to access the URI or path.

**Solution**

1. Check whether the caller cannot use the URI shared by another application. For details, see [access control mechanisms](../../security/AccessToken/access-token-overview.md) of the system.

2. Check whether the permission is obtained by Picker. The permission obtained by Picker is temporary. For details, see [System Pickers](../../application-models/system-app-startup.md).

3. Check whether the URI is a concatenated path, which has no permission by default.

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

This error code is reported if a process does not exist.

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

Make the I/O request again.

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

### 13900008 File Descriptor Corrupted

**Error Message**

Bad file descriptor

**Possible Causes**

1. This file descriptor is closed.

2. The read and write permissions on the file do not match the settings.

**Solution**

1. Check whether the file descriptor is closed.

2. Check that the permissions on the file match the settings.

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

Request the resource again.

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

1. The operation is intercepted by DAC or SELinux.

2. The file sandbox path is incorrect.

**Solution**

1. Check the UGO permission of the file.

2. Check the kernel log for [AVC log information](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-security-selinux-develop-intro.md). If yes,<!--RP1--> see [SELinux Development](../../../device-dev/subsystems/subsys-security-selinux-develop-intro.md).<!--RP1End-->

3. Check whether the file path is a [sandbox path](../../file-management/app-sandbox-directory.md). The File Management system does not allow operations on files outside the sandbox directory.

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

Check that the specified data is correct.

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

The input parameter is invalid.

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

The file name length exceeds 256 bytes.

**Solution**

Check the file name length.

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

Too many symbolic links encountered

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

### 13900040 System Call Not Started

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

Insufficient storage space.

**Solution**

Clear disk space.

### 13900042 Unknown Error

**Error Message**

Unknown error

**Possible Causes**

Internal error

**Solution**

1. Call the API again.

2. Restart the service.

### 13900043 No Available Lock

**Error Message**

No record is locks available

**Possible Causes**

System resources are insufficient.

**Solution**

Wait until a lock is released and try again.

### 2300007 Network Access Failure

**Error Message**

Network is unreachable

**Possible Causes**

A network error occurs.

**Solution**

Check the network status.

### 13900045 Connection Failed

**Error Message**

Connection failed

**Possible Causes**

The device is abnormal, or Wi-Fi or Bluetooth is unavailable.

**Solution**

1. Check that the device is in normal status.

2. Check that Wi-Fi and Bluetooth are available.

### 13900046 Connection Interrupted by Software

**Error Message**

Software caused connection abort

**Possible Causes**

The device goes offline, or the Wi-Fi or Bluetooth is disconnected.

**Solution**

1. Check that the device is in normal status.

2. Check that Wi-Fi and Bluetooth are available.

## User Data Management Error Codes

### 14000001 Invalid File Name

**Error Message**

Invalid file name

**Possible Causes**

The file name contains invalid characters.

**Solution**

Modify the file name.

### 14000002 Invalid URI

**Error Message**

Invalid URI

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

File already in the recycle bin

**Possible Causes**

The file is moved to the Recycle Bin.

**Solution**

Check whether the file is in the Recycle Bin.

### 14000011 Internal System Error

**Error Message**

System inner fail

**Possible Causes**

An unidentified error occurs in the system.

**Solution**

Clear the background or restart the device.

### 14000014 Invalid Member Name

**Error Message**

Member is not a valid PhotoKey

**Possible Causes**

The input string is not a member name of a class or interface.

**Solution**

Ensure that the input string is the member name of the class or interface.

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

File system not supported

**Possible Causes**

The file system is not supported.

**Solution**

Use a supported file system.

### 13600003 Mount Failed

**Error Message**

Mount failed

**Possible Causes**

The **mount** command fails.

**Solution**

Remove the card and run the **mount** command again.

### 13600004 Unmount Failed

**Error Message**

Unmount failed

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

Failed to create the directory or node

**Possible Causes**

The directory or node to be created already exists.

**Solution**

Check whether the directory or node to be created already exists.

### 13600007 Failed to Delete a Directory or Node

**Error Message**

Failed to delete the directory or node

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

User ID out of range

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

Invalid URI

**Possible Causes**

The URI is invalid.

**Solution**

Check that the URI is in correct format.

### 14300003 Failed to Obtain the Server Ability Information

**Error Message**

Failed to obtain the server ability information

**Possible Causes**

The BMS interface is abnormal.

**Solution**

Check for basic system capability errors. <!--RP1-->Please contact the OpenHarmony team for support.<!--RP1End-->

### 14300004 Incorrect Result Returned by js-server

**Error Message**

Incorrect result returned by js-server

**Possible Causes**

The data returned by the server is incorrect.

**Solution**

Check the data returned by the server.

### 14300005 Failed to Register Notify

**Error Message**

Failed to register notify

**Possible Causes**

1. The server service does not exist.

2. The extension mechanism is abnormal.

**Solution**

Check that the server service exists.

### 14300006 Failed to Unregister Notify

**Error Message**

Failed to unregister notify

**Possible Causes**

1. The server service does not exist.

2. The extension mechanism is abnormal.

**Solution**

Check that the server service exists.

### 14300007 Failed to Initialize the Notify Agent

**Error Message**

Failed to initialize the notify agent

**Possible Causes**

The specified Notify agent has not been registered.

**Solution**

Check whether the Notify agent has been registered.

### 14300008 Failed to Notify the Agent

**Error Message**

Failed to notify the agent

**Possible Causes**

1. The service does not exist.

2. The extension mechanism is abnormal.

**Solution**

Check whether the client is normal.

## Device-Cloud Synchronization Error Codes

### 22400001 Cloud Unavailable

**Error Message**

Cloud status not ready

**Possible Causes**

1. The cloud is not enabled.

2. The cloud synchronization switch is not enabled for the application.

**Solution**

1. Check whether the user has logged in using an account.

2. Check whether the cloud synchronization switch is enabled.

### 22400002 Network Unavailable

**Error Message**

Network unavailable

**Possible Causes**

The device is not connected to the network or the network is unavailable.

**Solution**

Check the network status.

### 22400003 Low Battery Level

**Error Message**

Low battery level

**Possible Causes**

The battery level is low.

**Solution**

Perform the operation after the battery is being charged or the battery level is restored.

### 22400004 Maximum Number of Input Parameters Reached

**Error Message**

Exceeded the maximum limit

**Possible Causes**

The number of requests exceeds the upper limit defined by API specifications.

**Solution**

Check the input parameters and ensure that the number of requests meets the specifications.

### 22400005 Internal Error

**Error Message**

Inner error

**Possible Causes**

1. The internal database request fails or the SQL statement fails to be executed.

2. An exception such as a null pointer occurs in the system.

3. The system memory is insufficient or abnormal.

4. The JS framework is abnormal.

**Solution**

Check for basic system capability errors. <!--RP1-->Please contact the OpenHarmony team for support.<!--RP1End-->

### 22400006 Task Running of the Same Type

**Error Message**

The same task is already in progress

**Possible Causes**

A task of the same type is running.

**Solution**

Wait until the existing tasks of the same type are complete, or call **stop()** to stop the existing tasks and trigger a new task.

### 22400007 Historical File Specified to Replace the Original File Not Exist

**Error Message**

The version file specified to replace the original file does not exist

**Possible Causes**

The files of earlier versions are not downloaded or have been deleted.

**Solution**

Download the specified historical version file again. Ensure that the file exists.
