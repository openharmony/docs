# Open system_grant Permissions

All the permissions in this topic are available to all applications and granted by the system.

After an application requests this type of permissions, the system automatically grants the permissions to the application when the application is installed.

<!--Del-->
> **NOTE**
> "Enable via ACL" is not involved for permissions of the normal level.
<!--DelEnd-->

## Request Mode

The [system_grant permissions](app-permission-mgmt-overview.md#system_grant-system-authorization) are permissions authorized by the system. For details about how to request this type of permissions, see [Declaring Permissions](declare-permissions.md).

## ohos.permission.USE_BLUETOOTH

Allows an application to access Bluetooth configurations.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

## ohos.permission.GET_BUNDLE_INFO

Allows an application to obtain basic information about another application.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.PREPARE_APP_TERMINATE

Allows an application to perform customized actions before being terminated.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 10

## ohos.permission.PRINT

Allows an application to obtain the print framework capability.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 10

## ohos.permission.DISCOVER_BLUETOOTH

Allows an application to configure Bluetooth on a device, initiate or cancel a scan for Bluetooth devices, and pair with Bluetooth devices.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

## ohos.permission.ACCELEROMETER

Allows an application to read data from an acceleration sensor, uncalibrated acceleration sensor, or linear acceleration sensor.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.ACCESS_BIOMETRIC

Allows an application to use biometric recognition for identity authentication.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 6

## ohos.permission.ACCESS_NOTIFICATION_POLICY

Allows an application to access the notification policy on the device.

This permission is required only when the ringtone needs to be changed from mute to unmute.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.GET_NETWORK_INFO

Allows an application to obtain network information.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

## ohos.permission.GET_WIFI_INFO

Allows an application to obtain Wi-Fi information.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

## ohos.permission.GYROSCOPE

Allows an application to read data from a gyroscope sensor or uncalibrated gyroscope sensor.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.INTERNET

Allows an application to access the Internet.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 9

## ohos.permission.KEEP_BACKGROUND_RUNNING

Allows a Service ability to keep running in the background.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

## ohos.permission.NFC_CARD_EMULATION

Allows an application to implement card emulation.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

## ohos.permission.NFC_TAG

Allows an application to read and write NFC tags.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.PRIVACY_WINDOW

Allows an application to set screens that cannot be captured or recorded.

**Permission level**: system_basic for API versions 9 to 10; normal for API version 11 and later

**Authorization mode**: system_grant

**Valid since**: 9

## ohos.permission.PUBLISH_AGENT_REMINDER

Allows an application to use agent-powered reminders.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.SET_WIFI_INFO

Allows an application to set a Wi-Fi device.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

## ohos.permission.VIBRATE

Allows an application to control vibration.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.CLEAN_BACKGROUND_PROCESSES

Allows an application to clear background processes based on their bundle names.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.COMMONEVENT_STICKY

Allows an application to publish sticky common events.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.MODIFY_AUDIO_SETTINGS

Allows an application to modify audio settings.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 8

## ohos.permission.RUNNING_LOCK

Allows an application to obtain a running lock.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.SET_WALLPAPER

Allows an application to set wallpapers.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 7

## ohos.permission.ACCESS_CERT_MANAGER

Allows an application to query certificates and private credentials.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 9

## ohos.permission.hsdr.HSDR_ACCESS

Allows an application to access OpenHarmony Security Detection and Response Framework.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 10

## ohos.permission.RUN_DYN_CODE

Allows an application to run dynamically delivered ArkCompiler bytecode when the ArkCompiler runtime engine is in restricted mode.

The APIs related to this permission are system APIs, and this permission is available only to specific system applications.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 11

## ohos.permission.READ_CLOUD_SYNC_CONFIG

Allows an application that has accessed the cloud to obtain its device-cloud synchronization configuration.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 11

## ohos.permission.STORE_PERSISTENT_DATA

Allows an application to store persistent data. The persistent data will be cleared only when the device's factory settings are restored or the system is reinstalled.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 11

## ohos.permission.ACCESS_EXTENSIONAL_DEVICE_DRIVER

Allows an application to use enhanced functions of the devices connected to this device.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 11

## ohos.permission.READ_ACCOUNT_LOGIN_STATE

Allows an application to read the login status of user accounts.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

## ohos.permission.ACCESS_SERVICE_NAVIGATION_INFO

Allows an application to access the navigation service.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

## ohos.permission.PROTECT_SCREEN_LOCK_DATA

Allows an application to protect its sensitive data from being accessed after the screen is locked.

After the application obtains this permission, a directory in **/el5** will be automatically created. Access to the data in this directory is denied after the screen is locked.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

## ohos.permission.FILE_ACCESS_PERSIST

Allows an application to support persistent access to file URIs.

<!--RP2--><!--RP2End-->

**Permission level**: system_basic for API version 11 and normal for API versions 12 and later.

**Authorization mode**: system_grant

**Valid since**: 11

## ohos.permission.ACCESS_CAR_DISTRIBUTED_ENGINE

Allows an application to access the distributed travel service engine.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

## ohos.permission.WINDOW_TOPMOST

Allows an application to set pinned windows.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 13

## ohos.permission.USE_MESSAGES_PICKER

Allows an application to use the message Picker to obtain SMS messages.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Valid since**: 16

## ohos.permission.USE_CALL_LOG_PICKER

Allows an application to use the call log Picker to obtain call logs.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Valid since**: 16

### ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY

Allows an application to have its system JS engine to apply for anonymous executable memory with the MAP_FORT identifier.

After the application has this permission, the system JS engine can request anonymous executable memory with MAP_FORT for just-in-time (JIT) compilation, which increase the runtime execution efficiency.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Valid since**: 14

<!--Del-->
### ohos.permission.PRELOAD_FILE

Allows an application to preload files to improve file opening speed.

This permission is available only to document editing applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Valid since**: 15
<!--DelEnd-->

### ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

Allows a system application to use infrared interfaces.

With this permission, the application can query the maximum frequency supported by the infrared 
and send infrared signals of a specific frequency.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

**Changelog**: This permission is available to system applications in API versions 12 to 15,
and available to normal applications since API version 16.

### ohos.permission.INPUT_KEYBOARD_CONTROLLER

Allows an application to set the status of keyboard function keys.

With this permission, the application can turn on or off the function keys, such as CapsLock.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 15

### ohos.permission.NDK_START_SELF_UI_ABILITY

Allows an application to start its UIAbility by using C API.

Currently, this permission is available only to 2-in-1 device applications.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 15
