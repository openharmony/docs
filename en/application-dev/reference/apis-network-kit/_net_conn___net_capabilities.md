# NetConn_NetCapabilities


## Overview

Defines network capability sets.

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)

**Header file**: [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## Summary


### Member Variables

| Name| Use guide| 
| -------- | -------- |
| [linkUpBandwidthKbps](#linkupbandwidthkbps) | Uplink bandwidth.| 
| [linkDownBandwidthKbps](#linkdownbandwidthkbps) | Downlink bandwidth.| 
| [netCaps](#netcaps) [NETCONN_MAX_CAP_SIZE] | Network capability list.| 
| [netCapsSize](#netcapssize) | Actual size of the network capability list.| 
| [bearerTypes](#bearertypes) [NETCONN_MAX_BEARER_TYPE_SIZE] | Bearer type list.| 
| [bearerTypesSize](#bearertypessize) | Actual size of the bearer type list.| 


## Member Variable Description


### bearerTypes

```
NetConn_NetBearerType NetConn_NetCapabilities::bearerTypes[NETCONN_MAX_BEARER_TYPE_SIZE]
```

**Description**

Bearer type list.


### bearerTypesSize

```
int32_t NetConn_NetCapabilities::bearerTypesSize
```

**Description**

Actual size of the bearer type list.


### linkDownBandwidthKbps

```
uint32_t NetConn_NetCapabilities::linkDownBandwidthKbps
```

**Description**

Downlink bandwidth.


### linkUpBandwidthKbps

```
uint32_t NetConn_NetCapabilities::linkUpBandwidthKbps
```

**Description**

Uplink bandwidth.


### netCaps

```
NetConn_NetCap NetConn_NetCapabilities::netCaps[NETCONN_MAX_CAP_SIZE]
```

**Description**

Network capability list.


### netCapsSize

```
int32_t NetConn_NetCapabilities::netCapsSize
```

**Description**

Actual size of the network capability list.
