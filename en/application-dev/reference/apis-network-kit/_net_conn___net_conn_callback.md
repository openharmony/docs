# NetConn_NetConnCallback

## Overview

Defines network status callbacks.

**Since**: 12

**Related module**: [NetConnection](_net_connection.md)

**Header file**: [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## Summary

### Member Variables

| Name| Description|
| -------- | -------- |
| [onNetworkAvailable](#onnetworkavailable) | Called when the network is available.|
| [onNetCapabilitiesChange](#onnetcapabilitieschange) | Called when the network capabilities change.|
| [onConnetionProperties](#onconnetionproperties) | Called when network connection properties change.|
| [onNetLost](#onnetlost) | Called when the network is disconnected.|
| [onNetUnavailable](#onnetunavailable) | Called when the network is unavailable. This callback is triggered when the network is not activated within the specified timeout interval. If the timeout interval is not set, this callback is not triggered.|


## Member Variable Description


### onNetworkAvailable

```
typedef void (*OH_NetConn_NetworkAvailable)(NetConn_NetHandle *netHandle)
```

**Description**

Called when the network is available.

**Note**

After the callback is complete, the parameter memory is automatically cleared and therefore the parameter pointer should be released.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| netHandle |[NetHandle](js-apis-net-connection.md#nethandle) | Network handle.|

### onNetCapabilitiesChange

```
typedef void (*OH_NetConn_NetCapabilitiesChange)(NetConn_NetHandle *netHandle, NetConn_NetCapabilities *netCapabilities)
```

**Description**

Called when the network capabilities change.

**Note**

After the callback is complete, the parameter memory is automatically cleared and therefore the parameter pointer should be released.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| netHandle | [NetHandle](js-apis-net-connection.md#nethandle) | Network handle.|
| netCapabilities | [NetCapabilities](js-apis-net-connection.md#netcapabilities)| Network capability set.|

### onConnetionProperties

```
typedef void (*OH_NetConn_NetConnectionPropertiesChange)(NetConn_NetHandle *netHandle, NetConn_ConnectionProperties *connConnetionProperties)
```

**Description**

Called when network connection properties change.

**Note**

After the callback is complete, the parameter memory is automatically cleared and therefore the parameter pointer should be released.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| netHandle |[NetHandle](js-apis-net-connection.md#nethandle) | Network handle.|
| connConnetionProperties | [ConnectionProperties](js-apis-net-connection.md#connectionproperties)| Network connection properties.|

### onNetLost

```
typedef void (*OH_NetConn_NetLost)(NetConn_NetHandle *netHandle)
```

**Description**

Called when the network is disconnected.

**Note**

After the callback is complete, the parameter memory is automatically cleared and therefore the parameter pointer should be released.

**Parameters**

| Name| Type| Description|
| -------- | -------- | -------- |
| netHandle |[NetHandle](js-apis-net-connection.md#nethandle)| Network handle.|

### onNetUnavailable

```
typedef void (*OH_NetConn_NetUnavailable)(void)
```

**Description**

Called when the network is unavailable. This callback is triggered when the network is not activated within the specified timeout interval. If the timeout interval is not set, this callback is not triggered.
