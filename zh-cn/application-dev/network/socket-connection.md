# 使用Socket访问网络
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

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

    <!-- @[tcp_client_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->
    
    ``` TypeScript
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. 创建一个TCPSocket连接，返回一个TCPSocket对象。

    <!-- @[tcp_client_worker_tcpClient](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->
    
    ``` TypeScript
    // 创建一个TCPSocket连接，返回一个TCPSocket对象。
    let tcpClient: socket.TCPSocket = socket.constructTCPSocketInstance();
    ```

3. （可选）订阅TCPSocket相关的订阅事件。

      <!-- @[tcp_client_worker_socketInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->
      
      ``` TypeScript
      class SocketInfo {
        public message: ArrayBuffer = new ArrayBuffer(1);
        public remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
      }
      
      tcpClient.on('message', (value: SocketInfo) => {
        hilog.info(0x0000, 'testTag', 'on message');
        let buffer = value.message;
        let dataView = new DataView(buffer);
        let str = '';
        for (let i = 0; i < dataView.byteLength; ++i) {
          str += String.fromCharCode(dataView.getUint8(i));
        }
        hilog.info(0x0000, 'testTag', 'on connect received:' + str);
      });
      
      tcpClient.on('connect', () => {
        hilog.info(0x0000, 'testTag', 'on connect');
      });
      
      tcpClient.on('close', () => {
        hilog.info(0x0000, 'testTag', 'on close');
      });
      ```

4. 绑定IP地址和端口，端口可以指定或由系统随机分配，绑定成功后可以连接到指定的IP地址和端口，连接成功后可以发送数据。
   ```ts
    // 绑定本地IP地址和端口。
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 1234;

    // bind成功后，连接到指定的IP地址和端口。
    let netAddress: socket.NetAddress = {} as socket.NetAddress;
    netAddress.address = "192.168.xxx.xxx";
    netAddress.port = 5678;
    ```
    <!-- @[tcp_client_worker_ipAddress](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->
    
    ``` TypeScript
      // 绑定本地IP地址和端口。
    // ···
      tcpClient.bind(ipAddress, (err: BusinessError) => {
        if (err) {
          hilog.error(0x0000, 'testTag', 'bind fail');
          return;
        }
        hilog.info(0x0000, 'testTag', 'bind success');
    
      // bind成功后，连接到指定的IP地址和端口。
        // ···
        let tcpConnect: socket.TCPConnectOptions = {
          address: netAddress,
          timeout: 6000 // 超时时间设置
        };
        tcpClient.connect(tcpConnect).then(() => {
          hilog.info(0x0000, 'testTag', 'connect success');
          let tcpSendOptions: socket.TCPSendOptions = {
            data: tcpMessage.message!
          };
          tcpClient.send(tcpSendOptions).then(() => {
            hilog.info(0x0000, 'testTag', 'send success');
            // ···
          }).catch(() => {
            hilog.info(0x0000, 'testTag', 'send fail');
            // ···
          });
        }).catch((err: BusinessError) => {
          hilog.error(0x0000, 'testTag', 'connect fail');
        });
      })
    ```

5. Socket连接使用完毕后，主动关闭。

    <!-- @[tcp_client_worker_disConnect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->
    
    ``` TypeScript
    // 连接使用完毕后，主动关闭。取消相关事件的订阅。
    setTimeout(() => {
      tcpClient.close().then(() => {
      // ···
        hilog.info(0x0000, 'testTag', 'close success');
      }).catch((err: BusinessError) => {
      // ···
        hilog.error(0x0000, 'testTag', 'close fail');
      });
      tcpClient.off('message');
      tcpClient.off('connect');
      tcpClient.off('close');
    }, 30 * 1000);
    ```

## 应用通过TCP Socket Server进行数据传输

服务端TCP Socket流程：

1. 导入所需的socket模块。

    <!-- @[tcp_server_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->
    
    ``` TypeScript
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. 创建一个TCPSocketServer连接，返回一个TCPSocketServer对象。

    <!-- @[tcp_server_worker_tcpServer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->
    
    ``` TypeScript
    // 创建一个TCPSocketServer连接，返回一个TCPSocketServer对象。
    let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
    ```

3. 绑定本地IP地址和端口，监听并接受与此套接字建立的客户端TCPSocket连接。
   ```ts
    // 绑定本地IP地址和端口，进行监听。
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 4651;
    ```
    <!-- @[tcp_server_worker_ipAddress](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->
    
    ``` TypeScript
    // 绑定本地IP地址和端口，进行监听。
    tcpServer.listen(ipAddress).then(() => {
      hilog.info(0x0000, 'testTag', 'listen success');
      // ···
    }).catch(() => {
      hilog.info(0x0000, 'testTag', 'listen fail');
      // ···
    });
    ```

4. 订阅TCPSocketServer的connect事件，用于监听客户端的连接状态。客户端与服务端建立连接后，会返回一个TCPSocketConnection对象，用于与客户端通信，通过该对象可以订阅与客户端的连接关闭、客户端数据接收事件，也可以进行向客户端发送数据、关闭与客户端的连接、取消订阅TCPSocketConnection相关事件的动作。

    <!-- @[tcp_server_worker_socketInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->
    
    ``` TypeScript
      class SocketInfo {
        public message: ArrayBuffer = new ArrayBuffer(1);
        public remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
      }
      // 订阅TCPSocketServer的connect事件
      // 客户端与服务端建立连接后，返回一个TCPSocketConnection对象，用于与客户端通信。
      tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
        // ···
    
        // client即为建立连接后获取到的连接对象，可以通过该对象订阅TCPSocketConnection相关的事件。
        client.on('close', () => {
          hilog.info(0x0000, 'testTag', 'client on close success');
        // ···
        });
    
        client.on('message', (value: SocketInfo) => {
          let buffer = value.message;
          let dataView = new DataView(buffer);
          let str = '';
          for (let i = 0; i < dataView.byteLength; ++i) {
            str += String.fromCharCode(dataView.getUint8(i));
          }
          hilog.info(0x0000, 'testTag', 'received message--:' + str);
          hilog.info(0x0000, 'testTag', 'received address--:' + value.remoteInfo.address);
          hilog.info(0x0000, 'testTag', 'received family--:' + value.remoteInfo.family);
          hilog.info(0x0000, 'testTag', 'received port--:' + value.remoteInfo.port);
          hilog.info(0x0000, 'testTag', 'received size--:' + value.remoteInfo.size);
        // ···
        });
      });
    // ···
        let tcpSendOptions: socket.TCPSendOptions = {} as socket.TCPSendOptions;
        // 用户可根据需要自行定义发送数据
        tcpSendOptions.data = tcpMessage.message!;
    
        client.send(tcpSendOptions).then(() => {
          hilog.info(0x0000, 'testTag', 'send success');
        // ···
        }).catch((err: Object) => {
          hilog.error(0x0000, 'testTag', 'send fail: ' + JSON.stringify(err));
        // ···
        });
        // ···
        client.close().then(() => {
          hilog.info(0x0000, 'testTag', 'close success');
        // ···
        }).catch((err: BusinessError) => {
          hilog.info(0x0000, 'testTag', 'close fail');
        // ···
        });
    
        // 取消事件订阅，设置关闭连接超时（例如 10 秒后取消关闭连接）
        setTimeout(() => {
          client?.off('message');
          client?.off('close');
        }, 10 * 1000);
    ```

5. 取消TCPSocketServer相关事件的订阅。

    <!-- @[tcp_server_worker_setTimeout](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->
    
    ``` TypeScript
    // 设置连接超时（例如 30 秒后取消连接）
    setTimeout(() => {
      tcpServer.off('connect');
    }, 30 * 1000);
    ```

## 应用通过Multicast Socket进行数据传输

1. 导入所需的socket模块。

   <!-- @[multicast_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->
   
   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 创建multicastSocket多播对象。

   <!-- @[multicast_worker_multicast](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->
   
   ``` TypeScript
   // 创建Multicast对象。
   let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
   ```

3. 指定多播IP与端口，加入多播组。
   ```ts
   // 构造一个对象用于加入多播组
   let addr : socket.NetAddress = {
     address: '239.255.0.1',
     port: 32123,
     family: 1
   }
   ```
   <!-- @[multicast_worker_multicastConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->
   
   ``` TypeScript
   // 加入多播组。
   multicast.addMembership(addr).then(() => {
     // ...
     hilog.info(0x0000, 'testTag', 'addMembership success');
   }).catch((err: BusinessError) => {
     // ...
     hilog.error(0x0000, 'testTag', 'addMembership fail');
   });
   ```

4. 开启消息message监听。

   <!-- @[multicast_worker_on_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->
   
   ``` TypeScript
   // 开启监听消息数据，将接收到的ArrayBuffer类型数据转换为String。
   class SocketInfo {
     public message: ArrayBuffer = new ArrayBuffer(1);
     public remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
   }
   multicast.on('message', (data: SocketInfo) => {
     hilog.info(0x0000, 'testTag', '接收的数据: ' + JSON.stringify(data))
     const uintArray = new Uint8Array(data.message)
     let str = ''
     for (let i = 0; i < uintArray.length; ++i) {
       str += String.fromCharCode(uintArray[i])
     }
     hilog.info(0x0000, 'testTag', str)
     // ...
   });
   ```

5. 发送数据，数据以广播的形式传输，同一多播组中已经开启消息message监听的多播对象都会接收到数据。

   <!-- @[multicast_worker_send](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->
   
   ``` TypeScript
   // 发送一条多播消息
   multicast.send({ data: 'Hello multicast group!', address: addr }).then(() => {
     hilog.info(0x0000, 'testTag', 'Multicast: Message sent successfully');
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'testTag', `Multicast: Failed to send message - ${JSON.stringify(err)}`);
   });
   ```

6. 关闭message消息的监听。

   <!-- @[multicast_worker_off_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->
   
   ``` TypeScript
   // 关闭消息的监听。
   multicast.off('message');
   ```

7. 退出多播组。

   <!-- @[multicast_worker_dropMembership](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->
   
   ``` TypeScript
   // 退出多播组。
   multicast.dropMembership(addr).then(() => {
     // ...
     hilog.info(0x0000, 'testTag', 'Multicast: Dropped membership successfully');
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'testTag', `Multicast: Failed to drop membership - ${JSON.stringify(err)}`);
   });
   ```
## 应用通过LocalSocket进行数据传输

1. 导入所需的socket模块。

   <!-- @[local_socket_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 使用constructLocalSocketInstance接口，创建一个LocalSocket客户端对象。

   <!-- @[local_socket_worker_client](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   // 创建一个LocalSocket连接，返回一个LocalSocket对象。
   let client: socket.LocalSocket = socket.constructLocalSocketInstance();
   ```

3. 注册LocalSocket的消息(message)事件，以及一些其它事件(可选)。

   <!-- @[local_socket_worker_on_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   client.on('message', (value: socket.LocalSocketMessageInfo) => {
     const uintArray = new Uint8Array(value.message);
     let messageView = '';
     for (let i = 0; i < uintArray.length; i++) {
       messageView += String.fromCharCode(uintArray[i]);
     }
     hilog.info(0x0000, 'testTag', 'total receive: ' + JSON.stringify(value));
     hilog.info(0x0000, 'testTag', 'message information: ' + messageView);
   });
   
   client.on('connect', () => {
     // ...
     hilog.info(0x0000, 'testTag', 'Client connected');
   });
   
   client.on('close', () => {
     // ...
     hilog.info(0x0000, 'testTag', 'Client closed');
   });
   ```
4. 连接到指定的本地套接字文件路径，连接成功之后可以发送数据。

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
   ```
   <!-- @[local_socket_worker_sendOpt](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   client.connect(connectOpt).then(() => {
     hilog.info(0x0000, 'testTag', `connect success`);
     // 发送数据。
     client.send(sendOpt).then(() => {
       hilog.info(0x0000, 'testTag', `send success`);
     }).catch((err: Object) => {
       hilog.info(0x0000, 'testTag', `send failed: ` + JSON.stringify(err));
     });
   }).catch((err: Object) => {
     hilog.info(0x0000, 'testTag', `connect fail: ` + JSON.stringify(err));
   });
   ```

5. Socket连接使用完毕后，取消事件的注册，并关闭套接字。

   <!-- @[local_socket_worker_close_server](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   // 当不需要再连接服务端，需要断开且取消事件的监听时。
   client.off('message');
   client.off('connect');
   client.off('close');
   client.close().then(() => {
     hilog.info(0x0000, 'testTag', 'close client success')
     // ...
   }).catch((err: Object) => {
     hilog.error(0x0000, 'testTag', 'close client err: ' + JSON.stringify(err))
     // ...
   })
   ```

## 应用通过Local Socket Server进行数据传输

服务端LocalSocket Server的主要流程包括：

1. 导入所需的socket模块。

   <!-- @[local_socket_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 使用constructLocalSocketServerInstance接口，创建一个 LocalSocketServer 服务端对象。

   <!-- @[local_socket_server_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   // 创建一个LocalSocketServer连接，返回一个LocalSocketServer对象。
   let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
   ```

3. 启动服务，绑定本地套接字路径，创建出本地套接字文件，监听客户端的连接请求。

   ``` TypeScript
   // 创建并绑定本地套接字文件testSocket，进行监听。
   let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
   let sandboxPath: string = context.filesDir + '/testSocket';
   let listenAddr: socket.LocalAddress = {
     address: sandboxPath
   }
   ```
   <!-- @[local_socket_worker_server_listen](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   server.listen(listenAddr).then(() => {
     // ...
     hilog.info(0x0000, 'testTag', `Server listening on ${address}`);
   }).catch((err: object) => {
     // ...
     hilog.error(0x0000, 'testTag', `Server listen error: ${JSON.stringify(err)}`);
   });
   ```

4. 注册LocalSocket的客户端连接事件，以及一些其它事件(可选)，在客户端连接成功时，可以获取到客户端连接会话对象LocalSocketConnection，通过该会话对象可以订阅客户端收到消息(message)事件，以及一些其它事件(可选)，通过该会话对象也可发起主动向客户端发送数据，主动关闭与客户端的连接的动作，订阅事件不再需要时，可以取消LocalSocketConnection相关的事件订阅。

   <!-- @[local_socket_worker_server_connection](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
   
   ``` TypeScript
   // 订阅LocalSocketServer的connect事件。
   server.on('connect', (connection: socket.LocalSocketConnection) => {
     // 订阅LocalSocketConnection相关的事件。
     connection.on('error', (err: Object) => {
       hilog.info(0x0000, 'testTag', 'on error success');
     });
   
     connection.on('message', (value: socket.LocalSocketMessageInfo) => {
       const uintArray = new Uint8Array(value.message);
       let messageView = '';
       for (let i = 0; i < uintArray.length; i++) {
         messageView += String.fromCharCode(uintArray[i]);
       }
       hilog.info(0x0000, 'testTag', `Server received: ${messageView}`);
     });
   
     connection.on('error', (err: Object) => {
       hilog.error(0x0000, 'testTag', 'err:' + JSON.stringify(err));
     })
   
     // 向客户端发送数据。
     let sendOpt : socket.LocalSendOptions = {
       data: 'Hello world!'
     };
     connection.send(sendOpt).then(() => {
       hilog.info(0x0000, 'testTag', 'Server send success');
     }).catch((err: object) => {
       hilog.error(0x0000, 'testTag', `Server send failed: ${JSON.stringify(err)}`);
     });
   
     // ...
       // 关闭与客户端的连接。
       connection.close().then(() => {
         hilog.info(0x0000, 'testTag', 'close success');
       }).catch((err: Object) => {
         hilog.error(0x0000, 'testTag', 'close failed: ' + JSON.stringify(err));
       });
   
       // 取消LocalSocketConnection相关的事件订阅。
       connection.off('message');
       connection.off('error');
       // ...
   });
   ```

5.  取消LocalSocketServer相关事件的订阅。

    <!-- @[local_socket_worker_server_off](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->
    
    ``` TypeScript
    // 取消LocalSocketServer相关的事件订阅。
    server.off('connect');
    server.off('error');
    ```

## 应用通过TLS Socket进行加密数据传输

客户端TLS Socket流程（双向认证）包括：

1. 导入所需的socket模块。

   <!-- @[two_way_tls_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TwoWayTlsWorker.ets) -->
   
   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 创建一个双向认证TLSSocket连接，返回一个TLSSocket对象。

   <!-- @[two-way_constructTLSSocketInstance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TwoWayTlsWorker.ets) -->
   
   ``` TypeScript
   // 创建一个（双向认证）TLS Socket连接，返回一个TLS Socket对象。
   let tlsSocket: socket.TLSSocket | null = socket.constructTLSSocketInstance();
   ```

3. 绑定本地IP地址和端口，确保bind成功后，再订阅TLS Socket相关的订阅事件。上传客户端CA证书及数字证书，调用[connect](../reference/apis-network-kit/js-apis-socket.md#connect9)接口建立连接。连接成功后，可调用[send](../reference/apis-network-kit/js-apis-socket.md#send9)接口发送数据。
   ```ts
   // 绑定本地IP地址和端口。
   let ipAddress : socket.NetAddress = {} as socket.NetAddress;
   ipAddress.address = "192.168.xxx.xxx";
   ipAddress.port = 4512;
  
   // 服务器IP地址和端口。
   let serverAddress : socket.NetAddress = {} as socket.NetAddress;
   serverAddress.address = "192.168.xxx.xxx";
   serverAddress.port = 1234;

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
   tlsTwoWayConnectOption.address = serverAddress;
   tlsTwoWayConnectOption.secureOptions = tlsSecureOption;
   tlsTwoWayConnectOption.ALPNProtocols = ["spdy/1", "http/1.1"];
   ```
   <!-- @[two-way_bindTlsSocket](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TwoWayTlsWorker.ets) -->
   
   ``` TypeScript
   class SocketInfo {
     public message: ArrayBuffer = new ArrayBuffer(1);
     public remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
   }
   // 绑定本地IP地址和端口。
   tlsSocket!.bind(ipAddress).then(() => {
     hilog.info(0x0000, 'testTag', 'bind success');
     // ...
     // 确保bind成功后，再订阅TLS Socket相关的订阅事件
     tlsSocket!.on('message', (value: SocketInfo) => {
       hilog.info(0x0000, 'testTag', 'on message');
       let buffer = value.message;
       let dataView = new DataView(buffer);
       let str = '';
       for (let i = 0; i < dataView.byteLength; ++i) {
         str += String.fromCharCode(dataView.getUint8(i));
       }
       hilog.info(0x0000, 'testTag', 'on connect received:' + str);
     });
   
     tlsSocket!.on('connect', () => {
       // ...
       hilog.info(0x0000, 'testTag', 'on connect');
     });
     // 监听连接关闭
     tlsSocket!.on('close', () => { 
       hilog.info(0x0000, 'testTag', 'on close');
       // ...
     });
     tlsSocket!.connect({ address: serverAddress, secureOptions: opt }).then(() => {
       hilog.info(0x0000, 'testTag', 'Connected successfully');
       // ...
     }).catch((e: BusinessError) => {
       hilog.error(0x0000, 'testTag', `Failed to connect: ${e.message}`);
       // ...
     });
   }).catch((e: BusinessError) => {
     hilog.error(0x0000, 'testTag', 'bind fail');
     // ...
   });
   // ...
   tlsSocket!.send('message').then(() => {
     hilog.info(0x0000, 'testTag', 'send successfully');
     // ...
   }).catch((e: BusinessError) => {
     hilog.error(0x0000, 'testTag', 'send failed ' + JSON.stringify(e));
     // ...
   });
   ```

4. TLSSocket连接使用完毕后，主动关闭。

   <!-- @[two-way_closeTlsSocket](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TwoWayTlsWorker.ets) -->
   
   ``` TypeScript
   // 连接使用完毕后，主动关闭，并取消相关事件的订阅。
   tlsSocket!.close((err: BusinessError) => {
     if (err) {
       hilog.error(0x0000, 'testTag', 'close callback error = ' + err);
     } else {
       hilog.info(0x0000, 'testTag', 'close success');
     }
     tlsSocket!.off('message');
     tlsSocket!.off('connect');
     tlsSocket!.off('close');
   });
   ```

客户端TLS Socket流程（单向认证）包括：

1. 导入所需的socket模块。

   <!-- @[one_way_tls_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/OneWayTlsWorker.ets) -->
   
   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 创建一个单向认证TLSSocket连接，返回一个TLSSocket对象。

   <!-- @[create_tls_worker_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/OneWayTlsWorker.ets) -->
   
   ``` TypeScript
   // 创建一个（单向认证）TLS Socket连接，返回一个TLS Socket对象。
   let tlsOneWaySocket: socket.TLSSocket = socket.constructTLSSocketInstance();  // One way authentication
   ```

3. 绑定本地IP地址和端口，确保bind成功后，再订阅TLS Socket相关的订阅事件。上传客户端CA证书及数字证书，调用[connect](../reference/apis-network-kit/js-apis-socket.md#connect9)接口建立连接。连接成功后，可调用[send](../reference/apis-network-kit/js-apis-socket.md#send9)接口发送数据。
   ```ts
   // 绑定本地IP地址和端口。
   let ipAddress : socket.NetAddress = {} as socket.NetAddress;
   ipAddress.address = "192.168.xxx.xxx";
   ipAddress.port = 5445;
  
   // 服务器IP地址和端口。
   let serverAddress : socket.NetAddress = {} as socket.NetAddress;
   serverAddress.address = "192.168.xxx.xxx";
   serverAddress.port = 8789;
   let tlsOneWaySecureOption : socket.TLSSecureOptions = {} as socket.TLSSecureOptions;
   tlsOneWaySecureOption.ca = ["xxxx", "xxxx"];
   tlsOneWaySecureOption.cipherSuite = "AES256-SHA256";

   let tlsOneWayConnectOptions: socket.TLSConnectOptions = {} as socket.TLSConnectOptions;
   tlsOneWayConnectOptions.address = serverAddress;
   tlsOneWayConnectOptions.secureOptions = tlsOneWaySecureOption;
   ```
   <!-- @[tls_worker_bind_the_server](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/OneWayTlsWorker.ets) -->
   
   ``` TypeScript
   class SocketInfo {
     public message: ArrayBuffer = new ArrayBuffer(1);
     public remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
   }
   // ...
     // 绑定本地IP地址和端口。
     tlsOneWaySocket!.bind(ipAddress).then(() => {
       hilog.info(0x0000, 'testTag', 'bind success');
       // ...
       /// 订阅TLS Socket相关的订阅事件
       tlsOneWaySocket!.on('message', (value: SocketInfo) => {
         hilog.info(0x0000, 'testTag', 'on message');
         let buffer = value.message;
         let dataView = new DataView(buffer);
         let str = '';
         for (let i = 0; i < dataView.byteLength; ++i) {
           str += String.fromCharCode(dataView.getUint8(i));
         }
         hilog.info(0x0000, 'testTag', 'on connect received:' + str);
       });
       tlsOneWaySocket!.on('connect', () => {
         hilog.info(0x0000, 'testTag', 'on connect');
       });
       tlsOneWaySocket!.on('close', () => {
         hilog.info(0x0000, 'testTag', 'on close');
         // ...
       });
       tlsOneWaySocket!.connect({ address: serverAddress, secureOptions: opt }).then(() => {
         hilog.info(0x0000, 'testTag', 'connect successfully');
         // ...
       }).catch((e: BusinessError) => {
         hilog.error(0x0000, 'testTag', `Failed to connect: ${e.message}`);
         // ...
       });
     }).catch((e: BusinessError) => {
       hilog.error(0x0000, 'testTag', 'bind fail');
       // ...
     });
     // ...
     // 建立连接，连接建立成功后，可以发送数据。
     tlsOneWaySocket.send(message + '\r\n').then(() => {
       hilog.info(0x0000, 'testTag', 'send successfully');
       // ...
     }).catch((e: BusinessError) => {
       hilog.error(0x0000, 'testTag', 'send failed ' + JSON.stringify(e));
       // ...
     });
   ```

4. TLSSocket连接使用完毕后，主动关闭。

   <!-- @[tls_worker_close_the_server](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/OneWayTlsWorker.ets) -->
   
   ``` TypeScript
   // 连接使用完毕后，主动关闭，并取消相关事件的订阅。
   tlsOneWaySocket!.close((err: BusinessError) => {
     if (err) {
       hilog.error(0x0000, 'testTag', 'close callback error = ' + err);
       // ...
     } else {
       hilog.info(0x0000, 'testTag', 'close success');
       // ...
     }
     tlsOneWaySocket!.off('message');
     tlsOneWaySocket!.off('connect');
     tlsOneWaySocket!.off('close');
   });
   ```

## 应用通过将TCP Socket升级为TLS Socket进行加密数据传输

客户端TCP Socket升级为TLS Socket流程，以TLS Socket双向认证为例：

1. 导入所需的socket模块。

   <!-- @[tcp_to_tls_server_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/Tcp2TwoWayTlsWorker.ets) -->
   
   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 参考[应用 TCP/UDP 协议进行通信](#应用tcpudp协议进行通信)，创建一个TCPSocket连接。

   <!-- @[tcp_to_tls_server_create_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/Tcp2TwoWayTlsWorker.ets) -->
   
   ``` TypeScript
   // 创建一个TCPSocket连接，返回一个TCPSocket对象。
   let tcpSocket: socket.TCPSocket = socket.constructTCPSocketInstance();
   ```

3. 绑定本地IP地址和端口，绑定成功后，连接到服务器端IP地址和端口，连接成功后使用该TCPSocket对象创建TLSSocket，配置双向认证上传客户端CA证书及数字证书，可以建立TLSSocket连接，连接使用完毕后，主动关闭并取消相关事件的订阅。
   ```ts
   // 连接到服务器端指定的IP地址和端口。
   let serverAddress: socket.NetAddress = {} as socket.NetAddress;
   serverAddress.address = "192.168.xxx.xxx";
   serverAddress.port = 1234;

   let tcpConnect: socket.TCPConnectOptions = {} as socket.TCPConnectOptions;
   tcpConnect.address = serverAddress;
   tcpConnect.timeout = 6000;

   // 配置TLSSocket目的地址、证书等信息。
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
   tlsTwoWayConnectOption.address = serverAddress;
   tlsTwoWayConnectOption.secureOptions = tlsSecureOption;
   tlsTwoWayConnectOption.ALPNProtocols = ["spdy/1", "http/1.1"];
   ```
   <!-- @[tcp_Upgrade_to_tls_server](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/Tcp2TwoWayTlsWorker.ets) -->
   
   ``` TypeScript
   // 如果需要绑定特定的端口，可通过bind接口实现
   tcpSocket.connect(tcpConnect).then(() => {
     hilog.info(0x0000, 'testTag', 'connect success');
     // ...
     // 确保TCPSocket已连接后，将其升级为TLSSocket连接。
     tlsSocket = socket.constructTLSSocketInstance(tcpSocket);
     // 订阅TLSSocket相关的订阅事件。
     tlsSocket.on('message', (value: SocketInfo) => {
       hilog.info(0x0000, 'testTag', 'tls on message');
       let buffer = value.message;
       let dataView = new DataView(buffer);
       let str = '';
       for (let i = 0; i < dataView.byteLength; ++i) {
         str += String.fromCharCode(dataView.getUint8(i));
       }
       hilog.info(0x0000, 'testTag', 'tls on connect received:' + str);
     });
     tlsSocket.on('connect', () => {
       hilog.info(0x0000, 'testTag', 'tls on connect');
     });
     tlsSocket!.on('close', () => {
       hilog.info(0x0000, 'testTag', 'tls on close');
       // ...
     });
     // ...
     // 建立TLSSocket连接。
     tlsSocket.connect(tlsTwoWayConnectOption).then(() => {
       hilog.info(0x0000, 'testTag', 'tls connect success');
       // ...
     }).catch((e: BusinessError) => {
       hilog.info(0x0000, 'testTag', 'tls connect fail');
       // ...
     });
   }).catch((e: BusinessError) => {
     hilog.error(0x0000, 'testTag', 'connect fail');
     // ...
   });
   ```

4. 连接使用完毕后，主动关闭。取消相关事件的订阅。

   <!-- @[tls_server_close](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/Tcp2TwoWayTlsWorker.ets) -->
   
   ``` TypeScript
   // 连接使用完毕后，主动关闭。取消相关事件的订阅。
   tlsSocket!.close((err: BusinessError) => {
     if (err) {
       // ...
       hilog.error(0x0000, 'testTag', 'tls close callback error = ' + err);
     } else {
       hilog.info(0x0000, 'testTag', 'tls close success');
       // ...
     }
     tlsSocket!.off('message');
     tlsSocket!.off('connect');
     tlsSocket!.off('close');
   });
   ```

## 应用通过TLS Socket Server进行加密数据传输

服务端TLS Socket Server流程：

1. 导入所需的socket模块。

   <!-- @[tls_server_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TlsServerWorker.ets) -->
   
   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. 创建一个TLSSocketServer连接，返回一个TLSSocketServer对象。

   <!-- @[tls_server_instance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TlsServerWorker.ets) -->
   
   ``` TypeScript
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
   ```
   <!-- @[tlsServer_start_service](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TlsServerWorker.ets) -->
   
   ``` TypeScript
   tlsServer.listen(tlsConnectOptions).then(() => {
     hilog.info(0x0000, 'testTag', 'listen callback success');
     // ...
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'testTag', 'failed' + err);
     // ...
   });
   ```

4. 订阅TLSSocketServer的连接事件，收到客户端连接，通过回调得到TLSSocketConnection对象，通过该对象可以实现订阅TLSSocketConnection相关的事件、向客户端发送数据的动作，TLSSocketConnection连接使用完毕后，需要主动断开连接，进行取消订阅回调的动作。

   <!-- @[tlsServer_connection_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TlsServerWorker.ets) -->
   
   ``` TypeScript
   class SocketInfo {
     public message: ArrayBuffer = new ArrayBuffer(1);
     public remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
   }
   let callback = (value: SocketInfo) => {
     let messageView = '';
     for (let i: number = 0; i < value.message.byteLength; i++) {
       let uint8Array = new Uint8Array(value.message)
       let messages = uint8Array[i]
       let message = String.fromCharCode(messages);
       messageView += message;
     }
     hilog.info(0x0000, 'testTag', 'on message message: ' + JSON.stringify(messageView));
     hilog.info(0x0000, 'testTag', 'remoteInfo: ' + JSON.stringify(value.remoteInfo));
     // ...
   }
   // ...
     tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
       client.on('message', callback);
       // 发送数据。
       client.send('Hello, client!').then(() => {
         hilog.info(0x0000, 'testTag', 'send success');
         // ...
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', 'send fail');
         // ...
       });
       // 断开连接。
       client.close().then(() => {
         hilog.info(0x0000, 'testTag', 'close success');
         // ...
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', 'close fail');
         // ...
       });
   
       // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
       client.off('message', callback);
       client.off('message');
   ```

5. 取消订阅TLSSocketServer的相关事件。

   <!-- @[tlsServer_off_connect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TlsServerWorker.ets) -->
   
   ``` TypeScript
   tlsServer.close();
   // 取消订阅tlsServer的相关事件
   tlsServer.off('connect');
   ```

## 相关实例

针对Socket连接开发，有以下相关实例可供参考：

- [网络管理-Socket连接（ArkTS）（API9）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Socket)

- [Socket连接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket)