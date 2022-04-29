# WebSocket连接


## 场景介绍

使用WebSocket建立服务器与客户端的双向连接，需要先通过createWebSocket方法创建WebSocket对象，然后通过connect方法连接到服务器。当连接成功后，客户端会收到open事件的回调，之后客户端就可以通过send方法与服务器进行通信。当服务器发信息给客户端时，客户端会收到message事件的回调。当客户端不要此连接时，可以通过调用close方法主动断开连接，之后客户端会收到close事件的回调。

若在上述任一过程中发生错误，客户端会收到error事件的回调。


## 接口说明

WebSocket连接功能主要由webSocket模块提供。使用该功能需要申请ohos.permission.INTERNET权限。具体接口说明如下表。

| 接口名 | 功能描述 |
| -------- | -------- |
| createWebSocket() | 创建一个WebSocket连接。 |
| connect() | 根据URL地址，建立一个WebSocket连接。 |
| send() | 通过WebSocket连接发送数据。 |
| close() | 关闭WebSocket连接。 |
| on(type:&nbsp;'open') | 订阅WebSocket的打开事件。 |
| off(type:&nbsp;'open') | 取消订阅WebSocket的打开事件。 |
| on(type:&nbsp;'message') | 订阅WebSocket的接收到服务器消息事件。 |
| off(type:&nbsp;'message') | 取消订阅WebSocket的接收到服务器消息事件。 |
| on(type:&nbsp;'close') | 订阅WebSocket的关闭事件。 |
| off(type:&nbsp;'close') | 取消订阅WebSocket的关闭事件 |
| on(type:&nbsp;'error') | 订阅WebSocket的Error事件。 |
| off(type:&nbsp;'error') | 取消订阅WebSocket的Error事件。 |


## 开发步骤

1. import需要的webSocket模块。

2. 创建一个WebSocket连接，返回一个WebSocket对象。

3. （可选）订阅WebSocket的打开、消息、关闭、Error事件。

4. 根据URL地址，发起WebSocket连接。

5. 使用完WebSocket连接之后，主动断开连接。
   
   ```js
   import webSocket from '@ohos.net.webSocket';
   
   var defaultIpAddress = "ws://";
   let ws = webSocket.createWebSocket();
   ws.on('open', (err, value) => {
       console.log("on open, status:" + JSON.stringify(value));
       // 当收到on('open')事件时，可以通过send()方法与服务器进行通信
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
       // 当收到服务器的`bye`消息时（此消息字段仅为示意，具体字段需要与服务器协商），主动断开连接
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
