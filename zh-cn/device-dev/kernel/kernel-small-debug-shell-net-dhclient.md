# dhclient


## 命令功能

设置和查看dhclient的参数。


## 命令格式

- dhclient &lt;_netif name_&gt;

- dhclient -x &lt;_netif name_&gt;


## 参数说明

**表1** 参数说明

| 参数                            | 参数说明                                     | 取值范围         |
| ------------------------------- | -------------------------------------------- | ---------------- |
| -h&nbsp;\|&nbsp;--help          | 查看dhclient命令支持的参数列表，及使用方式。 | N/A              |
| &lt;netif&nbsp;name&gt;         | 启动对应网卡的dhcp请求。                     | 网卡名字，eth0。 |
| -x&nbsp;&lt;netif&nbsp;name&gt; | 关闭对应网卡的dhcp功能。                     | 网卡名字，eth0。 |


## 使用指南

举例：

- dhclient eth0

- dhclient -x eth0

## 特殊说明

shell端暂不支持。

## 使用实例

**示例1** 启动网卡eth0的dhcp请求


```
OHOS:/$ dhclient eth0
OHOS:/$ ifconfig
lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
        ip6: ::1/64
        HWaddr 00 MTU:0 Running Link UP
eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
        HWaddr 42:da:81:bc:58:94 MTU:1500 Running Default Link UP
OHOS:/$
```


**示例2** 关闭网卡eth0的dhcp请求


```
OHOS:/$ dhclient -x eth0
NetifStatusCallback(eth0): nsc event: 0xf0
OHOS:/$ ifconfig
lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
        ip6: ::1/64
        HWaddr 00 MTU:0 Running Link UP
eth0    ip:0.0.0.0 netmask:0.0.0.0 gateway:0.0.0.0
        HWaddr 42:da:81:bc:58:94 MTU:1500 Running Default Link UP
```