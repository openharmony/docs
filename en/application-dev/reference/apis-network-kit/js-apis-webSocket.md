# # @ohos.net.webSocket (WebSocket Connection)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **webSocket** module implements bidirectional connections between the WebSocket client and WebSocket server for third-party applications. Currently, the WebSocket server is available only for smart TVs.

On the WebSocket client: You can use WebSocket to establish a bidirectional connection between the server and client. Before doing this, you need to use the [createWebSocket](#websocketcreatewebsocket6) API to create a [WebSocket](#websocket6) object and then use the [connect](#connect6) API to connect to the server. If the connection is successful, the client will receive a callback of the [open](#onopen6) event. Then, the client can communicate with the server using the [send](#send6) API. When the server sends a message to the client, the client will receive a callback of the [message](#onmessage6) event. If the connection is no longer needed, the client can call the [close](#close6) API to close the connection. After successful disconnection, the client will receive a callback of the [close](#onclose6) event. If an error occurs in any of the preceding processes, the client will receive a callback of the [error](#onerror6) event.

On the WebSocket server: You can use WebSocket to establish a bidirectional connection between the server and client. Before doing this, you need to use the [createWebSocketServer](#websocketcreatewebsocketserver19) API to create a [WebSocketServer](#websocketserver19) object and then use the [start](#start19) API to start the server to listen for connection requests from the client. If the connection is successful, the server receives the callback of the [connect](#onconnect19) event. The server can then communicate with the client by using the [send](#send19) API or obtain information about all connected clients by using the [listAllConnections](#listallconnections19) API. When the client sends a message to the server, the server receives the callback of the [messageReceive](#onmessagereceive19) event. If the connection is no longer needed, the server can call the [close](#close19) API to close the connection. After successful disconnection, the server will receive a callback of the [close](#onclose19) event. To stop the service, the server can use the [stop](#stop19) API. If an error occurs in any of the preceding processes, the server will receive a callback of the [error](#onerror19) event.

## Modules to Import

```ts
import { webSocket } from '@kit.NetworkKit';
```

## webSocket.createWebSocket<sup>6+</sup>

createWebSocket(): WebSocket

Creates a **WebSocket** object, which provides methods to create or close a WebSocket connection, send data over the connection, and enable or disable listening for the **open**, **close**, **message**, and **error** events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                               | Description                                                        |
| :---------------------------------- | :----------------------------------------------------------- |
| [WebSocket](#websocket6) | A **WebSocket** object, which contains the **connect**, **send**, **close**, **on**, or **off** method.|

**Example**

```ts
let ws: webSocket.WebSocket = webSocket.createWebSocket();
```

## WebSocket<sup>6+</sup>

Defines a **WebSocket** object. Before invoking WebSocket APIs, you need to call [webSocket.createWebSocket](#websocketcreatewebsocket6) to create a **WebSocket** object.

### connect<sup>6+</sup>

connect(url: string, callback: AsyncCallback\<boolean\>): void

Initiates a WebSocket request to establish a WebSocket connection to a given URL. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can listen to **error** events to obtain the operation result. 

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Note**: The URL cannot contain more than 1024 characters. Otherwise, the connection fails. Since API version 15, the maximum length of URLs is changed from 1024 characters to 2048 characters.

**Parameters**

| Name  | Type                    | Mandatory| Description                        |
| -------- | ------------------------ | ---- | ---------------------------- |
| url      | string                   | Yes  | URL for establishing a WebSocket connection.|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.                  |

**Error codes**

For details about the error codes, see [webSocket Error Codes](errorcode-net-webSocket.md) and [Universal Error Codes](../errorcode-universal.md).

| ID             | Error Message                                  |
| --------------------- | ------------------------------------------ |
| 401                   | Parameter error.                           |
| 201                   | Permission denied.                         |
| 2302001               | Websocket url error.                       |
| 2302002               | Websocket certificate file does not exist. |
| 2302003               | Websocket connection already exists.       |
| 2302998               | It is not allowed to access this domain.   |
| 2302999               | Internal error.             |


**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
let url = "ws://";
ws.connect(url, (err: BusinessError, value: boolean) => {
  if (!err) {
    console.info("connect success")
  } else {
    console.error(`connect fail. Code: ${err.code}, message: ${err.message}`)
  }
});
```

### connect<sup>6+</sup>

connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean\>): void

Initiates a WebSocket request to establish a WebSocket connection to a given URL. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can listen to **error** events to obtain the operation result. If an error occurs, the error code 200 will be returned.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Note**: The URL cannot contain more than 1024 characters. Otherwise, the connection fails.

**Parameters**

| Name  | Type                    | Mandatory| Description                                                   |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| url      | string                   | Yes  | URL for establishing a WebSocket connection.                           |
| options  | WebSocketRequestOptions  | Yes  | Request options. For details, see [WebSocketRequestOptions](#websocketrequestoptions).|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.                                             |

**Error codes**

For details about the error codes, see [webSocket Error Codes](errorcode-net-webSocket.md) and [Universal Error Codes](../errorcode-universal.md).

| ID             | Error Message                                  |
| --------------------- | ------------------------------------------ |
| 401                   | Parameter error.                           |
| 201                   | Permission denied.                         |
| 2302001               | Websocket url error.                       |
| 2302002               | Websocket certificate file does not exist. |
| 2302003               | Websocket connection already exists.       |
| 2302998               | It is not allowed to access this domain.   |
| 2302999               | Internal error.             |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
let options: webSocket.WebSocketRequestOptions | undefined;
if (options !=undefined) {
  options.header = {
     name1: "value1",
     name2: "value2",
     name3: "value3"
  };
  options.caPath = "";
}
let url = "ws://"
ws.connect(url, options, (err: BusinessError, value: Object) => {
  if (!err) {
    console.info("connect success")
  } else {
    console.error(`connect fail. Code: ${err.code}, message: ${err.message}`)
  }
});
```

### connect<sup>6+</sup>

connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean\>

Establishes a WebSocket connection to a given URL. This API uses a promise to return the result.

> **NOTE**
>
> You can listen to **error** events to obtain the operation result. If an error occurs, the error code 200 will be returned.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Note**: The URL cannot contain more than 1024 characters. Otherwise, the connection fails.

**Parameters**

| Name | Type                   | Mandatory| Description                                                   |
| ------- | ----------------------- | ---- | ------------------------------------------------------- |
| url     | string                  | Yes  | URL for establishing a WebSocket connection.                           |
| options | WebSocketRequestOptions | No  | Request options. For details, see [WebSocketRequestOptions](#websocketrequestoptions).|

**Return value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Callback used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [webSocket Error Codes](errorcode-net-webSocket.md) and [Universal Error Codes](../errorcode-universal.md).

| ID             | Error Message                                  |
| --------------------- | ------------------------------------------ |
| 401                   | Parameter error.                           |
| 201                   | Permission denied.                         |
| 2302001               | Websocket url error.                       |
| 2302002               | Websocket certificate file does not exist. |
| 2302003               | Websocket connection already exists.       |
| 2302998               | It is not allowed to access this domain.   |
| 2302999               | Internal error.             |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
let url = "ws://"
let promise = ws.connect(url);
promise.then((value: boolean) => {
  console.info("connect success")
}).catch((err:string) => {
  console.error("connect fail, error:" + JSON.stringify(err))
});
```

### send<sup>6+</sup>

send(data: string | ArrayBuffer, callback: AsyncCallback\<boolean\>): void

Sends data through a WebSocket connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description        |
| -------- | ------------------------ | ---- | ------------ |
| data     | string \| ArrayBuffer | Yes  | Data to send.<br>Only the string type is supported for API version 6 or earlier. Both the string and ArrayBuffer types are supported for API version 8 or later.|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
let url = "ws://"
class OutValue {
  status: number = 0
  message: string = ""
}
ws.connect(url, (err: BusinessError, value: boolean) => {
    if (!err) {
      console.info("connect success")
    } else {
      console.error(`connect fail. Code: ${err.code}, message: ${err.message}`)
    }
});
ws.on('open', (err: BusinessError, value: Object) => {
  console.info("on open, status:" + (value as OutValue).status + ", message:" + (value as OutValue).message)
    ws.send("Hello, server!", (err: BusinessError, value: boolean) => {
    if (!err) {
      console.info("send success")
    } else {
      console.error(`send fail. Code: ${err.code}, message: ${err.message}`)
    }
  });
});
```

> **NOTE**
>
> The **send** API can be called only after an **open** event is listened.

### send<sup>6+</sup>

send(data: string | ArrayBuffer): Promise\<boolean\>

Sends data through the WebSocket connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| data     | string \| ArrayBuffer | Yes  | Data to send.<br>Only the string type is supported for API version 6 or earlier. Both the string and ArrayBuffer types are supported for API version 8 or later.|

**Return value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
let url = "ws://"
class OutValue {
  status: number = 0
  message: string = ""
}
ws.connect(url, (err: BusinessError, value: boolean) => {
    if (!err) {
      console.info("connect success")
    } else {
      console.error("connect fail. Code: ${err.code}, message: ${err.message}")
    }
});

ws.on('open', (err: BusinessError, value: Object) => {
  console.info("on open, status:" + (value as OutValue).status + ", message:" + (value as OutValue).message)
  let promise = ws.send("Hello, server!");
  promise.then((value: boolean) => {
    console.info("send success")
  }).catch((err:string) => {
    console.error("send fail, error:" + JSON.stringify(err))
  });
});
```

> **NOTE**
>
> The **send** API can be called only after an **open** event is listened.

### close<sup>6+</sup>

close(callback: AsyncCallback\<boolean\>): void

Closes a WebSocket connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description      |
| -------- | ------------------------ | ---- | ---------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
ws.close((err: BusinessError) => {
  if (!err) {
    console.info("close success")
  } else {
    console.error(`close fail. Code: ${err.code}, message: ${err.message}`)
  }
});
```

### close<sup>6+</sup>

close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean\>): void

Closes a WebSocket connection based on the specified **options**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description                                                 |
| -------- | ------------------------ | ---- | ----------------------------------------------------- |
| options  | WebSocketCloseOptions    | Yes  | Request options. For details, see [WebSocketCloseOptions](#websocketcloseoptions).|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.                                           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();

let options: webSocket.WebSocketCloseOptions | undefined;
if (options != undefined) {
    options.code = 1000
    options.reason = "your reason"
}
ws.close(options, (err: BusinessError) => {
    if (!err) {
        console.info("close success")
    } else {
        console.error(`close fail. Code: ${err.code}, message: ${err.message}`)
    }
});
```

### close<sup>6+</sup>

close(options?: WebSocketCloseOptions): Promise\<boolean\>

Closes a WebSocket connection based on the specified options. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                 | Mandatory| Description                                                 |
| ------- | --------------------- | ---- | ----------------------------------------------------- |
| options | WebSocketCloseOptions | No  | Request options. For details, see [WebSocketCloseOptions](#websocketcloseoptions).|

**Return value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
let options: webSocket.WebSocketCloseOptions | undefined;
if (options != undefined) {
    options.code = 1000
    options.reason = "your reason"
}
let promise = ws.close();
promise.then((value: boolean) => {
    console.info("close success")
}).catch((err:string) => {
    console.error("close fail, error:" + JSON.stringify(err))
});
```

### on('open')<sup>6+</sup>

on(type: 'open', callback: AsyncCallback\<Object\>): void

Enables listening for the **open** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                         |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | Yes  | Event type.<br/> **open**: event indicating that a WebSocket connection has been opened.|
| callback | AsyncCallback\<Object\> | Yes  | Callback used to return the result.                   |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let ws= webSocket.createWebSocket();
class OutValue {
  status: number = 0
  message: string = ""
}
ws.on('open', (err: BusinessError, value: Object) => {
  console.info("on open, status:" + (value as OutValue).status + ", message:" + (value as OutValue).message)
});
```

### off('open')<sup>6+</sup>

off(type: 'open', callback?: AsyncCallback\<Object\>): void

Disables listening for the **open** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                         |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | Yes  | Type of the event to unsubscribe from. Event type. <br />**open**: event indicating that a WebSocket connection has been opened.|
| callback | AsyncCallback\<Object\> | No  | Callback used to return the result.                   |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
class OutValue {
  status: number = 0
  message: string = ""
}
let callback1 = (err: BusinessError, value: Object) => {
 console.info("on open, status:" + ((value as OutValue).status + ", message:" + (value as OutValue).message))
}
ws.on('open', callback1);
// You can pass the callback of the on function if you want to cancel listening for a certain type of events. If you do not pass the callback, you will cancel listening for all events.
ws.off('open', callback1);
```

### on('message')<sup>6+</sup>

on(type: 'message', callback: AsyncCallback\<string | ArrayBuffer\>): void

Enables listening for the **message** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The data in **AsyncCallback** can be in the format of string (API version 6) or ArrayBuffer (API version 8).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                                        |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | Yes  | Event type.<br/> **message**: event indicating that a message has been received from the server.|
| callback | AsyncCallback\<string \| ArrayBuffer <sup>8+</sup>\> | Yes  | Callback used to return the result.                                  |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
ws.on('message', (err: BusinessError<void>, value: string | ArrayBuffer) => {
  console.info("on message, message:" + value)
});
```

### off('message')<sup>6+</sup>

off(type: 'message', callback?: AsyncCallback\<string | ArrayBuffer\>): void

Disables listening for the **message** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The data in **AsyncCallback** can be in the format of string (API version 6) or ArrayBuffer (API version 8).
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                               | Mandatory| Description                                        |
| -------- | --------------------------------------------------- | ---- | -------------------------------------------- |
| type     | string                                              | Yes  | Type of the event to unsubscribe from. **message**: event indicating that a message has been received from the server.|
| callback | AsyncCallback\<string \|ArrayBuffer <sup>8+</sup>\> | No  | Callback used to return the result.                                  |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('message');
```

### on('close')<sup>6+</sup>

on(type: 'close', callback: AsyncCallback\<CloseResult\>): void

Enables listening for the **close** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                           | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | Yes  | Event type.<br/> **close**: event indicating that a WebSocket connection has been closed.|
| callback | AsyncCallback\<CloseResult\> | Yes  | Callback used to return the result.<br>**close** and **reason** indicate the error code and error cause for closing the connection, respectively.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
ws.on('close', (err: BusinessError, value: webSocket.CloseResult) => {
  console.info("on close, code is " + value.code + ", reason is " + value.reason)
});
```

### off('close')<sup>6+</sup>

off(type: 'close', callback?: AsyncCallback\<CloseResult\>): void

Disables listening for the **close** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                           | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | Yes  | Type of the event to unsubscribe from. Event type. <br />**close**: event indicating that a WebSocket connection has been closed.|
| callback | AsyncCallback\<CloseResult\> | No  | Callback used to return the result.<br>**close** and **reason** indicate the error code and error cause for closing the connection, respectively.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('close');
```

### on('error')<sup>6+</sup>

on(type: 'error', callback: ErrorCallback): void

Enables listening for the **error** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                           |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | Yes  | Event type.<br/> **error**: event indicating the WebSocket connection has encountered an error.|
| callback | ErrorCallback | Yes  | Callback used to return the result.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
ws.on('error', (err: BusinessError) => {
  console.error(`on error. Code: ${err.code}, message: ${err.message}`)
});
```

### off('error')<sup>6+</sup>

off(type: 'error', callback?: ErrorCallback): void

Disables listening for the **error** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                           |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | Yes  | Type of the event to unsubscribe from. **error**: event indicating the WebSocket connection has encountered an error.|
| callback | ErrorCallback | No  | Callback used to return the result.                     |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('error');
```

### on('dataEnd')<sup>11+</sup>

on(type: 'dataEnd', callback: Callback\<void\>): void

Enables listening for the **dataEnd** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  |       Type       | Mandatory|                  Description                  |
| -------- | ---------------- | ---- | --------------------------------------- |
| type     | string           | Yes  | Event type.<br/> **dataEnd**: event indicating the data receiving over the WebSocket connection has ended.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.                             |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.on('dataEnd', () => {
  console.info("on dataEnd")
});
```

### off('dataEnd')<sup>11+</sup>

off(type: 'dataEnd', callback?: Callback\<void\>): void

Disables listening for the **dataEnd** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  |        Type      | Mandatory|                Description                   |
| -------- | ---------------- | ---- | -------------------------------------- |
| type     | string           | Yes  | Type of the event to unsubscribe from. **dataEnd**: event indicating the data receiving over the WebSocket connection has ended.|
| callback | Callback\<void\> | No  | Callback used to return the result.                            |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('dataEnd');
```

### on('headerReceive')<sup>12+</sup>

on(type: 'headerReceive', callback: Callback\<ResponseHeaders\>): void

Registers an observer for HTTP Response Header events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  |        Type      | Mandatory|                Description                   |
| -------- | ---------------- | ---- | -------------------------------------- |
| type     | string           | Yes  | Event type.<br/> Event type. The value is **headerReceive**.|
| callback | Callback\<ResponseHeaders\> | Yes  | Callback used to return the result.                            |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.on('headerReceive', (data) => {
  console.info("on headerReceive " + JSON.stringify(data))
});
```

### off('headerReceive')<sup>12+</sup>

off(type: 'headerReceive', callback?: Callback\<ResponseHeaders\>): void

Unregisters the observer for HTTP Response Header events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  |        Type      | Mandatory|                Description                   |
| -------- | ---------------- | ---- | -------------------------------------- |
| type     | string           | Yes  | Type of the event to unsubscribe from. Event type. The value is **headerReceive**.|
| callback | Callback\<ResponseHeaders\> | No  | Callback used to return the result.                          |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('headerReceive');
```

## webSocket.createWebSocketServer<sup>19+</sup>

createWebSocketServer(): WebSocketServer

Creates a **WebSocketServer** object, which provides methods to start or stop the WebSocketServer service, send data over the connection, close the connection, list all connections, and enable or disable listening for the **open**, **close**, **message**, and **error** events.

> **NOTE**
>
> This API can be called on smart TVs but does not work on other devices.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                               | Description                                                        |
| :---------------------------------- | :----------------------------------------------------------- |
| [WebSocketServer](#websocketserver19) | **WebSocketServer** object, which provides the **start**, **listAllConnections**, **send**, **close**, **stop**, **on**, and **off** methods.|

**Example**

```ts
let ws: webSocket.WebSocketServer = webSocket.createWebSocketServer();
```

## WebSocketServer<sup>19+</sup>

Defines a **WebSocketServer** object. You need to use [webSocket.createWebSocketServer](#websocketcreatewebsocketserver19) to create a **WebSocketServer** object before using its methods.

### start<sup>19+</sup>

start(config: WebSocketServerConfig): Promise\<boolean\>

Starts the WebSocketServer service based on the specified **config**. This API uses a promise to return the result.

> **NOTE**
>
> You can listen for the **error** events to obtain the execution result of this API. For details about the result codes, see [WebSocket Error Codes](errorcode-net-webSocket.md).

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| ------- | ----------------------- | ---- | ------------------------------------------------------ |
| config  | [WebSocketServerConfig](#websocketserverconfig19)   | Yes  | Starts the WebSocket server.|

**Return value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [WebSocket Error Codes](errorcode-net-webSocket.md).

| ID  | Error Message                                  |
| -------   | ------------------------------------------ |
| 201       | Permission denied.                         |
| 2302002   | Websocket certificate file does not exist. |
| 2302004   | Can't listen on the given NIC.            |
| 2302005   | Can't listen on the given Port.           |
| 2302999   | Websocket other unknown error.             |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let localServer: webSocket.WebSocketServer;
let config: webSocket.WebSocketServerConfig = {
  serverPort: 8080, // Listening port
  maxConcurrentClientsNumber: 10,
  maxConnectionsForOneClient: 10,
}

localServer = webSocket.createWebSocketServer();
localServer.start(config).then((success: boolean) => {
  if (success) {
    console.info('webSocket server start success');
  } else {
    console.error('websocket server start failed');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to start. Code: ${error.code}, message: ${error.message}`);
});
```

### send<sup>19+</sup>

send(data: string \| ArrayBuffer, connection: WebSocketConnection): Promise\<boolean\>

Sends data through the WebSocket connection. This API uses a promise to return the result.

> **NOTE**
>
> The **send** API can be called only after a **connect** event is listened.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| ---------- | ---------------------- | --------------------- | ------------------------------------------------ |
| data       | string \| ArrayBuffer                       | Yes | Data to send, which can be of the string or ArrayBuffer type.|
| connection | [WebSocketConnection](#websocketconnection19) | Yes | Client information.                             |

**Return value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [WebSocket Error Codes](errorcode-net-webSocket.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |
| 2302006 | websocket connection does not exist.        |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let localServer: webSocket.WebSocketServer;
let config: webSocket.WebSocketServerConfig = {
  serverPort: 8080, // Listening port
  maxConcurrentClientsNumber: 10,
  maxConnectionsForOneClient: 10,
}

localServer = webSocket.createWebSocketServer();
localServer.start(config).then((success: boolean) => {
  if (success) {
    console.info('webSocket server start success');
  } else {
    console.error('websocket server start failed');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to start. Code: ${error.code}, message: ${error.message}`);
});

localServer.on('connect', async (connection: webSocket.WebSocketConnection) => {
  console.info(`New client connected! Client ip: ${connection.clientIP}, Client port: ${connection.clientPort}`);
  // Use send() to send data to the client when the on('connect') event is received.
  localServer.send("Hello, I'm server!", connection).then((success: boolean) => {
    if (success) {
      console.info('message send successfully');
    } else {
      console.error('message send failed');
    }
  }).catch((error: BusinessError) => {
    console.error(`message send failed, Code: ${error.code}, message: ${error.message}`);
  });
});
```

### listAllConnections<sup>19+</sup>

listAllConnections(): WebSocketConnection[]

Obtains information about all clients connected to the server.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**
| Type                                       | Description                        |
| ------------------------------------------- | ---------------------------- |
| [WebSocketConnection[]](#websocketconnection19) | Information about all clients connected to the server, which is of the string array type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**
```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let connections: webSocket.WebSocketConnection[] = [];
let localServer: webSocket.WebSocketServer;
let config: webSocket.WebSocketServerConfig = {
  serverPort: 8080, // Listening port
  maxConcurrentClientsNumber: 10,
  maxConnectionsForOneClient: 10,
}

localServer = webSocket.createWebSocketServer();
localServer.start(config).then((success: boolean) => {
  if (success) {
    console.info('webSocket server start success');
  } else {
    console.error('websocket server start failed');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to start. Code: ${error.code}, message: ${error.message}`);
});

localServer.on('connect', async (connection: webSocket.WebSocketConnection) => {
  console.info(`New client connected! Client ip: ${connection.clientIP}, Client port: ${connection.clientPort}`);
  try {
    connections = await localServer.listAllConnections();
    if (connections.length === 0) {
      console.info('client list is empty');
    } else {
      console.info(`client list cnt: ${connections.length}, client connections list is: ${connections}`);
    }
  } catch (error) {
    console.error(`Failed to listAllConnections. Code: ${error.code}, message: ${error.message}`);
  }
});
```

### close<sup>19+</sup>

close(connection: WebSocketConnection, options?: webSocket.WebSocketCloseOptions): Promise\<boolean\>

Closes a WebSocket connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| ---------- | --------------------- | ---- | ----------------------------------------------------- |
| connection | [WebSocketConnection](#websocketconnection19) | Yes | Client information, including the IP address and port number.                  |
| options    | [webSocket.WebSocketCloseOptions](#websocketcloseoptions) | No | Defines the optional parameters carried in the request for closing a WebSocket connection.<br>By default, the error code is 200, and the cause is **Websocket connect failed**.|

**Return value**

| Type              | Description                                                                      |
| :----------------- | :------------------------------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [WebSocket Error Codes](errorcode-net-webSocket.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |
| 2302006 | websocket connection does not exist.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let localServer: webSocket.WebSocketServer;
let config: webSocket.WebSocketServerConfig = {
  serverPort: 8080, // Listening port
  maxConcurrentClientsNumber: 10,
  maxConnectionsForOneClient: 10,
}

localServer = webSocket.createWebSocketServer();
localServer.start(config).then((success: boolean) => {
  if (success) {
    console.info('webSocket server start success');
  } else {
    console.error('websocket server start failed');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to start. Code: ${error.code}, message: ${error.message}`);
});

localServer.on('connect', (connection: webSocket.WebSocketConnection) => {
  console.info(`New client connected! Client ip: ${connection.clientIP}, Client port: ${connection.clientPort}`);
  localServer.close(connection).then((success: boolean) => {
    if (success) {
      console.info('close client successfully');
    } else {
      console.error('close client failed');
    }
  });
});
```

### stop<sup>19+</sup>

stop(): Promise\<boolean\>

Stops the WebSocketServer service. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type              | Description                                                                      |
| :----------------- | :------------------------------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the operation is successful, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let localServer: webSocket.WebSocketServer;
let config: webSocket.WebSocketServerConfig = {
  serverPort: 8080, // Listening port
  maxConcurrentClientsNumber: 10,
  maxConnectionsForOneClient: 10,
}

localServer = webSocket.createWebSocketServer();
localServer.start(config).then((success: boolean) => {
  if (success) {
    console.info('webSocket server start success');
  } else {
    console.error('websocket server start failed');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to start. Code: ${error.code}, message: ${error.message}`);
});

localServer.stop().then((success: boolean) => {
  if (success) {
    console.info('server stop service successfully');
  } else {
    console.error('server stop service failed');
  }
});
```

### on('connect')<sup>19+</sup>

on(type: 'connect', callback: Callback\<WebSocketConnection\>): void

Enables listening for WebSocketServer connection events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| type     | string                  | Yes | Event type, which has a fixed value of **connect**. Successful calling of **onconnect()** indicates that a connection is established between the client and server.|
| callback | Callback\<[WebSocketConnection](#websocketconnection19)\> | Yes| Callback used to return the result. which is the information about connected clients.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let localServer = webSocket.createWebSocketServer();
localServer.on('connect', (connection: webSocket.WebSocketConnection) => {
  console.info(`New client connected! Client ip: ${connection.clientIP}, Client port: ${connection.clientPort}`);
});
```

### off('connect')<sup>19+</sup>

off(type: 'connect', callback?: Callback\<WebSocketConnection\>): void

Disables listening for WebSocketServer connection events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------- |
| type     | string                  | Yes | Event type, which has a fixed value of **connect**. Successful calling of **offconnect()** indicates that listening for connection events is canceled successful.|
| callback | Callback\<[WebSocketConnection](#websocketconnection19)\> | No | Callback used to return the result. which is the information about connected clients.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let localServer = webSocket.createWebSocketServer();
localServer.off('connect');
```

### on('messageReceive')<sup>19+</sup>

on(type: 'messageReceive', callback: Callback\<WebSocketMessage\>): void

Enables listening for **messageReceive** events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| -------- | ----------------------- | ---- | -------------------------------- |
| type     | string                  | Yes | Event type, which has a fixed value of **messageReceive**. Successful calling of **onmessageReceive()** indicates that a message is received from the client.|
| callback | Callback\<[WebSocketMessage](#websocketmessage19)\> | Yes | Callback used to return the result.<br>**clientconnection** indicates the client information and **data** indicates the data message sent by the client.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let localServer = webSocket.createWebSocketServer();
localServer.on('messageReceive', (message: webSocket.WebSocketMessage) => {
  console.info(`on message received, client: ${message.clientConnection}, data: ${message.data}`);
});
```

### off('messageReceive')<sup>19+</sup>

off(type: 'messageReceive', callback?: Callback\<WebSocketMessage\>): void

Cancels listening for **messageReceive** events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| -------- | --------------------------------------------------- | ---- | -------------------------------------------- |
| type     | string                  | Yes | Event type, which has a fixed value of **messageReceive**. Successful calling of **offmessageReceive()** indicates that listening for **messageReceive** events is canceled successfully.|
| callback | Callback\<[WebSocketMessage](#websocketmessage19)\> |  No| Callback used to return the result, which contains:<br>- **clientconnection**: client information.<br>- **data**: data sent by the client.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let localServer = webSocket.createWebSocketServer();
localServer.off('messageReceive');
```

### on('close')<sup>19+</sup>

on(type: 'close', callback: ClientConnectionCloseCallback): void

Enables listening for the **close** events of a WebSocketServer connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| -------- | ----------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                          | Yes | Event type, which has a fixed value of **close**. Successful calling of **onclose()** indicates that the connection is closed successfully.|
| callback | [ClientConnectionCloseCallback](#clientconnectionclosecallback19) | Yes | Callback used to return the result.<br>**close** and **reason** indicate the error code and error cause for closing the connection, respectively.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let localServer = webSocket.createWebSocketServer();
localServer.on('close', (clientConnection: webSocket.WebSocketConnection, closeReason: webSocket.CloseResult) => {
  console.info(`client close, client: ${clientConnection}, closeReason: Code: ${closeReason.code}, reason: ${closeReason.reason}`);
});
```

### off('close')<sup>19+</sup>

off(type: 'close', callback?: ClientConnectionCloseCallback): void

Disables listening for the **close** events of a WebSocketServer connection. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| -------- | ----------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                          | Yes | Event type, which has a fixed value of **close**. Successful calling of **offclose()** indicates that listening for the **close** events is canceled successfully.|
| callback | [ClientConnectionCloseCallback](#clientconnectionclosecallback19) | No | Callback used to return the result.<br>**close** and **reason** indicate the error code and error cause for closing the connection, respectively.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let localServer = webSocket.createWebSocketServer();
localServer.off('close');
```

### on('error')<sup>19+</sup>

on(type: 'error', callback: ErrorCallback): void

Enables listening for the **error** events of a WebSocketServer connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                    |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes | Event type, which has a fixed value of **error**. Successful calling of **onerror()** indicates that an error has occurred.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes | Callback used to return the result.|

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wsServer: webSocket.WebSocketServer = webSocket.createWebSocketServer();
wsServer.on('error', (err: BusinessError) => {
  console.error(`error. Code: ${err.code}, message: ${err.message}`);
});
```

### off('error')<sup>19+</sup>

off(type: 'error', callback?: ErrorCallback): void

Disables listening for the **error** events of a WebSocketServer connection. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                          |
| -------- | ------------- | ---- | --------------------------------- |
| type     | string        | Yes|  Event type, which has a fixed value of **error**. Successful calling of **offerror()** indicates that listening for the **error** events is canceled successfully.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No| Callback used to return the result. which is the error code (default value: **200**).                        |

**Example**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let localServer = webSocket.createWebSocketServer();
localServer.off('error');
```

## WebSocketRequestOptions

Defines the optional parameters carried in the request for establishing a WebSocket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type|  Read Only | Optional| Description                                                        |
| ------ | ------ |------ | ---- | ------------------------------------------------------------ |
| header | Object |  No |  Yes  | Header carrying optional parameters in the request for establishing a WebSocket connection. You can customize the parameter or leave it unspecified.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| caPath<sup>11+</sup> | string |  No |  Yes | Path of CA certificates. If a path is set, the system uses the CA certificates in this path. If a path is not set, the system uses the preset CA certificate, namely, **/etc/ssl/certs/cacert.pem**. This path is the sandbox mapping path, which can be obtained by using **UIAbilityContext** APIs. Currently, only text certificates in PEM format are supported.|
| clientCert<sup>11+</sup> | [ClientCert](#clientcert11) |   No |  Yes  | Client certificate.|
| proxy<sup>12+</sup> | ProxyConfiguration |  No | Yes| Proxy configuration. By default, the system network proxy is used.|
| protocol<sup>12+</sup> | string |  No | Yes| Custom **Sec-WebSocket-Protocol** field. The default value is "".             |
| skipServerCertVerification<sup>20+</sup> | boolean | No| Yes| Whether to skip server certificate verification. The value **true** means to skip server certificate verification, and the value **false** means the opposite. Default value: **false**.|
| pingInterval<sup>21+</sup> | int | No| Yes| Custom [heartbeat detection interval](../../network/websocket-connection.md). The default value is 30s. Heartbeat detection is initiated at the specified interval. If the value is set to **0**, heartbeat detection is disabled. The maximum value is 30000s, and the minimum value is 0s.|
| pongTimeout<sup>21+</sup> | int | No| Yes| Timeout interval for disconnecting a connection after heartbeat detection is initiated. The default value is 30s. If no response is received during the specified interval, the connection is disconnected. The maximum value is 30000s, and the minimum value is 0s. **pongTimeout** must be less than or equal to **pingInterval**.|

## ClientCert<sup>11+</sup>

Defines the client certificate type.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description               |
| ------ | ------ | ---- |-------------------|
| certPath   | string  | Yes  | Path of the certificate file.            |
| keyPath | string | Yes  | Path of the certificate key file.         |
| keyPassword | string | No  | Password of the certificate key file. The default value is an empty string.|

## ProxyConfiguration<sup>12+</sup>
type ProxyConfiguration = 'system' | 'no-proxy' | HttpProxy

Represents the HTTP proxy configuration.

**System capability**: SystemCapability.Communication.NetStack

|  Type  | Description                     |
| ------  |------------------------- |
| 'system'   |  The default network proxy is used.|
| 'no-proxy' |  No network proxy is used.|
| [HttpProxy](js-apis-net-connection.md#httpproxy10)  | The specified network proxy is used.|

## WebSocketCloseOptions

Defines the optional parameters carried in the request for closing a WebSocket connection.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | No  | Error code. Set this parameter based on the actual situation. The input value must be a positive integer. The default value is **1000**.|
| reason | string | No  | Error cause. Set this parameter based on the actual situation. The default value is an empty string ("").|

## CloseResult<sup>10+</sup>

Represents the result obtained from the **close** event reported when the WebSocket connection is closed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | Yes  | Error code for closing the connection.|
| reason | string | Yes  | Error cause for closing the connection.|

## ResponseHeaders<sup>12+</sup>
type ResponseHeaders = {
  [k: string]: string | string[] | undefined;
}

Enumerates the response headers sent by the server.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
|  [k:string]  | string \| string[] \| undefined | Yes  | Key-value pairs. The key can be any character string and the value can be any character string, character array, or **undefined**.|

## Result Codes for Connection Closing

You can customize the result codes sent to the server. The result codes in the following table are for reference only.

**System capability**: SystemCapability.Communication.NetStack

| Value       | Description              |
| :-------- | :----------------- |
| 1000      | Normally closed.          |
| 1001      | Connection closed by the server.    |
| 1002      | Incorrect protocol.          |
| 1003      | Data unable to be processed.|
| 1004~1015 | Reserved.            |

## HttpProxy<sup>12+</sup>

type HttpProxy = connection.HttpProxy

Defines the global HTTP proxy configuration of the network.

**System capability**: SystemCapability.Communication.NetManager.Core

|       Type      |            Description            |
| ---------------- | --------------------------- |
| connection.HttpProxy | The specified network proxy is used.   |

## WebSocketServerConfig<sup>19+</sup>

Defines the WebSocketServer configuration.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Read Only| Optional| Description                                                        |
| ---------- | ------ | ---- | ---- | ----------------------------------------------------- |
| serverIP   | string | No  | Yes  |  IP address of the WebSocketServer. The default value is **0.0.0.0**.|
| serverPort | number | No  | No  | Port of the WebSocketServer.                  |
| serverCert | [ServerCert](#servercert19) | No | Yes  | Certificate information, which includes the paths of the WebSocketServer certificate file and private key file.|
| protocol   | string | No  | Yes  | Custom protocol.|
| maxConcurrentClientsNumber | number | No| No  | Maximum number of concurrent clients. When the number of concurrent clients reaches the maximum, the server rejects new connections. The default value is **10**.|
| maxConnectionsForOneClient | number | No| No  | Maximum number of connections for each client. The default value is **10**.|

## ServerCert<sup>19+</sup>

Certificate information, which includes the paths of the WebSocketServer certificate file and private key file.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Read Only| Optional| Description                           |
| ------ | ------ | ---- | --- | ----------------------- |
| certPath   | string |  No   | No  | Path of the server certificate file.     |
| keyPath    | string |  No   | No  | Path of the private key file of the server certificate.|

## WebSocketMessage<sup>19+</sup>

Callback used to return the result, which contains:

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Read Only| Optional| Description                                     |
| ------ | ------ | ---- | ---- | ------------------------------------------------------- |
| data   | string \|ArrayBuffer  | No | No  | Message data sent by the client.|
| clientConnection | [WebSocketConnection](#websocketconnection19) | No | No  | Client information, including the IP address and port number.|

## WebSocketConnection<sup>19+</sup>

Client information, including the IP address and port number.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Read Only| Optional| Description                           |
| ------ | ------ | ---- | --- |------------------ |
| clientIP   | string | No  | No  | IP address of the client.    |
| clientPort | number | No  | No  | Port number of the client.|

## ClientConnectionCloseCallback<sup>19+</sup>

type ClientConnectionCloseCallback = (clientConnection: WebSocketConnection, closeReason: CloseResult) => void

Callback invoked when the WebSocketServer connection is closed.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**
| Name| Type   | Mandatory| Description                           |
| ---------------- | -------------------  | ------ | --------------------------------------------- |
| clientConnection | [WebSocketConnection](#websocketconnection19) | Yes| Client information, including the IP address and port number.            |
| closeReason | [CloseResult](#closeresult10)  | Yes| Represents the result obtained from the **close** event reported when the WebSocket connection is closed.|
