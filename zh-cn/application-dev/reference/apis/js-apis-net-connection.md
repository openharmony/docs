# @ohos.net.connection (网络连接管理)

网络连接管理提供管理网络一些基础能力，包括获取默认激活的数据网络、获取所有激活数据网络列表、开启关闭飞行模式、获取网络能力信息等功能。

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import connection from '@ohos.net.connection'
```

## connection.createNetConnection<sup>8+</sup>

createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection

返回一个NetConnection对象，netSpecifier指定关注的网络的各项特征；timeout是超时时间(单位是毫秒)；netSpecifier是timeout的必要条件，两者都没有则表示关注默认网络。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| netSpecifier | [NetSpecifier](#netspecifier) | 否   | 指定网络的各项特征，不指定或为undefined时关注默认网络。                   |
| timeout      | number                        | 否   | 获取netSpecifier指定的网络时的超时时间，仅netSpecifier存在时生效，undefined时默认值为0。 |

**返回值：**

| 类型                            | 说明                 |
| ------------------------------- | -------------------- |
| [NetConnection](#netconnection) | 所关注的网络的句柄。 |

**示例：**

```ts
import connection from '@ohos.net.connection'

// 关注默认网络, 不需要传参
let netConnection = connection.createNetConnection()

// 关注蜂窝网络，需要传入相关网络特征，timeout参数未传入说明未使用超时时间，此时timeout为0
let netConnectionCellular = connection.createNetConnection({
  netCapabilities: {
    bearerTypes: [connection.NetBearType.BEARER_CELLULAR]
  }
})
```

## connection.getDefaultNet<sup>8+</sup>

getDefaultNet(callback: AsyncCallback\<NetHandle>): void

获取默认激活的数据网络，使用callback方式作为异步方法。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络的类型、拥有的能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | 是   | 回调函数。当成功获取默认激活的数据网络时，error为undefined，data为默认激活的数据网络；否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getDefaultNet((error: BusinessError, data: connection.NetHandle) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## connection.getDefaultNet<sup>8+</sup>

getDefaultNet(): Promise\<NetHandle>

获取默认激活的数据网络，使用Promise方式作为异步方法。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络的类型、拥有的能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetHandle](#nethandle)> | 以Promise形式返回默认激活的数据网络。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
connection.getDefaultNet().then((data: connection.NetHandle) => {
  console.log(JSON.stringify(data))
})
```

## connection.getDefaultNetSync<sup>9+</sup>

getDefaultNetSync(): NetHandle

使用同步方法获取默认激活的数据网络。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络的类型、拥有的能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| NetHandle | 以同步方式返回默认激活的数据网络。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

let netHandle = connection.getDefaultNetSync();
```

## connection.getGlobalHttpProxy<sup>10+</sup>

getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void

获取网络的全局代理配置信息，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[HttpProxy](#httpproxy10)> | 是   | 回调函数。当成功获取网络的全局代理配置信息时，error为undefined，data为网络的全局代理配置信息；否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 202     | Non-system applications use system APIs.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getGlobalHttpProxy((error: BusinessError, data: connection.HttpProxy) => {
  console.info(JSON.stringify(error));
  console.info(JSON.stringify(data));
})
```

## connection.getGlobalHttpProxy<sup>10+</sup>

getGlobalHttpProxy(): Promise\<HttpProxy>;

获取网络的全局代理配置信息，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[HttpProxy](#httpproxy10)> | 以Promise形式返回网络的全局代理配置信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 202     | Non-system applications use system APIs.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getGlobalHttpProxy().then((data: connection.HttpProxy) => {
  console.info(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.info(JSON.stringify(error));
})
```

## connection.setGlobalHttpProxy<sup>10+</sup>

setGlobalHttpProxy(httpProxy: HttpProxy, callback: AsyncCallback\<void>): void

设置网络全局Http代理配置信息，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                         |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| httpProxy | [HttpProxy](#httpproxy10) | 是   | 网络全局Http代理配置信息                                     |
| callback  | AsyncCallback\<void>    | 是   | 回调函数。当成功设置网络全局Http代理配置信息时，error为undefined，否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 202     | Non-system applications use system APIs.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base';

let exclusionStr = "192.168,baidu.com"
let exclusionArray = exclusionStr.split(',');
connection.setGlobalHttpProxy({
  host: "192.168.xx.xxx",
  port: 8080,
  exclusionList: exclusionArray
} as connection.HttpProxy).then(() => {
  console.info("success");
}).catch((error: BusinessError) => {
  console.info(JSON.stringify(error));
});
```

## connection.setGlobalHttpProxy<sup>10+</sup>

setGlobalHttpProxy(httpProxy: HttpProxy): Promise\<void>;

