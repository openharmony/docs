# @ohos.commonEventManager

The **CommonEventManager** module provides common event capabilities, including the capabilities to publish, subscribe to, and unsubscribe from common events, as well obtaining and setting the common event result code and result data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import CommonEventManager from '@ohos.commonEventManager';
```

## Support

The table below lists the event types supported by the **CommonEventManager** module. The name and value indicate the macro and name of a common event, respectively.

**System capability**: SystemCapability.Notification.CommonEvent

| Name     | Value         | Subscriber Permission    | Description              |
| ------------ | ------------------ | ---------------------- | -------------------- |
| COMMON_EVENT_BOOT_COMPLETED                                  | usual.event.BOOT_COMPLETED                                  | ohos.permission.RECEIVER_STARTUP_COMPLETED                   | Indicates the common event that the user has finished booting and the system has been loaded.       |
| COMMON_EVENT_LOCKED_BOOT_COMPLETED                           | usual.event.LOCKED_BOOT_COMPLETED                           | ohos.permission.RECEIVER_STARTUP_COMPLETED                   | Indicates the common event that the user has finished booting and the system has been loaded but the screen is still locked.         |
| COMMON_EVENT_SHUTDOWN                                        | usual.event.SHUTDOWN                                        | -                                                          | Indicates the common event that the device is being shut down and the final shutdown will proceed.           |
| COMMON_EVENT_BATTERY_CHANGED                                 | usual.event.BATTERY_CHANGED                                 | -                                                          | Indicates the common event that the charging state, level, and other information about the battery have changed.         |
| COMMON_EVENT_BATTERY_LOW                                     | usual.event.BATTERY_LOW                                     | -                                                          | Indicates the common event that the battery level is low.         |
| COMMON_EVENT_BATTERY_OKAY                                    | usual.event.BATTERY_OKAY                                    | -                                                          | Indicates the common event that the battery exits the low state.   |
| COMMON_EVENT_POWER_CONNECTED                                 | usual.event.POWER_CONNECTED                                 | -                                                          | Indicates the common event that the device is connected to an external power supply.           |
| COMMON_EVENT_POWER_DISCONNECTED                              | usual.event.POWER_DISCONNECTED                              | -                                                          | Indicates the common event that the device is disconnected from the external power supply.           |
| COMMON_EVENT_SCREEN_OFF                                      | usual.event.SCREEN_OFF                                      | -                                                          | Indicates the common event that the device screen is off and the device is sleeping.           |
| COMMON_EVENT_SCREEN_ON                                       | usual.event.SCREEN_ON                                       | -                                                          | Indicates the common event that the device screen is on and the device is in interactive state. |
| COMMON_EVENT_THERMAL_LEVEL_CHANGED                           | usual.event.THERMAL_LEVEL_CHANGED                           | -                                                          | Indicates the common event that the device's thermal level has changed. |
| COMMON_EVENT_USER_PRESENT                                    | usual.event.USER_PRESENT                                    | -                                                          | Indicates the common event that the user unlocks the device.     |
| COMMON_EVENT_TIME_TICK                                       | usual.event.TIME_TICK                                       | -                                                          | Indicates the common event that the system time has changed.       |
| COMMON_EVENT_TIME_CHANGED                                    | usual.event.TIME_CHANGED                                    | -                                                          | Indicates the common event that the system time is set.     |
| COMMON_EVENT_DATE_CHANGED                                    | usual.event.DATE_CHANGED                                    | -                                                          | Indicates the common event that the system time has changed.       |
| COMMON_EVENT_TIMEZONE_CHANGED                                | usual.event.TIMEZONE_CHANGED                                | -                                                          | Indicates the common event that the system time zone has changed.         |
| COMMON_EVENT_CLOSE_SYSTEM_DIALOGS                            | usual.event.CLOSE_SYSTEM_DIALOGS                            | -                                                          | Indicates the common event that a user closes a temporary system dialog box.       |
| COMMON_EVENT_PACKAGE_ADDED                                   | usual.event.PACKAGE_ADDED                                   | -                                                          | Indicates the common event that a new application package has been installed on the device.     |
| COMMON_EVENT_PACKAGE_REPLACED                                | usual.event.PACKAGE_REPLACED                                | -                                                          | Indicates the common event that a later version of an installed application package has replaced the previous one on the device.       |
| COMMON_EVENT_MY_PACKAGE_REPLACED                             | usual.event.MY_PACKAGE_REPLACED                             | -                                                          | Indicates the common event that a later version of your application package has replaced the previous one. 
| COMMON_EVENT_PACKAGE_REMOVED                                 | usual.event.PACKAGE_REMOVED                                 | -                                                          | Indicates the common event that an installed application has been uninstalled from the device with the application data retained.   |
| COMMON_EVENT_BUNDLE_REMOVED                                  | usual.event.BUNDLE_REMOVED                                  | -                                                          | Indicates the common event that an installed bundle has been uninstalled from the device with the application data retained.   |
| COMMON_EVENT_PACKAGE_FULLY_REMOVED                           | usual.event.PACKAGE_FULLY_REMOVED                           | -                                                          | Indicates the common event that an installed application, including both the application data and code, has been completely uninstalled from the device.   |
| COMMON_EVENT_PACKAGE_CHANGED                                 | usual.event.PACKAGE_CHANGED                                 | -                                                          | Indicates the common event that an application package has been changed (for example, a component in the package has been enabled or disabled). |
| COMMON_EVENT_PACKAGE_RESTARTED                               | usual.event.PACKAGE_RESTARTED                               | -                                                          | Indicates the common event that the user has restarted the application package and killed all its processes.   |
| COMMON_EVENT_PACKAGE_DATA_CLEARED                            | usual.event.PACKAGE_DATA_CLEARED                            | -                                                          | Indicates the common event that the user has cleared the application package data.       |
| COMMON_EVENT_PACKAGE_CACHE_CLEARED<sup>9+</sup>              | usual.event.PACKAGE_CACHE_CLEARED                           | -                                                          | Indicates the common event that the user has cleared the application package data.       |
| COMMON_EVENT_PACKAGES_SUSPENDED                              | usual.event.PACKAGES_SUSPENDED                              | -                                                          | Indicates the common event that application packages have been suspended.         |
| COMMON_EVENT_PACKAGES_UNSUSPENDED                            | usual.event.PACKAGES_UNSUSPENDED                            | -                                                          | Indicates the common event that application package has not been suspended.       |
| COMMON_EVENT_MY_PACKAGE_SUSPENDED                            | usual.event.MY_PACKAGE_SUSPENDED                            | -                                                          | Indicates the common event that an application package has been suspended.         |
| COMMON_EVENT_MY_PACKAGE_UNSUSPENDED                          | usual.event.MY_PACKAGE_UNSUSPENDED                          | -                                                          | Indicates the common event that application package has not been suspended.       |
| COMMON_EVENT_UID_REMOVED                                     | usual.event.UID_REMOVED                                     | -                                                          | Indicates the common event that a user ID has been removed from the system.   |
| COMMON_EVENT_PACKAGE_FIRST_LAUNCH                            | usual.event.PACKAGE_FIRST_LAUNCH                            | -                                                          | Indicates the common event that an installed application is started for the first time.   |
| COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION                      | usual.event.PACKAGE_NEEDS_VERIFICATION                      | -                                                          | Indicates the common event that an application requires system verification.        |
| COMMON_EVENT_PACKAGE_VERIFIED                                | usual.event.PACKAGE_VERIFIED                                | -                                                          | Indicates the common event that an application has been verified by the system.       |
| COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE                 | usual.event.EXTERNAL_APPLICATIONS_AVAILABLE                 | -                                                          | Indicates the common event that applications installed on the external storage become available for the system.     |
| COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE               | usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE               | -                                                          | Indicates the common event that applications installed on the external storage become unavailable for the system.       |
| COMMON_EVENT_CONFIGURATION_CHANGED                           | usual.event.CONFIGURATION_CHANGED                           | -                                                          | Indicates the common event that the device state (for example, orientation and locale) has changed.       |
| COMMON_EVENT_LOCALE_CHANGED                                  | usual.event.LOCALE_CHANGED                                  | -                                                          | Indicates the common event that the device locale has changed.     |
| COMMON_EVENT_MANAGE_PACKAGE_STORAGE                          | usual.event.MANAGE_PACKAGE_STORAGE                          | -                                                          | Indicates the common event that the device storage is insufficient.       |
| COMMON_EVENT_DRIVE_MODE                                      | common.event.DRIVE_MODE                                     | -                                                          | Indicates the common event that the system is in driving mode.     |
| COMMON_EVENT_HOME_MODE                                       | common.event.HOME_MODE                                      | -                                                          | Indicates the common event that the system is in home mode.   |
| COMMON_EVENT_OFFICE_MODE                                     | common.event.OFFICE_MODE                                    | -                                                          | Indicates the common event that the system is in office mode.     |
| COMMON_EVENT_USER_STARTED                                    | usual.event.USER_STARTED                                    | -                                                          | Indicates the common event that the user has been started.     |
| COMMON_EVENT_USER_BACKGROUND                                 | usual.event.USER_BACKGROUND                                 | -                                                          | Indicates the common event that the user has been brought to the background.     |
| COMMON_EVENT_USER_FOREGROUND                                 | usual.event.USER_FOREGROUND                                 | -                                                          | Indicates the common event that the user has been brought to the foreground.       |
| COMMON_EVENT_USER_SWITCHED                                   | usual.event.USER_SWITCHED                                   | ohos.permission.MANAGE_LOCAL_ACCOUNTS                                 | Indicates the common event that user switching is happening.     |
| COMMON_EVENT_USER_STARTING                                   | usual.event.USER_STARTING                                   | ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS                        | Indicates the common event that the user is going to be started.       |
| COMMON_EVENT_USER_UNLOCKED                                   | usual.event.USER_UNLOCKED                                   | -                                                          | Indicates the common event that the credential-encrypted storage has been unlocked for the current user when the device is unlocked after being restarted.    |
| COMMON_EVENT_USER_STOPPING                                   | usual.event.USER_STOPPING                                   | ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS                        | Indicates the common event that the user is going to be stopped.   |
| COMMON_EVENT_USER_STOPPED                                    | usual.event.USER_STOPPED                                    | -                                                          | Indicates the common event that the user has been stopped.   |
| COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN                                     | usual.event.DISTRIBUTED_ACCOUNT_LOGIN                                    | -                                                          | Indicates the action of successful login using a distributed account.   |
| COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT                                     | usual.event.DISTRIBUTED_ACCOUNT_LOGOUT                                    | -                                                          | Indicates the action of successful logout of a distributed account.   |
| COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID                                     | usual.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID                                    | -                                                          | Indicates the action when the token of a distributed account is invalid.   |
| COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF                                     | usual.event.DISTRIBUTED_ACCOUNT_LOGOFF                                    | -                                                          | Indicates the action of deregistering a distributed account.   |
| COMMON_EVENT_WIFI_POWER_STATE                                | usual.event.wifi.POWER_STATE                                | -                                                          | Indicates the common event about the Wi-Fi network state, such as enabled and disabled.     |
| COMMON_EVENT_WIFI_SCAN_FINISHED                              | usual.event.wifi.SCAN_FINISHED                              | ohos.permission.LOCATION                                     | Indicates the common event that the Wi-Fi access point has been scanned and proven to be available.      |
| COMMON_EVENT_WIFI_RSSI_VALUE                                 | usual.event.wifi.RSSI_VALUE                                 | ohos.permission.GET_WIFI_INFO                                | Indicates the common event that the Wi-Fi signal strength (RSSI) has changed.     |
| COMMON_EVENT_WIFI_CONN_STATE                                 | usual.event.wifi.CONN_STATE                                 | -                                                          | Indicates the common event that the Wi-Fi connection state has changed.      |
| COMMON_EVENT_WIFI_HOTSPOT_STATE                              | usual.event.wifi.HOTSPOT_STATE                              | -                                                          | Indicates the common event about the Wi-Fi hotspot state, such as enabled or disabled.  |
| COMMON_EVENT_WIFI_AP_STA_JOIN                                | usual.event.wifi.WIFI_HS_STA_JOIN                           | ohos.permission.GET_WIFI_INFO                                | Indicates the common event that a client has joined the Wi-Fi hotspot of the current device.      |
| COMMON_EVENT_WIFI_AP_STA_LEAVE                               | usual.event.wifi.WIFI_HS_STA_LEAVE                          | ohos.permission.GET_WIFI_INFO                                |Indicates the common event that a client has disconnected from the Wi-Fi hotspot of the current device.      |
| COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE                        | usual.event.wifi.mplink.STATE_CHANGE                        | ohos.permission.MPLINK_CHANGE_STATE                          | Indicates the common event that the state of MPLINK (an enhanced Wi-Fi feature) has changed.    |
| COMMON_EVENT_WIFI_P2P_CONN_STATE                             | usual.event.wifi.p2p.CONN_STATE_CHANGE                      | ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION   | Indicates the common event that the Wi-Fi P2P connection state has changed.     |
| COMMON_EVENT_WIFI_P2P_STATE_CHANGED                          | usual.event.wifi.p2p.STATE_CHANGE                           | ohos.permission.GET_WIFI_INFO                                | Indicates the common event about the Wi-Fi P2P state, such as enabled and disabled.       |
| COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED                    | usual.event.wifi.p2p.DEVICES_CHANGE                         | ohos.permission.GET_WIFI_INFO                                | Indicates the common event about the status change of Wi-Fi P2P peer devices.    |
| COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED          | usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE            | ohos.permission.GET_WIFI_INFO                                | Indicates the common event about the Wi-Fi P2P discovery status change.      |
| COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED           | usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE                  | ohos.permission.GET_WIFI_INFO                                | Indicates the common event about the status change of the Wi-Fi P2P local device.       |
| COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED                    | usual.event.wifi.p2p.GROUP_STATE_CHANGED                    | ohos.permission.GET_WIFI_INFO                                | Indicates the common event that the Wi-Fi P2P group information has changed.       |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE     | usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE     | ohos.permission.USE_BLUETOOTH                                | Indicates the common event about the connection state of Bluetooth handsfree communication.       |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE    | usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE    | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the device connected to the Bluetooth handsfree is active.       |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE       | usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the connection state of Bluetooth A2DP has changed.       |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE       | usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                | Indicates the common event about the connection state of Bluetooth A2DP.     |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE      | usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE      | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the device connected using Bluetooth A2DP is active.     |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE       | usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the playing state of Bluetooth A2DP has changed.     |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE | usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the AVRCP connection state of Bluetooth A2DP has changed.     |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE         | usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE         | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the audio codec state of Bluetooth A2DP has changed.      |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED               | usual.event.bluetooth.remotedevice.DISCOVERED               | ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH   | Indicates the common event that a remote Bluetooth device is discovered.       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE       | usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE       | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the Bluetooth class of a remote Bluetooth device has changed.       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED            | usual.event.bluetooth.remotedevice.ACL_CONNECTED            | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that a low-ACL connection has been established with a remote Bluetooth device.     |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED         | usual.event.bluetooth.remotedevice.ACL_DISCONNECTED         | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that a low-ACL connection has been disconnected from a remote Bluetooth device.     |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE              | usual.event.bluetooth.remotedevice.NAME_UPDATE              | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the friendly name of a remote Bluetooth device is retrieved for the first time or is changed since the last retrieval.       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE               | usual.event.bluetooth.remotedevice.PAIR_STATE               | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the connection state of a remote Bluetooth device has changed.       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE     | usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE     | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the battery level of a remote Bluetooth device is retrieved for the first time or is changed since the last retrieval.     |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT               | usual.event.bluetooth.remotedevice.SDP_RESULT               | -                                                          | Indicates the common event about the SDP state of a remote Bluetooth device.    |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE               | usual.event.bluetooth.remotedevice.UUID_VALUE               | ohos.permission.DISCOVER_BLUETOOTH                           | Indicates the common event about the UUID connection state of a remote Bluetooth device.     |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ              | usual.event.bluetooth.remotedevice.PAIRING_REQ              | ohos.permission.DISCOVER_BLUETOOTH                           | Indicates the common event about the pairing request from a remote Bluetooth device.       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL           | usual.event.bluetooth.remotedevice.PAIRING_CANCEL           | -                                                          | Indicates the common event that Bluetooth pairing is canceled.       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ              | usual.event.bluetooth.remotedevice.CONNECT_REQ              | -                                                          | Indicates the common event about the connection request from a remote Bluetooth device.       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY            | usual.event.bluetooth.remotedevice.CONNECT_REPLY            | -                                                          | Indicates the common event about the response to the connection request from a remote Bluetooth device.       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL           | usual.event.bluetooth.remotedevice.CONNECT_CANCEL           | -                                                          | Indicates the common event that the connection to a remote Bluetooth device has been canceled.       |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE    | -                                                          | Indicates the common event that the connection state of a Bluetooth handsfree has changed.       |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE      | usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE      | -                                                          | Indicates the common event that the audio state of a Bluetooth handsfree has changed.       |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT         | usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT         | -                                                          | Indicates the common event that the audio gateway state of a Bluetooth handsfree has changed.       |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE    | -                                                          | Indicates the common event that the calling state of a Bluetooth handsfree has changed.       |
| COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE                     | usual.event.bluetooth.host.STATE_UPDATE                     | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the state of a Bluetooth adapter has been changed, for example, Bluetooth has been enabled or disabled.       |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE                 | usual.event.bluetooth.host.REQ_DISCOVERABLE                 | -                                                          | Indicates the common event about the request for the user to allow Bluetooth device scanning.     |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE                       | usual.event.bluetooth.host.REQ_ENABLE                       | ohos.permission.USE_BLUETOOTH                                | Indicates the common event about the request for the user to enable Bluetooth.       |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE                      | usual.event.bluetooth.host.REQ_DISABLE                      | ohos.permission.USE_BLUETOOTH                                | Indicates the common event about the request for the user to disable Bluetooth.     |
| COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE                 | usual.event.bluetooth.host.SCAN_MODE_UPDATE                 | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the Bluetooth scanning mode of a device has changed.       |
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED                | usual.event.bluetooth.host.DISCOVERY_STARTED                | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the Bluetooth scanning has been started on the device.       |
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED               | usual.event.bluetooth.host.DISCOVERY_FINISHED               | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the Bluetooth scanning is finished on the device.       |
| COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE                      | usual.event.bluetooth.host.NAME_UPDATE                      | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the Bluetooth adapter name of the device has changed.       |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE         | usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE         | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the connection state of Bluetooth A2DP Sink has changed.       |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE         | usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE         | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the playing state of Bluetooth A2DP Sink has changed.       |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE           | usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE           | ohos.permission.USE_BLUETOOTH                                | Indicates the common event that the audio state of Bluetooth A2DP Sink has changed.       |
| COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED                | usual.event.nfc.action.ADAPTER_STATE_CHANGED                | -                                                          | Indicates the common event that the state of the device's NFC adapter has changed.    |
| COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED                 | usual.event.nfc.action.RF_FIELD_ON_DETECTED                 | ohos.permission.MANAGE_SECURE_SETTINGS                       | Indicates the action of a common event that the NFC RF field is detected to be in the enabled state.      |
| COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED                | usual.event.nfc.action.RF_FIELD_OFF_DETECTED                | ohos.permission.MANAGE_SECURE_SETTINGS                       | Indicates the common event that the NFC RF field is detected to be in the disabled state.  |
| COMMON_EVENT_DISCHARGING                                     | usual.event.DISCHARGING                                     | -                                                          | Indicates the common event that the system stops charging the battery.    |
| COMMON_EVENT_CHARGING                                        | usual.event.CHARGING                                        | -                                                          | Indicates the common event that the system starts charging the battery.   |
| COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED                        | usual.event.DEVICE_IDLE_MODE_CHANGED                        | -                                                          | Indicates the common event that the system idle mode has changed.   |
| COMMON_EVENT_POWER_SAVE_MODE_CHANGED                         | usual.event.POWER_SAVE_MODE_CHANGED                         | -                                                          | Indicates the common event that the power saving mode of the system has changed.     |
| COMMON_EVENT_USER_ADDED                                      | usual.event.USER_ADDED                                      | ohos.permission.MANAGE_LOCAL_ACCOUNTS                                 | Indicates the common event that a user has been added to the system.       |
| COMMON_EVENT_USER_REMOVED                                    | usual.event.USER_REMOVED                                    | ohos.permission.MANAGE_LOCAL_ACCOUNTS                                 | Indicates the common event that a user has been removed from the system.       |
| COMMON_EVENT_ABILITY_ADDED                                   | usual.event.ABILITY_ADDED                                   | ohos.permission.LISTEN_BUNDLE_CHANGE                         | Indicates the common event that an ability has been added.    |
| COMMON_EVENT_ABILITY_REMOVED                                 | usual.event.ABILITY_REMOVED                                 | ohos.permission.LISTEN_BUNDLE_CHANGE                         | Indicates the common event that an ability has been removed.    |
| COMMON_EVENT_ABILITY_UPDATED                                 | usual.event.ABILITY_UPDATED                                 | ohos.permission.LISTEN_BUNDLE_CHANGE                         | Indicates the common event that an ability has been updated.    |
| COMMON_EVENT_LOCATION_MODE_STATE_CHANGED                     | usual.event.location.MODE_STATE_CHANGED                     | -                                                          | Indicates the common event that the location mode of the system has changed.    |
| COMMON_EVENT_IVI_SLEEP                                       | common.event.IVI_SLEEP                                      | -                                                          | Indicates the common event that the in-vehicle infotainment (IVI) system of a vehicle is sleeping.       |
| COMMON_EVENT_IVI_PAUSE                                       | common.event.IVI_PAUSE                                      | -                                                          | Indicates the common event that the IVI system of a vehicle has entered sleep mode and the playing application is instructed to stop playback.   |
| COMMON_EVENT_IVI_STANDBY                                     | common.event.IVI_STANDBY                                    | -                                                          | Indicates the common event that a third-party application is instructed to pause the current work.    |
| COMMON_EVENT_IVI_LASTMODE_SAVE                               | common.event.IVI_LASTMODE_SAVE                              | -                                                          | Indicates the common event that a third-party application is instructed to save its last mode.     |
| COMMON_EVENT_IVI_VOLTAGE_ABNORMAL                            | common.event.IVI_VOLTAGE_ABNORMAL                           | -                                                          | Indicates the common event that the voltage of the vehicle's power system is abnormal.    |
| COMMON_EVENT_IVI_HIGH_TEMPERATURE                            | common.event.IVI_HIGH_TEMPERATURE                           | -                                                          | Indicates the common event that the temperature of the IVI system is high.    |
| COMMON_EVENT_IVI_EXTREME_TEMPERATURE                         | common.event.IVI_EXTREME_TEMPERATURE                        | -                                                          | Indicates the common event that the temperature of the IVI system is extremely high.    |
| COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL                        | common.event.IVI_TEMPERATURE_ABNORMAL                       | -                                                          | Indicates the common event that the IVI system has an extreme temperature.    |
| COMMON_EVENT_IVI_VOLTAGE_RECOVERY                            | common.event.IVI_VOLTAGE_RECOVERY                           | -                                                          | Indicates the common event that the voltage of the vehicle's power system is restored to normal.    |
| COMMON_EVENT_IVI_TEMPERATURE_RECOVERY                        | common.event.IVI_TEMPERATURE_RECOVERY                       | -                                                          | Indicates the common event that the temperature of the IVI system is restored to normal.    |
| COMMON_EVENT_IVI_ACTIVE                                      | common.event.IVI_ACTIVE                                     | -                                                          | Indicates the common event that the battery service is active.       |
|COMMON_EVENT_USB_STATE<sup>9+</sup>                           | usual.event.hardware.usb.action.USB_STATE                   | -                                                          | Indicates a common event indicating that the USB device status changes.    |
|COMMON_EVENT_USB_PORT_CHANGED<sup>9+</sup>                    | usual.event.hardware.usb.action.USB_PORT_CHANGED            | -                                                          | Indicates the public event that the USB port status of the user device changes.         |
| COMMON_EVENT_USB_DEVICE_ATTACHED                             | usual.event.hardware.usb.action.USB_DEVICE_ATTACHED         | -                                                          | Indicates the common event that a USB device has been attached when the user device functions as a USB host.      |
| COMMON_EVENT_USB_DEVICE_DETACHED                             | usual.event.hardware.usb.action.USB_DEVICE_DETACHED         | -                                                          | Indicates the common event that a USB device has been detached when the user device functions as a USB host.      | 
| COMMON_EVENT_USB_ACCESSORY_ATTACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED      | -                                                          | Indicates the common event that a USB accessory was attached.      |
| COMMON_EVENT_USB_ACCESSORY_DETACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED      | -                                                          | Indicates the common event that a USB accessory was detached.    |
| COMMON_EVENT_DISK_REMOVED                                    | usual.event.data.DISK_REMOVED                               | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was removed.    |
| COMMON_EVENT_DISK_UNMOUNTED                                  | usual.event.data.DISK_UNMOUNTED                             | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was unmounted.    |
| COMMON_EVENT_DISK_MOUNTED                                    | usual.event.data.DISK_MOUNTED                               | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was mounted.    |
| COMMON_EVENT_DISK_BAD_REMOVAL                                | usual.event.data.DISK_BAD_REMOVAL                           | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was removed without being unmounted.      |
| COMMON_EVENT_DISK_UNMOUNTABLE                                | usual.event.data.DISK_UNMOUNTABLE                           | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device becomes unmountable.    |
| COMMON_EVENT_DISK_EJECT                                      | usual.event.data.DISK_EJECT                                 | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was ejected.      |
| COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>                                  | usual.event.data.VOLUME_REMOVED                             | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was removed.    |
| COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>                                | usual.event.data.VOLUME_UNMOUNTED                           | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was unmounted.    |
| COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>                                  | usual.event.data.VOLUME_MOUNTED                             | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was mounted.    |
| COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>                              | usual.event.data.VOLUME_BAD_REMOVAL                         | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was removed without being unmounted.      |
| COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>                                    | usual.event.data.VOLUME_EJECT                               | ohos.permission.STORAGE_MANAGER | Indicates the common event that an external storage device was ejected.      |
| COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED                        | usual.event.data.VISIBLE_ACCOUNTS_UPDATED                   | ohos.permission.GET_APP_ACCOUNTS                             | Indicates the common event that the account visibility changed.       |
| COMMON_EVENT_ACCOUNT_DELETED                                 | usual.event.data.ACCOUNT_DELETED                            | ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS               | Indicates the common event that the account was deleted.     |
| COMMON_EVENT_FOUNDATION_READY                                | usual.event.data.FOUNDATION_READY                           | ohos.permission.RECEIVER_STARTUP_COMPLETED                   | Indicates the common event that the foundation is ready.     |
| COMMON_EVENT_AIRPLANE_MODE_CHANGED                           | usual.event.AIRPLANE_MODE                                   | -                                                          | Indicates the common event that the airplane mode of the device has changed.     |
| COMMON_EVENT_SPLIT_SCREEN                                    | usual.event.SPLIT_SCREEN                                    | ohos.permission.RECEIVER_SPLIT_SCREEN                        | Indicates the common event of screen splitting.     |
| COMMON_EVENT_SLOT_CHANGE<sup>9+<sup>                                    | usual.event.SLOT_CHANGE                                    | ohos.permission.NOTIFICATION_CONTROLLER                        | Indicates the common event that the notification slot has been updated.     |
| COMMON_EVENT_SPN_INFO_CHANGED <sup>9+<sup>                                    | usual.event.SPN_INFO_CHANGED                                    | -                       | Indicates the common event that the SPN displayed has been updated.     |
| COMMON_EVENT_QUICK_FIX_APPLY_RESULT <sup>9+<sup>                                    | usual.event.QUICK_FIX_APPLY_RESULT                        | -                       | Indicates the common event that a quick fix is applied to the application.     |


## CommonEventManager.publish

publish(event: string, callback: AsyncCallback\<void>): void

Publishes a common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | Yes  | Name of the common event to publish.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**
For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

|ID   |Error Message           |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

**Example**

```ts
// Callback for common event publication
function publishCallBack(err) {
	if (err) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

// Publish a common event.
try {
    CommonEventManager.publish("event", publishCallBack);
} catch(err) {
    console.error('publish failed, catch error' + JSON.stringify(err));
}
```

## CommonEventManager.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. |
| options  | [CommonEventPublishData](#commoneventpublishdata) | Yes  | Attributes of the common event to publish.|
| callback | syncCallback\<void>   | Yes  | Callback used to return the result. |

**Error codes**
|ID   |Error Message           |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|


**Example**


```ts
// Attributes of a common event.
var options = {
	code: 0,			 // Result code of the common event.
	data: "initial data";// Result data of the common event.
	isOrdered: true	 // The common event is an ordered one.
}

// Callback for common event publication
function publishCallBack(err) {
	if (err) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

// Publish a common event.
try {
    CommonEventManager.publish("event", options, publishCallBack);
} catch (err) {
    console.error('publish failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.publishAsUser<sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

Publishes a common event to a specific user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | Yes  | Name of the common event to publish.            |
| userId   | number               | Yes  | User ID.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.            |

**Error codes**
|ID   |Error Message           |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

**Example**

```ts
// Callback for common event publication
function publishAsUserCallBack(err) {
	if (err) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
var userId = 100;

// Publish a common event.
try {
    CommonEventManager.publishAsUser("event", userId, publishAsUserCallBack);
} catch (err) {
    console.error('publishAsUser failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.publishAsUser

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes to a specific user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. |
| userId   | number | Yes| User ID.|
| options  | [CommonEventPublishData](#commoneventpublishdata) | Yes  | Attributes of the common event to publish.|
| callback | AsyncCallback\<void>   | Yes  | Callback used to return the result. |

**Error codes**
|ID   |Error Message           |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

**Example**


```ts
// Attributes of a common event.
var options = {
	code: 0,			 // Result code of the common event.
	data: "initial data";// Result data of the common event.
}

// Callback for common event publication
function publishAsUserCallBack(err) {
	if (err) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
var userId = 100;

// Publish a common event.
try {
    CommonEventManager.publishAsUser("event", userId, options, publishAsUserCallBack);
} catch (err) {
    console.error('publishAsUser failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

Creates a subscriber. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                        | Mandatory| Description                      |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](#commoneventsubscribeinfo)        | Yes  | Subscriber information.            |
| callback      | AsyncCallback\<[CommonEventSubscriber](#commoneventsubscriber)> | Yes  | Callback used to return the result.|

**Example**


```ts
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
var subscribeInfo = {
    events: ["event"]
};

// Callback for subscriber creation.
function createSubscriberCallBack(err, commonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    } else {
        console.error("createSubscriber failed " + JSON.stringify(err));
    }
}

// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

Creates a subscriber. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                 | Mandatory| Description          |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](#commoneventsubscribeinfo) | Yes  | Subscriber information.|

**Return value**
| Type                                                     | Description            |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](#commoneventsubscriber)> | Promise used to return the subscriber object.|

**Example**

```ts
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
var subscribeInfo = {
	events: ["event"]
};

// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err) => {
    console.error("createSubscriber failed " + JSON.stringify(err));
});
} catch(err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}

```



## CommonEventManager.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

Subscribes to common events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                               | Mandatory| Description                            |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](#commoneventsubscriber)     | Yes  | Subscriber object.                |
| callback   | AsyncCallback\<[CommonEventData](#commoneventdata)> | Yes  | Callback used to return the result.|

**Example**

```ts
// Subscriber information.
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
var subscribeInfo = {
    events: ["event"]
};

// Callback for common event subscription.
function SubscribeCallBack(err, data) {
    if (err.code) {
        console.error("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe ");
    }
}

// Callback for subscriber creation.
function createSubscriberCallBack(err, commonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
            CommonEventManager.subscribe(subscriber, SubscribeCallBack);
        } catch (err) {
            console.error("createSubscriber failed " + JSON.stringify(err));
        }
    } else {
        console.error("createSubscriber failed " + JSON.stringify(err));
    }
}

// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

Unsubscribes from common events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                            | Mandatory| Description                    |
| ---------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | [CommonEventSubscriber](#commoneventsubscriber) | Yes  | Subscriber object.        |
| callback   | AsyncCallback\<void>                            | No  | Callback used to return the result.|

**Example**

```ts
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.
// Subscriber information.
var subscribeInfo = {
    events: ["event"]
};
// Callback for common event subscription.
function subscribeCallBack(err, data) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe");
    }
}
// Callback for subscriber creation.
function createSubscriberCallBack(err, commonEventSubscriber) {
    if (err) {
        console.info("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
            CommonEventManager.subscribe(subscriber, subscribeCallBack);
        } catch(err) {
            console.info("subscribe failed " + JSON.stringify(err));
        }
    }
}
// Callback for common event unsubscription.
function unsubscribeCallBack(err) {
    if (err) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe");
    }
}
// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.info("createSubscriber failed " + JSON.stringify(err));
}

// Unsubscribe from the common event.
try {
    CommonEventManager.unsubscribe(subscriber, unsubscribeCallBack);
} catch (err) {
    console.info("unsubscribe failed " + JSON.stringify(err));
}
```

## CommonEventSubscriber

### getCode

getCode(callback: AsyncCallback\<number>): void

Obtains the result code of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description              |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result code obtaining of an ordered common event.
function getCodeCallback(err, Code) {
    if (err.code) {
        console.error("getCode failed " + JSON.stringify(err));
    } else {
        console.info("getCode " + JSON.stringify(Code));
    }
}
subscriber.getCode(getCodeCallback);
```

### getCode

getCode(): Promise\<number>

Obtains the result code of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<number> | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.getCode().then((Code) => {
    console.info("getCode " + JSON.stringify(Code));
}).catch((err) => {
    console.error("getCode failed " + JSON.stringify(err));
});
```

### setCode

setCode(code: number, callback: AsyncCallback\<void>): void

Sets the result code for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Result code of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result code setting of an ordered common event.
function setCodeCallback(err) {
    if (err.code) {
        console.error("setCode failed " + JSON.stringify(err));
    } else {
        console.info("setCode");
    }
}
subscriber.setCode(1, setCodeCallback);
```

### setCode

setCode(code: number): Promise\<void>

Sets the result code for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Result code of the common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error("setCode failed " + JSON.stringify(err));
});
```

### getData

getData(callback: AsyncCallback\<string>): void

Obtains the result data of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result data.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result data obtaining of an ordered common event.
function getDataCallback(err, Data) {
    if (err.code) {
        console.error("getData failed " + JSON.stringify(err));
    } else {
        console.info("getData " + JSON.stringify(Data));
    }
}
subscriber.getData(getDataCallback);
```

### getData

getData(): Promise\<string>

Obtains the result data of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description              |
| ---------------- | ------------------ |
| Promise\<string> | Promise used to return the result data.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.getData().then((Data) => {
    console.info("getData " + JSON.stringify(Data));
}).catch((err) => {
    console.error("getData failed " + JSON.stringify(err));
});
```

### setData

setData(data: string, callback: AsyncCallback\<void>): void

Sets the result data for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | Yes  | Result data of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result data setting of an ordered common event
function setDataCallback(err) {
    if (err.code) {
        console.error("setData failed " + JSON.stringify(err));
    } else {
        console.info("setData");
    }
}
subscriber.setData("publish_data_changed", setDataCallback);
```

### setData

setData(data: string): Promise\<void>

Sets the result data for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| data   | string | Yes  | Result data of the common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error("setData failed " + JSON.stringify(err));
});
```

### setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

Sets the result code and result data for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Result code of the common event.  |
| data     | string               | Yes  | Result data of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result code and result data setting of an ordered common event.
function setCodeDataCallback(err) {
    if (err.code) {
        console.error("setCodeAndData failed " + JSON.stringify(err));
    } else {
        console.info("setCodeDataCallback");
    }
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCallback);
```

### setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

Sets the result code and result data for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| code   | number | Yes  | Result code of the common event.|
| data   | string | Yes  | Result data of the common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.info("setCodeAndData failed " + JSON.stringify(err));
});
```

### isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is an ordered one. This API uses an asynchronous callback to return the result.

 

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the common event is an ordered one; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is an ordered one.
function isOrderedCallback(err, isOrdered) {
    if (err.code) {
        console.error("isOrderedCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isOrdered " + JSON.stringify(isOrdered));
    }
}
subscriber.isOrderedCommonEvent(isOrderedCallback);
```

### isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

Checks whether this common event is an ordered one. This API uses a promise to return the result.

 

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the common event is an ordered one; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error("isOrdered failed " + JSON.stringify(err));
});
```

### isStickyCommonEvent

isStickyCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is a sticky one. This API uses an asynchronous callback to return the result.

 

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the common event is a sticky one; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is a sticky one.
function isStickyCallback(err, isSticky) {
    if (err.code) {
        console.error("isStickyCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isSticky " + JSON.stringify(isSticky));
    }
}
subscriber.isStickyCommonEvent(isStickyCallback);
```

### isStickyCommonEvent

isStickyCommonEvent(): Promise\<boolean>

Checks whether this common event is a sticky one. This API uses a promise to return the result.

 

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the common event is a sticky one; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error("isSticky failed " + JSON.stringify(err));
});
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for common event aborting.
function abortCallback(err) {
    if (err.code) {
        console.error("abortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("abortCommonEvent");
    }
}
subscriber.abortCommonEvent(abortCallback);
```

### abortCommonEvent

abortCommonEvent(): Promise\<void>

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error("abortCommonEvent failed " + JSON.stringify(err));
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for clearing the aborted state of the current common event.
function clearAbortCallback(err) {
    if (err.code) {
        console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("clearAbortCommonEvent");
    }
}
subscriber.clearAbortCommonEvent(clearAbortCallback);
```

### clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the ordered common event is in the aborted state; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is in the aborted state.
function getAbortCallback(err, AbortCommonEvent) {
    if (err.code) {
        console.error("getAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("AbortCommonEvent " + AbortCommonEvent)
    }
}
subscriber.getAbortCommonEvent(getAbortCallback);
```

### getAbortCommonEvent

getAbortCommonEvent(): Promise\<boolean>

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                              |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the ordered common event is in the aborted state; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.getAbortCommonEvent().then((AbortCommonEvent) => {
    console.info("AbortCommonEvent " + JSON.stringify(AbortCommonEvent));
}).catch((err) => {
    console.error("getAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

Obtains the subscriber information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Yes  | Callback used to return the subscriber information.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for subscriber information obtaining.
function getSubscribeInfoCallback(err, SubscribeInfo) {
    if (err.code) {
        console.error("getSubscribeInfo failed " + JSON.stringify(err));
    } else {
        console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
    }
}
subscriber.getSubscribeInfo(getSubscribeInfoCallback);
```

### getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

Obtains the subscriber information. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Promise used to return the subscriber information.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.getSubscribeInfo().then((SubscribeInfo) => {
    console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
}).catch((err) => {
    console.error("getSubscribeInfo failed " + JSON.stringify(err));
});
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(callback: AsyncCallback\<void\>): void

Finishes this ordered common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                 | Mandatory| Description                             |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback returned after the ordered common event is finished.|

**Example**

```ts
var subscriber; // Subscriber object successfully created.

// Callback for ordered common event finishing.
function finishCommonEventCallback(err) {
  if (err.code) {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
} else {
    console.info("FinishCommonEvent");
}
}
subscriber.finishCommonEvent(finishCommonEventCallback);
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(): Promise\<void\>

Finishes this ordered common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
});
```

## CommonEventData

**System capability**: SystemCapability.Notification.CommonEvent

| Name      | Type                | Readable| Writable| Description                                                   |
| ---------- |-------------------- | ---- | ---- |  ------------------------------------------------------- |
| event      | string               | Yes | No | Name of the common event that is being received.                             |
| bundleName | string               | Yes | No | Bundle name.                                             |
| code       | number               | Yes | No | Result code of the common event, which is used to transfer data of the int type.          |
| data       | string               | Yes | No | Custom result data of the common event, which is used to transfer data of the string type.|
| parameters | {[key: string]: any} | Yes | No | Additional information about the common event.                                 |


## CommonEventPublishData

**System capability**: SystemCapability.Notification.CommonEvent

| Name                 | Type                | Readable| Writable| Description                        |
| --------------------- | -------------------- | ---- | ---- | ---------------------------- |
| bundleName            | string               | Yes | No | Bundle name.                  |
| code                  | number               | Yes | No | Result code of the common event.      |
| data                  | string               | Yes | No | Custom result data of the common event.|
| subscriberPermissions | Array\<string>       | Yes | No | Permissions required for subscribers to receive the common event.            |
| isOrdered             | boolean              | Yes | No | Whether the common event is an ordered one.          |
| isSticky              | boolean              | Yes | No | Whether the common event is a sticky one. Only system applications and system services are allowed to send sticky events.|
| parameters            | {[key: string]: any} | Yes | No | Additional information about the common event.      |

## CommonEventSubscribeInfo

**System capability**: SystemCapability.Notification.CommonEvent

| Name               | Type          | Readable| Writable| Description                                                        |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| events              | Array\<string> | Yes | No | Name of the common event to publish.                                        |
| publisherPermission | string         | Yes | No | Permissions required for publishers to publish the common event.                                            |
| publisherDeviceId   | string         | Yes | No | Device ID. The value must be the ID of an existing device on the same network.            |
| userId              | number         | Yes | No | User ID. The default value is the ID of the current user. If this parameter is specified, the value must be an existing user ID in the system.|
| priority            | number         | Yes | No | Subscriber priority. The value ranges from -100 to +1000.                    |
