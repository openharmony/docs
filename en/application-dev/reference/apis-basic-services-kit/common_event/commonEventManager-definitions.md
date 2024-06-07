# System Common Events

This document provides indexes for predefined system common events.
Common event types are defined in [Support enumeration of the ohos.commonEventManager module](../js-apis-commonEventManager.md#support).

**System capability**: SystemCapability.Notification.CommonEvent

* [COMMON_EVENT_BOOT_COMPLETED](../common_event/commonEvent-ability.md#common_event_boot_completed)
Indicates the common event that the user has finished booting and the system has been loaded.

* COMMON_EVENT_LOCKED_BOOT_COMPLETED
(Reserved, not supported yet) Indicates the common event that the user has finished booting and the system has been loaded but the screen is still locked.
  - Value: **usual.event.LOCKED_BOOT_COMPLETED**
  - Permission required by subscribers: ohos.permission.RECEIVER_STARTUP_COMPLETED (Only system applications can apply for this permission.)

* [COMMON_EVENT_SHUTDOWN](../common_event/commonEvent-powermgr.md#common_event_shutdown)
Indicates the common event that the device is being shut down.

* [COMMON_EVENT_BATTERY_CHANGED](../common_event/commonEvent-powermgr.md#common_event_battery_changed)
Indicates that the charging state, level, and other information about the battery have changed.

* [COMMON_EVENT_BATTERY_LOW](../common_event/commonEvent-powermgr.md#common_event_battery_low)
Indicates that the battery level is low.

* [COMMON_EVENT_BATTERY_OKAY](../common_event/commonEvent-powermgr.md#common_event_battery_okay)
Indicates the common event that the battery exits the low state.

* [COMMON_EVENT_POWER_CONNECTED](../common_event/commonEvent-powermgr.md#common_event_power_connected)
Indicates that the device is connected to an external power supply.

* [COMMON_EVENT_POWER_DISCONNECTED](../common_event/commonEvent-powermgr.md#common_event_power_disconnected)
Indicates that the device is disconnected from the external power supply.

* [COMMON_EVENT_SCREEN_OFF](../common_event/commonEvent-powermgr.md#common_event_screen_off)
Indicates that the device screen is off and the device is in sleep mode.

* [COMMON_EVENT_SCREEN_ON](../common_event/commonEvent-powermgr.md#common_event_screen_on)
Indicates that the device screen is on and the device is in the active state.

* [COMMON_EVENT_THERMAL_LEVEL_CHANGED](../common_event/commonEvent-powermgr.md#common_event_thermal_level_changed)
Indicates that the device's thermal level has changed.

* COMMON_EVENT_USER_PRESENT<sup>(deprecated)</sup>
(Reserved, not supported yet) Indicates the common event that the user unlocks the device.
  - Value: **usual.event.USER_PRESENT**
  - Required subscriber permissions: none
  > Notes:
  >
  > This API is deprecated since API version 10.
  > You are advised to use [COMMON_EVENT_SCREEN_UNLOCKED<sup>10+</sup> ](../common_event/commonEvent-screenlock.md#common_event_screen_unlocked) as a substitute.

* [COMMON_EVENT_TIME_TICK](../common_event/commonEvent-time.md#common_event_time_tick)
Indicates that the system time has changed.

* [COMMON_EVENT_TIME_CHANGED](../common_event/commonEvent-time.md#common_event_time_changed)
Indicates the common event that the system time is set.

* COMMON_EVENT_DATE_CHANGED
(Reserved, not supported yet) Indicates the common event that the system time has changed.
  - Value: **usual.event.DATE_CHANGED**
  - Required subscriber permissions: none

* [COMMON_EVENT_TIMEZONE_CHANGED](../common_event/commonEvent-time.md#common_event_timezone_changed)
Indicates the common event that the system time zone has changed.

* COMMON_EVENT_CLOSE_SYSTEM_DIALOGS
(Reserved, not supported yet) Indicates the common event that a user closes a temporary system dialog box.
  - Value: **usual.event.CLOSE_SYSTEM_DIALOGS**
  - Required subscriber permissions: none

* [COMMON_EVENT_PACKAGE_ADDED](../common_event/commonEvent-bundleManager.md#common_event_package_added)
Indicates the common event that a new application package has been installed on the device.
* COMMON_EVENT_PACKAGE_REPLACED
(Reserved, not supported yet) Indicates the common event that a new version of an installed application package has replaced the previous one on the device.
  - Value: **usual.event.PACKAGE_REPLACED**
  - Required subscriber permissions: none

* COMMON_EVENT_MY_PACKAGE_REPLACED
(Reserved, not supported yet) Indicates the common event that a later version of your application package has replaced the previous one.
  - Value: **usual.event.MY_PACKAGE_REPLACED**
  - Required subscriber permissions: none

* [COMMON_EVENT_PACKAGE_REMOVED](../common_event/commonEvent-bundleManager.md#common_event_package_removed)
Indicates the common event that an installed application has been uninstalled from the device with the application data retained.
* COMMON_EVENT_BUNDLE_REMOVED
(Reserved, not supported yet) Indicates the common event that an installed bundle has been uninstalled from the device with the application data retained.
  - Value: **usual.event.BUNDLE_REMOVED**
  - Required subscriber permissions: none

* COMMON_EVENT_PACKAGE_FULLY_REMOVED
(Reserved, not supported yet) Indicates the common event that an installed application, including both the application data and code, has been completely uninstalled from the device.
  - Value: **usual.event.PACKAGE_FULLY_REMOVED**
  - Required subscriber permissions: none

* [COMMON_EVENT_PACKAGE_CHANGED](../common_event/commonEvent-bundleManager.md#common_event_package_changed)
Indicates that an application package has been changed (for example, an ability in the package has been enabled or disabled).
* [COMMON_EVENT_PACKAGE_RESTARTED](../common_event/commonEvent-ability.md#common_event_package_restarted)
Indicates that the user has restarted the application package and killed all its processes.

* [COMMON_EVENT_PACKAGE_DATA_CLEARED](../common_event/commonEvent-ability.md#common_event_package_data_cleared)
Indicates the common event that the user has cleared the application package data.

* [COMMON_EVENT_PACKAGE_CACHE_CLEARED<sup>9+</sup>](../common_event/commonEvent-bundleManager.md#common_event_package_cache_cleared)
Indicates that the user cleared the application package cache.
* COMMON_EVENT_PACKAGES_SUSPENDED
(Reserved, not supported yet) Indicates the common event that application packages have been suspended.
  - Value: **usual.event.PACKAGES_SUSPENDED**
  - Required subscriber permissions: none

* COMMON_EVENT_PACKAGES_UNSUSPENDED
(Reserved, not supported yet) Indicates the common event that application package has not been suspended.
  - Value: **usual.event.PACKAGES_UNSUSPENDED**
  - Required subscriber permissions: none

* COMMON_EVENT_MY_PACKAGE_SUSPENDED
Indicates the common event that an application package has been suspended.
  - Value: **usual.event.MY_PACKAGE_SUSPENDED**
  - Required subscriber permissions: none

* COMMON_EVENT_MY_PACKAGE_UNSUSPENDED
Indicates the common event that application packages have not been suspended.
  - Value: **usual.event.MY_PACKAGE_UNSUSPENDED**
  - Required subscriber permissions: none

* COMMON_EVENT_UID_REMOVED
(Reserved, not supported yet) Indicates the common event that a user ID has been removed from the system.
  - Value: **usual.event.UID_REMOVED**
  - Required subscriber permissions: none

* COMMON_EVENT_PACKAGE_FIRST_LAUNCH
(Reserved, not supported yet) Indicates the common event that an installed application is started for the first time.
  - Value: **usual.event.PACKAGE_FIRST_LAUNCH**
  - Required subscriber permissions: none

* COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION
(Reserved, not supported yet) Indicates the common event that an application requires system verification.
  - Value: **usual.event.PACKAGE_NEEDS_VERIFICATION**
  - Required subscriber permissions: none

* COMMON_EVENT_PACKAGE_VERIFIED
(Reserved, not supported yet) Indicates the common event that an application has been verified by the system.
  - Value: **usual.event.PACKAGE_VERIFIED**
  - Required subscriber permissions: none

* COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE
(Reserved, not supported yet) Indicates the common event that applications installed on the external storage become available for the system.
  - Value: **usual.event.EXTERNAL_APPLICATIONS_AVAILABLE**
  - Required subscriber permissions: none

* COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE
(Reserved, not supported yet) Indicates the common event that applications installed on the external storage become unavailable for the system.
  - Value: **usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE**
  - Required subscriber permissions: none

* COMMON_EVENT_CONFIGURATION_CHANGED
(Reserved, not supported yet) Indicates the common event that the device state (for example, orientation and locale) has changed.
  - Value: **usual.event.CONFIGURATION_CHANGED**
  - Required subscriber permissions: none

* [COMMON_EVENT_LOCALE_CHANGED<sup>11+</sup>](../common_event/commonEvent-locale.md#common_event_locale_changed11)
Indicates the common event that the device locale has changed.
  - Value: **usual.event.LOCALE_CHANGED**
  - Required subscriber permissions: none

* COMMON_EVENT_MANAGE_PACKAGE_STORAGE
(Reserved, not supported yet) Indicates the common event that the device storage space is insufficient.
  - Value: **usual.event.MANAGE_PACKAGE_STORAGE**
  - Required subscriber permissions: none

* COMMON_EVENT_DRIVE_MODE
(Reserved, not supported yet) Indicates the common event that the system is in driving mode.
  - Value: **common.event.DRIVE_MODE**
  - Required subscriber permissions: none

* COMMON_EVENT_HOME_MODE
(Reserved, not supported yet) Indicates the common event that the system is in home mode.
  - Value: **common.event.HOME_MODE**
  - Required subscriber permissions: none

* COMMON_EVENT_OFFICE_MODE
(Reserved, not supported yet) Indicates the common event that the system is in office mode.
  - Value: **common.event.OFFICE_MODE**
  - Required subscriber permissions: none

* COMMON_EVENT_USER_STARTED
(Reserved, not supported yet) Indicates the common event that the user has been started.
  - Value: **usual.event.USER_STARTED**
  - Required subscriber permissions: none

* COMMON_EVENT_USER_BACKGROUND
(Reserved, not supported yet) Indicates the common event that the user has been brought to the background.
  - Value: **usual.event.USER_BACKGROUND**
  - Required subscriber permissions: none

* COMMON_EVENT_USER_FOREGROUND
(Reserved, not supported yet) Indicates the common event that the user has been brought to the foreground.
  - Value: **usual.event.USER_FOREGROUND**
  - Required subscriber permissions: none

* [COMMON_EVENT_USER_SWITCHED](../common_event/commonEvent-account.md#common_event_user_switched)
Indicates the common event that a user switch is happening.
* COMMON_EVENT_USER_STARTING
(Reserved, not supported yet) Indicates the common event that the user is going to be started.
  - Value: **usual.event.USER_STARTING**
  - Permission required by subscribers: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS. Only system applications can apply for this permission.

* [COMMON_EVENT_USER_UNLOCKED](../common_event/commonEvent-account.md#common_event_user_unlocked)
Indicates the common event that the credential-encrypted storage has become unlocked for the current user when the device is unlocked after being restarted.
  - Value: **usual.event.USER_UNLOCKED**
  - Required subscriber permissions: none

* COMMON_EVENT_USER_STOPPING
(Reserved, not supported yet) Indicates the common event that the user is going to be stopped.
  - Value: **usual.event.USER_STOPPING**
  - Permission required by subscribers: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS. Only system applications can apply for this permission.

* COMMON_EVENT_USER_STOPPED
(Reserved, not supported yet) Indicates the common event that the user has been stopped.
  - Value: **usual.event.USER_STOPPED**
  - Required subscriber permissions: none

* [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN](../common_event/commonEvent-account.md#common_event_distributed_account_login)
(Reserved, not supported yet) Indicates a successful login to a distributed account.

* [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT](../common_event/commonEvent-account.md#common_event_distributed_account_logout)
(Reserved, not supported yet) Indicates a successful logout of a distributed account.

* [COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID](../common_event/commonEvent-account.md#common_event_distributed_account_token_invalid)
(Reserved, not supported yet) Indicates the token of a distributed account is invalid.

* [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF](../common_event/commonEvent-account.md#common_event_distributed_account_logoff)
(Reserved, not supported yet) Indicates that a distributed account is deregistered.

* [COMMON_EVENT_WIFI_POWER_STATE](../common_event/commonEvent-wifi.md#common_event_wifi_power_state)
Indicates that the Wi-Fi state has changed, for example, enabled or disabled.

* [COMMON_EVENT_WIFI_SCAN_FINISHED](../common_event/commonEvent-wifi.md#common_event_wifi_scan_finished)
Indicates that the Wi-Fi access point has been detected and proven to be available.

* [COMMON_EVENT_WIFI_SCAN_STATE](../common_event/commonEvent-wifi.md#common_event_wifi_scan_state)
Indicates that the Wi-Fi access point state has changed.

* [COMMON_EVENT_WIFI_RSSI_VALUE](../common_event/commonEvent-wifi.md#common_event_wifi_rssi_value)
Indicates that the Wi-Fi signal strength (RSSI) has changed.

* [COMMON_EVENT_WIFI_CONN_STATE](../common_event/commonEvent-wifi.md#common_event_wifi_conn_state)
Indicates the common event that the WLAN connection state has changed.

* [COMMON_EVENT_WIFI_HOTSPOT_STATE](../common_event/commonEvent-wifi.md#common_event_wifi_hotspot_state)
Indicates that the Wi-Fi hotspot state has changed, for example, enabled or disabled.

* [COMMON_EVENT_WIFI_AP_STA_JOIN](../common_event/commonEvent-wifi.md#common_event_wifi_ap_sta_join)
Indicates that a client has joined the Wi-Fi hotspot of the current device.

* [COMMON_EVENT_WIFI_AP_STA_LEAVE](../common_event/commonEvent-wifi.md#common_event_wifi_ap_sta_leave)
Indicates that a client has disconnected from the Wi-Fi hotspot of the current device.

* [COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE](../common_event/commonEvent-wifi.md#common_event_wifi_mplink_state_change)
Indicates that the state of MPLINK (an enhanced Wi-Fi feature) has changed.

* [COMMON_EVENT_WIFI_P2P_CONN_STATE](../common_event/commonEvent-wifi.md#common_event_wifi_p2p_conn_state)
Indicates that the Wi-Fi P2P connection state has changed.

* [COMMON_EVENT_WIFI_P2P_STATE_CHANGED](../common_event/commonEvent-wifi.md#common_event_wifi_p2p_state_changed)
Indicates that the Wi-Fi P2P state has changed, for example, enabled or disabled.

* [COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED](../common_event/commonEvent-wifi.md#common_event_wifi_p2p_peers_state_changed)
Indicates that the state of the Wi-Fi P2P peer device has changed.

* [COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED](../common_event/commonEvent-wifi.md#common_event_wifi_p2p_peers_discovery_state_changed)
Indicates that the Wi-Fi P2P discovery state has changed.

* [COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED](../common_event/commonEvent-wifi.md#common_event_wifi_p2p_current_device_state_changed)
Indicates that the state of the Wi-Fi P2P local device has changed.

* [COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED](../common_event/commonEvent-wifi.md#common_event_wifi_p2p_group_state_changed)
Indicates the common event that the Wi-Fi P2P group information has changed.

* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event about the connection state of Bluetooth handsfree communication.
  - Value: **usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE
(Reserved, not supported yet) Indicates the common event that the device connected to the Bluetooth handsfree is active.
  - Value: **usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the connection state of Bluetooth A2DP has changed.
  - Value: **usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event about the connection state of Bluetooth A2DP.
  - Value: **usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE
(Reserved, not supported yet) Indicates the common event that the device connected using Bluetooth A2DP is active.
  - Value: **usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the playing state of Bluetooth A2DP has changed.
  - Value: **usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the AVRCP connection state of Bluetooth A2DP has changed.
  - Value: **usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE
(Reserved, not supported yet) Indicates the common event that the audio codec state of Bluetooth A2DP has changed.
  - Value: **usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED
(Reserved, not supported yet) Indicates the common event that a remote Bluetooth device is discovered.
  - Value: **usual.event.bluetooth.remotedevice.DISCOVERED**
  - Required subscriber permissions: ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE
(Reserved, not supported yet) Indicates the common event that the Bluetooth class of a remote Bluetooth device has changed.
  - Value: **usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED
(Reserved, not supported yet) Indicates the common event that a low-ACL connection has been established with a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.ACL_CONNECTED**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED
(Reserved, not supported yet) Indicates the common event that a low-ACL connection has been disconnected from a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.ACL_DISCONNECTED**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE
Indicates the common event that the friendly name of a remote Bluetooth device has been retrieved for the first time or has been changed since the last retrieval.
  - Value: **usual.event.bluetooth.remotedevice.NAME_UPDATE**
  - Required subscriber permissions: ohos.permission.ACCESS_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE
(Reserved, not supported yet) Indicates the common event that the connection state of a remote Bluetooth device has changed.
  - Value: **usual.event.bluetooth.remotedevice.PAIR_STATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE
(Reserved, not supported yet) Indicates the common event that the battery level of a remote Bluetooth device is retrieved for the first time or has changed since the last retrieval.
  - Value: **usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT
(Reserved, not supported yet) Indicates the common event about the SDP state of a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.SDP_RESULT**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE
Indicates the action of a common event about the UUID connection state of a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.UUID_VALUE**
  - Required subscriber permissions: ohos.permission.ACCESS_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ
(Reserved, not supported yet) Indicates the common event about the pairing request from a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.PAIRING_REQ**
  - Required subscriber permissions: ohos.permission.DISCOVER_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL
(Reserved, not supported yet) Indicates the common event that Bluetooth pairing is canceled.
  - Value: **usual.event.bluetooth.remotedevice.PAIRING_CANCEL**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ
(Reserved, not supported yet) Indicates the common event about the connection request from a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.CONNECT_REQ**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY
(Reserved, not supported yet) Indicates the common event about the response to the connection request from a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.CONNECT_REPLY**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL
(Reserved, not supported yet) Indicates the common event that the connection to a remote Bluetooth device has been canceled.
  - Value: **usual.event.bluetooth.remotedevice.CONNECT_CANCEL**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the connection state of a Bluetooth handsfree has changed.
  - Value: **usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the audio state of a Bluetooth handsfree has changed.
  - Value: **usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT
(Reserved, not supported yet) Indicates the common event that the audio gateway state of a Bluetooth handsfree has changed.
  - Value: **usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the calling state of a Bluetooth handsfree has changed.
  - Value: **usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE
Indicates the common event that the state of a Bluetooth adapter has been changed, for example, Bluetooth has been enabled or disabled.
  - Value: **usual.event.bluetooth.host.STATE_UPDATE**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE
(Reserved, not supported yet) Indicates the common event about the request for the user to allow Bluetooth device scanning.
  - Value: **usual.event.bluetooth.host.REQ_DISCOVERABLE**
  - Required subscriber permissions: none

* COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE
(Reserved, not supported yet) Indicates the common event about the request for the user to enable Bluetooth.
  - Value: **usual.event.bluetooth.host.REQ_ENABLE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE
(Reserved, not supported yet) Indicates the common event about the request for the user to disable Bluetooth.
  - Value: **usual.event.bluetooth.host.REQ_DISABLE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE
(Reserved, not supported yet) Indicates the common event that the Bluetooth scanning mode of a device has changed.
  - Value: **usual.event.bluetooth.host.SCAN_MODE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED
Indicates the common event that the Bluetooth scanning has been started on the device.
  - Value: **usual.event.bluetooth.host.DISCOVERY_STARTED**
  - Required subscriber permissions: ohos.permission.ACCESS_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED
Indicates the common event that the Bluetooth scanning is finished on the device.
  - Value: **usual.event.bluetooth.host.DISCOVERY_FINISHED**
  - Required subscriber permissions: ohos.permission.ACCESS_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE
Indicates the common event that the Bluetooth adapter name of the device has changed.
  - Value: **usual.event.bluetooth.host.NAME_UPDATE**
  - Required subscriber permissions: ohos.permission.ACCESS_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the connection state of Bluetooth A2DP Sink has changed.
  - Value: **usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the playing state of Bluetooth A2DP Sink has changed.
  - Value: **usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the audio state of Bluetooth A2DP Sink has changed.
  - Value: **usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE**
  - Required subscriber permissions: ohos.permission.USE_BLUETOOTH

* [COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED](../common_event/commonEvent-nfc.md#common_event_nfc_action_adapter_state_changed)
Indicates that the state of the device NFC adapter has changed.

* [COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED](../common_event/commonEvent-nfc.md#common_event_nfc_action_rf_field_on_detected)
Indicates that the NFC RF field is on.

* [COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED](../common_event/commonEvent-nfc.md#common_event_nfc_action_rf_field_off_detected)
Indicates that the NFC RF field is off.

* [COMMON_EVENT_DISCHARGING](../common_event/commonEvent-powermgr.md#common_event_discharging)
Indicates that the system stops charging the battery.

* [COMMON_EVENT_CHARGING](../common_event/commonEvent-powermgr.md#common_event_charging)
Indicates the common event that the system starts charging the battery.

* [COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED](../common_event/commonEvent-powermgr.md#common_event_charge_idle_mode_changed)
Indicates the common event that the device enters the charging idle mode.

* [COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED](../common_event/commonEvent-resourceschedule.md#common_event_device_idle_mode_changed)
Indicates the common event that the system standby mode has changed.

* [COMMON_EVENT_POWER_SAVE_MODE_CHANGED](../common_event/commonEvent-powermgr.md#common_event_power_save_mode_changed)
Indicates that the system power saving mode has changed.

* [COMMON_EVENT_USER_ADDED](../common_event/commonEvent-account.md#common_event_user_added)
Indicates that a user has been added to the system.

* [COMMON_EVENT_USER_REMOVED](../common_event/commonEvent-account.md#common_event_user_removed)
Indicates the common event that a user has been removed from the system.

* COMMON_EVENT_ABILITY_ADDED
(Reserved, not supported yet) Indicates the common event that an ability has been added.
  - Value: **usual.event.ABILITY_ADDED**
  - Required subscriber permissions: ohos.permission.LISTEN_BUNDLE_CHANGE

* COMMON_EVENT_ABILITY_REMOVED
(Reserved, not supported yet) Indicates the common event that an ability has been removed.
  - Value: **usual.event.ABILITY_REMOVED**
  - Required subscriber permissions: ohos.permission.LISTEN_BUNDLE_CHANGE

* COMMON_EVENT_ABILITY_UPDATED
(Reserved, not supported yet) Indicates the common event that an ability has been updated.
  - Value: **usual.event.ABILITY_UPDATED**
  - Required subscriber permissions: ohos.permission.LISTEN_BUNDLE_CHANGE

* COMMON_EVENT_LOCATION_MODE_STATE_CHANGED
(Reserved, not supported yet) Indicates the common event that the location mode of the system has changed.
  - Value: **usual.event.location.MODE_STATE_CHANGED**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_SLEEP
(Reserved, not supported yet) Indicates the common event that the in-vehicle infotainment (IVI) system of a vehicle is sleeping.
  - Value: **common.event.IVI_SLEEP**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_PAUSE
(Reserved, not supported yet) Indicates the common event that the IVI system of a vehicle has entered sleep mode and the playing application is instructed to stop playback.
  - Value: **common.event.IVI_PAUSE**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_STANDBY
(Reserved, not supported yet) Indicates the common event that a third-party application is instructed to pause the current work.
  - Value: **common.event.IVI_STANDBY**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_LASTMODE_SAVE
(Reserved, not supported yet) Indicates the common event that a third-party application is instructed to save its last mode.
  - Value: **common.event.IVI_LASTMODE_SAVE**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_VOLTAGE_ABNORMAL
(Reserved, not supported yet) Indicates the common event that the voltage of the vehicle's power system is abnormal.
  - Value: **common.event.IVI_VOLTAGE_ABNORMAL**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_HIGH_TEMPERATURE
(Reserved, not supported yet) Indicates the common event that the temperature of the IVI system is high.
  - Value: **common.event.IVI_HIGH_TEMPERATURE**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_EXTREME_TEMPERATURE
(Reserved, not supported yet) Indicates the common event that the temperature of the IVI system is extremely high.
  - Value: **common.event.IVI_EXTREME_TEMPERATURE**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL
(Reserved, not supported yet) Indicates the common event that the IVI system has an extreme temperature.
  - Value: **common.event.IVI_TEMPERATURE_ABNORMAL**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_VOLTAGE_RECOVERY
(Reserved, not supported yet) Indicates the common event that the voltage of the vehicle's power system is restored to normal.
  - Value: **common.event.IVI_VOLTAGE_RECOVERY**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_TEMPERATURE_RECOVERY
(Reserved, not supported yet) Indicates the common event that the temperature of the IVI system is restored to normal.
  - Value: **common.event.IVI_TEMPERATURE_RECOVERY**
  - Required subscriber permissions: none

* COMMON_EVENT_IVI_ACTIVE
(Reserved, not supported yet) Indicates the common event that the battery service is active.
  - Value: **common.event.IVI_ACTIVE**
  - Required subscriber permissions: none

* [COMMON_EVENT_USB_STATE<sup>9+</sup>](../common_event/commonEvent-usb.md#common_event_usb_state)
Indicates the common event that the USB device state has changed.

* [COMMON_EVENT_USB_PORT_CHANGED<sup>9+</sup>](../common_event/commonEvent-usb.md#common_event_usb_port_changed)
Indicates the common event that the USB port state of the user device has changed.

* [COMMON_EVENT_USB_DEVICE_ATTACHED](../common_event/commonEvent-usb.md#common_event_usb_device_attached)
Indicates the common event that a USB device has been attached when the user device functions as a USB host.

* [COMMON_EVENT_USB_DEVICE_DETACHED](../common_event/commonEvent-usb.md#common_event_usb_device_detached)
Indicates the common event that a USB device has been detached when the user device functions as a USB host.

* [COMMON_EVENT_USB_ACCESSORY_ATTACHED](../common_event/commonEvent-usb.md#common_event_usb_accessory_attached)
(Reserved, not supported yet) Indicates that a USB accessory was attached.

* [COMMON_EVENT_USB_ACCESSORY_DETACHED](../common_event/commonEvent-usb.md#common_event_usb_accessory_detached)
(Reserved, not supported yet) Indicates the common event that a USB accessory was detached.

* COMMON_EVENT_DISK_REMOVED
(Reserved, not supported yet) Indicates the common event that an external storage device was removed.
  - Value: **usual.event.data.DISK_BAD_REMOVAL**
  - The subscriber requires the ohos.permission.STORAGE_MANAGER permission. Only system applications can apply for this permission.

* COMMON_EVENT_DISK_UNMOUNTED
(Reserved, not supported yet) Indicates the common event that an external storage device was unmounted.
  - Value: **usual.event.data.DISK_UNMOUNTABLE**
  - The subscriber requires the ohos.permission.STORAGE_MANAGER permission. Only system applications can apply for this permission.

* COMMON_EVENT_DISK_MOUNTED
(Reserved, not supported yet) Indicates the common event that an external storage device was mounted.
  - Value: **usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED**
  - The subscriber requires the ohos.permission.STORAGE_MANAGER permission. Only system applications can apply for this permission.

* COMMON_EVENT_DISK_BAD_REMOVAL
(Reserved, not supported yet) Indicates the common event that an external storage device was removed without being unmounted.
  - Value: **usual.event.data.DISK_REMOVED**
  - The subscriber requires the ohos.permission.STORAGE_MANAGER permission. Only system applications can apply for this permission.

* COMMON_EVENT_DISK_UNMOUNTABLE
(Reserved, not supported yet) Indicates the common event that an external storage device becomes unmountable.
  - Value: **usual.event.data.DISK_UNMOUNTED**
  - The subscriber requires the ohos.permission.STORAGE_MANAGER permission. Only system applications can apply for this permission.

* COMMON_EVENT_DISK_EJECT
(Reserved, not supported yet) Indicates the common event that an external storage device was ejected.
  - Value: **usual.event.data.DISK_EJECT**
  - The subscriber requires the ohos.permission.STORAGE_MANAGER permission. Only system applications can apply for this permission.

* [COMMON_EVENT_VOLUME_REMOVED<sup>9+</sup> ](../common_event/commonEvent-filemanagement.md#common_event_volume_removed9)
Indicates the common event that an external storage device was removed.

* [COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+</sup> ](../common_event/commonEvent-filemanagement.md#common_event_volume_unmounted9)
Indicates the common event that an external storage device was unmounted.

* [COMMON_EVENT_VOLUME_MOUNTED<sup>9+</sup> ](../common_event/commonEvent-filemanagement.md#common_event_volume_mounted9)
Indicates the common event that an external storage device was mounted.

* [COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+</sup> ](../common_event/commonEvent-filemanagement.md#common_event_volume_bad_removal9)
Indicates the common event that an external storage device was removed without being unmounted.

* [COMMON_EVENT_VOLUME_EJECT<sup>9+</sup> ](../common_event/commonEvent-filemanagement.md#common_event_volume_eject9)
Indicates the common event that an external storage device was ejected.

* COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED
(Reserved, not supported yet) Indicates the common event that the account visibility changed.
  - Value: **usual.event.data.VISIBLE_ACCOUNTS_UPDATED**
  - The subscriber requires the ohos.permission.GET_APP_ACCOUNTS permission. Only system applications can apply for this permission.

* COMMON_EVENT_ACCOUNT_DELETED
(Reserved, not supported yet) Indicates the common event that the account was deleted.
  - Value: **usual.event.data.ACCOUNT_DELETED**
  - Permission required by subscribers: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS. Only system applications can apply for this permission.

* COMMON_EVENT_FOUNDATION_READY
(Reserved, not supported yet) Indicates the common event that the foundation is ready.
  - Value: **usual.event.data.FOUNDATION_READY**
  - Permission required by subscribers: ohos.permission.RECEIVER_STARTUP_COMPLETED (Only system applications can apply for this permission.)

* COMMON_EVENT_AIRPLANE_MODE_CHANGED
Indicates the common event that the airplane mode of the device has changed.
  - Value: **usual.event.AIRPLANE_MODE**
  - Required subscriber permissions: none

* COMMON_EVENT_SPLIT_SCREEN
Indicates the common event of screen splitting.
  - Value: **usual.event.SPLIT_SCREEN**
  - Required subscriber permissions: ohos.permission.RECEIVER_SPLIT_SCREEN

* [COMMON_EVENT_SLOT_CHANGE<sup>9+</sup> ](../common_event/commonEvent-ans.md#common_event_slot_change)
Indicates the common event of slot changing.
* COMMON_EVENT_SPN_INFO_CHANGED <sup>9+</sup> 
Indicates the common event of that the SPN information had changed.
  - Value: **usual.event.SPN_INFO_CHANGED**
  - Required subscriber permissions: none

* [COMMON_EVENT_QUICK_FIX_APPLY_RESULT<sup>9+</sup> ](../common_event/commonEvent-ability.md#common_event_quick_fix_apply_result9)
Indicates the result of applying a quick fix to the application.
* COMMON_EVENT_HTTP_PROXY_CHANGE<sup>10+</sup> 
Indicates that the HTTP proxy configuration has changed.
  - Value: **usual.event.HTTP_PROXY_CHANGE**
  - Required subscriber permissions: none

* [COMMON_EVENT_DOMAIN_ACCOUNT_STATUS_CHANGED<sup>10+</sup> ](../common_event/commonEvent-account.md#common_event_domain_account_status_changed10)
Indicates that the status of the domain account status changes.

* [COMMON_EVENT_SIM_STATE_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sim_state_changed)
Indicates that the SIM card status has changed.

* [COMMON_EVENT_SMS_RECEIVED_COMPLETED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sms_received_completed)
Indicates that an SMS message is received.

* [COMMON_EVENT_SMS_EMERGENCY_CB_RECEIVE_COMPLETED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sms_emergency_cb_receive_completed)
Indicates that an emergency cell broadcast message is received.

* [COMMON_EVENT_SMS_CB_RECEIVE_COMPLETED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sms_cb_receive_completed)
Indicates that a cell broadcast message is received.

* [COMMON_EVENT_STK_COMMAND<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_stk_command)
(Reserved, not supported yet) Indicates that an STK command is sent.

* [COMMON_EVENT_STK_SESSION_END<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_stk_session_end)
(Reserved, not supported yet) Indicates that an STK session has ended.

* [COMMON_EVENT_STK_CARD_STATE_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_stk_card_state_changed)
(Reserved, not supported yet) Indicates that the STK card status has been updated.

* [COMMON_EVENT_STK_ALPHA_IDENTIFIER<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_stk_alpha_identifier)
(Reserved, not supported yet) Indicates that an STK Alpha identifier is sent.

* [COMMON_EVENT_SMS_WAPPUSH_RECEIVE_COMPLETED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sms_wappush_receive_completed)
Indicates that a WAP push message is received.

* [COMMON_EVENT_OPERATOR_CONFIG_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_operator_config_changed)
Indicates that the carrier configuration has been updated.

* [COMMON_EVENT_SIM_CARD_DEFAULT_SMS_SUBSCRIPTION_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sim_card_default_sms_subscription_changed)
Indicates that the default primary SIM card for the SMS service has been updated.

* [COMMON_EVENT_SIM_CARD_DEFAULT_DATA_SUBSCRIPTION_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sim_card_default_data_subscription_changed)
Indicates that the default primary SIM card for the data service has been updated.

* [COMMON_EVENT_SIM_CARD_DEFAULT_MAIN_SUBSCRIPTION_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sim_card_default_main_subscription_changed)
Indicates that the default primary SIM card of the device has been updated.

* [COMMON_EVENT_SIM_CARD_DEFAULT_VOICE_SUBSCRIPTION_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_sim_card_default_voice_subscription_changed)
When the default primary SIM card for the voice service is updated, the event notification service is triggered to publish this event.

* [COMMON_EVENT_CALL_STATE_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_call_state_changed)
Indicates that the call status has been updated.

* [COMMON_EVENT_CELLULAR_DATA_STATE_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_cellular_data_state_changed)
Indicates that the cellular data status has been updated.

* [COMMON_EVENT_NETWORK_STATE_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_network_state_changed)
Indicates that the network status has been updated.

* [COMMON_EVENT_SIGNAL_INFO_CHANGED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_signal_info_changed)
Indicates that the signal information has been updated.

* [COMMON_EVENT_INCOMING_CALL_MISSED<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_incoming_call_missed)
Indicates that an incoming call is missed.

* [COMMON_EVENT_RADIO_STATE_CHANGE<sup>10+</sup> ](../common_event/commonEvent-telephony.md#common_event_radio_state_change)
Indicates that the radio status of the device has changed.

* [COMMON_EVENT_SCREEN_LOCKED <sup>10+</sup> ](../common_event/commonEvent-screenlock.md#common_event_screen_locked)
Indicates that the screen has been locked.

* [COMMON_EVENT_SCREEN_UNLOCKED<sup>10+</sup> ](../common_event/commonEvent-screenlock.md#common_event_screen_unlocked)
Indicates that the screen has been unlocked.

* [COMMON_EVENT_QUICK_FIX_REVOKE_RESULT<sup>10+</sup> ](../common_event/commonEvent-ability.md#common_event_quick_fix_revoke_result10)
Indicates the result of revoking a quick fix to the application.

* [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN](../common_event/commonEvent-account.md#common_event_distributed_account_login)
Indicates a successful login to a distributed account.

* [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT](../common_event/commonEvent-account.md#common_event_distributed_account_logout)
Indicates a successful logout from a distributed account.

* [COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID](../common_event/commonEvent-account.md#common_event_distributed_account_token_invalid)
Indicates that the token of a distributed account is invalid.

* [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF](../common_event/commonEvent-account.md#common_event_distributed_account_logoff)
Indicates that a distributed account is deregistered.

* [COMMON_EVENT_USER_INFO_UPDATED<sup>9+</sup> ](../common_event/commonEvent-account.md#common_event_user_info_updated9)
Indicates that the user information has been updated.

* [COMMON_EVENT_AUDIO_QUALITY_CHANGE](../common_event/commonEvent-telephony.md#common_event_audio_quality_change)
Indicates that the audio quality has changed.

* [COMMON_EVENT_HTTP_PROXY_CHANGE<sup>10+</sup> ](../common_event/commonEvent-netmanager.md#common_event_http_proxy_change10)
Indicates that the HTTP proxy configuration has been updated.

* [COMMON_EVENT_AIRPLANE_MODE_CHANGED<sup>10+</sup> ](../common_event/commonEvent-netmanager.md#common_event_airplane_mode_changed10)
Indicates that the airplane mode state has changed.

* [COMMON_EVENT_CONNECTIVITY_CHANGE<sup>10+</sup> ](../common_event/commonEvent-netmanager.md#common_event_connectivity_change10)
Indicates that the network connection state has changed.