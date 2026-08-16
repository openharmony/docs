# Using Socket for Network Access

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=8afc34f10cffeb751b25bb9c79ee3a256aa4e3af translatedAt=2026-08-13T03:10:32.928Z pushedAt=2026-08-13T07:22:29.824Z -->

## Overview

The Socket Connection module allows an application to transmit data over a socket connection through the TCP, UDP, Multicast, or TLS protocol.

> **NOTE**
>
> After an application is moved from the background to the foreground, the socket connection may be disconnected. If the communication fails after the application enters the foreground, an exception needs to be thrown and a new TCP/UDP socket connection needs to be created.

## Basic Concepts

- Socket: An abstraction of endpoints for bidirectional communication between application processes running on different hosts in a network.

- Transmission Control Protocol (TCP: A byte stream–based transport layer communication protocol that is connection-oriented and reliable.

- User Datagram Protocol (UDP): A simple, datagram-oriented transport layer protocol that is connectionless.

- Multicast: A UDP-based communication mode that implements broadcast communication between all devices in a group.

- LocalSocket: An inter-process communication (IPC) mechanism that implements communication between processes on a device without using a network.

- Transport Layer Security (TLS): A protocol that provides confidentiality and data integrity between two communication applications.

## When to Use

Applications can transmit data over TCP, UDP, Multicast, or TLS socket connections. The main application scenarios include:

- Transmitting data on the TCP/UDP socket client (UDP does not distinguish between the client and server. The client is the party that sends data to the server.)

- Transmitting data on the TCP socket server

- Transmitting data over multicast socket connections

- Transmitting data over the local socket client connection between different processes of the same device 

- Transmitting data over the local socket server connection between different processes of the same device 

- Implementing encrypted data transmission over TLS socket client connections

- Implementing encrypted data transmission over TLS socket server connections

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain the UIAbilityContext, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

## Transmitting Data over TCP Socket or UDP Socket Connections

The implementation is similar for UDP socket and TCP socket connections. The following uses data transmission over a TCP socket connection as an example.

1. Import the required socket module.

    <!-- @[tcp_client_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->

    ``` TypeScript
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. Create a TCP socket connection. A **TCPSocket** object is returned.

    <!-- @[tcp_client_worker_tcpClient](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->

    ``` TypeScript
    // Create a TCP socket connection. A TCPSocket object is returned.
    let tcpClient: socket.TCPSocket = socket.constructTCPSocketInstance();
    ```

3. (Optional) Subscribe to TCP socket connection events.

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

4. Bind the IP address and port number. The port number can be specified or randomly allocated by the system. After the binding is successful, you can establish a connection to the specified IP address and port number and send data over the connection.

   ```ts
    // Bind the local IP address and port number.
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 1234;

    // Set up a connection to the specified IP address and port number.
    let netAddress: socket.NetAddress = {} as socket.NetAddress;
    netAddress.address = "192.168.xxx.xxx";
    netAddress.port = 5678;
    ```

    <!-- @[tcp_client_worker_ipAddress](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->

    ``` TypeScript
      // Bind the local IP address and port number.
    // ···
      tcpClient.bind(ipAddress, (err: BusinessError) => {
        if (err) {
          hilog.error(0x0000, 'testTag', 'bind fail');
          return;
        }
        hilog.info(0x0000, 'testTag', 'bind success');
    
      // Set up a connection to the specified IP address and port number.
        // ···
        let tcpConnect: socket.TCPConnectOptions = {
          address: netAddress,
          timeout: 6000 // Set the timeout interval.
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
            hilog.error(0x0000, 'testTag', 'send fail');
            // ···
          });
        }).catch((err: BusinessError) => {
          hilog.error(0x0000, 'testTag', 'connect fail');
        });
      })
    ```

5. Enable the TCP socket connection to be automatically closed after use.

    <!-- @[tcp_client_worker_disConnect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpClientWorker.ets) -->

    ``` TypeScript
    // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
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

## Transmitting Data over TCP Socket Server Connections

The TCP socket connection process on the server is as follows:

