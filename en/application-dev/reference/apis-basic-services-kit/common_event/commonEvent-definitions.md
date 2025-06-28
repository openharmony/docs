# System Common Events (To Be Deprecated Soon)

This document provides indexes for predefined system common events.
Common event types are defined in [Support enumeration of the ohos.commonEvent module](../js-apis-commonEvent.md#support).

**System capability**: SystemCapability.Notification.CommonEvent

* COMMON_EVENT_BOOT_COMPLETED
Indicates that the boot is complete and the system is loaded.
  - Value: **usual.event.BOOT_COMPLETED**
  - Required permissions: ohos.permission.RECEIVER_STARTUP_COMPLETED (for system applications only)

* COMMON_EVENT_LOCKED_BOOT_COMPLETED
(Reserved, not supported yet) Indicates that the guidance is complete and the system is loaded, but the screen is still locked.
  - Value: **usual.event.LOCKED_BOOT_COMPLETED**
  - Required permissions: ohos.permission.RECEIVER_STARTUP_COMPLETED (for system applications only)

* COMMON_EVENT_SHUTDOWN
Indicates that the device is being shut down and will continue until it is finally shut down.
  - Value: **usual.event.SHUTDOWN**
  - Required permissions: none

* COMMON_EVENT_BATTERY_CHANGED
Indicates that the battery charging status, battery level, and other information has changed.
  - Value: **usual.event.BATTERY_CHANGED**
  - Required permissions: none

* COMMON_EVENT_BATTERY_LOW
Indicates that the battery level is low.
  - Value: **usual.event.BATTERY_LOW**
  - Required permissions: none

* COMMON_EVENT_BATTERY_OKAY
Indicates that the battery level is normal.
  - Value: **usual.event.BATTERY_OKAY**
  - Required permissions: none

* COMMON_EVENT_POWER_CONNECTED
Indicates that the device is connected to an external power supply.
  - Value: **usual.event.POWER_CONNECTED**
  - Required permissions: none


* COMMON_EVENT_POWER_DISCONNECTED
Indicates that the device is disconnected from the external power supply.
  - Value: **usual.event.POWER_DISCONNECTED**
  - Required permissions: none


* COMMON_EVENT_SCREEN_OFF
Indicates that the device screen is off and the device is in sleep mode.
  - Value: **usual.event.SCREEN_OFF**
  - Required permissions: none


* COMMON_EVENT_SCREEN_ON
Indicates that the device screen is on and the device is in interactive state.
  - Value: **usual.event.SCREEN_ON**
  - Required permissions: none


* COMMON_EVENT_THERMAL_LEVEL_CHANGED<sup>8+</sup>
Indicates that the device's thermal level has changed.
  - Value: **usual.event.THERMAL_LEVEL_CHANGED**
  - Required permissions: none


* COMMON_EVENT_USER_PRESENT
(Reserved, not supported yet) Indicates that the user unlocks the device.
  - Value: **usual.event.USER_PRESENT**
  - Required permissions: none


* COMMON_EVENT_TIME_TICK
Indicates that the system time has changed as time ticks by.
  - Value: **usual.event.TIME_TICK**
  - Required permissions: none


* COMMON_EVENT_TIME_CHANGED
Indicates that the system time is set.
  - Value: **usual.event.TIME_CHANGED**
  - Required permissions: none


* COMMON_EVENT_DATE_CHANGED
(Reserved, not supported yet) Indicates that the system date has been changed.
  - Value: **usual.event.DATE_CHANGED**
  - Required permissions: none


* COMMON_EVENT_TIMEZONE_CHANGED
Indicates that the system time zone is changed.
  - Value: **usual.event.TIMEZONE_CHANGED**
  - Required permissions: none


* COMMON_EVENT_CLOSE_SYSTEM_DIALOGS
(Reserved, not supported yet) Indicates that the user closes a temporary system dialog box.
  - Value: **usual.event.CLOSE_SYSTEM_DIALOGS**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_ADDED
Indicates that a new application package has been installed on the device.
  - Value: **usual.event.PACKAGE_ADDED**
  - Required permissions: none

* COMMON_EVENT_PACKAGE_INSTALLATION_STARTED
Indicates that the application package starts to be installed on the device.
  - Value: **usual.event.PACKAGE_INSTALLATION_STARTED**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_REPLACED
(Reserved, not supported yet) Indicates that a later version of an installed application package has replaced the previous one on the device.
  - Value: **usual.event.PACKAGE_REPLACED**
  - Required permissions: none


* COMMON_EVENT_MY_PACKAGE_REPLACED
(Reserved, not supported yet) Indicates that the new version of the application package has replaced the previous version.
  - Value: **usual.event.MY_PACKAGE_REPLACED**
  - Required permissions: none

* COMMON_EVENT_PACKAGE_REMOVED
Indicates that an installed application has been uninstalled from the device with the application data retained.
  - Value: **usual.event.PACKAGE_REMOVED**
  - Required permissions: none


* COMMON_EVENT_BUNDLE_REMOVED
(Reserved, not supported yet) Indicates that an installed bundle has been uninstalled from the device with the application data retained. 
  - Value: **usual.event.BUNDLE_REMOVED**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_FULLY_REMOVED
(Reserved, not supported yet) Indicates that an installed application, including both the application data and code, has been completely uninstalled from the device.
  - Value: **usual.event.PACKAGE_FULLY_REMOVED**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_CHANGED
Indicates that an application package has been changed (for example, an ability in the package has been enabled or disabled).
  - Value: **usual.event.PACKAGE_CHANGED**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_RESTARTED
Indicates that the user closed all processes of the application and restarted the application.
  - Value: **usual.event.PACKAGE_RESTARTED**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_DATA_CLEARED
Indicates that the user cleared the application package data.
  - Value: **usual.event.PACKAGE_DATA_CLEARED**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_CACHE_CLEARED<sup>9+</sup>
Indicates that the user cleared the application package cache.
  - Value: **usual.event.PACKAGE_CACHE_CLEARED**
  - Required permissions: none


* COMMON_EVENT_PACKAGES_SUSPENDED
(Reserved, not supported yet) Indicates that application packages have been suspended.
  - Value: **usual.event.PACKAGES_SUSPENDED**
  - Required permissions: none


* COMMON_EVENT_PACKAGES_UNSUSPENDED
(Reserved, not supported yet) Indicates that the application HAP package is not suspended (resumed from the suspended state).
  - Value: **usual.event.PACKAGES_UNSUSPENDED**
  - Required permissions: none


* COMMON_EVENT_MY_PACKAGE_SUSPENDED
Indicates that the application HAP package is suspended.
  - Value: **usual.event.MY_PACKAGE_SUSPENDED**
  - Required permissions: none


* COMMON_EVENT_MY_PACKAGE_UNSUSPENDED
Indicates that the application package is not suspended.
  - Value: **usual.event.MY_PACKAGE_UNSUSPENDED**
  - Required permissions: none


* COMMON_EVENT_UID_REMOVED
(Reserved, not supported yet) Indicates that a user ID has been removed from the system.
  - Value: **usual.event.UID_REMOVED**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_FIRST_LAUNCH
(Reserved, not supported yet) Indicates that an installed application is started for the first time.
  - Value: **usual.event.PACKAGE_FIRST_LAUNCH**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION
(Reserved, not supported yet) Indicates that an application requires system verification.
  - Value: **usual.event.PACKAGE_NEEDS_VERIFICATION**
  - Required permissions: none


* COMMON_EVENT_PACKAGE_VERIFIED
(Reserved, not supported yet) Indicates that an application has been verified by the system.
  - Value: **usual.event.PACKAGE_VERIFIED**
  - Required permissions: none


* COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE
(Reserved, not supported yet) Indicates that applications installed on the external storage are available for the system.
  - Value: **usual.event.EXTERNAL_APPLICATIONS_AVAILABLE**
  - Required permissions: none


* COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE
(Reserved, not supported yet) Indicates that applications installed on the external storage are not available for the system.
  - Value: **usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE**
  - Required permissions: none


* COMMON_EVENT_CONFIGURATION_CHANGED
(Reserved, not supported yet) Indicates that the device state (for example, orientation and locale) has changed.
  - Value: **usual.event.CONFIGURATION_CHANGED**
  - Required permissions: none


* COMMON_EVENT_LOCALE_CHANGED
(Reserved, not supported yet) Indicates that the device locale has changed.
  - Value: **usual.event.LOCALE_CHANGED**
  - Required permissions: none


* COMMON_EVENT_MANAGE_PACKAGE_STORAGE
(Reserved, not supported yet) Indicates that the device storage is insufficient.
  - Value: **usual.event.MANAGE_PACKAGE_STORAGE**
  - Required permissions: none


* COMMON_EVENT_DRIVE_MODE
(Reserved, not supported yet) Indicates that the system is in driving mode.
  - Value: **common.event.DRIVE_MODE**
  - Required permissions: none


* COMMON_EVENT_HOME_MODE
(Reserved, not supported yet) Indicates that the system is in home mode.
  - Value: **common.event.HOME_MODE**
  - Required permissions: none


* COMMON_EVENT_OFFICE_MODE
(Reserved, not supported yet) Indicates that the system is in office mode.
  - Value: **common.event.OFFICE_MODE**
  - Required permissions: none


* COMMON_EVENT_USER_STARTED
(Reserved, not supported yet) Indicates that the user has been started.
  - Value: **usual.event.USER_STARTED**
  - Required permissions: none


* COMMON_EVENT_USER_BACKGROUND
(Reserved, not supported yet) Indicates that the user has been brought to the background.
  - Value: **usual.event.USER_BACKGROUND**
  - Required permissions: none


* COMMON_EVENT_USER_FOREGROUND
(Reserved, not supported yet) Indicates that the user has been brought to the foreground.
  - Value: **usual.event.USER_FOREGROUND**
  - Required permissions: none


* COMMON_EVENT_USER_SWITCHED
Indicates that user switching is in progress.
  - Value: **usual.event.USER_SWITCHED**
  - Required permissions: ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only)


