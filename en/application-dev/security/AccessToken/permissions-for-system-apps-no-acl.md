# system_grant Non-ACL Permissions for System Applications

Before requesting permissions for your application, read and understand the [permission request paths](determine-application-mode.md) and this topic to determine the permissions required.

> **NOTE**
>
> - The permissions listed in this topic are available to system_basic or system_core applications, but not to normal applications.
> - The authorization mode of these permissions is system_grant.
> - These permissions cannot be requested via access control list (ACL).

For details about the process for requesting the permissions, see [Workflow for Requesting Permissions](determine-application-mode.md).

## ohos.permission.RECEIVER_STARTUP_COMPLETED

Allows an application to subscribe to the startup broadcast.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

## ohos.permission.SYSTEM_LIGHT_CONTROL

Allows an application to control lights, including turning on and off lights.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 11

## ohos.permission.QUERY_ACCESSIBILITY_ELEMENT

Allows an application to query accessibility elements in batches.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 11

## ohos.permission.GET_ALL_APP_ACCOUNTS

Allows an application to obtain information about all application accounts.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 7

## ohos.permission.MANAGE_DEVICE_AUTH_CRED

Allows an application to call interfaces of the DeviceAuthCredMgr application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

## ohos.permission.ACCESS_AUTH_RESPOOL

Allows an SA to register the executor.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

## ohos.permission.READ_ACCESSIBILITY_CONFIG

Allows an application to read the accessibility configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

## ohos.permission.WRITE_APP_PUSH_DATA

Allows the push service to write data to an application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

## ohos.permission.READ_APP_PUSH_DATA

Allows the push service to read data from an application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

## ohos.permission.NETSYS_INTERNAL

Allows an SA to call the network diagnosis, Wi-Fi, network adapter listening, and iptables setting APIs of **netsys**.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

## ohos.permission.DISTRIBUTED_SOFTBUS_CENTER

Allows networking between different devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

## ohos.permission.RESTRICT_APPLICATION_ACTIVE

Allows a standby component to publish a customized network limit event.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

## ohos.permission.CONNECT_CELLULAR_CALL_SERVICE

Allows a system service to access the cellular call SA.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

## ohos.permission.CONNECT_IMS_SERVICE

Allows a system service to access the IMS SA.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

## ohos.permission.ENFORCE_USER_IDM

Allows an SA to delete the IAM user information without a token.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

## ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Allows an application to set the accessibility configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

## ohos.permission.ENABLE_DISTRIBUTED_HARDWARE

Allows a system service to enable distributed hardware resources.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 11

## ohos.permission.ACCESS_SUPER_HUB

Allows an application to access Super Hub.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 12

## ohos.permission.CALLED_UIEXTENSION_ON_LOCK_SCREEN

Allows a UIExtensionAbility to be displayed on the locked screen.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 14

## ohos.permission.USE_USER_ACCESS_MANAGER

Allows an application to query and configure user identity authentication policies, and verify the authentication result.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 18

## ohos.permission.SET_LAUNCH_REASON_MESSAGE

Allows a system application to set the launch reason when starting another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 18

## ohos.permission.ACCESS_USER_ACCOUNT_INFO

Allows a system application to access user account information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 18
