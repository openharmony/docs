# Enterprise Device Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 9200001 DeviceAdmin Not Enabled

**Error Message**

The application is not an administrator application of the device.

**Description**

This error code is reported when the caller is not an enabled device administrator application.

**Possible Causes**

The enterprise device management APIs can be called only by a device administrator application that has been enabled.

**Solution**

Check whether the caller is a device administrator application that is enabled.

## 9200002 Permission Denied

**Error Message**

The administrator application does not have permission to manage the device.

**Description**

This error code is reported when the device administrator application does not have the permission to call the API.

**Possible Causes**

A device administrator application calls an API that is accessible only by a super administrator application.

**Solution**

Check that the device administrator type enabled for the caller is the same as that required by the API.

## 9200003 Invalid Administrator Ability Component

**Error Message**

The administrator ability component is invalid.

**Description**

This error code is reported when the specified device manager ability component is invalid.

**Possible Causes**

The specified administrator ability component is invalid due to any of the following causes:
1. The administrator ability component does not exist when the device administrator application is enabled.
2. The administrator ability component is not a valid enterprise administrator ability component.

**Solution**

1. Check that the name of the administrator ability component is included in the application bundle when the application is enabled as a device administrator application.
2. Check that the administrator ability component inherits from the **EnterpriseAdminExtensionAbility** component defined by the enterprise device management framework.

## 9200004 Failed to Enable the Device Administrator Application

**Error Message**

Failed to activate the administrator application of the device.

**Description**

This error code is reported when an application fails to be enabled as a device administrator application.

**Possible Causes**

1. Multiple applications are enabled as the super device administrator application.
2. The application has been enabled as a device administrator application, but the administrator type has changed.
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

1. The device administrator application to be disabled has not been enabled.
2. The caller cannot disable other device administrator applications.

**Solution**

1. Check whether the target device administrator application has been enabled.
2. Check whether the specified device administrator ability component of the target device administrator application has been enabled.
3. Check whether the device administrator application to be disabled is the caller itself.

## 9200006 Invalid User ID

**Error Message**

The specified user ID is invalid.

**Description**

This error code is reported when the specified user ID does not exist or the specified user ID is different from the caller's user ID.

**Possible Causes**

1. The user ID specified for setting a user policy does not exist.
2. When the application is not a super device administrator application, the specified user ID is different from the caller's user ID.

**Solution**

1. Check whether the specified user ID is valid and exists.
2. Check that the caller's user ID is the same as the specified user ID. If the application is not a super device administrator application, policies cannot be set across users.

## 9200007 System Ability Error

**Error Message**

The system ability works abnormally.

**Description**

This error code is reported when the enterprise device management ability is not working properly.

**Possible Causes**

1. The EnterpriseAdminAbility is not started.
2. The RPC object for enterprise device management cannot be obtained.
3. Other abilities, on which the EnterpriseAdminAbility depends, are not started, or the RPC object cannot be obtained.
4. A system exception occurs during the running of EnterpriseAdminAbility.

**Solution**

Try again later or restart the device.

## 9200008 Invalid System Event

**Error Message**

The specified system event is invalid.

**Description**

This error code is reported when the enterprise device management module does not support subscription to the specified event or the specified event is invalid.

**Possible Causes**

The enterprise device management module does not support subscription to the specified event or the specified event is invalid.

**Solution**

Check that the specified event is valid and supported by the enterprise device management module.

## 9200009 Failed to Grant Permissions to an Application

**Error Message**

Failed to grant the permission to the application.

**Description**

This error code is reported when the super device administrator application fails to grant administrator rights to other applications.

**Possible Causes**

The target application is not installed by the administrator.

**Solution**

Check that the target application has been installed by the administrator.

## 9200010 Policy Conflict

**Error Message**

A conflict policy has been configured.

**Description**

This error code is reported when a conflict policy is being delivered.

**Possible Causes**

A conflict policy is defined and to be delivered.

**Solution**

Resolve the conflict, and then deliver the policy.

## 9201001 Failed to Manage the Certificate

**Error Message**

Failed to manage the certificate.

**Description**

This error code is reported when the super device administrator application fails to install or uninstall a user certificate.

**Possible Causes**

The user certificate is incorrect.

**Solution**

Check that the user certificate is correct.

## 9201002 Failed to Install the Application

**Error Message**

Failed to install the application.

**Description**

This error code is reported when a device administrator application fails to install an enterprise application.

**Possible Causes**

1. The application installation path is empty or invalid, or does not exist.
2. The operation attempts to install multiple applications with different bundle names.
3. The application to be installed already exists when the installation parameter flag is 0.
4. The user ID is invalid.

**Solution**

1. Check that the application installation path is valid.
2. Check that all the installation parameters are valid.
3. Check that the same application is installed.

## 9201003 Failed to Add an Account

**Error Message**

Failed to add an OS account.

**Description**

This error code is reported when an account fails to be added.

**Possible Causes**

1. The account already exists.
2. The account name is invalid.
3. The network is not connected when the account is added.
4. The system does not support multiple accounts.

**Solution**

1. Check whether the account name exists. If yes, change the account name and try again.
2. Check that the account name is valid.
3. Check that the network is connected when the account is added.

## 9201004 Update Package Not Exist or Fails to be Parsed

**Error Message**

The update packages do not exist or analyzing failed.

**Description**

This error code is reported when the enterprise device administrator application fails to notify the system of the package update.

**Possible Causes**

1. The system update package does not exist.
2. The verification of the system update package name fails.
3. The system update package fails to be opened.
4. The system update package fails to be parsed.

**Solution**

1. Check whether the system update package exists.
2. Check whether the name of the system update package is valid.
3. Check whether the system update package is readable.
4. Check whether the system update package is complete.
