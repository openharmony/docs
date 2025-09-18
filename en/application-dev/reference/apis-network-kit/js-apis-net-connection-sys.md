# @ohos.net.connection (Network Connection Management) (System API)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

The network connection management module provides basic network management capabilities. You can obtain the default active data network or the list of all active data networks, enable or disable the airplane mode, and obtain network capability information.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.net.connection (Network Connection Management)](js-apis-net-connection.md).

## Modules to Import

```ts
import { connection } from '@kit.NetworkKit';
```


## connection.getGlobalHttpProxy<sup>10+</sup>

getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void

Obtains the global HTTP proxy configuration of the network. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[HttpProxy](js-apis-net-connection.md#httpproxy10)> | Yes  | Callback used to return the result. If the global HTTP proxy configuration of the network is obtained successfully, **error** is **undefined** and **data** is the global HTTP proxy configuration. Otherwise, **error** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 202     | Non-system applications use system APIs.             |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**Example**

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

Obtains the global HTTP proxy configuration of the network. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[HttpProxy](js-apis-net-connection.md#httpproxy10)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 202     | Non-system applications use system APIs.             |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**Example**

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

Sets the global HTTP proxy configuration of the network. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                   | Mandatory| Description                                                        |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| httpProxy | [HttpProxy](js-apis-net-connection.md#httpproxy10) | Yes  | Global HTTP proxy configuration of the network.                                 |
| callback  | AsyncCallback\<void>    | Yes  | Callback used to return the result. If the global HTTP proxy configuration of the network is set successfully, **error** is **undefined**. Otherwise, **error** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 202     | Non-system applications use system APIs.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**Example**

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
    console.info(`setGlobalHttpProxy success.`);
});
```

## connection.setGlobalHttpProxy<sup>10+</sup>

setGlobalHttpProxy(httpProxy: HttpProxy): Promise\<void>;

Sets the global HTTP proxy configuration of the network. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                                        | Mandatory| Description            |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| httpProxy | [HttpProxy](js-apis-net-connection.md#httpproxy10)                                      | Yes  | Global HTTP proxy configuration of the network.|

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 202     | Non-system applications use system APIs.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**Example**

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

Enables the airplane mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description              |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.        |

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.              |
| 401     | Parameter error.               |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**Example**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.enableAirplaneMode((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## connection.enableAirplaneMode

enableAirplaneMode(): Promise\<void>

Enables the airplane mode. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.              |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**Example**

```ts
import { connection } from '@kit.NetworkKit';

connection.enableAirplaneMode().then((error: void) => {
  console.error(JSON.stringify(error));
});
```

## connection.disableAirplaneMode

disableAirplaneMode(callback: AsyncCallback\<void>): void

Disables the airplane mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description              |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the airplane mode is disabled successfully, **error** is **undefined**. Otherwise, **error** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.              |
| 401     | Parameter error.               |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**Example**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.disableAirplaneMode((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## connection.disableAirplaneMode

disableAirplaneMode(): Promise\<void>

Disables the airplane mode. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 202     | Non-system applications use system APIs.              |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.         |

**Example**

```ts
import { connection } from '@kit.NetworkKit';

connection.disableAirplaneMode().then((error: void) => {
  console.error(JSON.stringify(error));
});
```


## connection.factoryReset<sup>11+</sup>

factoryReset(): Promise\<void\>

Resets the network settings to factory defaults. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                  | Description                   |
| ---------------------- | ----------------------- |
| Promise\<void\>        | Promise that returns no value. |

**Error codes**

| ID| Error Message                                   |
| ------- | ------------------------------------------  |
| 201     | Permission denied.                          |
| 202     | Non-system applications use system APIs.    |
| 2100002 | Failed to connect to the service.|
| 2100003 | System internal error.                      |

**Example**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

connection.factoryReset().then(() => {
    console.info("success");
}).catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
})
```

## ProxyMode<sup>20+</sup>

Enumerates the proxy modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name             | Value  | Description                    |
| -------------------- | ------ | ------------------------ |
| PROXY_MODE_OFF     | 0 | Proxy disabled.         |
| PROXY_MODE_AUTO    | 1 | Auto mode.         |

## connection.setProxyMode<sup>20+</sup>

setProxyMode(mode: ProxyMode): Promise\<void\>

Sets the proxy mode.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type            | Mandatory| Description              |
| ------ |----------------| ---- | ------------------ |
| mode   | [ProxyMode](#proxymode20) | Yes  | Specified proxy mode.  |

**Return value**

| Type| Description                    |
| -------- | ------------------------ |
| Promise\<void\> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
|-------|---------------|
| 201   | Permission denied.   |
| 202   | Non-system applications use system APIs. |



**Example**

```ts
import { connection, ProxyMode } from '@kit.NetworkKit';

connection.setProxyMode(ProxyMode.AUTO).then(() => {
    console.info("Proxy mode set successfully.");
}).catch(error => {
    console.error("Error setting proxy mode:", error);
});
```

## connection.getProxyMode<sup>20+</sup>

getProxyMode(): Promise\<ProxyMode\>

Obtains the current proxy mode.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                       | Description                         |
|---------------------------| ------------------------ |
| Promise\<[ProxyMode](#proxymode20)\> | Promise used to return the result.|


**Example**

```ts
import { connection } from '@kit.NetworkKit';

connection.getProxyMode().then(mode => {
    console.info("Current proxy mode:", mode);
}).catch(error => {
    console.error("Error getting proxy mode:", error);
});
```
