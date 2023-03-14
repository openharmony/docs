# netstat


## 命令功能

netstat是控制台命令,是一个监测TCP/IP网络的非常有用的工具，它可以显示实际的网络连接以及每一个网络接口设备的状态信息。netstat用于显示与TCP、UDP协议相关的统计数据，一般用于检验本设备（单板）各端口的网络连接情况。


## 命令格式

netstat


## 参数说明

无


## 使用指南

netstat

## 特殊说明

shell端暂不支持。

## 使用实例

举例：输入netstat


## 输出说明

**示例** netstat 打印信息

```
OHOS # netstat
========== total sockets 128 ======  unused sockets 119 ==========
Proto   Recv-Q      Send-Q      Local Address           Foreign Address         State
tcp     0           0           192.168.1.10:578        192.168.1.3:2049        ESTABLISHED
tcp     0           0           192.168.1.10:58653      0.0.0.0:0               LISTEN
tcp     0           0           192.168.1.10:58652      0.0.0.0:0               LISTEN
tcp     0           0           192.168.1.10:58651      0.0.0.0:0               LISTEN
Proto   Recv-Q      Send-Q      Local Address           Foreign Address
udp     0           0           127.0.0.1:62177         127.0.0.1:62178
udp     0           0           0.0.0.0:5684            0.0.0.0:0
udp     0           0           127.0.0.1:62179         127.0.0.1:62180
udp     0           0           127.0.0.1:62180         127.0.0.1:62179
udp     0           0           127.0.0.1:62178         127.0.0.1:62177
```

**表1** 输出说明

| 输出                 | 说明                                                         |
| -------------------- | ------------------------------------------------------------ |
| Proto                | 协议类型。                                                   |
| Recv-Q               | 未被用户读取的数据量。<br/>对于Listen&nbsp;TCP，此值为已完成三次握手，但是未被用户accept的TCP连接的数量。 |
| Send-Q               | 对TCP连接，已发送但未确认的数据量。<br/>对UDP连接，由于IP地址解析未完成而缓存的数据量。 |
| Local&nbsp;Address   | 本地地址和端口。                                             |
| Foreign&nbsp;Address | 远程地址和端口。                                             |
| State                | TCP连接状态，UDP此项无意义。                                 |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 形如“========== total sockets 32 ====== unused sockets 22 BootTime 27 s ========== ”，表示一共32个套接字，未使用套接字22个，距系统启动已经过27秒。