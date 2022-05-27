# WebSocket Connection


## Use Cases

You can use WebSocket to establish a bidirectional connection between a server and a client. Before doing this, you need to use the **createWebSocket** API to create a **WebSocket** object and then use the **connect** API to connect to the server. If the connection is successful, the client will receive a callback of the **open** event. Then, the client can communicate with the server using the **send** API. When the server sends a message to the client, the client will receive a callback of the **message** event. If the client no longer needs this connection, it can call the **close** API to disconnect from the server. Then, the client will receive a callback of the **close** event.

If an error occurs in any of the preceding processes, the client will receive a callback of the **error** event.


## Available APIs

The WebSocket connection function is mainly implemented by the WebSocket module. To use related APIs, you must declare the **ohos.permission.INTERNET** permission. The following table describes the related APIs.

| API | Description |
| -------- | -------- |
| createWebSocket() | Creates a WebSocket connection. |
| connect() | Establishes a WebSocket connection to a given URL. |
| send() | Sends data through the WebSocket connection. |
| close() | Closes a WebSocket connection. |
| on(type:&nbsp;'open') | Enables listening for **open** events of a WebSocket connection. |
| off(type:&nbsp;'open') | Disables listening for **open** events of a WebSocket connection. |
| on(type:&nbsp;'message') | Enables listening for **message** events of a WebSocket connection. |
| off(type:&nbsp;'message') | Disables listening for **message** events of a WebSocket connection. |
| on(type:&nbsp;'close') | Enables listening for **close** events of a WebSocket connection. |
| off(type:&nbsp;'close') | Disables listening for **close** events of a WebSocket connection. |
| on(type:&nbsp;'error') | Enables listening for **error** events of a WebSocket connection. |
| off(type:&nbsp;'error') | Disables listening for **error** events of a WebSocket connection. |


## How to Develop

1. Import the required WebSocket module.

2. Create a **WebSocket** object.

3. (Optional) Subscribe to WebSocket open, message, close, and error events.

4. Establish a WebSocket connection to a given URL.

5. Close the WebSocket connection if it is no longer needed.
   
   ```js
   import webSocket from '@ohos.net.webSocket';
   
   var defaultIpAddress = "ws://";
   let ws = webSocket.createWebSocket();
   ws.on('open', (err, value) => {
       console.log("on open, status:" + JSON.stringify(value));
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
       // When receiving the `bye` message (the actual message name may differ) from the server, the client proactively disconnects from the server.
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
       console.log("on close, code is " + value.code + ", reason is " + value.reason);
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
