# NetConn_NetCapabilities


## 概述

网络能力集。

**起始版本：** 11

**相关模块：**[NetConnection](_net_connection.md)

**所在头文件：** [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [linkUpBandwidthKbps](#linkupbandwidthkbps) | 上行带宽。 | 
| [linkDownBandwidthKbps](#linkdownbandwidthkbps) | 下行带宽。 | 
| [netCaps](#netcaps) [NETCONN_MAX_CAP_SIZE] | 网络能力列表。 | 
| [netCapsSize](#netcapssize) | 网络能力列表的实际size。 | 
| [bearerTypes](#bearertypes) [NETCONN_MAX_BEARER_TYPE_SIZE] | 承载类型列表。 | 
| [bearerTypesSize](#bearertypessize) | 承载类型列表的实际size。 | 


## 结构体成员变量说明


### bearerTypes

```
NetConn_NetBearerType NetConn_NetCapabilities::bearerTypes[NETCONN_MAX_BEARER_TYPE_SIZE]
```

**描述**

承载类型列表。


### bearerTypesSize

```
int32_t NetConn_NetCapabilities::bearerTypesSize
```

**描述**

承载类型列表的实际size。


### linkDownBandwidthKbps

```
uint32_t NetConn_NetCapabilities::linkDownBandwidthKbps
```

**描述**

下行带宽。


### linkUpBandwidthKbps

```
uint32_t NetConn_NetCapabilities::linkUpBandwidthKbps
```

**描述**

上行带宽。


### netCaps

```
NetConn_NetCap NetConn_NetCapabilities::netCaps[NETCONN_MAX_CAP_SIZE]
```

**描述**

网络能力列表。


### netCapsSize

```
int32_t NetConn_NetCapabilities::netCapsSize
```

**描述**

网络能力列表的实际size。
