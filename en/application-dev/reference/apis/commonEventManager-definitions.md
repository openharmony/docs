# System Common Events

This document provides indexes for system common events defined in OpenHarmony.
For details about the definition of a system common event, see [Support in @ohos.commonEventManager (Common Event)](./js-apis-commonEventManager.md#support).

**System capability**: SystemCapability.Notification.CommonEvent

## [COMMON_EVENT_BOOT_COMPLETED](./common_event/commonEvent-ability.md)
Indicates that the user has finished the boot process.

## COMMON_EVENT_LOCKED_BOOT_COMPLETED
(Reserved, not supported yet) Indicates that the user has finished the boot process but the screen is still locked.
- Value: **usual.event.LOCKED_BOOT_COMPLETED**
- Required subscriber permissions: ohos.permission.RECEIVER_STARTUP_COMPLETED

## [COMMON_EVENT_SHUTDOWN](./common_event/commonEvent-powermgr.md)
Indicates that the device is being shut down and the final shutdown will proceed.

## [COMMON_EVENT_BATTERY_CHANGED](./common_event/commonEvent-powermgr.md)
Indicates that the charging state, level, and other information about the battery have changed.

## [COMMON_EVENT_BATTERY_LOW](./common_event/commonEvent-powermgr.md)
Indicates that the battery level is low.

## [COMMON_EVENT_BATTERY_OKAY](./common_event/commonEvent-powermgr.md)
Indicates that the battery level is normal.

## [COMMON_EVENT_POWER_CONNECTED](./common_event/commonEvent-powermgr.md)
Indicates that the device is connected to an external power supply.

## [COMMON_EVENT_POWER_DISCONNECTED](./common_event/commonEvent-powermgr.md)
Indicates that the device is disconnected from the external power supply.

## [COMMON_EVENT_SCREEN_OFF](./common_event/commonEvent-powermgr.md)
Indicates that the device screen is off and the device is in sleep mode.

## [COMMON_EVENT_SCREEN_ON](./common_event/commonEvent-powermgr.md)
Indicates that the device screen is on and the device is in the active state.

## [COMMON_EVENT_THERMAL_LEVEL_CHANGED](./common_event/commonEvent-powermgr.md)
Indicates that the device's thermal level has changed.

## COMMON_EVENT_USER_PRESENT<sup>(deprecated)</sup>
(Reserved, not supported yet) Indicates that the user unlocks the device.
- Value: **usual.event.USER_PRESENT**
- Required subscriber permissions: none
> NOTE
>
> This API is deprecated since API version 10.
> You are advised to use [COMMON_EVENT_SCREEN_UNLOCKED<sup>10+<sup>](./common_event/commonEvent-screenlock.md) instead.

## [COMMON_EVENT_TIME_TICK](./common_event/commonEvent-time.md)
Indicates that the system time has changed as time ticks by.

## [COMMON_EVENT_TIME_CHANGED](./common_event/commonEvent-time.md)
Indicates that the system time is set.

## COMMON_EVENT_DATE_CHANGED
(Reserved, not supported yet) Indicates that the system date has changed.
- Value: **usual.event.DATE_CHANGED**
- Required subscriber permissions: none

## [COMMON_EVENT_TIMEZONE_CHANGED](./common_event/commonEvent-time.md)
Indicates that the system time zone has changed.

## COMMON_EVENT_CLOSE_SYSTEM_DIALOGS
(Reserved, not supported yet) Indicates that the user closes a temporary system dialog box.
- Value: **usual.event.CLOSE_SYSTEM_DIALOGS**
- Required subscriber permissions: none

## [COMMON_EVENT_PACKAGE_ADDED](./common_event/commonEvent-bundleManager.md)
Indicates that a new application package has been installed on the device.
## COMMON_EVENT_PACKAGE_REPLACED
(Reserved, not supported yet) Indicates that a later version of an installed application package has replaced the previous one on the device.
- Value: **usual.event.PACKAGE_REPLACED**
- Required subscriber permissions: none

## COMMON_EVENT_MY_PACKAGE_REPLACED
(Reserved, not supported yet) Indicates that a later version of your application package has replaced the previous one.
- Value: **usual.event.MY_PACKAGE_REPLACED**
- Required subscriber permissions: none

## [COMMON_EVENT_PACKAGE_REMOVED](./common_event/commonEvent-bundleManager.md)
Indicates that an installed application has been uninstalled from the device with the application data retained.
## COMMON_EVENT_BUNDLE_REMOVED
(Reserved, not supported yet) Indicates that an installed bundle has been uninstalled from the device with the application data retained. 
- Value: **usual.event.BUNDLE_REMOVED**
- Required subscriber permissions: none

## COMMON_EVENT_PACKAGE_FULLY_REMOVED
(Reserved, not supported yet) Indicates that an installed application, including both the application data and code, has been completely uninstalled from the device.
- Value: **usual.event.PACKAGE_FULLY_REMOVED**
- Required subscriber permissions: none

## [COMMON_EVENT_PACKAGE_CHANGED](./common_event/commonEvent-bundleManager.md)
Indicates that an application package has been changed (for example, an ability in the package has been enabled or disabled).
## [COMMON_EVENT_PACKAGE_RESTARTED](./common_event/commonEvent-ability.md)
Indicates that the user closed all processes of the application and restarted the application.

## [COMMON_EVENT_PACKAGE_DATA_CLEARED](./common_event/commonEvent-ability.md)
Indicates that the user cleared the application package data.

## [COMMON_EVENT_PACKAGE_CACHE_CLEARED<sup>9+</sup>](./common_event/commonEvent-bundleManager.md)
Indicates that the user cleared the application package cache.
## COMMON_EVENT_PACKAGES_SUSPENDED
(Reserved, not supported yet) Indicates that application HAP files are suspended.
- Value: **usual.event.PACKAGES_SUSPENDED**
- Required subscriber permissions: none

## COMMON_EVENT_PACKAGES_UNSUSPENDED
(Reserved, not supported yet) Indicates that application HAP files are not suspended (restored from the suspended state).
- Value: **usual.event.PACKAGES_UNSUSPENDED**
- Required subscriber permissions: none

## COMMON_EVENT_MY_PACKAGE_SUSPENDED
Indicates that an application HAP file is suspended.
- Value: **usual.event.MY_PACKAGE_SUSPENDED**
- Required subscriber permissions: none

## COMMON_EVENT_MY_PACKAGE_UNSUSPENDED
Indicates that an application HAP file is not suspended.
- Value: **usual.event.MY_PACKAGE_UNSUSPENDED**
- Required subscriber permissions: none

## COMMON_EVENT_UID_REMOVED
(Reserved, not supported yet) Indicates that a user ID has been removed from the system.
- Value: **usual.event.UID_REMOVED**
- Required subscriber permissions: none

## COMMON_EVENT_PACKAGE_FIRST_LAUNCH
(Reserved, not supported yet) Indicates that an installed application is started for the first time.
- Value: **usual.event.PACKAGE_FIRST_LAUNCH**
- Required subscriber permissions: none

## COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION
(Reserved, not supported yet) Indicates that an application requires system verification.
- Value: **usual.event.PACKAGE_NEEDS_VERIFICATION**
- Required subscriber permissions: none

## COMMON_EVENT_PACKAGE_VERIFIED
(Reserved, not supported yet) Indicates that an application has been verified by the system.
- Value: **usual.event.PACKAGE_VERIFIED**
- Required subscriber permissions: none

## COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE
(Reserved, not supported yet) Indicates that applications installed on the external storage are available for the system.
- Value: **usual.event.EXTERNAL_APPLICATIONS_AVAILABLE**
- Required subscriber permissions: none

## COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE
(Reserved, not supported yet) Indicates that applications installed on the external storage are not available for the system.
- Value: **usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE**
- Required subscriber permissions: none

## COMMON_EVENT_CONFIGURATION_CHANGED
(Reserved, not supported yet) Indicates that the device state (for example, orientation and locale) has changed.
- Value: **usual.event.CONFIGURATION_CHANGED**
- Required subscriber permissions: none

## [COMMON_EVENT_LOCALE_CHANGED<sup>11+</sup>](./common_event/commonEvent-locale.md)
Indicates that the device locale has changed.
- Value: **usual.event.LOCALE_CHANGED**
- Required subscriber permissions: none

## COMMON_EVENT_MANAGE_PACKAGE_STORAGE
(Reserved, not supported yet) Indicates that the device storage is insufficient.
- Value: **usual.event.MANAGE_PACKAGE_STORAGE**
- Required subscriber permissions: none

## COMMON_EVENT_DRIVE_MODE
(Reserved, not supported yet) Indicates that the system is in driving mode.
- Value: **common.event.DRIVE_MODE**
- Required subscriber permissions: none

## COMMON_EVENT_HOME_MODE
(Reserved, not supported yet) Indicates that the system is in home mode.
- Value: **common.event.HOME_MODE**
- Required subscriber permissions: none

## COMMON_EVENT_OFFICE_MODE
(Reserved, not supported yet) Indicates that the system is in office mode.
- Value: **common.event.OFFICE_MODE**
- Required subscriber permissions: none

## COMMON_EVENT_USER_STARTED
(Reserved, not supported yet) Indicates that the user has been started.
- Value: **usual.event.USER_STARTED**
- Required subscriber permissions: none

## COMMON_EVENT_USER_BACKGROUND
(Reserved, not supported yet) Indicates that the user has been brought to the background.
- Value: **usual.event.USER_BACKGROUND**
- Required subscriber permissions: none

## COMMON_EVENT_USER_FOREGROUND
(Reserved, not supported yet) Indicates that the user has been brought to the foreground.
- Value: **usual.event.USER_FOREGROUND**
- Required subscriber permissions: none

## [COMMON_EVENT_USER_SWITCHED](./common_event/commonEvent-account.md)
Indicates that user switching is in progress.
## COMMON_EVENT_USER_STARTING
(Reserved, not supported yet) Indicates that the user is being started.
- Value: **usual.event.USER_STARTING**
- Required subscriber permissions: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

## [COMMON_EVENT_USER_UNLOCKED](./common_event/commonEvent-account.md)
Indicates that the credential-encrypted storage has been unlocked for the current user after the device is restarted.
- Value: **usual.event.USER_UNLOCKED**
- Required subscriber permissions: none

## COMMON_EVENT_USER_STOPPING
(Reserved, not supported yet) Indicates that the user is going to be stopped.
- Value: **usual.event.USER_STOPPING**
- Required subscriber permissions: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

## COMMON_EVENT_USER_STOPPED
(Reserved, not supported yet) Indicates that the user has been stopped.
- Value: **usual.event.USER_STOPPED**
- Required subscriber permissions: none

## [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN](./common_event/commonEvent-account.md)
(Reserved, not supported yet) Indicates a successful login to a distributed account.
## [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT](./common_event/commonEvent-account.md)
(Reserved, not supported yet) Indicates a successful logout of a distributed account.
## [COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID](./common_event/commonEvent-account.md)
(Reserved, not supported yet) Indicates the token of a distributed account is invalid.
## [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF](./common_event/commonEvent-account.md)
(Reserved, not supported yet) Indicates that a distributed account is deregistered.

## [COMMON_EVENT_WIFI_POWER_STATE](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi state has changed, for example, enabled or disabled.

## [COMMON_EVENT_WIFI_SCAN_FINISHED](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi access point has been detected and proven to be available.

## [COMMON_EVENT_WIFI_SCAN_STATE](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi access point state has changed.

## [COMMON_EVENT_WIFI_RSSI_VALUE](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi signal strength (RSSI) has changed.

## [COMMON_EVENT_WIFI_CONN_STATE](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi connection state has changed.

## [COMMON_EVENT_WIFI_HOTSPOT_STATE](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi hotspot state has changed, for example, enabled or disabled.

## [COMMON_EVENT_WIFI_AP_STA_JOIN](./common_event/commonEvent-wifi.md)
Indicates that a client has joined the Wi-Fi hotspot of the current device.

## [COMMON_EVENT_WIFI_AP_STA_LEAVE](./common_event/commonEvent-wifi.md)
Indicates that a client has disconnected from the Wi-Fi hotspot of the current device.

## [COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE](./common_event/commonEvent-wifi.md)
Indicates that the state of MPLINK (an enhanced Wi-Fi feature) has changed.

## [COMMON_EVENT_WIFI_P2P_CONN_STATE](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi P2P connection state has changed.

## [COMMON_EVENT_WIFI_P2P_STATE_CHANGED](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi P2P state has changed, for example, enabled or disabled.

## [COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED](./common_event/commonEvent-wifi.md)
Indicates that the state of the Wi-Fi P2P peer device has changed.

## [COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi P2P discovery state has changed.

## [COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED](./common_event/commonEvent-wifi.md)
Indicates that the state of the Wi-Fi P2P local device has changed.

## [COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED](./common_event/commonEvent-wifi.md)
Indicates that the Wi-Fi P2P group information has changed.

## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the connection state of Bluetooth handsfree communication.
- Value: **usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE
(Reserved, not supported yet) Indicates that the device connected through Bluetooth handsfree is active.
- Value: **usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates that the connection state of Bluetooth A2DP has changed.
- Value: **usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the connection state of Bluetooth A2DP.
- Value: **usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE
(Reserved, not supported yet) Indicates that the device connected using Bluetooth A2DP is active.
- Value: **usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE
(Reserved, not supported yet) Indicates that the playing state of Bluetooth A2DP has changed.
- Value: **usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates that the AVRCP connection state of Bluetooth A2DP has changed.
- Value: **usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE
(Reserved, not supported yet) Indicates that the audio codec state of Bluetooth A2DP has changed.
- Value: **usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED
(Reserved, not supported yet) Indicates that a remote Bluetooth device is discovered.
- Value: **usual.event.bluetooth.remotedevice.DISCOVERED**
- Required subscriber permissions: ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE
(Reserved, not supported yet) Indicates that the Bluetooth class of a remote Bluetooth device has changed.
- Value: **usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED
(Reserved, not supported yet) Indicates that a low-ACL connection with a remote Bluetooth device has been established.
- Value: **usual.event.bluetooth.remotedevice.ACL_CONNECTED**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED
(Reserved, not supported yet) Indicates that the low-ACL connection with a remote Bluetooth device has been terminated.
- Value: **usual.event.bluetooth.remotedevice.ACL_DISCONNECTED**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE
(Reserved, not supported yet) Indicates that the friendly name of a remote Bluetooth device is retrieved for the first time or has changed since the last retrieval.
- Value: **usual.event.bluetooth.remotedevice.NAME_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE
(Reserved, not supported yet) Indicates that the connection state with a remote Bluetooth device has changed.
- Value: **usual.event.bluetooth.remotedevice.PAIR_STATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE
(Reserved, not supported yet) Indicates that the battery level of a remote Bluetooth device is retrieved for the first time or has changed since the last retrieval.
- Value: **usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT
(Reserved, not supported yet) Indicates the SDP state of a remote Bluetooth device.
- Value: **usual.event.bluetooth.remotedevice.SDP_RESULT**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE
(Reserved, not supported yet) Indicates the UUID connection state with a remote Bluetooth device.
- Value: **usual.event.bluetooth.remotedevice.UUID_VALUE**
- Required subscriber permissions: ohos.permission.DISCOVER_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ
(Reserved, not supported yet) Indicates the pairing request from a remote Bluetooth device.
- Value: **usual.event.bluetooth.remotedevice.PAIRING_REQ**
- Required subscriber permissions: ohos.permission.DISCOVER_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL
(Reserved, not supported yet) Indicates that Bluetooth pairing has been canceled.
- Value: **usual.event.bluetooth.remotedevice.PAIRING_CANCEL**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ
(Reserved, not supported yet) Indicates the connection request from a remote Bluetooth device.
- Value: **usual.event.bluetooth.remotedevice.CONNECT_REQ**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY
(Reserved, not supported yet) Indicates the response to the connection request from a remote Bluetooth device.
- Value: **usual.event.bluetooth.remotedevice.CONNECT_REPLY**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL
(Reserved, not supported yet) Indicates that the connection to a remote Bluetooth device has been canceled.
- Value: **usual.event.bluetooth.remotedevice.CONNECT_CANCEL**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates that the connection state with a Bluetooth handsfree has changed.
- Value: **usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates that the audio state of a Bluetooth handsfree has changed.
- Value: **usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT
(Reserved, not supported yet) Indicates that the audio gateway state of a Bluetooth handsfree has changed.
- Value: **usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE
(Reserved, not supported yet) Indicates that the calling state of a Bluetooth handsfree has changed.
- Value: **usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE
(Reserved, not supported yet) Indicates that the state of a Bluetooth adapter has changed, for example, Bluetooth has been enabled or disabled.
- Value: **usual.event.bluetooth.host.STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE
(Reserved, not supported yet) Indicates the request for the user to allow Bluetooth device scanning.
- Value: **usual.event.bluetooth.host.REQ_DISCOVERABLE**
- Required subscriber permissions: none

## COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE
(Reserved, not supported yet) Indicates the request for the user to enable Bluetooth.
- Value: **usual.event.bluetooth.host.REQ_ENABLE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE
(Reserved, not supported yet) Indicates the request for the user to disable Bluetooth.
- Value: **usual.event.bluetooth.host.REQ_DISABLE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE
(Reserved, not supported yet) Indicates that the Bluetooth scanning mode of the device has changed.
- Value: **usual.event.bluetooth.host.SCAN_MODE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED
(Reserved, not supported yet) Indicates that Bluetooth scanning has been started on the device. 
- Value: **usual.event.bluetooth.host.DISCOVERY_STARTED**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED
(Reserved, not supported yet) Indicates that Bluetooth scanning is finished on the device.
- Value: **usual.event.bluetooth.host.DISCOVERY_FINISHED**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE
(Reserved, not supported yet) Indicates that the Bluetooth adapter name of the device has changed.
- Value: **usual.event.bluetooth.host.NAME_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates that the connection state of Bluetooth A2DP Sink has changed.
- Value: **usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE
(Reserved, not supported yet) Indicates that the playing state of Bluetooth A2DP Sink has changed.
- Value: **usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates that the audio state of Bluetooth A2DP Sink has changed.
- Value: **usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE**
- Required subscriber permissions: ohos.permission.USE_BLUETOOTH

## [COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED](./common_event/commonEvent-nfc.md)
Indicates that the state of the device NFC adapter has changed.

## [COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED](./common_event/commonEvent-nfc.md)
Indicates that the NFC RF field is on.

## [COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED](./common_event/commonEvent-nfc.md)
Indicates that the NFC RF field is off.

## [COMMON_EVENT_DISCHARGING](./common_event/commonEvent-powermgr.md)
Indicates that the system stops charging the battery.

## [COMMON_EVENT_CHARGING](./common_event/commonEvent-powermgr.md)
Indicates that the system starts charging the battery.

## [COMMON_EVENT_CHARGE_TYPE_CHANGED](./common_event/commonEvent-powermgr.md)
Indicates that the system charging type has changed. This event is available only for system applications.

## [COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED](./common_event/commonEvent-powermgr.md)
Indicates that the device enters the charging idle mode.

## [COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED](./common_event/commonEvent-resourceschedule.md)
Indicates that the system idle mode has changed.
## [COMMON_EVENT_DEVICE_IDLE_EXEMPTION_LIST_UPDATED<sup>10+<sup>](./common_event/commonEvent-resourceschedule.md)
Indicates that the exemption list for resource usage restrictions has been updated in idle mode. This event is for system applications only.

## [COMMON_EVENT_POWER_SAVE_MODE_CHANGED](./common_event/commonEvent-powermgr.md)
Indicates that the system power saving mode has changed.

## [COMMON_EVENT_USER_ADDED](./common_event/commonEvent-account.md)
Indicates that a user has been added to the system.
## [COMMON_EVENT_USER_REMOVED](./common_event/commonEvent-account.md)
Indicates that a user has been removed from the system.
## COMMON_EVENT_ABILITY_ADDED
(Reserved, not supported yet) Indicates that an ability has been added.
- Value: **usual.event.ABILITY_ADDED**
- Required subscriber permissions: ohos.permission.LISTEN_BUNDLE_CHANGE

## COMMON_EVENT_ABILITY_REMOVED
(Reserved, not supported yet) Indicates that an ability has been removed.
- Value: **usual.event.ABILITY_REMOVED**
- Required subscriber permissions: ohos.permission.LISTEN_BUNDLE_CHANGE

## COMMON_EVENT_ABILITY_UPDATED
(Reserved, not supported yet) Indicates that an ability has been updated.
- Value: **usual.event.ABILITY_UPDATED**
- Required subscriber permissions: ohos.permission.LISTEN_BUNDLE_CHANGE

## COMMON_EVENT_LOCATION_MODE_STATE_CHANGED
(Reserved, not supported yet) Indicates that the location mode of the system has changed.
- Value: **usual.event.location.MODE_STATE_CHANGED**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_SLEEP
(Reserved, not supported yet) Indicates that the in-vehicle infotainment (IVI) system is in sleep mode.
- Value: **common.event.IVI_SLEEP**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_PAUSE
(Reserved, not supported yet) Indicates that the IVI system as entered sleep mode and instructs the playing application to stop playback.
- Value: **common.event.IVI_PAUSE**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_STANDBY
(Reserved, not supported yet) Requests a third-party application in the IVI system to pause the current work.
- Value: **common.event.IVI_STANDBY**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_LASTMODE_SAVE
(Reserved, not supported yet) Requests a third-party application in the IVI system to save its last mode.
- Value: **common.event.IVI_LASTMODE_SAVE**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_VOLTAGE_ABNORMAL
(Reserved, not supported yet) Indicates that the voltage of the vehicle's power system is abnormal.
- Value: **common.event.IVI_VOLTAGE_ABNORMAL**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_HIGH_TEMPERATURE
(Reserved, not supported yet) Indicates that the temperature of the IVI system is high.
- Value: **common.event.IVI_HIGH_TEMPERATURE**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_EXTREME_TEMPERATURE
(Reserved, not supported yet) Indicates that the temperature of the IVI system is extremely high. 
- Value: **common.event.IVI_EXTREME_TEMPERATURE**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL
(Reserved, not supported yet) Indicates that the IVI system is at an extreme temperature.
- Value: **common.event.IVI_TEMPERATURE_ABNORMAL**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_VOLTAGE_RECOVERY
(Reserved, not supported yet) Indicates that the voltage of the vehicle's power system is restored to normal.
- Value: **common.event.IVI_VOLTAGE_RECOVERY**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_TEMPERATURE_RECOVERY
(Reserved, not supported yet) Indicates that the temperature of the IVI system is restored to normal.
- Value: **common.event.IVI_TEMPERATURE_RECOVERY**
- Required subscriber permissions: none

## COMMON_EVENT_IVI_ACTIVE
(Reserved, not supported yet) Indicates that the battery service of the IVI system is active.
- Value: **common.event.IVI_ACTIVE**
- Required subscriber permissions: none

## [COMMON_EVENT_USB_STATE<sup>9+</sup>](common_event/commonEvent-usb.md)
Indicates that the USB device state has changed.

## [**COMMON_EVENT_USB_PORT_CHANGED**<sup>9+</sup>](./common_event/commonEvent-usb.md)
Indicates that the USB port state of the device has changed.

## [COMMON_EVENT_USB_DEVICE_ATTACHED](./common_event/commonEvent-usb.md)
Indicates that a USB device has been attached to the device functioning as a USB host.

## [COMMON_EVENT_USB_DEVICE_DETACHED](./common_event/commonEvent-usb.md)
Indicates that a USB device has been detached from the device functioning as a USB host.

## [COMMON_EVENT_USB_ACCESSORY_ATTACHED](./common_event/commonEvent-usb.md)
(Reserved, not supported yet) Indicates that a USB accessory was attached.

## [COMMON_EVENT_USB_ACCESSORY_DETACHED](./common_event/commonEvent-usb.md)
(Reserved, not supported yet) Indicates that a USB accessory was detached.

## COMMON_EVENT_DISK_REMOVED
(Reserved, not supported yet) Indicates that an external storage device was removed.
- Value: **usual.event.data.DISK_BAD_REMOVAL**
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_UNMOUNTED
(Reserved, not supported yet) Indicates that an external storage device was unmounted.
- Value: **usual.event.data.DISK_UNMOUNTABLE**
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_MOUNTED
(Reserved, not supported yet) Indicates that an external storage device was mounted.
- Value: **usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED**
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_BAD_REMOVAL
(Reserved, not supported yet) Indicates that an external storage device was removed without being unmounted.
- Value: usual.event.data.DISK_REMOVED
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_UNMOUNTABLE
(Reserved, not supported yet) Indicates that an external storage device is unmountable when the card is inserted.
- Value: **usual.event.data.DISK_UNMOUNTED**
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_EJECT
(Reserved, not supported yet) Indicates that an external storage device was ejected (at the software level).
- Value: **usual.event.data.DISK_EJECT**
- Required subscriber permissions: ohos.permission.STORAGE_MANAGER

## [COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>](./common_event/commonEvent-filemanagement.md)
Indicates that an external storage device was removed.

## [COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>](./common_event/commonEvent-filemanagement.md)
Indicates that an external storage device was unmounted.

## [COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>](./common_event/commonEvent-filemanagement.md)
Indicates that an external storage device was mounted.

## [COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>](./common_event/commonEvent-filemanagement.md)
Indicates that an external storage device was removed without being unmounted.

## [COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>](./common_event/commonEvent-filemanagement.md)
Indicates that an external storage device was ejected (at the software level).

## COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED
(Reserved, not supported yet) Indicates that the account visibility changed.
- Value: **usual.event.data.VISIBLE_ACCOUNTS_UPDATED**
- Required subscriber permissions: ohos.permission.GET_APP_ACCOUNTS

## COMMON_EVENT_ACCOUNT_DELETED
(Reserved, not supported yet) Indicates that an account was deleted.
- Value: **usual.event.data.ACCOUNT_DELETED**
- Required subscriber permissions: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

## COMMON_EVENT_FOUNDATION_READY
(Reserved, not supported yet) Indicates that the foundation is ready.
- Value: **usual.event.data.FOUNDATION_READY**
- Required subscriber permissions: ohos.permission.RECEIVER_STARTUP_COMPLETED

## COMMON_EVENT_AIRPLANE_MODE_CHANGED
Indicates that the airplane mode of the device has changed.
- Value: **usual.event.AIRPLANE_MODE**
- Required subscriber permissions: none

## COMMON_EVENT_SPLIT_SCREEN
Indicates that the screen has been split.
- Value: **usual.event.SPLIT_SCREEN**
- Required subscriber permissions: ohos.permission.RECEIVER_SPLIT_SCREEN

## [COMMON_EVENT_SLOT_CHANGE<sup>9+<sup>](./common_event/commonEvent-ans.md)
Indicates that the notification slot has been updated.
## COMMON_EVENT_SPN_INFO_CHANGED<sup>9+</sup>
Indicates that the SPN displayed has been updated.
- Value: **usual.event.SPN_INFO_CHANGED**
- Required subscriber permissions: none

## [COMMON_EVENT_QUICK_FIX_APPLY_RESULT<sup>9+<sup>](./common_event/commonEvent-ability.md)
Indicates the result of applying a quick fix to the application.
## COMMON_EVENT_HTTP_PROXY_CHANGE<sup>10+</sup>
Indicates that the HTTP proxy configuration has changed.
- Value: **usual.event.HTTP_PROXY_CHANGE**
- Required subscriber permissions: none

## [COMMON_EVENT_DOMAIN_ACCOUNT_STATUS_CHANGED<sup>10+<sup>](./common_event/commonEvent-account.md)
Indicates that the domain account status has changed.
## [COMMON_EVENT_SIM_STATE_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the SIM card state has changed.
## [COMMON_EVENT_SMS_RECEIVED_COMPLETED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the SMS message is received.
## [COMMON_EVENT_SMS_EMERGENCY_CB_RECEIVE_COMPLETED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that an emergency cell broadcast message is received.
## [COMMON_EVENT_SMS_CB_RECEIVE_COMPLETED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that a cell broadcast message is received.
## [COMMON_EVENT_STK_COMMAND<sup>10+<sup>](./common_event/commonEvent-telephony.md)
(Reserved, not supported yet) Indicates the STK command.
## [COMMON_EVENT_STK_SESSION_END<sup>10+<sup>](./common_event/commonEvent-telephony.md)
(Reserved, not supported yet) Indicates that an STK session ends.
## [COMMON_EVENT_STK_CARD_STATE_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
(Reserved, not supported yet) Indicates that the STK card state has changed.
## [COMMON_EVENT_STK_ALPHA_IDENTIFIER<sup>10+<sup>](./common_event/commonEvent-telephony.md)
(Reserved, not supported yet) Indicates the STK alpha indicator.
## [COMMON_EVENT_SMS_WAPPUSH_RECEIVE_COMPLETED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that a WAP push message is received.
## [COMMON_EVENT_OPERATOR_CONFIG_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the carrier configuration has been updated.
## [COMMON_EVENT_SIM_CARD_DEFAULT_SMS_SUBSCRIPTION_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the default SIM card for the SMS service has changed.
## [COMMON_EVENT_SIM_CARD_DEFAULT_DATA_SUBSCRIPTION_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the default SIM card for the mobile data service has changed.
## [COMMON_EVENT_SIM_CARD_DEFAULT_MAIN_SUBSCRIPTION_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the default primary SIM card has changed.
## [COMMON_EVENT_SIM_CARD_DEFAULT_VOICE_SUBSCRIPTION_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the default SIM card for the voice service has changed.
## [COMMON_EVENT_CALL_STATE_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the call state has changed.
## [COMMON_EVENT_CELLULAR_DATA_STATE_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the cellular data state has changed.
## [COMMON_EVENT_NETWORK_STATE_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the network state has changed.
## [COMMON_EVENT_SIGNAL_INFO_CHANGED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the signal information is updated.
## [COMMON_EVENT_INCOMING_CALL_MISSED<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates a missed call.
## [COMMON_EVENT_RADIO_STATE_CHANGE<sup>10+<sup>](./common_event/commonEvent-telephony.md)
Indicates that the power-on and power-off status of the modem has changed.
## [COMMON_EVENT_SCREEN_LOCKED <sup>10+<sup>](./common_event/commonEvent-screenlock.md)

Indicates that the screen is locked.

## [COMMON_EVENT_SCREEN_UNLOCKED<sup>10+<sup>](./common_event/commonEvent-screenlock.md)

Indicates that the screen is unlocked.

## [COMMON_EVENT_QUICK_FIX_REVOKE_RESULT<sup>10+<sup>](./common_event/commonEvent-ability.md#common_event_quick_fix_revoke_result10)

ָIndicates the result of revoking a quick fix to the application.

## [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN](./common_event/commonEvent-account.md)
(Reserved, not supported yet) Indicates a successful login to a distributed account.

## [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT](./common_event/commonEvent-account.md)
(Reserved, not supported yet) Indicates a successful logout of a distributed account.

## [COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID](./common_event/commonEvent-account.md)
(Reserved, not supported yet) Indicates the token of a distributed account is invalid.

## [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF](./common_event/commonEvent-account.md)
(Reserved, not supported yet) Indicates that a distributed account is deregistered.

## [COMMON_EVENT_USER_INFO_UPDATED<sup>9+<sup>](./common_event/commonEvent-account.md)

Indicates that the user information has been updated.

## [COMMON_EVENT_AUDIO_QUALITY_CHANGE](./common_event/commonEvent-telephony.md)

Indicates that the audio quality has changed.

## [COMMON_EVENT_NET_QUOTA_WARNING<sup>10+<sup>](./common_event/commonEvent-netmanager.md)
Indicates that the network data usage has reached the alarm threshold.

## [COMMON_EVENT_NET_QUOTA_LIMIT_REMINDED<sup>10+<sup>](./common_event/commonEvent-netmanager.md)
Indicates that the network data usage has reached the upper limit, and network access is still available.

## [OMMON_EVENT_NET_QUOTA_LIMIT<sup>10+<sup>](./common_event/commonEvent-netmanager.md)
Indicates that the network data usage has reached the upper limit, and network access becomes unavailable.

## [COMMON_EVENT_HTTP_PROXY_CHANGE<sup>10+<sup>](./common_event/commonEvent-netmanager.md)
Indicates that the HTTP proxy configuration has changed.

## [COMMON_EVENT_AIRPLANE_MODE_CHANGED<sup>10+<sup>](./common_event/commonEvent-netmanager.md)
Indicates that the airplane mode state has changed.

## [COMMON_EVENT_CONNECTIVITY_CHANGE<sup>10+<sup>](./common_event/commonEvent-netmanager.md)
Indicates that the network connection state has changed.