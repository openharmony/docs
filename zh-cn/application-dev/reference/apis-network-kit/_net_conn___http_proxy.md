# NetConn_HttpProxy


## 概述

代理配置信息。

**起始版本：** 11

**相关模块：**[NetConnection](_net_connection.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [host](#host) [NETCONN_MAX_STR_LEN] | 主机名。 | 
| [exclusionList](#exclusionlist) [NETCONN_MAX_EXCLUSION_SIZE][NETCONN_MAX_STR_LEN] | 代理服务器的排除列表。 | 
| [exclusionListSize](#exclusionlistsize) | 排除列表的实际大小。 | 
| [port](#port) | 端口号。 | 


## 结构体成员变量说明


### exclusionList

```
char NetConn_HttpProxy::exclusionList[NETCONN_MAX_EXCLUSION_SIZE][NETCONN_MAX_STR_LEN]
```

**描述**

代理服务器的排除列表。


### exclusionListSize

```
int32_t NetConn_HttpProxy::exclusionListSize
```

**描述**

排除列表的实际大小。


### host

```
char NetConn_HttpProxy::host[NETCONN_MAX_STR_LEN]
```

**描述**

主机名。


### port

```
uint16_t NetConn_HttpProxy::port
```

**描述**

端口号。
