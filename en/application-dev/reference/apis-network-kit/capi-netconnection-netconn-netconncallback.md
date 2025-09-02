# NetConn_NetConnCallback

## Overview

Defines network status callbacks.

**Since**: 12

**Related module**: [NetConnection](capi-netconnection.md)

**Header file**: [net_connection_type.h](capi-net-connection-type-h.md)

## Summary

### Member Variables

| Name                                                                                                                                      | Description|
|------------------------------------------------------------------------------------------------------------------------------------------| -- |
| [OH_NetConn_NetworkAvailable](capi-net-connection-type-h.md#oh_netconn_networkavailable) onNetworkAvailable                              | Callback invoked when the network is available.|
| [OH_NetConn_NetCapabilitiesChange](capi-net-connection-type-h.md#oh_netconn_netcapabilitieschange) onNetCapabilitiesChange               | Callback invoked when the network capabilities change.|
| [OH_NetConn_NetConnectionPropertiesChange](capi-net-connection-type-h.md#oh_netconn_netconnectionpropertieschange) onConnetionProperties | Callback invoked when network connection properties change.|
| [OH_NetConn_NetLost](capi-net-connection-type-h.md#oh_netconn_netlost) onNetLost                                                         | Callback invoked when the network is disconnected.|
| [OH_NetConn_NetUnavailable](capi-net-connection-type-h.md#oh_netconn_netunavailable) onNetUnavailable                                    | Callback invoked when the network is unavailable. This callback is triggered when the network is not activated within the specified timeout interval. If the timeout interval is not set, this callback is not triggered.|
| [OH_NetConn_NetBlockStatusChange](capi-net-connection-type-h.md#oh_netconn_netblockstatuschange) onNetBlockStatusChange                  | Callback invoked when the network blocking status changes.|
