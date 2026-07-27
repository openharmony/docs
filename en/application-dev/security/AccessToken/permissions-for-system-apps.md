# system_grant Permissions Available for System Applications via ACL

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

Before requesting permissions for your application, read and understand the [permission request paths](determine-application-mode.md) and this topic to determine the permissions required.

> **NOTE**
>
> - The permissions listed in this topic are available to system_basic or system_core applications, but not to normal applications.
> - The authorization mode of these permissions is system_grant.
> - Applications of a lower APL can request these permissions via [Access Control List (ACL)](app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).

For details about the process for requesting permissions, see [Workflow for Requesting Permissions](determine-application-mode.md).

## ohos.permission.SET_WALLPAPER

Allows an application to set wallpapers.

**Permission level**: normal

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.MODIFY_AUDIO_SETTINGS

Allows an application to modify audio settings.

**Permission level**: normal

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.RECEIVER_STARTUP_COMPLETED

Allows an application to subscribe to the startup broadcast.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.PRE_START_ATOMIC_SERVICE

Allows a window to be displayed with animation for an atomic service without the loading dialog box.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_APP_KEEP_ALIVE

Allows a system service to set the keep-alive flag for other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 14

**Supported devices**: PCs/2-in-1 devices | wearables

## ohos.permission.ACCESS_BBOX_DIR

Allows a system application to access the bbox directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.CONTROL_LOCATION_SWITCH

Allows an application to turn on and off the location service.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.LOCATION_SWITCH_IGNORED

Allows a system application to obtain location information when the location switch is turned off.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.SUBSCRIBE_SWING_ABILITY

Allows an application to use the subscription capability powered by smart sensing.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGER_SWING_MOTION

Allows an application to use the air gesture adaptation capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MOCK_LOCATION

Allows an application to use the mock location function.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_LEARN_MORE_DIALOG

Allows a system application to display the **Learn more** dialog for detailed information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.WRITE_PROTECTION_ADVICE_POLICY

Allows a system application to modify the protection advice database.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 17

## ohos.permission.READ_PROTECTION_ADVICE_POLICY

Allows a system application to read the protection advice database

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 17

## ohos.permission.PROXY_MESSAGE_AUTH

Allows a system application to call the Message application authorization interface.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Since**: 18

## ohos.permission.MANAGE_SETTINGS

Allows an application to set the device-level configuration table and user-level configuration table in **SettingsData**.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SCREEN_LOCK

Allow an application to access screen lock and unlock information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ALLOW_UPGRADE_GUIDE_ACCESS

Allows a system application to obtain the application upgrade guide or start the application upgrade component.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_MEDIALIB_THUMB_DB

Allows a system application to access and modify the media library database.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.AGENT_REQUIRE_FORM

Allows the application agent to request widgets.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_VPN

Allows a system application to enable or disable the VPN function.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

**Changelog**: For APIs versions 10 and 11, **Certificate-based authorization** is **false**. For API 12 and later, it is changed to **true**.

## ohos.permission.WAKEUP_VISION

Allows an application to access the AI Voice vision component.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.WAKEUP_VOICE

Allows an application to access the AI Voice wakeup component.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ATTEST_KEY

Allows an application to obtain the certificate chain that attests the key validity.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.GET_PHONE_NUMBERS

Allows an application to obtain the phone numbers of the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.ACTIVATE_THEME_PACKAGE

Allows a system application to set themes, including wallpapers, icons, skins, Always On Display (AOD), and fonts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.THEME_SKIN

Allows a system application to obtain theme skinning resources in the skin directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.READ_ACCESSIBILITY_CONFIG

Allows an application to read the accessibility configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Allows an application to set the accessibility configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.QUERY_ACCESSIBILITY_ELEMENT

Allows an application to query accessibility elements in batches.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.SET_UNREMOVABLE_NOTIFICATION

Allows an application to publish unremovable notifications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.UNINSTALL_BUNDLE

Allows an application to uninstall applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.RECOVER_BUNDLE

Allows pre-installed applications to be recovered.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.UPDATE_SYSTEM

Allows an application to call the update APIs.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.FACTORY_RESET

Allows an application to call the API for restoring factory settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.FORCE_FACTORY_RESET

Allows a system application to forcibly restore a device to its factory settings, which cannot be interrupted.

**Permission level**: system_core

**Authorization mode**: system_grant

**Supported devices**: general devices

**Certificate-based authorization**: true

**Since**: 23

## ohos.permission.ASSIST_DEVICE_UPDATE

Allows an application to start the upgrade service to perform assisted or collaborative update for other devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.PLUGIN_UPDATE

Allows a system application or system service to call the update APIs to download and update plug-ins and AI models.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.RECEIVE_UPDATE_MESSAGE

Allows a system application or system service to listen for the key events occurred in the system update process.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.GET_ALL_PROCESSES

Allows a system application or system service to read files in **/proc**.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_LOCAL_ACCOUNTS

Allows an application to manage local accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.ACCESS_SYSTEM_SETTINGS

Allows an application to access or start **Settings**.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.SET_ABILITY_CONTROLLER

Allows an application to intercept the startup of the Ability component. This permission is used for testing, such as the stability test.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

Allows an application to interact across local accounts.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.CLEAN_APPLICATION_DATA

Allows an application to clear application data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.START_ABILITIES_FROM_BACKGROUND

Allows an application to start or access other components from the background.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MANAGE_MISSIONS

Allows an application to manage missions in the system.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

Allows an application to activate a device administrator application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.ENTERPRISE_CONFIG

Allows an application to activate enterprise devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | wearables

**Since**: 12

## ohos.permission.RECEIVE_ENTERPRISE_POLICY_EVENT

Allows a system application to subscribe to the policy events published by the Enterprise Device Management service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 14

## ohos.permission.PUBLISH_SYSTEM_COMMON_EVENT

Allows an application to publish system common events.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.NOTIFICATION_CONTROLLER

Allows an application to manage and subscribe to notifications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.CLOUDDATA_CONFIG

Allows an application to obtain the device-cloud information of the configuration database.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.GET_DEFAULT_APPLICATION

Allows an application to query default applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MANAGE_INTELLIGENT_VOICE

Allows an application to access the intelligent voice service APIs.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.POWER_MANAGER

Allows an application to hibernate or wake up the device by calling an API of the power management subsystem.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.GET_SCENE_CODE

Allows an application to obtain the scene code of the specified application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.MANAGE_ECOLOGICAL_RULE

Allows the rules for generating the scene code and the matching experience to be set for the manager service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.INSTALL_ENTERPRISE_BUNDLE

Allows an application to install enterprise InHouse applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.INSTALL_BUNDLE

Allows an application to install and uninstall other applications except enterprise applications, including enterprise InHouse, mobile device management (MDM), and Normal applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.INSTALL_ALLOW_DOWNGRADE

Allows an application to downgrade other applications.

With this permission, an application can perform downgrade installation of other applications, even if a later version already exists.

**Permission level**: system_core

**Authorization mode**: system_grant

**Supported devices**: general devices

**Certificate-based authorization**: true

**Since**: 23

## ohos.permission.MANAGE_SHORTCUTS

Allows an application to query and start shortcuts of other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.OBSERVE_FORM_RUNNING

Allows an application to listen for the card running status.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.WRITE_HIVIEW_SYSTEM

Allows an application to modify HiView data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.READ_HIVIEW_SYSTEM

Allows an application to access HiView data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.READ_DFX_SYSEVENT

Allows an application to access system event logging data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | TVs | wearables | PCs/2-in-1 devices | tablets | cars

