# Permissions for Enterprise Applications

The following permissions are available to <!--Del-->system applications and <!--DelEnd-->enterprise applications. Enterprise applications include normal enterprise apps and Mobile Device Management (MDM) applications.

The distribution type of enterprise applications can be **enterprise_normal** (normal enterprise application) or **enterprise_mdm** (MDM application). You can <!--RP1-->obtain the distribution type from the **app-distribution-type** field in the [HarmonyAppProvision configuration file](../app-provision-structure.md).<!--RP1End-->

For details about how to request the permissions for enterprise applications, see [declaring permissions](declare-permissions.md).

## ohos.permission.SET_FILE_GUARD_POLICY

Allows an application to update the file guard policy.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 10

**Changelog**: For API versions 10 to 14, this permission is of the system_core level and available only to MDM applications. Starting from API version 14, the permission level is changed to system_basic and this permission is accessible to normal enterprise applications.

## ohos.permission.FILE_GUARD_MANAGER

Allows an application to scan media and sandbox and set file extended properties.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 10

**Changelog**: For API versions 10 to 14, this permission is of the system_core level and available only to MDM applications. Starting from API version 14, the permission level is changed to system_basic and this permission is accessible to normal enterprise applications.

## ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

Allows an application to interact across local accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 7

**Changelog**: This permission is available only to system applications in API versions 7 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.GET_RUNNING_INFO

Allows an application to obtain running status information of another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 7

**Changelog**: This permission is available only to system applications in API versions 7 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.RUNNING_STATE_OBSERVER

Allows an application to listen for the state of another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 7

**Changelog**: This permission is available only to system applications in API versions 7 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

Allows an application to obtain basic information and sensitive information about another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 7

**Changelog**: This permission is available only to system applications in API versions 7 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.GET_WIFI_CONFIG

Allows an application to obtain the Wi-Fi configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 8

**Changelog**: This permission is available only to system applications in API versions 8 to 14. From API version 15, it is available to normal enterprise applications.

## ohos.permission.SET_WIFI_CONFIG

Allows an application to configure Wi-Fi information.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 8

**Changelog**: This permission is available only to system applications in API versions 8 to 14. From API version 15, it is available to normal enterprise applications.

## ohos.permission.GET_DOMAIN_ACCOUNTS

Allows an application to obtain domain account information.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 10

**Changelog**: This permission is available only to system applications in API versions 10 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.QUERY_AUDIT_EVENT

Allows an application to query security audit events.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 12

**Changelog**: This permission is available only to MDM applications in API versions 12 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.KILL_APP_PROCESSES

Allows a system application to kill other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 12

**Changelog**: This permission is available only to system applications in API versions 7 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

Allows an application to manage Wi-Fi connections.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 15

## ohos.permission.ACCESS_ENTERPRISE_USER_TRUSTED_CERT

Allows an application to access the user CA certificates of enterprise devices.

With this permission, the enterprise application can install private CA certificates on enterprise devices and manage the installed certificates.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 18

## ohos.permission.MANAGE_NET_FIREWALL

Allows a system application to configure firewall rules.

Currently, this permission is available only to 2-in-1 device applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 12

**Changelog**: This permission is available only to system applications in API versions 12 to 14. From API version 15, it is available to normal enterprise applications.

## ohos.permission.GET_NET_FIREWALL

Allows a system application to obtain firewall rules and firewall interception records.

Currently, this permission is available only to 2-in-1 device applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 12

**Changelog**: This permission is available only to system applications in API versions 12 to 14. From API version 15, it is available to normal enterprise applications.

## ohos.permission.GET_DOMAIN_ACCOUNT_SERVER_CONFIGS

Allows an application to obtain domain account server configurations.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 18

## ohos.permission.MANAGE_DOMAIN_ACCOUNT_SERVER_CONFIGS

Allows an application to manage domain account server configurations.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 18

## ohos.permission.MANAGE_DOMAIN_ACCOUNTS

Allows an application to manage domain accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 18

## ohos.permission.GET_SIGNATURE_INFO

Allows an application to obtain the application package signature information.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 18

## ohos.permission.VISIBLE_WINDOW_INFO

Allows an application to obtain visible window information of the current screen.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 18
