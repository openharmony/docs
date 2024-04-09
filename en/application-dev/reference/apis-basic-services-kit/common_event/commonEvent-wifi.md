# Common Events of the Wi-Fi Subsystem
This document lists the common system events provided by the Wi-Fi subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_WIFI_POWER_STATE
Indicates that the Wi-Fi state has changed, for example, enabled or disabled.

- Value: usual.event.wifi.POWER_STATE
- Required subscriber permissions: none

When the Wi-Fi state changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_SCAN_FINISHED
Indicates that the Wi-Fi access point has been detected and proven to be available.

- Value: usual.event.wifi.SCAN_FINISHED
- Required subscriber permissions: ohos.permission.LOCATION

When a Wi-Fi access point is detected and proven to be available, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_SCAN_STATE
Indicates that the Wi-Fi access point state has changed.

- Value: usual.event.wifi.SCAN_STATE
- Required subscriber permissions: ohos.permission.LOCATION

When the Wi-Fi access point state changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_RSSI_VALUE
Indicates that the Wi-Fi signal strength (RSSI) has changed.

- Value: usual.event.wifi.RSSI_VALUE
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO

When the Wi-Fi signal strength (RSSI) changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_CONN_STATE
Indicates that the Wi-Fi connection state has changed.

- Value: usual.event.wifi.CONN_STATE
- Required subscriber permissions: none

When the Wi-Fi connection state changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_HOTSPOT_STATE
Indicates that the Wi-Fi hotspot state has changed, for example, enabled or disabled.

- Value: usual.event.wifi.HOTSPOT_STATE
- Required subscriber permissions: none

When the Wi-Fi hotspot state changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_AP_STA_JOIN
Indicates that a client has joined the Wi-Fi hotspot of the current device.

- Value: usual.event.wifi.WIFI_HS_STA_JOIN
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO

When a client joins the Wi-Fi hotspot of the current device, the event notification service is triggered to publish this event.


## COMMON_EVENT_WIFI_AP_STA_LEAVE
Indicates that a client has disconnected from the Wi-Fi hotspot of the current device.

- Value: usual.event.wifi.WIFI_HS_STA_LEAVE
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO

When a client is disconnected from the Wi-Fi hotspot of the current device, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE
Indicates that the state of MPLINK (an enhanced Wi-Fi feature) has changed.

- Value: usual.event.wifi.mplink.STATE_CHANGE
- Required subscriber permissions: ohos.permission.MPLINK_CHANGE_STATE

When the state of MPLINK (an enhanced Wi-Fi feature) changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_P2P_CONN_STATE
Indicates that the Wi-Fi P2P connection state has changed.

- Value: usual.event.wifi.p2p.CONN_STATE_CHANGE
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

When the Wi-Fi P2P connection state changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_P2P_STATE_CHANGED
Indicates that the Wi-Fi P2P state has changed, for example, enabled or disabled.

- Value: usual.event.wifi.p2p.STATE_CHANGE
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO

When the Wi-Fi P2P state changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED
Indicates that the state of the Wi-Fi P2P peer device has changed.

- Value: usual.event.wifi.p2p.DEVICES_CHANGE
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO

When the state of the Wi-Fi P2P peer device changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED
Indicates that the Wi-Fi P2P discovery state has changed.

- Value: usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO

When the Wi-Fi P2P discovery state changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED
Indicates that the state of the Wi-Fi P2P local device has changed.

- Value: usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO

When the state of the Wi-Fi P2P local device changes, the event notification service is triggered to publish this event.

## COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED
Indicates that the Wi-Fi P2P group information has changed.

- Value: usual.event.wifi.p2p.GROUP_STATE_CHANGED
- Required subscriber permissions: ohos.permission.GET_WIFI_INFO

When the Wi-Fi P2P group information changes, the event notification service is triggered to publish this event.