设置网络全局Http代理配置信息，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明             |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| httpProxy | [HttpProxy](#httpproxy10)                                      | 是   | 网络全局Http代理配置信息。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 202     | Non-system applications use system APIs.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base';

let exclusionStr = "192.168,baidu.com"
let exclusionArray = exclusionStr.split(',');
connection.setGlobalHttpProxy({
  host: "192.168.xx.xxx",
  port: 8080,
  exclusionList: exclusionArray
} as connection.HttpProxy).then(() => {
  console.info("success");
}).catch((error: BusinessError) => {
  console.info(JSON.stringify(error));
});
```

## connection.getDefaultHttpProxy<sup>10+</sup>

getDefaultHttpProxy(callback: AsyncCallback\<HttpProxy>): void

获取网络默认的代理配置信息。
如果设置了全局代理，则会返回全局代理配置信息。如果进程使用[setAppNet](#connectionsetappnet)绑定到指定[NetHandle](#nethandle)对应的网络，则返回[NetHandle](#nethandle)对应网络的代理配置信息。在其它情况下，将返回默认网络的代理配置信息。
使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[HttpProxy](#httpproxy10)> | 是   | 回调函数。当成功获取网络默认的代理配置信息时，error为undefined，data为网络默认的代理配置信息；否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 2100002  | Operation failed. Cannot connect to service. |
| 2100003  | System internal error.                       |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getDefaultHttpProxy((error: BusinessError, data: connection.HttpProxy) => {
  console.info(JSON.stringify(error));
  console.info(JSON.stringify(data));
})
```

## connection.getDefaultHttpProxy<sup>10+</sup>

getDefaultHttpProxy(): Promise\<HttpProxy>;

获取网络默认的代理配置信息。
如果设置了全局代理，则会返回全局代理配置信息。如果进程使用[setAppNet](#connectionsetappnet)绑定到指定[NetHandle](#nethandle)对应的网络，则返回[NetHandle](#nethandle)对应网络的代理配置信息。在其它情况下，将返回默认网络的代理配置信息。
使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                             | 说明                                      |
| -------------------------------- | ----------------------------------------- |
| Promise<[HttpProxy](#httpproxy10)> | 以Promise形式返回网络默认的代理配置信息。 |

**错误码：**

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 2100002  | Operation failed. Cannot connect to service. |
| 2100003  | System internal error.                       |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getDefaultHttpProxy().then((data: connection.HttpProxy) => {
  console.info(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.info(JSON.stringify(error));
})
```

## connection.getAppNet<sup>9+</sup>

getAppNet(callback: AsyncCallback\<NetHandle>): void

获取App绑定的网络信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | 是   | 回调函数。当成功获取App绑定的网络信息时，error为undefined，data为获取到App绑定的网络信息；否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401 | Parameter error.|
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getAppNet((error: BusinessError, data: connection.NetHandle) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## connection.getAppNet<sup>9+</sup>

getAppNet(): Promise\<NetHandle>;

获取App绑定的网络信息，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetHandle](#nethandle)> | 以Promise形式返回App绑定的网络信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401 | Parameter error.|
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getAppNet().then((data: connection.NetHandle) => {
  console.info(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.info(JSON.stringify(error));
})
```

## connection.getAppNetSync<sup>10+</sup>

getAppNetSync(): NetHandle

使用同步方法获取App绑定的网络信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| [NetHandle](#nethandle8) | 返回APP绑定的数据网络。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

let netHandle = connection.getAppNetSync();
```

## connection.SetAppNet<sup>9+</sup>

setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void

绑定App到指定网络，绑定后的App只能通过指定网络访问外网，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                         |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle) | 是   | 数据网络的句柄。                                             |
| callback  | AsyncCallback\<void>    | 是   | 回调函数。当成功绑定App到指定网络时，error为undefined，否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getDefaultNet((error: BusinessError, netHandle: connection.NetHandle) => {
  connection.setAppNet(netHandle, (error: BusinessError, data: void) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  });
})
```

## connection.SetAppNet<sup>9+</sup>

setAppNet(netHandle: NetHandle): Promise\<void>;

绑定App到指定网络，绑定后的App只能通过指定网络访问外网，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明             |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                                      | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.setAppNet(netHandle).then(() => {
    console.log("success")
  }).catch((error: BusinessError) => {
    console.log(JSON.stringify(error))
  })
})
```

## connection.getAllNets<sup>8+</sup>

getAllNets(callback: AsyncCallback&lt;Array&lt;NetHandle&gt;&gt;): void

获取所有处于连接状态的网络列表，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | 是 | 回调函数。当成功获取所有处于连接状态的网络列表时，error为undefined，data为激活的数据网络列表；否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getAllNets((error: BusinessError, data: connection.NetHandle[]) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
}); 
```

## connection.getAllNets<sup>8+</sup>

getAllNets(): Promise&lt;Array&lt;NetHandle&gt;&gt;

获取所有处于连接状态的网络列表，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | 以Promise形式返回激活的数据网络列表。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

connection.getAllNets().then((data: connection.NetHandle[]) => {
  console.log(JSON.stringify(data))
});
```

## connection.getAllNetsSync<sup>10+</sup>

getAllNetsSync(): Array&lt;NetHandle&gt;

使用同步方法获取所有处于连接状态的网络列表。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| Array&lt;[NetHandle](#nethandle8)&gt; | 返回激活的数据网络列表。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

let netHandle = connection.getAllNetsSync();
```

## connection.getConnectionProperties<sup>8+</sup>

getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void

获取netHandle对应的网络的连接信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                                      | 是   | 数据网络的句柄。                                             |
| callback  | AsyncCallback\<[ConnectionProperties](#connectionproperties)> | 是   | 回调函数。当成功获取netHandle对应的网络的连接信息时，error为undefined，data为获取的网络连接信息；否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.getConnectionProperties(netHandle, (error: BusinessError, data: connection.ConnectionProperties) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  })
})
```

## connection.getConnectionProperties<sup>8+</sup>

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

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.getConnectionProperties(netHandle).then((data: connection.ConnectionProperties) => {
    console.log(JSON.stringify(data))
  })
})
```

## connection.getConnectionPropertiesSync<sup>10+</sup>

getConnectionPropertiesSync(netHandle: NetHandle): ConnectionProperties

获取netHandle对应的网络的连接信息，使用同步方法返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle8) | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                                    | 说明                              |
| ------------------------------------------------------- | --------------------------------- |
| [ConnectionProperties](#connectionproperties8) | 返回网络的连接信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

let netHandle = connection.getDefaultNetSync();
let connectionproperties = connection.getConnectionPropertiesSync(netHandle);
```

## connection.getNetCapabilities<sup>8+</sup>

getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void

获取netHandle对应的网络的能力信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                | 必填 | 说明                                                         |
| --------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                             | 是   | 数据网络的句柄。                                             |
| callback  | AsyncCallback\<[NetCapabilities](#netcapabilities)> | 是   | 回调函数。当成功获取netHandle对应的网络的能力信息时，error为undefined，data为获取到的网络能力信息；否则为错误对象 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.getNetCapabilities(netHandle, (error: BusinessError, data: connection.NetCapabilities) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  })
})
```

## connection.getNetCapabilities<sup>8+</sup>

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

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.getNetCapabilities(netHandle).then((data: connection.NetCapabilities) => {
    console.log(JSON.stringify(data))
  })
})
```

## connection.getNetCapabilitiesSync<sup>10+</sup>

getNetCapabilitiesSync(netHandle: NetHandle): NetCapabilities

获取netHandle对应的网络的能力信息，使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle8) | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                          | 说明                              |
| --------------------------------------------- | --------------------------------- |
| [NetCapabilities](#netcapabilities8) | 返回网络的能力信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

let netHandle = connection.getDefaultNetSync();
let getNetCapabilitiesSync = connection.getNetCapabilitiesSync(netHandle);
```

