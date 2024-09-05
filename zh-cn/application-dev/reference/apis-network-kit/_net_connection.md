# NetConnection


## 概述

为网络管理数据网络连接模块提供C接口。

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
| [NetConn_NetConnCallback](_net_conn___net_conn_callback.md) | 网络状态监听回调集合。 |
| [NetConn_NetSpecifier](_net_conn___net_specifier.md) | 网络的特征集，包含网络的能力集与网络的标识符。 |


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
| [NetConn_NetConnCallback](#netconn_netconncallback) | 网络状态监听回调集合。 |
| [NetConn_NetSpecifier](#netconn_netspecifier) | 网络的特征集，包含网络的能力集与网络的标识符。 |

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NetConn_NetCap](#netconn_netcap) {<br/>NETCONN_NET_CAPABILITY_MMS = 0,<br/>NETCONN_NET_CAPABILITY_NOT_METERED = 11,<br/>NETCONN_NET_CAPABILITY_INTERNET = 12,<br/>NETCONN_NET_CAPABILITY_NOT_VPN = 15,<br/>NETCONN_NET_CAPABILITY_VALIDATED = 16<br/>} | 网络能力集。 | 
| [NetConn_NetBearerType](#netconn_netbearertype) {<br/>NETCONN_BEARER_CELLULAR = 0,<br/>NETCONN_BEARER_WIFI = 1,<br/>NETCONN_BEARER_ETHERNET = 3<br/>NETCONN_BEARER_VPN = 4<br/>} | 网络载体类型。 |


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NetConn_HasDefaultNet](#oh_netconn_hasdefaultnet) (int32_t \*hasDefaultNet) | 查询是否有默认激活的数据网络。 | 
| [OH_NetConn_GetDefaultNet](#oh_netconn_getdefaultnet) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle) | 获取激活的默认的数据网络。 | 
| [OH_NetConn_IsDefaultNetMetered](#oh_netconn_isdefaultnetmetered) (int32_t \*isMetered) | 查询默认网络是否按流量计费。 | 
| [OH_NetConn_GetConnectionProperties](#oh_netconn_getconnectionproperties) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_ConnectionProperties](_net_conn___connection_properties.md) \*prop) | 查询某个数据网络的链路信息。 | 
| [OH_NetConn_GetNetCapabilities](#oh_netconn_getnetcapabilities) ([NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle, [NetConn_NetCapabilities](_net_conn___net_capabilities.md) \*netCapacities) | 查询某个网络的能力集。 | 
| [OH_NetConn_GetDefaultHttpProxy](#oh_netconn_getdefaulthttpproxy) ([NetConn_HttpProxy](_net_conn___http_proxy.md) \*httpProxy) | 查询默认的网络代理。 | 
| [OH_NetConn_GetAddrInfo](#oh_netconn_getaddrinfo) (char \*host, char \*serv, struct addrinfo \*hint, struct addrinfo \*\*res, int32_t netId) | 通过netId获取DNS结果。 | 
| [OH_NetConn_FreeDnsResult](#oh_netconn_freednsresult) (struct addrinfo \*res) | 释放DNS结果。 | 
| [OH_NetConn_GetAllNets](#oh_netconn_getallnets) ([NetConn_NetHandleList](_net_conn___net_handle_list.md) \*netHandleList) | 查询所有激活的数据网络。 | 
| [OHOS_NetConn_RegisterDnsResolver](#ohos_netconn_registerdnsresolver) ([OH_NetConn_CustomDnsResolver](#oh_netconn_customdnsresolver) resolver) | 注册自定义 DNS 解析器。 | 
| [OHOS_NetConn_UnregisterDnsResolver](#ohos_netconn_unregisterdnsresolver) (void) | 取消注册自定义 DNS 解析器。 | 
| [OH_NetConn_BindSocket](#oh_netconn_bindsocket) (int32_t socketFd, [NetConn_NetHandle](_net_conn___net_handle.md) \*netHandle) | 将套接字与指定的网络进行绑定。 |
| [OH_NetConn_SetAppHttpProxy](#oh_netconn_setapphttpproxy) ([NetConn_HttpProxy](_net_conn___http_proxy.md) \*httpProxy) | 设置应用级代理信息。 |
| [OH_NetConn_RegisterAppHttpProxyCallback](#oh_netconn_registerapphttpproxycallback) ([OH_NetConn_AppHttpProxyChange](#oh_netconn_apphttpproxychange) appHttpProxyChange, uint32_t \*callbackId) | 注册监听应用级代理变化。 |
| [OH_NetConn_UnregisterAppHttpProxyCallback](#oh_netconn_unregisterapphttpproxycallback) (uint32_t callbackId) | 注销监听应用级代理变化。 | 
| [OH_NetConn_RegisterNetConnCallback](#oh_netconn_registernetconncallback) ([NetConn_NetSpecifier](_net_conn___net_specifier.md) \*specifier, [NetConn_NetConnCallback](_net_conn___net_conn_callback.md) \*netConnCallback, uint32_t timeoutMS, uint32_t \*callbackId) | 注册监听网络状态的回调。 |
| [OH_NetConn_RegisterDefaultNetConnCallback](#oh_netconn_registerdefaultnetconncallback) ([NetConn_NetConnCallback](_net_conn___net_conn_callback.md) \*netConnCallback, uint32_t \*callbackId) | 注册监听默认网络状态的回调。 |
| [OH_NetConn_UnregisterNetConnCallback](#oh_netconn_unregisternetconncallback) (uint32_t callbackId) | 注销监听网络状态的回调。 |


## 类型定义说明


### NetConn_ConnectionProperties

```
typedef struct NetConn_ConnectionProperties NetConn_ConnectionProperties
```

**描述**

网络链接信息。

**起始版本：** 11


### NetConn_HttpProxy

```
typedef struct NetConn_HttpProxy NetConn_HttpProxy
```

**描述**

代理配置信息。

**起始版本：** 11


### NetConn_NetAddr

```
typedef struct NetConn_NetAddr NetConn_NetAddr
```

**描述**

网络地址。

**起始版本：** 11


### NetConn_NetBearerType

```
typedef enum NetConn_NetBearerType NetConn_NetBearerType
```

**描述**

网络载体类型。

**起始版本：** 11


### NetConn_NetCap

```
typedef enum NetConn_NetCap NetConn_NetCap
```

**描述**

网络能力集。

**起始版本：** 11


### NetConn_NetCapabilities

```
typedef struct NetConn_NetCapabilities NetConn_NetCapabilities
```

**描述**

网络能力集。

**起始版本：** 11


### NetConn_NetHandle

```
typedef struct NetConn_NetHandle NetConn_NetHandle
```

**描述**

存放网络ID。

**起始版本：** 11


### NetConn_NetHandleList

```
typedef struct NetConn_NetHandleList NetConn_NetHandleList
```

**描述**

网络列表。

**起始版本：** 11


### NetConn_Route

```
typedef struct NetConn_Route NetConn_Route
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


### OH_NetConn_AppHttpProxyChange

```
typedef void(* OH_NetConn_AppHttpProxyChange) (NetConn_HttpProxy *proxy)
```

**描述**

应用级代理变化回调指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| proxy | 变化的代理配置信息（可能为空指针） | 


### NetConn_NetConnCallback

```
typedef struct NetConn_NetConnCallback NetConn_NetConnCallback
```

**描述**

网络状态监听回调集合。

**起始版本：** 12


### NetConn_NetSpecifier

```
typedef struct NetConn_NetSpecifier NetConn_NetSpecifier
```

**描述**

网络的特征集，包含网络的能力集与网络的标识符。

**起始版本：** 12


## 枚举类型说明


### NetConn_NetBearerType

```
enum NetConn_NetBearerType
```

**描述**

网络载体类型。

**起始版本：** 11

|         枚举值          |         描述            |
| ------------------------| ----------------------- |
| NETCONN_BEARER_CELLULAR | 蜂窝网络。              |
| NETCONN_BEARER_WIFI     | WIFI。                  |
| NETCONN_BEARER_BLUETOOTH     | 蓝牙。<br/>起始版本：12。 |
| NETCONN_BEARER_ETHERNET | Ethernet。              |
| NETCONN_BEARER_VPN      | VPN。<br/>起始版本：12。|


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
| NETCONN_NET_CAPABILITY_CHECKING_CONNECTIVITY  | 检测连通性中。<br/>起始版本：12。 | 


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


### OH_NetConn_BindSocket()

```
int32_t OH_NetConn_BindSocket (int32_t socketFd, NetConn_NetHandle * netHandle)
```

**描述**

将套接字与指定的网络进行绑定。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| socketFd | 用户创建的套接字. |
| netHandle | 存放网络ID. |

**返回：**

0 - 成功.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.


### OH_NetConn_SetAppHttpProxy()

```
int32_t OH_NetConn_SetAppHttpProxy(NetConn_HttpProxy *httpProxy)
```

**描述**

设置应用级代理配置信息。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| httpProxy | 应用级代理配置信息。 |

**返回：**

0 - 成功.

401 - 参数错误.


### OH_NetConn_RegisterAppHttpProxyCallback()

```
int32_t OH_NetConn_RegisterAppHttpProxyCallback(OH_NetConn_AppHttpProxyChange appHttpProxyChange, uint32_t *callbackId)
```

**描述**

注册监听应用级代理变化的回调。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| appHttpProxyChange | 指向应用级代理变化回调的指针。 |
| callbackId | 关联本次注册的回调的id。 |

**返回：**

0 - 成功.

401 - 参数错误.


### OH_NetConn_UnregisterAppHttpProxyCallback()

```
void OH_NetConn_UnregisterAppHttpProxyCallback(uint32_t callbackId)
```

**描述**

注销监听应用级代理变化的回调。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| callbackId | 关联需要注销的回调的id，此id在注册时得到。 |


### OH_NetConn_RegisterNetConnCallback()

```
int32_t OH_NetConn_RegisterNetConnCallback(NetConn_NetSpecifier *specifier, NetConn_NetConnCallback *netConnCallback, uint32_t timeout, uint32_t *callbackId)
```

**描述**

注册回调，用于监听特定的网络状态变更。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| specifier | 网络特征集。 |
| netConnCallback | 注册的回调函数集合。 |
| timeout | 等待时间，单位为毫秒，为0时表示无限等待。 |
| callbackId | 出参，对应本次注册成功的回调。 |

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

2101008 - 回调已注册.

2101022 - 超过最大请求数.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_RegisterDefaultNetConnCallback()

```
int32_t OH_NetConn_RegisterDefaultNetConnCallback(NetConn_NetConnCallback *netConnCallback, uint32_t *callbackId)
```

**描述**

注册回调，用于监听默认的网络状态变更。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| netConnCallback | 注册的回调函数集合。 |
| callbackId | 出参，对应本次注册成功的回调。 |

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

2101008 - 回调已注册.

2101022 - 超过最大请求数.

**Permission：**

ohos.permission.GET_NETWORK_INFO


### OH_NetConn_UnregisterNetConnCallback()

```
int32_t OH_NetConn_UnregisterNetConnCallback(uint32_t callBackId)
```

**描述**

注销网络状态监听回调。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callBackId | 需要被注销的回调对应id。 |

**返回：**

0 - 成功.

201 - 缺少权限.

401 - 参数错误.

2100002 - 无法连接到服务.

2100003 - 内部错误.

2101007 - 未找到相应回调.

**Permission：**

ohos.permission.GET_NETWORK_INFO