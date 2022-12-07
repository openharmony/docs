# 公共事件模块

本模块提供了公共事件的能力，包括公共事件的权限列表，发布公共事件，订阅或取消订阅公共事件，获取或修改公共事件结果代码、结果数据等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import CommonEventManager from '@ohos.commonEventManager';
```

## Support

CommonEventManager模块支持的事件类型。名称指的是系统公共事件宏；值指的是系统公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

| 名称      | 值          | 订阅者所需权限     | 说明               |
| ------------ | ------------------ | ---------------------- | -------------------- |
| COMMON_EVENT_BOOT_COMPLETED                                  | usual.event.BOOT_COMPLETED                                  | ohos.permission.RECEIVER_STARTUP_COMPLETED                   | 表示用户已完成引导并加载系统的公共事件的操作。        |
| COMMON_EVENT_LOCKED_BOOT_COMPLETED                           | usual.event.LOCKED_BOOT_COMPLETED                           | ohos.permission.RECEIVER_STARTUP_COMPLETED                   | 表示用户已完成引导，系统已加载，但屏幕仍锁定的公共事件的操作。          |
| COMMON_EVENT_SHUTDOWN                                        | usual.event.SHUTDOWN                                        | 无                                                           | 表示设备正在关闭并将继续最终关闭的公共事件的操作。            |
| COMMON_EVENT_BATTERY_CHANGED                                 | usual.event.BATTERY_CHANGED                                 | 无                                                           | 表示电池充电状态、电平和其他信息发生变化的公共事件的动作。          |
| COMMON_EVENT_BATTERY_LOW                                     | usual.event.BATTERY_LOW                                     | 无                                                           | 表示电池电量低的普通事件的动作。          |
| COMMON_EVENT_BATTERY_OKAY                                    | usual.event.BATTERY_OKAY                                    | 无                                                           | 表示电池退出低电平状态的公共事件的动作。    |
| COMMON_EVENT_POWER_CONNECTED                                 | usual.event.POWER_CONNECTED                                 | 无                                                           | 设备连接到外部电源的公共事件的动作。            |
| COMMON_EVENT_POWER_DISCONNECTED                              | usual.event.POWER_DISCONNECTED                              | 无                                                           | 设备与外部电源断开的公共事件的动作。            |
| COMMON_EVENT_SCREEN_OFF                                      | usual.event.SCREEN_OFF                                      | 无                                                           | 表示设备屏幕关闭且设备处于睡眠状态的普通事件的动作。            |
| COMMON_EVENT_SCREEN_ON                                       | usual.event.SCREEN_ON                                       | 无                                                           | 表示设备屏幕打开且设备处于交互状态的公共事件的操作。  |
| COMMON_EVENT_THERMAL_LEVEL_CHANGED<sup>8+<sup>                           | usual.event.THERMAL_LEVEL_CHANGED                           | 无                                                           | 表示设备热状态的公共事件的动作。  |
| COMMON_EVENT_USER_PRESENT                                    | usual.event.USER_PRESENT                                    | 无                                                           | 用户解锁设备的公共事件的动作。      |
| COMMON_EVENT_TIME_TICK                                       | usual.event.TIME_TICK                                       | 无                                                           | 表示系统时间更改的公共事件的动作。        |
| COMMON_EVENT_TIME_CHANGED                                    | usual.event.TIME_CHANGED                                    | 无                                                           | 设置系统时间的公共事件的动作。      |
| COMMON_EVENT_DATE_CHANGED                                    | usual.event.DATE_CHANGED                                    | 无                                                           | 表示系统日期已更改的公共事件的动作。        |
| COMMON_EVENT_TIMEZONE_CHANGED                                | usual.event.TIMEZONE_CHANGED                                | 无                                                           | 表示系统时区更改的公共事件的动作。          |
| COMMON_EVENT_CLOSE_SYSTEM_DIALOGS                            | usual.event.CLOSE_SYSTEM_DIALOGS                            | 无                                                           | 表示用户关闭临时系统对话框的公共事件的动作。        |
| COMMON_EVENT_PACKAGE_ADDED                                   | usual.event.PACKAGE_ADDED                                   | 无                                                           | 设备上已安装新应用包的公共事件的动作。      |
| COMMON_EVENT_PACKAGE_REPLACED                                | usual.event.PACKAGE_REPLACED                                | 无                                                           | 表示已安装的应用程序包的新版本已替换设备上的旧版本的公共事件的操作。        |
| COMMON_EVENT_MY_PACKAGE_REPLACED                             | usual.event.MY_PACKAGE_REPLACED                             | 无                                                           | 表示应用程序包的新版本已取代前一个版本的公共事件的操作。  
| COMMON_EVENT_PACKAGE_REMOVED                                 | usual.event.PACKAGE_REMOVED                                 | 无                                                           | 表示已从设备卸载已安装的应用程序，但应用程序数据保留的公共事件的操作。    |
| COMMON_EVENT_BUNDLE_REMOVED                                  | usual.event.BUNDLE_REMOVED                                  | 无                                                           | 表示已从设备中卸载已安装的捆绑包，但应用程序数据仍保留的公共事件的操作。    |
| COMMON_EVENT_PACKAGE_FULLY_REMOVED                           | usual.event.PACKAGE_FULLY_REMOVED                           | 无                                                           | 表示已从设备中完全卸载已安装的应用程序（包括应用程序数据和代码）的公共事件的操作。    |
| COMMON_EVENT_PACKAGE_CHANGED                                 | usual.event.PACKAGE_CHANGED                                 | 无                                                           | 表示应用包已更改的公共事件的动作（例如，包中的组件已启用或禁用）。  |
| COMMON_EVENT_PACKAGE_RESTARTED                               | usual.event.PACKAGE_RESTARTED                               | 无                                                           | 表示用户重启应用包并杀死其所有进程的普通事件的动作。    |
| COMMON_EVENT_PACKAGE_DATA_CLEARED                            | usual.event.PACKAGE_DATA_CLEARED                            | 无                                                           | 用户清除应用包数据的公共事件的动作。        |
| COMMON_EVENT_PACKAGE_CACHE_CLEARED<sup>9+</sup>              | usual.event.PACKAGE_CACHE_CLEARED                           | 无                                                           | 用户清除应用包缓存数据的公共事件的动作。        |
| COMMON_EVENT_PACKAGES_SUSPENDED                              | usual.event.PACKAGES_SUSPENDED                              | 无                                                           | 表示应用包已挂起的公共事件的动作。          |
| COMMON_EVENT_PACKAGES_UNSUSPENDED                            | usual.event.PACKAGES_UNSUSPENDED                            | 无                                                           | 表示应用包未挂起的公共事件的动作。        |
| COMMON_EVENT_MY_PACKAGE_SUSPENDED                            | usual.event.MY_PACKAGE_SUSPENDED                            | 无                                                           | 应用包被挂起的公共事件的动作。          |
| COMMON_EVENT_MY_PACKAGE_UNSUSPENDED                          | usual.event.MY_PACKAGE_UNSUSPENDED                          | 无                                                           | 表示应用包未挂起的公共事件的动作。        |
| COMMON_EVENT_UID_REMOVED                                     | usual.event.UID_REMOVED                                     | 无                                                           | 表示用户ID已从系统中删除的公共事件的动作。    |
| COMMON_EVENT_PACKAGE_FIRST_LAUNCH                            | usual.event.PACKAGE_FIRST_LAUNCH                            | 无                                                           | 表示首次启动已安装应用程序的公共事件的动作。    |
| COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION                      | usual.event.PACKAGE_NEEDS_VERIFICATION                      | 无                                                           | 表示应用需要系统校验的公共事件的动作。         |
| COMMON_EVENT_PACKAGE_VERIFIED                                | usual.event.PACKAGE_VERIFIED                                | 无                                                           | 表示应用已被系统校验的公共事件的动作。        |
| COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE                 | usual.event.EXTERNAL_APPLICATIONS_AVAILABLE                 | 无                                                           | 表示安装在外部存储上的应用程序对系统可用的公共事件的操作。      |
| COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE               | usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE               | 无                                                           | 表示安装在外部存储上的应用程序对系统不可用的公共事件的操作。        |
| COMMON_EVENT_CONFIGURATION_CHANGED                           | usual.event.CONFIGURATION_CHANGED                           | 无                                                           | 表示设备状态（例如，方向和区域设置）已更改的公共事件的操作。        |
| COMMON_EVENT_LOCALE_CHANGED                                  | usual.event.LOCALE_CHANGED                                  | 无                                                           | 表示设备区域设置已更改的公共事件的操作。      |
| COMMON_EVENT_MANAGE_PACKAGE_STORAGE                          | usual.event.MANAGE_PACKAGE_STORAGE                          | 无                                                           | 设备存储空间不足的公共事件的动作。        |
| COMMON_EVENT_DRIVE_MODE                                      | common.event.DRIVE_MODE                                     | 无                                                           | 表示系统处于驾驶模式的公共事件的动作。      |
| COMMON_EVENT_HOME_MODE                                       | common.event.HOME_MODE                                      | 无                                                           | 表示系统处于HOME模式的公共事件的动作。    |
| COMMON_EVENT_OFFICE_MODE                                     | common.event.OFFICE_MODE                                    | 无                                                           | 表示系统处于办公模式的公共事件的动作。      |
| COMMON_EVENT_USER_STARTED                                    | usual.event.USER_STARTED                                    | 无                                                           | 表示用户已启动的公共事件的动作。      |
| COMMON_EVENT_USER_BACKGROUND                                 | usual.event.USER_BACKGROUND                                 | 无                                                           | 表示用户已被带到后台的公共事件的动作。      |
| COMMON_EVENT_USER_FOREGROUND                                 | usual.event.USER_FOREGROUND                                 | 无                                                           | 表示用户已被带到前台的公共事件的动作。        |
| COMMON_EVENT_USER_SWITCHED                                   | usual.event.USER_SWITCHED                                   | ohos.permission.MANAGE_LOCAL_ACCOUNTS                                 | 表示用户切换正在发生的公共事件的动作。      |
| COMMON_EVENT_USER_STARTING                                   | usual.event.USER_STARTING                                   | ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS                        | 表示要启动用户的公共事件的动作。        |
| COMMON_EVENT_USER_UNLOCKED                                   | usual.event.USER_UNLOCKED                                   | 无                                                           | 设备重启后解锁时，当前用户的凭据加密存储已解锁的公共事件的动作。     |
| COMMON_EVENT_USER_STOPPING                                   | usual.event.USER_STOPPING                                   | ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS                        | 表示要停止用户的公共事件的动作。    |
| COMMON_EVENT_USER_STOPPED                                    | usual.event.USER_STOPPED                                    | 无                                                           | 表示用户已停止的公共事件的动作。    |
| COMMON_EVENT_WIFI_POWER_STATE                                | usual.event.wifi.POWER_STATE                                | 无                                                           | Wi-Fi状态公共事件的动作，如启用和禁用。      |
| COMMON_EVENT_WIFI_SCAN_FINISHED                              | usual.event.wifi.SCAN_FINISHED                              | ohos.permission.LOCATION                                     | 表示Wi-Fi接入点已被扫描并证明可用的公共事件的操作。       |
| COMMON_EVENT_WIFI_RSSI_VALUE                                 | usual.event.wifi.RSSI_VALUE                                 | ohos.permission.GET_WIFI_INFO                                | 表示Wi-Fi信号强度（RSSI）改变的公共事件的动作。      |
| COMMON_EVENT_WIFI_CONN_STATE                                 | usual.event.wifi.CONN_STATE                                 | 无                                                           | Wi-Fi连接状态发生改变的公共事件的动作。       |
| COMMON_EVENT_WIFI_HOTSPOT_STATE                              | usual.event.wifi.HOTSPOT_STATE                              | 无                                                           | Wi-Fi热点状态的公共事件的动作，如启用或禁用。   |
| COMMON_EVENT_WIFI_AP_STA_JOIN                                | usual.event.wifi.WIFI_HS_STA_JOIN                           | ohos.permission.GET_WIFI_INFO                                | 客户端加入当前设备Wi-Fi热点的普通事件的动作。       |
| COMMON_EVENT_WIFI_AP_STA_LEAVE                               | usual.event.wifi.WIFI_HS_STA_LEAVE                          | ohos.permission.GET_WIFI_INFO                                |客户端已断开与当前设备Wi-Fi热点的连接的公共事件的动作。       |
| COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE                        | usual.event.wifi.mplink.STATE_CHANGE                        | ohos.permission.MPLINK_CHANGE_STATE                          | 表示MPLink（增强Wi-Fi功能）状态已更改的公共事件的动作。     |
| COMMON_EVENT_WIFI_P2P_CONN_STATE                             | usual.event.wifi.p2p.CONN_STATE_CHANGE                      | ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION   | Wi-Fi P2P连接状态改变的公共事件的动作。      |
| COMMON_EVENT_WIFI_P2P_STATE_CHANGED                          | usual.event.wifi.p2p.STATE_CHANGE                           | ohos.permission.GET_WIFI_INFO                                | Wi-Fi P2P状态公共事件的动作，如启用和禁用。        |
| COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED                    | usual.event.wifi.p2p.DEVICES_CHANGE                         | ohos.permission.GET_WIFI_INFO                                | Wi-Fi P2P对等体状态变化。     |
| COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED          | usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE            | ohos.permission.GET_WIFI_INFO                                | Wi-Fi P2P发现状态变化。       |
| COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED           | usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE                  | ohos.permission.GET_WIFI_INFO                                | Wi-Fi P2P当前设备状态变化。        |
| COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED                    | usual.event.wifi.p2p.GROUP_STATE_CHANGED                    | ohos.permission.GET_WIFI_INFO                                | Wi-Fi P2P群组信息已更改。        |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE     | usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE     | ohos.permission.USE_BLUETOOTH                                | 蓝牙免提通信连接状态公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE    | usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE    | ohos.permission.USE_BLUETOOTH                                | 表示连接到蓝牙免提的设备处于活动状态的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE       | usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                | 表示蓝牙A2DP连接状态已更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE       | usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                | 蓝牙A2DP连接状态公共事件的动作。      |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE      | usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE      | ohos.permission.USE_BLUETOOTH                                | 表示使用蓝牙A2DP连接的设备处于活动状态的公共事件的动作。      |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE       | usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                | 蓝牙A2DP播放状态改变的普通事件的动作。      |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE | usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE | ohos.permission.USE_BLUETOOTH                                | 表示蓝牙A2DP的AVRCP连接状态已更改的公共事件的动作。      |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE         | usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE         | ohos.permission.USE_BLUETOOTH                                | 表示蓝牙A2DP音频编解码状态更改的公共事件的动作。       |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED               | usual.event.bluetooth.remotedevice.DISCOVERED               | ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH   | 表示发现远程蓝牙设备的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE       | usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE       | ohos.permission.USE_BLUETOOTH                                | 表示远程蓝牙设备的蓝牙类别已更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED            | usual.event.bluetooth.remotedevice.ACL_CONNECTED            | ohos.permission.USE_BLUETOOTH                                | 表示已与远程蓝牙设备建立低级别（ACL）连接的公共事件的动作。      |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED         | usual.event.bluetooth.remotedevice.ACL_DISCONNECTED         | ohos.permission.USE_BLUETOOTH                                | 表示低电平（ACL）连接已从远程蓝牙设备断开的普通事件的动作。      |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE              | usual.event.bluetooth.remotedevice.NAME_UPDATE              | ohos.permission.USE_BLUETOOTH                                | 表示远程蓝牙设备的友好名称首次被检索或自上次检索以来被更改的公共事件的操作。        |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE               | usual.event.bluetooth.remotedevice.PAIR_STATE               | ohos.permission.USE_BLUETOOTH                                | 远程蓝牙设备连接状态更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE     | usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE     | ohos.permission.USE_BLUETOOTH                                | 表示远程蓝牙设备的电池电量首次被检索或自上次检索以来被更改的公共事件的动作。      |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT               | usual.event.bluetooth.remotedevice.SDP_RESULT               | 无                                                           | 远程蓝牙设备SDP状态公共事件的动作。     |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE               | usual.event.bluetooth.remotedevice.UUID_VALUE               | ohos.permission.DISCOVER_BLUETOOTH                           | 远程蓝牙设备UUID连接状态公共事件的动作。      |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ              | usual.event.bluetooth.remotedevice.PAIRING_REQ              | ohos.permission.DISCOVER_BLUETOOTH                           | 表示远程蓝牙设备配对请求的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL           | usual.event.bluetooth.remotedevice.PAIRING_CANCEL           | 无                                                           | 取消蓝牙配对的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ              | usual.event.bluetooth.remotedevice.CONNECT_REQ              | 无                                                           | 表示远程蓝牙设备连接请求的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY            | usual.event.bluetooth.remotedevice.CONNECT_REPLY            | 无                                                           | 表示远程蓝牙设备连接请求响应的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL           | usual.event.bluetooth.remotedevice.CONNECT_CANCEL           | 无                                                           | 表示取消与远程蓝牙设备的连接的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE    | 无                                                           | 表示蓝牙免提连接状态已更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE      | usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE      | 无                                                           | 表示蓝牙免提音频状态已更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT         | usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT         | 无                                                           | 表示蓝牙免提音频网关状态已更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE    | 无                                                           | 表示蓝牙免提呼叫状态已更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE                     | usual.event.bluetooth.host.STATE_UPDATE                     | ohos.permission.USE_BLUETOOTH                                | 表示蓝牙适配器状态已更改的公共事件的操作，例如蓝牙已打开或关闭。        |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE                 | usual.event.bluetooth.host.REQ_DISCOVERABLE                 | 无                                                           | 表示用户允许扫描蓝牙请求的公共事件的动作。      |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE                       | usual.event.bluetooth.host.REQ_ENABLE                       | ohos.permission.USE_BLUETOOTH                                | 表示用户打开蓝牙请求的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE                      | usual.event.bluetooth.host.REQ_DISABLE                      | ohos.permission.USE_BLUETOOTH                                | 表示用户关闭蓝牙请求的公共事件的动作。      |
| COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE                 | usual.event.bluetooth.host.SCAN_MODE_UPDATE                 | ohos.permission.USE_BLUETOOTH                                | 设备蓝牙扫描模式更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED                | usual.event.bluetooth.host.DISCOVERY_STARTED                | ohos.permission.USE_BLUETOOTH                                | 设备上已启动蓝牙扫描的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED               | usual.event.bluetooth.host.DISCOVERY_FINISHED               | ohos.permission.USE_BLUETOOTH                                | 设备上蓝牙扫描完成的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE                      | usual.event.bluetooth.host.NAME_UPDATE                      | ohos.permission.USE_BLUETOOTH                                | 表示设备蓝牙适配器名称已更改的公共事件的操作。        |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE         | usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE         | ohos.permission.USE_BLUETOOTH                                | 表示蓝牙A2DP宿连接状态已更改的公共事件的动作。        |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE         | usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE         | ohos.permission.USE_BLUETOOTH                                | 蓝牙A2DP宿播放状态改变的普通事件的动作。        |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE           | usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE           | ohos.permission.USE_BLUETOOTH                                | 表示蓝牙A2DP宿的音频状态已更改的公共事件的动作。        |
| COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED                | usual.event.nfc.action.ADAPTER_STATE_CHANGED                | 无                                                           | 表示设备NFC适配器状态已更改的公共事件的操作。     |
| COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED                 | usual.event.nfc.action.RF_FIELD_ON_DETECTED                 | ohos.permission.MANAGE_SECURE_SETTINGS                       | 检测到NFC RF字段处于使能状态的公共事件的动作。       |
| COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED                | usual.event.nfc.action.RF_FIELD_OFF_DETECTED                | ohos.permission.MANAGE_SECURE_SETTINGS                       | 检测到NFC RF字段处于关闭状态的公共事件的动作。   |
| COMMON_EVENT_DISCHARGING                                     | usual.event.DISCHARGING                                     | 无                                                           | 表示系统停止为电池充电的公共事件的动作。     |
| COMMON_EVENT_CHARGING                                        | usual.event.CHARGING                                        | 无                                                           | 表示系统开始为电池充电的公共事件的动作。    |
| COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED                        | usual.event.DEVICE_IDLE_MODE_CHANGED                        | 无                                                           | 表示系统空闲模式已更改的公共事件的动作。    |
| COMMON_EVENT_POWER_SAVE_MODE_CHANGED                         | usual.event.POWER_SAVE_MODE_CHANGED                         | 无                                                           | 表示系统节能模式更改的公共事件的动作。      |
| COMMON_EVENT_USER_ADDED                                      | usual.event.USER_ADDED                                      | ohos.permission.MANAGE_LOCAL_ACCOUNTS                                 | 表示用户已添加到系统中的公共事件的动作。        |
| COMMON_EVENT_USER_REMOVED                                    | usual.event.USER_REMOVED                                    | ohos.permission.MANAGE_LOCAL_ACCOUNTS                                 | 表示用户已从系统中删除的公共事件的动作。        |
| COMMON_EVENT_ABILITY_ADDED                                   | usual.event.ABILITY_ADDED                                   | ohos.permission.LISTEN_BUNDLE_CHANGE                         | 表示已添加能力的公共事件的动作。     |
| COMMON_EVENT_ABILITY_REMOVED                                 | usual.event.ABILITY_REMOVED                                 | ohos.permission.LISTEN_BUNDLE_CHANGE                         | 表示已删除能力的公共事件的动作。     |
| COMMON_EVENT_ABILITY_UPDATED                                 | usual.event.ABILITY_UPDATED                                 | ohos.permission.LISTEN_BUNDLE_CHANGE                         | 表示能力已更新的公共事件的动作。     |
| COMMON_EVENT_LOCATION_MODE_STATE_CHANGED                     | usual.event.location.MODE_STATE_CHANGED                     | 无                                                           | 表示系统定位模式已更改的公共事件的动作。     |
| COMMON_EVENT_IVI_SLEEP                                       | common.event.IVI_SLEEP                                      | 无                                                           | 表示表示车辆的车载信息娱乐（IVI）系统正在休眠的常见事件的动作。        |
| COMMON_EVENT_IVI_PAUSE                                       | common.event.IVI_PAUSE                                      | 无                                                           | 表示IVI已休眠，并通知应用程序停止播放。    |
| COMMON_EVENT_IVI_STANDBY                                     | common.event.IVI_STANDBY                                    | 无                                                           | 表示第三方应用暂停当前工作的公共事件的动作。     |
| COMMON_EVENT_IVI_LASTMODE_SAVE                               | common.event.IVI_LASTMODE_SAVE                              | 无                                                           | 表示第三方应用保存其最后一个模式的公共事件的动作。      |
| COMMON_EVENT_IVI_VOLTAGE_ABNORMAL                            | common.event.IVI_VOLTAGE_ABNORMAL                           | 无                                                           | 表示车辆电源系统电压异常的公共事件的动作。     |
| COMMON_EVENT_IVI_HIGH_TEMPERATURE                            | common.event.IVI_HIGH_TEMPERATURE                           | 无                                                           | 表示IVI温度过高。     |
| COMMON_EVENT_IVI_EXTREME_TEMPERATURE                         | common.event.IVI_EXTREME_TEMPERATURE                        | 无                                                           | 表示IVI温度极高。     |
| COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL                        | common.event.IVI_TEMPERATURE_ABNORMAL                       | 无                                                           | 表示车载系统具有极端温度的常见事件的动作。     |
| COMMON_EVENT_IVI_VOLTAGE_RECOVERY                            | common.event.IVI_VOLTAGE_RECOVERY                           | 无                                                           | 表示车辆电源系统电压恢复正常的公共事件的动作。     |
| COMMON_EVENT_IVI_TEMPERATURE_RECOVERY                        | common.event.IVI_TEMPERATURE_RECOVERY                       | 无                                                           | 表示车载系统温度恢复正常的公共事件的动作。     |
| COMMON_EVENT_IVI_ACTIVE                                      | common.event.IVI_ACTIVE                                     | 无                                                           | 表示电池服务处于活动状态的公共事件的动作。        |
|COMMON_EVENT_USB_STATE<sup>9+</sup>                           | usual.event.hardware.usb.action.USB_STATE                   | 无                                                           | 表示USB设备状态发生变化的公共事件。     |
|COMMON_EVENT_USB_PORT_CHANGED<sup>9+</sup>                    | usual.event.hardware.usb.action.USB_PORT_CHANGED            | 无                                                           | 表示用户设备的USB端口状态发生改变的公共事件。          |
| COMMON_EVENT_USB_DEVICE_ATTACHED                             | usual.event.hardware.usb.action.USB_DEVICE_ATTACHED         | 无                                                           | 当用户设备作为USB主机时，USB设备已挂载的公共事件的动作。       |
| COMMON_EVENT_USB_DEVICE_DETACHED                             | usual.event.hardware.usb.action.USB_DEVICE_DETACHED         | 无                                                           | 当用户设备作为USB主机时，USB设备被卸载的公共事件的动作。       | 
| COMMON_EVENT_USB_ACCESSORY_ATTACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED      | 无                                                           | 表示已连接USB附件的公共事件的动作。       |
| COMMON_EVENT_USB_ACCESSORY_DETACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED      | 无                                                           | 表示USB附件被卸载的公共事件的动作。     |
| COMMON_EVENT_DISK_REMOVED                                    | usual.event.data.DISK_REMOVED                               | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为移除时发送此公共事件。     |
| COMMON_EVENT_DISK_UNMOUNTED                                  | usual.event.data.DISK_UNMOUNTED                             | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为卸载时发送此公共事件。     |
| COMMON_EVENT_DISK_MOUNTED                                    | usual.event.data.DISK_MOUNTED                               | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为挂载时发送此公共事件。     |
| COMMON_EVENT_DISK_BAD_REMOVAL                                | usual.event.data.DISK_BAD_REMOVAL                           | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为挂载状态下移除时发送此公共事件。       |
| COMMON_EVENT_DISK_UNMOUNTABLE                                | usual.event.data.DISK_UNMOUNTABLE                           | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为插卡情况下无法挂载时发送此公共事件。     |
| COMMON_EVENT_DISK_EJECT                                      | usual.event.data.DISK_EJECT                                 | ohos.permission.STORAGE_MANAGER | 用户已表示希望删除外部存储介质时发送此公共事件。       |
| COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>                                  | usual.event.data.VOLUME_REMOVED                             | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为移除时发送此公共事件。     |
| COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>                                | usual.event.data.VOLUME_UNMOUNTED                           | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为卸载时发送此公共事件。     |
| COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>                                  | usual.event.data.VOLUME_MOUNTED                             | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为挂载时发送此公共事件。     |
| COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>                              | usual.event.data.VOLUME_BAD_REMOVAL                         | ohos.permission.STORAGE_MANAGER | 外部存储设备状态变更为挂载状态下移除时发送此公共事件。       |
| COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>                                    | usual.event.data.VOLUME_EJECT                               | ohos.permission.STORAGE_MANAGER | 用户已表示希望删除外部存储介质时发送此公共事件。       |
| COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED                        | usual.event.data.VISIBLE_ACCOUNTS_UPDATED                   | ohos.permission.GET_APP_ACCOUNTS                             | 表示帐户可见更改的公共事件的动作。        |
| COMMON_EVENT_ACCOUNT_DELETED                                 | usual.event.data.ACCOUNT_DELETED                            | ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS               | 删除帐户的公共事件的动作。      |
| COMMON_EVENT_FOUNDATION_READY                                | usual.event.data.FOUNDATION_READY                           | ohos.permission.RECEIVER_STARTUP_COMPLETED                   | 表示foundation已准备好的公共事件的动作。      |
| COMMON_EVENT_AIRPLANE_MODE_CHANGED                           | usual.event.AIRPLANE_MODE                                   | 无                                                           | 表示设备飞行模式已更改的公共事件的动作。      |
| COMMON_EVENT_SPLIT_SCREEN<sup>8+<sup>                                    | usual.event.SPLIT_SCREEN                                    | ohos.permission.RECEIVER_SPLIT_SCREEN                        | 表示分屏的公共事件的动作。      |
| COMMON_EVENT_SLOT_CHANGE<sup>9+<sup>                                    | usual.event.SLOT_CHANGE                                    | ohos.permission.NOTIFICATION_CONTROLLER                        | 表示通知通道更新的动作。      |
| COMMON_EVENT_SPN_INFO_CHANGED <sup>9+<sup>                                    | usual.event.SPN_INFO_CHANGED                                    | 无                        | 表示spn显示信息已更新的公共事件的动作。      |
| COMMON_EVENT_QUICK_FIX_APPLY_RESULT <sup>9+<sup>                                    | usual.event.QUICK_FIX_APPLY_RESULT                        | 无                        | 表示快速修复应用的动作。      |


## CommonEventManager.publish

publish(event: string, callback: AsyncCallback\<void>): void

发布公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称     | 类型                 | 必填 | 描述                   |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | 是   | 表示要发送的公共事件。 |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**错误码：**
以下错误码详细介绍请参考[@ohos.commonEventManager(事件)](../errorcodes/errorcode-CommonEventService.md)

|错误码ID    |错误信息            |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

**示例：**

```ts
//发布公共事件回调
function PublishCallBack(err) {
	if (err) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

//发布公共事件
try {
    CommonEventManager.publish("event", PublishCallBack);
} catch(err) {
    console.error('publish failed, catch error' + JSON.stringify(err));
}
```

## CommonEventManager.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

发布公共事件指定发布信息（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称     | 类型                   | 必填 | 描述                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | 是   | 表示要发布的公共事件。  |
| options  | [CommonEventPublishData](#commoneventpublishdata) | 是   | 表示发布公共事件的属性。 |
| callback | syncCallback\<void>   | 是   | 表示被指定的回调方法。  |

**错误码：**
|错误码ID    |错误信息            |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|


**示例：**


```ts
//公共事件相关信息
var options = {
	code: 0,			 //公共事件的初始代码
	data: "initial data",//公共事件的初始数据
	isOrdered: true	 //有序公共事件
}

//发布公共事件回调
function PublishCallBack(err) {
	if (err) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

//发布公共事件
try {
    CommonEventManager.publish("event", options, PublishCallBack);
} catch (err) {
    console.error('publish failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.publishAsUser<sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

向指定用户发布公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                 | 必填 | 描述                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | 是   | 表示要发送的公共事件。             |
| userId   | number               | 是   | 表示指定向该用户ID发送此公共事件。 |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。             |

**错误码：**
|错误码ID    |错误信息            |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

**示例：**

```ts
//发布公共事件回调
function PublishAsUserCallBack(err) {
	if (err) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

//指定发送的用户
var userId = 100;

//发布公共事件
try {
    CommonEventManager.publishAsUser("event", userId, PublishAsUserCallBack);
} catch (err) {
    console.error('publishAsUser failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.publishAsUser

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

向指定用户发布公共事件并指定发布信息（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                   | 必填 | 描述                   |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | 是   | 表示要发布的公共事件。  |
| userId   | number | 是 | 表示指定向该用户ID发送此公共事件。 |
| options  | [CommonEventPublishData](#commoneventpublishdata) | 是   | 表示发布公共事件的属性。 |
| callback | AsyncCallback\<void>   | 是   | 表示被指定的回调方法。  |

**错误码：**
|错误码ID    |错误信息            |
|-----------|--------------------|
|1500004    |not System services or System app|
|1500007    |message send error|
|1500008    |CEMS error|
|1500009    |system error|

**示例：**


```ts
//公共事件相关信息
var options = {
	code: 0,			 //公共事件的初始代码
	data: "initial data",//公共事件的初始数据
}

//发布公共事件回调
function PublishAsUserCallBack(err) {
	if (err) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

//指定发送的用户
var userId = 100;

//发布公共事件
try {
    CommonEventManager.publishAsUser("event", userId, options, PublishAsUserCallBack);
} catch (err) {
    console.error('publishAsUser failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

创建订阅者（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称          | 类型                                                         | 必填 | 描述                       |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](#commoneventsubscribeinfo)        | 是   | 表示订阅信息。             |
| callback      | AsyncCallback\<[CommonEventSubscriber](#commoneventsubscriber)> | 是   | 表示创建订阅者的回调方法。 |

**示例：**


```ts
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
    events: ["event"]
};

//创建订阅者回调
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    } else {
        console.error("createSubscriber failed " + JSON.stringify(err));
    }
}

//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
} catch (err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

创建订阅者（Promise形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称          | 类型                                                  | 必填 | 描述           |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](#commoneventsubscribeinfo) | 是   | 表示订阅信息。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](#commoneventsubscriber)> | 返回订阅者对象。 |

**示例：**

```ts
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
	events: ["event"]
};

//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err) => {
    console.error("createSubscriber failed " + JSON.stringify(err));
});
} catch(err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}

```



## CommonEventManager.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

订阅公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称       | 类型                                                | 必填 | 描述                             |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](#commoneventsubscriber)     | 是   | 表示订阅者对象。                 |
| callback   | AsyncCallback\<[CommonEventData](#commoneventdata)> | 是   | 表示接收公共事件数据的回调函数。 |

**示例：**

```ts
//订阅者信息
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
    events: ["event"]
};

//订阅公共事件回调
function SubscribeCallBack(err, data) {
    if (err.code) {
        console.error("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe ");
    }
}

//创建订阅者回调
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        //订阅公共事件
        try {
            CommonEventManager.subscribe(subscriber, SubscribeCallBack);
        } catch (err) {
            console.error("createSubscriber failed " + JSON.stringify(err));
        }
    } else {
        console.error("createSubscriber failed " + JSON.stringify(err));
    }
}

//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
} catch (err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
}
```



## CommonEventManager.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

取消订阅公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称       | 类型                                             | 必填 | 描述                     |
| ---------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | [CommonEventSubscriber](#commoneventsubscriber) | 是   | 表示订阅者对象。         |
| callback   | AsyncCallback\<void>                            | 否   | 表示取消订阅的回调方法。 |

**示例：**

```ts
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作
//订阅者信息
var subscribeInfo = {
    events: ["event"]
};
//订阅公共事件回调
function SubscribeCallBack(err, data) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe");
    }
}
//创建订阅者回调
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if (err) {
        console.info("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        //订阅公共事件
        try {
            CommonEventManager.subscribe(subscriber, SubscribeCallBack);
        } catch(err) {
            console.info("subscribe failed " + JSON.stringify(err));
        }
    }
}
//取消订阅公共事件回调
function UnsubscribeCallBack(err) {
    if (err) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe");
    }
}
//创建订阅者
try {
    CommonEventManager.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
} catch (err) {
    console.info("createSubscriber failed " + JSON.stringify(err));
}

