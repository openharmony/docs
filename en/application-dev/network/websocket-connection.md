# Using WebSocket for Network Access

## When to Use

The **webSocket** module implements bidirectional connections between the WebSocket client and WebSocket server for third-party applications. Currently, the WebSocket server is available only for smart TVs.

On the WebSocket client: Use WebSocket to establish a bidirectional connection between the server and the client. Before doing this, you need to use [createWebSocket()](../reference/apis-network-kit/js-apis-webSocket.md#websocketcreatewebsocket6) to create a [WebSocket](../reference/apis-network-kit/js-apis-webSocket.md#websocket6) object and then use [connect()](../reference/apis-network-kit/js-apis-webSocket.md#connect6) to connect to the server. If the connection is successful, the client will receive a callback of the [open](../reference/apis-network-kit/js-apis-webSocket.md#onopen6) event. Then, the client can communicate with the server by using [send()](../reference/apis-network-kit/js-apis-webSocket.md#send6). When the server sends a message to the client, the client will receive a callback of the [message](../reference/apis-network-kit/js-apis-webSocket.md#onmessage6) event. If the connection is no longer needed, the client can call [close()](../reference/apis-network-kit/js-apis-webSocket.md#close6) to close the connection. After successful disconnection, the client will receive a callback of the [close](../reference/apis-network-kit/js-apis-webSocket.md#onclose6) event. If an error occurs in any of the preceding processes, the client will receive a callback of the [error](../reference/apis-network-kit/js-apis-webSocket.md#onerror6) event.

On the WebSocket server (available only for smart TVs): Use WebSocket to establish a bidirectional connection between the server and client. Before doing this, you need to use [createWebSocketServer()](../reference/apis-network-kit/js-apis-webSocket.md#websocketcreatewebsocketserver19) to create a [WebSocketServer](../reference/apis-network-kit/js-apis-webSocket.md#websocketserver19) object and then use [start()](../reference/apis-network-kit/js-apis-webSocket.md#start19) to start the server to listen for connection requests from the client. If the connection is successful, the server receives the callback of the [connect](../reference/apis-network-kit/js-apis-webSocket.md#onconnect19) event. The server can then communicate with the client by using [send()](../reference/apis-network-kit/js-apis-webSocket.md#send19) or obtain information about all connected clients by using [listAllConnections()](../reference/apis-network-kit/js-apis-webSocket.md#listallconnections19). When the client sends a message to the server, the server receives the callback of the [messageReceive](../reference/apis-network-kit/js-apis-webSocket.md#onmessagereceive19) event. If the connection is no longer needed, the server can call [close()](../reference/apis-network-kit/js-apis-webSocket.md#close19) to close the connection. After successful disconnection, the server will receive a callback of the [close](../reference/apis-network-kit/js-apis-webSocket.md#onclose19) event. To stop the service, the server can use the [stop()](../reference/apis-network-kit/js-apis-webSocket.md#stop19) API. If an error occurs in any of the preceding processes, the server will receive a callback of the [error](../reference/apis-network-kit/js-apis-webSocket.md#onerror19) event.

The WebSocket module supports the heartbeat detection mechanism. After a WebSocket connection is established between the client and server, the client sends a ping frame to the server every 30 seconds. On receiving the ping frame, the server immediately returns a Pong frame. You are not allowed to disable this mechanism.

## Available APIs

The WebSocket connection function is mainly implemented by the [WebSocket module](../reference/apis-network-kit/js-apis-webSocket.md). To use related APIs, you must declare the **ohos.permission.INTERNET** permission. The following table describes the related APIs.

**APIs for the client**
| API             | Description                                     |
| ------------------ | ----------------------------------------- |
| createWebSocket()  | Creates a **WebSocket** object, which represents a WebSocket connection.                   |
| connect()          | Establishes a WebSocket connection to a given URL.      |
| send()             | Sends data through the WebSocket connection.               |
| close()            | Closes a WebSocket connection.                       |
| on(type: 'open')   | Subscribes to **open** events of a WebSocket connection.                 |
| off(type: 'open')   | Unsubscribes from **open** events of a WebSocket connection.            |
| on(type: 'message') | Subscribes to **message** events of a WebSocket connection.     |
| off(type: 'message') | Unsubscribes from **message** events of a WebSocket connection.|
| on(type: 'close')   | Subscribes to **close** events of a WebSocket connection.                |
| off(type: 'close') | Unsubscribes from **close** events of a WebSocket connection.               |
| on(type: 'error')  | Subscribes to **error** events of a WebSocket connection.                |
| off(type: 'error') | Unsubscribes from **error** events of a WebSocket connection.            |

**APIs for the server**
| API                      | Description                                                   |
| ---------------------------- | -------------------------------------------------------|
| createWebSocketServer()      | Creates a **WebSocketServer** object, which represents a WebSocket server.                          |
| start()                      | Starts the WebSocket server.                            |
| send()                       | Sends data through the WebSocket server.                       |
| listAllConnections()         | Obtains information about all clients connected to the WebSocket server. |
| close()                      | Closes the specified client connection.                                  |
| stop()                       | Stops the WebSocket server.                            |
| on(type: 'connect')          | Subscribes to **connect** events of the WebSocket server.   |
| off(type: 'connect')         | Unsubscribes from **connect** events of the WebSocket server.|
| on(type: 'messageReceive')   | Subscribes to **message** events of the WebSocket server.              |
| off(type: 'messageReceive')  | Unsubscribes from **message** events of the WebSocket server.          |
| on(type: 'close')            | Subscribes to **close** events of the WebSocket server.                         |
| off(type: 'close')           | Unsubscribes from **close** events of the WebSocket server.                     |
| on(type: 'error')            | Subscribes to **error** events of the WebSocket server.                       |
| off(type: 'error')           | Unsubscribes from **error** events of the WebSocket server.                   |

## Client Development Procedure

1. Import the required webSocket module.

2. Create a WebSocket connection.

3. (Optional) Subscribe to the **open**, **message**, **close**, and **error** events of the WebSocket connection.

4. Establish a WebSocket connection to a given URL.

5. Close the WebSocket connection if it is no longer needed.

**Example**

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
      console.error("Failed to send the message. Err:" + JSON.stringify(err));
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
        console.error("Failed to close the connection. Err: " + JSON.stringify(err));
      }
    });
  }
});
ws.on('close', (err: BusinessError, value: webSocket.CloseResult) => {
  console.log("on close, code is " + value.code + ", reason is " + value.reason);
});
ws.on('error', (err: BusinessError) => {
  console.error("on error, error:" + JSON.stringify(err));
});
ws.connect(defaultIpAddress, (err: BusinessError, value: boolean) => {
  if (!err) {
    console.log("Connected successfully");
  } else {
    console.error("Connection failed. Err:" + JSON.stringify(err));
  }
});
```

## Server Development Procedure

1. Import the required webSocket module.

2. Create a WebSocket server.

3. (Optional) Subscribe to the **connect**, **message**, **close**, and **error** events of the WebSocket server.

4. Configure **config** parameters and call **start()** to start the WebSocket server.

5. Transmit messages and listen for events through the WebSocket server.

6. Call **stop()** to stop the WebSocket server after use.

**Example**

```js
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

