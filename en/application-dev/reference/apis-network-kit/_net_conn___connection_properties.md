# NetConn_ConnectionProperties


## Overview

Defines the network connection information.

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)

**Header file**: [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## Summary


### Member Variables

| Name| Use guide| 
| -------- | -------- |
| [ifaceName](#ifacename) [NETCONN_MAX_STR_LEN] | Network interface name.| 
| [domain](#domain) [NETCONN_MAX_STR_LEN] | Domain name of the network connection.| 
| [tcpBufferSizes](#tcpbuffersizes) [NETCONN_MAX_STR_LEN] | TCP buffer size.| 
| [mtu](#mtu) | Maximum transmission unit.| 
| [netAddrList](#netaddrlist) [NETCONN_MAX_ADDR_SIZE] | Address list.| 
| [netAddrListSize](#netaddrlistsize) | Actual size of the address list.| 
| [dnsList](#dnslist) [NETCONN_MAX_ADDR_SIZE] | DNS list.| 
| [dnsListSize](#dnslistsize) | Actual size of the DNS list.| 
| [routeList](#routelist) [NETCONN_MAX_ROUTE_SIZE] | Route list.| 
| [routeListSize](#routelistsize) | Actual size of the route list.| 
| [httpProxy](#httpproxy) | HTTP proxy information.| 


## Member Variable Description


### dnsList

```
NetConn_NetAddr NetConn_ConnectionProperties::dnsList[NETCONN_MAX_ADDR_SIZE]
```

**Description**

DNS list.


### dnsListSize

```
int32_t NetConn_ConnectionProperties::dnsListSize
```

**Description**

Actual size of the DNS list.


### domain

```
char NetConn_ConnectionProperties::domain[NETCONN_MAX_STR_LEN]
```

**Description**

Domain name of the network connection.


### httpProxy

```
NetConn_HttpProxy NetConn_ConnectionProperties::httpProxy
```

**Description**

HTTP proxy information.


### ifaceName

```
char NetConn_ConnectionProperties::ifaceName[NETCONN_MAX_STR_LEN]
```

**Description**

Network interface name.


### mtu

```
uint16_t NetConn_ConnectionProperties::mtu
```

**Description**

Maximum transmission unit.


### netAddrList

```
NetConn_NetAddr NetConn_ConnectionProperties::netAddrList[NETCONN_MAX_ADDR_SIZE]
```

**Description**

Address list.


### netAddrListSize

```
int32_t NetConn_ConnectionProperties::netAddrListSize
```

**Description**

Actual size of the address list.


### routeList

```
NetConn_Route NetConn_ConnectionProperties::routeList[NETCONN_MAX_ROUTE_SIZE]
```

**Description**

Route list.


### routeListSize

```
int32_t NetConn_ConnectionProperties::routeListSize
```

**Description**

Actual size of the route list.


### tcpBufferSizes

```
char NetConn_ConnectionProperties::tcpBufferSizes[NETCONN_MAX_STR_LEN]
```

**Description**

TCP buffer size.
