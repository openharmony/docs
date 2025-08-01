# NetConn_ConnectionProperties

## 概述

网络连接信息。

**起始版本：** 11

**相关模块：** [NetConnection](capi-netconnection.md)

**所在头文件：** [net_connection_type.h](capi-net-connection-type-h.md)

## 汇总

### 成员变量

| 名称                                                                                        | 描述                 |
|---------------------------------------------------------------------------------------------| -------------------- |
| char ifaceName[NETCONN_MAX_STR_LEN]                                                         | 网络接口的名称。     |
| char domain[NETCONN_MAX_STR_LEN]                                                            | 网络连接的域名信息。 |
| char tcpBufferSizes[NETCONN_MAX_STR_LEN]                                                    | TCP缓冲区大小。      |
| uint16_t mtu                                                                                | MTU。                |
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) netAddrList[NETCONN_MAX_ADDR_SIZE] | 地址列表。           |
| int32_t netAddrListSize                                                                     | 地址列表的实际size。 |
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) dnsList[NETCONN_MAX_ADDR_SIZE]     | DNS列表。            |
| int32_t dnsListSize                                                                         | DNS列表的实际size。  |
| [NetConn_Route](capi-netconnection-netconn-route.md) routeList[NETCONN_MAX_ROUTE_SIZE]      | 路由列表。           |
| int32_t routeListSize                                                                       | 路由列表的实际大小。 |
| [NetConn_HttpProxy](capi-netconnection-netconn-httpproxy.md) httpProxy                      | HTTP代理信息。       |


