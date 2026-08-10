# 系统公共事件定义
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

本文档提供系统所定义的公共事件类型的索引。

公共事件类型定义在[ohos.commonEvent模块的Support枚举](../js-apis-commonEvent.md#support)中。

> **说明：**
>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[系统定义的公共事件](commonEventManager-definitions.md)替代。


**系统能力：** SystemCapability.Notification.CommonEvent

* COMMON_EVENT_BOOT_COMPLETED<sup>(deprecated)</sup> 提示用户已完成引导并加载系统。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用COMMON_EVENT_BOOT_COMPLETED替代。

  - 值：usual.event.BOOT_COMPLETED
  - 订阅者所需权限：ohos.permission.RECEIVER_STARTUP_COMPLETED（该权限仅系统应用可申请）

* COMMON_EVENT_LOCKED_BOOT_COMPLETED<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户已完成引导，系统已加载，但屏幕仍锁定。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_LOCKED_BOOT_COMPLETED](commonEventManager-definitions.md#common_event_locked_boot_completed)替代。

  - 值：usual.event.LOCKED_BOOT_COMPLETED
  - 订阅者所需权限：无

* COMMON_EVENT_SHUTDOWN<sup>(deprecated)</sup> 提示设备正在关闭并将继续直至最终关闭。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_SHUTDOWN](commonEventManager-definitions.md#common_event_shutdown)替代。

  - 值：usual.event.SHUTDOWN
  - 订阅者所需权限：无

* COMMON_EVENT_BATTERY_CHANGED<sup>(deprecated)</sup> 提示电池充电状态、电量和其他信息发生变化。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BATTERY_CHANGED](commonEventManager-definitions.md#common_event_battery_changed)替代。

  - 值：usual.event.BATTERY_CHANGED
  - 订阅者所需权限：无

* COMMON_EVENT_BATTERY_LOW<sup>(deprecated)</sup> 提示电池电量低。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BATTERY_LOW](commonEventManager-definitions.md#common_event_battery_low)替代。

  - 值：usual.event.BATTERY_LOW
  - 订阅者所需权限：无

* COMMON_EVENT_BATTERY_OKAY<sup>(deprecated)</sup> 提示电池退出低电量状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BATTERY_OKAY](commonEventManager-definitions.md#common_event_battery_okay)替代。

  - 值：usual.event.BATTERY_OKAY
  - 订阅者所需权限：无

* COMMON_EVENT_POWER_CONNECTED<sup>(deprecated)</sup> 提示设备连接到外部电源。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_POWER_CONNECTED](commonEventManager-definitions.md#common_event_power_connected)替代。

  - 值：usual.event.POWER_CONNECTED
  - 订阅者所需权限：无


* COMMON_EVENT_POWER_DISCONNECTED<sup>(deprecated)</sup> 提示设备与外部电源断开。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_POWER_DISCONNECTED](commonEventManager-definitions.md#common_event_power_disconnected)替代。

  - 值：usual.event.POWER_DISCONNECTED
  - 订阅者所需权限：无


* COMMON_EVENT_SCREEN_OFF<sup>(deprecated)</sup> 提示设备屏幕关闭且设备处于睡眠状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_SCREEN_OFF](commonEventManager-definitions.md#common_event_screen_off)替代。

  - 值：usual.event.SCREEN_OFF
  - 订阅者所需权限：无


* COMMON_EVENT_SCREEN_ON<sup>(deprecated)</sup> 提示设备屏幕打开且设备处于交互状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_SCREEN_ON](commonEventManager-definitions.md#common_event_screen_on)替代。

  - 值：usual.event.SCREEN_ON
  - 订阅者所需权限：无


* COMMON_EVENT_THERMAL_LEVEL_CHANGED<sup>(deprecated)</sup> 提示设备热状态（温度等级）发生变化。

  > **说明：**
  >
  > 从API version 8 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_THERMAL_LEVEL_CHANGED](commonEventManager-definitions.md#common_event_thermal_level_changed)替代。

  - 值：usual.event.THERMAL_LEVEL_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_USER_PRESENT<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户解锁了设备。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USER_PRESENT](commonEventManager-definitions.md#common_event_user_presentdeprecated)替代。

  - 值：usual.event.USER_PRESENT
  - 订阅者所需权限：无


* COMMON_EVENT_TIME_TICK<sup>(deprecated)</sup> 提示系统时间发生更改（指时间正常流逝）。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_TIME_TICK](commonEventManager-definitions.md#common_event_time_tick)替代。

  - 值：usual.event.TIME_TICK
  - 订阅者所需权限：无


* COMMON_EVENT_TIME_CHANGED<sup>(deprecated)</sup> 提示系统时间被重新设置。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_TIME_CHANGED](commonEventManager-definitions.md#common_event_time_changed)替代。

  - 值：usual.event.TIME_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_DATE_CHANGED<sup>(deprecated)</sup> （预留事件，暂未支持）提示系统日期已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DATE_CHANGED](commonEventManager-definitions.md#common_event_date_changed)替代。

  - 值：usual.event.DATE_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_TIMEZONE_CHANGED<sup>(deprecated)</sup> 提示系统时区发生变更。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_TIMEZONE_CHANGED](commonEventManager-definitions.md#common_event_timezone_changed)替代。

  - 值：usual.event.TIMEZONE_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_CLOSE_SYSTEM_DIALOGS<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户关闭临时系统对话框。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_CLOSE_SYSTEM_DIALOGS](commonEventManager-definitions.md#common_event_close_system_dialogs)替代。

  - 值：usual.event.CLOSE_SYSTEM_DIALOGS
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGE_ADDED<sup>(deprecated)</sup> 提示设备上已安装新应用程序包。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_ADDED](commonEventManager-definitions.md#common_event_package_added)替代。

  - 值：usual.event.PACKAGE_ADDED
  - 订阅者所需权限：无

* COMMON_EVENT_PACKAGE_REPLACED<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备上已安装的旧版本应用程序已被新版本所替换。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_REPLACED](commonEventManager-definitions.md#common_event_package_replaced)替代。

  - 值：usual.event.PACKAGE_REPLACED
  - 订阅者所需权限：无


* COMMON_EVENT_MY_PACKAGE_REPLACED<sup>(deprecated)</sup> （预留事件，暂未支持）提示应用程序包的新版本已取代前一个版本。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_MY_PACKAGE_REPLACED](commonEventManager-definitions.md#common_event_my_package_replaced)替代。

  - 值：usual.event.MY_PACKAGE_REPLACED
  - 订阅者所需权限：无

* COMMON_EVENT_PACKAGE_REMOVED<sup>(deprecated)</sup> 提示已安装的应用程序已从设备卸载，但应用程序数据得到保留的。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_REMOVED](commonEventManager-definitions.md#common_event_package_removed)替代。

  - 值：usual.event.PACKAGE_REMOVED
  - 订阅者所需权限：无


* COMMON_EVENT_BUNDLE_REMOVED<sup>(deprecated)</sup> （预留事件，暂未支持）提示已从设备中卸载已安装应用程序的附加包，但应用程序数据得到保留。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BUNDLE_REMOVED](commonEventManager-definitions.md#common_event_bundle_removed)替代。

  - 值：usual.event.BUNDLE_REMOVED
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGE_FULLY_REMOVED<sup>(deprecated)</sup> （预留事件，暂未支持）提示已从设备中完全卸载已安装的应用程序（包括应用程序数据和代码）。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_FULLY_REMOVED](commonEventManager-definitions.md#common_event_package_fully_removed)替代。

  - 值：usual.event.PACKAGE_FULLY_REMOVED
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGE_CHANGED<sup>(deprecated)</sup> 提示应用程序包已发生更改（例如，包中的组件已启用或禁用）。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_CHANGED](commonEventManager-definitions.md#common_event_package_changed)替代。

  - 值：usual.event.PACKAGE_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGE_RESTARTED<sup>(deprecated)</sup> 提示用户终止了应用程序的所有进程并重启应用程序。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_RESTARTED](commonEventManager-definitions.md#common_event_package_restarted)替代。

  - 值：usual.event.PACKAGE_RESTARTED
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGE_DATA_CLEARED<sup>(deprecated)</sup> 提示用户清除了应用包数据。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_DATA_CLEARED](commonEventManager-definitions.md#common_event_package_data_cleared)替代。

  - 值：usual.event.PACKAGE_DATA_CLEARED
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGES_SUSPENDED<sup>(deprecated)</sup> （预留事件，暂未支持）提示应用程序已挂起。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGES_SUSPENDED](commonEventManager-definitions.md#common_event_packages_suspended)替代。

  - 值：usual.event.PACKAGES_SUSPENDED
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGES_UNSUSPENDED<sup>(deprecated)</sup> （预留事件，暂未支持）提示应用HAP包未挂起（从挂起状态恢复）。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGES_UNSUSPENDED](commonEventManager-definitions.md#common_event_packages_unsuspended)替代。

  - 值：usual.event.PACKAGES_UNSUSPENDED
  - 订阅者所需权限：无


* COMMON_EVENT_MY_PACKAGE_SUSPENDED<sup>(deprecated)</sup> 提示应用HAP包被挂起的。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_MY_PACKAGE_SUSPENDED](commonEventManager-definitions.md#common_event_my_package_suspended)替代。

  - 值：usual.event.MY_PACKAGE_SUSPENDED
  - 订阅者所需权限：无


* COMMON_EVENT_MY_PACKAGE_UNSUSPENDED<sup>(deprecated)</sup> 提示应用包未挂起。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_MY_PACKAGE_UNSUSPENDED](commonEventManager-definitions.md#common_event_my_package_unsuspended)替代。

  - 值：usual.event.MY_PACKAGE_UNSUSPENDED
  - 订阅者所需权限：无


* COMMON_EVENT_UID_REMOVED<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户ID已从系统中删除。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_UID_REMOVED](commonEventManager-definitions.md#common_event_uid_removed)替代。

  - 值：usual.event.UID_REMOVED
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGE_FIRST_LAUNCH<sup>(deprecated)</sup> （预留事件，暂未支持）提示首次启动已安装的应用程序。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_FIRST_LAUNCH](commonEventManager-definitions.md#common_event_package_first_launch)替代。

  - 值：usual.event.PACKAGE_FIRST_LAUNCH
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION<sup>(deprecated)</sup> （预留事件，暂未支持）提示应用需要系统校验。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION](commonEventManager-definitions.md#common_event_package_needs_verification)替代。

  - 值：usual.event.PACKAGE_NEEDS_VERIFICATION
  - 订阅者所需权限：无


* COMMON_EVENT_PACKAGE_VERIFIED<sup>(deprecated)</sup> （预留事件，暂未支持）提示应用已被系统校验。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_PACKAGE_VERIFIED](commonEventManager-definitions.md#common_event_package_verified)替代。

  - 值：usual.event.PACKAGE_VERIFIED
  - 订阅者所需权限：无


* COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE<sup>(deprecated)</sup> （预留事件，暂未支持）提示安装在外部存储上的应用程序对系统可用。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE](commonEventManager-definitions.md#common_event_external_applications_available)替代。

  - 值：usual.event.EXTERNAL_APPLICATIONS_AVAILABLE
  - 订阅者所需权限：无


* COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE<sup>(deprecated)</sup> （预留事件，暂未支持）提示安装在外部存储上的应用程序对系统不可用。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE](commonEventManager-definitions.md#common_event_external_applications_unavailable)替代。

  - 值：usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE
  - 订阅者所需权限：无


* COMMON_EVENT_CONFIGURATION_CHANGED<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备状态（例如，方向、区域设置等）已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_CONFIGURATION_CHANGED](commonEventManager-definitions.md#common_event_configuration_changed)替代。

  - 值：usual.event.CONFIGURATION_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_LOCALE_CHANGED<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备区域设置已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_LOCALE_CHANGED](commonEventManager-definitions.md#common_event_locale_changed)替代。

  - 值：usual.event.LOCALE_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_MANAGE_PACKAGE_STORAGE<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备存储空间不足。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_MANAGE_PACKAGE_STORAGE](commonEventManager-definitions.md#common_event_manage_package_storage)替代。

  - 值：usual.event.MANAGE_PACKAGE_STORAGE
  - 订阅者所需权限：无


* COMMON_EVENT_DRIVE_MODE<sup>(deprecated)</sup> （预留事件，暂未支持）提示系统处于驾驶模式。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DRIVE_MODE](commonEventManager-definitions.md#common_event_drive_mode)替代。

  - 值：common.event.DRIVE_MODE
  - 订阅者所需权限：无


* COMMON_EVENT_HOME_MODE<sup>(deprecated)</sup> （预留事件，暂未支持）提示系统处于HOME模式。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_HOME_MODE](commonEventManager-definitions.md#common_event_home_mode)替代。

  - 值：common.event.HOME_MODE
  - 订阅者所需权限：无


* COMMON_EVENT_OFFICE_MODE<sup>(deprecated)</sup> （预留事件，暂未支持）提示系统处于办公模式。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_OFFICE_MODE](commonEventManager-definitions.md#common_event_office_mode)替代。

  - 值：common.event.OFFICE_MODE
  - 订阅者所需权限：无


* COMMON_EVENT_USER_STARTED<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户已启动。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USER_STARTED](commonEventManager-definitions.md#common_event_user_started)替代。

  - 值：usual.event.USER_STARTED
  - 订阅者所需权限：无


* COMMON_EVENT_USER_BACKGROUND<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户已被带到后台。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USER_BACKGROUND](commonEventManager-definitions.md#common_event_user_background)替代。

  - 值：usual.event.USER_BACKGROUND
  - 订阅者所需权限：无


* COMMON_EVENT_USER_FOREGROUND<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户已被带到前台。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USER_FOREGROUND](commonEventManager-definitions.md#common_event_user_foreground)替代。

  - 值：usual.event.USER_FOREGROUND
  - 订阅者所需权限：无


* COMMON_EVENT_USER_SWITCHED<sup>(deprecated)</sup> 提示用户正在切换。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用COMMON_EVENT_USER_SWITCHED替代。

  - 值：usual.event.USER_SWITCHED
  - 订阅者所需权限：ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。


* COMMON_EVENT_USER_STARTING<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户正在启动。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USER_STARTING](commonEventManager-definitions.md#common_event_user_starting)替代。

  - 值：usual.event.USER_STARTING
  - 订阅者所需权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，该权限仅系统应用可申请。


* COMMON_EVENT_USER_UNLOCKED<sup>(deprecated)</sup> （预留事件，暂未支持）在重启后解锁时，提示当前用户的凭据加密存储已解锁。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USER_UNLOCKED](commonEventManager-definitions.md#common_event_user_unlocked)替代。

  - 值：usual.event.USER_UNLOCKED
  - 订阅者所需权限：无


* COMMON_EVENT_USER_STOPPING<sup>(deprecated)</sup> （预留事件，暂未支持）提示要停止用户。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USER_STOPPING](commonEventManager-definitions.md#common_event_user_stopping)替代。

  - 值：usual.event.USER_STOPPING
  - 订阅者所需权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，该权限仅系统应用可申请。


* COMMON_EVENT_USER_STOPPED<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户已停止。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USER_STOPPED](commonEventManager-definitions.md#common_event_user_stopped)替代。

  - 值：usual.event.USER_STOPPED
  - 订阅者所需权限：无


* COMMON_EVENT_WIFI_POWER_STATE<sup>(deprecated)</sup> 提示Wi-Fi功能状态的变更，如启用或禁用。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_POWER_STATE](commonEventManager-definitions.md#common_event_wifi_power_state)替代。

  - 值：usual.event.wifi.POWER_STATE
  - 订阅者所需权限：无


* COMMON_EVENT_WIFI_SCAN_FINISHED<sup>(deprecated)</sup> 提示Wi-Fi接入点已被扫描并证明可用。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_SCAN_FINISHED](commonEventManager-definitions.md#common_event_wifi_scan_finished)替代。

  - 值：usual.event.wifi.SCAN_FINISHED
  - 订阅者所需权限：ohos.permission.LOCATION


* COMMON_EVENT_WIFI_RSSI_VALUE<sup>(deprecated)</sup> 提示Wi-Fi信号强度（RSSI）改变。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_RSSI_VALUE](commonEventManager-definitions.md#common_event_wifi_rssi_value)替代。

  - 值：usual.event.wifi.RSSI_VALUE
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_CONN_STATE<sup>(deprecated)</sup> 提示Wi-Fi连接状态发生改变。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_CONN_STATE](commonEventManager-definitions.md#common_event_wifi_conn_state)替代。

  - 值：usual.event.wifi.CONN_STATE
  - 订阅者所需权限：无


* COMMON_EVENT_WIFI_HOTSPOT_STATE<sup>(deprecated)</sup> 提示Wi-Fi热点功能状态的变更，如启用或禁用。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_HOTSPOT_STATE](commonEventManager-definitions.md#common_event_wifi_hotspot_state)替代。

  - 值：usual.event.wifi.HOTSPOT_STATE
  - 订阅者所需权限：无


* COMMON_EVENT_WIFI_AP_STA_JOIN<sup>(deprecated)</sup> 提示有客户端加入当前设备Wi-Fi热点。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_AP_STA_JOIN](commonEventManager-definitions.md#common_event_wifi_ap_sta_join)替代。

  - 值：usual.event.wifi.WIFI_HS_STA_JOIN
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_AP_STA_LEAVE<sup>(deprecated)</sup> 提示客户端已断开与当前设备Wi-Fi热点的连接。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_AP_STA_LEAVE](commonEventManager-definitions.md#common_event_wifi_ap_sta_leave)替代。

  - 值：usual.event.wifi.WIFI_HS_STA_LEAVE
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE<sup>(deprecated)</sup> 提示MPLink（增强Wi-Fi功能）状态已更改（暂不支持）。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE](commonEventManager-definitions.md#common_event_wifi_mplink_state_change)替代。

  - 值：usual.event.wifi.mplink.STATE_CHANGE
  - 订阅者所需权限：无


* COMMON_EVENT_WIFI_P2P_CONN_STATE<sup>(deprecated)</sup> 提示Wi-Fi P2P连接状态改变。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_P2P_CONN_STATE](commonEventManager-definitions.md#common_event_wifi_p2p_conn_state)替代。

  - 值：usual.event.wifi.p2p.CONN_STATE_CHANGE
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION


* COMMON_EVENT_WIFI_P2P_STATE_CHANGED<sup>(deprecated)</sup> 提示Wi-Fi P2P状态发生变更，如启用和禁用。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_P2P_STATE_CHANGED](commonEventManager-definitions.md#common_event_wifi_p2p_state_changed)替代。

  - 值：usual.event.wifi.p2p.STATE_CHANGE
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED<sup>(deprecated)</sup> 提示Wi-Fi P2P对等体状态变化。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED](commonEventManager-definitions.md#common_event_wifi_p2p_peers_state_changed)替代。

  - 值：usual.event.wifi.p2p.DEVICES_CHANGE
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED<sup>(deprecated)</sup> 提示Wi-Fi P2P发现状态变化。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED](commonEventManager-definitions.md#common_event_wifi_p2p_peers_discovery_state_changed)替代。

  - 值：usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED<sup>(deprecated)</sup> 提示Wi-Fi P2P当前设备状态变化。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED](commonEventManager-definitions.md#common_event_wifi_p2p_current_device_state_changed)替代。

  - 值：usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED<sup>(deprecated)</sup> 提示Wi-Fi P2P群组信息已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED](commonEventManager-definitions.md#common_event_wifi_p2p_group_state_changed)替代。

  - 值：usual.event.wifi.p2p.GROUP_STATE_CHANGED
  - 订阅者所需权限：ohos.permission.GET_WIFI_INFO


* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙免提通信连接状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_handsfree_ag_connect_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示连接到具有蓝牙免提功能的设备处于活动状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_handsfree_ag_current_device_updatedeprecated)替代。

  - 值：usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙A2DP连接状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_handsfree_ag_audio_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙A2DP连接状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_a2dpsource_connect_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示使用蓝牙A2DP连接的设备处于活动状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_a2dpsource_current_device_updatedeprecated)替代。

  - 值：usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙A2DP播放状态发生改变。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_a2dpsource_playing_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙A2DP的AVRCP连接状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_a2dpsource_avrcp_connect_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙A2DP音频编解码状态更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_a2dpsource_codec_value_updatedeprecated)替代。

  - 值：usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED<sup>(deprecated)</sup> （预留事件，暂未支持）提示发现远程蓝牙设备。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_discovereddeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.DISCOVERED
  - 订阅者所需权限：ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备的蓝牙类别已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_class_value_updatedeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED<sup>(deprecated)</sup> （预留事件，暂未支持）提示已与远程蓝牙设备建立低级别（ACL）连接。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_acl_connecteddeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.ACL_CONNECTED
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED<sup>(deprecated)</sup> （预留事件，暂未支持）提示低级别（ACL）连接已从远程蓝牙设备断开。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_acl_disconnecteddeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.ACL_DISCONNECTED
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备的友好名称首次被检索或自上次检索以来被更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_name_updatedeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.NAME_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备连接状态更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_pair_statedeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.PAIR_STATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备的电池电量首次被检索或自上次检索以来被更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_battery_value_updatedeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备SDP状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_sdp_resultdeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.SDP_RESULT
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备UUID连接状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_uuid_valuedeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.UUID_VALUE
  - 订阅者所需权限：ohos.permission.DISCOVER_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备配对请求。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_pairing_reqdeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.PAIRING_REQ
  - 订阅者所需权限：ohos.permission.DISCOVER_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL<sup>(deprecated)</sup> （预留事件，暂未支持）提示取消蓝牙配对。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_pairing_canceldeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.PAIRING_CANCEL
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备连接请求。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_connect_reqdeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.CONNECT_REQ
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY<sup>(deprecated)</sup> （预留事件，暂未支持）提示远程蓝牙设备连接请求响应。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_connect_replydeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.CONNECT_REPLY
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL<sup>(deprecated)</sup> （预留事件，暂未支持）提示取消与远程蓝牙设备的连接。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL](commonEventManager-definitions.md#common_event_bluetooth_remotedevice_connect_canceldeprecated)替代。

  - 值：usual.event.bluetooth.remotedevice.CONNECT_CANCEL
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙免提连接状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_handsfreeunit_connect_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙免提音频状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_handsfreeunit_audio_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙免提音频网关状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT](commonEventManager-definitions.md#common_event_bluetooth_handsfreeunit_ag_common_eventdeprecated)替代。

  - 值：usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙免提呼叫状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_handsfreeunit_ag_call_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙适配器状态已更改，例如蓝牙已打开或关闭。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_host_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.host.STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户允许扫描蓝牙请求。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE](commonEventManager-definitions.md#common_event_bluetooth_host_req_discoverabledeprecated)替代。

  - 值：usual.event.bluetooth.host.REQ_DISCOVERABLE
  - 订阅者所需权限：无


* COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户打开蓝牙请求。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE](commonEventManager-definitions.md#common_event_bluetooth_host_req_enabledeprecated)替代。

  - 值：usual.event.bluetooth.host.REQ_ENABLE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户关闭蓝牙请求。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE](commonEventManager-definitions.md#common_event_bluetooth_host_req_disabledeprecated)替代。

  - 值：usual.event.bluetooth.host.REQ_DISABLE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备蓝牙扫描模式更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_host_scan_mode_updatedeprecated)替代。

  - 值：usual.event.bluetooth.host.SCAN_MODE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备上已启动蓝牙扫描。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED](commonEventManager-definitions.md#common_event_bluetooth_host_discovery_starteddeprecated)替代。

  - 值：usual.event.bluetooth.host.DISCOVERY_STARTED
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备上蓝牙扫描完成。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED](commonEventManager-definitions.md#common_event_bluetooth_host_discovery_finisheddeprecated)替代。

  - 值：usual.event.bluetooth.host.DISCOVERY_FINISHED
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备蓝牙适配器名称已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_host_name_updatedeprecated)替代。

  - 值：usual.event.bluetooth.host.NAME_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙A2DP宿的连接状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_a2dpsink_connect_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙A2DP宿的播放状态发生改变。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_a2dpsink_playing_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE<sup>(deprecated)</sup> （预留事件，暂未支持）提示蓝牙A2DP宿的音频状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE](commonEventManager-definitions.md#common_event_bluetooth_a2dpsink_audio_state_updatedeprecated)替代。

  - 值：usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE
  - 订阅者所需权限：ohos.permission.USE_BLUETOOTH


* COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED<sup>(deprecated)</sup> （预留事件，暂未支持）提示设备NFC适配器状态已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED](commonEventManager-definitions.md#common_event_nfc_action_adapter_state_changed)替代。

  - 值：usual.event.nfc.action.ADAPTER_STATE_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED<sup>(deprecated)</sup> （预留事件，暂未支持）提示检测到NFC设备RF字段处于使能状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED](commonEventManager-definitions.md#common_event_nfc_action_rf_field_on_detected)替代。

  - 值：usual.event.nfc.action.RF_FIELD_ON_DETECTED
  - 订阅者所需权限：ohos.permission.MANAGE_SECURE_SETTINGS（该权限仅系统应用可申请）


* COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED<sup>(deprecated)</sup> （预留事件，暂未支持）提示检测到NFC设备RF字段处于关闭状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED](commonEventManager-definitions.md#common_event_nfc_action_rf_field_off_detected)替代。

  - 值：usual.event.nfc.action.RF_FIELD_OFF_DETECTED
  - 订阅者所需权限：ohos.permission.MANAGE_SECURE_SETTINGS（该权限仅系统应用可申请）


* COMMON_EVENT_DISCHARGING<sup>(deprecated)</sup> 提示系统停止为电池充电。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DISCHARGING](commonEventManager-definitions.md#common_event_discharging)替代。

  - 值：usual.event.DISCHARGING
  - 订阅者所需权限：无


* COMMON_EVENT_CHARGING<sup>(deprecated)</sup> 提示系统开始为电池充电。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_CHARGING](commonEventManager-definitions.md#common_event_charging)替代。

  - 值：usual.event.CHARGING
  - 订阅者所需权限：无


* COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED<sup>(deprecated)</sup> （预留事件，暂未支持）提示系统空闲模式已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED](commonEventManager-definitions.md#common_event_device_idle_mode_changed)替代。

  - 值：usual.event.DEVICE_IDLE_MODE_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_POWER_SAVE_MODE_CHANGED<sup>(deprecated)</sup> 提示系统节能模式更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_POWER_SAVE_MODE_CHANGED](commonEventManager-definitions.md#common_event_power_save_mode_changed)替代。

  - 值：usual.event.POWER_SAVE_MODE_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_USER_ADDED<sup>(deprecated)</sup> 提示用户已添加到系统中。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用COMMON_EVENT_USER_ADDED替代。

  - 值：usual.event.USER_ADDED
  - 订阅者所需权限：ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。


* COMMON_EVENT_USER_REMOVED<sup>(deprecated)</sup> 提示用户已从系统中删除。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用COMMON_EVENT_USER_REMOVED替代。

  - 值：usual.event.USER_REMOVED
  - 订阅者所需权限：ohos.permission.MANAGE_LOCAL_ACCOUNTS，该权限仅系统应用可申请。


* COMMON_EVENT_ABILITY_ADDED<sup>(deprecated)</sup> （预留事件，暂未支持）提示有某个能力已被添加。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_ABILITY_ADDED](commonEventManager-definitions.md#common_event_ability_added)替代。

  - 值：usual.event.ABILITY_ADDED
  - 订阅者所需权限：ohos.permission.LISTEN_BUNDLE_CHANGE


* COMMON_EVENT_ABILITY_REMOVED<sup>(deprecated)</sup> （预留事件，暂未支持）提示已删除某个能力。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_ABILITY_REMOVED](commonEventManager-definitions.md#common_event_ability_removed)替代。

  - 值：usual.event.ABILITY_REMOVED
  - 订阅者所需权限：ohos.permission.LISTEN_BUNDLE_CHANGE


* COMMON_EVENT_ABILITY_UPDATED<sup>(deprecated)</sup> （预留事件，暂未支持）提示能力已更新。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_ABILITY_UPDATED](commonEventManager-definitions.md#common_event_ability_updated)替代。

  - 值：usual.event.ABILITY_UPDATED
  - 订阅者所需权限：ohos.permission.LISTEN_BUNDLE_CHANGE


* COMMON_EVENT_LOCATION_MODE_STATE_CHANGED<sup>(deprecated)</sup> （预留事件，暂未支持）提示系统定位模式已更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_LOCATION_MODE_STATE_CHANGED](commonEventManager-definitions.md#common_event_location_mode_state_changed)替代。

  - 值：usual.event.location.MODE_STATE_CHANGED
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_SLEEP<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统正在休眠。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_SLEEP](commonEventManager-definitions.md#common_event_ivi_sleep)替代。

  - 值：common.event.IVI_SLEEP
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_PAUSE<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统已休眠，并通知应用程序停止播放。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_PAUSE](commonEventManager-definitions.md#common_event_ivi_pause)替代。

  - 值：common.event.IVI_PAUSE
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_STANDBY<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统中的第三方应用暂停当前工作。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_STANDBY](commonEventManager-definitions.md#common_event_ivi_standby)替代。

  - 值：common.event.IVI_STANDBY
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_LASTMODE_SAVE<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统中的第三方应用保存其最后一个模式。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_LASTMODE_SAVE](commonEventManager-definitions.md#common_event_ivi_lastmode_save)替代。

  - 值：common.event.IVI_LASTMODE_SAVE
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_VOLTAGE_ABNORMAL<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆电源系统电压异常。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_VOLTAGE_ABNORMAL](commonEventManager-definitions.md#common_event_ivi_voltage_abnormal)替代。

  - 值：common.event.IVI_VOLTAGE_ABNORMAL
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_HIGH_TEMPERATURE<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统温度过高。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_HIGH_TEMPERATURE](commonEventManager-definitions.md#common_event_ivi_high_temperature)替代。

  - 值：common.event.IVI_HIGH_TEMPERATURE
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_EXTREME_TEMPERATURE<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统温度极高。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_EXTREME_TEMPERATURE](commonEventManager-definitions.md#common_event_ivi_extreme_temperature)替代。

  - 值：common.event.IVI_EXTREME_TEMPERATURE
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆的车载信息娱乐（IVI）系统具有极端温度。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL](commonEventManager-definitions.md#common_event_ivi_temperature_abnormal)替代。

  - 值：common.event.IVI_TEMPERATURE_ABNORMAL
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_VOLTAGE_RECOVERY<sup>(deprecated)</sup> （预留事件，暂未支持）提示车辆电源系统电压恢复正常。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_VOLTAGE_RECOVERY](commonEventManager-definitions.md#common_event_ivi_voltage_recovery)替代。

  - 值：common.event.IVI_VOLTAGE_RECOVERY
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_TEMPERATURE_RECOVERY<sup>(deprecated)</sup> （预留事件，暂未支持）提示车载系统温度恢复正常。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_TEMPERATURE_RECOVERY](commonEventManager-definitions.md#common_event_ivi_temperature_recovery)替代。

  - 值：common.event.IVI_TEMPERATURE_RECOVERY
  - 订阅者所需权限：无


* COMMON_EVENT_IVI_ACTIVE<sup>(deprecated)</sup> （预留事件，暂未支持）提示车载系统电池服务处于活动状态。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_IVI_ACTIVE](commonEventManager-definitions.md#common_event_ivi_active)替代。

  - 值：common.event.IVI_ACTIVE
  - 订阅者所需权限：无

* COMMON_EVENT_USB_DEVICE_ATTACHED<sup>(deprecated)</sup> 当用户设备作为USB主机时，提示USB设备已挂载。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USB_DEVICE_ATTACHED](commonEventManager-definitions.md#common_event_usb_device_attached)替代。

  - 值：usual.event.hardware.usb.action.USB_DEVICE_ATTACHED
  - 订阅者所需权限：无


* COMMON_EVENT_USB_DEVICE_DETACHED<sup>(deprecated)</sup> 当用户设备作为USB主机时，提示USB设备被卸载。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USB_DEVICE_DETACHED](commonEventManager-definitions.md#common_event_usb_device_detached)替代。

  - 值：usual.event.hardware.usb.action.USB_DEVICE_DETACHED
  - 订阅者所需权限：无


* COMMON_EVENT_USB_ACCESSORY_ATTACHED<sup>(deprecated)</sup> （预留事件，暂未支持）提示已连接USB附件。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USB_ACCESSORY_ATTACHED](commonEventManager-definitions.md#common_event_usb_accessory_attached)替代。

  - 值：usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED
  - 订阅者所需权限：无


* COMMON_EVENT_USB_ACCESSORY_DETACHED<sup>(deprecated)</sup> （预留事件，暂未支持）提示USB附件被卸载。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_USB_ACCESSORY_DETACHED](commonEventManager-definitions.md#common_event_usb_accessory_detached)替代。

  - 值：usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED
  - 订阅者所需权限：无


* COMMON_EVENT_DISK_REMOVED<sup>(deprecated)</sup> （预留事件，暂未支持）提示外部存储设备状态变更为移除。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DISK_REMOVED](commonEventManager-definitions.md#common_event_disk_removed)替代。

  - 值：usual.event.data.DISK_REMOVED
  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER，该权限仅系统应用可申请。


* COMMON_EVENT_DISK_UNMOUNTED<sup>(deprecated)</sup> （预留事件，暂未支持）提示外部存储设备状态变更为卸载。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DISK_UNMOUNTED](commonEventManager-definitions.md#common_event_disk_unmounted)替代。

  - 值：usual.event.data.DISK_UNMOUNTED
  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER，该权限仅系统应用可申请。


* COMMON_EVENT_DISK_MOUNTED<sup>(deprecated)</sup> （预留事件，暂未支持）提示外部存储设备状态变更为挂载。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DISK_MOUNTED](commonEventManager-definitions.md#common_event_disk_mounted)替代。

  - 值：usual.event.data.DISK_MOUNTED
  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER，该权限仅系统应用可申请。


* COMMON_EVENT_DISK_BAD_REMOVAL<sup>(deprecated)</sup> （预留事件，暂未支持）提示外部存储设备在挂载状态下被移除。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DISK_BAD_REMOVAL](commonEventManager-definitions.md#common_event_disk_bad_removal)替代。

  - 值：usual.event.data.DISK_BAD_REMOVAL
  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER，该权限仅系统应用可申请。


* COMMON_EVENT_DISK_UNMOUNTABLE<sup>(deprecated)</sup> （预留事件，暂未支持）提示外部存储设备在插卡情况下无法挂载。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DISK_UNMOUNTABLE](commonEventManager-definitions.md#common_event_disk_unmountable)替代。

  - 值：usual.event.data.DISK_UNMOUNTABLE
  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER，该权限仅系统应用可申请。


* COMMON_EVENT_DISK_EJECT<sup>(deprecated)</sup> （预留事件，暂未支持）提示用户已作出弹出外部存储介质的操作（系统软件层面的交互操作，非直接物理弹出）。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_DISK_EJECT](commonEventManager-definitions.md#common_event_disk_eject)替代。

  - 值：usual.event.data.DISK_EJECT
  - 订阅者所需权限：ohos.permission.STORAGE_MANAGER，该权限仅系统应用可申请。


* COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED<sup>(deprecated)</sup> （预留事件，暂未支持）提示账户发生可见性的更改。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED](commonEventManager-definitions.md#common_event_visible_accounts_updated)替代。

  - 值：usual.event.data.VISIBLE_ACCOUNTS_UPDATED
  - 订阅者所需权限：ohos.permission.GET_APP_ACCOUNTS，该权限仅系统应用可申请。


* COMMON_EVENT_ACCOUNT_DELETED<sup>(deprecated)</sup> （预留事件，暂未支持）提示有账户被删除。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_ACCOUNT_DELETED](commonEventManager-definitions.md#common_event_account_deleted)替代。

  - 值：usual.event.data.ACCOUNT_DELETED
  - 订阅者所需权限：ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS，该权限仅系统应用可申请。


* COMMON_EVENT_FOUNDATION_READY<sup>(deprecated)</sup> （预留事件，暂未支持）提示foundation已准备好。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_FOUNDATION_READY](commonEventManager-definitions.md#common_event_foundation_ready)替代。

  - 值：usual.event.data.FOUNDATION_READY
  - 订阅者所需权限：ohos.permission.RECEIVER_STARTUP_COMPLETED（该权限仅系统应用可申请）


* COMMON_EVENT_AIRPLANE_MODE_CHANGED<sup>(deprecated)</sup> 提示设备飞行模式发生了切换。

  > **说明：**
  >
  > 从API version 7 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_AIRPLANE_MODE_CHANGED](commonEventManager-definitions.md#common_event_airplane_mode_changed10)替代。

  - 值：usual.event.AIRPLANE_MODE
  - 订阅者所需权限：无

* COMMON_EVENT_SPLIT_SCREEN<sup>(deprecated)</sup> 提示分屏。

  > **说明：**
  >
  > 从API version 8 开始支持，从API version 9 开始废弃，建议使用[COMMON_EVENT_SPLIT_SCREEN](commonEventManager-definitions.md#common_event_split_screen)替代。