# 网络连接管理

网络连接管理提供管理网络一些基础能力，包括获取默认激活的数据网络、获取所有激活数据网络列表、开启关闭飞行模式、获取网络能力信息等功能。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import connection from '@ohos.net.connection'
```

## connection.getDefaultNet

getDefaultNet(callback: AsyncCallback\<NetHandle>): void

获取默认激活的数据网络，使用callback方式作为异步方法。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络的类型、拥有的能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | 是   | 回调函数。 |

**示例：**

```js
connection.getDefaultNet(function (error, netHandle) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(netHandle))
})
```

## connection.getDefaultNet

getDefaultNet(): Promise\<NetHandle>

获取默认激活的数据网络，使用Promise方式作为异步方法。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络的类型、拥有的能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetHandle](#nethandle)> | 以Promise形式返回默认激活的数据网络。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    console.log(JSON.stringify(netHandle))
})
```

## connection.getDefaultNetSync

getDefaultNetSync(): NetHandle;

使用同步方法获取默认激活的数据网络。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络的类型、拥有的能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| NetHandle | 以同步方式返回默认激活的数据网络。 |

**示例：**

```js
let netHandle = connection.getDefaultNetSync();
```

## connection.hasDefaultNet

hasDefaultNet(callback: AsyncCallback\<boolean>): void

检查默认数据网络是否被激活，使用callback方式作为异步方法。如果有默认数据网路，可以使用[getDefaultNet](#connectiongetdefaultnet)去获取。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，默认数据网络被激活返回true。 |

**示例：**

```js
connection.hasDefaultNet(function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
```

## connection.hasDefaultNet

hasDefaultNet(): Promise\<boolean>

检查默认数据网络是否被激活，使用Promise方式作为异步方法。如果有默认数据网路，可以使用[getDefaultNet](#connectiongetdefaultnet)去获取。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | 以Promise形式返回，默认数据网络被激活返回true。 |

**示例：**

```js
connection.hasDefaultNet().then(function (has) {
    console.log('has: ' + has)
})
```

## connection.getAllNets

getAllNets(callback: AsyncCallback&lt;Array&lt;NetHandle&gt;&gt;): void

获取所有处于连接状态的网络列表，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | 是 | 回调函数。 |

**示例：**

```js
connection.getAllNets(function (error, nets) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(nets))
});
```


## connection.getAllNets

getAllNets(): Promise&lt;Array&lt;NetHandle&gt;&gt;

获取所有处于连接状态的网络列表，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | 以Promise形式返回激活的数据网络列表。 |

**示例：**

```js
connection.getAllNets().then(function (nets) {
    console.log(JSON.stringify(nets))
});
```

## connection.getConnectionProperties

getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void

获取netHandle对应的网络的连接信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明             |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                                      | 是   | 数据网络的句柄。 |
| callback  | AsyncCallback\<[ConnectionProperties](#connectionproperties)> | 是   | 回调函数。       |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.getConnectionProperties(netHandle, function (error, info) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(info))
    })
})
```

## connection.getConnectionProperties

getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>

获取netHandle对应的网络的连接信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                                    | 说明                              |
| ------------------------------------------------------- | --------------------------------- |
| Promise\<[ConnectionProperties](#connectionproperties)> | 以Promise形式返回网络的连接信息。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.getConnectionProperties(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void

获取netHandle对应的网络的能力信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                | 必填 | 说明             |
| --------- | --------------------------------------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                             | 是   | 数据网络的句柄。 |
| callback  | AsyncCallback\<[NetCapabilities](#netcapabilities)> | 是   | 回调函数。       |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.getNetCapabilities(netHandle, function (error, info) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(info))
    })
})
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>

获取netHandle对应的网络的能力信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                          | 说明                              |
| --------------------------------------------- | --------------------------------- |
| Promise\<[NetCapabilities](#netcapabilities)> | 以Promise形式返回网络的能力信息。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.getNetCapabilities(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

向网络管理报告网络处于可用状态，调用此接口说明应用程序认为网络的可用性（ohos.net.connection.NetCap.NET_CAPABILITY_VAILDATED）与网络管理不一致。
使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 数据网络的句柄，参考[NetHandle](#nethandle)。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.reportNetConnected(netHandle, function (error) {
        console.log(JSON.stringify(error))
    });
});
```


## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle): Promise&lt;void&gt;

向网络管理报告网络处于可用状态，调用此接口说明应用程序认为网络的可用性（ohos.net.connection.NetCap.NET_CAPABILITY_VAILDATED）与网络管理不一致。
使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 数据网络的句柄，参考[NetHandle](#nethandle)。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回值的Promise对象。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.reportNetConnected(netHandle).then(function () {
        console.log(`report success`)
    });
});
```


## connection.reportNetDisconnected

reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

向网络管理报告网络处于不可用状态，调用此接口说明应用程序认为网络的可用性（ohos.net.connection.NetCap.NET_CAPABILITY_VAILDATED）与网络管理不一致。
使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 数据网络的句柄，参考[NetHandle](#nethandle)。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.reportNetDisconnected(netHandle, function (error) {
        console.log(JSON.stringify(error))
    });
});
```


## connection.reportNetDisconnected

reportNetDisconnected(netHandle: NetHandle): Promise&lt;void&gt;

向网络管理报告网络处于不可用状态，调用此接口说明应用程序认为网络的可用性（ohos.net.connection.NetCap.NET_CAPABILITY_VAILDATED）与网络管理不一致。
使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 数据网络的句柄，参考[NetHandle](#nethandle)。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回值的Promise对象。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.reportNetDisconnected(netHandle).then(function () {
        console.log(`report success`)
    });
});
```

## connection.getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

使用默认网络解析主机名以获取所有IP地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明               |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| host     | string                                            | 是   | 需要解析的主机名。 |
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | 是   | 回调函数。         |

**示例：**

```js
let host = "xxxx";
connection.getAddressesByName(host, function (error, addresses) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(addresses))
})
```

## connection.getAddressesByName

getAddressesByName(host: string): Promise\<Array\<NetAddress>>

使用默认网络解析主机名以获取所有IP地址，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | 以Promise形式返回所有IP地址。 |

**示例：**

```js
let host = "xxxx";
connection.getAddressesByName(host).then(function (addresses) {
    console.log(JSON.stringify(addresses))
})
```


## connection.enableAirplaneMode

enableAirplaneMode(callback: AsyncCallback\<void>): void

开启飞行模式，使用callback方式作为异步方法。

该接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明               |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。         |

**示例：**

```js
connection.enableAirplaneMode(function (error) {
    console.log(JSON.stringify(error))
})
```

## connection.enableAirplaneMode

enableAirplaneMode(): Promise\<void>

开启飞行模式，使用Promise方式作为异步方法。

该接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**示例：**

```js
connection.enableAirplaneMode().then(function (error) {
    console.log(JSON.stringify(error))
})
```


## connection.disableAirplaneMode

disableAirplaneMode(callback: AsyncCallback\<void>): void

关闭飞行模式，使用callback方式作为异步方法。

该接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明               |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。         |

**示例：**

```js
connection.disableAirplaneMode(function (error) {
    console.log(JSON.stringify(error))
})
```

## connection.disableAirplaneMode

disableAirplaneMode(): Promise\<void>

关闭飞行模式，使用Promise方式作为异步方法。

该接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**示例：**

```js
connection.disableAirplaneMode().then(function (error) {
    console.log(JSON.stringify(error))
})
```


## connection.createNetConnection

createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection

返回一个NetConnection对象，netSpecifier指定关注的网络的各项特征，timeout是超时时间(单位是毫秒)，netSpecifier是timeout的必要条件，两者都没有则表示关注默认网络。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| netSpecifier | [NetSpecifier](#netspecifier) | 否   | 指定网络的各项特征，不指定则关注默认网络。                   |
| timeout      | number                        | 否   | 获取netSpecifier指定的网络时的超时时间，仅netSpecifier存在时生效。 |

**返回值：**

| 类型                            | 说明                 |
| ------------------------------- | -------------------- |
| [NetConnection](#netconnection) | 所关注的网络的句柄。 |

**示例：**

```js
// 关注默认网络
let netConnection = connection.createNetConnection()

