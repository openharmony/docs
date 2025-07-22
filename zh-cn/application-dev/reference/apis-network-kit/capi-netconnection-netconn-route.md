# NetConn_Route

## 概述

路由配置信息。

**起始版本：** 11

**相关模块：** [NetConnection](capi-netconnection.md)

**所在头文件：** [net_connection_type.h](capi-net-connection-type-h.md)

## 汇总

### 成员变量

| 名称                              | 描述 |
|---------------------------------| -- |
| char iface[NETCONN_MAX_STR_LEN] | 网络接口。 |
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) destination | 目标地址。 |
| [NetConn_NetAddr](capi-netconnection-netconn-netaddr.md) gateway         | 网关地址。 |
| int32_t hasGateway              | 是否存在网关。 |
| int32_t isDefaultRoute          | 是否是默认路由。 |
