# Mechanic Manager Error Codes
<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @hobbycao-->
<!--Designer: @saga2025-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @foryourself-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 33300001 System Error

**Error Message**

Service exception.

**Description**

This error code is reported if a system error occurs.

**Possible Causes**

An unrecoverable error occurs in the service logic processing on the server.

**Solution**

The system error cannot be rectified.

## 33300002 Device Not Connected

**Error Message**

Device not connected.

**Description**

This error code is reported if the mechanical device is not connected.

**Possible Causes**

No connected device is available.

**Solution**

Ensure that the development device is properly connected to the mechanical device through Bluetooth.

## 33300003 Function Not Supported

**Error Message**

Feature not supported.

**Description**

This error code is reported if the function is not supported by the current development device.

**Possible Causes**

The camera driver of the current development device does not support the object detection function.

**Solution**

Add the object detection function to the camera driver of the current development device or replace the development device with one that supports the object detection function.