## connection.isDefaultNetMetered<sup>9+</sup>

isDefaultNetMetered(callback: AsyncCallback\<boolean>): void

检查当前网络上的数据流量使用是否被计量，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。当前网络上的数据流量使用被计量返回true。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.isDefaultNetMetered((error: BusinessError, data: boolean) => {
  console.log(JSON.stringify(error))
  console.log('data: ' + data)
})
```

## connection.isDefaultNetMetered<sup>9+</sup>

isDefaultNetMetered(): Promise\<boolean>

检查当前网络上的数据流量使用是否被计量，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | 以Promise形式返回，当前网络上的数据流量使用被计量true。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

connection.isDefaultNetMetered().then((data: boolean) => {
  console.log('data: ' + data)
})
```

## connection.isDefaultNetMeteredSync<sup>10+</sup>

isDefaultNetMeteredSync(): boolean

检查当前网络上的数据流量使用是否被计量，使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| boolean | 当前网络上的数据流量使用被计量true。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

let isMetered = connection.isDefaultNetMeteredSync();
```

## connection.hasDefaultNet<sup>8+</sup>

hasDefaultNet(callback: AsyncCallback\<boolean>): void

检查默认数据网络是否被激活，使用callback方式作为异步方法。如果有默认数据网路，可以使用[getDefaultNet](#connectiongetdefaultnet)去获取。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。默认数据网络被激活返回true。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.hasDefaultNet((error: BusinessError, data: boolean) => {
  console.log(JSON.stringify(error))
  console.log('data: ' + data)
})
```

