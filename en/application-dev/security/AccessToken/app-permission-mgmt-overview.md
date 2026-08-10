# Application Permission Management Overview

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

## Introduction

The system provides a common permission access mode to allow applications to access system resources (such as contacts) and system capabilities (such as cameras and microphones), thereby protecting system data (including user personal data) and functions from improper or malicious use.

Application permissions are used to protect:

- Data, including personal data (such as photos, contacts, calendar, and location) and device data (such as device ID, camera data, and microphone data).

- Functionalities, including device functionalities (such as accessing the camera or microphone, making a call, and connecting to the Internet) and application functionalities (such as displaying a floating window and creating a shortcut).

## Basic Principles for Using Permissions

Determine the permissions required by your application based on the use cases of your application. Comply with the following principles when requesting permissions during application development:

- All the permissions required by your application (including third-party libraries referenced by your application) must be declared one by one in the application's configuration file. For details, see [Declaring Permissions](declare-permissions.md).

- Request only the least required permissions for your application. Do not apply for unnecessary or obsolete permissions. Excess permission requests can cause users to worry about application security and degrade user experience, thereby affecting the application's installation rate and retention rate.

- When requesting a sensitive permission, also specify the reason why this permission is required. Sensitive permissions are permissions closely related to user privacy, including those related to the location, camera, microphone, Calendar, fitness, body sensors, media, files, images and videos. For details, see [Requesting User Authorization](request-user-authorization.md).

- Sensitive permissions must be dynamically requested before the related service feature is provided.

- If a user refuses to grant a permission, other service features irrelevant to this permission can be used normally.

## Authorization Mode

Permissions can be classified into system_grant permissions, user_grant permissions, and manual_settings permissions based on the authorization mode.

### system_grant (System Authorization)

system_grant permissions are authorized by the system. The application with this type of permission cannot access user personal information.

For an application with a system_grant permission, the system automatically grants the permission to the application during the installation process.

### user_grant (User Authorization)

user_grant permissions are authorized by the user. The application with this type of permission can access user personal information.

This type of permissions must be declared in the application installation package and authorized by the user in a dialog box during the running of the application. The application has the permission only after the user has granted it.

### manual_settings (Manual Authorization)

From API version 21, **manual_settings** (manual authorization) is supported.

manual_settings permissions need to be manually set. The application with this type of permission can access user personal information, and the operations allowed may have a critical impact on the system or users.

This type of permissions must be declared in the application installation package and authorized by the user in the system settings. The application has the permission only after the user has set it.

## Permission Groups and Permissions

A permission group consists of user_grant permissions that are logically related to reduce the number of permission pop-up windows.

It helps minimize the number of dialogs that are presented to the user when an application requests closely related permissions. A permission in a permission group is called a sub-permission of the group.

The relationship between a permission group and its permissions is not fixed. For details about the permission groups supported by the current system, see [Application Permission Groups](app-permission-group-list.md).

## Basic Concepts in the Permission Mechanism

- **TokenID**

  Token identity (token ID or **TokenID**) uniquely identifies an application in the system. The AccessTokenManager (ATM) service manages the application Access Token (AT) information based on the token ID. The AT information includes the application ID, sub-user ID, twin index, Ability Privilege Level (APL), and permission grant status. When resources are required, the system uses the token ID as the unique identifier to obtain the application's permission grant status and performs authentication based on the information to control the resource access behavior of the application.

  In addition, the system supports the multi-user feature and the App Twin feature. Different sub-users and twin applications of the same application have their own AT information with different token IDs.

- APL

  To prevent applications from excessively requesting and abusing permissions, the system configures different permission scopes based on the APLs.

  The APL defines the priority of an application's permission request. Applications at different APLs can request different permissions.

- Application APL

  Application APLs are classified into three levels in ascending order of seniority.

  | APL| Description|
  | -------- | -------- |
  | normal | Default APL of an application.|
  | system_basic | Application that provides basic system services.|
  | system_core | Application that provides OS core abilities. <br>The APL of an application cannot be system_core.|

- Permission APL

  Permissions are granted to applications based on the application APL. The permission APLs are also classified into three levels in ascending order of seniority. 

  | APL| Description| Available To|
  | -------- | -------- | -------- |
  | normal | Allows an application to access common system resources beyond the default rules, such as configuring Wi-Fi and invoking the camera to take photos.<br>Access to these resources (including data and functions) has minor risks on user privacy and other applications.| Applications with the normal or higher APL.|
  | system_basic | Allows an application to access resources related to basic OS services (basic functions provided or preset by the system), such as system settings and identity authentication.<br>Access to these resources imposes high risks to user privacy and other applications.| - Applications with the system_basic or system_core APL.<br>- [Restricted permissions](restricted-permissions.md), which are some system_basic permissions that can be granted to normal applications via ACL.|
  | system_core | Allows an application to access OS core resources. These resources are underlying core services of the system. If these resources are corrupted, the OS cannot run properly.| - Applications with the system_core APL.<br>- System applications only.|

- ACL

  Permission APLs and application APLs are in one-to-one correspondence. In principle, an application with a lower APL cannot apply for higher-level permissions by default. However, you can use the Access Control List (ACL) to enable an application to have permissions beyond its APL.

  The **Certificate-based authorization** field is defined for all system permissions. When this field is set to **TRUE**, applications can request permissions across levels in ACL mode. For details about the definition of a permission, see [Restricted Permissions](restricted-permissions.md)<!--Del-->, [system_grant Permissions Available for System Applications via ACL](permissions-for-system-apps.md), and [user_grant Permissions for System Applications](permissions-for-system-apps-user.md)<!--DelEnd-->.

  For example, to implement a special feature, application A with the normal APL requires permission P, whose APL is system_basic. If **Certificate-based authorization** is **TRUE** for permission P, application A can request permission P via the ACL.

- Permission type with data

  In the traditional permission model, permissions are either allowed or denied — with limited information. This model cannot meet the increasing requirements for refined permission control.

  To address this challenge, the system introduces the permission key-value (KV) pairs that carry additional information. This permission type offers greater flexibility and adaptability to complex permission control models.

  The following uses [ohos.permission.ACCESS_DDK_DRIVERS](restricted-permissions.md#ohospermissionaccess_ddk_drivers) as an example.

  In scenarios involving extended peripherals, the system needs to manage diverse driver servers that can be connected to. This requires that the permissions carry specific server data. <!--Del-->In this case, you can use the data defined in [app-services-capabilities](declare-permissions-in-acl.md) to specify server information.<!--DelEnd-->
