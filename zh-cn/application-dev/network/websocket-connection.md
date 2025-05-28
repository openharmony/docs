# WebSocket连接

## 场景介绍

给第三方应用提供webSocket客户端和服务端的服务器，实现客户端与服务端的双向连接，目前服务端仅支持智慧屏使用。

客户端：使用WebSocket建立服务器与客户端的双向连接，需要先通过[createWebSocket()](../reference/apis-network-kit/js-apis-webSocket.md#websocketcreatewebsocket6)方法创建[WebSocket](../reference/apis-network-kit/js-apis-webSocket.md#websocket6)对象，然后通过[connect()](../reference/apis-network-kit/js-apis-webSocket.md#connect6)方法连接到服务器。当连接成功后，客户端会收到[open](../reference/apis-network-kit/js-apis-webSocket.md#onopen6)事件的回调，之后客户端就可以通过[send()](../reference/apis-network-kit/js-apis-webSocket.md#send6)方法与服务器进行通信。当服务器发信息给客户端时，客户端会收到[message](../reference/apis-network-kit/js-apis-webSocket.md#onmessage6)事件的回调。当客户端想要取消此连接时，通过调用[close()](../reference/apis-network-kit/js-apis-webSocket.md#close6)方法主动断开连接后，客户端会收到[close](../reference/apis-network-kit/js-apis-webSocket.md#onclose6)事件的回调。若在上述任一过程中发生错误，客户端会收到[error](../reference/apis-network-kit/js-apis-webSocket.md#onerror6)事件的回调。

服务端：（目前服务端仅支持智慧屏使用）使用WebSocket建立服务器与客户端的双向连接，需要先通过[createWebSocketServer()](../reference/apis-network-kit/js-apis-webSocket.md#websocketcreatewebsocketserver19)方法创建[WebSocketServer](../reference/apis-network-kit/js-apis-webSocket.md#websocketserver19)对象，然后通过[start()](../reference/apis-network-kit/js-apis-webSocket.md#start19)方法启动服务器，监听客户端申请建链的消息。当连接成功后，服务端会收到[connect](../reference/apis-network-kit/js-apis-webSocket.md#onconnect19)事件的回调，之后服务端可以通过[send()](../reference/apis-network-kit/js-apis-webSocket.md#send19)方法与客户端进行通信，可以通过[listAllConnections()](../reference/apis-network-kit/js-apis-webSocket.md#listallconnections19)方法列举出当前与服务端建链的所有客户端信息。当客户端给服务端发消息时，服务端会收到[messageReceive](../reference/apis-network-kit/js-apis-webSocket.md#onmessagereceive19)事件回调。当服务端想断开某个与客户端的连接时，可以通过调用[close()](../reference/apis-network-kit/js-apis-webSocket.md#close19)方法主动断开与某个客户端的连接，之后服务端会收到[close](../reference/apis-network-kit/js-apis-webSocket.md#onclose19)事件的回调。当服务端想停止service时，可以调用[stop()](../reference/apis-network-kit/js-apis-webSocket.md#stop19)方法。若在上述任一过程中发生错误，服务端会收到[error](../reference/apis-network-kit/js-apis-webSocket.md#onerror19)事件的回调。

websocket支持心跳检测机制，在客户端和服务端建立WebSocket连接之后，每间隔30秒客户端会发送Ping帧给服务器，服务器收到后应立即回复Pong帧，且不支持开发者关闭该机制。

## 接口说明

WebSocket连接功能主要由[webSocket](../reference/apis-network-kit/js-apis-webSocket.md)模块提供。使用该功能需要申请ohos.permission.INTERNET权限。具体接口说明如下表。

**client端：**
| 接口名              | 描述                                      |
| ------------------ | ----------------------------------------- |
| createWebSocket()  | 创建一个WebSocket连接。                    |
| connect()          | 根据URL地址，建立一个WebSocket连接。       |
| send()             | 通过WebSocket连接发送数据。                |
| close()            | 关闭WebSocket连接。                        |
| on(type: 'open')   | 订阅WebSocket的打开事件。                  |
| off(type: 'open')   | 取消订阅WebSocket的打开事件。             |
| on(type: 'message') | 订阅WebSocket的接收到服务器消息事件。      |
| off(type: 'message') | 取消订阅WebSocket的接收到服务器消息事件。 |
| on(type: 'close')   | 订阅WebSocket的关闭事件。                 |
| off(type: 'close') | 取消订阅WebSocket的关闭事件                |
| on(type: 'error')  | 订阅WebSocket的error事件。                 |
| off(type: 'error') | 取消订阅WebSocket的error事件。             |

**server端：**
| 接口名                       | 描述                                                    |
| ---------------------------- | -------------------------------------------------------|
| createWebSocketServer()      | 创建一个websocketServer对象。                           |
| start()                      | 启动websocketServer服务器。                             |
| send()                       | 通过WebSocketServer连接发送数据。                        |
| listAllConnections()         | 通过WebSocketServer连接获取与服务端连接的所有客户端信息。  |
| close()                      | 关闭指定客户端的连接。                                   |
| stop()                       | 停止websocketServer服务器。                             |
| on(type: 'connect')          | 订阅WebSocketServer的连接事件（客户端与服务端建链成功）。    |
| off(type: 'connect')         | 取消订阅WebSocketServer的连接事件（客户端与服务端建链成功）。|
| on(type: 'messageReceive')   | 订阅WebSocketServer的接收到客户端消息事件。               |
| off(type: 'messageReceive')  | 取消订阅WebSocketServer的接收到客户端消息事件。           |
| on(type: 'close')            | 订阅WebSocketServer的关闭事件。                          |
| off(type: 'close')           | 取消订阅WebSocketServer的关闭事件。                      |
| on(type: 'error')            | 订阅WebSocketServer的error事件。                        |
| off(type: 'error')           | 取消订阅WebSocketServer的error事件。                    |


## client端开发步骤

1. 导入需要的webSocket模块。

2. 创建一个WebSocket连接，返回一个WebSocket对象。

3. （可选）订阅WebSocket的打开、消息接收、关闭、Error事件。

4. 根据URL地址，发起WebSocket连接。

5. 使用完WebSocket连接之后，主动断开连接。

**示例：**

```js
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let defaultIpAddress = "ws://";
let ws = webSocket.createWebSocket();
ws.on('open', (err: BusinessError, value: Object) => {
  console.log("on open, status:" + JSON.stringify(value));
  // 当收到on('open')事件时，可以通过send()方法与服务器进行通信
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
  // 当收到服务器的`bye`消息时（此消息字段仅为示意，具体字段需要与服务器协商），主动断开连接
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

## server端开发步骤

1. 导入需要的webSocket模块。

2. 创建一个WebSocketServer对象。

3. （可选）订阅WebSocketServer的客户端连接事件、消息接收事件、关闭事件、Error事件。

4. 配置config参数，通过start()启动server端服务。

5. 通过WebSocketServer收发消息、监听事件等。

6. 使用完WebSocketServer端服务器后，通过stop()停止服务。

**示例：**

```js
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let connections: webSocket.WebSocketConnection[] = [];
let localServer: webSocket.WebSocketServer;
let config: webSocket.WebSocketServerConfig = {
  serverPort: 8080, // 监听端口
  maxConcurrentClientsNumber: 10,
  maxConnectionsForOneClient: 10,
}

localServer = webSocket.createWebSocketServer();

localServer.on('connect', async (connection: webSocket.WebSocketConnection) => {
  console.info(`New client connected! Client ip: ${connection.clientIP}, Client port: ${connection.clientPort}`);
  // 当收到on('connect')事件时，可以通过send()方法与客户端进行通信
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
    // 当收到客户端的"bye"消息时（此消息字段仅为示意，具体字段需要与客户端协商），主动断开连接
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

## 相关实例

针对WebSocket连接的开发，有以下相关实例可供参考：

- [WebSocket（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/WebSocket)