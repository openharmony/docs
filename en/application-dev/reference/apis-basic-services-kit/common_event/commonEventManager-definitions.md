# System Common Events

This document provides a list of common events defined by the system.
Common event types are defined in [Support](https://gitee.com/hu-zhishan/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-commonEventManager.md#support) of the **ohos.commonEventManager** module.

## Ability Kit


### COMMON_EVENT_PACKAGE_RESTARTED

Indicates that the user has restarted the application package and killed all its processes.

When the specified user restarts the application and kills all its processes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_RESTARTED"

### COMMON_EVENT_PACKAGE_DATA_CLEARED

Indicates the common event that the user has cleared the application package data.

When the specified user clears the application package data on the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_DATA_CLEARED"


### COMMON_EVENT_QUICK_FIX_APPLY_RESULT

Indicates the result of applying a quick fix to the application.

When the specified user applies a quick fix to the application on the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.QUICK_FIX_APPLY_RESULT"

### COMMON_EVENT_QUICK_FIX_REVOKE_RESULT<sup>10+</sup>

Indicates the result of revoking a quick fix to the application.

When a quick fix to the application is revoked on the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.QUICK_FIX_REVOKE_RESULT"

### COMMON_EVENT_PACKAGE_ADDED

Indicates that a new application package has been installed on the device.

When a new application is installed by a specified user on the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_ADDED"


### COMMON_EVENT_PACKAGE_REMOVED

Indicates the common event that an installed application has been uninstalled from the device with the application data retained.

When a specified application package is removed by a specified user on the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_REMOVED"


### COMMON_EVENT_BUNDLE_REMOVED

Indicates the common event that an installed bundle has been uninstalled from the device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.BUNDLE_REMOVED"


### COMMON_EVENT_PACKAGE_FULLY_REMOVED

Indicates the common event that an installed application has been completely uninstalled from the device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_FULLY_REMOVED"


### COMMON_EVENT_PACKAGE_CHANGED

Indicates that an application package has been changed (for example, an ability in the package has been enabled or disabled).

When an application package installed on the device is updated or an ability in the package is enabled or disabled, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_CHANGED"


### COMMON_EVENT_PACKAGE_CACHE_CLEARED

Indicates that the user cleared the application package cache.

When the cache of an application package installed on the device is cleared, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_CACHE_CLEARED"


### COMMON_EVENT_PACKAGES_SUSPENDED

Indicates the common event that application packages have been suspended.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGES_SUSPENDED"



### COMMON_EVENT_MY_PACKAGE_SUSPENDED

Sent to a package that has been suspended by the system.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.MY_PACKAGE_SUSPENDED"


### COMMON_EVENT_MY_PACKAGE_UNSUSPENDED

Sent to a package that has been unsuspended by the system.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.MY_PACKAGE_UNSUSPENDED"

### COMMON_EVENT_MANAGE_PACKAGE_STORAGE

Notifies the low memory state and package management should be started.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.MANAGE_PACKAGE_STORAGE"



## Account Kit

### COMMON_EVENT_MINORSMODE_ON<sup>12+</sup>

Indicates that the minor mode is enabled.

When the minor mode is enabled on the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Atomic service API**: This API can be used in atomic services since API version 12.

**Value**: "usual.event.MINORSMODE_ON"

### COMMON_EVENT_MINORSMODE_OFF<sup>12+</sup>

Indicates that the minor mode is disabled.

When the minor mode is disabled on the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Atomic service API**: This API can be used in atomic services since API version 12.

**Value**: "usual.event.MINORSMODE_OFF"



## ArkUI

### COMMON_EVENT_SPLIT_SCREEN

Indicates a screen splitting action.

When any of the following actions is performed, the event notification service is triggered to publish this event: accessing the recent tasks screen, creating a split-screen bar, and destroying a split-screen bar.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.RECEIVER_SPLIT_SCREEN

**Atomic service API**: This API can be used in atomic services since API version 11.

**Value**: usual.event.SPLIT_SCREEN"



## Notification Kit

### COMMON_EVENT_SLOT_CHANGE

  Indicates that the notification slot or notification switch settings have changed.

  When the notification slot settings (including the switch) change or the notification feature is enabled or disabled, the notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions:** ohos.permission.NOTIFICATION_CONTROLLER

**System capability**: SystemCapability.Notification.CommonEvent

**Value**: "usual.event.SLOT_CHANGE"




## Background Tasks Kit


### COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED
Indicates that the system idle mode has changed.

When the user does not use the device for the specified period of time and the screen is turned off, the system delays the CPU and network access by background applications, and the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.DEVICE_IDLE_MODE_CHANGED"




## Basic Services Kit

### COMMON_EVENT_USB_STATE

Indicates that the USB device state has changed.

When a USB device is connected to or disconnected from the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.hardware.usb.action.USB_STATE"


### COMMON_EVENT_USB_PORT_CHANGED

Indicates that the USB port state of the device has changed.

When the USB port state changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.hardware.usb.action.USB_PORT_CHANGED"


### COMMON_EVENT_USB_DEVICE_ATTACHED

Indicates that a USB device has been attached to the device functioning as a USB host.

When a USB device is attached, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.hardware.usb.action.USB_DEVICE_ATTACHED"


### COMMON_EVENT_USB_DEVICE_DETACHED

Indicates that a USB device has been detached from the device functioning as a USB host.

When a USB device is detached, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.hardware.usb.action.USB_DEVICE_DETACHED"


### COMMON_EVENT_TIME_CHANGED

Indicates the common event that the system time is set.

When the system time is set, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.TIME_CHANGED"


### COMMON_EVENT_TIME_TICK

Indicates the common event that the system time has changed.

When the system time in the unit of minute changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.TIME_TICK"


### COMMON_EVENT_TIMEZONE_CHANGED

Indicates the common event that the system time zone has changed.

When the system time zone changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.TIMEZONE_CHANGED"

### COMMON_EVENT_USER_INFO_UPDATED

Indicates that the user information has been updated.

When the distributed account information, system account profile picture, or system account name is changed, the event notification service is triggered to publish this event carrying the system account ID.

APIs related to this event: **setOsAccountName**, **setOsAccountProfilePhoto**, and **setOsAccountDistributedInfon**. The first two are system APIs, and the last is a public API. For details, see [@ohos.account.osAccount (System Account Management)](https://gitee.com/hu-zhishan/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-osAccount.md) and [@ohos.account.distributedAccount (Distributed Account Management)](https://gitee.com/hu-zhishan/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-distributed-account.md).

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**System capability**: SystemCapability.Notification.CommonEvent

**Value**: "usual.event.USER_INFO_UPDATED"


### COMMON_EVENT_USER_UNLOCKED

Indicates that the credential-encrypted storage has been unlocked for the current user after the device is restarted.

When the device is unlocked with the lock screen password the first time after user switching, the event notification service is triggered to publish this event carrying the system account ID that identifies the user.

APIs related to this event: **auth**. This API is a system API. For details, see [@ohos.account.osAccount (System Account Management)](https://gitee.com/hu-zhishan/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-osAccount.md).

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**System capability**: SystemCapability.Notification.CommonEvent

**Value**: "usual.event.USER_UNLOCKED"


### COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN

Indicates a successful login from a distributed account.

When a distributed account is successfully logged in, the event notification service is triggered to publish this event carrying the system account ID.

APIs related to this event: **setOsAccountDistributedInfo** and **updateOsAccountDistributedInfo** (discarded), and **setOsAccountDistributedInfoByLocalId**. The first two are public APIs, and the last one is a system API. For details, see [@ohos.account.distributedAccount (Distributed Account Management)](https://gitee.com/hu-zhishan/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-distributed-account.md).

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Atomic service API**: This API can be used in atomic services since API version 12.

**Value**: "common.event.DISTRIBUTED_ACCOUNT_LOGIN"


### COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT

Indicates a successful logout from a distributed account.

When a distributed account is successfully logged out, the event notification service is triggered to publish this event carrying the system account ID.

APIs related to this event: **setOsAccountDistributedInfo** and **updateOsAccountDistributedInfo** (discarded), and **setOsAccountDistributedInfoByLocalId**. The first two are public APIs, and the last one is a system API. For details, see [@ohos.account.distributedAccount (Distributed Account Management)](https://gitee.com/hu-zhishan/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-distributed-account.md).

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Atomic service API**: This API can be used in atomic services since API version 12.

**Value**: "common.event.DISTRIBUTED_ACCOUNT_LOGOUT"


### COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID

Indicates that the token of a distributed account is invalid.

When the token of a distributed account is invalid, the event notification service is triggered to publish this event carrying the system account ID.

APIs related to this event: **setOsAccountDistributedInfo** and **updateOsAccountDistributedInfo** (discarded), and **setOsAccountDistributedInfoByLocalId**. The first two are public APIs, and the last one is a system API. For details, see [@ohos.account.distributedAccount (Distributed Account Management)](https://gitee.com/hu-zhishan/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-distributed-account.md).

**Required subscriber permissions**: none

**System capability**: SystemCapability.Notification.CommonEvent

**Atomic service API**: This API can be used in atomic services since API version 12.

**Value**: "common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID"

### COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF

Indicates that a distributed account is deregistered.

When a distributed account is deregistered, the event notification service is triggered to publish this event carrying the system account ID.

APIs related to this event: **setOsAccountDistributedInfo** and **updateOsAccountDistributedInfo** (discarded), and **setOsAccountDistributedInfoByLocalId**. The first two are public APIs, and the last one is a system API. For details, see [@ohos.account.distributedAccount (Distributed Account Management)](https://gitee.com/hu-zhishan/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-distributed-account.md).

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Atomic service API**: This API can be used in atomic services since API version 12.

**Value**: "common.event.DISTRIBUTED_ACCOUNT_LOGOFF"

### COMMON_EVENT_SCREEN_LOCKED

Indicates that the screen has been locked.
When the screen is locked, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Atomic service API**: This API can be used in atomic services since API version 11.

**Value**: usual.event.SCREEN_LOCKED

### COMMON_EVENT_SCREEN_UNLOCKED

Indicates that the screen has been unlocked.
When the screen is unlocked, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Atomic service API**: This API can be used in atomic services since API version 11.

**Value**: usual.event.SCREEN_UNLOCKED


### COMMON_EVENT_USER_PRESENT<sup>(deprecated)</sup>
Indicates the action of a common event that the user unlocks the device.

  > Notes:
  >
  > This API is deprecated since API Version 10 and replaced by [COMMON_EVENT_SCREEN_UNLOCKED](#common_event_screen_unlocked).

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: usual.event.USER_PRESENT


### COMMON_EVENT_BATTERY_CHANGED

Indicates that the charging state, level, and other information about the battery have changed.

When any of the following information changes, the event notification service is triggered to publish this event: battery level, battery voltage, battery temperature, battery health status, type of the charger connected to the device, maximum current of the charger, maximum voltage of the charger, battery charging status, number of charging times, total battery capacity, remaining battery capacity, battery model, current of the battery, and battery charging type.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.BATTERY_CHANGED"


### COMMON_EVENT_BATTERY_LOW

Indicates that the battery level is low.

When the battery level drops to lower than the low battery level set for the device, the event notification service is triggered to publish this event. <!--Del-->For details about how to set the low battery level percentage, see [Battery Level Customization](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-power-battery-level-customization.md).<!--DelEnd-->

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.BATTERY_LOW"


### COMMON_EVENT_BATTERY_OKAY

Indicates that the battery level is normal.

When the battery level changes from the low level to normal level, the event notification service is triggered to publish this event.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.BATTERY_OKAY"


### COMMON_EVENT_POWER_CONNECTED

Indicates that the device is connected to an external power supply.

When the device connects to an external charger, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.POWER_CONNECTED"


### COMMON_EVENT_POWER_DISCONNECTED

Indicates that the device is disconnected from the external power supply.

When the device is disconnected from the external power supply, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.POWER_DISCONNECTED"


### COMMON_EVENT_DISCHARGING

Indicates the common event that the system stops charging the battery.

When the system stops charging the battery, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.DISCHARGING"


### COMMON_EVENT_CHARGING

Indicates the common event that the system starts charging the battery.

When the system starts charging the battery, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.CHARGING"

### COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED<sup>10+</sup>

Indicates the common event that the device enters the charging idle mode.

When the device starts charging in idle mode, and the temperature rise is acceptable, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.CHARGE_IDLE_MODE_CHANGED"


### COMMON_EVENT_SHUTDOWN

Indicates the common event that the device is being shut down and the final shutdown will proceed.

When the device is being shut down until it is powered off, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.SHUTDOWN"


### COMMON_EVENT_SCREEN_OFF

Indicates the common event that a device screen-off initiated by the power service is complete.

When the device screen-off initiated by the power service is complete, the event notification service is triggered to release this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.SCREEN_OFF"


### COMMON_EVENT_SCREEN_ON

Indicates the common event that a device screen-on initiated by the power service is complete.

When the device screen-on initiated by the power service is complete, the event notification service is triggered to release this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.SCREEN_ON"


### COMMON_EVENT_POWER_SAVE_MODE_CHANGED

Indicates that the system power saving mode has changed.

When the system power saving mode changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.POWER_SAVE_MODE_CHANGED"


### COMMON_EVENT_THERMAL_LEVEL_CHANGED

Indicates that the device's thermal level has changed.

When the device's thermal level changes, the event notification service is triggered to publish this event. <!--Del-->For details about how to configure the device thermal level, see [Thermal Level Customization](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-thermal_level.md).<!--DelEnd-->

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.THERMAL_LEVEL_CHANGED"


### COMMON_EVENT_ENTER_FORCE_SLEEP<sup>12+</sup>

Indicates that the device is about to enter the forced sleep mode.

When the device is about to enter the forced sleep mode, the event notification service is triggered to publish this event. This event should be processed within one second.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.ENTER_FORCE_SLEEP"

### COMMON_EVENT_EXIT_FORCE_SLEEP<sup>12+</sup>

Indicates that the device exits the forced sleep mode.

When the device exits the forced sleep mode, the event notification service is triggered to publish this event.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.EXIT_FORCE_SLEEP"

### COMMON_EVENT_ENTER_HIBERNATE<sup>15+</sup>

Indicates that the device is about to enter the hibernation mode.

When the device is about to enter the hibernation mode, the event notification service is triggered to publish this event. This event should be processed within one second.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.ENTER_HIBERNATE"

### COMMON_EVENT_EXIT_HIBERNATE<sup>15+</sup>

Indicates that the device exits the hibernation mode.

When the device exits the hibernation mode, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.EXIT_HIBERNATE"




## Connectivity Kit


### COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED

Indicates that the state of the device NFC adapter has changed.

When the state of the device NFC adapter changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.nfc.action.ADAPTER_STATE_CHANGED"


### COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED

Indicates that the NFC RF field is on.

When the NFC RF field becomes available, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.nfc.action.RF_FIELD_ON_DETECTED"


### COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED

Indicates that the NFC RF field is off.

When the NFC RF field becomes unavailable, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.nfc.action.RF_FIELD_OFF_DETECTED"


### COMMON_EVENT_WIFI_POWER_STATE

Indicates that the Wi-Fi state changes.

When the Wi-Fi state changes (such as enabled or disabled), the event notification service is triggered to release the system public event.

State values: **0** indicates that the Wi-Fi is being disabled; **1** indicates that the Wi-Fi has been disabled; **2** indicates that the Wi-Fi is being enabled; **3** indicates that the Wi-Fi has been enabled.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.wifi.POWER_STATE"


### COMMON_EVENT_WIFI_SCAN_FINISHED

Indicates that a Wi-Fi access point is detected and proven to be available.

When a Wi-Fi access point is detected and proven to be available, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.LOCATION

**Value**: "usual.event.wifi.SCAN_FINISHED"


### COMMON_EVENT_WIFI_SCAN_STATE

Indicates that the Wi-Fi access point state has changed.

When the Wi-Fi access point state changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.LOCATION

**Value**: "usual.event.wifi.SCAN_STATE"

### COMMON_EVENT_WIFI_RSSI_VALUE

  Indicates that the Wi-Fi signal strength (RSSI) has changed.

  When the Wi-Fi signal strength (RSSI) changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO

**Value**: "usual.event.wifi.RSSI_VALUE"

### COMMON_EVENT_WIFI_CONN_STATE

  Indicates that the Wi-Fi connection state has changed.

  When the Wi-Fi connection state changes, the event notification service is triggered to publish this event.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.wifi.CONN_STATE"


### COMMON_EVENT_WIFI_HOTSPOT_STATE

Indicates that the Wi-Fi hotspot state has changed.

When the Wi-Fi hotspot state changes, the event notification service is triggered to publish this event.

State values: **2** indicates that the AP is being enabled, **3** indicates that the AP has been enabled; **4** indicates that the AP is being disabled; **5** indicates that the AP has been disabled.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.wifi.HOTSPOT_STATE"


### COMMON_EVENT_WIFI_AP_STA_JOIN

Indicates that a client has joined the Wi-Fi hotspot of the current device.

When a client joins the Wi-Fi hotspot of the current device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO

**Value**: "usual.event.wifi.WIFI_HS_STA_JOIN"


### COMMON_EVENT_WIFI_AP_STA_LEAVE

Indicates that the client is disconnected from the Wi-Fi hotspot of the current device.

When a client is disconnected from the Wi-Fi hotspot of the current device, the event notification service is triggered to publish this event.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO

**Value**: "usual.event.wifi.WIFI_HS_STA_LEAVE"


### COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE

Indicates that the state of MPLINK (an enhanced Wi-Fi feature) has changed.

When the state of MPLINK (an enhanced Wi-Fi feature) changes, the event notification service is triggered to publish this event.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.MPLINK_CHANGE_STATE

**Value**: "usual.event.wifi.mplink.STATE_CHANGE"


### COMMON_EVENT_WIFI_P2P_CONN_STATE

Indicates that the Wi-Fi P2P connection state has changed.

When the Wi-Fi P2P connection state changes, the event notification service is triggered to publish this event.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**Value**: "usual.event.wifi.p2p.CONN_STATE_CHANGE"


### COMMON_EVENT_WIFI_P2P_STATE_CHANGED

Indicates that the Wi-Fi P2P state has changed.

When the Wi-Fi P2P state changes, the event notification service is triggered to publish this event.

State values: **2** indicates that the P2P is being enabled, **3** indicates that the P2P has been enabled; **4** indicates that the P2P is being disabled; **5** indicates that the P2P has been disabled.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO

**Value**: "usual.event.wifi.p2p.STATE_CHANGE"


### COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED

Indicates that the state of the Wi-Fi P2P peer device has changed.

When the state of the Wi-Fi P2P peer device changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO

**Value:** "usual.event.wifi.p2p.DEVICES_CHANGE"


### COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED

Indicates that the Wi-Fi P2P discovery state has changed.

When the Wi-Fi P2P discovery state changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO

**Value**: "usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE"


### COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED

Indicates that the state of the Wi-Fi P2P local device has changed.

When the state of the Wi-Fi P2P local device changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO

**Value**: "usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE"


### COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED

Indicates that the Wi-Fi P2P group information has changed.

When the Wi-Fi P2P group information changes, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_WIFI_INFO

**Value**: "usual.event.wifi.p2p.GROUP_STATE_CHANGED"



## Localization Kit

### COMMON_EVENT_LOCALE_CHANGED

Indicates the common event that the system language is set.
When the system language is set, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: usual.event.LOCALE_CHANGED



## Network Kit

### COMMON_EVENT_CONNECTIVITY_CHANGE<sup>10+</sup>

Indicates that the network connection state has changed.

When the (Ethernet, Wi-Fi, or cellular) network connection state changes (to disconnected, connecting, or connected), the event notification service is triggered to publish this event.
The following table lists the enumerated values and their corresponding connection status.

| Value |  Connection State |
| ------ | ---------- |
|    2   |   Connecting.  |
|    3   |   Connected.  |
|    4   |   Disconnecting.|
|    5   |   Disconnected.  |

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Atomic service API**: This API can be used in atomic services since API version 11.

**Value**: usual.event.CONNECTIVITY_CHANGE


### COMMON_EVENT_AIRPLANE_MODE_CHANGED<sup>10+</sup>

Indicates that the airplane mode state has changed.

When the airplane mode is enabled or disabled, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: usual.event.AIRPLANE_MODE


### COMMON_EVENT_HTTP_PROXY_CHANGE<sup>10+</sup>

Indicates that the HTTP proxy configuration has changed.

When the configuration information of the system global proxy or HTTP proxy on various networks (such as Ethernet, Wi-Fi, and cellular networks) changes, the event notification service is triggered to release the system common event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: usual.event.HTTP_PROXY_CHANGE



## Telephony Kit

This document lists the common system events provided by the telephony subsystem to applications.

### COMMON_EVENT_SIM_STATE_CHANGED<sup>10+</sup>

Indicates that the SIM card status has changed.

When there is a change in the SIM card status of the device, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: usual.event.SIM_STATE_CHANGED

### COMMON_EVENT_CALL_STATE_CHANGED<sup>10+</sup>

Indicates that the call state has been updated.

When the call state of the device is updated, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_TELEPHONY_STATE (for system apps only)

**Value**: usual.event.CALL_STATE_CHANGED

### COMMON_EVENT_NETWORK_STATE_CHANGED<sup>10+</sup>

Indicates that the network state has been updated.

When the network state of the device is updated, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: usual.event.NETWORK_STATE_CHANGED


### COMMON_EVENT_SIGNAL_INFO_CHANGED<sup>10+</sup>

Indicates that the signal information has been updated.

When the signal information of the device is updated, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: usual.event.SIGNAL_INFO_CHANGED

**System capability**: SystemCapability.Notification.CommonEvent



## Store Kit
This document lists the common system events provided by the Store Kit to applications.

### COMMON_EVENT_PRIVACY_STATE_CHANGED<sup>11+</sup>
Indicates the privacy signature result.
When a user clicks **Agree** in a privacy dialog box, the event notification service is triggered to publish this event.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PRIVACY_STATE_CHANGED"



## Reserved Common Event

Below are reserved common events that are not supported yet.


### COMMON_EVENT_PACKAGE_FIRST_LAUNCH

(Reserved, not supported yet) Indicates an initial start of an application after installation.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_FIRST_LAUNCH"


### COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION

(Reserved, not supported yet) Indicates that a package is sent by the system verifier when the package needs verification.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_NEEDS_VERIFICATION"


### COMMON_EVENT_PACKAGE_VERIFIED

(Reserved, not supported yet) Indicates that a package is sent by the system verifier when the package is verified.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_VERIFIED"

### COMMON_EVENT_PACKAGE_REPLACED

(Reserved, not supported yet) Indicates the action of a common event that a new version of an installed application package has replaced the previous one on the device. Data contains the name of the package.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGE_REPLACED"


### COMMON_EVENT_MY_PACKAGE_REPLACED

(Reserved, not supported yet) Indicates the action of a common event that a new version of an installed application package has replaced the previous one on the device. This event does not contain additional data and is sent only to the replaced application.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.MY_PACKAGE_REPLACED"


### COMMON_EVENT_PACKAGES_UNSUSPENDED

(Reserved, not supported yet) Indicates that the package has been unsuspended.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.PACKAGES_UNSUSPENDED"


### COMMON_EVENT_CLOSE_SYSTEM_DIALOGS

(Reserved, not supported yet) Indicates the common event that a user closes a temporary system dialog box.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.CLOSE_SYSTEM_DIALOGS"

### COMMON_EVENT_UID_REMOVED

(Reserved, not supported yet) Indicates the common event that a user ID has been removed from the system.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.UID_REMOVED"


### COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE

(Reserved, not supported yet) Indicates the common event that applications installed on the external storage become available for the system.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.EXTERNAL_APPLICATIONS_AVAILABLE"


### COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE

(Reserved, not supported yet) Indicates the common event that applications installed on the external storage become unavailable for the system.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE"


### COMMON_EVENT_CONFIGURATION_CHANGED

(Reserved, not supported yet) Indicates the common event that the device state (for example, orientation and locale) has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.CONFIGURATION_CHANGED"

### COMMON_EVENT_DRIVE_MODE
(Reserved, not supported yet) Indicates the common event that the system is in driving mode.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.DRIVE_MODE"

### COMMON_EVENT_HOME_MODE
(Reserved, not supported yet) Indicates the common event that the system is in home mode.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.HOME_MODE"

### COMMON_EVENT_OFFICE_MODE
(Reserved, not supported yet) Indicates the common event that the system is in office mode.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.OFFICE_MODE"

### COMMON_EVENT_USER_STARTED

(Reserved, not supported yet) Indicates the common event that the user has been started.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.USER_STARTED"


### COMMON_EVENT_USER_BACKGROUND

(Reserved, not supported yet) Indicates the common event that the user has been brought to the background.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.USER_BACKGROUND"


### COMMON_EVENT_USER_STARTING
(Reserved, not supported yet) Indicates the common event that the user is going to be started.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (for system applications only)

**Value**: "usual.event.USER_STARTING"

### COMMON_EVENT_USER_STOPPING
(Reserved, not supported yet) Indicates the common event that the user is going to be stopped.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (for system applications only)

**Value**: "usual.event.USER_STOPPING"


### COMMON_EVENT_USER_STOPPED
(Reserved, not supported yet) Indicates the common event that the user has been stopped.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.USER_STOPPED"


### COMMON_EVENT_DISK_REMOVED

(Reserved, not supported yet) Indicates the common event that an external storage device was removed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.STORAGE_MANAGER (for system applications only)

**Value**: "usual.event.data.DISK_BAD_REMOVAL"


### COMMON_EVENT_DISK_UNMOUNTED

(Reserved, not supported yet) Indicates the common event that an external storage device was unmounted.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.STORAGE_MANAGER (for system applications only)

**Value**: "usual.event.data.DISK_UNMOUNTABLE"


### COMMON_EVENT_DISK_MOUNTED

(Reserved, not supported yet) Indicates the common event that an external storage device was mounted.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.STORAGE_MANAGER (for system applications only)

**Value**: "usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED"

### COMMON_EVENT_DISK_BAD_REMOVAL

(Reserved, not supported yet) Indicates the common event that an external storage device was removed without being unmounted.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.STORAGE_MANAGER (for system applications only)

**Value**: "usual.event.data.DISK_REMOVED"


### COMMON_EVENT_DISK_UNMOUNTABLE

(Reserved, not supported yet) Indicates the common event that an external storage device becomes unmountable.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.STORAGE_MANAGER (for system applications only)

**Value**: "usual.event.data.DISK_UNMOUNTED"


### COMMON_EVENT_DISK_EJECT

(Reserved, not supported yet) Indicates the common event that an external storage device was ejected.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.STORAGE_MANAGER (for system applications only)

**Value**: "usual.event.data.DISK_EJECT"


### COMMON_EVENT_DATE_CHANGED

(Reserved, not supported yet) Indicates the common event that the system time has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: usual.event.DATE_CHANGED

### COMMON_EVENT_USB_ACCESSORY_ATTACHED

(Reserved, not supported yet) Indicates that a USB accessory was attached.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED"


### COMMON_EVENT_USB_ACCESSORY_DETACHED

(Reserved, not supported yet) Indicates the common event that a USB accessory was detached.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.data.DISK_MOUNTED"

### COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event about the connection state of Bluetooth handsfree communication.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE"

### COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE
(Reserved, not supported yet) Indicates the common event that the device connected to the Bluetooth handsfree is active.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE"


### COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the connection state of Bluetooth A2DP has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE"


### COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event about the connection state of Bluetooth A2DP.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE"


### COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE
(Reserved, not supported yet) Indicates the common event that the device connected using Bluetooth A2DP is active.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE"

### COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the AVRCP connection state of Bluetooth A2DP has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE"

### COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the playing state of Bluetooth A2DP has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE"

### COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE
(Reserved, not supported yet) Indicates the common event that the audio codec state of Bluetooth A2DP has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE"


### COMMON_EVENT_USER_FOREGROUND

(Reserved, not supported yet) Indicates the common event that the user has been brought to the foreground.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.USER_FOREGROUND"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED
(Reserved, not supported yet) Indicates the common event that a remote Bluetooth device is discovered.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.remotedevice.DISCOVERED"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE
(Reserved, not supported yet) Indicates the common event that the Bluetooth class of a remote Bluetooth device has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED
(Reserved, not supported yet) Indicates the common event that a low-ACL connection has been established with a remote Bluetooth device.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.remotedevice.ACL_CONNECTED"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED
(Reserved, not supported yet) Indicates the common event that a low-ACL connection has been disconnected from a remote Bluetooth device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.remotedevice.ACL_DISCONNECTED"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE

(Reserved, not supported yet) Indicates the common event that the friendly name of a remote Bluetooth device is retrieved for the first time or has changed since the last retrieval.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.ACCESS_BLUETOOTH

**Value**: "usual.event.bluetooth.remotedevice.NAME_UPDATE"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE
(Reserved, not supported yet) Indicates the common event that the connection state of a remote Bluetooth device has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.remotedevice.PAIR_STATE"

### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE
(Reserved, not supported yet) Indicates the common event that the battery level of a remote Bluetooth device is retrieved for the first time or has changed since the last retrieval.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT
(Reserved, not supported yet) Indicates the common event about the SDP state of a remote Bluetooth device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.remotedevice.SDP_RESULT"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE
Indicates the action of a common event about the UUID connection state of a remote Bluetooth device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.ACCESS_BLUETOOTH

**Value**: "usual.event.bluetooth.remotedevice.UUID_VALUE"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ
(Reserved, not supported yet) Indicates the common event about the pairing request from a remote Bluetooth device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.DISCOVER_BLUETOOTH

**Value**: "usual.event.bluetooth.remotedevice.PAIRING_REQ"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL
(Reserved, not supported yet) Indicates the common event that Bluetooth pairing is canceled.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.remotedevice.PAIRING_CANCEL"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ
(Reserved, not supported yet) Indicates the common event about the connection request from a remote Bluetooth device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.remotedevice.CONNECT_REQ"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY
(Reserved, not supported yet) Indicates the common event about the response to the connection request from a remote Bluetooth device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.remotedevice.CONNECT_REPLY"


### COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL
(Reserved, not supported yet) Indicates the common event that the connection to a remote Bluetooth device has been canceled.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.remotedevice.CONNECT_CANCEL"


### COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the connection state of a Bluetooth handsfree has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE"


### COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the audio state of a Bluetooth handsfree has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE"


### COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT
(Reserved, not supported yet) Indicates the common event that the audio gateway state of a Bluetooth handsfree has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT"


### COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the calling state of a Bluetooth handsfree has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE"


### COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE
Indicates the common event that the state of a Bluetooth adapter has been changed, for example, Bluetooth has been enabled or disabled.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.host.STATE_UPDATE"


### COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE
(Reserved, not supported yet) Indicates the common event about the request for the user to allow Bluetooth device scanning.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.bluetooth.host.REQ_DISCOVERABLE"


### COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE
(Reserved, not supported yet) Indicates the common event about the request for the user to enable Bluetooth.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.host.REQ_ENABLE"



### COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE
(Reserved, not supported yet) Indicates the common event about the request for the user to disable Bluetooth.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.host.REQ_DISABLE"


### COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE
(Reserved, not supported yet) Indicates the common event that the Bluetooth scanning mode of a device has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.host.SCAN_MODE_UPDATE"




### COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED
Indicates the common event that the Bluetooth scanning has been started on the device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.ACCESS_BLUETOOTH

**Value**: "usual.event.bluetooth.host.DISCOVERY_STARTED"


### COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED
Indicates the common event that the Bluetooth scanning is finished on the device.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.ACCESS_BLUETOOTH

**Value**: "usual.event.bluetooth.host.DISCOVERY_FINISHED"


### COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE
Indicates the common event that the Bluetooth adapter name of the device has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.ACCESS_BLUETOOTH

**Value**: "usual.event.bluetooth.host.NAME_UPDATE"


### COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the connection state of Bluetooth A2DP Sink has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE"

### COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the playing state of Bluetooth A2DP Sink has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE"


### COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE
(Reserved, not supported yet) Indicates the common event that the audio state of Bluetooth A2DP Sink has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.USE_BLUETOOTH

**Value**: "usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE"


### COMMON_EVENT_ABILITY_ADDED
(Reserved, not supported yet) Indicates the common event that an ability has been added.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.LISTEN_BUNDLE_CHANGE

**Value**: "usual.event.ABILITY_ADDED"


### COMMON_EVENT_ABILITY_REMOVED
(Reserved, not supported yet) Indicates the common event that an ability has been removed.
**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.LISTEN_BUNDLE_CHANGE

**Value**: "usual.event.ABILITY_REMOVED"

### COMMON_EVENT_ABILITY_UPDATED
(Reserved, not supported yet) Indicates the common event that an ability has been updated.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.LISTEN_BUNDLE_CHANGE

**Value**: "usual.event.ABILITY_UPDATED"


### COMMON_EVENT_LOCATION_MODE_STATE_CHANGED
(Reserved, not supported yet) Indicates the common event that the location mode of the system has changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.location.MODE_STATE_CHANGED"


### COMMON_EVENT_IVI_SLEEP
(Reserved, not supported yet) Indicates the common event that the in-vehicle infotainment (IVI) system of a vehicle is sleeping.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_SLEEP"


### COMMON_EVENT_IVI_PAUSE
(Reserved, not supported yet) Indicates the common event that the IVI system of a vehicle has entered sleep mode and the playing application is instructed to stop playback.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_PAUSE"

### COMMON_EVENT_IVI_STANDBY
(Reserved, not supported yet) Indicates the common event that a third-party application is instructed to pause the current work.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_STANDBY"


### COMMON_EVENT_IVI_LASTMODE_SAVE
(Reserved, not supported yet) Indicates the common event that a third-party application is instructed to save its last mode.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_LASTMODE_SAVE"


### COMMON_EVENT_IVI_VOLTAGE_ABNORMAL
(Reserved, not supported yet) Indicates the common event that the voltage of the vehicle's power system is abnormal.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_VOLTAGE_ABNORMAL"


### COMMON_EVENT_IVI_HIGH_TEMPERATURE

(Reserved, not supported yet) Indicates the common event that the temperature of the IVI system is high.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_HIGH_TEMPERATURE"


### COMMON_EVENT_IVI_EXTREME_TEMPERATURE
(Reserved, not supported yet) Indicates the common event that the temperature of the IVI system is extremely high.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_EXTREME_TEMPERATURE"

### COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL
(Reserved, not supported yet) Indicates the common event that the IVI system has an extreme temperature.


**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_TEMPERATURE_ABNORMAL"


### COMMON_EVENT_IVI_VOLTAGE_RECOVERY
(Reserved, not supported yet) Indicates the common event that the voltage of the vehicle's power system is restored to normal.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_VOLTAGE_RECOVERY"


### COMMON_EVENT_IVI_TEMPERATURE_RECOVERY
(Reserved, not supported yet) Indicates the common event that the temperature of the IVI system is restored to normal.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_TEMPERATURE_RECOVERY"


### COMMON_EVENT_IVI_ACTIVE
(Reserved, not supported yet) Indicates the common event that the battery service is active.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "common.event.IVI_ACTIVE"

### COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED
(Reserved, not supported yet) Indicates the common event that the account visibility changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.GET_APP_ACCOUNTS (for system applications only)

**Value**: "usual.event.data.VISIBLE_ACCOUNTS_UPDATED"


### COMMON_EVENT_ACCOUNT_DELETED
(Reserved, not supported yet) Indicates the common event that the account was deleted.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (for system applications only)

**Value**: "usual.event.data.ACCOUNT_DELETED"

### COMMON_EVENT_FOUNDATION_READY
(Reserved, not supported yet) Indicates the common event that the foundation is ready.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: ohos.permission.RECEIVER_STARTUP_COMPLETED (for system applications only)

**Value**: "usual.event.data.FOUNDATION_READY"

### COMMON_EVENT_SPN_INFO_CHANGED 
Indicates the common event of that the SPN information had changed.

**System capability**: SystemCapability.Notification.CommonEvent

**Required subscriber permissions**: none

**Value**: "usual.event.SPN_INFO_CHANGED"

