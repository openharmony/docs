# @ohos.net.connection (网络连接管理)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

网络连接管理提供管理网络一些基础能力，包括获取默认激活的数据网络、获取所有激活数据网络列表、开启关闭飞行模式、获取网络能力信息等功能。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 无特殊说明，接口默认不支持并发。

## 导入模块

```ts
import { connection } from '@kit.NetworkKit';
```

## connection.createNetConnection

createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection

创建一个NetConnection对象，[netSpecifier](#netspecifier)指定关注的网络的各项特征；timeout是超时时间(单位是毫秒)；netSpecifier是timeout的必要条件，两者都没有则表示关注默认网络。

**注意：** createNetConnection注册回调函数的数量不能超过2000（个），否则无法继续注册网络监听。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| netSpecifier | [NetSpecifier](#netspecifier) | 否   | 指定待关注网络的特征，缺省表示关注默认网络。                   |
| timeout      | number                        | 否   | 获取netSpecifier指定网络时的超时时间，传入值需为uint32_t范围内的整数，仅netSpecifier存在时生效，默认值为0。 |

**返回值：**

| 类型                            | 说明                 |
| ------------------------------- | -------------------- |
| [NetConnection](#netconnection) | 所关注的网络的句柄。 |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

// 关注默认网络, 不需要传参。
let netConnection = connection.createNetConnection();

// 关注蜂窝网络，需要传入相关网络特征，timeout参数未传入说明未使用超时时间，此时timeout为0。
let netConnectionCellular = connection.createNetConnection({
  netCapabilities: {
    bearerTypes: [connection.NetBearType.BEARER_CELLULAR]
  }
});
```

## connection.getDefaultNet

getDefaultNet(callback: AsyncCallback\<NetHandle>): void

异步获取默认激活的数据网络，使用callback方式作为异步方法。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络类型、拥有能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | 是   | 回调函数。当成功获取默认激活的数据网络时，error为undefined，data为默认激活的数据网络；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.                 |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet((error: BusinessError, data: connection.NetHandle) => {
  if (error) {
    console.error(`Failed to get default net. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.info("Succeeded to get data " + JSON.stringify(data));
});
```

## connection.getDefaultNet

getDefaultNet(): Promise\<NetHandle>

异步获取默认激活的数据网络，使用Promise方式作为异步方法。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络的类型、拥有的能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetHandle](#nethandle)> | 以Promise形式返回默认激活的数据网络。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| ------- | -------------------------------- |
| 201     | Permission denied.               |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.           |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getDefaultNet().then((data: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```

## connection.getDefaultNetSync<sup>9+</sup>

getDefaultNetSync(): NetHandle

使用同步方法获取默认激活的数据网络。可以使用[getNetCapabilities](#connectiongetnetcapabilities)去获取网络的类型、拥有的能力等信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| [NetHandle](#nethandle) | 以同步方式返回默认激活的数据网络。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| ------- | -------------------------------- |
| 201     | Permission denied.               |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.           |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

let netHandle = connection.getDefaultNetSync();
```


## connection.setAppHttpProxy<sup>11+</sup>

setAppHttpProxy(httpProxy: HttpProxy): void

设置应用级Http代理配置信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明             |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| httpProxy | [HttpProxy](#httpproxy10)                                      | 是   | 网络应用级Http代理配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                       |
| ------- | -----------------------------  |
| 401     | Parameter error.               |
| 2100001 | Invalid http proxy.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let exclusionStr = "192.168,baidu.com";
let exclusionArray = exclusionStr.split(',');
connection.setAppHttpProxy({
  host: "192.168.xx.xxx",
  port: 8080,
  exclusionList: exclusionArray
} as connection.HttpProxy);
```

## connection.getDefaultHttpProxy<sup>10+</sup>

getDefaultHttpProxy(callback: AsyncCallback\<HttpProxy>): void

获取网络默认的代理配置信息。如果设置了全局代理，则会返回全局代理配置信息。如果进程使用[setAppNet](#connectionsetappnet9)绑定到指定[NetHandle](#nethandle)对应的网络，则返回[NetHandle](#nethandle)对应网络的代理配置信息。在其它情况下，将返回默认网络的代理配置信息。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[HttpProxy](#httpproxy10)> | 是   | 回调函数。当成功获取网络默认的代理配置信息时，error为undefined，data为网络默认的代理配置信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 2100002  | Failed to connect to the service.            |
| 2100003  | System internal error.                       |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultHttpProxy((error: BusinessError, data: connection.HttpProxy) => {
  if (error) {
    console.error(`Failed to get default http proxy. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.log("Succeeded to get data" + JSON.stringify(data));
});
```

## connection.getDefaultHttpProxy<sup>10+</sup>

getDefaultHttpProxy(): Promise\<HttpProxy>

获取网络默认的代理配置信息。如果设置了全局代理，则会返回全局代理配置信息。如果进程使用[setAppNet](#connectionsetappnet9)绑定到指定[NetHandle](#nethandle)对应的网络，则返回[NetHandle](#nethandle)对应网络的代理配置信息。在其它情况下，将返回默认网络的代理配置信息。使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                             | 说明                                      |
| -------------------------------- | ----------------------------------------- |
| Promise<[HttpProxy](#httpproxy10)> | 以Promise形式返回网络默认的代理配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 2100002  | Failed to connect to the service.            |
| 2100003  | System internal error.                       |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultHttpProxy().then((data: connection.HttpProxy) => {
  console.info(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.info(JSON.stringify(error));
});
```

## connection.getAppNet<sup>9+</sup>

getAppNet(callback: AsyncCallback\<NetHandle>): void

异步获取App绑定的网络信息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | 是   | 回调函数。当成功获取App绑定的网络信息时，error为undefined，data为获取到App绑定的网络信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.                 |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getAppNet((error: BusinessError, data: connection.NetHandle) => {
  if (error) {
    console.error(`Failed to get App net. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.info("Succeeded to get data: " + JSON.stringify(data));
})
```

## connection.getAppNet<sup>9+</sup>

getAppNet(): Promise\<NetHandle>

异步获取App绑定的网络信息，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetHandle](#nethandle)> | 以Promise形式返回App绑定的网络信息。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getAppNet().then((data: connection.NetHandle) => {
  console.info(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.info(JSON.stringify(error));
});
```

## connection.getAppNetSync<sup>10+</sup>

getAppNetSync(): NetHandle

使用同步方法获取App绑定的网络信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| [NetHandle](#nethandle) | 返回App绑定的数据网络。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

let netHandle = connection.getAppNetSync();
```

## connection.setAppNet<sup>9+</sup>

setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void

将App异步绑定到特定的网络，绑定后App只能通过netHandle对应的网络访问网络，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                         |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle) | 是   | 数据网络的句柄。                                             |
| callback  | AsyncCallback\<void>    | 是   | 回调函数。当成功绑定App到指定网络时，error为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet((error: BusinessError, netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  connection.setAppNet(netHandle, (error: BusinessError, data: void) => {
    if (error) {
      console.error(`Failed to get default net. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("Succeeded to get data: " + JSON.stringify(data));
  });
});
```

## connection.setAppNet<sup>9+</sup>

setAppNet(netHandle: NetHandle): Promise\<void\>

将App异步绑定到特定的网络，绑定后App只能通过netHandle对应的网络访问网络。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明             |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                                      | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }

  connection.setAppNet(netHandle).then(() => {
    console.log("success");
  }).catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  })
});
```

## connection.getAllNets

getAllNets(callback: AsyncCallback&lt;Array&lt;NetHandle&gt;&gt;): void

获取所有处于连接状态的网络列表，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | 是 | 回调函数。当成功获取所有处于连接状态的网络列表时，error为undefined，data为处于激活状态的数据网络列表；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.                 |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getAllNets((error: BusinessError, data: connection.NetHandle[]) => {
  if (error) {
    console.error(`Failed to get all nets. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.info("Succeeded to get data: " + JSON.stringify(data));
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
| Promise&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | 以Promise形式返回处于激活状态的数据网络列表。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getAllNets().then((data: connection.NetHandle[]) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
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
| Array&lt;[NetHandle](#nethandle)&gt; | 返回所有处于连接状态的数据网络列表。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

let netHandle = connection.getAllNetsSync();
```

## connection.getConnectionProperties

getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void

获取netHandle对应的网络的连接信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                                      | 是   | 数据网络的句柄。                                             |
| callback  | AsyncCallback\<[ConnectionProperties](#connectionproperties)> | 是   | 回调函数。当成功获取netHandle对应的网络的连接信息时，error为undefined，data为获取的网络连接信息；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  connection.getConnectionProperties(netHandle, (error: BusinessError, data: connection.ConnectionProperties) => {
    if (error) {
      console.error(`Failed to get connection properties. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("Succeeded to get data: " + JSON.stringify(data));
  })
});
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

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }

  connection.getConnectionProperties(netHandle).then((data: connection.ConnectionProperties) => {
    console.info("Succeeded to get data: " + JSON.stringify(data));
  })
});
```

## connection.getConnectionPropertiesSync<sup>10+</sup>

getConnectionPropertiesSync(netHandle: NetHandle): ConnectionProperties

获取netHandle对应的网络的连接信息，使用同步方法返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                                    | 说明                              |
| ------------------------------------------------------- | --------------------------------- |
| [ConnectionProperties](#connectionproperties) | 返回网络的连接信息。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netHandle: connection.NetHandle;
let connectionproperties: connection.ConnectionProperties;

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  netHandle = connection.getDefaultNetSync();
  connectionproperties = connection.getConnectionPropertiesSync(netHandle);
  console.info("Succeeded to get connectionproperties: " + JSON.stringify(connectionproperties));
});

```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void

获取netHandle对应网络的能力信息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                | 必填 | 说明                                                         |
| --------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                             | 是   | 数据网络的句柄。                                             |
| callback  | AsyncCallback\<[NetCapabilities](#netcapabilities)> | 是   | 回调函数。当成功获取netHandle对应网络的能力信息时，error为undefined，data为获取到的网络能力信息；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  connection.getNetCapabilities(netHandle, (error: BusinessError, data: connection.NetCapabilities) => {
    if (error) {
      console.error(`Failed to get net capabilities. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("Succeeded to get data: " + JSON.stringify(data));
  })
}).catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
});
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>

获取netHandle对应网络的能力信息，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  connection.getNetCapabilities(netHandle).then((data: connection.NetCapabilities) => {
      console.info("Succeeded to get data: " + JSON.stringify(data));
  })
}).catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
});
```

## connection.getNetCapabilitiesSync<sup>10+</sup>

getNetCapabilitiesSync(netHandle: NetHandle): NetCapabilities

获取netHandle对应网络的能力信息，使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                          | 说明                              |
| --------------------------------------------- | --------------------------------- |
| [NetCapabilities](#netcapabilities) | 返回网络的能力信息。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netHandle: connection.NetHandle;
let getNetCapabilitiesSync: connection.NetCapabilities;

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }

  getNetCapabilitiesSync = connection.getNetCapabilitiesSync(netHandle);
  console.info("Succeeded to get net capabilities sync: " + JSON.stringify(getNetCapabilitiesSync));
});

```

## connection.isDefaultNetMetered<sup>9+</sup>

isDefaultNetMetered(callback: AsyncCallback\<boolean>): void

检查当前网络上的数据流量使用是否被计费（例如：WiFi网络不会被计费，蜂窝网络会被计费）。使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。当前网络上的数据流量是否被计费。true表示会被计费，false表示不会被计费。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.                 |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.isDefaultNetMetered((error: BusinessError, data: boolean) => {
  console.error(JSON.stringify(error));
  console.log('data: ' + data);
});
```

## connection.isDefaultNetMetered<sup>9+</sup>

isDefaultNetMetered(): Promise\<boolean>

检查当前网络上的数据流量使用是否被计费（例如：WiFi网络不会被计费，蜂窝网络会被计费）。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | Promise对象。当前网络上的数据流量是否被计费。true表示会被计费，false表示不会被计费。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| ------- | -------------------------------- |
| 201     | Permission denied.               |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.           |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.isDefaultNetMetered().then((data: boolean) => {
  console.log('data: ' + data);
});
```

## connection.isDefaultNetMeteredSync<sup>10+</sup>

isDefaultNetMeteredSync(): boolean

检查当前网络上的数据流量使用是否被计费（例如：WiFi网络不会被计费，蜂窝网络会被计费）。使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| boolean | 表示当前网络上的数据流量是否被计费。true表示会被计费，false表示不会被计费。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| ------- | -------------------------------- |
| 201     | Permission denied.               |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.           |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

let isMetered = connection.isDefaultNetMeteredSync();
```

## connection.hasDefaultNet

hasDefaultNet(callback: AsyncCallback\<boolean>): void

检查默认数据网络是否被激活，使用callback方式作为异步方法。如果有默认数据网络，可以使用[getDefaultNet](#connectiongetdefaultnet)去获取。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回true表示默认数据网络被激活，返回false表示没有被激活。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.hasDefaultNet((error: BusinessError, data: boolean) => {
  console.error(JSON.stringify(error));
  console.log('data: ' + data);
});
```

## connection.hasDefaultNet

hasDefaultNet(): Promise\<boolean>

检查默认数据网络是否被激活，使用Promise方式作为异步方法。如果有默认数据网络，可以使用[getDefaultNet](#connectiongetdefaultnet)去获取。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | Promise对象。返回true表示默认数据网络被激活，返回false表示没有被激活。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.hasDefaultNet().then((data: boolean) => {
  console.log('data: ' + data);
});
```

## connection.hasDefaultNetSync<sup>10+</sup>

hasDefaultNetSync(): boolean

检查默认数据网络是否被激活，使用同步方式返回接口。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| boolean | 表示默认数据网络是否被激活。true表示默认数据网络被激活，fasle表示默认数据网络没有被激活。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

let isDefaultNet = connection.hasDefaultNetSync();
```


## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

向网络管理上报网络处于可用状态，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 数据网络的句柄，参考[NetHandle](#nethandle)。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向网络管理报告网络处于可用状态成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.reportNetConnected(netHandle, (error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
});
```

## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle): Promise\<void\>

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
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.reportNetConnected(netHandle).then(() => {
    console.log(`report success`);
  });
});
```

## connection.reportNetDisconnected

reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

向网络管理上报网络处于不可用状态，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 数据网络的句柄，参考[NetHandle](#nethandle)。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向网络管理报告网络处于不可用状态成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet((error: BusinessError, netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  connection.reportNetDisconnected(netHandle, (error: BusinessError, data: void) => {
    if (error) {
      console.error(`Failed to get default net. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("report success");
  });
});
```

## connection.reportNetDisconnected

reportNetDisconnected(netHandle: NetHandle): Promise&lt;void&gt;

向网络管理上报网络处于不可用状态，使用Promise方式作为异步方法。

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

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  connection.reportNetDisconnected(netHandle).then( () => {
    console.log(`report success`);
  });
});
```

## connection.getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

使用对应网络解析主机名以获取所有IP地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| host     | string                                            | 是   | 需要解析的主机名。                                           |
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | 是   | 回调函数。当使用默认网络解析主机名成功获取所有IP地址，error为undefined，data为获取到的所有IP地址；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getAddressesByName("xxxx", (error: BusinessError, data: connection.NetAddress[]) => {
  if (error) {
    console.error(`Failed to get addresses. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```

## connection.getAddressesByName

getAddressesByName(host: string): Promise\<Array\<NetAddress\>\>

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

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getAddressesByName("xxxx").then((data: connection.NetAddress[]) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```

## connection.addCustomDnsRule<sup>11+</sup>

addCustomDnsRule(host: string, ip: Array\<string\>, callback: AsyncCallback\<void\>): void

为当前应用程序添加自定义host和对应的IP地址的映射，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| host     | string               | 是   | 需要自定义解析的主机名。                                     |
| ip       | Array\<string>       | 是   | 主机名所映射的IP地址列表。                                   |
| callback | AsyncCallback\<void> | 是   | 回调函数。当为当前应用程序添加自定义host和对应的ip地址的映射成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.addCustomDnsRule("xxxx", ["xx.xx.xx.xx","xx.xx.xx.xx"], (error: BusinessError, data: void) => {
  if (error) {
    console.error(`Failed to get add custom dns rule. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.info("Succeeded to get data: " + JSON.stringify(data));
})
```

## connection.addCustomDnsRule<sup>11+</sup>

addCustomDnsRule(host: string, ip: Array\<string\>): Promise\<void\>

为当前应用程序添加自定义host和对应的IP地址的映射，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型           | 必填 | 说明                       |
| ------ | -------------- | ---- | -------------------------- |
| host   | string         | 是   | 需要自定义解析的主机名。   |
| ip     | Array\<string> | 是   | 主机名所映射的IP地址列表。 |

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.addCustomDnsRule("xxxx", ["xx.xx.xx.xx","xx.xx.xx.xx"]).then(() => {
    console.info("success");
}).catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
})
```

## connection.removeCustomDnsRule<sup>11+</sup>

removeCustomDnsRule(host: string, callback: AsyncCallback\<void\>): void

删除当前应用程序中对应host的自定义DNS规则，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| host     | string               | 是   | 需要删除自定义DNS规则的主机名。                              |
| callback | AsyncCallback\<void> | 是   | 回调函数。当删除当前应用程序中对应host的自定义DNS规则成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.removeCustomDnsRule("xxxx", (error: BusinessError, data: void) => {
  if (error) {
    console.error(`Failed to remove custom dns rule. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.info("Succeeded to get data: " + JSON.stringify(data));
})
```

## connection.removeCustomDnsRule<sup>11+</sup>

removeCustomDnsRule(host: string): Promise\<void\>

删除当前应用程序中对应host的自定义DNS规则，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| host   | string | 是   | 需要删除自定义DNS规则的主机名。 |

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.removeCustomDnsRule("xxxx").then(() => {
    console.log("success");
}).catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
})
```

## connection.clearCustomDnsRules<sup>11+</sup>

clearCustomDnsRules(callback: AsyncCallback\<void\>): void

删除当前应用程序的所有的自定义DNS规则，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当删除当前应用程序的所有的自定义DNS规则成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID| 错误信息                           |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.clearCustomDnsRules((error: BusinessError, data: void) => {
  if (error) {
    console.error(`Failed to clear custom dns rules. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.info("Succeeded to get data: " + JSON.stringify(data));
})
```

## connection.clearCustomDnsRules<sup>11+</sup>

clearCustomDnsRules(): Promise\<void\>

删除当前应用程序的所有的自定义DNS规则，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| Promise\<void\>        | Promise对象。无返回结果的Promise对象。  |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.clearCustomDnsRules().then(() => {
    console.log("success");
}).catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
})
```

## connection.setPacFileUrl<sup>20+</sup>

setPacFileUrl(pacFileUrl: string): void

设置当前PAC脚本的URL地址。通过解析脚本地址可以获取代理信息。

**需要权限**：ohos.permission.SET_PAC_URL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                           |
| ----------- | ------ | ---- | ------------------------------ |
| pacFileUrl  | string | 是   | 当前PAC脚本的URL地址。         |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息     |
|---------|----------|
| 201     | Permission denied.   |
| 2100002 | Failed to connect to the service. |

**示例：**

```typescript
import { connection } from '@kit.NetworkKit';

let pacFileUrl = "http://example.com/proxy.pac";
connection.setPacFileUrl(pacFileUrl);
```
## connection.getPacFileUrl<sup>20+</sup>

getPacFileUrl(): string

获取当前PAC脚本的URL地址。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型 | 说明                                            |
| -------- | ----------------------------------------------- |
| string   | 当前PAC脚本的URL地址，如果没有PAC脚本则返回空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 2100002  | Failed to connect to the service.                 |

**示例：**

```typescript
import { connection } from '@kit.NetworkKit';

let pacFileUrl = connection.getPacFileUrl();
console.info(pacFileUrl);
```

## connection.findProxyForUrl<sup>20+</sup>

findProxyForUrl(url: string): string

根据给定的URL查找PAC代理信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明              |
| ------ | ------ | ---- | ----------------- |
| url    | string | 是   | 要查找代理信息的URL。 |

**返回值：**

| 类型 | 说明                     |
| -------- | ------------------------ |
| string   | 返回代理信息。              |


**示例：**

```typescript
import { connection } from '@kit.NetworkKit';

let proxyInfo = connection.findProxyForUrl("http://example.com");
console.info(proxyInfo);
```

## connection.setPacUrl<sup>15+</sup>

setPacUrl(pacUrl: string): void

设置系统级代理自动配置（Proxy Auto Config，PAC）脚本地址。

**需要权限**：ohos.permission.SET_PAC_URL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| pacUrl   | string                                            | 是   | 需要设置的PAC脚本的地址，该接口不会对脚本地址进行校验。             |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

let pacUrl = "xxx";
connection.setPacUrl(pacUrl);
```

## connection.getPacUrl<sup>15+</sup>

getPacUrl(): string

获取系统级代理自动配置（PAC）脚本地址。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| string        | 返回PAC脚本地址。PAC脚本不存在时，抛出2100003错误码。  |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

let pacUrl = connection.getPacUrl();
```

## connection.setNetExtAttribute<sup>20+</sup>

setNetExtAttribute(netHandle: NetHandle, netExtAttribute: string): Promise\<void\>

为netHandle对应的网络设置扩展属性，标识网络的安全级别。使用Promise异步回调。

> **说明：**
> 该接口所需的权限目前仅支持PC设备。

**需要权限**：ohos.permission.SET_NET_EXT_ATTRIBUTE

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                              | 必填 | 说明                                                         |
| --------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                                         | 是   | 数据网络的句柄。           |
| netExtAttribute | string                                      | 是   | 需要设置的网络扩展属性。                                         |

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| Promise\<void\> | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let netExtAttribute: string = "xxx";
  connection.setNetExtAttribute(netHandle, netExtAttribute).then(() => {
    console.info("setNetExtAttribute success");
  }).catch((error: BusinessError) => {
    console.error("setNetExtAttribute failed, err: " + error.code);
  })
});
```

## connection.setNetExtAttributeSync<sup>20+</sup>

setNetExtAttributeSync(netHandle: NetHandle, netExtAttribute: string): void

使用同步方法为netHandle对应的网络设置扩展属性，标识网络的安全级别。

> **说明：**
> 该接口所需的权限目前仅支持PC设备。

**需要权限**：ohos.permission.SET_NET_EXT_ATTRIBUTE

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                              | 必填 | 说明                                                         |
| --------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                  | 是   | 数据网络的句柄。             |
| netExtAttribute | string                             | 是   | 需要设置的网络扩展属性。      |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netExtAttribute: string = "xxx";
let netHandle = connection.getDefaultNetSync();
if (netHandle.netId != 0) {
  connection.setNetExtAttributeSync(netHandle, netExtAttribute);
}
```

## connection.getNetExtAttribute<sup>20+</sup>

getNetExtAttribute(netHandle: NetHandle): Promise\<string\>

获取netHandle对应网络的扩展属性，以确定网络的安全级别。使用Promise异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                      | 必填 | 说明                           |
| --------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                | 是   | 数据网络的句柄。             |

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| Promise\<string\> | Promise对象。以Promise形式返回的网络扩展属性。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  connection.getNetExtAttribute(netHandle).then((netExtAttribute: string) => {
    console.info("getNetExtAttribute: " + netExtAttribute);
  }).catch((error: BusinessError) => {
    console.error("getNetExtAttribute failed, err: " + error.code);
  })
});
```

## connection.getNetExtAttributeSync<sup>20+</sup>

getNetExtAttributeSync(netHandle: NetHandle): string

使用同步方法获取netHandle对应网络的扩展属性，以确定网络的安全级别。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                              | 必填 | 说明                                                         |
| --------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                   | 是   | 数据网络的句柄。         |

**返回值：**

| 类型   | 说明                     |
| ------ | ----------------------- |
| string | 以同步方式返回的网络扩展属性。|


**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netHandle = connection.getDefaultNetSync();
if (netHandle.netId != 0) {
  let netExtAttribute: string = connection.getNetExtAttributeSync(netHandle);
  console.info("getNetExtAttribute: " + netExtAttribute);
}
```

## NetConnection

网络连接的句柄。

> **说明：**
>
>（1）设备从无网络状态转变为有网络状态时，将触发netAvailable事件、netCapabilitiesChange事件和netConnectionPropertiesChange事件；
>
>（2）接收到netAvailable事件后，若设备从有网络状态转变为无网络状态，将触发netLost事件；
>
>（3）若未接收到netAvailable事件，则将直接接收到netUnavailable事件；
>
>（4）设备从WiFi网络切换至蜂窝网络时，将先触发netLost事件（WiFi丢失），随后触发netAvailable事件（蜂窝可用）。

### register

register(callback: AsyncCallback\<void>): void

订阅指定网络状态变化的通知。

**注意：** 使用完register接口后需要及时调用unregister取消注册。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当订阅指定网络状态变化的通知成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |                       错误信息                       |
| ------- | ---------------------------------------------------- |
| 201     | Permission denied.                                   |
| 401     | Parameter error.                                     |
| 2100002 | Failed to connect to the service.                    |
| 2100003 | System internal error.                               |
| 2101008 | The callback already exists.                         |
| 2101022 | The number of requests exceeded the maximum allowed. |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netCon: connection.NetConnection = connection.createNetConnection();
netCon.register((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

### unregister

unregister(callback: AsyncCallback\<void>): void

取消订阅默认网络状态变化的通知。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当取消订阅指定网络状态变化的通知成功，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 401     | Parameter error.                  |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |
| 2101007 | The callback does not exist.      |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netCon: connection.NetConnection = connection.createNetConnection();
netCon.unregister((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

### on('netAvailable')

on(type: 'netAvailable', callback: Callback\<NetHandle>): void

订阅网络可用事件。此接口调用之前需要先调用register接口，不需要网络状态变化回调通知时，使用unregister取消订阅默认网络状态变化的通知。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | 是   | 订阅事件，固定为'netAvailable'。<br>netAvailable：数据网络可用事件。 |
| callback | Callback\<[NetHandle](#nethandle)> | 是   | 回调函数，返回数据网络句柄。|

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 创建NetConnection对象。
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册网络状态变化事件。
netCon.register((error: BusinessError) => {
  console.error(JSON.stringify(error));
});

// 订阅网络可用事件。调用register后，才能接收到此事件通知。
netCon.on('netAvailable', (data: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 使用unregister接口取消订阅网络可用事件。
netCon.unregister((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

### on('netBlockStatusChange')

on(type: 'netBlockStatusChange', callback: Callback\<NetBlockStatusInfo>): void

订阅网络阻塞状态事件。此接口调用之前需要先调用register接口，不需要网络状态变化回调通知时，使用unregister取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netBlockStatusChange'。<br/>netBlockStatusChange：网络阻塞状态事件。 |
| callback | Callback<[NetBlockStatusInfo](#netblockstatusinfo11)>        | 是   | 回调函数，获取网络阻塞状态信息。|

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 创建NetConnection对象。
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册网络状态变化事件。
netCon.register((error: BusinessError) => {
  console.error(JSON.stringify(error));
});

// 订阅网络阻塞状态事件。调用register后，才能接收到此事件通知。
netCon.on('netBlockStatusChange', (data: connection.NetBlockStatusInfo) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 使用unregister接口取消订阅网络阻塞状态事件。
netCon.unregister((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

### on('netCapabilitiesChange')

on(type: 'netCapabilitiesChange', callback: Callback\<NetCapabilityInfo\>): void

订阅网络能力变化事件。此接口调用之前需要先调用register接口，不需要网络状态变化回调通知时，使用unregister取消订阅默认网络状态变化的通知。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netCapabilitiesChange'。<br/>netCapabilitiesChange：网络能力变化事件。 |
| callback | Callback<[NetCapabilityInfo](#netcapabilityinfo10)>          | 是   | 回调函数，返回数据网络句柄(netHandle)和网络的能力信息(netCap)。|

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 创建NetConnection对象。
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册网络状态变化事件。
netCon.register((error: BusinessError) => {
  console.error(JSON.stringify(error));
});

// 订阅网络能力变化事件。调用register后，才能接收到此事件通知。
netCon.on('netCapabilitiesChange', (data: connection.NetCapabilityInfo) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 使用unregister接口取消订阅网络能力变化事件。
netCon.unregister((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

### on('netConnectionPropertiesChange')

on(type: 'netConnectionPropertiesChange', callback: Callback\<NetConnectionPropertyInfo\>): void

订阅网络连接信息变化事件。此接口调用之前需要先调用register接口，不需要网络状态变化回调通知时，使用unregister取消订阅默认网络状态变化的通知。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 订阅事件，固定为'netConnectionPropertiesChange'。<br/>netConnectionPropertiesChange：网络连接信息变化事件。 |
| callback | Callback<[NetConnectionPropertyInfo](#netconnectionpropertyinfo11)> | 是   | 回调函数，获取网络连接属性信息。|

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 创建NetConnection对象。
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册网络状态变化事件。
netCon.register((error: BusinessError) => {
  console.error(JSON.stringify(error));
});

// 订阅网络连接信息变化事件。调用register后，才能接收到此事件通知。
netCon.on('netConnectionPropertiesChange', (data: connection.NetConnectionPropertyInfo) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 使用unregister接口取消订阅网络连接信息变化事件。
netCon.unregister((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

### on('netLost')

on(type: 'netLost', callback: Callback\<NetHandle>): void

订阅网络丢失事件。此接口调用之前需要先调用register接口，不需要网络状态变化回调通知时，使用unregister取消订阅默认网络状态变化的通知。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | 是   | 订阅事件，固定为'netLost'。<br/>netLost：网络严重中断或正常断开事件。 |
| callback | Callback\<[NetHandle](#nethandle)> | 是   | 回调函数，数据网络句柄(netHandle)。|

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 创建NetConnection对象。
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册网络状态变化事件。
netCon.register((error: BusinessError) => {
  console.error(JSON.stringify(error));
});

// 订阅网络丢失事件。调用register后，才能接收到此事件通知。
netCon.on('netLost', (data: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 使用unregister接口取消订阅网络丢失事件。
netCon.unregister((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

### on('netUnavailable')

on(type: 'netUnavailable', callback: Callback\<void>): void

订阅网络不可用事件。此接口调用之前需要先调用register接口，不需要网络状态变化回调通知时，使用unregister取消订阅默认网络状态变化的通知。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | 是   | 订阅事件，固定为'netUnavailable'。<br/>netUnavailable：网络不可用事件。 |
| callback | Callback\<void> | 是   | 回调函数，无返回结果。|

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 创建NetConnection对象。
let netCon: connection.NetConnection = connection.createNetConnection();

// 先使用register接口注册网络状态变化事件。
netCon.register((error: BusinessError) => {
  console.error(JSON.stringify(error));
});

// 订阅网络不可用事件。调用register后，才能接收到此事件通知。
netCon.on('netUnavailable', () => {
  console.info("Succeeded to get unavailable net event");
});

// 使用unregister接口取消订阅网络不可用事件。
netCon.unregister((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## NetHandle

数据网络的句柄。

在调用NetHandle的方法之前，需要先获取NetHandle对象。

**系统能力**：SystemCapability.Communication.NetManager.Core

### 属性

| 名称    | 类型   | 必填 | 说明                      |
| ------ | ------ | --- |------------------------- |
| netId  | number | 是  |  网络ID，取值为0代表没有默认网络，其余取值必须大于等于100。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |

### bindSocket<sup>9+</sup>

bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void

将TCPSocket或UDPSocket绑定到当前NetHandle对应的网络，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                            |
| ----------- | ------------------------ | ---- | -------------------------------|
| socketParam | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | 是 | 待绑定的TCPSocket或UDPSocket对象。|
| callback    | AsyncCallback\<void>      | 是   | 回调函数。当TCPSocket或UDPSocket成功绑定到当前网络，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection, socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

interface Data {
  message: ArrayBuffer,
  remoteInfo: socket.SocketRemoteInfo
}

  connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
  }
  let tcp : socket.TCPSocket = socket.constructTCPSocketInstance();
  let udp : socket.UDPSocket = socket.constructUDPSocketInstance();
  let socketType = "TCPSocket";
  if (socketType == "TCPSocket") {
    tcp.bind({address:"192.168.xxx.xxx",
              port:8080,
              family:1} as socket.NetAddress, (error: Error) => {
      if (error) {
        console.error('bind fail');
        return;
      }
      netHandle.bindSocket(tcp, (error: BusinessError, data: void) => {
        if (error) {
          console.error(`Failed to bind socket. Code:${error.code}, message:${error.message}`);
          return;
        } else {
          console.info(JSON.stringify(data));
        }
      });
    });
  } else {
    let callback: (value: Data) => void = (value: Data) => {
      console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
    };
    udp.bind({address:"192.168.xxx.xxx",
              port:8080,
              family:1} as socket.NetAddress, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to bind. Code:${error.code}, message:${error.message}`);
        return;
      }
      udp.on('message', (data: Data) => {
        console.info("Succeeded to get data: " + JSON.stringify(data));
      });
      netHandle.bindSocket(udp, (error: BusinessError, data: void) => {
        if (error) {
          console.error(`Failed to bind socket. Code:${error.code}, message:${error.message}`);
          return;
        } else {
          console.info(JSON.stringify(data));
        }
      });
    });
  }
})
```

### bindSocket<sup>9+</sup>

bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void\>

将TCPSocket或UDPSockett绑定到当前NetHandle对应的网络，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名          | 类型                  | 必填  | 说明                           |
| --------------- | --------------------- | ---- | ------------------------------ |
| socketParam     | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | 是   | 待绑定的TCPSocket或UDPSocket对象。|

**返回值：**

| 类型           | 说明                   |
| -------------- | ---------------------- |
| Promise\<void\> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection, socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

interface Data {
  message: ArrayBuffer,
  remoteInfo: socket.SocketRemoteInfo
}

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let tcp : socket.TCPSocket = socket.constructTCPSocketInstance();
  let udp : socket.UDPSocket = socket.constructUDPSocketInstance();
  let socketType = "TCPSocket";
  if (socketType == "TCPSocket") {
    tcp.bind({address:"192.168.xxx.xxx",
              port:8080,
              family:1} as socket.NetAddress, (error: Error) => {
      if (error) {
        console.error('bind fail');
        return;
      }
      netHandle.bindSocket(tcp).then(() => {
        console.info("bind socket success");
      }).catch((error: BusinessError) => {
        console.error(`Failed to bind socket. Code:${error.code}, message:${error.message}`);
      });
    });
  } else {
    let callback: (value: Data) => void = (value: Data) => {
      console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
    }
    udp.bind({address:"192.168.xxx.xxx",
              port:8080,
              family:1} as socket.NetAddress, (error: BusinessError) => {
      if (error) {
        console.error(`Failed to bind. Code:${error.code}, message:${error.message}`);
        return;
      }
      udp.on('message', (data: Data) => {
        console.info("Succeeded to get data: " + JSON.stringify(data));
      });
      netHandle.bindSocket(udp).then(() => {
        console.info("bind socket success");
      }).catch((error: BusinessError) => {
        console.error(`Failed to bind socket. Code:${error.code}, message:${error.message}`);
      });
    });
  }
});
```

### getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>\>\): void

使用当前NetHandle对应的网络解析主机名获取到的所有IP地址，使用callback方式作为异步方法。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| host     | string                                            | 是   | 需要解析的主机名。                                           |
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | 是   | 回调函数。当使用对应网络解析主机名成功获取所有IP地址，error为undefined，data为获取到的所有IP地址；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandler的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let host = "xxxx";
  netHandle.getAddressesByName(host, (error: BusinessError, data: connection.NetAddress[]) => {
    if (error) {
      console.error(`Failed to get addresses. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("Succeeded to get data: " + JSON.stringify(data));
  });
});
```

### getAddressesByName

getAddressesByName(host: string): Promise\<Array\<NetAddress>>

使用当前NetHandle对应的网络解析主机名获取到的所有IP地址，使用Promise方式作为异步方法。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

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

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandler的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let host = "xxxx";
  netHandle.getAddressesByName(host).then((data: connection.NetAddress[]) => {
    console.info("Succeeded to get data: " + JSON.stringify(data));
  });
});
```

### getAddressByName

getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void

使用当前NetHandle对应的网络解析主机名获取到的第一个IP地址，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| host     | string                                    | 是   | 需要解析的主机名。                                           |
| callback | AsyncCallback\<[NetAddress](#netaddress)> | 是   | 回调函数。当使用对应网络解析主机名获取第一个IP地址成功，error为undefined，data为获取的第一个IP地址；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandler的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let host = "xxxx";
  netHandle.getAddressByName(host, (error: BusinessError, data: connection.NetAddress) => {
    if (error) {
      console.error(`Failed to get address. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("Succeeded to get data: " + JSON.stringify(data));
  });
});
```

### getAddressByName

getAddressByName(host: string): Promise\<NetAddress>

使用当前NetHandle对应的网络解析主机名获取到的第一个IP地址，使用Promise方式作为异步方法。

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

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 401     | Parameter error.                  |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandler的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let host = "xxxx";
  netHandle.getAddressByName(host).then((data: connection.NetAddress) => {
    console.info("Succeeded to get data: " + JSON.stringify(data));
  });
});
```

