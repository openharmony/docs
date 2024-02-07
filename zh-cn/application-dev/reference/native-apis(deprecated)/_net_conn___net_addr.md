# NetConn_NetAddr


## 概述

网络地址。

**起始版本：** 11

**相关模块：**[NetConnection](_net_connection.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [family](#family) | 网络地址族。 | 
| [prefixlen](#prefixlen) | 前缀长度。 | 
| [port](#port) | 端口号。 | 
| [address](#address) [NETCONN_MAX_STR_LEN] | 地址。 | 


## 结构体成员变量说明


### address

```
char NetConn_NetAddr::address[NETCONN_MAX_STR_LEN]
```

**描述**

地址。


### family

```
uint8_t NetConn_NetAddr::family
```

**描述**

网络地址族。


### port

```
uint8_t NetConn_NetAddr::port
```

**描述**

端口号。


### prefixlen

```
uint8_t NetConn_NetAddr::prefixlen
```

**描述**

前缀长度。
