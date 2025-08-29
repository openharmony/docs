# @ohos.net.connection (网络连接管理)（系统接口）

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

网络连接管理提供管理网络一些基础能力，包括获取默认激活的数据网络、获取所有激活数据网络列表、开启关闭飞行模式、获取网络能力信息等功能。

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.net.connection (网络连接管理)](js-apis-net-connection.md)。

## 导入模块

```ts
import { connection } from '@kit.NetworkKit';
```


## connection.getGlobalHttpProxy<sup>10+</sup>

getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void

获取网络的全局代理配置信息，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[HttpProxy](js-apis-net-connection.md#httpproxy10)> | 是   | 回调函数。当成功获取网络的全局代理配置信息时，error为undefined，data为网络的全局代理配置信息；否则为错误对象。|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 202     | Non-system applications use system APIs.             |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getGlobalHttpProxy((error: BusinessError, data: connection.HttpProxy) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## connection.getGlobalHttpProxy<sup>10+</sup>

getGlobalHttpProxy(): Promise\<HttpProxy>;

获取网络的全局代理配置信息，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[HttpProxy](js-apis-net-connection.md#httpproxy10)> | 以Promise形式返回网络的全局代理配置信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 202     | Non-system applications use system APIs.             |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.getGlobalHttpProxy().then((data: connection.HttpProxy) => {
  console.info(JSON.stringify(data));
}).catch((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
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
| httpProxy | [HttpProxy](js-apis-net-connection.md#httpproxy10) | 是   | 网络全局Http代理配置信息。                                  |
| callback  | AsyncCallback\<void>    | 是   | 回调函数。当成功设置网络全局Http代理配置信息时，error为undefined，否则为错误对象。|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 202     | Non-system applications use system APIs.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let exclusionStr = "192.168,baidu.com";
let exclusionArray = exclusionStr.split(',');
let httpProxy: connection.HttpProxy = {
    host: "192.168.xx.xxx",
    port: 8080,
    exclusionList: exclusionArray
}
connection.setGlobalHttpProxy(httpProxy, (err: BusinessError) => {
    if (err) {
        console.error(`setGlobalHttpProxy failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setGlobalHttpProxy success.`);
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
| httpProxy | [HttpProxy](js-apis-net-connection.md#httpproxy10)                                      | 是   | 网络全局Http代理配置信息。 |

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
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let exclusionStr = "192.168,baidu.com";
let exclusionArray = exclusionStr.split(',');
connection.setGlobalHttpProxy({
  host: "192.168.xx.xxx",
  port: 8080,
  exclusionList: exclusionArray
} as connection.HttpProxy).then(() => {
  console.info("success");
}).catch((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```


## connection.enableAirplaneMode

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
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.enableAirplaneMode((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## connection.enableAirplaneMode

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
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.enableAirplaneMode().then((error: void) => {
  console.error(JSON.stringify(error));
});
```

## connection.disableAirplaneMode

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
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.disableAirplaneMode((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## connection.disableAirplaneMode

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
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.disableAirplaneMode().then((error: void) => {
  console.error(JSON.stringify(error));
});
```


## connection.factoryReset<sup>11+</sup>

factoryReset(): Promise\<void\>

出厂重置网络设置，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                   | 说明                    |
| ---------------------- | ----------------------- |
| Promise\<void\>        | 无返回值的Promise对象。  |

**错误码：**

| 错误码ID | 错误信息                                    |
| ------- | ------------------------------------------  |
| 201     | Permission denied.                          |
| 202     | Non-system applications use system APIs.    |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.                      |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.factoryReset().then(() => {
    console.log("success");
}).catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
})
```

## ProxyMode<sup>20+</sup>

表示代理模式的枚举。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称              | 值   | 说明                     |
| -------------------- | ------ | ------------------------ |
| PROXY_MODE_OFF     | 0 | 关闭代理模式。          |
| PROXY_MODE_AUTO    | 1 | 自动代理模式。          |

## connection.setProxyMode<sup>20+</sup>

setProxyMode(mode: ProxyMode): Promise\<void\>

设置代理模式。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型             | 必填 | 说明               |
| ------ |----------------| ---- | ------------------ |
| mode   | [ProxyMode](#proxymode20) | 是   | 指定的代理模式。   |

**返回值：**

| 类型 | 说明                     |
| -------- | ------------------------ |
| Promise\<void\> | Promise对象，无返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息          |
|-------|---------------|
| 201   | Permission denied.   |
| 202   | Non-system applications use system APIs. |



**示例：**

```ts
import { connection, ProxyMode } from '@kit.NetworkKit';

connection.setProxyMode(ProxyMode.AUTO).then(() => {
    console.log("Proxy mode set successfully.");
}).catch(error => {
    console.error("Error setting proxy mode:", error);
});
```

## connection.getProxyMode<sup>20+</sup>

getProxyMode(): Promise\<ProxyMode\>

获取当前的代理模式。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                        | 说明                          |
|---------------------------| ------------------------ |
| Promise\<[ProxyMode](#proxymode20)\> | 返回的Promise对象，包含当前代理模式。 |


**示例：**

```ts
import { connection } from '@kit.NetworkKit';

connection.getProxyMode().then(mode => {
    console.log("Current proxy mode:", mode);
}).catch(error => {
    console.error("Error getting proxy mode:", error);
});
```
