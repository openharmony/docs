# NetConnection


## Overview

Provides the C APIs of the network connection module for network management.

**Since**: 11


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [net_connection.h](net__connection_8h.md) | Provides the C APIs of the network connection module for network management.| 
| [net_connection_type.h](net__connection__type_8h.md) | Declares the structs for the C APIs of the network connection module.| 


### Structs

| Name| Description| 
| -------- | -------- |
| [NetConn_NetHandle](_net_conn___net_handle.md) | Network ID.| 
| [NetConn_NetCapabilities](_net_conn___net_capabilities.md) | Network capability set.| 
| [NetConn_NetAddr](_net_conn___net_addr.md) | Network address.| 
| [NetConn_Route](_net_conn___route.md) | Route configuration.| 
| [NetConn_HttpProxy](_net_conn___http_proxy.md) | Proxy configuration information.| 
| [NetConn_ConnectionProperties](_net_conn___connection_properties.md) | Network connection information.| 
| [NetConn_NetHandleList](_net_conn___net_handle_list.md) | Network list.| 
| [NetConn_NetConnCallback](_net_conn___net_conn_callback.md) | Network connection callbacks. |
| [NetConn_NetSpecifier](_net_conn___net_specifier.md) | Network specifier, including network capability sets and network identifier. |


### Macros

| Name| Description| 
| -------- | -------- |
| **NETCONN_MAX_NET_SIZE** | 32 | 
| **NETCONN_MAX_BEARER_TYPE_SIZE** | 32 | 
| **NETCONN_MAX_CAP_SIZE** | 32 | 
| **NETCONN_MAX_ADDR_SIZE** | 32 | 
| **NETCONN_MAX_ROUTE_SIZE** | 64 | 
| **NETCONN_MAX_EXCLUSION_SIZE** | 256 | 
| **NETCONN_MAX_STR_LEN** | 256 | 


### Types

