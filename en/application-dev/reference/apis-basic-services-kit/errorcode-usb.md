# USB Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 14400001 USB Device Connection Denied

**Error Message**

Permission denied. Call requestRight or requestAccessoryRight to get the permission or USBDevicePipe access right first.

**Description**

This error code is reported if a certain API of the USB module is called but the required permission is not granted.

**Possible Causes**

The permission to access the USB device is not granted.

**Procedure**

Call **requestRight** to request for the permission to access the USB device.
<!--Del-->
## 14400002 HDC Disabled

**Error Message**

Permission denied. The HDC is disabled by the system.

**Description**

This error code is reported if HDC is disabled by the system.

**Possible Causes**

The USB debugging permission is not granted.

**Procedure**

Apply for the USB debugging permission.

## 14400003 Port Role Switching Unsupported

**Error Message**

Unsupported operation. The current device does not support port role switching.

**Description**

This error code is reported if port role switching is not supported. The device does not support port role switching.

**Possible Causes**

The port role is incorrect.

**Procedure**

Use the correct port role.
<!--DelEnd-->
## 14400004 Service Exception

**Error Message**

Service exception. Possible causes: No accessory is plugged in.

**Description**

This error code is reported if the service is abnormal.

**Possible Causes**

No accessory is inserted.

**Procedure**

Insert the accessory.

## 14400005 Database Operation Exception

**Error Message**

Database operation exception.

**Description**

This error code is reported if the database operation is abnormal.

**Procedure**

Call the API again.
<!--Del-->
## 14400006 USB Device Function Unsupported

**Error Message**

Unsupported operation. The function is not supported.

**Description**

This error code is reported if the requested USB device function is not supported.  

**Possible Causes**

The USB device function is not supported.

**Procedure**

Use the correct USB device function.
<!--DelEnd-->
## 14401001 Target USB Accessory Unmatched

**Error Message**

The target USBAccessory not matched.

**Description**

This error code is reported if the target USB accessory does not match the device.

**Procedure**

Call **getAccessoryList** to obtain the accessory list and use a matched USB accessory to try again.

## 14401002 Failed to Open the Native Accessory Node

**Error Message**

Failed to open the native accessory node.

**Description**

This error code is reported if the attempt to open the native accessory node fails.

**Procedure**

Call the API again.

## 14401003 Accessory Opened Repeatedly

**Error Message**

Cannot reopen the accessory.

**Description**

This error code is reported if an accessory is opened repeatedly.

**Procedure**

The accessory has been opened. Continue to perform subsequent operations.

## 14400007 Resource Busy

**Error Message**

Resource busy.

**Description**

This error code is reported if the requested resource is in use.

**Procedure**

Check whether [usbManager.claimInterface](js-apis-usbManager.md#usbmanagerclaiminterface) is successfully called.

## 14400008 No Device (Disconnected)

**Error Message**

No such device (it may have been disconnected).

**Description**

This error code is reported if the device cannot be identified.

**Procedure**

Check whether the device type is correct and whether the device is successfully connected.

## 14400009 Insufficient Memory

**Error Message**

Insufficient memory.

**Description**

This error code is reported if no memory is available when being requested. The maximum data size is 1 KB for a single transfer.

**Procedure**

Clear memory in a timely manner.

## 14400010 Unrecognized Error

**Error Message**

Other USB error. Possible causes:Unrecognized discard error code.

**Description**

This error code is reported if an unknown error occurs.

**Procedure**

Correct the error by referring to the related documentation, and try again.

## 14400011 No Ongoing Transfer Found

**Error Message**

If the transfer is not in progress, already complete, or already cancelled. 

**Description**

This error code is reported if the current data transfer has been canceled or completed.

**Procedure**

Initiate a new data transfer request.

## 14400012 I/O Error

**Error Message**

Transmission I/O error.

**Description**

This error code is reported if the read/write operation fails because the I/O channel is abnormal.

**Procedure**

Try again.

## 31400001 Serial Port Service Error

**Error Message**

serial service exception.

**Description**

This error code is reported if the serial port service is abnormal.

**Possible Causes**

The process exits due to a program exception.

**Procedure**

Check whether the device is connected, and obtain the correct serial port number from the serial port list.

## 31400002 No Serial Port Device Access Permission

**Error Message**

no access right to serial device, call requestSerialRight first.

**Description**

This error code is reported if you do not have the permission to access the serial port device.

**Possible Causes**

You have not applied for the permission to access the serial port device.

**Procedure**

Call **requestSerialRight** to apply for the access permission.

## 31400003 Port Number Not Exist

**Error Message**

portId not exist.

**Description**

This error code is reported if the port number does not exist.

**Possible Causes**

The original port number becomes invalid because the device connection is abnormal.

**Procedure**

Remove and insert the device, and try again.

## 31400004 Port in Use

**Error Message**

device is using by other application.

**Description**

This error code is reported if the device is being used by another application.

**Possible Causes**

The serial port device is enabled repeatedly.

**Procedure**

Remove and insert the device, and try again.

## 31400005 Device Not Opened

**Error Message**

device is not open, call open first.

**Description**

This error code is reported if the device is not opened. 

**Possible Causes**

A device has not been opened.

**Procedure**

Call the **Open** API to open the device before performing subsequent operations.

## 31400006 Transmission Timeout

**Error Message**

transfer timeout.

**Description**

This error code is reported if the data transfer times out.

**Possible Causes**

The peer end does not send data.

**Procedure**

Check whether the peer device initiates data transfer.

## 31400007 I/O Exception

**Error Message**

I/O exception.

**Description**

This error code is reported if an I/O exception occurs.

**Possible Causes**

The amount of received data in a single transfer exceeds the configured buffer size.

**Procedure**

Adjust the buffer size properly, and perform data transfer again.