//取消订阅公共事件
try {
    CommonEventManager.unsubscribe(subscriber, UnsubscribeCallBack);
} catch (err) {
    console.info("unsubscribe failed " + JSON.stringify(err));
}
```

## CommonEventSubscriber

### getCode

getCode(callback: AsyncCallback\<number>): void

获取公共事件的结果代码（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                   | 必填 | 描述               |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | 是   | 公共事件的结果代码。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取有序公共事件的结果代码回调
function getCodeCallback(err, Code) {
    if (err.code) {
        console.error("getCode failed " + JSON.stringify(err));
    } else {
        console.info("getCode " + JSON.stringify(Code));
    }
}
subscriber.getCode(getCodeCallback);
```

### getCode

getCode(): Promise\<number>

获取公共事件的结果代码（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<number> | 公共事件的结果代码。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.getCode().then((Code) => {
    console.info("getCode " + JSON.stringify(Code));
}).catch((err) => {
    console.error("getCode failed " + JSON.stringify(err));
});
```

### setCode

setCode(code: number, callback: AsyncCallback\<void>): void

设置公共事件的结果代码（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的结果代码。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果代码回调
function setCodeCallback(err) {
    if (err.code) {
        console.error("setCode failed " + JSON.stringify(err));
    } else {
        console.info("setCode");
    }
}
subscriber.setCode(1, setCodeCallback);
```

