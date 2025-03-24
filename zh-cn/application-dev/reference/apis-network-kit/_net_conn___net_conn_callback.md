# NetConn_NetConnCallback

## 概述

网络状态监听回调集合。

**起始版本：** 12

**相关模块：**[NetConnection](_net_connection.md)


## 汇总

### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [onNetworkAvailable](#onnetworkavailable) | 网络可用回调。 |
| [onNetCapabilitiesChange](#onnetcapabilitieschange) | 网络能力集变更回调。 |
| [onConnetionProperties](#onconnetionproperties) | 网络连接属性变更回调。 |
| [onNetLost](#onnetlost) | 网络断开回调。 |
| [onNetUnavailable](#onnetunavailable) | 网络不可用回调，在指定的超时时间内网络未激活时触发该回调，如果未设置超时时间则不会触发该回调。 |


## 结构体成员变量说明


### onNetworkAvailable

```
typedef void (*OH_NetConn_NetworkAvailable)(NetConn_NetHandle *netHandle)
```

**描述**

网络可用回调。

**说明**

回调结束后参数内存会自动释放，不应保存参数指针。

**参数:**

| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| netHandle |[NetHandle](js-apis-net-connection.md#nethandle) | 网络句柄 |

### onNetCapabilitiesChange

```
typedef void (*OH_NetConn_NetCapabilitiesChange)(NetConn_NetHandle *netHandle, NetConn_NetCapabilities *netCapabilities)
```

**描述**

网络能力集变更回调。

**说明**

回调结束后参数内存会自动释放，不应保存参数指针。

**参数:**

| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| netHandle | [NetHandle](js-apis-net-connection.md#nethandle) | 网络句柄 |
| netCapabilities | [NetCapabilities](js-apis-net-connection.md#netcapabilities)| 网络能力集 |

### onConnetionProperties

```
typedef void (*OH_NetConn_NetConnectionPropertiesChange)(NetConn_NetHandle *netHandle, NetConn_ConnectionProperties *connConnetionProperties)
```

**描述**

网络连接属性变更回调。

**说明**

回调结束后参数内存会自动释放，不应保存参数指针。

**参数:**

| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| netHandle |[NetHandle](js-apis-net-connection.md#nethandle) | 网络句柄 |
| connConnetionProperties | [ConnectionProperties](js-apis-net-connection.md#connectionproperties)| 网络连接属性 |

### onNetLost

```
typedef void (*OH_NetConn_NetLost)(NetConn_NetHandle *netHandle)
```

**描述**

网络断开回调。

**说明**

回调结束后参数内存会自动释放，不应保存参数指针。

**参数:**

| 名称 | 类型 | 描述 |
| -------- | -------- | -------- |
| netHandle |[NetHandle](js-apis-net-connection.md#nethandle)| 网络句柄 |

### onNetUnavailable

```
typedef void (*OH_NetConn_NetUnavailable)(void)
```

**描述**

网络不可用回调，在指定的超时时间内网络未激活时触发该回调，如果未设置超时时间则不会触发该回调。
