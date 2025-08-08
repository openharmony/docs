# NetConn_NetCapabilities

## Overview

Defines network capability sets.

**Since**: 11

**Related module**: [NetConnection](capi-netconnection.md)

**Header file**: [net_connection_type.h](capi-net-connection-type-h.md)

## Summary

### Member Variables

| Name                                                                                                                  | Description|
|------------------------------------------------------------------------------------------------------------------------| -- |
| uint32_t linkUpBandwidthKbps                                                                                           | Uplink bandwidth.|
| uint32_t linkDownBandwidthKbps                                                                                         | Downlink bandwidth.|
| [NetConn_NetCap](capi-net-connection-type-h.md#netconn_netcap) netCaps[NETCONN_MAX_CAP_SIZE]                           | Network capability list.|
| int32_t netCapsSize                                                                                                    | Actual size of the network capability list.|
| [NetConn_NetBearerType](capi-net-connection-type-h.md#netconn_netbearertype) bearerTypes[NETCONN_MAX_BEARER_TYPE_SIZE] | Bearer type list.|
| int32_t bearerTypesSize                                                                                                | Actual size of the bearer type list.|
