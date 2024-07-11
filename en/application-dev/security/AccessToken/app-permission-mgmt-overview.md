# Application Permission Management Overview

## Introduction

Application permissions are used to control the access to system resources (such as the Contacts) and system capabilities (such as the camera and microphone) to protect system data (including personal data) and functions.

Application permissions are used to protect:

- Data, including personal data (such as photos, Contacts, Calendar, and location) and device data (such as device ID, camera data, and microphone data).

- Functionalities, including device functionalities (such as accessing the camera or microphone, making a call, and connecting to the Internet) and application functionalities (such as displaying a floating window and creating a shortcut).

## Basic Principles for Using Permissions

Determine the permissions required by your application based on the use cases of your application. Comply with the following principles when applying for permissions during application development:

- All the permissions required by your application (including third-party libraries referenced by your application) must be declared one by one in the application's configuration file. For details, see [Declaring Permissions](declare-permissions.md).

- Request only the least required permissions for your application. Do not apply for unnecessary or obsolete permissions. Excess permission for an application may adversely affect user experience. When users have concern about the application security, they are reluctant to install or use the application.

- When requesting a sensitive permission, also specify the reason why this permission is required. Sensitive permissions are permissions closely related to user privacy, including those related to the location, camera, microphone, Calendar, fitness, body sensors, media, files, images and videos. For details, see [Requesting User Authorization](request-user-authorization.md).

- Sensitive permissions must be dynamically requested before the related service feature is provided.

- If a user refuses to grant a permission, other service features irrelevant to this permission can be used normally.

## Authorization Mode

Permissions can be classified into system_grant permissions and user_grant permissions based on the authorization mode.

### system_grant (System Authorization)

A system_grant permission is authorized by the system. The application with this type of permission cannot access user or device sensitive information, and the operations allowed have controllable impact on the system or other applications.

For an application with a system_grant permission, the system automatically grants the permission to the application during the installation process.

### user_grant (User Authorization)

A user_grant permission must be authorized by the user. An application with this type of permission may access user or device sensitive information, and the operations allowed may have a critical impact on the system or other applications.

This type of permissions must be declared in the application installation package and authorized by the user in a dialog box during the running of the application. The application has the permission only after user authorization.

For example, the permissions related to the microphone and camera in the [Permissions for All Applications](permissions-for-all.md) are user_grant permissions. The list of user_grant permissions must be presented on the application details page in the application market.

## Permission Groups and Permissions

A permission group consists of user_grant permissions that are logically related.

 It helps minimize the number of dialogs that are presented to the user when an application requests closely related permissions. A permission in a permission group is called a sub-permission of the group.

The relationship between a permission group and its permissions is not fixed. For details about the permission groups supported by the system, see [Application Permission Groups](app-permission-group-list.md).

## Basic Concepts in the Permission Mechanism

- TokenID

  Token identity (token ID or **TokenID**) uniquely identifies an application in the system. The AccessTokenManager (ATM) service manages the application Access Token (AT) information based on the token ID. The AT information includes the application ID, sub-user ID, application twin index, application Ability Privilege Level (APL), and permission grant status. When resources are required, the system uses the token ID as the unique identifier to obtain the application's permission grant status and performs authentication based on the information to control the resource access behavior of the application.

  In addition, the system supports the multi-user feature and the App Twin feature. Different users and the twin applications of the same application have their own AT information with different token IDs.

- APL

  Both the applications and permissions are assigned with different APLs to prevent abuse of permissions.

  The APL defines the application's priority for requesting permissions. Applications of different APLs can request permissions of different APLs.

- Application APL

  Application APLs are classified into three levels in ascending order of seniority.

  | APL| Description|
  | -------- | -------- |
  | normal | Default APL of an application.|
  | system_basic | Application that provides basic system services.|
  | system_core | Application that provides OS core abilities. <br>Only the APL of a system application or Mobile Device Management (MDM) application can be system_core.|

- Permission APL

  Permissions are granted to applications based on the application APL. The permission APLs are also classified into three levels in ascending order of seniority. 

  | APL| Description| Available To|
  | -------- | -------- | -------- |
  | normal | Allows an application to access common system resources beyond the default rules, such as configuring Wi-Fi and invoking the camera to take photos.<br>Access to these resources (including data and functions) imposes low risks on user privacy and other applications.| Applications with the normal or higher APL.|
  | system_basic | Allows an application to access resources related to basic OS services (basic functions provided or preset by the system), such as system settings and identity authentication.<br>Access to these resources imposes low risks to user privacy and other applications.| <!--RP1-->Applications with the system_basic or system_core APL.<!--RP1End--> |
  | system_core | Allows an application to access OS core resources, which are critical to underlying core services. If these resources are corrupted, the OS cannot run properly.| - Applications with the system_core APL.<br>- System applications only.|

- ACL

  Permission APLs and application APLs are in one-to-one correspondence. In principle, an application with a lower APL cannot request a permission with a higher APL. However, you can use the Access Control List (ACL) to enable an application to have permissions beyond its APL.

  All the system permissions are defined with the **Enable via ACL** field. If the value is true, the application can be granted to an application with a lower APL via the ACL. For the definition of a permission, see <!--RP2-->[Permissions for System Applications](permissions-for-system-apps.md)<!--RP2End-->.

  For example, to implement a special feature, application A with the normal APL requires permission P, whose APL is system_basic. If **Enable via ACL** is true for permission P, application A can request permission P via the ACL.
