# NetConn_TraceRouteInfo

## 概述

定义跟踪路由信息。

**起始版本：** 20

**相关模块：** [NetConnection](capi-netconnection.md)

**所在头文件：** [net_connection_type.h](capi-net-connection-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t jumpNo | 跳数。 |
| char address[[NETCONN_MAX_STR_LEN]](capi-net-connection-type-h.md#宏定义) | 主机名或地址。 |
| uint32_t rtt[[NETCONN_MAX_RTT_NUM]](capi-net-connection-type-h.md#宏定义) | 往返时间（单位：毫秒）。 |