**Valid since**: 8

## ohos.permission.READ_DFX_XPOWER

Allows an application to read XPower data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | TVs | wearables | PCs/2-in-1 devices | tablets | cars

**Since**: 12

## ohos.permission.PERMISSION_USED_STATS

Allows a system application to access the permission usage records.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | TVs | wearables | PCs/2-in-1 devices | tablets | cars

**Since**: 9

## ohos.permission.PERMISSION_RECORD_TOGGLE

Allows an application to set the permission usage record switch.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.CAPTURE_SCREEN

Allows an application to take screenshots.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

Allows an application to install, uninstall, and authorize users' public certificate credentials.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

**Changelog**: The permission level is system_basic in API versions 9 to 11, and is changed to system_core since API version 12.

## ohos.permission.CLOUDFILE_SYNC

Allows an application to perform device-cloud synchronization.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.CHANGE_OVERLAY_ENABLED_STATE

Allows a system application to disable the application with the overlay feature enabled.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.ACCESS_SCREEN_LOCK_INNER

Allows an application to use the lock screen service to lock the screen, send a screen lock event, and invoke the system event callback.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.BACKUP

Allows an application to use the backup and restore capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MOUNT_FORMAT_MANAGER

Allows an application to format external cards.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MOUNT_UNMOUNT_MANAGER

Allows an application to mount and unmount external cards.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.PROXY_AUTHORIZATION_URI

Allows the application to act as a proxy for granting URI permissions.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.ACCESS_CAST_ENGINE_MIRROR

Allows an application to use the mirror projection capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.ACCESS_CAST_ENGINE_STREAM

Allows an application to invoke the system resource projection capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE

Allows an enterprise normal bundle to be installed on enterprise devices.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.INSTALL_ENTERPRISE_MDM_BUNDLE

Allows installation of enterprise MDM applications on enterprise devices.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.INSTALL_SELF_BUNDLE

Allows enterprise MDM applications to self-update on enterprise devices.

**Permission level**: system_core

**Authorization mode**: system_grant


**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.UPDATE_MIGRATE

Allows data migration during the update process.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.MANAGE_SENSOR

Allows an application that cannot directly use the sensor to turn on and off the sensor.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.MANAGE_PRINT_JOB

Allows an application to obtain the capability of managing print tasks.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.securityguard.SET_MODEL_STATE

Allows an application to control the SecurityGuard model switch.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.UNLOCK_DEVELOPER_MODE

Allows an application to unlock the developer mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO

Allows an application to capture the downlink voice audio.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.GET_WIFI_INFO_INTERNAL

Allows a system process to obtain Wi-Fi parameters.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.ACCESS_BUNDLE_DIR

Allows an application to access the installation directory of another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.CHANGE_ABILITY_ENABLED_STATE

Allows an application to enable or disable an application or component.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.CLOUDFILE_SYNC_MANAGER

Allows an application to obtain the device-cloud synchronization management capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.DUMP

Allows the basic system information and system ability (SA) information to be dumped.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.HIVIEW_TRACE_MANAGE

Allows a system service or system application to enable or disable system trace.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.DEVICE_STANDBY_EXEMPTION

Allows an application to use resources when the system is in standby mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.PERCEIVE_SMART_POWER_SCENARIO

Allows an application to perceive smart power scenarios.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_CAMERA_CONFIG

Allows an application to enable or disable cameras globally.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MANAGE_AUDIO_CONFIG

Allows an application to mute microphones globally.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MICROPHONE_CONTROL

Allows an application to control the microphone, for example, persisting the mute of the microphone globally.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.CAPTURE_PLAYBACK

Allows a system service to capture audio without using the AVScreenCapture framework.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.MICROPHONE_BACKGROUND

Allows a system application to use the microphone in the background.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.START_DLP_CRED

Allows a system application or system service to start the DLP credential management application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs

**Since**: 12

## ohos.permission.START_SHORTCUT

Allows an application to start shortcuts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.PRELOAD_UI_EXTENSION_ABILITY

Allows an application to preload a UIExtensionAbility instance.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_DISPOSED_APP_STATUS

Allows an application to set and query the application handling state.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.GET_DISPOSED_APP_STATUS

Allows an application to obtain the disposed application status.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.FILE_ACCESS_MANAGER

Allows a file management application to access public data files through the FAF.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.ACCESS_PUSH_SERVICE

Allows an application to access the Ability of the push service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MANAGE_NET_STRATEGY

Allows an application to obtain network strategy information or modify network strategy settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO

Allows an application to obtain detailed security event information.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.securityguard.REPORT_SECURITY_INFO

Allows an application to report risk data for security guard.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.GET_SENSITIVE_PERMISSIONS

Allows an application to obtain the sensitive permissions that have been granted to other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.ACCESS_SERVICE_DM

Allows a system application to obtain the authentication and networking capability of distributed devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.UPLOAD_SESSION_MANAGER

Allows an application to manage the upload sessions.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.ABILITY_BACKGROUND_COMMUNICATION

Allows an application to start the Ability component in the background and establish a connection with it.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.ACCESS_DLP_FILE

Allows configuration and management of the permissions on .dlp files.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs

**Since**: 9

## ohos.permission.ACCESS_IDS

Allows an application to query the unique identifier of a device.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.ACCESS_MISSIONS

Allows an application to obtain information about missions in a mission stack.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

**Deprecated since**: 9

## ohos.permission.BUNDLE_ACTIVE_INFO

Allows an application to obtain how long other applications have been running in the foreground or background.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.CONNECT_IME_ABILITY

Allows an application to bind the InputMethodAbility.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.CONNECT_SCREEN_SAVER_ABILITY

Allows an application to bind the ScreenSaverAbility.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.CONNECTIVITY_INTERNAL

Allows an application to obtain network information or modify network settings. Currently, this permission is available only to system applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.CONTROL_TASK_SYNC_ANIMATOR

Allows an application to use sync task animations.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.DOWNLOAD_SESSION_MANAGER

Allows an application to manage the download sessions.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.GET_DISTRIBUTED_ACCOUNTS

Allows an application to obtain information about distributed accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.GET_LOCAL_ACCOUNTS

Allows an application to obtain information about local accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.GET_TELEPHONY_STATE

Allows an application to read telephony information. 

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.ACCESS_BOOSTER_SERVICE

Allows a system service or system application to call network booster service APIs, such as APIs for network quality perception, network scenario prediction, and network acceleration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.GET_WALLPAPER

Allows an application to read wallpaper files.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.GRANT_SENSITIVE_PERMISSIONS

Allows an application to grant sensitive permissions to other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Supported devices**: general devices

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.LAUNCH_DATA_PRIVACY_CENTER

Allows an application to navigate from its privacy statement page to the **Data & privacy** page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.LISTEN_BUNDLE_CHANGE

Allows an application to listen for changes in other applications, when they are installed, updated, or uninstalled.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.MANAGE_BLUETOOTH

Allows an application to pair with a Bluetooth device and access the Contacts or messages of the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS

Allows an application to manage information about distributed accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MANAGE_MEDIA_RESOURCES

Allows an application to obtain and manage the media resources that are being played on the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.MANAGE_SECURE_SETTINGS

Allows an application to modify security settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.MANAGE_WIFI_CONNECTION

Allows an application to manage Wi-Fi connections.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.MANAGE_WIFI_HOTSPOT

Allows an application to enable or disable Wi-Fi hotspots.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.NOTIFICATION_AGENT_CONTROLLER

Allows an application to send agent-powered notifications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.PLACE_CALL

