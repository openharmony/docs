# 使用Socket访问网络

## 简介

Socket连接主要是通过Socket进行数据传输，支持TCP/UDP/Multicast/TLS协议。

> **说明：**
>
> 应用退后台后，Socket可能会断开，当应用重新回到前台，发生通信失败时，需匹配错误码并重新创建新的TCP/UDP Socket。

## 基本概念

- Socket：套接字，就是对网络中不同主机上的应用进程之间进行双向通信的端点的抽象。
- TCP：传输控制协议(Transmission Control Protocol)，是一种面向连接的、可靠的、基于字节流的传输层通信协议。
- UDP：用户数据报协议(User Datagram Protocol)，是一个简单的面向消息的传输层，不需要连接。
- Multicast：多播，基于UDP的一种通信模式，用于实现组内所有设备之间广播形式的通信。
- LocalSocket：本地套接字，IPC(Inter-Process Communication)进程间通信的一种，实现设备内进程之间相互通信，无需网络。
- TLS：安全传输层协议(Transport Layer Security)，用于在两个通信应用程序之间提供保密性和数据完整性。

## 场景介绍

应用通过Socket进行数据传输，支持TCP/UDP/Multicast/TLS协议。主要场景有：

- 在TCP/UDP传输的客户端（UDP本身并没有客户端和服务器端的明确区分，此处描述UDP传输的客户端是指主动向服务器发送数据的一方），应用通过TCP/UDP Socket进行数据传输
- 在TCP传输的服务器端，应用通过TCP Socket Server进行数据传输
- 多播通信场景，应用通过Multicast Socket进行数据传输
- 同一台主机上不同进程之间传输的客户端，应用通过Local Socket进行数据传输
- 同一台主机上不同进程之间传输的服务器端，应用通过Local Socket Server进行数据传输
- 数据加密传输时，客户端侧通过TLS Socket进行加密数据传输
- 数据加密传输时，服务器侧通过TLS Socket Server进行加密数据传输

>**说明：** 
>
>在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

## 应用TCP/UDP协议进行通信

UDP与TCP流程大体类似，下面以TCP为例：

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 创建一个TCPSocket连接，返回一个TCPSocket对象。

    ```ts
    // 创建一个TCPSocket连接，返回一个TCPSocket对象。
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
    ```

