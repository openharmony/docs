# 系统事件定义

本文档提供OpenHarmony系统支持的事件类型的索引。
公共事件类型定义在ohos.commonEvent模块的Support枚举中。

**系统能力：** SystemCapability.Notification.CommonEvent

## COMMON_EVENT_BOOT_COMPLETED
公共事件，表示用户已完成引导并加载系统。
- 值：usual.event.BOOT_COMPLETED
- 订阅者所需权限：ohos.permission.RECEIVER_STARTUP_COMPLETED

## COMMON_EVENT_LOCKED_BOOT_COMPLETED
（预留事件能力，暂未支持）公共事件，表示用户已完成引导，系统已加载，但屏幕仍锁定。
- 值：usual.event.LOCKED_BOOT_COMPLETED
- 订阅者所需权限：ohos.permission.RECEIVER_STARTUP_COMPLETED

## COMMON_EVENT_SHUTDOWN
公共事件，表示设备正在关闭并将继续直至最终关闭。 
- 值：usual.event.SHUTDOWN
- 订阅者所需权限：无

## COMMON_EVENT_BATTERY_CHANGED
公共事件，表示电池充电状态、电量和其他信息发生变化。
- 值：usual.event.BATTERY_CHANGED
- 订阅者所需权限：无

## COMMON_EVENT_BATTERY_LOW
普通事件，表示电池电量低。
- 值：usual.event.BATTERY_LOW
- 订阅者所需权限：无

## COMMON_EVENT_BATTERY_OKAY
公共事件，表示电池退出低电量状态。
- 值：usual.event.BATTERY_OKAY
- 订阅者所需权限：无

## COMMON_EVENT_POWER_CONNECTED
公共事件，表示设备连接到外部电源。
- 值：usual.event.POWER_CONNECTED
- 订阅者所需权限：无


## COMMON_EVENT_POWER_DISCONNECTED
公共事件，表示设备与外部电源断开。
- 值：usual.event.POWER_DISCONNECTED
- 订阅者所需权限：无


## COMMON_EVENT_SCREEN_OFF
普通事件，表示设备屏幕关闭且设备处于睡眠状态。
- 值：usual.event.SCREEN_OFF
- 订阅者所需权限：无


## COMMON_EVENT_SCREEN_ON
公共事件，表示设备屏幕打开且设备处于交互状态。
- 值：usual.event.SCREEN_ON
- 订阅者所需权限：无


## COMMON_EVENT_THERMAL_LEVEL_CHANGED<sup>8+<sup>
公共事件，表示设备热状态（温度等级）发生变化。
- 值：usual.event.THERMAL_LEVEL_CHANGED
- 订阅者所需权限：无


## COMMON_EVENT_USER_PRESENT
（预留事件能力，暂未支持）公共事件，表示用户解锁了设备。
- 值：usual.event.USER_PRESENT
- 订阅者所需权限：无


## COMMON_EVENT_TIME_TICK
公共事件，表示系统时间发生更改（指时间正常流逝）。
- 值：usual.event.TIME_TICK
- 订阅者所需权限：无


## COMMON_EVENT_TIME_CHANGED
公共事件，表示系统时间被被重新设置。
- 值：usual.event.TIME_CHANGED
- 订阅者所需权限：无


## COMMON_EVENT_DATE_CHANGED
（预留事件能力，暂未支持）公共事件，表示系统日期已更改。
- 值：usual.event.DATE_CHANGED
- 订阅者所需权限：无


## COMMON_EVENT_TIMEZONE_CHANGED
公共事件，表示系统时区发生变更。
- 值：usual.event.TIMEZONE_CHANGED
- 订阅者所需权限：无


## COMMON_EVENT_CLOSE_SYSTEM_DIALOGS
（预留事件能力，暂未支持）公共事件，表示用户关闭临时系统对话框。
- 值：usual.event.CLOSE_SYSTEM_DIALOGS
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGE_ADDED
公共事件设备上已安装新应用程序包。
- 值：usual.event.PACKAGE_ADDED
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGE_REPLACED
（预留事件能力，暂未支持）公共事件，表示设备上已安装的旧版本应用程序已被新版本所替换。
- 值：usual.event.PACKAGE_REPLACED
- 订阅者所需权限：无


