# Permission List

On the basis of the [principles for app permission management](accesstoken-overview.md#basic-principles), apply for permissions for an app by following the procedure illustrated in the figure below.

![](figures/permission-application-process.png)

1. For details about the mapping between the app's ability privilege level (APL) and permission level, see [Permission Levels](accesstoken-overview.md#permission-levels).
2. Permissions can be authorized by the user (user_grant) or the system (system_grant). For details, see [Permission Authorization Modes](accesstoken-overview.md#permission-authorization-modes).
3. In principle, an app with a lower APL cannot apply for higher permissions by default. The Access Control List (ACL) makes low-level apps have high-level permissions. For details, see [ACL](accesstoken-overview.md#acl).

The following lists the permissions defined by the system. For details about permission usage examples, see [Access Control Development](accesstoken-guidelines.md).

| Permission                                                  | APL    | Authorization Mode    | Enable ACL| Description                                                    |
| -------------------------------------------------------- | ------------ | ------------ | ------- | ------------------------------------------------------------ |
| ohos.permission.USE_BLUETOOTH                            | normal       | system_grant | TRUE    | Allows an app to access to Bluetooth configuration.                                    |
| ohos.permission.DISCOVER_BLUETOOTH                       | normal       | system_grant | TRUE    | Allows an app to configure Bluetooth on a device, initiate or cancel a scan for Bluetooth devices, and pair with Bluetooth devices.          |
| ohos.permission.MANAGE_BLUETOOTH                         | system_basic | system_grant | TRUE    | Allows an app to pair with a Bluetooth device and access the contacts or messages of the device.      |
| ohos.permission.INTERNET                                 | normal       | system_grant | TRUE    | Allows an app to access the Internet.                                      |
| ohos.permission.MODIFY_AUDIO_SETTINGS                    | normal       | system_grant | TRUE    | Allows an app to modify audio settings.                                      |
| ohos.permission.ACCESS_NOTIFICATION_POLICY               | normal       | system_grant | FALSE   | Allows an app to access the notification policy on the device.                            |
| ohos.permission.GET_TELEPHONY_STATE                      | system_basic | system_grant | TRUE    | Allows an app to read telephony information.                                       |
| ohos.permission.REQUIRE_FORM                             | system_basic | system_grant | TRUE    | Allows an app to obtain the Ability Form.                                  |
| ohos.permission.GET_NETWORK_INFO                         | normal       | system_grant | TRUE    | Allows an app to obtain network information.                                  |
| ohos.permission.PLACE_CALL                               | system_basic | system_grant | TRUE    | Allows an app to make calls without starting the dialer.                                      |
| ohos.permission.SET_NETWORK_INFO                         | normal       | system_grant | TRUE    | Allows an app to set data network information.                                      |
| ohos.permission.REMOVE_CACHE_FILES                       | system_basic | system_grant | TRUE    | Allows the cache of the specified app to be cleared.                                    |
| ohos.permission.REBOOT                                   | system_basic | system_grant | TRUE    | Allows an app to restart the device.                                          |
| ohos.permission.RUNNING_LOCK                             | normal       | system_grant | TRUE    | Allows an app to obtain a running lock.              |
| ohos.permission.ENROLL_BIOMETRIC                         | system_core  | system_grant | FALSE   | Allows an app to add or remove biometric data.                            |
| ohos.permission.ACCESS_BIOMETRIC                         | normal       | system_grant | FALSE   | Allows an app to use biometric recognition for identity authentication.                  |
| ohos.permission.ACCESS_BIOMETRIC_INTERNAL                | system_core  | system_grant | FALSE   | Allows an app to apply for or release biometric recognition resources.                      |
| ohos.permission.RESET_BIOMETRIC_LOCKOUT                  | system_core  | system_grant | FALSE   | Allows an app to reset the maximum number of failures allowed before biometric authentication is locked.                    |
| ohos.permission.SET_TIME                                 | system_basic | system_grant | TRUE    | Allows an app to set the system time.                                      |
| ohos.permission.SET_TIME_ZONE                            | system_basic | system_grant | TRUE    | Allows an app to set the system time zone.                                      |
| ohos.permission.DOWNLOAD_SESSION_MANAGER                 | system_core  | system_grant | TRUE    | Allows an app to manage the download sessions.                                  |
| ohos.permission.COMMONEVENT_STICKY                       | normal       | system_grant | TRUE    | Allows an app to publish sticky common events.                                  |
| ohos.permission.SYSTEM_FLOAT_WINDOW                      | normal       | system_grant | TRUE    | Allows an app to be displayed in a floating window on top of other apps.                                  |
| ohos.permission.POWER_MANAGER                            | system_core  | system_grant | TRUE    | Allows an app to hibernate or wake up the device by calling APIs.        |
| ohos.permission.REFRESH_USER_ACTION                      | system_basic | system_grant | TRUE    | Allows an app to reset the screen timeout counter when a user input event occurs, such as pressing a key or touching the screen.                |
| ohos.permission.POWER_OPTIMIZATION                       | system_basic | system_grant | TRUE    | Allows an app to set power saving mode, obtain configuration of the power saving mode, and receive notifications of the configuration changes.|
| ohos.permission.REBOOT_RECOVERY                          | system_basic | system_grant | TRUE    | Allows an app to restart the device and enter Recovery mode.                        |
| ohos.permission.MANAGE_LOCAL_ACCOUNTS                    | system_basic | system_grant | TRUE    | Allows an app to manage local user accounts.                                  |
| ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS           | system_basic | system_grant | TRUE    | Allows access between multiple OS accounts.                              |
| ohos.permission.VIBRATE                                  | normal       | system_grant | TRUE    | Allows an app to control vibration.                                      |
| ohos.permission.CONNECT_IME_ABILITY                      | system_core  | system_grant | TRUE    | Allows an app or service to bind to the **InputMethodAbility**.                 |
| ohos.permission.CONNECT_SCREEN_SAVER_ABILITY             | system_core  | system_grant | TRUE    | Allows an app or service to bind to the **ScreenSaverAbility**.                   |
| ohos.permission.READ_SCREEN_SAVER                        | system_basic | system_grant | TRUE    | Allows an app to read the screen saver information, such as the list of screen savers that have been installed and the activated one.                                  |
| ohos.permission.WRITE_SCREEN_SAVER                       | system_basic | system_grant | TRUE    | Allows an app to modify the screen saver information, such as activating and previewing a screen saver.                                  |
| ohos.permission.SET_WALLPAPER                            | normal       | system_grant | TRUE    | Allows an app to set a static wallpaper.                                      |
| ohos.permission.GET_WALLPAPER                            | system_basic | system_grant | TRUE    | Allows an app to read wallpaper files.                                      |
| ohos.permission.CHANGE_ABILITY_ENABLED_STATE             | system_basic | system_grant | TRUE    | Allows an app to enable or disable an app or component.                            |
| ohos.permission.ACCESS_MISSIONS                          | system_basic | system_grant | TRUE    | Allows an app to obtain information about running processes and mission in a mission stack.                                    |
| ohos.permission.CLEAN_BACKGROUND_PROCESSES               | normal       | system_grant | TRUE    | Allows an app to clear background processes based on their bundle names.                          |
| ohos.permission.KEEP_BACKGROUND_RUNNING                  | normal       | system_grant | TRUE    | Allows a Service ability to keep running in the background.                         |
| ohos.permission.UPDATE_CONFIGURATION                     | system_basic | system_grant | TRUE    | Allows an app to modify system settings.                                          |
| ohos.permission.UPDATE_SYSTEM                            | system_basic | system_grant | TRUE    | Allows an app to call the update APIs.                                          |
| ohos.permission.FACTORY_RESET                            | system_basic | system_grant | TRUE    | Allows an app to call the APIs for restoring factory settings.                                      |
| ohos.permission.GRANT_SENSITIVE_PERMISSIONS              | system_core  | system_grant | TRUE    | Allows an app to grant sensitive permissions to other apps.                            |
| ohos.permission.REVOKE_SENSITIVE_PERMISSIONS             | system_core  | system_grant | TRUE    | Allows an app to revoke sensitive permissions granted to other apps.                      |
| ohos.permission.GET_SENSITIVE_PERMISSIONS                | system_core  | system_grant | TRUE    | Allows an app to obtain the sensitive permissions that have been granted to other apps.                      |
| ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION | system_core  | system_grant | TRUE    | Allows an app to set the attributes of apps of other users.                    |
| ohos.permission.LISTEN_BUNDLE_CHANGE                     | system_basic | system_grant | TRUE    | Allows an app to listen for changes in other apps, when they are installed, updated, or uninstalled.            |
| ohos.permission.GET_BUNDLE_INFO                          | normal       | system_grant | TRUE    | Allows a non-system app to obtain information about other apps.                                |
| ohos.permission.ACCELEROMETER                            | normal       | system_grant | TRUE    | Allows an app to read data from an acceleration sensor, uncalibrated acceleration sensor, or linear acceleration sensor.                            |
| ohos.permission.GYROSCOPE                                | normal       | system_grant | TRUE    | Allows an app to read data from a gyroscope sensor or uncalibrated gyroscope sensor.                            |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED               | system_basic | system_grant | TRUE    | Allows a non-system app to obtain information about other apps.                                |
| ohos.permission.INSTALL_BUNDLE                           | system_core  | system_grant | TRUE    | Allows an app to install and uninstall other apps.                                |
| ohos.permission.MANAGE_SHORTCUTS                         | system_core  | system_grant | TRUE    | Allows an app to query and start shortcuts of other apps.|
| ohos.permission.radio.ACCESS_FM_AM                       | system_core  | system_grant | TRUE    | Allows an app to access radio services.                                |
| ohos.permission.SET_TELEPHONY_STATE                      | system_basic | system_grant | TRUE    | Allows an app to change the telephone state.                               |
| ohos.permission.START_ABILIIES_FROM_BACKGROUND           | system_basic | system_grant | TRUE    | Allows an app to start Feature abilities in the background.                                      |
| ohos.permission.BUNDLE_ACTIVE_INFO                       | system_basic | system_grant | TRUE    | Allows an app to obtain how long other apps have been running in the foreground or background.            |
| ohos.permission.START_INVISIBLE_ABILITY                  | system_core  | system_grant | TRUE    | Allows an app to start an invisible ability.                   |
| ohos.permission.sec.ACCESS_UDID                          | system_basic | system_grant | TRUE    | Allows an app to obtain the Unified Device ID (UDID).                                      |
| ohos.permission.LAUNCH_DATA_PRIVACY_CENTER               | system_basic | system_grant | TRUE    | Allows an app to switch from its privacy statement page to the <b>Data & privacy</b> page.            |
| ohos.permission.MANAGE_MEDIA_RESOURCES                   | system_basic | system_grant | TRUE    | Allows an app to obtain and manage the media resources that are being played on the device.|
| ohos.permission.PUBLISH_AGENT_REMINDER                   | normal       | system_grant | TRUE    | Allows an app to use agent-powered reminders.                                |
| ohos.permission.CONTROL_TASK_SYNC_ANIMATOR               | system_core  | system_grant | TRUE    | Allows apps to use sync task animations.                                  |
| ohos.permission.INPUT_MONITORING                         | system_core  | system_grant | TRUE    | Allows an app to listen for input events. Only the system signature apps can apply for this permission.          |
| ohos.permission.MANAGE_MISSIONS                          | system_core  | system_grant | TRUE    | Allows an app to manage ability mission stacks.                                  |
| ohos.permission.NOTIFICATION_CONTROLLER                  | system_core  | system_grant | TRUE    | Allows an app to manage and subscribe to notifications.                                |
| ohos.permission.CONNECTIVITY_INTERNAL                    | system_basic | system_grant | TRUE    | Allows an app to obtain network information or modify network settings.          |
| ohos.permission.SET_ABILITY_CONTROLLER                   | system_basic | system_grant | TRUE    | Allows an app to set the start and stop of an ability.                       |
| ohos.permission.USE_USER_IDM                             | system_basic | system_grant | FALSE   | Allows an app to access the system identity credential information.                              |
| ohos.permission.MANAGE_USER_IDM                          | system_basic | system_grant | FALSE   | Allows an app to use the system identity credential management capability to enroll, modify, and delete PINs, face images, and fingerprints.|
| ohos.permission.ACCESS_BIOMETRIC                         | normal       | system_grant | TRUE    | Allows an app to use biometric recognition for identity authentication.                  |
| ohos.permission.ACCESS_USER_AUTH_INTERNAL                | system_basic | system_grant | FALSE   | Allows an app to use the system identity authentication capability to authenticate or identify users.    |
| ohos.permission.ACCESS_PIN_AUTH                          | system_basic | system_grant | FALSE   | Allows a system app to call the PIN input APIs to present a password input dialog box for users.|
| ohos.permission.GET_RUNNING_INFO                         | system_basic | system_grant | TRUE    | Allows an app to obtain running status information.                                    |
| ohos.permission.CLEAN_APPLICATION_DATA                   | system_basic | system_grant | TRUE    | Allows an app to clear app data.                                      |
| ohos.permission.RUNNING_STATE_OBSERVER                   | system_basic | system_grant | TRUE    | Allows an app to observe the app status.                                      |
| ohos.permission.CAPTURE_SCREEN                           | system_core  | system_grant | TRUE    | Allows an app to take screenshots.                                      |
| ohos.permission.GET_WIFI_INFO                            | normal       | system_grant | TRUE    | Allows an app to obtain WLAN information.                                      |
| ohos.permission.GET_WIFI_INFO_INTERNAL                   | system_core  | system_grant | TRUE    | Allows an app to obtain WLAN information.                                      |
| ohos.permission.SET_WIFI_INFO                            | normal       | system_grant | TRUE    | Allows an app to set WLAN devices.                                      |
| ohos.permission.GET_WIFI_PEERS_MAC                       | system_core  | system_grant | TRUE    | Allows an app to obtain the MAC address of the peer WLAN or Bluetooth device.                 |
| ohos.permission.GET_WIFI_LOCAL_MAC                       | system_basic | system_grant | TRUE    | Allows an app to obtain the MAC address of the local WLAN or Bluetooth device.                 |
| ohos.permission.GET_WIFI_CONFIG                          | system_basic | system_grant | TRUE    | Allows an app to obtain the WLAN configuration.                                  |
| ohos.permission.SET_WIFI_CONFIG                          | system_basic | system_grant | TRUE    | Allows an app to set WLAN information.                                      |
| ohos.permission.MANAGE_WIFI_CONNECTION                   | system_core  | system_grant | TRUE    | Allows an app to manage WLAN connections.                                      |
| ohos.permission.MANAGE_WIFI_HOTSPOT                      | system_core  | system_grant | TRUE    | Allows an app to enable or disable Wi-Fi hotspots.                              |
| ohos.permission.GET_ALL_APP_ACCOUNTS                     | system_core  | system_grant | FALSE   | Allows an app to obtain all app account information.                              |
| ohos.permission.MANAGE_SECURE_SETTINGS                   | system_basic | system_grant | TRUE    | Allows an app to modify security settings.                                |
| ohos.permission.READ_DFX_SYSEVENT                        | system_basic | system_grant | FALSE   | Allows an app to obtain all app account information.                                  |
| ohos.permission.MANAGE_ADMIN                             | system_core  | system_grant | TRUE    | Allows an app to activate the device administrator app.                                |
| ohos.permission.EDM_MANAGE_DATETIME                      | normal       | system_grant | FALSE   | Allows the device administrator app to set the system time.                            |
| ohos.permission.NFC_TAG                                  | normal       | system_grant | FALSE   | Allows an app to read NFC tag information.                                       |
| ohos.permission.NFC_CARD_EMULATION                       | normal       | system_grant | FALSE   | Allows an app to implement card emulation.                                    |
| ohos.permission.PERMISSION_USED_STATS                    | system_core  | system_grant | TRUE    | Allows a system application to access the permission usage records.                              |
| ohos.permission.NOTIFICATION_AGENT_CONTROLLER            | system_core  | system_grant | TRUE    | Allows an app to send agent-powered notifications.                                      |
| ohos.permission.ANSWER_CALL                              | system_basic | user_grant   | TRUE    | Allows an app to answer incoming calls.                                          |
| ohos.permission.READ_CALENDAR                            | normal       | user_grant   | TRUE    | Allows an app to read calendar data.                                      |
| ohos.permission.READ_CALL_LOG                            | system_basic | user_grant   | TRUE    | Allows an app to read call logs.                                      |
| ohos.permission.READ_CELL_MESSAGES                       | system_basic | user_grant   | TRUE    | Allows an app to read cell broadcast messages received by the device.                        |
| ohos.permission.READ_CONTACTS                            | system_basic | user_grant   | TRUE    | Allows an app to read contacts.                                    |
| ohos.permission.READ_MESSAGES                            | system_basic | user_grant   | TRUE    | Allows an app to read messages.                                        |
| ohos.permission.RECEIVE_MMS                              | system_basic | user_grant   | TRUE    | Allows an app to receive and process MMS messages.                                    |
| ohos.permission.RECEIVE_SMS                              | system_basic | user_grant   | TRUE    | Allows an app to receive and process SMS messages.                                    |
| ohos.permission.RECEIVE_WAP_MESSAGES                     | system_basic | user_grant   | TRUE    | Allows an app to receive and process WAP messages.                                 |
| ohos.permission.MICROPHONE                               | normal       | user_grant   | TRUE    | Allows an app to access the microphone.                                        |
| ohos.permission.SEND_MESSAGES                            | system_basic | user_grant   | TRUE    | Allows an app to send messages.                                          |
| ohos.permission.WRITE_CALENDAR                           | normal       | user_grant   | TRUE    | Allows an app to add, remove, and modify calendar events.                          |
| ohos.permission.WRITE_CALL_LOG                           | system_basic | user_grant   | TRUE    | Allows an app to add, remove, and modify call logs.                          |
| ohos.permission.WRITE_CONTACTS                           | system_basic | user_grant   | TRUE    | Allows an app to add, remove, and modify contacts.                        |
| ohos.permission.DISTRIBUTED_DATASYNC                     | normal       | user_grant   | TRUE    | Allows an app to exchange data with other devices.                                  |
| ohos.permission.MANAGE_VOICEMAIL                         | system_basic | user_grant   | TRUE    | Allows an app to leave messages in the voice mailbox.                                    |
| ohos.permission.LOCATION_IN_BACKGROUND                   | normal       | user_grant   | FALSE   | Allows an app running in the background to obtain the device location.                      |
| ohos.permission.LOCATION                                 | normal       | user_grant   | TRUE    | Allows an app to obtain the device location.                                  |
| ohos.permission.MEDIA_LOCATION                           | normal       | user_grant   | TRUE    | Allows an app to access geographical locations in the user's media file.                  |
| ohos.permission.CAMERA                                   | normal       | user_grant   | TRUE    | Allows an app to use the camera to take photos and record videos.                        |
| ohos.permission.READ_MEDIA                               | normal       | user_grant   | TRUE    | Allows an app to read media files from the user's external storage.                  |
| ohos.permission.WRITE_MEDIA                              | normal       | user_grant   | TRUE    | Allows an app to read media files from and write media files into the user's external storage.                  |
| ohos.permission.ACTIVITY_MOTION                          | normal       | user_grant   | TRUE    | Allows an app to read the current workout status of the user.                            |
| ohos.permission.READ_HEALTH_DATA                         | normal       | user_grant   | TRUE    | Allows an app to read the health data of the user.                                |
| ohos.permission.GET_DEFAULT_APPLICATION                  | system_core  | system_grant | TRUE    | Allows an app to query default apps.                                      |
| ohos.permission.SET_DEFAULT_APPLICATION                  | system_core  | system_grant | TRUE    | Allows an app to set and reset default apps.                                |
| ohos.permission.MANAGE_DISPOSED_APP_STATUS               | system_core  | system_grant | TRUE    | Allows an app to set and query the app handling state.                              |
| ohos.permission.ACCESS_IDS                               | system_core  | system_grant | TRUE    | Allows an app to query the unique identifier of a device.                              |
