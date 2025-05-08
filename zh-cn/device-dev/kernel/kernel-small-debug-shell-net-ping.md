# ping


## 命令功能

ping命令用于测试网络连接是否正常。


## 命令格式

ping _[-4] [-c cnt] [-f] [-i interval] [-q] [-s size] &lt;IP&gt;_


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| --help | 查看ping命令支持的参数列表。 | N/A | 
| -4 | 强制以IPV4通讯协议ping目标地址。 | 0-65500 | 
| -c&nbsp;CNT | 执行的次数，不带本参数则默认为3次。 | 1-65535 | 
| -f | 隐式的ping&nbsp;IPv4地址，其默认参数配置等价于"-c&nbsp;15&nbsp;-i&nbsp;0.2"。 | N/A | 
| -i&nbsp;interval | 发送两次ping包的时间间隔，单位毫秒。 | 1-200 | 
| -q | 隐式的ping&nbsp;IPv4地址，如果主机还存活，则在返回&nbsp;true&nbsp;后停止ping。 | N/A | 
| -s&nbsp;SIZE | 设置每个ping包的大小，SIZE是以字节为单位的数据（默认为56字节）。 | 0-4088 | 
| IP | 要测试是否网络连通的IPv4地址。 | N/A | 


## 使用指南

- ping命令用来测试到目的IP的网络连接是否正常，参数为目的IP地址。

- 如果目的IP不可达，会显示请求超时。

- 如果显示发送错误，说明没有到目的IP的路由。

- 命令需要启动TCP/IP协议栈后才能使用。


## 使用实例

举例：输入ping 192.168.1.3。


## 输出说明

**示例** ping tftp 服务器地址。

```
OHOS:/$ ping 192.168.1.3
Ping 192.168.1.3 (192.168.1.3): 56(84) bytes.
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=0 ms
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=1 ms
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=0 ms
--- 192.168.1.3 ping statistics ---
3 packets transmitted, 3 received, 0% packet loss
round-trip min/avg/max = 0/0/0 ms
```