## connection.hasDefaultNet<sup>8+</sup>

hasDefaultNet(): Promise\<boolean>

检查默认数据网络是否被激活，使用Promise方式作为异步方法。如果有默认数据网路，可以使用[getDefaultNet](#connectiongetdefaultnet)去获取。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | 以Promise形式返回，默认数据网络被激活返回true。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
connection.hasDefaultNet().then((data: boolean) => {
  console.log('data: ' + data)
})
```

## connection.hasDefaultNetSync<sup>10+</sup>

hasDefaultNetSync(): boolean

检查默认数据网络是否被激活，使用同步方式返回接口，如果被激活则返回true。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| boolean | 默认数据网络被激活返回true。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

let isDefaultNet = connection.hasDefaultNetSync();
```

## connection.enableAirplaneMode<sup>8+</sup>

enableAirplaneMode(callback: AsyncCallback\<void>): void

开启飞行模式，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明               |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。         |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.              |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.enableAirplaneMode((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

## connection.enableAirplaneMode<sup>8+</sup>

enableAirplaneMode(): Promise\<void>

开启飞行模式，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.              |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

connection.enableAirplaneMode().then((error: void) => {
  console.log(JSON.stringify(error))
})
```

## connection.disableAirplaneMode<sup>8+</sup>

disableAirplaneMode(callback: AsyncCallback\<void>): void

关闭飞行模式，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明               |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当关闭飞行模式成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.              |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.disableAirplaneMode((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

## connection.disableAirplaneMode<sup>8+</sup>

disableAirplaneMode(): Promise\<void>

关闭飞行模式，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.              |
| 401     | Parameter error.               |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

connection.disableAirplaneMode().then((error: void) => {
  console.log(JSON.stringify(error))
})
```

## connection.reportNetConnected<sup>8+</sup>

reportNetConnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

向网络管理报告网络处于可用状态，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 数据网络的句柄，参考[NetHandle](#nethandle)。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向网络管理报告网络处于可用状态成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from '@ohos.base'

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.reportNetConnected(netHandle, (error: BusinessError) => {
    console.log(JSON.stringify(error))
  });
});
```

## connection.reportNetConnected<sup>8+</sup>

reportNetConnected(netHandle: NetHandle): Promise&lt;void&gt;

向网络管理报告网络处于可用状态，使用Promise方式作为异步方法。

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

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.reportNetConnected(netHandle).then(() => {
    console.log(`report success`)
  });
});
```

## connection.reportNetDisconnected<sup>8+</sup>

reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

向网络管理报告网络处于不可用状态，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 数据网络的句柄，参考[NetHandle](#nethandle)。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向网络管理报告网络处于不可用状态成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.reportNetDisconnected(netHandle).then( () => {
    console.log(`report success`)
  });
});
```

## connection.reportNetDisconnected<sup>8+</sup>

reportNetDisconnected(netHandle: NetHandle): Promise&lt;void&gt;

向网络管理报告网络处于不可用状态，使用Promise方式作为异步方法。

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

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.reportNetDisconnected(netHandle).then( () => {
    console.log(`report success`)
  });
});
```

## connection.getAddressesByName<sup>8+</sup>

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

