# net_ethernet.h

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->


## 概述

为以太网网卡模块提供C接口。

**引用文件：** <network/netmanager_ext/net_ethernet.h>

**库：** libnet_ethernet.so

**系统能力：** SystemCapability.Communication.NetManager.Ethernet

**起始版本：** 26.0.0

**相关模块：** [netmanager_ext](capi-netethernet.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_Ethernet_GetMacAddress(Ethernet_MacAddrInfoList *macAddrList)](#oh_ethernet_getmacaddress) | 获取以太网网卡MAC地址列表。 |
| [int32_t OH_Ethernet_GetNetAddress(Ethernet_NetAddrList *netAddrList)](#oh_ethernet_getnetaddress) | 获取以太网网卡IP地址列表。 |

## 函数说明

### OH_Ethernet_GetMacAddress()

```c
int32_t OH_Ethernet_GetMacAddress(Ethernet_MacAddrInfoList *macAddrList)
```

**描述**

获取以太网网卡MAC地址列表。

**系统能力：** SystemCapability.Communication.NetManager.Ethernet

**需要权限：** ohos.permission.GET_ETHERNET_LOCAL_MAC

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Ethernet_MacAddrInfoList](capi-netethernet-ethernet-macaddrinfolist.md) *macAddrList | 以太网网卡MAC地址列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         2200001 - 参数错误。 2200002 - 无法连接到服务。<br>         2201005 - 设备信息不存在。 |

### OH_Ethernet_GetNetAddress()

```c
int32_t OH_Ethernet_GetNetAddress(Ethernet_NetAddrList *netAddrList)
```

**描述**

获取以太网网卡IP地址列表。

**系统能力：** SystemCapability.Communication.NetManager.Ethernet

**需要权限：** ohos.permission.GET_NETWORK_INFO

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Ethernet_NetAddrList](capi-netethernet-ethernet-netaddrlist.md) *netAddrList | 以太网网卡IP地址列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 0 - 成功。 201 - 缺少权限。<br>         2200001 - 参数错误。 2200002 - 无法连接到服务。<br>         2201005 - 设备信息不存在。 |