Allows an application to make calls without starting the dialer.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.POWER_OPTIMIZATION

Allows an application to set power saving mode, obtain configuration of the power saving mode, and receive notifications of the configuration changes.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.PROVISIONING_MESSAGE

Allows the Super Device Manager application to be activated.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.radio.ACCESS_FM_AM

Allows an application to access radio services.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.READ_SCREEN_SAVER

Allows an application to read the screen saver information, such as the list of screen savers that have been installed and the activated one.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.REBOOT

Allows an application to restart the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.REBOOT_RECOVERY

Allows an application to restart the device and enter Recovery mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.REFRESH_USER_ACTION

Allows an application to reset the screen timeout counter when a user input event occurs, such as pressing a key or touching the screen.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.REMOVE_CACHE_FILES

Allows the cache of the specified application to be cleared.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.REQUIRE_FORM

Allows an application to obtain the Ability Form.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.START_DESKTOP_UI_COMPONENT

Allows an application to start desktop UI components.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.REVOKE_SENSITIVE_PERMISSIONS

Allows an application to revoke the sensitive permissions it has granted to other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Supported devices**: general devices

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.RUN_ANY_CODE

Allows an application to run unsigned code.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.securityguard.REQUEST_SECURITY_MODEL_RESULT

Allows an application to obtain the device risk status.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.SET_DEFAULT_APPLICATION

Allows an application to set and reset default applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.SET_TELEPHONY_STATE

Allows an application to set the telephony state.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.SET_TIME

Allows an application to set the system time.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.SET_TIME_ZONE

Allows an application to set the system time zone.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.START_ABILIIES_FROM_BACKGROUND

Allows an application to start FAs in the background.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

**Deprecated since**: 9

## ohos.permission.START_INVISIBLE_ABILITY

Allows an application to start an invisible ability.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.STORAGE_MANAGER

Allows an application to call the interfaces of the Storage Manager service to query space statistics and volume information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 9

## ohos.permission.UPDATE_CONFIGURATION

Allows an application to modify system settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.WRITE_SCREEN_SAVER

Allows an application to modify the screen saver information, such as activating and previewing a screen saver.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 7

## ohos.permission.GET_BLUETOOTH_LOCAL_MAC

Allows an application to obtain the Bluetooth MAC address of the local device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.GET_BLUETOOTH_PEERS_MAC

Allows an application to obtain the real Bluetooth MAC address of a device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.USE_USER_IDM

Allows an application to access the system identity credential information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.MANAGE_USER_IDM

Allows an application to enroll and manage user identity authentication credentials.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.ACCESS_PIN_AUTH

Allows an application to register the callback for obtaining the PIN during the PIN authentication process.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.ACCESS_USER_AUTH_INTERNAL

Allows an application to call internal system interfaces of IAM.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 8

## ohos.permission.SUPPORT_USER_AUTH

Allows access to the resource pool of the user authentication widget (auth_widget).

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.ACCESS_SENSING_WITH_ULTRASOUND

Allows an application to use ultrasonic sensing.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 10

## ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

Allows a system service or system application to access distributed hardware resources.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.INSTANTSHARE_SWITCH_CONTROL

Allows a system service or system application to change the **instantshare** switch state.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_INSTANTSHARE_SERVICE

Allows a system service or system application to access the **instantshare** service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_INSTANTSHARE_PRIVATE_ABILITY

Allows a system service or system application to use the **instantshare** private ability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_MCP_AUTHORIZATION

Allows the MCP host application to perform user account authorization and login for its sub-applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.GET_BUNDLE_RESOURCES

Allows an application to obtain resource information of another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.COOPERATE_MANAGER

Allows a system application to enable the ScreenHop feature, which allows the user to use a mouse across multiple devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 11

## ohos.permission.PERCEIVE_TRAIL

Allows a system application to use the Multimodal Sensor Data Platform (MSDP) trail perception function.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.EXECUTE_INSIGHT_INTENT

Allows a system application to execute intent calls.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.EXECUTE_DISTRIBUTED_INTENT

Allows a system application to execute distributed intents.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars | phones | TVs | wearables | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.VERIFY_ACTIVATION_LOCK

Allows an application to verify the validity of activation lock credentials.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_OUC

Allows a system application to start the software update capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_FINGERPRINT_AUTH

Allows an application to call APIs for configuring and managing the fingerprint authentication module.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.TRUSTED_RING_HASH_DATA_PERMISSION

Allows an application to send data to the trusted ring of critical assets.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.INPUT_CONTROL_DISPATCHING

Allows a system application to shield the shortcut key distribution logic.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_TRUSTED_RING

Allows the use of the capabilities provided by the asset trusted ring service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.USE_TRUSTED_RING

Allows an application or service to use the asset trusted ring.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.RECEIVE_APP_INSTALL_INFO_CHANGE

Allows an application to listen for the installation progress of other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.LAUNCH_SPAMSHIELD_PAGE

Allows an application to access the spam shield pages.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SPAMSHIELD_SERVICE

Allows an application to access the spam shield service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SECURITY_PRIVACY_CENTER

Allows a service to access the Security & Privacy Center.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.GET_SECURITY_PRIVACY_ADVICE

Allows a system application to obtain advice from the Security & Privacy Center.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.SET_SECURITY_PRIVACY_ADVICE

Allows a system application to process the advice provided by the Security & Privacy Center.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.USE_SECURITY_PRIVACY_MESSAGER

Allows a system service to call permission management APIs.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.GET_PRIVACY_INDICATOR

Allows a system application to obtain details about privacy event notifications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.SET_PRIVACY_INDICATOR

Allows a system application to control the presence status of privacy event notifications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.EXEMPT_PRIVACY_INDICATOR

Allows an application to use permissions without displaying the privacy indicator.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.EXEMPT_CAMERA_PRIVACY_INDICATOR

Allows an application to access the device's camera without displaying the privacy indicator.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.EXEMPT_MICROPHONE_PRIVACY_INDICATOR

Allows an application to access the device's microphone without displaying the privacy indicator.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.EXEMPT_LOCATION_PRIVACY_INDICATOR

Allows an application to use the location service without displaying the privacy indicator.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.EXEMPT_PRIVACY_SECURITY_CENTER

Allows a system application to be hidden on the **Privacy & Security** page.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.GET_SUPER_PRIVACY

Allows a system application to obtain the status of the super privacy mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.SET_SUPER_PRIVACY

Allows a system application to set the super privacy mode.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_PRIVATE_SPACE_MANAGER

Allows a system application or system service to start the PrivateSpace manager.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_PRIVATE_SPACE_PASSWORD_PROTECT

Allows a system application to call PrivateSpace APIs related to password protection.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_PASSWORDVAULT_ABILITY

Allows a system application or system service to start the Password Vault ability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_TEXTAUTOFILL_ABILITY

Allows a system application or system service to start the text autofill ability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_LOWPOWER_MANAGER

Allows a system application or system service to send messages to LowpowerManager.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_APP_BOOT

Allows a system application to set auto boot options for other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_ACCOUNT_KIT_SERVICE

Allows the account service to query and modify account data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.REQUEST_ANONYMOUS_ATTEST

Allows a system application to use the device anonymous attestation capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_ACCOUNT_KIT_UI

Allows a system application to display the account user authentication page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.START_RECENT_ABILITY

Allows an application to start the specified UIAbility or the last started instance if the UIAbility has multiple instances.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_CLOUD_SYNC_CONFIG

Allows an application that has accessed the cloud to manage the device-cloud sync configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_FINDDEVICE