3. （可选）订阅TCPSocket相关的订阅事件。

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }

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
    ```

4. 绑定IP地址和端口，端口可以指定或由系统随机分配，绑定成功后可以连接到指定的IP地址和端口，连接成功后可以发送数据。

    ```ts
    // 绑定本地IP地址和端口。
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 1234;
    tcp.bind(ipAddress, (err: BusinessError) => {
      if (err) {
        console.error('bind fail');
        return;
      }
      console.log('bind success');

      // bind成功后，连接到指定的IP地址和端口。
      ipAddress.address = "192.168.xxx.xxx";
      ipAddress.port = 5678;

      let tcpConnect : socket.TCPConnectOptions = {} as socket.TCPConnectOptions;
      tcpConnect.address = ipAddress;
      tcpConnect.timeout = 6000;

      tcp.connect(tcpConnect).then(() => {
        console.log('connect success');
        let tcpSendOptions: socket.TCPSendOptions = {
          data: 'Hello, server!'
        }
        // 连接成功之后，发送数据。
        tcp.send(tcpSendOptions).then(() => {
          console.log('send success');
        }).catch((err: BusinessError) => {
          console.error('send fail');
        });
      }).catch((err: BusinessError) => {
        console.error('connect fail');
      });
    });
    ```

5. Socket连接使用完毕后，主动关闭。

    ```ts
    // 连接使用完毕后，主动关闭。取消相关事件的订阅。
    setTimeout(() => {
      tcp.close().then(() => {
        console.log('close success');
      }).catch((err: BusinessError) => {
        console.error('close fail');
      });
      tcp.off('message');
      tcp.off('connect');
      tcp.off('close');
    }, 30 * 1000);
    ```

## 应用通过TCP Socket Server进行数据传输

服务端TCP Socket流程：

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 创建一个TCPSocketServer连接，返回一个TCPSocketServer对象。

    ```ts
    // 创建一个TCPSocketServer连接，返回一个TCPSocketServer对象。
    let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
    ```

3. 绑定本地IP地址和端口，监听并接受与此套接字建立的客户端TCPSocket连接。

    ```ts
    // 绑定本地IP地址和端口，进行监听。
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 4651;
    tcpServer.listen(ipAddress).then(() => {
      console.log('listen success');
    }).catch((err: BusinessError) => {
      console.error('listen fail');
    });
    ```

4. 订阅TCPSocketServer的connect事件，用于监听客户端的连接状态。客户端与服务端建立连接后，会返回一个TCPSocketConnection对象，用于与客户端通信，通过该对象可以订阅与客户端的连接关闭、客户端数据接收事件，也可以进行向客户端发送数据、关闭与客户端的连接、取消订阅TCPSocketConnection相关事件的动作。
   

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    // 订阅TCPSocketServer的connect事件，客户端与服务端建立连接后，返回一个TCPSocketConnection对象，用于与客户端通信。
    tcpServer.on("connect", (client: socket.TCPSocketConnection) => {
      // client即为建立连接后获取到的连接对象，可以通过该对象订阅TCPSocketConnection相关的事件。
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

      // 向客户端发送数据。
      let tcpSendOptions : socket.TCPSendOptions = {} as socket.TCPSendOptions;
      tcpSendOptions.data = 'Hello, client!';
      client.send(tcpSendOptions).then(() => {
        console.log('send success');
      }).catch((err: Object) => {
        console.error('send fail: ' + JSON.stringify(err));
      });

      // 关闭与客户端的连接。
      client.close().then(() => {
        console.log('close success');
      }).catch((err: BusinessError) => {
        console.error('close fail');
      });

      // 取消TCPSocketConnection相关的事件订阅。
      setTimeout(() => {
        client.off("message");
        client.off("close");
      }, 10 * 1000);
    });
    ```

5. 取消TCPSocketServer相关事件的订阅。

    ```ts
    // 取消TCPSocketServer相关的事件订阅。
    setTimeout(() => {
      tcpServer.off("connect");
    }, 30 * 1000);
    ```

## 应用通过Multicast Socket进行数据传输

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    ```

2. 创建multicastSocket多播对象。

    ```ts
    // 创建Multicast对象。
    let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
    ```

3. 指定多播IP与端口，加入多播组。

    ```ts
    let addr : socket.NetAddress = {
      address: '239.255.0.1',
      port: 32123,
      family: 1
    }

    // 加入多播组。
    multicast.addMembership(addr).then(() => {
      console.log('addMembership success');
    }).catch((err: Object) => {
      console.error('addMembership fail');
    });
    ```

4. 开启消息message监听。

    ```ts
    // 开启监听消息数据，将接收到的ArrayBuffer类型数据转换为String。
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    multicast.on('message', (data: SocketInfo) => {
      console.info('接收的数据: ' + JSON.stringify(data))
      const uintArray = new Uint8Array(data.message)
      let str = ''
      for (let i = 0; i < uintArray.length; ++i) {
        str += String.fromCharCode(uintArray[i])
      }
      console.info(str)
    })
    ```

5. 发送数据，数据以广播的形式传输，同一多播组中已经开启消息message监听的多播对象都会接收到数据。

    ```ts
    // 发送数据。
    multicast.send({ data:'Hello12345', address: addr }).then(() => {
      console.log('send success');
    }).catch((err: Object) => {
      console.error('send fail, ' + JSON.stringify(err));
    });
    ```

6. 关闭message消息的监听。

    ```ts
    // 关闭消息的监听。
    multicast.off('message')
    ```

7. 退出多播组。

    ```ts
    // 退出多播组。
    multicast.dropMembership(addr).then(() => {
      console.log('drop membership success');
    }).catch((err: Object) => {
      console.error('drop membership fail');
    });
    ```

## 应用通过LocalSocket进行数据传输

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { common } from '@kit.AbilityKit';
    ```