## NetCap

网络具体能力。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 值   | 说明                   |
| ------------------------ | ---- | ---------------------- |
| NET_CAPABILITY_MMS | 0 | 表示网络可以访问运营商的MMSC（Multimedia&nbsp;Message&nbsp;Service，多媒体短信服务）发送和接收彩信。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| NET_CAPABILITY_NOT_METERED | 11 | 表示网络流量未被计费。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| NET_CAPABILITY_INTERNET  | 12   | 表示该网络应具有访问Internet的能力，此能力由网络提供者设置，但该网络访问Internet的连通性并未被网络管理成功验证。网络连通性可以通过NET_CAPABILITY_VALIDATED和NET_CAPABILITY_CHECKING_CONNECTIVITY判断。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| NET_CAPABILITY_NOT_VPN | 15 | 表示网络不使用VPN（Virtual&nbsp;Private&nbsp;Network，虚拟专用网络）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| NET_CAPABILITY_VALIDATED | 16   | 表示网络管理通过该网络与华为云地址成功建立连接，此能力由网络管理模块设置。<br>**注意：** 网络管理可能会与华为云地址建立连接失败，导致网络能力不具备此标记位，但不完全代表该网络无法访问互联网。另外，对于新完成连接的网络，由于网络正在进行连通性验证，此值可能无法反映真实的验证结果。对此，应用可以通过NET_CAPABILITY_CHECKING_CONNECTIVITY<sup>12+</sup>检查网络是否正在检测连通性。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| NET_CAPABILITY_PORTAL<sup>12+</sup> | 17   | 表示系统发现该网络存在强制网络门户，需要用户登陆认证，该能力由网络管理模块设置。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| NET_CAPABILITY_CHECKING_CONNECTIVITY<sup>12+</sup> | 31   | 表示网络管理正在检验当前网络的连通性，此值会在网络连接时设置。当此值存在时，NET_CAPABILITY_VALIDATED的值不准确，连通性检测结束后不再设置，此时可以通过判断NetCap是否包含NET_CAPABILITY_VALIDATED判断连通性。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## NetBearType

