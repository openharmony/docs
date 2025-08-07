# NetConn_NetConnCallback

## 概述

网络状态监听回调集合。

**起始版本：** 12

**相关模块：** [NetConnection](capi-netconnection.md)

**所在头文件：** [net_connection_type.h](capi-net-connection-type-h.md)

## 汇总

### 成员变量

| 名称                                                                                                                                       | 描述 |
|------------------------------------------------------------------------------------------------------------------------------------------| -- |
| [OH_NetConn_NetworkAvailable](capi-net-connection-type-h.md#oh_netconn_networkavailable) onNetworkAvailable                              | 网络可用回调。 |
| [OH_NetConn_NetCapabilitiesChange](capi-net-connection-type-h.md#oh_netconn_netcapabilitieschange) onNetCapabilitiesChange               | 网络能力集变更回调。 |
| [OH_NetConn_NetConnectionPropertiesChange](capi-net-connection-type-h.md#oh_netconn_netconnectionpropertieschange) onConnetionProperties | 网络连接属性变更回调。 |
| [OH_NetConn_NetLost](capi-net-connection-type-h.md#oh_netconn_netlost) onNetLost                                                         | 网络断开回调。 |
| [OH_NetConn_NetUnavailable](capi-net-connection-type-h.md#oh_netconn_netunavailable) onNetUnavailable                                    | 网络不可用回调, 在指定的超时时间内网络未激活时触发该回调，如果未设置超时时间则不会触发该回调。 |
| [OH_NetConn_NetBlockStatusChange](capi-net-connection-type-h.md#oh_netconn_netblockstatuschange) onNetBlockStatusChange                  | 网络阻塞状态变更回调。 |
