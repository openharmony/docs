# net_connection_type.h


## 概述

定义网络连接模块的C接口需要的数据结构。

**库：** libnet_connection.so

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**相关模块：**[NetConnection](_net_connection.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [NetConn_NetHandle](_net_conn___net_handle.md) | 存放网络ID。 | 
| [NetConn_NetCapabilities](_net_conn___net_capabilities.md) | 网络能力集。 | 
| [NetConn_NetAddr](_net_conn___net_addr.md) | 网络地址。 | 
| [NetConn_Route](_net_conn___route.md) | 路由配置信息。 | 
| [NetConn_HttpProxy](_net_conn___http_proxy.md) | 代理配置信息。 | 
| [NetConn_ConnectionProperties](_net_conn___connection_properties.md) | 网络链接信息。 | 
| [NetConn_NetHandleList](_net_conn___net_handle_list.md) | 网络列表。 | 
| [NetConn_NetConnCallback](_net_conn___net_conn_callback.md) | 网络状态监听回调集合。  | 
| [NetConn_NetSpecifier](_net_conn___net_specifier.md) | 网络的特征集，包含网络的能力集与网络的标识符。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| **NETCONN_MAX_NET_SIZE** | 32 | 
| **NETCONN_MAX_BEARER_TYPE_SIZE** | 32 | 
| **NETCONN_MAX_CAP_SIZE** | 32 | 
| **NETCONN_MAX_ADDR_SIZE** | 32 | 
| **NETCONN_MAX_ROUTE_SIZE** | 64 | 
| **NETCONN_MAX_EXCLUSION_SIZE** | 256 | 
| **NETCONN_MAX_STR_LEN** | 256 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [NetConn_NetCap](_net_connection.md#netconn_netcap) | 网络能力集。 | 
| [NetConn_NetBearerType](_net_connection.md#netconn_netbearertype) | 网络载体类型。 | 
| [NetConn_NetHandle](_net_connection.md#netconn_nethandle) | 存放网络ID。 | 
| [NetConn_NetCapabilities](_net_connection.md#netconn_netcapabilities) | 网络能力集。 | 
| [NetConn_NetAddr](_net_connection.md#netconn_netaddr) | 网络地址。 | 
| [NetConn_Route](_net_connection.md#netconn_route) | 路由配置信息。 | 
| [NetConn_HttpProxy](_net_connection.md#netconn_httpproxy) | 代理配置信息。 | 
| [NetConn_ConnectionProperties](_net_connection.md#netconn_connectionproperties) | 网络链接信息。 | 
| [NetConn_NetHandleList](_net_connection.md#netconn_nethandlelist) | 网络列表。 | 
| (\*[OH_NetConn_CustomDnsResolver](_net_connection.md#oh_netconn_customdnsresolver)) (const char \*host, const char \*serv, const struct addrinfo \*hint, struct addrinfo \*\*res) | 指向自定义 DNS 解析器的指针。 | 
| [NetConn_ErrorCode](_net_connection.md#netconn_errorcode) | 网络连接返回值错误码。 |


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NetConn_NetCap](_net_connection.md#netconn_netcap) {<br/>[NETCONN_NET_CAPABILITY_MMS](_net_connection.md) = 0,<br/>[NETCONN_NET_CAPABILITY_NOT_METERED](_net_connection.md) = 11,<br/>[NETCONN_NET_CAPABILITY_INTERNET](_net_connection.md) = 12,<br/>[NETCONN_NET_CAPABILITY_NOT_VPN](_net_connection.md) = 15,<br/>[NETCONN_NET_CAPABILITY_VALIDATED](_net_connection.md) = 16<br/>} | 网络能力集。 | 
| [NetConn_NetBearerType](_net_connection.md#netconn_netbearertype) {<br/>[NETCONN_BEARER_CELLULAR](_net_connection.md#netconn_netbearertype-1) = 0,<br/>[NETCONN_BEARER_WIFI](_net_connection.md#netconn_netbearertype-1) = 1,<br/>[NETCONN_BEARER_ETHERNET](_net_connection.md#netconn_netbearertype-1) = 3<br/>[NETCONN_BEARER_VPN](_net_connection.md#netconn_netbearertype-1) = 4<br/>} | 网络载体类型。 |
| [NetConn_ErrorCode](_net_connection.md#netconn_errorcode) {<br/>[NETCONN_SUCCESS](_net_connection.md#netconn_errorcode-1) = 0,<br/>[NETCONN_PERMISSION_DENIED](_net_connection.md#netconn_errorcode-1) = 201,<br/>[NETCONN_PARAMETER_ERROR](_net_connection.md#netconn_errorcode-1) = 401,<br/>[NETCONN_OPERATION_FAILED](_net_connection.md#netconn_errorcode-1) = 2100002,<br/>[NETCONN_INTERNAL_ERROR](_net_connection.md#netconn_errorcode-1) = 2100003<br/>} | 网络连接返回值错误码。 |
