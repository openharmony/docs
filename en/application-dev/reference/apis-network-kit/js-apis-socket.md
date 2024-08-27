# @ohos.net.socket (Socket Connection)

The **socket** module implements data transfer over **TCPSocket**, **UDPSocket**, **WebSocket**, and **TLSSocket** connections.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { socket } from '@kit.NetworkKit';
```

## socket.constructUDPSocketInstance

constructUDPSocketInstance(): UDPSocket

Creates a **UDPSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                   |
|  --------------------------------- |  ---------------------- |
| [UDPSocket](#udpsocket) | **UDPSocket** connection.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
```

## UDPSocket

Defines a **UDPSocket** connection. Before calling **UDPSocket** APIs, you need to call [socket.constructUDPSocketInstance](#socketconstructudpsocketinstance) to create a **UDPSocket** connection.

### bind

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                              | Mandatory| Description                                                  |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | Yes  | Destination address. For details, see [NetAddress](#netaddress).|
| callback | AsyncCallback\<void\>              | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.       |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 1234
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
```

### bind

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
|  -------------- |  ----------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr).then(() => {
  console.log('bind success');
}).catch((err: BusinessError) => {
  console.log('bind fail');
});
```

### send

send(options: UDPSendOptions, callback: AsyncCallback\<void\>): void

Sends data from a **UDPSocket** connection. This API uses an asynchronous callback to return the result.

Before sending data, call [UDPSocket.bind()](#bind) to bind the IP address and port.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                        |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPSendOptions](#udpsendoptions) | Yes  | Parameters for sending data over a **UDPSocket** connection. For details, see [UDPSendOptions](#udpsendoptions).|
| callback | AsyncCallback\<void\>                    | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.                                                 |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let sendOptions: socket.UDPSendOptions = {
  data: 'Hello, server!',
  address: netAddress
}
udp.send(sendOptions, (err: BusinessError) => {
  if (err) {
    console.log('send fail');
    return;
  }
  console.log('send success');
});
```

### send

send(options: UDPSendOptions): Promise\<void\>

Sends data from a **UDPSocket** connection. This API uses a promise to return the result.

Before sending data, call [UDPSocket.bind()](#bind) to bind the IP address and port.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description                                                        |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [UDPSendOptions](#udpsendoptions) | Yes  | Parameters for sending data over a **UDPSocket** connection. For details, see [UDPSendOptions](#udpsendoptions).|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Return value**

| Type           | Description                                          |
|  -------------- |  --------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let sendOptions: socket.UDPSendOptions = {
  data: 'Hello, server!',
  address: netAddress
}
udp.send(sendOptions).then(() => {
  console.log('send success');
}).catch((err: BusinessError) => {
  console.log('send fail');
});
```

### close

close(callback: AsyncCallback\<void\>): void

Closes a **UDPSocket** connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.close((err: BusinessError) => {
  if (err) {
    console.log('close fail');
    return;
  }
  console.log('close success');
})
```

### close

close(): Promise\<void\>

Closes a **UDPSocket** connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Return value**

| Type           | Description                                      |
|  -------------- |  ----------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.close().then(() => {
  console.log('close success');
}).catch((err: BusinessError) => {
  console.log('close fail');
});
```

### getState

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of the **UDPSocket** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase)\> | Yes  | Callback used to return the result. If the operation is successful, the status of the **UDPSocket** object is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  udp.getState((err: BusinessError, data: socket.SocketStateBase) => {
    if (err) {
      console.log('getState fail');
      return;
    }
    console.log('getState success:' + JSON.stringify(data));
  })
})
```

### getState

getState(): Promise\<SocketStateBase\>

Obtains the status of the **UDPSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Return value**

| Type                                            | Description                                      |
|  ----------------------------------------------- |  ----------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  udp.getState().then((data: socket.SocketStateBase) => {
    console.log('getState success:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.log('getState fail' + JSON.stringify(err));
  });
});
```

### setExtraOptions

setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of the **UDPSocket** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                        |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPExtraOptions](#udpextraoptions) | Yes  | Other properties of the **UDPSocket** connection. For details, see [UDPExtraOptions](#udpextraoptions).|
| callback | AsyncCallback\<void\>                    | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.                   |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  let udpextraoptions: socket.UDPExtraOptions = {
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: false,
    socketTimeout: 6000,
    broadcast: true
  }
  udp.setExtraOptions(udpextraoptions, (err: BusinessError) => {
    if (err) {
      console.log('setExtraOptions fail');
      return;
    }
    console.log('setExtraOptions success');
  })
})
```

### setExtraOptions

setExtraOptions(options: UDPExtraOptions): Promise\<void\>

Sets other properties of the **UDPSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description                                                        |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [UDPExtraOptions](#udpextraoptions) | Yes  | Other properties of the **UDPSocket** connection. For details, see [UDPExtraOptions](#udpextraoptions).|

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  let udpextraoptions: socket.UDPExtraOptions = {
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: false,
    socketTimeout: 6000,
    broadcast: true
  }
  udp.setExtraOptions(udpextraoptions).then(() => {
    console.log('setExtraOptions success');
  }).catch((err: BusinessError) => {
    console.log('setExtraOptions fail');
  });
})
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<NetAddress\>

Obtains the local socket address of a **UDPSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr).then(() => {
  console.info('bind success');
  udp.getLocalAddress().then((localAddress: socket.NetAddress) => {
        console.info("UDP_Socket get SUCCESS! Address: " + JSON.stringify(localAddress));
      }).catch((err: BusinessError) => {
        console.error("UDP_Socket get FAILED! Error: " + JSON.stringify(err));
      })
}).catch((err: BusinessError) => {
  console.error('bind fail');
});
```

### on('message')

on(type: 'message', callback: Callback\<SocketMessageInfo\>): void

Subscribes to **message** events of a **UDPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | Yes  | Callback used to return the result.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