// 关注蜂窝网络
let netConnectionCellular = connection.createNetConnection({
    netCapabilities: {
        bearerTypes: [connection.NetBearType.BEARER_CELLULAR]
    }
})
```

## NetConnection

网络连接的句柄。

### on('netAvailable')

on(type: 'netAvailable', callback: Callback\<NetHandle>): void

订阅网络可用事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | 是   | 订阅事件，固定为'netAvailable'。<br>netAvailable：数据网络可用事件。 |
| callback | Callback\<[NetHandle](#nethandle)> | 是   | 回调函数。                                                   |

**示例：**

```js
netConnection.on('netAvailable', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netCapabilitiesChange')

on(type: 'netCapabilitiesChange', callback: Callback<{ netHandle: NetHandle, netCap: NetCapabilities }>): void

订阅网络能力变化事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netCapabilitiesChange'。<br/>netCapabilitiesChange：网络能力变化事件。 |
| callback | Callback<{ netHandle: [NetHandle](#nethandle), netCap: [NetCapabilities](#netcapabilities) }> | 是   | 回调函数。                                                   |

**示例：**

```js
netConnection.on('netCapabilitiesChange', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netConnectionPropertiesChange')

on(type: 'netConnectionPropertiesChange', callback: Callback<{ netHandle: NetHandle, connectionProperties: ConnectionProperties }>): void

订阅网络连接信息变化事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netConnectionPropertiesChange'。<br/>netConnectionPropertiesChange：网络连接信息变化事件。 |
| callback | Callback<{ netHandle: [NetHandle](#nethandle), connectionProperties: [ConnectionProperties](#connectionproperties) }> | 是   | 回调函数。                                                   |

**示例：**

```js
netConnection.on('netConnectionPropertiesChange', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netBlockStatusChange')

on(type: 'netBlockStatusChange', callback: Callback&lt;{ netHandle: NetHandle, blocked: boolean }&gt;): void

订阅网络阻塞状态事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netBlockStatusChange'。<br/>netBlockStatusChange：网络阻塞状态事件。 |
| callback | Callback&lt;{&nbsp;netHandle:&nbsp;[NetHandle](#nethandle),&nbsp;blocked:&nbsp;boolean&nbsp;}&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
netConnection.on('netBlockStatusChange', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netLost')

on(type: 'netLost', callback: Callback\<NetHandle>): void

订阅网络丢失事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | 是   | 订阅事件，固定为'netLost'。<br/>netLost：网络严重中断或正常断开事件。 |
| callback | Callback\<[NetHandle](#nethandle)> | 是   | 回调函数。                                                   |

**示例：**

```js
let netConnection1 = connection.createNetConnection()
netConnection1.on('netLost', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netUnavailable')

on(type: 'netUnavailable', callback: Callback\<void>): void

订阅网络不可用事件。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | 是   | 订阅事件，固定为'netUnavailable'。<br/>netUnavailable：网络不可用事件。 |
| callback | Callback\<void> | 是   | 回调函数。                                                   |

**示例：**

```js
netConnection.on('netUnavailable', function (data) {
    console.log(JSON.stringify(data))
})
```

### register

register(callback: AsyncCallback\<void>): void

订阅指定网络状态变化的通知。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。 |

**示例：**

```js
netConnection.register(function (error) {
    console.log(JSON.stringify(error))
})
```

### unregister

unregister(callback: AsyncCallback\<void>): void

取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。 |

**示例：**

```js
netConnection.unregister(function (error) {
    console.log(JSON.stringify(error))
})
```

## NetHandle

数据网络的句柄。

在调用NetHandle的方法之前，需要先获取NetHandle对象。

**系统能力**：SystemCapability.Communication.NetManager.Core

### 属性

| 参数名 | 类型   | 说明                      |
| ------ | ------ | ------------------------- |
| netId  | number | 网络ID，取值为0代表没有默认网络，其余取值必须大于等于100。 |


### bindSocket

bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void;

将TCPSocket或UDPSocket绑定到当前网络，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                            |
| ----------- | ------------------------ | ---- | -------------------------------|
| socketParam | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | 是 | 待绑定的TCPSocket或UDPSocket对象。|
| callback    | AsyncCallback\<void>      | 是   | 回调函数                        |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    var tcp = socket.constructTCPSocketInstance();
    var udp = socket.constructUDPSocketInstance();
    let socketType = "xxxx";
    if (socketType == "TCPSocket") {
        tcp.bind({
            address: "xxxx", port: xxxx, family: xxxx
        }, err => {
            netHandle.bindSocket(tcp, function (error, data) {
            console.log(JSON.stringify(error))
            console.log(JSON.stringify(data))
        })
    } else {
        udp.on('message', callback);
        udp.bind({
            address: "xxxx", port: xxxx, family: xxxx
        }, err => {
            udp.on('message', (data) => {
            console.log(JSON.stringify(data))
            });
            netHandle.bindSocket(udp, function (error, data) {
            console.log(JSON.stringify(error))
            console.log(JSON.stringify(data))
            });
        })
     }
}
```

### bindSocket

bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;

将TCPSocket或UDPSockett绑定到当前网络，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名          | 类型                  | 必填  | 说明                           |
| --------------- | --------------------- | ---- | ------------------------------ |
| socketParam     | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | 是   | 待绑定的TCPSocket或UDPSocket对象。|

**返回值：**

| 类型           | 说明                   |
| -------------- | ---------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    var tcp = socket.constructTCPSocketInstance();
    var udp = socket.constructUDPSocketInstance();
    let socketType = "xxxx";
    if(socketType == "TCPSocket") {
        tcp.bind({
            address: "xxxx", port: xxxx, family: xxxx
        }, err => {
            netHandle.bindSocket(tcp).then(err, data) {
            console.log(JSON.stringify(data))
        })
    } else {
        udp.on('message', callback);
        udp.bind({
            address: "xxxx", port: xxxx, family: xxxx
        }, err => {
            udp.on('message', (data) => {
            console.log(JSON.stringify(data))
            });
            netHandle.bindSocket(tcp).then(err, data) {
            console.log(JSON.stringify(data))
            });
        })
     }
}
```

### getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

使用对应网络解析主机名以获取所有IP地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明               |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| host     | string                                            | 是   | 需要解析的主机名。 |
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | 是   | 回调函数           |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    let host = "xxxx";
    netHandle.getAddressesByName(host, function (error, addresses) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(addresses))
    })
})
```

### getAddressesByName

getAddressesByName(host: string): Promise\<Array\<NetAddress>>

使用对应网络解析主机名以获取所有IP地址，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | 以Promise形式返回所有IP地址。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    let host = "xxxx";
    netHandle.getAddressesByName(host).then(function (addresses) {
        console.log(JSON.stringify(addresses))
    })
})
```

### getAddressByName

getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void

使用对应网络解析主机名以获取第一个IP地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明               |
| -------- | ----------------------------------------- | ---- | ------------------ |
| host     | string                                    | 是   | 需要解析的主机名。 |
| callback | AsyncCallback\<[NetAddress](#netaddress)> | 是   | 回调函数。         |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    let host = "xxxx";
    netHandle.getAddressByName(host, function (error, address) {
        console.log(JSON.stringify(error))
        console.log(JSON.stringify(address))
    })
})
```

### getAddressByName

getAddressByName(host: string): Promise\<NetAddress>

使用对应网络解析主机名以获取第一个IP地址，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。 |

**返回值：**

| 类型                                | 说明                            |
| ----------------------------------- | ------------------------------- |
| Promise\<[NetAddress](#netaddress)> | 以Promise形式返回第一个IP地址。 |

**示例：**

```js
connection.getDefaultNet().then(function (netHandle) {
    let host = "xxxx";
    netHandle.getAddressByName(host).then(function (address) {
        console.log(JSON.stringify(address))
    })
})
```

## NetSpecifier

提供承载数据网络能力的实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                  | 类型                                | 说明                                                         |
| ----------------------- | ----------------------------------- | ------------------------------------------------------------ |
| netCapabilities         | [NetCapabilities](#netcapabilities) | 存储数据网络的传输能力和承载类型。                           |
| bearerPrivateIdentifier | string                              | 网络标识符，Wi-Fi网络的标识符是"wifi"，蜂窝网络的标识符是"slot0"（对应SIM卡1）。 |

## NetCapabilities

网络的能力集。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                | 类型                               | 说明                     |
| --------------------- | ---------------------------------- | ------------------------ |
| linkUpBandwidthKbps   | number                             | 上行（设备到网络）带宽。 |
| linkDownBandwidthKbps | number                             | 下行（网络到设备）带宽。 |
| networkCap            | Array<[NetCap](#netcap)>           | 网络具体能力。           |
| bearerTypes           | Array<[NetBearType](#netbeartype)> | 网络类型。               |

## NetCap

网络具体能力。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                  | 值   | 说明                   |
| ------------------------ | ---- | ---------------------- |
| NET_CAPABILITY_MMS | 0 | 表示网络可以访问运营商的MMSC（Multimedia&nbsp;Message&nbsp;Service，多媒体短信服务）发送和接收彩信。 |
| NET_CAPABILITY_NOT_METERED | 11 | 表示网络流量未被计费。 |
| NET_CAPABILITY_INTERNET  | 12   | 表示该网络应具有访问Internet的能力，该能力由网络提供者设置。 |
| NET_CAPABILITY_NOT_VPN | 15 | 表示网络不使用VPN（Virtual&nbsp;Private&nbsp;Network，虚拟专用网络）。 |
| NET_CAPABILITY_VALIDATED | 16   | 表示该网络访问Internet的能力被网络管理成功验证，该能力由网络管理模块设置。 |

## NetBearType

网络类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 名称         | 值   | 说明        |
| --------------- | ---- | ----------- |
| BEARER_CELLULAR | 0    | 蜂窝网络。  |
| BEARER_WIFI     | 1    | Wi-Fi网络。 |
| BEARER_ETHERNET | 3 | 以太网网络。 |

## ConnectionProperties

网络连接信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名       | 类型                               | 说明             |
| ------------- | ---------------------------------- | ---------------- |
| interfaceName | string                             | 网卡名称。       |
| domains       | string                             | 所属域，默认""。 |
| linkAddresses | Array<[LinkAddress](#linkaddress)> | 链路信息。       |
| routes        | Array<[RouteInfo](#routeinfo)>     | 路由信息。       |
| dnses | Array&lt;[NetAddress](#netaddress)&gt; | 网络地址，参考[NetAddress](#netaddress)。 |
| mtu           | number                             | 最大传输单元。   |

## LinkAddress

网络链路信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名       | 类型                      | 说明                 |
| ------------ | ------------------------- | -------------------- |
| address      | [NetAddress](#netaddress) | 链路地址。           |
| prefixLength | number                    | 链路地址前缀的长度。 |

## RouteInfo

网络路由信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名         | 类型                        | 说明             |
| -------------- | --------------------------- | ---------------- |
| interface      | string                      | 网卡名称。       |
| destination    | [LinkAddress](#linkaddress) | 目的地址。       |
| gateway        | [NetAddress](#netaddress)   | 网关地址。       |
| hasGateway     | boolean                     | 是否有网关。     |
| isDefaultRoute | boolean                     | 是否为默认路由。 |

## NetAddress

网络地址。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名  | 类型   | 说明                           |
| ------- | ------ | ------------------------------ |
| address | string | 地址。                         |
| family  | number | IPv4 = 1，IPv6 = 2，默认IPv4。 |
| port    | number | 端口，取值范围\[0, 65535]。    |
