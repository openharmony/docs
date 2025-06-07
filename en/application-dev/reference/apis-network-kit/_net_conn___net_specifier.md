# NetConn_NetSpecifier

## Overview

Defines the network feature set, including a network capability set and a network ID.

**Since**: 12

**Related module**: [NetConnection](_net_connection.md)

**Header file**: [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [caps](#caps) | Network capability set.|
| [bearerPrivateIdentifier](#bearerprivateidentifier) | Network ID.|


## Member Variable Description


### caps

```
NetConn_NetCapabilities NetConn_NetSpecifier::caps
```

**Description**

Defines the network capability set.


### bearerPrivateIdentifier

```
char* NetConn_NetSpecifier::bearerPrivateIdentifier
```

**Description**

Defines the network ID.
