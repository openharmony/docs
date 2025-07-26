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

## ohos.permission.SET_NETWORK_INFO

Allows an application to set data network information.

With this permission, the application can activate or deactivate a network, and obtain and listen for network information.

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

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 9

**Changelog**: The permission level is system_basic in API versions 9 to 10 and changed to normal since API version 11.

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

## ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

Allows a system application to use infrared interfaces.

With this permission, the application can obtain the maximum frequency supported by the infrared module and send infrared signals at a specific frequency.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 12

**Changelog**: This permission is available to system applications in API versions 12 to 15, and becomes available to normal applications since API version 16.

## ohos.permission.INPUT_KEYBOARD_CONTROLLER

Allows an application to set the status of keyboard function keys.

With this permission, the application can turn on or off the function keys, such as **CapsLock**. This permission is available only to input method applications.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 15

## ohos.permission.SET_ABILITY_INSTANCE_INFO

Allows an application to set the icon and label information for each ability.

The configured icon and label information can be displayed in **Task Center** and the shortcut bar.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 15

## ohos.permission.NDK_START_SELF_UI_ABILITY

Allows an application to start its UIAbility by using C APIs.

Currently, this permission is available only to 2-in-1 device applications.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 15

## ohos.permission.GET_FILE_ICON

Allows an application to obtain the icon of the specified file type.

With this permission, the application can obtain the icon of the specified file type.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 17

## ohos.permission.DETECT_GESTURE

Allows an application to detect gestures.

With this permission, the application can detect information such as the user's holding posture and operating hand.

**Permission level**: normal

**Authorization mode**: system_grant

**Valid since**: 20

## ohos.permission.kernel.NET_RAW

Allows an application to capture network data packets.

With this permission, the application needs user authentication before it can capture network data packets. Otherwise, this operation is not allowed.

**Permission level**: normal

**Authorization mode**: system_grant

**Supported devices**: PC/2in1

**Valid since**: 20

## ohos.permission.kernel.DEBUGGER

Allows an application to obtain the debugging capability.

With this permission, the application, as the main process, can obtain the PTRACE debugging capability.

**Permission level**: normal

**Authorization mode**: system_grant

**Supported devices**: PC/2in1

**Valid since**: 20

## ohos.permission.kernel.ALLOW_DEBUG

Allows a C/C++ program to be debugged.

With this permission, the C/C++ program in the application can be debugged. However, the runtime memory may be dumped. Exercise caution when using this permission.

**Permission level**: normal

**Authorization mode**: system_grant

**Supported devices**: PC/2in1

**Valid since**: 20

## ohos.permission.BACKGROUND_MANAGER_POWER_SAVE_MODE

Allows an application to set its power-saving mode.

This permission is applicable to the applications that meet the following conditions: 
- The application does not gain the system focus or is not performing audio playback or UI refresh operations. 
- It cannot acquire a power lock through the framework layer. 
- It should not be forced into power-saving mode when CPU resources become constrained during the execution of time-consuming tasks such as compression, decompression, and compilation.

**Permission level**: normal

**Authorization mode**: system_grant

**Supported devices**: PC/2in1

**Valid since**: 20

## ohos.permission.SET_WINDOW_TRANSPARENT

Allows an application to set the main window container to be transparent and remove the shadow of the outer border of the main window.

With this permission, the application can set the background color and shadow visibility of the main window.

**Permission level**: normal

**Authorization mode**: system_grant

**Supported devices**: PC/2in1

**Valid since**: 20
