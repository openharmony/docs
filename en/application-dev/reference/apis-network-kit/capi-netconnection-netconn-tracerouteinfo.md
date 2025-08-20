# NetConn_TraceRouteInfo

## Overview

Defines the trace route information.

**Since**: 20

**Related Module**: [NetConnection](capi-netconnection.md)

**Header File**: [net_connection_type.h](capi-net-connection-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t jumpNo | Number of hops.|
| char address[[NETCONN_MAX_STR_LEN]](capi-net-connection-type-h.md#macros)| Host name or address.|
| uint32_t rtt[[NETCONN_MAX_RTT_NUM]](capi-net-connection-type-h.md#macros)| Round-trip time, in ms.|
