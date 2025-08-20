# NetConn_Route

## Overview

Defines the route configuration.

**Since**: 11

**Related module**: [NetConnection](capi-netconnection.md)

**Header file**: [net_connection_type.h](capi-net-connection-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char iface[[NETCONN_MAX_STR_LEN]](capi-net-connection-type-h.md#macros)| Network interface.|
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) destination | Destination address.|
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) gateway | Gateway IP address.|
| int32_t hasGateway | Whether a gateway exists.|
| int32_t isDefaultRoute | Whether the default route is used. |
