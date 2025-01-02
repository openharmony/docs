# oh_commonevent_support.h


## 概述

声明系统公共事件常量定义。

**库：** libohcommonevent.so

**系统能力：** SystemCapability.Notification.CommonEvent

**起始版本：** 12

**相关模块：**[CommonEvent](capi-common-event.md)


## 汇总


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
|static const char* const [COMMON_EVENT_PACKAGE_RESTARTED](common_event/commonEventManager-definitions.md#common_event_package_restarted) = "usual.event.PACKAGE_RESTARTED"| 表示用户重启应用包并杀死其所有进程的普通事件的动作。|
|static const char* const [COMMON_EVENT_PACKAGE_DATA_CLEARED](common_event/commonEventManager-definitions.md#common_event_package_data_cleared) = "usual.event.PACKAGE_DATA_CLEARED"| 表示用户清除应用包数据的公共事件的动作|
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
