# @ohos.net.connection (Network Connection Management)

The network connection management module provides basic network management capabilities. You can obtain the default active data network or the list of all active data networks, enable or disable the airplane mode, and obtain network capability information.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import connection from '@ohos.net.connection'
```

## connection.createNetConnection

createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection

Creates a **NetConnection** object. **netSpecifier** specifies the network, and **timeout** specifies the timeout duration in ms. **timeout** is configurable only when **netSpecifier** is specified. If neither of them is present, the default network is used.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| netSpecifier | [NetSpecifier](#netspecifier) | No  | Network specifier, which specifies the characteristics of a network. If this parameter is not set or is set to **undefined**, the default network is used.                  |
| timeout      | number                        | No  | Timeout duration for obtaining the network specified by **netSpecifier**. This parameter is valid only when **netSpecifier** is specified. The default value is **0** if **netSpecifier** is **undefined**.|

**Return value**

| Type                           | Description                |
| ------------------------------- | -------------------- |
| [NetConnection](#netconnection) | Handle of the network specified by **netSpecifier**.|

**Example**

```js
// For the default network, you do not need to pass in parameters.
let netConnection = connection.createNetConnection()

// For the cellular network, you need to pass in related network parameters. If the timeout parameter is not specified, the timeout value is 0 by default.
let netConnectionCellular = connection.createNetConnection({
  netCapabilities: {
    bearerTypes: [connection.NetBearType.BEARER_CELLULAR]
  }
})
```

## connection.getDefaultNet

getDefaultNet(callback: AsyncCallback\<NetHandle>): void

Obtains the default active data network. This API uses an asynchronous callback to return the result. You can use [getNetCapabilities](#connectiongetnetcapabilities) to obtain information such as the network type and capabilities.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | Yes  | Callback used to return the result. If the default activated data network is obtained successfully, err is undefined and data is the default activated data network. Otherwise, err is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## connection.getDefaultNet

getDefaultNet(): Promise\<NetHandle>

Obtains the default active data network. This API uses a promise to return the result. You can use [getNetCapabilities](#connectiongetnetcapabilities) to obtain information such as the network type and capabilities.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetHandle](#nethandle)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (data) {
  console.log(JSON.stringify(data))
})
```

## connection.getDefaultNetSync<sup>9+</sup>

getDefaultNetSync(): NetHandle

Obtains the default active data network in synchronous mode. You can use [getNetCapabilities](#connectiongetnetcapabilities) to obtain information such as the network type and capabilities.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type     | Description                              |
| --------- | ---------------------------------- |
| NetHandle | Handle of the default active data network.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
let netHandle = connection.getDefaultNetSync();
```

## connection.getAppNet<sup>9+</sup>

getAppNet(callback: AsyncCallback\<NetHandle>): void

Obtains information about the network bound to an application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                                        | Mandatory| Description            |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| callback  | AsyncCallback\<[NetHandle](#nethandle)> | Yes  | Callback used to return the result. If information about the network bound to the application is successfully obtained, **err** is **undefined** and **data** is the obtained network information. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getAppNet(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## connection.getAppNet<sup>9+</sup>

getAppNet(): Promise\<NetHandle>;

Obtains information about the network bound to an application. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                             | Description                                 |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetHandle](#nethandle)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getAppNet().then((data) => {
  console.info(JSON.stringify(data));
}).catch(error => {
  console.info(JSON.stringify(error));
})
```

## connection.SetAppNet<sup>9+</sup>

setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void

Binds an application to the specified network, so that the application can access the external network only through this network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                                        | Mandatory| Description            |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                                      | Yes  | Handle of the data network.|
| callback  | AsyncCallback\<void> | Yes  | Callback used to return the result. If the application is successfully bound to the specified network, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet(function (error, netHandle) {
  connection.setAppNet(netHandle, (error, data) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  });
})
```

## connection.SetAppNet<sup>9+</sup>

setAppNet(netHandle: NetHandle): Promise\<void>;

Binds an application to the specified network, so that the application can access the external network only through this network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                                        | Mandatory| Description            |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                                      | Yes  | Handle of the data network.|

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.setAppNet(netHandle).then(() => {
    console.log("success")
  }).catch(error => {
    console.log(JSON.stringify(error))
  })
})
```