2. 使用constructLocalSocketInstance接口，创建一个LocalSocket客户端对象。

    ```ts
    // 创建一个LocalSocket连接，返回一个LocalSocket对象。
    let client: socket.LocalSocket = socket.constructLocalSocketInstance();
    ```

3. 注册LocalSocket的消息(message)事件，以及一些其它事件(可选)。

    ```ts
    client.on('message', (value: socket.LocalSocketMessageInfo) => {
      const uintArray = new Uint8Array(value.message)
      let messageView = '';
      for (let i = 0; i < uintArray.length; i++) {
        messageView += String.fromCharCode(uintArray[i]);
      }
      console.log('total receive: ' + JSON.stringify(value));
      console.log('message information: ' + messageView);
    });
    client.on('connect', () => {
      console.log("on connect");
    });
    client.on('close', () => {
      console.log("on close");
    });
    ```

4. 连接到指定的本地套接字文件路径，连接成功之后可以发送数据。

    <!--code_no_check-->
    ```ts
    // 传入指定的本地套接字路径，连接服务端。
    let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
    let sandboxPath: string = context.filesDir + '/testSocket';
    let localAddress : socket.LocalAddress = {
      address: sandboxPath
    }
    let connectOpt: socket.LocalConnectOptions = {
      address: localAddress,
      timeout: 6000
    }
    let sendOpt: socket.LocalSendOptions = {
      data: 'Hello world!'
    }
    client.connect(connectOpt).then(() => {
      console.log('connect success')
      // 发送数据。
      client.send(sendOpt).then(() => {
      console.log('send success')
      }).catch((err: Object) => {
        console.error('send failed: ' + JSON.stringify(err))
      })
    }).catch((err: Object) => {
      console.error('connect fail: ' + JSON.stringify(err));
    });
    ```

5. Socket连接使用完毕后，取消事件的注册，并关闭套接字。

    ```ts
    // 当不需要再连接服务端，需要断开且取消事件的监听时。
    client.off('message');
    client.off('connect');
    client.off('close');
    client.close().then(() => {
      console.log('close client success')
    }).catch((err: Object) => {
      console.error('close client err: ' + JSON.stringify(err))
    })
    ```

## 应用通过Local Socket Server进行数据传输

服务端LocalSocket Server的主要流程包括：

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { common } from '@kit.AbilityKit';
    ```

2. 使用constructLocalSocketServerInstance接口，创建一个 LocalSocketServer 服务端对象。

    ```ts
    // 创建一个LocalSocketServer连接，返回一个LocalSocketServer对象。
    let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
    ```

3. 启动服务，绑定本地套接字路径，创建出本地套接字文件，监听客户端的连接请求。

    <!--code_no_check-->
    ```ts
    // 创建并绑定本地套接字文件testSocket，进行监听。
    let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
    let sandboxPath: string = context.filesDir + '/testSocket';
    let listenAddr: socket.LocalAddress = {
      address: sandboxPath
    }
    server.listen(listenAddr).then(() => {
      console.log("listen success");
    }).catch((err: Object) => {
      console.error("listen fail: " + JSON.stringify(err));
    });
    ```

4. 注册LocalSocket的客户端连接事件，以及一些其它事件(可选)，在客户端连接成功时，可以获取到客户端连接会话对象LocalSocketConnection，通过该会话对象可以订阅客户端收到消息(message)事件，以及一些其它事件(可选)，通过该会话对象也可发起主动向客户端发送数据，主动关闭与客户端的连接的动作，订阅事件不再需要时，可以取消LocalSocketConnection相关的事件订阅。

    ```ts
    // 订阅LocalSocketServer的connect事件。
    server.on('connect', (connection: socket.LocalSocketConnection) => {
      // 订阅LocalSocketConnection相关的事件。
      connection.on('error', (err: Object) => {
        console.log("on error success");
      });
      connection.on('message', (value: socket.LocalSocketMessageInfo) => {
        const uintArray = new Uint8Array(value.message);
        let messageView = '';
        for (let i = 0; i < uintArray.length; i++) {
          messageView += String.fromCharCode(uintArray[i]);
        }
        console.log('total: ' + JSON.stringify(value));
        console.log('message information: ' + messageView);
      });

      connection.on('error', (err: Object) => {
        console.error("err:" + JSON.stringify(err));
      })

      // 向客户端发送数据。
      let sendOpt : socket.LocalSendOptions = {
        data: 'Hello world!'
      };
      connection.send(sendOpt).then(() => {
        console.log('send success');
      }).catch((err: Object) => {
        console.log('send failed: ' + JSON.stringify(err));
      })

      // 关闭与客户端的连接。
      connection.close().then(() => {
        console.log('close success');
      }).catch((err: Object) => {
        console.error('close failed: ' + JSON.stringify(err));
      });

      // 取消LocalSocketConnection相关的事件订阅。
      connection.off('message');
      connection.off('error');
    });
    ```

5.  取消LocalSocketServer相关事件的订阅。

    ```ts
    // 取消LocalSocketServer相关的事件订阅。
    server.off('connect');
    server.off('error');
    ```

## 应用通过TLS Socket进行加密数据传输

客户端TLS Socket流程（双向认证）包括：

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 创建一个双向认证TLSSocket连接，返回一个TLSSocket对象。

    ```ts
    // 创建一个（双向认证）TLS Socket连接，返回一个TLS Socket对象。
    let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance();
    ```

3. 绑定服务器IP地址和端口，确保bind成功后，再订阅TLS Socket相关的订阅事件。

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    // 绑定本地IP地址和端口。
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 4512;
    tlsTwoWay.bind(ipAddress, (err: BusinessError) => {
      if (err) {
        console.error('bind fail');
        return;
      }
      console.log('bind success');
      // 确保bind成功后，再订阅TLS Socket相关的订阅事件
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
    });
    ```

