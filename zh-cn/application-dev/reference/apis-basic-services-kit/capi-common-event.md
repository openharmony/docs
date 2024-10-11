# CommonEvent


## 概述

描述CommonEvent向应用提供公共事件的能力。

**系统能力：** SystemCapability.Notification.CommonEvent

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [oh_commonevent.h](oh_commonevent_8h.md) | 声明公共事件相关的API，包含订阅公共事件与退订公共事件。<br/>**引用文件**：&lt;BasicServicesKit/oh_commonevent.h&gt;<br/>**库**：libohcommonevent.so|
| [oh_commonevent_support.h](oh_commonevent_support_8h.md) | 提供系统定义的公共事件常量。<br/>**引用文件**：&lt;BasicServicesKit/oh_commonevent_support.h&gt;<br/>**库**：libohcommonevent.so |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
|[CommonEvent_SubscribeInfo](#commonevent_subscribeinfo) | 订阅者信息。 |
|[CommonEvent_Subscriber](#commonevent_subscriber) | 订阅者。 |
|[CommonEvent_RcvData](#commonevent_rcvdata) | 公共事件的回调数据。 |
|[CommonEvent_Parameters](#commonevent_parameters) | 公共事件的回调附加信息。 |
|[CommonEvent_ReceiveCallback](#commonevent_receivecallback)| 公共事件的回调函数。 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 枚举错误码。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_CommonEvent_CreateSubscribeInfo](#oh_commonevent_createsubscribeinfo)| 创建订阅者信息。 |
| [OH_CommonEvent_SetPublisherPermission](#oh_commonevent_setpublisherpermission) | 设置订阅者权限。 |
| [OH_CommonEvent_SetPublisherBundleName](#oh_commonevent_setpublisherbundlename) | 设置订阅者包名称。 |
| [OH_CommonEvent_DestroySubscribeInfo](#oh_commonevent_destroysubscribeinfo) | 销毁订阅者信息。 |
| [OH_CommonEvent_CreateSubscriber](#oh_commonevent_createsubscriber)| 创建订阅者。 |
| [OH_CommonEvent_DestroySubscriber](#oh_commonevent_destroysubscriber) | 销毁订阅者。 |
| [OH_CommonEvent_Subscribe](#oh_commonevent_subscribe) | 订阅事件。 |
| [OH_CommonEvent_UnSubscribe](#oh_commonevent_unsubscribe) | 退订事件。 |
| [OH_CommonEvent_GetEventFromRcvData](#oh_commonevent_geteventfromrcvdata)| 获取公共事件名称。 |
| [OH_CommonEvent_GetCodeFromRcvData](#oh_commonevent_getcodefromrcvdata) | 获取公共事件结果代码。 |
| [OH_CommonEvent_GetDataStrFromRcvData](#oh_commonevent_getdatastrfromrcvdata)| 获取公共事件自定义结果数据。 |
| [OH_CommonEvent_GetBundleNameFromRcvData](#oh_commonevent_getbundlenamefromrcvdata)| 获取公共事件包名称。 |
| [OH_CommonEvent_GetParametersFromRcvData](#oh_commonevent_getparametersfromrcvdata) | 获取公共事件附加信息。 |
| [OH_CommonEvent_HasKeyInParameters](#oh_commonevent_haskeyinparameters) | 检查公共事件附加信息中是否包含某个键值对信息。 |
| [OH_CommonEvent_GetIntFromParameters](#oh_commonevent_getintfromparameters) | 获取公共事件附加信息中int数据信息。 |
| [OH_CommonEvent_GetIntArrayFromParameters](#oh_commonevent_getintarrayfromparameters)| 获取公共事件附加信息中int数组信息。 |
| [OH_CommonEvent_GetLongFromParameters](#oh_commonevent_getlongfromparameters)| 获取公共事件附加信息中long数据信息。 |
| [OH_CommonEvent_GetLongArrayFromParameters](#oh_commonevent_getlongarrayfromparameters)| 获取公共事件附加信息中long数组信息。 |
| [OH_CommonEvent_GetBoolFromParameters](#oh_commonevent_getboolfromparameters)| 获取公共事件附加信息中布尔数据信息。 |
| [OH_CommonEvent_GetBoolArrayFromParameters](#oh_commonevent_getboolarrayfromparameters)| 获取公共事件附加信息中布尔数组信息。 |
| [OH_CommonEvent_GetCharFromParameters](#oh_commonevent_getcharfromparameters)| 获取公共事件附加信息中字符数据信息。 |
| [OH_CommonEvent_GetCharArrayFromParameters](#oh_commonevent_getchararrayfromparameters)| 获取公共事件附加信息中字符数组信息。 |
| [OH_CommonEvent_GetDoubleFromParameters](#oh_commonevent_getdoublefromparameters)| 获取公共事件附加信息中double数据信息。 |
| [OH_CommonEvent_GetDoubleArrayFromParameters](#oh_commonevent_getdoublearrayfromparameters)| 获取公共事件附加信息中double数组信息。 |

### 常量
| 名称 | 描述 |
| -------- | -------- |
|static const char* const [COMMON_EVENT_SHUTDOWN](common_event/commonEventManager-definitions.md#common_event_shutdown) = "usual.event.SHUTDOWN" | 表示设备正在关闭并将继续直至最终关闭的公共事件。 |
|static const char* const [COMMON_EVENT_BATTERY_CHANGED](common_event/commonEventManager-definitions.md#common_event_battery_changed) = "usual.event.BATTERY_CHANGED" | 表示电池充电状态、电平和其他信息发生变化的公共事件。|
|static const char* const [COMMON_EVENT_BATTERY_LOW](common_event/commonEventManager-definitions.md#common_event_battery_low) = "usual.event.BATTERY_LOW"|表示电池电量低的公共事件。 |
|static const char* const [COMMON_EVENT_BATTERY_OKAY](common_event/commonEventManager-definitions.md#common_event_battery_okay) = "usual.event.BATTERY_OKAY"|表示电池退出低电平状态的公共事件。 |
|static const char* const [COMMON_EVENT_POWER_CONNECTED](common_event/commonEventManager-definitions.md#common_event_power_connected) = "usual.event.POWER_CONNECTED"|表示设备连接到外部电源的公共事件。|
|static const char* const [COMMON_EVENT_POWER_DISCONNECTED](common_event/commonEventManager-definitions.md#common_event_power_disconnected) = "usual.event.POWER_DISCONNECTED"|表示设备与外部电源断开的公共事件。|
|static const char* const [COMMON_EVENT_SCREEN_OFF](common_event/commonEventManager-definitions.md#common_event_screen_off) = "usual.event.SCREEN_OFF"| 表示设备屏幕关闭且设备处于睡眠状态的公共事件。|
|static const char* const [COMMON_EVENT_SCREEN_ON](common_event/commonEventManager-definitions.md#common_event_screen_on) = "usual.event.SCREEN_ON"|表示设备屏幕打开且设备处于交互状态的公共事件。 |
|static const char* const [COMMON_EVENT_THERMAL_LEVEL_CHANGED](common_event/commonEventManager-definitions.md#common_event_thermal_level_changed) = "usual.event.THERMAL_LEVEL_CHANGED"|表示设备热状态的公共事件。 |
|static const char* const [COMMON_EVENT_TIME_TICK](common_event/commonEventManager-definitions.md#common_event_time_tick) = "usual.event.TIME_TICK"|表示系统时间随时间流逝而发生变化的公共事件。 |
|static const char* const [COMMON_EVENT_TIME_CHANGED](common_event/commonEventManager-definitions.md#common_event_time_changed) = "usual.event.TIME_CHANGED"|表示系统时间被重新设置的公共事件。 |
|static const char* const [COMMON_EVENT_TIMEZONE_CHANGED](common_event/commonEventManager-definitions.md#common_event_timezone_changed) = "usual.event.TIMEZONE_CHANGED"|表示系统时区更改的公共事件。 |
|static const char* const [COMMON_EVENT_PACKAGE_ADDED](common_event/commonEventManager-definitions.md#common_event_package_added) = "usual.event.PACKAGE_ADDED"| 表示设备上已安装新应用包的公共事件。|
|static const char* const [COMMON_EVENT_PACKAGE_REMOVED](common_event/commonEventManager-definitions.md#common_event_package_removed) = "usual.event.PACKAGE_REMOVED"| 表示已安装的应用程序从设备中卸载，但应用程序数据保留的公共事件。|
|static const char* const [COMMON_EVENT_BUNDLE_REMOVED](common_event/commonEventManager-definitions.md#common_event_bundle_removed) = "usual.event.BUNDLE_REMOVED"| 表示从设备中卸载已安装应用程序的附加包，但应用程序数据仍保留的公共事件。|
|static const char* const [COMMON_EVENT_PACKAGE_FULLY_REMOVED](common_event/commonEventManager-definitions.md#common_event_package_fully_removed) = "usual.event.PACKAGE_FULLY_REMOVED"|表示已从设备中完全卸载已安装的应用程序（包括应用程序数据和代码）的公共事件。 |
|static const char* const [COMMON_EVENT_PACKAGE_CHANGED](common_event/commonEventManager-definitions.md#common_event_package_changed) = "usual.event.PACKAGE_CHANGED"| 表示应用包已更改的公共事件（例如，包中的组件已启用或禁用）。|
|static const char* const [COMMON_EVENT_PACKAGE_RESTARTED](common_event/commonEventManager-definitions.md#common_event_package_restarted) = "usual.event.PACKAGE_RESTARTED"| 表示用户重启应用包并杀死其所有进程的公共事件。|
|static const char* const [COMMON_EVENT_PACKAGE_DATA_CLEARED](common_event/commonEventManager-definitions.md#common_event_package_data_cleared) = "usual.event.PACKAGE_DATA_CLEARED"| 表示用户清除应用包数据的公共事件|
|static const char* const [COMMON_EVENT_PACKAGE_CACHE_CLEARED](common_event/commonEventManager-definitions.md#common_event_package_cache_cleared) = "usual.event.PACKAGE_CACHE_CLEARED"|表示用户清除应用包缓存数据的公共事件。 |
|static const char* const [COMMON_EVENT_PACKAGES_SUSPENDED](common_event/commonEventManager-definitions.md#common_event_packages_suspended) = "usual.event.PACKAGES_SUSPENDED"|表示应用包已挂起的公共事件。 |
|static const char* const [COMMON_EVENT_MY_PACKAGE_SUSPENDED](common_event/commonEventManager-definitions.md#common_event_my_package_suspended) = "usual.event.MY_PACKAGE_SUSPENDED"| 表示应用程序包已被挂起的公共事件，该事件可以发送到被挂起的应用程序包。|
|static const char* const [COMMON_EVENT_MY_PACKAGE_UNSUSPENDED](common_event/commonEventManager-definitions.md#common_event_my_package_unsuspended) = "usual.event.MY_PACKAGE_UNSUSPENDED"| 表示应用包未挂起的公共事件。 |
|static const char* const [COMMON_EVENT_LOCALE_CHANGED](common_event/commonEventManager-definitions.md#common_event_locale_changed) = "usual.event.LOCALE_CHANGED"| 表示设备区域设置已更改的公共事件。|
|static const char* const [COMMON_EVENT_MANAGE_PACKAGE_STORAGE](common_event/commonEventManager-definitions.md#common_event_manage_package_storage) = "usual.event.MANAGE_PACKAGE_STORAGE"| 设备存储空间不足的公共事件。|
|static const char* const [COMMON_EVENT_USER_UNLOCKED](common_event/commonEventManager-definitions.md#common_event_user_unlocked) = "usual.event.USER_UNLOCKED"| 表示设备重启后解锁时，当前用户的凭据加密存储已解锁的公共事件。 |
|static const char* const [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT](common_event/commonEventManager-definitions.md#common_event_distributed_account_logout) = "common.event.DISTRIBUTED_ACCOUNT_LOGOUT"|表示分布式账号登出成功的公共事件。 |
|static const char* const [COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID](common_event/commonEventManager-definitions.md#common_event_distributed_account_token_invalid) = "common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID"|表示分布式账号token令牌无效的公共事件。 |
|static const char* const [COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF](common_event/commonEventManager-definitions.md#common_event_distributed_account_logoff) = "common.event.DISTRIBUTED_ACCOUNT_LOGOFF"| 表示分布式账号注销的公共事件。|
|static const char* const [COMMON_EVENT_WIFI_POWER_STATE](common_event/commonEventManager-definitions.md#common_event_wifi_power_state) = "usual.event.wifi.POWER_STATE"| 表示Wi-Fi状态公共事件，如启用和禁用。|
|static const char* const [COMMON_EVENT_WIFI_SCAN_FINISHED](common_event/commonEventManager-definitions.md#common_event_wifi_scan_finished) = "usual.event.wifi.SCAN_FINISHED"|表示Wi-Fi接入点已被扫描并证明可用的公共事件。 |
|static const char* const [COMMON_EVENT_WIFI_RSSI_VALUE](common_event/commonEventManager-definitions.md#common_event_wifi_rssi_value) = "usual.event.wifi.RSSI_VALUE"|表示Wi-Fi信号强度（RSSI）改变的公共事件。 |
|static const char* const [COMMON_EVENT_WIFI_CONN_STATE](common_event/commonEventManager-definitions.md#common_event_wifi_conn_state) = "usual.event.wifi.CONN_STATE"| 表示Wi-Fi连接状态发生改变的公共事件。|
|static const char* const [COMMON_EVENT_WIFI_HOTSPOT_STATE](common_event/commonEventManager-definitions.md#common_event_wifi_hotspot_state) = "usual.event.wifi.HOTSPOT_STATE"| 表示Wi-Fi热点状态的公共事件，如启用或禁用。|
|static const char* const [COMMON_EVENT_WIFI_AP_STA_JOIN](common_event/commonEventManager-definitions.md#common_event_wifi_ap_sta_join) = "usual.event.wifi.WIFI_HS_STA_JOIN"| 表示客户端加入当前设备Wi-Fi热点的公共事件。|
|static const char* const [COMMON_EVENT_WIFI_AP_STA_LEAVE](common_event/commonEventManager-definitions.md#common_event_wifi_ap_sta_leave) = "usual.event.wifi.WIFI_HS_STA_LEAVE"|表示客户端已断开与当前设备Wi-Fi热点的连接的公共事件。 |
|static const char* const [COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE](common_event/commonEventManager-definitions.md#common_event_wifi_mplink_state_change) = "usual.event.wifi.mplink.STATE_CHANGE"|表示MPLink（增强Wi-Fi功能）状态已更改的公共事件。 |
|static const char* const [COMMON_EVENT_WIFI_P2P_CONN_STATE](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_conn_state) = "usual.event.wifi.p2p.CONN_STATE_CHANGE"|表示Wi-Fi P2P连接状态改变的公共事件。 |
|static const char* const [COMMON_EVENT_WIFI_P2P_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_state_changed) = "usual.event.wifi.p2p.STATE_CHANGE"|表示Wi-Fi P2P状态公共事件，如启用和禁用。 |
|static const char* const [COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_peers_state_changed) = "usual.event.wifi.p2p.DEVICES_CHANGE"|表示Wi-Fi P2P对等体状态变化的公共事件。 |
|static const char* const [COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_peers_discovery_state_changed) = "usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE"|表示Wi-Fi P2P发现状态变化的公共事件。 |
|static const char* const [COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_current_device_state_changed) = "usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE"|表示Wi-Fi P2P当前设备状态变化的公共事件。 |
|static const char* const [COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_wifi_p2p_group_state_changed) = "usual.event.wifi.p2p.GROUP_STATE_CHANGED"|表示Wi-Fi P2P群组信息已更改的公共事件。 |
|static const char* const [COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_nfc_action_adapter_state_changed) = "usual.event.nfc.action.ADAPTER_STATE_CHANGED"| 表示设备NFC状态已更改的公共事件。|
|static const char* const [COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED](common_event/commonEventManager-definitions.md#common_event_nfc_action_rf_field_on_detected) = "usual.event.nfc.action.RF_FIELD_ON_DETECTED"|表示检测到NFC场强进入的公共事件。 |
|static const char* const [COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED](common_event/commonEventManager-definitions.md#common_event_nfc_action_rf_field_off_detected) = "usual.event.nfc.action.RF_FIELD_OFF_DETECTED"|表示检测到NFC场强离开的公共事件。 |
|static const char* const [COMMON_EVENT_DISCHARGING](common_event/commonEventManager-definitions.md#common_event_discharging) = "usual.event.DISCHARGING"| 表示系统停止为电池充电的公共事件。|
|static const char* const [COMMON_EVENT_CHARGING](common_event/commonEventManager-definitions.md#common_event_charging) = "usual.event.CHARGING"|表示系统开始为电池充电的公共事件。 |
|static const char* const [COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED](common_event/commonEventManager-definitions.md#common_event_device_idle_mode_changed) = "usual.event.DEVICE_IDLE_MODE_CHANGED"| 表示系统待机空闲模式已更改的公共事件。|
|static const char* const [COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED](common_event/commonEventManager-definitions.md#common_event_charge_idle_mode_changed10) = "usual.event.CHARGE_IDLE_MODE_CHANGED"|表示设备进入充电空闲模式的公共事件。 |
|static const char* const [COMMON_EVENT_POWER_SAVE_MODE_CHANGED](common_event/commonEventManager-definitions.md#common_event_power_save_mode_changed) = "usual.event.POWER_SAVE_MODE_CHANGED"|表示系统节能模式更改的公共事件。 |
|static const char* const [COMMON_EVENT_USB_STATE](common_event/commonEventManager-definitions.md#common_event_usb_state) = "usual.event.hardware.usb.action.USB_STATE"|表示USB设备状态发生变化的公共事件。 |
|static const char* const [COMMON_EVENT_USB_PORT_CHANGED](common_event/commonEventManager-definitions.md#common_event_usb_port_changed) = "usual.event.hardware.usb.action.USB_PORT_CHANGED"|表示用户设备的USB端口状态发生改变的公共事件。 |
|static const char* const [COMMON_EVENT_USB_DEVICE_ATTACHED](common_event/commonEventManager-definitions.md#common_event_usb_device_attached) = "usual.event.hardware.usb.action.USB_DEVICE_ATTACHED"|当用户设备作为USB主机时，USB设备已挂载的公共事件。 |
|static const char* const [COMMON_EVENT_USB_DEVICE_DETACHED](common_event/commonEventManager-definitions.md#common_event_usb_device_detached) = "usual.event.hardware.usb.action.USB_DEVICE_DETACHED"|当用户设备作为USB主机时，USB设备被卸载的公共事件。 |
|static const char* const [COMMON_EVENT_AIRPLANE_MODE_CHANGED](common_event/commonEventManager-definitions.md#common_event_airplane_mode_changed10) = "usual.event.AIRPLANE_MODE"| 表示设备飞行模式已更改的公共事件。|
|static const char* const [COMMON_EVENT_SPLIT_SCREEN](common_event/commonEventManager-definitions.md#common_event_split_screen) = "common.event.SPLIT_SCREEN"| 表示分屏的公共事件。|
|static const char* const [COMMON_EVENT_QUICK_FIX_APPLY_RESULT](common_event/commonEventManager-definitions.md#common_event_quick_fix_apply_result) = "usual.event.QUICK_FIX_APPLY_RESULT"| 表示快速修复应用的公共事件。|
|static const char* const [COMMON_EVENT_QUICK_FIX_REVOKE_RESULT](common_event/commonEventManager-definitions.md#common_event_quick_fix_revoke_result10) = "usual.event.QUICK_FIX_REVOKE_RESULT"| 表示撤销快速修复的公共事件。|
|static const char* const [COMMON_EVENT_USER_INFO_UPDATED](common_event/commonEventManager-definitions.md#common_event_user_info_updated) = "usual.event.USER_INFO_UPDATED"| 表示用户信息已更新的公共事件。|
|static const char* const [COMMON_EVENT_SIM_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_sim_state_changed10) = "usual.event.SIM_STATE_CHANGED"|表示SIM卡状态更新的公共事件。 |
|static const char* const [COMMON_EVENT_CALL_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_call_state_changed10) = "usual.event.CALL_STATE_CHANGED"| 表示呼叫状态更新的公共事件。|
|static const char* const [COMMON_EVENT_NETWORK_STATE_CHANGED](common_event/commonEventManager-definitions.md#common_event_network_state_changed10) = "usual.event.NETWORK_STATE_CHANGED"| 表示网络状态更新的公共事件。|
|static const char* const [COMMON_EVENT_SIGNAL_INFO_CHANGED](common_event/commonEventManager-definitions.md#common_event_signal_info_changed10) = "usual.event.SIGNAL_INFO_CHANGED"|表示信号信息更新的公共事件。 |
|static const char* const [COMMON_EVENT_SCREEN_UNLOCKED](common_event/commonEventManager-definitions.md#common_event_screen_unlocked) = "usual.event.SCREEN_UNLOCKED"|表示屏幕解锁的公共事件。 |
|static const char* const [COMMON_EVENT_SCREEN_LOCKED](common_event/commonEventManager-definitions.md#common_event_screen_locked) = "usual.event.SCREEN_LOCKED"| 表示屏幕锁定的公共事件。|
|static const char* const [COMMON_EVENT_HTTP_PROXY_CHANGE](common_event/commonEventManager-definitions.md#common_event_http_proxy_change10) = "usual.event.HTTP_PROXY_CHANGE"| 表示HTTP代理的配置信息发生变化的公共事件。|
|static const char* const [COMMON_EVENT_CONNECTIVITY_CHANGE](common_event/commonEventManager-definitions.md#common_event_connectivity_change10) = "usual.event.CONNECTIVITY_CHANGE"| 表示网络连接状态变化的公共事件。|
|static const char* const [COMMON_EVENT_MINORSMODE_ON](common_event/commonEventManager-definitions.md#common_event_minorsmode_on12) = "usual.event.MINORSMODE_ON"|表示未成年人模式开启的公共事件。 |
|static const char* const [COMMON_EVENT_MINORSMODE_OFF](common_event/commonEventManager-definitions.md#common_event_minorsmode_off12) = "usual.event.MINORSMODE_OFF"| 表示未成年人模式关闭的公共事件。|
## 类型定义说明

### CommonEvent_SubscribeInfo

```c
typedef struct CommonEvent_SubscribeInfo CommonEvent_SubscribeInfo
```

**描述**

订阅者信息。

**起始版本：** 12

### CommonEvent_Subscriber

```c
typedef void CommonEvent_Subscriber
```

**描述**

订阅者。

**起始版本：** 12

### CommonEvent_RcvData

```c
typedef struct CommonEvent_RcvData CommonEvent_RcvData
```

**描述**

公共事件的回调数据。

**起始版本：** 12

### CommonEvent_Parameters

```c
typedef void CommonEvent_Parameters
```

**描述**

公共事件的回调附加信息。

**起始版本：** 12

### CommonEvent_ReceiveCallback

```c
typedef void (*CommonEvent_ReceiveCallback)(const CommonEvent_RcvData *data)
```

**描述**

公共事件的回调函数。

**起始版本：** 12


## 枚举类型说明

### CommonEvent_ErrCode
**描述**

表示错误码信息。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| COMMONEVENT_ERR_OK = 0 |执行成功。|
| COMMONEVENT_ERR_PERMISSION_ERROR = 201 |没有权限。|
| COMMONEVENT_ERR_INVALID_PARAMETER = 401 |无效的参数。|
| COMMONEVENT_ERR_SENDING_REQUEST_FAILED = 1500007 |发送IPC请求失败。|
| COMMONEVENT_ERR_INIT_UNDONE = 1500008|服务未初始化。|
| COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED = 1500010|订阅者数量超过200个。|
| COMMONEVENT_ERR_ALLOC_MEMORY_FAILED = 1500011|系统分配内存失败。|

## 常量说明

### COMMON_EVENT_SHUTDOWN

```c
static const char* const COMMON_EVENT_SHUTDOWN = "usual.event.SHUTDOWN"
```

**描述**

表示设备正在关闭并将继续直至最终关闭的公共事件。

**起始版本：** 12

### COMMON_EVENT_BATTERY_CHANGED

```c
static const char* const COMMON_EVENT_BATTERY_CHANGED = "usual.event.BATTERY_CHANGED"
```

**描述**

表示电池充电状态、电平和其他信息发生变化的公共事件。

**起始版本：** 12

### COMMON_EVENT_BATTERY_LOW

```c
static const char* const COMMON_EVENT_BATTERY_LOW = "usual.event.BATTERY_LOW"
```

**描述**

表示电池电量低的公共事件。

**起始版本：** 12

### COMMON_EVENT_BATTERY_OKAY

```c
static const char* const COMMON_EVENT_BATTERY_OKAY = "usual.event.BATTERY_OKAY"
```

**描述**

表示电池退出低电平状态的公共事件。

**起始版本：** 12

### COMMON_EVENT_POWER_CONNECTED

```c
static const char* const COMMON_EVENT_POWER_CONNECTED = "usual.event.POWER_CONNECTED"
```

**描述**

表示设备连接到外部电源的公共事件。

**起始版本：** 12

### COMMON_EVENT_POWER_DISCONNECTED

```c
static const char* const COMMON_EVENT_POWER_DISCONNECTED = "usual.event.POWER_DISCONNECTED"
```

**描述**

表示设备与外部电源断开的公共事件。

**起始版本：** 12

### COMMON_EVENT_SCREEN_OFF

```c
static const char* const COMMON_EVENT_SCREEN_OFF = "usual.event.SCREEN_OFF"
```

**描述**

表示设备屏幕关闭且设备处于睡眠状态的公共事件。

**起始版本：** 12

### COMMON_EVENT_SCREEN_ON

```c
static const char* const COMMON_EVENT_SCREEN_ON = "usual.event.SCREEN_ON"
```

**描述**

表示设备屏幕打开且设备处于交互状态的公共事件。

**起始版本：** 12

### COMMON_EVENT_THERMAL_LEVEL_CHANGED

```c
static const char* const COMMON_EVENT_THERMAL_LEVEL_CHANGED = "usual.event.THERMAL_LEVEL_CHANGED"
```

**描述**

表示设备热状态的公共事件。

**起始版本：** 12

### COMMON_EVENT_TIME_TICK

```c
static const char* const COMMON_EVENT_TIME_TICK = "usual.event.TIME_TICK"
```

**描述**

表示系统时间随时间流逝而发生变化的公共事件。

**起始版本：** 12

### COMMON_EVENT_TIME_CHANGED

```c
static const char* const COMMON_EVENT_TIME_CHANGED = "usual.event.TIME_CHANGED"
```

**描述**

表示系统时间被重新设置的公共事件。

**起始版本：** 12

### COMMON_EVENT_TIMEZONE_CHANGED

```c
static const char* const COMMON_EVENT_TIMEZONE_CHANGED = "usual.event.TIMEZONE_CHANGED"
```

**描述**

表示系统时区更改的公共事件。

**起始版本：** 12

### COMMON_EVENT_PACKAGE_ADDED

```c
static const char* const COMMON_EVENT_PACKAGE_ADDED = "usual.event.PACKAGE_ADDED"
```

**描述**

表示设备上已安装新应用包的公共事件。

**起始版本：** 12

### COMMON_EVENT_PACKAGE_REMOVED

```c
static const char* const COMMON_EVENT_PACKAGE_REMOVED = "usual.event.PACKAGE_REMOVED"
```

**描述**

表示已从设备卸载已安装的应用程序，但应用程序数据保留的公共事件。

**起始版本：** 12

### COMMON_EVENT_BUNDLE_REMOVED

```c
static const char* const COMMON_EVENT_BUNDLE_REMOVED = "usual.event.BUNDLE_REMOVED"
```

**描述**

表示已从设备中卸载已安装的捆绑包，但应用程序数据仍保留的公共事件。

**起始版本：** 12

### COMMON_EVENT_PACKAGE_FULLY_REMOVED

```c
static const char* const COMMON_EVENT_PACKAGE_FULLY_REMOVED = "usual.event.PACKAGE_FULLY_REMOVED"
```

**描述**

表示已从设备中完全卸载已安装的应用程序（包括应用程序数据和代码）的公共事件。

**起始版本：** 12

### COMMON_EVENT_PACKAGE_CHANGED

```c
static const char* const COMMON_EVENT_PACKAGE_CHANGED = "usual.event.PACKAGE_CHANGED"
```

**描述**

表示应用包已更改的公共事件（例如，包中的组件已启用或禁用）。

**起始版本：** 12

### COMMON_EVENT_PACKAGE_RESTARTED

```c
static const char* const COMMON_EVENT_PACKAGE_RESTARTED = "usual.event.PACKAGE_RESTARTED"
```

**描述**

表示用户重启应用包并杀死其所有进程的公共事件。

**起始版本：** 12

### COMMON_EVENT_PACKAGE_DATA_CLEARED

```c
static const char* const COMMON_EVENT_PACKAGE_DATA_CLEARED = "usual.event.PACKAGE_DATA_CLEARED"
```

**描述**

表示用户清除应用包数据的公共事件。

**起始版本：** 12

### COMMON_EVENT_PACKAGE_CACHE_CLEARED

```c
static const char* const COMMON_EVENT_PACKAGE_CACHE_CLEARED = "usual.event.PACKAGE_CACHE_CLEARED"
```

**描述**

表示用户清除应用包缓存数据的公共事件。

**起始版本：** 12

### COMMON_EVENT_PACKAGES_SUSPENDED

```c
static const char* const COMMON_EVENT_PACKAGES_SUSPENDED = "usual.event.PACKAGES_SUSPENDED"
```

**描述**

表示应用包已挂起的公共事件。

**起始版本：** 12

### COMMON_EVENT_MY_PACKAGE_SUSPENDED

```c
static const char* const COMMON_EVENT_MY_PACKAGE_SUSPENDED = "usual.event.MY_PACKAGE_SUSPENDED"
```

**描述**

表示应用程序包已被挂起的公共事件，该事件可以发送到被挂起的应用程序包。

**起始版本：** 12

### COMMON_EVENT_MY_PACKAGE_UNSUSPENDED

```c
static const char* const COMMON_EVENT_MY_PACKAGE_UNSUSPENDED = "usual.event.MY_PACKAGE_UNSUSPENDED"
```

**描述**

表示应用包未挂起的公共事件。

**起始版本：** 12

### COMMON_EVENT_LOCALE_CHANGED

```c
static const char* const COMMON_EVENT_LOCALE_CHANGED = "usual.event.LOCALE_CHANGED"
```

**描述**

表示设备区域设置已更改的公共事件。

**起始版本：** 12

### COMMON_EVENT_MANAGE_PACKAGE_STORAGE

```c
static const char* const COMMON_EVENT_MANAGE_PACKAGE_STORAGE = "usual.event.MANAGE_PACKAGE_STORAGE"
```

**描述**

表示设备存储空间不足的公共事件。

**起始版本：** 12

### COMMON_EVENT_USER_UNLOCKED

```c
static const char* const COMMON_EVENT_USER_UNLOCKED = "usual.event.USER_UNLOCKED"
```

**描述**

表示设备重启后解锁时，当前用户的凭据加密存储已解锁的公共事件。

**起始版本：** 12

### COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT

```c
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT = "common.event.DISTRIBUTED_ACCOUNT_LOGOUT"
```

**描述**

表示分布式账号登出成功的公共事件。

**起始版本：** 12

### COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID

```c
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID = "common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID"
```

**描述**

表示分布式账号token令牌无效的公共事件。

**起始版本：** 12

### COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF

```c
static const char* const COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF = "common.event.DISTRIBUTED_ACCOUNT_LOGOFF"
```

**描述**

表示分布式账号注销的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_POWER_STATE

```c
static const char* const COMMON_EVENT_WIFI_POWER_STATE = "usual.event.wifi.POWER_STATE"
```

**描述**

表示Wi-Fi状态公共事件，如启用和禁用。

**起始版本：** 12

### COMMON_EVENT_WIFI_SCAN_FINISHED

```c
static const char* const COMMON_EVENT_WIFI_SCAN_FINISHED = "usual.event.wifi.SCAN_FINISHED"
```

**描述**

表示Wi-Fi接入点已被扫描并证明可用的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_RSSI_VALUE

```c
static const char* const COMMON_EVENT_WIFI_RSSI_VALUE = "usual.event.wifi.RSSI_VALUE"
```

**描述**

表示Wi-Fi信号强度（RSSI）改变的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_CONN_STATE

```c
static const char* const COMMON_EVENT_WIFI_CONN_STATE = "usual.event.wifi.CONN_STATE"
```

**描述**

表示Wi-Fi连接状态发生改变的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_HOTSPOT_STATE

```c
static const char* const COMMON_EVENT_WIFI_HOTSPOT_STATE = "usual.event.wifi.HOTSPOT_STATE"
```

**描述**

表示Wi-Fi热点状态的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_AP_STA_JOIN

```c
static const char* const COMMON_EVENT_WIFI_AP_STA_JOIN = "usual.event.wifi.WIFI_HS_STA_JOIN"
```

**描述**

表示客户端加入当前设备Wi-Fi热点的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_AP_STA_LEAVE

```c
static const char* const COMMON_EVENT_WIFI_AP_STA_LEAVE = "usual.event.wifi.WIFI_HS_STA_LEAVE"
```

**描述**

表示客户端已断开与当前设备Wi-Fi热点的连接的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE

```c
static const char* const COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE = "usual.event.wifi.mplink.STATE_CHANGE"
```

**描述**

表示MPLink（增强Wi-Fi功能）状态已更改的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_P2P_CONN_STATE

```c
static const char* const COMMON_EVENT_WIFI_P2P_CONN_STATE = "usual.event.wifi.p2p.CONN_STATE_CHANGE"
```

**描述**

表示Wi-Fi P2P连接状态改变的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_P2P_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_STATE_CHANGED = "usual.event.wifi.p2p.STATE_CHANGE"
```

**描述**

表示Wi-Fi P2P状态公共事件，如启用和禁用。

### COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED = "usual.event.wifi.p2p.DEVICES_CHANGE"
```

**描述**

表示Wi-Fi P2P对等体状态变化的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED = "usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE"
```

**描述**

表示Wi-Fi P2P发现状态变化的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED = "usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE"
```

**描述**

表示Wi-Fi P2P当前设备状态变化的公共事件。

**起始版本：** 12

### COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED

```c
static const char* const COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED = "usual.event.wifi.p2p.GROUP_STATE_CHANGED"
```

**描述**

表示Wi-Fi P2P群组信息已更改的公共事件。

**起始版本：** 12

### COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED

```c
static const char* const COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED = "usual.event.nfc.action.ADAPTER_STATE_CHANGED"
```

**描述**

表示设备NFC状态已更改的公共事件。

**起始版本：** 12

### COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED

```c
static const char* const COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED = "usual.event.nfc.action.RF_FIELD_ON_DETECTED"
```

**描述**

表示检测到NFC场强进入的公共事件。

**起始版本：** 12

### COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED

```c
static const char* const COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED = "usual.event.nfc.action.RF_FIELD_OFF_DETECTED"
```

**描述**

表示检测到NFC场强离开的公共事件。

**起始版本：** 12

### COMMON_EVENT_DISCHARGING

```c
static const char* const COMMON_EVENT_DISCHARGING = "usual.event.DISCHARGING"
```

**描述**

表示系统停止为电池充电的公共事件。

**起始版本：** 12

### COMMON_EVENT_CHARGING

```c
static const char* const COMMON_EVENT_CHARGING = "usual.event.CHARGING"
```

**描述**

表示系统开始为电池充电的公共事件。

### COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED

```c
static const char* const COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED = "usual.event.DEVICE_IDLE_MODE_CHANGED"
```

**描述**

表示系统待机空闲模式已更改的公共事件。

**起始版本：** 12

### COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED

```c
static const char* const COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED = "usual.event.CHARGE_IDLE_MODE_CHANGED"
```

**描述**

表示设备进入充电空闲模式的公共事件。

**起始版本：** 12

### COMMON_EVENT_POWER_SAVE_MODE_CHANGED

```c
static const char* const COMMON_EVENT_POWER_SAVE_MODE_CHANGED = "usual.event.POWER_SAVE_MODE_CHANGED"
```

**描述**

表示系统节能模式更改的公共事件。

**起始版本：** 12

### COMMON_EVENT_USB_STATE

```c
static const char* const COMMON_EVENT_USB_STATE = "usual.event.hardware.usb.action.USB_STATE"
```

**描述**

表示USB设备状态发生变化的公共事件。

**起始版本：** 12

### COMMON_EVENT_USB_PORT_CHANGED

```c
static const char* const COMMON_EVENT_USB_PORT_CHANGED = "usual.event.hardware.usb.action.USB_PORT_CHANGED"
```

**描述**

表示用户设备的USB端口状态发生改变的公共事件。

**起始版本：** 12

### COMMON_EVENT_USB_DEVICE_ATTACHED

```c
static const char* const COMMON_EVENT_USB_DEVICE_ATTACHED = "usual.event.hardware.usb.action.USB_DEVICE_ATTACHED"
```

**描述**

当用户设备作为USB主机时，USB设备已挂载的公共事件。

**起始版本：** 12

### COMMON_EVENT_USB_DEVICE_DETACHED

```c
static const char* const COMMON_EVENT_USB_DEVICE_DETACHED = "usual.event.hardware.usb.action.USB_DEVICE_DETACHED"
```

**描述**

当用户设备作为USB主机时，USB设备被卸载的公共事件。

**起始版本：** 12

### COMMON_EVENT_AIRPLANE_MODE_CHANGED

```c
static const char* const COMMON_EVENT_AIRPLANE_MODE_CHANGED = "usual.event.AIRPLANE_MODE"
```

**描述**

表示设备飞行模式已更改的公共事件。

**起始版本：** 12

### COMMON_EVENT_SPLIT_SCREEN

```c
static const char* const COMMON_EVENT_SPLIT_SCREEN = "common.event.SPLIT_SCREEN"
```

**描述**

表示分屏的公共事件。

**起始版本：** 12

### COMMON_EVENT_QUICK_FIX_APPLY_RESULT

```c
static const char* const COMMON_EVENT_QUICK_FIX_APPLY_RESULT = "usual.event.QUICK_FIX_APPLY_RESULT"
```

**描述**

表示快速修复应用的公共事件。

**起始版本：** 12

### COMMON_EVENT_QUICK_FIX_REVOKE_RESULT

```c
static const char* const COMMON_EVENT_QUICK_FIX_REVOKE_RESULT = "usual.event.QUICK_FIX_REVOKE_RESULT"
```

**描述**

表示撤销快速修复的公共事件。

**起始版本：** 12

### COMMON_EVENT_USER_INFO_UPDATED

```c
static const char* const COMMON_EVENT_USER_INFO_UPDATED = "usual.event.USER_INFO_UPDATED"
```

**描述**

表示用户信息已更新的公共事件。

**起始版本：** 12

### COMMON_EVENT_SIM_STATE_CHANGED

```c
static const char* const COMMON_EVENT_SIM_STATE_CHANGED = "usual.event.SIM_STATE_CHANGED"
```

**描述**

表示SIM卡状态更新的公共事件。

**起始版本：** 12

### COMMON_EVENT_CALL_STATE_CHANGED

```c
static const char* const COMMON_EVENT_CALL_STATE_CHANGED = "usual.event.CALL_STATE_CHANGED"
```

**描述**

表示呼叫状态更新的公共事件。

**起始版本：** 12

### COMMON_EVENT_NETWORK_STATE_CHANGED

```c
static const char* const COMMON_EVENT_NETWORK_STATE_CHANGED = "usual.event.NETWORK_STATE_CHANGED"
```

**描述**

表示网络状态更新的公共事件。

**起始版本：** 12

### COMMON_EVENT_SIGNAL_INFO_CHANGED

```c
static const char* const COMMON_EVENT_SIGNAL_INFO_CHANGED = "usual.event.SIGNAL_INFO_CHANGED"
```

**描述**

表示信号信息更新的公共事件。

**起始版本：** 12

### COMMON_EVENT_SCREEN_UNLOCKED

```c
static const char* const COMMON_EVENT_SCREEN_UNLOCKED = "usual.event.SCREEN_UNLOCKED"
```

**描述**

表示屏幕解锁的公共事件。

**起始版本：** 12

### COMMON_EVENT_SCREEN_LOCKED

```c
static const char* const COMMON_EVENT_SCREEN_LOCKED = "usual.event.SCREEN_LOCKED"
```

**描述**

表示屏幕锁定的公共事件。

**起始版本：** 12

### COMMON_EVENT_HTTP_PROXY_CHANGE

```c
static const char* const COMMON_EVENT_HTTP_PROXY_CHANGE = "usual.event.HTTP_PROXY_CHANGE"
```

**描述**

表示HTTP代理的配置信息发生变化的公共事件。

**起始版本：** 12

### COMMON_EVENT_CONNECTIVITY_CHANGE

```c
static const char* const COMMON_EVENT_CONNECTIVITY_CHANGE = "usual.event.CONNECTIVITY_CHANGE"
```

**描述**

表示网络连接状态变化的公共事件。

**起始版本：** 12

### COMMON_EVENT_MINORSMODE_ON

```c
static const char* const COMMON_EVENT_MINORSMODE_ON = "usual.event.MINORSMODE_ON"
```

**描述**

表示未成年人模式开启的公共事件。

**起始版本：** 12

### COMMON_EVENT_MINORSMODE_OFF

```c
static const char* const COMMON_EVENT_MINORSMODE_OFF = "usual.event.MINORSMODE_OFF"
```

**描述**

表示未成年人模式关闭的公共事件。

**起始版本：** 12

## 函数说明

### OH_CommonEvent_CreateSubscribeInfo

```cpp
CommonEvent_SubscribeInfo* OH_CommonEvent_CreateSubscribeInfo(const char* events[], int32_t eventsNum)
```

**描述**

创建订阅者信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| events | 订阅的事件。 |
| eventsNum | 事件数量。 |

**返回：**

返回订阅者信息。

### OH_CommonEvent_SetPublisherPermission

```cpp
CommonEvent_ErrCode OH_CommonEvent_SetPublisherPermission(CommonEvent_SubscribeInfo* info, const char* permission)
```

**描述**

设置订阅者权限。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| info | 订阅者信息。 |
| permission | 权限名称。 |

**返回：**

返回COMMONEVENT_ERR_OK表示成功；返回COMMONEVENT_ERR_INVALID_PARAMETER表示info为空指针。

### OH_CommonEvent_SetPublisherBundleName

```cpp
CommonEvent_ErrCode OH_CommonEvent_SetPublisherBundleName(CommonEvent_SubscribeInfo* info, const char* bundleName)
```

**描述**

设置订阅者包名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| info | 订阅者信息。 |
| bundleName | 包名称。 |

**返回：**

返回COMMONEVENT_ERR_OK表示成功；返回COMMONEVENT_ERR_INVALID_PARAMETER表示info为空指针。

### OH_CommonEvent_DestroySubscribeInfo

```cpp
void OH_CommonEvent_DestroySubscribeInfo(CommonEvent_SubscribeInfo* info)
```

**描述**

销毁订阅者信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| info | 订阅者信息。 |

### OH_CommonEvent_CreateSubscriber

```cpp
CommonEvent_Subscriber* OH_CommonEvent_CreateSubscriber(const CommonEvent_SubscribeInfo* info, CommonEvent_ReceiveCallback callback)
```

**描述**

创建订阅者。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| info | 订阅者信息。 |
| callback | 事件回调函数。 |

**返回：**

返回订阅者。

### OH_CommonEvent_DestroySubscriber

```cpp
void OH_CommonEvent_DestroySubscriber(CommonEvent_Subscriber* subscriber)
```

**描述**

销毁订阅者。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| subscriber | 订阅者。 |

### OH_CommonEvent_Subscribe

```cpp
CommonEvent_ErrCode OH_CommonEvent_Subscribe(const CommonEvent_Subscriber* subscriber)
```

**描述**

订阅公共事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| subscriber | 订阅者。 |

**返回：**

返回COMMONEVENT_ERR_OK表示成功；返回COMMONEVENT_ERR_INVALID_PARAMETER表示参数subscriber为空；返回COMMONEVENT_ERR_SENDING_REQUEST_FAILED表示IPC发送失败；返回COMMONEVENT_ERR_INIT_UNDONE表示公共事件服务未初始化；返回COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED表示当前进程订阅者超过200个；返回COMMONEVENT_ERR_ALLOC_MEMORY_FAILED表示系统分配内存失败。

### OH_CommonEvent_UnSubscribe

```cpp
CommonEvent_ErrCode OH_CommonEvent_UnSubscribe(const CommonEvent_Subscriber* subscriber)
```

**描述**

退订公共事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| subscriber | 订阅者。 |

**返回：**

返回COMMONEVENT_ERR_OK表示成功；返回COMMONEVENT_ERR_INVALID_PARAMETER表示参数subscriber为空；返回COMMONEVENT_ERR_SENDING_REQUEST_FAILED表示IPC发送失败；返回COMMONEVENT_ERR_INIT_UNDONE表示公共事件服务未初始化。

### OH_CommonEvent_GetEventFromRcvData

```cpp
const char* OH_CommonEvent_GetEventFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取回调公共事件名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rcvData | 公共事件回调数据。 |

**返回：**

返回公共事件名称。

### OH_CommonEvent_GetCodeFromRcvData

```cpp
int32_t OH_CommonEvent_GetCodeFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取回调公共事件结果代码。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rcvData | 公共事件回调数据。 |

**返回：**

返回公共事件结果代码。

### OH_CommonEvent_GetDataStrFromRcvData

```cpp
const char* OH_CommonEvent_GetDataStrFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取回调公共事件自定义结果数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rcvData | 公共事件回调数据。 |

**返回：**

返回公共事件自定义结果数据。

### OH_CommonEvent_GetBundleNameFromRcvData

```cpp
const char* OH_CommonEvent_GetBundleNameFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取回调公共事件包名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rcvData | 公共事件回调数据。 |

**返回：**

返回公共事件包名称。

### OH_CommonEvent_GetParametersFromRcvData

```cpp
const CommonEvent_Parameters* OH_CommonEvent_GetParametersFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取回调公共事件附件信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rcvData | 公共事件回调数据。 |

**返回：**

返回公共事件附加信息。

### OH_CommonEvent_HasKeyInParameters

```cpp
bool OH_CommonEvent_HasKeyInParameters(const CommonEvent_Parameters* para, const char* key)
```

**描述**

查询公共事件附加信息中是否存在该键值对信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |

**返回：**

返回true表示存在该键值对信息，返回false表示不存在。

### OH_CommonEvent_GetIntFromParameters

```cpp
int OH_CommonEvent_GetIntFromParameters(const CommonEvent_Parameters* para, const char* key, const int defaultValue)
```

**描述**

获取公共事件附加信息中键为key的int类型数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| defaultValue | 默认返回值。 |

### OH_CommonEvent_GetIntArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetIntArrayFromParameters(const CommonEvent_Parameters* para, const char* key, int** array)
```

**描述**

获取公共事件附加信息中键为key的int数组数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| array | 接收数据的int数组。 |

**返回：**

返回数组长度。

### OH_CommonEvent_GetLongFromParameters

```cpp
long OH_CommonEvent_GetLongFromParameters(const CommonEvent_Parameters* para, const char* key, const long defaultValue)
```

**描述**

获取公共事件附加信息中键为key的long类型数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| defaultValue | 默认返回值。 |

### OH_CommonEvent_GetLongArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetLongArrayFromParameters(const CommonEvent_Parameters* para, const char* key, long** array)
```

**描述**

获取公共事件附加信息中键为key的long数组数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| array | 接收数据的long数组。 |

**返回：**

返回数组长度。

### OH_CommonEvent_GetBoolFromParameters

```cpp
bool OH_CommonEvent_GetBoolFromParameters(const CommonEvent_Parameters* para, const char* key, const bool defaultValue)
```

**描述**

获取公共事件附加信息中键为key的布尔类型数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| defaultValue | 默认返回值。 |

### OH_CommonEvent_GetBoolArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetBoolArrayFromParameters(const CommonEvent_Parameters* para, const char* key, bool** array)
```

**描述**

获取公共事件附加信息中键为key的布尔数组数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| array | 接收数据的long数组。 |

**返回：**

返回数组长度。

### OH_CommonEvent_GetCharFromParameters

```cpp
char OH_CommonEvent_GetCharFromParameters(const CommonEvent_Parameters* para, const char* key, const char defaultValue)
```

**描述**

获取公共事件附加信息中键为key的字符类型数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| defaultValue | 默认返回值。 |

### OH_CommonEvent_GetCharArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetCharArrayFromParameters(const CommonEvent_Parameters* para, const char* key, char** array)
```

**描述**

获取公共事件附加信息中键为key的字符数组数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| array | 接收数据的字符数组。 |

**返回：**

返回数组长度。

### OH_CommonEvent_GetDoubleFromParameters

```cpp
double OH_CommonEvent_GetDoubleFromParameters(const CommonEvent_Parameters* para, const char* key, const double defaultValue)
```

**描述**

获取公共事件附加信息中键为key的double类型数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| defaultValue | 默认返回值。 |

### OH_CommonEvent_GetDoubleArrayFromParameters

```cpp
int32_t OH_CommonEvent_GetDoubleArrayFromParameters(const CommonEvent_Parameters* para, const char* key, double** array)
```

**描述**

获取公共事件附加信息中键为key的double数组数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| para | 公共事件附加信息。 |
| key | 数据键。 |
| array | 接收数据的字符数组。 |

**返回：**

返回数组长度。