* COMMON_EVENT_USER_STARTING
(Reserved, not supported yet) Indicates that user starting is in progress.
  - Value: **usual.event.USER_STARTING**
  - Required permissions: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (for system applications only)


* COMMON_EVENT_USER_UNLOCKED
(Reserved, not supported yet) Indicates that the credential encryption storage of the current user has been unlocked upon restart.
  - Value: **usual.event.USER_UNLOCKED**
  - Required permissions: none


* COMMON_EVENT_USER_STOPPING
(Reserved, not supported yet) Prompt the user to stop.
  - Value: **usual.event.USER_STOPPING**
  - Required permissions: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (for system applications only)


* COMMON_EVENT_USER_STOPPED
(Reserved, not supported yet) Indicates that the user has been stopped.
  - Value: **usual.event.USER_STOPPED**
  - Required permissions: none


* COMMON_EVENT_WIFI_POWER_STATE
Indicates that the Wi-Fi state has changed, for example, enabled or disabled.
  - Value: **usual.event.wifi.POWER_STATE**
  - Required permissions: none


* COMMON_EVENT_WIFI_SCAN_FINISHED
Indicates that the Wi-Fi access point has been scanned and proved available.
  - Value: **usual.event.wifi.SCAN_FINISHED**
  - Required permissions: ohos.permission.LOCATION


