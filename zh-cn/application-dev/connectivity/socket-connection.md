# Socket连接


## 场景介绍

应用通过Socket进行数据传输，支持TCP和UDP两种协议。


## 接口说明

Socket连接主要由socket模块提供。具体接口说明如下表。

| 接口名 | 功能描述 |
| -------- | -------- |
| constructUDPSocketInstance() | 创建一个UDPSocket对象。 |
| constructTCPSocketInstance() | 创建一个TCPSocket对象。 |
| bind() | 绑定IP地址和端口。 |
| send() | 发送数据。 |
| close() | 关闭连接。 |
| getState() | 获取Socket状态。 |
| connect() | 连接到指定的IP地址和端口（仅TCP支持） |
| getRemoteAddress() | 获取对端Socket地址（仅TCP支持，需要先调用connect方法） |
| on(type:&nbsp;'message') | 订阅Socket连接的接收消息事件。 |
| off(type:&nbsp;'message') | 取消订阅Socket连接的接收消息事件。 |
| on(type:&nbsp;'close') | 订阅Socket连接的关闭事件。 |
| off(type:&nbsp;'close') | 取消订阅Socket连接的关闭事件。 |
| on(type:&nbsp;'error') | 订阅Socket连接的Error事件。 |
| off(type:&nbsp;'error') | 取消订阅Socket连接的Error事件。 |
| on(type:&nbsp;'listening') | 订阅UDPSocket连接的数据包消息事件（仅UDP支持）。 |
| off(type:&nbsp;'listening') | 取消订阅UDPSocket连接的数据包消息事件（仅UDP支持）。 |
| on(type:&nbsp;'connect') | 订阅TCPSocket的连接事件（仅TCP支持）。 |
| off(type:&nbsp;'connect') | 取消订阅TCPSocket的连接事件（仅TCP支持）。 |


## 开发步骤

UDP与TCP流程大体类似，下面以TCP为例：

1. import需要的socket模块。

2. 创建一个TCPSocket连接，返回一个TCPSocket对象。

3. （可选）订阅TCPSocket相关的订阅事件。

4. 绑定IP地址和端口，端口可以指定或由系统随机分配。

5. 连接到指定的IP地址和端口。

6. 发送数据。

7. Socket连接使用完毕后，主动关闭。
   
   ```js
   import socket from '@ohos.net.socket'
   
   // 创建一个TCPSocket连接，返回一个TCPSocket对象。
   let tcp = socket.constructTCPSocketInstance();
   
   // 订阅TCPSocket相关的订阅事件
   tcp.on('message', value => {
       console.log("on message")
       let buffer = value.message
       let dataView = new DataView(buffer)
       let str = ""
       for (let i = 0;i < dataView.byteLength; ++i) {
           str += String.fromCharCode(dataView.getUint8(i))
       }
       console.log("on connect received:" + str)
   });
   tcp.on('connect', () => {
       console.log("on connect")
   });
   tcp.on('close', () => {
       console.log("on close")
   });
   
   // 绑定本地IP地址和端口。
   let bindAddress = {
       address: '192.168.xx.xx',
       port: 1234, // 绑定端口，如1234
       family: 1
   };
   tcp.bind(bindAddress, err => {
       if (err) {
           console.log('bind fail');
           return;
       }
       console.log('bind success');
       // 连接到指定的IP地址和端口。
       let connectAddress = {
           address: '192.168.xx.xx',
           port: 5678, // 连接端口，如5678
           family: 1
       };
       tcp.connect({
           address: connectAddress, timeout: 6000
       }, err => {
           if (err) {
               console.log('connect fail');
               return;
           }
           console.log('connect success');
           // 发送数据
           tcp.send({
               data: 'Hello, server!'
           }, err => {
               if (err) {
                   console.log('send fail');
                   return;
               }
               console.log('send success');
           })
       });
   });
   // 连接使用完毕后，主动关闭。取消相关事件的订阅。
   setTimeout(() => {
       tcp.close((err) => {
           console.log('close socket.')
       });
       tcp.off('message');
       tcp.off('connect');
       tcp.off('close');
   }, 30 * 1000);
   ```

## 相关实例
针对Socket连接开发，有以下相关实例可供参考：
- [`Socket`：Socket 连接（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/Network/Socket)
- [使用UDP实现与服务端通信（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/NetworkManagement/UdpDemoOH)
- [使用TCP实现与服务端通信（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/NetworkManagement/TcpSocketDemo)