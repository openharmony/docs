# ifconfig


## 命令功能

ifconfig命令用来查询和设置网卡的IP地址、网络掩码、网关、硬件mac地址等参数。并能够启用/关闭网卡。


## 命令格式

ifconfig [option]

option:

- [_-a_]

- &lt;_interface_&gt; &lt;_address_&gt; [_netmask &lt;mask&gt;_] [_gateway &lt;address&gt;_]

- [_hw ether &lt;address&gt;_] [_mtu &lt;size&gt;_]

- [_inet6 add &lt;address&gt;_]

- [_inet6 del &lt;address&gt;_]

- [_up|down_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| 不带参数 | 打印所有网卡的IP地址、网络掩码、网关、硬件mac地址、MTU、运行状态等信息。 | N/A | 
| -a | 打印协议栈收发数据信息。 | N/A | 
| interface | 指定网卡名，比如eth0。 | N/A | 
| address | 设置IP地址，比如192.168.1.10，需指定网卡名。 | N/A | 
| netmask | 设置子网掩码，后面要掩码参数，比如255.255.255.0。 | N/A | 
| gateway | 设置网关，后面跟网关参数，比如192.168.1.1。 | N/A | 
| hw&nbsp;ether | 设置mac地址，&nbsp;后面是MAC地址，比如00:11:22:33:44:55。目前只支持ether硬件类型。 | N/A | 
| mtu | 设置mtu大小，后面是mtu大小，比如1000。 | -&nbsp;仅支持ipv4情况下的范围为<br/>&nbsp;&nbsp;[68,1500]。<br/>-&nbsp;支持ipv6情况下的范围为<br/>&nbsp;&nbsp;[1280,1500]。 | 
| add | 设置ipv6的地址，比如2001:a:b:c:d:e:f:d，需指定网卡名和inet6。 | N/A | 
| del | 删除ipv6的地址，需指定网卡名和加"inet6"选项，详见示例。 | N/A | 
| up | 启用网卡数据处理，需指定网卡名。 | N/A | 
| down | 关闭网卡数据处理，需指定网卡名。 | N/A | 


## 使用指南

- 命令需要启动TCP/IP协议栈后才能使用。

- 由于IP冲突检测需要反应时间，每次使用ifconfig设置IP后会有2S左右的延时。


## 使用实例

- ifconfig eth0 192.168.100.31 netmask 255.255.255.0 gateway 192.168.100.1 hw ether 00:49:cb:6c:a1:31

- ifconfig -a

- ifconfig eth0 inet6 add 2001:a:b:c:d:e:f:d

- ifconfig eth0 inet6 del 2001:a:b:c:d:e:f:d


## 输出说明

- **示例1** 设置网络参数

  ```
  OHOS:/$ ifconfig eth0 192.168.100.31 netmask 255.255.255.0 gateway 192.168.100.1 hw ether 00:49:cb:6c:a1:31
  OHOS:/$ ifconfig
  lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
          ip6: ::1/64
          HWaddr 00 MTU:0 Running Link UP
  eth0    ip:192.168.100.31 netmask:255.255.255.0 gateway:192.168.100.1
          HWaddr 00:49:cb:6c:a1:31 MTU:1500 Running Default Link UP
  ```

  输出的各参数说明如下表所示：

  **表2** 参数说明
  
  | 参数 | 说明 | 
  | -------- | -------- |
  | ip | 板子IP地址。 | 
  | netmask | 网络掩码。 | 
  | gateway | 网关。 | 
  | HWaddr | 板子硬件mac地址。 | 
  | MTU | 网络最大传输单元。 | 
  | Running/Stop | 网卡是否正在运行。 | 
  | Default | 有这项说明此网卡连接到默认网关。 | 
  | Link&nbsp;UP/Down | 网卡连接状态。 | 

- **示例2** 获取协议栈统计信息

  ```
  OHOS # ifconfig -a
  RX packets:6922  errors:0        ip dropped:4312         link dropped:67         overrun:0       bytes:0 (0.0 B)
  RX packets(ip6):3     errors:0        dropped:0       overrun:0       bytes:0 (0.0 B)
  TX packets:1394  errors:0        link dropped:67         overrun:0       bytes:0(0.0 B)
  TX packets(ip6):3     errors:0        overrun:0       bytes:0(0.0 B)
  ```

  输出的各参数说明如下表所示：

**表3** ifconfig -a 参数说明
  
  | 参数 | 说明 | 
  | -------- | -------- |
  | RX&nbsp;packets | IP层已接收的正常数据包的个数。 | 
  | RX&nbsp;error | IP层已接收的错误数据包的个数，错误类型包括长度错误，校验错误，IP&nbsp;option错误，IP首部protocol错误等。 | 
  | RX&nbsp;dropped | IP层已丢弃的数据包的个数，丢弃原因包括数据包错误，封包无法转发，本地网卡处于关闭状态等。 | 
  | RX&nbsp;overrun | MAC层向上层协议栈投递封包失败的个数，失败原因主要是协议栈资源不足。 | 
  | RX&nbsp;bytes | IP层已接收的正常数据包的总长度，不包括重组未完成的分片的长度。 | 
  | TX&nbsp;packets | IP层已正常发送或转发的数据包的个数。 | 
  | TX&nbsp;error | IP层发送失败的数据包的个数，失败原因包括封包无法路由，封包在协议栈内处理失败等。 | 
  | TX&nbsp;dropped | MAC层由于发送失败而丢弃的数据包个数，失败原因包括网卡驱动处理封包失败等。 | 
  | TX&nbsp;overrun | 暂未使用。 | 
  | TX&nbsp;bytes | IP层已正常发送或者转发的数据包的总长度。 | 

- **示例3** 设置IPv6的地址信息

  ```
  OHOS:/$ ifconfig eth0 inet6 add 2001:a:b:c:d:e:f:d
  NetifStatusCallback(eth0): nsc event: 0x8
  NetifStatusCallback(eth0): nsc status changed: 0
  NetifStatusCallback(eth0): nsc event: 0x200
  NetifStatusCallback(eth0): nsc event: 0x8
  NetifStatusCallback(eth0): nsc status changed: 1
  NetifStatusCallback(eth0): nsc event: 0x200
  NetifStatusCallback(eth0): nsc event: 0x200
  OHOS:/$ ifconfig
  lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
          ip6: ::1/64
          HWaddr 00 MTU:0 Running Link UP
  eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
          ip6: 2001:A:B:C:D:E:F:D/64
          HWaddr 66:2f:e5:bd:24:e6 MTU:1500 Running Default Link UP
  ```

- **示例4** 删除IPv6的地址信息

  ```
  OHOS:/$ ifconfig eth0 inet6 del 2001:a:b:c:d:e:f:d
  NetifStatusCallback(eth0): nsc event: 0x200
  OHOS:/$ ifconfig
  lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
          ip6: ::1/64
          HWaddr 00 MTU:0 Running Link UP
  eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
          HWaddr 66:2f:e5:bd:24:e6 MTU:1500 Running Default Link UP
  ```
