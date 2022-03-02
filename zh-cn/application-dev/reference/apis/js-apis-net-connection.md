# 网络

> **说明：**
>
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```javascript
import connection from '@ohos.net.connection'
```

## connection.getDefaultNet

getDefaultNet(callback: AsyncCallback\<NetHandle>): void

获取默认网络，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | 是 | 回调函数 |

**示例：**

```javascript
connection.getDefaultNet(function (error, netHandle) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(netHandle))
})
```

## connection.getDefaultNet

getDefaultNet(): Promise\<NetHandle>

获取默认网络，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型 | 说明 |
| ----- | ----- |
| Promise\<[NetHandle](#nethandle)> | 以Promise形式返回 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    console.log(JSON.stringify(netHandle))
})
```

## connection.hasDefaultNet

hasDefaultNet(callback: AsyncCallback\<boolean>): void

判断是否有默认网络，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| callback | AsyncCallback\<boolean> | 是 | 回调函数，有默认网络返回true。 |

**示例：**

```javascript
connection.hasDefaultNet(function (error, has) {
    console.log(JSON.stringify(error))
    console.log(has)
})
```

## connection.hasDefaultNet

hasDefaultNet(): Promise\<boolean>

判断是否有默认网络，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型 | 说明 |
| ----- | ----- |
| Promise\<boolean> | 以Promise形式返回，有默认网络返回true。 |

**示例：**

```javascript
connection.hasDefaultNet().then(function (has) {
    console.log(has)
})
```

## connection.getConnectionProperties

getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void

查询netHandle对应的网络的连接信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| netHandle |  [NetHandle](#nethandle) | 是 | 对应网络 |
| callback | AsyncCallback\<[ConnectionProperties](#connectionproperties)> | 是 | 回调函数 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getConnectionProperties(netHandle, function (error, info) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(info))
    })
})
```

## connection.getConnectionProperties

getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>

查询netHandle对应的网络的连接信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| netHandle |  [NetHandle](#nethandle) | 是 | 对应网络 |

**返回值：**

| 类型 | 说明 |
| ----- | ----- |
| Promise\<[ConnectionProperties](#connectionproperties)> | 以Promise形式返回 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getConnectionProperties(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void

查询netHandle对应的网络的能力信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| netHandle |  [NetHandle](#nethandle) | 是 | 对应网络 |
| callback | AsyncCallback\<[NetCapabilities](#netcapabilities)> | 是 | 回调函数 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getNetCapabilities(netHandle, function (error, info) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(info))
    })
})
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>

查询netHandle对应的网络的能力信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| netHandle |  [NetHandle](#nethandle) | 是 | 对应网络 |

**返回值：**

| 类型 | 说明 |
| ----- | ----- |
| Promise\<[NetCapabilities](#netcapabilities)> | 以Promise形式返回 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getNetCapabilities(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

## connection.getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

使用默认网络将host解析成IP，返回所有IP，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| host | string | 是 | 需要解析的域名 |
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | 是 | 回调函数 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getAddressesByName(netHandle, function (error, info) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(info))
    })
})
```

## connection.getAddressesByName

getAddressesByName(netHandle: NetHandle): Promise\<Array\<NetAddress>>

使用默认网络将host解析成IP，返回所有IP，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| host | string | 是 | 需要解析的域名 |

**返回值：**

| 类型 | 说明 |
| ----- | ----- |
| Promise\<Array\<[NetAddress](#netaddress)>> | 以Promise形式返回 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getAddressesByName(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

## connection.createNetConnection

createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection

获取一个netSpecifier指定的网络的句柄。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| netSpecifier | [NetSpecifier](#netspecifier) | 否 | 指定网络的各项特征，不指定则关注默认网络。 |
| timeout | number | 否 | 获取netSpecifier指定的网络时的超时时间，仅netSpecifier存在时生效。 |

**返回值：**

| 类型 | 说明 |
| ----- | ----- |
|[NetConnection](#netconnection) | 所关注的网络的句柄 |

**示例：**

```javascript
// 关注默认网络
let netConnection1 = connection.createNetConnection()