localServer.on('connect', async (connection: webSocket.WebSocketConnection) => {
  console.info(`New client connected! Client ip: ${connection.clientIP}, Client port: ${connection.clientPort}`);
  // Use send() to send data to the client when the on('connect') event is received.
  localServer.send("Hello, I'm server!", connection).then((success: boolean) => {
    if (success) {
      console.info('message send successfully');
    } else {
      console.info('message send failed');
    }
  }).catch((error: BusinessError) => {
    console.error(`message send failed, Code: ${error.code}, message: ${error.message}`);
  });

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

localServer.on('messageReceive', (message: webSocket.WebSocketMessage) => {
  try{
    console.info(`on message received, client: ${message.clientConnection}, data: ${message.data}`);
    // When receiving the bye message (the actual message name may differ) from the client, the server proactively disconnects from the client.
    if (message.data === 'bye') {
      localServer.close(message.clientConnection).then((success: boolean) => {
        if (success) {
          console.info('close client successfully');
        } else {
          console.info('close client failed');
        }
      });
    }
  } catch (error) {
    console.error(`on messageReceive failed. Code: ${error.code}, message: ${error.message}`);
  }
});

localServer.on('close', (clientConnection: webSocket.WebSocketConnection, closeReason: webSocket.CloseResult) => {
  console.info(`client close, client: ${clientConnection}, closeReason: Code: ${closeReason.code}, reason: ${closeReason.reason}`);
  localServer.stop().then((success: boolean) => {
    if (success) {
      console.info('server stop service successfully');
    } else {
      console.info('server stop service failed');
    }
  });
});

localServer.on('error', (error: BusinessError) => {
  console.info(`error. Code: ${error.code}, message: ${error.message}`);
});

localServer.start(config).then((success: boolean) => {
  if (success) {
    console.info('webSocket server start success');
  } else {
    console.info('websocket server start failed');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to start. Code: ${error.code}, message: ${error.message}`);
});
```
