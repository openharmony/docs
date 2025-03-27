# net_connection.h


## Overview

Provides the C APIs of the network connection module for network management.

**System capability**: SystemCapability.Communication.NetManager.Core

**Library**: libnet_connection.so

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_NetConn_HasDefaultNet](_net_connection.md#oh_netconn_hasdefaultnet) (int32_t \*hasDefaultNet) | Checks whether a default activated data network is available.| 
| [OH_NetConn_GetDefaultNet](_net_connection.md#oh_netconn_getdefaultnet) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle) | Obtains the default activated data network.| 
| [OH_NetConn_IsDefaultNetMetered](_net_connection.md#oh_netconn_isdefaultnetmetered) (int32_t \*isMetered) | Checks whether data traffic usage on the current network is metered.| 
| [OH_NetConn_GetConnectionProperties](_net_connection.md#oh_netconn_getconnectionproperties) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_ConnectionProperties](_net_conn___connection_properties.md) \*prop) | Obtains the link information of a data network.| 
| [OH_NetConn_GetNetCapabilities](_net_connection.md#oh_netconn_getnetcapabilities) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_NetCapabilities](_net_conn___net_capabilities.md) \*netCapacities) | Obtains the capabilities of a data network.| 
| [OH_NetConn_GetDefaultHttpProxy](_net_connection.md#oh_netconn_getdefaulthttpproxy) ([NetConn_HttpProxy](_net_conn___http_proxy.md) \*httpProxy) | Obtains the default network proxy.| 
| [OH_NetConn_GetAddrInfo](_net_connection.md#oh_netconn_getaddrinfo) (char \*host, char \*serv, struct addrinfo \*hint, struct addrinfo \*\*res, int32_t netId) | Obtains the DNS result using **netId**.| 
| [OH_NetConn_FreeDnsResult](_net_connection.md#oh_netconn_freednsresult) (struct addrinfo \*res) | Releases the DNS query result.| 
| [OH_NetConn_GetAllNets](_net_connection.md#oh_netconn_getallnets) ([NetConn_NetHandleList](_net_conn___net_handle_list.md) \*netHandleList) | Obtains all activated data networks.| 
| [OHOS_NetConn_RegisterDnsResolver](_net_connection.md#ohos_netconn_registerdnsresolver-deprecated) ([OH_NetConn_CustomDnsResolver](_net_connection.md#oh_netconn_customdnsresolver) resolver) | Registers a custom DNS resolver.<br>Note: This API is deprecated since API version 13.<br>You are advised to use **OH_NetConn_RegisterDnsResolver** instead.|
| [OHOS_NetConn_UnregisterDnsResolver](_net_connection.md#ohos_netconn_unregisterdnsresolver-deprecated) (void) | Unregisters a custom DNS resolver.<br>Note: This API is deprecated since API version 13.<br>You are advised to use **OH_NetConn_UnregisterDnsResolver** instead.|
| [OH_NetConn_RegisterDnsResolver](_net_connection.md#oh_netconn_registerdnsresolver) ([OH_NetConn_CustomDnsResolver](_net_connection.md#oh_netconn_customdnsresolver) resolver) | Registers a custom DNS resolver.|
| [OH_NetConn_UnregisterDnsResolver](_net_connection.md#oh_netconn_unregisterdnsresolver) (void) | Unregisters a custom DNS resolver.|
| [OH_NetConn_SetPacUrl](_net_connection.md#oh_netconn_setpacurl) (const char \*pacUrl) | Sets the URL of the system-level proxy auto-config (PAC) script.|
| [OH_NetConn_GetPacUrl](_net_connection.md#oh_netconn_getpacurl) (char \*pacUrl) | Obtains the URL of the system-level PAC script.|
