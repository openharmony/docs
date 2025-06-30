# net_connection_type.h


## Overview

Declares the structs for the C APIs of the network connection module.

**Library**: libnet_connection.so

**System capability**: SystemCapability.Communication.NetManager.Core

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [NetConn_NetHandle](_net_conn___net_handle.md) | Network ID.| 
| [NetConn_NetCapabilities](_net_conn___net_capabilities.md) | Network capability set.| 
| [NetConn_NetAddr](_net_conn___net_addr.md) | Network address.| 
| [NetConn_Route](_net_conn___route.md) | Route configuration:| 
| [NetConn_HttpProxy](_net_conn___http_proxy.md) | Proxy configuration information.| 
| [NetConn_ConnectionProperties](_net_conn___connection_properties.md) | Network connection information.| 
| [NetConn_NetHandleList](_net_conn___net_handle_list.md) | Network list.| 
| [NetConn_NetConnCallback](_net_conn___net_conn_callback.md) | Network status callback. | 
| [NetConn_NetSpecifier](_net_conn___net_specifier.md) | Network specifier, including a network capability set and a network ID. | 


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
| [NetConn_NetCap](_net_connection.md#netconn_netcap) | Network capability set.| 
| [NetConn_NetBearerType](_net_connection.md#netconn_netbearertype) | Network carrier type.| 
| [NetConn_NetHandle](_net_connection.md#netconn_nethandle) | Network ID.| 
| [NetConn_NetCapabilities](_net_connection.md#netconn_netcapabilities) | Network capability set.| 
| [NetConn_NetAddr](_net_connection.md#netconn_netaddr) | Network address.| 
| [NetConn_Route](_net_connection.md#netconn_route) | Route configuration:| 
| [NetConn_HttpProxy](_net_connection.md#netconn_httpproxy) | Proxy configuration information.| 
| [NetConn_ConnectionProperties](_net_connection.md#netconn_connectionproperties) | Network connection information.| 
| [NetConn_NetHandleList](_net_connection.md#netconn_nethandlelist) | Network list.| 
| (\*[OH_NetConn_CustomDnsResolver](_net_connection.md#oh_netconn_customdnsresolver)) (const char \*host, const char \*serv, const struct addrinfo \*hint, struct addrinfo \*\*res) | Pointer to the custom DNS resolver.| 
| [NetConn_ErrorCode](_net_connection.md#netconn_errorcode) | Network connection error code.|


### Enums

| Name| Description| 
| -------- | -------- |
| [NetConn_NetCap](_net_connection.md#netconn_netcap) {<br>NETCONN_NET_CAPABILITY_MMS = 0,<br>NETCONN_NET_CAPABILITY_NOT_METERED = 11,<br>NETCONN_NET_CAPABILITY_INTERNET = 12,<br>NETCONN_NET_CAPABILITY_NOT_VPN = 15,<br>NETCONN_NET_CAPABILITY_VALIDATED = 16<br>} | Network capability set.| 
| [NetConn_NetBearerType](_net_connection.md#netconn_netbearertype) {<br>NETCONN_BEARER_CELLULAR = 0,<br>NETCONN_BEARER_WIFI = 1,<br>NETCONN_BEARER_ETHERNET = 3<br>NETCONN_BEARER_VPN = 4<br>} | Network carrier type.|
| [NetConn_ErrorCode](_net_connection.md#netconn_errorcode) {<br>NETCONN_SUCCESS = 0,<br>NETCONN_PERMISSION_DENIED = 201,<br>NETCONN_PARAMETER_ERROR = 401,<br>NETCONN_OPERATION_FAILED = 2100002,<br>NETCONN_INTERNAL_ERROR = 2100003<br>} | Network connection error code.|
