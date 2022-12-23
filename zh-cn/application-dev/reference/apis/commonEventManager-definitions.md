# 系统公共事件定义

本文档提供OpenHarmony系统所定义的公共事件类型的索引。
公共事件类型定义在[ohos.commonEvent模块的Support枚举](./js-apis-commonEventManager.md#support)中。

**系统能力：** SystemCapability.Notification.CommonEvent

## COMMON_EVENT_BOOT_COMPLETED
表示用户已完成引导并加载系统的公共事件的操作。
- 值： usual.event.BOOT_COMPLETED
- 订阅者所需权限： ohos.permission.RECEIVER_STARTUP_COMPLETED

## COMMON_EVENT_LOCKED_BOOT_COMPLETED
（预留事件，暂未支持）表示用户已完成引导，系统已加载，但屏幕仍锁定的公共事件的操作。
- 值： usual.event.LOCKED_BOOT_COMPLETED
- 订阅者所需权限： ohos.permission.RECEIVER_STARTUP_COMPLETED

## COMMON_EVENT_SHUTDOWN
表示设备正在关闭并将继续最终关闭的公共事件的操作。
- 值： usual.event.SHUTDOWN
- 订阅者所需权限： 无

## COMMON_EVENT_BATTERY_CHANGED
表示电池充电状态、电平和其他信息发生变化的公共事件的动作。
- 值： usual.event.BATTERY_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_BATTERY_LOW
表示电池电量低的普通事件的动作。
- 值： usual.event.BATTERY_LOW
- 订阅者所需权限： 无

## COMMON_EVENT_BATTERY_OKAY
表示电池退出低电平状态的公共事件的动作。
- 值： usual.event.BATTERY_OKAY
- 订阅者所需权限： 无

## COMMON_EVENT_POWER_CONNECTED
设备连接到外部电源的公共事件的动作。
- 值： usual.event.POWER_CONNECTED
- 订阅者所需权限： 无

## COMMON_EVENT_POWER_DISCONNECTED
设备与外部电源断开的公共事件的动作。
- 值： usual.event.POWER_DISCONNECTED
- 订阅者所需权限： 无

## COMMON_EVENT_SCREEN_OFF
表示设备屏幕关闭且设备处于睡眠状态的普通事件的动作。
- 值： usual.event.SCREEN_OFF
- 订阅者所需权限： 无

## COMMON_EVENT_SCREEN_ON
表示设备屏幕打开且设备处于交互状态的公共事件的操作。
- 值： usual.event.SCREEN_ON
- 订阅者所需权限： 无

## COMMON_EVENT_THERMAL_LEVEL_CHANGED
表示设备热状态的公共事件的动作。
- 值： usual.event.THERMAL_LEVEL_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_USER_PRESENT
（预留事件，暂未支持）用户解锁设备的公共事件的动作。
- 值： usual.event.USER_PRESENT
- 订阅者所需权限： 无

## COMMON_EVENT_TIME_TICK
表示系统时间更改的公共事件的动作。
- 值： usual.event.TIME_TICK
- 订阅者所需权限： 无

## COMMON_EVENT_TIME_CHANGED
设置系统时间的公共事件的动作。
- 值： usual.event.TIME_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_DATE_CHANGED
（预留事件，暂未支持）表示系统日期已更改的公共事件的动作。
- 值： usual.event.DATE_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_TIMEZONE_CHANGED
表示系统时区更改的公共事件的动作。
- 值： usual.event.TIMEZONE_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_CLOSE_SYSTEM_DIALOGS
（预留事件，暂未支持）表示用户关闭临时系统对话框的公共事件的动作。
- 值： usual.event.CLOSE_SYSTEM_DIALOGS
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_ADDED
设备上已安装新应用包的公共事件的动作。
- 值： usual.event.PACKAGE_ADDED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_REPLACED
（预留事件，暂未支持）表示已安装的应用程序包的新版本已替换设备上的旧版本的公共事件的操作。
- 值： usual.event.PACKAGE_REPLACED
- 订阅者所需权限： 无

## COMMON_EVENT_MY_PACKAGE_REPLACED
（预留事件，暂未支持）表示应用程序包的新版本已取代前一个版本的公共事件的操作。
- 值： usual.event.MY_PACKAGE_REPLACED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_REMOVED
表示已从设备卸载已安装的应用程序，但应用程序数据保留的公共事件的操作。
- 值： usual.event.PACKAGE_REMOVED
- 订阅者所需权限： 无

## COMMON_EVENT_BUNDLE_REMOVED
（预留事件，暂未支持）表示已从设备中卸载已安装的捆绑包，但应用程序数据仍保留的公共事件的操作。
- 值： usual.event.BUNDLE_REMOVED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_FULLY_REMOVED
（预留事件，暂未支持）表示已从设备中完全卸载已安装的应用程序（包括应用程序数据和代码）的公共事件的操作。
- 值： usual.event.PACKAGE_FULLY_REMOVED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_CHANGED
表示应用包已更改的公共事件的动作（例如，包中的组件已启用或禁用）。
- 值： usual.event.PACKAGE_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_RESTARTED
表示用户重启应用包并杀死其所有进程的普通事件的动作。
- 值： usual.event.PACKAGE_RESTARTED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_DATA_CLEARED
用户清除应用包数据的公共事件的动作。
- 值： usual.event.PACKAGE_DATA_CLEARED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_CACHE_CLEARED<sup>9+</sup>
用户清除应用包缓存数据的公共事件的动作。
- 值： usual.event.PACKAGE_CACHE_CLEARED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGES_SUSPENDED
（预留事件，暂未支持）表示应用包已挂起的公共事件的动作。
- 值： usual.event.PACKAGES_SUSPENDED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGES_UNSUSPENDED
（预留事件，暂未支持）表示应用包未挂起的公共事件的动作。
- 值： usual.event.PACKAGES_UNSUSPENDED
- 订阅者所需权限： 无

## COMMON_EVENT_MY_PACKAGE_SUSPENDED
应用包被挂起的公共事件的动作。
- 值： usual.event.MY_PACKAGE_SUSPENDED
- 订阅者所需权限： 无

## COMMON_EVENT_MY_PACKAGE_UNSUSPENDED
表示应用包未挂起的公共事件的动作。
- 值： usual.event.MY_PACKAGE_UNSUSPENDED
- 订阅者所需权限： 无

## COMMON_EVENT_UID_REMOVED
（预留事件，暂未支持）表示用户ID已从系统中删除的公共事件的动作。
- 值： usual.event.UID_REMOVED
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_FIRST_LAUNCH
（预留事件，暂未支持）表示首次启动已安装应用程序的公共事件的动作。
- 值： usual.event.PACKAGE_FIRST_LAUNCH
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION
（预留事件，暂未支持）表示应用需要系统校验的公共事件的动作。
- 值： usual.event.PACKAGE_NEEDS_VERIFICATION
- 订阅者所需权限： 无

## COMMON_EVENT_PACKAGE_VERIFIED
（预留事件，暂未支持）表示应用已被系统校验的公共事件的动作。
- 值： usual.event.PACKAGE_VERIFIED
- 订阅者所需权限： 无

## COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE
（预留事件，暂未支持）表示安装在外部存储上的应用程序对系统可用的公共事件的操作。
- 值： usual.event.EXTERNAL_APPLICATIONS_AVAILABLE
- 订阅者所需权限： 无

## COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE
（预留事件，暂未支持）表示安装在外部存储上的应用程序对系统不可用的公共事件的操作。
- 值： usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE
- 订阅者所需权限： 无

## COMMON_EVENT_CONFIGURATION_CHANGED
（预留事件，暂未支持）表示设备状态（例如，方向和区域设置）已更改的公共事件的操作。
- 值： usual.event.CONFIGURATION_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_LOCALE_CHANGED
（预留事件，暂未支持）表示设备区域设置已更改的公共事件的操作。
- 值： usual.event.LOCALE_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_MANAGE_PACKAGE_STORAGE
（预留事件，暂未支持）设备存储空间不足的公共事件的动作。
- 值： usual.event.MANAGE_PACKAGE_STORAGE
- 订阅者所需权限： 无

## COMMON_EVENT_DRIVE_MODE
（预留事件，暂未支持）表示系统处于驾驶模式的公共事件的动作。
- 值： common.event.DRIVE_MODE
- 订阅者所需权限： 无

## COMMON_EVENT_HOME_MODE
（预留事件，暂未支持）表示系统处于HOME模式的公共事件的动作。
- 值： common.event.HOME_MODE
- 订阅者所需权限： 无

## COMMON_EVENT_OFFICE_MODE
（预留事件，暂未支持）表示系统处于办公模式的公共事件的动作。
- 值： common.event.OFFICE_MODE
- 订阅者所需权限： 无

## COMMON_EVENT_USER_STARTED
（预留事件，暂未支持）表示用户已启动的公共事件的动作。
- 值： usual.event.USER_STARTED
- 订阅者所需权限： 无

## COMMON_EVENT_USER_BACKGROUND
（预留事件，暂未支持）表示用户已被带到后台的公共事件的动作。
- 值： usual.event.USER_BACKGROUND
- 订阅者所需权限： 无

## COMMON_EVENT_USER_FOREGROUND
（预留事件，暂未支持）表示用户已被带到前台的公共事件的动作。
- 值： usual.event.USER_FOREGROUND
- 订阅者所需权限： 无

## COMMON_EVENT_USER_SWITCHED
表示用户切换正在发生的公共事件的动作。
- 值： usual.event.USER_SWITCHED
- 订阅者所需权限： ohos.permission.MANAGE_LOCAL_ACCOUNTS

## COMMON_EVENT_USER_STARTING
（预留事件，暂未支持）表示要启动用户的公共事件的动作。
- 值： usual.event.USER_STARTING
- 订阅者所需权限： ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

## COMMON_EVENT_USER_UNLOCKED
（预留事件，暂未支持）设备重启后解锁时，当前用户的凭据加密存储已解锁的公共事件的动作。
- 值： usual.event.USER_UNLOCKED
- 订阅者所需权限： 无

## COMMON_EVENT_USER_STOPPING
（预留事件，暂未支持）表示要停止用户的公共事件的动作。
- 值： usual.event.USER_STOPPING
- 订阅者所需权限： ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

## COMMON_EVENT_USER_STOPPED
（预留事件，暂未支持）表示用户已停止的公共事件的动作。
- 值： usual.event.USER_STOPPED
- 订阅者所需权限： 无

## COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN
（预留事件，暂未支持）表示分布式账号登录成功的动作。
- 值： usual.event.DISTRIBUTED_ACCOUNT_LOGIN
- 订阅者所需权限： 无

## COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT
（预留事件，暂未支持）表示分布式账号登出成功的动作。
- 值： usual.event.DISTRIBUTED_ACCOUNT_LOGOUT
- 订阅者所需权限： 无

## COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID
（预留事件，暂未支持）表示分布式账号token令牌无效的动作。
- 值： usual.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID
- 订阅者所需权限： 无

## COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF
（预留事件，暂未支持）表示分布式账号注销的动作。
- 值： usual.event.DISTRIBUTED_ACCOUNT_LOGOFF
- 订阅者所需权限： 无

## COMMON_EVENT_WIFI_POWER_STATE
Wi-Fi状态公共事件的动作，如启用和禁用。
- 值： usual.event.wifi.POWER_STATE
- 订阅者所需权限： 无

## COMMON_EVENT_WIFI_SCAN_FINISHED
表示Wi-Fi接入点已被扫描并证明可用的公共事件的操作。
- 值： usual.event.wifi.SCAN_FINISHED
- 订阅者所需权限： ohos.permission.LOCATION

## COMMON_EVENT_WIFI_RSSI_VALUE
表示Wi-Fi信号强度（RSSI）改变的公共事件的动作。
- 值： usual.event.wifi.RSSI_VALUE
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO

## COMMON_EVENT_WIFI_CONN_STATE
Wi-Fi连接状态发生改变的公共事件的动作
- 值： usual.event.wifi.CONN_STATE
- 订阅者所需权限： 无

## COMMON_EVENT_WIFI_HOTSPOT_STATE
Wi-Fi热点状态的公共事件的动作，如启用或禁用。
- 值： usual.event.wifi.HOTSPOT_STATE
- 订阅者所需权限： 无

## COMMON_EVENT_WIFI_AP_STA_JOIN
客户端加入当前设备Wi-Fi热点的普通事件的动作。
- 值： usual.event.wifi.WIFI_HS_STA_JOIN
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO

## COMMON_EVENT_WIFI_AP_STA_LEAVE
客户端已断开与当前设备Wi-Fi热点的连接的公共事件的动作。
- 值： usual.event.wifi.WIFI_HS_STA_LEAVE
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO

## COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE
表示MPLink（增强Wi-Fi功能）状态已更改的公共事件的动作。
- 值： usual.event.wifi.mplink.STATE_CHANGE
- 订阅者所需权限： ohos.permission.MPLINK_CHANGE_STATE

## COMMON_EVENT_WIFI_P2P_CONN_STATE
 Wi-Fi P2P连接状态改变的公共事件的动作。
- 值： usual.event.wifi.p2p.CONN_STATE_CHANGE
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO和ohos.permission.LOCATION

## COMMON_EVENT_WIFI_P2P_STATE_CHANGED
Wi-Fi P2P状态公共事件的动作，如启用和禁用。
- 值： usual.event.wifi.p2p.STATE_CHANGE
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO

## COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED
Wi-Fi P2P对等体状态变化。
- 值： usual.event.wifi.p2p.DEVICES_CHANGE
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO

## COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED
Wi-Fi P2P发现状态变化。
- 值： usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO

## COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED
Wi-Fi P2P当前设备状态变化。
- 值： usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO

## COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED
Wi-Fi P2P群组信息已更改。
- 值： usual.event.wifi.p2p.GROUP_STATE_CHANGED
- 订阅者所需权限： ohos.permission.GET_WIFI_INFO

## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE
（预留事件，暂未支持）蓝牙免提通信连接状态公共事件的动作。
- 值： usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE
（预留事件，暂未支持）表示连接到蓝牙免提的设备处于活动状态的公共事件的动作。
- 值： usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE
（预留事件，暂未支持）表示蓝牙A2DP连接状态已更改的公共事件的动作。
- 值： usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE
（预留事件，暂未支持）蓝牙A2DP连接状态公共事件的动作。
- 值： usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE
（预留事件，暂未支持）表示使用蓝牙A2DP连接的设备处于活动状态的公共事件的动作。
- 值： usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE
（预留事件，暂未支持）蓝牙A2DP播放状态改变的普通事件的动作。
- 值： usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE
（预留事件，暂未支持）表示蓝牙A2DP的AVRCP连接状态已更改的公共事件的动作。
- 值： usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE
（预留事件，暂未支持）表示蓝牙A2DP音频编解码状态更改的公共事件的动作。
- 值： usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED
（预留事件，暂未支持）表示发现远程蓝牙设备的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.DISCOVERED
- 订阅者所需权限： ohos.permission.LOCATION和ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE
（预留事件，暂未支持）表示远程蓝牙设备的蓝牙类别已更改的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED
（预留事件，暂未支持）表示已与远程蓝牙设备建立低级别（ACL）连接的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.ACL_CONNECTED
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED
（预留事件，暂未支持）表示低电平（ACL）连接已从远程蓝牙设备断开的普通事件的动作。
- 值： usual.event.bluetooth.remotedevice.ACL_DISCONNECTED
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE
（预留事件，暂未支持）表示远程蓝牙设备的友好名称首次被检索或自上次检索以来被更改的公共事件的操作。
- 值： usual.event.bluetooth.remotedevice.NAME_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE
（预留事件，暂未支持）远程蓝牙设备连接状态更改的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.PAIR_STATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE
（预留事件，暂未支持）表示远程蓝牙设备的电池电量首次被检索或自上次检索以来被更改的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE
- 订阅者所需权限：ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT
（预留事件，暂未支持）远程蓝牙设备SDP状态公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.SDP_RESULT
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE
（预留事件，暂未支持）远程蓝牙设备UUID连接状态公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.UUID_VALUE
- 订阅者所需权限： ohos.permission.DISCOVER_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ
（预留事件，暂未支持）表示远程蓝牙设备配对请求的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.PAIRING_REQ
- 订阅者所需权限： ohos.permission.DISCOVER_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL
（预留事件，暂未支持）取消蓝牙配对的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.PAIRING_CANCEL
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ
（预留事件，暂未支持）表示远程蓝牙设备连接请求的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.CONNECT_REQ
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY
（预留事件，暂未支持）表示远程蓝牙设备连接请求响应的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.CONNECT_REPLY
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL
（预留事件，暂未支持）表示取消与远程蓝牙设备的连接的公共事件的动作。
- 值： usual.event.bluetooth.remotedevice.CONNECT_CANCEL
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE
（预留事件，暂未支持）表示蓝牙免提连接状态已更改的公共事件的动作。
- 值： usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE
（预留事件，暂未支持）表示蓝牙免提音频状态已更改的公共事件的动作。
- 值： usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT
（预留事件，暂未支持）表示蓝牙免提音频网关状态已更改的公共事件的动作。
- 值： usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE
（预留事件，暂未支持）表示蓝牙免提呼叫状态已更改的公共事件的动作。
- 值： usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE
（预留事件，暂未支持）表示蓝牙适配器状态已更改的公共事件的操作，例如蓝牙已打开或关闭。
- 值： usual.event.bluetooth.host.STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE
（预留事件，暂未支持）表示用户允许扫描蓝牙请求的公共事件的动作。
- 值： usual.event.bluetooth.host.REQ_DISCOVERABLE
- 订阅者所需权限： 无

## COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE
（预留事件，暂未支持）表示用户打开蓝牙请求的公共事件的动作
- 值： usual.event.bluetooth.host.REQ_ENABLE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE
（预留事件，暂未支持）表示用户关闭蓝牙请求的公共事件的动作。
- 值： usual.event.bluetooth.host.REQ_DISABLE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE
（预留事件，暂未支持）设备蓝牙扫描模式更改的公共事件的动作。
- 值： usual.event.bluetooth.host.SCAN_MODE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED
（预留事件，暂未支持）设备上已启动蓝牙扫描的公共事件的动作。
- 值： usual.event.bluetooth.host.DISCOVERY_STARTED
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED
（预留事件，暂未支持）设备上蓝牙扫描完成的公共事件的动作。
- 值： usual.event.bluetooth.host.DISCOVERY_FINISHED
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE
（预留事件，暂未支持）指示设备蓝牙适配器名称已更改的公共事件的操作。
- 值： usual.event.bluetooth.host.NAME_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE
（预留事件，暂未支持）表示蓝牙A2DP宿连接状态已更改的公共事件的动作。
- 值： usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE
（预留事件，暂未支持）蓝牙A2DP宿播放状态改变的普通事件的动作。
- 值： usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE
（预留事件，暂未支持）表示蓝牙A2DP宿的音频状态已更改的公共事件的动作。
- 值： usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE
- 订阅者所需权限： ohos.permission.USE_BLUETOOTH

## COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED
指示设备NFC适配器状态已更改的公共事件的操作。
- 值： usual.event.nfc.action.ADAPTER_STATE_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED
（预留事件，暂未支持）检测到NFC RF字段处于使能状态的公共事件的动作。
- 值： usual.event.nfc.action.RF_FIELD_ON_DETECTED
- 订阅者所需权限： ohos.permission.MANAGE_SECURE_SETTINGS

## COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED
（预留事件，暂未支持）检测到NFC RF字段处于关闭状态的公共事件的动作。
- 值： usual.event.nfc.action.RF_FIELD_OFF_DETECTED
- 订阅者所需权限： ohos.permission.MANAGE_SECURE_SETTINGS

## COMMON_EVENT_DISCHARGING
表示系统停止为电池充电的公共事件的动作。
- 值： usual.event.DISCHARGING
- 订阅者所需权限： 无

## COMMON_EVENT_CHARGING
表示系统开始为电池充电的公共事件的动作。
- 值： usual.event.CHARGING
- 订阅者所需权限： 无

## COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED
（预留事件，暂未支持）表示系统空闲模式已更改的公共事件的动作。
- 值： usual.event.DEVICE_IDLE_MODE_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_POWER_SAVE_MODE_CHANGED
表示系统节能模式更改的公共事件的动作。
- 值： usual.event.POWER_SAVE_MODE_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_USER_ADDED
表示用户已添加到系统中的公共事件的动作。
- 值： usual.event.USER_ADDED
- 订阅者所需权限： ohos.permission.MANAGE_LOCAL_ACCOUNTS

## COMMON_EVENT_USER_REMOVED
表示用户已从系统中删除的公共事件的动作。
- 值： usual.event.USER_REMOVED
- 订阅者所需权限： ohos.permission.MANAGE_LOCAL_ACCOUNTS

## COMMON_EVENT_ABILITY_ADDED
（预留事件，暂未支持）表示已添加能力的公共事件的动作。
- 值： usual.event.ABILITY_ADDED
- 订阅者所需权限： ohos.permission.LISTEN_BUNDLE_CHANGE

## COMMON_EVENT_ABILITY_REMOVED
（预留事件，暂未支持）表示已删除能力的公共事件的动作。
- 值： usual.event.ABILITY_REMOVED
- 订阅者所需权限： ohos.permission.LISTEN_BUNDLE_CHANGE

## COMMON_EVENT_ABILITY_UPDATED
（预留事件，暂未支持）表示能力已更新的公共事件的动作。
- 值： usual.event.ABILITY_UPDATED
- 订阅者所需权限： ohos.permission.LISTEN_BUNDLE_CHANGE

## COMMON_EVENT_LOCATION_MODE_STATE_CHANGED
（预留事件，暂未支持）表示系统定位模式已更改的公共事件的动作。
- 值： usual.event.location.MODE_STATE_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_SLEEP
（预留事件，暂未支持）表示表示车辆的车载信息娱乐（IVI）系统正在休眠的常见事件的动作。
- 值： common.event.IVI_SLEEP
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_PAUSE
（预留事件，暂未支持）表示IVI已休眠，并通知应用程序停止播放。
- 值： common.event.IVI_PAUSE
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_STANDBY
（预留事件，暂未支持）表示第三方应用暂停当前工作的公共事件的动作。
- 值： common.event.IVI_STANDBY
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_LASTMODE_SAVE
（预留事件，暂未支持）表示第三方应用保存其最后一个模式的公共事件的动作。
- 值： common.event.IVI_LASTMODE_SAVE
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_VOLTAGE_ABNORMAL
（预留事件，暂未支持）表示车辆电源系统电压异常的公共事件的动作。
- 值： common.event.IVI_VOLTAGE_ABNORMAL
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_HIGH_TEMPERATURE
（预留事件，暂未支持）表示IVI温度过高。
- 值： common.event.IVI_HIGH_TEMPERATURE
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_EXTREME_TEMPERATURE
（预留事件，暂未支持）表示IVI温度极高。
- 值： common.event.IVI_EXTREME_TEMPERATURE
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL
（预留事件，暂未支持）表示车载系统具有极端温度的常见事件的动作。
- 值： common.event.IVI_TEMPERATURE_ABNORMAL
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_VOLTAGE_RECOVERY
（预留事件，暂未支持）表示车辆电源系统电压恢复正常的公共事件的动作。
- 值： common.event.IVI_VOLTAGE_RECOVERY
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_TEMPERATURE_RECOVERY
（预留事件，暂未支持）表示车载系统温度恢复正常的公共事件的动作。
- 值： common.event.IVI_TEMPERATURE_RECOVERY
- 订阅者所需权限： 无

## COMMON_EVENT_IVI_ACTIVE
（预留事件，暂未支持）表示电池服务处于活动状态的公共事件的动作。
- 值： common.event.IVI_ACTIVE
- 订阅者所需权限： 无

## COMMON_EVENT_USB_STATE<sup>9+</sup>
表示USB设备状态发生变化的公共事件。
- 值： usual.event.hardware.usb.action.USB_STATE
- 订阅者所需权限： 无

## COMMON_EVENT_USB_PORT_CHANGED<sup>9+</sup>
表示用户设备的USB端口状态发生改变的公共事件。
- 值： usual.event.hardware.usb.action.USB_PORT_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_USB_DEVICE_ATTACHED
当用户设备作为USB主机时，USB设备已挂载的公共事件的动作。
- 值： usual.event.hardware.usb.action.USB_DEVICE_ATTACHED
- 订阅者所需权限： 无

## COMMON_EVENT_USB_DEVICE_DETACHED
当用户设备作为USB主机时，USB设备被卸载的公共事件的动作。
- 值： usual.event.hardware.usb.action.USB_DEVICE_DETACHED
- 订阅者所需权限： 无

## COMMON_EVENT_USB_ACCESSORY_ATTACHED
（预留事件，暂未支持）表示已连接USB附件的公共事件的动作。
- 值： usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED
- 订阅者所需权限： 无

## COMMON_EVENT_USB_ACCESSORY_DETACHED
（预留事件，暂未支持）表示USB附件被卸载的公共事件的动作。
- 值： usual.event.data.DISK_MOUNTED
- 订阅者所需权限： 无

## COMMON_EVENT_DISK_REMOVED
（预留事件，暂未支持）外部存储设备状态变更为移除时发送此公共事件。
- 值： usual.event.data.DISK_BAD_REMOVAL
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_UNMOUNTED
（预留事件，暂未支持）部存储设备状态变更为卸载时发送此公共事件。
- 值： usual.event.data.DISK_UNMOUNTABLE
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_MOUNTED
（预留事件，暂未支持）外部存储设备状态变更为挂载时发送此公共事件。
- 值： usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_BAD_REMOVAL
（预留事件，暂未支持）外部存储设备状态变更为挂载状态下移除时发送此公共事件。
- 值： usual.event.data.DISK_REMOVED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_UNMOUNTABLE
（预留事件，暂未支持）外部存储设备状态变更为插卡情况下无法挂载时发送此公共事件。
- 值： usual.event.data.DISK_UNMOUNTED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_DISK_EJECT
（预留事件，暂未支持）用户已表示希望删除外部存储介质时发送此公共事件。
- 值： usual.event.data.DISK_EJECT
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>
外部存储设备状态变更为移除时发送此公共事件。
- 值： usual.event.data.VOLUME_REMOVED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>
外部存储设备状态变更为卸载时发送此公共事件。
- 值： usual.event.data.VOLUME_UNMOUNTED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>
外部存储设备状态变更为挂载时发送此公共事件。
- 值： usual.event.data.VOLUME_MOUNTED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>
外部存储设备状态变更为挂载状态下移除时发送此公共事件。
- 值： usual.event.data.VOLUME_BAD_REMOVAL
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>
用户已表示希望删除外部存储介质时发送此公共事件。
- 值： usual.event.data.VOLUME_EJECT
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

## COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED
（预留事件，暂未支持）表示帐户可见更改的公共事件的动作。
- 值： usual.event.data.VISIBLE_ACCOUNTS_UPDATED
- 订阅者所需权限： ohos.permission.GET_APP_ACCOUNTS

## COMMON_EVENT_ACCOUNT_DELETED
（预留事件，暂未支持）删除帐户的公共事件的动作。
- 值： usual.event.data.ACCOUNT_DELETED
- 订阅者所需权限： ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

## COMMON_EVENT_FOUNDATION_READY
（预留事件，暂未支持）表示foundation已准备好的公共事件的动作。
- 值： usual.event.data.FOUNDATION_READY
- 订阅者所需权限： ohos.permission.RECEIVER_STARTUP_COMPLETED

## COMMON_EVENT_AIRPLANE_MODE_CHANGED
表示设备飞行模式已更改的公共事件的动作。
- 值： usual.event.AIRPLANE_MODE
- 订阅者所需权限： 无

## COMMON_EVENT_SPLIT_SCREEN
表示分屏的公共事件的动作。
- 值： usual.event.SPLIT_SCREEN
- 订阅者所需权限： ohos.permission.RECEIVER_SPLIT_SCREEN

## COMMON_EVENT_SLOT_CHANGE<sup>9+<sup>
表示通知通道更新的动作。
- 值： usual.event.SLOT_CHANGE
- 订阅者所需权限： ohos.permission.NOTIFICATION_CONTROLLER

## COMMON_EVENT_SPN_INFO_CHANGED <sup>9+<sup>
表示spn显示信息已更新的公共事件的动作。
- 值： usual.event.SPN_INFO_CHANGED
- 订阅者所需权限： 无

## COMMON_EVENT_QUICK_FIX_APPLY_RESULT <sup>9+<sup>
表示快速修复应用的动作。
- 值： usual.event.QUICK_FIX_APPLY_RESULT
- 订阅者所需权限： 无
