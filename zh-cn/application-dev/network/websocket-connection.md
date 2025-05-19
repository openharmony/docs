# WebSocket连接

## 场景介绍

提供webSocket客户端和服务端服务器，实现客户端与服务端的双向连接。
客户端：使用WebSocket建立服务器与客户端的双向连接，需要先通过createWebSocket()方法创建WebSocket对象，然后通过connect()方法连接到服务器。当连接成功后，客户端会收到open事件的回调，之后客户端就可以通过send()方法与服务器进行通信。当服务器发信息给客户端时，客户端会收到message事件的回调。当客户端不要此连接时，可以通过调用close()方法主动断开连接，之后客户端会收到close事件的回调。若在上述任一过程中发生错误，客户端会收到error事件的回调。

服务端：使用WebSocket建立服务器与客户端的双向连接，需要先通过createWebSocketServer()方法创建WebSocketServer对象，然后通过start()方法启动服务器，监听客户端的申请建链的消息。当连接成功后，服务端会收到connect事件的回调，之后服务端可以通过send()方法与客户端进行通信，可以通过listAllConnections()方法列举出当前与服务端建链的所有客户端信息。当客户端给服务端发消息时，服务端会收到messageReceive事件回调。当服务端想断开某个与客户端的连接，可以通过调用close()方法主动断开与某个客户端的连接，之前服务端会收到close事件的回调。当服务端想停止服务器，可以通过调用stop()方法。若在上述任一过程中发生错误，服务端会收到error事件的回调。

websocket支持心跳检测机制，在客户端和服务端建立WebSocket连接之后，每间隔30秒客户端会发送Ping帧给服务器，服务器收到后应立即回复Pong帧，且不支持开发者关闭该机制。

## 接口说明

WebSocket连接功能主要由[webSocket模块](../reference/apis-network-kit/js-apis-webSocket.md)提供。使用该功能需要申请ohos.permission.INTERNET权限。具体接口说明如下表。
client端：
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
| on(type: 'error')  | 订阅WebSocket的Error事件。                 |
| off(type: 'error') | 取消订阅WebSocket的Error事件。             |

server端:
| 接口名                       | 描述                                                    |
| ---------------------------- | -------------------------------------------------------|
| createWebSocketServer()      | 创建一个websocketServer对象。                           |
| start()                      | 启动websocketServer服务器。                             |
| send()                       | 通过WebSocketServer连接发送数据。                        |
| listAllConnections()         | 通过WebSocketServer连接获取与服务端连接的所有客户端信息。  |
| close()                      | 关闭指定客户端的连接。                                   |
| stop()                       | 停止websocketServer服务器。                             |
| on(type: 'connect')          | 订阅WebSocketServer的连接事件(客户端与服务端建链成功)。    |
| off(type: 'connect')         | 取消订阅WebSocketServer的连接事件(客户端与服务端建链成功)。|
| on(type: 'messageReceive')   | 订阅WebSocketServer的接收到客户端消息事件。               |
| off(type: 'messageReceive')  | 取消订阅WebSocketServer的接收到客户端消息事件。           |
| on(type: 'close')            | 订阅WebSocketServer的关闭事件。                          |
| off(type: 'close')           | 取消订阅WebSocketServer的关闭事件。                      |
| on(type: 'error')            | 订阅WebSocketServer的Error事件。                        |
| off(type: 'error')           | 取消订阅WebSocketServer的Error事件。                    |


## 开发步骤
client端：
1. 导入需要的webSocket模块。

2. 创建一个WebSocket连接，返回一个WebSocket对象。

3. （可选）订阅WebSocket的打开、消息接收、关闭、Error事件。

4. 根据URL地址，发起WebSocket连接。

5. 使用完WebSocket连接之后，主动断开连接。

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

server端：
1. 导入需要的webSocket模块。

2. 创建一个WebSocketServer对象。

3. （可选）订阅WebSocketServer的客户端连接事件、消息接收事件、关闭事件、Error事件。

4. 配置config参数，通过start()启动server端服务。

5. 通过WebSocketServer收发消息、监听事件等。

5. 使用完WebSocketServer端服务器后，通过stop()停止服务。

```js
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let connections: webSocket.WebSocketConnection[] = [];
let localServer: webSocket.WebSocketServer;
let config: webSocket.WebSocketServerConfig = {
  serverPort: 8080, //监听端口
  maxConcurrentClientsNumber: 10,
  maxConnectionsForOneClient: 10,
}

localServer = webSocket.createWebSocketServer();

localServer.on('connect', async (connection: webSocket.WebSocketConnection) => {
  console.log("New client connected! Client:" + JSON.stringify(connection));
  // 当收到on('connect')事件时，可以通过send()方法与客户端进行通信
  localServer.send("Hello, I'm server!", connection).then((success: boolean) => {
    if (success) {
      console.log("message send successfully");
    } else {
      console.log("message send failed");
    }
  }).catch((error: BusinessError) => {
    console.log("message send failed, Err:" + JSON.stringify(error));
  });

  try {
    connections = await localServer.listAllConnections();
    if (connections.length === 0) {
      console.log("client list is empty");
    } else {
      console.log("client list cnt :" + connections.length + "client connections are: " + JSON.stringify(connections));
    }
  } catch (error) {
    console.log("Err: " + JSON.stringify(error));
  }
});

localServer.on('messageReceive', (message: webSocket.WebSocketMessage) => {
  try{
    console.log("on message received: " + JSON.stringify(message));
    // 当收到客户端的"bye"消息时（此消息字段仅为示意，具体字段需要与客户端协商），主动断开连接
    if (message.data === 'bye') {
      localServer.close(message.clientConnection).then((success: boolean) => {
        if (success) {
          console.log("close client successfully");
        } else {
          console.log("close client failed");
        }
      });
    }
  } catch (error) {
    console.log("Err: " + JSON.stringify(error));
  }
});

localServer.on('close', (clientConnection: webSocket.WebSocketConnection, closeReason: webSocket.CloseResult) => {
  console.log("client close, client: " + JSON.stringify(clientConnection) + "closeReason: " + JSON.stringify(closeReason));
  localServer.stop().then((success: boolean) => {
    if (success) {
      console.log("server stop service successfully");
    } else {
      console.log("server stop service failed");
    }
  });
});

localServer.on('error', (err: BusinessError) => {
  console.log("error: " + JSON.stringify(err));
});

localServer.start(config).then((success: boolean) => {
  if (success) {
    console.log("webSocket server start success");
  } else {
    console.log("websocket server start failed");
  }
}).catch((error: BusinessError) => {
  console.log("Err: " + JSON.stringify(error));
});
```

## 相关实例

针对WebSocket连接的开发，有以下相关实例可供参考：

- [WebSocket（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/WebSocket)