* COMMON_EVENT_WIFI_RSSI_VALUE
Indicates that the Wi-Fi signal strength (RSSI) has changed.
  - Value: **usual.event.wifi.RSSI_VALUE**
  - Required permissions: ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_CONN_STATE
Indicates that the Wi-Fi connection state has changed.
  - Value: **usual.event.wifi.CONN_STATE**
  - Required permissions: none


* COMMON_EVENT_WIFI_HOTSPOT_STATE
Indicates that the Wi-Fi hotspot state has changed, for example, enabled or disabled.
  - Value: **usual.event.wifi.HOTSPOT_STATE**
  - Required permissions: none


* COMMON_EVENT_WIFI_AP_STA_JOIN
Indicates that a client has joined the Wi-Fi hotspot of the current device.
  - Value: **usual.event.wifi.WIFI_HS_STA_JOIN**
  - Required permissions: ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_AP_STA_LEAVE
Indicates that the client is disconnected from the Wi-Fi hotspot of the current device.
  - Value: **usual.event.wifi.WIFI_HS_STA_LEAVE**
  - Required permissions: ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE
(Not supported yet) Indicates that the state of MPLINK (an enhanced Wi-Fi feature) has changed. 
  - Value: **usual.event.wifi.mplink.STATE_CHANGE**
  - Required permissions: none


* COMMON_EVENT_WIFI_P2P_CONN_STATE
Indicates that the Wi-Fi P2P connection state has changed.
  - Value: **usual.event.wifi.p2p.CONN_STATE_CHANGE**
  - Required permissions: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION


