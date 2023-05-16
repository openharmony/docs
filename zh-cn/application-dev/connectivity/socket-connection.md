# Socket连接

## 简介

Socket连接主要是通过Socket进行数据传输，支持TCP/UDP/TLS协议。

## 基本概念

- Socket：套接字，就是对网络中不同主机上的应用进程之间进行双向通信的端点的抽象。
- TCP：传输控制协议(Transmission Control Protocol)。是一种面向连接的、可靠的、基于字节流的传输层通信协议。
- UDP：用户数据报协议协议(User Datagram Protocol)。是一个简单的面向消息的传输层，不需要连接。
- TLS：安全传输层协议(Transport Layer Security)。用于在两个通信应用程序之间提供保密性和数据完整性。

## 场景介绍

应用通过Socket进行数据传输，支持TCP/UDP/TLS协议。主要场景有：

- 应用通过TCP/UDP Socket进行数据传输
- 应用通过TLS Socket进行加密数据传输

## 接口说明

完整的JS API说明以及实例代码请参考：[Socket连接](../reference/apis/js-apis-socket.md)。

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

TLS Socket连接主要由tls_socket模块提供。具体接口说明如下表。

| 接口名 | 功能描述 |
| -------- | -------- |
| constructTLSSocketInstance() | 创建一个TLSSocket对象。 |
| bind() | 绑定IP地址和端口号。 |
| close(type:&nbsp;'error') | 关闭连接。 |
| connect() | 连接到指定的IP地址和端口。 |
| getCertificate() | 返回表示本地证书的对象。 |
| getCipherSuite() | 返回包含协商的密码套件信息的列表。 |
| getProtocol() | 返回包含当前连接协商的SSL/TLS协议版本的字符串。 |
| getRemoteAddress() | 获取TLSSocket连接的对端地址。 |
| getRemoteCertificate() | 返回表示对等证书的对象。 |
| getSignatureAlgorithms() | 在服务器和客户端之间共享的签名算法列表，按优先级降序排列。 |
| getState() | 获取TLSSocket连接的状态。 |
| off(type:&nbsp;'close') | 取消订阅TLSSocket连接的关闭事件。 |
| off(type:&nbsp;'error') | 取消订阅TLSSocket连接的Error事件。 |
| off(type:&nbsp;'message') | 取消订阅TLSSocket连接的接收消息事件。 |
| on(type:&nbsp;'close') | 订阅TLSSocket连接的关闭事件。 |
| on(type:&nbsp;'error') | 订阅TLSSocket连接的Error事件。 |
| on(type:&nbsp;'message') | 订阅TLSSocket连接的接收消息事件。 |
| send() | 发送数据。 |
| setExtraOptions() | 设置TLSSocket连接的其他属性。 |

## 应用TCP/UDP协议进行通信

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
  for (let i = 0; i < dataView.byteLength; ++i) {
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

// 绑定IP地址和端口。
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

## 应用通过TLS Socket进行加密数据传输

### 开发步骤

客户端TLS Socket流程：

1. import需要的socket模块。

2. 绑定服务器IP和端口号。

3. 双向认证上传客户端CA证书及数字证书；单向认证上传客户端CA证书。

4. 创建一个TLSSocket连接，返回一个TLSSocket对象。

5. （可选）订阅TLSSocket相关的订阅事件。

6. 发送数据。

7. TLSSocket连接使用完毕后，主动关闭。

```js
// 创建一个（双向认证）TLS Socket连接，返回一个TLS Socket对象。
let tlsTwoWay = socket.constructTLSSocketInstance();

// 订阅TLS Socket相关的订阅事件
tlsTwoWay.on('message', value => {
  console.log("on message")
  let buffer = value.message
  let dataView = new DataView(buffer)
  let str = ""
  for (let i = 0; i < dataView.byteLength; ++i) {
    str += String.fromCharCode(dataView.getUint8(i))
  }
  console.log("on connect received:" + str)
});
tlsTwoWay.on('connect', () => {
  console.log("on connect")
});
tlsTwoWay.on('close', () => {
  console.log("on close")
});

// 绑定本地IP地址和端口。
tlsTwoWay.bind({ address: '192.168.xxx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

// 设置通信过程中使用参数
let options = {
  ALPNProtocols: ["spdy/1", "http/1.1"],

  // 连接到指定的IP地址和端口。
  address: {
    address: "192.168.xx.xxx",
    port: xxxx, // 端口
    family: 1,
  },

  // 设置用于通信过程中完成校验的参数。
  secureOptions: {
    key: "xxxx",                            // 密钥
    cert: "xxxx",                           // 数字证书
    ca: ["xxxx"],                           // CA证书
    passwd: "xxxx",                         // 生成密钥时的密码
    protocols: [socket.Protocol.TLSv12],    // 通信协议
    useRemoteCipherPrefer: true,            // 是否优先使用对端密码套件
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",    // 签名算法
    cipherSuite: "AES256-SHA256",           // 密码套件
  },
};

// 建立连接
tlsTwoWay.connect(options, (err, data) => {
  console.error(err);
  console.log(data);
});

// 连接使用完毕后，主动关闭。取消相关事件的订阅。
tlsTwoWay.close((err) => {
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
tlsTwoWay.on('message', value => {
  console.log("on message")
  let buffer = value.message
  let dataView = new DataView(buffer)
  let str = ""
  for (let i = 0; i < dataView.byteLength; ++i) {
    str += String.fromCharCode(dataView.getUint8(i))
  }
  console.log("on connect received:" + str)
});
tlsTwoWay.on('connect', () => {
  console.log("on connect")
});
tlsTwoWay.on('close', () => {
  console.log("on close")
});

// 绑定本地IP地址和端口。
tlsOneWay.bind({ address: '192.168.xxx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

// 设置通信过程中使用参数
let oneWayOptions = {
  address: {
    address: "192.168.xxx.xxx",
    port: xxxx,
    family: 1,
  },
  secureOptions: {
    ca: ["xxxx", "xxxx"],            // CA证书
    cipherSuite: "AES256-SHA256",   // 密码套件
  },
};

// 建立连接
tlsOneWay.connect(oneWayOptions, (err, data) => {
  console.error(err);
  console.log(data);
});

// 连接使用完毕后，主动关闭。取消相关事件的订阅。
tlsTwoWay.close((err) => {
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

