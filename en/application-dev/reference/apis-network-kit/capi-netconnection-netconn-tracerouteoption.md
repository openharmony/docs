# NetConn_TraceRouteOption

## Overview

Defines the network trace route options.

**Since**: 20

**Related module**: [NetConnection](capi-netconnection.md)

**Header file**: [net_connection_type.h](capi-net-connection-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t maxJumpNumber | Maximum number of hops in the probe result. The value must be the same as that of **TraceRouteInfo**. The maximum number of hops is 30, which is also the default value.|
| NetConn_PacketsType packetsType | Protocol type of the probe packet. The default value is **NETCONN_PACKETS_ICMP**.|