## connection.getAllNets

getAllNets(callback: AsyncCallback&lt;Array&lt;NetHandle&gt;&gt;): void

Obtains the list of all connected networks. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | Yes| Callback used to return the result. If the list of all connected networks is obtained successfully, **err** is **undefined** and **data** is the list of activated data networks. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getAllNets(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## connection.getAllNets

getAllNets(): Promise&lt;Array&lt;NetHandle&gt;&gt;

Obtains the list of all connected networks. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getAllNets().then(function (data) {
  console.log(JSON.stringify(data))
});
```

## connection.getConnectionProperties

getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void

Obtains connection properties of the network corresponding to the **netHandle**. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                                        | Mandatory| Description            |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                                      | Yes  | Handle of the data network.|
| callback  | AsyncCallback\<[ConnectionProperties](#connectionproperties)> | Yes  | Callback used to return the result. If the connection properties of the network corresponding to the **netHandle** is obtained successfully, **err** is **undefined** and **data** is the obtained network connection information. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.getConnectionProperties(netHandle, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  })
})
```

## connection.getConnectionProperties

getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>

Obtains connection properties of the network corresponding to the **netHandle**. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                   | Mandatory| Description            |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | Yes  | Handle of the data network.|

**Return value**

| Type                                                   | Description                             |
| ------------------------------------------------------- | --------------------------------- |
| Promise\<[ConnectionProperties](#connectionproperties)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.getConnectionProperties(netHandle).then(function (data) {
    console.log(JSON.stringify(data))
  })
})
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void

Obtains capability information of the network corresponding to the **netHandle**. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                               | Mandatory| Description            |
| --------- | --------------------------------------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                             | Yes  | Handle of the data network.|
| callback  | AsyncCallback\<[NetCapabilities](#netcapabilities)> | Yes  | Callback used to return the result. If the capability information of the network corresponding to the **netHandle** is obtained successfully, **err** is **undefined** and **data** is the obtained network capability information. Otherwise, **err** is an error object.      |

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.getNetCapabilities(netHandle, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  })
})
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>

Obtains capability information of the network corresponding to the **netHandle**. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                   | Mandatory| Description            |
| --------- | ----------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle) | Yes  | Handle of the data network.|

**Return value**

| Type                                         | Description                             |
| --------------------------------------------- | --------------------------------- |
| Promise\<[NetCapabilities](#netcapabilities)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.getNetCapabilities(netHandle).then(function (data) {
    console.log(JSON.stringify(data))
  })
})
```

## connection.isDefaultNetMetered<sup>9+</sup>

isDefaultNetMetered(callback: AsyncCallback\<boolean>): void

Checks whether the data traffic usage on the current network is metered. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** indicates the data traffic usage is metered.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.isDefaultNetMetered(function (error, data) {
  console.log(JSON.stringify(error))
  console.log('data: ' + data)
})
```

## connection.isDefaultNetMetered<sup>9+</sup>

isDefaultNetMetered(): Promise\<boolean>

Checks whether the data traffic usage on the current network is metered. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type             | Description                                           |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** indicates the data traffic usage is metered.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.isDefaultNetMetered().then(function (data) {
  console.log('data: ' + data)
})
```

## connection.hasDefaultNet

hasDefaultNet(callback: AsyncCallback\<boolean>): void

Checks whether the default data network is activated. This API uses an asynchronous callback to return the result. You can use [getDefaultNet](#connectiongetdefaultnet) to obtain the default data network, if any.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** indicates the default data network is activated.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.hasDefaultNet(function (error, data) {
  console.log(JSON.stringify(error))
  console.log('data: ' + data)
})
```

