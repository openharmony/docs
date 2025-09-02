# NetConn_NetCapabilities

## 概述

网络能力集。

**起始版本：** 11

**相关模块：** [NetConnection](capi-netconnection.md)

**所在头文件：** [net_connection_type.h](capi-net-connection-type-h.md)

## 汇总

### 成员变量

| 名称                                                                                                                   | 描述 |
|------------------------------------------------------------------------------------------------------------------------| -- |
| uint32_t linkUpBandwidthKbps                                                                                           | 上行带宽。 |
| uint32_t linkDownBandwidthKbps                                                                                         | 下行带宽。 |
| [NetConn_NetCap](capi-net-connection-type-h.md#netconn_netcap) netCaps[[NETCONN_MAX_CAP_SIZE]](capi-net-connection-type-h.md#宏定义)                           | 网络能力列表。 |
| int32_t netCapsSize                                                                                                    | 网络能力列表的实际size。 |
| [NetConn_NetBearerType](capi-net-connection-type-h.md#netconn_netbearertype) bearerTypes[[NETCONN_MAX_BEARER_TYPE_SIZE]](capi-net-connection-type-h.md#宏定义) | 承载类型列表 |
| int32_t bearerTypesSize                                                                                                | 承载类型列表的实际size |