使用默认网络解析主机名以获取所有IP地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| host     | string                                            | 是   | 需要解析的主机名。                                           |
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | 是   | 回调函数。当使用默认网络解析主机名成功获取所有IP地址，error为undefined，data为获取到的所有IP地址；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"
connection.getAddressesByName("xxxx", (error: BusinessError, data: connection.NetAddress[]) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## connection.getAddressesByName<sup>8+</sup>

getAddressesByName(host: string): Promise\<Array\<NetAddress>>

使用默认网络解析主机名以获取所有IP地址，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | 以Promise形式返回所有IP地址。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
connection.getAddressesByName("xxxx").then((data: connection.NetAddress[]) => {
  console.log(JSON.stringify(data))
})
```

## NetConnection

网络连接的句柄。

> **说明：**
> 设备从无网络到有网络会触发netAvailable事件、netCapabilitiesChange事件和netConnectionPropertiesChange事件；
> 设备从有网络到无网络状态会触发netLost事件；
> 设备从WiFi到蜂窝会触发netLost事件（WiFi丢失）之后触发 netAvaliable事件（蜂窝可用）；

### register<sup>8+</sup>

register(callback: AsyncCallback\<void>): void

订阅指定网络状态变化的通知。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当订阅指定网络状态变化的通知成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |
| 2101008 | The same callback exists.     |
| 2101022 | The number of requests exceeded the maximum. |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"
let netCon: connection.NetConnection = connection.createNetConnection();
netCon.register((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

### unregister<sup>8+</sup>

unregister(callback: AsyncCallback\<void>): void

取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当取消订阅指定网络状态变化的通知成功，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201 | Permission denied.|
| 401 | Parameter error.         |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |
| 2101007 | The callback is not exists.      |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"
let netCon: connection.NetConnection = connection.createNetConnection();
netCon.unregister((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

### on('netAvailable')<sup>8+</sup>

on(type: 'netAvailable', callback: Callback\<NetHandle>): void

订阅网络可用事件。

**模型约束**：此接口调用之前需要先调用register接口，使用unregister取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | 是   | 订阅事件，固定为'netAvailable'。<br>netAvailable：数据网络可用事件。 |
| callback | Callback\<[NetHandle](#nethandle)> | 是   | 回调函数，返回数据网络句柄。|

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"

// 创建NetConnection对象
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册订阅事件
netCon.register((error: BusinessError) => {
  console.log(JSON.stringify(error))
})

// 订阅网络可用事件。调用register后，才能接收到此事件通知
netCon.on('netAvailable', (data: connection.NetHandle) => {
  console.log(JSON.stringify(data))
})

// 使用unregister接口取消订阅
netCon.unregister((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

### on('netBlockStatusChange')<sup>8+</sup>

on(type: 'netBlockStatusChange', callback: Callback&lt;{ netHandle: NetHandle, blocked: boolean }&gt;): void

订阅网络阻塞状态事件，使用callback方式作为异步方法。

**模型约束**：此接口调用之前需要先调用register接口，使用unregister取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netBlockStatusChange'。<br/>netBlockStatusChange：网络阻塞状态事件。 |
| callback | Callback&lt;{&nbsp;netHandle:&nbsp;[NetHandle](#nethandle),&nbsp;blocked:&nbsp;boolean&nbsp;}&gt; | 是   | 回调函数，返回数据网络句柄(netHandle),及网络堵塞状态(blocked)。|

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"

// 创建NetConnection对象
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册订阅事件
netCon.register((error: BusinessError) => {
  console.log(JSON.stringify(error))
})

// 订阅网络可用事件。调用register后，才能接收到此事件通知
class Value {
    netHandle: NetHandle = connection.NetHandle
    blocked: boolean = false
}
netCon.on('netBlockStatusChange', (data: Value) => {
  console.log(JSON.stringify(data))
})

// 使用unregister接口取消订阅
netCon.unregister((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

### on('netCapabilitiesChange')<sup>8+</sup>

on(type: 'netCapabilitiesChange', callback: Callback\<NetCapabilityInfo>): void

订阅网络能力变化事件。

**模型约束**：此接口调用之前需要先调用register接口，使用unregister取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netCapabilitiesChange'。<br/>netCapabilitiesChange：网络能力变化事件。 |
| callback | Callback<[NetCapabilityInfo](#netcapabilityinfo)> | 是   | 回调函数，返回数据网络句柄(netHandle)和网络的能力信息(netCap)。|

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"

// 创建NetConnection对象
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册订阅事件
netCon.register((error: BusinessError) => {
  console.log(JSON.stringify(error))
})

// 订阅网络可用事件。调用register后，才能接收到此事件通知
netCon.on('netAvailable', (data: connection.NetHandle) => {
  console.log(JSON.stringify(data))
})

// 使用unregister接口取消订阅
netCon.unregister((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

### on('netConnectionPropertiesChange')<sup>8+</sup>

on(type: 'netConnectionPropertiesChange', callback: Callback<{ netHandle: NetHandle, connectionProperties:
ConnectionProperties }>): void

订阅网络连接信息变化事件。

**模型约束**：此接口调用之前需要先调用register接口，使用unregister取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netConnectionPropertiesChange'。<br/>netConnectionPropertiesChange：网络连接信息变化事件。 |
| callback | Callback<{ netHandle: [NetHandle](#nethandle), connectionProperties: [ConnectionProperties](#connectionproperties) }> | 是   | 回调函数，返回数据网络句柄(netHandle)和网络的连接信息(connectionProperties)|

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"

// 创建NetConnection对象
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册订阅事件
netCon.register((error: BusinessError) => {
  console.log(JSON.stringify(error))
})

class Value {
    netHandle: NetHandle = connection.NetHandle
    connectionProperties: ConnectionProperties = connection.ConnectionProperties
}

// 订阅网络可用事件。调用register后，才能接收到此事件通知
netCon.on('netConnectionPropertiesChange', (data: Value) => {
  console.log(JSON.stringify(data))
})

// 使用unregister接口取消订阅
netCon.unregister((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

### on('netLost')<sup>8+</sup>

on(type: 'netLost', callback: Callback\<NetHandle>): void

订阅网络丢失事件。

**模型约束**：此接口调用之前需要先调用register接口，使用unregister取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | 是   | 订阅事件，固定为'netLost'。<br/>netLost：网络严重中断或正常断开事件。 |
| callback | Callback\<[NetHandle](#nethandle)> | 是   | 回调函数，数据网络句柄(netHandle)|

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"

// 创建NetConnection对象
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册订阅事件
netCon.register((error: BusinessError) => {
  console.log(JSON.stringify(error))
})

// 订阅网络可用事件。调用register后，才能接收到此事件通知
netCon.on('netLost', (data: connection.NetHandle) => {
  console.log(JSON.stringify(data))
})

// 使用unregister接口取消订阅
netCon.unregister((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

### on('netUnavailable')<sup>8+</sup>

on(type: 'netUnavailable', callback: Callback\<void>): void

订阅网络不可用事件。

**模型约束**：此接口调用之前需要先调用register接口，使用unregister取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | 是   | 订阅事件，固定为'netUnavailable'。<br/>netUnavailable：网络不可用事件。 |
| callback | Callback\<void> | 是   | 回调函数，无返回结果。|

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"

// 创建NetConnection对象
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册订阅事件
netCon.register((error: BusinessError) => {
  console.log(JSON.stringify(error))
})

// 订阅网络可用事件。调用register后，才能接收到此事件通知
netCon.on('netAvailable', (data: connection.NetHandle) => {
  console.log(JSON.stringify(data))
})

// 使用unregister接口取消订阅
netCon.unregister((error: BusinessError) => {
  console.log(JSON.stringify(error))
})
```

## NetHandle<sup>8+</sup>

数据网络的句柄。

在调用NetHandle的方法之前，需要先获取NetHandle对象。

**系统能力**：SystemCapability.Communication.NetManager.Core

### 属性

| 名称    | 类型   | 必填 | 说明                      |
| ------ | ------ | --- |------------------------- |
| netId  | number | 是  |  网络ID，取值为0代表没有默认网络，其余取值必须大于等于100。 |

### bindSocket<sup>9+</sup>

bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void

将TCPSocket或UDPSocket绑定到当前网络，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                            |
| ----------- | ------------------------ | ---- | -------------------------------|
| socketParam | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | 是 | 待绑定的TCPSocket或UDPSocket对象。|
| callback    | AsyncCallback\<void>      | 是   | 回调函数。当TCPSocket或UDPSocket成功绑定到当前网络，error为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
import connection from '@ohos.net.connection';
import { BusinessError } from '@ohos.base';

interface Data {
  message: ArrayBuffer,
  remoteInfo: socket.SocketRemoteInfo
}

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  let tcp = socket.constructTCPSocketInstance();
  let udp = socket.constructUDPSocketInstance();
  let socketType = "TCPSocket";
  if (socketType == "TCPSocket") {
    tcp.bind({address:"192.168.xxx.xxx",
              port:8080,
              family:1} as socket.NetAddress, (error: Error) => {
      if (error) {
        console.log('bind fail');
        return;
      }
      netHandle.bindSocket(tcp, (error: BusinessError, data: void) => {
        if (error) {
          console.log(JSON.stringify(error));
        } else {
          console.log(JSON.stringify(data));
        }
      })
    })
  } else {
    let callback: (value: Data) => void = (value: Data) => {
      console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
    }
    udp.bind({address:"192.168.xxx.xxx",
              port:8080,
              family:1} as socket.NetAddress, (error: BusinessError) => {
      if (error) {
        console.log('bind fail');
        return;
      }
      udp.on('message', (data: Data) => {
        console.log(JSON.stringify(data))
      });
      netHandle.bindSocket(udp, (error: BusinessError, data: void) => {
        if (error) {
          console.log(JSON.stringify(error));
        } else {
          console.log(JSON.stringify(data));
        }
      })
    })
  }
})
```

### bindSocket<sup>9+</sup>

bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;

将TCPSocket或UDPSockett绑定到当前网络，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名          | 类型                  | 必填  | 说明                           |
| --------------- | --------------------- | ---- | ------------------------------ |
| socketParam     | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | 是   | 待绑定的TCPSocket或UDPSocket对象。|

**返回值：**

| 类型           | 说明                   |
| -------------- | ---------------------- |
| Promise\<void> | 无返回值的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
import connection from '@ohos.net.connection';
import { BusinessError } from '@ohos.base';
interface Data {
  message: ArrayBuffer,
  remoteInfo: socket.SocketRemoteInfo
}

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  let tcp = socket.constructTCPSocketInstance();
  let udp = socket.constructUDPSocketInstance();
  let socketType = "TCPSocket";
  if (socketType == "TCPSocket") {
    tcp.bind({address:"192.168.xxx.xxx",
              port:8080,
              family:1} as socket.NetAddress, (error: Error) => {
      if (error) {
        console.log('bind fail');
        return;
      }
      netHandle.bindSocket(tcp, (error: BusinessError, data: void) => {
        if (error) {
          console.log(JSON.stringify(error));
        } else {
          console.log(JSON.stringify(data));
        }
      })
    })
  } else {
    let callback: (value: Data) => void = (value: Data) => {
      console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
    }
    udp.bind({address:"192.168.xxx.xxx",
              port:8080,
              family:1} as socket.NetAddress, (error: BusinessError) => {
    if (error) {
      console.log('bind fail');
      return;
    }
    udp.on('message', (data: Data) => {
      console.log(JSON.stringify(data))
    });
    netHandle.bindSocket(udp, (error: BusinessError, data: void) => {
      if (error) {
        console.log(JSON.stringify(error));
      } else {
        console.log(JSON.stringify(data));
      }
    })
  })
}
})
```

