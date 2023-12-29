# Socket 连接

## 简介

Socket 连接主要是通过 Socket 进行数据传输，支持 TCP/UDP/TLS 协议。

## 基本概念

- Socket：套接字，就是对网络中不同主机上的应用进程之间进行双向通信的端点的抽象。
- TCP：传输控制协议(Transmission Control Protocol)。是一种面向连接的、可靠的、基于字节流的传输层通信协议。
- UDP：用户数据报协议(User Datagram Protocol)。是一个简单的面向消息的传输层，不需要连接。
- TLS：安全传输层协议(Transport Layer Security)。用于在两个通信应用程序之间提供保密性和数据完整性。

## 场景介绍

应用通过 Socket 进行数据传输，支持 TCP/UDP/TLS 协议。主要场景有：

- 应用通过 TCP/UDP Socket 进行数据传输
- 应用通过 TCP Socket Server 进行数据传输
- 应用通过 TLS Socket 进行加密数据传输

## 接口说明

完整的 JS API 说明以及实例代码请参考：[Socket 连接](../reference/apis/js-apis-socket.md)。

Socket 连接主要由 socket 模块提供。具体接口说明如下表。

| 接口名                             | 描述                                                                          |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| constructUDPSocketInstance()       | 创建一个 UDPSocket 对象。                                                      |
| constructTCPSocketInstance()       | 创建一个 TCPSocket 对象。                                                      |
| constructTCPSocketServerInstance() | 创建一个 TCPSocketServer 对象。                                                |
| listen()                           | 绑定 IP 地址和端口，监听并接受与此套接字建立的 TCPSocket 连接。（仅 TCP 支持）    |
| bind()                             | 绑定 IP 地址和端口。                                                           |
| send()                             | 发送数据。                                                                     |
| close()                            | 关闭连接。                                                                     |
| getState()                         | 获取 Socket 状态。                                                             |
| connect()                          | 连接到指定的 IP 地址和端口（仅 TCP 支持）                                      |
| getRemoteAddress()                 | 获取对端 Socket 地址（仅 TCP 支持，需要先调用 connect 方法）                   |
| setExtraOptions()                  | 设置 Socket 连接的其他属性。                                                   |
| on(type:&nbsp;'message')           | 订阅 Socket 连接的接收消息事件。                                               |
| off(type:&nbsp;'message')          | 取消订阅 Socket 连接的接收消息事件。                                           |
| on(type:&nbsp;'close')             | 订阅 Socket 连接的关闭事件。                                                   |
| off(type:&nbsp;'close')            | 取消订阅 Socket 连接的关闭事件。                                               |
| on(type:&nbsp;'error')             | 订阅 Socket 连接的 Error 事件。                                                |
| off(type:&nbsp;'error')            | 取消订阅 Socket 连接的 Error 事件。                                            |
| on(type:&nbsp;'listening')         | 订阅 UDPSocket 连接的数据包消息事件（仅 UDP 支持）。                           |
| off(type:&nbsp;'listening')        | 取消订阅 UDPSocket 连接的数据包消息事件（仅 UDP 支持）。                       |
| on(type:&nbsp;'connect')           | 订阅 TCPSocket 的连接事件（仅 TCP 支持）。                                     |
| off(type:&nbsp;'connect')          | 取消订阅 TCPSocket 的连接事件（仅 TCP 支持）。                                 |

TLS Socket 连接主要由 tls_socket 模块提供。具体接口说明如下表。

| 接口名                       | 功能描述                                                   |
| ---------------------------- | ---------------------------------------------------------- |
| constructTLSSocketInstance() | 创建一个 TLSSocket 对象。                                  |
| bind()                       | 绑定 IP 地址和端口号。                                     |
| close(type:&nbsp;'error')    | 关闭连接。                                                 |
| connect()                    | 连接到指定的 IP 地址和端口。                               |
| getCertificate()             | 返回表示本地证书的对象。                                   |
| getCipherSuite()             | 返回包含协商的密码套件信息的列表。                         |
| getProtocol()                | 返回包含当前连接协商的 SSL/TLS 协议版本的字符串。          |
| getRemoteAddress()           | 获取 TLSSocket 连接的对端地址。                            |
| getRemoteCertificate()       | 返回表示对等证书的对象。                                   |
| getSignatureAlgorithms()     | 在服务器和客户端之间共享的签名算法列表，按优先级降序排列。 |
| getState()                   | 获取 TLSSocket 连接的状态。                                |
| off(type:&nbsp;'close')      | 取消订阅 TLSSocket 连接的关闭事件。                        |
| off(type:&nbsp;'error')      | 取消订阅 TLSSocket 连接的 Error 事件。                     |
| off(type:&nbsp;'message')    | 取消订阅 TLSSocket 连接的接收消息事件。                    |
| on(type:&nbsp;'close')       | 订阅 TLSSocket 连接的关闭事件。                            |
| on(type:&nbsp;'error')       | 订阅 TLSSocket 连接的 Error 事件。                         |
| on(type:&nbsp;'message')     | 订阅 TLSSocket 连接的接收消息事件。                        |
| send()                       | 发送数据。                                                 |
| setExtraOptions()            | 设置 TLSSocket 连接的其他属性。                            |