* COMMON_EVENT_WIFI_P2P_STATE_CHANGED
Indicates that the Wi-Fi P2P state has changed, for example, enabled or disabled.
  - Value: **usual.event.wifi.p2p.STATE_CHANGE**
  - Required permissions: ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED
Indicates that the state of the Wi-Fi P2P peer device has changed.
  - Value: **usual.event.wifi.p2p.DEVICES_CHANGE**
  - Required permissions: ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED
Indicates that the Wi-Fi P2P discovery state has changed.
  - Value: **usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE**
  - Required permissions: ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED
Indicates that the state of the Wi-Fi P2P local device has changed.
  - Value: **usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE**
  - Required permissions: ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED
Indicates that the Wi-Fi P2P group information has changed.
  - Value: **usual.event.wifi.p2p.GROUP_STATE_CHANGED**
  - Required permissions: ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the connection state of Bluetooth handsfree communication.
  - Value: **usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE
(Reserved, not supported yet) Indicates that the device connected to the Bluetooth hands-free function is active.
  - Value: **usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates that the connection state of Bluetooth A2DP has changed.
  - Value: **usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the connection state of Bluetooth A2DP.
  - Value: **usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE
(Reserved, not supported yet) Indicates that the device connected using Bluetooth A2DP is active.
  - Value: **usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE
(Reserved, not supported yet) Indicates that the playing state of Bluetooth A2DP has changed.
  - Value: **usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates that the AVRCP connection state of Bluetooth A2DP has changed.
  - Value: **usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE
(Reserved, not supported yet) Indicates that the audio codec state of Bluetooth A2DP has changed.
  - Value: **usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED
(Reserved, not supported yet) Indicates that a remote Bluetooth device is discovered.
  - Value: **usual.event.bluetooth.remotedevice.DISCOVERED**
  - Required permissions: ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE
(Reserved, not supported yet) Indicates that the Bluetooth class of a remote Bluetooth device has changed.
  - Value: **usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED
(Reserved, not supported yet) A low-level (ACL) connection has been established with the remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.ACL_CONNECTED**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED
(Reserved, not supported yet) Indicates that the low-level (ACL) connection has been disconnected from the remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.ACL_DISCONNECTED**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE
(Reserved, not supported yet) Indicates that the friendly name of a remote Bluetooth device is retrieved for the first time or has changed since the last retrieval.
  - Value: **usual.event.bluetooth.remotedevice.NAME_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE
(Reserved, not supported yet) Indicates the connection state with a remote Bluetooth device is changed.
  - Value: **usual.event.bluetooth.remotedevice.PAIR_STATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE
(Reserved, not supported yet) Indicates that the battery level of a remote Bluetooth device is retrieved for the first time or has changed since the last retrieval.
  - Value: **usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT
(Reserved, not supported yet) Indicates the SDP state of a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.SDP_RESULT**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE
(Reserved, not supported yet) Indicates the UUID connection state with a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.UUID_VALUE**
  - Required permissions: ohos.permission.DISCOVER_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ
(Reserved, not supported yet) Indicates the pairing request from a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.PAIRING_REQ**
  - Required permissions: ohos.permission.DISCOVER_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL
(Reserved, not supported yet) Indicates that Bluetooth pairing has been canceled.
  - Value: **usual.event.bluetooth.remotedevice.PAIRING_CANCEL**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ
(Reserved, not supported yet) Indicates the connection request from a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.CONNECT_REQ**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY
(Reserved, not supported yet) Indicates the response to the connection request from a remote Bluetooth device.
  - Value: **usual.event.bluetooth.remotedevice.CONNECT_REPLY**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL
(Reserved, not supported yet) Indicates that the connection to a remote Bluetooth device has been canceled.
  - Value: **usual.event.bluetooth.remotedevice.CONNECT_CANCEL**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates that the connection state with a Bluetooth handsfree has changed.
  - Value: **usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates that the audio state of a Bluetooth handsfree has changed.
  - Value: **usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT
(Reserved, not supported yet) Indicates that the audio gateway state of a Bluetooth handsfree has changed.
  - Value: **usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE
(Reserved, not supported yet) Indicates that the calling state of a Bluetooth handsfree has changed.
  - Value: **usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE
(Reserved, not supported yet) Displays a message indicating that the Bluetooth adapter status has been changed, for example, Bluetooth has been enabled or disabled.
  - Value: **usual.event.bluetooth.host.STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE
(Reserved, not supported yet) This event is used to notify a subscriber that Bluetooth scanning is allowed.
  - Value: **usual.event.bluetooth.host.REQ_DISCOVERABLE**
  - Required permissions: none


* COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE
(Reserved, not supported yet) Prompt the user to enable the Bluetooth request.
  - Value: **usual.event.bluetooth.host.REQ_ENABLE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE
(Reserved, not supported yet) Prompt the user to disable the Bluetooth request.
  - Value: **usual.event.bluetooth.host.REQ_DISABLE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE
(Reserved, not supported yet) Indicates that the Bluetooth scanning mode of the device is changed.
  - Value: **usual.event.bluetooth.host.SCAN_MODE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED
(Reserved, not supported yet) Displays a message indicating that Bluetooth scanning has been enabled on the device.
  - Value: **usual.event.bluetooth.host.DISCOVERY_STARTED**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED
(Reserved, not supported yet) Displays a message indicating that Bluetooth scanning on the device is complete.
  - Value: **usual.event.bluetooth.host.DISCOVERY_FINISHED**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE
(Reserved, not supported yet) Indicates that the name of the device Bluetooth adapter has changed.
  - Value: **usual.event.bluetooth.host.NAME_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates that the connection state of Bluetooth A2DP Sink has changed.
  - Value: **usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE
(Reserved, not supported yet) Indicates that the playing state of Bluetooth A2DP Sink has changed.
  - Value: **usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates that the audio state of Bluetooth A2DP Sink has changed.
  - Value: **usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE**
  - Required permissions: ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED
(Reserved, not supported yet) Indicates that the state of the device NFC adapter has changed.
  - Value: **usual.event.nfc.action.ADAPTER_STATE_CHANGED**
  - Required permissions: none


* COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED
(Reserved, not supported yet) Indicates that the NFC RF field is detected to be in the enabled state.
  - Value: **usual.event.nfc.action.RF_FIELD_ON_DETECTED**
  - Required permissions: ohos.permission.MANAGE_SECURE_SETTINGS (for system applications only)


* COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED
(Reserved, not supported yet) Indicates that the NFC RF field is detected to be in the disabled state.
  - Value: **usual.event.nfc.action.RF_FIELD_OFF_DETECTED**
  - Required permissions: ohos.permission.MANAGE_SECURE_SETTINGS (for system applications only)


* COMMON_EVENT_DISCHARGING
Indicates that the system stops charging the battery.
  - Value: **usual.event.DISCHARGING**
  - Required permissions: none


* COMMON_EVENT_CHARGING
Indicates that the system starts charging the battery.
  - Value: **usual.event.CHARGING**
  - Required permissions: none


* COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED
(Reserved, not supported yet) Indicates that the system idle mode has changed.
  - Value: **usual.event.DEVICE_IDLE_MODE_CHANGED**
  - Required permissions: none


* COMMON_EVENT_POWER_SAVE_MODE_CHANGED
Indicates that the system power-saving mode has changed.
  - Value: **usual.event.POWER_SAVE_MODE_CHANGED**
  - Required permissions: none


* COMMON_EVENT_USER_ADDED
Indicates that a user has been added to the system.
  - Value: **usual.event.USER_ADDED**
  - Required permissions: ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only)


* COMMON_EVENT_USER_REMOVED
Indicates that a user has been removed from the system.
  - Value: **usual.event.USER_REMOVED**
  - Required permissions: ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only)


* COMMON_EVENT_ABILITY_ADDED
(Reserved, not supported yet) Indicates that an ability has been added.
  - Value: **usual.event.ABILITY_ADDED**
  - Required permissions: ohos.permission.LISTEN_BUNDLE_CHANGE


* COMMON_EVENT_ABILITY_REMOVED
(Reserved, not supported yet) Indicates that an ability has been removed.
  - Value: **usual.event.ABILITY_REMOVED**
  - Required permissions: ohos.permission.LISTEN_BUNDLE_CHANGE


* COMMON_EVENT_ABILITY_UPDATED
(Reserved, not supported yet) Indicates that an ability has been updated.
  - Value: **usual.event.ABILITY_UPDATED**
  - Required permissions: ohos.permission.LISTEN_BUNDLE_CHANGE