### setCode

setCode(code: number): Promise\<void>

设置公共事件的结果代码（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 描述               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | 公共事件的结果代码。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error("setCode failed " + JSON.stringify(err));
});
```

### getData

getData(callback: AsyncCallback\<string>): void

获取公共事件的结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                   | 必填 | 描述                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | 是   | 公共事件的结果数据。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取有序公共事件的结果数据回调
function getDataCallback(err, Data) {
    if (err.code) {
        console.error("getData failed " + JSON.stringify(err));
    } else {
        console.info("getData " + JSON.stringify(Data));
    }
}
subscriber.getData(getDataCallback);
```

### getData

getData(): Promise\<string>

获取公共事件的结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明               |
| ---------------- | ------------------ |
| Promise\<string> | 公共事件的结果数据。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.getData().then((Data) => {
    console.info("getData " + JSON.stringify(Data));
}).catch((err) => {
    console.error("getData failed " + JSON.stringify(err));
});
```

### setData

setData(data: string, callback: AsyncCallback\<void>): void

设置公共事件的结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | 是   | 公共事件的结果数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function setDataCallback(err) {
    if (err.code) {
        console.error("setData failed " + JSON.stringify(err));
    } else {
        console.info("setData");
    }
}
subscriber.setData("publish_data_changed", setDataCallback);
```

