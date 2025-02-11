# Camera Development Preparations

The main process of camera application development includes development preparations, device input management, session management, preview, photo capture, and video recording.

## Requesting Permissions

Before developing a camera application, you must request camera-related permissions (as described in the table below) to ensure that the application has the permission to access the camera hardware and other services. Before requesting permissions, ensure that the [basic principles for using permissions](../../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met.

- To use the camera for photo capture, request the ohos.permission.CAMERA permission.
- To use the microphone to record audio, request the ohos.permission.MICROPHONE permission.
- To display location information in photos or videos captured, request the ohos.permission.MEDIA_LOCATION permission.

All these permissions must be authorized by users through a dialog box. For details about how to request and verify the permissions, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

- To read images or videos, you are advised to use the media library [Picker to access them](../medialibrary/photoAccessHelper-photoviewpicker.md).
- To save images or videos, use the [security components to save them](../medialibrary/photoAccessHelper-savebutton.md).
  
> **NOTE**
> 
> When the application needs to clone, back up, or synchronize images and videos in users' public directory, request the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions for reading and writing audio files. For details, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.

## How to Develop

You can use either ArkTS or C++ APIs for camera development.

| Procedure| ArkTS Development| C++ Development|
| ------- | ------------- | --------- |
| Input management| [Device Input Management (ArkTS)](camera-device-input.md)| [Device Input Management (C/C++)](native-camera-device-input.md)|
| Session management| [Camera Session Management (ArkTS)](camera-session-management.md)| [Camera Session Management (C/C++)](native-camera-session-management.md)|
| Preview | [Preview (ArkTS)](camera-preview.md)| [Preview (C/C++)](native-camera-preview.md)|
| Secondary processing of preview streams| -  | [Secondary Processing of Preview Streams (C/C++)](native-camera-preview-imageReceiver.md)|
| Photo capture| [Photo Capture (ArkTS)](camera-shooting.md)| [Photo Capture (C/C++)](native-camera-shooting.md)|
| Deferred photo delivery| [Deferred Photo Delivery (ArkTS)](camera-deferred-capture.md)| -  |
| Moving photos| [Moving Photos (ArkTS)](camera-moving-photo.md)| - |
| Video Recording| [Video Recording (ArkTS)](camera-recording.md)| [Video Recording (C/C++)](native-camera-recording.md)|
| Metadata| [Camera Metadata (ArkTS)](camera-metadata.md)| [Camera Metadata (C/C++)](native-camera-metadata.md)|
