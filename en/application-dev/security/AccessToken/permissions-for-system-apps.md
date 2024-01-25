# Permissions for System Applications

Before requesting permissions for your application, read and understand the [Workflow for Using Permissions](determine-application-mode.md) and this topic to determine the permissions required.

> **NOTE**
>
> - The permissions listed in this topic apply to the applications whose Ability Privilege Level (APL) is system_basic or system_core, but not to the applications with the normal APL.
> - Only some of the permissions can be requested via the [Access Control List (ACL)](app-permission-mgmt-overview.md#acl).

## system_grant Permissions (Requestable via ACL)

The following lists the system_grant permissions that can be requested via the ACL.

For details about the process for requesting permissions, see [Workflow for Using Permissions](determine-application-mode.md).

### ohos.permission.SYSTEM_FLOAT_WINDOW

Allows an application to be displayed in a floating window on top of other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.AGENT_REQUIRE_FORM

Allows the application agent to request widgets.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.WAKEUP_VISION

Allows an application to access the AI Voice vision component.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.WAKEUP_VOICE

Allows an application to access the AI Voice wakeup component.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ATTEST_KEY

Allows an application to obtain the certificate chain that attests the key validity.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.GET_PHONE_NUMBERS

Allows an application to obtain the phone numbers of the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.ACTIVATE_THEME_PACKAGE

Allows a system application to set themes, including wallpapers, icons, skins, Always On Display (AOD), and fonts.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.SET_UNREMOVABLE_NOTIFICATION

Allows an application to publish unremovable notifications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.GET_DOMAIN_ACCOUNTS

Allows an application to obtain domain account information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.UNINSTALL_BUNDLE

Allows an application to uninstall applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.RECOVER_BUNDLE

Allows pre-installed applications to be recovered.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.UPDATE_SYSTEM

Allows an application to call the update APIs.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.FACTORY_RESET

Allows an application to call the API for restoring factory settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.MANAGE_LOCAL_ACCOUNTS

Allows an application to manage local accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.ACCESS_SYSTEM_SETTINGS

Allows an application to access or start **Settings**.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.SET_ABILITY_CONTROLLER

Allows an application to intercept the startup of the Ability component. This permission is used for testing, such as the stability test.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

Allows an application to interact across local accounts.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

Allows an application to interact across local accounts.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.CLEAN_APPLICATION_DATA

Allows an application to clear application data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.GET_RUNNING_INFO

Allows an application to obtain running status information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.START_ABILITIES_FROM_BACKGROUND

Allows an application to start or access other components from the background.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MANAGE_MISSIONS

Allows an application to manage missions in the system.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.RUNNING_STATE_OBSERVER

Allows an application to listen for its status.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

Allows an application to activate a device administrator application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.PUBLISH_SYSTEM_COMMON_EVENT

Allows an application to publish system common events.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.NOTIFICATION_CONTROLLER

Allows an application to manage and subscribe to notifications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.CLOUDDATA_CONFIG

Allows an application to obtain the device-cloud information of the configuration database.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.GET_DEFAULT_APPLICATION

Allows an application to query default applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MANAGE_INTELLIGENT_VOICE

Allows an application to access the intelligent voice service interfaces.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.POWER_MANAGER

Allows an application to hibernate or wake up the device by calling an API.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.GET_SCENE_CODE

Allows an application to obtain the scene code of the specified application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.MANAGE_ECOLOGICAL_RULE

Allows the rules for generating the scene code and the matching experience to be set for the manager service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.INSTALL_ENTERPRISE_BUNDLE

Allows an application to install enterprise InHouse applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.INSTALL_BUNDLE

Allows an application to install and uninstall other applications except enterprise applications, including enterprise InHouse, mobile device management (MDM), and Normal applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.MANAGE_SHORTCUTS

Allows an application to query and start shortcuts of other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.OBSERVE_FORM_RUNNING

Allows an application to listen for the card running status.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.WRITE_HIVIEW_SYSTEM

Allows an application to modify HiView data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.READ_HIVIEW_SYSTEM

Allows an application to access HiView data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.READ_DFX_SYSEVENT

Allows an application to access system event logging data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.PERMISSION_USED_STATS

Allows a system application to access the permission usage records.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.CAPTURE_SCREEN

Allows an application to take screenshots.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.ACCESS_CERT_MANAGER_INTERNAL

Allows an application to install, uninstall, enable, and disable certificates and credentials.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

Allows an application to obtain basic information and sensitive information about another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.CLOUDFILE_SYNC

Allows an application to perform device-cloud synchronization.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.CHANGE_OVERLAY_ENABLED_STATE

Allows a system application to disable the application with the overlay feature enabled.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.ACCESS_SCREEN_LOCK_INNER

Allows an application to use the lock screen service to lock the screen, send a screen lock event, and invoke the system event callback.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.BACKUP

Allows an application to have backup and restore capabilities.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MOUNT_FORMAT_MANAGER

Allows an application to format external cards.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MOUNT_UNMOUNT_MANAGER

Allows an application to mount and unmount external cards.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.PROXY_AUTHORIZATION_URI

Allows the application proxy to authorize the URI.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.ACCESS_CAST_ENGINE_MIRROR

Allows an application to use the mirror projection capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.ACCESS_CAST_ENGINE_STREAM

Allows an application to invoke the system resource projection capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.INSTALL_ENTERPRISE_NORMAL_BUNDLE

Allows an enterprise normal bundle to be installed on enterprise devices.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.UPDATE_MIGRATE

Allows data migration during the update process.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.MANAGE_SENSOR

Allows an application that cannot directly use the sensor to turn on and off the sensor.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.MANAGE_PRINT_JOB

Allows an application to obtain the capability of managing print tasks.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.securityguard.SET_MODEL_STATE

Allows an application to control the SecurityGuard model switch.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO

Allows an application to capture the downlink voice audio.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.GET_WIFI_INFO_INTERNAL

Allows a system process to obtain Wi-Fi parameters.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.ACCESS_BUNDLE_DIR

Allows an application to access the installation directory of another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.CHANGE_ABILITY_ENABLED_STATE

Allows an application to enable or disable an application or component.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.CLOUDFILE_SYNC_MANAGER

Allows an application to obtain the device-cloud synchronization management capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.DUMP

Allows the basic system information and SA service information to be exported.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.DEVICE_STANDBY_EXEMPTION

Allows an application to use resources when the system is in standby mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.MANAGE_CAMERA_CONFIG

Allows an application to enable or disable cameras globally.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MANAGE_AUDIO_CONFIG

Allows an application to mute microphones globally.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MANAGE_DISPOSED_APP_STATUS

Allows an application to set and query the application handling state.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.FILE_ACCESS_MANAGER

Allows a file management application to access user data files through the FAF.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.ACCESS_PUSH_SERVICE

Allows an application to access the Ability of the push service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MANAGE_NET_STRATEGY

Allows an application to obtain network strategy information or modify network strategy settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.INPUT_MONITORING

Allows an application to listen for input events. Only the system signed applications can apply for this permission.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.GET_WIFI_LOCAL_MAC

Allows an application to obtain the MAC address of the local Wi-Fi device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.GET_WIFI_PEERS_MAC

Allows an application to obtain the MAC address of the peer Wi-Fi device.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO

Allows an application to obtain detailed risk data.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.securityguard.REPORT_SECURITY_INFO

Allows an application to report risk data for security guard.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.GET_SENSITIVE_PERMISSIONS

Allows an application to obtain the sensitive permissions that have been granted to other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.ACCESS_SERVICE_DM

Allows a system application to obtain the authentication and networking capability of distributed devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.UPLOAD_SESSION_MANAGER

Allows an application to manage the upload sessions.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.ABILITY_BACKGROUND_COMMUNICATION

Allows an application to start the Ability component in the background and establish a connection with it.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.ACCESS_DLP_FILE

Allows configuration and management of the permissions on .dlp files.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.ACCESS_IDS

Allows an application to query the unique identifier of a device.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.ACCESS_MISSIONS

Allows an application to obtain information about running processes and mission in a mission stack.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.BUNDLE_ACTIVE_INFO

Allows an application to obtain how long other applications have been running in the foreground or background.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.CONNECT_IME_ABILITY

Allows an application to bind the InputMethodAbility.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.CONNECT_SCREEN_SAVER_ABILITY

Allows an application to bind the ScreenSaverAbility.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.CONNECTIVITY_INTERNAL

Allows an application to obtain network information or modify network settings. Currently, this permission is available only to system applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.CONTROL_TASK_SYNC_ANIMATOR

Allows an application to use sync task animations.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.DOWNLOAD_SESSION_MANAGER

Allows an application to manage the download sessions.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.GET_DISTRIBUTED_ACCOUNTS

Allows an application to obtain distributed account information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.GET_LOCAL_ACCOUNTS

Allows an application to obtain local account information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.GET_TELEPHONY_STATE

Allows an application to read telephony information. 

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.GET_WALLPAPER

Allows an application to read wallpaper files.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.GET_WIFI_CONFIG

Allows an application to obtain the Wi-Fi configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.GRANT_SENSITIVE_PERMISSIONS

Allows an application to grant sensitive permissions to other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.LAUNCH_DATA_PRIVACY_CENTER

Allows an application to switch from its privacy statement page to the **Data & privacy** page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.LISTEN_BUNDLE_CHANGE

Allows an application to listen for changes in other applications, when they are installed, updated, or uninstalled.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.MANAGE_BLUETOOTH

Allows an application to pair with a Bluetooth device and access the Contacts or messages of the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS

Allows an application to manage distributed account information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MANAGE_MEDIA_RESOURCES

Allows an application to obtain and manage the media resources that are being played on the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MANAGE_SECURE_SETTINGS

Allows an application to modify security settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.MANAGE_WIFI_CONNECTION

Allows an application to manage Wi-Fi connections.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.MANAGE_WIFI_HOTSPOT

Allows an application to enable or disable Wi-Fi hotspots.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.NOTIFICATION_AGENT_CONTROLLER

Allows an application to send agent-powered notifications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.PLACE_CALL

Allows an application to make calls without starting the dialer.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.POWER_OPTIMIZATION

Allows an application to set power saving mode, obtain configuration of the power saving mode, and receive notifications of the configuration changes.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.PROVISIONING_MESSAGE

Allows the Super Device Manager application to be activated.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.radio.ACCESS_FM_AM

Allows an application to access radio services.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.READ_SCREEN_SAVER

Allows an application to read the screen saver information, such as the list of screen savers that have been installed and the activated one.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.REBOOT

Allows an application to restart the device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.REBOOT_RECOVERY

Allows an application to restart the device and enter Recovery mode.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.REFRESH_USER_ACTION

Allows an application to reset the screen timeout counter when a user input event occurs, such as pressing a key or touching the screen.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.REMOVE_CACHE_FILES

Allows the cache of the specified application to be cleared.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.REQUIRE_FORM

Allows an application to obtain the Ability Form.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.REVOKE_SENSITIVE_PERMISSIONS

Allows an application to revoke the sensitive permissions it has granted to other applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.RUN_ANY_CODE

Allows an application to run unsigned code.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.sec.ACCESS_UDID

Allows an application to obtain the Unified Device ID (UDID).

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.securityguard.REQUEST_SECURITY_MODEL_RESULT

Allows an application to obtain the device risk status.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.SET_DEFAULT_APPLICATION

Allows an application to set and reset default applications.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.SET_TELEPHONY_STATE

Allows an application to set the telephony state.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.SET_TIME

Allows an application to set the system time.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.SET_TIME_ZONE

Allows an application to set the system time zone.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.SET_WIFI_CONFIG

Allows an application to configure Wi-Fi information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.START_ABILIIES_FROM_BACKGROUND

Allows an application to start FAs in the background.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.START_INVISIBLE_ABILITY

Allows an application to start an invisible ability.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.STORAGE_MANAGER

Allows an application to call the interfaces of the Storage Manager service to query space statistics and volume information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.UPDATE_CONFIGURATION

Allows an application to modify system settings.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.WRITE_SCREEN_SAVER

Allows an application to modify the screen saver information, such as activating and previewing a screen saver.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 7

### ohos.permission.GET_BLUETOOTH_LOCAL_MAC

Allows an application to obtain the Bluetooth MAC address of the local device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.USE_USER_IDM

Allows an application to access the system identity credential information.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.MANAGE_USER_IDM

Allows an application to enroll and manage user identity authentication credentials.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.ACCESS_PIN_AUTH

Allows an application to register the callback for obtaining the PIN during the PIN authentication process.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.SUPPORT_USER_AUTH

Allows access to the resource pool of the user authentication widget (auth_widget).

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.ACCESS_SENSING_WITH_ULTRASOUND

Allows an application to use ultrasonic sensing.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.ACCESS_DISTRIBUTED_HARDWARE

Allows a system service or system application to access distributed hardware resources.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.INSTANTSHARE_SWITCH_CONTROL

Allows a system service or system application to change the **instantshare** switch state.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_INSTANTSHARE_SERVICE

Allows a system service or system application to access the **instantshare** service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_INSTANTSHARE_PRIVATE_ABILITY

Allows a system service or system application to use the **instantshare** private ability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_MCP_AUTHORIZATION

Allows the MCP host application to perform user account authorization and login for its sub-applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.GET_BUNDLE_RESOURCES

Allows an application to obtain resource information of another application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.COOPERATE_MANAGER

Allows a system application to enable the ScreenHop feature, which allows the user to use a mouse across multiple devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.PERCEIVE_TRAIL

Allows a system application to use the Multimodal Sensor Data Platform (MSDP) trail perception function.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.EXECUTE_INSIGHT_INTENT

Allows a system application to execute intent calls.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.VERIFY_ACTIVATION_LOCK

Allows an application to verify the validity of activation lock credentials.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_OUC

Allows a system application to start the software update capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_FINGERPRINT_AUTH

Allows an application to call APIs for configuring and managing the fingerprint authentication module.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.TRUSTED_RING_HASH_DATA_PERMISSION

Allows an application to send data to the trusted ring of critical assets.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.INPUT_CONTROL_DISPATCHING

Allows a system application to shield the shortcut key distribution logic.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_TRUSTED_RING

Allows the use of the capabilities provided by the critical asset trusted ring service.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.USE_TRUSTED_RING

Allows an applications or service to use the critical asset trusted ring.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.FILE_ACCESS_PERSIST

Allows an application to support persistent access to file URIs.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.RECEIVE_APP_INSTALL_INFO_CHANGE

Allows an application to listen for the installation progress of other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_SECURITY_PRIVACY_CENTER

Allows a service to access the Security & Privacy Center.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.GET_SECURITY_PRIVACY_ADVICE

Allows a system application to obtain advice from the Security & Privacy Center.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.SET_SECURITY_PRIVACY_ADVICE

Allows a system application to process the advice provided by the Security & Privacy Center.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.USE_SECURITY_PRIVACY_MESSAGER

Allows a system service to call permission management interfaces.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_PASSWORDVAULT_ABILITY

Allows a system application or system service to start the Password Vault ability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_LOWPOWER_MANAGER

Allows a system application or system service to send messages to LowpowerManager.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_APP_BOOT

Allows a system application to set auto boot options for other applications.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_DDK_HID

Allows extended peripheral drivers to access the HID DDK interfaces to implement development of HID extended peripheral drivers.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_DDK_USB

Allows extended peripheral drivers to access the USB DDK interfaces to implement development of USB extended peripheral drivers.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_ACCOUNT_KIT_SERVICE

Allows the account service to query and modify account data.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.REQUEST_ANONYMOUS_ATTEST

Allows a system application to use the device anonymous attestation capability.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_ACCOUNT_KIT_UI

Allows a system application to display the account user authentication page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.START_RECENT_ABILITY

Allows an application to start the specified UIAbility or the last started instance if the UIAbility has multiple instances.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_CLOUD_SYNC_CONFIG

Allows an application that has accessed the cloud to manage the device-cloud synchronization configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_FINDDEVICE

Allows an application to start the **Find Device** app.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_FINDSERVICE

Allows a system application to obtain and modify the setting of **Find My Phone**.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_USB_CONFIG

Allows an application to manage the USB device functions and ports.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.START_SYSTEM_DIALOG

Allows an application to start modal system dialog boxes.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

## ohos.permission.ACCESS_STATUSBAR_ICON

Allow an application to access the status bar icons.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

Allows an application to manage the system audio effects.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.SECURE_PASTE

Allows an application to read the pasteboard via silent access.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.SET_CODE_PROTECT_INFO

Allows a system application to set the public key and working secret ciphertext in the cloud and agrees on a key for code protection.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.SET_ADVANCED_SECURITY_MODE

Allows an application to set the advanced security mode configuration.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.SET_DEVELOPER_MODE

Allows an application to set the developer mode configuration.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.DISABLE_PERMISSION_DIALOG

Allows a system application to set whether an application can start the permission dialog box.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_ACTIVATION_LOCK

Allows an application to manage the activation lock of a device.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_PRIVATE_PHOTOS

Allows an application to access the built-in hidden albums and files in the albums.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.INTERCEPT_INPUT_EVENT

Allows a system application to intercept input events.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.RECORD_VOICE_CALL

Allows the application to record voice calls.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.MANAGE_APP_INSTALL_INFO

Allows an application to create and manage application installation tasks.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_ADVANCED_SECURITY_MODE

Allows a system application to access the advanced security mode configuration page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_HIVIEWX

Allows a system application to start HiViewX, which displays the **User Experience Improvement Program** page.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.ACCESS_HIVIEWCARE

Allows a system application to start HiViewCare.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.CONNECT_UI_EXTENSION_ABILITY

Allows a system service to connect to UIExtensionAbility.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.SET_SANDBOX_POLICY

Allows a system application to set dynamic sandbox policies.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.TRIGGER_ACTIVATIONLOCK

Allows an SA to call **Find Device**.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.WRITE_PRIVACY_PUSH_DATA

Allows an application to write privacy push data to another application.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: true

**Valid since**: 11

## system_grant Permissions (Unavailable via ACL)

The following lists the system_grant permissions that cannot be requested via the ACL.

For details about the process for requesting permissions, see [Workflow for Using Permissions](determine-application-mode.md).

### ohos.permission.RECEIVER_STARTUP_COMPLETED

Allows an application to subscribe to the startup broadcast.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

### ohos.permission.SYSTEM_LIGHT_CONTROL

Allows an application to control lights, including turning on and off lights.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 11

### ohos.permission.QUERY_ACCESSIBILITY_ELEMENT

Allows an application to query accessibility elements in batches.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 11

### ohos.permission.GET_ALL_APP_ACCOUNTS

Allows an application to obtain information about all application accounts.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 7

### ohos.permission.MANAGE_DEVICE_AUTH_CRED

Allows an application to call interfaces of the DeviceAuthCredMgr application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.ACCESS_USER_AUTH_INTERNAL

Allows an application to call internal system interfaces of IAM.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 8

### ohos.permission.ACCESS_AUTH_RESPOOL

Allows an SA to register the executor.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

### ohos.permission.READ_ACCESSIBILITY_CONFIG

Allows an application to read the accessibility configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

### ohos.permission.WRITE_APP_PUSH_DATA

Allows the push service to write data to an application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.READ_APP_PUSH_DATA

Allows the push service to read data from an application.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.NETSYS_INTERNAL

Allows an SA to call the network diagnosis, Wi-Fi, network adapter listening, and iptables setting APIs of **netsys**.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.DISTRIBUTED_SOFTBUS_CENTER

Allows networking between different devices.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

### ohos.permission.GET_NETWORK_STATS

Allows a system application to obtain historical network traffic.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.MANAGE_VPN

Allows a system application to enable or disable the VPN function.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.RESTRICT_APPLICATION_ACTIVE

Allows a standby component to publish a customized network limit event.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.CONNECT_CELLULAR_CALL_SERVICE

Allows a system service to access the cellular call SA.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.CONNECT_IMS_SERVICE

Allows a system service to access the IMS SA.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 10

### ohos.permission.ENFORCE_USER_IDM

Allows an SA to delete the IAM user information without a token.

**Permission level**: system_core

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

### ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Allows an application to set the accessibility configuration.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 9

### ohos.permission.ENABLE_DISTRIBUTED_HARDWARE

Allows a system service to enable distributed hardware resources.

**Permission level**: system_basic

**Authorization mode**: system_grant

**Enable via ACL**: false

**Valid since**: 11

## user_grant Permissions (Available via ACL)

The following lists the user_grant permissions that can be requested via the ACL.

For details about the process for requesting permissions, see [Workflow for Using Permissions](determine-application-mode.md).

### ohos.permission.READ_AUDIO

Allows access to the audio files in a user directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.READ_DOCUMENT

Allows access to the files in a user directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.READ_IMAGEVIDEO

Allows access to the images or video files in a user's directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.WRITE_AUDIO

Allows modification to the audio files in a user directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.WRITE_DOCUMENT

Allows modification to the files in a user's directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.WRITE_IMAGEVIDEO

Allows modification to the images or video files in a user's directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.READ_CONTACTS

Allows an application to read the Contacts.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.WRITE_CONTACTS

Allows an application to add, remove, and modify the Contacts.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.READ_WHOLE_CALENDAR

Allows an application to read all Calendar information.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.WRITE_WHOLE_CALENDAR

Allows an application to add, remove, or change all Calendar events.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.GET_INSTALLED_BUNDLE_LIST

Allows an application to obtain the list of installed applications.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 10

### ohos.permission.ANSWER_CALL

Allows an application to answer incoming calls.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 9

### ohos.permission.MANAGE_VOICEMAIL

Allows an application to leave messages in the voice mailbox.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.READ_CALL_LOG

Allows an application to read call logs.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.READ_CELL_MESSAGES

Allows an application to read cell broadcast messages received by the device.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.READ_MESSAGES

Allows an application to read messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.RECEIVE_MMS

Allows an application to receive and process MMS messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.RECEIVE_SMS

Allows an application to receive and process SMS messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.RECEIVE_WAP_MESSAGES

Allows an application to receive and process WAP messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.SEND_MESSAGES

Allows an application to send messages.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.WRITE_CALL_LOG

Allows an application to add, remove, and modify call logs.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 8

### ohos.permission.READ_PASTEBOARD

Allows an application to read the pasteboard.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

Allows an application to access the **Download** directory in the user directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

Allows an application to access the **Documents** directory in the user directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 11

### ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

Allows an application to access the **Desktop** directory in the user directory.

**Permission level**: system_basic

**Authorization mode**: user_grant

**Enable via ACL**: true

**Valid since**: 11