### getAddressesByName<sup>8+</sup>

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

使用对应网络解析主机名以获取所有IP地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| host     | string                                            | 是   | 需要解析的主机名。                                           |
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | 是   | 回调函数。当使用对应网络解析主机名成功获取所有IP地址，error为undefined，data为获取到的所有IP地址；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  let host = "xxxx";
  netHandle.getAddressesByName(host, (error: BusinessError, data: connection.NetAddress[]) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  })
})
```

### getAddressesByName<sup>8+</sup>

getAddressesByName(host: string): Promise\<Array\<NetAddress>>

使用对应网络解析主机名以获取所有IP地址，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | 以Promise形式返回所有IP地址。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  let host = "xxxx";
  netHandle.getAddressesByName(host).then((data: connection.NetAddress[]) => {
    console.log(JSON.stringify(data))
  })
})
```

### getAddressByName<sup>8+</sup>

getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void

使用对应网络解析主机名以获取第一个IP地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| host     | string                                    | 是   | 需要解析的主机名。                                           |
| callback | AsyncCallback\<[NetAddress](#netaddress)> | 是   | 回调函数。当使用对应网络解析主机名获取第一个IP地址成功，error为undefined，data为获取的第一个IP地址；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'
import { BusinessError } from "@ohos.base"

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  let host = "xxxx";
  netHandle.getAddressByName(host, (error: BusinessError, data: connection.NetAddress) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  })
}) 
```

### getAddressByName<sup>8+</sup>

getAddressByName(host: string): Promise\<NetAddress>

使用对应网络解析主机名以获取第一个IP地址，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。 |

**返回值：**

| 类型                                | 说明                            |
| ----------------------------------- | ------------------------------- |
| Promise\<[NetAddress](#netaddress)> | 以Promise形式返回第一个IP地址。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import connection from '@ohos.net.connection'

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  let host = "xxxx";
  netHandle.getAddressByName(host).then((data: connection.NetAddress) => {
    console.log(JSON.stringify(data))
  })
})
```

