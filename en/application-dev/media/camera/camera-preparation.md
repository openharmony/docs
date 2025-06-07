# Requesting Camera Development Permissions

The main process of camera application development includes development preparations, device input management, session management, preview, photo capture, and video recording.

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
