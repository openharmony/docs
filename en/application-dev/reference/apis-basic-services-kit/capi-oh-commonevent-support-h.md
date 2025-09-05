# oh_commonevent_support.h

<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

## Overview

Provides common event constants defined by the system.

**Library**: libohcommonevent.so

**System capability**: SystemCapability.Notification.CommonEvent

**Since**: 12

**Related modules:** [OH_CommonEvent](capi-oh-commonevent.md)

## Summary

### Constants

| Name| Description|
| -- | -- |
| static const char * const COMMON_EVENT_SHUTDOWN = "usual.event.SHUTDOWN" | Indicates the common event that the device is being shut down and the final shutdown will proceed.<br>**Since**: 12<br>**System capability**: SystemCapability.Notification.CommonEvent|
| static const char * const COMMON_EVENT_BATTERY_CHANGED = "usual.event.BATTERY_CHANGED" | Indicates the common event that the charging state, level, and other information about the battery have changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_BATTERY_LOW = "usual.event.BATTERY_LOW" | Indicates the common event that the battery level is low.<br>**Since**: 12|
| static const char * const COMMON_EVENT_BATTERY_OKAY = "usual.event.BATTERY_OKAY" | Indicates the common event that the battery exits the low state.<br>**Since**: 12|
| static const char * const COMMON_EVENT_POWER_CONNECTED = "usual.event.POWER_CONNECTED" | Indicates the common event that the device is connected to an external power supply.<br>**Since**: 12|
| static const char * const COMMON_EVENT_POWER_DISCONNECTED = "usual.event.POWER_DISCONNECTED" | Indicates the common event that the device is disconnected from the external power supply.<br>**Since**: 12|
| static const char * const COMMON_EVENT_SCREEN_OFF = "usual.event.SCREEN_OFF" | Indicates the common event that the device screen is off and the device is sleeping.<br>**Since**: 12|
| static const char * const COMMON_EVENT_SCREEN_ON = "usual.event.SCREEN_ON" | Indicates the common event that the device screen is on and the device is in interactive state.<br>**Since**: 12|
| static const char * const COMMON_EVENT_ENTER_HIBERNATE = "usual.event.ENTER_HIBERNATE" | Indicates that the device is about to enter the hibernation mode.<br>**Since**: 15|
| static const char * const COMMON_EVENT_EXIT_HIBERNATE = "usual.event.EXIT_HIBERNATE" | Indicates that the device exits the hibernation mode.<br>**Since**: 15|
| static const char * const COMMON_EVENT_THERMAL_LEVEL_CHANGED = "usual.event.THERMAL_LEVEL_CHANGED" | Indicates the common event that the device's thermal level has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_TIME_TICK = "usual.event.TIME_TICK" | Indicates the common event that the system time has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_TIME_CHANGED = "usual.event.TIME_CHANGED" | Indicates the common event that the system time has been set.<br>**Since**: 12|
| static const char * const COMMON_EVENT_TIMEZONE_CHANGED = "usual.event.TIMEZONE_CHANGED" | Indicates the common event that the system time zone has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_PACKAGE_ADDED = "usual.event.PACKAGE_ADDED" | Indicates the common event that a new application package has been installed on the device.<br>**Since**: 12|
| static const char * const COMMON_EVENT_PACKAGE_REMOVED = "usual.event.PACKAGE_REMOVED" | Indicates the common event that an installed application has been uninstalled from the device with the application data retained.<br>**Since**: 12|
| static const char * const COMMON_EVENT_BUNDLE_REMOVED = "usual.event.BUNDLE_REMOVED" | Indicates the common event that an installed bundle has been uninstalled from the device with the application data retained.<br>**Since**: 12|
| static const char * const COMMON_EVENT_PACKAGE_FULLY_REMOVED = "usual.event.PACKAGE_FULLY_REMOVED" | Indicates the common event that an installed application, including both the application data and code, has been completely uninstalled from the device.<br>**Since**: 12|
| static const char * const COMMON_EVENT_PACKAGE_CHANGED = "usual.event.PACKAGE_CHANGED" | Indicates the common event that an application package has been changed (for example, a component in the package has been enabled or disabled).<br>**Since**: 12|
| static const char * const COMMON_EVENT_PACKAGE_RESTARTED = "usual.event.PACKAGE_RESTARTED" | Indicates the common event that the user has restarted the application package and killed all its processes.<br>**Since**: 12|
| static const char * const COMMON_EVENT_PACKAGE_DATA_CLEARED = "usual.event.PACKAGE_DATA_CLEARED" | Indicates the common event that the user cleared the application package data.<br>**Since**: 12|
| static const char * const COMMON_EVENT_PACKAGE_CACHE_CLEARED = "usual.event.PACKAGE_CACHE_CLEARED" | Indicates the common event that the user has cleared the application package data cache.<br>**Since**: 12|
| static const char * const COMMON_EVENT_PACKAGES_SUSPENDED = "usual.event.PACKAGES_SUSPENDED" | Indicates the common event that application packages have been suspended.<br>**Since**: 12|
| static const char * const COMMON_EVENT_MY_PACKAGE_SUSPENDED = "usual.event.MY_PACKAGE_SUSPENDED" | Indicates the common event that application packages are suspended.<br>**Since**: 12|
| static const char * const COMMON_EVENT_MY_PACKAGE_UNSUSPENDED = "usual.event.MY_PACKAGE_UNSUSPENDED" | Indicates the common event that application packages have not been suspended.<br>**Since**: 12|
| static const char * const COMMON_EVENT_LOCALE_CHANGED = "usual.event.LOCALE_CHANGED" | Indicates the common event that the device locale has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_MANAGE_PACKAGE_STORAGE = "usual.event.MANAGE_PACKAGE_STORAGE" | Indicates the common event that the device storage is insufficient.<br>**Since**: 12|
| static const char * const COMMON_EVENT_USER_UNLOCKED = "usual.event.USER_UNLOCKED" | Indicates the common event that the credential-encrypted storage has been unlocked for the current user when the device is unlocked upon restart.<br>**Since**: 12|
| static const char * const COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT = "common.event.DISTRIBUTED_ACCOUNT_LOGOUT" | Indicates the common event that a distributed account is successfully logged out.<br>**Since**: 12|
| static const char * const COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID = "common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID" | Indicates the common event that the token of a distributed account is invalid.<br>**Since**: 12|
| static const char * const COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF = "common.event.DISTRIBUTED_ACCOUNT_LOGOFF" | Indicates the common event that a distributed account is deregistered.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_POWER_STATE = "usual.event.wifi.POWER_STATE" | Indicates the common event that the Wi-Fi state has changed to a new state, such as enabled or disabled.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_SCAN_FINISHED = "usual.event.wifi.SCAN_FINISHED" | Indicates the common event that the Wi-Fi access point has been scanned and proven to be available.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_RSSI_VALUE = "usual.event.wifi.RSSI_VALUE" | Indicates the common event that the Wi-Fi signal strength (RSSI) has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_CONN_STATE = "usual.event.wifi.CONN_STATE" | Indicates the common event that the Wi-Fi connection state has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_HOTSPOT_STATE = "usual.event.wifi.HOTSPOT_STATE" | Indicates the common event that the Wi-Fi hotspot state has changed to a new state, such as enabled or disabled.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_AP_STA_JOIN = "usual.event.wifi.WIFI_HS_STA_JOIN" | Indicates the common event that a client has joined the Wi-Fi hotspot of the current device.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_AP_STA_LEAVE = "usual.event.wifi.WIFI_HS_STA_LEAVE" | Indicates the common event that a client has disconnected from the Wi-Fi hotspot of the current device.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE = "usual.event.wifi.mplink.STATE_CHANGE" | Indicates the common event that the state of MPLINK (an enhanced Wi-Fi feature) has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_P2P_CONN_STATE = "usual.event.wifi.p2p.CONN_STATE_CHANGE" | Indicates the common event that the Wi-Fi P2P connection state has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_P2P_STATE_CHANGED = "usual.event.wifi.p2p.STATE_CHANGE" | Indicates the common event that the Wi-Fi P2P state has changed, such as to enabled or disabled.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED = "usual.event.wifi.p2p.DEVICES_CHANGE" | Indicates the common event that the state of the Wi-Fi P2P peer device has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED = "usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE" | Indicates the common event that the Wi-Fi P2P discovery state has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED = "usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE" | Indicates the common event that the state of the Wi-Fi P2P local device has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED = "usual.event.wifi.p2p.GROUP_STATE_CHANGED" | Indicates the common event that the Wi-Fi P2P group information has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED = "usual.event.nfc.action.ADAPTER_STATE_CHANGED" | Indicates the common event that the state of the device NFC adapter has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED = "usual.event.nfc.action.RF_FIELD_ON_DETECTED" | Indicates the common event that the NFC RF field is on.<br>**Since**: 12|
| static const char * const COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED = "usual.event.nfc.action.RF_FIELD_OFF_DETECTED" | Indicates the common event that the NFC RF field is off.<br>**Since**: 12|
| static const char * const COMMON_EVENT_DISCHARGING = "usual.event.DISCHARGING" | Indicates the common event that the system stops charging the battery.<br>**Since**: 12|
| static const char * const COMMON_EVENT_CHARGING = "usual.event.CHARGING" | Indicates the common event that the system starts charging the battery.<br>**Since**: 12|
| static const char * const COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED = "usual.event.DEVICE_IDLE_MODE_CHANGED" | Indicates the common event that the system standby mode has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED = "usual.event.CHARGE_IDLE_MODE_CHANGED" | Indicates the common event that the device enters the charging idle mode.<br>**Since**: 12|
| static const char * const COMMON_EVENT_POWER_SAVE_MODE_CHANGED = "usual.event.POWER_SAVE_MODE_CHANGED" | Indicates the common event that the system power saving mode is changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_USB_STATE = "usual.event.hardware.usb.action.USB_STATE" | Indicates the common event that the USB device state has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_USB_PORT_CHANGED = "usual.event.hardware.usb.action.USB_PORT_CHANGED" | Indicates the common event that the USB port state of the user device has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_USB_DEVICE_ATTACHED = "usual.event.hardware.usb.action.USB_DEVICE_ATTACHED" | Indicates the common event that a USB device has been attached when the user device functions as a USB host.<br>**Since**: 12|
| static const char * const COMMON_EVENT_USB_DEVICE_DETACHED = "usual.event.hardware.usb.action.USB_DEVICE_DETACHED" | Indicates the common event that a USB device has been detached when the user device functions as a USB host.<br>**Since**: 12|
| static const char * const COMMON_EVENT_AIRPLANE_MODE_CHANGED = "usual.event.AIRPLANE_MODE" | Indicates the common event that the airplane mode of the device has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_SPLIT_SCREEN = "common.event.SPLIT_SCREEN" | Indicates the common event of screen splitting.<br>**Since**: 12|
| static const char * const COMMON_EVENT_QUICK_FIX_APPLY_RESULT = "usual.event.QUICK_FIX_APPLY_RESULT" | Indicates the common event that a quick fix is applied to an application.<br>**Since**: 12|
| static const char * const COMMON_EVENT_QUICK_FIX_REVOKE_RESULT = "usual.event.QUICK_FIX_REVOKE_RESULT" | Indicates the common event that a quick fix is revoked.<br>**Since**: 12|
| static const char * const COMMON_EVENT_USER_INFO_UPDATED = "usual.event.USER_INFO_UPDATED" | Indicates the common event that the user information has been updated.<br>**Since**: 12|
| static const char * const COMMON_EVENT_SIM_STATE_CHANGED = "usual.event.SIM_STATE_CHANGED" | Indicates the common event that the SIM card state has been updated.<br>**Since**: 12|
| static const char * const COMMON_EVENT_CALL_STATE_CHANGED = "usual.event.CALL_STATE_CHANGED" | Indicates the common event that the call state has been updated.<br>**Since**: 12|
| static const char * const COMMON_EVENT_NETWORK_STATE_CHANGED = "usual.event.NETWORK_STATE_CHANGED" | Indicates the common event that the network state has been updated.<br>**Since**: 12|
| static const char * const COMMON_EVENT_SIGNAL_INFO_CHANGED = "usual.event.SIGNAL_INFO_CHANGED" | Indicates the common event that the signal information has been updated.<br>**Since**: 12|
| static const char * const COMMON_EVENT_SCREEN_UNLOCKED = "usual.event.SCREEN_UNLOCKED" | Indicates the common event that the screen has been unlocked.<br>**Since**: 12|
| static const char * const COMMON_EVENT_SCREEN_LOCKED = "usual.event.SCREEN_LOCKED" | Indicates the common event that the screen has been locked.<br>**Since**: 12|
| static const char * const COMMON_EVENT_HTTP_PROXY_CHANGE = "usual.event.HTTP_PROXY_CHANGE" | Indicates the common event that the HTTP proxy configuration has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_CONNECTIVITY_CHANGE = "usual.event.CONNECTIVITY_CHANGE" | Indicates the common event that the network connection state has changed.<br>**Since**: 12|
| static const char * const COMMON_EVENT_MINORSMODE_ON = "usual.event.MINORSMODE_ON" | Indicates that the minor mode is enabled.<br>**Since**: 12|
| static const char * const COMMON_EVENT_MINORSMODE_OFF = "usual.event.MINORSMODE_OFF" | Indicates the common event that the minor mode is disabled.<br>**Since**: 12|
| static const char * const COMMON_EVENT_MANAGED_BROWSER_POLICY_CHANGED = "usual.event.MANAGED_BROWSER_POLICY_CHANGED" | Indicates that the browser hosting policy has been changed.<br>**Since**: 15|