## 应用 TCP/UDP 协议进行通信

UDP 与 TCP 流程大体类似，下面以 TCP 为例：

1. import 需要的 socket 模块。

2. 创建一个 TCPSocket 连接，返回一个 TCPSocket 对象。

3. （可选）订阅 TCPSocket 相关的订阅事件。

4. 绑定 IP 地址和端口，端口可以指定或由系统随机分配。

5. 连接到指定的 IP 地址和端口。

6. 发送数据。

7. Socket 连接使用完毕后，主动关闭。

```js
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
// 创建一个TCPSocket连接，返回一个TCPSocket对象。
let tcp = socket.constructTCPSocketInstance();
tcp.on('message', (value: SocketInfo) => {
  console.log("on message");
  let buffer = value.message;
  let dataView = new DataView(buffer);
  let str = "";
  for (let i = 0; i < dataView.byteLength; ++i) {
    str += String.fromCharCode(dataView.getUint8(i));
  }
  console.log("on connect received:" + str);
});
tcp.on('connect', () => {
  console.log("on connect");
});
tcp.on('close', () => {
  console.log("on close");
});

// 绑定本地IP地址和端口。
let ipAddress : socket.NetAddress = {} as socket.NetAddress;
ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 1234;
tcp.bind(ipAddress, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');

  // 连接到指定的IP地址和端口。
  ipAddress.address = "192.168.xxx.xxx";
  ipAddress.port = 5678;

  let tcpConnect : socket.TCPConnectOptions = {} as socket.TCPConnectOptions;
  tcpConnect.address = ipAddress;
  tcpConnect.timeout = 6000;

  tcp.connect(tcpConnect, (err: BusinessError) => {
    if (err) {
      console.log('connect fail');
      return;
    }
    console.log('connect success');
    // 发送数据
    let tcpSendOptions : socket.TCPSendOptions = {} as socket.TCPSendOptions;
    tcpSendOptions.data = 'Hello, server!';
    tcp.send(tcpSendOptions, (err: BusinessError) => {
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
  tcp.close((err: BusinessError) => {
    console.log('close socket.');
  });
  tcp.off('message');
  tcp.off('connect');
  tcp.off('close');
}, 30 * 1000);
```

## 应用通过 TCP Socket Server 进行数据传输

### 开发步骤

服务端 TCP Socket 流程：

1. import 需要的 socket 模块。
2. 创建一个 TCPSocketServer 连接，返回一个 TCPSocketServer 对象。
3. 绑定本地 IP 地址和端口，监听并接受与此套接字建立的客户端 TCPSocket 连接。
4. 订阅 TCPSocketServer 的 connect 事件，用于监听客户端的连接状态。
5. 客户端与服务端建立连接后，返回一个 TCPSocketConnection 对象，用于与客户端通信。
6. 订阅 TCPSocketConnection 相关的事件，通过 TCPSocketConnection 向客户端发送数据。
7. 主动关闭与客户端的连接。
8. 取消 TCPSocketConnection 和 TCPSocketServer 相关事件的订阅。

```js
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';
// 创建一个TCPSocketServer连接，返回一个TCPSocketServer对象。
let tcpServer = socket.constructTCPSocketServerInstance();
// 绑定本地IP地址和端口，进行监听

let ipAddress : socket.NetAddress = {} as socket.NetAddress;
ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 4651;
tcpServer.listen(ipAddress, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
});

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
// 订阅TCPSocketServer的connect事件
tcpServer.on("connect", (client: socket.TCPSocketConnection) => {
  // 订阅TCPSocketConnection相关的事件
  client.on("close", () => {
    console.log("on close success");
  });
  client.on("message", (value: SocketInfo) => {
    let buffer = value.message;
    let dataView = new DataView(buffer);
    let str = "";
    for (let i = 0; i < dataView.byteLength; ++i) {
      str += String.fromCharCode(dataView.getUint8(i));
    }
    console.log("received message--:" + str);
    console.log("received address--:" + value.remoteInfo.address);
    console.log("received family--:" + value.remoteInfo.family);
    console.log("received port--:" + value.remoteInfo.port);
    console.log("received size--:" + value.remoteInfo.size);
  });

  // 向客户端发送数据
  let tcpSendOptions : socket.TCPSendOptions = {} as socket.TCPSendOptions;
  tcpSendOptions.data = 'Hello, client!';
  client.send(tcpSendOptions, (err: BusinessError) => {
    if (err) {
      console.log("send fail");
      return;
    }
    console.log("send success");
  });

  // 关闭与客户端的连接
  client.close((err: BusinessError) => {
    if (err) {
      console.log("close fail");
      return;
    }
    console.log("close success");
  });

  // 取消TCPSocketConnection相关的事件订阅
  setTimeout(() => {
    client.off("message");
    client.off("close");
  }, 10 * 1000);
});

// 取消TCPSocketServer相关的事件订阅
setTimeout(() => {
  tcpServer.off("connect");
}, 30 * 1000);
```

