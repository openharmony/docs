# Permissions for Enterprise Applications

The following permissions are available to <!--Del-->system applications and <!--DelEnd-->enterprise applications. Enterprise applications include normal enterprise apps and Mobile Device Management (MDM) applications.

The distribution type of enterprise applications can be **enterprise_normal** (normal enterprise application) or **enterprise_mdm** (MDM application). You can <!--RP1-->obtain the distribution type from the **app-distribution-type** field in the [HarmonyAppProvision configuration file](../app-provision-structure.md).<!--RP1End-->

For details about how to request the permissions for enterprise applications, see [declaring permissions](declare-permissions.md).

> **NOTE**
> 
> The following permissions do not support automatic code signing. You must [manually sign the code](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section297715173233) during the debugging and release phases.

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

## ohos.permission.FILE_GUARD_FILE_WRITE

Allows an enterprise application to modify files.

With this permission, the application can obtain the write permission on user files and modify them.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported Devices**：PC/2in1

**Valid since**：20

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

Currently, this permission is available only to applications running on PCs and 2-in-1 devices.

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

### ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

Allows a system application or carrier application to set the eSIM nickname and activate the eSIM.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 14

**Changelog**: Since API version 14, the permission level is changed to system_basic, and this permission is available only to normal enterprise applications instead of all applications.

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

## ohos.permission.kernel.AUTH_AUDIT_EVENT

Allows an enterprise security application to block security audit events.

With this permission, the application can block security audit events, such as events of file creation, file opening, and file deletion.

**Permission level**：system_basic

**Authorization mode**：system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PC/2in1

**Valid since**：20

## ohos.permission.SUPPORT_APP_SERVICE_EXTENSION

Allows an application to be launched as an AppServiceExtension.

With this permission, the application can be launched or connected as an AppServiceExtension by the same application or applications in appidentifierAllowList.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported Devices**：PC/2in1

**Valid since**：20

## ohos.permission.ENTERPRISE_MANAGE_EAP

Allows enterprise network security software to add private information to EAP packets.

With this permission, the software can obtain 802.1x packets and add information to complete customized authentication.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported Devices**：PC/2in1

**Valid since**：20

## ohos.permission.SUPPORT_INSTALL_ON_U1

Allows an application to install on user 1.

User 1 is a user who supports third-party applications running in singleton mode.

**Permission level**：system_basic

**Authorization mode**：system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PC/2in1

**Valid since**：20

## ohos.permission.QUERY_LOCAL_WORKSPACES

Allows a normal enterprise application to query workspace and the list of non-deletable workspaces.

With this permission, the application can query basic workspace information and the list of non-deletable workspaces.

**Permission level**：system_basic

**Authorization mode**：system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PC/2in1

**Valid since**：20

## ohos.permission.SET_NET_EXT_ATTRIBUTE

Allows an application to set network-specific extended attributes.

With this permission, the application can specify whether a network is identified as internal or external.

**Permission level**：system_basic

**Authorization mode**：system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PC/2in1

**Valid since**：20

## ohos.permission.CALL_TPM_CMD

Allows an application to call Trusted Platform Module(TPM) commands.

**Permission level**：system_basic

**Authorization mode**：system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PC/2in1

**Valid since**：20