Allows an application to start the **Find Device** app.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_FINDSERVICE

Allows a system application to obtain and modify the setting of **Find My Phone**.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.READ_FINDSERVICE

Allows a system application to read the status of **Find Device**.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_USB_CONFIG

Allows an application to manage the USB device functions and ports.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.START_SYSTEM_DIALOG

Allows an application to start modal system dialog boxes.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_STATUSBAR_ICON

Allows an application to access the status bar icons.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

Allows an application to manage the system audio effects.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.SECURE_PASTE

Allows an application to read the pasteboard via silent access.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Phone | TV | Wearable | PC/2in1 | Tablet | Car

**Valid since**: 11

## ohos.permission.SET_CODE_PROTECT_INFO

Allows a system application to set the public key and working secret ciphertext in the cloud and agrees on a key for code protection.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.SET_ADVANCED_SECURITY_MODE

Allows an application to set the advanced security mode configuration.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.SET_DEVELOPER_MODE

Allows an application to set the developer mode configuration.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.DISABLE_PERMISSION_DIALOG

Allows a system application to set whether an application can start the permission dialog box.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_ACTIVATION_LOCK

Allows an application to manage the activation lock of a device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_PRIVATE_PHOTOS

Allows an application to access the built-in hidden albums and files in the albums.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.RECORD_VOICE_CALL

Allows an application to record voice calls.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_APP_INSTALL_INFO

Allows an application to create and manage application installation tasks.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.MANAGE_APP_UNINSTALL

Allows a system application to uninstall other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 19

## ohos.permission.ACCESS_ADVANCED_SECURITY_MODE

Allows a system application to access the advanced security mode configuration page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_HIVIEWX

Allows a system application to start HiViewX, which displays the **User Experience Improvement Program** page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.ACCESS_HIVIEWCARE

Allows a system application to start HiViewCare.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.SET_SANDBOX_POLICY

Allows a system application to set dynamic sandbox policies.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.CHECK_SANDBOX_POLICY

Allows a system application or system service to check sandbox policies of other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 15

## ohos.permission.TRIGGER_ACTIVATIONLOCK

Allows an SA to call **Find Device**.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.WRITE_PRIVACY_PUSH_DATA

Allows an application to write private Push data to another application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 11

## ohos.permission.READ_PRIVACY_PUSH_DATA

Allows an application to read the private Push data of another application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_NEARLINK

Allows an application to pair with a NearLink device and access the Contacts or messages of the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.GET_NEARLINK_LOCAL_MAC

Allows an application to obtain the NearLink MAC address of the local device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.GET_NEARLINK_PEER_MAC

Allows an application to obtain the NearLink MAC address of the peer device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_UWB

Allows a system application to manage the ultra-wideband (UWB) function,

for example, enabling or disabling UWB communication, querying the chip type, and querying UWB capabilities.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.USE_UWB_RANGING

Allows a system application to use UWB ranging,

for example, opening a session for UWB ranging, starting ranging, stopping ranging, and closing a session.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_FINDNETWORK

Allows an application to manage the **Find Network** switch and pair and unpair accessories.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.OPERATE_FINDNETWORK

Allows an application to call APIs for finding network.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.QUERY_FINDNETWORK_LOCATION

Allows an application to query the location of an offline device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.REGISTER_FINDNETWORK_ACCESSORY

Allows an application or system service to initiate the process for registering the Find Network accessories.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | wearables | PCs/2-in-1 devices | tablets

**Since**: 13

## ohos.permission.MANAGE_SHUTDOWN_FINDNETWORK

Allows a system application or system service to manage the service that enables a powered-off device to be found by another device with the same account.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | wearables | PCs/2-in-1 devices | tablets

**Valid since**: 15

## ohos.permission.MANAGE_RGM

Allows a system service or system application to manage RGM.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_PROTOCOL_DFX_DATA

Allows a system application to access communication failure information and system statistics.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_PROTOCOL_DFX_STATE

Allows a system application to enable or disable the switches related to communication protocols.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_CMAP_SERVICE

Allows a system application to access the cellular map service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 14

## ohos.permission.MANAGE_USER_ACCOUNT_INFO

Allows a system application or an SA to call the account service.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ALLOW_TIPS_ACCESS

Allows a system application to start the exposed components of another system application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_AI_ABILITY

Allows a system application or an SA to access the AI ability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.READ_HEALTH_MOTION

Allows a system application to read the activity ring information, such as the step count.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.hsdr.REQUEST_HSDR

Allows a system application to access the OpenHarmony Security Detection and Response (HSDR) function of querying the security policies from the cloud.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.WRITE_GTOKEN_POLICY

Allows a system application to write application control policies.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.READ_GTOKEN_POLICY

Allows a system application to read application control policies.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.NOTIFY_DEBUG_ASSERT_RESULT

Allows a system application to set the assertion debugging result.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.QUERY_PASSWORD_VAULT_DATA

Allows a system application to obtain password vault data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.WRITE_ACCOUNT_LOGIN_STATE

Allows user account login status to be written to the data management service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_AS_USER

Allows a service in the U0 user space to call the open account APIs.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.SUBSCRIBE_NOTIFICATION_WINDOW_STATE

Allows an application to subscribe to the broadcasts sent when the notification window is displayed or collapsed.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.CHANGE_DISPLAYMODE

Allows a system application to change the display mode.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MIGRATE_DATA

Allows a system application to migrate data.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_DYNAMIC_ICON

Allows a system application to use dynamic icons.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.CHANGE_BUNDLE_UNINSTALL_STATE

Allows a system application to change the uninstall status of the specified application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_STYLUS_EVENT

Allows a system application to use the stylus capabilities.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.USE_CLOUD_DRIVE_SERVICE

Allows a system application or service to use the DriveServiceAbility of the cloud space service to perform device-cloud sync.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.USE_CLOUD_BACKUP_SERVICE

Allows a system application or service to trigger the BackupServiceAbility of the cloud space service to implement backup and backup-related event notifications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.USE_CLOUD_COMMON_SERVICE

Allows a system application to obtain cloud space information and resources through the CommonServiceAbility of the cloud space service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.PRELOAD_APPLICATION

Allows a system application or service to preload application processes.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ENABLE_EXPERIENCE_HBM

Allows an application to enable the High Brightness Mode (HBM) for the screen.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.SET_PROCESS_CACHE_STATE

Allows an application to set whether to support application cache and quick startup after cached.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SYSTEM_APP_CERT

Allows the caller to manage and use system service certificate credentials.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_USER_TRUSTED_CERT

Allows the caller to manage user CA certificates.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_LOCAL_BACKUP

Allows an application to access the local backup directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.CAST_AUDIO_OUTPUT

Allows the system to cast audio or collaborate with another application to cast audio.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.WRITE_RINGTONE

Allows an application to write the ring tone library.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.GET_ACCOUNT_MINORS_INFO

Allows a system application to obtain information about the minor users (users not of the legal age) of a user account.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_LOCAL_THEME

Allows a system application to access the local theme information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SHADER_CACHE_DIR

Allows a system application to access the shader_cache directory.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.INSTALL_CLONE_BUNDLE

Allows an application to install a cloned application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.UNINSTALL_CLONE_BUNDLE

Allows an application to uninstall a cloned application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SCREEN_LOCK_MEDIA_DATA

Allows an application to access images and videos when the screen is locked.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SCREEN_LOCK_ALL_DATA

Allows an application to access sensitive data, such as images and videos, call logs, call recordings, SMS messages, and emails, when the screen is locked.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_DEVICE_COLLABORATION_PRIVATE_ABILITY

