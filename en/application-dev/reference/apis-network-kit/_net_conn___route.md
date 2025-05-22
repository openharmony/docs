# NetConn_Route


## Overview

Defines the route configuration.

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)

**Header file**: [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## Summary


### Member Variables

| Name| Use guide| 
| -------- | -------- |
| [iface](#iface) [NETCONN_MAX_STR_LEN] | Network interface.| 
| [destination](#destination) | Destination address.| 
| [gateway](#gateway) | Gateway address.| 
| [hasGateway](#hasgateway) | Whether a gateway exists.| 
| [isDefaultRoute](#isdefaultroute) | Whether the default route is used. | 


## Member Variable Description


### destination

```
NetConn_NetAddr NetConn_Route::destination
```

**Description**

Destination address.


### gateway

```
NetConn_NetAddr NetConn_Route::gateway
```

**Description**

Gateway address.


### hasGateway

```
int32_t NetConn_Route::hasGateway
```

**Description**

Whether a gateway exists.


### iface

```
char NetConn_Route::iface[NETCONN_MAX_STR_LEN]
```

**Description**

Network interface.


### isDefaultRoute

```
int32_t NetConn_Route::isDefaultRoute
```

**Description**

Whether the default route is used. 
