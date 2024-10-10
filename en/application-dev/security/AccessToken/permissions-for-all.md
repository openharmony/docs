# Permissions for All Applications

Before requesting permissions for your application, read and understand the [Workflow for Using Permissions](determine-application-mode.md) and this topic to determine the permissions required.

> **NOTE**
> "Enable via ACL" is not involved for permissions of the normal level.

## system_grant Permissions

The [system_grant permissions](app-permission-mgmt-overview.md#system_grant-system-authorization) are permissions authorized by the system. For details about how to request this type of permissions, see [Declaring Permissions](declare-permissions.md).

### ohos.permission.USE_BLUETOOTH

Allows an application to access Bluetooth configurations.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

### ohos.permission.GET_BUNDLE_INFO

Allows an application to obtain basic information about another application.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.PREPARE_APP_TERMINATE

Allows an application to perform customized actions before being terminated.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 10

### ohos.permission.PRINT

Allows an application to obtain the print framework capability.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 10

### ohos.permission.DISCOVER_BLUETOOTH

Allows an application to configure Bluetooth on a device, initiate or cancel a scan for Bluetooth devices, and pair with Bluetooth devices.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

### ohos.permission.ACCELEROMETER

Allows an application to read data from an acceleration sensor, uncalibrated acceleration sensor, or linear acceleration sensor.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.ACCESS_BIOMETRIC

Allows an application to use biometric recognition for identity authentication.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 6

### ohos.permission.ACCESS_NOTIFICATION_POLICY

Allows an application to access the notification policy on the device.

This permission is required only when the ringtone needs to be changed from mute to unmute.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.GET_NETWORK_INFO

Allows an application to obtain network information.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

### ohos.permission.GET_WIFI_INFO

Allows an application to obtain Wi-Fi information.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

### ohos.permission.GYROSCOPE

Allows an application to read data from a gyroscope sensor or uncalibrated gyroscope sensor.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.INTERNET

Allows an application to access the Internet.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 9

### ohos.permission.KEEP_BACKGROUND_RUNNING

Allows a Service ability to keep running in the background.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

### ohos.permission.NFC_CARD_EMULATION

Allows an application to implement card emulation.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

### ohos.permission.NFC_TAG

Allows an application to read and write NFC tags.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.PRIVACY_WINDOW

Allows an application to set screens that cannot be captured or recorded.

**Permission level**: system_basic for API versions 9 to 10; normal for API version 11 and later

**Authorization mode**: system_grant

**Valid since**: 9

### ohos.permission.PUBLISH_AGENT_REMINDER

Allows an application to use agent-powered reminders.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.SET_WIFI_INFO

Allows an application to set a Wi-Fi device.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

### ohos.permission.VIBRATE

Allows an application to control vibration.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.CLEAN_BACKGROUND_PROCESSES

Allows an application to clear background processes based on their bundle names.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.COMMONEVENT_STICKY

Allows an application to publish sticky common events.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.MODIFY_AUDIO_SETTINGS

Allows an application to modify audio settings.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

### ohos.permission.RUNNING_LOCK

Allows an application to obtain a running lock.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.SET_WALLPAPER

Allows an application to set wallpapers.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

### ohos.permission.ACCESS_CERT_MANAGER

Allows an application to query certificates and private credentials.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 9

### ohos.permission.hsdr.HSDR_ACCESS

Allows an application to access OpenHarmony Security Detection and Response Framework.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 10

### ohos.permission.RUN_DYN_CODE

Allows an application to run dynamically delivered ArkCompiler bytecode when the ArkCompiler runtime engine is in restricted mode.

This permission is available only for certain system applications.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 11

### ohos.permission.READ_CLOUD_SYNC_CONFIG

Allows an application that has accessed the cloud to obtain its device-cloud synchronization configuration.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 11

### ohos.permission.STORE_PERSISTENT_DATA

Allows an application to store persistent data. The persistent data will be cleared only when the device's factory settings are restored or the system is reinstalled.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 11

### ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

Allows an application to use enhanced functions of the devices connected to this device.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 11

### ohos.permission.READ_ACCOUNT_LOGIN_STATE

Allows an application to read the login status of user accounts.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

### ohos.permission.ACCESS_SERVICE_NAVIGATION_INFO

Allows an application to access the navigation service.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

### ohos.permission.PROTECT_SCREEN_LOCK_DATA

Allows an application to protect its sensitive data from being accessed after the screen is locked.

After the application obtains this permission, a directory in **/el5** will be automatically created. Access to the data in this directory is denied after the screen is locked. There is no API for this permission.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

### ohos.permission.FILE_ACCESS_PERSIST

Allows an application to support persistent access to file URIs.

<!--RP2--><!--RP2End-->

**Permission level**: system_basic for API version 11 and normal for API versions 12 and later.

**Authorization mode**: system_grant

**Valid since**: 11

### ohos.permission.ACCESS_CAR_DISTRIBUTED_ENGINE

Allows an application to access the distributed travel service engine.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

### ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

Allows a system application or carrier application to set the eSIM nickname and activate the eSIM.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 13

### ohos.permission.WINDOW_TOPMOST

Allows an application to set pinned windows.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 13

## user_grant Permissions

The [user_grant permissions](app-permission-mgmt-overview.md#user_grant-user-authorization) are permissions granted by users. For details about how to request this type of permissions, see [Requesting User Authorization](request-user-authorization.md).

### ohos.permission.ACCESS_BLUETOOTH

Allows an application to access Bluetooth and use Bluetooth capabilities, such as pairing and connecting to peripheral devices.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 10

### ohos.permission.MEDIA_LOCATION

Allows an application to access geographical locations in the user's media file.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

### ohos.permission.APP_TRACKING_CONSENT

Allows an application to read the open anonymous device identifier (OAID).

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 9

### ohos.permission.ACTIVITY_MOTION

Allows an application to read the current workout status of the user, such as detecting whether the user is working out and recording the number of steps the user has taken.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

### ohos.permission.CAMERA

Allows an application to use the camera.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 9

### ohos.permission.DISTRIBUTED_DATASYNC

Allows the application data to be exchanged between devices.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

### ohos.permission.LOCATION_IN_BACKGROUND

Allows an application running in the background to obtain the device location.

For security purposes, this permission cannot be granted to applications in a dialog box. If an application needs this permission, direct the user to manually grant this permission on the **Settings** screen.

**Procedure**:

1. Request the foreground location permissions in the dialog box. You can request either of the following permissions:
   - Request [ohos.permission.APPROXIMATELY_LOCATION](#ohospermissionapproximately_location).
   - Request [ohos.permission.APPROXIMATELY_LOCATION](#ohospermissionapproximately_location) and [ohos.permission.LOCATION](#ohospermissionlocation).
2. After the user grants the foreground location permissions, display a message to direct the user to go to the **Settings** screen to grant the ohos.permission.LOCATION_IN_BACKGROUND permission.
3. The permission is granted to the application if the user selects **Always allow** on the **Settings** screen.

   Paths:
   <!--RP1-->
   - Path 1: **Settings** > **Privacy** > **Permission manager** > **Permissions** > **Location** > *Target application*
   - Path 2: **Settings** > **Privacy** > **Permission manager** > **Apps** > *Target application* > Location
   <!--RP1End-->

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

### ohos.permission.LOCATION

Allows an application to obtain the device location.

**Prerequisites**: This permission must be requested with [ohos.permission.APPROXIMATELY_LOCATION](#ohospermissionapproximately_location) together.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

### ohos.permission.APPROXIMATELY_LOCATION

Allows an application to obtain the approximate location information of a device.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 9

### ohos.permission.MICROPHONE

Allows an application to access the microphone.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 8

### ohos.permission.READ_CALENDAR

Allows an application to read Calendar data.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 8

### ohos.permission.WRITE_CALENDAR

Allows an application to add, remove, and modify Calendar events.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 8

### ohos.permission.READ_HEALTH_DATA

Allows an application to read the health data of the user.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

### ohos.permission.ACCESS_NEARLINK

Allows an application to use NearLink, such as device pairing and connecting to nearby devices.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 12

### ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

Allows an application to access the **Download** directory and its subdirectories in the user directory.

Currently, this permission is available only for 2-in-1 device applications.

<!--RP2--><!--RP2End-->

**Permission level**: system_basic for API version 11 and normal for API versions 12 and later.

**Authorization mode**: user_grant

**Valid since**: 11

### ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

Allows an application to access the **Documents** directory and its subdirectories in the user directory.

Currently, this permission is available only for 2-in-1 device applications.

<!--RP2--><!--RP2End-->

**Permission level**: system_basic for API version 11 and normal for API versions 12 and later.

**Authorization mode**: user_grant

**Valid since**: 11

### ohos.permission.READ_MEDIA

Allows an application to read media files from the user's external storage.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

**Deprecated from**: 12

**Substitute**:

See the [alternative solution of the **Files** permission group](app-permission-group-list.md#filesdeprecated).

### ohos.permission.WRITE_MEDIA

Allows an application to read media files from and write media files into the user's external storage.

**Permission level**: normal

**Authorization mode**: user_grant

**Valid since**: 7

**Deprecated from**: 12

**Substitute**:

See the [alternative solution of the **Files** permission group](app-permission-group-list.md#filesdeprecated).