Allows a system service or system application to access the device collaboration private ability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_FILE_CONTENT_SHARE

Allows a system service or system application to access shared files.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_RINGTONE_RESOURCE

Allows a system application to access and write the ring tone public directory.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SUBSCRIPTION_CAPSULE_DATA

Allows a system application to access the subscribed capsule data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SEARCH_SERVICE

Allows a system application to call the local search ability provided by the fusion search service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.INJECT_INPUT_EVENT

Allows a system application to inject input events.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.QUERY_SECURITY_EVENT

Allows an application to obtain detailed security event information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.REPORT_SECURITY_EVENT

Allows an application to report risk data for security guard.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.QUERY_SECURITY_MODEL_RESULT

Allows an application to query the security model execution result.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_SECURITY_GUARD_CONFIG

Allows an application to manage Security Guard configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.COLLECT_SECURITY_EVENT

Allows an application to collect security events.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.QUERY_SECURITY_POLICY_FROM_CLOUD

Allows an application to query security policies from the cloud.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.REPORT_SECURITY_EVENT_TO_CLOUD

Allows an application to report security events to the cloud.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_SCAN_SERVICE

Allows a system application to invoke the code dispatching capability provided by the scan-to-access service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_FACTORY_OTA_DIR

Allows a system application to access the over-the-air update directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: wearables

**Since**: 12

## ohos.permission.MANAGE_MOUSE_CURSOR

Allows a system application to set the mouse cursor status.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.FILTER_INPUT_EVENT

Allows a system application to filter input events.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.INPUT_DEVICE_CONTROLLER

Allows an application to obtain and set the status of input devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACTIVATE_DEVICE_PSI

Allows a system application or system service to report the device activation status.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.DUMP_AUDIO

Allows an application to dump audio data to a local storage device.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.RECEIVE_FUSION_MESSAGES

Allows a system application or system service to receive fusion service messages.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.RECEIVE_BMS_BROKER_MESSAGES

Allows a system application or system service to receive BMS broker messages.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_FUSION_MANAGER

Allows a system service or system application to access the fusion service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.PUBLISH_LOCATION_EVENT

Allows an application to publish common events related to location management.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_MULTICORE_HYBRID_ABILITY

Allows an application to access the system service APIs of the smart watch.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_DEVICE_COLLABORATION_SERVICE

Allows an application to use the multi-screen collaboration service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.GET_APP_DOMAIN_BUNDLE_INFO

Allows an application to access the mappings between applications and domain names.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.OPEN_FILE

Allows a system application to start the File Manager application to open files or folders.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.PROCESS_FILE_COPY_PASTE

Allows a system application to start the File Manager application to copy, cut, and paste files.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.CLEAR_RECYCLEBIN

Allows a system application to start the File Manager application to clear the Recycle Bin.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.GET_FILE_THUMBNAIL

Allows a system service to obtain file thumbnails.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.NETWORK_DHCP

Allows a system application to apply for IP addresses from the DHCP server.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: phone | PCs/2-in-1 devices | tablets | TV | wearable | car

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ALLOW_CONNECT_CAR

Allows an application to connect to a head unit.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_IDM_WIDGET

Allows a system application to access the widget for credential enrollment.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.MANAGE_ACCESSORY

Allows an application to obtain information about accessories (such as the keyboard and mouse), send data to accessories, and obtain responses from them.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.COLLECT_ACCESSORY_LOG

Allows an application to obtain logs of accessories (such as the keyboard and mouse).

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.INSTALL_INTERNALTESTING_BUNDLE

Allows an application to install beta applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.PUBLISH_DISPLAY_ROTATION_EVENT

Allows a system ability to send screen rotation events to applications or other system abilities.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.PUBLISH_CAST_PLUGGED_EVENT

Allows a system ability to send the projection cable plug-in and plug-out events to applications or other system abilities.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS

Allows a modal UIExtension to unhide non-secure windows.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.CALLED_UIEXTENSION_ON_LOCK_SCREEN

Allows a UIExtensionAbility to be displayed on the locked screen.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 14

## ohos.permission.ACCESS_DISTRIBUTED_MODEM

Allows a system service to access distributed modems.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.GET_TELEPHONY_ESIM_STATE

Allows a system application to obtain eSIM profile information and data written on the device chip when the eSIM is activated.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.SET_TELEPHONY_ESIM_STATE

Allows a system application to modify the eSIM profile and upgrade the eSIM.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.CAMERA_BACKGROUND

Allows a system application to use the camera in the background.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.CALLED_TRANSITION_ON_LOCK_SCREEN

Allows an application to be started by another application on the lock screen page and redirected.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.CALLED_BELOW_LOCK_SCREEN

Allows an application to start even when the screen is locked.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.ACCESS_ANALYTICS

Allows a system service to access and read files in **/data/log/faultlog/faultlogger** directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.START_RESTORE_NOTIFICATION

Allows a system application to subscribe to the restore start event of the backup and restore framework.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.READ_WEATHER_DATA

Allows an application to read weather data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 14

## ohos.permission.GRANT_SHORT_TERM_WRITE_MEDIAVIDEO

Allows a system application or system service to grant third-party applications the temporary permission to save images and videos for the specified period of time.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.CHECK_QUICKFIX_RESULT

Allows a system service or system application to check the patch installation result.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

**Changelog**: This permission is available to system services in API versions 12 to 13. From API version 14, it is available to system applications.

## ohos.permission.USER_AUTH_FROM_BACKGROUND

Allows a system application or service to initiate user identity authentication from the background.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.MANAGE_RECOVERY_KEY

Allows an application to create or remove the recovery key.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 14

## ohos.permission.UTILIZE_RECOVERY_KEY

Allows an application to utilize the recovery key to reset the lock screen password or restore user data.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 14

## ohos.permission.ACCESS_CONFIDENTIAL_COMPUTING_ZONE

Allows an application to access the confidential computing zone.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.SYNC_ASSET_BETWEEN_TRUSTED_ACCOUNT

Allows an application to synchronize assets between the devices logged with the same trusted account.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.GET_RECOVERY_KEY_BRIEF_INFORMATION

Allows an application to obtain brief information about the recovery key.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 14

## ohos.permission.ACCESS_VIRTUAL_KEYBOARD

Allows an application to update the virtual keyboard status or a service to query the virtual keyboard status.

With this permission, the application can update the virtual keyboard status and the service can query the virtual keyboard status. Currently, this permission is available only to applications or services running on 2-in-1 devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 14

## ohos.permission.READ_APP_LOCK

Allows a system application to read the application lock state.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.WRITE_APP_LOCK

Allows a system application to modify the application lock state.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.ACCESS_APP_LOCK

Allows an application to access the application lock.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 13

## ohos.permission.ACCESS_CAR_CONTROL

Allows an application to access or start the vehicle control screen.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Since**: 13

## ohos.permission.ACCESS_APP_SINGLE_PERMISSION_MANAGEMENT

Allows an application to launch a page for modifying a specific permission of another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 15

## ohos.permission.ACCESS_APP_INSTALL_DIR

Allows a system application to access the application installation directory.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 14

## ohos.permission.ACCESS_ACCOUNT_SERVICE_EXTENSION_ABILITY

Allows a system application to invoke the services provided by the account ServiceExtensionAbility.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 15

## ohos.permission.ANTI_FRAUD

Allows an application to access risk control probes to detect device security risks. The detection result can be used as the input for risk control decision-making in the cloud.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.EXEMPT_CAPTURE_SCREEN_AUTHORIZE

