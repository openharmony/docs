# NetConn_ConnectionProperties


## 概述

网络链接信息。

**起始版本：** 11

**相关模块：**[NetConnection](_net_connection.md)

**所在头文件：** [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ifaceName](#ifacename) [NETCONN_MAX_STR_LEN] | 网络接口的名称。 | 
| [domain](#domain) [NETCONN_MAX_STR_LEN] | 网络连接的域名信息。 | 
| [tcpBufferSizes](#tcpbuffersizes) [NETCONN_MAX_STR_LEN] | TCP 缓冲区大小。 | 
| [mtu](#mtu) | MTU。 | 
| [netAddrList](#netaddrlist) [NETCONN_MAX_ADDR_SIZE] | 地址列表。 | 
| [netAddrListSize](#netaddrlistsize) | 地址列表的实际size。 | 
| [dnsList](#dnslist) [NETCONN_MAX_ADDR_SIZE] | DNS 列表。 | 
| [dnsListSize](#dnslistsize) | DNS 列表的实际size。 | 
| [routeList](#routelist) [NETCONN_MAX_ROUTE_SIZE] | 路由列表。 | 
| [routeListSize](#routelistsize) | 路由列表的实际大小。 | 
| [httpProxy](#httpproxy) | HTTP 代理信息。 | 


## 结构体成员变量说明


### dnsList

```
NetConn_NetAddr NetConn_ConnectionProperties::dnsList[NETCONN_MAX_ADDR_SIZE]
```

**描述**

DNS 列表。


### dnsListSize

```
int32_t NetConn_ConnectionProperties::dnsListSize
```

**描述**

DNS 列表的实际size。


### domain

```
char NetConn_ConnectionProperties::domain[NETCONN_MAX_STR_LEN]
```

**描述**

网络连接的域名信息。


### httpProxy

```
NetConn_HttpProxy NetConn_ConnectionProperties::httpProxy
```

**描述**

HTTP 代理信息。


### ifaceName

```
char NetConn_ConnectionProperties::ifaceName[NETCONN_MAX_STR_LEN]
```

**描述**

网络接口的名称。


### mtu

```
uint16_t NetConn_ConnectionProperties::mtu
```

**描述**

MTU。


### netAddrList

```
NetConn_NetAddr NetConn_ConnectionProperties::netAddrList[NETCONN_MAX_ADDR_SIZE]
```

**描述**

地址列表。


### netAddrListSize

```
int32_t NetConn_ConnectionProperties::netAddrListSize
```

**描述**

地址列表的实际size。


### routeList

```
NetConn_Route NetConn_ConnectionProperties::routeList[NETCONN_MAX_ROUTE_SIZE]
```

**描述**

路由列表。


### routeListSize

```
int32_t NetConn_ConnectionProperties::routeListSize
```

**描述**

路由列表的实际大小。


### tcpBufferSizes

```
char NetConn_ConnectionProperties::tcpBufferSizes[NETCONN_MAX_STR_LEN]
```

**描述**

TCP 缓冲区大小。