## COMMON_EVENT_MY_PACKAGE_REPLACED
（预留事件能力，暂未支持）指示应用程序包的新版本已取代前一个版本的公共事件。
- 值：usual.event.MY_PACKAGE_REPLACED
- 订阅者所需权限：无

## COMMON_EVENT_PACKAGE_REMOVED
公共事件，表示已安装的应用程序已从设备卸载，但应用程序数据得到保留的。
- 值：usual.event.PACKAGE_REMOVED
- 订阅者所需权限：无


## COMMON_EVENT_BUNDLE_REMOVED
（预留事件能力，暂未支持）公共事件，表示已从设备中卸载已安装应用程序的附加包，但应用程序数据得到保留。
- 值：usual.event.BUNDLE_REMOVED
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGE_FULLY_REMOVED
（预留事件能力，暂未支持）公共事件，表示已从设备中完全卸载已安装的应用程序（包括应用程序数据和代码）。
- 值：usual.event.PACKAGE_FULLY_REMOVED
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGE_CHANGED
公共事件，指示应用程序包已发生更改（例如，包中的组件已启用或禁用）。
- 值：usual.event.PACKAGE_CHANGED
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGE_RESTARTED
普通事件，表示用户终止了应用程序的所有进程并重启应用程序。
- 值：usual.event.PACKAGE_RESTARTED
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGE_DATA_CLEARED
公共事件，表示用户清除了应用包数据。
- 值：usual.event.PACKAGE_DATA_CLEARED
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGE_CACHE_CLEARED<sup>9+</sup>
公共事件，表示用户清除了应用包缓存数据。
- 值：usual.event.PACKAGE_CACHE_CLEARED
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGES_SUSPENDED
（预留事件能力，暂未支持）公共事件，表示应用程序已挂起。
- 值：usual.event.PACKAGES_SUSPENDED
- 订阅者所需权限：无


## COMMON_EVENT_PACKAGES_UNSUSPENDED
（预留事件能力，暂未支持）公共事件，表示应用包未挂起（从挂起状态恢复）。
- 值：usual.event.PACKAGES_UNSUSPENDED
- 订阅者所需权限：无


## COMMON_EVENT_MY_PACKAGE_SUSPENDED
- 值：usual.event.MY_PACKAGE_SUSPENDED
- 订阅者所需权限：无
应用包被挂起的公共事件。


## COMMON_EVENT_MY_PACKAGE_UNSUSPENDED
- 值：usual.event.MY_PACKAGE_UNSUSPENDED
- 订阅者所需权限：无
表示应用包未挂起的公共事件。


## COMMON_EVENT_UID_REMOVED
- 值：usual.event.UID_REMOVED
- 订阅者所需权限：无
表示用户ID已从系统中删除的公共事件。预留事件，暂未支持。


## COMMON_EVENT_PACKAGE_FIRST_LAUNCH
- 值：usual.event.PACKAGE_FIRST_LAUNCH
- 订阅者所需权限：无
表示首次启动已安装应用程序的公共事件。预留事件，暂未支持。


## COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION
- 值：usual.event.PACKAGE_NEEDS_VERIFICATION
- 订阅者所需权限：无
表示应用需要系统校验的公共事件。预留事件，暂未支持。


## COMMON_EVENT_PACKAGE_VERIFIED
- 值：usual.event.PACKAGE_VERIFIED
- 订阅者所需权限：无
表示应用已被系统校验的公共事件。预留事件，暂未支持。


## COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE
- 值：usual.event.EXTERNAL_APPLICATIONS_AVAILABLE
- 订阅者所需权限：无
指示安装在外部存储上的应用程序对系统可用的公共事件。预留事件，暂未支持。


## COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE
- 值：usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE
- 订阅者所需权限：无
指示安装在外部存储上的应用程序对系统不可用的公共事件。预留事件，暂未支持。


