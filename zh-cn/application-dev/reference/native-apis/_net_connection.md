# NetConnection


## 概述

为网络管理数据网络连接模块提供C接口。

为网络管理的数据网络连接模块的C接口提供数据结构.

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [net_connection.h](net__connection_8h.md) | 为网络管理数据网络连接模块提供C接口。 | 
| [net_connection_type.h](net__connection__type_8h.md) | 定义网络连接模块的C接口需要的数据结构。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [NetConn_NetHandle](_net_conn___net_handle.md) | 存放网络ID。 | 
| [NetConn_NetCapabilities](_net_conn___net_capabilities.md) | 网络能力集。 | 
| [NetConn_NetAddr](_net_conn___net_addr.md) | 网络地址。 | 
| [NetConn_Route](_net_conn___route.md) | 路由配置信息。 | 
| [NetConn_HttpProxy](_net_conn___http_proxy.md) | 代理配置信息。 | 
| [NetConn_ConnectionProperties](_net_conn___connection_properties.md) | 网络链接信息。 | 
| [NetConn_NetHandleList](_net_conn___net_handle_list.md) | 网络列表。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| **NETCONN_MAX_NET_SIZE** | 32 | 
| **NETCONN_MAX_BEARER_TYPE_SIZE** | 32 | 
| **NETCONN_MAX_CAP_SIZE** | 32 | 
| **NETCONN_MAX_ADDR_SIZE** | 32 | 
| **NETCONN_MAX_ROUTE_SIZE** | 64 | 
| **NETCONN_MAX_EXCLUSION_SIZE** | 256 | 
| **NETCONN_MAX_STR_LEN** | 256 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [NetConn_NetCap](#netconn_netcap) | 网络能力集。 | 
| [NetConn_NetBearerType](#netconn_netbearertype) | 网络载体类型。 | 
| [NetConn_NetHandle](#netconn_nethandle) | 存放网络ID。 | 
| [NetConn_NetCapabilities](#netconn_netcapabilities) | 网络能力集。 | 
| [NetConn_NetAddr](#netconn_netaddr) | 网络地址。 | 
| [NetConn_Route](#netconn_route) | 路由配置信息。 | 
| [NetConn_HttpProxy](#netconn_httpproxy) | 代理配置信息。 | 
| [NetConn_ConnectionProperties](#netconn_connectionproperties) | 网络链接信息。 | 
| [NetConn_NetHandleList](#netconn_nethandlelist) | 网络列表。 | 
| (\*[OH_NetConn_CustomDnsResolver](#oh_netconn_customdnsresolver)) (const char \*host, const char \*serv, const struct addrinfo \*hint, struct addrinfo \*\*res) | 指向自定义 DNS 解析器的指针。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NetConn_NetCap](#netconn_netcap) {<br/>NETCONN_NET_CAPABILITY_MMS = 0,<br/>NETCONN_NET_CAPABILITY_NOT_METERED = 11,<br/>NETCONN_NET_CAPABILITY_INTERNET = 12,<br/>NETCONN_NET_CAPABILITY_NOT_VPN = 15,<br/>NETCONN_NET_CAPABILITY_VALIDATED = 16<br/>} | 网络能力集。 | 
| [NetConn_NetBearerType](#netconn_netbearertype) {<br/>NETCONN_BEARER_CELLULAR = 0,<br/>NETCONN_BEARER_WIFI = 1,<br/>NETCONN_BEARER_ETHERNET = 3<br/>} | 网络载体类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NetConn_HasDefaultNet](#oh_netconn_hasdefaultnet) (int32_t \*hasDefaultNet) | 查询是否有默认激活的数据网络。 | 
| [OH_NetConn_GetDefaultNet](#oh_netconn_getdefaultnet) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle) | 获取激活的默认的数据网络。 | 
| [OH_NetConn_IsDefaultNetMetered](#oh_netconn_isdefaultnetmetered) (int32_t \*isMetered) | 查询默认数据网络是否记流量。 | 
| [OH_NetConn_GetConnectionProperties](#oh_netconn_getconnectionproperties) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_ConnectionProperties](_net_conn___connection_properties.md) \*prop) | 查询某个数据网络的链路信息。 | 
| [OH_NetConn_GetNetCapabilities](#oh_netconn_getnetcapabilities) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_NetCapabilities](_net_conn___net_capabilities.md) \*netCapacities) | 查询某个网络的能力集。 | 
| [OH_NetConn_GetDefaultHttpProxy](#oh_netconn_getdefaulthttpproxy) ([NetConn_HttpProxy](_net_conn___http_proxy.md) \*httpProxy) | 查询默认的网络代理。 | 
| [OH_NetConn_GetAddrInfo](#oh_netconn_getaddrinfo) (char \*host, char \*serv, struct addrinfo \*hint, struct addrinfo \*\*res, int32_t netId) | 通过netId获取DNS结果。 | 
| [OH_NetConn_FreeDnsResult](#oh_netconn_freednsresult) (struct addrinfo \*res) | 释放DNS结果。 | 
| [OH_NetConn_GetAllNets](#oh_netconn_getallnets) ([NetConn_NetHandleList](_net_conn___net_handle_list.md) \*netHandleList) | 查询所有激活的数据网络。 | 
| [OHOS_NetConn_RegisterDnsResolver](#ohos_netconn_registerdnsresolver) ([OH_NetConn_CustomDnsResolver](#oh_netconn_customdnsresolver) resolver) | 注册自定义 DNS 解析器。 | 
| [OHOS_NetConn_UnregisterDnsResolver](#ohos_netconn_unregisterdnsresolver) (void) | 取消注册自定义 DNS 解析器。 | 


## 类型定义说明


### NetConn_ConnectionProperties

```
typedef struct NetConn_ConnectionPropertiesNetConn_ConnectionProperties
```

**描述**

网络链接信息。

**起始版本：** 11


### NetConn_HttpProxy

```
typedef struct NetConn_HttpProxyNetConn_HttpProxy
```

**描述**

代理配置信息。

**起始版本：** 11


### NetConn_NetAddr

```
typedef struct NetConn_NetAddrNetConn_NetAddr
```

**描述**

网络地址。

**起始版本：** 11


### NetConn_NetBearerType

```
typedef enum NetConn_NetBearerTypeNetConn_NetBearerType
```

**描述**

网络载体类型。

**起始版本：** 11


### NetConn_NetCap

```
typedef enum NetConn_NetCapNetConn_NetCap
```

**描述**

网络能力集。

**起始版本：** 11


### NetConn_NetCapabilities

```
typedef struct NetConn_NetCapabilitiesNetConn_NetCapabilities
```

**描述**

网络能力集。

**起始版本：** 11


### NetConn_NetHandle

```
typedef struct NetConn_NetHandleNetConn_NetHandle
```

**描述**

存放网络ID。

**起始版本：** 11


### NetConn_NetHandleList

```
typedef struct NetConn_NetHandleListNetConn_NetHandleList
```

**描述**

网络列表。

**起始版本：** 11


### NetConn_Route

```
typedef struct NetConn_RouteNetConn_Route
```

**描述**

路由配置信息。

**起始版本：** 11


### OH_NetConn_CustomDnsResolver

```
typedef int(* OH_NetConn_CustomDnsResolver) (const char *host, const char *serv, const struct addrinfo *hint, struct addrinfo **res)
```

**描述**

指向自定义 DNS 解析器的指针。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| host | 要查询的主机名 | 
| serv | 服务名称 | 
| hint | 指向addrinfo结构的指针 | 
| res | 存储DNS查询结果并以链表形式返回 | 


## 枚举类型说明


### NetConn_NetBearerType

```
enum NetConn_NetBearerType
```

**描述**

网络载体类型。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| NETCONN_BEARER_CELLULAR | 蜂窝网络。 | 
| NETCONN_BEARER_WIFI | WIFI。 | 
| NETCONN_BEARER_ETHERNET | Ethernet。 | 


### NetConn_NetCap

```
enum NetConn_NetCap
```

**描述**

网络能力集。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| NETCONN_NET_CAPABILITY_MMS | MMS。 | 
| NETCONN_NET_CAPABILITY_NOT_METERED | 非计量网络。 | 
| NETCONN_NET_CAPABILITY_INTERNET | Internet。 | 
| NETCONN_NET_CAPABILITY_NOT_VPN | 非VPN。 | 
| NETCONN_NET_CAPABILITY_VALIDATED | 已验证。 | 


## 函数说明


### OH_NetConn_FreeDnsResult()

```
int32_t OH_NetConn_FreeDnsResult (struct addrinfo * res)
```

**描述**

释放DNS结果。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| res | DNS查询结果链表头。 | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.INTERNET


### OH_NetConn_GetAddrInfo()

```
int32_t OH_NetConn_GetAddrInfo (char * host, char * serv, struct addrinfo * hint, struct addrinfo ** res, int32_t netId )
```

**描述**

通过netId获取DNS结果。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| host | 所需查询的host名. | 
| serv | 服务名. | 
| hint | 指向addrinfo结构体的指针. | 
| res | 存放DNS查询结果，以链表形式返回. | 
| netId | DNS查询netId 为0是使用默认netid查询. | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.INTERNET


### OH_NetConn_GetAllNets()

```
int32_t OH_NetConn_GetAllNets (NetConn_NetHandleList * netHandleList)
```

**描述**

查询所有激活的数据网络。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| netHandleList | 网络信息列表. | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_GetConnectionProperties()

```
int32_t OH_NetConn_GetConnectionProperties (NetConn_NetHandle * netHandle, NetConn_ConnectionProperties * prop )
```

**描述**

查询某个数据网络的链路信息。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nethandle | 存放网络ID. | 
| prop | 存放链路信息. | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_GetDefaultHttpProxy()

```
int32_t OH_NetConn_GetDefaultHttpProxy (NetConn_HttpProxy * httpProxy)
```

**描述**

查询默认的网络代理。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpProxy | 存放代理配置信息. | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.


### OH_NetConn_GetDefaultNet()

```
int32_t OH_NetConn_GetDefaultNet (NetConn_NetHandle * netHandle)
```

**描述**

获取激活的默认的数据网络。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| netHandle | 存放网络ID. | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_GetNetCapabilities()

```
int32_t OH_NetConn_GetNetCapabilities (NetConn_NetHandle * netHandle, NetConn_NetCapabilities * netCapacities )
```

**描述**

查询某个网络的能力集。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| netHandle | 存放网络ID. | 
| netCapacities | 存放能力集. | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_HasDefaultNet()

```
int32_t OH_NetConn_HasDefaultNet (int32_t * hasDefaultNet)
```

**描述**

查询是否有默认激活的数据网络。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| hasDefaultNet | 是否有默认网络。 | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_IsDefaultNetMetered()

```
int32_t OH_NetConn_IsDefaultNetMetered (int32_t * isMetered)
```

**描述**

查询默认数据网络是否记流量。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| isMetered | 是否激活。 | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OHOS_NetConn_RegisterDnsResolver()

```
int32_t OHOS_NetConn_RegisterDnsResolver (OH_NetConn_CustomDnsResolver resolver)
```

**描述**

注册自定义 DNS 解析器。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resolver | 指向自定义 DNS 解析器的指针。 | 

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.INTERNET


### OHOS_NetConn_UnregisterDnsResolver()

```
int32_t OHOS_NetConn_UnregisterDnsResolver (void )
```

**描述**

取消注册自定义 DNS 解析器。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

**Permission：**

ohos.permission.INTERNET
