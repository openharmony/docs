# @ohos.net.socket (Socket Connection) 

The **socket** module implements data transfer over TCP, UDP, Web, and TLS socket connections.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import socket from '@ohos.net.socket';
```

## socket.constructUDPSocketInstance<sup>7+</sup>

constructUDPSocketInstance(): UDPSocket

Creates a **UDPSocket** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                   |
| :--------------------------------- | :---------------------- |
| [UDPSocket](#udpsocket) | **UDPSocket** object.|

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
```

## UDPSocket<sup>7+</sup>

Defines a UDP socket connection. Before calling UDPSocket APIs, you need to call [socket.constructUDPSocketInstance](#socketconstructudpsocketinstance) to create a **UDPSocket** object.

### bind<sup>7+</sup>

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                              | Mandatory| Description                                                  |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | Yes  | Destination address. For details, see [NetAddress](#netaddress).|
| callback | AsyncCallback\<void\>              | Yes  | Callback used to return the result.                                            |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let netaddress = new NetAddress();
udp.bind(netaddress, (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
```

### bind<sup>7+</sup>

bind(address: NetAddress): Promise\<void\>

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                              | Mandatory| Description                                                  |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress) | Yes  | Destination address. For details, see [NetAddress](#netaddress).|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Return value**

| Type           | Description                                      |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let netaddress = new NetAddress();
let promise: socket = udp.bind(netaddress);
promise.then(() => {
  console.log('bind success');
}).catch((err: string) => {
  console.log('bind fail');
});
```

### send<sup>7+</sup>

send(options: UDPSendOptions, callback: AsyncCallback\<void\>): void

Sends data over a UDP socket connection. This API uses an asynchronous callback to return the result.

Before sending data, call [UDPSocket.bind()](#bind) to bind the IP address and port.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                        |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPSendOptions](#udpsendoptions) | Yes  | Parameters for sending data over the UDP socket connection. For details, see [UDPSendOptions](#udpsendoptions).|
| callback | AsyncCallback\<void\>                    | Yes  | Callback used to return the result.                                                  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class UDPSendOptions {
  data: string = 'Hello, server!'
  address: Object = new NetAddress()
}

let udpsendoptions = new UDPSendOptions();
udp.send(udpsendoptions, (err: string) => {
  if (err) {
    console.log('send fail');
    return;
  }
  console.log('send success');
});
```

### send<sup>7+</sup>

send(options: UDPSendOptions): Promise\<void\>

Sends data over a UDP socket connection. This API uses a promise to return the result.

Before sending data, call [UDPSocket.bind()](#bind) to bind the IP address and port.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description                                                        |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [UDPSendOptions](#udpsendoptions) | Yes  | Parameters for sending data over the UDP socket connection. For details, see [UDPSendOptions](#udpsendoptions).|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Return value**

| Type           | Description                                          |
| :-------------- | :--------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class UDPSendOptions {
  data: string = 'Hello, server!'
  address: Object = new NetAddress()
}
let udpsendoptions = new UDPSendOptions();
let promise: socket = udp.send(udpsendoptions);
promise.then(() => {
  console.log('send success');
}).catch((err: string) => {
  console.log('send fail');
});
```

### close<sup>7+</sup>

close(callback: AsyncCallback\<void\>): void

Closes a UDP socket connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
udp.close((err: string) => {
  if (err) {
    console.log('close fail');
    return;
  }
  console.log('close success');
})
```

### close<sup>7+</sup>

close(): Promise\<void\>

Closes a UDP socket connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                      |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
let promise: socket = udp.close();
promise.then(() => {
  console.log('close success');
}).catch((err: string) => {
  console.log('close fail');
});
```

### getState<sup>7+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of the UDP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback<[SocketStateBase](#socketstatebase)> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let netaddress = new NetAddress();
udp.bind(netaddress, (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  udp.getState((err: string, data: string) => {
    if (err) {
      console.log('getState fail');
      return;
    }
    console.log('getState success:' + JSON.stringify(data));
  })
})
```

### getState<sup>7+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of the UDP socket connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                            | Description                                      |
| :----------------------------------------------- | :----------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | Promise used to return the result.|

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let netaddress = new NetAddress();
let promise: socket = udp.bind(netaddress);
promise.then((err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  let promise: socket = udp.getState();
  promise.then((data: string) => {
    console.log('getState success:' + JSON.stringify(data));
  }).catch((err: string) => {
    console.log('getState fail');
  });
});
```

### setExtraOptions<sup>7+</sup>

setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of the UDP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                        |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPExtraOptions](#udpextraoptions) | Yes  | Other properties of the UDP socket connection. For details, see [UDPExtraOptions](#udpextraoptions).|
| callback | AsyncCallback\<void\>                    | Yes  | Callback used to return the result.                                                  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let netaddress = new NetAddress();
udp.bind(netaddress, (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  class UDPExtraOptions {
    receiveBufferSize: number = 1000
    sendBufferSize: number = 1000
    reuseAddress: boolean = false
    socketTimeout: number = 6000
    broadcast: boolean = true
  }
  let udpextraoptions = new UDPExtraOptions();
  udp.setExtraOptions(udpextraoptions, (err:string) => {
    if (err) {
      console.log('setExtraOptions fail');
      return;
    }
    console.log('setExtraOptions success');
  })
})
```

### setExtraOptions<sup>7+</sup>

setExtraOptions(options: UDPExtraOptions): Promise\<void\>

Sets other properties of the UDP socket connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description                                                        |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [UDPExtraOptions](#udpextraoptions) | Yes  | Other properties of the UDP socket connection. For details, see [UDPExtraOptions](#udpextraoptions).|

**Return value**

| Type           | Description                                                |
| :-------------- | :--------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
let udp: socket = socket.constructUDPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let netaddress = new NetAddress();
class UDPExtraOptions {
  receiveBufferSize: number = 1000
  sendBufferSize: number = 1000
  reuseAddress: boolean = false
  socketTimeout: number = 6000
  broadcast: boolean = true
}
let udpextraoptions = new UDPExtraOptions();
let promise: socket = udp.bind(z);
promise.then(() => {
  console.log('bind success');
  let promise1: socket = udp.setExtraOptions(udpextraoptions);
  promise1.then(() => {
    console.log('setExtraOptions success');
  }).catch((err: string) => {
    console.log('setExtraOptions fail');
  });
}).catch((err: string) => {
  console.log('bind fail');
});
```

### on('message')<sup>7+</sup>

on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Subscribes to **message** events of the UDP socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback\<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}\> | Yes  | Callback used to return the result.                               |

**Example**

```js
import socket from "@ohos.net.socket";
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
let messageView = '';
udp.on('message', (value: SocketInfo) => {
  for (let i : number = 0; i < value.message.byteLength; i++) {
    let messages : number = value.message.i
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')<sup>7+</sup>

off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Unsubscribes from **message** events of the UDP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | No  | Callback used to return the result.                               |

**Example**

```js
import socket from "@ohos.net.socket";
class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let messageView = '';
let callback = (value: SocketInfo) => {
  for (let i : number = 0; i < value.message.byteLength; i++) {
    let messages : number = value.message.i
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
udp.on('message', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
udp.off('message', callback);
udp.off('message');
```

### on('listening' | 'close')<sup>7+</sup>

on(type: 'listening' | 'close', callback: Callback\<void\>): void

Subscribes to **listening** events or **close** events of the UDP socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Type of the event to subscribe to.<br>- **listening**: data packet message event.<br>- **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
import socket from "@ohos.net.socket";
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.on('listening', () => {
  console.log("on listening success");
});
udp.on('close', () => {
  console.log("on close success");
});
```

### off('listening' | 'close')<sup>7+</sup>

off(type: 'listening' | 'close', callback?: Callback\<void\>): void

Unsubscribes from **listening** events or **close** events of the UDP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Type of the event to subscribe to.<br>- **listening**: data packet message event.<br>- **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result.                                                  |

**Example**

```js
import socket from "@ohos.net.socket";
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let callback1 = () => {
  console.log("on listening, success");
}
udp.on('listening', callback1);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
udp.off('listening', callback1);
udp.off('listening');
let callback2 = () => {
  console.log("on close, success");
}
udp.on('close', callback2);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
udp.off('close', callback2);
udp.off('close');
```

### on('error')<sup>7+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of the UDP socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                          |

**Example**

```js
import socket from "@ohos.net.socket";
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.on('error', (err: string) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>7+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of the UDP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                          |

**Example**

```js
import socket from "@ohos.net.socket";
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let callback = (err: string) => {
  console.log("on error, err:" + JSON.stringify(err));
}
udp.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
udp.off('error', callback);
udp.off('error');
```

## NetAddress<sup>7+</sup>

Defines the destination address.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | Yes  | Bound IP address.                                          |
| port    | number | No  | Port number. The value ranges from **0** to **65535**. If this parameter is not specified, the system randomly allocates a port.          |
| family  | number | No  | Network protocol type.<br>- **1**: IPv4<br>- **2**: IPv6<br>The default value is **1**.|

## UDPSendOptions<sup>7+</sup>

Defines the parameters for sending data over the UDP socket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type                              | Mandatory| Description          |
| ------- | ---------------------------------- | ---- | -------------- |
| data    | string \| ArrayBuffer<sup>7+</sup>                          | Yes  | Data to send.  |
| address | [NetAddress](#netaddress) | Yes  | Destination address.|

## UDPExtraOptions<sup>7+</sup>

Defines other properties of the UDP socket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name           | Type   | Mandatory| Description                            |
| ----------------- | ------- | ---- | -------------------------------- |
| broadcast         | boolean | No  | Whether to send broadcast messages. The default value is **false**. |
| receiveBufferSize | number  | No  | Size of the receive buffer, in bytes. The default value is **0**.  |
| sendBufferSize    | number  | No  | Size of the send buffer, in bytes. The default value is **0**.  |
| reuseAddress      | boolean | No  | Whether to reuse addresses. The default value is **false**.     |
| socketTimeout     | number  | No  | Timeout duration of the UDP socket connection, in ms. The default value is **0**.|

## SocketStateBase<sup>7+</sup>

Defines the status of the socket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name     | Type   | Mandatory| Description      |
| ----------- | ------- | ---- | ---------- |
| isBound     | boolean | Yes  | Whether the connection is in the bound state.|
| isClose     | boolean | Yes  | Whether the connection is in the closed state.|
| isConnected | boolean | Yes  | Whether the connection is in the connected state.|

## SocketRemoteInfo<sup>7+</sup>

Defines information about the socket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | Yes  | Bound IP address.                                          |
| family  | string | Yes  | Network protocol type.<br>- IPv4<br>- IPv6<br>The default value is **IPv4**.|
| port    | number | Yes  | Port number. The value ranges from **0** to **65535**.                                       |
| size    | number | Yes  | Length of the server response message, in bytes.                                  |

## Description of UDP Error Codes

The UDP error code mapping is in the format of 2301000 + Linux kernel error code.

For details about error codes, see [Socket Error Codes](../errorcodes/errorcode-net-socket.md).

## socket.constructTCPSocketInstance<sup>7+</sup>

constructTCPSocketInstance(): TCPSocket

Creates a **TCPSocket** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                   |
  | :--------------------------------- | :---------------------- |
| [TCPSocket](#tcpsocket) | **TCPSocket** object.|

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
```

## TCPSocket<sup>7+</sup>

Defines a TCP socket connection. Before calling TCPSocket APIs, you need to call [socket.constructTCPSocketInstance](#socketconstructtcpsocketinstance) to create a **TCPSocket** object.

### bind<sup>7+</sup>

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. This API uses an asynchronous callback to return the result.

> **NOTE**
> If the operation fails, the system randomly allocates a port number.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                              | Mandatory| Description                                                  |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | Yes  | Destination address. For details, see [NetAddress](#netaddress).|
| callback | AsyncCallback\<void\>              | Yes  | Callback used to return the result.                                            |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let netaddress = new NetAddress();
tcp.bind(netaddress, (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
})
```

### bind<sup>7+</sup>

bind(address: NetAddress): Promise\<void\>

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. This API uses a promise to return the result.

> **NOTE**
> If the operation fails, the system randomly allocates a port number.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                              | Mandatory| Description                                                  |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress) | Yes  | Destination address. For details, see [NetAddress](#netaddress).|

**Return value**

| Type           | Description                                                    |
| :-------------- | :------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let netaddress = new NetAddress();
let promise: socket = tcp.bind(netaddress);
promise.then(() => {
  console.log('bind success');
}).catch((err: string) => {
  console.log('bind fail');
});
```

### connect<sup>7+</sup>

connect(options: TCPConnectOptions, callback: AsyncCallback\<void\>): void

Sets up a connection to the specified IP address and port number. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                        |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPConnectOptions](#tcpconnectoptions) | Yes  | TCP socket connection parameters. For details, see [TCPConnectOptions](#tcpconnectoptions).|
| callback | AsyncCallback\<void\>                    | Yes  | Callback used to return the result.                                                  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let ipAddr : socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080

let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
tcp.connect(tcpconnectoptions, (err: string) => {
  if (err) {
    console.log('connect fail');
    return;
  }
  console.log('connect success');
})
```

### connect<sup>7+</sup>

connect(options: TCPConnectOptions): Promise\<void\>

Sets up a connection to the specified IP address and port number. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description                                                        |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPConnectOptions](#tcpconnectoptions) | Yes  | TCP socket connection parameters. For details, see [TCPConnectOptions](#tcpconnectoptions).|

**Return value**

| Type           | Description                                                      |
| :-------------- | :--------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let ipAddr : socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080

let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
let promise: socket = tcp.connect(tcpconnectoptions);
promise.then(() => {
  console.log('connect success')
}).catch((err: string) => {
  console.log('connect fail');
});
```

### send<sup>7+</sup>

send(options: TCPSendOptions, callback: AsyncCallback\<void\>): void

Sends data over a TCP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPSendOptions](#tcpsendoptions) | Yes  | Parameters for sending data over the TCP socket connection. For details, see [TCPSendOptions](#tcpsendoptions).|
| callback | AsyncCallback\<void\>                   | Yes  | Callback used to return the result.                                                  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let ipAddr : socket.NetAddress = {} as socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080

let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpSendOptions : socket.TCPSendOptions
  tcpSendOptions.data = 'Hello, server!'
  tcp.send(tcpSendOptions, (err: string) => {
    if (err) {
      console.log('send fail');
      return;
    }
    console.log('send success');
  })
})
```

### send<sup>7+</sup>

send(options: TCPSendOptions): Promise\<void\>

Sends data over a TCP socket connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                   | Mandatory| Description                                                        |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPSendOptions](#tcpsendoptions) | Yes  | Parameters for sending data over the TCP socket connection. For details, see [TCPSendOptions](#tcpsendoptions).|

**Return value**

| Type           | Description                                              |
| :-------------- | :------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let ipAddr : socket.NetAddress = {} as socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080
let tcpconnectoptions : socket.TCPConnectOptions = {} as socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success');
  let tcpSendOptions : socket.TCPSendOptions = {} as socket.TCPSendOptions
  tcpSendOptions.data = 'Hello, server!'
  tcp.send(tcpSendOptions).then(() => {
    console.log('send success');
  }).catch((err: string) => {
    console.log('send fail');
  });
}).catch((err: string) => {
  console.log('connect fail');
});
```

### close<sup>7+</sup>

close(callback: AsyncCallback\<void\>): void

Closes a TCP socket connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

tcp.close((err: string) => {
  if (err) {
    console.log('close fail');
    return;
  }
  console.log('close success');
})
```

### close<sup>7+</sup>

close(): Promise\<void\>

Closes a TCP socket connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                      |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let promise: socket = tcp.close();
promise.then(() => {
  console.log('close success');
}).catch((err: string) => {
  console.log('close fail');
});
```

### getRemoteAddress<sup>7+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

Obtains the remote address of a socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                             | Mandatory| Description      |
| -------- | ------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback<[NetAddress](#netaddress)> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let ipAddr : socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080
let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  tcp.getRemoteAddress((err: string, data: string) => {
    if (err) {
      console.log('getRemoteAddressfail');
      return;
    }
    console.log('getRemoteAddresssuccess:' + JSON.stringify(data));
  })
});
```

### getRemoteAddress<sup>7+</sup>

getRemoteAddress(): Promise\<NetAddress\>

Obtains the remote address of a socket connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                       | Description                                       |
| :------------------------------------------ | :------------------------------------------ |
| Promise<[NetAddress](#netaddress)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let ipAddr : socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080
let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success');
  tcp.getRemoteAddress().then(() => {
    console.log('getRemoteAddress success');
  }).catch((err: string) => {
    console.log('getRemoteAddressfail');
  });
}).catch((err: string) => {
  console.log('connect fail');
});
```

### getState<sup>7+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of the TCP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback<[SocketStateBase](#socketstatebase)> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let ipAddr : socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080
let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
let promise: socket = tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  tcp.getState((err: string, data: string) => {
    if (err) {
      console.log('getState fail');
      return;
    }
    console.log('getState success:' + JSON.stringify(data));
  });
});
```

### getState<sup>7+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of the TCP socket connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                            | Description                                      |
| :----------------------------------------------- | :----------------------------------------- |
| Promise<[SocketStateBase](#socketstatebase)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let ipAddr : socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080
let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success');
  tcp.getState().then(() => {
    console.log('getState success');
  }).catch((err: string) => {
    console.log('getState fail');
  });
}).catch((err: string) => {
  console.log('connect fail');
});
```

### getSocketFd<sup>10+</sup>

getSocketFd(callback: AsyncCallback\<number\>): void

Obtains the file descriptor of the **TCPSocket** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result. If the operation is successful, the file descriptor of the socket is returned. Otherwise, **undefined** is returned.|

**Example**

```js
  import socket from "@ohos.net.socket";
  let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
  let tunnelfd = 0
  let bindAddr : socket.NetAddress
  bindAddr.address = '0.0.0.0'
  tcp.bind(bindAddr)

  let ipAddr : socket.NetAddress
  ipAddr.address = '192.168.xx.xxx'
  ipAddr.port = 8080
  let tcpconnectoptions : socket.TCPConnectOptions
  tcpconnectoptions.address = ipAddr
  tcpconnectoptions.timeout = 6000
  tcp.connect(tcpconnectoptions)
  tcp.getSocketFd((data: string) => {
    console.info("tunenlfd: " + data);
    tunnelfd = data
  })
```
### getSocketFd<sup>10+</sup>

getSocketFd(): Promise\<number\>

Obtains the file descriptor of the **TCPSocket** object. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                            | Description                                      |
| :----------------------------------------------- | :----------------------------------------- |
| Promise\<number\> | Promise used to return the result.|

**Example**

```js
  import socket from "@ohos.net.socket";
  let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
  let tunnelfd = 0
  let bindAddr : socket.NetAddress
  bindAddr.address = '0.0.0.0'
  tcp.bind(bindAddr)

  let ipAddr : socket.NetAddress
  ipAddr.address = '192.168.xx.xxx'
  ipAddr.port = 8080
  let tcpconnectoptions : socket.TCPConnectOptions
  tcpconnectoptions.address = ipAddr
  tcpconnectoptions.timeout = 6000
  tcp.connect(tcpconnectoptions)
  tcp.getSocketFd().then((data: string) => {
      console.info("tunenlfd: " + data);
      tunnelfd = data
  })
```

### setExtraOptions<sup>7+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of the TCP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of the TCP socket connection. For details, see [TCPExtraOptions](#tcpextraoptions).|
| callback | AsyncCallback\<void\>                     | Yes  | Callback used to return the result.                                                  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let ipAddr : socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080
let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000

let tcpExtraOptions : socket.TCPExtraOptions
tcpExtraOptions.keepAlive = true
tcpExtraOptions.OOBInline = true
tcpExtraOptions.TCPNoDelay = true
tcpExtraOptions.socketLinger = { on: true, linger: 10 }
tcpExtraOptions.receiveBufferSize = 1000
tcpExtraOptions.sendBufferSize = 1000
tcpExtraOptions.reuseAddress = true
tcpExtraOptions.socketTimeout = 3000

tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  tcp.setExtraOptions(tcpExtraOptions, (err: string) => {
    if (err) {
      console.log('setExtraOptions fail');
      return;
    }
    console.log('setExtraOptions success');
  });
});
```

### setExtraOptions<sup>7+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

Sets other properties of the TCP socket connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of the TCP socket connection. For details, see [TCPExtraOptions](#tcpextraoptions).|

**Return value**

| Type           | Description                                                |
| :-------------- | :--------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let ipAddr : socket.NetAddress
ipAddr.address = '192.168.xx.xxx'
ipAddr.port = 8080
let tcpconnectoptions : socket.TCPConnectOptions
tcpconnectoptions.address = ipAddr
tcpconnectoptions.timeout = 6000
class Linger {
  on: boolean = true
  linger: number = 10
}
class TCPExtraOptions {
  keepAlive: boolean = true
  OOBInline: boolean = true
  TCPNoDelay: boolean = true
  socketLinger: Object = new Linger()
  receiveBufferSize: number = 1000
  sendBufferSize: number = 1000
  reuseAddress: boolean = true
  socketTimeout: number = 3000
}
let promise: socket = tcp.connect(new TCPConnectOptions());
promise.then(() => {
  console.log('connect success');
  let promise1: socket = tcp.setExtraOptions(new TCPExtraOptions());
  promise1.then(() => {
    console.log('setExtraOptions success');
  }).catch((err: string) => {
    console.log('setExtraOptions fail');
  });
}).catch((err: string) => {
  console.log('connect fail');
});
```

### on('message')<sup>7+</sup>

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Subscribes to **message** events of the TCP socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | Yes  | Callback used to return the result.                               |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
let messageView = '';
tcp.on('message', (value: SocketInfo) => {
  for (let i : number = 0; i < value.message.byteLength; i++) {
    let messages : number = value.message.i
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')<sup>7+</sup>

off(type: 'message', callback?: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Unsubscribes from **message** events of the TCP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | No  | Callback used to return the result.                               |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
let messageView = '';
let callback = (value: SocketInfo) => {
  for (let i : number = 0; i < value.message.byteLength; i++) {
    let messages : number = value.message.i
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
tcp.on('message', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcp.off('message', callback);
tcp.off('message');
```

### on('connect' | 'close')<sup>7+</sup>

on(type: 'connect' | 'close', callback: Callback\<void\>): void

Subscribes to connection or close events of the TCP socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Type of the event to subscribe to.<br>- **connect**: connection event.<br>- **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
tcp.on('connect', () => {
  console.log("on connect success")
});
tcp.on('close', () => {
  console.log("on close success")
});
```

### off('connect' | 'close')<sup>7+</sup>

off(type: 'connect' | 'close', callback?: Callback\<void\>): void

Unsubscribes from connection or close events of the TCP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Type of the event to subscribe to.<br>- **connect**: connection event.<br>- **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result.                                                  |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let callback1 = () => {
  console.log("on connect success");
}
tcp.on('connect', callback1);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcp.off('connect', callback1);
tcp.off('connect');
let callback2 = () => {
  console.log("on close success");
}
tcp.on('close', callback2);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcp.off('close', callback2);
tcp.off('close');
```

### on('error')<sup>7+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of the TCP socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                          |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
tcp.on('error', (err: string) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>7+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of the TCP socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                          |

**Example**

```js
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let callback = (err: string) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tcp.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcp.off('error', callback);
tcp.off('error');
```

## TCPConnectOptions<sup>7+</sup>

Defines TCP socket connection parameters.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type                              | Mandatory| Description                      |
| ------- | ---------------------------------- | ---- | -------------------------- |
| address | [NetAddress](#netaddress) | Yes  | Bound IP address and port number.      |
| timeout | number                             | No  | Timeout duration of the TCP socket connection, in ms.|

## TCPSendOptions<sup>7+</sup>

Defines the parameters for sending data over the TCP socket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| data     | string\| ArrayBuffer<sup>7+</sup>  | Yes  | Data to send.                                                |
| encoding | string | No  | Character encoding format. The options are as follows: **UTF-8**, **UTF-16BE**, **UTF-16LE**, **UTF-16**, **US-AECII**, and **ISO-8859-1**. The default value is **UTF-8**.|

## TCPExtraOptions<sup>7+</sup>

Defines other properties of the TCP socket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name           | Type   | Mandatory| Description                                                        |
| ----------------- | ------- | ---- | ------------------------------------------------------------ |
| keepAlive         | boolean | No  | Whether to keep the connection alive. The default value is **false**.                                 |
| OOBInline         | boolean | No  | Whether to enable OOBInline. The default value is **false**.                                |
| TCPNoDelay        | boolean | No  | Whether to enable no-delay on the TCP socket connection. The default value is **false**.                      |
| socketLinger      | Object  | Yes  | Socket linger.<br>- **on**: whether to enable socket linger. The value true means to enable socket linger and false means the opposite.<br>- **linger**: linger time, in ms. The value ranges from **0** to **65535**.<br>Specify this parameter only when **on** is set to **true**.|
| receiveBufferSize | number  | No  | Size of the receive buffer, in bytes. The default value is **0**.                              |
| sendBufferSize    | number  | No  | Size of the send buffer, in bytes. The default value is **0**.                              |
| reuseAddress      | boolean | No  | Whether to reuse addresses. The default value is **false**.                                 |
| socketTimeout     | number  | No  | Timeout duration of the UDP socket connection, in ms. The default value is **0**.                            |

## socket.constructTCPSocketServerInstance<sup>10+</sup>

constructTCPSocketServerInstance(): TCPSocketServer

Creates a **TCPSocketServer** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                               | Description                         |
| :---------------------------------- | :---------------------------- |
| [TCPSocketServer](#tcpsocketserver10) | **TCPSocketServer** object.|

**Example**

```js
let tcpServer: socket = socket.constructTCPSocketServerInstance();
```

## TCPSocketServer<sup>10+</sup>

Defines a TCPSocketServer connection. Before calling TCPSocketServer APIs, you need to call [socket.constructTCPSocketServerInstance](#socketconstructtcpsocketserverinstance10) to create a **TCPSocketServer** object.

### listen<sup>10+</sup>

listen(address: NetAddress, callback: AsyncCallback\<void\>): void

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. The server listens to and accepts TCP socket connections established over the socket. Multiple threads are used to process client data concurrently. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> The server uses this API to perform the **bind**, **listen**, and **accept** operations. If the **bind** operation fails, the system randomly allocates a port number.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                     | Mandatory| Description                                         |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| address  | [NetAddress](#netaddress7) | Yes  | Destination address.|
| callback | AsyncCallback\<void\>     | Yes  | Callback used to return the result.                                   |

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable try again. |
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
tcpServer.listen(new NetAddress(), (err: string) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
```

### listen<sup>10+</sup>

listen(address: NetAddress): Promise\<void\>

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. The server listens to and accepts TCP socket connections established over the socket. Multiple threads are used to process client data concurrently. This API uses a promise to return the result.

> **NOTE**<br>
> The server uses this API to perform the **bind**, **listen**, and **accept** operations. If the **bind** operation fails, the system randomly allocates a port number.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                     | Mandatory| Description                                         |
| ------- | ------------------------- | ---- | --------------------------------------------- |
| address | [NetAddress](#netaddress7) | Yes  | Destination address.|

**Return value**

| Type           | Description                                                        |
| :-------------- | :----------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable try again. |
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let promise: socket = tcpServer.listen(new NetAddress());
promise.then(() => {
  console.log('listen success');
}).catch((err: string) => {
  console.log('listen fail');
});
```

### getState<sup>10+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of the TCPSocketServer connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                              | Mandatory| Description      |
| -------- | -------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback<[SocketStateBase](#socketstatebase7)> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
tcpServer.listen(new NetAddress(), (err: string) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
tcpServer.getState((err: string, data: string) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
})
```

### getState<sup>10+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of the TCPSocketServer connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                        | Description                                      |
| :------------------------------------------- | :----------------------------------------- |
| Promise<[SocketStateBase](#socketstatebase7)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let promiseListen: socket = tcpServer.listen(new NetAddress());
promiseListen.then(() => {
  console.log('listen success');
}).catch((err: string) => {
  console.log('listen fail');
});
let promise: socket = tcpServer.getState();
promise.then(() => {
  console.log('getState success');
}).catch((err: string) => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of the TCPSocketServer connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions7) | Yes  | Other properties of the TCPSocketServer connection.|
| callback | AsyncCallback\<void\>               | Yes  | Callback used to return the result.                                                  |

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
tcpServer.listen(new NetAddress(), (err: string) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
class Linger {
  on: boolean = true
  linger: number = 10
}
class TCPExtraOptions {
  keepAlive: boolean = true
  OOBInline: boolean = true
  TCPNoDelay: boolean = true
  socketLinger: Object = new Linger()
  receiveBufferSize: number = 1000
  sendBufferSize: number = 1000
  reuseAddress: boolean = true
  socketTimeout: number = 3000
}
tcpServer.setExtraOptions(new TCPExtraOptions(), (err: string) => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

Sets other properties of the TCPSocketServer connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                               | Mandatory| Description                                                        |
| ------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions7) | Yes  | Other properties of the TCPSocketServer connection.|

**Return value**

| Type           | Description                                                      |
| :-------------- | :--------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let promiseListen: socket = tcpServer.listen(new NetAddress());
promiseListen.then(() => {
  console.log('listen success');
}).catch((err: string) => {
  console.log('listen fail');
});
class Linger {
  on: boolean = true
  linger: number = 10
}
class TCPExtraOptions {
  keepAlive: boolean = true
  OOBInline: boolean = true
  TCPNoDelay: boolean = true
  socketLinger: Object = new Linger()
  receiveBufferSize: number = 1000
  sendBufferSize: number = 1000
  reuseAddress: boolean = true
  socketTimeout: number = 3000
}
let promise: socket = tcpServer.setExtraOptions(new TCPExtraOptions());
promise.then(() => {
  console.log('setExtraOptions success');
}).catch((err: string) => {
  console.log('setExtraOptions fail');
});
```

### on('connect')<sup>10+</sup>

on(type: 'connect', callback: Callback\<TCPSocketConnection\>): void

Subscribes to TCPSocketServer connection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                           | Mandatory| Description                                 |
| -------- | ------------------------------- | ---- | ------------------------------------- |
| type     | string                          | Yes  | Type of the event to subscribe to.<br/> **connect**: connection event.|
| callback | Callback<[TCPSocketConnection](#tcpsocketconnection10)> | Yes  | Callback used to return the result.                           |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (data: string) => {
  console.log(JSON.stringify(data))
});
```

### off('connect')<sup>10+</sup>

off(type: 'connect', callback?: Callback\<TCPSocketConnection\>): void

Unsubscribes from TCPSocketServer connection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                           | Mandatory| Description                                 |
| -------- | ------------------------------- | ---- | ------------------------------------- |
| type     | string                          | Yes  | Type of the event to subscribe to.<br/> **connect**: connection event.|
| callback | Callback<[TCPSocketConnection](#tcpsocketconnection10)> | No  | Callback used to return the result.                           |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = (data: string) => {
  console.log('on connect message: ' + JSON.stringify(data));
}
tcpServer.on('connect', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcpServer.off('connect', callback);
tcpServer.off('connect');
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of the TCPSocketServer connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('error', (err: string) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of the TCPSocketServer connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = (err: string) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tcpServer.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcpServer.off('error', callback);
tcpServer.off('error');
```

## TCPSocketConnection<sup>10+</sup>

Defines a **TCPSocketConnection** object, that is, the connection between the TCPSocket client and the server. Before calling TCPSocketConnection APIs, you need to obtain a **TCPSocketConnection** object.

> **NOTE**
> The TCPSocket client can call related APIs through the **TCPSocketConnection** object only after a connection is successfully established between the TCPSocket client and the server.

**System capability**: SystemCapability.Communication.NetStack

### Attributes

| Name    | Type  | Mandatory| Description                                     |
| -------- | ------ | ---- | ----------------------------------------- |
| clientId | number | Yes  | ID of the connection between the client and TCPSocketServer.|

### send<sup>10+</sup>

send(options: TCPSendOptions, callback: AsyncCallback\<void\>): void

Sends data over a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after a connection with the client is set up.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPSendOptions](#tcpsendoptions7) | Yes  | Defines the parameters for sending data over the **TCPSocketConnection** object.|
| callback | AsyncCallback\<void\>             | Yes  | Callback used to return the result.                                                  |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client : socket.TCPSocketConnection) => {
  let tcpSendOption : socket.TCPSendOptions
  tcpSendOption.data = 'Hello, client!'
  client.send(tcpSendOption, () => {
    console.log('send success');
  });
});
```

### send<sup>10+</sup>

send(options: TCPSendOptions): Promise\<void\>

Sends data over a **TCPSocketConnection** object. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after a connection with the client is set up.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                             | Mandatory| Description                                                        |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPSendOptions](#tcpsendoptions7) | Yes  | Defines the parameters for sending data over the **TCPSocketConnection** object.|

**Return value**

| Type           | Description                                                        |
| :-------------- | :----------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  let tcpSendOption : socket.TCPSendOptions
  tcpSendOption.data = 'Hello, client!'
  client.send(tcpSendOption).then(() => {
    console.log('send success');
  }).catch((err: string) => {
    console.log('send fail');
  });
});
```

### close<sup>10+</sup>

close(callback: AsyncCallback\<void\>): void

Closes a TCP socket connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.close((err: string) => {
    if (err) {
      console.log('close fail');
      return;
    }
    console.log('close success');
  });
});
```

### close<sup>10+</sup>

close(): Promise\<void\>

Closes a TCP socket connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                        |
| :-------------- | :------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  let promise: socket = client.close();
  promise.then(() => {
  	console.log('close success');
  }).catch((err: string) => {
  	console.log('close fail');
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

Obtains the remote address of a socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after a connection with the client is set up.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description      |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback | AsyncCallback<[NetAddress](#netaddress7)> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.getRemoteAddress((err: string, data: string) => {
    if (err) {
      console.log('getRemoteAddress fail');
      return;
    }
    console.log('getRemoteAddress success:' + JSON.stringify(data));
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(): Promise\<NetAddress\>

Obtains the remote address of a socket connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after a connection with the client is set up.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                                       |
| :--------------------------------- | :------------------------------------------ |
| Promise<[NetAddress](#netaddress7)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  let promise: socket = client.getRemoteAddress();
  promise.then(() => {
    console.log('getRemoteAddress success');
  }).catch((err: string) => {
    console.log('getRemoteAddress fail');
  });
});
```

### on('message')<sup>10+</sup>

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Subscribes to **message** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo7)}> | Yes  | Callback used to return the result.<br> **message**: received message.<br>**remoteInfo**: socket connection information.                               |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('message', (value: SocketInfo) => {
    let messageView = '';
    for (let i : number = 0; i < value.message.byteLength; i++) {
      let messages : number = value.message.i
      let message = String.fromCharCode(messages);
      messageView += message;
    }
    console.log('on message message: ' + JSON.stringify(messageView));
    console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
  });
});
```

### off('message')<sup>10+</sup>

off(type: 'message', callback?: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Unsubscribes from **message** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo7)}> | No  | Callback used to return the result.<br> **message**: received message.<br>**remoteInfo**: socket connection information.                               |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
let callback = (value: SocketInfo) => {
  let messageView = '';
  for (let i : number = 0; i < value.message.byteLength; i++) {
    let messages : number = value.message.i
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('message', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  client.off('message', callback);
  client.off('message');
});
```

### on('close')<sup>10+</sup>

on(type: 'close', callback: Callback\<void\>): void

Subscribes to **close** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                               |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | Yes  | Type of the event to subscribe to.<br/> **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.                         |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('close', () => {
    console.log("on close success")
  });
});
```

### off('close')<sup>10+</sup>

off(type: 'close', callback?: Callback\<void\>): void

Unsubscribes from **close** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                               |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | Yes  | Type of the event to subscribe to.<br/> **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result.                         |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = () => {
  console.log("on close success");
}
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('close', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  client.off('close', callback);
  client.off('close');
});
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('error', (err: string) => {
    console.log("on error, err:" + JSON.stringify(err))
  });
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let callback = (err: string) => {
  console.log("on error, err:" + JSON.stringify(err));
}
let tcpServer: socket = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket) => {
  client.on('error', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  client.off('error', callback);
  client.off('error');
});
```

## Description of TCP Error Codes

The TCP error code mapping is in the format of 2301000 + Linux kernel error code.

For details about error codes, see [Socket Error Codes](../errorcodes/errorcode-net-socket.md).

## socket.constructTLSSocketInstance<sup>9+</sup>

constructTLSSocketInstance(): TLSSocket

Creates a **TLSSocket** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                   |
| :--------------------------------- | :---------------------- |
| [TLSSocket](#tlssocket9) | **TLSSocket** object.|

**Example**

```js
let tls: socket = socket.constructTLSSocketInstance();
```

## TLSSocket<sup>9+</sup>

Defines a TLS socket connection. Before calling TLSSocket APIs, you need to call [socket.constructTLSSocketInstance](#socketconstructtlssocketinstance9) to create a **TLSSocket** object.

### bind<sup>9+</sup>

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

Binds the IP address and port number. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                              | Mandatory| Description                                                  |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | Yes  | Destination address. For details, see [NetAddress](#netaddress).|
| callback | AsyncCallback\<void\>              | Yes  | Callback used to return the result. If the operation is successful, the result of binding the local IP address and port number is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2303198 | Address already in use. |
| 2300002 | System internal error.  |

**Example**

```js
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
tls.bind(new NetAddress(), (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
```

### bind<sup>9+</sup>

bind(address: NetAddress): Promise\<void\>

Binds the IP address and port number. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                              | Mandatory| Description                                                  |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress)          | Yes  | Destination address. For details, see [NetAddress](#netaddress).|

**Return value**

| Type           | Description                                                    |
| :-------------- | :------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2303198 | Address already in use. |
| 2300002 | System internal error.  |

**Example**

```js
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let promise: socket = tls.bind(new NetAddress());
promise.then(() => {
  console.log('bind success');
}).catch((err: string) => {
  console.log('bind fail');
});
```

### getState<sup>9+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of the TLS socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase)> | Yes  | Callback used to return the result. If the operation is successful, the status of the TLS socket connection is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```js
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let promise: socket = tls.bind(new NetAddress(), (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
tls.getState((err: string, data: string) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
});
```

### getState<sup>9+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of the TLS socket connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                            | Description                                      |
| :----------------------------------------------- | :----------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```js
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
let promiseBind: socket = tls.bind(new NetAddress());
promiseBind.then(() => {
  console.log('bind success');
}).catch((err: string) => {
  console.log('bind fail');
});
let promise: socket = tls.getState();
promise.then(() => {
  console.log('getState success');
}).catch((err: string) => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>9+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of the TCP socket connection after **bind** is successfully called. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of the TCP socket connection. For details, see [TCPExtraOptions](#tcpextraoptions).|
| callback | AsyncCallback\<void\>                     | Yes  | Callback used to return the result. If the operation is successful, the result of setting other properties of the TCP socket connection is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 401     | Parameter error.               |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```js
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
tls.bind(new NetAddress(), (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
class Linger {
  on: boolean = true
  linger: number = 10
}
class TCPExtraOptions {
  keepAlive: boolean = true
  OOBInline: boolean = true
  TCPNoDelay: boolean = true
  socketLinger: Object = new Linger()
  receiveBufferSize: number = 1000
  sendBufferSize: number = 1000
  reuseAddress: boolean = true
  socketTimeout: number = 3000
}
tls.setExtraOptions(new TCPExtraOptions(), (err: string) => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>9+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

Sets other properties of the TCP socket connection after **bind** is successfully called. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of the TCP socket connection. For details, see [TCPExtraOptions](#tcpextraoptions).|

**Return value**

| Type           | Description                                                |
| :-------------- | :--------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 401     | Parameter error.               |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```js
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
tls.bind(new NetAddress(), (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
class Linger {
  on: boolean = true
  linger: number = 10
}
class TCPExtraOptions {
  keepAlive: boolean = true
  OOBInline: boolean = true
  TCPNoDelay: boolean = true
  socketLinger: Object = new Linger()
  receiveBufferSize: number = 1000
  sendBufferSize: number = 1000
  reuseAddress: boolean = true
  socketTimeout: number = 3000
}
let promise: socket = tls.setExtraOptions(new TCPExtraOptions());
promise.then(() => {
  console.log('setExtraOptions success');
}).catch((err: string) => {
  console.log('setExtraOptions fail');
});
```

### on('message')<sup>9+</sup>

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;

Subscribes to **message** events of the TLS socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback\<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}\> | Yes  | Callback used to return the result.<br> **message**: received message.<br>**remoteInfo**: socket connection information.|

**Example**

```js
import socket from '@ohos.net.socket';
let tls: socket = socket.constructTLSSocketInstance();
class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
let messageView = '';
tls.on('message', (value: SocketInfo) => {
  for (let i : number = 0; i < value.message.byteLength; i++) {
    let messages : number = value.message.i
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')<sup>9+</sup>

off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Unsubscribes from **message** events of the TLS socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | No  | Callback used to return the result.<br> **message**: received message.<br>**remoteInfo**: socket connection information.|

**Example**

```js
import socket from '@ohos.net.socket';
let tls: socket = socket.constructTLSSocketInstance();
class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
let messageView = '';
let callback = (value: SocketInfo) => {
  for (let i : number = 0; i < value.message.byteLength; i++) {
    let messages : number = value.message.i
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
tls.on('message', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tls.off('message', callback);
```
### on('connect' | 'close')<sup>9+</sup>

on(type: 'connect' | 'close', callback: Callback\<void\>): void

Subscribes to **connect** or **close** events of the TLS socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Type of the event to subscribe to.<br>- **connect**: connection event.<br>- **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.                                                  |

**Example**

```js
import socket from '@ohos.net.socket';
let tls: socket = socket.constructTLSSocketInstance();
tls.on('connect', () => {
  console.log("on connect success")
});
tls.on('close', () => {
  console.log("on close success")
});
```

### off('connect' | 'close')<sup>9+</sup>

off(type: 'connect' | 'close', callback?: Callback\<void\>): void

Unsubscribes from **connect** or **close** events of the TLS socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Type of the event to subscribe to.<br>- **connect**: connection event.<br>- **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result.                                                  |

**Example**

```js
import socket from '@ohos.net.socket';
let tls: socket = socket.constructTLSSocketInstance();
let callback1 = () => {
  console.log("on connect success");
}
tls.on('connect', callback1);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tls.off('connect', callback1);
tls.off('connect');
let callback2 = () => {
  console.log("on close success");
}
tls.on('close', callback2);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tls.off('close', callback2);
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of the TLS socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                          |

**Example**

```js
import socket from '@ohos.net.socket';
let tls: socket = socket.constructTLSSocketInstance();
tls.on('error', (err: string) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>9+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of the TLS socket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                          |

**Example**

```js
import socket from '@ohos.net.socket';
let tls: socket = socket.constructTLSSocketInstance();
let callback = (err: string) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tls.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tls.off('error', callback);
```

### connect<sup>9+</sup>

connect(options: TLSConnectOptions, callback: AsyncCallback\<void\>): void

Sets up a TLS socket connection, and creates and initializes a TLS session after **bind** is successfully called. During this process, a TLS/SSL handshake is performed between the application and the server to implement data transmission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description|
| -------- | ---------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions9) | Yes  | Parameters required for the TLS socket connection.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303104 | Interrupted system call.                     |
| 2303109 | Bad file number.                             |
| 2303111 | Resource temporarily unavailable try again.  |
| 2303188 | Socket operation on non-socket.              |
| 2303191 | Protocol wrong type for socket.              |
| 2303198 | Address already in use.                      |
| 2303199 | Cannot assign requested address.             |
| 2303210 | Connection timed out.                        |
| 2303501 | SSL is null.                                 |
| 2303502 | Error in tls reading.                        |
| 2303503 | Error in tls writing                         |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**Example**

```js
let tlsTwoWay: socket = socket.constructTLSSocketInstance(); // Two way authentication
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
tlsTwoWay.bind(new NetAddress(), (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
};
tlsTwoWay.connect(new Options(), (err: string, data: string) => {
  console.error("connect callback error" + err);
  console.log(JSON.stringify(data));
});

let tlsOneWay: socket = socket.constructTLSSocketInstance(); // One way authentication
tlsOneWay.bind(new NetAddress(), (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
class SecureOptions{
    ca: string[] = ["xxxx", "xxxx"]
    cipherSuite: string = "AES256-SHA256"
}
class OneWayOptions {
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
};
tlsOneWay.connect(new OneWayOptions(), (err: string, data: string) => {
  console.error("connect callback error" + err);
  console.log(JSON.stringify(data));
});
```

### connect<sup>9+</sup>

connect(options: TLSConnectOptions): Promise\<void\>

Sets up a TLS socket connection, and creates and initializes a TLS session after **bind** is successfully called. During this process, a TLS/SSL handshake is performed between the application and the server to implement data transmission. Both two-way and one-way authentication modes are supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description|
| -------- | --------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions9) | Yes  | Parameters required for the connection.|

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<void\>                              | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303104 | Interrupted system call.                     |
| 2303109 | Bad file number.                             |
| 2303111 | Resource temporarily unavailable try again.  |
| 2303188 | Socket operation on non-socket.              |
| 2303191 | Protocol wrong type for socket.              |
| 2303198 | Address already in use.                      |
| 2303199 | Cannot assign requested address.             |
| 2303210 | Connection timed out.                        |
| 2303501 | SSL is null.                                 |
| 2303502 | Error in tls reading.                        |
| 2303503 | Error in tls writing                         |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**Example**

```js
let tlsTwoWay: socket = socket.constructTLSSocketInstance(); // Two way authentication
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
tlsTwoWay.bind(new NetAddress(), (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
};
tlsTwoWay.connect(new Options()).then((data: string) => {
  console.log(JSON.stringify(data));
}).catch((err: string) => {
  console.error(err);
});

let tlsOneWay: socket = socket.constructTLSSocketInstance(); // One way authentication
tlsOneWay.bind(new NetAddress(), (err: string) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
class SecureOptions{
  ca: string[] = ["xxxx", "xxxx"]
  cipherSuite: string = "AES256-SHA256"
}
class OneWayOptions {
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
};
tlsOneWay.connect(new OneWayOptions()).then((data: string) => {
  console.log(JSON.stringify(data));
}).catch((err: string) => {
  console.error(err);
});
```

### getRemoteAddress<sup>9+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

Obtains the remote address of a TLS socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                             | Mandatory| Description      |
| -------- | ------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetAddress](#netaddress)\> | Yes  | Callback used to return the result. If the operation is successful, the remote address is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```js
tls.getRemoteAddress((err: string, data: string) => {
  if (err) {
    console.log('getRemoteAddress fail');
    return;
  }
  console.log('getRemoteAddress success:' + JSON.stringify(data));
});
```

### getRemoteAddress<sup>9+</sup>

getRemoteAddress(): Promise\<NetAddress\>

Obtains the remote address of a TLS socket connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                       | Description                                       |
| :------------------------------------------ | :------------------------------------------ |
| Promise\<[NetAddress](#netaddress)> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```js
let promise: socket = tls.getRemoteAddress();
promise.then(() => {
  console.log('getRemoteAddress success');
}).catch((err: string) => {
  console.log('getRemoteAddress fail');
});
```

### getCertificate<sup>9+</sup>

getCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

Obtains the local digital certificate after a TLS socket connection is established. This API is applicable to two-way authentication. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description|
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>    | Yes  | Callback used to return the result. If the operation is successful, the local certificate is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303504 | Error looking up x509.         |
| 2300002 | System internal error.         |

**Example**

```js
tls.getCertificate((err: string, data: string) => {
  if (err) {
    console.log("getCertificate callback error = " + err);
  } else {
    console.log("getCertificate callback = " + data);
  }
});
```

### getCertificate<sup>9+</sup>

getCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

Obtains the local digital certificate after a TLS socket connection is established. This API is applicable to two-way authentication. It uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                 |
| -------------- | -------------------- |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303504 | Error looking up x509.         |
| 2300002 | System internal error.         |

**Example**

```js
tls.getCertificate().then((data: string) => {
  console.log(data);
}).catch((err: string) => {
  console.error(err);
});
```

### getRemoteCertificate<sup>9+</sup>

getRemoteCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

Obtains the digital certificate of the server after a TLS socket connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type                                   | Mandatory | Description          |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>  | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2300002 | System internal error.         |

**Example**

```js
tls.getRemoteCertificate((err: string, data: string) => {
  if (err) {
    console.log("getRemoteCertificate callback error = " + err);
  } else {
    console.log("getRemoteCertificate callback = " + data);
  }
});
```

### getRemoteCertificate<sup>9+</sup>

getRemoteCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

Obtains the digital certificate of the server after a TLS socket connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                 |
| -------------- | -------------------- |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2300002 | System internal error.         |

**Example**

```js
tls.getRemoteCertificate().then((data: string) => {
  console.log(data);
}).catch((err: string) => {
  console.error(err);
});
```

### getProtocol<sup>9+</sup>

getProtocol(callback: AsyncCallback\<string\>): void

Obtains the communication protocol version after a TLS socket connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                      | Mandatory| Description          |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string\>                  | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 2303501 | SSL is null.                   |
| 2303505 | Error occurred in the tls system call. |
| 2300002 | System internal error.         |

**Example**

```js
tls.getProtocol((err: string, data: string) => {
  if (err) {
    console.log("getProtocol callback error = " + err);
  } else {
    console.log("getProtocol callback = " + data);
  }
});
```

### getProtocol<sup>9+</sup>

getProtocol():Promise\<string\>

Obtains the communication protocol version after a TLS socket connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                 |
| -------------- | -------------------- |
| Promise\<string\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303505 | Error occurred in the tls system call. |
| 2300002 | System internal error.         |

**Example**

```js
tls.getProtocol().then((data: string) => {
  console.log(data);
}).catch((err: string) => {
  console.error(err);
});
```

### getCipherSuite<sup>9+</sup>

getCipherSuite(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the cipher suite negotiated by both communication parties after a TLS socket connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description|
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string\>\>          | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303502 | Error in tls reading.          |
| 2303505 | Error occurred in the tls system call. |
| 2300002 | System internal error.         |

**Example**

```js
tls.getCipherSuite((err: string, data: string) => {
  if (err) {
    console.log("getCipherSuite callback error = " + err);
  } else {
    console.log("getCipherSuite callback = " + data);
  }
});
```

### getCipherSuite<sup>9+</sup>

getCipherSuite(): Promise\<Array\<string\>\>

Obtains the cipher suite negotiated by both communication parties after a TLS socket connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                   | Description                 |
| ---------------------- | --------------------- |
| Promise\<Array\<string\>\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303502 | Error in tls reading.          |
| 2303505 | Error occurred in the tls system call. |
| 2300002 | System internal error.         |

**Example**

```js
tls.getCipherSuite().then((data: string) => {
  console.log('getCipherSuite success:' + JSON.stringify(data));
}).catch((err: string) => {
  console.error(err);
});
```

### getSignatureAlgorithms<sup>9+</sup>

getSignatureAlgorithms(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the signing algorithm negotiated by both communication parties after a TLS socket connection is established. This API is applicable to two-way authentication. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description           |
| -------- | -------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string\>\>         | Yes  | Callback used to return the result.  |

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2300002 | System internal error.         |

**Example**

```js
tls.getSignatureAlgorithms((err: string, data: string) => {
  if (err) {
    console.log("getSignatureAlgorithms callback error = " + err);
  } else {
    console.log("getSignatureAlgorithms callback = " + data);
  }
});
```

### getSignatureAlgorithms<sup>9+</sup>

getSignatureAlgorithms(): Promise\<Array\<string\>\>

Obtains the signing algorithm negotiated by both communication parties after a TLS socket connection is established. This API is applicable to two-way authentication. It uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                   | Description                 |
| ---------------------- | -------------------- |
| Promise\<Array\<string\>\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2300002 | System internal error.         |

**Example**

```js
tls.getSignatureAlgorithms().then((data: string) => {
  console.log("getSignatureAlgorithms success" + data);
}).catch((err: string) => {
  console.error(err);
});
```

### send<sup>9+</sup>

send(data: string, callback: AsyncCallback\<void\>): void

Sends a message to the server after a TLS socket connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type                         | Mandatory| Description           |
| -------- | -----------------------------| ---- | ---------------|
|   data   | string                       | Yes  | Data content of the message to send.  |
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303501 | SSL is null.                                 |
| 2303503 | Error in tls writing.                         |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**Example**

```js
tls.send("xxxx", (err: string) => {
  if (err) {
    console.log("send callback error = " + err);
  } else {
    console.log("send success");
  }
});
```

### send<sup>9+</sup>

send(data: string): Promise\<void\>

Sends a message to the server after a TLS socket connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type                         | Mandatory| Description           |
| -------- | -----------------------------| ---- | ---------------|
|   data   | string                       | Yes  | Data content of the message to send.  |

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303501 | SSL is null.                                 |
| 2303503 | Error in tls writing.                         |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**Return value**

| Type          | Description                 |
| -------------- | -------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```js
tls.send("xxxx").then(() => {
  console.log("send success");
}).catch((err: string) => {
  console.error(err);
});
```

### close<sup>9+</sup>

close(callback: AsyncCallback\<void\>): void

Closes a TLS socket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type                         | Mandatory| Description           |
| -------- | -----------------------------| ---- | ---------------|
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401 | Parameter error.                                 |
| 2303501 | SSL is null.                                 |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**Example**

```js
tls.close((err: string) => {
  if (err) {
    console.log("close callback error = " + err);
  } else {
    console.log("close success");
  }
});
```

### close<sup>9+</sup>

close(): Promise\<void\>

Closes a TLS socket connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type          | Description                 |
| -------------- | -------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401 | Parameter error.                                 |
| 2303501 | SSL is null.                                 |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**Example**

```js
tls.close().then(() => {
  console.log("close success");
}).catch((err: string) => {
  console.error(err);
});
```

## TLSConnectOptions<sup>9+</sup>

Defines TLS connection options.

**System capability**: SystemCapability.Communication.NetStack

| Name         | Type                                    | Mandatory| Description           |
| -------------- | ------------------------------------- | ---  |-------------- |
| address        | [NetAddress](#netaddress)             | Yes |  Gateway address.      |
| secureOptions  | [TLSSecureOptions](#tlssecureoptions9) | Yes| TLS security options.|
| ALPNProtocols  | Array\<string\>                         | No| ALPN protocol. The value range is ["spdy/1", "http/1.1"]. The default value is **[]**.     |

## TLSSecureOptions<sup>9+</sup>

Defines TLS security options. The CA certificate is mandatory, and other parameters are optional. When **cert** (local certificate) and **key** (private key) are not empty, the two-way authentication mode is enabled. If **cert** or **key** is empty, one-way authentication is enabled.

**System capability**: SystemCapability.Communication.NetStack

| Name                | Type                                                   | Mandatory| Description                               |
| --------------------- | ------------------------------------------------------ | --- |----------------------------------- |
| ca                    | string \| Array\<string\>                               | Yes| CA certificate of the server, which is used to authenticate the digital certificate of the server.|
| cert                  | string                                                  | No| Digital certificate of the local client.                |
| key                   | string                                                  | No| Private key of the local digital certificate.                  |
| password                | string                                                  | No| Password for reading the private key.                     |
| protocols             | [Protocol](#protocol9) \|Array\<[Protocol](#protocol9)\> | No| TLS protocol version. The default value is **TLSv1.2**.                 |
| useRemoteCipherPrefer | boolean                                                 | No| Whether to use the remote cipher suite preferentially.       |
| signatureAlgorithms   | string                                                 | No| Signing algorithm used during communication. The default value is **""**.             |
| cipherSuite           | string                                                 | No| Cipher suite used during communication. The default value is **""**.             |

## Protocol<sup>9+</sup>

Enumerates TLS protocol versions.

**System capability**: SystemCapability.Communication.NetStack

| Name     |    Value   | Description               |
| --------- | --------- |------------------ |
| TLSv12    | "TLSv1.2" | TLSv1.2.|
| TLSv13    | "TLSv1.3" | TLSv1.3.|

## X509CertRawData<sup>9+</sup>

Defines the certificate raw data.

**System capability**: SystemCapability.Communication.NetStack

## socket.constructTLSSocketServerInstance<sup>10+</sup>

constructTLSSocketServerInstance(): TLSSocketServer

Creates a **TLSSocketServer** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                 | Description                         |
| :------------------------------------ | :---------------------------- |
| [TLSSocketServer](#tlssocketserver10) | **TLSSocketServer** object.|

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
```

## TLSSocketServer<sup>10+</sup>

Defines a TLS socket server connection. Before calling TLSSocketServer APIs, you need to call [socket.constructTLSSocketServerInstance](#socketconstructtlssocketserverinstance10) to create a **TLSSocketServer** object.

### listen<sup>10+</sup>

listen(options: TLSConnectOptions, callback: AsyncCallback\<void\>): void

Listens to client connections after **bind** is successfully called. This API uses an asynchronous callback to return the result. After a connection is established, a TLS session will be created and initialized and a certificate key will be loaded and verified. 

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description                                            |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------ |
| options  | [TLSConnectOptions](#tlsconnectoptions9) | Yes  | Parameters required for the connection.               |
| callback | AsyncCallback\<void>                     | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable try again. |
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |
| 2303501  | SSL is null.                                |
| 2303502  | Error in tls reading.                       |
| 2303503  | Error in tls writing                        |
| 2303505  | Error occurred in the tls system call.      |
| 2303506  | Error clearing tls connection.              |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
});
```

### listen<sup>10+</sup>

listen(options: TLSConnectOptions): Promise\<void\>

Listens to client connections after **bind** is successfully called. This API uses a promise to return the result. After a connection is established, a TLS session will be created and initialized and a certificate key will be loaded and verified. 

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description              |
| ------- | ---------------------------------------- | ---- | ------------------ |
| options | [TLSConnectOptions](#tlsconnectoptions9) | Yes  | Parameters required for the connection.|

**Return value**

| Type           | Description                                                     |
| --------------- | --------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable try again. |
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |
| 2303501  | SSL is null.                                |
| 2303502  | Error in tls reading.                       |
| 2303503  | Error in tls writing                        |
| 2303505  | Error occurred in the tls system call.      |
| 2303506  | Error clearing tls connection.              |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
});
```

### getState<sup>10+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of the TLS socket server connection upon successful listening. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase7)> | Yes  | Callback used to return the result. If the operation is successful, the status of the TLS socket server connection is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});

tlsServer.getState((err: string, data: string) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
});
```

### getState<sup>10+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of the TLS socket server connection upon successful listening. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                          | Description                                                        |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase7)> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
let promise: socket = tlsServer.getState();
promise.then(() => {
  console.log('getState success');
}).catch((err: string) => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of the TLS socket server connection upon successful listening. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                | Mandatory| Description                                            |
| -------- | ------------------------------------ | ---- | ------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions7) | Yes  | Other properties of the TLS socket server connection.                 |
| callback | AsyncCallback\<void\>                | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
class Linger {
  on: boolean = true
  linger: number = 10
}
class TCPExtraOptions {
  keepAlive: boolean = true
  OOBInline: boolean = true
  TCPNoDelay: boolean = true
  socketLinger: Object = new Linger()
  receiveBufferSize: number = 1000
  sendBufferSize: number = 1000
  reuseAddress: boolean = true
  socketTimeout: number = 3000
}
tlsServer.setExtraOptions(new TCPExtraOptions(), (err: string) => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

Sets other properties of the TLS socket server connection upon successful listening. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                | Mandatory| Description                           |
| ------- | ------------------------------------ | ---- | ------------------------------- |
| options | [TCPExtraOptions](#tcpextraoptions7) | Yes  | Other properties of the TLS socket server connection.|

**Return value**

| Type           | Description                                                     |
| :-------------- | :-------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
class Linger {
  on: boolean = true
  linger: number = 10
}
class TCPExtraOptions {
  keepAlive: boolean = true
  OOBInline: boolean = true
  TCPNoDelay: boolean = true
  socketLinger: Object = new Linger()
  receiveBufferSize: number = 1000
  sendBufferSize: number = 1000
  reuseAddress: boolean = true
  socketTimeout: number = 3000
}
let promise: socket = tlsServer.setExtraOptions(new TCPExtraOptions());
promise.then(() => {
  console.log('setExtraOptions success');
}).catch((err: string) => {
  console.log('setExtraOptions fail');
});
```

### getCertificate<sup>10+</sup>

getCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

Obtains the local digital certificate after a TLS socket server connection is established. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                    |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------------- |
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\> | Yes  | Callback used to return the result. If the operation is successful, the local certificate is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 2303501  | SSL is null.           |
| 2303504  | Error looking up x509. |
| 2300002  | System internal error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.getCertificate((err: string, data: string) => {
  if (err) {
    console.log("getCertificate callback error = " + err);
  } else {
    console.log("getCertificate callback = " + data);
  }
});
```

### getCertificate<sup>10+</sup>

getCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

Obtains the local digital certificate after a TLS socket server connection is established. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                           | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 2303501  | SSL is null.           |
| 2303504  | Error looking up x509. |
| 2300002  | System internal error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.getCertificate().then((data: string) => {
  console.log(data);
}).catch((err: string) => {
  console.error(err);
});
```

### getProtocol<sup>10+</sup>

getProtocol(callback: AsyncCallback\<string\>): void

Obtains the communication protocol version after a TLS socket server connection is established. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                                                |
| -------- | ----------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303505  | Error occurred in the tls system call. |
| 2300002  | System internal error.                 |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.getProtocol((err: string, data: string) => {
  if (err) {
    console.log("getProtocol callback error = " + err);
  } else {
    console.log("getProtocol callback = " + data);
  }
});
```

### getProtocol<sup>10+</sup>

getProtocol():Promise\<string\>

Obtains the communication protocol version after a TLS socket server connection is established. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type             | Description                                                   |
| ----------------- | ------------------------------------------------------- |
| Promise\<string\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 2303501  | SSL is null.                           |
| 2303505  | Error occurred in the tls system call. |
| 2300002  | System internal error.                 |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.getProtocol().then((data: string) => {
  console.log(data);
}).catch((err: string) => {
  console.error(err);
});
```

### on('connect')<sup>10+</sup>

on(type: 'connect', callback: Callback\<TLSSocketConnection\>): void

Subscribes to TLS socket server connection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                 |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------- |
| type     | string                                                  | Yes  | Type of the event to subscribe to.<br/> **connect**: connection event.|
| callback | Callback<[TLSSocketConnection](#tlssocketconnection10)> | Yes  | Callback used to return the result.                           |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('connect', (data: string) => {
  console.log(JSON.stringify(data))
});
```

### off('connect')<sup>10+</sup>

off(type: 'connect', callback?: Callback\<TLSSocketConnection\>): void

Unsubscribes from TLS socket server connection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                 |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------- |
| type     | string                                                  | Yes  | Type of the event to subscribe to.<br/> **connect**: connection event.|
| callback | Callback<[TLSSocketConnection](#tlssocketconnection10)> | No  | Callback used to return the result.                           |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
import socket from "@ohos.net.socket";
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();

let callback = (data: socket.TLSSocketConnection) => {
  console.log('on connect message: ' + JSON.stringify(data));
}
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tlsServer.off('connect', callback);
tlsServer.off('connect');
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **TLSSocketServer** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('error', (err: string) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **TLSSocketServer** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
let callback = (err: string) => {
  console.log("on error, err:" + JSON.stringify(err));
}
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tlsServer.off('error', callback);
tlsServer.off('error');
```

## TLSSocketConnection<sup>10+</sup>

Defines a **TLSSocketConnection** object, that is, the connection between the TLSSocket client and the server. Before calling TLSSocketConnection APIs, you need to obtain a **TLSSocketConnection** object.

> **NOTE**
> The TLSSocket client can call related APIs through the **TLSSocketConnection** object only after a connection is successfully established between the TLSSocket client and the server.

**System capability**: SystemCapability.Communication.NetStack

### Attributes

| Name    | Type  | Mandatory| Description                                 |
| -------- | ------ | ---- | ------------------------------------- |
| clientId | number | Yes  | ID of the connection between the client and TLSSocketServer.|

### send<sup>10+</sup>

send(data: string, callback: AsyncCallback\<void\>): void

Sends a message to the client after a TLS socket server connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description                                            |
| -------- | --------------------- | ---- | ------------------------------------------------ |
| data     | string                | Yes  | Parameters for sending data over the TLS socket server connection.           |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303503  | Error in tls writing.                  |
| 2303505  | Error occurred in the tls system call. |
| 2303506  | Error clearing tls connection.         |
| 2300002  | System internal error.                 |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
class Data {
  data: string = 'Hello, client!'
}
tlsServer.on('connect', (client: socket) => {
  client.send(new Data(), (err: string) => {
    if (err) {
        console.log('send fail');
        return;
    }
    console.log('send success');
  });
});
```

### send<sup>10+</sup>

send(data: string): Promise\<void\>

Sends a message to the server after a TLS socket server connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name| Type  | Mandatory| Description                                 |
| ------ | ------ | ---- | ------------------------------------- |
| data   | string | Yes  | Parameters for sending data over the TLS socket server connection.|

**Return value**

| Type           | Description                                                     |
| --------------- | --------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303503  | Error in tls writing.                  |
| 2303505  | Error occurred in the tls system call. |
| 2303506  | Error clearing tls connection.         |
| 2300002  | System internal error.                 |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
class Data {
  data: string = 'Hello, client!'
}
tlsServer.on('connect', (client: socket) => {
  let promise: socket = client.send(new Data());
  promise.then(() => {
    console.log('send success');
  }).catch((err: string) => {
    console.log('send fail');
  });
});
```

### close<sup>10+</sup>

close(callback: AsyncCallback\<void\>): void

Closes a TLS socket server connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description                                            |
| -------- | --------------------- | ---- | ------------------------------------------------ |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303505  | Error occurred in the tls system call. |
| 2303506  | Error clearing tls connection.         |
| 2300002  | System internal error.                 |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.close((err: string) => {
    if (err) {
      console.log('close fail');
      return;
    }
    console.log('close success');
  });
});
```

### close<sup>10+</sup>

close(): Promise\<void\>

Closes a TLS socket server connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                     |
| --------------- | --------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 2303501  | SSL is null.                           |
| 2303505  | Error occurred in the tls system call. |
| 2303506  | Error clearing tls connection.         |
| 2300002  | System internal error.                 |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  let promise: socket = client.close();
  promise.then(() => {
    console.log('close success');
  }).catch((err: string) => {
    console.log('close fail');
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

Obtains the remote address of a TLS socket server connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[NetAddress](#netaddress7)\> | Yes  | Callback used to return the result. If the operation is successful, the remote address is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.getRemoteAddress((err: string, data: string) => {
    if (err) {
      console.log('getRemoteAddress fail');
      return;
    }
    console.log('getRemoteAddress success:' + JSON.stringify(data));
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(): Promise\<NetAddress\>

Obtains the remote address of a TLS socket server connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                | Description                                                        |
| :----------------------------------- | :----------------------------------------------------------- |
| Promise\<[NetAddress](#netaddress7)> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.getRemoteAddress().then((data: string) => {
    console.log('getRemoteAddress success:' + JSON.stringify(data));
  }).catch((err: string) => {
    console.error(err);
  });
});
```

### getRemoteCertificate<sup>10+</sup>

getRemoteCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

Obtains the digital certificate of the peer end after a TLS socket server connection is established. This API uses an asynchronous callback to return the result. It applies only to the scenario where the client sends a certificate to the server. 

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 2303501  | SSL is null.           |
| 2300002  | System internal error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.getRemoteCertificate((err: string, data: string) => {
    if (err) {
      console.log("getRemoteCertificate callback error = " + err);
    } else {
      console.log("getRemoteCertificate callback = " + data);
    }
  });
});
```

### getRemoteCertificate<sup>10+</sup>

getRemoteCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

Obtains the digital certificate of the peer end after a TLS socket server connection is established. This API uses a promise to return the result. It applies only to the scenario where the client sends a certificate to the server. 

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                           | Description                                                        |
| ----------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 2303501  | SSL is null.           |
| 2300002  | System internal error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.getRemoteCertificate().then((data: string) => {
    console.log('getRemoteCertificate success:' + JSON.stringify(data));
  }).catch((err: string) => {
    console.error(err);
  });
});
```

### getCipherSuite<sup>10+</sup>

getCipherSuite(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the cipher suite negotiated by both communication parties after a TLS socket server connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<Array\<string\>\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303502  | Error in tls reading.                  |
| 2303505  | Error occurred in the tls system call. |
| 2300002  | System internal error.                 |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.getCipherSuite((err: string, data: string) => {
    if (err) {
      console.log("getCipherSuite callback error = " + err);
    } else {
      console.log("getCipherSuite callback = " + data);
    }
  });
});
```

### getCipherSuite<sup>10+</sup>

getCipherSuite(): Promise\<Array\<string\>\>

Obtains the cipher suite negotiated by both communication parties after a TLS socket server connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                      | Description                                                        |
| -------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<string\>\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 2303501  | SSL is null.                           |
| 2303502  | Error in tls reading.                  |
| 2303505  | Error occurred in the tls system call. |
| 2300002  | System internal error.                 |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.getCipherSuite().then((data: string) => {
    console.log('getCipherSuite success:' + JSON.stringify(data));
  }).catch((err: string) => {
    console.error(err);
  });
});
```

### getSignatureAlgorithms<sup>10+</sup>

getSignatureAlgorithms(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the signing algorithm negotiated by both communication parties after a TLS socket server connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                            | Mandatory| Description                              |
| -------- | -------------------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<Array\<string\>\> | Yes  | Callback used to return the result. |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 2303501  | SSL is null.           |
| 2300002  | System internal error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.getSignatureAlgorithms((err: string, data: string) => {
    if (err) {
      console.log("getSignatureAlgorithms callback error = " + err);
    } else {
      console.log("getSignatureAlgorithms callback = " + data);
    }
  });
});
```

### getSignatureAlgorithms<sup>10+</sup>

getSignatureAlgorithms(): Promise\<Array\<string\>\>

Obtains the signing algorithm negotiated by both communication parties after a TLS socket server connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                      | Description                                         |
| -------------------------- | --------------------------------------------- |
| Promise\<Array\<string\>\> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 2303501  | SSL is null.           |
| 2300002  | System internal error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.getSignatureAlgorithms().then((data: string) => {
    console.log("getSignatureAlgorithms success" + data);
  }).catch((err: string) => {
    console.error(err);
  });
});
```

### on('message')<sup>10+</sup>

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Subscribes to **message** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo7)}> | Yes  | Callback used to return the result.                               |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
tlsServer.on('connect', (client: socket) => {
  client.on('message', (value: SocketInfo) => {
    let messageView = '';
    for (let i : number = 0; i < value.message.byteLength; i++) {
      let messages : number = value.message.i
      let message = String.fromCharCode(messages);
      messageView += message;
    }
    console.log('on message message: ' + JSON.stringify(messageView));
    console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
  });
});
```

### off('message')<sup>10+</sup>

off(type: 'message', callback?: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

Unsubscribes from **message** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Type of the event to subscribe to.<br/> **message**: message receiving event.|
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo7)}> | No  | Callback used to return the result.                               |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
class SocketInfo {
  message: ArrayBuffer = [];
  remoteInfo: socket.SocketRemoteInfo = "";
}
let callback = (value: SocketInfo) => {
  let messageView = '';
    for (let i : number = 0; i < value.message.byteLength; i++) {
      let messages : number = value.message.i
      let message = String.fromCharCode(messages);
      messageView += message;
    }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.on('message', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  client.off('message', callback);
  client.off('message');
});
```

### on('close')<sup>10+</sup>

on(type: 'close', callback: Callback\<void\>): void

Subscribes to **close** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                               |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | Yes  | Type of the event to subscribe to.<br/> **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.                         |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.on('close', () => {
    console.log("on close success")
  });
});
```

### off('close')<sup>10+</sup>

off(type: 'close', callback?: Callback\<void\>): void

Unsubscribes from **close** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                               |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | Yes  | Type of the event to subscribe to.<br/> **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result.                         |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let callback = () => {
  console.log("on close success");
}
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.on('close', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  client.off('close', callback);
  client.off('close');
});
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options(), (err: string) => {
  console.log("listen callback error" + err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.on('error', (err: string) => {
    console.log("on error, err:" + JSON.stringify(err))
  });
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```js
let callback = (err: string) => {
  console.log("on error, err:" + JSON.stringify(err));
}
let tlsServer: socket = socket.constructTLSSocketServerInstance();
class NetAddress {
  address: string = '192.168.xx.xxx'
  port: number = 8080
  family: number = 1
}
class SecureOptions {
  key: string = "xxxx"
  cert: string = "xxxx"
  ca: string[] = ["xxxx"]
  password: string = "xxxx"
  protocols: enum = socket.Protocol.TLSv12
  useRemoteCipherPrefer: boolean = true
  signatureAlgorithms: string = "rsa_pss_rsae_sha256:ECDSA+SHA256"
  cipherSuite: string = "AES256-SHA256"
}
class Options {
  ALPNProtocols: string[] = ["spdy/1", "http/1.1"]
  address: Object = new NetAddress()
  secureOptions: Object = new SecureOptions()
}
tlsServer.listen(new Options()).then(() => {
  console.log("listen callback success");
}).catch((err: string) => {
  console.log(err);
  return;
});
tlsServer.on('connect', (client: socket) => {
  client.on('error', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  client.off('error', callback);
  client.off('error');
});
```
