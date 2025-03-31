# NetConn_NetHandleList


## 概述

网络列表。

**起始版本：** 11

**相关模块：**[NetConnection](_net_connection.md)

**所在头文件：** [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [netHandles](#nethandles) [NETCONN_MAX_NET_SIZE] | netHandle列表。 | 
| [netHandleListSize](#nethandlelistsize) | netHandleList的实际大小。 | 


## 结构体成员变量说明


### netHandleListSize

```
int32_t NetConn_NetHandleList::netHandleListSize
```

**描述**

netHandleList的实际大小。


### netHandles

```
NetConn_NetHandle NetConn_NetHandleList::netHandles[NETCONN_MAX_NET_SIZE]
```

**描述**

netHandle列表。