## NetCap<sup>8+</sup>

网络具体能力。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 值   | 说明                   |
| ------------------------ | ---- | ---------------------- |
| NET_CAPABILITY_MMS | 0 | 表示网络可以访问运营商的MMSC（Multimedia&nbsp;Message&nbsp;Service，多媒体短信服务）发送和接收彩信。 |
| NET_CAPABILITY_NOT_METERED | 11 | 表示网络流量未被计费。 |
| NET_CAPABILITY_INTERNET  | 12   | 表示该网络应具有访问Internet的能力，该能力由网络提供者设置。 |
| NET_CAPABILITY_NOT_VPN | 15 | 表示网络不使用VPN（Virtual&nbsp;Private&nbsp;Network，虚拟专用网络）。 |
| NET_CAPABILITY_VALIDATED | 16   | 表示该网络访问Internet的能力被网络管理成功验证，该能力由网络管理模块设置。 |

## NetBearType<sup>8+</sup>

网络类型。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称         | 值   | 说明        |
| --------------- | ---- | ----------- |
| BEARER_CELLULAR | 0    | 蜂窝网络。  |
| BEARER_WIFI     | 1    | Wi-Fi网络。 |
| BEARER_ETHERNET | 3 | 以太网网络。 |

## HttpProxy<sup>10+</sup>

