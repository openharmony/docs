# Mechanic Manager Error Codes

<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @qxqxqxqxqx-->
<!--Designer: @peter__1024-->
<!--Tester: @Aullar-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=daa1afa787d586cf2e119ff322b4912d4397cfb5 translatedAt=2026-08-05T01:25:08.816Z pushedAt=2026-08-05T01:28:11.384Z -->

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