* COMMON_EVENT_LOCATION_MODE_STATE_CHANGED
(Reserved, not supported yet) Indicates that the location mode of the system has changed.
  - Value: **usual.event.location.MODE_STATE_CHANGED**
  - Required permissions: none


* COMMON_EVENT_IVI_SLEEP
(Reserved, not supported yet) Indicates that the in-vehicle infotainment (IVI) system of the vehicle is sleeping.
  - Value: **common.event.IVI_SLEEP**
  - Required permissions: none


* COMMON_EVENT_IVI_PAUSE
(Reserved, not supported yet) Displays a message indicating that the in-vehicle infotainment (IVI) system of the vehicle is in sleep mode and notifies the application to stop playing.
  - Value: **common.event.IVI_PAUSE**
  - Required permissions: none


* COMMON_EVENT_IVI_STANDBY
(Reserved, not supported yet) This event is used to notify a third-party application in the in-vehicle infotainment (IVI) system of a vehicle that the current work is suspended.
  - Value: **common.event.IVI_STANDBY**
  - Required permissions: none


* COMMON_EVENT_IVI_LASTMODE_SAVE
(Reserved, not supported yet) Prompts the third-party application in the in-vehicle infotainment (IVI) system of the vehicle to save the last mode.
  - Value: **common.event.IVI_LASTMODE_SAVE**
  - Required permissions: none


* COMMON_EVENT_IVI_VOLTAGE_ABNORMAL
(Reserved, not supported yet) Indicates that the voltage of the vehicle's power system is abnormal.
  - Value: **common.event.IVI_VOLTAGE_ABNORMAL**
  - Required permissions: none


* COMMON_EVENT_IVI_HIGH_TEMPERATURE
(Reserved, not supported yet) Indicates that the temperature of the in-vehicle infotainment (IVI) system of the vehicle is too high.
  - Value: **common.event.IVI_HIGH_TEMPERATURE**
  - Required permissions: none


* COMMON_EVENT_IVI_EXTREME_TEMPERATURE
(Reserved, not supported yet) Indicates that the temperature of the in-vehicle infotainment (IVI) system of the vehicle is extremely high.
  - Value: **common.event.IVI_EXTREME_TEMPERATURE**
  - Required permissions: none


* COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL
(Reserved, not supported yet) Indicates that the in-vehicle infotainment (IVI) system of the vehicle has an extreme temperature.
  - Value: **common.event.IVI_TEMPERATURE_ABNORMAL**
  - Required permissions: none


* COMMON_EVENT_IVI_VOLTAGE_RECOVERY
(Reserved, not supported yet) Indicates that the voltage of the vehicle's power system is restored to normal.
  - Value: **common.event.IVI_VOLTAGE_RECOVERY**
  - Required permissions: none


* COMMON_EVENT_IVI_TEMPERATURE_RECOVERY
(Reserved, not supported yet) Indicates that the temperature of the IVI system is restored to normal.
  - Value: **common.event.IVI_TEMPERATURE_RECOVERY**
  - Required permissions: none


* COMMON_EVENT_IVI_ACTIVE
(Reserved, not supported yet) Indicates that the battery service of the vehicle-mounted system is active.
  - Value: **common.event.IVI_ACTIVE**
  - Required permissions: none


* COMMON_EVENT_USB_STATE<sup>9+</sup>
Indicates that the USB device state has changed.
  - Value: **usual.event.hardware.usb.action.USB_STATE**
  - Required permissions: none


* COMMON_EVENT_USB_PORT_CHANGED<sup>9+</sup>
Indicates that the USB port state of the device has changed.
  - Value: **usual.event.hardware.usb.action.USB_PORT_CHANGED**
  - Required permissions: none


* COMMON_EVENT_USB_DEVICE_ATTACHED
Indicates that a USB device has been attached to the device functioning as a USB host.
  - Value: **usual.event.hardware.usb.action.USB_DEVICE_ATTACHED**
  - Required permissions: none


* COMMON_EVENT_USB_DEVICE_DETACHED
Indicates that a USB device has been detached from the device functioning as a USB host.
  - Value: **usual.event.hardware.usb.action.USB_DEVICE_DETACHED**
  - Required permissions: none


* COMMON_EVENT_USB_ACCESSORY_ATTACHED
(Reserved, not supported yet) Indicates that a USB accessory was attached.
  - Value: **usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED**
  - Required permissions: none