Allows an application to initiate screen recording without displaying the user authorization dialog box.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 15

## ohos.permission.STORAGE_MANAGER_CRYPT

Allows a system application or system service to call APIs to perform encryption and decryption.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.WATCH_READ_EMERGENCY_INFO

Allows an application to read the SOS emergency information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.WATCH_WRITE_EMERGENCY_INFO

Allows an application to write the SOS emergency information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.WATCH_START_SOS_SERVICE

Allows an application to enable or access the SOS service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

**Changelog**: This permission is available only to system services in API versions 12 to 14, and becomes available to system applications since API version 15.

## ohos.permission.ACCESS_DLP_HIDE_INFO

Allows a system application to start the page for setting privacy protection.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.GET_ANIM_POLICY

Allows a system application to register the animation plugin to obtain animation policies.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.VIRTUAL_KEYBOARD_WINDOW

Allows a system application to create a virtual keyboard window.

A system application can create a virtual keyboard window only after obtaining this permission. Currently, this permission is available only to system applications running on 2-in-1 devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 15

**Supported devices**: PCs/2-in-1 devices

## ohos.permission.GET_FAMILY_INFO

Allows a system application to obtain the group information of Family Sharing.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Since**: 18

## ohos.permission.ACCESS_FUSION_AWARENESS_DATA

Allows a system application to obtain fusion awareness data.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_ACCOUNT_RECOMMENDATION_DATA

Allows an application to read the data of Account Suggestions and start the UIExtensionAbility of the account suggestion list.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 16

## ohos.permission.GET_PAGE_INFO

Allows a system application to obtain the page information of a specified application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_CUSTOM_RINGTONE

Allows an application to access the RBT library.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_STARTUPGUIDE

Allows a system application to access common data and common events of the startup wizard.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_DEVAUTH_CRED_MGR

Allows a system application or system service to access the credential management module for the device authentication (device_auth) SA.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_DEVAUTH_CRED_PRIVILEGE

Allows a system application or system service to access the credential management module and credential authentication module for the device authentication (device_auth) SA and to query and authenticate other service credentials.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_DEVAUTH_CRED_AUTH

Allows a system application or system service to access the credential authentication module for the device authentication (device_auth) SA.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ANTIFRAUD_DETECT

Allows a system application to perform anti-fraud detection.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ANTIFRAUD_PICTURE_DETECT

Allows a system application to perform face swapping detection for images.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ANTIFRAUD_MODEL_DOWNLOAD

Allows a system application to use model download APIs.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_APP_CLONE_DIR

Allows a system application to access the installation file path copied from another device.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_MEDIALIB_RESTORE

Allows an application to mount media restore paths.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 17

## ohos.permission.ACCESS_TRUST_LIST_OOBE_MANAGER

Allows an application to access the list of applications that can be started in the out-of-box experience.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.READ_DLP_HIDE_SWITCH

Allows a system application to read data from the Peep Protect database.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.WRITE_DLP_HIDE_SWITCH

Allows a system application to write data to the Peep Protect database.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.INSTALL_PLUGIN_BUNDLE

Allows an application to call the APIs for installing plugins.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 19

## ohos.permission.UNINSTALL_PLUGIN_BUNDLE

Allows an application to call the APIs for uninstalling plugins.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 19

## ohos.permission.GET_EDM_CONFIG

Allows a system application to obtain custom enterprise device management (EDM) configuration files.

This permission prevents unauthorized access to custom configuration files, such as the startup animation, startup logo, homepage layout, and wallpapers.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | wearables

**Since**: 18

## ohos.permission.READ_DHA

Allows an application to read device health attestation information.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.WRITE_DHA

Allows an application to write device health attestation information.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.NOTIFY_DHA

Allows an application to notify the device health attestation event.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.CHANGE_DEFAULT_APPLICATION

Allows an application to listen for the changes of a default application.

Users can set default applications for the system, for example, specifying an application to open files of a certain type by default. Any change in the default application will trigger an event indicating the change.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 19

## ohos.permission.SEND_NOTIFICATION_CROSS_USER

Allows an application to send notifications to the specified users in the system.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ALLOW_ACCESS_TIPS

Allows a system application to start the components provided by Tips.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.UPDATE_FONT

Allows an application to install and uninstall fonts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 19

**Changelog**: Since API version 23, this permission is also available on smartphones.

## ohos.permission.READ_PARENT_CONTROL_DATA

Allows an application to read the parental control website configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 19

## ohos.permission.WRITE_PARENT_CONTROL_DATA

Allows an application to write the parental control website configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 19

## ohos.permission.MINORS_PROTECTION_UI

Allows a system application to call the ExtensionAbility in youth mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.ACCESSIBILITY_EXTENSION_ABILITY

Allows an application to call the accessibility service extension APIs to query and manipulate UI components.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Supported devices**: general devices

**Certificate-based authorization**: true

**Valid since**: 20

## ohos.permission.READ_SOUND_RECORD_IN_FILE_MANAGER

Allows an application to read recording files from the file manager directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.WRITE_SOUND_RECORD_IN_FILE_MANAGER

Allows an application to write recording files to the file manager directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.SANDBOX_ACCESS_MANAGER

Allows an application to access the sandbox directories of other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Valid since**: 17

## ohos.permission.REQUEST_DISABLE_NOTIFICATION

Allows an application to run background upload and download tasks without triggering notifications in the notification bar.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 20

## ohos.permission.RESTORE_APP

Allows a system application to display a dialog box for application restore.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.ALLOW_IOURING

Allows a system application to call **io_uring** to perform async I/O operations.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 20

## ohos.permission.NFC_NOTIFICATION

Allows an application to publish common events related to NFC notifications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones

**Valid since**: 20

## ohos.permission.INJECT_PLAYBACK_TO_AUDIO_CAPTURE

Allows a system application to inject playback audio into the capture stream.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 22

## ohos.permission.kernel.ALLOW_APP_CODE_DECRYPT

Allows a system application or system service to call kernel APIs for code decryption. 

With this permission, the application can access kernel APIs across processes to request decryption of encrypted code. This helps prevent unauthorized access and further safeguards application code assets.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 20

## ohos.permission.kernel.READ_PROTECT_RANGE

Allow system applications or system services to access the code files of encrypted applications.

With this permission, the system application or service can read the protected code files.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 20

## ohos.permission.VIRUS_PROTECTION_SERVICE

Allows an application to start virus protection tasks.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.UPLOAD_SAMPLE_FILE

Allows an application to upload sample files to the cloud.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.DOWNLOAD_POLICY_FILE

Allows an application to download policy files from the cloud.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.NOTIFY_VIRUS_PROTECTION

Allows an application to send notification to the virus protection page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.ACCESS_VIRUS_PROTECTION

Allows an application to access the virus protection page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.ACCESS_TVCOOPERATION

Allows a system application to use the TvCooperation service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: TVs

**Valid since**: 20

## ohos.permission.GRANT_URI_PERMISSION_AS_CALLER

Allow an application to grant URI access permissions to the target application as the caller.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 20

## ohos.permission.ACCESS_DFX_LOG_DIR

Allows an application to access the **/data/log** directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 19

## ohos.permission.MANAGE_FILE_ENCRYPTION

Allows a system application to modify the encryption status of system files.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.FILE_TRANSFER_OPERATION

Allows a system application to perform operations, such as transferring files, canceling file transfer, and deleting, moving, and modifying files.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.FILE_TRANSFER_INFO_QUERY

Allows a system application to query files and file transfer information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.MANAGE_LOCAL_WORKSPACES

