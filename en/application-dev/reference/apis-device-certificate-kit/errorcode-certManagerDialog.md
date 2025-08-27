# Certificate Management Dialog Box Error Codes

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @chaceli-->
<!--Designer: @chande-->
<!--Tester: @zhangzhi1995-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 29700001 Internal Error

**Error Message**

Internal error. Possible causes: 1. IPC communication failed; 2. Memory operation error; 3. File operation error.

**Possible Causes**

An internal error occurs when the API is called.

**Solution**

Check for and rectify the internal error.

## 29700002 Operation Canceled

**Error Message**

The user cancels the installation operation.

**Possible Causes**

The user canceled the operation when the API was called.

**Solution**

No action is required.

## 29700003 Failed to Install the Certificate

**Error Message**

The user install certificate failed in the certificate manager dialog, such as the certificate is in an invalid format.

**Possible Causes**

The certificate format is incorrect.

**Solution**

Check for incorrect certificate format and data.

## 29700004 Operation Not Supported by the Device

**Error Message**

The API is not supported on this device.

**Possible Causes**

The API is available only for a PC application.

**Solution**

Ensure that the caller is running on a PC.

## 29700005 Non-secure Operation

**Error Message**

The operation does not comply with the device security policy, such as the device does not allow users to manage the ca certificate of the global user.

**Possible Causes**

The device is not an enterprise device.

**Solution**

Call the API on an enterprise device.
