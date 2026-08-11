# Requesting Camera Development Permissions

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=36759ebd9c79cee7975baec37f23a3d924106eb4 translatedAt=2026-08-10T09:14:38.532Z pushedAt=2026-08-10T11:56:06.923Z -->

The main process of camera application development includes development preparations, device input management, session management, preview, photo capture, and video recording.

Before developing a camera application, you must request camera-related permissions to ensure that the application has the permission to access the camera device and other services. Before requesting permissions, ensure that the [basic principles for using permissions](../../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met.

- To use the camera for photo capture, request the ohos.permission.CAMERA permission.

- To use the microphone to record audio, request the ohos.permission.MICROPHONE permission.

- To display location information in photos or videos captured, request the ohos.permission.MEDIA_LOCATION permission.

All these permissions must be authorized by users through a dialog box. For details about how to request and verify the permissions, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md) and [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

- To read images or videos, you are advised to use the media library [Picker to access them](../medialibrary/photoAccessHelper-photoviewpicker.md).

- To save images or videos, use the [security components to save them](../medialibrary/photoAccessHelper-savebutton.md).

> **NOTE**
> 
> - When the user denies authorization in the pop-up window, you can call [isCameraMuted](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#iscameramuted) to check whether the camera is currently muted.
> - Only when the app needs to clone, back up, or sync image and video files in the user's public directory, you can apply for the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions to read and write image/video files. For details about how to apply, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.