4. 双向认证上传客户端CA证书及数字证书，并建立连接，连接建立成功后可以发送数据。

    ```ts
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
    tlsTwoWayConnectOption.address = ipAddress;
    tlsTwoWayConnectOption.secureOptions = tlsSecureOption;
    tlsTwoWayConnectOption.ALPNProtocols = ["spdy/1", "http/1.1"];

    // 建立连接，连接建立成功后，可以发送数据。
    tlsTwoWay.connect(tlsTwoWayConnectOption).then(() => {
      console.log("connect successfully");
      // 发送数据。
      tlsTwoWay.send("xxxx").then(() => {
        console.log("send successfully");
      }).catch((err: BusinessError) => {
        console.error("send failed " + JSON.stringify(err));
      });
    }).catch((err: BusinessError) => {
      console.error("connect failed " + JSON.stringify(err));
    });
    ```

5. TLSSocket连接使用完毕后，主动关闭。

    ```ts
    // 连接使用完毕后，主动关闭，并取消相关事件的订阅。
    tlsTwoWay.close((err: BusinessError) => {
      if (err) {
        console.error("close callback error = " + err);
      } else {
        console.log("close success");
      }
      tlsTwoWay.off('message');
      tlsTwoWay.off('connect');
      tlsTwoWay.off('close');
    });
    ```

客户端TLS Socket流程（单向认证）包括：

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 创建一个单向认证TLSSocket连接，返回一个TLSSocket对象。

    ```ts
    // 创建一个（单向认证）TLS Socket连接，返回一个TLS Socket对象。
    let tlsOneWay: socket.TLSSocket = socket.constructTLSSocketInstance(); // One way authentication
    ```

