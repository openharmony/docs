# Camera Development Preparations

The main process of camera application development includes development preparations, device input management, session management, preview, photographing, and video recording.

Before developing a camera application, you must request camera-related permissions (as described in the table below) to ensure that the application has the permission to access the camera hardware and other services. Before requesting permissions, ensure that the [basic principles for using permissions](../../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met.


| Permission| Description| Authorization Mode| 
| -------- | -------- | -------- |
| ohos.permission.CAMERA | Allows an application to use the camera to take photos and record videos.| user_grant | 
| ohos.permission.MICROPHONE | Allows an application to access the microphone.<br>This permission is required only if the application is used to record audio.| user_grant | 
| ohos.permission.WRITE_MEDIA | Allows an application to read media files from and write media files into the user's external storage. This permission is optional.| user_grant | 
| ohos.permission.READ_MEDIA | Allows an application to read media files from the user's external storage. This permission is optional.| user_grant | 
| ohos.permission.MEDIA_LOCATION | Allows an application to access geographical locations in the user's media file. This permission is optional.| user_grant | 


After configuring the permissions in the **module.json5** file, the application must call [abilityAccessCtrl.requestPermissionsFromUser](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to check whether the required permissions are granted. If not, request the permissions from the user by displaying a dialog box.


For details about how to request and verify the permissions, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).


> **NOTE**
> Even if the user has granted a permission, the application must check for the permission before calling an API protected by the permission. It should not persist the permission granted status, because the user can revoke the permission through the system application **Settings**.

## How to Develop

You can use either ArkTS or C++ APIs for camera development.

| Procedure| ArkTS Development| C++ Development|
| ------- | ------------- | --------- |
| Input management| [Device Input Management (ArkTS)](camera-device-input.md)| [Device Input Management (C/C++)](native-camera-device-input.md)|
| Session management| [Camera Session Management (ArkTS)](camera-session-management.md)| [Camera Session Management (C/C++)](native-camera-session-management.md)|
| Preview | [Camera Preview (ArkTS)](camera-preview.md)| [Camera Preview (C/C++)](native-camera-preview.md)|
| Secondary processing of preview streams| -  | [Secondary Processing of Preview Streams (C/C++)](native-camera-preview-imageReceiver.md)|
| Photographing| [Camera Photographing (ArkTS)](camera-shooting.md)| [Camera Photographing (C/C++)](native-camera-shooting.md)|
| Deferred photo delivery| [Deferred Photo Delivery (ArkTS)](camera-deferred-capture.md)| -  |
| Moving photos| [Moving Photos (ArkTS)](camera-moving-photo.md)| - |
| Recording| [Camera Recording (ArkTS)](camera-recording.md)| [Camera Recording (C/C++)](native-camera-recording.md)|
| Secondary processing of video streams| - | [Secondary Processing of Video Streams (C/C++)](native-camera-recording-imageReceiver.md)|
| Metadata| [Camera Metadata (ArkTS)](camera-metadata.md)| [Camera Metadata (C/C++)](native-camera-metadata.md)|
