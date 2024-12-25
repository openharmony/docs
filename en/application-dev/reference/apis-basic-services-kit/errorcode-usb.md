# USB Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 14400001 USB Device Connection Denied

**Error Message**

Permission denied. Call requestRight to get the permission first.

**Description**

This error code is reported if a certain API of the USB module is called but the required permission is not granted.

**Possible Causes**

The permission to access the USB device is not granted.

**Procedure**

Call **requestRight** to request for the permission to access the USB device.

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

## 14400006 USB Device Function Unsupported

**Error Message**

Unsupported operation. The function is not supported.

**Description**

This error code is reported if the requested USB device function is not supported.  

**Possible Causes**

The USB device function is not supported.

**Procedure**

Use the correct USB device function.

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
