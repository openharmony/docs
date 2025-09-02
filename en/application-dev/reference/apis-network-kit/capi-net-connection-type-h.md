# net_connection_type.h

## Overview

Provides the C APIs of the network connection module for network management.

**File to include**: <network/netmanager/net_connection_type.h>

**Library**: libnet_connection.so

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Related module**: [NetConnection](capi-netconnection.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) | NetConn_NetHandle | Network ID.|
| [NetConn_NetCapabilities](capi-netconnection-netconn-netcapabilities.md) | NetConn_NetCapabilities | Network capability set.|
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) | NetConn_NetAddr | Network address.|
| [NetConn_Route](capi-netconnection-netconn-route.md) | NetConn_Route | Route configuration.|
| [NetConn_HttpProxy](capi-netconnection-netconn-httpproxy.md) | NetConn_HttpProxy | Proxy configuration.|
| [NetConn_ConnectionProperties](capi-netconnection-netconn-connectionproperties.md) | NetConn_ConnectionProperties | Network connection information.|
| [NetConn_NetHandleList](capi-netconnection-netconn-nethandlelist.md) | NetConn_NetHandleList | Network list.|
| [NetConn_NetSpecifier](capi-netconnection-netconn-netspecifier.md) | NetConn_NetSpecifier | Defines network feature sets.|
| [NetConn_NetConnCallback](capi-netconnection-netconn-netconncallback.md) | NetConn_NetConnCallback | Network status callback.|
| [NetConn_ProbeResultInfo](capi-netconnection-netconn-proberesultinfo.md) | NetConn_ProbeResultInfo | Defines the probe result.|
| [NetConn_TraceRouteOption](capi-netconnection-netconn-tracerouteoption.md) | NetConn_TraceRouteOption | Defines the network trace route options.|
| [NetConn_TraceRouteInfo](capi-netconnection-netconn-tracerouteinfo.md) | NetConn_TraceRouteInfo | Defines the trace route information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NetConn_NetCap](#netconn_netcap) | NetConn_NetCap | Network capability set.|
| [NetConn_NetBearerType](#netconn_netbearertype) | NetConn_NetBearerType | Network carrier type.|
| [NetConn_ErrorCode](#netconn_errorcode) | NetConn_ErrorCode | Network connection error code.|
| [NetConn_PacketsType](#netconn_packetstype) | NetConn_PacketsType | Trace route packet type.|


### Macros

| Name| Description| 
| -------- | -------- |
| **NETCONN_MAX_RTT_NUM** | 4 | 
| **NETCONN_MAX_NET_SIZE** | 32 | 
| **NETCONN_MAX_BEARER_TYPE_SIZE** | 32 | 
| **NETCONN_MAX_CAP_SIZE** | 32 | 
| **NETCONN_MAX_ADDR_SIZE** | 32 | 
| **NETCONN_MAX_ROUTE_SIZE** | 64 | 
| **NETCONN_MAX_EXCLUSION_SIZE** | 256 | 
| **NETCONN_MAX_STR_LEN** | 256 | 

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef int (\*OH_NetConn_CustomDnsResolver)(const char *host, const char *serv,const struct addrinfo *hint, struct addrinfo **res)](#oh_netconn_customdnsresolver) | OH_NetConn_CustomDnsResolver | Pointer to the custom DNS resolver.|
| [typedef void (\*OH_NetConn_AppHttpProxyChange)(NetConn_HttpProxy *proxy)](#oh_netconn_apphttpproxychange) | OH_NetConn_AppHttpProxyChange | Callback invoked when the HTTP proxy information of the application changes.|
| [typedef void (\*OH_NetConn_NetworkAvailable)(NetConn_NetHandle *netHandle)](#oh_netconn_networkavailable) | OH_NetConn_NetworkAvailable | Callback invoked when the network is available.|
| [typedef void (\*OH_NetConn_NetCapabilitiesChange)(NetConn_NetHandle *netHandle,NetConn_NetCapabilities *netCapabilities)](#oh_netconn_netcapabilitieschange) | OH_NetConn_NetCapabilitiesChange | Callback invoked when the network capabilities change.|
| [typedef void (\*OH_NetConn_NetConnectionPropertiesChange)(NetConn_NetHandle *netHandle,NetConn_ConnectionProperties *connConnetionProperties)](#oh_netconn_netconnectionpropertieschange) | OH_NetConn_NetConnectionPropertiesChange | Callback invoked when network connection properties change.|
| [typedef void (\*OH_NetConn_NetLost)(NetConn_NetHandle *netHandle)](#oh_netconn_netlost) | OH_NetConn_NetLost | Callback invoked when the network is disconnected.|
| [typedef void (\*OH_NetConn_NetUnavailable)(void)](#oh_netconn_netunavailable) | OH_NetConn_NetUnavailable | Callback invoked when the network is unavailable. This callback is triggered when the network is not activated within the specified timeout interval. If the timeout interval is not set, this callback is not triggered.|
| [typedef void (\*OH_NetConn_NetBlockStatusChange)(NetConn_NetHandle *netHandle, bool blocked)](#oh_netconn_netblockstatuschange) | OH_NetConn_NetBlockStatusChange | Callback invoked when the network blocking status changes.|

## Enum Description

### NetConn_NetCap

```
enum NetConn_NetCap
```

**Description**

Defines the network capability set.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| NETCONN_NET_CAPABILITY_MMS = 0 | MMS.|
| NETCONN_NET_CAPABILITY_NOT_METERED = 11 | Non-metered network.|
| NETCONN_NET_CAPABILITY_INTERNET = 12 | Internet.|
| NETCONN_NET_CAPABILITY_NOT_VPN = 15 | Non-VPN.|
| NETCONN_NET_CAPABILITY_VALIDATED = 16 | Verified.|
| NETCONN_NET_CAPABILITY_PORTAL = 17 | Portal.<br>**Since**: 12|
| NETCONN_NET_CAPABILITY_CHECKING_CONNECTIVITY = 31 | Connectivity check.<br>**Since**: 12|

### NetConn_NetBearerType

```
enum NetConn_NetBearerType
```

**Description**

Network carrier type.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| NETCONN_BEARER_CELLULAR = 0 | Cellular network.|
| NETCONN_BEARER_WIFI = 1 | Wi-Fi.|
| NETCONN_BEARER_BLUETOOTH = 2 | Bluetooth.<br>**Since**: 12|
| NETCONN_BEARER_ETHERNET = 3 | Ethernet.|
| NETCONN_BEARER_VPN = 4 | VPN.<br>**Since**: 12|

### NetConn_ErrorCode

```
enum NetConn_ErrorCode
```

**Description**

Enumerates network connection error codes.

**Since**: 15

| Enum Item| Description|
| -- | -- |
| NETCONN_SUCCESS = 0 | Success.|
| NETCONN_PERMISSION_DENIED = 201 | Missing permissions.|
| NETCONN_PARAMETER_ERROR = 401 | Invalid parameter.|
| NETCONN_OPERATION_FAILED = 2100002 | Service connection failure.|
| NETCONN_INTERNAL_ERROR = 2100003 | Internal error.1. Memory-related error, for example, insufficient memory, memory data copy failure, or memory request failure.2. Null pointer, for example, access to a released memory pointer.|

### NetConn_PacketsType

```
enum NetConn_PacketsType
```

**Description**

Enumerates trace route packet types.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| NETCONN_PACKETS_ICMP = 0 | Internet Control Message Protocol.|
| NETCONN_PACKETS_UDP = 1 | User Datagram Protocol.|


## Function Description

### OH_NetConn_CustomDnsResolver()

```
typedef int (*OH_NetConn_CustomDnsResolver)(const char *host, const char *serv,const struct addrinfo *hint, struct addrinfo **res)
```

**Description**

Pointer to the custom DNS resolver.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char *host | Host name.|
|  const char *serv | Service name.|
| const struct addrinfo *hint | Pointer to the addrinfo structure.|
|  struct addrinfo **res | DNS query result, which is in the format of linked lists.|

### OH_NetConn_AppHttpProxyChange()

```
typedef void (*OH_NetConn_AppHttpProxyChange)(NetConn_HttpProxy *proxy)
```

**Description**

Callback invoked when the HTTP proxy information of the application changes.

**Since**: 12


**Parameters**

| Name                         | Description|
|------------------------------| -- |
| [NetConn_HttpProxy](capi-netconnection-netconn-httpproxy.md) *proxy | Proxy configuration information (probably a null pointer).|

### OH_NetConn_NetworkAvailable()

```
typedef void (*OH_NetConn_NetworkAvailable)(NetConn_NetHandle *netHandle)
```

**Description**

Callback invoked when the network is available.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Network handle.|

### OH_NetConn_NetCapabilitiesChange()

```
typedef void (*OH_NetConn_NetCapabilitiesChange)(NetConn_NetHandle *netHandle,NetConn_NetCapabilities *netCapabilities)
```

**Description**

Callback invoked when the network capabilities change.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Network handle.|
| [NetConn_NetCapabilities](capi-netconnection-netconn-netcapabilities.md) *netCapabilities | Network capability set.|

### OH_NetConn_NetConnectionPropertiesChange()

```
typedef void (*OH_NetConn_NetConnectionPropertiesChange)(NetConn_NetHandle *netHandle,NetConn_ConnectionProperties *connConnetionProperties)
```

**Description**

Callback invoked when network connection properties change.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Network handle.|
| [NetConn_ConnectionProperties](capi-netconnection-netconn-connectionproperties.md) *connConnetionProperties | Network connection properties.|

### OH_NetConn_NetLost()

```
typedef void (*OH_NetConn_NetLost)(NetConn_NetHandle *netHandle)
```

**Description**

Callback invoked when the network is disconnected.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Network handle.|

### OH_NetConn_NetUnavailable()

```
typedef void (*OH_NetConn_NetUnavailable)(void)
```

**Description**

Callback invoked when the network is unavailable. This callback is triggered when the network is not activated within the specified timeout interval. If the timeout interval is not set, this callback is not triggered.

**Since**: 12

### OH_NetConn_NetBlockStatusChange()

```
typedef void (*OH_NetConn_NetBlockStatusChange)(NetConn_NetHandle *netHandle, bool blocked)
```

**Description**

Callback invoked when the network blocking status changes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Network handle.|
|  bool blocked | Whether the network is blocked.|
