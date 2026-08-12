# net_ethernet_type.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->


## 概述

为以太网网卡模块C接口定义数据结构。

**引用文件：** <network/netmanager_ext/net_ethernet_type.h>

**库：** libnet_ethernet.so

**系统能力：** SystemCapability.Communication.NetManager.Ethernet

**起始版本：** 26.0.0

**相关模块：** [NetEthernet](capi-netethernet.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Ethernet_MacAddressInfo](capi-netethernet-ethernet-macaddressinfo.md) | Ethernet_MacAddressInfo | 以太网网卡MAC地址信息。 |
| [Ethernet_MacAddrInfoList](capi-netethernet-ethernet-macaddrinfolist.md) | Ethernet_MacAddrInfoList | 以太网网卡MAC地址信息列表。 |
| [Ethernet_NetAddr](capi-netethernet-ethernet-netaddr.md) | Ethernet_NetAddr | 网络地址。 |
| [Ethernet_NetAddrInfo](capi-netethernet-ethernet-netaddrinfo.md) | Ethernet_NetAddrInfo | 以太网网卡网络地址信息，包含以太网网卡名称及网络地址信息。 |
| [Ethernet_NetAddrList](capi-netethernet-ethernet-netaddrlist.md) | Ethernet_NetAddrList | 以太网网卡网络地址列表。 |

### 宏定义

| 名称 | 描述 |
| -- | -- |
| ETHERNET_MAX_NET_SIZE 32 | 以太网网卡最大连接数量。<br>**起始版本：** 26.0.0 |
| ETHERNET_MAX_STR_LEN 256 | 以太网网卡MAC地址、IP地址最大长度。<br>**起始版本：** 26.0.0 |