## 应用通过 TLS Socket 进行加密数据传输

### 开发步骤

客户端 TLS Socket 流程：

1. import 需要的 socket 模块。

2. 绑定服务器 IP 和端口号。

3. 双向认证上传客户端 CA 证书及数字证书；单向认证上传客户端 CA 证书。

4. 创建一个 TLSSocket 连接，返回一个 TLSSocket 对象。

5. （可选）订阅 TLSSocket 相关的订阅事件。

6. 发送数据。

7. TLSSocket 连接使用完毕后，主动关闭。

```js
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
// 创建一个（双向认证）TLS Socket连接，返回一个TLS Socket对象。
let tlsTwoWay = socket.constructTLSSocketInstance();
// 订阅TLS Socket相关的订阅事件
tlsTwoWay.on('message', (value: SocketInfo) => {
  console.log("on message");
  let buffer = value.message;
  let dataView = new DataView(buffer);
  let str = "";
  for (let i = 0; i < dataView.byteLength; ++i) {
    str += String.fromCharCode(dataView.getUint8(i));
  }
  console.log("on connect received:" + str);
});
tlsTwoWay.on('connect', () => {
  console.log("on connect");
});
tlsTwoWay.on('close', () => {
  console.log("on close");
});

// 绑定本地IP地址和端口。
let ipAddress : socket.NetAddress = {} as socket.NetAddress;
ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 4512;
tlsTwoWay.bind(ipAddress, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 1234;

let tlsSecureOption : socket.TLSSecureOptions = {} as socket.TLSSecureOptions;
tlsSecureOption.key = "xxxx";
tlsSecureOption.cert = "xxxx";
tlsSecureOption.ca = ["xxxx"];
tlsSecureOption.password = "xxxx";
tlsSecureOption.protocols = [socket.Protocol.TLSv12];
tlsSecureOption.useRemoteCipherPrefer = true;
tlsSecureOption.signatureAlgorithms = "rsa_pss_rsae_sha256:ECDSA+SHA256";
tlsSecureOption.cipherSuite = "AES256-SHA256";

let tlsTwoWayConnectOption : socket.TLSConnectOptions = {} as socket.TLSConnectOptions;
tlsSecureOption.key = "xxxx";
tlsTwoWayConnectOption.address = ipAddress;
tlsTwoWayConnectOption.secureOptions = tlsSecureOption;
tlsTwoWayConnectOption.ALPNProtocols = ["spdy/1", "http/1.1"];

// 建立连接
tlsTwoWay.connect(tlsTwoWayConnectOption, () => {
  console.error("connect function");
});

// 连接使用完毕后，主动关闭。取消相关事件的订阅。
tlsTwoWay.close((err: BusinessError) => {
  if (err) {
    console.log("close callback error = " + err);
  } else {
    console.log("close success");
  }
  tlsTwoWay.off('message');
  tlsTwoWay.off('connect');
  tlsTwoWay.off('close');
});

// 创建一个（单向认证）TLS Socket连接，返回一个TLS Socket对象。
let tlsOneWay = socket.constructTLSSocketInstance(); // One way authentication

// 订阅TLS Socket相关的订阅事件
tlsTwoWay.on('message', (value: SocketInfo) => {
  console.log("on message");
  let buffer = value.message;
  let dataView = new DataView(buffer);
  let str = "";
  for (let i = 0; i < dataView.byteLength; ++i) {
    str += String.fromCharCode(dataView.getUint8(i));
  }
  console.log("on connect received:" + str);
});
tlsTwoWay.on('connect', () => {
  console.log("on connect");
});
tlsTwoWay.on('close', () => {
  console.log("on close");
});

// 绑定本地IP地址和端口。
ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 5445;
tlsOneWay.bind(ipAddress, (err:BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 8789;
let tlsOneWaySecureOption : socket.TLSSecureOptions = {} as socket.TLSSecureOptions;
tlsOneWaySecureOption.ca = ["xxxx", "xxxx"];
tlsOneWaySecureOption.cipherSuite = "AES256-SHA256";

let tlsOneWayConnectOptions: socket.TLSConnectOptions = {} as socket.TLSConnectOptions;
tlsOneWayConnectOptions.address = ipAddress;
tlsOneWayConnectOptions.secureOptions = tlsOneWaySecureOption;

// 建立连接
tlsOneWay.connect(tlsOneWayConnectOptions, () => {
  console.error("connect function");
});

// 连接使用完毕后，主动关闭。取消相关事件的订阅。
tlsTwoWay.close((err: BusinessError) => {
  if (err) {
    console.log("close callback error = " + err);
  } else {
    console.log("close success");
  }
  tlsTwoWay.off('message');
  tlsTwoWay.off('connect');
  tlsTwoWay.off('close');
});
```

## 相关实例

针对 Socket 连接开发，有以下相关实例可供参考：

- [网络管理-Socket 连接（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/BasicFeature/Connectivity/Socket)