// 关注蜂窝网络
let netConnection2 = connection.createNetConnection({
    netCapabilities: {
        networkCap: [0]
    }
})
```

## NetConnection

网络连接的句柄

### on('netAvailable')

on(type: 'netAvailable', callback: Callback\<NetHandle>): void

监听网络可用事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| type | string | 是 | 监听的事件，固定'netAvailable' |
| callback | Callback\<[NetHandle](#nethandle)>> | 是 | 回调函数 |

**示例：**

```javascript
connection.createNetConnection().on('netAvailable', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netCapabilitiesChange')

on(type: 'netCapabilitiesChange', callback: Callback<{ netHandle: NetHandle, netCap: NetCapabilities }>): void

监听网络能力变化事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| type | string | 是 | 监听的事件，固定'netCapabilitiesChange' |
| callback | Callback<{ netHandle: [NetHandle](#nethandle), netCap: [NetCapabilities](#netcapabilities) }> | 是 | 回调函数 |

**示例：**

```javascript
connection.createNetConnection().on('netCapabilitiesChange', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netConnectionPropertiesChange')

on(type: 'netConnectionPropertiesChange', callback: Callback<{ netHandle: NetHandle, connectionProperties: ConnectionProperties }>): void

监听网络连接信息变化事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| type | string | 是 | 监听的事件，固定'netConnectionPropertiesChange' |
| callback | Callback<{ netHandle: [NetHandle](#nethandle), connectionProperties: [ConnectionProperties](#connectionproperties) }> | 是 | 回调函数 |

**示例：**

```javascript
connection.createNetConnection().on('netConnectionPropertiesChange', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netLost')

on(type: 'netLost', callback: Callback\<NetHandle>): void

监听网络丢失事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| type | string | 是 | 监听的事件，固定'netLost' |
| callback | Callback\<[NetHandle](#nethandle)>> | 是 | 回调函数 |

**示例：**

```javascript
connection.createNetConnection().on('netLost', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netUnavailable')

on(type: 'netUnavailable', callback: Callback\<void>): void

监听网络不可用事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| type | string | 是 | 监听的事件，固定'netUnavailable' |
| callback | Callback\<void>> | 是 | 回调函数 |

**示例：**

```javascript
connection.createNetConnection().on('netUnavailable', function (data) {
    console.log(JSON.stringify(data))
})
```

### register

register(callback: AsyncCallback\<void>): void

注册网络的监听。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| callback | Callback\<void>> | 是 | 回调函数 |

**示例：**

```javascript
connection.createNetConnection().register(function (error) {
    console.log(JSON.stringify(error))
})
```

### unregister

unregister(callback: AsyncCallback\<void>): void

注销网络的监听。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| callback | Callback\<void>> | 是 | 回调函数 |

**示例：**

```javascript
connection.createNetConnection().unregister(function (error) {
    console.log(JSON.stringify(error))
})
```

## NetHandle

网络的句柄

| 变量 | 类型 | 说明 |
| ----- | ----- | ----- |
| netId | number | 对应网络的编号 |

### getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

使用对应网络将host解析成IP，返回所有IP，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| host | string | 是 | 需要解析的域名 |
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | 是 | 回调函数 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getAddressesByName(netHandle, function (error, info) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(info))
    })
})
```

### getAddressesByName

getAddressesByName(netHandle: NetHandle): Promise\<Array\<NetAddress>>

使用对应网络将host解析成IP，返回所有IP，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| host | string | 是 | 需要解析的域名 |

**返回值：**

| 类型 | 说明 |
| ----- | ----- |
| Promise\<Array\<[NetAddress](#netaddress)>> | 以Promise形式返回 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getAddressesByName(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

### getAddressByName

getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void

使用对应网络将host解析成IP，返回一个IP，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| host | string | 是 | 需要解析的域名 |
| callback | AsyncCallback\<[NetAddress](#netaddress)> | 是 | 回调函数 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getAddressByName(netHandle, function (error, info) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(info))
    })
})
```

### getAddressByName

getAddressByName(netHandle: NetHandle): Promise\<NetAddress>

使用对应网络将host解析成IP，返回一个IP，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ----- | ---- | ----- |
| host | string | 是 | 需要解析的域名 |

**返回值：**

| 类型 | 说明 |
| ----- | ----- |
| Promise\<[NetAddress](#netaddress)> | 以Promise形式返回 |

**示例：**

```javascript
connection.getDefaultNet().then(function (netHandle) {
    connection.getAddressByName(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

## NetSpecifier

网络的特征。

| 变量 | 类型 | 说明 |
| ----- | ----- | ----- |
| netCapabilities | [NetCapabilities](#netcapabilities) | 网络的能力集 |
| bearerPrivateIdentifier | string | 网络标识符，WIFI网络的标识符是"wifi"，蜂窝网络的标识符是"slot0"(对应SIM卡1) |

## NetCapabilities

网络的能力集。

| 变量 | 类型 | 说明 |
| ----- | ----- | ----- |
| linkUpBandwidthKbps | number | 带宽上限 |
| linkDownBandwidthKbps | number | 带宽下限 |
| networkCap | Array<[NetCap](#netcap)> | 网络具体能力 |
| bearerTypes | Array<[NetBearType](#netbearType)> | 网络类型 |

## NetCap

网络具体能力。

| 变量 | 值 | 说明 |
| ------ | ----- | ----- |
| NET_CAPABILITY_INTERNET | 12 | 联网能力 |
| NET_CAPABILITY_VALIDATED | 16 | 网络可用 |

## NetBearType

网络类型。

| 变量 | 值 | 说明 |
| ------ | ----- | ----- |
| BEARER_CELLULAR | 0 | 蜂窝网络 |
| BEARER_WIFI | 1 | WIFI网络 |

## ConnectionProperties

网络连接信息。

| 变量 | 类型 | 说明 |
| ----- | ----- | ----- |
| interfaceName | string | 网卡名称 |
| domains | string | 所属域，默认"" |
| linkAddresses | Array<[LinkAddress](#linkaddress)> | 链路信息 |
| routes | Array<[RouteInfo](#routeinfo)> | 路由信息 |
| mtu | number | 最大传输单元 |

## LinkAddress

网络链路信息。

| 变量 | 类型 | 说明 |
| ----- | ----- | ----- |
| address | [NetAddress](#netaddress) | 链路地址 |
| prefixLength | number | 地址前缀长度 |

## RouteInfo

网络路由信息。

| 变量 | 类型 | 说明 |
| ----- | ----- | ----- |
| interface | string | 网卡名称 |
| destination | [LinkAddress](#linkaddress) | 目的地址 |
| gateway | [NetAddress](#netaddress) | 网关地址 |
| hasGateway | boolean | 是否有网关 |
| isDefaultRoute | boolean | 是否为默认路由 |

## NetAddress

地址。

| 变量 | 类型 | 说明 |
| ----- | ----- | ----- |
| address | string | 一个IPv4地址或者IPv6地址 |
| family | number | IPv4 = 1， IPv6 = 2, 默认IPv4 |
| port | number | 端口，取值范围\[0, 65535] |
