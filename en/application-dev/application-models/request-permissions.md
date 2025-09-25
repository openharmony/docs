# Requesting Permissions


If an application needs to obtain user privacy information or use system capabilities, for example, obtaining location information or using the camera to take photos or record videos, it must request the respective permission from users.


During application development, you must declare the required permission in the **config.json** file and call **requestPermissionsFromUser** to request the permission from users in the form of a dialog box.


To declare a permission in **config.json**, add **reqPermissions** under **module** and list the permission.

For example, to request the permission to access the calendar, perform the following steps:

1. Declare the ohos.permission.DISTRIBUTED_DATASYNC permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).
2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).
