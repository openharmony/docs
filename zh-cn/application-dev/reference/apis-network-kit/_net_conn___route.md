# NetConn_Route


## 概述

路由配置信息。

**起始版本：** 11

**相关模块：**[NetConnection](_net_connection.md)

**所在头文件：** [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [iface](#iface) [NETCONN_MAX_STR_LEN] | 网络接口。 | 
| [destination](#destination) | 目标地址。 | 
| [gateway](#gateway) | 网关地址。 | 
| [hasGateway](#hasgateway) | 是否存在网关。 | 
| [isDefaultRoute](#isdefaultroute) | 是否是默认路由。 | 


## 结构体成员变量说明


### destination

```
NetConn_NetAddr NetConn_Route::destination
```

**描述**

目标地址。


### gateway

```
NetConn_NetAddr NetConn_Route::gateway
```

**描述**

网关地址。


### hasGateway

```
int32_t NetConn_Route::hasGateway
```

**描述**

是否存在网关。


### iface

```
char NetConn_Route::iface[NETCONN_MAX_STR_LEN]
```

**描述**

网络接口。


### isDefaultRoute

```
int32_t NetConn_Route::isDefaultRoute
```

**描述**

是否是默认路由。