Allows a system application to create and delete workspaces.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.FILE_ACCESS_FOR_PRIVATE_SPACE

Allows the private space application to mount public directories from the main space into the application sandbox.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | tablets

**Valid since**: 20

## ohos.permission.MOUNT_HDCDEBUG_PATH

Allows an application to mount hdc debugging paths.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.ACCESS_CAMERA_SCENARIOS_CARD

Allows an application to access the remote photography card services.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: wearables

**Valid since**: 20

## ohos.permission.TRIGGER_LOCAL_WANTAGENT

Allows a system application to trigger local **WantAgent** instances.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 20

## ohos.permission.ACCESS_DISTRIBUTED_KEY_STORE

Allows an application to use the distributed keystore capabilities.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | tablets | PCs/2-in-1 devices | wearables | TVs

**Valid since**: 20

## ohos.permission.SANDBOX_ACCESS_MANAGER_EXT

Allows an application to access the sandbox directories of other extended applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 19

## ohos.permission.GET_DEVICE_INDEPENDENT_BINARY_CERT

Allows a system application to query the certificate information of independent binary programs.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.SET_DEVICE_INDEPENDENT_BINARY_CERT_STATUS

Allows a system application to set the certificate status of independent binary programs.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 20

## ohos.permission.GET_SCREEN_CONTENT

Allows an application to obtain the content on the screen.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 20

## ohos.permission.SIMULATE_USER_INPUT

Allows an application to simulate user operations.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 20

## ohos.permission.ACCESS_ANCO_APP_DATA

Allows an application to access the directory containing compatible applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 22

## ohos.permission.MANAGE_SELF_SKILLS

Allows an application to manage its skills configuration.

With this permission, the application can extend its implicit matching capabilities, such as opening specific file types.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 22

## ohos.permission.DATA_IDENTIFY_ANONYMIZE

Allows a system application to invoke the data identification and anonymization capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices | phones | tablets | TVs | cars

**Valid since**: 22

## ohos.permission.CAPTURE_SCREEN_ALL

Allows an application to capture screenshots, including privacy windows.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 13

## ohos.permission.GET_BACKGROUND_TASK_INFO

Allows an application to obtain background task status.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.SET_BACKGROUND_TASK_STATE

Allows an application to obtain and set the user authorization status of special continuous tasks.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.SET_LAUNCH_REASON_MESSAGE

Allows a system application to set the launch reason when starting another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.ACCESS_SUPER_HUB

Allows an application to access Super Hub.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 12

## ohos.permission.ACCESS_USER_ACCOUNT_INFO

Allows a system application to access user account information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.USE_USER_ACCESS_MANAGER

Allows an application to query and configure user identity authentication policies, and verify the authentication result.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Since**: 18

## ohos.permission.MANAGE_DYNAMIC_UTD_TYPE

Allows an application to dynamically register or remove custom UTD data types.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 22

## ohos.permission.MANAGE_MEDIA_SHARED_RESOURCE

Allows a system application to access media sharing resources within the camera framework directory.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.MANAGE_CLOUD_DATA_SERVICE

Allows an application that has accessed Cloud to manage cloud data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.MANAGE_RISK_PHOTOS

Allows a system application to access potentially risky images or videos.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.READ_CLOUD_IMAGEVIDEO

Allows an application to read image or video files from the user's cloud storage.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.ACCESS_SECURE_FENCE

Allows a system application to access the security fence capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | cars

**Since**: 23

## ohos.permission.ACCESS_MINI_SYSTEM

Allows a system application to use the running capability framework.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | tablets | TVs | wearables

**Since**: 23

## ohos.permission.PUBLISH_FORM_CROSS_BUNDLE

Allows a system application to start the preview panel for adding application widgets to the home screen.

With this permission, the system application can help users add the widgets to distribute to the home screen.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | TVs | wearables | PCs/2-in-1 devices | tablets | cars

**Valid since**: 20

## ohos.permission.PUBLISH_FORM_CROSS_BUNDLE_CONTROL

Allows users to add WiseCard widgets of other apps.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.MANAGE_LOCAL_EDUCATION_SPACES

Allows an application to manage local education space accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: tablets

**Since**: 23

## ohos.permission.QUERY_LOCAL_EDUCATION_SPACES

Allows an application to query the properties of local education space accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: tablets

**Since**: 23

## ohos.permission.POWER_CONFIG

Allows an application to read and write file nodes related to power configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.MANAGE_STANDBY

Allows an application to manage the standby state of the page, such as controlling when the page enters or exits the standby state.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | TVs | PCs/2-in-1 devices | tablets | cars

**Since**: 23

## ohos.permission.ACCESS_STANDBY

Allows an application to query whether the page is in the standby state and access the page in this state.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | TVs | PCs/2-in-1 devices | tablets | cars

**Since**: 23

## ohos.permission.RESTORE_END_NOTIFICATION

Allows a system application to subscribe to the restore end event of the backup framework.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Since**: 23

## ohos.permission.ACQUIRE_LOCAL_ACCOUNT_AUTHORIZATION

Allows an application to obtain the local account authorization.

With this permission, the application can call the API to obtain the local account authorization. Once authorized, the application can handle sensitive tasks like creating or deleting local accounts, modifying account types, and adjusting time and time zone settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 24

## ohos.permission.GET_AGENT_CARD

Allows a system application to obtain AgentCard information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 24

## ohos.permission.CONNECT_AGENT

Allows a system application to connect to the Agent.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 24

## ohos.permission.READ_APP_PROTECTION_RECORD

Allows a system application to read application protection records.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.WRITE_APP_PROTECTION_RECORD

Allows a system application to modify application protection records.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.READ_SPAM_SHIELD_SETTING

Allows a system application to read the spam shield settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.WRITE_SPAM_SHIELD_SETTING

Allows a system application to modify the spam shield settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.EXEMPT_MOTION_SENSORS_RESTRICTION

Allows an application to bypass sensor controls.

With this permission, the application can always use sensors.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 24

## ohos.permission.MODIFY_AGENT_CARD

Allows a system application to update and delete AgentCard.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.START_ABILITY_TO_PAGE

Allows a system application to launch another application to a specified page stack.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | tablets

**Valid since**: 26.0.0

## ohos.permission.vehicle.CAR_MODE_MANAGEMENT

Allows an application to obtain and set the car scenario mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.vehicle.AUTO_UPDATER

Allows an application to send update instructions to the head unit.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Since**: 26.0.0

## ohos.permission.NOTIFICATION_SYSTEM_SUBSCRIBER

Allows an application to subscribe to the notification service.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | TVs | wearables | PCs/2-in-1 devices | tablets | cars

**Valid since**: 26.0.0

## ohos.permission.ASSET_CACHE_MANAGER

Allows an application to deliver, control, and query tasks through the asset cache service management APIs.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 24

## ohos.permission.DCAS_OTA_PERMISSION

Allows an application and a service to access the device-side model deployment management.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 24

## ohos.permission.ACCESS_SUPPORT_FEEDBACK

Allows a system application to open the Feedback screen.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.REVOKE_FILE_ACCESS_PERSIST

Allows an application to revoke persistent file authorizations for specified applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.ACCESS_SHARED_FILE

Allows an application to obtain and access shared files.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.GET_FILE_ACCESS_PERSIST

Allows an application to retrieve persistent file authorization records for specified applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.ACCESS_SUPPORT_HELP

Allows a system application to launch the intelligent customer service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.ACCESS_DIGITAL_IDENTITY_ABILITY

Allows a system application to use the unified management capabilities of the digital certificate service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | tablets

