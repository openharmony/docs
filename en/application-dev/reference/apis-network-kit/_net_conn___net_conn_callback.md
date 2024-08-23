# NetConn_NetConnCallback

## Overview

Network connection callbacks.

**Since**: 12

**Related module**: [NetConnection](_net_connection.md)


## Summary


### Member Variables

| Name| Description.| 
| -------- | -------- |
| [onNetworkAvailable](#onnetworkavailable) | Callback for network available. |
| [onNetCapabilitiesChange](#onnetcapabilitieschange) | Callback for network capabilities changed. |
| [onConnetionProperties](#onconnetionproperties) | Callback for network connection properties changed. |
| [onNetLost](#onnetlost) | Callback for network lost. |
| [onNetUnavailable](#onnetunavailable) | Callback for network unavailable, this function invoked while network can not be available in given timeout. |
| [onNetBlockStatusChange](#onnetblockstatuschange) | Callback for network blocked status changed. |

## Member Variable Description


### onNetworkAvailable

```
typedef void (*OH_NetConn_NetworkAvailable)(NetConn_NetHandle *netHandle)
```

**Description**

Callback for network available.

**Information**

After the callback ends, the memory of the parameters will be automatically released, and the parameter pointers should not be saved.

**Parameters**

| Name| Description| 
| -------- | -------- |
| netHandle | Network ID. |

### onNetCapabilitiesChange

```
typedef void (*OH_NetConn_NetCapabilitiesChange)(NetConn_NetHandle *netHandle, NetConn_NetCapabilities *netCapabilities)
```

**Description**

Callback for network capabilities changed.

**Information**

After the callback ends, the memory of the parameters will be automatically released, and the parameter pointers should not be saved.

**Parameters**

| Name| Description| 
| -------- | -------- |
| netHandle | Network ID. |
| netCapabilities | Network capabilities. |

### onConnetionProperties

```
typedef void (*OH_NetConn_NetConnectionPropertiesChange)(NetConn_NetHandle *netHandle, NetConn_ConnectionProperties *connConnetionProperties)
```

**Description**

Callback for network connection properties changed.

**Information**

After the callback ends, the memory of the parameters will be automatically released, and the parameter pointers should not be saved.

**Parameters**

| Name| Description| 
| -------- | -------- |
| netHandle | Network ID. |
| connConnetionProperties | Network connection properties. |

### onNetLost

```
typedef void (*OH_NetConn_NetLost)(NetConn_NetHandle *netHandle)
```

**Description**

Callback for network lost.

**Information**

After the callback ends, the memory of the parameters will be automatically released, and the parameter pointers should not be saved.

**Parameters**

| Name| Description| 
| -------- | -------- |
| netHandle | Network ID. |

### onNetUnavailable

```
typedef void (*OH_NetConn_NetUnavailable)(void)
```

**Description**

Callback for network unavailable, this function invoked while network can not be available in given timeout.

### onNetBlockStatusChange

```
typedef void (*OH_NetConn_NetBlockStatusChange)(NetConn_NetHandle *netHandle, bool blocked)
```

**Description**

Callback for network blocked status changed.

**Information**

After the callback ends, the memory of the parameters will be automatically released, and the parameter pointers should not be saved.

**Parameters**

| Name| Description| 
| -------- | -------- |
| netHandle | Network ID. |
| blocked | The flag used to indicate whether the network will be blocked. |
