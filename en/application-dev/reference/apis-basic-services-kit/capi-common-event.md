# CommonEvent


## Overview

Describes the common event capabilities provided by the **CommonEvent** for applications.

**System capability**: SystemCapability.Notification.CommonEvent

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_commonevent.h](oh_commonevent_8h.md) | Defines the APIs for subscribing to and unsubscribing from common events.<br>**File to include**: <BasicServicesKit/oh_commonevent.h><br>**Library**: libohcommonevent.so|
| [oh_commonevent_support.h](oh_commonevent_support_8h.md) | Provides common event constants defined by the system.<br>**File to include**: <BasicServicesKit/oh_commonevent_support.h><br>**Library**: libohcommonevent.so|


### Types

| Name| Description|
| -------- | -------- |
|[CommonEvent_SubscribeInfo](#commonevent_subscribeinfo) | Defines the subscriber information.|
|[CommonEvent_Subscriber](#commonevent_subscriber) | Defines a subscriber.|
|[CommonEvent_RcvData](#commonevent_rcvdata) | Defines the callback data of a common event.|
|[CommonEvent_Parameters](#commonevent_parameters) | Defines the additional information about a common event.|
|[CommonEvent_ReceiveCallback](#commonevent_receivecallback)| Defines the callback function of a common event.|

### Enums

| Name| Description|
| -------- | -------- |
| [CommonEvent_ErrCode](#commonevent_errcode) | Enumerates the error codes.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_CommonEvent_CreateSubscribeInfo](#oh_commonevent_createsubscribeinfo)| Creates the subscriber information.|
| [OH_CommonEvent_SetPublisherPermission](#oh_commonevent_setpublisherpermission) | Sets the subscriber permission.|
| [OH_CommonEvent_SetPublisherBundleName](#oh_commonevent_setpublisherbundlename) | Sets a bundle name of the subscriber.|
| [OH_CommonEvent_DestroySubscribeInfo](#oh_commonevent_destroysubscribeinfo) | Destroys the subscriber information.|
| [OH_CommonEvent_CreateSubscriber](#oh_commonevent_createsubscriber)| Creates a subscriber.|
| [OH_CommonEvent_DestroySubscriber](#oh_commonevent_destroysubscriber) | Destroys a subscriber.|
| [OH_CommonEvent_Subscribe](#oh_commonevent_subscribe) | Subscribes to a common event.|
| [OH_CommonEvent_UnSubscribe](#oh_commonevent_unsubscribe) | Unsubscribes from a common event.|
| [OH_CommonEvent_GetEventFromRcvData](#oh_commonevent_geteventfromrcvdata)| Obtains the name of a common event.|
| [OH_CommonEvent_GetCodeFromRcvData](#oh_commonevent_getcodefromrcvdata) | Obtains the result code of a common event.|
| [OH_CommonEvent_GetDataStrFromRcvData](#oh_commonevent_getdatastrfromrcvdata)| Obtains the custom result data of a common event.|
| [OH_CommonEvent_GetBundleNameFromRcvData](#oh_commonevent_getbundlenamefromrcvdata)| Obtains the bundle name of a common event.|
| [OH_CommonEvent_GetParametersFromRcvData](#oh_commonevent_getparametersfromrcvdata) | Obtains the additional information about a common event.|
| [OH_CommonEvent_HasKeyInParameters](#oh_commonevent_haskeyinparameters) | Checks whether the additional information of a common event contains a key-value pair.|
| [OH_CommonEvent_GetIntFromParameters](#oh_commonevent_getintfromparameters) | Obtains the **int** data information from the additional information of a common event.|
| [OH_CommonEvent_GetIntArrayFromParameters](#oh_commonevent_getintarrayfromparameters)| Obtains the **int** array information from the additional information of a common event.|
| [OH_CommonEvent_GetLongFromParameters](#oh_commonevent_getlongfromparameters)| Obtains the **long** data information from the additional information of a common event.|
| [OH_CommonEvent_GetLongArrayFromParameters](#oh_commonevent_getlongarrayfromparameters)| Obtains the **long** array information from the additional information of a common event.|
| [OH_CommonEvent_GetBoolFromParameters](#oh_commonevent_getboolfromparameters)| Obtains the **bool** data information from the additional information of a common event.|
| [OH_CommonEvent_GetBoolArrayFromParameters](#oh_commonevent_getboolarrayfromparameters)| Obtains the **bool** array information from the additional information of a common event.|
| [OH_CommonEvent_GetCharFromParameters](#oh_commonevent_getcharfromparameters)| Obtains the **char** data from the additional information of a common event.|
| [OH_CommonEvent_GetCharArrayFromParameters](#oh_commonevent_getchararrayfromparameters)| Obtains the **char** array information from the additional information of a common event.|
| [OH_CommonEvent_GetDoubleFromParameters](#oh_commonevent_getdoublefromparameters)| Obtains the **double** data information from the additional information of a common event.|
| [OH_CommonEvent_GetDoubleArrayFromParameters](#oh_commonevent_getdoublearrayfromparameters)| Obtains the **double** array information from the additional information of a common event.|

### Constants
| Name| Description|
| -------- | -------- |
|static const char* const [COMMON_EVENT_SHUTDOWN](common_event/commonEventManager-definitions.md#common_event_shutdown) = "usual.event.SHUTDOWN" | Indicates the common event that the device is being shut down and the final shutdown will proceed.|
|static const char* const [COMMON_EVENT_BATTERY_CHANGED](common_event/commonEventManager-definitions.md#common_event_battery_changed) = "usual.event.BATTERY_CHANGED" | Indicates the common event that the charging state, level, and other information about the battery have changed.|
|static const char* const [COMMON_EVENT_BATTERY_LOW](common_event/commonEventManager-definitions.md#common_event_battery_low) = "usual.event.BATTERY_LOW"|Indicates the common event that the battery level is low.|
|static const char* const [COMMON_EVENT_BATTERY_OKAY](common_event/commonEventManager-definitions.md#common_event_battery_okay) = "usual.event.BATTERY_OKAY"|Indicates the common event that the battery exits the low state.|
|static const char* const [COMMON_EVENT_POWER_CONNECTED](common_event/commonEventManager-definitions.md#common_event_power_connected) = "usual.event.POWER_CONNECTED"|Indicates the common event that the device is connected to an external power supply.|
|static const char* const [COMMON_EVENT_POWER_DISCONNECTED](common_event/commonEventManager-definitions.md#common_event_power_disconnected) = "usual.event.POWER_DISCONNECTED"|Indicates the common event that the device is disconnected from the external power supply.|
|static const char* const [COMMON_EVENT_SCREEN_OFF](common_event/commonEventManager-definitions.md#common_event_screen_off) = "usual.event.SCREEN_OFF"| Indicates the common event that the device screen is off and the device is sleeping.|
|static const char* const [COMMON_EVENT_SCREEN_ON](common_event/commonEventManager-definitions.md#common_event_screen_on) = "usual.event.SCREEN_ON"|Indicates the common event that the device screen is on and the device is in interactive state.|
|static const char* const [COMMON_EVENT_THERMAL_LEVEL_CHANGED](common_event/commonEventManager-definitions.md#common_event_thermal_level_changed) = "usual.event.THERMAL_LEVEL_CHANGED"|Indicates the common event that the device's thermal level has changed.|
|static const char* const [COMMON_EVENT_TIME_TICK](common_event/commonEventManager-definitions.md#common_event_time_tick) = "usual.event.TIME_TICK"|Indicates the common event that the system time has changed.|
|static const char* const [COMMON_EVENT_TIME_CHANGED](common_event/commonEventManager-definitions.md#common_event_time_changed) = "usual.event.TIME_CHANGED"|Indicates the common event that the system time is reset.|
|static const char* const [COMMON_EVENT_TIMEZONE_CHANGED](common_event/commonEventManager-definitions.md#common_event_timezone_changed) = "usual.event.TIMEZONE_CHANGED"|Indicates the common event that the system time zone has changed.|
|static const char* const [COMMON_EVENT_PACKAGE_ADDED](common_event/commonEventManager-definitions.md#common_event_package_added) = "usual.event.PACKAGE_ADDED"| Indicates the common event that a new application package has been installed on the device.|
|static const char* const [COMMON_EVENT_PACKAGE_REMOVED](common_event/commonEventManager-definitions.md#common_event_package_removed) = "usual.event.PACKAGE_REMOVED"| Indicates the common event that an installed application has been uninstalled from the device with the application data retained.|
|static const char* const [COMMON_EVENT_BUNDLE_REMOVED](common_event/commonEventManager-definitions.md#common_event_bundle_removed) = "usual.event.BUNDLE_REMOVED"| Indicates the common event that an installed bundle has been uninstalled from the device with the application data retained.|
|static const char* const [COMMON_EVENT_PACKAGE_FULLY_REMOVED](common_event/commonEventManager-definitions.md#common_event_package_fully_removed) = "usual.event.PACKAGE_FULLY_REMOVED"|Indicates the common event that an installed application, including both the application data and code, has been completely uninstalled from the device.|
|static const char* const [COMMON_EVENT_PACKAGE_CHANGED](common_event/commonEventManager-definitions.md#common_event_package_changed) = "usual.event.PACKAGE_CHANGED"| Indicates the common event that an application package has been changed (for example, a component in the package has been enabled or disabled).|
|static const char* const [COMMON_EVENT_PACKAGE_RESTARTED](common_event/commonEventManager-definitions.md#common_event_package_restarted) = "usual.event.PACKAGE_RESTARTED"| Indicates a common event that a user restarts an application package and kills all its processes.|
|static const char* const [COMMON_EVENT_PACKAGE_DATA_CLEARED](common_event/commonEventManager-definitions.md#common_event_package_data_cleared) = "usual.event.PACKAGE_DATA_CLEARED"| Indicates the common event that the user has cleared the application package data.|
|static const char* const [COMMON_EVENT_PACKAGE_CACHE_CLEARED](common_event/commonEventManager-definitions.md#common_event_package_cache_cleared) = "usual.event.PACKAGE_CACHE_CLEARED"|Indicates the common event that the user has cleared the application package data cache.|
|static const char* const [COMMON_EVENT_PACKAGES_SUSPENDED](common_event/commonEventManager-definitions.md#common_event_packages_suspended) = "usual.event.PACKAGES_SUSPENDED"|Indicates the common event that application packages have been suspended.|
|static const char* const [COMMON_EVENT_MY_PACKAGE_SUSPENDED](common_event/commonEventManager-definitions.md#common_event_my_package_suspended) = "usual.event.MY_PACKAGE_SUSPENDED"| Indicates the common event that can be sent to a suspended application package.|
|static const char* const [COMMON_EVENT_MY_PACKAGE_UNSUSPENDED](common_event/commonEventManager-definitions.md#common_event_my_package_unsuspended) = "usual.event.MY_PACKAGE_UNSUSPENDED"| Indicates the common event that application packages have not been suspended.|
|static const char* const [COMMON_EVENT_LOCALE_CHANGED](common_event/commonEventManager-definitions.md#common_event_locale_changed) = "usual.event.LOCALE_CHANGED"| Indicates the common event that the device locale has changed.|
|static const char* const [COMMON_EVENT_MANAGE_PACKAGE_STORAGE](common_event/commonEventManager-definitions.md#common_event_manage_package_storage) = "usual.event.MANAGE_PACKAGE_STORAGE"| Indicates the common event that the device storage is insufficient.|
|static const char* const [COMMON_EVENT_USER_UNLOCKED](common_event/commonEventManager-definitions.md#common_event_user_unlocked) = "usual.event.USER_UNLOCKED"| Indicates the common event that the credential-encrypted storage has become unlocked for the current user when the device is unlocked after being restarted.|
|static const char* const [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT](common_event/commonEventManager-definitions.md#common_event_distributed_account_logout) = "common.event.DISTRIBUTED_ACCOUNT_LOGOUT"|Indicates the common event that a distributed account is successfully logged out.|
|static const char* const [COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID](common_event/commonEventManager-definitions.md#common_event_distributed_account_token_invalid) = "common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID"|Indicates the common event that the token of a distributed account is invalid.|
|static const char* const [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF](common_event/commonEventManager-definitions.md#common_event_distributed_account_logoff) = "common.event.DISTRIBUTED_ACCOUNT_LOGOFF"| Indicates the common event that a distributed account is deregistered.|
|static const char* const [COMMON_EVENT_WIFI_POWER_STATE](common_event/commonEventManager-definitions.md#common_event_wifi_power_state) = "usual.event.wifi.POWER_STATE"| Indicates the common event that the Wi-Fi state has changed, for example, enabled or disabled.|
|static const char* const [COMMON_EVENT_WIFI_SCAN_FINISHED](common_event/commonEventManager-definitions.md#common_event_wifi_scan_finished) = "usual.event.wifi.SCAN_FINISHED"|Indicates the common event that the Wi-Fi access point has been scanned and proven to be available.|
|static const char* const [COMMON_EVENT_WIFI_RSSI_VALUE](common_event/commonEventManager-definitions.md#common_event_wifi_rssi_value) = "usual.event.wifi.RSSI_VALUE"|Indicates the common event that the Wi-Fi signal strength (RSSI) has changed.|
|static const char* const [COMMON_EVENT_WIFI_CONN_STATE](common_event/commonEventManager-definitions.md#common_event_wifi_conn_state) = "usual.event.wifi.CONN_STATE"| Indicates the common event that the Wi-Fi connection state has changed.|
|static const char* const [COMMON_EVENT_WIFI_HOTSPOT_STATE](common_event/commonEventManager-definitions.md#common_event_wifi_hotspot_state) = "usual.event.wifi.HOTSPOT_STATE"| Indicates the common event that the Wi-Fi hotspot state has changed, for example, enabled or disabled.|
|static const char* const [COMMON_EVENT_WIFI_AP_STA_JOIN](common_event/commonEventManager-definitions.md#common_event_wifi_ap_sta_join) = "usual.event.wifi.WIFI_HS_STA_JOIN"| Indicates the common event that a client has joined the Wi-Fi hotspot of the current device.|
|static const char* const [COMMON_EVENT_WIFI_AP_STA_LEAVE](common_event/commonEventManager-definitions.md#common_event_wifi_ap_sta_leave) = "usual.event.wifi.WIFI_HS_STA_LEAVE"|Indicates the common event that a client has disconnected from the Wi-Fi hotspot of the current device.|
|static const char* const [COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE](common_event/commonEventManager-definitions.md#common_event_wifi_mplink_state_change) = "usual.event.wifi.mplink.STATE_CHANGE"|Indicates the common event that the state of MPLINK (an enhanced Wi-Fi feature) has changed.|
|static const char* const [COMMON_EVENT_WIFI_P2P_CONN_STATE](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_conn_state) = "usual.event.wifi.p2p.CONN_STATE_CHANGE"|Indicates the common event that the Wi-Fi P2P connection state has changed.|
|static const char* const [COMMON_EVENT_WIFI_P2P_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_state_changed) = "usual.event.wifi.p2p.STATE_CHANGE"|Indicates the common event that the Wi-Fi P2P state has changed, for example, enabled or disabled.|
|static const char* const [COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_peers_state_changed) = "usual.event.wifi.p2p.DEVICES_CHANGE"|Indicates the common event that the state of the Wi-Fi P2P peer device has changed.|
|static const char* const [COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_peers_discovery_state_changed) = "usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE"|Indicates the common event that the Wi-Fi P2P discovery state has changed.|
|static const char* const [COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_current_device_state_changed) = "usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE"|Indicates the common event that the state of the Wi-Fi P2P local device has changed.|
|static const char* const [COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_group_state_changed) = "usual.event.wifi.p2p.GROUP_STATE_CHANGED"|Indicates the common event that the Wi-Fi P2P group information has changed.|
|static const char* const [COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_nfc_action_adapter_state_changed) = "usual.event.nfc.action.ADAPTER_STATE_CHANGED"| Indicates the common event that the state of the device NFC adapter has changed.|
|static const char* const [COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED](common_event/commonEventManager-definitions.md#common_event_nfc_action_rf_field_on_detected) = "usual.event.nfc.action.RF_FIELD_ON_DETECTED"|Indicates the common event that the NFC RF field is on.|
|static const char* const [COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED](common_event/commonEventManager-definitions.md#common_event_nfc_action_rf_field_off_detected) = "usual.event.nfc.action.RF_FIELD_OFF_DETECTED"|Indicates the common event that the NFC RF field is off.|
|static const char* const [COMMON_EVENT_DISCHARGING](common_event/commonEventManager-definitions.md#common_event_discharging) = "usual.event.DISCHARGING"| Indicates the common event that the system stops charging the battery.|
|static const char* const [COMMON_EVENT_CHARGING](common_event/commonEventManager-definitions.md#common_event_charging) = "usual.event.CHARGING"|Indicates a common event that the system starts charging the battery.|
|static const char* const [COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED](common_event/commonEventManager-definitions.md#common_event_device_idle_mode_changed) = "usual.event.DEVICE_IDLE_MODE_CHANGED"| Indicates the common event that the system standby mode has changed.|
|static const char* const [COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED](common_event/commonEventManager-definitions.md#common_event_charge_idle_mode_changed10) = "usual.event.CHARGE_IDLE_MODE_CHANGED"|Indicates the common event that the device enters the charging idle mode.|
|static const char* const [COMMON_EVENT_POWER_SAVE_MODE_CHANGED](common_event/commonEventManager-definitions.md#common_event_power_save_mode_changed) = "usual.event.POWER_SAVE_MODE_CHANGED"|Indicates the common event that the system power saving mode is changed.|
|static const char* const [COMMON_EVENT_USB_STATE](common_event/commonEventManager-definitions.md#common_event_usb_state) = "usual.event.hardware.usb.action.USB_STATE"|Indicates the common event that the USB device state has changed.|
|static const char* const [COMMON_EVENT_USB_PORT_CHANGED](common_event/commonEventManager-definitions.md#common_event_usb_port_changed) = "usual.event.hardware.usb.action.USB_PORT_CHANGED"|Indicates the common event that the USB port state of the user device has changed.|
|static const char* const [COMMON_EVENT_USB_DEVICE_ATTACHED](common_event/commonEventManager-definitions.md#common_event_usb_device_attached) = "usual.event.hardware.usb.action.USB_DEVICE_ATTACHED"|Indicates the common event that a USB device has been attached when the user device functions as a USB host.|
|static const char* const [COMMON_EVENT_USB_DEVICE_DETACHED](common_event/commonEventManager-definitions.md#common_event_usb_device_detached) = "usual.event.hardware.usb.action.USB_DEVICE_DETACHED"|Indicates the common event that a USB device has been detached when the user device functions as a USB host.|
|static const char* const [COMMON_EVENT_AIRPLANE_MODE_CHANGED](common_event/commonEventManager-definitions.md#common_event_airplane_mode_changed10) = "usual.event.AIRPLANE_MODE"| Indicates the common event that the airplane mode of the device has changed.|
|static const char* const [COMMON_EVENT_SPLIT_SCREEN](common_event/commonEventManager-definitions.md#common_event_split_screen) = "common.event.SPLIT_SCREEN"| Indicates the common event of screen splitting.|
|static const char* const [COMMON_EVENT_QUICK_FIX_APPLY_RESULT](common_event/commonEventManager-definitions.md#common_event_quick_fix_apply_result) = "usual.event.QUICK_FIX_APPLY_RESULT"| Indicates the common event that a quick fix is applied to an application.|
|static const char* const [COMMON_EVENT_QUICK_FIX_REVOKE_RESULT](common_event/commonEventManager-definitions.md#common_event_quick_fix_revoke_result10) = "usual.event.QUICK_FIX_REVOKE_RESULT"| Indicates the common event that a quick fix is canceled.|
|static const char* const [COMMON_EVENT_USER_INFO_UPDATED](common_event/commonEventManager-definitions.md#common_event_user_info_updated) = "usual.event.USER_INFO_UPDATED"| Indicates the common event that the user information has been updated.|
|static const char* const [COMMON_EVENT_SIM_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_sim_state_changed10) = "usual.event.SIM_STATE_CHANGED"|Indicates the common event that the SIM card state has been updated.|
|static const char* const [COMMON_EVENT_CALL_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_call_state_changed10) = "usual.event.CALL_STATE_CHANGED"| Indicates the common event that the call state has been updated.|
|static const char* const [COMMON_EVENT_NETWORK_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_network_state_changed10) = "usual.event.NETWORK_STATE_CHANGED"| Indicates the common event that the network state has been updated.|
|static const char* const [COMMON_EVENT_SIGNAL_INFO_CHANGED](common_event/commonEventManager-definitions.md#common_event_signal_info_changed10) = "usual.event.SIGNAL_INFO_CHANGED"|Indicates the common event that the signal information has been updated.|
|static const char* const [COMMON_EVENT_SCREEN_UNLOCKED](common_event/commonEventManager-definitions.md#common_event_screen_unlocked) = "usual.event.SCREEN_UNLOCKED"|Indicates the common event that the screen has been unlocked.|
|static const char* const [COMMON_EVENT_SCREEN_LOCKED](common_event/commonEventManager-definitions.md#common_event_screen_locked) = "usual.event.SCREEN_LOCKED"| Indicates the common event that the screen has been locked.|
|static const char* const [COMMON_EVENT_HTTP_PROXY_CHANGE](common_event/commonEventManager-definitions.md#common_event_http_proxy_change10) = "usual.event.HTTP_PROXY_CHANGE"| Indicates the common event that the HTTP proxy configuration has changed.|
|static const char* const [COMMON_EVENT_CONNECTIVITY_CHANGE](common_event/commonEventManager-definitions.md#common_event_connectivity_change10) = "usual.event.CONNECTIVITY_CHANGE"| Indicates the common event that the network connection state has changed.|
|static const char* const [COMMON_EVENT_MINORSMODE_ON](common_event/commonEventManager-definitions.md#common_event_minorsmode_on12) = "usual.event.MINORSMODE_ON"|Indicates the common event that the minor mode is enabled.|
|static const char* const [COMMON_EVENT_MINORSMODE_OFF](common_event/commonEventManager-definitions.md#common_event_minorsmode_off12) = "usual.event.MINORSMODE_OFF"| Indicates the common event that the minor mode is disabled.|
## Type Description

### CommonEvent_SubscribeInfo

```c
typedef struct CommonEvent_SubscribeInfo CommonEvent_SubscribeInfo
```

**Description**

Defines the subscriber information.

**Since**: 12

### CommonEvent_Subscriber

```c
typedef void CommonEvent_Subscriber
```

**Description**

Defines a subscriber.

**Since**: 12

### CommonEvent_RcvData

```c
typedef struct CommonEvent_RcvData CommonEvent_RcvData
```

**Description**

Defines the callback data of a common event.

**Since**: 12

### CommonEvent_Parameters

```c
typedef void CommonEvent_Parameters
```

**Description**

Defines the additional information about a common event.

**Since**: 12

### CommonEvent_ReceiveCallback

```c
typedef void (*CommonEvent_ReceiveCallback)(const CommonEvent_RcvData *data)
```

**Description**

Defines the callback function of a common event.

**Since**: 12


## Enum Description

### CommonEvent_ErrCode
**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| COMMONEVENT_ERR_OK = 0 |The operation is successful.|
| COMMONEVENT_ERR_PERMISSION_ERROR = 201 |Permission denied.|
| COMMONEVENT_ERR_INVALID_PARAMETER = 401 |Invalid parameter.|
| COMMONEVENT_ERR_SENDING_REQUEST_FAILED = 1500007 |Failed to send an IPC request.|
| COMMONEVENT_ERR_INIT_UNDONE = 1500008|The service is not initialized.|
| COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED = 1500010|The number of subscribers exceeds 200.|
| COMMONEVENT_ERR_ALLOC_MEMORY_FAILED = 1500011|The system failed to allocate memory.|

## Constant Description

### COMMON_EVENT_SHUTDOWN

```c
static const char* const COMMON_EVENT_SHUTDOWN = "usual.event.SHUTDOWN"
```

**Description**

Indicates the common event that the device is being shut down and the final shutdown will proceed.

**Since**: 12

### COMMON_EVENT_BATTERY_CHANGED

```c
static const char* const COMMON_EVENT_BATTERY_CHANGED = "usual.event.BATTERY_CHANGED"
```

**Description**

Indicates the common event that the charging state, level, and other information about the battery have changed.

**Since**: 12

### COMMON_EVENT_BATTERY_LOW

```c
static const char* const COMMON_EVENT_BATTERY_LOW = "usual.event.BATTERY_LOW"
```

**Description**

Indicates the common event that the battery level is low.

**Since**: 12

### COMMON_EVENT_BATTERY_OKAY

```c
static const char* const COMMON_EVENT_BATTERY_OKAY = "usual.event.BATTERY_OKAY"
```

**Description**

Indicates the common event that the battery exits the low state.

**Since**: 12

### COMMON_EVENT_POWER_CONNECTED

```c
static const char* const COMMON_EVENT_POWER_CONNECTED = "usual.event.POWER_CONNECTED"
```

**Description**

Indicates the common event that the device is connected to an external power supply.

**Since**: 12

### COMMON_EVENT_POWER_DISCONNECTED

```c
static const char* const COMMON_EVENT_POWER_DISCONNECTED = "usual.event.POWER_DISCONNECTED"
```

**Description**

Indicates the common event that the device is disconnected from the external power supply.

**Since**: 12

### COMMON_EVENT_SCREEN_OFF

```c
static const char* const COMMON_EVENT_SCREEN_OFF = "usual.event.SCREEN_OFF"
```

**Description**

Indicates the common event that the device screen is off and the device is sleeping.

**Since**: 12

### COMMON_EVENT_SCREEN_ON

```c
static const char* const COMMON_EVENT_SCREEN_ON = "usual.event.SCREEN_ON"
```

**Description**

Indicates the common event that the device screen is on and the device is in interactive state.

**Since**: 12

### COMMON_EVENT_THERMAL_LEVEL_CHANGED

```c
static const char* const COMMON_EVENT_THERMAL_LEVEL_CHANGED = "usual.event.THERMAL_LEVEL_CHANGED"
```

**Description**

Indicates the common event that the device's thermal level has changed.

**Since**: 12

### COMMON_EVENT_TIME_TICK

```c
static const char* const COMMON_EVENT_TIME_TICK = "usual.event.TIME_TICK"
```

**Description**

Indicates the common event that the system time has changed.

**Since**: 12

### COMMON_EVENT_TIME_CHANGED

```c
static const char* const COMMON_EVENT_TIME_CHANGED = "usual.event.TIME_CHANGED"
```

**Description**

Indicates the common event that the system time is reset.

**Since**: 12

### COMMON_EVENT_TIMEZONE_CHANGED

```c
static const char* const COMMON_EVENT_TIMEZONE_CHANGED = "usual.event.TIMEZONE_CHANGED"
```

**Description**

Indicates the common event that the system time zone has changed.

**Since**: 12

### COMMON_EVENT_PACKAGE_ADDED

```c
static const char* const COMMON_EVENT_PACKAGE_ADDED = "usual.event.PACKAGE_ADDED"
```

**Description**

Indicates the common event that a new application package has been installed on the device.

**Since**: 12

### COMMON_EVENT_PACKAGE_REMOVED

```c
static const char* const COMMON_EVENT_PACKAGE_REMOVED = "usual.event.PACKAGE_REMOVED"
```

**Description**

Indicates the common event that an installed application has been uninstalled from the device with the application data retained.

**Since**: 12

### COMMON_EVENT_BUNDLE_REMOVED

```c
static const char* const COMMON_EVENT_BUNDLE_REMOVED = "usual.event.BUNDLE_REMOVED"
```

**Description**

Indicates the common event that an installed bundle has been uninstalled from the device with the application data retained.

**Since**: 12

### COMMON_EVENT_PACKAGE_FULLY_REMOVED

```c
static const char* const COMMON_EVENT_PACKAGE_FULLY_REMOVED = "usual.event.PACKAGE_FULLY_REMOVED"
```

**Description**

Indicates the common event that an installed application, including both the application data and code, has been completely uninstalled from the device.

**Since**: 12

### COMMON_EVENT_PACKAGE_CHANGED

```c
static const char* const COMMON_EVENT_PACKAGE_CHANGED = "usual.event.PACKAGE_CHANGED"
```

**Description**

Indicates the common event that an application package has been changed (for example, a component in the package has been enabled or disabled).

**Since**: 12

### COMMON_EVENT_PACKAGE_RESTARTED

```c
static const char* const COMMON_EVENT_PACKAGE_RESTARTED = "usual.event.PACKAGE_RESTARTED"
```

**Description**

Indicates a common event that a user restarts an application package and kills all its processes.

**Since**: 12

### COMMON_EVENT_PACKAGE_DATA_CLEARED

```c
static const char* const COMMON_EVENT_PACKAGE_DATA_CLEARED = "usual.event.PACKAGE_DATA_CLEARED"
```

**Description**

Indicates the common event that the user has cleared the application package data.

**Since**: 12

### COMMON_EVENT_PACKAGE_CACHE_CLEARED

```c
static const char* const COMMON_EVENT_PACKAGE_CACHE_CLEARED = "usual.event.PACKAGE_CACHE_CLEARED"
```

**Description**

Indicates the common event that the user has cleared the application package data cache.

**Since**: 12

### COMMON_EVENT_PACKAGES_SUSPENDED

```c
static const char* const COMMON_EVENT_PACKAGES_SUSPENDED = "usual.event.PACKAGES_SUSPENDED"
```

**Description**

Indicates the common event that application packages have been suspended.

**Since**: 12

### COMMON_EVENT_MY_PACKAGE_SUSPENDED

```c
static const char* const COMMON_EVENT_MY_PACKAGE_SUSPENDED = "usual.event.MY_PACKAGE_SUSPENDED"
```

**Description**

Indicates the common event that can be sent to a suspended application package.

**Since**: 12

### COMMON_EVENT_MY_PACKAGE_UNSUSPENDED

```c
static const char* const COMMON_EVENT_MY_PACKAGE_UNSUSPENDED = "usual.event.MY_PACKAGE_UNSUSPENDED"
```

**Description**

Indicates the common event that application packages have not been suspended.

**Since**: 12

### COMMON_EVENT_LOCALE_CHANGED

```c
static const char* const COMMON_EVENT_LOCALE_CHANGED = "usual.event.LOCALE_CHANGED"
```

**Description**

Indicates the common event that the device locale has changed.

**Since**: 12

### COMMON_EVENT_MANAGE_PACKAGE_STORAGE

```c
static const char* const COMMON_EVENT_MANAGE_PACKAGE_STORAGE = "usual.event.MANAGE_PACKAGE_STORAGE"
```

**Description**

Indicates the common event that the device storage is insufficient.

**Since**: 12

### COMMON_EVENT_USER_UNLOCKED

```c
static const char* const COMMON_EVENT_USER_UNLOCKED = "usual.event.USER_UNLOCKED"
```

**Description**

Indicates the common event that the credential-encrypted storage has become unlocked for the current user when the device is unlocked after being restarted.

**Since**: 12

### COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT

```c
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT = "common.event.DISTRIBUTED_ACCOUNT_LOGOUT"
```

**Description**

Indicates the common event that a distributed account is successfully logged out.

**Since**: 12

### COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID

```c
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID = "common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID"
```

**Description**

Indicates the common event that the token of a distributed account is invalid.

**Since**: 12

### COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF

```c
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF = "common.event.DISTRIBUTED_ACCOUNT_LOGOFF"
```

**Description**

Indicates the common event that a distributed account is deregistered.

**Since**: 12

### COMMON_EVENT_WIFI_POWER_STATE

```c
static const char* const COMMON_EVENT_WIFI_POWER_STATE = "usual.event.wifi.POWER_STATE"
```

**Description**

Indicates the common event that the Wi-Fi state has changed, for example, enabled or disabled.

**Since**: 12

### COMMON_EVENT_WIFI_SCAN_FINISHED

```c
static const char* const COMMON_EVENT_WIFI_SCAN_FINISHED = "usual.event.wifi.SCAN_FINISHED"
```

**Description**

Indicates the common event that the Wi-Fi access point has been scanned and proven to be available.

**Since**: 12

### COMMON_EVENT_WIFI_RSSI_VALUE

```c
static const char* const COMMON_EVENT_WIFI_RSSI_VALUE = "usual.event.wifi.RSSI_VALUE"
```

**Description**

Indicates the common event that the Wi-Fi signal strength (RSSI) has changed.

**Since**: 12

### COMMON_EVENT_WIFI_CONN_STATE

```c
static const char* const COMMON_EVENT_WIFI_CONN_STATE = "usual.event.wifi.CONN_STATE"
```

**Description**

Indicates the common event that the Wi-Fi connection state has changed.

**Since**: 12

### COMMON_EVENT_WIFI_HOTSPOT_STATE

```c
static const char* const COMMON_EVENT_WIFI_HOTSPOT_STATE = "usual.event.wifi.HOTSPOT_STATE"
```

**Description**

Indicates a common event of the Wi-Fi hotspot state.

**Since**: 12

### COMMON_EVENT_WIFI_AP_STA_JOIN

```c
static const char* const COMMON_EVENT_WIFI_AP_STA_JOIN = "usual.event.wifi.WIFI_HS_STA_JOIN"
```

**Description**

Indicates the common event that a client has joined the Wi-Fi hotspot of the current device.

**Since**: 12

### COMMON_EVENT_WIFI_AP_STA_LEAVE

```c
static const char* const COMMON_EVENT_WIFI_AP_STA_LEAVE = "usual.event.wifi.WIFI_HS_STA_LEAVE"
```

**Description**

Indicates the common event that a client has disconnected from the Wi-Fi hotspot of the current device.

**Since**: 12

### COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE

```c
static const char* const COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE = "usual.event.wifi.mplink.STATE_CHANGE"
```

**Description**

Indicates the common event that the state of MPLINK (an enhanced Wi-Fi feature) has changed.

**Since**: 12

### COMMON_EVENT_WIFI_P2P_CONN_STATE

```c
static const char* const COMMON_EVENT_WIFI_P2P_CONN_STATE = "usual.event.wifi.p2p.CONN_STATE_CHANGE"
```

**Description**

Indicates the common event that the Wi-Fi P2P connection state has changed.

**Since**: 12

### COMMON_EVENT_WIFI_P2P_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_STATE_CHANGED = "usual.event.wifi.p2p.STATE_CHANGE"
```

**Description**

Indicates the common event that the Wi-Fi P2P state has changed, for example, enabled or disabled.

### COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED = "usual.event.wifi.p2p.DEVICES_CHANGE"
```

**Description**

Indicates the common event that the state of the Wi-Fi P2P peer device has changed.

**Since**: 12

### COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED = "usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE"
```

**Description**

Indicates the common event that the Wi-Fi P2P discovery state has changed.

**Since**: 12

### COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED = "usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE"
```

**Description**

Indicates the common event that the state of the Wi-Fi P2P local device has changed.

**Since**: 12

### COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED = "usual.event.wifi.p2p.GROUP_STATE_CHANGED"
```

**Description**

Indicates the common event that the Wi-Fi P2P group information has changed.

**Since**: 12

### COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED

```c
static const char* const COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED = "usual.event.nfc.action.ADAPTER_STATE_CHANGED"
```

**Description**

Indicates the common event that the state of the device NFC adapter has changed.

**Since**: 12

### COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED

```c
static const char* const COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED = "usual.event.nfc.action.RF_FIELD_ON_DETECTED"
```

**Description**

Indicates the common event that the NFC RF field is on.

**Since**: 12

### COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED

```c
static const char* const COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED = "usual.event.nfc.action.RF_FIELD_OFF_DETECTED"
```

**Description**

Indicates the common event that the NFC RF field is off.

**Since**: 12

### COMMON_EVENT_DISCHARGING

```c
static const char* const COMMON_EVENT_DISCHARGING = "usual.event.DISCHARGING"
```

**Description**

Indicates the common event that the system stops charging the battery.

**Since**: 12

### COMMON_EVENT_CHARGING

```c
static const char* const COMMON_EVENT_CHARGING = "usual.event.CHARGING"
```

**Description**

Indicates a common event that the system starts charging the battery.

### COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED

```c
static const char* const COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED = "usual.event.DEVICE_IDLE_MODE_CHANGED"
```

**Description**

Indicates the common event that the system standby mode has changed.

**Since**: 12

### COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED

```c
static const char* const COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED = "usual.event.CHARGE_IDLE_MODE_CHANGED"
```

**Description**

Indicates the common event that the device enters the charging idle mode.

**Since**: 12

### COMMON_EVENT_POWER_SAVE_MODE_CHANGED

```c
static const char* const COMMON_EVENT_POWER_SAVE_MODE_CHANGED = "usual.event.POWER_SAVE_MODE_CHANGED"
```

**Description**

Indicates the common event that the system power saving mode is changed.

**Since**: 12

### COMMON_EVENT_USB_STATE

```c
static const char* const COMMON_EVENT_USB_STATE = "usual.event.hardware.usb.action.USB_STATE"
```

**Description**

Indicates the common event that the USB device state has changed.

**Since**: 12

### COMMON_EVENT_USB_PORT_CHANGED

```c
static const char* const COMMON_EVENT_USB_PORT_CHANGED = "usual.event.hardware.usb.action.USB_PORT_CHANGED"
```

**Description**

Indicates the common event that the USB port state of the user device has changed.

**Since**: 12

### COMMON_EVENT_USB_DEVICE_ATTACHED

```c
static const char* const COMMON_EVENT_USB_DEVICE_ATTACHED = "usual.event.hardware.usb.action.USB_DEVICE_ATTACHED"
```

**Description**

Indicates the common event that a USB device has been attached when the user device functions as a USB host.

**Since**: 12

### COMMON_EVENT_USB_DEVICE_DETACHED

```c
static const char* const COMMON_EVENT_USB_DEVICE_DETACHED = "usual.event.hardware.usb.action.USB_DEVICE_DETACHED"
```

**Description**

Indicates the common event that a USB device has been detached when the user device functions as a USB host.

**Since**: 12

### COMMON_EVENT_AIRPLANE_MODE_CHANGED

```c
static const char* const COMMON_EVENT_AIRPLANE_MODE_CHANGED = "usual.event.AIRPLANE_MODE"
```

**Description**

Indicates the common event that the airplane mode of the device has changed.

**Since**: 12

### COMMON_EVENT_SPLIT_SCREEN

```c
static const char* const COMMON_EVENT_SPLIT_SCREEN = "common.event.SPLIT_SCREEN"
```

**Description**

Indicates the common event of screen splitting.

**Since**: 12

### COMMON_EVENT_QUICK_FIX_APPLY_RESULT

```c
static const char* const COMMON_EVENT_QUICK_FIX_APPLY_RESULT = "usual.event.QUICK_FIX_APPLY_RESULT"
```

**Description**

Indicates the common event that a quick fix is applied to an application.

**Since**: 12

### COMMON_EVENT_QUICK_FIX_REVOKE_RESULT

```c
static const char* const COMMON_EVENT_QUICK_FIX_REVOKE_RESULT = "usual.event.QUICK_FIX_REVOKE_RESULT"
```

**Description**

Indicates the common event that a quick fix is canceled.

**Since**: 12

### COMMON_EVENT_USER_INFO_UPDATED

```c
static const char* const COMMON_EVENT_USER_INFO_UPDATED = "usual.event.USER_INFO_UPDATED"
```

**Description**

Indicates the common event that the user information has been updated.

**Since**: 12

### COMMON_EVENT_SIM_STATE_CHANGED

```c
static const char* const COMMON_EVENT_SIM_STATE_CHANGED = "usual.event.SIM_STATE_CHANGED"
```

**Description**

Indicates the common event that the SIM card state has been updated.

**Since**: 12

### COMMON_EVENT_CALL_STATE_CHANGED

```c
static const char* const COMMON_EVENT_CALL_STATE_CHANGED = "usual.event.CALL_STATE_CHANGED"
```

**Description**

Indicates the common event that the call state has been updated.

**Since**: 12

### COMMON_EVENT_NETWORK_STATE_CHANGED

```c
static const char* const COMMON_EVENT_NETWORK_STATE_CHANGED = "usual.event.NETWORK_STATE_CHANGED"
```

**Description**

Indicates the common event that the network state has been updated.

**Since**: 12

### COMMON_EVENT_SIGNAL_INFO_CHANGED

```c
static const char* const COMMON_EVENT_SIGNAL_INFO_CHANGED = "usual.event.SIGNAL_INFO_CHANGED"
```

**Description**

Indicates the common event that the signal information has been updated.

**Since**: 12

### COMMON_EVENT_SCREEN_UNLOCKED

```c
static const char* const COMMON_EVENT_SCREEN_UNLOCKED = "usual.event.SCREEN_UNLOCKED"
```

**Description**

Indicates the common event that the screen has been unlocked.

**Since**: 12

### COMMON_EVENT_SCREEN_LOCKED

```c
static const char* const COMMON_EVENT_SCREEN_LOCKED = "usual.event.SCREEN_LOCKED"
```

**Description**

Indicates the common event that the screen has been locked.

**Since**: 12

### COMMON_EVENT_HTTP_PROXY_CHANGE

```c
static const char* const COMMON_EVENT_HTTP_PROXY_CHANGE = "usual.event.HTTP_PROXY_CHANGE"
```

**Description**

Indicates the common event that the HTTP proxy configuration has changed.

**Since**: 12

### COMMON_EVENT_CONNECTIVITY_CHANGE

```c
static const char* const COMMON_EVENT_CONNECTIVITY_CHANGE = "usual.event.CONNECTIVITY_CHANGE"
```

**Description**

Indicates the common event that the network connection state has changed.

**Since**: 12

### COMMON_EVENT_MINORSMODE_ON

```c
static const char* const COMMON_EVENT_MINORSMODE_ON = "usual.event.MINORSMODE_ON"
```

**Description**

Indicates that the minor mode is enabled.

**Since**: 12

### COMMON_EVENT_MINORSMODE_OFF

```c
static const char* const COMMON_EVENT_MINORSMODE_OFF = "usual.event.MINORSMODE_OFF"
```

**Description**

Indicates the common event that the minor mode is disabled.

**Since**: 12

## Function Description

### OH_CommonEvent_CreateSubscribeInfo

```cpp
CommonEvent_SubscribeInfo* OH_CommonEvent_CreateSubscribeInfo(const char* events[], int32_t eventsNum)
```

**Description**

Creates the subscriber information.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| events | Events you have subscribed to.|
| eventsNum | Number of events|

**Returns**

Returns the subscriber information.

### OH_CommonEvent_SetPublisherPermission

```cpp
CommonEvent_ErrCode OH_CommonEvent_SetPublisherPermission(CommonEvent_SubscribeInfo* info, const char* permission)
```

**Description**

Sets the subscriber permission.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Subscriber information.|
| permission | Name of the permission.|

**Returns**

Returns **COMMONEVENT_ERR_OK** if the operation is successful.<br>Returns **COMMONEVENT_ERR_INVALID_PARAMETER** if **info** is a null pointer.

### OH_CommonEvent_SetPublisherBundleName

```cpp
CommonEvent_ErrCode OH_CommonEvent_SetPublisherBundleName(CommonEvent_SubscribeInfo* info, const char* bundleName)
```

**Description**

Sets a bundle name of the subscriber.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Subscriber information.|
| bundleName | Bundle name.|

**Returns**

Returns **COMMONEVENT_ERR_OK** if the operation is successful.<br>Returns **COMMONEVENT_ERR_INVALID_PARAMETER** if **info** is a null pointer.

### OH_CommonEvent_DestroySubscribeInfo

```cpp
void OH_CommonEvent_DestroySubscribeInfo(CommonEvent_SubscribeInfo* info)
```

**Description**

Destroys the subscriber information.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Subscriber information.|

### OH_CommonEvent_CreateSubscriber

```cpp
CommonEvent_Subscriber* OH_CommonEvent_CreateSubscriber(const CommonEvent_SubscribeInfo* info, CommonEvent_ReceiveCallback callback)
```

**Description**

Creates a subscriber.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| info | Subscriber information.|
| callback | Event callback.|

**Returns**

Returns the subscriber.

### OH_CommonEvent_DestroySubscriber

```cpp
void OH_CommonEvent_DestroySubscriber(CommonEvent_Subscriber* subscriber)
```

**Description**

Destroys a subscriber.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| subscriber | Subscriber.|

### OH_CommonEvent_Subscribe

```cpp
CommonEvent_ErrCode OH_CommonEvent_Subscribe(const CommonEvent_Subscriber* subscriber)
```

**Description**

Subscribes to a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| subscriber | Subscriber.|

**Returns**

Returns **COMMONEVENT_ERR_OK** if the operation is successful.<br>Returns **COMMONEVENT_ERR_INVALID_PARAMETER** if the **subscriber** is a null parameter.<br>Returns **COMMONEVENT_ERR_SENDING_REQUEST_FAILED** if the IPC fails to be sent.<br>Returns **COMMONEVENT_ERR_INIT_UNDONE** if the common event service is not initialized.<br>Returns **COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED** if the number of subscribers in the current process exceeds 200.<br>Returns **COMMONEVENT_ERR_ALLOC_MEMORY_FAILED** if the system fails to allocate memory.

### OH_CommonEvent_UnSubscribe

```cpp
CommonEvent_ErrCode OH_CommonEvent_UnSubscribe(const CommonEvent_Subscriber* subscriber)
```

**Description**

Unsubscribes from a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| subscriber | Subscriber.|

**Returns**

Returns **COMMONEVENT_ERR_OK** if the operation is successful.<br>Returns **COMMONEVENT_ERR_INVALID_PARAMETER** if the **subscriber** is a null parameter.<br>Returns **COMMONEVENT_ERR_SENDING_REQUEST_FAILED** if the IPC fails to be sent.<br>Returns **COMMONEVENT_ERR_INIT_UNDONE** if the common event service is not initialized.

### OH_CommonEvent_GetEventFromRcvData

```cpp
const char* OH_CommonEvent_GetEventFromRcvData(const CommonEvent_RcvData* rcvData)
```

**Description**

Obtains the name of a callback common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| rcvData | Callback data of a common event.|

**Returns**

Returns the name of a common event.

### OH_CommonEvent_GetCodeFromRcvData

```cpp
int32_t OH_CommonEvent_GetCodeFromRcvData(const CommonEvent_RcvData* rcvData)
```

**Description**

Obtains the result code of the callback common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| rcvData | Callback data of a common event.|

**Returns**

Returns the result code of a common event. The default value is **0**.

### OH_CommonEvent_GetDataStrFromRcvData

```cpp
const char* OH_CommonEvent_GetDataStrFromRcvData(const CommonEvent_RcvData* rcvData)
```

**Description**

Obtains the custom result data of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| rcvData | Callback data of a common event.|

**Returns**

Returns the custom result data of a common event. The default value is **null**.

### OH_CommonEvent_GetBundleNameFromRcvData

```cpp
const char* OH_CommonEvent_GetBundleNameFromRcvData(const CommonEvent_RcvData* rcvData)
```

**Description**

Obtains the bundle name of a callback common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| rcvData | Callback data of a common event.|

**Returns**

Returns the bundle name of a common event. The default value is **null**.

### OH_CommonEvent_GetParametersFromRcvData

```cpp
const CommonEvent_Parameters* OH_CommonEvent_GetParametersFromRcvData(const CommonEvent_RcvData* rcvData)
```

**Description**

Obtains the additional information about a callback common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| rcvData | Callback data of a common event.|

**Returns**

Returns the additional information about a common event. The default value is **null**.

### OH_CommonEvent_HasKeyInParameters

```cpp
bool OH_CommonEvent_HasKeyInParameters(const CommonEvent_Parameters* para, const char* key)
```

**Description**

Checks whether the additional information of a common event contains a key-value pair.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|

**Returns**

Returns **true** if the key-value pair exists; returns **false** otherwise.

### OH_CommonEvent_GetIntFromParameters

```cpp
int OH_CommonEvent_GetIntFromParameters(const CommonEvent_Parameters* para, const char* key, const int defaultValue)
```

**Description**

Obtains the **int** data with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| defaultValue | Default value to be returned.|

### OH_CommonEvent_GetIntArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetIntArrayFromParameters(const CommonEvent_Parameters* para, const char* key, int** array)
```

**Description**

Obtains the **int** array with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| array | **Int** array to receive data.|

**Returns**

Returns the length of an array.

### OH_CommonEvent_GetLongFromParameters

```cpp
long OH_CommonEvent_GetLongFromParameters(const CommonEvent_Parameters* para, const char* key, const long defaultValue)
```

**Description**

Obtains the **long** data with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| defaultValue | Default value to be returned.|

### OH_CommonEvent_GetLongArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetLongArrayFromParameters(const CommonEvent_Parameters* para, const char* key, long** array)
```

**Description**

Obtains the **long** array with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| array | **long** array to receive data.|

**Returns**

Returns the length of an array.

### OH_CommonEvent_GetBoolFromParameters

```cpp
bool OH_CommonEvent_GetBoolFromParameters(const CommonEvent_Parameters* para, const char* key, const bool defaultValue)
```

**Description**

Obtains the **bool** data with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| defaultValue | Default value to be returned.|

### OH_CommonEvent_GetBoolArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetBoolArrayFromParameters(const CommonEvent_Parameters* para, const char* key, bool** array)
```

**Description**

Obtains the **bool** array with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| array | **long** array to receive data.|

**Returns**

Returns the length of an array.

### OH_CommonEvent_GetCharFromParameters

```cpp
char OH_CommonEvent_GetCharFromParameters(const CommonEvent_Parameters* para, const char* key, const char defaultValue)
```

**Description**

Obtains the **char** data with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| defaultValue | Default value to be returned.|

### OH_CommonEvent_GetCharArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetCharArrayFromParameters(const CommonEvent_Parameters* para, const char* key, char** array)
```

**Description**

Obtains the **char** array with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| array | **char** array to receive data.|

**Returns**

Returns the length of an array.

### OH_CommonEvent_GetDoubleFromParameters

```cpp
double OH_CommonEvent_GetDoubleFromParameters(const CommonEvent_Parameters* para, const char* key, const double defaultValue)
```

**Description**

Obtains the **double** data with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| defaultValue | Default value to be returned.|

### OH_CommonEvent_GetDoubleArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetDoubleArrayFromParameters(const CommonEvent_Parameters* para, const char* key, double** array)
```

**Description**

Obtains the **double** array with a specific key from the additional information of a common event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| para | Additional information about a common event.|
| key | Key.|
| array | **char** array to receive data.|

**Returns**

Returns the length of an array. The default value is **0**.