**Valid since**: 26.0.0

## ohos.permission.MANAGE_VOLUME_ENCRYPTION_POLICY

Allows an application to configure the encryption policy for a volume.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Supported devices**: PCs/2-in-1 devices

**Valid since**: 26.0.0

## ohos.permission.SUBSCRIBE_OUTDOOR_EXPLORATION_SERVICE

Allows an application to enable the outdoor exploration service to provide the altitude subscription capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones

**Valid since**: 26.0.0

## ohos.permission.ACCESS_INTIMATE_RELATION_INFO

Allows an application to obtain information about close contacts and open the close contact page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.QUERY_TOOL_PERMISSIONS

Allows a system application to query the permissions required for running a CLI or skill.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.MANAGE_TOOL_RUNTIME_PERMISSIONS

Allows a system application to set and query the permissions required for running a specified CLI or skill.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.CAMERA_SHARED

Allows a system application to access the camera together with other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Car

**Valid since**: 26.0.0

## ohos.permission.ACCESS_DEVICE_INTERCONNECTIVITY

Allows an application to use the device interconnectivity capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs

**Valid since**: 24

## ohos.permission.GET_TICKET_INFO

Allows a system application to generate integrity protection credentials for sensitive messages.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.MANAGE_AOD

Allows an application to trigger the Always On Display (AOD) mode or exit it, and manage the AOD status.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | tablets

**Valid since**: 26.0.0

## ohos.permission.MANAGE_SKILL_PRIVILEGE
     
Allows an application to use skills.

With this permission, the application can:

- Query information about skill packages.
- Listen for events such as the installation, update, and uninstallation of skill packages.
- Access the sandbox directory where skill packages are installed.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Supported devices**: general devices

**Valid since**: 26.0.0

## ohos.permission.cli.READ_ACCESSIBILITY_CONFIG_VISION

Allows a system application to query the status of visual-related accessibility functions via CLI commands.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Valid since**: 26.0.0

## ohos.permission.cli.READ_ACCESSIBILITY_CONFIG_HEARING

Allows a system application to query the status of hearing-related accessibility functions via CLI commands. 

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Valid since**: 26.0.0

## ohos.permission.cli.READ_ACCESSIBILITY_CONFIG_ACTION

Allows a system application to query the status of interaction-related accessibility functions via CLI commands.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Valid since**: 26.0.0

## ohos.permission.CONNECT_GAME_ACCELERATION

Allows an application to adjust the policy in gaming scenarios.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | tablets | TVs

**Valid since**: 26.0.0

## ohos.permission.QUERY_CLI_TOOL

Allows a system application to query CLI tools.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.EXEC_CLI_TOOL

Allows a system application to run CLI tools.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.cli.GET_STORAGE_MANAGER

Allows an application to query storage using CLI commands.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | TVs | wearables | PCs/2-in-1 devices | tablets | cars| lite wearables

**Valid since**: 26.0.0

## ohos.permission.cli.START_ABILITY

Allows an agent application to start a specific application using CLI commands.

**Permission level**: system_core

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Valid since**: 26.0.0

## ohos.permission.cli.KILL_APP_PROCESSES

Allows an agent application to stop a specific application using CLI commands.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Valid since**: 26.0.0

## ohos.permission.ACCESS_MAPDATA_DIR

Allows a system application to read and write map data.

With this permission, the application can access and modify the offline map data downloaded to the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones

**Valid since**: 20

## ohos.permission.ACCESS_FIDO2_ONLINEAUTH_PRIVILEGE

Allows a system application to use the credential management feature of the passkey service.

With this permission, the system application can obtain and delete all credentials of the passkey service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 20

## ohos.permission.QUERY_SPACE_OPTIMIZATION

Allows an application to query the space optimization effect.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Phone | PC/2in1 | Tablet | TV | Wearable | Car

**Valid since**: 26.0.0

## ohos.permission.ARKWEBCORE_SYS_CAP

Allows a system application to invoke ArkWebCore extended capabilities.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets | TVs | wearables | cars

**Valid since**: 26.0.0

## ohos.permission.HDC_REPORT_INFO

Allows a system application to subscribe to the hdc events.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: phones | PCs/2-in-1 devices | tablets

**Valid since**: 26.0.0

## ohos.permission.vehicle.VEHICLE_THERMAL

Allows an application to access thermal control information of the cockpit device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.SET_ADAS_CMD

Allows a system application to set advanced driver assistance systems (ADAS) commands.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.GET_ADAS_INFO

Allows a system application to obtain advanced driver assistance systems (ADAS) information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.GET_CLUSTER_INFO

Allows a system application to obtain cluster information on the head unit.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.SET_CLUSTER_CMD

Allows a system application to set cluster commands on the head unit.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.SET_MMS_CMD

Allows a system application to set MMS commands.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.GET_MMS_INFO

Allows a system application to obtain MMS information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.GET_XCALL_INFO

Allows a system application to obtain dedicated head unit communication information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.SET_XCALL_CMD

Allows a system application to set dedicated head unit communication commands.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.SET_SECBOX_CMD

Allows a system application to configure the secure box of the head unit.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.GET_SECBOX_INFO

Allows a system application to obtain secure box information of the head unit.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.RECV_HUAP_INFO

Allows a system application to receive HUAP data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.automotive.SEND_HUAP_MSG

Allows a system application to send HUAP messages.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.ENTERPRISE_SPACE_FILE_TRANSFER_DATA_ACCESS
 	 
Allows a system application to access the file cache path of the file transfer service.
 	 
**Permission level**: system_basic
 	 
**Authorization mode**: system_grant
 	 
**Certificate-based authorization**: true
 	 
**Supported devices**: PCs/2-in-1 devices
 	 
**Valid since**: 26.0.0

## ohos.permission.vehicle.CAMERA_EVS

Allows an application to access the vehicle camera.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: cars

**Valid since**: 26.0.0

## ohos.permission.SAMBA_CLIENT_ACCESS

Allows an application to connect to the network neighborhood client and manage network neighborhood files.

With this permission, the application can connect to or disconnect from network neighborhood, perform operations on network neighborhood files, and obtain basic information about network neighborhood connections.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Phone | PC/2in1 | Tablet

**Valid since**: 26.0.0

## ohos.permission.CREATE_SIGN_CONTENT_TRUST

Allows an application to create a content trust signature.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Phone | PC/2in1 | Tablet

**Since**: 26.0.0

## ohos.permission.APPEND_SIGN_CONTENT_TRUST

Allows an application to append a content trust signature.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Phone | PC/2in1 | Tablet

**Since**: 26.0.0

## ohos.permission.FILE_MANAGER_SERVICE_ACCESS

Allows an application to call the file management service APIs to perform operations on files.

With this permission, the application can use file management functions, including the recycle bin, frequently used folders, favorites, USB device queries, and shortcuts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Phone | PC/2in1 | Tablet

**Valid since**: 26.0.0

## ohos.permission.FILE_MANAGER_SERVICE_SMART_FILE_ACCESS

Allows an application to obtain and manage smart files.

With this permission, the application can manage smart file categorization, generate file summaries, and provide file recommendations.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Phone | PC/2in1 | Tablet

**Valid since**: 26.0.0

## ohos.permission.FILE_MANAGER_SERVICE_DATA_ACCESS

Allows an application to obtain and operate files of the file management application.

With this permission, the application can add file event records, search for files, manage recent files, and obtain music files, duplicate files, and aggregated files.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Certificate-based authorization**: true

**Supported devices**: Phone | PC/2in1 | Tablet

**Valid since**: 26.0.0