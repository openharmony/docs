# Tool Access Control Error Codes

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @gcw_3MIoLA9y-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=c89bb0cf93af51551c4faf078b55b3a44a78dce9 translatedAt=2026-08-13T13:23:53.232Z pushedAt=2026-08-14T07:56:22.638Z -->

The tool access control module provides the capability of managing access permissions to system tools, including permission query, authorization, and issuance of execution credentials. It applies to scenarios where permission control is required for app access to system tools.

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 24010000 Invalid Parameter

**Error Message**

Invalid Parameter. Error message: messageInfo.

**Description**

This error code is returned when the input parameter is invalid.

**Possible Causes**

1. The permission name exceeds 256 characters.

2. The value of permissionStatus is invalid.

3. The permission query information permissionQuery is an invalid value.

4. The user authorization result userAuthResult is an invalid value.

5. The remote authorization package ticketInfo is an invalid value.

6. The remote device information remoteInfo is an invalid value.

7. The remote authorization status value remoteGrantStatus has an invalid value.

**Solution**

Check the input parameters and correct the parameter values to valid values. For details about valid values, see the parameter description of each API in [@ohos.abilityToolAccessCtrl](js-apis-abilityToolAccessCtrl-sys.md).

## 24010001 System Service Abnormal

**Error Message**

The service is abnormal.

**Description**

This error code is returned when the system service is abnormal.

**Possible Causes**

1. IPC communication fails.

2. The tool management service fails to start properly.

**Solution**

1. Retry later. This exception may be caused by a temporary IPC communication failure, and retrying will resolve the issue.

2. If the problem persists, check the system logs to confirm that the tool management service has started properly.

3. If the service fails to start, restart the device and retry.

## 24010002 Internal Service Error

**Error Message**

Common internal error.

**Description**

This error code is returned when an internal error occurs in the tool access control service, for example, a dependent system service is unavailable or resource access fails. It indicates that the server-side processing failed and the API call was not successfully executed.

**Possible Causes**

1. A dependent system service is unavailable.

2. Resource access fails.

**Solution**

1. Check whether the dependent system service is running properly.

2. Check whether the resource access permission and path are correct.

3. Restart the device and try again.

## 24010003 Environment Error

**Error Message**

Environment error. The account is not logged in, network is unavailable, timeout, etc.

**Description**

This error code is returned when the running environment does not meet the conditions.

**Possible Causes**

1. The current account is not logged in.

2. The network is unavailable.

3. The operation timed out.

**Solution**

1. Confirm that the current account is logged in.

2. Confirm that the device network connection is normal.

3. Retry later and check whether the failure is caused by a timeout.

## 24010004 Permission Does Not Exist

**Error Message**

Invalid permission. A permission in permissionInfo does not exist.

**Description**

This error code is returned when the specified permission does not exist.

**Possible Causes**

1. The permission name in permissionInfo does not exist in the system.

2. The permission name is not declared in the module.json5 file of the app.

**Solution**

Check the input parameter and correct the permission name to a valid value. For valid values, see [Permission List](../../security/AccessToken/app-permissions.md).

## 24010005 Authorization Failed

**Error Message**

Grant permission failed. The application specified by the tokenID is not allowed to be granted with the specified permission, or the specified permission cannot be granted by user, etc.

**Description**

This error code is returned when the permission granting operation fails.

**Possible Causes**

1. The app corresponding to the specified tokenID does not support being granted the specified permission.

2. The specified permission cannot be granted through user authorization.

**Solution**

1. Check whether the app corresponding to the tokenID is allowed to be granted the permission.

2. Check whether the specified permission is a permission type that can be granted through user authorization.

## 24010006 Operation Not Allowed While the Device Is Locked

**Error Message**

The requested operation is not allowed to be executed while the device is locked.

**Description**

This error code is returned when an operation that cannot be executed while the device is locked is requested.

**Possible Causes**

An operation that cannot be executed while the device is locked was requested.

**Solution**

Make sure the device is unlocked before initiating the operation request.