1. Import the required socket module.

    <!-- @[tcp_server_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->

    ``` TypeScript
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    ```

2. Create a TCP socket server connection. A **TCPSocketServer** object is returned.

    <!-- @[tcp_server_worker_tcpServer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->

    ``` TypeScript
    // Create a TCP socket server connection. A TCPSocketServer object is returned.
    let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
    ```

3. Bind the local IP address and port, and listen for and accept TCP socket connections established over the socket.

   ```ts
    // Bind the local IP address and port number for listening.
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 4651;
    ```

    <!-- @[tcp_server_worker_ipAddress](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->

    ``` TypeScript
    // Bind the local IP address and port number for listening.
    tcpServer.listen(ipAddress).then(() => {
      hilog.info(0x0000, 'testTag', 'listen success');
      // ···
    }).catch(() => {
      hilog.error(0x0000, 'testTag', 'listen fail');
      // ···
    });
    ```

4. Subscribe to **connect** events of the **TCPSocketServer** object to listen for client connection status changes. A **TCPSocketConnection** object is returned after a connection is established between the client and the server. Through this object, you can subscribe to the **close** and **message** events of the client, send data over the connection, disconnect from the client, and unsubscribe from events of **TCPSocketConnection**.

    <!-- @[tcp_server_worker_socketInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->

    ``` TypeScript
      class SocketInfo {
        public message: ArrayBuffer = new ArrayBuffer(1);
        public remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
      }
      // Subscribe to connect events of the TCPSocketServer object.
      // Set up a connection between the client and the server. A **TCPSocketConnection** object is returned.
      tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
        // ···
    
        // client is the connection object obtained after the connection is established. You can subscribe to events of TCPSocketConnection through this object.
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
        // Define the data to be sent as required.
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
          hilog.error(0x0000, 'testTag', 'close fail');
        // ···
        });
    
        // Disable listening for events. Set the timeout interval for closing the connection (for example, 10 seconds).
        setTimeout(() => {
          client?.off('message');
          client?.off('close');
        }, 10 * 1000);
    ```

5. Disable listening for events of the **TCPSocketServer** object.

    <!-- @[tcp_server_worker_setTimeout](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TcpServerWorker.ets) -->

    ``` TypeScript
    // Set the connection timeout interval (for example, 30 seconds).
    setTimeout(() => {
      tcpServer.off('connect');
    }, 30 * 1000);
    ```

## Transmitting Data over Multicast Socket Connections

1. Import the required socket module.

   <!-- @[multicast_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->

   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Create a **MulticastSocket** object.

   <!-- @[multicast_worker_multicast](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->

   ``` TypeScript
   // Create a MulticastSocket object.
   let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
   ```

3. Specify a **MulticastSocket** object by the IP address and port number, and add it to the multicast group.

   ```ts
   // Construct a object to add it to a multicast group.
   let addr : socket.NetAddress = {
     address: '239.255.0.1',
     port: 32123,
     family: 1
   }
   ```

   <!-- @[multicast_worker_multicastConfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->

   ``` TypeScript
   // Add the MulticastSocket object to a multicast group.
   multicast.addMembership(addr).then(() => {
     // ...
     hilog.info(0x0000, 'testTag', 'addMembership success');
   }).catch((err: BusinessError) => {
     // ...
     hilog.error(0x0000, 'testTag', 'addMembership fail');
   });
   ```

4. Subscribe to **message** events.

   <!-- @[multicast_worker_on_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->

   ``` TypeScript
   // Subscribe to message events and convert the received data of the ArrayBuffer type to strings.
   class SocketInfo {
     public message: ArrayBuffer = new ArrayBuffer(1);
     public remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
   }
   multicast.on('message', (data: SocketInfo) => {
     hilog.info(0x0000, 'testTag', 'Received data: ' + JSON.stringify(data))
     const uintArray = new Uint8Array(data.message)
     let str = ''
     for (let i = 0; i < uintArray.length; ++i) {
       str += String.fromCharCode(uintArray[i])
     }
     hilog.info(0x0000, 'testTag', str)
     // ...
   });
   ```

5. Send data in broadcast mode. All **MulticastSocket** objects in the same multicast group for which **message** event listening has been enabled will receive the data.

   <!-- @[multicast_worker_send](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->

   ``` TypeScript
   // Send a multicast message.
   multicast.send({ data: 'Hello multicast group!', address: addr }).then(() => {
     hilog.info(0x0000, 'testTag', 'Multicast: Message sent successfully');
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'testTag', `Multicast: Failed to send message - ${JSON.stringify(err)}`);
   });
   ```

6. Unsubscribe from **message** events.

   <!-- @[multicast_worker_off_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->

   ``` TypeScript
   // Unsubscribe from message events.
   multicast.off('message');
   ```

7. Drop the **MulticastSocket** object from the multicast group.

   <!-- @[multicast_worker_dropMembership](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/MulticastWorker.ets) -->

   ``` TypeScript
   // Drop the MulticastSocket object from the multicast group.
   multicast.dropMembership(addr).then(() => {
     // ...
     hilog.info(0x0000, 'testTag', 'Multicast: Dropped membership successfully');
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'testTag', `Multicast: Failed to drop membership - ${JSON.stringify(err)}`);
   });
   ```

## Transmitting Data over Local Socket Connections

1. Import the required socket module.

   <!-- @[local_socket_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->

   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Call **constructLocalSocketInstance** to create a **LocalSocket** object.

   <!-- @[local_socket_worker_client](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->

   ``` TypeScript
   // Create a local socket connection. A LocalSocket object is returned.
   let client: socket.LocalSocket = socket.constructLocalSocketInstance();
   ```

3. Subscribe to **message** events of the **LocalSocket** object and other events (optional).

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

4. Connect to server based on the specified address of the local socket file. After the connection is established successfully, you can then send data over it.

   ```ts
   // Specify the address of local socket file to connect to the server.
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
     // Send data.
     client.send(sendOpt).then(() => {
       hilog.info(0x0000, 'testTag', `send success`);
     }).catch((err: Object) => {
       hilog.error(0x0000, 'testTag', `send failed: ` + JSON.stringify(err));
     });
   }).catch((err: Object) => {
     hilog.error(0x0000, 'testTag', `connect fail: ` + JSON.stringify(err));
   });
   ```

5. If the socket connection is no longer needed, unsubscribe from message events and close the connection.

   <!-- @[local_socket_worker_close_server](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->

   ``` TypeScript
   // If the socket connection is no longer needed, unsubscribe from message events and close the connection.
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

## Transmitting Data over Local Socket Server Connections

The local socket connection process on the server is as follows:

1. Import the required socket module.

   <!-- @[local_socket_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->

   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { common } from '@kit.AbilityKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Call **constructLocalSocketServerInstance** to create a **LocalSocketServer** object.

   <!-- @[local_socket_server_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->

   ``` TypeScript
   // Create a local socket server connection. A LocalSocketServer object is returned.
   let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
   ```

3. Bind the address of the local socket file.

   ``` TypeScript
   // Create and bind the local socket file testSocket for listening.
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

4. Subscribe to the **connect** and optionally other events of the local socket client. A **LocalSocketConnection** object is returned after a connection established between the client and the server. Through this object, you can subscribe to the **message** and optionally other events of the client, send data over the connection, disconnect from the client, and unsubscribe from events of **LocalSocketConnection**.

   <!-- @[local_socket_worker_server_connection](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->

   ``` TypeScript
   // Subscribe to connect events of the LocalSocketServer object.
   server.on('connect', (connection: socket.LocalSocketConnection) => {
     // Subscribe to events of the LocalSocketConnection object.
     connection.on('error', (err: Object) => {
       hilog.error(0x0000, 'testTag', 'on error received');
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
   
     // Send data to the client.
     let sendOpt : socket.LocalSendOptions = {
       data: 'Hello world!'
     };
     connection.send(sendOpt).then(() => {
       hilog.info(0x0000, 'testTag', 'Server send success');
     }).catch((err: object) => {
       hilog.error(0x0000, 'testTag', `Server send failed: ${JSON.stringify(err)}`);
     });
   
     // ...
       // Close the connection between the client and the server.
       connection.close().then(() => {
         hilog.info(0x0000, 'testTag', 'close success');
       }).catch((err: Object) => {
         hilog.error(0x0000, 'testTag', 'close failed: ' + JSON.stringify(err));
       });
   
       // Unsubscribe from events of the LocalSocketConnection object.
       connection.off('message');
       connection.off('error');
       // ...
   });
   ```

5.  Unsubscribe from events of the **LocalSocketServer** object.

    <!-- @[local_socket_worker_server_off](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/LocalSocketWorker.ets) -->

    ``` TypeScript
    // Unsubscribe from events of the LocalSocketServer object.
    server.off('connect');
    server.off('error');
    ```

## Implementing Encrypted Data Transmission over TLS Socket Connections

To implement the TLS socket process (two-way authentication) on the client, perform the following steps:

1. Import the required socket module.

   <!-- @[two_way_tls_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TwoWayTlsWorker.ets) -->

   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Create a TLSSocket connection. A **TLSSocket** object is returned.

   <!-- @[two-way_constructTLSSocketInstance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TwoWayTlsWorker.ets) -->

   ``` TypeScript
   // Create a TLS socket connection (for two-way authentication). A TLSSocketConnection object is returned.
   let tlsSocket: socket.TLSSocket | null = socket.constructTLSSocketInstance();
   ```

3. Bind the local IP address and port. Ensure that the bind operation is successful before subscribing to events of the **TLSSocket** object. Upload the client CA certificate and digital certificate, and call the [connect](../reference/apis-network-kit/js-apis-socket.md#connect9) API to establish a connection. After the connection is successful, call the [send](../reference/apis-network-kit/js-apis-socket.md#send9) API to send data.

   ```ts
   // Bind the local IP address and port number.
   let ipAddress : socket.NetAddress = {} as socket.NetAddress;
   ipAddress.address = "192.168.xxx.xxx";
   ipAddress.port = 4512;
  
   // Server IP address and port number.
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
   // Bind the local IP address and port number.
   tlsSocket!.bind(ipAddress).then(() => {
     hilog.info(0x0000, 'testTag', 'bind success');
     // ...
     // Subscribe to events of the TLSSocket object after successful binding.
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
     // Listen to connection closure.
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

4. After the TLSSocket connection is no longer needed, actively close it.

   <!-- @[two-way_closeTlsSocket](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TwoWayTlsWorker.ets) -->

   ``` TypeScript
   // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
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

To implement the TLS socket process (one-way authentication) on the client, perform the following steps:

1. Import the required socket module.

   <!-- @[one_way_tls_worker_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/OneWayTlsWorker.ets) -->

   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Create a TLSSocket connection. A **TLSSocket** object is returned.

   <!-- @[create_tls_worker_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/OneWayTlsWorker.ets) -->

   ``` TypeScript
   // Create a TLS socket connection (for one-way authentication). A TLSSocketConnection object is returned.
   let tlsOneWaySocket: socket.TLSSocket = socket.constructTLSSocketInstance();  // One way authentication
   ```

3. Bind the local IP address and port. Ensure that the bind operation is successful before subscribing to events of the **TLSSocket** object. Upload the client CA certificate and digital certificate, and call the [connect](../reference/apis-network-kit/js-apis-socket.md#connect9) API to establish a connection. After the connection is successful, call the [send](../reference/apis-network-kit/js-apis-socket.md#send9) API to send data.

   ```ts
   // Bind the local IP address and port number.
   let ipAddress : socket.NetAddress = {} as socket.NetAddress;
   ipAddress.address = "192.168.xxx.xxx";
   ipAddress.port = 5445;
  
   // Server IP address and port number.
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
     // Bind the local IP address and port number.
     tlsOneWaySocket!.bind(ipAddress).then(() => {
       hilog.info(0x0000, 'testTag', 'bind success');
       // ...
       /// Subscribe to events of the TLSSocket object.
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
     // Establish a connection. After the connection is established successfully, you can then send data over it.
     tlsOneWaySocket.send(message + '\r\n').then(() => {
       hilog.info(0x0000, 'testTag', 'send successfully');
       // ...
     }).catch((e: BusinessError) => {
       hilog.error(0x0000, 'testTag', 'send failed ' + JSON.stringify(e));
       // ...
     });
   ```

4. Enable the TLS socket connection to be automatically closed after use.

   <!-- @[tls_worker_close_the_server](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/OneWayTlsWorker.ets) -->

   ``` TypeScript
   // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
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

## Implementing Encrypted Data Transmission by Upgrading a TCP Socket Connection to a TLS Socket Connection

The following uses two-way authentication as an example to describe how to upgrade TCP Socket to TLS Socket on a client:

1. Import the required socket module.

   <!-- @[tcp_to_tls_server_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/Tcp2TwoWayTlsWorker.ets) -->

   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Create a TCP socket connection. For details, see [Transmitting Data over TCP Socket or UDP Socket Connections](#transmitting-data-over-tcp-socket-or-udp-socket-connections).

   <!-- @[tcp_to_tls_server_create_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/Tcp2TwoWayTlsWorker.ets) -->

   ``` TypeScript
   // Create a TCP socket connection. A TCPSocket object is returned.
   let tcpSocket: socket.TCPSocket = socket.constructTCPSocketInstance();
   ```

3. Bind the local IP address and port. After the binding succeeds, connect to the server IP address and port. After the connection succeeds, use the TCPSocket object to create a TLSSocket, configure mutual authentication, and upload the client CA certificate and digital certificate to establish a TLSSocket connection. After the connection is no longer needed, actively close it and cancel the subscription to related events.

   ```ts
   // Connect to the specified IP address and port of the server.
   let serverAddress: socket.NetAddress = {} as socket.NetAddress;
   serverAddress.address = "192.168.xxx.xxx";
   serverAddress.port = 1234;

   let tcpConnect: socket.TCPConnectOptions = {} as socket.TCPConnectOptions;
   tcpConnect.address = serverAddress;
   tcpConnect.timeout = 6000;

   // Configure the destination address and certificate of the TLSSocket object.
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
   // If a specific port needs to be bound, the bind API can be used.
   tcpSocket.connect(tcpConnect).then(() => {
     hilog.info(0x0000, 'testTag', 'connect success');
     // ...
     // After TCP socket connection is established, upgrade it to a TLS socket connection.
     tlsSocket = socket.constructTLSSocketInstance(tcpSocket);
     // Subscribe to events of the TLSSocket object.
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
     // Establish a TLS socket connection.
     tlsSocket.connect(tlsTwoWayConnectOption).then(() => {
       hilog.info(0x0000, 'testTag', 'tls connect success');
       // ...
     }).catch((e: BusinessError) => {
       hilog.error(0x0000, 'testTag', 'tls connect fail');
       // ...
     });
   }).catch((e: BusinessError) => {
     hilog.error(0x0000, 'testTag', 'connect fail');
     // ...
   });
   ```

4. After the connection is no longer needed, actively close it and cancel the subscription to related events.

   <!-- @[tls_server_close](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/Tcp2TwoWayTlsWorker.ets) -->

   ``` TypeScript
   // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
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

## Implementing Encrypted Data Transmission over TLS Socket Server Connections

The TLS socket connection process on the server is as follows:

1. Import the required socket module.

   <!-- @[tls_server_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TlsServerWorker.ets) -->

   ``` TypeScript
   import { socket } from '@kit.NetworkKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Create a TLS socket server connection.

   <!-- @[tls_server_instance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TlsServerWorker.ets) -->

   ``` TypeScript
   let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
   ```

3. Start the service and bind the IP address and port number to set up a TLS socket connection. Then, create and initialize a TLS session, and load and verify the certificate key.

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

4. Subscribe to the connection event of TLSSocketServer. When a client connection is received, obtain the TLSSocketConnection object through the callback. Through this object, you can subscribe to events related to TLSSocketConnection and send data to the client. After the TLSSocketConnection is no longer needed, actively disconnect it and cancel the subscription callback.

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
       // Send data.
       client.send('Hello, client!').then(() => {
         hilog.info(0x0000, 'testTag', 'send success');
         // ...
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', 'send fail');
         // ...
       });
       // Close the connection.
       client.close().then(() => {
         hilog.info(0x0000, 'testTag', 'close success');
         // ...
       }).catch((err: BusinessError) => {
         hilog.error(0x0000, 'testTag', 'close fail');
         // ...
       });
   
       // You can pass the callback of the on function if you want to unsubscribe from a certain type of events. If you do not pass the callback, you will unsubscribe from all events.
       client.off('message', callback);
       client.off('message');
     });
   ```

5. Unsubscribe from events of the TLSSocketServer object.

   <!-- @[tlsServer_off_connect](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket/entry/src/main/ets/workers/TlsServerWorker.ets) -->

   ``` TypeScript
   tlsServer.close();
   // Unsubscribe from events of the TLSSocketServer object.
   tlsServer.off('connect');
   ```

## Samples

The following samples are provided to help you better understand how to develop socket connection features:

- [Network Management - Socket Connection (ArkTS, API version 9)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Socket)

- [Socket Connection](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/NetWork_Kit/NetWorkKit_Datatransmission/Socket)