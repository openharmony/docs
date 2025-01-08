# WebSocket Connection

## When to Use

You can use WebSocket to establish a bidirectional connection between a server and a client. Before doing this, you need to use the **createWebSocket()** API to create a **WebSocket** object and then use the **connect()** API to connect to the server. If the connection is successful, the client will receive a callback of the **open** event. Then, the client can communicate with the server using the **send()** API. When the server sends a message to the client, the client will receive a callback of the **message** event. If the client no longer needs this connection, it can call the **close()** API to disconnect from the server. Then, the client will receive a callback of the **close** event.

If an error occurs in any of the preceding processes, the client will receive a callback of the **error** event.

The WebSocket module supports the heartbeat detection mechanism. After a WebSocket connection is established between the client and server, the client sends a ping frame to the server at a specified interval. On receiving the ping frame, the server immediately returns a Pong frame.

## Available APIs

The WebSocket connection function is mainly implemented by the [WebSocket module](../reference/apis-network-kit/js-apis-webSocket.md). To use related APIs, you must declare the **ohos.permission.INTERNET** permission. The following table describes the related APIs.

| API             | Description                                     |
| ------------------ | ----------------------------------------- |
| createWebSocket()  | Creates a WebSocket connection.                   |
| connect()          | Establishes a WebSocket connection to a given URL.      |
| send()             | Sends data through the WebSocket connection.               |
| close()            | Closes a WebSocket connection.                       |
| on(type: 'open')   | Enables listening for **open** events of a WebSocket connection.                 |
| off(type: 'open')   | Disables listening for **open** events of a WebSocket connection.            |
| on(type: 'message') | Enables listening for **message** events of a WebSocket connection.     |
| off(type: 'message') | Disables listening for **message** events of a WebSocket connection.|
| on(type: 'close')   | Enables listening for **close** events of a WebSocket connection.                |
| off(type: 'close') | Disables listening for **close** events of a WebSocket connection.               |
| on(type: 'error')  | Enables listening for **error** events of a WebSocket connection.                |
| off(type: 'error') | Disables listening for **error** events of a WebSocket connection.            |

## How to Develop

1. Import the required webSocket module.

2. Create a **WebSocket** object.

3. (Optional) Subscribe to WebSocket **open**, **message**, **close**, and **error** events.

4. Establish a WebSocket connection to a given URL.

5. Close the WebSocket connection if it is no longer needed.

```js
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let defaultIpAddress = "ws://";
let ws = webSocket.createWebSocket();
ws.on('open', (err: BusinessError, value: Object) => {
  console.log("on open, status:" + JSON.stringify(value));
  // When receiving the on('open') event, the client can use the send() API to communicate with the server.
  ws.send("Hello, server!", (err: BusinessError, value: boolean) => {
    if (!err) {
      console.log("Message send successfully");
    } else {
      console.log("Failed to send the message. Err:" + JSON.stringify(err));
    }
  });
});
ws.on('message', (err: BusinessError, value: string | ArrayBuffer) => {
  console.log("on message, message:" + value);
  // When receiving the `bye` message (the actual message name may differ) from the server, the client proactively disconnects from the server.
  if (value === 'bye') {
    ws.close((err: BusinessError, value: boolean) => {
      if (!err) {
        console.log("Connection closed successfully");
      } else {
        console.log("Failed to close the connection. Err: " + JSON.stringify(err));
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
    console.log("Connected successfully");
  } else {
    console.log("Connection failed. Err:" + JSON.stringify(err));
  }
});
```

