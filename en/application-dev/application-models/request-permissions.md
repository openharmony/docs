# Requesting Permissions


If an application needs to obtain user privacy information or use system capabilities, for example, obtaining location information or using the camera to take photos or record videos, it must request the respective permission from users.


During application development, you must declare the required permission in the **config.json** file and call **requestPermissionsFromUser** to request the permission from users in the form of a dialog box.


To declare a permission in **config.json**, add **reqPermissions** under **module** and list the permission.

For example, to request the permission to access the calendar, perform the following steps:

1. Request the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).
2. Display a dialog box to ask authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).
