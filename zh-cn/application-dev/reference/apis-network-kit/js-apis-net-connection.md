# @ohos.net.connection (网络连接管理)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

网络连接管理提供管理网络一些基础能力，包括获取默认激活的网络、获取所有激活网络列表、获取网络能力信息等功能。

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

创建一个NetConnection对象，可用于监听网络状态。[netSpecifier](#netspecifier)表示需要监听网络的网络特征；timeout是超时时间（单位：毫秒)；netSpecifier是timeout的必要条件，两者都没有则表示关注默认网络。

>**说明：**
>
>若需要监听网络状态，创建一个NetConnection对象后，还需调用[register](#register)注册指定网络状态变化的通知。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| netSpecifier | [NetSpecifier](#netspecifier) | 否   | 需要监听网络的网络特征，缺省则表示监听默认网络。                   |
| timeout      | number                        | 否   | 获取netSpecifier指定网络时的超时时间（单位：ms），传入值需为uint32_t范围内的整数，仅netSpecifier存在时生效，默认值为0。<br>**说明**：当监听网络不存在时，会尝试激活此网络。若超过设置的超时时间，且注册了网络状态监听，则会触发netUnavailable事件。|

**返回值：**

| 类型                            | 说明                 |
| ------------------------------- | -------------------- |
| [NetConnection](#netconnection) | 需要监听的网络连接对象的类型。 |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

// 示例1：仅关注默认网络, 无需指定netSpecifier参数，timeout参数未传入说明未使用超时时间，此时timeout为0。
let netConnection = connection.createNetConnection();

// 示例2：仅关注蜂窝网络，需要指定网络类型为蜂窝网络。
let timeout = 1000;
let netConnectionCellular = connection.createNetConnection({
  netCapabilities: {
    bearerTypes: [connection.NetBearType.BEARER_CELLULAR]
  }
}, timeout);

// 示例3：关注蜂窝或Wi-Fi网络，需要指定网络类型为蜂窝网络和Wi-Fi网络。
let netConnectionCellularAndWifi = connection.createNetConnection({
  netCapabilities: {
    bearerTypes: [connection.NetBearType.BEARER_CELLULAR,
      connection.NetBearType.BEARER_WIFI]
  }
});
```

## connection.getDefaultNet

getDefaultNet(callback: AsyncCallback\<NetHandle>): void

获取系统默认使用的网络句柄，包含网络ID。使用callback异步回调。

> **说明：**
>
>- 系统默认使用的网络，该网络的capabilities必须具备[NET_CAPABILITY_INTERNET](#netcap)且不是VPN类型的网络。
>
>- 该接口的返回由系统决定，与应用是否指定网络无关。
>
>- 一般情况下优先级为：以太网（PC）|蓝牙（手表）> WIFI > 蜂窝，特殊情况以实际返回结果为准。
>
>- [NetHandle](#nethandle)为网络唯一标识，当无网络可用时，返回0。其可用于[getNetCapabilities](#connectiongetnetcapabilities)继续查询更多网络信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | 是   | 回调函数。当成功获取默认激活网络的网络句柄时，error为undefined，data为默认网络的网络句柄；否则为错误对象。 |

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
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```

## connection.getDefaultNet

getDefaultNet(): Promise\<NetHandle>

获取系统默认使用的网络句柄，包含网络ID。使用Promise异步回调。

> **说明：**
>
>- 系统默认使用的网络，该网络的capabilities必须具备[NET_CAPABILITY_INTERNET](#netcap)且不是VPN类型的网络。
>
>- 该接口的返回由系统决定，与应用是否指定网络无关。
>
>- 一般情况下，优先级：以太网（PC）|蓝牙（手表）> WIFI > 蜂窝，特殊情况以实际返回结果为准。
>
>- [NetHandle](#nethandle)为网络唯一标识，当无网络可用时，返回0。其可用于[getNetCapabilities](#connectiongetnetcapabilities)继续查询更多网络信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetHandle](#nethandle)> | 以Promise形式返回默认网络的网络句柄。 |

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

获取系统默认使用的网络句柄，包含网络ID。使用同步方式返回。

> **说明：**
>
>- 系统默认使用的网络，该网络的capabilities必须具备[NET_CAPABILITY_INTERNET](#netcap)且不是VPN类型的网络。
>
>- 该接口的返回由系统决定，与应用是否指定网络无关。
>
>- 一般情况下，优先级：以太网（PC）|蓝牙（手表）> WIFI > 蜂窝，特殊情况以实际返回结果为准。
>
>- [NetHandle](#nethandle)为网络唯一标识，当无网络可用时，返回0。其可用于[getNetCapabilities](#connectiongetnetcapabilities)继续查询更多网络信息。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| [NetHandle](#nethandle) | 以同步方式返回默认网络的网络句柄。 |

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

> **说明：**
>
> 若需使用本接口所配置的代理信息，则需在[HttpRequestOptions](js-apis-http.md#httprequestoptions)字段中将usingProxy设置为true以启用代理转发。本接口仅负责配置代理规则，不校验代理服务的有效性。

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
import { http } from '@kit.NetworkKit';

// 将exclusionStr以逗号分隔为数组。
let exclusionStr = "192.168,test.com";
// exclusionArray将exclusionStr以逗号分隔为数组。
let exclusionArray = exclusionStr.split(',');
connection.setAppHttpProxy({
  host: "192.168.xx.xxx",
  port: 8080,
  exclusionList: exclusionArray
} as connection.HttpProxy);
let httpRequest = http.createHttp();
let options: http.HttpRequestOptions = {
  usingProxy: true, // 选择使用网络代理，从API 10开始支持该属性。
};
// 发起一个HTTP请求。
httpRequest.request("EXAMPLE_URL", options, (err: BusinessError, data: http.HttpResponse) => {
  if (!err) {
   console.info('Succeeded to get result: ' + JSON.stringify(data.result));
   console.info('Succeeded to get code: ' + JSON.stringify(data.responseCode));
   console.info('Succeeded to get type: ' + JSON.stringify(data.resultType));
   console.info('Succeeded to get header: ' + JSON.stringify(data.header));
   console.info('Succeeded to get cookies: ' + JSON.stringify(data.cookies)); // 从API version 8开始支持cookie。
  } else {
   console.error(`Failed to get request. Code:${err.code}, message:${err.message}`);
  }
});

```

## connection.getDefaultHttpProxy<sup>10+</sup>

getDefaultHttpProxy(callback: AsyncCallback\<HttpProxy>): void

获取网络的默认代理配置信息。使用callback异步回调。

> **说明：**
>
>- 如果设置了全局代理，则返回全局代理配置信息。
>- 如果进程使用[setAppNet](#connectionsetappnet9)绑定到指定[NetHandle](#nethandle)对应的网络，则返回[NetHandle](#nethandle)对应网络的代理配置信息。在其它情况下，将返回默认网络的代理配置信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[HttpProxy](#httpproxy10)> | 是   | 回调函数。当成功获取网络的默认代理配置信息时，error为undefined，data为网络的默认代理配置信息；否则为错误对象。 |

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
  console.info("Succeeded to get data" + JSON.stringify(data));
});
```

## connection.getDefaultHttpProxy<sup>10+</sup>

getDefaultHttpProxy(): Promise\<HttpProxy>

获取网络默认的代理配置信息。使用Promise异步回调。

> **说明：**
>
>- 如果设置了全局代理，则返回全局代理配置信息。
>- 如果进程使用[setAppNet](#connectionsetappnet9)绑定到指定[NetHandle](#nethandle)对应的网络，则返回[NetHandle](#nethandle)对应网络的代理配置信息。在其它情况下，将返回默认网络的代理配置信息。

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
  console.info("Succeeded to get data: " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error(`Failed to get request. Code:${error.code}, message:${error.message} `);
});
```

## connection.getAppNet<sup>9+</sup>

getAppNet(callback: AsyncCallback\<NetHandle>): void

获取App绑定的网络句柄。使用callback异步回调。

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

获取App绑定的网络信息。使用Promise异步回调。

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
  console.info("Succeeded to get data: " + JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error(`Failed to get request. Code:${error.code}, message:${error.message}`);
});
```

## connection.getAppNetSync<sup>10+</sup>

getAppNetSync(): NetHandle

获取App绑定的网络信息。使用同步方式返回。

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

将App绑定到特定的网络，绑定后App只能通过netHandle对应的网络访问网络。使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                         |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle) | 是   | 网络句柄。                                             |
| callback  | AsyncCallback\<void>    | 是   | 回调函数。当成功绑定App到指定网络时，error为undefined，否则为错误对象。|

>**说明：**
>
> 当应用不再使用该网络或者该网络不可用时，需要解除App和指定网络的绑定关系，以免导致应用无法上网。
> 
> 如需解除App和指定网络的绑定关系，可以调用[setAppNet](#connectionsetappnet9)，并传入一个netId = 0的NetHandle对象，参考以下示例。

```ts
connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  netHandle.netId = 0;
  connection.setAppNet(netHandle, (error: BusinessError, data: void) => {
    if (error) {
      console.error(`Failed to get default net. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("Succeeded to get data: " + JSON.stringify(data));
  });
});
```

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

当应用绑定WIFI网络，WIFI弱信号或者断开时，如果不解绑，会导致应用无法上网。

以下示例以绑定WIFI网络为例，结合[on('netAvailable')](#onnetavailable)、[on('netLost')](#onnetlost)接口，当监听到WIFI网络可用时绑定WIFI网络，不可用时解绑，使用默认网络。

```ts

import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 创建NetConnection对象。仅关注WIFI网络，需要指定网络类型为WIFI网络。
let netCon = connection.createNetConnection({
  netCapabilities: {
    bearerTypes: [connection.NetBearType.BEARER_WIFI]
  }
});

// 使用on接口订阅网络可用事件
netCon.on('netAvailable', (netHandle: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(netHandle));
  connection.setAppNet(netHandle, (error: BusinessError, data: void) => {
    if (error) {
      console.error(`Failed to setAppNet. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("Succeeded to setAppNet, netid: " + JSON.stringify(netHandle.netId));
  });
});

// 使用on接口订阅网络丢失事件。
netCon.on('netLost', (netHandle: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(netHandle));
  // 网络丢失时，需要主动解除指定网络的绑定关系
  netHandle.netId = 0;
  connection.setAppNet(netHandle, (error: BusinessError, data: void) => {
    if (error) {
      console.error(`Failed to setAppNet. Code:${error.code}, message:${error.message}`);
      return;
    }
    console.info("Succeeded to setAppNet, netid: " + JSON.stringify(netHandle.netId));
  });
});

// 注册网络状态变化事件。此接口要在调用on后调用。
netCon.register((error: BusinessError) => {
  if (error) {
    console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
  }
});

```

## connection.setAppNet<sup>9+</sup>

setAppNet(netHandle: NetHandle): Promise\<void\>

将App异步绑定到特定的网络，绑定后App只能通过netHandle对应的网络访问网络。使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明             |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                                      | 是   | 网络句柄。 |

>**说明：**
>
> 当应用不再使用该网络或者该网络不可用时，需要解除App和指定网络的绑定关系，以免导致应用无法上网。
> 
> 如需解除App和指定网络的绑定关系，可以调用[setAppNet](#connectionsetappnet9)，并传入一个netId = 0的NetHandle对象，参考以下示例。
```ts
connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  netHandle.netId = 0;
  connection.setAppNet(netHandle).then(() => {
    console.info("Succeeded to setAppNet");
  }).catch((error: BusinessError) => {
    console.error(`Failed to setAppNet. Code:${error.code}, message:${error.message}`);
  })
});
```

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

当应用绑定WIFI网络，WIFI弱信号或者断开时，如果不解绑，会导致应用无法上网。

以下示例以绑定WIFI网络为例，结合[on('netAvailable')](#onnetavailable)、[on('netLost')](#onnetlost)接口，当监听到WIFI网络可用时绑定WIFI网络，不可用时解绑，使用默认网络。

```ts

import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 创建NetConnection对象。仅关注WIFI网络，需要指定网络类型为WIFI网络。
let netCon = connection.createNetConnection({
  netCapabilities: {
    bearerTypes: [connection.NetBearType.BEARER_WIFI]
  }
});

// 使用on接口订阅网络可用事件
netCon.on('netAvailable', (netHandle: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(netHandle));
  connection.setAppNet(netHandle).then(() => {
    console.info("Succeeded to setAppNet, netid: " + JSON.stringify(netHandle.netId));
  }).catch((error: BusinessError) => {
    console.error(`Failed to setAppNet. Code:${error.code}, message:${error.message}`);
  })
});

// 使用on接口订阅网络丢失事件。
netCon.on('netLost', (netHandle: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(netHandle));
  // 网络丢失时，需要主动解除指定网络的绑定关系
  netHandle.netId = 0;
  connection.setAppNet(netHandle).then(() => {
    console.info("Succeeded to setAppNet, netid: " + JSON.stringify(netHandle.netId));
  }).catch((error: BusinessError) => {
    console.error(`Failed to setAppNet. Code:${error.code}, message:${error.message}`);
  })
});

// 注册网络状态变化事件。此接口要在调用on后调用。
netCon.register((error: BusinessError) => {
  if (error) {
    console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
  }
});

```

## connection.getAllNets

getAllNets(callback: AsyncCallback&lt;Array&lt;NetHandle&gt;&gt;): void

获取所有处于连接状态的网络列表，使用callback异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | 是 | 回调函数。当成功获取所有处于连接状态的网络列表时，error为undefined，data为处于激活状态的网络列表；否则为错误对象。<br> **说明：** 在Wi-Fi和蜂窝数据开关均开启的情况下，若无应用指定使用蜂窝网络，则仅激活Wi-Fi网络，因此仅返回Wi-Fi的NetHandle。除非有特定应用启动蜂窝网络，才能同时获取Wi-Fi和蜂窝数据的NetHandle。|

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

获取所有处于连接状态的网络列表。使用Promise异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | Promise对象，返回处于激活状态的网络列表。 |

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

获取所有处于连接状态的网络列表。使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| Array&lt;[NetHandle](#nethandle)&gt; | 返回所有处于连接状态的网络列表。 |

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

获取netHandle对应的网络的连接信息，包含网卡名称、域名、链路信息、路由信息、网络地址及最大传输单元。使用callback异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                                      | 是   | 网络句柄。                                             |
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

// 示例： 获取当前默认网络的连接信息。
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

获取netHandle对应的网络的连接信息，包含网卡名称、域名、链路信息、路由信息、网络地址及最大传输单元。使用Promise异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | 是   | 数据网络的句柄。 |

**返回值：**

| 类型                                                    | 说明                              |
| ------------------------------------------------------- | --------------------------------- |
| Promise\<[ConnectionProperties](#connectionproperties)> | Promise对象，返回网络的连接信息。 |

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

获取netHandle对应的网络的连接信息，包含网卡名称、域名、链路信息、路由信息、网络地址及最大传输单元。使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | 是   | 网络句柄。 |

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

connection.getDefaultNet().then((netHandle: connection.NetHandle) => {
  if (netHandle.netId == 0) {
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let connectionproperties = connection.getConnectionPropertiesSync(netHandle);
  console.info("Succeeded to get connectionproperties: " + JSON.stringify(connectionproperties));
});
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void

获取netHandle对应网络的能力集，包含上/下行带宽、网络具体能力、网络类型。使用callback异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                                | 必填 | 说明                                                         |
| --------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                             | 是   | 网络的句柄。                                             |
| callback  | AsyncCallback\<[NetCapabilities](#netcapabilities)> | 是   | 回调函数。当成功获取netHandle对应网络的能力集时，error为undefined，data为获取到的网络能力集；否则为错误对象。|

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
    console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>

获取netHandle对应网络的能力集，包含上/下行带宽、网络具体能力、网络类型。使用Promise异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | 是   | 网络句柄。 |

**返回值：**

| 类型                                          | 说明                              |
| --------------------------------------------- | --------------------------------- |
| Promise\<[NetCapabilities](#netcapabilities)> | Promise对象，返回网络的能力集。 |

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
    console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});
```

## connection.getNetCapabilitiesSync<sup>10+</sup>

getNetCapabilitiesSync(netHandle: NetHandle): NetCapabilities

获取netHandle对应网络的能力信息，包含上/下行带宽、网络具体能力、网络类型。使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | 是   | 网络句柄。 |

**返回值：**

| 类型                                          | 说明                              |
| --------------------------------------------- | --------------------------------- |
| [NetCapabilities](#netcapabilities) | 返回网络的能力集。 |

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

  let getNetCapabilitiesSync = connection.getNetCapabilitiesSync(netHandle);
  console.info("Succeeded to get net capabilities sync: " + JSON.stringify(getNetCapabilitiesSync));
});
```

## connection.isDefaultNetMetered<sup>9+</sup>

isDefaultNetMetered(callback: AsyncCallback\<boolean>): void

检查当前默认网络上的数据流量使用是否被计费（例如：WiFi网络不会被计费，蜂窝网络会被计费）。使用callback异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回当前网络上的数据流量是否被计费。true表示会被计费，false表示不会被计费。 |

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
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```

## connection.isDefaultNetMetered<sup>9+</sup>

isDefaultNetMetered(): Promise\<boolean>

检查当前默认网络上的数据流量使用是否被计费（例如：WiFi网络不会被计费，蜂窝网络会被计费）。使用Promise异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | Promise对象。返回当前网络上的数据流量是否被计费。true表示会被计费，false表示不会被计费。 |

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
console.info("Succeeded to get data: " + JSON.stringify(data));
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

获取当前是否有可用网络，使用callback异步回调。如果有可用网络，可以使用[getDefaultNet](#connectiongetdefaultnet)获取默认网络句柄。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回当前是否有可用网络。true表示当前有可用网络，false表示当前没有可用网络。 |

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
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```

## connection.hasDefaultNet

hasDefaultNet(): Promise\<boolean>

获取当前是否有可用网络。使用Promise异步回调。如果有可用网络，可以使用[getDefaultNet](#connectiongetdefaultnet)获取默认网络句柄。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | Promise对象。返回当前是否有可用网络。true表示当前有可用网络，false表示当前没有可用网络。 |

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
  console.info("Succeeded to get data: " + JSON.stringify(data));
});
```

## connection.hasDefaultNetSync<sup>10+</sup>

hasDefaultNetSync(): boolean

获取当前是否有可用网络。使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                            |
| ----------------- | ----------------------------------------------- |
| boolean | 返回当前是否有可用网络。true表示当前有可用网络，false表示当前没有可用网络。 |

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

let hasDefaultNet = connection.hasDefaultNetSync();
```


## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

向网络管理上报网络处于可用状态。使用callback方式异步回调。

>**说明：**
>
>该接口用于浏览器连接portal网络，网络认证成功后，向网络管理上报网络连接成功，网络管理会触发网络探测，更新网络状态。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 网络句柄，参考[NetHandle](#nethandle)。 |
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
    console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
  });
});
```

## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle): Promise\<void\>

向网络管理报告网络处于可用状态。使用Promise异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 网络句柄，参考[NetHandle](#nethandle)。 |

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
    console.info(`Succeeded to report`);
  });
});
```

## connection.reportNetDisconnected

reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

向网络管理上报网络处于不可用状态。使用callback异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 网络句柄，参考[NetHandle](#nethandle)。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当向网络管理报告网络处于不可用状态成功时，error为undefined，否则为错误对象。 |

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
    console.info("Succeeded to report");
  });
});
```

## connection.reportNetDisconnected

reportNetDisconnected(netHandle: NetHandle): Promise&lt;void&gt;

向网络管理上报网络处于不可用状态。使用Promise异步回调。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | 是 | 网络句柄。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回值的Promise对象。 |

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
    console.info(`Succeeded to report`);
  });
});
```

## connection.getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

使用当前默认网络解析主机名以获取所有IP地址。使用callback异步回调。

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

使用当前默认网络解析主机名以获取所有IP地址。使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | Promise对象。返回所有IP地址。 |

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

## connection.getAddressesByNameWithOptions<sup>23+</sup>

getAddressesByNameWithOptions(host: string, option?: QueryOptions): Promise\<Array\<NetAddress\>\>

使用当前默认网络基于指定IP类型进行DNS解析。使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。例如："www.example.com"。 |
| option | [QueryOptions](#queryoptions23) | 否   | 需要查询的IP类型，默认值为FAMILY_TYPE_ALL。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | Promise对象，返回查询到的IP地址。返回值中的port字段固定为0，无需关注。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let option: connection.QueryOptions = {
  family: connection.FamilyType.FAMILY_TYPE_IPV4
};
connection.getAddressesByNameWithOptions("www.example.com", option).then((data: connection.NetAddress[]) => {
  console.info(`Succeeded to get data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get msg. Code:${err.code}, message:${err.message}`)
});
```


## QueryOptions<sup>23+</sup>

需要查询的IP类型。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称 | 类型  | 只读 | 可选 | 说明               |
| ------ | ------| ---- | ---- | ------------------ |
| family   | [FamilyType](#familytype23) | 否 | 是   | 需要查询的具体IP地址类型，默认值为FAMILY_TYPE_ALL。 |

## FamilyType<sup>23+</sup>

需要查询的具体IP地址类型。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称  |值         | 说明               |
| ------ |---------- | ------------------ |
| FAMILY_TYPE_ALL    | 0   | 查询所有IPv4和IPv6地址。 |
| FAMILY_TYPE_IPV4   | 1   | 仅查询IPv4地址。       |
| FAMILY_TYPE_IPV6   | 2   | 仅查询IPv6地址。       |

## connection.addCustomDnsRule<sup>11+</sup>

addCustomDnsRule(host: string, ip: Array\<string\>, callback: AsyncCallback\<void\>): void

为当前应用程序添加自定义host和对应的IP地址的映射。使用callback异步回调。

> **说明：**
>
> 不需要时可调用[removeCustomDnsRule](#connectionremovecustomdnsrule11)删除某一条自定义规则或调用[clearCustomDnsRules](#connectionclearcustomdnsrules11)删除当前应用程序的所有的自定义DNS规则 。<br>
> 调用本接口添加自定义DNS规则后可持续生效，无需重复添加同一条规则。不需要时可按照上述方法删除。

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

为当前应用程序添加自定义host和对应的IP地址的映射。使用Promise异步回调。

> **说明：**
>
> 不需要时可调用[removeCustomDnsRule](#connectionremovecustomdnsrule11)删除某一条自定义规则或调用[clearCustomDnsRules](#connectionclearcustomdnsrules11)删除当前应用程序的所有的自定义DNS规则 。<br>
> 调用本接口添加自定义DNS规则后可持续生效，无需重复添加同一条规则。不需要时可按照上述方法删除。

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
    console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
})
```

## connection.removeCustomDnsRule<sup>11+</sup>

removeCustomDnsRule(host: string, callback: AsyncCallback\<void\>): void

删除当前应用程序中对应host的自定义DNS规则。使用callback异步回调。

> **说明：**
>
> 删除前需确认当前无线程正在使用该自定义规则，以避免冲突。<br>
> 可调用[addCustomDnsRule](#connectionaddcustomdnsrule11)添加自定义规则。

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

删除当前应用程序中对应host的自定义DNS规则。使用Promise异步回调。

> **说明：**
>
> 删除前需确认当前无线程正在使用该自定义规则，以避免冲突。<br>
> 可调用[addCustomDnsRule](#connectionaddcustomdnsrule11)添加自定义规则。

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

connection.removeCustomDnsRule("xxxx", (error: BusinessError, data: void) => {
  if (error) {
    console.error(`Failed to remove custom dns rule. Code:${error.code}, message:${error.message}`);
    return;
  }
  console.info("Succeeded to get data: " + JSON.stringify(data));
})
```

## connection.clearCustomDnsRules<sup>11+</sup>

clearCustomDnsRules(callback: AsyncCallback\<void\>): void

删除当前应用程序的所有的自定义DNS规则。使用callback异步回调。

> **说明：**
>
> 删除前需确认当前无线程正在使用当前存在的自定义规则，以避免冲突。<br>
> 可调用[addCustomDnsRule](#connectionaddcustomdnsrule11)添加自定义规则。

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

删除当前应用程序的所有的自定义DNS规则。使用Promise异步回调。

> **说明：**
>
> 删除前需确认当前无线程正在使用当前存在的自定义规则，以避免冲突。<br>
> 可调用[addCustomDnsRule](#connectionaddcustomdnsrule11)添加自定义规则。

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
    console.info("success");
}).catch((error: BusinessError) => {
    console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
})
```

## connection.setPacFileUrl<sup>20+</sup>

setPacFileUrl(pacFileUrl: string): void

设置PAC脚本（Proxy Auto-Configuration Script，代理自动配置脚本）的URL地址，并启动PAC代理能力，比如：http://127.0.0.1:21998/PacProxyScript.pac 。可通过调用[findProxyForUrl](#connectionfindproxyforurl20)解析URL地址来获取代理信息。

>**注意：**
>
> 1、本接口当前在PC/2in1<sup>20+</sup>、Phone<sup>23+</sup>、Tablet<sup>23+</sup>、TV<sup>23+</sup>设备上支持解析脚本并启用PAC代理能力，Wearable设备类型上只保存脚本地址，不会启用PAC代理能力。<br>
> 2、该接口不会校验URL真实性，在启动PAC代理时，若URL有误，则启动代理失败，返回2100002错误码。

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
console.info("Succeeded to get pacFileUrl");
```

## connection.findProxyForUrl<sup>20+</sup>

findProxyForUrl(url: string): string

通过设置的PAC脚本，解析指定的URL代理地址，返回对应的PAC代理信息。

> **说明：**
>
> 1、可通过 [setPacFileUrl](#connectionsetpacfileurl20) 或 [setPacUrl](#connectionsetpacurl15) 设置PAC脚本。<br>
> 2、如果调用本接口前未设置PAC脚本，则返回空字符串。<br>
> 3、由于[setPacFileUrl](#connectionsetpacfileurl20)接口支持PC/2in1<sup>20+</sup>、Phone<sup>23+</sup>、Tablet<sup>23+</sup>、TV<sup>23+</sup>设备解析脚本并启用PAC代理能力，因此本接口支持以上设备获取PAC代理信息。 Wearable设备调用本接口功能不生效，返回空字串。

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

> **说明：**
>
> 只支持设置脚本地址，不支持解析和启用代理功能，如需设置脚本并启用代理，则可调用[setPacFileUrl](#connectionsetpacfileurl20)接口。

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
| netHandle | [NetHandle](#nethandle)                                         | 是   | 网络句柄。           |
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
    console.info("Succeeded to setNetExtAttribute");
  }).catch((error: BusinessError) => {
    console.error("setNetExtAttribute failed, err: " + error.code);
  })
});
```

## connection.setNetExtAttributeSync<sup>20+</sup>

setNetExtAttributeSync(netHandle: NetHandle, netExtAttribute: string): void

为netHandle对应的网络设置扩展属性，标识网络的安全级别。使用同步方式返回。

> **说明：**
> 该接口所需的权限目前仅支持PC设备。

**需要权限**：ohos.permission.SET_NET_EXT_ATTRIBUTE

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                              | 必填 | 说明                                                         |
| --------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                  | 是   | 网络句柄。             |
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
| netHandle | [NetHandle](#nethandle)                | 是   | 网络句柄。             |

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| Promise\<string\> | Promise对象，返回的网络扩展属性。|

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
    console.info("Succeeded to getNetExtAttribute: " + netExtAttribute);
  }).catch((error: BusinessError) => {
    console.error("getNetExtAttribute failed, err: " + error.code);
  })
});
```

## connection.getNetExtAttributeSync<sup>20+</sup>

getNetExtAttributeSync(netHandle: NetHandle): string

获取netHandle对应网络的扩展属性，以确定网络的安全级别。使用同步方式返回。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                              | 必填 | 说明                                                         |
| --------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| netHandle | [NetHandle](#nethandle)                   | 是   | 网络句柄。         |

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
  console.info("Succeeded to getNetExtAttribute: " + netExtAttribute);
}
```

## connection.getIpNeighTable<sup>22+</sup>

getIpNeighTable(): Promise\<Array\<NetIpMacInfo>>

获取本地设备IP邻居表条目信息，包括IPv4和IPv6，每个条目信息包括IP地址、MAC地址、网卡名。使用Promise异步回调。

> **说明：**
>
> 该接口获取IP邻居表的缓存的数据，并非局域网内所有连接的数据。
>
> 开发者可使用此接口排查网络异常、解析IP地址与MAC地址映射。

**需要权限**：ohos.permission.GET_NETWORK_INFO 和 ohos.permission.GET_IP_MAC_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型   | 说明                     |
| ------ | ----------------------- |
| Promise\<Array\<[NetIpMacInfo](#netipmacinfo22)>> | Promise对象，返回ip邻居表条目信息。|


**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getIpNeighTable().then((data: connection.NetIpMacInfo[]) => {
  if (data.length !== 0) {
    console.info(`Succeeded to get ipAddress: ${JSON.stringify(data.ipAddress)}`);
    console.info(`Succeeded to get iface: ${JSON.stringify(data.iface)}`);
    console.info(`Succeeded to get macAddress: ${JSON.stringify(data.macAddress)}`);
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to get ip neigh table. Code:${error.code}, message:${error.message}`);
});
```

## connection.getConnectOwnerUid<sup>23+</sup>

getConnectOwnerUid(protocol: ProtocolType, local: NetAddress, remote: NetAddress): Promise\<number>

用于查询发起指定网络连接的应用UID。使用Promise异步回调。

> **说明：**
>
> - 该接口仅限在VPN应用中调用。
> - 调用接口时请设置local和remote参数的端口号。若未设置端口号或将端口号设置为0，接口会基于其他参数筛选出符合条件的UID的集合，并从中返回一个匹配的UID。
> - protocol参数为PROTO_TYPE_UDP时，若通过local，remote参数未筛选出符合条件的UID，则仅基于local参数筛选并返回匹配的UID。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                             | 必填 | 说明            |
| -------- | ------------------------------- | ---- | -------------- |
| protocol | [ProtocolType](#protocoltype23) | 是   | 网络协议的类型。 |
| local    | [NetAddress](#netaddress)       | 是   | 源网络地址。     |
| remote   | [NetAddress](#netaddress)       | 是   | 目标网络地址。   |

**返回值：**

| 类型   | 说明                     |
| ------ | ----------------------- |
| Promise\<number> | Promise对象，返回应用程序的UID。如果不存在匹配的UID则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100301 | Incorrect usage in non-VPN application. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let protocol = connection.ProtocolType.PROTO_TYPE_TCP;
let local: connection.NetAddress = { address: '192.168.1.100', family: 1, port: 6666 };
let remote: connection.NetAddress = { address: '192.168.1.200', family: 1, port: 8888 };
connection.getConnectOwnerUid(protocol, local, remote).then((uid) => {
  console.info(`Succeeded to get uid: ${uid}`);
}).catch((error: BusinessError) => {
  console.error(`Failed to get ConnectOwnerUid. errorCode: ${error.code} message:${error.message}`);
});
```

## connection.getConnectOwnerUidSync<sup>23+</sup>

getConnectOwnerUidSync(protocol: ProtocolType, local: NetAddress, remote: NetAddress): number

用于查询发起指定网络连接的应用UID。使用同步方式返回。

> **说明：**
>
> - 该接口仅限在VPN应用中调用。
> - 调用接口时请设置local和remote参数的端口号。若未设置端口号或将端口号设置为0，接口会基于其他参数筛选出符合条件的UID的集合，并从中返回一个匹配的UID。
> - protocol参数为PROTO_TYPE_UDP时，若通过local，remote参数未筛选出符合条件的UID，则仅基于local参数筛选并返回匹配的UID。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Communication.NetManager.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                             | 必填 | 说明            |
| -------- | ------------------------------- | ---- | -------------- |
| protocol | [ProtocolType](#protocoltype23) | 是   | 网络协议的类型。 |
| local    | [NetAddress](#netaddress)       | 是   | 源网络地址。     |
| remote   | [NetAddress](#netaddress)       | 是   | 目标网络地址。   |

**返回值：**

| 类型   | 说明                     |
| ------ | ----------------------- |
| number | 返回应用程序的UID。如果不存在匹配的UID则返回-1。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100001 | Invalid parameter value.          |
| 2100002 | Failed to connect to the service. |
| 2100301 | Incorrect usage in non-VPN application. |
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let protocol = connection.ProtocolType.PROTO_TYPE_TCP;
let local: connection.NetAddress = { address: '192.168.1.100', family: 1, port: 6666 };
let remote: connection.NetAddress = { address: '192.168.1.200', family: 1, port: 8888 };
try {
  let uid = connection.getConnectOwnerUidSync(protocol, local, remote);
  console.info(`Succeeded to get uid: ${uid}`);
} catch (e) {
  let err = e as BusinessError;
  console.error(`Failed to get ConnectOwnerUid. errorCode: ${err.code} message:${err.message}`);
}
```

## connection.getDnsAscii<sup>23+</sup>

getDnsAscii(host: string, flag?: ConversionProcess): string

将Unicode编码形式的主机名转换为ASCII编码形式，并可通过可选的转换流程参数（conversionProcess）控制转换行为。

> **说明：**
>
> conversionProcess设置为NO_CONFIGURATION时，只能转换已正式分配含义的Unicode字符所对应的域名。<br/>
> conversionProcess设置为ALLOW_UNASSIGNED时，可以转换包含尚未分配含义的Unicode字符的域名。<br/>
> conversionProcess设置为USE_STD3_ASCII_RULES时，会在转换过程中强制按照STD-3 ASCII规则（即RFC 1123标准）对生成的ASCII域名进行检查。<br/>
> 传入参数中的数字和英文不做转码。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ---- | ----------------- |
| host | string | 是 | 要转换的主机名（host）。每个标签（点分隔的部分）长度不超过63字节。 |
| flag | [ConversionProcess](#conversionprocess23) | 否 | 转换流程参数，默认值为NO_CONFIGURATION。 |

**返回值：**

| 类型 | 说明 |
| -------- | ------------------------ |
| string | 返回转换结果。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------- |
| 2100001 | Invalid parameter value. |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error. |

**示例：**

```typescript
import { connection } from '@kit.NetworkKit';

let result = connection.getDnsAscii("www.示例.com", connection.ConversionProcess.NO_CONFIGURATION);
console.info("Succeeded to getDnsAscii: " + result);  // 预期结果：www.xn--fsq092h.com
let result = connection.getDnsAscii("www.example.com", connection.ConversionProcess.NO_CONFIGURATION);
console.info("Succeeded to getDnsAscii: " + result);  // 预期结果：www.example.com
```

## connection.getDnsUnicode<sup>23+</sup>

getDnsUnicode(host: string, flag?: ConversionProcess): string

使用Punycode编码方式，将ASCII编码形式的主机名转换为Unicode编码形式，并通过可选的conversionProcess参数控制转换行为。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ---- | ----------------- |
| host | string | 是 | 要转换的主机名（host）。 |
| flag | [ConversionProcess](#conversionprocess23) | 否 | 转换流程参数，默认值为NO_CONFIGURATION。 |

**返回值：**

| 类型 | 说明 |
| -------- | ------------------------ |
| string | 返回转换结果。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------- |
| 2100001 | Invalid parameter value. |
| 2100002 | Failed to connect to the service. |
| 2100003 | System internal error. |

**示例：**

```typescript
import { connection } from '@kit.NetworkKit';

let result = connection.getDnsUnicode("www.xn--fsq092h.com", connection.ConversionProcess.NO_CONFIGURATION);
console.info("Succeeded to getDnsUnicode: " + result);  // 预期结果：www.示例.com
let result = connection.getDnsUnicode("www.example.com", connection.ConversionProcess.NO_CONFIGURATION);
console.info("Succeeded to getDnsUnicode: " + result);  // 预期结果：www.example.com
```

## connection.getSystemNetPortStates<sup>24+</sup>

getSystemNetPortStates(): Promise\<NetPortStatesInfo>

获取系统当前监听的所有TCP、UDP端口信息，以及监听端口进程的PID、UID，支持IPv4和IPv6。  

> **说明：**
>
> 该接口获取系统当前监听的TCP、UDP端口信息，详细字段包括：
>
>  TCP端口字段：本地地址、本地端口、远端地址、远端端口、TCP连接状态、进程PID、进程UID  
>
>  UDP端口字段：本地地址、本地端口、进程PID 、进程UID  

**需要权限**：ohos.permission.GET_IP_MAC_INFO

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型   | 说明                     |
| ------ | ----------------------- |
| Promise\<[NetPortStatesInfo](#netportstatesinfo24)> | Promise对象，返回系统当前监听的TCP、UDP端口信息。|


**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getSystemNetPortStates().then((data: connection.NetPortStatesInfo) => {
  console.info(`Succeeded to get data: ${JSON.stringify(data)}`);
  if (data.tcpPortStatesInfo?.length) {
    data.tcpPortStatesInfo?.forEach(item => {
      console.info(`Succeeded to get Tcp data: ${JSON.stringify(item)}`);
    })
  } else {
    console.info("TcpPortStatesInfo is undefined ");
  }
  if (data.udpPortStatesInfo?.length) {
    data.udpPortStatesInfo?.forEach(item => {
      console.info(`Succeeded to get Udp data: ${JSON.stringify(item)}`);
    })
  } else {
    console.info("UdpPortStatesInfo is undefined ");
  }
}).catch((error: BusinessError) => {
  console.error(`Error fetching getSystemNetPortStates. Code:${error.code}, message:${error.message}`);
});
```

## connection.queryTraceRoute

queryTraceRoute(destination: string, option?: TraceRouteOptions): Promise\<TraceRouteInfo[]\>

查询网络路由跟踪信息，使用Promise方式作为异步方法。

> **说明：**
>
> 应用调用该接口需申请精确位置权限。<!--RP1-->根据[申请位置权限开发指导](../../device/location/location-permission-guidelines.md)<!--RP1End-->，调用方需同时申请ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION。

**起始版本**：26.0.0

**需要权限**：ohos.permission.INTERNET、ohos.permission.ACCESS_NET_TRACE_INFO、ohos.permission.LOCATION和ohos.permission.APPROXIMATELY_LOCATION

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| destination | string | 是 | 目标域名或IP地址，例如www.example.com、8.8.8.8。 |
| option | [TraceRouteOptions](#tracerouteoptions) | 否 | 路由跟踪的选项参数，缺省则使用默认配置。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<[TraceRouteInfo](#tracerouteinfo)[]\> | Promise对象，返回路由跟踪信息数组。 |

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 2100001 | Invalid parameter value. |
| 2100003 | Internal error. |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dest: string = "www.example.com";
let options: connection.TraceRouteOptions = {
    maxJumpNumber: 30,
    packetsType: connection.PacketsType.NETCONN_PACKETS_ICMP
};

connection.queryTraceRoute(dest, options).then((data: connection.TraceRouteInfo[]) => {
    console.info('Succeeded to getDefaultHttpProxy:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
    console.error(`Failed to get request. Code:${err.code}, message:${err.message}`);
});
```


## connection.queryProbeResult

queryProbeResult(destination: string, duration: number): Promise\<ProbeResultInfo\>

查询网络探测结果。若出现异常（例如断网），导致发送请求失败，则接口会立即返回，不再进行后续探测。本接口使用Promise方式作为异步方法。

> **说明：**
>
> 此接口用于对目标主机进行一段持续时间的网络探测，以获取丢包率和RTT信息。

**起始版本**：26.0.0

**需要权限**：ohos.permission.INTERNET。

**系统能力：** SystemCapability.Communication.NetManager.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| destination | string | 是 | 目标域名或IP地址，例如www.example.com、8.8.8.8。 |
| duration | number | 是 | 探测持续时间，单位为秒，取值范围\[1, 1000\]。探测间隔为1秒。若未出现异常（例如断网），探测时间到期后返回探测结果。该字段表示探测持续总时长，设置过长可能导致长时间占用应用线程资源。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<[ProbeResultInfo](#proberesultinfo)\> | Promise对象，返回探测结果信息。 |

**错误码：**
以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。
  
| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 2100001 | Invalid parameter value. |
| 2100003 | Internal error. |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dest: string = "www.example.com";
let duration: number = 10;

connection.queryProbeResult(dest, duration).then((data: connection.ProbeResultInfo) => {
    console.info(`Succeeded to get LossRate: ${data.lossRate}, Succeeded to getRTT: ${data.rtt}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to get request. Code:${err.code}, message:${err.message}`);
});
```

## connection.refreshGlobalHttpProxy

refreshGlobalHttpProxy(): Promise\<HttpProxy\>

通知系统重新认证全局代理。

>**说明：**
>
>若当前未配置全局代理或代理配置信息有误（例如未正确配置username和password），则会抛出2100003错误码。可通过[getDefaultHttpProxy](#connectiongetdefaulthttpproxy10)接口查询当前代理配置信息。

**起始版本**：26.0.0

**需要权限**：ohos.permission.INTERNET

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型   | 说明                     |
| ------ | ----------------------- |
| Promise\<[HttpProxy](#httpproxy10)\> | Promise对象，返回全局代理配置信息。其中username和password字段固定为空字符串，不返回有效信息。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                          |
| ------- | --------------------------------- |
| 201     | Permission denied.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.            |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.refreshGlobalHttpProxy().then((data: connection.HttpProxy) => {
  console.info(`Succeeded to refresh global http proxy: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
  console.error(`Failed to refresh global http proxy. Code:${error.code}, message:${error.message}`);
});
```

## NetConnection

网络连接对象类型。

> **说明：**
>
>（1）设备从无网络状态转变为有网络状态时，将触发[on('netAvailable')](#onnetavailable)事件、[on('netCapabilitiesChange')](#onnetcapabilitieschange)事件和[on('netConnectionPropertiesChange')](#onnetconnectionpropertieschange)事件；
>
>（2）接收到[on('netAvailable')](#onnetavailable)事件后，若设备从有网络状态转变为无网络状态，将触发[on('netLost')](#onnetlost)事件；
>
>（3）若未接收到[on('netAvailable')](#onnetavailable)事件，则将直接接收到[on('netUnavailable')](#onnetunavailable)事件；
>
>（4）设备从WiFi网络切换至蜂窝网络时，将先触发[on('netLost')](#onnetlost)事件（WiFi丢失），随后触发[on('netAvailable')](#onnetavailable)事件（蜂窝可用）。

### register

register(callback: AsyncCallback\<void>): void

订阅指定网络状态变化的通知。如需监听特定事件，确保调用on监听事件后再调用register进行注册。

>**注意：**
>
>使用完register接口后需要及时调用[unregister](#unregister)取消注册。

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
  console.error(`Failed to register.Code:${error.code}, message:${error.message}`);
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
  console.error(`Failed to unregister.Code:${error.code}, message:${error.message}`);
});
```

### on('netAvailable')

on(type: 'netAvailable', callback: Callback\<NetHandle>): void

订阅网络可用事件。此接口需在调用[register](#register)接口之前调用。若无需接收网络状态变化的回调通知，应使用[unregister](#unregister)取消订阅默认的网络状态变化通知。

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

// 先使用on接口订阅网络可用事件。
netCon.on('netAvailable', (data: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 注册网络状态变化事件。此接口要在调用on后调用。
netCon.register((error: BusinessError) => {
  console.error(`Failed to register.Code:${error.code}, message:${error.message}`);
});

// 使用unregister接口取消订阅网络可用事件。
netCon.unregister((error: BusinessError) => {
  console.error(`Failed to unregister.Code:${error.code}, message:${error.message}`);
});
```

### on('netBlockStatusChange')

on(type: 'netBlockStatusChange', callback: Callback\<NetBlockStatusInfo>): void

订阅网络阻塞状态事件。此接口需要在调用[register](#register)接口之前调用。若无需接收网络状态变化的回调通知，应使用[unregister](#unregister)取消订阅默认的网络状态变化通知。

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

// 先使用on接口订阅网络阻塞状态事件。
netCon.on('netBlockStatusChange', (data: connection.NetBlockStatusInfo) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 注册网络状态变化事件。此接口要在调用on后调用。
netCon.register((error: BusinessError) => {
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});

// 使用unregister接口取消订阅网络阻塞状态事件。
netCon.unregister((error: BusinessError) => {
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});
```

### on('netCapabilitiesChange')

on(type: 'netCapabilitiesChange', callback: Callback\<NetCapabilityInfo\>): void

订阅网络能力变化事件。此接口要在[register](#register)接口调用前调用，不需要网络状态变化回调通知时，使用[unregister](#unregister)取消订阅默认网络状态变化的通知。

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

// 先使用on接口订阅网络能力变化事件。
netCon.on('netCapabilitiesChange', (data: connection.NetCapabilityInfo) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 注册网络状态变化事件。此接口要在调用on后调用。
netCon.register((error: BusinessError) => {
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});

// 使用unregister接口取消订阅网络能力变化事件。
netCon.unregister((error: BusinessError) => {
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});
```

### on('netConnectionPropertiesChange')

on(type: 'netConnectionPropertiesChange', callback: Callback\<NetConnectionPropertyInfo\>): void

订阅网络连接信息变化事件。此接口要在[register](#register)接口调用前调用，不需要网络状态变化回调通知时，使用[unregister](#unregister)取消订阅默认网络状态变化的通知。

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

// 先使用on接口订阅网络连接信息变化事件。
netCon.on('netConnectionPropertiesChange', (data: connection.NetConnectionPropertyInfo) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 注册网络状态变化事件。此接口要在调用on后调用。
netCon.register((error: BusinessError) => {
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});

// 使用unregister接口取消订阅网络连接信息变化事件。
netCon.unregister((error: BusinessError) => {
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});
```

### on('netLost')

on(type: 'netLost', callback: Callback\<NetHandle>): void

订阅网络丢失事件。此接口要在[register](#register)接口调用前调用，不需要网络状态变化回调通知时，使用[unregister](#unregister)取消订阅默认网络状态变化的通知。

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

// 先使用on接口订阅网络丢失事件。
netCon.on('netLost', (data: connection.NetHandle) => {
  console.info("Succeeded to get data: " + JSON.stringify(data));
});

// 注册网络状态变化事件。此接口要在调用on后调用。
netCon.register((error: BusinessError) => {
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});

// 使用unregister接口取消订阅网络丢失事件。
netCon.unregister((error: BusinessError) => {
  console.error(`Failed to get request.Code:${error.code}, message:${error.message}`);
});
```

### on('netUnavailable')

on(type: 'netUnavailable', callback: Callback\<void>): void

订阅网络不可用事件。此接口要在[register](#register)接口调用前调用，不需要网络状态变化回调通知时，使用[unregister](#unregister)取消订阅默认网络状态变化的通知。

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

// 先使用on接口订阅网络不可用事件。
netCon.on('netUnavailable', () => {
  console.info("Succeeded to get unavailable net event");
});

// 注册网络状态变化事件。此接口要在调用on后调用。
netCon.register((error: BusinessError) => {
  console.error(`Failed to get register.Code:${error.code}, message:${error.message}`);
});

// 使用unregister接口取消订阅网络不可用事件。
netCon.unregister((error: BusinessError) => {
  console.error(`Failed to get unregister.Code:${error.code}, message:${error.message}`);
});
```

## NetHandle

网络句柄。

在调用NetHandle的方法之前，需要先获取NetHandle对象。例如可通过[getDefaultNet](#connectiongetdefaultnet)获取系统当前默认网络的网络句柄。

**系统能力**：SystemCapability.Communication.NetManager.Core

### 属性

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| netId  | number | 否 | 否  |  网络ID，取值为0代表没有默认网络，其余有效取值必须大于等于100。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |

### bindSocket<sup>9+</sup>

bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void

将TCPSocket或UDPSocket绑定到当前NetHandle对应的网络。使用callback异步回调。

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
        console.error(`Failed to bind. Code:${error.code}, message:${error.message}`);
        return;
      }
      netHandle.bindSocket(tcp, (error: BusinessError, data: void) => {
        if (error) {
          console.error(`Failed to bind socket. Code:${error.code}, message:${error.message}`);
          return;
        } else {
          console.info('Succeeded to getdefaultHttpProxy:' + JSON.stringify(data));
        }
      });
    });
  } else {
    let callback: (value: Data) => void = (value: Data) => {
      console.info("Succeeded to get message, message:" + value.message + ", Succeeded to get remoteInfo:" + value.remoteInfo);
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
          console.info('Succeeded to get defaultHttpProxy: ' + JSON.stringify(data));
        }
      });
    });
  }
})
```

### bindSocket<sup>9+</sup>

bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void\>

将TCPSocket或UDPSocket绑定到当前NetHandle对应的网络。使用Promise异步回调。

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
        console.error('Failed to bind');
        return;
      }
      netHandle.bindSocket(tcp).then(() => {
        console.info("Succeeded to bind socket");
      }).catch((error: BusinessError) => {
        console.error(`Failed to bind socket. Code:${error.code}, message:${error.message}`);
      });
    });
  } else {
    let callback: (value: Data) => void = (value: Data) => {
      console.info("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
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
        console.info("Succeeded to bind socket");
      }).catch((error: BusinessError) => {
        console.error(`Failed to bind socket. Code:${error.code}, message:${error.message}`);
      });
    });
  }
});
```

### getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>\>\): void

使用当前NetHandle对应的网络解析主机名获取到的所有IP地址。使用callback异步回调。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| host     | string                                            | 是   | 需要解析的主机名。例如："www.example.com"。                                           |
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
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let host = "www.example.com";
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

使用当前NetHandle对应的网络解析主机名获取到的所有IP地址。使用Promise异步回调。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。例如："www.example.com"。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | Promise对象，返回所有IP地址。 |

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
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let host = "www.example.com";
  netHandle.getAddressesByName(host).then((data: connection.NetAddress[]) => {
    console.info("Succeeded to get data: " + JSON.stringify(data));
  });
});
```

### getAddressesByNameWithOptions<sup>23+</sup>

getAddressesByNameWithOptions(host: string, option?: QueryOptions): Promise\<Array\<NetAddress\>\>

使用当前NetHandle对应的网络基于指定IP类型进行DNS解析。使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。例如："www.example.com"。 |
| option | [QueryOptions](#queryoptions23) | 否   | 需要查询的IP类型。 |

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | Promise对象，返回查询到的IP地址。返回值中的port字段固定为0，无需关注。|

**错误码：**

以下错误码的详细介绍请参见[网络连接管理错误码](errorcode-net-connection.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service. |
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
  let host = "www.example.com";
  let option: connection.QueryOptions = {
      family: connection.FamilyType.FAMILY_TYPE_IPV4
    };
  netHandle.getAddressesByNameWithOptions(host, option).then((data: connection.NetAddress[]) => {
    console.info(`Succeeded to get data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get addresses by name. Code:${err.code}, message:${err.message}`);
  });
});
```

### getAddressByName

getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void

使用当前NetHandle对应的网络解析主机名获取到的第一个IP地址。使用callback异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| host     | string                                    | 是   | 需要解析的主机名。例如："www.example.com"。                                           |
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
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let host = "www.example.com";
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

使用当前NetHandle对应的网络解析主机名获取到的第一个IP地址。使用Promise异步回调。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| host   | string | 是   | 需要解析的主机名。例如："www.example.com"。 |

**返回值：**

| 类型                                | 说明                            |
| ----------------------------------- | ------------------------------- |
| Promise\<[NetAddress](#netaddress)> | Promise对象，返回获取到的第一个IP地址。 |

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
    // 当前没有已连接的网络时，netHandle的netId为0，属于异常场景。可根据实际情况添加处理机制。
    return;
  }
  let host = "www.example.com";
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

## ConversionProcess<sup>23+</sup>

ASCII/Unicode转码转换流程参数的枚举。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称 | 值 | 说明 |
| ---------------- | --------------- | --------------------------- |
| NO_CONFIGURATION | 0 | 仅允许转换已分配的Unicode代码点的域名（Unicode为每个字符分配一个唯一的数字，这个数字就叫做代码点）。 |
| ALLOW_UNASSIGNED | 1 | 允许转换包含未分配Unicode代码点的域名(在Unicode字符集中，并非所有代码点都已分配字符，即未分配Unicode代码点)。 |
| USE_STD3_ASCII_RULES | 2 | 在转换过程中，强制使用STD-3 ASCII规则（即RFC 1123标准）检查生成的ASCII域名。 |

## TcpState<sup>24+</sup>

TCP状态。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

|            名称         | 值   | 说明        |
| ----------------------- | ---- | ---------- |
| TCP_ESTABLISHED | 1  | 连接已建立，可正常收发数据。  |
| TCP_SYN_SENT    | 2  | 客户端发送SYN，等待服务端ACK+SYN（三次握手的第一步）。 |
| TCP_SYN_RECV    | 3  | 服务端接收SYN并发送ACK+SYN，等待客户端ACK（三次握手的第二步）。 |
| TCP_FIN_WAIT1   | 4  | 主动端发送FIN，等待对方ACK。 |
| TCP_FIN_WAIT2   | 5  | 主动端接收FIN的ACK，等待对方ACK。 |
| TCP_TIME_WAIT   | 6  | 主动端接收对方FIN并回复ACK，等待2倍最大报文段生存时间后彻底释放。 |
| TCP_CLOSE       | 7  | 初始/关闭状态，无连接。 |
| TCP_CLOSE_WAIT  | 8  | 被动端接收FIN并发送ACK，等待对方FIN。 |
| TCP_LAST_ACK    | 9  | 被动端发送FIN后，等待对方ACK。 |
| TCP_LISTEN      | 10 | 服务端监听，等待客户端连接。 |
| TCP_CLOSING     | 11 | 双方同时发送FIN，互相等待ACK。   |
  
  ## PacketsType

网络探测数据包类型。

**起始版本**：26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。
  
**系统能力：** SystemCapability.Communication.NetManager.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NETCONN_PACKETS_ICMP | 0 | ICMP数据包类型。 |
| NETCONN_PACKETS_UDP | 1 | UDP数据包类型。 |

## HttpProxy<sup>10+</sup>

网络代理配置信息

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| host  | string | 否  | 否 |代理服务器主机名。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| port  | number | 否  |否  |主机端口。取值范围[0,65535]。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| exclusionList  | Array\<string\> | 否  |否 |不使用代理的主机名列表，主机名支持域名、IP地址以及通配符形式，详细匹配规则如下：<br/>1、域名匹配规则：<br/>（1）完全匹配：代理服务器主机名只要与列表中的任意一个主机名完全相同，就可以匹配。<br/>（2）包含匹配：代理服务器主机名只要包含列表中的任意一个主机名，就可以匹配。<br/>例如，如果在主机名列表中设置了 “ample.com”，则  “ample.com”、“www.ample.com”、“ample.com:80”都会被匹配，而 “www.example.com”、“ample.com.org”则不会被匹配。<br/>2、IP地址匹配规则：代理服务器主机名只要与列表中的任意一个IP地址完全相同，就可以匹配。<br/>3、域名跟IP地址可以同时添加到列表中进行匹配。<br/>4、单个“\*”是唯一有效的通配符，当列表中只有通配符时，将与所有代理服务器主机名匹配，表示禁用代理。通配符只能单独添加，不可以与其他域名、IP地址一起添加到列表中，否则通配符将不生效。<br/>5、匹配规则不区分主机名大小写。<br/>6、匹配主机名时，不考虑http和https等协议前缀。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| username<sup>12+</sup>  | string | 否 |是  |使用代理的用户名。<br>**说明:** 需同时设置password参数才会生效。|
| password<sup>12+</sup>  | string | 否 | 是| 使用代理的用户密码。<br>**说明:** 需同时设置username参数才会生效。|

## Socks5DnsStrategy

SOCKS5代理的DNS查询策略配置信息。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称             | 值   | 说明                     |
| --------------- | ------ | ------------------------ |
| SYSTEM_MODE     | 0 | 使用SOCKS5代理时，DNS解析由系统执行。|
| PROXY_MODE      | 1 | 使用SOCKS5代理时，DNS解析由代理服务器执行。|

## Socks5Proxy

SOCKS5代理配置信息。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| host  | string | 否  | 否 |代理服务器主机名。<br>**说明:** 当该项为空字符串时，视为未配置SOCKS5代理。|
| port  | number | 否  |否  |主机端口。取值范围[0, 65535]。<br>**说明:** 当参数不在上述取值范围时，视为未配置SOCKS5代理。 |
| username | string | 否 |是  |使用代理的用户名。<br>**说明:** 需同时设置password参数才会生效。|
| password | string | 否 | 是| 使用代理的用户密码。<br>**说明:** 需同时设置username参数才会生效。|
| dnsStrategy | [Socks5DnsStrategy](#socks5dnsstrategy) | 否 | 是 | 指定DNS解析由系统执行还是由代理服务器执行。<br>**说明:** 当此项未指定时，如果host有`socks5h://`协议前缀，则DNS解析由代理服务器执行，否则DNS解析由系统执行。 |
| exclusionList  | Array\<string\> | 否  |是 |不使用代理的主机名列表，主机名支持域名、IP地址以及通配符形式，详细匹配规则如下：<br/>1、域名匹配规则：<br/>（1）完全匹配：代理服务器主机名只要与列表中的任意一个主机名完全相同，就可以匹配。<br/>（2）包含匹配：代理服务器主机名只要包含列表中的任意一个主机名，就可以匹配。<br/>例如，如果在主机名列表中设置了“example.com”，则“example.com”、“www.example.com”、“example.com:80”都会被匹配，而 “www.myexample.com”、“myexample.com.org”则不会被匹配。<br/>2、IP地址匹配规则：代理服务器主机名只要与列表中的任意一个IP地址完全相同，就可以匹配。<br/>3、域名跟IP地址可以同时添加到列表中进行匹配。<br/>4、单个“\*”是唯一有效的通配符，当列表中只有通配符时，将与所有代理服务器主机名匹配，表示禁用代理。通配符只能单独添加，不可以与其他域名、IP地址一起添加到列表中，否则通配符将不生效。<br/>5、匹配规则不区分主机名大小写。<br/>6、匹配主机名时，不考虑http、https、socks5、socks5h等协议前缀。 |

## NetSpecifier

提供承载数据网络能力的实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| netCapabilities         | [NetCapabilities](#netcapabilities) |  否 | 否  | 存储数据网络的传输能力和承载类型。                                |
| bearerPrivateIdentifier | string                              |  否 | 是  |  网络标识符，蜂窝网络的标识符是"slot0"（对应SIM卡1）、"slot1"（对应SIM卡2）。从API12开始可以通过传递注册的WLAN热点信息表示应用希望激活的指定的WLAN网络。 |

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
   console.error(`Failed to get register.Code:${error.code}, message:${error.message}`);
 });
});
```

## NetCapabilityInfo<sup>10+</sup>

提供承载数据网络能力的实例。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| netHandle               | [NetHandle](#nethandle)              |  否 | 否  | 网络句柄。                                                |
| netCap                  |  [NetCapabilities](#netcapabilities) |  否 | 否  |  存储数据网络的传输能力和承载类型。                            |

## NetCapabilities

网络的能力集。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| linkUpBandwidthKbps   | number                             |  否 | 是  |  上行（设备到网络）带宽，单位(Kbps，千比特每秒)。0表示无法评估当前网络带宽。|
| linkDownBandwidthKbps | number                             |  否 | 是 |  下行（网络到设备）带宽，单位(Kbps，千比特每秒)。0表示无法评估当前网络带宽。|
| networkCap            | Array\<[NetCap](#netcap)>           |  否 | 是 |  网络具体能力。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。           |
| bearerTypes           | Array\<[NetBearType](#netbeartype)> |  否 | 否 |  网络类型。数组里面只包含了一种网络类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。      |

## NetConnectionPropertyInfo<sup>11+</sup>

网络连接信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

### 属性

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| netHandle            | [NetHandle](#nethandle)                             | 否 | 否   |网络句柄。|
| connectionProperties | [ConnectionProperties](#connectionproperties)       | 否 | 否   |网络连接信息。           |

## NetBlockStatusInfo<sup>11+</sup>

获取网络状态信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

### 属性

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| netHandle            | [NetHandle](#nethandle)               | 否 | 否   |网络句柄。   |
| blocked              | boolean                               | 否 | 否   | 标识当前网络是否是堵塞状态。true：标识当前网络是堵塞状态；false：标识当前网络不是堵塞状态。 |

## ConnectionProperties

网络连接信息。
>**注意：**
>
> linkAddresses、routes和dnses可能为空，需要做好空值保护，建议使用前先判断对象是否存在。  

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 | 说明                                                                                             |
| ------ | ------ | --- |---|------------------------------------------------------------------------------------------------|
| interfaceName | string                              | 否 | 否 | 网卡名称。                                                                                          |
| domains       | string                              | 否 | 否 | 域名。                                                                                            |
| linkAddresses | Array\<[LinkAddress](#linkaddress)> | 否 | 否 | 链路信息。                                                                                          |
| routes        | Array\<[RouteInfo](#routeinfo)>     | 否 | 否 | 路由信息。                                                                                          |
| dnses         | Array\<[NetAddress](#netaddress)>   | 否 | 否 | 网络地址，参考[NetAddress](#netaddress)。                                                              |
| mtu           | number                              | 否 | 否 | 最大传输单元。                                                                                        |
| isIPv4LinkValid<sup>24+</sup> | boolean                             | 否 | 是 | 当前网络的IPv4是否可用。true：当IPv4地址有效，且存在IPv4的默认路由时，认为IPv4可用；false：当IPv4地址无效，或者不存在IPv4的默认路由时，认为IPv4不可用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| isIPv6LinkValid<sup>24+</sup> | boolean                             | 否 | 是 | 当前网络的IPv6是否可用。true：当IPv6地址有效，且存在IPv6的默认路由时，认为IPv6可用；false：当IPv6地址无效，或者不存在IPv6的默认路由时，认为IPv6不可用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## RouteInfo

网络路由信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| interface      | string                      | 否 | 否 |网卡名称。       |
| destination    | [LinkAddress](#linkaddress) | 否 | 否 |目的地址。       |
| gateway        | [NetAddress](#netaddress)   | 否 | 否 |网关地址。       |
| hasGateway     | boolean                     | 否 | 否 | 是否有网关。true：有网关；false：无网关。     |
| isDefaultRoute | boolean                     | 否 | 否 | 是否为默认路由。true：默认路由；false：非默认路由。<br>  **说明：** IPv4默认路由是指目的地址为0.0.0.0/0的路由；IPv6默认路由是指目的地址为::/0的路由。 |
| isExcludedRoute<sup>20+</sup>| boolean                     | 否 | 是 |是否为排除路由。true表示排除路由，false表示非排除路由，默认值为false。|

## LinkAddress

网络链路信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| address      | [NetAddress](#netaddress) | 否 | 否  | 链路地址。           |
| prefixLength | number                    | 否 | 否  |链路地址前缀的长度。  |

## NetAddress

网络地址。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| address | string | 否 | 否 |地址。                       |
| family  | number | 否 | 是 |IPv4 = 1，IPv6 = 2，默认IPv4。|
| port    | number | 否 | 是 |端口，取值范围\[0, 65535]，默认值为0。  |

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

定义一个TCPSocket对象，可以通过[socket.constructTCPSocketInstance](js-apis-socket.md#socketconstructtcpsocketinstance)创建。

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


## NetIpMacInfo<sup>22+</sup>

IP邻居表条目信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| ipAddress | [NetAddress](#netaddress)     | 否 | 否 |IP地址相关信息。   |
| iface       | string                              | 否 | 否 |网卡名。                                    |
| macAddress | string | 否 | 否 |MAC地址。                                |

## ProtocolType<sup>23+</sup>

网络协议类型的枚举。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称            | 值   | 说明          |
| --------------- | ---- | ------------ |
| PROTO_TYPE_TCP  | 6    | TCP网络协议。 |
| PROTO_TYPE_UDP  | 17   | UDP网络协议。 |

## TcpNetPortStatesInfo<sup>24+</sup>

TCP端口状态信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| tcpLocalIp    | string | 否 | 否 |TCP网络本地IP地址。                       |
| tcpLocalPort  | number | 否 | 否 |TCP网络本地端口，取值范围\[0, 65535]。 |
| tcpRemoteIp   | string | 否 | 否 |TCP网络远程IP地址。  |
| tcpRemotePort | number | 否 | 否 |TCP网络远程端口，取值范围\[0, 65535]。 |
| tcpUid        | number | 否 | 否 |监听该TCP端口的用户UID。 |
| tcpPid        | number | 否 | 否 |监听该TCP端口的进程PID。 |
| tcpState      | [TcpState](#tcpstate24) | 否 | 否 |TCP网络状态。  |


## UdpNetPortStatesInfo<sup>24+</sup>

UDP端口状态信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| udpLocalIp    | string | 否 | 否 |UDP网络本地IP地址。                       |
| udpLocalPort  | number | 否 | 否 |UDP网络本地端口，取值范围\[0, 65535]。 |
| udpUid        | number | 否 | 否 |监听该UDP端口的用户UID。 |
| udpPid        | number | 否 | 否 |监听该UDP端口的进程PID。 |


## NetPortStatesInfo<sup>24+</sup>

系统当前监听的TCP、UDP端口信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称    | 类型   | 只读|可选 |说明                      |
| ------ | ------ | --- |---|------------------------- |
| tcpPortStatesInfo | Array\<[TcpNetPortStatesInfo](#tcpnetportstatesinfo24)\> | 否 | 是 | 系统当前监听的TCP信息。   |
| udpPortStatesInfo | Array\<[UdpNetPortStatesInfo](#udpnetportstatesinfo24)\> | 否 | 是 | 系统当前监听的UDP信息。   |
  
 
## TraceRouteOptions

路由跟踪的选项。

**起始版本**：26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。
  
**系统能力：** SystemCapability.Communication.NetManager.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| maxJumpNumber | number | 否 | 是 | 最大跳数，取值范围\[1, 30\]，默认值为30。 |
| packetsType | [PacketsType](#packetstype) | 否 | 是 | 探测使用的数据包类型，默认为NETCONN_PACKETS_ICMP。 |
  

## TraceRouteInfo

路由跟踪信息。

**起始版本**：26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。
  
**系统能力：** SystemCapability.Communication.NetManager.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| jumpNo | number | 否 | 否 | 跳数序号。 |
| address | string | 否 | 否 | 该跳的IP地址。 |
| rtt | number[] | 否 | 否 | 往返时间（RTT），单位为毫秒。每一跳发送5个探测报文，数组元素依次为这些探测报文RTT中的最小值、平均值、最大值、标准差。 |
  

## ProbeResultInfo

网络探测结果信息。

**起始版本**：26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。
  
**系统能力：** SystemCapability.Communication.NetManager.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| lossRate | number | 否 | 否 | 丢包率，取值范围\[0, 100\]。例如，100表示100%丢包，50表示50%丢包。 |
| rtt | number[] | 否 | 否 | 往返时间（RTT），单位为毫秒。对目的主机发送多个探测报文，探测报文数量由[queryProbeResult](#connectionqueryproberesult)接口中duration参数决定。数组元素依次为这些探测报文RTT中最小值、平均值、最大值、标准差。 |