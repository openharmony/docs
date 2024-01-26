# # @ohos.net.webSocket (WebSocket Connection)

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


You can use WebSocket to establish a bidirectional connection between a server and a client. Before doing this, you need to use the <span name="createWebSocket">[createWebSocket](#websocketcreatewebsocket)</span> API to create a <span name="WebSocket">[WebSocket](#websocket)</span> object and then use the <span name="connect">[connect](#connected)</span> API to connect to the server.
If the connection is successful, the client will receive a callback of the <span name="open">[open](#onopen)</span> event. Then, the client can communicate with the server using the <span name="sended">[send](#send)</span> API.
When the server sends a message to the client, the client will receive a callback of the <span name="message">[message](#onmessage)</span> event. If the client no longer needs this connection, it can call the <span name="closed">[close](#close)</span> API to disconnect from the server. Then, the client will receive a callback of the <span name="closes">[close](#onclose)</span> event.

If an error occurs in any of the preceding steps, the client will receive a callback of the <span name="error">[error](#onerror)</span> event.

## Modules to Import

```ts
import webSocket from '@ohos.net.webSocket';
```

## Examples

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let defaultIpAddress = "ws://";
let ws = webSocket.createWebSocket();
ws.on('open', (err:BusinessError, value: Object) => {
  if (err != undefined) {
    console.log(JSON.stringify(err));
    return;
  }
  // When receiving the on('open') event, the client can use the send() API to communicate with the server.
  ws.send("Hello, server!", (err: BusinessError, value: boolean) => {
    if (!err) {
      console.log("send success");
    } else {
      console.log("send fail, err:" + JSON.stringify(err));
    }
  });
});
ws.on('message',(BusinessError<void>, value: string | ArrayBuffer) => {
  console.log("on message, message:" + value);
  // When receiving the `bye` message (the actual message name may differ) from the server, the client proactively disconnects from the server.
  if (value === 'bye') {
    ws.close((err: BusinessError, value: boolean) => {
      if (!err) {
        console.log("close success");
      } else {
        console.log("close fail, err is " + JSON.stringify(err));
      }
    });
  }
});
ws.on('close', (err: BusinessError, value: webSocket.CloseResult) => {
  console.log("on close, code is " + value.code + ", reason is " + value.reason);
});
ws.on('error', (err: BusinessError) => {
  console.log("on error, error:" + JSON.stringify(err));
});
ws.connect(defaultIpAddress, (err: BusinessError, value: boolean) => {
  if (!err) {
    console.log("connect success");
  } else {
    console.log("connect fail, err:" + JSON.stringify(err));
  }
  ws.close((err: BusinessError) => {
    if (!err) {
      console.log("close success");
    } else {
      console.log("close fail, err is " + JSON.stringify(err));
    }
  });
});
```

## <span name="websocketcreatewebsocket">webSocket.createWebSocket<sup>6+</sup></span>

createWebSocket(): WebSocket

Creates a WebSocket connection. You can use this API to create or close a WebSocket connection, send data over it, or enable or disable listening for the **open**, **close**, **message**, and **error** events.

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                               | Description                                                        |
| :---------------------------------- | :----------------------------------------------------------- |
| [WebSocket](#websocket) | A **WebSocket** object, which contains the **connect**, **send**, **close**, **on**, or **off** method.|

**Example**

```ts
let ws: webSocket = webSocket.createWebSocket();
```

## <span name="websocket">WebSocket<sup>6+</sup></span>

Defines a **WebSocket** object. Before invoking WebSocket APIs, you need to call [webSocket.createWebSocket](#websocketcreatewebsocket) to create a **WebSocket** object.

### <span name="connected">connect<sup>6+</sup></span>

connect(url: string, callback: AsyncCallback\<boolean\>): void

Initiates a WebSocket request to establish a WebSocket connection to a given URL. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can listen to **error** events to obtain the operation result. If an error occurs, the error code 200 will be returned.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description                        |
| -------- | ------------------------ | ---- | ---------------------------- |
| url      | string                   | Yes  | URL for establishing a WebSocket connection.|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.                  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
let url = "ws://";
ws.connect(url, (err: BusinessError, value: boolean) => {
  if (!err) {
    console.log("connect success");
  } else {
    console.log("connect fail, err:" + JSON.stringify(err));
  }
});
```

### connect<sup>6+</sup>

connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean\>): void

Initiates a WebSocket request carrying specified options to establish a WebSocket connection to a given URL. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can listen to **error** events to obtain the operation result. If an error occurs, the error code 200 will be returned.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description                                                   |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| url      | string                   | Yes  | URL for establishing a WebSocket connection.                           |
| options  | WebSocketRequestOptions  | Yes  | Request options. For details, see [WebSocketRequestOptions](#websocketrequestoptions).|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.                                             |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
let header: Map<string, string> | undefined;
if (header !=undefined) {
    header.set("key", "value")
    header.set("key2", "value2")
}
let url = "ws://"
ws.connect(url, header as webSocket.WebSocketRequestOptions, (err: BusinessError, value: Object) => {
  if (!err) {
    console.log("connect success");
  } else {
    console.log("connect fail, err:" + JSON.stringify(err))
  }
});
```

### connect<sup>6+</sup>

connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean\>

Initiates a WebSocket request carrying specified options to establish a WebSocket connection to a given URL. This API uses a promise to return the result.

> **NOTE**
> You can listen to **error** events to obtain the operation result. If an error occurs, the error code 200 will be returned.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                   |
| ------- | ----------------------- | ---- | ------------------------------------------------------- |
| url     | string                  | Yes  | URL for establishing a WebSocket connection.                           |
| options | WebSocketRequestOptions | No  | Request options. For details, see [WebSocketRequestOptions](#websocketrequestoptions).|

**Return value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';

let ws = webSocket.createWebSocket();
let url = "ws://"
let promise = ws.connect(url);
promise.then((value: boolean) => {
  console.log("connect success")
}).catch((err:string) => {
  console.log("connect fail, error:" + JSON.stringify(err))
});
```

### <span name="send">send<sup>6+</sup></span>

send(data: string | ArrayBuffer, callback: AsyncCallback\<boolean\>): void

Sends data through a WebSocket connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description        |
| -------- | ------------------------ | ---- | ------------ |
| data     | string \| ArrayBuffer | Yes  | Data to send.<br>Only the string type is supported for API version 6 or earlier. Both the string and ArrayBuffer types are supported for API version 8 or later.|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.  |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err: BusinessError, value: boolean) => {
  ws.send("Hello, server!", (err: BusinessError, value: boolean) => {
    if (!err) {
      console.log("send success");
    } else {
      console.log("send fail, err:" + JSON.stringify(err))
    }
  });
});
```

### send<sup>6+</sup>

send(data: string | ArrayBuffer): Promise\<boolean\>

Sends data through a WebSocket connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| data     | string \| ArrayBuffer | Yes  | Data to send.<br>Only the string type is supported for API version 6 or earlier. Both the string and ArrayBuffer types are supported for API version 8 or later.|

**Return value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err: BusinessError, value: boolean) => {
  let promise = ws.send("Hello, server!");
  promise.then((value: boolean) => {
    console.log("send success")
  }).catch((err:string) => {
    console.log("send fail, error:" + JSON.stringify(err))
  });
});
```

### <span name="close">close<sup>6+</sup></span>

close(callback: AsyncCallback\<boolean\>): void

Closes a WebSocket connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description      |
| -------- | ------------------------ | ---- | ---------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
ws.close((err: BusinessError) => {
  if (!err) {
    console.log("close success")
  } else {
    console.log("close fail, err is " + JSON.stringify(err))
  }
});
```

### close<sup>6+</sup>

close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean\>): void

Closes a WebSocket connection carrying specified options such as **code** and **reason**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description                                                 |
| -------- | ------------------------ | ---- | ----------------------------------------------------- |
| options  | WebSocketCloseOptions    | Yes  | Request options. For details, see [WebSocketCloseOptions](#websocketcloseoptions).|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.                                           |

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();

let options: webSocket.WebSocketCloseOptions | undefined;
if (options != undefined) {
    options.code = 1000
    options.reason = "your reason"
}
ws.close(options, (err: BusinessError) => {
    if (!err) {
        console.log("close success")
    } else {
        console.log("close fail, err is " + JSON.stringify(err))
    }
});
```

### close<sup>6+</sup>

close(options?: WebSocketCloseOptions): Promise\<boolean\>

Closes a WebSocket connection carrying specified options such as **code** and **reason**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                 | Mandatory| Description                                                 |
| ------- | --------------------- | ---- | ----------------------------------------------------- |
| options | WebSocketCloseOptions | No  | Request options. For details, see [WebSocketCloseOptions](#websocketcloseoptions).|

**Return value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

| ID| Error Message                |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';

let ws = webSocket.createWebSocket();
let options: webSocket.WebSocketCloseOptions | undefined;
if (options != undefined) {
    options.code = 1000
    options.reason = "your reason"
}
let promise = ws.close();
promise.then((value: boolean) => {
    console.log("close success")
}).catch((err:string) => {
    console.log("close fail, err is " + JSON.stringify(err))
});
```

### <span name="onopen">on('open')<sup>6+</sup></span>

on(type: 'open', callback: AsyncCallback\<Object\>): void

Enables listening for the **open** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                         |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | Yes  | Event type. <br />**open**: event indicating that a WebSocket connection has been opened.|
| callback | AsyncCallback\<Object\> | Yes  | Callback used to return the result.                   |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError, Callback } from '@ohos.base';

let ws= webSocket.createWebSocket();
class OutValue {
  status: number = 0
  message: string = ""
}
ws.on('open', (err: BusinessError, value: Object) => {
  console.log("on open, status:" + (value as OutValue).status + ", message:" + (value as OutValue).message);
});
```

### off('open')<sup>6+</sup>

off(type: 'open', callback?: AsyncCallback\<Object\>): void

Disables listening for the **open** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                         |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | Yes  | Event type. <br />**open**: event indicating that a WebSocket connection has been opened.|
| callback | AsyncCallback\<Object\> | No  | Callback used to return the result.                   |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
class OutValue {
  status: number = 0
  message: string = ""
}
let callback1 = (err: BusinessError, value: Object) => {
 console.log("on open, status:" + ((value as OutValue).status + ", message:" + (value as OutValue).message));
}
ws.on('open', callback1);
// You can pass the callback of the on function to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
ws.off('open', callback1);
```

### <span name="onmessage">on('message')<sup>6+</sup></spam>

on(type: 'message', callback: AsyncCallback\<string | ArrayBuffer\>): void

Enables listening for the **message** events of a WebSocket connection. This API uses an asynchronous callback to return the result. The maximum length of each message is 4 KB. If the length exceeds 4 KB, the message is automatically fragmented.

> **NOTE**
> The data in **AsyncCallback** can be in the format of string (API version 6) or ArrayBuffer (API version 8).

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                                        |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | Yes  | Event type.<br />**message**: event indicating that a message has been received from the server.|
| callback | AsyncCallback\<string \| ArrayBuffer <sup>8+</sup>\> | Yes  | Callback used to return the result.                                  |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
ws.on('message', (err: BusinessError<void>, value: string | ArrayBuffer) => {
  console.log("on message, message:" + value);
});
```

### off('message')<sup>6+</sup>

off(type: 'message', callback?: AsyncCallback\<string | ArrayBuffer\>): void

Disables listening for the **message** events of a WebSocket connection. This API uses an asynchronous callback to return the result. The maximum length of each message is 4 KB. If the length exceeds 4 KB, the message is automatically fragmented.

> **NOTE**
> The data in **AsyncCallback** can be in the format of string (API version 6) or ArrayBuffer (API version 8).
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                               | Mandatory| Description                                        |
| -------- | --------------------------------------------------- | ---- | -------------------------------------------- |
| type     | string                                              | Yes  | Event type.<br />**message**: event indicating that a message has been received from the server.|
| callback | AsyncCallback\<string \|ArrayBuffer <sup>8+</sup>\> | No  | Callback used to return the result.                                  |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';

let ws = webSocket.createWebSocket();
ws.off('message');
```

### <span name="onclose">on('close')<sup>6+</sup></span>

on(type: 'close', callback: AsyncCallback\<CloseResult\>): void

Enables listening for the **close** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                           | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | Yes  | Event type. <br />**close**: event indicating that a WebSocket connection has been closed.|
| callback | AsyncCallback\<CloseResult\> | Yes  | Callback used to return the result.<br>**close** and **reason** indicate the error code and error cause for closing the connection, respectively.|

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
ws.on('close', (err: BusinessError, value: webSocket.CloseResult) => {
  console.log("on close, code is " + value.code + ", reason is " + value.reason);
});
```

### off('close')<sup>6+</sup>

off(type: 'close', callback?: AsyncCallback\<CloseResult\>): void

Disables listening for the **close** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                           | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | Yes  | Event type. <br />**close**: event indicating that a WebSocket connection has been closed.|
| callback | AsyncCallback\<CloseResult\> | No  | Callback used to return the result.<br>**close** and **reason** indicate the error code and error cause for closing the connection, respectively.|

**Example**

```ts
import webSocket from '@ohos.net.webSocket';

let ws = webSocket.createWebSocket();
ws.off('close');
```

### <span name="onerror">on('error')<sup>6+</sup></span>

on(type: 'error', callback: ErrorCallback): void

Enables listening for the **error** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                           |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | Yes  | Event type.<br />**error**: event indicating the WebSocket connection has encountered an error.|
| callback | ErrorCallback | Yes  | Callback used to return the result.<br>Common error code: 200|

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
ws.on('error', (err: BusinessError) => {
  console.log("on error, error:" + JSON.stringify(err))
});
```

### off('error')<sup>6+</sup>

off(type: 'error', callback?: ErrorCallback): void

Disables listening for the **error** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                           |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | Yes  | Event type.<br />**error**: event indicating the WebSocket connection has encountered an error.|
| callback | ErrorCallback | No  | Callback used to return the result.                     |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
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
| type     | string           | Yes  | Event type.<br />**dataEnd**: event indicating the data receiving over the WebSocket connection has ended.|
| callback | Callback\<void\> | Yes  | Callback used to return the result.                             |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';

let ws = webSocket.createWebSocket();
ws.on('dataEnd', () => {
  console.log("on dataEnd")
});
```

### off('dataEnd')<sup>11+</sup>

off(type: 'dataEnd', callback?: Callback\<void\>): void

Disables listening for the **dataEnd** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

> **NOTE**
> You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  |        Type      | Mandatory|                Description                   |
| -------- | ---------------- | ---- | -------------------------------------- |
| type     | string           | Yes  | Event type.<br />**dataEnd**: event indicating the data receiving over the WebSocket connection has ended.|
| callback | Callback\<void\> | No  | Callback used to return the result.                            |

**Example**

```ts
import webSocket from '@ohos.net.webSocket';
let ws = webSocket.createWebSocket();
ws.off('dataEnd');
```

## WebSocketRequestOptions

Defines the optional parameters carried in the request for establishing a WebSocket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| header | Object | No  | Header carrying optional parameters in the request for establishing a WebSocket connection. You can customize the parameter or leave it unspecified.|
| caPath<sup>11+</sup> | string | No  | Path of CA certificates. If a path is set, the system uses the CA certificates in this path. If a path is not set, the system uses the preset CA certificate, namely, **/etc/ssl/certs/cacert.pem**. This path is the sandbox mapping path, which can be obtained through **Global.getContext().filesDir**. Currently, only text certificates in PEM format are supported.|
| clientCert<sup>11+</sup> | [ClientCert](#clientcert11) | No  | Client certificate.|

## ClientCert<sup>11+</sup>

Defines the client certificate type.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| certPath   | string  | Yes  | Path of the certificate file.|
| keyPath | string | Yes  | Path of the certificate key file.|
| keyPassword | string | No  | Password of the certificate key file.|

## WebSocketCloseOptions

Defines the optional parameters carried in the request for closing a WebSocket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | No  | Error code. Set this parameter based on the actual situation. The default value is **1000**.|
| reason | string | No  | Error cause. Set this parameter based on the actual situation. The default value is an empty string ("").|

## CloseResult<sup>10+</sup>

Represents the result obtained from the **close** event reported when the WebSocket connection is closed.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | Yes  | Error code for closing the connection.|
| reason | string | Yes  | Error cause for closing the connection.|

## Result Codes for Closing a WebSocket Connection

You can customize the result codes sent to the server. The result codes in the following table are for reference only.

**System capability**: SystemCapability.Communication.NetStack

| Value       | Description              |
| :-------- | :----------------- |
| 1000      | Normally closed.          |
| 1001      | Connection closed by the server.    |
| 1002      | Incorrect protocol.          |
| 1003      | Data unable to be processed.|
| 1004~1015 | Reserved.            |
