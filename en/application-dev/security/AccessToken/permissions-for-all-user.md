# Open user_grant Permissions

<!--Kit: ArkUI-->
<!--Subsystem: Security-->
<!--Owner: @harylee-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

All the permissions in this topic are available to all applications and granted by the user.

This type of permissions must be declared in the application installation package and authorized by the user in a dialog box during the running of the application. The application has the permission only after the user has granted the permission.

<!--Del-->
> **NOTE**
> "Enable via ACL" is not involved for permissions of the normal level.
<!--DelEnd-->

## Request Mode

The [user_grant permissions](app-permission-mgmt-overview.md#user_grant-user-authorization) are permissions granted by users. For details about how to request this type of permissions, see [Declaring Permissions](declare-permissions.md) &gt; [Requesting User Authorization](request-user-authorization.md).

## ohos.permission.ACCESS_BLUETOOTH

Allows an application to access Bluetooth.

This permission enables features such as scanning, discovering, pairing with, and connecting to nearby Bluetooth devices, as well as advertising and scanning for Bluetooth Low Energy devices.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 10

## ohos.permission.MEDIA_LOCATION

Allows an application to access geographical locations in the user's media file.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

## ohos.permission.APP_TRACKING_CONSENT

Allows an application to read the open anonymous device identifier (OAID).

<!--RP3--><!--RP3End-->

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 9

## ohos.permission.ACTIVITY_MOTION

Allows an application to read the current workout status of the user, such as detecting whether the user is working out and recording the number of steps the user has taken.

For example, to determine whether the user is in motion or to record the number of steps that the user has walked.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

## ohos.permission.CAMERA

Allows an application to use the camera.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 9

## ohos.permission.DISTRIBUTED_DATASYNC

Allows the application data to be exchanged between devices.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

## ohos.permission.LOCATION_IN_BACKGROUND

Allows an application running in the background to obtain the device location.

For security purposes, this permission cannot be granted to applications in a dialog box. If an application needs this permission, direct the user to manually grant this permission on the **Settings** screen.

**Procedure**:

1. [Declare permissions](declare-permissions.md) in the **module.json5** file.

   You must request the foreground location permission before requesting the background permission. Therefore, you must declare both the ohos.permission.LOCATION_IN_BACKGROUND permission and the foreground location permission. The foreground location permissions include the following:
   - Request [ohos.permission.APPROXIMATELY_LOCATION](#ohospermissionapproximately_location).
   - Request [ohos.permission.APPROXIMATELY_LOCATION](#ohospermissionapproximately_location) and [ohos.permission.LOCATION](#ohospermissionlocation).
2. Request the foreground location permission from the user through a pop-up window.
3. After the user grants the foreground location permissions, display a message to direct the user to go to the **Settings** screen to grant the ohos.permission.LOCATION_IN_BACKGROUND permission.
4. The permission is granted to the application if the user selects **Always allow** on the **Settings** screen.

   Paths:
   <!--RP1-->
   - Path 1: **Settings** > **Privacy** > **Permission manager** > **Permissions** > **Location** > *Target application*
   - Path 2: **Settings** > **Privacy** > **Permission manager** > **Apps** > *Target application* > Location
   <!--RP1End-->

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

## ohos.permission.LOCATION

Allows an application to obtain the device location.

**Prerequisites**: This permission must be requested with [ohos.permission.APPROXIMATELY_LOCATION](#ohospermissionapproximately_location) together.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

## ohos.permission.APPROXIMATELY_LOCATION

Allows an application to obtain the approximate location information of a device.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 9

## ohos.permission.MICROPHONE

Allows an application to access the microphone.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 8

## ohos.permission.READ_CALENDAR

Allows an application to read Calendar data.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 8

## ohos.permission.WRITE_CALENDAR

Allows an application to add, remove, and modify Calendar events.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 8

## ohos.permission.READ_HEALTH_DATA

Allows an application to read the health data of the user.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

## ohos.permission.ACCESS_NEARLINK

Allows an application to use NearLink, such as device pairing and connecting to nearby devices.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 12

## ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

Allows an application to access the **Download** directory and its subdirectories in the user directory.

<!--RP2--><!--RP2End-->

**Permission level**: normal

**Authorization mode**: user_grant

**Supported devices**: PCs/2-in-1 devices | tablets

**Valid since**: 11

**Changelog**: The permission level is system_basic in API version 11, and is changed to normal since API version 12.

## ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

Allows an application to access the **Documents** directory and its subdirectories in the user directory.

<!--RP2--><!--RP2End-->

**Permission level**: normal

**Authorization mode**: user_grant

**Supported devices**: PCs/2-in-1 devices | tablets

**Valid since**: 11

**Changelog**: The permission level is system_basic in API version 11, and is changed to normal since API version 12.

## ohos.permission.CUSTOM_SCREEN_CAPTURE

Allows an application to capture screen information.

With this permission, the application can perform operations such as taking screenshots.

**Permission level**: normal

**Authorization mode**: user_grant

**Supported devices**: PCs/2-in-1 devices | tablets

**Valid since**: 14

## ohos.permission.READ_MEDIA

Allows an application to read media files from the user's external storage.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

**Deprecated from**: 12

**Substitute**:

See the [alternative solution of the **Files** permission group](app-permission-group-list.md#filesdeprecated).

## ohos.permission.WRITE_MEDIA

Allows an application to read media files from and write media files into the user's external storage.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

**Deprecated from**: 12

**Substitute**:

See the [alternative solution of the **Files** permission group](app-permission-group-list.md#filesdeprecated).