| Name| Description| 
| -------- | -------- |
| [NetConn_NetCap](#netconn_netcap) | Network capability set.| 
| [NetConn_NetBearerType](#netconn_netbearertype) | Network carrier type.| 
| [NetConn_NetHandle](#netconn_nethandle) | Network ID.| 
| [NetConn_NetCapabilities](#netconn_netcapabilities) | Network capability set.| 
| [NetConn_NetAddr](#netconn_netaddr) | Network address.| 
| [NetConn_Route](#netconn_route) | Route configuration.| 
| [NetConn_HttpProxy](#netconn_httpproxy) | Proxy configuration information.| 
| [NetConn_ConnectionProperties](#netconn_connectionproperties) | Network connection information.| 
| [NetConn_NetHandleList](#netconn_nethandlelist) | Network list.| 
| (\*[OH_NetConn_CustomDnsResolver](#oh_netconn_customdnsresolver)) (const char \*host, const char \*serv, const struct addrinfo \*hint, struct addrinfo \*\*res) | Pointer to the custom DNS resolver.| 
| [NetConn_NetConnCallback](#netconn_netconncallback) | Network connection callbacks. |
| [NetConn_NetSpecifier](#netconn_netspecifier) | Network specifier, including network capability sets and network identifier. |


### Enums

| Name| Description| 
| -------- | -------- |
| [NetConn_NetCap](#netconn_netcap) {<br>NETCONN_NET_CAPABILITY_MMS = 0,<br>NETCONN_NET_CAPABILITY_NOT_METERED = 11,<br>NETCONN_NET_CAPABILITY_INTERNET = 12,<br>NETCONN_NET_CAPABILITY_NOT_VPN = 15,<br>NETCONN_NET_CAPABILITY_VALIDATED = 16<br>} | Network capability set.| 
| [NetConn_NetBearerType](#netconn_netbearertype) {<br>NETCONN_BEARER_CELLULAR = 0,<br>NETCONN_BEARER_WIFI = 1,<br>NETCONN_BEARER_ETHERNET = 3<br>NETCONN_BEARER_VPN = 4<br>} | Network carrier type.|


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_NetConn_HasDefaultNet](#oh_netconn_hasdefaultnet) (int32_t \*hasDefaultNet) | Checks whether a default activated data network is available.| 
| [OH_NetConn_GetDefaultNet](#oh_netconn_getdefaultnet) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle) | Obtains the default activated data network.| 
| [OH_NetConn_IsDefaultNetMetered](#oh_netconn_isdefaultnetmetered) (int32_t \*isMetered) | Checks whether data traffic usage on the current network is metered.| 
| [OH_NetConn_GetConnectionProperties](#oh_netconn_getconnectionproperties) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_ConnectionProperties](_net_conn___connection_properties.md) \*prop) | Obtains the link information of a data network.| 
| [OH_NetConn_GetNetCapabilities](#oh_netconn_getnetcapabilities) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_NetCapabilities](_net_conn___net_capabilities.md) \*netCapacities) | Obtains the capabilities of a data network.| 
| [OH_NetConn_GetDefaultHttpProxy](#oh_netconn_getdefaulthttpproxy) ([NetConn_HttpProxy](_net_conn___http_proxy.md) \*httpProxy) | Obtains the default network proxy.| 
| [OH_NetConn_GetAddrInfo](#oh_netconn_getaddrinfo) (char \*host, char \*serv, struct addrinfo \*hint, struct addrinfo \*\*res, int32_t netId) | Obtains the DNS result using **netId**.| 
| [OH_NetConn_FreeDnsResult](#oh_netconn_freednsresult) (struct addrinfo \*res) | Releases the DNS query result.| 
| [OH_NetConn_GetAllNets](#oh_netconn_getallnets) ([NetConn_NetHandleList](_net_conn___net_handle_list.md) \*netHandleList) | Obtains all activated data networks.| 
| [OHOS_NetConn_RegisterDnsResolver](#ohos_netconn_registerdnsresolver) ([OH_NetConn_CustomDnsResolver](#oh_netconn_customdnsresolver) resolver) | Registers a custom DNS resolver.| 
| [OHOS_NetConn_UnregisterDnsResolver](#ohos_netconn_unregisterdnsresolver) (void) | Unregisters a custom DNS resolver.| 
| [OH_NetConn_BindSocket](#oh_netconn_bindsocket) (int32_t socketFd, [NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle) | Binds a socket to the specified network.|
| [OH_NetConn_SetAppHttpProxy](#oh_netconn_setapphttpproxy) ([NetConn_HttpProxy](_net_conn___http_proxy.md) \*httpProxy) | Sets http proxy information to current application. |
| [OH_NetConn_RegisterAppHttpProxyCallback](#oh_netconn_registerapphttpproxycallback) ([OH_NetConn_AppHttpProxyChange](#oh_netconn_apphttpproxychange) appHttpProxyChange, uint32_t \*callbackId) | Registers callback to listen for changes to the application-level http proxy. |
| [OH_NetConn_UnregisterAppHttpProxyCallback](#oh_netconn_unregisterapphttpproxycallback) (uint32_t callbackId) | Unregisters a callback function that listens for application-level proxy changes. | 
| [OH_NetConn_RegisterNetConnCallback](#oh_netconn_registernetconncallback) ([NetConn_NetSpecifier](_net_conn___net_specifier.md) \*specifier, [NetConn_NetConnCallback](_net_conn___net_conn_callback.md) \*netConnCallback, uint32_t timeoutMS, uint32_t \*callbackId) | Registers callback, used to monitor specific network status. |
| [OH_NetConn_RegisterDefaultNetConnCallback](#oh_netconn_registerdefaultnetconncallback) ([NetConn_NetConnCallback](_net_conn___net_conn_callback.md) \*netConnCallback, uint32_t \*callbackId) | Registers a callback to listen default network's status changed. |
| [OH_NetConn_UnregisterNetConnCallback](#oh_netconn_unregisternetconncallback) (uint32_t callbackId) | Unregisters network status callback. |


## Type Description


### NetConn_ConnectionProperties

```
typedef struct NetConn_ConnectionProperties NetConn_ConnectionProperties
```

**Description**

Network connection information.

**Since**: 11


### NetConn_HttpProxy

```
typedef struct NetConn_HttpProxy NetConn_HttpProxy
```

**Description**

Proxy configuration information.

**Since**: 11


### NetConn_NetAddr

```
typedef struct NetConn_NetAddr NetConn_NetAddr
```

**Description**

Network address.

**Since**: 11


### NetConn_NetBearerType

```
typedef enum NetConn_NetBearerType NetConn_NetBearerType
```

**Description**

Network carrier type.

**Since**: 11


### NetConn_NetCap

```
typedef enum NetConn_NetCap NetConn_NetCap
```

**Description**

Network capability set.

**Since**: 11


### NetConn_NetCapabilities

```
typedef struct NetConn_NetCapabilities NetConn_NetCapabilities
```

**Description**

Network capability set.

**Since**: 11


### NetConn_NetHandle

```
typedef struct NetConn_NetHandle NetConn_NetHandle
```

**Description**

Network ID.

**Since**: 11


### NetConn_NetHandleList

```
typedef struct NetConn_NetHandleList NetConn_NetHandleList
```

**Description**

Network list.

**Since**: 11


### NetConn_Route

```
typedef struct NetConn_Route NetConn_Route
```

**Description**

Route configuration.

**Since**: 11


### OH_NetConn_CustomDnsResolver

```
typedef int(* OH_NetConn_CustomDnsResolver) (const char *host, const char *serv, const struct addrinfo *hint, struct addrinfo **res)
```

**Description**

Pointer to the custom DNS resolver.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| host | Host name.| 
| serv | Service name.| 
| hint | Pointer to the addrinfo structure.| 
| res | DNS query result, which is in the format of linked lists.| 


### OH_NetConn_AppHttpProxyChange

```
typedef void(* OH_NetConn_AppHttpProxyChange) (NetConn_HttpProxy *proxy)
```

**Description**

Callback for application’s http proxy information changed.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | The changed proxy information, may be a null pointer. | 


### NetConn_NetConnCallback

```
typedef struct NetConn_NetConnCallback NetConn_NetConnCallback
```

**Description**

Network connection callbacks.

**Since**: 12


### NetConn_NetSpecifier

```
typedef struct NetConn_NetSpecifier NetConn_NetSpecifier
```

**Description**

Network specifier, including network capability sets and network identifier.

**Since**: 12


## Enum Description


### NetConn_NetBearerType

```
enum NetConn_NetBearerType
```

**Description**

Network carrier type.

**Since**: 11

|         Value         |         Description           |
| ------------------------| ----------------------- |
| NETCONN_BEARER_CELLULAR | Cellular network.             |
| NETCONN_BEARER_WIFI     | Wi-Fi.                 |
| NETCONN_BEARER_BLUETOOTH     | Bluetooth. <br>**Since**: 12 |
| NETCONN_BEARER_ETHERNET | Ethernet.             |
| NETCONN_BEARER_VPN      | Virtual private network.<br>**Since**: 12|


### NetConn_NetCap

```
enum NetConn_NetCap
```

**Description**

Network capability set.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| NETCONN_NET_CAPABILITY_MMS | MMS.| 
| NETCONN_NET_CAPABILITY_NOT_METERED | Non-metered network.| 
| NETCONN_NET_CAPABILITY_INTERNET | Internet.| 
| NETCONN_NET_CAPABILITY_NOT_VPN | Non-VPN.| 
| NETCONN_NET_CAPABILITY_VALIDATED | Verified.| 
| NETCONN_NET_CAPABILITY_CHECKING_CONNECTIVITY  | Connectivity check.<br>**Since**: 12| 


## Function Description


### OH_NetConn_FreeDnsResult()

```
int32_t OH_NetConn_FreeDnsResult (struct addrinfo * res)
```

**Description**

Releases the DNS query result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| res | Header of the DNS query result, which is in the format of linked lists.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.INTERNET


### OH_NetConn_GetAddrInfo()

```
int32_t OH_NetConn_GetAddrInfo (char * host, char * serv, struct addrinfo * hint, struct addrinfo ** res, int32_t netId )
```

**Description**

Obtains the DNS result using **netId**.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| host | Host name.| 
| serv | Service name.| 
| hint | Pointer to the addrinfo structure.| 
| res | DNS query result, which is in the format of linked lists.| 
| netId | If **netId** is set to **0**, the default **netid** is used for query.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.INTERNET


### OH_NetConn_GetAllNets()

```
int32_t OH_NetConn_GetAllNets (NetConn_NetHandleList * netHandleList)
```

**Description**

Obtains all activated data networks.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| netHandleList | Network information list.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_GetConnectionProperties()

```
int32_t OH_NetConn_GetConnectionProperties (NetConn_NetHandle * netHandle, NetConn_ConnectionProperties * prop )
```

**Description**

Obtains the link information of a data network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| nethandle | Network ID.| 
| prop | Link information.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_GetDefaultHttpProxy()

```
int32_t OH_NetConn_GetDefaultHttpProxy (NetConn_HttpProxy * httpProxy)
```

**Description**

Obtains the default network proxy.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpProxy | Proxy configuration information.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.


### OH_NetConn_GetDefaultNet()

```
int32_t OH_NetConn_GetDefaultNet (NetConn_NetHandle * netHandle)
```

**Description**

Obtains the default activated data network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| netHandle | Network ID.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_GetNetCapabilities()

```
int32_t OH_NetConn_GetNetCapabilities (NetConn_NetHandle * netHandle, NetConn_NetCapabilities * netCapacities )
```

**Description**

Obtains the capabilities of a data network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| netHandle | Network ID.| 
| netCapacities | Capability set.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_HasDefaultNet()

```
int32_t OH_NetConn_HasDefaultNet (int32_t * hasDefaultNet)
```

**Description**

Checks whether a default activated data network is available.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| hasDefaultNet | Whether there is a default network.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_IsDefaultNetMetered()

```
int32_t OH_NetConn_IsDefaultNetMetered (int32_t * isMetered)
```

**Description**

Checks whether metering is enabled for the default data network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| isMetered | Whether metering is enabled.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.GET_NETWORK_INFO


### OHOS_NetConn_RegisterDnsResolver()

```
int32_t OHOS_NetConn_RegisterDnsResolver (OH_NetConn_CustomDnsResolver resolver)
```

**Description**

Registers a custom DNS resolver.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| resolver | Pointer to the custom DNS resolver.| 

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.INTERNET


### OHOS_NetConn_UnregisterDnsResolver()

```
int32_t OHOS_NetConn_UnregisterDnsResolver (void )
```

**Description**

Unregisters a custom DNS resolver.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**Required permissions**:

ohos.permission.INTERNET


### OH_NetConn_BindSocket()

```
int32_t OH_NetConn_BindSocket (int32_t socketFd, NetConn_NetHandle * netHandle)
```

**Description**

Binds a socket to the specified network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| socketFd | File descriptor of the socket created by the user.|
| netHandle | Network ID.|

**Returns**

**0**: success.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.


### OH_NetConn_SetAppHttpProxy()

```
int32_t OH_NetConn_SetAppHttpProxy(NetConn_HttpProxy *httpProxy)
```

**Description**

Sets http proxy information to current application.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| httpProxy | Information about the proxy that needs to be set. |

**Returns**

**0**: success.

**401**: parameter error.


### OH_NetConn_RegisterAppHttpProxyCallback()

```
int32_t OH_NetConn_RegisterAppHttpProxyCallback(OH_NetConn_AppHttpProxyChange appHttpProxyChange, uint32_t *callbackId)
```

**Description**

Registers callback to listen for changes to the application-level http proxy.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| appHttpProxyChange | Callback that need to be registered to listen for changes to the http proxy. |
| callbackId | Callback id returned after registration, associated with a registered callback. |

**Returns**

**0**: success.

**401**: parameter error.


### OH_NetConn_UnregisterAppHttpProxyCallback()

```
void OH_NetConn_UnregisterAppHttpProxyCallback(uint32_t callbackId)
```

**Description**

Unregisters a callback function that listens for application-level proxy changes.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| callbackId | Id of the callback function that needs to be deregistered. |


### OH_NetConn_RegisterNetConnCallback()

```
int32_t OH_NetConn_RegisterNetConnCallback(NetConn_NetSpecifier *specifier, NetConn_NetConnCallback *netConnCallback, uint32_t timeout, uint32_t *callbackId)
```

**Description**

Registers callback, used to monitor specific network status.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| specifier | Specifier information. |
| netConnCallback | The callback needed to be registered. |
| timeout | The timeout period in milliseconds, 0 indicates an infinite wait. |
| callbackId | callbackId out param, corresponding to a registered callback. |

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**2100008**: the callback already exists.

**2101022**: the number of requests exceeded the maximum allowed.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_RegisterDefaultNetConnCallback()

```
int32_t OH_NetConn_RegisterDefaultNetConnCallback(NetConn_NetConnCallback *netConnCallback, uint32_t *callbackId)
```

**Description**

Registers a callback to listen default network's status changed.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| netConnCallback | The callback needed to be registered. |
| callbackId | Out param, corresponding to a registered callback. |

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**2100008**: the callback already exists.

**2101022**: the number of requests exceeded the maximum allowed.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_UnregisterNetConnCallback()

```
int32_t OH_NetConn_UnregisterNetConnCallback(uint32_t callBackId)
```

**Description**

Unregisters network status callback.

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| callBackId | The id corresponding to a registered callback. |

**Returns**

**0**: success.

**201**: no permission.

**401**: parameter error.

**2100002**: failed to connect to the service.

**2100003**: internal error.

**2100007**: the callback does not exists.

**Permission：**

ohos.permission.GET_NETWORK_INFO