* COMMON_EVENT_USB_ACCESSORY_DETACHED
(Reserved, not supported yet) Indicates that the USB attachment is uninstalled.
  - Value: **usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED**
  - Required permissions: none


* COMMON_EVENT_DISK_REMOVED
(Reserved, not supported yet) Indicates that an external storage device was removed.
  - Value: **usual.event.data.DISK_REMOVED**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_DISK_UNMOUNTED
(Reserved, not supported yet) Indicates that an external storage device was unmounted.
  - Value: **usual.event.data.DISK_UNMOUNTED**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_DISK_MOUNTED
(Reserved, not supported yet) Indicates that an external storage device was mounted.
  - Value: **usual.event.data.DISK_MOUNTED**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_DISK_BAD_REMOVAL
(Reserved, not supported yet) Indicates that an external storage device was removed without being unmounted.
  - Value: **usual.event.data.DISK_BAD_REMOVAL**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_DISK_UNMOUNTABLE
(Reserved, not supported yet) Indicates that the external storage device cannot be mounted when a card is inserted.
  - Value: **usual.event.data.DISK_UNMOUNTABLE**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_DISK_EJECT
(Reserved, not supported yet) Indicates that the external storage medium has been ejected (interactive operation at the system software layer, not directly ejected physically).
  - Value: **usual.event.data.DISK_EJECT**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_VOLUME_REMOVED<sup>9+</sup>
Indicates that an external storage device was removed.
  - Value: **usual.event.data.VOLUME_REMOVED**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+</sup>
Indicates that an external storage device was unmounted.
  - Value: **usual.event.data.VOLUME_UNMOUNTED**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_VOLUME_MOUNTED<sup>9+</sup>
Indicates that an external storage device was mounted.
  - Value: **usual.event.data.VOLUME_MOUNTED**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+</sup>
Indicates that an external storage device was removed without being unmounted.
  - Value: **usual.event.data.VOLUME_BAD_REMOVAL**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_VOLUME_EJECT<sup>9+</sup>
Indicates that the external storage medium has been ejected (interactive operation at the system software layer, not physical ejection).
  - Value: **usual.event.data.VOLUME_EJECT**
  - Required permissions: ohos.permission.STORAGE_MANAGER (for system applications only)


* COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED
(Reserved, not supported yet) Indicates that the account visibility changed.
  - Value: **usual.event.data.VISIBLE_ACCOUNTS_UPDATED**
  - Required permissions: ohos.permission.GET_APP_ACCOUNTS (for system applications only)


* COMMON_EVENT_ACCOUNT_DELETED
(Reserved, not supported yet) Indicates that an account was deleted.
  - Value: **usual.event.data.ACCOUNT_DELETED**
  - Required permissions: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (for system applications only)


* COMMON_EVENT_FOUNDATION_READY
(Reserved, not supported yet) Indicates that the foundation is ready.
  - Value: **usual.event.data.FOUNDATION_READY**
  - Required permissions: ohos.permission.RECEIVER_STARTUP_COMPLETED (for system applications only)


* COMMON_EVENT_AIRPLANE_MODE_CHANGED
Indicates that the airplane mode of the device has changed.
  - Value: **usual.event.AIRPLANE_MODE**
  - Required permissions: none


* COMMON_EVENT_SPLIT_SCREEN<sup>8+</sup>
Indicates that the screen has been split.


* COMMON_EVENT_SLOT_CHANGE<sup>9+</sup>
Indicates that the notification slot has been updated.
  - Value: **usual.event.SLOT_CHANGE**
  - Required permissions: ohos.permission.NOTIFICATION_CONTROLLER


* COMMON_EVENT_SPN_INFO_CHANGED<sup>9+</sup>
Indicates that the SPN displayed has been updated.
  - Value: **usual.event.SPN_INFO_CHANGED**
  - Required permissions: none


* COMMON_EVENT_QUICK_FIX_APPLY_RESULT<sup>9+</sup>
Indicates the result of quickly repairing an application.
  - Value: **usual.event.QUICK_FIX_APPLY_RESULT**
  - Required permissions: none

* COMMON_EVENT_USER_INFO_UPDATED<sup>9+</sup>
Indicates that the user information has been updated.
  - Value: **usual.event.USER_INFO_UPDATED**
  - Required permissions: none

* COMMON_EVENT_SMS_RECEIVE_COMPLETED
Indicates that a new SMS message has been received.

 <!--no_check--> 