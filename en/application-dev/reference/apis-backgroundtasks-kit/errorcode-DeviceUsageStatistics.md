# DeviceUsageStatistics Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 10000001 Memory Operation Failure

**Error Message**

Memory operation failed.

**Description**

This error code is reported when a memory operation fails.

**Possible Causes**

The system memory is insufficient.

**Solution**

Check whether memory leak occurs.

## 10000002 IPC Parcel Write Failure

**Error Message**

Parcel operation failed. Failed to write the parcel.

**Description**

Failed to write the data object during the IPC.

**Possible Causes**

Failed to write the object.

**Solution**

Check whether the object value is normal.

## 10000003 System Service Operation Failure

**Error Message**

System service operation failed.

**Description**

The client process fails to obtain the system service.

**Possible Causes**

The dependent service process is faulty.

**Solution**

Try again later or restart the device.

## 10000004 IPC Failure

**Error Message**

IPC failed.

**Description**

The IPC fails.

**Possible Causes**

The system service is abnormal or the IPC data is abnormal.

**Solution**

Try again later or restart the device.

## 10000005 Application Not Installed

**Error Message**

The application is not installed.

**Description**

The application is not installed.

**Possible Causes**

The application is not installed or has been uninstalled.

**Solution**

Check whether the application exists.

## 10000006 Failed to Obtain Application Information

**Error Message**

Failed to get the application information.

**Description**

The client process fails to obtain application information from the service.

**Possible Causes**

1. The value of **beginTime** or **endTime** is invalid.
2. The application is not installed or has been uninstalled.
3. The value of **intervalType** is invalid.

**Solution**

Check whether the input parameters are valid and whether the application exists.

## 10000007 Time Operation Failure

**Error Message**

Failed to get the system time.

**Description**

The system service fails to obtain the system time.

**Possible Causes**

The system is abnormal.

**Solution**

Try again later or restart the device.

## 10100001 Duplicate Application Group Operation

**Error Message**

Repeated operation on the application group.

**Description**

Operating the application group, for example, setting an application group or registering or deregistering a callback for application group changes, fails.

**Possible Causes**

The application group to set already exists, or the callback for application group changes to register or deregister has already been registered or deregistered.

**Solution**

Do not repeatedly set application groups, or register or deregister a callback for application group changes.

## 10100002 Failed to Obtain Application Group Information

**Error Message**

Failed to get the application group information.

**Description**

The client process fails to obtain the application group information.

**Possible Causes**

1. An incorrect bundle name is passed.
2. The application is not installed or has been uninstalled.

**Solution**

Check whether the bundle name is valid and whether the application exists.