3. 绑定服务器IP地址和端口，确保bind成功后，再订阅TLS Socket相关的订阅事件。。

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    // 绑定本地IP地址和端口。
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 5445;
    tlsOneWay.bind(ipAddress, (err:BusinessError) => {
      if (err) {
        console.error('bind fail');
        return;
      }
      console.log('bind success');
      // 订阅TLS Socket相关的订阅事件
      tlsOneWay.on('message', (value: SocketInfo) => {
        console.log("on message");
        let buffer = value.message;
        let dataView = new DataView(buffer);
        let str = "";
        for (let i = 0; i < dataView.byteLength; ++i) {
          str += String.fromCharCode(dataView.getUint8(i));
        }
        console.log("on connect received:" + str);
      });
      tlsOneWay.on('connect', () => {
        console.log("on connect");
      });
      tlsOneWay.on('close', () => {
        console.log("on close");
      });
    });
    ```

4. 单向认证上传客户端CA证书，并建立连接。

    ```ts
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 8789;
    let tlsOneWaySecureOption : socket.TLSSecureOptions = {} as socket.TLSSecureOptions;
    tlsOneWaySecureOption.ca = ["xxxx", "xxxx"];
    tlsOneWaySecureOption.cipherSuite = "AES256-SHA256";

    let tlsOneWayConnectOptions: socket.TLSConnectOptions = {} as socket.TLSConnectOptions;
    tlsOneWayConnectOptions.address = ipAddress;
    tlsOneWayConnectOptions.secureOptions = tlsOneWaySecureOption;

    // 建立连接，连接建立成功后，可以发送数据。
    tlsOneWay.connect(tlsOneWayConnectOptions).then(() => {
      console.log("connect successfully");
      // 发送数据。
      tlsOneWay.send("xxxx").then(() => {
        console.log("send successfully");
      }).catch((err: BusinessError) => {
        console.error("send failed " + JSON.stringify(err));
      });
    }).catch((err: BusinessError) => {
      console.error("connect failed " + JSON.stringify(err));
    });
    ```

5. TLSSocket连接使用完毕后，主动关闭。

    ```ts
    // 连接使用完毕后，主动关闭，并取消相关事件的订阅。
    tlsOneWay.close((err: BusinessError) => {
      if (err) {
        console.error("close callback error = " + err);
      } else {
        console.log("close success");
      }
      tlsOneWay.off('message');
      tlsOneWay.off('connect');
      tlsOneWay.off('close');
    });
    ```

## 应用通过将TCP Socket升级为TLS Socket进行加密数据传输

客户端TCP Socket升级为TLS Socket流程，以TLS Socket双向认证为例：

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 参考[应用 TCP/UDP 协议进行通信](#应用tcpudp协议进行通信)，创建一个TCPSocket连接。

    ```ts
    // 创建一个TCPSocket连接，返回一个TCPSocket对象。
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
    ```

3. （可选）订阅TCPSocket相关的订阅事件。

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }

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
    ```

4. 绑定本地IP地址和端口，绑定成功后，连接到服务器端IP地址和端口，连接成功后使用该TCPSocket对象创建TLSSocket，配置双向认证上传客户端 CA 证书及数字证书，可以建立TLSSocket连接，连接使用完毕后，主动关闭并取消相关事件的订阅。。

    ```ts
    // 绑定本地IP地址和端口。
    let ipAddress: socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 1234;
    tcp.bind(ipAddress, (err: BusinessError) => {
      if (err) {
        console.error('bind fail');
        return;
      }
      console.log('bind success');

      // 连接到服务器端指定的IP地址和端口。
      ipAddress.address = "192.168.xxx.xxx";
      ipAddress.port = 443;

      let tcpConnect: socket.TCPConnectOptions = {} as socket.TCPConnectOptions;
      tcpConnect.address = ipAddress;
      tcpConnect.timeout = 6000;

      tcp.connect(tcpConnect, (err: BusinessError) => {
        if (err) {
          console.error('connect fail');
          return;
        }
        console.log('connect success');

        // 确保TCPSocket已连接后，将其升级为TLSSocket连接。
        let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance(tcp);
        // 订阅TLSSocket相关的订阅事件。
        tlsTwoWay.on('message', (value: SocketInfo) => {
          console.log("tls on message");
          let buffer = value.message;
          let dataView = new DataView(buffer);
          let str = "";
          for (let i = 0; i < dataView.byteLength; ++i) {
            str += String.fromCharCode(dataView.getUint8(i));
          }
          console.log("tls on connect received:" + str);
        });
        tlsTwoWay.on('connect', () => {
          console.log("tls on connect");
        });
        tlsTwoWay.on('close', () => {
          console.log("tls on close");
        });

        // 配置TLSSocket目的地址、证书等信息。
        ipAddress.address = "192.168.xxx.xxx";
        ipAddress.port = 1234;

        let tlsSecureOption: socket.TLSSecureOptions = {} as socket.TLSSecureOptions;
        tlsSecureOption.key = "xxxx";
        tlsSecureOption.cert = "xxxx";
        tlsSecureOption.ca = ["xxxx"];
        tlsSecureOption.password = "xxxx";
        tlsSecureOption.protocols = [socket.Protocol.TLSv12];
        tlsSecureOption.useRemoteCipherPrefer = true;
        tlsSecureOption.signatureAlgorithms = "rsa_pss_rsae_sha256:ECDSA+SHA256";
        tlsSecureOption.cipherSuite = "AES256-SHA256";

        let tlsTwoWayConnectOption: socket.TLSConnectOptions = {} as socket.TLSConnectOptions;
        tlsSecureOption.key = "xxxx";
        tlsTwoWayConnectOption.address = ipAddress;
        tlsTwoWayConnectOption.secureOptions = tlsSecureOption;
        tlsTwoWayConnectOption.ALPNProtocols = ["spdy/1", "http/1.1"];

        // 建立TLSSocket连接。
        tlsTwoWay.connect(tlsTwoWayConnectOption, () => {
          console.log("tls connect success");

          // 连接使用完毕后，主动关闭。取消相关事件的订阅。
          tlsTwoWay.close((err: BusinessError) => {
            if (err) {
              console.error("tls close callback error = " + err);
            } else {
              console.log("tls close success");
            }
            tlsTwoWay.off('message');
            tlsTwoWay.off('connect');
            tlsTwoWay.off('close');
          });
        });
      });
    });
    ```

