# Network Connection Management

The network connection management module provides basic network management capabilities. You can obtain the default active data network or the list of all active data networks, enable or disable the airplane mode, and obtain network capability information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import connection from '@ohos.net.connection'
```

## connection.getDefaultNet

getDefaultNet(callback: AsyncCallback\<NetHandle>): void

Obtains the default active data network. This API uses an asynchronous callback to return the result. You can use [getNetCapabilities](#connectiongetnetcapabilities) to obtain information such as the network type and capabilities.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description      |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetHandle](#nethandle)> | Yes  | Callback used to return the result.|

**Example**

```js
connection.getDefaultNet(function (error, netHandle) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(netHandle))
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

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
    console.log(JSON.stringify(netHandle))
})
```

## connection.getDefaultNetSync

getDefaultNetSync(): NetHandle;

Obtains the default active data network in synchronous mode. You can use [getNetCapabilities](#connectiongetnetcapabilities) to obtain information such as the network type and capabilities.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type     | Description                              |
| --------- | ---------------------------------- |
| NetHandle | Handle of the default active data network.|

**Example**

```js
let netHandle = connection.getDefaultNetSync();
```


## connection.hasDefaultNet

hasDefaultNet(callback: AsyncCallback\<boolean>): void

Checks whether the default data network is activated. This API uses an asynchronous callback to return the result. You can use [getDefaultNet](#connectiongetdefaultnet) to obtain the default data network, if any.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** indicates that the default data network is activated.|

**Example**

```js
connection.hasDefaultNet(function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
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

**Example**

```js
connection.hasDefaultNet().then(function (has) {
    console.log('has: ' + has)
})
```

## connection.getAllNets

getAllNets(callback: AsyncCallback&lt;Array&lt;NetHandle&gt;&gt;): void

Obtains the list of all active data networks. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | Yes| Callback used to return the result.|

**Example**

```js
connection.getAllNets(function (error, nets) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(nets))
});
```


## connection.getAllNets

getAllNets(): Promise&lt;Array&lt;NetHandle&gt;&gt;

Obtains the list of all active data networks. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[NetHandle](#nethandle)&gt;&gt; | Promise used to return the result.|

**Example**

```js
connection.getAllNets().then(function (nets) {
    console.log(JSON.stringify(nets))
});
```

## connection.getConnectionProperties

getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void

Obtains connection properties of the network corresponding to the given network handle. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                                        | Mandatory| Description            |
| --------- | ------------------------------------------------------------ | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                                      | Yes  | Handle of the data network.|
| callback  | AsyncCallback\<[ConnectionProperties](#connectionproperties)> | Yes  | Callback used to return the result.      |

**Example**

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

Obtains connection properties of the network corresponding to **netHandle**. This API uses a promise to return the result.

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

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.getConnectionProperties(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

## connection.getNetCapabilities

getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void

Obtains capability information of the network corresponding to **netHandle**. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                               | Mandatory| Description            |
| --------- | --------------------------------------------------- | ---- | ---------------- |
| netHandle | [NetHandle](#nethandle)                             | Yes  | Handle of the data network.|
| callback  | AsyncCallback\<[NetCapabilities](#netcapabilities)> | Yes  | Callback used to return the result.      |

**Example**

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

Obtains capability information of the network corresponding to **netHandle**. This API uses a promise to return the result.

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

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
    connection.getNetCapabilities(netHandle).then(function (info) {
        console.log(JSON.stringify(info))
    })
})
```

## connection.reportNetConnected

reportNetConnected(netHandle: NetHandle, callback: AsyncCallback&lt;void&gt;): void

Reports connection of the data network. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.GET_NETWORK_INFO and ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | Yes| Handle of the data network. For details, see [NetHandle](#nethandle).|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

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

Reports connection of the data network. This API uses a promise to return the result.

**Permission required**: ohos.permission.GET_NETWORK_INFO and ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | Yes| Handle of the data network. For details, see [NetHandle](#nethandle).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

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

Reports disconnection of the data network. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.GET_NETWORK_INFO and ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | Yes| Handle of the data network. For details, see [NetHandle](#nethandle).|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

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

Reports disconnection of the data network. This API uses a promise to return the result.

**Permission required**: ohos.permission.GET_NETWORK_INFO and ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| netHandle | [NetHandle](#nethandle) | Yes| Handle of the data network. For details, see [NetHandle](#nethandle).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

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

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description              |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| host     | string                                            | Yes  | Host name to be resolved.|
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | Yes  | Callback used to return the result.        |

**Example**

```js
let host = "xxxx";
connection.getAddressesByName(host, function (error, addresses) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(addresses))
})
```

## connection.getAddressesByName

getAddressesByName(host: string): Promise\<Array\<NetAddress>>

Resolves the host name by using the default network to obtain all IP addresses. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| host   | string | Yes  | Host name to be resolved.|

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | Promise used to return the result.|

**Example**

```js
let host = "xxxx";
connection.getAddressesByName(host).then(function (addresses) {
    console.log(JSON.stringify(addresses))
})
```


## connection.enableAirplaneMode

enableAirplaneMode(callback: AsyncCallback\<void>): void

Enables the airplane mode. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**:  SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description              |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.        |

**Example**

```js
connection.enableAirplaneMode(function (error) {
    console.log(JSON.stringify(error))
})
```

## connection.enableAirplaneMode

enableAirplaneMode(): Promise\<void>

Enables the airplane mode. This API uses a promise to return the result.

This is a system API.

**System capability**:  SystemCapability.Communication.NetManager.Core

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
connection.enableAirplaneMode().then(function (error) {
    console.log(JSON.stringify(error))
})
```


## connection.disableAirplaneMode

disableAirplaneMode(callback: AsyncCallback\<void>): void

Disables the airplane mode. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**:  SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description              |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.        |

**Example**

```js
connection.disableAirplaneMode(function (error) {
    console.log(JSON.stringify(error))
})
```

## connection.disableAirplaneMode

disableAirplaneMode(): Promise\<void>

Disables the airplane mode. This API uses a promise to return the result.

This is a system API.

**System capability**:  SystemCapability.Communication.NetManager.Core

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
connection.disableAirplaneMode().then(function (error) {
    console.log(JSON.stringify(error))
})
```


## connection.createNetConnection

createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection

Obtains the handle of the network specified by **netSpecifier**.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                                        |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| netSpecifier | [NetSpecifier](#netspecifier) | No  | Network specifier. If this parameter is not set, the default network is used.                  |
| timeout      | number                        | No  | Timeout interval for obtaining the network specified by **netSpecifier**. This parameter is valid only when **netSpecifier** is set.|

**Return value**

| Type                           | Description                |
| ------------------------------- | -------------------- |
| [NetConnection](#netconnection) | Handle of the network specified by **netSpecifier**.|

**Example**

```js
// Default network
let netConnection = connection.createNetConnection()

// Cellular network
let netConnectionCellular = connection.createNetConnection({
    netCapabilities: {
        bearerTypes: [connection.NetBearType.BEARER_CELLULAR]
    }
})
```

## NetConnection

Represents the network connection handle.

### on('netAvailable')

on(type: 'netAvailable', callback: Callback\<NetHandle>): void

Registers a listener for **netAvailable** events.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | Yes  | Event type. The value is fixed at **netAvailable**.<br>**netAvailable**: event indicating that the data network is available.|
| callback | Callback\<[NetHandle](#nethandle)> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
netConnection.on('netAvailable', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netCapabilitiesChange')

on(type: 'netCapabilitiesChange', callback: Callback<{ netHandle: NetHandle, netCap: NetCapabilities }>): void

Registers a listener for **netCapabilitiesChange** events.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **netCapabilitiesChange**.<br>**netCapabilitiesChange**: event indicating that network capabilities have changed.|
| callback | Callback<{ netHandle: [NetHandle](#nethandle), netCap: [NetCapabilities](#netcapabilities) }> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
netConnection.on('netCapabilitiesChange', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netConnectionPropertiesChange')

on(type: 'netConnectionPropertiesChange', callback: Callback<{ netHandle: NetHandle, connectionProperties: ConnectionProperties }>): void

Registers a listener for **netConnectionPropertiesChange** events.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **netConnectionPropertiesChange**.<br>**netConnectionPropertiesChange**: event indicating that network connection properties have changed.|
| callback | Callback<{ netHandle: [NetHandle](#nethandle), connectionProperties: [ConnectionProperties](#connectionproperties) }> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
netConnection.on('netConnectionPropertiesChange', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netBlockStatusChange')

on(type: 'netBlockStatusChange', callback: Callback&lt;{ netHandle: NetHandle, blocked: boolean }&gt;): void

Registers a listener for **netBlockStatusChange** events.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **netBlockStatusChange**.<br>**netBlockStatusChange**: event indicating a change in the network blocking status.|
| callback | Callback&lt;{&nbsp;netHandle:&nbsp;[NetHandle](#nethandle),&nbsp;blocked:&nbsp;boolean&nbsp;}&gt; | Yes  | Callback used to return the result.                                                  |

**Example**

```js
netConnection.on('netBlockStatusChange', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netLost')

on(type: 'netLost', callback: Callback\<NetHandle>): void

Registers a listener for **netLost** events.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | Yes  | Event type. The value is fixed at **netLost**.<br>netLost: event indicating that the network is interrupted or normally disconnected.|
| callback | Callback\<[NetHandle](#nethandle)> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
let netConnection1 = connection.createNetConnection()
netConnection1.on('netLost', function (data) {
    console.log(JSON.stringify(data))
})
```

### on('netUnavailable')

on(type: 'netUnavailable', callback: Callback\<void>): void

Registers a listener for **netUnavailable** events.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type           | Mandatory| Description                                                        |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | Yes  | Event type. The value is fixed at **netUnavailable**.<br>**netUnavailable**: event indicating that the network is unavailable.|
| callback | Callback\<void> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
netConnection.on('netUnavailable', function (data) {
    console.log(JSON.stringify(data))
})
```

### register

register(callback: AsyncCallback\<void>): void

Registers a listener for network status changes.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

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
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
netConnection.unregister(function (error) {
    console.log(JSON.stringify(error))
})
```

## NetHandle

Defines the handle of the data network.

Before invoking NetHandle APIs, call **getNetHandle** to obtain a **NetHandle** object.

**System capability**: SystemCapability.Communication.NetManager.Core

### Parameters

| Name| Type  | Description                     |
| ------ | ------ | ------------------------- |
| netId  | number | Network ID. The value must be greater than or equal to 100.|

### bindSocket

bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void;

Binds a **TCPSocket** or **UDPSocket** object to the data network. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                           |
| ----------- | ------------------------ | ---- | -------------------------------|
| socketParam | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | Yes| **TCPSocket** or **UDPSocket** object.|
| callback    | AsyncCallback\<void>      | Yes  | Callback used to return the result.                       |

**Example**

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

Binds a **TCPSocket** or **UDPSocket** object to the data network. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name         | Type                 | Mandatory | Description                          |
| --------------- | --------------------- | ---- | ------------------------------ |
| socketParam     | [TCPSocket](js-apis-socket.md#tcpsocket) \| [UDPSocket](js-apis-socket.md#udpsocket) | Yes  | **TCPSocket** or **UDPSocket** object.|

**Return value**

| Type          | Description                  |
| -------------- | ---------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

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

Resolves the host name by using the corresponding network to obtain all IP addresses. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                             | Mandatory| Description              |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| host     | string                                            | Yes  | Host name to be resolved.|
| callback | AsyncCallback\<Array\<[NetAddress](#netaddress)>> | Yes  | Callback used to return the result.          |

**Example**

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

Resolves the host name by using the corresponding network to obtain all IP addresses. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| host   | string | Yes  | Host name to be resolved.|

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetAddress](#netaddress)>> | Promise used to return the result.|

**Example**

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

Resolves the host name by using the corresponding network to obtain the first IP address. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description              |
| -------- | ----------------------------------------- | ---- | ------------------ |
| host     | string                                    | Yes  | Host name to be resolved.|
| callback | AsyncCallback\<[NetAddress](#netaddress)> | Yes  | Callback used to return the result.        |

**Example**

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

Resolves the host name by using the corresponding network to obtain the first IP address. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| host   | string | Yes  | Host name to be resolved.|

**Return value**

| Type                               | Description                           |
| ----------------------------------- | ------------------------------- |
| Promise\<[NetAddress](#netaddress)> | Promise used to return the result.|

**Example**

```js
connection.getDefaultNet().then(function (netHandle) {
    let host = "xxxx";
    netHandle.getAddressByName(host).then(function (address) {
        console.log(JSON.stringify(address))
    })
})
```

## NetSpecifier

Provides an instance that bears data network capabilities.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Type                               | Description                                                        |
| ----------------------- | ----------------------------------- | ------------------------------------------------------------ |
| netCapabilities         | [NetCapabilities](#netcapabilities) | Network transmission capabilities and bearer types of the data network.                          |
| bearerPrivateIdentifier | string                              | Network identifier. The identifier of a Wi-Fi network is **wifi**, and that of a cellular network is **slot0** (corresponding to SIM card 1).|

## NetCapabilities

Defines the network capability set.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name               | Type                              | Description                    |
| --------------------- | ---------------------------------- | ------------------------ |
| linkUpBandwidthKbps   | number                             | Uplink (from the device to the network) bandwidth.|
| linkDownBandwidthKbps | number                             | Downlink (from the network to the device) bandwidth.|
| networkCap            | Array<[NetCap](#netcap)>           | Network capability.          |
| bearerTypes           | Array<[NetBearType](#netbeartype)> | Network type.              |

## NetCap

Defines the network capability.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                 | Value  | Description                  |
| ------------------------ | ---- | ---------------------- |
| NET_CAPABILITY_MMS | 0 | The network can connect to the carrier's Multimedia Messaging Service Center (MMSC) to send and receive multimedia messages.|
| NET_CAPABILITY_NOT_METERED | 11 | The network traffic is not metered.|
| NET_CAPABILITY_INTERNET  | 12   | The network can connect to the Internet.|
| NET_CAPABILITY_NOT_VPN | 15 | The network does not use a Virtual Private Network (VPN).|
| NET_CAPABILITY_VALIDATED | 16   | The network is available.            |

## NetBearType

Defines the network type.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name        | Value  | Description       |
| --------------- | ---- | ----------- |
| BEARER_CELLULAR | 0    | Cellular network |
| BEARER_WIFI     | 1    | Wi-Fi network|
| BEARER_ETHERNET | 3 | Ethernet network|

## ConnectionProperties

Defines the network connection properties.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name      | Type                              | Description            |
| ------------- | ---------------------------------- | ---------------- |
| interfaceName | string                             | NIC card name.      |
| domains       | string                             | Domain. The default value is **""**.|
| linkAddresses | Array<[LinkAddress](#linkaddress)> | Link information.      |
| routes        | Array<[RouteInfo](#routeinfo)>     | Route information.      |
| dnses | Array&lt;[NetAddress](#netaddress)&gt; | Network address. For details, see [NetAddress](#netaddress).|
| mtu           | number                             | Maximum transmission unit (MTU).  |

## LinkAddress

Network link information.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name      | Type                     | Description                |
| ------------ | ------------------------- | -------------------- |
| address      | [NetAddress](#netaddress) | Link address.          |
| prefixLength | number                    | Length of the link address prefix.|

## RouteInfo

Network route information.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name        | Type                       | Description            |
| -------------- | --------------------------- | ---------------- |
| interface      | string                      | NIC card name.      |
| destination    | [LinkAddress](#linkaddress) | Destination IP address.      |
| gateway        | [NetAddress](#netaddress)   | Gateway address.      |
| hasGateway     | boolean                     | Whether a gateway is present.    |
| isDefaultRoute | boolean                     | Whether the route is the default route.|

## NetAddress

Defines the network address.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name | Type  | Description                          |
| ------- | ------ | ------------------------------ |
| address | string | Network address.                        |
| family  | number | Address family identifier. The value is **1** for IPv4 and **2** for IPv6. The default value is **1**.|
| port    | number | Port number. The value ranges from **0** to **65535**.   |