网络代理配置信息

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 必填 | 说明                      |
| ------ | ------ | --- |------------------------- |
| host  | string | 否  |  代理服务器主机名。 |
| port  | number | 否  |  主机端口。 |
| exclusionList  | Array<string> | 否  | 不使用代理的主机名列表，主机名支持域名、IP地址以及通配符形式，详细匹配规则如下：<br/>1、域名匹配规则：<br/>（1）完全匹配：代理服务器主机名只要与列表中的任意一个主机名完全相同，就可以匹配。<br/>（2）包含匹配：代理服务器主机名只要包含列表中的任意一个主机名，就可以匹配。<br/>例如，如果在主机名列表中设置了 “ample.com”，则  “ample.com”、“www.ample.com”、“ample.com:80”都会被匹配，而 “www.example.com”、“ample.com.org”则不会被匹配。<br/>2、IP地址匹配规则：代理服务器主机名只要与列表中的任意一个IP地址完全相同，就可以匹配。<br/>3、域名跟IP地址可以同时添加到列表中进行匹配。<br/>4、单个“*”是唯一有效的通配符，当列表中只有通配符时，将与所有代理服务器主机名匹配，表示禁用代理。通配符只能单独添加，不可以与其他域名、IP地址一起添加到列表中，否则通配符将不生效。<br/>5、匹配规则不区分主机名大小写。<br/>6、匹配主机名时，不考虑http和https等协议前缀。 |

## NetSpecifier<sup>8+</sup>

提供承载数据网络能力的实例。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                     | 类型                                | 必填  | 说明                                                         |
| ----------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| netCapabilities         | [NetCapabilities](#netcapabilities) |  是  | 存储数据网络的传输能力和承载类型。                                |
| bearerPrivateIdentifier | string                              |  否  |  网络标识符，Wi-Fi网络的标识符是"wifi"，蜂窝网络的标识符是"slot0"（对应SIM卡1）。 |

## NetCapabilityInfo<sup>10+</sup>

提供承载数据网络能力的实例。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                     | 类型                                | 必填  | 说明                                                         |
| ----------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle         | [NetHandle](#nethandle) |  是  | 数据网络句柄。                                |
| netCap |  [NetCapabilities](#netcapabilities)       |  否  |  存储数据网络的传输能力和承载类型。 |

## NetCapabilities<sup>8+</sup>

网络的能力集。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 类型                                | 必填 | 说明                     |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| linkUpBandwidthKbps   | number                             |  否 |  上行（设备到网络）带宽，0表示无法评估当前网络带宽。  |
| linkDownBandwidthKbps | number                             |  否 |  下行（网络到设备）带宽，0表示无法评估当前网络带宽。   |
| networkCap            | Array\<[NetCap](#netcap)>           |  否 |  网络具体能力。           |
| bearerTypes           | Array\<[NetBearType](#netbeartype)> |  是 |  网络类型。               |

## ConnectionProperties<sup>8+</sup>

网络连接信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称           | 类型                               | 必填 |  说明             |
| ------------- | ---------------------------------- | ----|---------------- |
| interfaceName | string                             | 是 |网卡名称。       |
| domains       | string                             | 是 |所属域，默认""。 |
| linkAddresses | Array\<[LinkAddress](#linkaddress)> | 是 |链路信息。       |
| routes        | Array\<[RouteInfo](#routeinfo)>     | 是 |路由信息。       |
| dnses     | Array\<[NetAddress](#netaddress)> | 是 |网络地址，参考[NetAddress](#netaddress)。 |
| mtu           | number                             | 是 |最大传输单元。   |

## RouteInfo<sup>8+</sup>

网络路由信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称           | 类型                        | 必填 |说明             |
| -------------- | --------------------------- | --- |---------------- |
| interface      | string                      | 是 |网卡名称。       |
| destination    | [LinkAddress](#linkaddress) | 是 |目的地址。       |
| gateway        | [NetAddress](#netaddress)   | 是 |网关地址。       |
| hasGateway     | boolean                     | 是 |是否有网关。     |
| isDefaultRoute | boolean                     | 是 |是否为默认路由。 |

## LinkAddress<sup>8+</sup>

网络链路信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称        | 类型                      | 必填 |说明                 |
| ------------ | ----------------------- |---- |-------------------- |
| address      | [NetAddress](#netaddress) | 是 | 链路地址。           |
| prefixLength | number                    | 是 |链路地址前缀的长度。 |

## NetAddress<sup>8+</sup>

网络地址。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称 | 类型 | 必填 | 说明 |
| ------- | ------ | -- |------------------------------ |
| address | string | 是 |地址。 |
| family  | number | 否 |IPv4 = 1，IPv6 = 2，默认IPv4。 |
| port    | number | 否 |端口，取值范围\[0, 65535]。 |