## 应用通过TLS Socket Server进行加密数据传输

服务端TLS Socket Server流程：

1. 导入所需的socket模块。

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 创建一个TLSSocketServer连接，返回一个TLSSocketServer对象。

    ```ts
    let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
    ```

3. 启动服务，绑定 IP 和端口号，监听客户端连接，创建并初始化TLS会话，加载证书密钥并验证。

    ```ts
    let netAddress: socket.NetAddress = {
      address: '192.168.xx.xxx',
      port: 8080
    }

    let tlsSecureOptions: socket.TLSSecureOptions = {
      key: "xxxx",
      cert: "xxxx",
      ca: ["xxxx"],
      password: "xxxx",
      protocols: socket.Protocol.TLSv12,
      useRemoteCipherPrefer: true,
      signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
      cipherSuite: "AES256-SHA256"
    }

    let tlsConnectOptions: socket.TLSConnectOptions = {
      address: netAddress,
      secureOptions: tlsSecureOptions,
      ALPNProtocols: ["spdy/1", "http/1.1"]
    }

    tlsServer.listen(tlsConnectOptions).then(() => {
      console.log("listen callback success");
    }).catch((err: BusinessError) => {
      console.error("failed" + err);
    });
    ```

4. 订阅TLSSocketServer的连接事件，收到客户端连接，通过回调得到TLSSocketConnection对象，通过该对象可以实现订阅TLSSocketConnection相关的事件、向客户端发送数的动作，TLSSocketConnection连接使用完毕后，需要主动断开连接，进行取消订阅回调的动作。

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    let callback = (value: SocketInfo) => {
      let messageView = '';
      for (let i: number = 0; i < value.message.byteLength; i++) {
        let uint8Array = new Uint8Array(value.message)
        let messages = uint8Array[i]
        let message = String.fromCharCode(messages);
        messageView += message;
      }
      console.log('on message message: ' + JSON.stringify(messageView));
      console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
    }
    tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
      client.on('message', callback);

      // 发送数据。
      client.send('Hello, client!').then(() => {
        console.log('send success');
      }).catch((err: BusinessError) => {
        console.error('send fail');
      });

      // 断开连接。
      client.close().then(() => {
        console.log('close success');
      }).catch((err: BusinessError) => {
        console.error('close fail');
      });

      // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
      client.off('message', callback);
      client.off('message');
    });
    ```

5. 取消订阅TLSSocketServer的相关事件。

    ```ts
    // 取消订阅tlsServer的相关事件
    tlsServer.off('connect');
    ```

## 相关实例

针对Socket连接开发，有以下相关实例可供参考：

- [网络管理-Socket连接（ArkTS）（API9）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Socket)