### setData

setData(data: string): Promise\<void>

设置公共事件的结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 描述                 |
| ------ | ------ | ---- | -------------------- |
| data   | string | 是   | 公共事件的结果数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error("setData failed " + JSON.stringify(err));
});
```

### setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

设置公共事件的结果代码和结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的结果代码。   |
| data     | string               | 是   | 公共事件的结果数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果代码和结果数据回调
function setCodeDataCallback(err) {
    if (err.code) {
        console.error("setCodeAndData failed " + JSON.stringify(err));
    } else {
        console.info("setCodeDataCallback");
    }
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCallback);
```

### setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

设置公共事件的结果代码和结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 描述                 |
| ------ | ------ | ---- | -------------------- |
| code   | number | 是   | 公共事件的结果代码。 |
| data   | string | 是   | 公共事件的结果数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.info("setCodeAndData failed " + JSON.stringify(err));
});
```

### isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

查询当前公共事件的是否为有序公共事件（callback形式）。

返回true代表是有序公共事件，false代表不是有序公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 描述                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为有序公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取当前公共事件是否为有序事件的回调
function isOrderedCallback(err, isOrdered) {
    if (err.code) {
        console.error("isOrderedCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isOrdered " + JSON.stringify(isOrdered));
    }
}
subscriber.isOrderedCommonEvent(isOrderedCallback);
```

### isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

查询当前公共事件的是否为有序公共事件（Promise形式）。

返回true代表是有序公共事件，false代表不是有序公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | 当前公共事件的是否为有序公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error("isOrdered failed " + JSON.stringify(err));
});
```

### isStickyCommonEvent

isStickyCommonEvent(callback: AsyncCallback\<boolean>): void

检查当前公共事件是否为一个粘性事件（callback形式）。

返回true代表是粘性公共事件，false代表不是粘性公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 描述                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为粘性公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取当前公共事件是否为粘性事件的回调
function isStickyCallback(err, isSticky) {
    if (err.code) {
        console.error("isStickyCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isSticky " + JSON.stringify(isSticky));
    }
}
subscriber.isStickyCommonEvent(isStickyCallback);
```

### isStickyCommonEvent

isStickyCommonEvent(): Promise\<boolean>

检查当前公共事件是否为一个粘性事件（Promise形式）。

返回true代表是粘性公共事件，false代表不是粘性公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | 当前公共事件的是否为粘性公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error("isSticky failed " + JSON.stringify(err));
});
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

取消当前的公共事件，仅对有序公共事件有效，取消后，公共事件不再向下一个订阅者传递（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 取消当前的公共事件。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//取消当前有序公共事件的回调
function abortCallback(err) {
    if (err.code) {
        console.error("abortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("abortCommonEvent");
    }
}
subscriber.abortCommonEvent(abortCallback);
```

### abortCommonEvent

abortCommonEvent(): Promise\<void>

取消当前的公共事件，仅对有序公共事件有效，取消后，公共事件不再向下一个订阅者传递（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error("abortCommonEvent failed " + JSON.stringify(err));
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

清除当前公共事件的取消状态，仅对有序公共事件有效（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//清除当前公共事件取消状态的回调
function clearAbortCallback(err) {
    if (err.code) {
        console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("clearAbortCommonEvent");
    }
}
subscriber.clearAbortCommonEvent(clearAbortCallback);
```

### clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

清除当前公共事件的取消状态，仅对有序公共事件有效（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

获取当前有序公共事件是否取消的状态（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 描述                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 表示当前有序公共事件是否取消的状态。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取当前有序公共事件是否取消的回调
function getAbortCallback(err, AbortCommonEvent) {
    if (err.code) {
        console.error("getAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("AbortCommonEvent " + AbortCommonEvent)
    }
}
subscriber.getAbortCommonEvent(getAbortCallback);
```

### getAbortCommonEvent

getAbortCommonEvent(): Promise\<boolean>

获取当前有序公共事件是否取消的状态（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                               |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | 表示当前有序公共事件是否取消的状态。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.getAbortCommonEvent().then((AbortCommonEvent) => {
    console.info("AbortCommonEvent " + JSON.stringify(AbortCommonEvent));
}).catch((err) => {
    console.error("getAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

获取订阅者的订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                                                         | 必填 | 描述                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | 是   | 表示订阅者的订阅信息。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

//获取订阅者信息回调
function getSubscribeInfoCallback(err, SubscribeInfo) {
    if (err.code) {
        console.error("getSubscribeInfo failed " + JSON.stringify(err));
    } else {
        console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
    }
}
subscriber.getSubscribeInfo(getSubscribeInfoCallback);
```

### getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

获取订阅者的订阅信息（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | 表示订阅者的订阅信息。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.getSubscribeInfo().then((SubscribeInfo) => {
    console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
}).catch((err) => {
    console.error("getSubscribeInfo failed " + JSON.stringify(err));
});
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(callback: AsyncCallback\<void\>): void

结束当前有序公共事件（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                  | 必填 | 描述                              |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | 是   | 表示有序公共事件结束后的回调函数。 |

**示例：**

```ts
var subscriber; //创建成功的订阅者对象

//结束当前有序公共事件的回调
function finishCommonEventCallback(err) {
  if (err.code) {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
} else {
    console.info("FinishCommonEvent");
}
}
subscriber.finishCommonEvent(finishCommonEventCallback);
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(): Promise\<void\>

结束当前有序公共事件（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```ts
var subscriber;	//创建成功的订阅者对象

subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
});
```

## CommonEventData

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称       | 可读 | 可写 | 类型                 | 描述                                                    |
| ---------- | ---- | ---- | -------------------- | ------------------------------------------------------- |
| event      | 是  | 否  | string               | 表示当前接收的公共事件名称。                              |
| bundleName | 是  | 否  | string               | 表示包名称。                                              |
| code       | 是  | 否  | number               | 表示公共事件的结果代码，用于传递int类型的数据。           |
| data       | 是  | 否  | string               | 表示公共事件的自定义结果数据，用于传递string类型的数据。 |
| parameters | 是  | 否  | {[key: string]: any} | 表示公共事件的附加信息。                                  |


## CommonEventPublishData

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称                  | 可读 | 可写 | 类型                 | 描述                         |
| --------------------- | ---- | ---- | -------------------- | ---------------------------- |
| bundleName            | 是  | 否  | string               | 表示包名称。                   |
| code                  | 是  | 否  | number               | 表示公共事件的结果代码。       |
| data                  | 是  | 否  | string               | 表示公共事件的自定义结果数据。 |
| subscriberPermissions | 是  | 否  | Array\<string>       | 表示订阅者的权限。             |
| isOrdered             | 是  | 否  | boolean              | 表示是否是有序事件。           |
| isSticky              | 是  | 否  | boolean              | 表示是否是粘性事件。仅系统应用或系统服务允许发送粘性事件。 |
| parameters            | 是  | 否  | {[key: string]: any} | 表示公共事件的附加信息。       |

## CommonEventSubscribeInfo

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称                | 可读 | 可写 | 类型           | 描述                                                         |
| ------------------- | ---- | ---- | -------------- | ------------------------------------------------------------ |
| events              | 是  | 否  | Array\<string> | 表示要发送的公共事件。                                         |
| publisherPermission | 是  | 否  | string         | 表示发布者的权限。                                             |
| publisherDeviceId   | 是  | 否  | string         | 表示设备ID，该值必须是同一ohos网络上的现有设备ID。             |
| userId              | 是  | 否  | number         | 表示用户ID。此参数是可选的，默认值当前用户的ID。如果指定了此参数，则该值必须是系统中现有的用户ID。 |
| priority            | 是  | 否  | number         | 表示订阅者的优先级。值的范围是-100到1000。                     |