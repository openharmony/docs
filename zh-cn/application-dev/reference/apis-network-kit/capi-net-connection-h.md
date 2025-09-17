# net_connection.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

## 概述

为网络管理数据网络连接模块提供C接口。

**引用文件：** <network/netmanager/net_connection.h>

**库：** libnet_connection.so

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11

**相关模块：** [NetConnection](capi-netconnection.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_NetConn_HasDefaultNet(int32_t *hasDefaultNet)](#oh_netconn_hasdefaultnet) | 查询是否有默认激活的数据网络。 |
| [int32_t OH_NetConn_GetDefaultNet(NetConn_NetHandle *netHandle)](#oh_netconn_getdefaultnet) | 获取激活的默认的数据网络。 |
| [int32_t OH_NetConn_IsDefaultNetMetered(int32_t *isMetered)](#oh_netconn_isdefaultnetmetered) | 查询默认网络是否按流量计费。 |
| [int32_t OH_NetConn_GetConnectionProperties(NetConn_NetHandle *netHandle, NetConn_ConnectionProperties *prop)](#oh_netconn_getconnectionproperties) | 查询某个数据网络的链路信息。 |
| [int32_t OH_NetConn_GetNetCapabilities(NetConn_NetHandle *netHandle, NetConn_NetCapabilities *netCapabilities)](#oh_netconn_getnetcapabilities) | 查询某个网络的能力集。 |
| [int32_t OH_NetConn_GetDefaultHttpProxy(NetConn_HttpProxy *httpProxy)](#oh_netconn_getdefaulthttpproxy) | 查询默认的网络代理。 |
| [int32_t OH_NetConn_GetAddrInfo(char *host, char *serv, struct addrinfo *hint, struct addrinfo **res, int32_t netId)](#oh_netconn_getaddrinfo) | 通过netId获取DNS结果。 |
| [int32_t OH_NetConn_FreeDnsResult(struct addrinfo *res)](#oh_netconn_freednsresult) | 释放DNS结果。 |
| [int32_t OH_NetConn_GetAllNets(NetConn_NetHandleList *netHandleList)](#oh_netconn_getallnets) | 查询所有激活的数据网络。 |
| [int32_t OHOS_NetConn_RegisterDnsResolver(OH_NetConn_CustomDnsResolver resolver)](#ohos_netconn_registerdnsresolver) | 注册自定义DNS解析器。 |
| [int32_t OHOS_NetConn_UnregisterDnsResolver(void)](#ohos_netconn_unregisterdnsresolver) | 取消注册自定义DNS解析器。 |
| [int32_t OH_NetConn_RegisterDnsResolver(OH_NetConn_CustomDnsResolver resolver)](#oh_netconn_registerdnsresolver) | 注册自定义DNS解析器。 |
| [int32_t OH_NetConn_UnregisterDnsResolver(void)](#oh_netconn_unregisterdnsresolver) | 取消注册自定义DNS解析器。 |
| [int32_t OH_NetConn_BindSocket(int32_t socketFd, NetConn_NetHandle *netHandle)](#oh_netconn_bindsocket) | 将套接字绑定到特定的网络。 |
| [int32_t OH_NetConn_SetAppHttpProxy(NetConn_HttpProxy *httpProxy)](#oh_netconn_setapphttpproxy) | 为当前应用设置http代理配置信息。 |
| [int32_t OH_NetConn_RegisterAppHttpProxyCallback(OH_NetConn_AppHttpProxyChange appHttpProxyChange, uint32_t *callbackId)](#oh_netconn_registerapphttpproxycallback) | 注册监听应用http代理变化的回调。 |
| [void OH_NetConn_UnregisterAppHttpProxyCallback(uint32_t callbackId)](#oh_netconn_unregisterapphttpproxycallback) | 注销监听应用http代理变化的回调。 |
| [int32_t OH_NetConn_RegisterNetConnCallback(NetConn_NetSpecifier *specifier, NetConn_NetConnCallback *netConnCallback,uint32_t timeout, uint32_t *callbackId)](#oh_netconn_registernetconncallback) | 注册监听网络状态变化的回调。 |
| [int32_t OH_NetConn_RegisterDefaultNetConnCallback(NetConn_NetConnCallback *netConnCallback, uint32_t *callbackId)](#oh_netconn_registerdefaultnetconncallback) | 注册监听默认网络状态变化的回调。 |
| [int32_t OH_NetConn_UnregisterNetConnCallback(uint32_t callBackId)](#oh_netconn_unregisternetconncallback) | 注销监听网络状态变化的回调。 |
| [NetConn_ErrorCode OH_NetConn_SetPacUrl(const char *pacUrl)](#oh_netconn_setpacurl) | 设置系统级代理自动配置（PAC）脚本地址。 |
| [NetConn_ErrorCode OH_NetConn_GetPacUrl(char *pacUrl)](#oh_netconn_getpacurl) | 获取系统级代理自动配置（PAC）脚本地址。 |
| [int32_t OH_NetConn_QueryProbeResult(char *destination, int32_t duration, NetConn_ProbeResultInfo *probeResultInfo)](#oh_netconn_queryproberesult) | 查询网络探测结果。 |
| [int32_t OH_NetConn_QueryTraceRoute(char *destination, NetConn_TraceRouteOption *option,NetConn_TraceRouteInfo *traceRouteInfo)](#oh_netconn_querytraceroute) | 查询网络跟踪路由。 |


## 函数说明

### OH_NetConn_HasDefaultNet()

```
int32_t OH_NetConn_HasDefaultNet(int32_t *hasDefaultNet)
```

**描述**

查询是否有默认激活的数据网络。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t *hasDefaultNet | 是否有默认网络。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_GetDefaultNet()

```
int32_t OH_NetConn_GetDefaultNet(NetConn_NetHandle *netHandle)
```

**描述**

获取激活的默认的数据网络。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | 存放网络ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_IsDefaultNetMetered()

```
int32_t OH_NetConn_IsDefaultNetMetered(int32_t *isMetered)
```

**描述**

查询默认数据网络是否记流量。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t *isMetered | 是否激活。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_GetConnectionProperties()

```
int32_t OH_NetConn_GetConnectionProperties(NetConn_NetHandle *netHandle, NetConn_ConnectionProperties *prop)
```

**描述**

查询某个数据网络的链路信息。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | 存放网络ID。 |
| [NetConn_ConnectionProperties](capi-netconnection-netconn-connectionproperties.md) *prop | 存放链路信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_GetNetCapabilities()

```
int32_t OH_NetConn_GetNetCapabilities(NetConn_NetHandle *netHandle, NetConn_NetCapabilities *netCapabilities)
```

**描述**

查询某个网络的能力集。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 11


**参数：**

| 参数项                                                                     | 描述 |
|-------------------------------------------------------------------------| -- |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | 存放网络ID。 |
| [NetConn_NetCapabilities](capi-netconnection-netconn-netcapabilities.md) *netCapabilities                            | 存放能力集。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误. 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_GetDefaultHttpProxy()

```
int32_t OH_NetConn_GetDefaultHttpProxy(NetConn_HttpProxy *httpProxy)
```

**描述**

查询默认的网络代理。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NetConn_HttpProxy](capi-netconnection-netconn-httpproxy.md) *httpProxy | 存放代理配置信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误. 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_GetAddrInfo()

```
int32_t OH_NetConn_GetAddrInfo(char *host, char *serv, struct addrinfo *hint, struct addrinfo **res, int32_t netId)
```

**描述**

通过netId获取DNS结果。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.INTERNET

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char *host | 所需查询的host名。 |
| char *serv | 服务名。 |
| struct addrinfo *hint | 指向addrinfo结构体的指针。 |
| struct addrinfo **res | 存放DNS查询结果，以链表形式返回。 |
| int32_t netId | DNS查询netId为0时，使用默认netid查询。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_FreeDnsResult()

```
int32_t OH_NetConn_FreeDnsResult(struct addrinfo *res)
```

**描述**

释放DNS结果。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.INTERNET

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct addrinfo *res | DNS查询结果链表头。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_GetAllNets()

```
int32_t OH_NetConn_GetAllNets(NetConn_NetHandleList *netHandleList)
```

**描述**

查询所有激活的数据网络。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NetConn_NetHandleList](capi-netconnection-netconn-nethandlelist.md) *netHandleList | 网络信息列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OHOS_NetConn_RegisterDnsResolver()

```
int32_t OHOS_NetConn_RegisterDnsResolver(OH_NetConn_CustomDnsResolver resolver)
```

**描述**

注册自定义DNS解析器。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.INTERNET

**起始版本：** 11

**废弃版本：** 13

**替代接口：** OH_NetConn_RegisterDnsResolver


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NetConn_CustomDnsResolver](capi-net-connection-type-h.md#oh_netconn_customdnsresolver) resolver | 指向自定义DNS解析器的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OHOS_NetConn_UnregisterDnsResolver()

```
int32_t OHOS_NetConn_UnregisterDnsResolver(void)
```

**描述**

取消注册自定义DNS解析器。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.INTERNET

**起始版本：** 11

**废弃版本：** 13

**替代接口：** OH_NetConn_UnregisterDnsResolver

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_RegisterDnsResolver()

```
int32_t OH_NetConn_RegisterDnsResolver(OH_NetConn_CustomDnsResolver resolver)
```

**描述**

注册自定义DNS解析器。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.INTERNET

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| 指向自定义DNS解析器的指针。 |  |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回结果码。<br>         NETMANAGER_EXT_SUCCESS 如果操作成功。<br>         NETMANAGER_ERR_PERMISSION_DENIED 缺少权限，请添加权限。<br>         NETMANAGER_ERR_PARAMETER_ERROR 参数错误。请输入正确的参数。 |

### OH_NetConn_UnregisterDnsResolver()

```
int32_t OH_NetConn_UnregisterDnsResolver(void)
```

**描述**

取消注册自定义DNS解析器。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.INTERNET

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         401 - 参数错误。 2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_BindSocket()

```
int32_t OH_NetConn_BindSocket(int32_t socketFd, NetConn_NetHandle *netHandle)
```

**描述**

将套接字绑定到特定的网络。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t socketFd | 由用户构造的套接字。 |
| [NetConn_NetHandle](capi-netconnection-netconn-nethandle.md) *netHandle | 指针类型，指向包含网络ID的网络句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。<br>         401 - 参数错误。<br>         2100002 - 无法连接到服务。<br>         2100003 - 内部错误。 |

### OH_NetConn_SetAppHttpProxy()

```
int32_t OH_NetConn_SetAppHttpProxy(NetConn_HttpProxy *httpProxy)
```

**描述**

为当前应用设置http代理配置信息。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NetConn_HttpProxy](capi-netconnection-netconn-httpproxy.md) *httpProxy | 需要设置的http代理配置信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。<br>         401 - 参数错误。 |

### OH_NetConn_RegisterAppHttpProxyCallback()

```
int32_t OH_NetConn_RegisterAppHttpProxyCallback(OH_NetConn_AppHttpProxyChange appHttpProxyChange, uint32_t *callbackId)
```

**描述**

注册监听应用http代理变化的回调。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NetConn_AppHttpProxyChange](capi-net-connection-type-h.md#oh_netconn_apphttpproxychange) appHttpProxyChange | 需要注册的监听回调。 |
| uint32_t *callbackId | 回调注册后生成的id, 关联已注册的回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。<br>         401 - 参数错误。 |

### OH_NetConn_UnregisterAppHttpProxyCallback()

```
void OH_NetConn_UnregisterAppHttpProxyCallback(uint32_t callbackId)
```

**描述**

注销监听应用http代理变化的回调。

**系统能力：** SystemCapability.Communication.NetManager.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint32_t callbackId | 需要被注销的回调所对应的id。 |

### OH_NetConn_RegisterNetConnCallback()

```
int32_t OH_NetConn_RegisterNetConnCallback(NetConn_NetSpecifier *specifier, NetConn_NetConnCallback *netConnCallback,uint32_t timeout, uint32_t *callbackId)
```

**描述**

注册监听网络状态变化的回调。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| netSpecifier | 网络特征集。 |
| callback | 注册的回调函数集合。 |
| uint32_t timeout | 超时时间，单位为毫秒，为0时表示无限等待。 |
| uint32_t *callbackId | 出参，对应本次注册成功的回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。<br>         201 - 缺少权限。<br>         401 - 参数错误。<br>         2100002 - 无法连接到服务。<br>         2100003 - 内部错误。<br>         2101008 - 回调已注册。<br>         2101022 - 请求数超出了允许的最大值。 |

### OH_NetConn_RegisterDefaultNetConnCallback()

```
int32_t OH_NetConn_RegisterDefaultNetConnCallback(NetConn_NetConnCallback *netConnCallback, uint32_t *callbackId)
```

**描述**

注册监听默认网络状态变化的回调。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| callback | 注册的回调函数集合。 |
| uint32_t *callbackId | 出参，对应本次注册成功的回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。<br>         201 - 缺少权限。<br>         401 - 参数错误。<br>         2100002 - 无法连接到服务。<br>         2100003 - 内部错误。<br>         2101008 - 回调已注册。<br>         2101022 - 请求数超出了允许的最大值。 |

### OH_NetConn_UnregisterNetConnCallback()

```
int32_t OH_NetConn_UnregisterNetConnCallback(uint32_t callBackId)
```

**描述**

注销监听网络状态变化的回调。

**系统能力：** SystemCapability.Communication.NetManager.Core

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint32_t callBackId | 需要被注销的回调对应id。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。<br>         201 - 缺少权限。<br>         401 - 参数错误。<br>         2100002 - 无法连接到服务。<br>         2100003 - 内部错误。<br>         2101007 - 回调不存在。 |

### OH_NetConn_SetPacUrl()

```
NetConn_ErrorCode OH_NetConn_SetPacUrl(const char *pacUrl)
```

**描述**

设置系统级代理自动配置（PAC）脚本地址。

**需要权限：** ohos.permission.SET_PAC_URL

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *pacUrl | 需要设置的PAC脚本地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [NetConn_ErrorCode](capi-net-connection-type-h.md#netconn_errorcode) | 结果定义在 [NetConn_ErrorCode](capi-net-connection-type-h.md#netconn_errorcode)。<br>         [NETCONN_SUCCESS](capi-net-connection-type-h.md#netconn_errorcode) 成功。<br>         [NETCONN_PERMISSION_DENIED](capi-net-connection-type-h.md#netconn_errorcode) 缺少权限。<br>         [NETCONN_PARAMETER_ERROR](capi-net-connection-type-h.md#netconn_errorcode) 参数错误。<br>         [NETCONN_OPERATION_FAILED](capi-net-connection-type-h.md#netconn_errorcode) 无法连接到服务。<br>         [NETCONN_INTERNAL_ERROR](capi-net-connection-type-h.md#netconn_errorcode) 内部错误。 |

### OH_NetConn_GetPacUrl()

```
NetConn_ErrorCode OH_NetConn_GetPacUrl(char *pacUrl)
```

**描述**

获取系统级代理自动配置（PAC）脚本地址。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char *pacUrl | 获取的PAC脚本地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [NetConn_ErrorCode](capi-net-connection-type-h.md#netconn_errorcode) | 结果定义在 [NetConn_ErrorCode](capi-net-connection-type-h.md#netconn_errorcode)。<br>         [NETCONN_SUCCESS](capi-net-connection-type-h.md#netconn_errorcode) 成功。<br>         [NETCONN_PARAMETER_ERROR](capi-net-connection-type-h.md#netconn_errorcode) 参数错误。<br>         [NETCONN_OPERATION_FAILED](capi-net-connection-type-h.md#netconn_errorcode) 无法连接到服务。<br>         [NETCONN_INTERNAL_ERROR](capi-net-connection-type-h.md#netconn_errorcode) 内部错误。 |

### OH_NetConn_QueryProbeResult()

```
int32_t OH_NetConn_QueryProbeResult(char *destination, int32_t duration, NetConn_ProbeResultInfo *probeResultInfo)
```

**描述**

查询网络探测结果。

**需要权限：** ohos.permission.INTERNET

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char *destination | 目的地址。 |
| int32_t duration | 探测持续时间。单位：秒。 |
| [NetConn_ProbeResultInfo](capi-netconnection-netconn-proberesultinfo.md) *probeResultInfo | 丢包率和往返时间（RTT）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。<br>         201 - 缺少权限。<br>         401 - 参数错误。<br>         2100003 - 内部错误。 |

### OH_NetConn_QueryTraceRoute()

```
int32_t OH_NetConn_QueryTraceRoute(char *destination, NetConn_TraceRouteOption *option,NetConn_TraceRouteInfo *traceRouteInfo)
```

**描述**

查询网络跟踪路由。

**需要权限：** ohos.permission.INTERNET、ohos.permission.LOCATION 和 ohos.permission.ACCESS_NET_TRACE_INFO

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char *destination | 目的地址。 |
| [NetConn_TraceRouteOption](capi-netconnection-netconn-tracerouteoption.md) *option | 路由参数选项。 |
| [NetConn_TraceRouteInfo](capi-netconnection-netconn-tracerouteinfo.md) *traceRouteInfo | 路由结果。需传入数组指针，数组大小代表路由跳数，默认30跳。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。<br>         201 - 缺少权限。 |
