# Camera Development Preparations

The main process of camera application development includes development preparations, device input management, session management, preview, photographing, and video recording.

Before developing a camera application, you must request camera-related permissions (as described in the table below) to ensure that the application has the permission to access the camera hardware and other services. Before requesting the permission, ensure that the [basic principles for permission management](../security/accesstoken-overview.md#basic-principles-for-permission-management) are met.


| Permission| Description| Authorization Mode|
| -------- | -------- | -------- |
| ohos.permission.CAMERA | Allows an application to use the camera to take photos and record videos.| user_grant |
| ohos.permission.MICROPHONE | Allows an application to access the microphone.<br>This permission is required only if the application is used to record audio.| user_grant |
| ohos.permission.WRITE_MEDIA | Allows an application to read media files from and write media files into the user's external storage. This permission is optional.| user_grant |
| ohos.permission.READ_MEDIA | Allows an application to read media files from the user's external storage. This permission is optional.| user_grant |
| ohos.permission.MEDIA_LOCATION | Allows an application to access geographical locations in the user's media file. This permission is optional.| user_grant |


After configuring the permissions in the **module.json5** file, the application must call [abilityAccessCtrl.requestPermissionsFromUser](../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to check whether the required permissions are granted. If not, request the permissions from the user by displaying a dialog box.


For details about how to request and verify the permissions, see [Permission Application Guide](../security/accesstoken-guidelines.md).


> **NOTE**
>
> Even if the user has granted a permission, the application must check for the permission before calling an API protected by the permission. It should not persist the permission granted status, because the user can revoke the permission through the system application **Settings**.
