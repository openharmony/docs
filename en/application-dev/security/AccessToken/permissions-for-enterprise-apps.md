# Permissions for Enterprise Applications

<!--Kit: ArkUI-->
<!--Subsystem: Security-->
<!--Owner: @harylee-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

The following permissions are open to <!--Del-->system applications and <!--DelEnd-->enterprise applications.

Enterprise applications include normal enterprise applications and mobile device management (MDM) applications.

Enterprise applications have the following characteristics:

- It runs only on enterprise-customized devices and does not run on common consumer devices.
- The distribution types are enterprise_normal (normal enterprise applications) and enterprise_mdm (MDM applications).
<!--RP1--><!--RP1End-->

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

Currently, the extended attributes include the file security level and file label.

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

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

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

With this permission, the application can obtain the runtime information of other applications, including the **Ability**, **Extension**, and **Application** information.

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

Allows an application to obtain basic information and sensitive information about another application,

such as the app bundle name and version.

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

**Supported devices**: PCs/2-in-1 devices

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 8

**Changelog**: This permission is available only to system applications in API versions 8 to 14. From API version 15, it is available to normal enterprise applications.

## ohos.permission.SET_WIFI_CONFIG

Allows an application to configure Wi-Fi information.

With this permission, the application can add and delete Wi-Fi networks, and modify Wi-Fi configurations.

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

Allows an enterprise security application to query security audit events.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 12

**Changelog**: This permission is available only to MDM applications in API versions 12 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.KILL_APP_PROCESSES

Allows a system application to kill other application processes.

With this permission, the system application can terminate other running applications and manage processes in the system when necessary.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 12

**Changelog**: This permission is available only to system applications in API versions 7 to 13. From API version 14, it is available to normal enterprise applications.

## ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

Allows a system application or carrier application to set the eSIM nickname and activate the eSIM.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Valid since**: 14

**Changelog**: The permission level is **normal** in API versions 13 and **system_basic** since API versions 14.

## ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

Allows an application to manage Wi-Fi connections.

With this permission, the application can enable or disable Wi-Fi, connect to Wi-Fi, and disconnect from Wi-Fi.

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

With this permission, the enterprise security application can block security audit events, including file creation, opening, and deletion.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.SUPPORT_APP_SERVICE_EXTENSION

Allows an application to be started as an **AppServiceExtension**.

With this permission, the application can be started or connected as an **AppServiceExtension** by the same application or an application in the **appidentifierAllowList** configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.ENTERPRISE_MANAGE_EAP

Allows enterprise network security software to add private information to EAP packets.

With this permission, the software can obtain 802.1X packets and add information to complete custom authentication.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.SUPPORT_INSTALL_ON_U1

Allows an application to be installed under User1.

User1 is a user who supports third-party applications running in singleton mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.QUERY_LOCAL_WORKSPACES

Allows a normal enterprise application to query workspaces and the list of workspaces that cannot be deleted.

With this permission, the application can query the basic information about workspaces and the workspaces that cannot be deleted.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.SET_NET_EXT_ATTRIBUTE

Allows an application to set network-specific extended attributes.

With this permission, the application can specify whether a network is identified as internal or external.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.MANAGE_ANTIVIRUS

Allows an enterprise application to manage antivirus software.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.REGISTER_ANTIVIRUS

Allows enterprise antivirus software to register with the system and update basic information.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.CALL_TPM_CMD

Allows an application to call Trusted Platform Module (TPM) commands.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.ENTERPRISE_WORKSPACES_EVENT_SUBSCRIBE

Allows an enterprise application to subscribe to events related to the enterprise workspace.

With this permission, the application can call **spaceManager.subscribeEvent** or **spaceManager.unsubscribeEvent** to subscribe to or unsubscribe from events related to the enterprise workspace.

**Permission level**: system_basic

**Authorization mode**: system_grant

<!--Del-->
**Enable via ACL**: true<!--DelEnd-->

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20
