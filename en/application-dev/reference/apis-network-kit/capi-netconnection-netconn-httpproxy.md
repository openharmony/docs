# NetConn_HttpProxy

## Overview

Defines the proxy configuration.

**Since**: 11

**Related module**: [NetConnection](capi-netconnection.md)

**Header file**: [net_connection_type.h](capi-net-connection-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char host[[NETCONN_MAX_STR_LEN]](capi-net-connection-type-h.md#macros) | Host name.|
| char exclusionList[[NETCONN_MAX_EXCLUSION_SIZE]](capi-net-connection-type-h.md#macros) [[NETCONN_MAX_STR_LEN]](capi-net-connection-type-h.md#macros)| Exclusion list of proxy servers.|
| int32_t exclusionListSize | Actual size of the exclusion list.|
| uint16_t port | Port number.|
