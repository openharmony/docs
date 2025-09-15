# net_connection.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## Overview

Provides the C APIs of the network connection module for network management.

**File to include**: <network/netmanager/net_connection.h>

**Library**: libnet_connection.so

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Related module**: [NetConnection](capi-netconnection.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_NetConn_HasDefaultNet(int32_t *hasDefaultNet)](#oh_netconn_hasdefaultnet) | Checks whether a default activated data network is available.|
| [int32_t OH_NetConn_GetDefaultNet(NetConn_NetHandle *netHandle)](#oh_netconn_getdefaultnet) | Obtains the default activated data network.|
| [int32_t OH_NetConn_IsDefaultNetMetered(int32_t *isMetered)](#oh_netconn_isdefaultnetmetered) | Checks whether data traffic usage on the current network is metered.|
| [int32_t OH_NetConn_GetConnectionProperties(NetConn_NetHandle *netHandle, NetConn_ConnectionProperties *prop)](#oh_netconn_getconnectionproperties) | Obtains the link information of a data network.|
| [int32_t OH_NetConn_GetNetCapabilities(NetConn_NetHandle *netHandle, NetConn_NetCapabilities *netCapabilities)](#oh_netconn_getnetcapabilities) | Obtains the capabilities of a data network.|
| [int32_t OH_NetConn_GetDefaultHttpProxy(NetConn_HttpProxy *httpProxy)](#oh_netconn_getdefaulthttpproxy) | Obtains the default network proxy.|
| [int32_t OH_NetConn_GetAddrInfo(char *host, char *serv, struct addrinfo *hint, struct addrinfo **res, int32_t netId)](#oh_netconn_getaddrinfo) | Obtains the DNS result based on the specified **netId**.|
| [int32_t OH_NetConn_FreeDnsResult(struct addrinfo *res)](#oh_netconn_freednsresult) | Releases the DNS query result.|
| [int32_t OH_NetConn_GetAllNets(NetConn_NetHandleList *netHandleList)](#oh_netconn_getallnets) | Obtains all activated data networks.|
| [int32_t OHOS_NetConn_RegisterDnsResolver(OH_NetConn_CustomDnsResolver resolver)](#ohos_netconn_registerdnsresolver) | Registers a custom DNS resolver.|
| [int32_t OHOS_NetConn_UnregisterDnsResolver(void)](#ohos_netconn_unregisterdnsresolver) | Unregisters a custom DNS resolver.|
| [int32_t OH_NetConn_RegisterDnsResolver(OH_NetConn_CustomDnsResolver resolver)](#oh_netconn_registerdnsresolver) | Registers a custom DNS resolver.|
| [int32_t OH_NetConn_UnregisterDnsResolver(void)](#oh_netconn_unregisterdnsresolver) | Unregisters a custom DNS resolver.|
| [int32_t OH_NetConn_BindSocket(int32_t socketFd, NetConn_NetHandle *netHandle)](#oh_netconn_bindsocket) | Binds a socket to the specified network.|
| [int32_t OH_NetConn_SetAppHttpProxy(NetConn_HttpProxy *httpProxy)](#oh_netconn_setapphttpproxy) | Sets an HTTP proxy for the current application.|
| [int32_t OH_NetConn_RegisterAppHttpProxyCallback(OH_NetConn_AppHttpProxyChange appHttpProxyChange, uint32_t *callbackId)](#oh_netconn_registerapphttpproxycallback) | Registers a callback for application-level HTTP proxy changes.|
| [void OH_NetConn_UnregisterAppHttpProxyCallback(uint32_t callbackId)](#oh_netconn_unregisterapphttpproxycallback) | Unregisters the callback for HTTP proxy changes of the application.|
| [int32_t OH_NetConn_RegisterNetConnCallback(NetConn_NetSpecifier *specifier, NetConn_NetConnCallback *netConnCallback,uint32_t timeout, uint32_t *callbackId)](#oh_netconn_registernetconncallback) | Registers a callback for network status changes.|
| [int32_t OH_NetConn_RegisterDefaultNetConnCallback(NetConn_NetConnCallback *netConnCallback, uint32_t *callbackId)](#oh_netconn_registerdefaultnetconncallback) | Registers a callback for status changes of the default network.|
| [int32_t OH_NetConn_UnregisterNetConnCallback(uint32_t callBackId)](#oh_netconn_unregisternetconncallback) | Unregisters the callback for network status changes.|
| [NetConn_ErrorCode OH_NetConn_SetPacUrl(const char *pacUrl)](#oh_netconn_setpacurl) | Sets the URL of the system-level proxy auto-config (PAC) script.|
| [NetConn_ErrorCode OH_NetConn_GetPacUrl(char *pacUrl)](#oh_netconn_getpacurl) | Obtains the URL of the system-level PAC script.|
| [int32_t OH_NetConn_QueryProbeResult(char *destination, int32_t duration, NetConn_ProbeResultInfo *probeResultInfo)](#oh_netconn_queryproberesult) | Queries network probe results.|
| [int32_t OH_NetConn_QueryTraceRoute(char *destination, NetConn_TraceRouteOption *option,NetConn_TraceRouteInfo *traceRouteInfo)](#oh_netconn_querytraceroute) | Queries network trace route information.|


## Function Description

### OH_NetConn_HasDefaultNet()

```
int32_t OH_NetConn_HasDefaultNet(int32_t *hasDefaultNet)
```

**Description**

Checks whether a default activated data network is available.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| int32_t *hasDefaultNet | Whether there is a default network.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_GetDefaultNet()

```
int32_t OH_NetConn_GetDefaultNet(NetConn_NetHandle *netHandle)
```

**Description**

Obtains the default activated data network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Network ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_IsDefaultNetMetered()

```
int32_t OH_NetConn_IsDefaultNetMetered(int32_t *isMetered)
```

**Description**

Checks whether metering is enabled for the default data network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| int32_t *isMetered | Whether metering is enabled.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_GetConnectionProperties()

```
int32_t OH_NetConn_GetConnectionProperties(NetConn_NetHandle *netHandle, NetConn_ConnectionProperties *prop)
```

**Description**

Obtains the link information of a data network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Network ID.|
| [NetConn_ConnectionProperties](capi-netconnection-netconn-connectionproperties.md) *prop | Link information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_GetNetCapabilities()

```
int32_t OH_NetConn_GetNetCapabilities(NetConn_NetHandle *netHandle, NetConn_NetCapabilities *netCapabilities)
```

**Description**

Obtains the capabilities of a data network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 11


**Parameters**

| Name                                                                    | Description|
|-------------------------------------------------------------------------| -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Network ID.|
| [NetConn_NetCapabilities](capi-netconnection-netconn-netcapabilities.md) *netCapabilities                            | Capability set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_GetDefaultHttpProxy()

```
int32_t OH_NetConn_GetDefaultHttpProxy(NetConn_HttpProxy *httpProxy)
```

**Description**

Obtains the default network proxy.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_HttpProxy](capi-netconnection-netconn-httpproxy.md) *httpProxy | Proxy configuration.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_GetAddrInfo()

```
int32_t OH_NetConn_GetAddrInfo(char *host, char *serv, struct addrinfo *hint, struct addrinfo **res, int32_t netId)
```

**Description**

Obtains the DNS result based on the specified **netId**.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permission**: ohos.permission.INTERNET

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| char *host | Host name.|
| char *serv | Service name.|
| struct addrinfo *hint | Pointer to the addrinfo structure.|
| struct addrinfo **res | DNS query result, which is in the format of linked lists.|
| int32_t netId | If **netId** is set to **0**, the default **netid** is used for query.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_FreeDnsResult()

```
int32_t OH_NetConn_FreeDnsResult(struct addrinfo *res)
```

**Description**

Releases the DNS query result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permission**: ohos.permission.INTERNET

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| struct addrinfo *res | Header of the DNS query result, which is in the format of linked lists.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_GetAllNets()

```
int32_t OH_NetConn_GetAllNets(NetConn_NetHandleList *netHandleList)
```

**Description**

Obtains all activated data networks.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_NetHandleList](capi-netconnection-netconn-nethandlelist.md) *netHandleList | Network information list.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OHOS_NetConn_RegisterDnsResolver()

```
int32_t OHOS_NetConn_RegisterDnsResolver(OH_NetConn_CustomDnsResolver resolver)
```

**Description**

Registers a custom DNS resolver.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permission**: ohos.permission.INTERNET

**Since**: 11

**Deprecated from**: 13

**Substitute**: OH_NetConn_RegisterDnsResolver


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NetConn_CustomDnsResolver](capi-net-connection-type-h.md#oh_netconn_customdnsresolver) resolver | Pointer to the custom DNS resolver.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OHOS_NetConn_UnregisterDnsResolver()

```
int32_t OHOS_NetConn_UnregisterDnsResolver(void)
```

**Description**

Unregisters a custom DNS resolver.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permission**: ohos.permission.INTERNET

**Since**: 11

**Deprecated from**: 13

**Substitute**: OH_NetConn_UnregisterDnsResolver

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_RegisterDnsResolver()

```
int32_t OH_NetConn_RegisterDnsResolver(OH_NetConn_CustomDnsResolver resolver)
```

**Description**

Registers a custom DNS resolver.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permission**: ohos.permission.INTERNET

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| Pointer to the custom DNS resolver.|  |

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         **NETMANAGER_EXT_SUCCESS**: Operation success.<br>         **NETMANAGER_ERR_PERMISSION_DENIED**: Permission denied.<br>         **NETMANAGER_ERR_PARAMETER_ERROR**: Parameter error. Enter a correct parameter.|

### OH_NetConn_UnregisterDnsResolver()

```
int32_t OH_NetConn_UnregisterDnsResolver(void)
```

**Description**

Unregisters a custom DNS resolver.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permission**: ohos.permission.INTERNET

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success. **201**: Missing permissions.<br>         **401**: Parameter error. **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_BindSocket()

```
int32_t OH_NetConn_BindSocket(int32_t socketFd, NetConn_NetHandle *netHandle)
```

**Description**

Binds a socket to the specified network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t socketFd | Socket constructed by the user.|
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | Pointer to the network handle containing the network ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **401**: Parameter error.<br>         **2100002**: Service connection failure.<br>         **2100003**: Internal error.|

### OH_NetConn_SetAppHttpProxy()

```
int32_t OH_NetConn_SetAppHttpProxy(NetConn_HttpProxy *httpProxy)
```

**Description**

Sets an HTTP proxy for the current application.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [NetConn_HttpProxy](capi-netconnection-netconn-httpproxy.md) *httpProxy | HTTP proxy to set.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **401**: Parameter error.|

### OH_NetConn_RegisterAppHttpProxyCallback()

```
int32_t OH_NetConn_RegisterAppHttpProxyCallback(OH_NetConn_AppHttpProxyChange appHttpProxyChange, uint32_t *callbackId)
```

**Description**

Registers a callback for HTTP proxy changes of the application.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NetConn_AppHttpProxyChange](capi-net-connection-type-h.md#oh_netconn_apphttpproxychange) appHttpProxyChange | Callback to register.|
| uint32_t *callbackId | ID of the registered callback.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **401**: Parameter error.|

### OH_NetConn_UnregisterAppHttpProxyCallback()

```
void OH_NetConn_UnregisterAppHttpProxyCallback(uint32_t callbackId)
```

**Description**

Unregisters the callback for HTTP proxy changes of the application.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| uint32_t callbackId | ID of the callback to unregister.|

### OH_NetConn_RegisterNetConnCallback()

```
int32_t OH_NetConn_RegisterNetConnCallback(NetConn_NetSpecifier *specifier, NetConn_NetConnCallback *netConnCallback,uint32_t timeout, uint32_t *callbackId)
```

**Description**

Registers a callback for network status changes.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| netSpecifier | Network feature set.|
| callback | Registered callbacks.|
| uint32_t timeout | Timeout duration, in milliseconds. The value **0** indicates infinite waiting.|
| uint32_t *callbackId | Callback IDs.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **201**: Missing permissions.<br>         **401**: Parameter error.<br>         **2100002**: Service connection failure.<br>         **2100003**: Internal error.<br>         **2101008**: Callback already registered.<br>         **2101022**: Maximum number of requests exceeded.|

### OH_NetConn_RegisterDefaultNetConnCallback()

```
int32_t OH_NetConn_RegisterDefaultNetConnCallback(NetConn_NetConnCallback *netConnCallback, uint32_t *callbackId)
```

**Description**

Registers a callback for status changes of the default network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| callback | Registered callbacks.|
| uint32_t *callbackId | Callback IDs.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **201**: Missing permissions.<br>         **401**: Parameter error.<br>         **2100002**: Service connection failure.<br>         **2100003**: Internal error.<br>         **2101008**: Callback already registered.<br>         **2101022**: Maximum number of requests exceeded.|

### OH_NetConn_UnregisterNetConnCallback()

```
int32_t OH_NetConn_UnregisterNetConnCallback(uint32_t callBackId)
```

**Description**

Unregisters the callback for network status changes.

**System capability**: SystemCapability.Communication.NetManager.Core

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| uint32_t callBackId | ID of the callback to unregister.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **201**: Missing permissions.<br>         **401**: Parameter error.<br>         **2100002**: Service connection failure.<br>         **2100003**: Internal error.<br>         **2101007**: Callback not exist.|

### OH_NetConn_SetPacUrl()

```
NetConn_ErrorCode OH_NetConn_SetPacUrl(const char *pacUrl)
```

**Description**

Sets the URL of the system-level proxy auto-config (PAC) script.

**Required permissions**: ohos.permission.SET_PAC_URL

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| const char *pacUrl | Address of the PAC script.|

**Returns**

| Type| Description|
| -- | -- |
| [NetConn_ErrorCode](capi-net-connection-type-h.md#netconn_errorcode) | Result code defined in [NetConn_ErrorCode](capi-net-connection-type-h.md#netconn_errorcode).<br>         [NETCONN_SUCCESS](capi-net-connection-type-h.md#netconn_errorcode): success.<br>         [NETCONN_PERMISSION_DENIED](capi-net-connection-type-h.md#netconn_errorcode): permission denied.<br>         [NETCONN_PARAMETER_ERROR](capi-net-connection-type-h.md#netconn_errorcode): parameter error.<br>         [NETCONN_OPERATION_FAILED](capi-net-connection-type-h.md#netconn_errorcode): unable to connect to the service.<br>         [NETCONN_INTERNAL_ERROR](capi-net-connection-type-h.md#netconn_errorcode): internal error.|

### OH_NetConn_GetPacUrl()

```
NetConn_ErrorCode OH_NetConn_GetPacUrl(char *pacUrl)
```

**Description**

Obtains the URL of the system-level PAC script.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| char *pacUrl | URL of the PAC script.|

**Returns**

| Type| Description|
| -- | -- |
| [NetConn_ErrorCode](capi-net-connection-type-h.md#netconn_errorcode) | Result code defined in [NetConn_ErrorCode](capi-net-connection-type-h.md#netconn_errorcode).<br>         [NETCONN_SUCCESS](capi-net-connection-type-h.md#netconn_errorcode): success.<br>         [NETCONN_PARAMETER_ERROR](capi-net-connection-type-h.md#netconn_errorcode): parameter error.<br>         [NETCONN_OPERATION_FAILED](capi-net-connection-type-h.md#netconn_errorcode): unable to connect to the service.<br>         [NETCONN_INTERNAL_ERROR](capi-net-connection-type-h.md#netconn_errorcode): internal error.|

### OH_NetConn_QueryProbeResult()

```
int32_t OH_NetConn_QueryProbeResult(char *destination, int32_t duration, NetConn_ProbeResultInfo *probeResultInfo)
```

**Description**

Queries network probe results.

**Required permission**: ohos.permission.INTERNET

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| char *destination | Destination address.|
| int32_t duration | Probe duration. in seconds.|
| [NetConn_ProbeResultInfo](capi-netconnection-netconn-proberesultinfo.md) *probeResultInfo | Packet loss rate and round-trip time (RTT).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **201**: Missing permissions.<br>         **401**: Parameter error.<br>         **2100003**: Internal error.|

### OH_NetConn_QueryTraceRoute()

```
int32_t OH_NetConn_QueryTraceRoute(char *destination, NetConn_TraceRouteOption *option,NetConn_TraceRouteInfo *traceRouteInfo)
```

**Description**

Queries network trace route information.

**Required permissions**: ohos.permission.INTERNET, ohos.permission.LOCATION, and ohos.permission.ACCESS_NET_TRACE_INFO

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| char *destination | Destination address.|
| [NetConn_TraceRouteOption](capi-netconnection-netconn-tracerouteoption.md) *option | Route options.|
| [NetConn_TraceRouteInfo](capi-netconnection-netconn-tracerouteinfo.md) *traceRouteInfo | Route result. An array pointer needs to be passed. The array size indicates the number of route hops, which is **30** by default.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0**: Success.<br>         **201**: Missing permissions.|
