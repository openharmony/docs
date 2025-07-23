# NetConn_ProbeResultInfo

## 概述

探测结果。

**起始版本：** 20

**相关模块：** [NetConnection](capi-netconnection.md)

**所在头文件：**  [net_connection_type.h](capi-net-connection-type-h.md)

## 汇总


### 常量定义
NETCONN_MAX_RTT_NUM = 4
<br>指定rtt个数
### 成员变量




## 结构体成员变量说明


### lossRate

```
NetConn_ProbeResultInfo::lossRate
```
**描述**<br>
丢包率，百分制，值100表示100%丢包；50表示50%丢包
### rtt
```
NetConn_ProbeResultInfo::rtt[NETCONN_MAX_RTT_NUM]
```
**描述**

时延结果，rtt数组，共计4个rtt成员：<br>
rtt[0] - rttMin: 探测过程中的最小rtt值；<br>
rtt[1] - rttMax: 探测过程中的最大rtt值；<br>
rtt[2] - rttAvg: 探测过程中的平均rtt值；<br>
rtt[3] - rttStd: 探测过程中的rtt标准差；