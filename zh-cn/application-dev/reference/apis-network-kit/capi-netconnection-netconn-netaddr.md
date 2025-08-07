# NetConn_NetAddr

## 概述

网络地址。

**起始版本：** 11

**相关模块：** [NetConnection](capi-netconnection.md)

**所在头文件：** [net_connection_type.h](capi-net-connection-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t family | 网络地址族。 |
| uint8_t prefixlen | 前缀长度。 |
| uint8_t port | 端口号。 |
| char address[[NETCONN_MAX_STR_LEN]](capi-net-connection-type-h.md#宏定义) | 地址。 |


