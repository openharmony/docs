# Enterprise Device Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 9200001 DeviceAdmin Not Enabled

**Error Message**

The application is not an administrator of the device.

**Description**

This error code is reported when the caller is not an enabled device administrator application.

**Possible Causes**

The enterprise device management APIs can be called only by a device administrator application that has been enabled.

**Solution**

Check that the caller is an enabled device administrator application.

## 9200002 Permission Denied

**Error Message**

The administrator application does not have permission to manage the device.

**Description**

This error code is reported when the device administrator application does not have the permission to call the API.

**Possible Causes**

The device administrator application cannot call the APIs that are accessible only by a super device administrator application.

**Solution**

Check that the device administrator type enabled for the caller is the same as that required by the API.

## 9200003 Invalid Administrator Ability Component

**Error Message**

The administrator ability component is invalid.

**Description**

This error code is reported when the specified device administrator ability component is invalid.

**Possible Causes**

1. The administrator ability component does not exist when the device administrator application is enabled.
2. The administrator ability component is not a valid enterprise administrator ability component.

**Solution**

1. Check that the name of the administrator ability component is included in the application bundle when the application is enabled as a device administrator application.
2. Check that the administrator ability component inherits the **EnterpriseAdminExtensionAbility** component defined by the enterprise device management framework.

## 9200004 Failed to Enable the Device Administrator Application

**Error Message**

Failed to activate the administrator application of the device.

**Description**

This error code is reported when an application fails to be enabled as a device administrator application.

**Possible Causes**

1. Multiple applications are enabled as the super device administrator application.
2. The application has been enabled as a device administrator application with a different administrator type.
3. Multiple device administrator ability components are enabled for the same application.

**Solution**

1. Check that only one super device administrator application exists.
2. Check whether the current application has been enabled as a device administrator with a different device administrator type. If yes, disable the device administrator application and try again.
3. Check whether a device administrator ability component has been enabled for the application. Only one device administrator ability component can be enabled for an application.

## 9200005 Failed to Disable the Device Administrator Application

**Error Message**

Failed to deactivate the administrator application of the device.

**Description**

This error code is reported when the operation for disabling a device administrator application fails.

**Possible Causes**

1. The application to be disabled is not an enabled device administrator application.
2. The caller cannot disable other device administrator applications.

**Solution**

1. Check that the target device administrator application has been enabled.
2. Check that the specified device administrator ability component of the target device administrator application has been enabled.
3. Check that the device administrator application to be disabled is the caller itself.

## 9200006 Invalid User ID

**Error Message**

The specified user ID is invalid.

**Description**

This error code is reported when the specified user ID does not exist or the specified user ID is different from the caller's user ID.

**Possible Causes**

1. The user ID specified for setting a user policy does not exist.
2. The specified user ID is different from the caller's user ID when the application is not a super device administrator application.

**Solution**

1. Check that the specified user ID is valid.
2. Check that caller's user ID is the same as the specified user ID. If the application is not a super device administrator application, policies cannot be set across users.

## 9200007 System Ability Error

**Error Message**

The system ability work abnormally.

**Description**

This error code is reported when the enterprise device management ability is not working properly.

**Possible Causes**

- The EnterpriseAdminAbility is not started.
- The RPC object for enterprise device management cannot be obtained.
- Other abilities, on which the EnterpriseAdminAbility depends, are not started, or the RPC object cannot be obtained.
- A system exception occurs during the running of EnterpriseAdminAbility.

**Solution**

Try again later or restart the device.

## 9200008 Invalid System Subscription Event

**Error Message**

The specified system events enum is invalid.

**Description**

This error code is reported when the enterprise device management module does not support subscription to the specified event or the specified event is invalid.

**Possible Causes**

The enterprise device management module does not support subscription to the specified event or the specified event is invalid.

**Solution**

Check that the specified event is valid and supported by the enterprise device management module.

## 9200009 Failed to Grant Permissions to the Application

**Error Message**

Authorize permission to the application failed.

**Description**

This error code is reported when the super device administrator application fails to grant administrator rights to other applications.

**Possible Causes**

The target application is not installed by the administrator.

**Solution**

Check that the target application has been installed by the administrator.

## 9200010 Policy Conflict

**Error Message**

A conflicting policy has been configured.

**Description**

This error code is reported when a conflict policy is being delivered.

**Possible Causes**

A conflict policy is defined and to be delivered.

**Solution**

Resolve the conflict, and then deliver the policy.

## 9201001 Failed to Manage the Certificate

**Error Message**

Manage certificate failed

**Description**

This error code is reported when the super device administrator application fails to install or uninstall a user certificate.

**Possible Causes**

The user certificate is incorrect.

**Solution**

Check that the user certificate is correct.

## 9201002 Failed to Install the Application

**Error Message**

The application installation failed.

**Description**

This error code is reported when a device administrator application fails to install an enterprise application.

**Possible Causes**

1. The application installation path is empty or invalid, or does not exist.
2. The operation attempts to install multiple apps with different bundle names.
3. The application to be installed already exists when the installation parameter flag is 0.
4. The user ID is invalid.

**Solution**

1. Check that the application installation path is valid.
2. Check that all the installation parameters are valid.
3. Check that the same application is installed.
