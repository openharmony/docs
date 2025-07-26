# USB Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 14400001 USB Device Connection Denied

**Error Message**

Access right denied. Call requestRight to get the USBDevicePipe access right first.

**Description**

This error code is reported if a certain API of the USB module is called but the required permission is not granted.

**Possible Causes**

The permission to access the USB device is not granted.

**Solution**

Call **requestRight** to request for the permission to access the USB device.
<!--Del-->
## 14400002 HDC Disabled

**Error Message**

Permission denied. The HDC is disabled by the system.

**Description**

This error code is reported if HDC is disabled by the system.

**Possible Causes**

The USB debugging permission is not granted.

**Solution**

Apply for the USB debugging permission.

## 14400003 Port Role Switching Unsupported

**Error Message**

Unsupported operation. The current device does not support port role switching.

**Description**

This error code is reported if the port role is switched.

**Possible Causes**

The port role is incorrect.

**Solution**

Use the correct port role.
<!--DelEnd-->
## 14400004 Service Exception

**Error Message**

Service exception. Possible causes: No accessory is plugged in.

**Description**

This error code is reported if the service is abnormal.

**Possible Causes**

No accessory is inserted.

**Solution**

Insert the accessory.

## 14400005 Database Operation Exception

**Error Message**

Database operation exception.

**Description**

This error code is reported if the database operation is abnormal.

**Solution**

Call the API again.
<!--Del-->
## 14400006 USB Device Function Unsupported

**Error Message**

Unsupported operation. The function is not supported.

**Description**

This error code is reported if the USB device function is switched.

**Possible Causes**

The USB device function is not supported.

**Solution**

Use the correct USB device function.
<!--DelEnd-->
## 14401001 Target USB Accessory Unmatched

**Error Message**

The target USBAccessory not matched.

**Description**

This error code is reported if the target USB accessory does not match the device.

**Solution**

Call **getAccessoryList** to obtain the accessory list and use a matched USB accessory to try again.

## 14401002 Failed to Open the Native Accessory Node

**Error Message**

Failed to open the native accessory node.

**Description**

This error code is reported if the attempt to open the native accessory node fails.

**Solution**

Call the API again.

## 14401003 Accessory Opened Repeatedly

**Error Message**

Cannot reopen the accessory.

**Description**

This error code is reported if an accessory is opened repeatedly.

**Solution**

The accessory has been opened. Continue to perform subsequent operations.

## 14400007 Resource Busy

**Error Message**

Resource busy. Possible causes: 1. The transfer has already been submitted. 2. The interface is claimed by another program or driver.

**Description**

This error code is reported if the requested resource is in use.

**Possible Causes**

1. The transmission task has been submitted.

2. The API is occupied by another program or driver.

**Solution**

Check whether [usbManager.claimInterface](js-apis-usbManager.md#usbmanagerclaiminterface) is successfully called.

## 14400008 No Device (Disconnected)

**Error Message**

No such device (it may have been disconnected).

**Description**

This error code is reported if the device cannot be identified.

**Solution**

Check whether the device type is correct and whether the device is successfully connected.

## 14400009 Insufficient Memory

**Error Message**

Insufficient memory. Possible causes: 1. Memory allocation failed.

**Description**

This error code is reported if no memory is available when being requested. The maximum data size is 1 KB for a single transfer.

**Possible Causes**

The memory usage is too high to allocate sufficient space to the current task.

**Solution**

Clear memory in a timely manner.

## 14400010 Unrecognized Error

**Error Message**

Other USB error. Possible causes: Unrecognized discard error code.

**Description**

This error code is reported if an unknown error occurs.

**Solution**

Correct the error by referring to the related documentation, and try again.

## 14400011 No Ongoing Transfer Found

**Error Message**

The transfer is not in progress, or is already complete or cancelled.

**Description**

This error code is reported if the current data transfer has been canceled or completed.

**Solution**

Initiate a new data transfer request.

## 14400012 I/O Error

**Error Message**

Transmission I/O error.

**Description**

This error code is reported when the read/write operation fails due to the abnormal I/O channel.

**Solution**

Try again.

## 14400013 Parameter Validity Check Failed

**Error Message**

The USBDevicePipe validity check failed. Possible causes: 1. The input parameters fail the validation check. 2. The call chain used to obtain the input parameters is not reasonable.

**Description**

This error code is reported if the parameter validity check fails.

 **Possible Causes**

1. The validity check of the input parameter fails.

2. The input parameter call chain is improper.

**Solution**

Use a proper call chain to obtain the input parameter.


## 31400001 Serial Port Service Error

**Error Message**

Serial port management exception.

**Description**

This error code is reported if the serial port service is abnormal.

**Possible Causes**

The process exits due to a program exception.

**Solution**

Check whether the device is connected, and obtain the correct serial port number from the serial port list.

## 31400002 No Serial Port Device Access Permission

**Error Message**

Access denied. Call requestSerialRight to request user authorization first.

**Description**

This error code is reported if you do not have the permission to access the serial port device.

**Possible Causes**

You have not applied for the permission to access the serial port device.

**Solution**

Call **requestSerialRight** to apply for the access permission.

## 31400003 Port Number Not Exist

**Error Message**

PortId does not exist.

**Description**

This error code is reported if the port number does not exist.

**Possible Causes**

The original port number becomes invalid because the device connection is abnormal.

**Solution**

Remove and insert the device, and try again.

## 31400004 Port in Use

**Error Message**

The serial port device is occupied.

**Description**

This error code is reported if the serial port device is occupied.

**Possible Causes**

The serial port device is enabled repeatedly.

**Solution**

Remove and insert the device, and try again.

## 31400005 Device Not Opened

**Error Message**

The serial port device is not opened. Call the open API first.

**Description**

This error code is reported if the serial port device is not opened.

**Possible Causes**

A device has not been opened.

**Solution**

Call the **Open** API to open the device before performing subsequent operations.

## 31400006 Data Transfer Timeout

**Error Message**

Data transfer timed out.

**Description**

This error code is reported if data transfer times out.

**Possible Causes**

The peer end does not send data.

**Solution**

Check whether the peer device initiates data transfer.

## 31400007 I/O Exception

**Error Message**

I/O exception.Possible causes: 1. The transfer was canceled. 2. The device offered more data than allowed.

**Description**

This error code is reported if an I/O exception occurs.

**Possible Causes**

1. The transfer task is canceled abnormally.

2. The amount of received data in a single transfer exceeds the buffer size limit.

**Solution**

Adjust the buffer size properly, and perform data transfer again.