网络类型。

**系统能力**：SystemCapability.Communication.NetManager.Core

|            名称         | 值   | 说明        |
| ----------------------- | ---- | ---------- |
| BEARER_CELLULAR | 0    | 蜂窝网络。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| BEARER_WIFI     | 1    | Wi-Fi网络。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| BEARER_BLUETOOTH<sup>12+</sup> | 2    | 蓝牙网络。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| BEARER_ETHERNET | 3    | 以太网网络。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| BEARER_VPN<sup>12+</sup>| 4    | VPN网络。   |

## HttpProxy<sup>10+</sup>

网络代理配置信息

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 必填 | 说明                      |
| ------ | ------ | --- |------------------------- |
| host  | string | 是  |  代理服务器主机名。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| port  | number | 是  |  主机端口。取值范围[0,65535]。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| exclusionList  | Array\<string\> | 是  | 不使用代理的主机名列表，主机名支持域名、IP地址以及通配符形式，详细匹配规则如下：<br/>1、域名匹配规则：<br/>（1）完全匹配：代理服务器主机名只要与列表中的任意一个主机名完全相同，就可以匹配。<br/>（2）包含匹配：代理服务器主机名只要包含列表中的任意一个主机名，就可以匹配。<br/>例如，如果在主机名列表中设置了 “ample.com”，则  “ample.com”、“www.ample.com”、“ample.com:80”都会被匹配，而 “www.example.com”、“ample.com.org”则不会被匹配。<br/>2、IP地址匹配规则：代理服务器主机名只要与列表中的任意一个IP地址完全相同，就可以匹配。<br/>3、域名跟IP地址可以同时添加到列表中进行匹配。<br/>4、单个“\*”是唯一有效的通配符，当列表中只有通配符时，将与所有代理服务器主机名匹配，表示禁用代理。通配符只能单独添加，不可以与其他域名、IP地址一起添加到列表中，否则通配符将不生效。<br/>5、匹配规则不区分主机名大小写。<br/>6、匹配主机名时，不考虑http和https等协议前缀。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| username<sup>12+</sup>  | string | 否 |  使用代理的用户名。|
| password<sup>12+</sup>  | string | 否 |  使用代理的用户密码。|

