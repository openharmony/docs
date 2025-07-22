# NetConn_TraceRouteInfo

## 概述

路由结果。

**起始版本：** 12

**相关模块：**[NetConnection](_net_connection.md)

**所在头文件：** [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [jumpNo](#jumpNo) | 当前路由跳数。 |
| [address[NETCONN_MAX_STR_LEN];](#address[NETCONN_MAX_STR_LEN];) | 当前路由地址。 |
| [rtt[NETCONN_MAX_RTT_NUM]](#rtt[NETCONN_MAX_RTT_NUM) | 探测结果。 |


## 结构体成员变量说明


### jumpNo

```
uint8_t jumpNo;
```

**描述**

当前路由跳数。

### address

```
char address[NETCONN_MAX_STR_LEN];
```

**描述**

当前路由地址。

### rtt

```
uint32_t rtt[NETCONN_MAX_RTT_NUM];
```

**描述**

时延结果，rtt数组，共计4个rtt成员：
rtt[0] - rttMin: 探测过程中的最小rtt值；
rtt[1] - rttMax: 探测过程中的最大rtt值；
rtt[2] - rttAvg: 探测过程中的平均rtt值；
rtt[3] - rttStd: 探测过程中的rtt标准差。
