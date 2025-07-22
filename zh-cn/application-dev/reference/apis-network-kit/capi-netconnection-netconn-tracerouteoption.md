# NetConn_TraceRouteOption

## 概述

路由参数选项。

**起始版本：** 20

**相关模块：**[NetConnection](_net_connection.md)

**所在头文件：** [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## 汇总

### 枚举定义

typedef enum NetConn_PacketsType {
    /** ICMP */
    NETCONN_PACKETS_ICMP = 0,
    /** UDP */
    NETCONN_PACKETS_UDP = 1,
} NetConn_PacketsType;

### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [maxJumpNumber](#maxJumpNumber) | 探测结果最大跳数。 |
| [packetsType](#packetsType) | 探测包协议类型。 |


## 结构体成员变量说明


### maxJumpNumber

```
uint8_t maxJumpNumber; 
```

**描述**

探测结果最大跳数，需要和TraceRouteInfo设置一致，最大可设置30跳，默认为30跳。

### packetsType

```
NetConn_PacketsType packetsType;
```

**描述**

探测包协议类型，默认为NETCONN_PACKETS_ICMP。