## COMMON_EVENT_CONFIGURATION_CHANGED
- 值：usual.event.CONFIGURATION_CHANGED
- 订阅者所需权限：无
指示设备状态（例如，方向和区域设置）已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_LOCALE_CHANGED
- 值：usual.event.LOCALE_CHANGED
- 订阅者所需权限：无
指示设备区域设置已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_MANAGE_PACKAGE_STORAGE
- 值：usual.event.MANAGE_PACKAGE_STORAGE
- 订阅者所需权限：无
设备存储空间不足的公共事件。预留事件，暂未支持。


## COMMON_EVENT_DRIVE_MODE
common.event.DRIVE_MODE
- 订阅者所需权限：无
指示系统处于驾驶模式的公共事件。预留事件，暂未支持。


## COMMON_EVENT_HOME_MODE
common.event.HOME_MODE
- 订阅者所需权限：无
表示系统处于HOME模式的公共事件。预留事件，暂未支持。


## COMMON_EVENT_OFFICE_MODE
common.event.OFFICE_MODE
- 订阅者所需权限：无
表示系统处于办公模式的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USER_STARTED
- 值：usual.event.USER_STARTED
- 订阅者所需权限：无
表示用户已启动的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USER_BACKGROUND
- 值：usual.event.USER_BACKGROUND
- 订阅者所需权限：无
表示用户已被带到后台的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USER_FOREGROUND
- 值：usual.event.USER_FOREGROUND
- 订阅者所需权限：无
表示用户已被带到前台的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USER_SWITCHED
- 值：usual.event.USER_SWITCHED
ohos.permission.MANAGE_LOCAL_ACCOUNTS
表示用户切换正在发生的公共事件。


## COMMON_EVENT_USER_STARTING
- 值：usual.event.USER_STARTING
ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS
表示要启动用户的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USER_UNLOCKED
- 值：usual.event.USER_UNLOCKED
- 订阅者所需权限：无
设备重启后解锁时，当前用户的凭据加密存储已解锁的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USER_STOPPING
- 值：usual.event.USER_STOPPING
ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS
表示要停止用户的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USER_STOPPED
- 值：usual.event.USER_STOPPED
- 订阅者所需权限：无
表示用户已停止的公共事件。预留事件，暂未支持。


## COMMON_EVENT_WIFI_POWER_STATE
- 值：usual.event.wifi.POWER_STATE
- 订阅者所需权限：无
Wi-Fi状态公共事件，如启用和禁用。


## COMMON_EVENT_WIFI_SCAN_FINISHED
- 值：usual.event.wifi.SCAN_FINISHED
ohos.permission.LOCATION
表示Wi-Fi接入点已被扫描并证明可用的公共事件。


## COMMON_EVENT_WIFI_RSSI_VALUE
- 值：usual.event.wifi.RSSI_VALUE
ohos.permission.GET_WIFI_INFO
表示Wi-Fi信号强度（RSSI）改变的公共事件。


## COMMON_EVENT_WIFI_CONN_STATE
- 值：usual.event.wifi.CONN_STATE
- 订阅者所需权限：无
Wi-Fi连接状态发生改变的公共事件。


## COMMON_EVENT_WIFI_HOTSPOT_STATE
- 值：usual.event.wifi.HOTSPOT_STATE
- 订阅者所需权限：无
Wi-Fi热点状态的公共事件，如启用或禁用。


## COMMON_EVENT_WIFI_AP_STA_JOIN
- 值：usual.event.wifi.WIFI_HS_STA_JOIN
ohos.permission.GET_WIFI_INFO
客户端加入当前设备Wi-Fi热点的普通事件的动作。


## COMMON_EVENT_WIFI_AP_STA_LEAVE
- 值：usual.event.wifi.WIFI_HS_STA_LEAVE
ohos.permission.GET_WIFI_INFO
客户端已断开与当前设备Wi-Fi热点的连接的公共事件。


## COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE
- 值：usual.event.wifi.mplink.STATE_CHANGE
ohos.permission.MPLINK_CHANGE_STATE
表示MPLink（增强Wi-Fi功能）状态已更改的公共事件。


## COMMON_EVENT_WIFI_P2P_CONN_STATE
- 值：usual.event.wifi.p2p.CONN_STATE_CHANGE
ohos.permission.GET_WIFI_INFOandohos.permission.LOCATION
Wi-FiP2P连接状态改变的公共事件。


