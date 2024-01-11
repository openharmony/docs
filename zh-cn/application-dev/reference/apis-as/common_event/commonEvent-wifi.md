# Wifi子系统公共事件定义
Wifi子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_WIFI_POWER_STATE
Wi-Fi状态公共事件的动作，如启用和禁用。

- 常量值： usual.event.wifi.POWER_STATE
- 订阅方需要的权限： 无需权限

当Wi-Fi状态发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_SCAN_FINISHED
表示Wi-Fi接入点已被扫描并证明可用的公共事件的操作。

- 常量值： usual.event.wifi.SCAN_FINISHED
- 订阅方需要的权限： ohos.permission.LOCATION

当Wi-Fi接入点已被扫描并证明可用，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_SCAN_STATE
表示Wi-Fi扫描接入点状态改变的公共事件的操作。

- 常量值： usual.event.wifi.SCAN_STATE
- 订阅方需要的权限： ohos.permission.LOCATION

当Wi-Fi扫描接入点状态发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_RSSI_VALUE
表示Wi-Fi信号强度（RSSI）改变的公共事件的动作。

- 常量值： usual.event.wifi.RSSI_VALUE
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO

当Wi-Fi信号强度（RSSI）发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_CONN_STATE
Wi-Fi连接状态发生改变的公共事件的动作

- 常量值： usual.event.wifi.CONN_STATE
- 订阅方需要的权限： 无需权限

当Wi-Fi连接状态发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_HOTSPOT_STATE
Wi-Fi热点状态的公共事件的动作，如启用或禁用。

- 常量值： usual.event.wifi.HOTSPOT_STATE
- 订阅方需要的权限： 无需权限

当Wi-Fi热点状态发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_AP_STA_JOIN
客户端加入当前设备Wi-Fi热点的普通事件的动作。

- 常量值： usual.event.wifi.WIFI_HS_STA_JOIN
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO

当客户端加入当前设备Wi-Fi热点，将会触发事件通知服务发布该系统公共事件。


## COMMON_EVENT_WIFI_AP_STA_LEAVE
客户端已断开与当前设备Wi-Fi热点的连接的公共事件的动作。

- 常量值： usual.event.wifi.WIFI_HS_STA_LEAVE
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO

当客户端已断开与当前设备Wi-Fi热点的连接，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE
表示MPLink（增强Wi-Fi功能）状态已更改的公共事件的动作。

- 常量值： usual.event.wifi.mplink.STATE_CHANGE
- 订阅方需要的权限： ohos.permission.MPLINK_CHANGE_STATE

当MPLink（增强Wi-Fi功能）状态发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_P2P_CONN_STATE
Wi-Fi P2P连接状态改变的公共事件的动作。

- 常量值： usual.event.wifi.p2p.CONN_STATE_CHANGE
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO和ohos.permission.LOCATION

当Wi-Fi P2P连接状态发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_P2P_STATE_CHANGED
Wi-Fi P2P状态公共事件的动作，如启用和禁用。

- 常量值： usual.event.wifi.p2p.STATE_CHANGE
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO

当Wi-Fi P2P状态发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED
Wi-Fi P2P对等体状态变化。

- 常量值： usual.event.wifi.p2p.DEVICES_CHANGE
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO

当Wi-Fi P2P对等体状态变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED
Wi-Fi P2P发现状态变化。

- 常量值： usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO

当Wi-Fi P2P发现状态变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED
Wi-Fi P2P当前设备状态变化。

- 常量值： usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO

当Wi-Fi P2P当前设备状态变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED
Wi-Fi P2P群组信息已更改。

- 常量值： usual.event.wifi.p2p.GROUP_STATE_CHANGED
- 订阅方需要的权限： ohos.permission.GET_WIFI_INFO

当Wi-Fi P2P群组信息发生变化，将会触发事件通知服务发布该系统公共事件。