# net_connection.h


## 概述

为网络管理数据网络连接模块提供C接口。

**系统能力：** SystemCapability.Communication.NetManager.Core

**库：** libnet_connection.so

**起始版本：** 11

**相关模块：**[NetConnection](_net_connection.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NetConn_HasDefaultNet](_net_connection.md#oh_netconn_hasdefaultnet) (int32_t \*hasDefaultNet) | 查询是否有默认激活的数据网络。 | 
| [OH_NetConn_GetDefaultNet](_net_connection.md#oh_netconn_getdefaultnet) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle) | 获取激活的默认的数据网络。 | 
| [OH_NetConn_IsDefaultNetMetered](_net_connection.md#oh_netconn_isdefaultnetmetered) (int32_t \*isMetered) | 查询默认网络是否按流量计费。 | 
| [OH_NetConn_GetConnectionProperties](_net_connection.md#oh_netconn_getconnectionproperties) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_ConnectionProperties](_net_conn___connection_properties.md) \*prop) | 查询某个数据网络的链路信息。 | 
| [OH_NetConn_GetNetCapabilities](_net_connection.md#oh_netconn_getnetcapabilities) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_NetCapabilities](_net_conn___net_capabilities.md) \*netCapacities) | 查询某个网络的能力集。 | 
| [OH_NetConn_GetDefaultHttpProxy](_net_connection.md#oh_netconn_getdefaulthttpproxy) ([NetConn_HttpProxy](_net_conn___http_proxy.md) \*httpProxy) | 查询默认的网络代理。 | 
| [OH_NetConn_GetAddrInfo](_net_connection.md#oh_netconn_getaddrinfo) (char \*host, char \*serv, struct addrinfo \*hint, struct addrinfo \*\*res, int32_t netId) | 通过netId获取DNS结果。 | 
| [OH_NetConn_FreeDnsResult](_net_connection.md#oh_netconn_freednsresult) (struct addrinfo \*res) | 释放DNS结果。 | 
| [OH_NetConn_GetAllNets](_net_connection.md#oh_netconn_getallnets) ([NetConn_NetHandleList](_net_conn___net_handle_list.md) \*netHandleList) | 查询所有激活的数据网络。 | 
| [OHOS_NetConn_RegisterDnsResolver](_net_connection.md#ohos_netconn_registerdnsresolver-deprecated) ([OH_NetConn_CustomDnsResolver](_net_connection.md#oh_netconn_customdnsresolver) resolver) | 注册自定义 DNS 解析器。<br/>**弃用：** 从API version 13开始废弃。<br/>**替代：** 推荐使用OH_NetConn_RegisterDnsResolver。|
| [OHOS_NetConn_UnregisterDnsResolver](_net_connection.md#ohos_netconn_unregisterdnsresolver-deprecated) (void) | 取消注册自定义 DNS 解析器。<br/>**弃用：** 从API version 13开始废弃。<br/>**替代：** 推荐使用OH_NetConn_UnregisterDnsResolver。|
| [OH_NetConn_RegisterDnsResolver](_net_connection.md#oh_netconn_registerdnsresolver) ([OH_NetConn_CustomDnsResolver](_net_connection.md#oh_netconn_customdnsresolver) resolver) | 注册自定义 DNS 解析器。 |
| [OH_NetConn_UnregisterDnsResolver](_net_connection.md#oh_netconn_unregisterdnsresolver) (void) | 取消注册自定义 DNS 解析器。 |