## NetSpecifier

提供承载数据网络能力的实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                     | 类型                                | 必填  | 说明                                                         |
| ----------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| netCapabilities         | [NetCapabilities](#netcapabilities) |  是  | 存储数据网络的传输能力和承载类型。                                |
| bearerPrivateIdentifier | string                              |  否  |  网络标识符，蜂窝网络的标识符是"slot0"（对应SIM卡1）、"slot1"（对应SIM卡2）。从API12开始可以通过传递注册的WLAN热点信息表示应用希望激活的指定的WLAN网络。 |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { wifiManager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let config: wifiManager.WifiDeviceConfig = {
  ssid: "TEST",
  preSharedKey: "**********",
  securityType: wifiManager.WifiSecurityType.WIFI_SEC_TYPE_PSK
};
// 通过wifiManager.addCandidateConfig获取注册WLAN的networkId。
wifiManager.addCandidateConfig(config,(error,networkId) => {
 let netConnectionWlan = connection.createNetConnection({
   netCapabilities: {
     bearerTypes: [connection.NetBearType.BEARER_WIFI]
   },
   bearerPrivateIdentifier: `${networkId}`
 });
 netConnectionWlan.register((error: BusinessError) => {
   console.error(JSON.stringify(error));
 });
});
```

## NetCapabilityInfo<sup>10+</sup>

提供承载数据网络能力的实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                    | 类型                                 | 必填  | 说明                                                         |
| ----------------------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| netHandle               | [NetHandle](#nethandle)              |  是  | 数据网络句柄。                                                |
| netCap                  |  [NetCapabilities](#netcapabilities) |  是  |  存储数据网络的传输能力和承载类型。                            |

## NetCapabilities

网络的能力集。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 类型                                | 必填 | 说明                     |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| linkUpBandwidthKbps   | number                             |  否 |  上行（设备到网络）带宽，单位(kb/s)。0表示无法评估当前网络带宽。|
| linkDownBandwidthKbps | number                             |  否 |  下行（网络到设备）带宽，单位(kb/s)。0表示无法评估当前网络带宽。|
| networkCap            | Array\<[NetCap](#netcap)>           |  否 |  网络具体能力。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。           |
| bearerTypes           | Array\<[NetBearType](#netbeartype)> |  是 |  网络类型。数组里面只包含了一种网络类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。      |

## NetConnectionPropertyInfo<sup>11+</sup>

网络连接信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

### 属性

| 名称                 |                          类型                        | 必填 |         说明           |
| -------------------- | --------------------------------------------------- | ---- |----------------------- |
| netHandle            | [NetHandle](#nethandle)                             | 是   |数据网络句柄(netHandle)。|
| connectionProperties | [ConnectionProperties](#connectionproperties)       | 是   |网络连接属性。           |

## NetBlockStatusInfo<sup>11+</sup>

获取网络状态信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

### 属性

| 名称                 | 类型                                  | 必填 |            说明            |
| -------------------- | ------------------------------------- | --- |--------------------------- |
| netHandle            | [NetHandle](#nethandle)               | 是   |数据网络句柄(netHandle)。   |
| blocked              | boolean                               | 是   |true：标识当前网络是堵塞状态；false：标识当前网络不是堵塞状态。 |

## ConnectionProperties

网络连接信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称          |                类型                 | 必填 |               说明                     |
| ------------- | ----------------------------------- | ----|--------------------------------------- |
| interfaceName | string                              | 是 |网卡名称。                                |
| domains       | string                              | 是 |域名。                                    |
| linkAddresses | Array\<[LinkAddress](#linkaddress)> | 是 |链路信息。                                |
| routes        | Array\<[RouteInfo](#routeinfo)>     | 是 |路由信息。                                |
| dnses         | Array\<[NetAddress](#netaddress)>   | 是 |网络地址，参考[NetAddress](#netaddress)。 |
| mtu           | number                              | 是 |最大传输单元。                            |

## RouteInfo

网络路由信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称           | 类型                        | 必填 |     说明      |
| -------------- | --------------------------- | --- |-------------- |
| interface      | string                      | 是 |网卡名称。       |
| destination    | [LinkAddress](#linkaddress) | 是 |目的地址。       |
| gateway        | [NetAddress](#netaddress)   | 是 |网关地址。       |
| hasGateway     | boolean                     | 是 |true：有网关；false：无网关。     |
| isDefaultRoute | boolean                     | 是 |true：默认路由；false：非默认路由。 |
| isExcludedRoute<sup>20+</sup>| boolean                     | 否 |是否为排除路由。true表示排除路由，false表示非排除路由，默认值为false。|

## LinkAddress

网络链路信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称         |           类型            | 必填 |        说明         |
| ------------ | ------------------------- |---- |-------------------- |
| address      | [NetAddress](#netaddress) | 是  | 链路地址。           |
| prefixLength | number                    | 是  |链路地址前缀的长度。  |

## NetAddress

网络地址。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

|  名称   | 类型   |必填|            说明              |
| ------- | ------ | -- |---------------------------- |
| address | string | 是 |地址。                       |
| family  | number | 否 |IPv4 = 1，IPv6 = 2，默认IPv4。|
| port    | number | 否 |端口，取值范围\[0, 65535]，默认值为0。  |

## HttpRequest

type HttpRequest = http.HttpRequest

定义一个HTTP请求，可以通过[http.createHttp](js-apis-http.md#httpcreatehttp)创建。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       |            说明             |
| ---------------- | --------------------------- |
| http.HttpRequest | 定义HTTP请求任务。在调用HttpRequest提供的API之前。 |

## TCPSocket

type TCPSocket = socket.TCPSocket

定义一个TCPSocket对象，可以通过[socket.constructTCPSocketInstance](js-apis-socket.md#socketconstructtcpsocketinstance7)创建。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       |            说明             |
| ---------------- | --------------------------- |
| socket.TCPSocket | 定义一个TCPSocket连接。     |

## UDPSocket

type UDPSocket = socket.UDPSocket

定义一个UDPSocket对象，可以通过[socket.constructUDPSocketInstance](js-apis-socket.md#socketconstructudpsocketinstance)创建。

**系统能力**：SystemCapability.Communication.NetStack

|       类型       |            说明             |
| ---------------- | --------------------------- |
| socket.UDPSocket | 定义UDPSocket连接。     |