## COMMON_EVENT_WIFI_P2P_STATE_CHANGED
- 值：usual.event.wifi.p2p.STATE_CHANGE
ohos.permission.GET_WIFI_INFO
Wi-FiP2P状态公共事件，如启用和禁用。


## COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED
- 值：usual.event.wifi.p2p.DEVICES_CHANGE
ohos.permission.GET_WIFI_INFO
Wi-FiP2P对等体状态变化。


## COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED
- 值：usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE
ohos.permission.GET_WIFI_INFO
Wi-FiP2P发现状态变化。


## COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED
- 值：usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE
ohos.permission.GET_WIFI_INFO
Wi-FiP2P当前设备状态变化。


## COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED
- 值：usual.event.wifi.p2p.GROUP_STATE_CHANGED
ohos.permission.GET_WIFI_INFO
Wi-FiP2P群组信息已更改。


## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE
- 值：usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE
ohos.permission.USE_BLUETOOTH
蓝牙免提通信连接状态公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE
- 值：usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE
ohos.permission.USE_BLUETOOTH
表示连接到蓝牙免提的设备处于活动状态的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE
- 值：usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE
ohos.permission.USE_BLUETOOTH
表示蓝牙A2DP连接状态已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE
- 值：usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE
ohos.permission.USE_BLUETOOTH
蓝牙A2DP连接状态公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE
- 值：usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE
ohos.permission.USE_BLUETOOTH
表示使用蓝牙A2DP连接的设备处于活动状态的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE
- 值：usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE
ohos.permission.USE_BLUETOOTH
蓝牙A2DP播放状态改变的普通事件的动作。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE
- 值：usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE
ohos.permission.USE_BLUETOOTH
表示蓝牙A2DP的AVRCP连接状态已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE
- 值：usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE
ohos.permission.USE_BLUETOOTH
表示蓝牙A2DP音频编解码状态更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED
- 值：usual.event.bluetooth.remotedevice.DISCOVERED
ohos.permission.LOCATIONandohos.permission.USE_BLUETOOTH
表示发现远程蓝牙设备的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE
- 值：usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE
ohos.permission.USE_BLUETOOTH
表示远程蓝牙设备的蓝牙类别已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED
- 值：usual.event.bluetooth.remotedevice.ACL_CONNECTED
ohos.permission.USE_BLUETOOTH
指示已与远程蓝牙设备建立低级别（ACL）连接的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED
- 值：usual.event.bluetooth.remotedevice.ACL_DISCONNECTED
ohos.permission.USE_BLUETOOTH
表示低电平（ACL）连接已从远程蓝牙设备断开的普通事件的动作。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE
- 值：usual.event.bluetooth.remotedevice.NAME_UPDATE
ohos.permission.USE_BLUETOOTH
表示远程蓝牙设备的友好名称首次被检索或自上次检索以来被更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE
- 值：usual.event.bluetooth.remotedevice.PAIR_STATE
ohos.permission.USE_BLUETOOTH
远程蓝牙设备连接状态更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE
- 值：usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE
ohos.permission.USE_BLUETOOTH
表示远程蓝牙设备的电池电量首次被检索或自上次检索以来被更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT
- 值：usual.event.bluetooth.remotedevice.SDP_RESULT
- 订阅者所需权限：无
远程蓝牙设备SDP状态公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE
- 值：usual.event.bluetooth.remotedevice.UUID_VALUE
ohos.permission.DISCOVER_BLUETOOTH
远程蓝牙设备UUID连接状态公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ
- 值：usual.event.bluetooth.remotedevice.PAIRING_REQ
ohos.permission.DISCOVER_BLUETOOTH
表示远程蓝牙设备配对请求的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL
- 值：usual.event.bluetooth.remotedevice.PAIRING_CANCEL
- 订阅者所需权限：无
取消蓝牙配对的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ
- 值：usual.event.bluetooth.remotedevice.CONNECT_REQ
- 订阅者所需权限：无
表示远程蓝牙设备连接请求的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY
- 值：usual.event.bluetooth.remotedevice.CONNECT_REPLY
- 订阅者所需权限：无
表示远程蓝牙设备连接请求响应的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL
- 值：usual.event.bluetooth.remotedevice.CONNECT_CANCEL
- 订阅者所需权限：无
表示取消与远程蓝牙设备的连接的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE
- 值：usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE
- 订阅者所需权限：无
表示蓝牙免提连接状态已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE
- 值：usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE
- 订阅者所需权限：无
表示蓝牙免提音频状态已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_## COMMON_EVENT
- 值：usual.event.bluetooth.handsfreeunit.AG_## COMMON_EVENT
- 订阅者所需权限：无
表示蓝牙免提音频网关状态已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE
- 值：usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE
- 订阅者所需权限：无
表示蓝牙免提呼叫状态已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE
- 值：usual.event.bluetooth.host.STATE_UPDATE
ohos.permission.USE_BLUETOOTH
表示蓝牙适配器状态已更改的公共事件，例如蓝牙已打开或关闭。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE
- 值：usual.event.bluetooth.host.REQ_DISCOVERABLE
- 订阅者所需权限：无
表示用户允许扫描蓝牙请求的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE
- 值：usual.event.bluetooth.host.REQ_ENABLE
ohos.permission.USE_BLUETOOTH
表示用户打开蓝牙请求的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE
- 值：usual.event.bluetooth.host.REQ_DISABLE
ohos.permission.USE_BLUETOOTH
表示用户关闭蓝牙请求的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE
- 值：usual.event.bluetooth.host.SCAN_MODE_UPDATE
ohos.permission.USE_BLUETOOTH
设备蓝牙扫描模式更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED
- 值：usual.event.bluetooth.host.DISCOVERY_STARTED
ohos.permission.USE_BLUETOOTH
设备上已启动蓝牙扫描的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED
- 值：usual.event.bluetooth.host.DISCOVERY_FINISHED
ohos.permission.USE_BLUETOOTH
设备上蓝牙扫描完成的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE
- 值：usual.event.bluetooth.host.NAME_UPDATE
ohos.permission.USE_BLUETOOTH
指示设备蓝牙适配器名称已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE
- 值：usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE
ohos.permission.USE_BLUETOOTH
表示蓝牙A2DP宿连接状态已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE
- 值：usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE
ohos.permission.USE_BLUETOOTH
蓝牙A2DP宿播放状态改变的普通事件的动作。预留事件，暂未支持。


## COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE
- 值：usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE
ohos.permission.USE_BLUETOOTH
表示蓝牙A2DP宿的音频状态已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED
- 值：usual.event.nfc.action.ADAPTER_STATE_CHANGED
- 订阅者所需权限：无
指示设备NFC适配器状态已更改的公共事件。


## COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED
- 值：usual.event.nfc.action.RF_FIELD_ON_DETECTED
ohos.permission.MANAGE_SECURE_SETTINGS
检测到NFCRF字段处于使能状态的公共事件。预留事件，暂未支持。


## COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED
- 值：usual.event.nfc.action.RF_FIELD_OFF_DETECTED
ohos.permission.MANAGE_SECURE_SETTINGS
检测到NFCRF字段处于关闭状态的公共事件。预留事件，暂未支持。


## COMMON_EVENT_DISCHARGING
- 值：usual.event.DISCHARGING
- 订阅者所需权限：无
表示系统停止为电池充电的公共事件。


## COMMON_EVENT_CHARGING
- 值：usual.event.CHARGING
- 订阅者所需权限：无
表示系统开始为电池充电的公共事件。


## COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED
- 值：usual.event.DEVICE_IDLE_MODE_CHANGED
- 订阅者所需权限：无
表示系统空闲模式已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_POWER_SAVE_MODE_CHANGED
- 值：usual.event.POWER_SAVE_MODE_CHANGED
- 订阅者所需权限：无
表示系统节能模式更改的公共事件。


## COMMON_EVENT_USER_ADDED
- 值：usual.event.USER_ADDED
ohos.permission.MANAGE_LOCAL_ACCOUNTS
表示用户已添加到系统中的公共事件。


## COMMON_EVENT_USER_REMOVED
- 值：usual.event.USER_REMOVED
ohos.permission.MANAGE_LOCAL_ACCOUNTS
表示用户已从系统中删除的公共事件。