## connection.hasDefaultNet

hasDefaultNet(): Promise\<boolean>

Checks whether the default data network is activated. This API uses a promise to return the result. You can use [getDefaultNet](#connectiongetdefaultnet) to obtain the default data network, if any.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type             | Description                                           |
| ----------------- | ----------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** indicates that the default data network is activated.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.hasDefaultNet().then(function (data) {
  console.log('data: ' + data)
})
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
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.enableAirplaneMode(function (error) {
  console.log(JSON.stringify(error))
})
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
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.enableAirplaneMode().then(function (error) {
  console.log(JSON.stringify(error))
})
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
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the airplane mode is disabled successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.disableAirplaneMode(function (error) {
  console.log(JSON.stringify(error))
})
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
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.disableAirplaneMode().then(function (error) {
  console.log(JSON.stringify(error))
})
```

## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

Reports connection of the data network to the network management module. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.GET_NETWORK_INFO and ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | Yes| Handle of the data network. For details, see [NetHandle](#nethandle).|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the network status is reported successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.reportNetConnected(netHandle, function (error) {
    console.log(JSON.stringify(error))
  });
});
```

## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle): Promise&lt;void&gt;

Reports connection of the data network to the network management module. This API uses a promise to return the result.

**Permission required**: ohos.permission.GET_NETWORK_INFO and ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | Yes| Handle of the data network. For details, see [NetHandle](#nethandle).|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.reportNetConnected(netHandle).then(function () {
    console.log(`report success`)
  });
});
```

## connection.reportNetDisconnected

reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

Reports disconnection of the data network to the network management module. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.GET_NETWORK_INFO and ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | Yes| Handle of the data network. For details, see [NetHandle](#nethandle).|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the network status is reported successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.reportNetDisconnected(netHandle, function (error) {
    console.log(JSON.stringify(error))
  });
});
```

## connection.reportNetDisconnected

reportNetDisconnected(netHandle: NetHandle): Promise&lt;void&gt;

Reports disconnection of the data network to the network management module. This API uses a promise to return the result.

**Permission required**: ohos.permission.GET_NETWORK_INFO and ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | Yes| Handle of the data network. For details, see [NetHandle](#nethandle).|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  connection.reportNetDisconnected(netHandle).then(function () {
    console.log(`report success`)
  });
});
```

## connection.getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

Resolves the host name by using the default network to obtain all IP addresses. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description              |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| host     | string                                            | Yes  | Host name to resolve.|
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | Yes  | Callback used to return the result. If all IP addresses are successfully obtained, **err** is **undefined**, and **data** is the list of all obtained IP addresses. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
let host = "xxxx";
connection.getAddressesByName(host, function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## connection.getAddressesByName

getAddressesByName(host: string): Promise\<Array\<NetAddress>>

Resolves the host name by using the default network to obtain all IP addresses. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| host   | string | Yes  | Host name to resolve.|

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
let host = "xxxx";
connection.getAddressesByName(host).then(function (data) {
  console.log(JSON.stringify(data))
})
```

## NetConnection

Represents the network connection handle.

### register

register(callback: AsyncCallback\<void>): void

Registers a listener for network status changes.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If a listener for network status changes is registered successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |
| 2101008 | The callback is not exists.      |
| 2101022 | The number of requests exceeded the maximum. |

**Example**

```js
netConnection.register(function (error) {
  console.log(JSON.stringify(error))
})
```

### unregister

unregister(callback: AsyncCallback\<void>): void

Unregisters the listener for network status changes.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If a listener for network status changes is unregistered successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |
| 2101007 | The same callback exists.      |

**Example**

```js
netConnection.unregister(function (error) {
  console.log(JSON.stringify(error))
})
```

### on('netAvailable')

on(type: 'netAvailable', callback: Callback\<NetHandle>): void

Registers a listener for **netAvailable** events.

