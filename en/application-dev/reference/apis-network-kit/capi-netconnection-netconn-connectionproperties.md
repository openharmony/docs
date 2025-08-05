# NetConn_ConnectionProperties

## Overview

Defines the network connection properties.

**Since**: 11

**Related module**: [NetConnection](capi-netconnection.md)

**Header file**: [net_connection_type.h](capi-net-connection-type-h.md)

## Summary

### Member Variables

| Name                                                                                       | Description                |
|---------------------------------------------------------------------------------------------| -------------------- |
| char ifaceName[NETCONN_MAX_STR_LEN]                                                         | Network interface name.    |
| char domain[NETCONN_MAX_STR_LEN]                                                            | Domain name of the network connection.|
| char tcpBufferSizes[NETCONN_MAX_STR_LEN]                                                    | TCP buffer size.     |
| uint16_t mtu                                                                                | Maximum transmission unit.               |
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) netAddrList[NETCONN_MAX_ADDR_SIZE] | Address list.          |
| int32_t netAddrListSize                                                                     | Actual size of the address list.|
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) dnsList[NETCONN_MAX_ADDR_SIZE]     | DNS list.           |
| int32_t dnsListSize                                                                         | Actual size of the DNS list. |
| [NetConn_Route](capi-netconnection-netconn-route.md) routeList[NETCONN_MAX_ROUTE_SIZE]      | Route list.          |
| int32_t routeListSize                                                                       | Actual size of the route list.|
| [NetConn_HttpProxy](capi-netconnection-netconn-httpproxy.md) httpProxy                      | HTTP proxy information.      |