let messageView = '';
udp.on('message', (value: socket.SocketMessageInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let uint8Array = new Uint8Array(value.message) 
    let messages = uint8Array[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')

off(type: 'message', callback?: Callback\<SocketMessageInfo\>): void

Unsubscribes from **message** events of a **UDPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | No  | Callback used to return the result.                               |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let messageView = '';
let callback = (value: socket.SocketMessageInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let uint8Array = new Uint8Array(value.message) 
    let messages = uint8Array[i]
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

### on('listening' | 'close')

on(type: 'listening' | 'close', callback: Callback\<void\>): void

Subscribes to **listening** events or **close** events of a **UDPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Event type.<br>- **listening**: data packet message event.<br>- **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.            |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.on('listening', () => {
  console.log("on listening success");
});
udp.on('close', () => {
  console.log("on close success");
});
```

### off('listening' | 'close')

off(type: 'listening' | 'close', callback?: Callback\<void\>): void

Unsubscribes from **listening** events or **close** events of a **UDPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Event type.<br>- **listening**: data packet message event.<br>- **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **UDPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                       |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **UDPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.       |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
udp.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
udp.off('error', callback);
udp.off('error');
```

## NetAddress

Defines the destination address.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address<sup>11+</sup> | string | Yes  | Bound IP address.                                          |
| port    | number | No  | Port number. The value ranges from **0** to **65535**. If this parameter is not specified, the system randomly allocates a port.          |
| family  | number | No  | Network protocol type.<br>- **1**: IPv4<br>- **2**: IPv6<br>The default value is **1**. For an IPv6 address, this field must be explicitly set to **2**.|
## UDPSendOptions

Defines the parameters for sending data over a **UDPSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type                              | Mandatory| Description          |
| ------- | ---------------------------------- | ---- | -------------- |
| data    | string \| ArrayBuffer                          | Yes  | Data to send.  |
| address | [NetAddress](#netaddress) | Yes  | Destination address.|

## UDPExtraOptions

Defines other properties of the **UDPSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name           | Type   | Mandatory| Description                            |
| ----------------- | ------- | ---- | -------------------------------- |
| broadcast         | boolean | No  | Whether to send broadcast messages. The default value is **false**. |
| receiveBufferSize | number  | No  | Size of the receive buffer, in bytes. The default value is **0**.  |
| sendBufferSize    | number  | No  | Size of the send buffer, in bytes. The default value is **0**.  |
| reuseAddress      | boolean | No  | Whether to reuse addresses. The default value is **false**.     |
| socketTimeout     | number  | No  | Timeout duration of the **UDPSocket** connection, in ms. The default value is **0**.|

## SocketMessageInfo<sup>11+</sup>

Defines the message of a **Socket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name       | Type  | Mandatory| Description                                 |
| ---------- | ------ | ---- | ------------------------------------- |
| message    | ArrayBuffer | Yes  | Received message.|
| remoteInfo | [SocketRemoteInfo](#socketremoteinfo) | Yes  | **Socket** connection information.|

## SocketStateBase

Defines the status of a **Socket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name     | Type   | Mandatory| Description      |
| ----------- | ------- | ---- | ---------- |
| isBound     | boolean | Yes  | Whether the connection is in the bound state.|
| isClose     | boolean | Yes  | Whether the connection is in the closed state.|
| isConnected | boolean | Yes  | Whether the connection is in the connected state.|

## SocketRemoteInfo

Defines the remote end of a **Socket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | Yes  | Bound IP address.                                          |
| family  | 'IPv4' \| 'IPv6' | Yes  | Network protocol type.<br>- IPv4<br>- IPv6<br>The default value is **IPv4**.|
| port    | number | Yes  | Port number. The value ranges from **0** to **65535**.                                       |
| size    | number | Yes  | Length of the server response message, in bytes.                                  |

## Description of UDP Error Codes

The UDP error code mapping is in the format of 2301000 + Linux kernel error code.

For details about error codes, see [Socket Error Codes](errorcode-net-socket.md).

## socket.constructMulticastSocketInstance<sup>11+</sup>

constructMulticastSocketInstance(): MulticastSocket

Creates a **MulticastSocket** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                   |
| ----------------------------------- | ----------------------------- |
| [MulticastSocket](#multicastsocket11) | **MulticastSocket** object.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
```
## MulticastSocket<sup>11+</sup>

Defines a **MulticastSocket** connection. Before calling **MulticastSocket** APIs, you need to call [socket.constructMulticastSocketInstance](#socketconstructmulticastsocketinstance11) to create a **MulticastSocket** object.

### addMembership<sup>11+</sup>

addMembership(multicastAddress: NetAddress, callback: AsyncCallback\<void\>): void;

Adds a member to a multicast group. This API uses an asynchronous callback to return the result.

> **NOTE**
> The IP addresses used for multicast belong to a specific range, for example, 224.0.0.0 to 239.255.255.255.
> A member in a multicast group can serve as a sender or a receiver. Data is transmitted in broadcast mode, regardless of the client or server.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name            | Type                          | Mandatory| Description                                      |
| ----------------- | ----------------------------- | ---- | ----------------------------------------- |
| multicastAddress  | [NetAddress](#netaddress)     |  Yes | Destination address. For details, see [NetAddress](#netaddress).|
| callback          | AsyncCallback\<void\>         |  Yes | Callback used to return the result. If the operation fails, an error message is returned.                                |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301022 | Invalid argument.       |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
multicast.addMembership(addr, (err: Object) => {
  if (err) {
    console.log('add membership fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('add membership success');
})
```

### addMembership<sup>11+</sup>

addMembership(multicastAddress: NetAddress): Promise\<void\>;

Adds a member to a multicast group. This API uses a promise to return the result.

> **NOTE**
> The IP addresses used for multicast belong to a specific range, for example, 224.0.0.0 to 239.255.255.255.
> A member in a multicast group can serve as a sender or a receiver. Data is transmitted in broadcast mode, regardless of the client or server.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name            | Type                          | Mandatory| Description                                          |
| ----------------- | ----------------------------- | ---- | --------------------------------------------  |
| multicastAddress  | [NetAddress](#netaddress)     |  Yes | Destination address. For details, see [NetAddress](#netaddress).|

**Return value**

| Type           | Description                                              |
|  -------------- |  -----------------------------------------------  |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
multicast.addMembership(addr).then(() => {
  console.log('addMembership success');
}).catch((err: Object) => {
  console.log('addMembership fail');
});
```

### dropMembership<sup>11+</sup>

dropMembership(multicastAddress: NetAddress, callback: AsyncCallback\<void\>): void;

Drops a member from a multicast group. This API uses an asynchronous callback to return the result.

> **NOTE**
> The IP addresses used for multicast belong to a specific range, for example, 224.0.0.0 to 239.255.255.255.
> You can drop only a member that has been added to a multicast group by using [addMembership](#addmembership11).

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name            | Type                          | Mandatory| Description                                        |
| ----------------- | ----------------------------- | ---- | ------------------------------------------- |
| multicastAddress  | [NetAddress](#netaddress)     |  Yes | Destination address. For details, see [NetAddress](#netaddress).  |
| callback          | AsyncCallback\<void\>         |  Yes | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
multicast.dropMembership(addr, (err: Object) => {
  if (err) {
    console.log('drop membership fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('drop membership success');
})
```

### dropMembership<sup>11+</sup>

dropMembership(multicastAddress: NetAddress): Promise\<void\>;

Drops a member from a multicast group. This API uses a promise to return the result.

> **NOTE**
> The IP addresses used for multicast belong to a specific range, for example, 224.0.0.0 to 239.255.255.255.
> You can drop only a member that has been added to a multicast group by using [addMembership](#addmembership11).

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name            | Type                                  | Mandatory| Description                                          |
| ----------------- | ------------------------------------- | ---- | --------------------------------------------  |
| multicastAddress  | [NetAddress](#netaddress) |  Yes | Destination address. For details, see [NetAddress](#netaddress).    |

**Return value**

| Type           | Description                                             |
|  -------------- |  ----------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
multicast.dropMembership(addr).then(() => {
  console.log('drop membership success');
}).catch((err: Object) => {
  console.log('drop membership fail');
});
```

### setMulticastTTL<sup>11+</sup>

setMulticastTTL(ttl: number, callback: AsyncCallback\<void\>): void;

Sets the time to live (TTL) for multicast packets. This API uses an asynchronous callback to return the result.

> **NOTE**
> TTL is used to limit the maximum number of router hops for packet transmission on a network.
> The value ranges from 0 to 255. The default value is **1**.
> If the TTL value is **1**, multicast packets can be transmitted only to the host directly connected to the sender. If the TTL is set to a large value, multicast packets can be transmitted over a longer distance.
> This API is effective only after [addMembership](#addmembership11) is called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name        | Type                  | Mandatory| Description                        |
| ------------- | --------------------- | ---- | ----------------------------- |
| ttl           | number                |  Yes | TTL value. The value is of the number type.|
| callback      | AsyncCallback\<void\> |  Yes | Callback used to return the result. If the operation fails, an error message is returned.   |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301022 | Invalid argument.       |
| 2301088 | Not a socket.           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let ttl = 8
multicast.setMulticastTTL(ttl, (err: Object) => {
  if (err) {
    console.log('set ttl fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('set ttl success');
})
```

### setMulticastTTL<sup>11+</sup>

setMulticastTTL(ttl: number): Promise\<void\>;

Sets the TTL for multicast packets. This API uses a promise to return the result.

> **NOTE**
> TTL is used to limit the maximum number of router hops for packet transmission on a network.
> The value ranges from 0 to 255. The default value is **1**.
> If the TTL value is **1**, multicast packets can be transmitted only to the host directly connected to the sender. If the TTL is set to a large value, multicast packets can be transmitted over a longer distance.
> This API is effective only after [addMembership](#addmembership11) is called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name        | Type                  | Mandatory| Description                          |
| ------------- | ---------------------- | ---- | ------------------------------ |
| ttl           | number                 |  Yes | TTL value. The value is of the number type.|

**Return value**

| Type           | Description                                            |
|  -------------- |  ---------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301022 | Invalid argument.       |
| 2301088 | Not a socket.           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.setMulticastTTL(8).then(() => {
  console.log('set ttl success');
}).catch((err: Object) => {
  console.log('set ttl failed');
});
```

### getMulticastTTL<sup>11+</sup>

getMulticastTTL(callback: AsyncCallback\<number\>): void;

Obtains the TTL for multicast packets. This API uses an asynchronous callback to return the result.

> **NOTE**
> TTL is used to limit the maximum number of router hops for packet transmission on a network.
> The value ranges from 0 to 255. The default value is **1**.
> If the TTL value is **1**, multicast packets can be transmitted only to the host directly connected to the sender. If the TTL is set to a large value, multicast packets can be transmitted over a longer distance.
> This API is effective only after [addMembership](#addmembership11) is called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name        | Type                    | Mandatory| Description                        |
| ------------- | ----------------------- | ---- | --------------------------- |
| callback      | AsyncCallback\<number\> |  Yes | Callback used to return the result. If the operation fails, an error message is returned. |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301088 | Not a socket.           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.getMulticastTTL((err: Object, value: Number) => {
  if (err) {
    console.log('set ttl fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('set ttl success, value: ' + JSON.stringify(value));
})
```

### getMulticastTTL<sup>11+</sup>

getMulticastTTL(): Promise\<number\>;

Obtains the TTL for multicast packets. This API uses a promise to return the result.

> **NOTE**
> TTL is used to limit the maximum number of router hops for packet transmission on a network.
> The value ranges from 0 to 255. The default value is **1**.
> If the TTL value is **1**, multicast packets can be transmitted only to the host directly connected to the sender. If the TTL is set to a large value, multicast packets can be transmitted over a longer distance.
> This API is effective only after [addMembership](#addmembership11) is called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type              | Description                       |
| ----------------   | --------------------------- |
| Promise\<number\> | Promise used to return the result.|

**Error codes**

| ID| Error Message               |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301088 | Not a socket.           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.getMulticastTTL().then((value: Number) => {
  console.log('ttl: ', JSON.stringify(value));
}).catch((err: Object) => {
  console.log('set ttl failed');
});
```

### setLoopbackMode<sup>11+</sup>

setLoopbackMode(flag: boolean, callback: AsyncCallback\<void\>): void;

Sets the loopback mode flag for multicast communication. This API uses an asynchronous callback to return the result.

> **NOTE**
> Use this API to enable or disable the loopback mode. By default, the loopback mode is enabled.
> The value **true** indicates that the host is allowed to receive the multicast packets sent by itself, and the value **false** indicates the opposite.
> This API is effective only after [addMembership](#addmembership11) is called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name        | Type                 | Mandatory| Description                        |
| ------------- | --------------------- | ---- | ---------------------------- |
| flag          | boolean               |  Yes | Loopback mode flag. The value is of the Boolean type. |
| callback      | AsyncCallback\<void\> |  Yes | Callback used to return the result. If the operation fails, an error message is returned.   |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301088 | Not a socket.           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.setLoopbackMode(false, (err: Object) => {
  if (err) {
    console.log('set loopback mode fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('set loopback mode success');
})
```

### setLoopbackMode<sup>11+</sup>

setLoopbackMode(flag: boolean): Promise\<void\>;

Sets the loopback mode flag for multicast communication. This API uses an asynchronous callback to return the result.

> **NOTE**
> Use this API to enable or disable the loopback mode. By default, the loopback mode is enabled.
> The value **true** indicates that the host is allowed to receive the multicast packets sent by itself, and the value **false** indicates the opposite.
> This API is effective only after [addMembership](#addmembership11) is called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name        | Type                  | Mandatory| Description                            |
| ------------- | ---------------------- | ---- | -------------------------------- |
| flag          | boolean                |  Yes | Loopback mode flag. The value is of the Boolean type.|

**Return value**

| Type           | Description                                            |
|  -------------- |  ---------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message               |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301088 | Not a socket.           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.setLoopbackMode(false).then(() => {
  console.log('set loopback mode success');
}).catch((err: Object) => {
  console.log('set loopback mode failed');
});
```

### getLoopbackMode<sup>11+</sup>

getLoopbackMode(callback: AsyncCallback\<boolean\>): void;

Obtains the loopback mode flag for multicast communication. This API uses a promise to return the result.

> **NOTE**
> Use this API to check whether the loopback mode is enabled.
> The value **true** indicates that the loopback mode is enabled, and the value **false** indicates the opposite. When the loopback mode is disabled, the host is does not receive the multicast packets sent by itself.
> This API is effective only after [addMembership](#addmembership11) is called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name        | Type                    | Mandatory| Description                        |
| ------------- | ----------------------- | ---- | --------------------------- |
| callback      | AsyncCallback\<number\> |  Yes | Callback used to return the result. If the operation fails, an error message is returned. |

**Error codes**

| ID| Error Message               |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301088 | Not a socket.           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.getLoopbackMode((err: Object, value: Boolean) => {
  if (err) {
    console.log('get loopback mode fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('get loopback mode success, value: ' + JSON.stringify(value));
})
```

### getLoopbackMode<sup>11+</sup>

getLoopbackMode(): Promise\<boolean\>;

Obtains the loopback mode flag for multicast communication. This API uses a promise to return the result.

> **NOTE**
> Use this API to check whether the loopback mode is enabled.
> The value **true** indicates that the loopback mode is enabled, and the value **false** indicates the opposite. When the loopback mode is disabled, the host is does not receive the multicast packets sent by itself.
> This API is effective only after [addMembership](#addmembership11) is called.

**System capability**: SystemCapability.Communication.NetStack
                                                      
**Return value**

| Type               | Description                       |
| ----------------  | --------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

| ID| Error Message               |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301088 | Not a socket.           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.getLoopbackMode().then((value: Boolean) => {
  console.log('loopback mode: ', JSON.stringify(value));
}).catch((err: Object) => {
  console.log('get loopback mode failed');
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<NetAddress\>

Obtains the local socket address for multicast communication. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.0',
  port: 8080
}
multicast.bind(addr).then(() => {
  console.info('bind success');
  multicast.getLocalAddress().then((localAddress: socket.NetAddress) => {
    console.info("Multicast_Socket get SUCCESS! Address:" + JSON.stringify(localAddress));
  }).catch((err: BusinessError) => {
    console.error("Multicast_Socket get FAILED! Error:" + JSON.stringify(err));
  })
}).catch((err: BusinessError) => {
  console.error('bind fail');
});
```

### send<sup>7+</sup>

send(options: UDPSendOptions, callback: AsyncCallback\<void\>): void

Sends data in multicast communication. This API uses an asynchronous callback to return the result.

Before sending data, call [addMembership](#addmembership11) to add a member to the multicast group.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPSendOptions](#udpsendoptions) | Yes  | Parameters for sending data over a **UDPSocket** connection. For details, see [UDPSendOptions](#udpsendoptions).|
| callback | AsyncCallback\<void\>             | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let netAddress: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
let sendOptions: socket.UDPSendOptions = {
  data: 'Hello, server!',
  address: netAddress
}
multicast.send(sendOptions, (err: Object) => {
  if (err) {
    console.log('send fail: ' + JSON.stringify(err));
    return;
  }
  console.log('send success');
});
```

### send<sup>7+</sup>

send(options: UDPSendOptions): Promise\<void\>

Sends data in multicast communication. This API uses a promise to return the result.

Before sending data, call [addMembership](#addmembership11) to add a member to the multicast group.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description                                                        |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [UDPSendOptions](#udpsendoptions) | Yes  | Parameters for sending data over a **UDPSocket** connection. For details, see [UDPSendOptions](#udpsendoptions).|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Return value**

| Type           | Description                             |
| :-------------- | :------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let netAddress: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
let sendOptions: socket.UDPSendOptions = {
  data: 'Hello, server!',
  address: netAddress
}
multicast.send(sendOptions).then(() => {
  console.log('send success');
}).catch((err: Object) => {
  console.log('send fail, ' + JSON.stringify(err));
});
```

### on('message')<sup>7+</sup>

on(type: 'message', callback: Callback\<SocketMessageInfo\>): void

Subscribes to **message** events of a **MulticastSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                                                   | Mandatory| Description                                |
| -------- | ------------------------------------------------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                                                                | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | Yes  | Callback used to return the result.                           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance()

multicast.on('message', (data: socket.SocketMessageInfo) => {
  console.info ('Received data:' + JSON.stringify (data))
  const uintArray = new Uint8Array(data.message)
  let str = ''
  for (let i = 0; i < uintArray.length; ++i) {
    str += String.fromCharCode(uintArray[i])
  }
  console.info(str)
})
```

### off('message')<sup>7+</sup>

off(type: 'message', callback?: Callback\<SocketMessageInfo\>): void

Unsubscribes to **message** events of a **MulticastSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                                                 | Mandatory| Description                                |
| -------- | ----------------------------------------------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                                                              | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | No  | Callback used to return the result.  |
**Example**

```ts
import { socket } from '@kit.NetworkKit';

let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance()
multicast.on('message', (data: socket.SocketMessageInfo) => {
  console.info ('Received data:' + JSON.stringify (data))
  const uintArray = new Uint8Array(data.message)
  let str = ''
  for (let i = 0; i < uintArray.length; ++i) {
    str += String.fromCharCode(uintArray[i])
  }
  console.info(str)
})
multicast.off('message')
```


## socket.constructTCPSocketInstance<sup>7+</sup>

constructTCPSocketInstance(): TCPSocket

Creates a **TCPSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                   |
| --------------------------------- | ---------------------- |
| [TCPSocket](#tcpsocket) | **TCPSocket** connection.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
```

## TCPSocket

Defines a **TCPSocket** connection. Before calling **TCPSocket** APIs, you need to call [socket.constructTCPSocketInstance](#socketconstructtcpsocketinstance7) to create a **TCPSocket** connection.

### bind

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

Binds an IP address and a port number. The port number can be specified or randomly allocated by the system. This API uses an asynchronous callback to return the result.

> **NOTE**
> If the bind operation fails due to a port conflict, the system will randomly allocate a port number.
> The TCP client can call **tcp.bind** to explicitly bind the IP address and port number, and then call **tcp.connect** to connect to the server. Alternatively, the TCP client can directly call **tcp.connect** to automatically bind the IP address and port number to connect to the server.
> If the IP address is **localhost** or **127.0.0.1**, only local loopback access is allowed; that is, the TCP client and the server are deployed on the same device.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                              | Mandatory| Description                                                  |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | Yes  | Destination address. For details, see [NetAddress](#netaddress).|
| callback | AsyncCallback\<void\>              | Yes  | Callback used to return the result. If the operation fails, an error message is returned.                  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tcp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
})
```

### bind

bind(address: NetAddress): Promise\<void\>

Binds an IP address and a port number. The port number can be specified or randomly allocated by the system. This API uses a promise to return the result.

> **NOTE**
> If the bind operation fails due to a port conflict, the system will randomly allocate a port number.
> The TCP client can call **tcp.bind** to explicitly bind the IP address and port number, and then call **tcp.connect** to connect to the server. Alternatively, the TCP client can directly call **tcp.connect** to automatically bind the IP address and port number to connect to the server.
> If the IP address is **localhost** or **127.0.0.1**, only local loopback access is allowed; that is, the TCP client and the server are deployed on the same device.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                              | Mandatory| Description                                                  |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress) | Yes  | Destination address. For details, see [NetAddress](#netaddress).|

**Return value**

| Type           | Description                                                    |
| --------------- | ------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tcp.bind(bindAddr).then(() => {
  console.log('bind success');
}).catch((err: BusinessError) => {
  console.log('bind fail');
});
```

### connect

connect(options: TCPConnectOptions, callback: AsyncCallback\<void\>): void

Sets up a connection to the specified IP address and port number. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API allows you to connect to the TCP server without first executing **tcp.bind**.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                        |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPConnectOptions](#tcpconnectoptions) | Yes  | parameters of a **TCPSocket** connection. For details, see [TCPConnectOptions](#tcpconnectoptions).|
| callback | AsyncCallback\<void\>                    | Yes  | Callback used to return the result. If the operation fails, an error message is returned.                     |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions, (err: BusinessError) => {
  if (err) {
    console.log('connect fail');
    return;
  }
  console.log('connect success');
})
```

### connect

connect(options: TCPConnectOptions): Promise\<void\>

Sets up a connection to the specified IP address and port number. This API uses a promise to return the result.

> **NOTE**
> This API allows you to connect to the TCP server without first executing **tcp.bind**.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description                                                        |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPConnectOptions](#tcpconnectoptions) | Yes  | parameters of a **TCPSocket** connection. For details, see [TCPConnectOptions](#tcpconnectoptions).|

**Return value**

| Type           | Description                                                      |
| -------------- | --------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success')
}).catch((err: BusinessError) => {
  console.log('connect fail');
});
```

### send

send(options: TCPSendOptions, callback: AsyncCallback\<void\>): void

Sends data from a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPSendOptions](#tcpsendoptions) | Yes  | Parameters for sending data over a **TCPSocket** connection. For details, see [TCPSendOptions](#tcpsendoptions).|
| callback | AsyncCallback\<void\>                   | Yes  | Callback used to return the result. If the operation fails, an error message is returned.                          |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpSendOptions: socket.TCPSendOptions = {
    data: 'Hello, server!'
  }
  tcp.send(tcpSendOptions, (err: BusinessError) => {
    if (err) {
      console.log('send fail');
      return;
    }
    console.log('send success');
  })
})
```

### send

send(options: TCPSendOptions): Promise\<void\>

Sends data from a **TCPSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                   | Mandatory| Description                                                        |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPSendOptions](#tcpsendoptions) | Yes  | Parameters for sending data over a **TCPSocket** connection. For details, see [TCPSendOptions](#tcpsendoptions).|

**Return value**

| Type           | Description                                              |
| -------------- | ------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpSendOptions: socket.TCPSendOptions = {
    data: 'Hello, server!'
  }
  tcp.send(tcpSendOptions).then(() => {
    console.log('send success');
  }).catch((err: BusinessError) => {
    console.log('send fail');
  });
})
```

### close

close(callback: AsyncCallback\<void\>): void

Closes a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

tcp.close((err: BusinessError) => {
  if (err) {
    console.log('close fail');
    return;
  }
  console.log('close success');
})
```

### close

close(): Promise\<void\>

Closes a **TCPSocket** connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                      |
| -------------- | ----------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

tcp.close().then(() => {
  console.log('close success');
}).catch((err: BusinessError) => {
  console.log('close fail');
});
```

### getRemoteAddress

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

Obtains the remote address of a **Socket** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                             | Mandatory| Description      |
| -------- | ------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetAddress](#netaddress)\> | Yes  | Callback used to return the result. If the operation is successful, the remote address is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  tcp.getRemoteAddress((err: BusinessError, data: socket.NetAddress) => {
    if (err) {
      console.log('getRemoteAddressfail');
      return;
    }
    console.log('getRemoteAddresssuccess:' + JSON.stringify(data));
  })
});
```

### getRemoteAddress

getRemoteAddress(): Promise\<NetAddress\>

Obtains the remote address of a **Socket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                       | Description                                       |
| ------------------------------------------ | ------------------------------------------ |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success');
  tcp.getRemoteAddress().then(() => {
    console.log('getRemoteAddress success');
  }).catch((err: BusinessError) => {
    console.log('getRemoteAddressfail');
  });
}).catch((err: BusinessError) => {
  console.log('connect fail');
});
```

### getState

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase)\> | Yes  | Callback used to return the result. If the operation is successful, the status of the TCP socket is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  tcp.getState((err: BusinessError, data: socket.SocketStateBase) => {
    if (err) {
      console.log('getState fail');
      return;
    }
    console.log('getState success:' + JSON.stringify(data));
  });
});
```

### getState

getState(): Promise\<SocketStateBase\>

Obtains the status of a **TCPSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                            | Description                                      |
| ----------------------------------------------- | ----------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success');
  tcp.getState().then(() => {
    console.log('getState success');
  }).catch((err: BusinessError) => {
    console.log('getState fail');
  });
}).catch((err: BusinessError) => {
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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '0.0.0.0'
}
tcp.bind(bindAddr)
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions)
tcp.getSocketFd((err: BusinessError, data: number) => {
  console.info("getSocketFd failed: " + err);
  console.info("tunenlfd: " + data);
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
| ----------------------------------------------- | ----------------------------------------- |
| Promise\<number\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '0.0.0.0'
}
tcp.bind(bindAddr)
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}
tcp.connect(tcpconnectoptions)
tcp.getSocketFd().then((data: number) => {
  console.info("tunenlfd: " + data);
})
```

### setExtraOptions

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of a **TCPSocket** connection. For details, see [TCPExtraOptions](#tcpextraoptions).|
| callback | AsyncCallback\<void\>                     | Yes  | Callback used to return the result. If the operation fails, an error message is returned.              |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}

interface SocketLinger {
  on: boolean;
  linger: number;
}

tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpExtraOptions: socket.TCPExtraOptions = {
    keepAlive: true,
    OOBInline: true,
    TCPNoDelay: true,
    socketLinger: { on: true, linger: 10 } as SocketLinger,
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: true,
    socketTimeout: 3000
  }
  tcp.setExtraOptions(tcpExtraOptions, (err: BusinessError) => {
    if (err) {
      console.log('setExtraOptions fail');
      return;
    }
    console.log('setExtraOptions success');
  });
});
```

### setExtraOptions

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

Sets other properties of a **TCPSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of a **TCPSocket** connection. For details, see [TCPExtraOptions](#tcpextraoptions).|

**Return value**

| Type           | Description                                                |
| -------------- | --------------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: netAddress,
  timeout: 6000
}

interface SocketLinger {
  on: boolean;
  linger: number;
}

tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpExtraOptions: socket.TCPExtraOptions = {
    keepAlive: true,
    OOBInline: true,
    TCPNoDelay: true,
    socketLinger: { on: true, linger: 10 } as SocketLinger,
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: true,
    socketTimeout: 3000
  }
  tcp.setExtraOptions(tcpExtraOptions).then(() => {
    console.log('setExtraOptions success');
  }).catch((err: BusinessError) => {
    console.log('setExtraOptions fail');
  });
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<NetAddress\>

Obtains the local socket address of a **TCPSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  family: 1,
  port: 8080
}
tcp.bind(bindAddr).then(() => {
  tcp.getLocalAddress().then((localAddress: socket.NetAddress) => {
    console.info("SUCCESS! Address:" + JSON.stringify(localAddress));
  }).catch((err: BusinessError) => {
    console.error("FAILED! Error:" + JSON.stringify(err));
  })
}).catch((err: BusinessError) => {
  console.error('bind fail');
});
```

### on('message')

on(type: 'message', callback: Callback<SocketMessageInfo\>): void

Subscribes to **message** events of a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | Yes  | Callback used to return the result.                           |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let messageView = '';
tcp.on('message', (value: socket.SocketMessageInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let uint8Array = new Uint8Array(value.message) 
    let messages = uint8Array[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')

off(type: 'message', callback?: Callback<SocketMessageInfo\>): void

Unsubscribes from **message** events of a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | No  | Callback used to return the result.                              |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let messageView = '';
let callback = (value: socket.SocketMessageInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let uint8Array = new Uint8Array(value.message) 
    let messages = uint8Array[i]
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

### on('connect' | 'close')

on(type: 'connect' | 'close', callback: Callback\<void\>): void

Subscribes to **connect** or **close** events of a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Event type.<br>- **connect**: connection event.<br>- **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.             |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
tcp.on('connect', () => {
  console.log("on connect success")
});
tcp.on('close', () => {
  console.log("on close success")
});
```

### off('connect' | 'close')

off(type: 'connect' | 'close', callback?: Callback\<void\>): void

Unsubscribes from **connect** or **close** events of a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Event type.<br>- **connect**: connection event.<br>- **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result.                         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                            |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
tcp.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                            |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tcp.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcp.off('error', callback);
tcp.off('error');
```

## TCPConnectOptions

Defines parameters of a **TCPSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type                              | Mandatory| Description                      |
| ------- | ---------------------------------- | ---- | -------------------------- |
| address | [NetAddress](#netaddress) | Yes  | Bound IP address and port number.      |
| timeout | number                             | No  | Timeout duration of a **TCPSocket** connection, in ms.|

## TCPSendOptions

Defines the parameters for sending data over a **TCPSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| data     | string\| ArrayBuffer  | Yes  | Data to send.                                                |
| encoding | string | No  | Character encoding format. The options are as follows: **UTF-8**, **UTF-16BE**, **UTF-16LE**, **UTF-16**, **US-AECII**, and **ISO-8859-1**. The default value is **UTF-8**.|

## TCPExtraOptions

Defines other properties of a **TCPSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name           | Type   | Mandatory| Description                                                        |
| ----------------- | ------- | ---- | ------------------------------------------------------------ |
| keepAlive         | boolean | No  | Whether to keep the connection alive. The default value is **false**.                                 |
| OOBInline         | boolean | No  | Whether to enable OOBInline. The default value is **false**.                                |
| TCPNoDelay        | boolean | No  | Whether to enable no-delay on the **TCPSocket** connection. The default value is **false**.                      |
| socketLinger      | \{on:boolean, linger:number\}  | No  | Socket linger.<br>- **on**: whether to enable socket linger. The value true means to enable socket linger and false means the opposite.<br>- **linger**: linger time, in ms. The value ranges from **0** to **65535**.<br>Specify this parameter only when **on** is set to **true**.|
| receiveBufferSize | number  | No  | Size of the receive buffer, in bytes. The default value is **0**.                              |
| sendBufferSize    | number  | No  | Size of the send buffer, in bytes. The default value is **0**.                              |
| reuseAddress      | boolean | No  | Whether to reuse addresses. The default value is **false**.                                 |
| socketTimeout     | number  | No  | Timeout duration of the **UDPSocket** connection, in ms. The default value is **0**.                            |

## socket.constructTCPSocketServerInstance<sup>10+</sup>

constructTCPSocketServerInstance(): TCPSocketServer

Creates a **TCPSocketServer** connection.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                               | Description                         |
|  ---------------------------------- |  ---------------------------- |
| [TCPSocketServer](#tcpsocketserver10) | **TCPSocketServer** connection.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
```

## TCPSocketServer<sup>10+</sup>

Defines a **TCPSocketServer** connection. Before calling **TCPSocketServer** APIs, you need to call [socket.constructTCPSocketServerInstance](#socketconstructtcpsocketserverinstance10) to create a **TCPSocketServer** object.

### listen<sup>10+</sup>

listen(address: NetAddress, callback: AsyncCallback\<void\>): void

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. The server listens to and accepts **TCPSocket** connections established over the socket. Multiple threads are used to process client data concurrently. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> The server uses this API to perform the **bind**, **listen**, and **accept** operations. If the **bind** operation fails, the system randomly allocates a port number.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                     | Mandatory| Description                                         |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| address  | [NetAddress](#netaddress) | Yes  | Destination address.|
| callback | AsyncCallback\<void\>     | Yes  | Callback used to return the result. If the operation fails, an error message is returned.   |

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable. Try again.|
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
```

### listen<sup>10+</sup>

listen(address: NetAddress): Promise\<void\>

Binds the IP address and port number. The port number can be specified or randomly allocated by the system. The server listens to and accepts **TCPSocket** connections established over the socket. Multiple threads are used to process client data concurrently. This API uses a promise to return the result.

> **NOTE**<br>
> The server uses this API to perform the **bind**, **listen**, and **accept** operations. If the **bind** operation fails, the system randomly allocates a port number.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                     | Mandatory| Description                                         |
| ------- | ------------------------- | ---- | --------------------------------------------- |
| address | [NetAddress](#netaddress) | Yes  | Destination address.|

**Return value**

| Type           | Description                                                        |
|  -------------- |  ----------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable. Try again.|
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr).then(() => {
  console.log('listen success');
}).catch((err: BusinessError) => {
  console.log('listen fail');
});
```

### getState<sup>10+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of a **TCPSocketServer** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                              | Mandatory| Description      |
| -------- | -------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase)\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
tcpServer.getState((err: BusinessError, data: socket.SocketStateBase) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
})
```

### getState<sup>10+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of a **TCPSocketServer** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                        | Description                                      |
|  ------------------------------------------- |  ----------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
tcpServer.getState().then((data: socket.SocketStateBase) => {
  console.log('getState success' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of a **TCPSocketServer** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of a **TCPSocketServer** connection.|
| callback | AsyncCallback\<void\>               | Yes  | Callback used to return the result. If the operation fails, an error message is returned.               |

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})

interface SocketLinger {
  on: boolean;
  linger: number;
}

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 } as SocketLinger,
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tcpServer.setExtraOptions(tcpExtraOptions, (err: BusinessError) => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

Sets other properties of a **TCPSocketServer** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                               | Mandatory| Description                                                        |
| ------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of a **TCPSocketServer** connection.|

**Return value**

| Type           | Description                                                      |
|  -------------- |  --------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}

interface SocketLinger {
  on: boolean;
  linger: number;
}

tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 } as SocketLinger,
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tcpServer.setExtraOptions(tcpExtraOptions).then(() => {
  console.log('setExtraOptions success');
}).catch((err: BusinessError) => {
  console.log('setExtraOptions fail');
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<NetAddress\>

Obtains the local socket address of a **TCPSocketServer** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr).then(() => {
  tcpServer.getLocalAddress().then((localAddress: socket.NetAddress) => {
    console.info("SUCCESS! Address:" + JSON.stringify(localAddress));
  }).catch((err: BusinessError) => {
    console.error("FerrorAILED! Error:" + JSON.stringify(err));
  })
}).catch((err: BusinessError) => {
  console.error('listen fail');
});
```

### on('connect')<sup>10+</sup>

on(type: 'connect', callback: Callback\<TCPSocketConnection\>): void

Subscribes to **connect** events of a **TCPSocketServer** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                           | Mandatory| Description                                 |
| -------- | ------------------------------- | ---- | ------------------------------------- |
| type     | string                          | Yes  | Event type.<br/> **connect**: connection event.|
| callback | Callback\<[TCPSocketConnection](#tcpsocketconnection10)\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.      |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (data: socket.TCPSocketConnection) => {
  console.log(JSON.stringify(data))
});
```

### off('connect')<sup>10+</sup>

off(type: 'connect', callback?: Callback\<TCPSocketConnection\>): void

Unsubscribes from **connect** events of a **TCPSocketServer** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                           | Mandatory| Description                                 |
| -------- | ------------------------------- | ---- | ------------------------------------- |
| type     | string                          | Yes  | Event type.<br/> **connect**: connection event.|
| callback | Callback\<[TCPSocketConnection](#tcpsocketconnection10)\> | No  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = (data: socket.TCPSocketConnection) => {
  console.log('on connect message: ' + JSON.stringify(data));
}
tcpServer.on('connect', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcpServer.off('connect', callback);
tcpServer.off('connect');
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **TCPSocketServer** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **TCPSocketServer** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result. If the operation fails, an error message is returned.                          |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tcpServer.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tcpServer.off('error', callback);
tcpServer.off('error');
```

## TCPSocketConnection<sup>10+</sup>

Defines a **TCPSocketConnection** object, that is, the connection between the **TCPSocket** client and the server. Before calling **TCPSocketConnection** APIs, you need to obtain a **TCPSocketConnection** object.

> **NOTE**
> The client can call related APIs through the **TCPSocketConnection** object only after a connection is successfully established between the client and the server.

**System capability**: SystemCapability.Communication.NetStack

### Attributes

| Name    | Type  | Mandatory| Description                                     |
| -------- | ------ | ---- | ----------------------------------------- |
| clientId | number | Yes  | ID of the connection between the **TCPSocket** client and the server.|

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
| options  | [TCPSendOptions](#tcpsendoptions) | Yes  | Defines the parameters for sending data over a **TCPSocket** connection.|
| callback | AsyncCallback\<void\>             | Yes  | Callback used to return the result. If the operation fails, an error message is returned.            |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  let tcpSendOption: socket.TCPSendOptions = {
    data: 'Hello, client!'
  }
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
| options | [TCPSendOptions](#tcpsendoptions) | Yes  | Defines the parameters for sending data over a **TCPSocket** connection.|

**Return value**

| Type           | Description                                                        |
|  -------------- |  ----------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  let tcpSendOption: socket.TCPSendOptions = {
    data: 'Hello, client!'
  }
  client.send(tcpSendOption).then(() => {
    console.log('send success');
  }).catch((err: BusinessError) => {
    console.log('send fail');
  });
});
```

### close<sup>10+</sup>

close(callback: AsyncCallback\<void\>): void

Closes a **TCPSocket** connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.close((err: BusinessError) => {
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

Closes a **TCPSocket** connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                        |
|  -------------- |  ------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.close().then(() => {
  	console.log('close success');
  }).catch((err: BusinessError) => {
  	console.log('close fail');
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

Obtains the remote address of a **Socket** connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after a connection with the client is set up.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description      |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetAddress](#netaddress)\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.getRemoteAddress((err: BusinessError, data: socket.NetAddress) => {
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

Obtains the remote address of a **Socket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after a connection with the client is set up.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                                       |
|  --------------------------------- |  ------------------------------------------ |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.getRemoteAddress().then(() => {
    console.log('getRemoteAddress success');
  }).catch((err: BusinessError) => {
    console.log('getRemoteAddress fail');
  });
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<NetAddress\>

Obtains the local socket address of a **TCPSocketConnection** connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address: "192.168.xx.xx",
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
  let netAddress: socket.NetAddress = {
    address: "192.168.xx.xx",
    port: 8080
  }
  let options: socket.TCPConnectOptions = {
    address: netAddress,
    timeout: 6000
  }
  tcp.connect(options, (err: BusinessError) => {
    if (err) {
      console.error('connect fail');
      return;
    }
    console.info('connect success!');
  })
  tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
    client.getLocalAddress().then((localAddress: socket.NetAddress) => {
      console.info("Family IP Port: " + JSON.stringify(localAddress));
    }).catch((err: BusinessError) => {
      console.error('Error:' + JSON.stringify(err));
    });
  })
})
```

### on('message')<sup>10+</sup>

on(type: 'message', callback: Callback<SocketMessageInfo\>): void

Subscribes to **message** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.        |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('message', (value: socket.SocketMessageInfo) => {
    let messageView = '';
    for (let i: number = 0; i < value.message.byteLength; i++) {
      let uint8Array = new Uint8Array(value.message) 
      let messages = uint8Array[i]
      let message = String.fromCharCode(messages);
      messageView += message;
    }
    console.log('on message message: ' + JSON.stringify(messageView));
    console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
  });
});
```

### off('message')<sup>10+</sup>

off(type: 'message', callback?: Callback<SocketMessageInfo\>): void

Unsubscribes from **message** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | No  | Callback used to return the result. If the operation fails, an error message is returned.       |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = (value: socket.SocketMessageInfo) => {
  let messageView = '';
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let uint8Array = new Uint8Array(value.message) 
    let messages = uint8Array[i]
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
| type     | string           | Yes  | Event type.<br/> **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.       |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                               |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | Yes  | Event type.<br/> **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result. If the operation fails, an error message is returned.   |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

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
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result. If the operation fails, an error message is returned.   |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('error', (err: BusinessError) => {
    console.log("on error, err:" + JSON.stringify(err))
  });
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **TCPSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result. If the operation fails, an error message is returned. |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('error', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  client.off('error', callback);
  client.off('error');
});
```

## Description of TCP Error Codes

The TCP error code mapping is in the format of 2301000 + Linux kernel error code.

For details about error codes, see [Socket Error Codes](errorcode-net-socket.md).

## socket.constructLocalSocketInstance<sup>11+</sup>

constructLocalSocketInstance(): LocalSocket

Creates a **LocalSocket** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                   |
  | :--------------------------------- | :---------------------- |
| [LocalSocket](#localsocket11) | **LocalSocket** object.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
let client: socket.LocalSocket = socket.constructLocalSocketInstance();
```

## LocalSocket<sup>11+</sup>

Defines a **LocalSocket** object. Before calling **LocalSocket** APIs, you need to call [socket.constructLocalSocketInstance](#socketconstructlocalsocketinstance11) to create a **LocalSocket** object.

### bind<sup>11+</sup>

bind(address: LocalAddress): Promise\<void\>;

Binds the address of a local socket file. This API uses a promise to return the result.

> **NOTE**
> This API explicitly binds the client to a local socket file based on the specified address.
> It is not mandatory in local socket communication.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                              | Mandatory| Description                                                  |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [LocalAddress](#localaddress11) | Yes  | Destination address. For details, see [LocalAddress](#localaddress11).|

**Error codes**

| ID| Error Message                   |
| ------- | -------------------------- |
| 401     | Parameter error.           |
| 2301013 | Insufficient permissions.  |
| 2301022 | Invalid argument.          |
| 2301098 | Address already in use.    |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance()
let sandboxPath: string = getContext().filesDir + '/testSocket'
let address : socket.LocalAddress = {
  address: sandboxPath
}
client.bind(address).then(() => {
  console.log('bind success')
}).catch((err: Object) => {
  console.error('failed to bind: ' + JSON.stringify(err))
})
```

### connect<sup>11+</sup>

connect(options: LocalConnectOptions): Promise\<void\>

Connects to the specified socket file. This API uses a promise to return the result.

> **NOTE**
> This API allows you to connect to the TCP server without first executing **localsocket.bind**.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                    | Mandatory| Description                                                        |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [LocalConnectOptions](#localconnectoptions11) | Yes  | **LocalSocket** connection parameters. For details, see [LocalConnectOptions](#localconnectoptions11).|

**Return value**

| Type           | Description                                      |
| :-------------- | :---------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.                 |
| 2301013     | Insufficient permissions.        |
| 2301022     | Invalid argument.                |
| 2301111     | Connection refused.              |
| 2301099     | Cannot assign requested address. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let localAddress : socket.LocalAddress = {
  address: sandboxPath
}
let connectOpt: socket.LocalConnectOptions = {
  address: localAddress,
  timeout: 6000
}
client.connect(connectOpt).then(() => {
  console.log('connect success')
}).catch((err: Object) => {
  console.error('connect fail: ' + JSON.stringify(err));
});
```

### send<sup>11+</sup>

send(options: LocalSendOptions): Promise\<void\>

Sends data over a **LocalSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **connect** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                   | Mandatory| Description                                                        |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [LocalSendOptions](#localsendoptions11) | Yes  | Parameters for sending data over a **LocalSocket** connection. For details, see [LocalSendOptions](#localsendoptions11).|

**Return value**

| Type           | Description                                        |
| :-------------- | :------------------------------------------ |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301011 | Operation would block.  |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance()
let sandboxPath: string = getContext().filesDir + '/testSocket'
let localAddress : socket.LocalAddress = {
  address: sandboxPath
}
let connectOpt: socket.LocalConnectOptions = {
  address: localAddress,
  timeout: 6000
}
client.connect(connectOpt).then(() => {
  console.log('connect success')
}).catch((err: Object) => {
  console.error('connect failed: ' + JSON.stringify(err))
})
let sendOpt: socket.LocalSendOptions = {
  data: 'Hello world!'
}
client.send(sendOpt).then(() => {
  console.log('send success')
}).catch((err: Object) => {
  console.error('send fail: ' + JSON.stringify(err))
})
```

### close<sup>11+</sup>

close(): Promise\<void\>

Closes a **LocalSocket** connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                      |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 2301009 | Bad file descriptor.    |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();

client.close().then(() => {
  console.log('close success');
}).catch((err: Object) => {
  console.error('close fail: ' + JSON.stringify(err));
});
```

### getState<sup>11+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the **LocalSocket** connection status. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                         | Description                                    |
| :------------------------------------------- | :--------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let localAddress : socket.LocalAddress = {
  address: sandboxPath
}
let connectOpt: socket.LocalConnectOptions = {
  address: localAddress,
  timeout: 6000
}
client.connect(connectOpt).then(() => {
  console.log('connect success');
  client.getState().then(() => {
    console.log('getState success');
  }).catch((err: Object) => {
    console.error('getState fail: ' + JSON.stringify(err))
  });
}).catch((err: Object) => {
  console.error('connect fail: ' + JSON.stringify(err));
});
```

### getSocketFd<sup>11+</sup>

getSocketFd(): Promise\<number\>

Obtains the file descriptor of the **LocalSocket** object. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.
> The file descriptor is allocated by the system kernel to uniquely identify the local socket in use.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type              | Description                             |
| :---------------- | :-------------------------------- |
| Promise\<number\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let localAddress : socket.LocalAddress = {
  address: sandboxPath
}
let connectOpt: socket.LocalConnectOptions = {
  address: localAddress,
  timeout: 6000
}
client.connect(connectOpt).then(() => {
  console.log('connect ok')
}).catch((err: Object) => {
  console.error('connect fail: ' + JSON.stringify(err))
})
client.getSocketFd().then((data: number) => {
  console.info("fd: " + data);
}).catch((err: Object) => {
  console.error("getSocketFd faile: " + JSON.stringify(err));
})
```

### setExtraOptions<sup>11+</sup>

setExtraOptions(options: ExtraOptionsBase): Promise\<void\>

Sets other properties of the **LocalSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ExtraOptionsBase](#extraoptionsbase7) | Yes  | Other properties of the **LocalSocket** connection. For details, see [ExtraOptionsBase](#extraoptionsbase7).|

**Return value**

| Type           | Description                                          |
| :-------------- | :-------------------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 2301009 | Bad file descriptor.    |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let localAddress : socket.LocalAddress = {
  address: sandboxPath
}
let connectOpt: socket.LocalConnectOptions = {
  address: localAddress,
  timeout: 6000
}
client.connect(connectOpt).then(() => {
  console.log('connect success');
  let options: socket.ExtraOptionsBase = {
    receiveBufferSize: 8000,
    sendBufferSize: 8000,
    socketTimeout: 3000
  }
  client.setExtraOptions(options).then(() => {
    console.log('setExtraOptions success');
  }).catch((err: Object) => {
    console.error('setExtraOptions fail: ' + JSON.stringify(err));
  });
}).catch((err: Object) => {
  console.error('connect fail: ' + JSON.stringify(err));
});
```

### getExtraOptions<sup>11+</sup>

getExtraOptions(): Promise\<ExtraOptionsBase\>;

Obtains other properties of the **LocalSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** or **connect** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                        | Description                                     |
| :-------------------------- | :---------------------------------------- |
| Promise\<[ExtraOptionsBase](#extraoptionsbase7)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 2301009 | Bad file descriptor.    |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let localAddress : socket.LocalAddress = {
  address: sandboxPath
}
let connectOpt: socket.LocalConnectOptions = {
  address: localAddress,
  timeout: 6000
}
client.connect(connectOpt).then(() => {
  console.log('connect success');
  client.getExtraOptions().then((options : socket.ExtraOptionsBase) => {
    console.log('options: ' + JSON.stringify(options));
  }).catch((err: Object) => {
    console.error('setExtraOptions fail: ' + JSON.stringify(err));
  });
}).catch((err: Object) => {
  console.error('connect fail: ' + JSON.stringify(err));
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<string\>

Obtains the local socket address of a **LocalSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **bind** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<string\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket';
let address : socket.LocalAddress = {
  address: sandboxPath
}
client.bind(address).then(() => {
  console.error('bind success');
  client.getLocalAddress().then((localPath: string) => {
    console.info("SUCCESS " + JSON.stringify(localPath));
  }).catch((err: BusinessError) => {
    console.error("FAIL " + JSON.stringify(err));
  })
}).catch((err: Object) => {
  console.info('failed to bind: ' + JSON.stringify(err));
})
```

### on('message')<sup>11+</sup>

on(type: 'message', callback: Callback\<LocalSocketMessageInfo\>): void

Subscribes to **message** events of a **LocalSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                             | Mandatory| Description                                     |
| -------- | ----------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                          | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[LocalSocketMessageInfo](#localsocketmessageinfo11)\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
client.on('message', (value: socket.LocalSocketMessageInfo) => {
  const uintArray = new Uint8Array(value.message)
  let messageView = '';
  for (let i = 0; i < uintArray.length; i++) {
    messageView += String.fromCharCode(uintArray[i]);
  }
  console.log('total: ' + JSON.stringify(value));
  console.log('message infomation: ' + messageView);
});
```

### off('message')<sup>11+</sup>

off(type: 'message', callback?: Callback\<LocalSocketMessageInfo\>): void

Unsubscribes from **message** events of a **LocalSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                              | Mandatory| Description                                |
| -------- | ------------------------------------------------ | ---- | ----------------------------------- |
| type     | string                                           | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[LocalSocketMessageInfo](#localsocketmessageinfo11)\> | No  | Callback passed to the **on** function.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let messageView = '';
let callback = (value: socket.LocalSocketMessageInfo) => {
  const uintArray = new Uint8Array(value.message)
  let messageView = '';
  for (let i = 0; i < uintArray.length; i++) {
    messageView += String.fromCharCode(uintArray[i]);
  }
  console.log('total: ' + JSON.stringify(value));
  console.log('message infomation: ' + messageView);
}
client.on('message', callback);
client.off('message');
```

### on('connect')<sup>11+</sup>

on(type: 'connect', callback: Callback\<void\>): void;

Subscribes to **connect** events of a **LocalSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | --------------------------------------------------------- |
| type     | string           | Yes  | Event type.<br/>                                            |
| callback | Callback\<void\> | Yes  | Callback used to return the result.                    |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
client.on('connect', () => {
  console.log("on connect success")
});
```

### off('connect')<sup>11+</sup>

off(type: 'connect', callback?: Callback\<void\>): void;

Unsubscribes from **connect** events of a **LocalSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | --------------------------------------------------------- |
| type     | string           | Yes  | Event type.<br/>                                            |
| callback | Callback\<void\> | No  | Callback passed to the **on** function.                          |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let callback = () => {
  console.log("on connect success");
}
client.on('connect', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
client.off('connect', callback);
client.off('connect');
```

### on('close')<sup>11+</sup>

on(type: 'close', callback: Callback\<void\>): void;

Subscribes to **close** events of a **LocalSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string           | Yes  | Event type.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let callback = () => {
  console.log("on close success");
}
client.on('close', callback);
```

### off('close')<sup>11+</sup>

off(type: 'close', callback?: Callback\<void\>): void;

Unsubscribes from **close** events of a **LocalSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string           | Yes  | Event type.|
| callback | Callback\<void\> | No  | Callback passed to the **on** function.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let callback = () => {
  console.log("on close success");
}
client.on('close', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
client.off('close', callback);
client.off('close');
```

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **LocalSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                           |
| -------- | ------------- | ---- | ---------------------------- |
| type     | string        | Yes  | Event type.  |
| callback | ErrorCallback | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
client.on('error', (err: Object) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void;

Unsubscribes from **error** events of a **LocalSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                            |
| -------- | ------------- | ---- | ----------------------------- |
| type     | string        | Yes  | Event type.|
| callback | ErrorCallback | No  | Callback passed to the **on** function.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let client: socket.LocalSocket = socket.constructLocalSocketInstance();
let callback = (err: Object) => {
  console.log("on error, err:" + JSON.stringify(err));
}
client.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
client.off('error', callback);
client.off('error');
```

## LocalSocketMessageInfo<sup>11+</sup>

Defines the data received by the client over a **LocalSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name    | Type           | Mandatory| Description              |
| ------- | --------------- | --- | ------------------ |
| message | ArrayBuffer     | Yes  | Data received.    |
| address | string          | Yes  | **LocalSocket** connection address.|
| size    | number          | Yes  | Data length.         |

## LocalAddress<sup>11+</sup>

Defines the address of a local socket file. When the address is passed for binding, a socket file is created at this address.

**System capability**: SystemCapability.Communication.NetStack

| Name    | Type      | Mandatory| Description              |
| ------- | ---------- | --- | ------------------ |
| address | string     | Yes  | Address of the local socket file.    |

## LocalConnectOptions<sup>11+</sup>

Defines **LocalSocket** connection parameters.

**System capability**: SystemCapability.Communication.NetStack

| Name    | Type      | Mandatory| Description                           |
| ------- | ---------- | --- | ------------------------------ |
| address | [LocalAddress](#localaddress11)    | Yes  | Address of the local socket file.           |
| timeout | number     | No  | Timeout duration of the **LocalSocket** connection, in ms. |

## LocalSendOptions<sup>11+</sup>

Defines the parameters for sending data over a **LocalSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name    | Type      | Mandatory| Description                |
| ------- | ---------- | --- | ------------------- |
| data    | string \| ArrayBuffer | Yes  | Data to be transmitted.|
| encoding | string   | No  | Encoding format of the string. |

## ExtraOptionsBase<sup>7+</sup>

Defines other properties of the **LocalSocket** connection.

**System capability**: SystemCapability.Communication.NetStack

| Name           | Type   | Mandatory| Description                             |
| ----------------- | ------- | ---- | ----------------------------- |
| receiveBufferSize | number  | No  | Size of the receive buffer, in bytes.    |
| sendBufferSize    | number  | No  | Size of the send buffer, in bytes.    |
| reuseAddress      | boolean | No  | Whether to reuse addresses.                  |
| socketTimeout     | number  | No  | Timeout duration of the **LocalSocket** connection, in ms.   |

## socket.constructLocalSocketServerInstance<sup>11+</sup>

constructLocalSocketServerInstance(): LocalSocketServer

Creates a **LocalSocketServer** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                               | Description                         |
| :---------------------------------- | :---------------------------- |
| [LocalSocketServer](#localsocketserver11) | **LocalSocketServer** object.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
```

## LocalSocketServer<sup>11+</sup>

Defines a **LocalSocketServer** connection. Before calling **LocalSocketServer** APIs, you need to call [socket.constructLocalSocketServerInstance](#socketconstructlocalsocketserverinstance11) to create a **LocalSocketServer** connection. 

### listen<sup>11+</sup>

listen(address: LocalAddress): Promise\<void\>

Binds the address of the local socket file. The server listens to and accepts **LocalSocket** connections established over the socket. Multiple threads are used to process client data concurrently. This API uses a promise to return the result.

> **NOTE**
> The server uses this API to complete the **bind**, **listen**, and **accept** operations. If the address of the local socket file is passed for binding, a socket file is automatically created when this API is called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                     | Mandatory| Description                                         |
| ------- | ------------------------- | ---- | --------------------------------------------- |
| address | [LocalAddress](#localaddress11) | Yes  | Destination address.|

**Return value**

| Type           | Description                                                  |
| :-------------- | :---------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                     |
| -------- | --------------------------- |
| 401      | Parameter error.            |
| 2303109  | Bad file number.            |
| 2301013  | Insufficient permissions.   |
| 2301022  | Invalid argument.           |
| 2301098  | Address already in use.     |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let addr: socket.LocalAddress = {
  address: sandboxPath
}
server.listen(addr).then(() => {
  console.log('listen success');
}).catch((err: Object) => {
  console.error('listen fail: ' + JSON.stringify(err));
});
```

### getState<sup>11+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of a **LocalSocketServer** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                        | Description                                           |
| :------------------------------------------- | :--------------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | Promise used to return the result.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let listenAddr: socket.LocalAddress = {
  address: sandboxPath
}
server.listen(listenAddr).then(() => {
  console.log("listen success");
}).catch((err: Object) => {
  console.error("listen fail: " + JSON.stringify(err));
})
server.getState().then((data: socket.SocketStateBase) => {
  console.log('getState success: ' + JSON.stringify(data));
}).catch((err: Object) => {
  console.error('getState fail: ' + JSON.stringify(err));
});
```

### setExtraOptions<sup>11+</sup>

setExtraOptions(options: ExtraOptionsBase): Promise\<void\>

Sets other properties of the **LocalSocketServer** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                     | Mandatory| Description                           |
| ------- | --------------------------------------- | ---- | ------------------------------ |
| options | [ExtraOptionsBase](#extraoptionsbase7) | Yes  | Other properties of a **LocalSocketServer** connection.|

**Return value**

| Type           | Description                                            |
| :-------------- | :---------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2301009  | Bad file descriptor.            |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let listenAddr: socket.NetAddress = {
  address: sandboxPath
}
server.listen(listenAddr).then(() => {
  console.log("listen success");
}).catch((err: Object) => {
  console.error("listen fail: " + JSON.stringify(err));
})

let options: socket.ExtraOptionsBase = {
  receiveBufferSize: 6000,
  sendBufferSize: 6000,
  socketTimeout: 3000
}
server.setExtraOptions(options).then(() => {
  console.log('setExtraOptions success');
}).catch((err: Object) => {
  console.error('setExtraOptions fail: ' + JSON.stringify(err));
});
```

### getExtraOptions<sup>11+</sup>

getExtraOptions(): Promise\<ExtraOptionsBase\>;

Obtains other properties of a **LocalSocketServer** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                        | Description                       |
| :-------------------------- | :-------------------------- |
| Promise\<[ExtraOptionsBase](#extraoptionsbase7)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | -------------------- |
| 401     | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let listenAddr: socket.LocalAddress = {
  address: sandboxPath
}
server.listen(listenAddr).then(() => {
  console.log("listen success");
}).catch((err: Object) => {
  console.error("listen fail: " + JSON.stringify(err));
})
server.getExtraOptions().then((options: socket.ExtraOptionsBase) => {
  console.log('options: ' + JSON.stringify(options));
}).catch((err: Object) => {
  console.error('getExtraOptions fail: ' + JSON.stringify(err));
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<string\>

Obtains the local socket address of a **LocalSocketServer** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<string\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket';
let listenAddr: socket.LocalAddress = {
  address: sandboxPath
}
server.listen(listenAddr).then(() => {
  console.info("listen success");
  server.getLocalAddress().then((localPath: string) => {
    console.info("SUCCESS " + JSON.stringify(localPath));
  }).catch((err: BusinessError) => {
    console.error("FAIL " + JSON.stringify(err));
  })
}).catch((err: Object) => {
  console.error("listen fail: " + JSON.stringify(err));
})

```

### on('connect')<sup>11+</sup>

on(type: 'connect', callback: Callback\<LocalSocketConnection\>): void

Subscribes to **connect** events of a **LocalSocketServer** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                           | Mandatory| Description                                 |
| -------- | ------------------------------- | ---- | ------------------------------------- |
| type     | string                          | Yes  | Event type.<br/> **connect**: connection event.|
| callback | Callback\<[LocalSocketConnection](#localsocketconnection11)\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
server.on('connect', (connection: socket.LocalSocketConnection) => {
  if (connection) {
    console.log('accept a client')
  }
});
```

### off('connect')<sup>11+</sup>

off(type: 'connect', callback?: Callback\<LocalSocketConnection\>): void

Unsubscribes from **connect** events of a **LocalSocketServer** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                           | Mandatory| Description                                 |
| -------- | ------------------------------- | ---- | ------------------------------------- |
| type     | string                          | Yes  | Event type.<br/> **connect**: connection event.|
| callback | Callback\<[LocalSocketConnection](#localsocketconnection11)\> | No  | Callback passed to the **on** function.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let callback = (connection: socket.LocalSocketConnection) => {
  if (connection) {
    console.log('accept a client')
  }
}
server.on('connect', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
server.off('connect', callback);
server.off('connect');
```

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **LocalSocketServer** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
server.on('error', (err: Object) => {
  console.error("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **LocalSocketServer** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback passed to the **on** function.  |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let callback = (err: Object) => {
  console.error("on error, err:" + JSON.stringify(err));
}
server.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
server.off('error', callback);
server.off('error');
```


## LocalSocketConnection<sup>11+</sup>

Defines a **LocalSocket** connection, that is, the session between the local socket client and the server. Before calling **LocalSocketConnection** APIs, you need to obtain a **LocalSocketConnection** object.

> **NOTE**
> The client can call related APIs through the **LocalSocketConnection** object only after a connection is successfully established between the client and the server.

**System capability**: SystemCapability.Communication.NetStack

### Attributes

| Name    | Type  | Mandatory| Description                           |
| -------- | ------ | ---- | ---------------------------- |
| clientId | number | Yes  | ID of the session between the client and the server.|

### send<sup>11+</sup>

send(options: LocalSendOptions): Promise\<void\>

Sends data over a **LocalSocket** connection. This API uses a promise to return the result.

> **NOTE**
> This API can be used only after the server obtains a **LocalSocketConnection** object through the **callback** of the **connect** event.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                             | Mandatory| Description                                                        |
| ------- | --------------------------------- | ---- | -------------------------------------- |
| options | [LocalSendOptions](#localsendoptions11) | Yes  | Defines the parameters for sending data over a **LocalSocket** connection.|

**Return value**

| Type           | Description                                            |
| :-------------- | :---------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 2301011  | Operation would block. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();

server.on('connect', (connection: socket.LocalSocketConnection) => {
  let sendOptions: socket.LocalSendOptions = {
    data: 'Hello, client!'
  }
  connection.send(sendOptions).then(() => {
    console.log('send success');
  }).catch((err: Object) => {
    console.error('send fail: ' + JSON.stringify(err));
  });
});
```

### close<sup>11+</sup>

close(): Promise\<void\>

Closes a **LocalSocket** connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                        |
| :-------------- | :------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message              |
| -------- | -------------------- |
| 2301009  | Bad file descriptor. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
server.on('connect', (connection: socket.LocalSocketConnection) => {
  connection.close().then(() => {
    console.log('close success');
  }).catch((err: Object) => {
    console.error('close fail: ' + JSON.stringify(err));
  });
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<string\>

Obtains the local socket address of a **LocalSocketConnection** connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<string\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket';
let localAddr: socket.LocalAddress = {
  address: sandboxPath
}
server.listen(localAddr).then(() => {
  console.info('listen success');
  let client: socket.LocalSocket = socket.constructLocalSocketInstance();
  let connectOpt: socket.LocalConnectOptions = {
    address: localAddr,
    timeout: 6000
  }
  client.connect(connectOpt).then(() => {
    server.getLocalAddress().then((localPath: string) => {
      console.info("success, localPath is" + JSON.stringify(localPath));
    }).catch((err: BusinessError) => {
      console.error("FAIL " + JSON.stringify(err));
    })
  }).catch((err: Object) => {
    console.error('connect fail: ' + JSON.stringify(err));
  });
});
```

### on('message')<sup>11+</sup>

on(type: 'message', callback: Callback\<LocalSocketMessageInfo\>): void;

Subscribes to **message** events of a **LocalSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                             | Mandatory| Description                                    |
| -------- | ----------------------------------------------- | ---- | --------------------------------------- |
| type     | string                                          | Yes  | Event type.<br/> **message**: message receiving event.    |
| callback | Callback\<[LocalSocketMessageInfo](#localsocketmessageinfo11)\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let sandboxPath: string = getContext().filesDir + '/testSocket'
let listenAddr: socket.LocalAddress = {
  address: sandboxPath
}
server.listen(listenAddr).then(() => {
  console.log("listen success");
}).catch((err: Object) => {
  console.error("listen fail: " + JSON.stringify(err));
});
server.on('connect', (connection: socket.LocalSocketConnection) => {
  connection.on('message', (value: socket.LocalSocketMessageInfo) => {
    const uintArray = new Uint8Array(value.message);
    let messageView = '';
    for (let i = 0; i < uintArray.length; i++) {
      messageView += String.fromCharCode(uintArray[i]);
    }
    console.log('total: ' + JSON.stringify(value));
    console.log('message infomation: ' + messageView);
  });
});
```

### off('message')<sup>11+</sup>

off(type: 'message', callback?: Callback\<LocalSocketMessageInfo\>): void

Unsubscribes from **message** events of a **LocalSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                             | Mandatory| Description                                |
| -------- | ----------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                          | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[LocalSocketMessageInfo](#localsocketmessageinfo11)\> | No  | Callback passed to the **on** function.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let callback = (value: socket.LocalSocketMessageInfo) => {
  const uintArray = new Uint8Array(value.message)
  let messageView = '';
  for (let i = 0; i < uintArray.length; i++) {
    messageView += String.fromCharCode(uintArray[i]);
  }
  console.log('total: ' + JSON.stringify(value));
  console.log('message infomation: ' + messageView);
}
server.on('connect', (connection: socket.LocalSocketConnection) => {
  connection.on('message', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  connection.off('message', callback);
  connection.off('message');
});
```

### on('close')<sup>11+</sup>

on(type: 'close', callback: Callback\<void\>): void

Unsubscribes from **close** events of a **LocalSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                               |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | Yes  | Event type.<br/> **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
server.on('connect', (connection: socket.LocalSocketConnection) => {
  connection.on('close', () => {
    console.log("on close success")
  });
});
```

### off('close')<sup>11+</sup>

off(type: 'close', callback?: Callback\<void\>): void

Unsubscribes from **close** events of a **LocalSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                               |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | Yes  | Event type.<br/> **close**: close event.|
| callback | Callback\<void\> | No  | Callback passed to the **on** function.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
let callback = () => {
  console.log("on close success");
}
server.on('connect', (connection: socket.LocalSocketConnection) => {
  connection.on('close', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  connection.off('close', callback);
  connection.off('close');
});
```

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **error** events of a **LocalSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
server.on('connect', (connection: socket.LocalSocketConnection) => {
  connection.on('error', (err: Object) => {
    console.error("on error, err:" + JSON.stringify(err))
  });
});
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **LocalSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback passed to the **on** function.  |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let callback = (err: Object) => {
  console.error("on error, err: " + JSON.stringify(err));
}
let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
server.on('connect', (connection: socket.LocalSocketConnection) => {
  connection.on('error', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  connection.off('error', callback);
  connection.off('error');
});
```

## Description of LocalSocket Error Codes

The LocalSocket error code mapping is in the format of 2301000 + Linux kernel error code.

For details about error codes, see [Socket Error Codes](errorcode-net-socket.md).

## socket.constructTLSSocketInstance<sup>9+</sup>

constructTLSSocketInstance(): TLSSocket

Creates a **TLSSocket** object.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                              | Description                   |
|  --------------------------------- |  ---------------------- |
| [TLSSocket](#tlssocket9) | **TLSSocket** connection.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
```

## socket.constructTLSSocketInstance<sup>12+</sup>

constructTLSSocketInstance(tcpSocket: TCPSocket): TLSSocket

Upgrades a **TCPSocket** connection to a **TLSSocket** connection.

> **NOTE**
> Before calling **constructTLSSocketInstance**, ensure that a **TCPSocket** connection has been established and no data is transmitted. After a successful upgrade, you do not need to call the **close** API for the **TCPSocket** object.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name      | Type| Mandatory| Description                    |
|-----------|----| ---- |------------------------|
| tcpSocket | [TCPSocket](#tcpsocket)   | Yes  | **TCPSocket** connection to be upgraded.|

**Return value**

| Type                              | Description                   |
|  --------------------------------- |  ---------------------- |
| [TLSSocket](#tlssocket9) | **TLSSocket** connection.|

**Error codes**

| ID  | Error Message                            |
|---------|----------------------------------|
| 401     | Parameter error.  |
| 2300002 | System internal error.  |
| 2303601 | Invalid socket FD.     |
| 2303602 | Socket is not connected.  |

**Example**

```ts
import { socket } from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';

let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions, (err: BusinessError) => {
  if (err) {
    console.log('connect fail');
    return;
  }
  console.log('connect success');

  // Ensure that a TCPSocket connection has been established before upgrading it to a TLSSocket connection.
  let tls: socket.TLSSocket = socket.constructTLSSocketInstance(tcp);
})
```

## TLSSocket<sup>9+</sup>

Defines a **TLSSocket** connection. Before calling **TLSSocket** APIs, you need to call [socket.constructTLSSocketInstance](#socketconstructtlssocketinstance9) to create a **TLSSocket** connection.

### bind<sup>9+</sup>

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

Binds the IP address and port number. This API uses an asynchronous callback to return the result.

> **NOTE**
> If the **TLSSocket** object is upgraded from a **TCPSocket** object, you do not need to execute the **bind** API.

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
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

> **NOTE**
> If the **TLSSocket** object is upgraded from a **TCPSocket** object, you do not need to execute the **bind** API.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                              | Mandatory| Description                                                  |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress)          | Yes  | Destination address. For details, see [NetAddress](#netaddress).|

**Return value**

| Type           | Description                                                    |
|  -------------- |  ------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2303198 | Address already in use. |
| 2300002 | System internal error.  |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr).then(() => {
  console.log('bind success');
}).catch((err: BusinessError) => {
  console.log('bind fail');
});
```

### getState<sup>9+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of the **TLSSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase)\> | Yes  | Callback used to return the result. If the operation is successful, the status of the **TLSSocket** connection is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
tls.getState((err: BusinessError, data: socket.SocketStateBase) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
});
```

### getState<sup>9+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of the **TLSSocket** connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                            | Description                                      |
|  ----------------------------------------------- |  ----------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
tls.getState().then(() => {
  console.log('getState success');
}).catch((err: BusinessError) => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>9+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of a **TCPSocket** connection after **bind** is successfully called. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of a **TCPSocket** connection. For details, see [TCPExtraOptions](#tcpextraoptions).|
| callback | AsyncCallback\<void\>                     | Yes  | Callback used to return the result. If the operation is successful, the result of setting other properties of a **TCPSocket** connection is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 401     | Parameter error.               |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

interface SocketLinger {
  on: boolean;
  linger: number;
}

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 } as SocketLinger,
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tls.setExtraOptions(tcpExtraOptions, (err: BusinessError) => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>9+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

Sets other properties of a **TCPSocket** connection after **bind** is successfully called. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                     | Mandatory| Description                                                        |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of a **TCPSocket** connection. For details, see [TCPExtraOptions](#tcpextraoptions).|

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 401     | Parameter error.               |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

interface SocketLinger {
  on: boolean;
  linger: number;
}

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 } as SocketLinger,
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tls.setExtraOptions(tcpExtraOptions).then(() => {
  console.log('setExtraOptions success');
}).catch((err: BusinessError) => {
  console.log('setExtraOptions fail');
});
```

### on('message')<sup>9+</sup>

on(type: 'message', callback: Callback\<SocketMessageInfo\>): void;

Subscribes to **message** events of a **TLSSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | Yes  | Callback used to return the result.  |

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 401     | Parameter error.               |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let messageView = '';
tls.on('message', (value: socket.SocketMessageInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let uint8Array = new Uint8Array(value.message) 
    let messages = uint8Array[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')<sup>9+</sup>

off(type: 'message', callback?: Callback\<SocketMessageInfo\>): void

Unsubscribes from **message** events of a **TLSSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | No  | Callback used to return the result.  |

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 401     | Parameter error.               |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let messageView = '';
let callback = (value: socket.SocketMessageInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let uint8Array = new Uint8Array(value.message) 
    let messages = uint8Array[i]
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

Subscribes to **connect** or **close** events of a **TLSSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Event type.<br>- **connect**: connection event.<br>- **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.                                                    |

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 401     | Parameter error.               |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.on('connect', () => {
  console.log("on connect success")
});
tls.on('close', () => {
  console.log("on close success")
});
```

### off('connect' | 'close')<sup>9+</sup>

off(type: 'connect' | 'close', callback?: Callback\<void\>): void

Unsubscribes from **connect** or **close** events of a **TLSSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                                                        |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | Yes  | Event type.<br>- **connect**: connection event.<br>- **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result.           |

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 401     | Parameter error.               |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
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

Subscribes to **error** events of a **TLSSocket** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result.         |

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 401     | Parameter error.               |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>9+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **TLSSocket** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result.                            |

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 401     | Parameter error.               |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tls.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tls.off('error', callback);
```

### connect<sup>9+</sup>

connect(options: TLSConnectOptions, callback: AsyncCallback\<void\>): void

Sets up a **TLSSocket** connection, and creates and initializes a TLS session after **bind** is successfully called. During this process, a TLS/SSL handshake is performed between the application and the server to implement data transmission. This API uses an asynchronous callback to return the result. Note that **ca** in **secureOptions** of the **options** parameter is mandatory. You need to enter the CA certificate of the server for certificate authentication. The certificate content starts with "-----BEGIN CERTIFICATE-----" and ends with "-----END CERTIFICATE-----".

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description|
| -------- | ---------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions9) | Yes  | Parameters required for the **TLSSocket** connection.|
| callback | AsyncCallback\<void\>                  | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303104 | Interrupted system call.                     |
| 2303109 | Bad file number.                             |
| 2303111 | Resource temporarily unavailable. Try again. |
| 2303188 | Socket operation on non-socket.              |
| 2303191 | Incorrect socket protocol type.              |
| 2303198 | Address already in use.                      |
| 2303199 | Cannot assign requested address.             |
| 2303210 | Connection timed out.                        |
| 2303501 | SSL is null.                                 |
| 2303502 | An error occurred when reading data on the TLS socket.|
| 2303503 | An error occurred when writing data on the TLS socket.|
| 2303505 | An error occurred in the TLS system call.    |
| 2303506 | Failed to close the TLS connection.          |
| 2300002 | System internal error.                       |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance();  // Two way authentication
let bindAddr: socket.NetAddress = {
  address: '0.0.0.0',
}
tlsTwoWay.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let twoWayNetAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let twoWaySecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: twoWayNetAddr,
  secureOptions: twoWaySecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}

tlsTwoWay.connect(tlsConnectOptions, (err: BusinessError) => {
  console.error("connect callback error" + err);
});

let tlsOneWay: socket.TLSSocket = socket.constructTLSSocketInstance(); // One way authentication
tlsOneWay.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let oneWayNetAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let oneWaySecureOptions: socket.TLSSecureOptions = {
  ca: ["xxxx", "xxxx"],
  cipherSuite: "AES256-SHA256"
}
let tlsOneWayConnectOptions: socket.TLSConnectOptions = {
  address: oneWayNetAddr,
  secureOptions: oneWaySecureOptions
}
tlsOneWay.connect(tlsOneWayConnectOptions, (err: BusinessError) => {
  console.error("connect callback error" + err);
});
```

### connect<sup>9+</sup>

connect(options: TLSConnectOptions): Promise\<void\>

Sets up a **TLSSocket** connection, and creates and initializes a TLS session after **bind** is successfully called. During this process, a TLS/SSL handshake is performed between the application and the server to implement data transmission. Both two-way and one-way authentication modes are supported. This API uses a promise to return the result. Note that **ca** in **secureOptions** of the **options** parameter is mandatory. You need to enter the CA certificate of the server for certificate authentication. The certificate content starts with "-----BEGIN CERTIFICATE-----" and ends with "-----END CERTIFICATE-----".

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
| 2303111 | Resource temporarily unavailable. Try again. |
| 2303188 | Socket operation on non-socket.              |
| 2303191 | Incorrect socket protocol type.              |
| 2303198 | Address already in use.                      |
| 2303199 | Cannot assign requested address.             |
| 2303210 | Connection timed out.                        |
| 2303501 | SSL is null.                                 |
| 2303502 | An error occurred when reading data on the TLS socket.|
| 2303503 | An error occurred when writing data on the TLS socket.|
| 2303505 | An error occurred in the TLS system call.    |
| 2303506 | Failed to close the TLS connection.          |
| 2300002 | System internal error.                       |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance();  // Two way authentication
let bindAddr: socket.NetAddress = {
  address: '0.0.0.0',
}
tlsTwoWay.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let twoWayNetAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let twoWaySecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: twoWayNetAddr,
  secureOptions: twoWaySecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}

tlsTwoWay.connect(tlsConnectOptions).then(() => {
  console.log("connect successfully");
}).catch((err: BusinessError) => {
  console.log("connect failed " + JSON.stringify(err));
});

let tlsOneWay: socket.TLSSocket = socket.constructTLSSocketInstance(); // One way authentication
tlsOneWay.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let oneWayNetAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let oneWaySecureOptions: socket.TLSSecureOptions = {
  ca: ["xxxx", "xxxx"],
  cipherSuite: "AES256-SHA256"
}
let tlsOneWayConnectOptions: socket.TLSConnectOptions = {
  address: oneWayNetAddr,
  secureOptions: oneWaySecureOptions
}
tlsOneWay.connect(tlsOneWayConnectOptions).then(() => {
  console.log("connect successfully");
}).catch((err: BusinessError) => {
  console.log("connect failed " + JSON.stringify(err));
});
```

### getRemoteAddress<sup>9+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

Obtains the remote address of a **TLSSocket** connection. This API uses an asynchronous callback to return the result.

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getRemoteAddress((err: BusinessError, data: socket.NetAddress) => {
  if (err) {
    console.log('getRemoteAddress fail');
    return;
  }
  console.log('getRemoteAddress success:' + JSON.stringify(data));
});
```

### getRemoteAddress<sup>9+</sup>

getRemoteAddress(): Promise\<NetAddress\>

Obtains the remote address of a **TLSSocket** connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                       | Description                                       |
|  ------------------------------------------ |  ------------------------------------------ |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getRemoteAddress().then(() => {
  console.log('getRemoteAddress success');
}).catch((err: BusinessError) => {
  console.log('getRemoteAddress fail');
});
```

### getCertificate<sup>9+</sup>

getCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

Obtains the local digital certificate after a **TLSSocket** connection is established. This API is applicable to two-way authentication. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description|
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>    | Yes  | Callback used to return the result. If the operation is successful, the local certificate is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303504 | An error occurred when verifying the X.509 certificate.|
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getCertificate((err: BusinessError, data: socket.X509CertRawData) => {
  if (err) {
    console.log("getCertificate callback error = " + err);
  } else {
    console.log("getCertificate callback = " + data);
  }
});
```

### getCertificate<sup>9+</sup>

getCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

Obtains the local digital certificate after a **TLSSocket** connection is established. This API is applicable to two-way authentication. It uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                 |
| -------------- | -------------------- |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303504 | An error occurred when verifying the X.509 certificate.|
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getCertificate().then((data: socket.X509CertRawData) => {
  const decoder = util.TextDecoder.create();
  const str = decoder.decodeWithStream(data.data);
  console.log("getCertificate: " + str);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### getRemoteCertificate<sup>9+</sup>

getRemoteCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

Obtains the digital certificate of the server after a **TLSSocket** connection is established. This API uses an asynchronous callback to return the result.

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getRemoteCertificate((err: BusinessError, data: socket.X509CertRawData) => {
  if (err) {
    console.log("getRemoteCertificate callback error = " + err);
  } else {
    const decoder = util.TextDecoder.create();
    const str = decoder.decodeWithStream(data.data);
    console.log("getRemoteCertificate callback = " + str);
  }
});
```

### getRemoteCertificate<sup>9+</sup>

getRemoteCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

Obtains the digital certificate of the server after a **TLSSocket** connection is established. This API uses a promise to return the result.

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getRemoteCertificate().then((data: socket.X509CertRawData) => {
  const decoder = util.TextDecoder.create();
  const str = decoder.decodeWithStream(data.data);
  console.log("getRemoteCertificate:" + str);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### getProtocol<sup>9+</sup>

getProtocol(callback: AsyncCallback\<string\>): void

Obtains the communication protocol version after a **TLSSocket** connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                      | Mandatory| Description          |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string\>                  | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | -----------------------------  |
| 2303501 | SSL is null.                   |
| 2303505 | An error occurred in the TLS system call. |
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getProtocol((err: BusinessError, data: string) => {
  if (err) {
    console.log("getProtocol callback error = " + err);
  } else {
    console.log("getProtocol callback = " + data);
  }
});
```

### getProtocol<sup>9+</sup>

getProtocol():Promise\<string\>

Obtains the communication protocol version after a **TLSSocket** connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                 |
| -------------- | -------------------- |
| Promise\<string\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303505 | An error occurred in the TLS system call. |
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getProtocol().then((data: string) => {
  console.log(data);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### getCipherSuite<sup>9+</sup>

getCipherSuite(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the cipher suite negotiated by both communication parties after a **TLSSocket** connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description|
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string\>\>          | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303502 | An error occurred when reading data on the TLS socket.|
| 2303505 | An error occurred in the TLS system call. |
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getCipherSuite((err: BusinessError, data: Array<string>) => {
  if (err) {
    console.log("getCipherSuite callback error = " + err);
  } else {
    console.log("getCipherSuite callback = " + data);
  }
});
```

### getCipherSuite<sup>9+</sup>

getCipherSuite(): Promise\<Array\<string\>\>

Obtains the cipher suite negotiated by both communication parties after a **TLSSocket** connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                   | Description                 |
| ---------------------- | --------------------- |
| Promise\<Array\<string\>\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303502 | An error occurred when reading data on the TLS socket.|
| 2303505 | An error occurred in the TLS system call. |
| 2300002 | System internal error.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getCipherSuite().then((data: Array<string>) => {
  console.log('getCipherSuite success:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### getSignatureAlgorithms<sup>9+</sup>

getSignatureAlgorithms(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the signing algorithm negotiated by both communication parties after a **TLSSocket** connection is established. This API is applicable to two-way authentication. It uses an asynchronous callback to return the result.

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getSignatureAlgorithms((err: BusinessError, data: Array<string>) => {
  if (err) {
    console.log("getSignatureAlgorithms callback error = " + err);
  } else {
    console.log("getSignatureAlgorithms callback = " + data);
  }
});
```

### getSignatureAlgorithms<sup>9+</sup>

getSignatureAlgorithms(): Promise\<Array\<string\>\>

Obtains the signing algorithm negotiated by both communication parties after a **TLSSocket** connection is established. This API is applicable to two-way authentication. It uses a promise to return the result.

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getSignatureAlgorithms().then((data: Array<string>) => {
  console.log("getSignatureAlgorithms success" + data);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<NetAddress\>

Obtains the local socket address of a **TLSSocket** connection. This API uses a promise to return the result.

> **NOTE**
> Call this API only after the **TLSSocketServer** connection is successfully established.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getLocalAddress().then((localAddress: socket.NetAddress) => {
  console.info("Get success: " + JSON.stringify(localAddress));
}).catch((err: BusinessError) => {
  console.error("Get failed, error: " + JSON.stringify(err));
})
```

### send<sup>9+</sup>

send(data: string \| ArrayBuffer, callback: AsyncCallback\<void\>): void

Sends a message to the server after a **TLSSocket** connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type                         | Mandatory| Description           |
| -------- | -----------------------------| ---- | ---------------|
|   data   | string \| ArrayBuffer                      | Yes  | Data content of the message to send.  |
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303501 | SSL is null.                                 |
| 2303503 | An error occurred when writing data on the TLS socket.|
| 2303505 | An error occurred in the TLS system call.    |
| 2303506 | Failed to close the TLS connection.          |
| 2300002 | System internal error.                       |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.send("xxxx", (err: BusinessError) => {
  if (err) {
    console.log("send callback error = " + err);
  } else {
    console.log("send success");
  }
});
```

### send<sup>9+</sup>

send(data: string \| ArrayBuffer): Promise\<void\>

Sends a message to the server after a **TLSSocket** connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type                         | Mandatory| Description           |
| -------- | -----------------------------| ---- | ---------------|
|   data   | string \| ArrayBuffer                       | Yes  | Data content of the message to send.  |

**Error codes**

| ID| Error Message                                     |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303501 | SSL is null.                                 |
| 2303503 | An error occurred when writing data on the TLS socket.|
| 2303505 | An error occurred in the TLS system call.    |
| 2303506 | Failed to close the TLS connection.          |
| 2300002 | System internal error.                       |

**Return value**

| Type          | Description                 |
| -------------- | -------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.send("xxxx").then(() => {
  console.log("send success");
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### close<sup>9+</sup>

close(callback: AsyncCallback\<void\>): void

Closes a **TLSSocket** connection. This API uses an asynchronous callback to return the result.

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
| 2303505 | An error occurred in the TLS system call.    |
| 2303506 | Failed to close the TLS connection.          |
| 2300002 | System internal error.                       |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.close((err: BusinessError) => {
  if (err) {
    console.log("close callback error = " + err);
  } else {
    console.log("close success");
  }
});
```

### close<sup>9+</sup>

close(): Promise\<void\>

Closes a **TLSSocket** connection. This API uses a promise to return the result.

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
| 2303505 | An error occurred in the TLS system call.    |
| 2303506 | Failed to close the TLS connection.          |
| 2300002 | System internal error.                       |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.close().then(() => {
  console.log("close success");
}).catch((err: BusinessError) => {
  console.error("failed" + err);
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
| skipRemoteValidation  | boolean                         | No| Whether to perform certificate authentication on the server. The default value is **false**.     |

## TLSSecureOptions<sup>9+</sup>

TLS security options. When **cert** (local certificate) and **key** (private key) are not empty, the two-way authentication mode is enabled. If **cert** or **key** is empty, one-way authentication is enabled.

**System capability**: SystemCapability.Communication.NetStack

| Name                | Type                                                   | Mandatory| Description                               |
| --------------------- | ------------------------------------------------------ | --- |----------------------------------- |
| ca                    | string \| Array\<string\> | No| CA certificate of the server, which is used to authenticate the digital certificate of the server. The default value is the preset CA certificate<sup>12+</sup>.|
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
|  ------------------------------------ |  ---------------------------- |
| [TLSSocketServer](#tlssocketserver10) | **TLSSocketServer** connection.|

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
```

## TLSSocketServer<sup>10+</sup>

Defines a **TLSSocketServer** connection. Before calling **TLSSocketServer** APIs, you need to call [socket.constructTLSSocketServerInstance](#socketconstructtlssocketserverinstance10) to create a **TLSSocketServer** object.

### listen<sup>10+</sup>

listen(options: TLSConnectOptions, callback: AsyncCallback\<void\>): void

Listens to client connections after **bind** is successfully called. This API uses an asynchronous callback to return the result. After a connection is established, a TLS session will be created and initialized and a certificate key will be loaded and verified. 

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description                                            |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------ |
| options  | [TLSConnectOptions](#tlsconnectoptions9) | Yes  | Parameters required for the connection.               |
| callback | AsyncCallback\<void\>                     | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable. Try again.|
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |
| 2303501  | SSL is null.                                |
| 2303502  | An error occurred when reading data on the TLS socket.|
| 2303503  | An error occurred when writing data on the TLS socket.|
| 2303505  | An error occurred in the TLS system call.   |
| 2303506  | Failed to close the TLS connection.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"],
  skipRemoteValidation: false
}
tlsServer.listen(tlsConnectOptions, (err: BusinessError) => {
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
| 2303111  | Resource temporarily unavailable. Try again.|
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |
| 2303501  | SSL is null.                                |
| 2303502  | An error occurred when reading data on the TLS socket.|
| 2303503  | An error occurred when writing data on the TLS socket.|
| 2303505  | An error occurred in the TLS system call.   |
| 2303506  | Failed to close the TLS connection.         |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"],
  skipRemoteValidation: false
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
```

### getState<sup>10+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

Obtains the status of the **TLSSocketServer** connection upon successful listening. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase)\> | Yes  | Callback used to return the result. If the operation is successful, the status of the **TLSSocketServer** connection is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getState((err: BusinessError, data: socket.SocketStateBase) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
});
```

### getState<sup>10+</sup>

getState(): Promise\<SocketStateBase\>

Obtains the status of the **TLSSocketServer** connection upon successful listening. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                          | Description                                                        |
|  --------------------------------------------- |  ----------------------------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getState().then(() => {
  console.log('getState success');
}).catch((err: BusinessError) => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

Sets other properties of the **TLSSocketServer** connection upon successful listening. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                | Mandatory| Description                                            |
| -------- | ------------------------------------ | ---- | ------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of the **TLSSocketServer** connection.                 |
| callback | AsyncCallback\<void\>                | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});

interface SocketLinger {
  on: boolean;
  linger: number;
}

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 } as SocketLinger,
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tlsServer.setExtraOptions(tcpExtraOptions, (err: BusinessError) => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

Sets other properties of the **TLSSocketServer** connection upon successful listening. This API uses a promise to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                                | Mandatory| Description                           |
| ------- | ------------------------------------ | ---- | ------------------------------- |
| options | [TCPExtraOptions](#tcpextraoptions) | Yes  | Other properties of the **TLSSocketServer** connection.|

**Return value**

| Type           | Description                                                     |
|  -------------- |  -------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});

interface SocketLinger {
  on: boolean;
  linger: number;
}

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 } as SocketLinger,
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tlsServer.setExtraOptions(tcpExtraOptions).then(() => {
  console.log('setExtraOptions success');
}).catch((err: BusinessError) => {
  console.log('setExtraOptions fail');
});
```

### getCertificate<sup>10+</sup>

getCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

Obtains the local digital certificate after a **TLSSocketServer** connection is established. This API uses an asynchronous callback to return the result.

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
| 2303504  | An error occurred when verifying the X.509 certificate. |
| 2300002  | System internal error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getCertificate((err: BusinessError, data: socket.X509CertRawData) => {
  if (err) {
    console.log("getCertificate callback error = " + err);
  } else {
    const decoder = util.TextDecoder.create();
    const str = decoder.decodeWithStream(data.data);
    console.log("getCertificate callback: " + str);
  }
});
```

### getCertificate<sup>10+</sup>

getCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

Obtains the local digital certificate after a **TLSSocketServer** connection is established. This API uses a promise to return the result.

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
| 2303504  | An error occurred when verifying the X.509 certificate. |
| 2300002  | System internal error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getCertificate().then((data: socket.X509CertRawData) => {
  const decoder = util.TextDecoder.create();
  const str = decoder.decodeWithStream(data.data);
  console.log("getCertificate: " + str);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### getProtocol<sup>10+</sup>

getProtocol(callback: AsyncCallback\<string\>): void

Obtains the communication protocol version after a **TLSSocketServer** connection is established. This API uses an asynchronous callback to return the result.

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
| 2303505  | An error occurred in the TLS system call. |
| 2300002  | System internal error.                 |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getProtocol((err: BusinessError, data: string) => {
  if (err) {
    console.log("getProtocol callback error = " + err);
  } else {
    console.log("getProtocol callback = " + data);
  }
});
```

### getProtocol<sup>10+</sup>

getProtocol():Promise\<string\>

Obtains the communication protocol version after a **TLSSocketServer** connection is established. This API uses a promise to return the result.

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
| 2303505  | An error occurred in the TLS system call. |
| 2300002  | System internal error.                 |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getProtocol().then((data: string) => {
  console.log(data);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<NetAddress\>

Obtains the local socket address of a **TLSSocketServer** connection. This API uses a promise to return the result.

> **NOTE**
> Call this API only after the **TLSSocketServer** connection is successfully established.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocket = socket.constructTLSSocketServerInstance();
tlsServer.getLocalAddress().then((localAddress: socket.NetAddress) => {
  console.info("Get success: " + JSON.stringify(localAddress));
}).catch((err: BusinessError) => {
  console.error("Get failed, error: " + JSON.stringify(err));
})
```

### on('connect')<sup>10+</sup>

on(type: 'connect', callback: Callback\<TLSSocketConnection\>): void

Subscribes to **TLSSocketServer** connection events. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                 |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------- |
| type     | string                                                  | Yes  | Event type.<br/> **connect**: connection event.|
| callback | Callback\<[TLSSocketConnection](#tlssocketconnection10)\> | Yes  | Callback used to return the result. If the operation fails, an error message is returned.   |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.on('connect', (data: socket.TLSSocketConnection) => {
  console.log(JSON.stringify(data))
});
```

### off('connect')<sup>10+</sup>

off(type: 'connect', callback?: Callback\<TLSSocketConnection\>): void

Unsubscribes from **connect** events of a **TLSSocketServer** object. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API can be called only after **listen** is successfully called.
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                 |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------- |
| type     | string                                                  | Yes  | Event type.<br/> **connect**: connection event.|
| callback | Callback\<[TLSSocketConnection](#tlssocketconnection10)\> | No  | Callback used to return the result. If the operation fails, an error message is returned.     |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});

let callback = (data: socket.TLSSocketConnection) => {
  console.log('on connect message: ' + JSON.stringify(data));
}
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
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result. If the operation fails, an error message is returned.    |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.on('error', (err: BusinessError) => {
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
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result. If the operation fails, an error message is returned.    |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});

let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tlsServer.on('error', callback);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
tlsServer.off('error', callback);
tlsServer.off('error');
```

## TLSSocketConnection<sup>10+</sup>

Defines a **TLSSocketConnection** object, that is, the connection between the **TLSSocket** client and the server. Before calling **TLSSocketConnection** APIs, you need to obtain a **TLSSocketConnection** object.

> **NOTE**
> The client can call related APIs through the **TLSSocketConnection** object only after a connection is successfully established between the client and the server.

**System capability**: SystemCapability.Communication.NetStack

### Attributes

| Name    | Type  | Mandatory| Description                                 |
| -------- | ------ | ---- | ------------------------------------- |
| clientId | number | Yes  | ID of the connection between the client and TLSSocketServer.|

### send<sup>10+</sup>

send(data: string \| ArrayBuffer, callback: AsyncCallback\<void\>): void

Sends a message to the client after a **TLSSocketServer** connection is established. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                 | Mandatory| Description                                            |
| -------- | --------------------- | ---- | ------------------------------------------------ |
| data     | string \| ArrayBuffer                | Yes  | Parameters for sending data over a **TLSSocketServer** connection.           |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303503  | An error occurred when writing data on the TLS socket.|
| 2303505  | An error occurred in the TLS system call.|
| 2303506  | Failed to close the TLS connection.    |
| 2300002  | System internal error.                 |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.send('Hello, client!', (err: BusinessError) => {
    if (err) {
      console.log('send fail');
      return;
    }
    console.log('send success');
  });
});
```

### send<sup>10+</sup>

send(data: string \| ArrayBuffer): Promise\<void\>

Sends a message to the server after a **TLSSocketServer** connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name| Type  | Mandatory| Description                                 |
| ------ | ------ | ---- | ------------------------------------- |
| data   | string \| ArrayBuffer | Yes  | Parameters for sending data over a **TLSSocketServer** connection.|

**Return value**

| Type           | Description                                                     |
| --------------- | --------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303503  | An error occurred when writing data on the TLS socket.|
| 2303505  | An error occurred in the TLS system call.|
| 2303506  | Failed to close the TLS connection.    |
| 2300002  | System internal error.                 |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.send('Hello, client!').then(() => {
    console.log('send success');
  }).catch((err: BusinessError) => {
    console.log('send fail');
  });
});
```

### close<sup>10+</sup>

close(callback: AsyncCallback\<void\>): void

Closes a **TLSSocketServer** connection. This API uses an asynchronous callback to return the result.

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
| 2303505  | An error occurred in the TLS system call. |
| 2303506  | Failed to close the TLS connection.    |
| 2300002  | System internal error.                 |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.close((err: BusinessError) => {
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

Closes a **TLSSocketServer** connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                     |
| --------------- | --------------------------------------------------------- |
| Promise\<void\> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 2303501  | SSL is null.                           |
| 2303505  | An error occurred in the TLS system call. |
| 2303506  | Failed to close the TLS connection.    |
| 2300002  | System internal error.                 |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.close().then(() => {
    console.log('close success');
  }).catch((err: BusinessError) => {
    console.log('close fail');
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

Obtains the remote address of a **TLSSocketServer** connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[NetAddress](#netaddress)\> | Yes  | Callback used to return the result. If the operation is successful, the remote address is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getRemoteAddress((err: BusinessError, data: socket.NetAddress) => {
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

Obtains the remote address of a **TLSSocketServer** connection. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                                | Description                                                        |
|  ----------------------------------- |  ----------------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getRemoteAddress().then((data: socket.NetAddress) => {
    console.log('getRemoteAddress success:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error("failed" + err);
  });
});
```

### getRemoteCertificate<sup>10+</sup>

getRemoteCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

Obtains the digital certificate of the peer end after a **TLSSocketServer** connection is established. This API uses an asynchronous callback to return the result. It applies only to the scenario where the client sends a certificate to the server. 

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getRemoteCertificate((err: BusinessError, data: socket.X509CertRawData) => {
    if (err) {
      console.log("getRemoteCertificate callback error: " + err);
    } else {
      const decoder = util.TextDecoder.create();
      const str = decoder.decodeWithStream(data.data);
      console.log("getRemoteCertificate callback: " + str);
    }
  });
});
```

### getRemoteCertificate<sup>10+</sup>

getRemoteCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

Obtains the digital certificate of the peer end after a **TLSSocketServer** connection is established. This API uses a promise to return the result. It applies only to the scenario where the client sends a certificate to the server. 

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getRemoteCertificate().then((data: socket.X509CertRawData) => {
    const decoder = util.TextDecoder.create();
    const str = decoder.decodeWithStream(data.data);
    console.log("getRemoteCertificate success: " + str);
  }).catch((err: BusinessError) => {
    console.error("failed" + err);
  });
});
```

### getCipherSuite<sup>10+</sup>

getCipherSuite(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the cipher suite negotiated by both communication parties after a **TLSSocketServer** connection is established. This API uses an asynchronous callback to return the result.

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
| 2303502  | An error occurred when reading data on the TLS socket.|
| 2303505  | An error occurred in the TLS system call.|
| 2300002  | System internal error.                 |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getCipherSuite((err: BusinessError, data: Array<string>) => {
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

Obtains the cipher suite negotiated by both communication parties after a **TLSSocketServer** connection is established. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                      | Description                                                        |
| -------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<string\>\> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 2303501  | SSL is null.                           |
| 2303502  | An error occurred when reading data on the TLS socket.|
| 2303505  | An error occurred in the TLS system call. |
| 2300002  | System internal error.                 |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getCipherSuite().then((data: Array<string>) => {
    console.log('getCipherSuite success:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error("failed" + err);
  });
});
```

### getSignatureAlgorithms<sup>10+</sup>

getSignatureAlgorithms(callback: AsyncCallback\<Array\<string\>\>): void

Obtains the signing algorithm negotiated by both communication parties after a **TLSSocketServer** connection is established. This API uses an asynchronous callback to return the result.

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getSignatureAlgorithms((err: BusinessError, data: Array<string>) => {
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

Obtains the signing algorithm negotiated by both communication parties after a **TLSSocketServer** connection is established. This API uses a promise to return the result.

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

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getSignatureAlgorithms().then((data: Array<string>) => {
    console.log("getSignatureAlgorithms success" + data);
  }).catch((err: BusinessError) => {
    console.error("failed" + err);
  });
});
```

### getLocalAddress<sup>12+</sup>

getLocalAddress(): Promise\<NetAddress\>

Obtains the local socket address of a **TLSSocketConnection** connection. This API uses a promise to return the result.

> **NOTE**
> Call this API only after the **TLSSocketServer** connection is successfully established.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                                                |
|  -------------- |  --------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 2300002  | System internal error.                      |
| 2303109  | Bad file descriptor.                            |
| 2303188  | Socket operation on non-socket. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.info("listen callback success");
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  tls.getLocalAddress().then((localAddress: socket.NetAddress) => {
    console.info("Family IP Port: " + JSON.stringify(localAddress));
  }).catch((err: BusinessError) => {
    console.error("TLS Client Get Family IP Port failed, error: " + JSON.stringify(err));
  })
});
```

### on('message')<sup>10+</sup>

on(type: 'message', callback: Callback\<SocketMessageInfo\>): void

Subscribes to **message** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | Yes  | Callback used to return the result. If the operation is successful, the **TLSSocket** connection information is returned. If the operation fails, an error message is returned.                              |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('message', (value: socket.SocketMessageInfo) => {
    let messageView = '';
    for (let i: number = 0; i < value.message.byteLength; i++) {
      let uint8Array = new Uint8Array(value.message) 
      let messages = uint8Array[i]
      let message = String.fromCharCode(messages);
      messageView += message;
    }
    console.log('on message message: ' + JSON.stringify(messageView));
    console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
  });
});
```

### off('message')<sup>10+</sup>

off(type: 'message', callback?: Callback\<SocketMessageInfo\>): void

Unsubscribes from **message** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | Yes  | Event type.<br/> **message**: message receiving event.|
| callback | Callback\<[SocketMessageInfo](#socketmessageinfo11)\> | No  | Callback used to return the result. If the operation is successful, the **TLSSocket** connection information is returned. If the operation fails, an error message is returned. |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

let callback = (value: socket.SocketMessageInfo) => {
  let messageView = '';
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let uint8Array = new Uint8Array(value.message) 
    let messages = uint8Array[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
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
| type     | string           | Yes  | Event type.<br/> **close**: close event.|
| callback | Callback\<void\> | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.   |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('close', () => {
    console.log("on close success")
  });
});
```

### off('close')<sup>10+</sup>

off(type: 'close', callback?: Callback\<void\>): void

Unsubscribes from **close** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type            | Mandatory| Description                               |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | Yes  | Event type.<br/> **close**: close event.|
| callback | Callback\<void\> | No  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.                        |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

let callback = () => {
  console.log("on close success");
}
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
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
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.                       |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('error', (err: BusinessError) => {
    console.log("on error, err:" + JSON.stringify(err))
  });
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **error** events of a **TLSSocketConnection** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type.<br/> **error**: error event.|
| callback | ErrorCallback | No  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.                       |

**Error codes**

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. |

**Example**

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let netAddress: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
let tlsSecureOptions: socket.TLSSecureOptions = {
  key: "xxxx",
  cert: "xxxx",
  ca: ["xxxx"],
  password: "xxxx",
  protocols: socket.Protocol.TLSv12,
  useRemoteCipherPrefer: true,
  signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
  cipherSuite: "AES256-SHA256"
}
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: netAddress,
  secureOptions: tlsSecureOptions,
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('error', callback);
  // You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
  client.off('error', callback);
  client.off('error');
});
```