## COMMON_EVENT_ABILITY_ADDED
- 值：usual.event.ABILITY_ADDED
ohos.permission.LISTEN_BUNDLE_CHANGE
表示已添加能力的公共事件。预留事件，暂未支持。


## COMMON_EVENT_ABILITY_REMOVED
- 值：usual.event.ABILITY_REMOVED
ohos.permission.LISTEN_BUNDLE_CHANGE
表示已删除能力的公共事件。预留事件，暂未支持。


## COMMON_EVENT_ABILITY_UPDATED
- 值：usual.event.ABILITY_UPDATED
ohos.permission.LISTEN_BUNDLE_CHANGE
表示能力已更新的公共事件。预留事件，暂未支持。


## COMMON_EVENT_LOCATION_MODE_STATE_CHANGED
- 值：usual.event.location.MODE_STATE_CHANGED
- 订阅者所需权限：无
表示系统定位模式已更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_IVI_SLEEP
common.event.IVI_SLEEP
- 订阅者所需权限：无
表示指示车辆的车载信息娱乐（IVI）系统正在休眠的常见事件的动作。预留事件，暂未支持。


## COMMON_EVENT_IVI_PAUSE
common.event.IVI_PAUSE
- 订阅者所需权限：无
表示IVI已休眠，并通知应用程序停止播放。预留事件，暂未支持。


## COMMON_EVENT_IVI_STANDBY
common.event.IVI_STANDBY
- 订阅者所需权限：无
指示第三方应用暂停当前工作的公共事件。预留事件，暂未支持。


## COMMON_EVENT_IVI_LASTMODE_SAVE
common.event.IVI_LASTMODE_SAVE
- 订阅者所需权限：无
指示第三方应用保存其最后一个模式的公共事件。预留事件，暂未支持。


## COMMON_EVENT_IVI_VOLTAGE_ABNORMAL
common.event.IVI_VOLTAGE_ABNORMAL
- 订阅者所需权限：无
表示车辆电源系统电压异常的公共事件。预留事件，暂未支持。


## COMMON_EVENT_IVI_HIGH_TEMPERATURE
common.event.IVI_HIGH_TEMPERATURE
- 订阅者所需权限：无
表示IVI温度过高。预留事件，暂未支持。


## COMMON_EVENT_IVI_EXTREME_TEMPERATURE
common.event.IVI_EXTREME_TEMPERATURE
- 订阅者所需权限：无
表示IVI温度极高。预留事件，暂未支持。


## COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL
common.event.IVI_TEMPERATURE_ABNORMAL
- 订阅者所需权限：无
表示车载系统具有极端温度的常见事件的动作。预留事件，暂未支持。


## COMMON_EVENT_IVI_VOLTAGE_RECOVERY
common.event.IVI_VOLTAGE_RECOVERY
- 订阅者所需权限：无
表示车辆电源系统电压恢复正常的公共事件。预留事件，暂未支持。


## COMMON_EVENT_IVI_TEMPERATURE_RECOVERY
common.event.IVI_TEMPERATURE_RECOVERY
- 订阅者所需权限：无
表示车载系统温度恢复正常的公共事件。预留事件，暂未支持。


## COMMON_EVENT_IVI_ACTIVE
common.event.IVI_ACTIVE
- 订阅者所需权限：无
表示电池服务处于活动状态的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USB_STATE<sup>9+</sup>
- 值：usual.event.hardware.usb.action.USB_STATE
- 订阅者所需权限：无
表示USB设备状态发生变化的公共事件。


## COMMON_EVENT_USB_PORT_CHANGED<sup>9+</sup>
- 值：usual.event.hardware.usb.action.USB_PORT_CHANGED
- 订阅者所需权限：无
表示用户设备的USB端口状态发生改变的公共事件。


## COMMON_EVENT_USB_DEVICE_ATTACHED
- 值：usual.event.hardware.usb.action.USB_DEVICE_ATTACHED
- 订阅者所需权限：无
当用户设备作为USB主机时，USB设备已挂载的公共事件。


## COMMON_EVENT_USB_DEVICE_DETACHED
- 值：usual.event.hardware.usb.action.USB_DEVICE_DETACHED
- 订阅者所需权限：无
当用户设备作为USB主机时，USB设备被卸载的公共事件。


