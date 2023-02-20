# Enterprise Device Management Error Codes

## 9200001 Application Not a Device Administrator

**Error Message**

The application is not a administrator of the device.

**Description**

This error code is reported when the calling application is not an administrator of the device.

**Possible Causes**

The calling application has not been enabled as an administrator of the device.

**Solution**

Make sure the application is enabled as an administrator of the device.

## 9200002 Insufficient Permission for Systsm Administration

**Error Message**

The administrator application does not have permission to manage the device.

**Description**

This error code is reported when the API requires a permission level higher than that granted to the calling application.

**Possible Causes**

The application is a device administrator application, and the called API is restricted to a device super administrator application.

**Solution**

Make sure the enabled device administrator type is the same as that required by the called API.

## 9200003 Invalid Administrator Ability Component

**Error Message**

The administrator ability component is invalid.

**Description**

This error code is reported when the administrator ability component specified in the input parameters is invalid.

**Possible Causes**

The specified administrator ability component is invalid due to any of the following:
1. The administrator ability component does not exist when the application is enabled as a device administrator application.
2. The administrator ability component is not valid in an enterprise setting.

**Solution**

1. Make sure the name of the device administrator ability component is included in the application bundle when the application is enabled as a device administrator application.
2. Make sure the administrator ability component inherits the **EnterpriseAdminExtensionAbility** component defined by the enterprise device administrator framework.

## 9200004 Failed to Enable the Device Administrator Application

**Error Message**

Failed to activate the administrator application of the device.

**Description**

This error code is reported when the application fails to be enabled as a device administrator application.

**Possible Causes**

 
1. Multiple applications are enabled as super device administrators (SDAs). 
2. The application has been enabled as a device administrator, and the device administrator type has changed.
3. Multiple device administrator ability components of the same application are enabled.

**Solution**

1. Make sure only one application is enabled as SDA.
2. Check whether the application has been enabled as a device administrator and whether the device administrator type changes when it is enabled again. If this is the case, disable the device administrator and enable it again.
3. Check whether any ability component in the application has been enabled as the device administrator. Only one ability component in an application can be enabled as the device administrator.

## 9200005 Failed to Disable the Device Administrator Application

**Error Message**

Failed to deactivate the administrator application of the device.

**Description**

This error code is reported when the application to disable has not been enabled as a device administrator application or the attempt to disable the device administrator application is made by a device administrator application.

**Possible Causes**

 
1. The application to disable has not been enabled as a device administrator application.
2. The attempt to disable the device administrator application is made by a device administrator application.

**Solution**

1. Check whether the target application has been enabled as a device administrator application.
2. Check whether the specified ability component in the target application has been enabled as a device administrator.
3. Check whether the attempt to disable the device administrator application is made by a device administrator application.

## 9200006 Invalid User ID

**Error Message**

The specified user ID is invalid.

**Description**

This error code is reported when the application calls an API to set the user policy but the specified user ID does not exist or the specified user ID is different from the caller user ID.

**Possible Causes**

 
1. The user ID used to set a user policy does not exist.
2. The specified user ID is different from the caller user ID, and the application is not a super device administrator (SDA) application.

**Solution**

1. Make sure the user ID specified in the called API is valid.
2. Check whether the caller user ID and the specified user ID are the same. In non-SDA mode, policies cannot be set across users.

## 9200007 System Service Error

**Error Message**

The system ability work abnormally.

**Description**

This error code is reported when the enterprise device management service is not working correctly.

**Possible Causes**

 
1. The enterprise device management service is not started properly.
2. The RPC object for enterprise device management cannot be obtained.
3. Other services on which the enterprise device management service depends are not started properly or the RPC object cannot be obtained for them.
4. A system exception occurs during the running of the enterprise device management service.

**Solution**

Try again later or restart the device.

## 9200008 Invalid System Event Subscription

**Error Message**

The specified system events enum is invalid.

**Description**

This error code is reported when the enterprise device management module does not support subscription to the specified event or the specified event is invalid.

**Possible Causes**

The enterprise device management module does not support subscription to the specified event or the specified event is invalid.

**Solution**

Make sure the event to subscribe to is a valid management event supported by the enterprise device management module.
