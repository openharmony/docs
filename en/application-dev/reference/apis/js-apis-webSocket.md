# WebSocket Connection

>![](public_sys-resources/icon-note.gif) **NOTE:**
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

You can use WebSocket to establish a bidirectional connection between a server and a client. Before doing this, you need to use the [createWebSocket](#websocketcreatewebsocket) API to create a [WebSocket](#websocket) object and then use the [connect](#connect) API to connect to the server. If the connection is successful, the client will receive a callback of the [open](#onopen) event. Then, the client can communicate with the server using the [send](#send) API. When the server sends a message to the client, the client will receive a callback of the [message](#onmessage) event. If the client no longer needs this connection, it can call the [close](#close) API to disconnect from the server. Then, the client will receive a callback of the [close](#onclose) event.

If an error occurs in any of the preceding processes, the client will receive a callback of the [error](#onerror) event.


## Modules to Import

```js
import webSocket from '@ohos.net.webSocket';
```

## Complete Example

```js
import webSocket from '@ohos.net.webSocket';

var defaultIpAddress = "ws://";
let ws = webSocket.createWebSocket();
ws.on('open', (err, value) => {
    console.log("on open, status:" + value['status'] + ", message:" + value['message']);
    // When receiving the on('open') event, the client can use the send() API to communicate with the server.
    ws.send("Hello, server!", (err, value) => {
        if (!err) {
            console.log("send success");
        } else {
            console.log("send fail, err:" + JSON.stringify(err));
        }
    });
});
ws.on('message', (err, value) => {
    console.log("on message, message:" + value);
    // When receiving the bye message (the actual message name may differ) from the server, the client proactively disconnects from the server.
    if (value === 'bye') {
        ws.close((err, value) => {
            if (!err) {
                console.log("close success");
            } else {
                console.log("close fail, err is " + JSON.stringify(err));
            }
        });
    }
});
ws.on('close', (err, value) => {
    console.log("on close, code is " + value['code'] + ", reason is " + value['reason']);
});
ws.on('error', (err) => {
    console.log("on error, error:" + JSON.stringify(err));
});
ws.connect(defaultIpAddress, (err, value) => {
    if (!err) {
        console.log("connect success");
    } else {
        console.log("connect fail, err:" + JSON.stringify(err));
    }
});
```

## webSocket.createWebSocket

createWebSocket\(\): WebSocket

Creates a WebSocket connection. You can use this API to create or close a WebSocket connection, send data over it, or enable or disable listening for the **open**, **close**, **message**, and **error** events.

**System capability**: SystemCapability.Communication.NetStack

**Return Value**

| Type                               | Description                                                        |
| :---------------------------------- | :----------------------------------------------------------- |
| [WebSocket](#websocket) | A **WebSocket** object, which contains the **connect**, **send**, **close**, **on**, or **off** method.|

**Example**

```js
let ws = webSocket.createWebSocket();
```


## WebSocket

Defines a **WebSocket** object. Before invoking WebSocket APIs, you need to call [webSocket.createWebSocket](#websocketcreatewebsocket) to create a **WebSocket** object.

### connect

connect\(url: string, callback: AsyncCallback<boolean\>\): void

Initiates a WebSocket request to establish a WebSocket connection to a given URL. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description                        |
| -------- | ------------------------ | ---- | ---------------------------- |
| url      | string                   | Yes  | URL for establishing a WebSocket connection.|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.                  |


**Example**

```js
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err, value) => {
	if (!err) {
		console.log("connect success");
	} else {
		console.log("connect fail, err:" + JSON.stringify(err))
	}
});
```


### connect

connect\(url: string, options: WebSocketRequestOptions, callback: AsyncCallback<boolean\>\): void

Initiates a WebSocket request carrying specified options to establish a WebSocket connection to a given URL. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description                                                   |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| url      | string                   | Yes  | URL for establishing a WebSocket connection.                           |
| options  | WebSocketRequestOptions  | Yes  | Request options. For details, see [WebSocketRequestOptions](#websocketrequestoptions).|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.                                             |


**Example**

```js
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, {
	header: {
		"key": "value",
		"key2": "value2"
	}
}, (err, value) => {
	if (!err) {
		console.log("connect success");
	} else {
		console.log("connect fail, err:" + JSON.stringify(err))
	}
});
```


### connect

connect\(url: string, options?: WebSocketRequestOptions\): Promise<boolean\>

Initiates a WebSocket request carrying specified options to establish a WebSocket connection to a given URL. This API uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                   | Mandatory| Description                                                   |
| ------- | ----------------------- | ---- | ------------------------------------------------------- |
| url     | string                  | Yes  | URL for establishing a WebSocket connection.                           |
| options | WebSocketRequestOptions | No  | Request options. For details, see [WebSocketRequestOptions](#websocketrequestoptions).|

**Return Value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
let ws = webSocket.createWebSocket();
let url = "ws://"
let promise = ws.connect(url);
promise.then((value) => {
	console.log("connect success")
}).catch((err) => {
	console.log("connect fail, error:" + JSON.stringify(err))
});
```


### send

send\(data: string | ArrayBuffer, callback: AsyncCallback<boolean\>\): void

Sends data through a WebSocket connection. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description        |
| -------- | ------------------------ | ---- | ------------ |
| data     | string \| ArrayBuffer <sup>8+</sup> | Yes  | Data to send.|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.  |

**Example**

```js
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err, value) => {
	ws.send("Hello, server!", (err, value) => {
		if (!err) {
			console.log("send success");
		} else {
			console.log("send fail, err:" + JSON.stringify(err))
		}
	});
});
```


### send

send\(data: string | ArrayBuffer\): Promise<boolean\>

Sends data through a WebSocket connection. This API uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| data     | string \| ArrayBuffer <sup>8+</sup> | Yes  | Data to send.|

**Return Value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err, value) => {
	let promise = ws.send("Hello, server!");
	promise.then((value) => {
		console.log("send success")
	}).catch((err) => {
		console.log("send fail, error:" + JSON.stringify(err))
	});
});
```


### close

close\(callback: AsyncCallback<boolean\>\): void

Closes a WebSocket connection. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description      |
| -------- | ------------------------ | ---- | ---------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```js
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.close((err, value) => {
	if (!err) {
		console.log("close success")
	} else {
		console.log("close fail, err is " + JSON.stringify(err))
	}
});
```


### close

close\(options: WebSocketCloseOptions, callback: AsyncCallback<boolean\>\): void

Closes a WebSocket connection carrying specified options such as **code** and **reason**. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                    | Mandatory| Description                                                 |
| -------- | ------------------------ | ---- | ----------------------------------------------------- |
| options  | WebSocketCloseOptions    | Yes  | Request options. For details, see [WebSocketCloseOptions](#websocketcloseoptions).|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.                                           |

**Example**

```js
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.close({
	code: 1000,
	reason: "your reason"
}, (err, value) => {
	if (!err) {
		console.log("close success")
	} else {
		console.log("close fail, err is " + JSON.stringify(err))
	}
});
```


### close

close\(options?: WebSocketCloseOptions\): Promise<boolean\>

Closes a WebSocket connection carrying specified options such as **code** and **reason**. This API uses a promise to return the result.

**Required permission**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name | Type                 | Mandatory| Description                                                 |
| ------- | --------------------- | ---- | ----------------------------------------------------- |
| options | WebSocketCloseOptions | No  | Request options. For details, see [WebSocketCloseOptions](#websocketcloseoptions).|

**Return Value**

| Type              | Description                             |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
let ws = webSocket.createWebSocket();
let url = "ws://"
let promise = ws.close({
	code: 1000,
	reason: "your reason"
});
promise.then((value) => {
	console.log("close success")
}).catch((err) => {
	console.log("close fail, err is " + JSON.stringify(err))
});
```


### on\('open'\)

on\(type: 'open', callback: AsyncCallback<Object\>\): void

Enables listening for the **open** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                         |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | Yes  | Event type. <br />**open**: event indicating that a WebSocket connection has been opened.|
| callback | AsyncCallback\<Object\> | Yes  | Callback used to return the result.                   |


**Example**

```js
let ws = webSocket.createWebSocket();
ws.on('open', (err, value) => {
	console.log("on open, status:" + value['status'] + ", message:" + value['message']);
});
```


### off\('open'\)

off\(type: 'open', callback?: AsyncCallback<Object\>\): void

Disables listening for the **open** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

>![](public_sys-resources/icon-note.gif) **NOTE:**
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                         |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | Yes  | Event type. <br />**open**: event indicating that a WebSocket connection has been opened.|
| callback | AsyncCallback\<Object\> | No  | Callback used to return the result.                   |

**Example**

```js
let ws = webSocket.createWebSocket();
let callback1 = (err, value) => {
	console.log("on open, status:" + value['status'] + ", message:" + value['message']);
}
ws.on('open', callback1);
// You can pass the callback of the on function to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
ws.off('open', callback1);
```


### on\('message'\)

on\(type: 'message', callback: AsyncCallback<string | ArrayBuffer\>\): void

Enables listening for the **message** events of a WebSocket connection. This API uses an asynchronous callback to return the result. The maximum length of each message is 4 KB. If the length exceeds 4 KB, the message is automatically fragmented.

>![](public_sys-resources/icon-note.gif) **NOTE:**
>The data in **AsyncCallback** can be in the format of string\(API 6\) or ArrayBuffer\(API 8\).

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                   | Mandatory| Description                                        |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | Yes  | Event type.<br />**message**: event indicating that a message has been received from the server.|
| callback | AsyncCallback\<string \| ArrayBuffer <sup>8+</sup>\> | Yes  | Callback used to return the result.                                  |


**Example**

```js
let ws = webSocket.createWebSocket();
ws.on('message', (err, value) => {
	console.log("on message, message:" + value);
});
```


### off\('message'\)

off\(type: 'message', callback?: AsyncCallback<string | ArrayBuffer\>\): void

Disables listening for the **message** events of a WebSocket connection. This API uses an asynchronous callback to return the result. The maximum length of each message is 4 KB. If the length exceeds 4 KB, the message is automatically fragmented.

>![](public_sys-resources/icon-note.gif) **NOTE:**
>The data in **AsyncCallback** can be in the format of string\(API 6\) or ArrayBuffer\(API 8\).
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                               | Mandatory| Description                                        |
| -------- | --------------------------------------------------- | ---- | -------------------------------------------- |
| type     | string                                              | Yes  | Event type.<br />**message**: event indicating that a message has been received from the server.|
| callback | AsyncCallback\<string \|ArrayBuffer <sup>8+</sup>\> | No  | Callback used to return the result.                                  |

**Example**

```js
let ws = webSocket.createWebSocket();
ws.off('message');
```


### on\('close'\)

on\(type: 'close', callback: AsyncCallback<\{ code: number, reason: string \}\>\): void

Enables listening for the **close** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                           | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | Yes  | Event type. <br />**close**: event indicating that a WebSocket connection has been closed.|
| callback | AsyncCallback<{ code: number, reason: string }> | Yes  | Callback used to return the result.                    |

**Example**

```js
let ws = webSocket.createWebSocket();
ws.on('close', (err, value) => {
	console.log("on close, code is " + value['code'] + ", reason is " + value['reason']);
});
```


### off\('close'\)

off\(type: 'close', callback?: AsyncCallback<\{ code: number, reason: string \}\>\): void

Disables listening for the **close** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

>![](public_sys-resources/icon-note.gif) **NOTE:**
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                           | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | Yes  | Event type. <br />**close**: event indicating that a WebSocket connection has been closed.|
| callback | AsyncCallback<{ code: number, reason: string }> | No  | Callback used to return the result.                    |


**Example**

```js
let ws = webSocket.createWebSocket();
ws.off('close');
```


### on\('error'\)

on\(type: 'error', callback: ErrorCallback\): void

Enables listening for the **error** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                           |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | Yes  | Event type.<br />**error**: event indicating the WebSocket connection has encountered an error.|
| callback | ErrorCallback | Yes  | Callback used to return the result.                     |


**Example**

```js
let ws = webSocket.createWebSocket();
ws.on('error', (err) => {
	console.log("on error, error:" + JSON.stringify(err))
});
```


### off\('error'\)

off\(type: 'error', callback?: ErrorCallback\): void

Disables listening for the **error** events of a WebSocket connection. This API uses an asynchronous callback to return the result.

>![](public_sys-resources/icon-note.gif) **NOTE:**
>You can pass the callback of the **on** function if you want to cancel listening for a certain type of event. If you do not pass the callback, you will cancel listening for all events.

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type         | Mandatory| Description                           |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | Yes  | Event type.<br />**error**: event indicating the WebSocket connection has encountered an error.|
| callback | ErrorCallback | No  | Callback used to return the result.                     |

**Example**

```js
let ws = webSocket.createWebSocket();
ws.off('error');
```


## WebSocketRequestOptions

Defines the optional parameters carried in the request for establishing a WebSocket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| header | Object | No  | Header carrying optional parameters in the request for establishing a WebSocket connection. You can customize the parameter or leave it unspecified.|


## WebSocketCloseOptions

Defines the optional parameters carried in the request for closing a WebSocket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | No  | Error code. Set this parameter based on the actual situation. The default value is **1000**.|
| reason | string | No  | Error cause. Set this parameter based on the actual situation. The default value is an empty string ("").|

## Result Codes for Closing a WebSocket Connection

You can customize the result codes sent to the server. The result codes in the following table are for reference only.

**System capability**: SystemCapability.Communication.NetStack

| Value       | Description              |
| :-------- | :----------------- |
| 1000      | Normally closed          |
| 1001      | Connection closed by the server    |
| 1002      | Incorrect protocol          |
| 1003      | Data unable to be processed|
| 1004~1015 | Reserved            |