## COMMON_EVENT_USB_ACCESSORY_ATTACHED
- 值：usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED
- 订阅者所需权限：无
表示已连接USB附件的公共事件。预留事件，暂未支持。


## COMMON_EVENT_USB_ACCESSORY_DETACHED
- 值：usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED
- 订阅者所需权限：无
表示USB附件被卸载的公共事件。预留事件，暂未支持。


## COMMON_EVENT_DISK_REMOVED
- 值：usual.event.data.DISK_REMOVED
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为移除时发送此公共事件。预留事件，暂未支持。


## COMMON_EVENT_DISK_UNMOUNTED
- 值：usual.event.data.DISK_UNMOUNTED
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为卸载时发送此公共事件。预留事件，暂未支持。


## COMMON_EVENT_DISK_MOUNTED
- 值：usual.event.data.DISK_MOUNTED
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为挂载时发送此公共事件。预留事件，暂未支持。


## COMMON_EVENT_DISK_BAD_REMOVAL
- 值：usual.event.data.DISK_BAD_REMOVAL
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为挂载状态下移除时发送此公共事件。预留事件，暂未支持。


## COMMON_EVENT_DISK_UNMOUNTABLE
- 值：usual.event.data.DISK_UNMOUNTABLE
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为插卡情况下无法挂载时发送此公共事件。预留事件，暂未支持。


## COMMON_EVENT_DISK_EJECT
- 值：usual.event.data.DISK_EJECT
ohos.permission.STORAGE_MANAGER
用户已表示希望删除外部存储介质时发送此公共事件。预留事件，暂未支持。


## COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>
- 值：usual.event.data.VOLUME_REMOVED
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为移除时发送此公共事件。


## COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>
- 值：usual.event.data.VOLUME_UNMOUNTED
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为卸载时发送此公共事件。


## COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>
- 值：usual.event.data.VOLUME_MOUNTED
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为挂载时发送此公共事件。


## COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>
- 值：usual.event.data.VOLUME_BAD_REMOVAL
ohos.permission.STORAGE_MANAGER
外部存储设备状态变更为挂载状态下移除时发送此公共事件。


## COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>
- 值：usual.event.data.VOLUME_EJECT
ohos.permission.STORAGE_MANAGER
用户已表示希望删除外部存储介质时发送此公共事件。


## COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED
- 值：usual.event.data.VISIBLE_ACCOUNTS_UPDATED
ohos.permission.GET_APP_ACCOUNTS
表示帐户可见更改的公共事件。预留事件，暂未支持。


## COMMON_EVENT_ACCOUNT_DELETED
- 值：usual.event.data.ACCOUNT_DELETED
ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS
删除帐户的公共事件。预留事件，暂未支持。


## COMMON_EVENT_FOUNDATION_READY
- 值：usual.event.data.FOUNDATION_READY
ohos.permission.RECEIVER_STARTUP_COMPLETED
表示foundation已准备好的公共事件。预留事件，暂未支持。


## COMMON_EVENT_AIRPLANE_MODE_CHANGED
- 值：usual.event.AIRPLANE_MODE
- 订阅者所需权限：无
表示设备飞行模式已更改的公共事件。


## COMMON_EVENT_SPLIT_SCREEN<sup>8+<sup>
- 值：usual.event.SPLIT_SCREEN
- 订阅者所需权限：无
表示分屏的公共事件。


## COMMON_EVENT_SLOT_CHANGE<sup>9+<sup>
- 值：usual.event.SLOT_CHANGE
ohos.permission.NOTIFICATION_CONTROLLER
表示通知通道更新的动作。


## COMMON_EVENT_SPN_INFO_CHANGED<sup>9+<sup>
- 值：usual.event.SPN_INFO_CHANGED
- 订阅者所需权限：无
表示spn显示信息已更新的公共事件。


## COMMON_EVENT_QUICK_FIX_APPLY_RESULT<sup>9+<sup>
- 值：usual.event.QUICK_FIX_APPLY_RESULT
- 订阅者所需权限：无
指示快速修复应用的动作。