**Model restriction**: Before you call this API, make sure that you have called **register** to add a listener and called **unregister** API to unsubscribe from status changes of the default network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | Yes  | Event type. The value is fixed to **netAvailable**.<br>**netAvailable**: event indicating that the data network is available.|
| callback | Callback\<[NetHandle](#nethandle)> | Yes  | Callback used to return the network handle.|

**Example**

```js
// Create a NetConnection object.
let netCon = connection.createNetConnection()

// Call register to register a listener.
netCon.register(function (error) {
  console.log(JSON.stringify(error))
})

// Subscribe to netAvailable events. Event notifications can be received only after register is called.
netCon.on('netAvailable', function (data) {
  console.log(JSON.stringify(data))
})

// Call unregister to unregister the listener.
netCon.unregister(function (error) {
  console.log(JSON.stringify(error))
})
```

### on('netBlockStatusChange')

on(type: 'netBlockStatusChange', callback: Callback&lt;{ netHandle: NetHandle, blocked: boolean }&gt;): void

Registers a listener for **netBlockStatusChange** events. This API uses an asynchronous callback to return the result.

**Model restriction**: Before you call this API, make sure that you have called **register** to add a listener and called **unregister** API to unsubscribe from status changes of the default network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed to **netBlockStatusChange**.<br>**netBlockStatusChange**: event indicating a change in the network blocking status.|
| callback | Callback&lt;{&nbsp;netHandle:&nbsp;[NetHandle](#nethandle),&nbsp;blocked:&nbsp;boolean&nbsp;}&gt; | Yes  | Callback used to return the network handle (**netHandle**) and network status (**blocked**).|

**Example**

```js
// Create a NetConnection object.
let netCon = connection.createNetConnection()

// Call register to register a listener.
netCon.register(function (error) {
  console.log(JSON.stringify(error))
})

// Subscribe to netBlockStatusChange events. Event notifications can be received only after register is called.
netCon.on('netBlockStatusChange', function (data) {
  console.log(JSON.stringify(data))
})

// Call unregister to unregister the listener.
netCon.unregister(function (error) {
  console.log(JSON.stringify(error))
})
```

### on('netCapabilitiesChange')

on(type: 'netCapabilitiesChange', callback: Callback<{ netHandle: NetHandle, netCap: NetCapabilities }>): void

Registers a listener for **netCapabilitiesChange** events.

**Model restriction**: Before you call this API, make sure tat you have called **register** to add a listener and called **unregister** API to unsubscribe from status changes of the default network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed to **netCapabilitiesChange**.<br>**netCapabilitiesChange**: event indicating that the network capabilities have changed.|
| callback | Callback<{ netHandle: [NetHandle](#nethandle), netCap: [NetCapabilities](#netcapabilities) }> | Yes  | Callback used to return the network handle (**netHandle**) and capability information (**netCap**).|

**Example**

```js
// Create a NetConnection object.
let netCon = connection.createNetConnection()

// Call register to register a listener.
netCon.register(function (error) {
  console.log(JSON.stringify(error))
})

// Subscribe to netCapabilitiesChange events. Event notifications can be received only after register is called.
netCon.on('netCapabilitiesChange', function (data) {
  console.log(JSON.stringify(data))
})

// Call unregister to unregister the listener.
netCon.unregister(function (error) {
  console.log(JSON.stringify(error))
})
```

### on('netConnectionPropertiesChange')

on(type: 'netConnectionPropertiesChange', callback: Callback<{ netHandle: NetHandle, connectionProperties:
ConnectionProperties }>): void

Registers a listener for **netConnectionPropertiesChange** events.

**Model restriction**: Before you call this API, make sure tat you have called **register** to add a listener and called **unregister** API to unsubscribe from status changes of the default network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed to **netConnectionPropertiesChange**.<br>**netConnectionPropertiesChange**: event indicating that network connection properties have changed.|
| callback | Callback<{ netHandle: [NetHandle](#nethandle), connectionProperties: [ConnectionProperties](#connectionproperties) }> | Yes  | Callback used to return the network handle (**netHandle**) and connection information (**connectionProperties**).|

**Example**

```js
// Create a NetConnection object.
let netCon = connection.createNetConnection()

// Call register to register a listener.
netCon.register(function (error) {
  console.log(JSON.stringify(error))
})

// Subscribe to netConnectionPropertiesChange events. Event notifications can be received only after register is called.
netCon.on('netConnectionPropertiesChange', function (data) {
  console.log(JSON.stringify(data))
})

// Call unregister to unregister the listener.
netCon.unregister(function (error) {
  console.log(JSON.stringify(error))
})
```

### on('netLost')

on(type: 'netLost', callback: Callback\<NetHandle>): void

Registers a listener for **netLost** events.

**Model restriction**: Before you call this API, make sure tat you have called **register** to add a listener and called **unregister** API to unsubscribe from status changes of the default network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | Yes  | Event type. The value is fixed to **netLost**.<br>netLost: event indicating that the network is interrupted or normally disconnected.|
| callback | Callback\<[NetHandle](#nethandle)> | Yes  | Callback used to return the network handle (**netHandle**).|

**Example**

```js
// Create a NetConnection object.
let netCon = connection.createNetConnection()

// Call register to register a listener.
netCon.register(function (error) {
  console.log(JSON.stringify(error))
})

// Subscribe to netLost events. Event notifications can be received only after register is called.
netCon.on('netLost', function (data) {
  console.log(JSON.stringify(data))
})

// Call unregister to unregister the listener.
netCon.unregister(function (error) {
  console.log(JSON.stringify(error))
})
```

### on('netUnavailable')

on(type: 'netUnavailable', callback: Callback\<void>): void

Registers a listener for **netUnavailable** events.

**Model restriction**: Before you call this API, make sure tat you have called **register** to add a listener and called **unregister** API to unsubscribe from status changes of the default network.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type           | Mandatory| Description                                                        |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | Yes  | Event type. The value is fixed to **netUnavailable**.<br>**netUnavailable**: event indicating that the network is unavailable.|
| callback | Callback\<void> | Yes  | Callback used to return the result, which is empty.|

**Example**

```js
// Create a NetConnection object.
let netCon = connection.createNetConnection()

// Call register to register a listener.
netCon.register(function (error) {
  console.log(JSON.stringify(error))
})

// Subscribe to netUnavailable events. Event notifications can be received only after register is called.
netCon.on('netUnavailable', function (data) {
  console.log(JSON.stringify(data))
})

// Call unregister to unregister the listener.
netCon.unregister(function (error) {
  console.log(JSON.stringify(error))
})
```

## NetHandle

Defines the handle of the data network.

Before invoking **NetHandle** APIs, call **getNetHandle** to obtain a **NetHandle** object.

**System capability**: SystemCapability.Communication.NetManager.Core

### Attributes

| Name   | Type  | Mandatory| Description                     |
| ------ | ------ | --- |------------------------- |
| netId  | number | Yes |  Network ID. The value **0** indicates no default network. Any other value must be greater than or equal to 100.|

### bindSocket<sup>9+</sup>

bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void

Binds a **TCPSocket** or **UDPSocket** object to the data network. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                           |
| ----------- | ------------------------ | ---- | -------------------------------|
| socketParam | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | Yes| **TCPSocket** or **UDPSocket** object.|
| callback    | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the **TCPSocket** or **UDPSocket** object is successfully bound to the current network, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
import socket from "@ohos.net.socket";

connection.getDefaultNet().then((netHandle) => {
  var tcp = socket.constructTCPSocketInstance();
  var udp = socket.constructUDPSocketInstance();
  let socketType = "TCPSocket";
  if (socketType == "TCPSocket") {
    tcp.bind({
      address: '192.168.xx.xxx', port: 8080, family: 1
    }, error => {
      if (error) {
        console.log('bind fail');
        return;
      }
      netHandle.bindSocket(tcp, (error, data) => {
        if (error) {
          console.log(JSON.stringify(error));
        } else {
          console.log(JSON.stringify(data));
        }
      })
    })
  } else {
    let callback = value => {
      console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
    }
    udp.on('message', callback);
    udp.bind({
      address: '192.168.xx.xxx', port: 8080, family: 1
    }, error => {
      if (error) {
        console.log('bind fail');
        return;
      }
      udp.on('message', (data) => {
        console.log(JSON.stringify(data))
      });
      netHandle.bindSocket(udp, (error, data) => {
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

Binds a **TCPSocket** or **UDPSocket** object to the data network. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name         | Type                 | Mandatory | Description                          |
| --------------- | --------------------- | ---- | ------------------------------ |
| socketParam     | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | Yes  | **TCPSocket** or **UDPSocket** object.|

**Return value**

| Type          | Description                  |
| -------------- | ---------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
import socket from "@ohos.net.socket";

connection.getDefaultNet().then((netHandle) => {
  var tcp = socket.constructTCPSocketInstance();
  var udp = socket.constructUDPSocketInstance();
  let socketType = "TCPSocket";
  if (socketType == "TCPSocket") {
    tcp.bind({
      address: '192.168.xx.xxx', port: 8080, family: 1
    }, error => {
      if (error) {
        console.log('bind fail');
        return;
      }
      netHandle.bindSocket(tcp).then((data) => {
        console.log(JSON.stringify(data));
      }).catch(error => {
        console.log(JSON.stringify(error));
      })
    })
  } else {
    let callback = value => {
      console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
    }
    udp.on('message', callback);
    udp.bind({
      address: '192.168.xx.xxx', port: 8080, family: 1
    }, error => {
      if (error) {
        console.log('bind fail');
        return;
      }
      udp.on('message', (data) => {
        console.log(JSON.stringify(data));
      })
      netHandle.bindSocket(udp).then((data) => {
        console.log(JSON.stringify(data));
      }).catch(error => {
        console.log(JSON.stringify(error));
      })
    })
  }
})
```

### getAddressesByName

getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void

Resolves the host name by using the corresponding network to obtain all IP addresses. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description              |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| host     | string                                            | Yes  | Host name to resolve.|
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | Yes  | Callback used to return the result. If all IP addresses are successfully obtained, **err** is **undefined**, and **data** is the list of all obtained IP addresses. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  let host = "xxxx";
  netHandle.getAddressesByName(host, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  })
})
```

### getAddressesByName

getAddressesByName(host: string): Promise\<Array\<NetAddress>>

Resolves the host name by using the corresponding network to obtain all IP addresses. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| host   | string | Yes  | Host name to resolve.|

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  let host = "xxxx";
  netHandle.getAddressesByName(host).then(function (data) {
    console.log(JSON.stringify(data))
  })
})
```

### getAddressByName

getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void

Resolves the host name by using the corresponding network to obtain the first IP address. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description              |
| -------- | ----------------------------------------- | ---- | ------------------ |
| host     | string                                    | Yes  | Host name to resolve.|
| callback | AsyncCallback\<[NetAddress](#netaddress)> | Yes  | Callback used to return the result. If the first IP address is obtained successfully, **err** is **undefined**, and **data** is the first obtained IP address. Otherwise, **err** is an error object.        |

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  let host = "xxxx";
  netHandle.getAddressByName(host, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
  })
})
```

### getAddressByName

getAddressByName(host: string): Promise\<NetAddress>

Resolves the host name by using the corresponding network to obtain the first IP address. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| host   | string | Yes  | Host name to resolve.|

**Return value**

| Type                               | Description                           |
| ----------------------------------- | ------------------------------- |
| Promise\<[NetAddress](#netaddress)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 201     | Permission denied.             |
| 401     | Parameter error.               |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.         |

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
  let host = "xxxx";
  netHandle.getAddressByName(host).then(function (data) {
    console.log(JSON.stringify(data))
  })
})
```

## NetCap

Defines the network capability.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Value  | Description                  |
| ------------------------ | ---- | ---------------------- |
| NET_CAPABILITY_MMS | 0 | The network can connect to the carrier's Multimedia Messaging Service Center (MMSC) to send and receive multimedia messages.|
| NET_CAPABILITY_NOT_METERED | 11 | The network traffic is not metered.|
| NET_CAPABILITY_INTERNET  | 12   | The network has the Internet access capability, which is set by the network provider.|
| NET_CAPABILITY_NOT_VPN | 15 | The network does not use a virtual private network (VPN).|
| NET_CAPABILITY_VALIDATED | 16   | The Internet access capability of the network is successfully verified by the connection management module.|

## NetBearType

Enumerates network types.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name        | Value  | Description       |
| --------------- | ---- | ----------- |
| BEARER_CELLULAR | 0    | Cellular network. |
| BEARER_WIFI     | 1    | Wi-Fi network.|
| BEARER_ETHERNET | 3 | Ethernet network.|

## NetSpecifier

Provides an instance that bears data network capabilities.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                    | Type                               | Mandatory | Description                                                        |
| ----------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| netCapabilities         | [NetCapabilities](#netcapabilities) |  Yes | Network transmission capabilities and bearer types of the data network.                               |
| bearerPrivateIdentifier | string                              |  No |  Network identifier. The identifier of a Wi-Fi network is **wifi**, and that of a cellular network is **slot0** (corresponding to SIM card 1).|

## NetCapabilities

Defines the network capability set.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Type                               | Mandatory| Description                    |
| --------------------- | ---------------------------------- | --- | ------------------------ |
| linkUpBandwidthKbps   | number                             |  No|  Uplink (from the device to the network) bandwidth. |
| linkDownBandwidthKbps | number                             |  No|  Downlink (from the network to the device) bandwidth.  |
| networkCap            | Array\<[NetCap](#netcap)>           |  No|  Network capability.          |
| bearerTypes           | Array\<[NetBearType](#netbeartype)> |  Yes|  Network type.              |

## ConnectionProperties

Defines the network connection properties.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name          | Type                              | Mandatory|  Description            |
| ------------- | ---------------------------------- | ----|---------------- |
| interfaceName | string                             | Yes|Network interface card (NIC) name.      |
| domains       | string                             | Yes|Domain. The default value is **""**.|
| linkAddresses | Array\<[LinkAddress](#linkaddress)> | Yes|Link information.      |
| routes        | Array\<[RouteInfo](#routeinfo)>     | Yes|Route information.      |
| dnses     | Array\<[NetAddress](#netaddress)> | Yes|Network address. For details, see [NetAddress](#netaddress).|
| mtu           | number                             | Yes|Maximum transmission unit (MTU).  |

## RouteInfo

Defines network route information.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name          | Type                       | Mandatory|Description            |
| -------------- | --------------------------- | --- |---------------- |
| interface      | string                      | Yes|NIC name.      |
| destination    | [LinkAddress](#linkaddress) | Yes|Destination address.      |
| gateway        | [NetAddress](#netaddress)   | Yes|Gateway address.      |
| hasGateway     | boolean                     | Yes|Whether a gateway is present.    |
| isDefaultRoute | boolean                     | Yes|Whether the route is the default route.|

## LinkAddress

Defines network link information.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name       | Type                     | Mandatory|Description                |
| ------------ | ----------------------- |---- |-------------------- |
| address      | [NetAddress](#netaddress) | Yes| Link address.          |
| prefixLength | number                    | Yes|Length of the link address prefix.|

## NetAddress

Defines a network address.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name| Type| Mandatory| Description|
| ------- | ------ | -- |------------------------------ |
| address | string | Yes|Network address.|
| family  | number | No|Address family identifier. The value is **1** for IPv4 and **2** for IPv6. The default value is **1**.|
| port    | number | No|Port number. The value ranges from **0** to **65535**.|
