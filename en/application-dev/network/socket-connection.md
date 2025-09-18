# Using Socket for Network Access
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

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

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Create a TCP socket connection. A **TCPSocket** object is returned.

    ```ts
    // Create a TCP socket connection. A TCPSocket object is returned.
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
    ```

3. (Optional) Subscribe to TCP socket connection events.

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }

    tcp.on('message', (value: SocketInfo) => {
      console.info("on message");
      let buffer = value.message;
      let dataView = new DataView(buffer);
      let str = "";
      for (let i = 0; i < dataView.byteLength; ++i) {
        str += String.fromCharCode(dataView.getUint8(i));
      }
      console.info("on connect received:" + str);
    });
    tcp.on('connect', () => {
      console.info("on connect");
    });
    tcp.on('close', () => {
      console.info("on close");
    });
    ```

4. Bind the IP address and port number. The port number can be specified or randomly allocated by the system. After the binding is successful, you can establish a connection to the specified IP address and port number and send data over the connection.

    ```ts
    // Bind the local IP address and port number.
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 1234;
    tcp.bind(ipAddress, (err: BusinessError) => {
      if (err) {
        console.error('bind fail');
        return;
      }
      console.info('bind success');

      // Set up a connection to the specified IP address and port number.
      ipAddress.address = "192.168.xxx.xxx";
      ipAddress.port = 5678;

      let tcpConnect : socket.TCPConnectOptions = {} as socket.TCPConnectOptions;
      tcpConnect.address = ipAddress;
      tcpConnect.timeout = 6000;

      tcp.connect(tcpConnect).then(() => {
        console.info('connect success');
        let tcpSendOptions: socket.TCPSendOptions = {
          data: 'Hello, server!'
        }
        // Send data after the connection is established.
        tcp.send(tcpSendOptions).then(() => {
          console.info('send success');
        }).catch((err: BusinessError) => {
          console.error('send fail');
        });
      }).catch((err: BusinessError) => {
        console.error('connect fail');
      });
    });
    ```

5. Enable the TCP socket connection to be automatically closed after use.

    ```ts
    // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
    setTimeout(() => {
      tcp.close().then(() => {
        console.info('close success');
      }).catch((err: BusinessError) => {
        console.error('close fail');
      });
      tcp.off('message');
      tcp.off('connect');
      tcp.off('close');
    }, 30 * 1000);
    ```

## Transmitting Data over TCP Socket Server Connections

The TCP socket connection process on the server is as follows:

1. Import the required socket module.

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Create a TCP socket server connection. A **TCPSocketServer** object is returned.

    ```ts
    // Create a TCP socket server connection. A TCPSocketServer object is returned.
    let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
    ```

3. Bind the local IP address and port, and listen for and accept TCP socket connections established over the socket.

    ```ts
    // Bind the local IP address and port number for listening.
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 4651;
    tcpServer.listen(ipAddress).then(() => {
      console.info('listen success');
    }).catch((err: BusinessError) => {
      console.error('listen fail');
    });
    ```

4. Subscribe to **connect** events of the **TCPSocketServer** object to listen for client connection status changes. A **TCPSocketConnection** object is returned after a connection is established between the client and the server. Through this object, you can subscribe to the **close** and **message** events of the client, send data over the connection, disconnect from the client, and unsubscribe from events of **TCPSocketConnection**.
   

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    // Subscribe to the connect event of TCPSocketServer. A TCPSocketConnection object is returned after a connection is established between the client and the server.
    tcpServer.on("connect", (client: socket.TCPSocketConnection) => {
      // client is the connection object obtained after the connection is established. You can subscribe to events of TCPSocketConnection through this object.
      client.on("close", () => {
        console.info("on close success");
      });
      client.on("message", (value: SocketInfo) => {
        let buffer = value.message;
        let dataView = new DataView(buffer);
        let str = "";
        for (let i = 0; i < dataView.byteLength; ++i) {
          str += String.fromCharCode(dataView.getUint8(i));
        }
        console.info("received message--:" + str);
        console.info("received address--:" + value.remoteInfo.address);
        console.info("received family--:" + value.remoteInfo.family);
        console.info("received port--:" + value.remoteInfo.port);
        console.info("received size--:" + value.remoteInfo.size);
      });

      // Send data to the client.
      let tcpSendOptions : socket.TCPSendOptions = {} as socket.TCPSendOptions;
      tcpSendOptions.data = 'Hello, client!';
      client.send(tcpSendOptions).then(() => {
        console.info('send success');
      }).catch((err: Object) => {
        console.error('send fail: ' + JSON.stringify(err));
      });

      // Close the connection between the client and the server.
      client.close().then(() => {
        console.info('close success');
      }).catch((err: BusinessError) => {
        console.error('close fail');
      });

      Unsubscribe from events of the TCPSocketConnection object.
      setTimeout(() => {
        client.off("message");
        client.off("close");
      }, 10 * 1000);
    });
    ```

5. Disable listening for events of the **TCPSocketServer** object.

    ```ts
    // Unsubscribe from events of the TCPSocketServer object.
    setTimeout(() => {
      tcpServer.off("connect");
    }, 30 * 1000);
    ```

## Transmitting Data over Multicast Socket Connections

1. Import the required socket module.

    ```ts
    import { socket } from '@kit.NetworkKit';
    ```

2. Create a **MulticastSocket** object.

    ```ts
    // Create a MulticastSocket object.
    let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
    ```

3. Specify a **MulticastSocket** object by the IP address and port number, and add it to the multicast group.

    ```ts
    let addr : socket.NetAddress = {
      address: '239.255.0.1',
      port: 32123,
      family: 1
    }

    // Add the MulticastSocket object to a multicast group.
    multicast.addMembership(addr).then(() => {
      console.info('addMembership success');
    }).catch((err: Object) => {
      console.error('addMembership fail');
    });
    ```

4. Subscribe to **message** events.

    ```ts
    // Subscribe to message events and convert the received data of the ArrayBuffer type to strings.
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    multicast.on('message', (data: SocketInfo) => {
      console.info ('Received data:' + JSON.stringify (data))
      const uintArray = new Uint8Array(data.message)
      let str = ''
      for (let i = 0; i < uintArray.length; ++i) {
        str += String.fromCharCode(uintArray[i])
      }
      console.info(str)
    })
    ```

5. Send data in broadcast mode. All **MulticastSocket** objects in the same multicast group for which **message** event listening has been enabled will receive the data.

    ```ts
    // Send data.
    multicast.send({ data:'Hello12345', address: addr }).then(() => {
      console.info('send success');
    }).catch((err: Object) => {
      console.error('send fail, ' + JSON.stringify(err));
    });
    ```

6. Unsubscribe from **message** events.

    ```ts
    // Unsubscribe from message events.
    multicast.off('message')
    ```

7. Drop the **MulticastSocket** object from the multicast group.

    ```ts
    // Drop the MulticastSocket object from the multicast group.
    multicast.dropMembership(addr).then(() => {
      console.info('drop membership success');
    }).catch((err: Object) => {
      console.error('drop membership fail');
    });
    ```

## Transmitting Data over Local Socket Connections

1. Import the required socket module.

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { common } from '@kit.AbilityKit';
    ```

2. Call **constructLocalSocketInstance** to create a **LocalSocket** object.

    ```ts
    // Create a local socket connection. A LocalSocket object is returned.
    let client: socket.LocalSocket = socket.constructLocalSocketInstance();
    ```

3. Subscribe to **message** events of the **LocalSocket** object and other events (optional).

    ```ts
    client.on('message', (value: socket.LocalSocketMessageInfo) => {
      const uintArray = new Uint8Array(value.message)
      let messageView = '';
      for (let i = 0; i < uintArray.length; i++) {
        messageView += String.fromCharCode(uintArray[i]);
      }
      console.info('total receive: ' + JSON.stringify(value));
      console.info('message information: ' + messageView);
    });
    client.on('connect', () => {
      console.info("on connect");
    });
    client.on('close', () => {
      console.info("on close");
    });
    ```

4. Connect to server based on the specified address of the local socket file. After the connection is established successfully, you can then send data over it.

    <!--code_no_check-->
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
    client.connect(connectOpt).then(() => {
      console.info('connect success')
      // Send data.
      client.send(sendOpt).then(() => {
      console.info('send success')
      }).catch((err: Object) => {
        console.error('send failed: ' + JSON.stringify(err))
      })
    }).catch((err: Object) => {
      console.error('connect fail: ' + JSON.stringify(err));
    });
    ```

5. If the socket connection is no longer needed, unsubscribe from message events and close the connection.

    ```ts
    // If the socket connection is no longer needed, unsubscribe from message events and close the connection.
    client.off('message');
    client.off('connect');
    client.off('close');
    client.close().then(() => {
      console.info('close client success')
    }).catch((err: Object) => {
      console.error('close client err: ' + JSON.stringify(err))
    })
    ```

## Transmitting Data over Local Socket Server Connections

The local socket connection process on the server is as follows:

1. Import the required socket module.

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { common } from '@kit.AbilityKit';
    ```

2. Call **constructLocalSocketServerInstance** to create a **LocalSocketServer** object.

    ```ts
    // Create a local socket server connection. A LocalSocketServer object is returned.
    let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
    ```

3. Bind the address of the local socket file.

    <!--code_no_check-->
    ```ts
    // Create and bind the local socket file testSocket for listening.
    let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
    let sandboxPath: string = context.filesDir + '/testSocket';
    let listenAddr: socket.LocalAddress = {
      address: sandboxPath
    }
    server.listen(listenAddr).then(() => {
      console.info("listen success");
    }).catch((err: Object) => {
      console.error("listen fail: " + JSON.stringify(err));
    });
    ```

4. Subscribe to the **connect** and optionally other events of the local socket client . A **LocalSocketConnection** object is returned after a connection established between the client and the server. Through this object, you can subscribe to the **message** and optionally other events of the client, send data over the connection, disconnect from the client, and unsubscribe from events of **LocalSocketConnection**.

    ```ts
    // Subscribe to connect events of the LocalSocketServer object.
    server.on('connect', (connection: socket.LocalSocketConnection) => {
      // Subscribe to events of the LocalSocketConnection object.
      connection.on('error', (err: Object) => {
        console.error("on error success");
      });
      connection.on('message', (value: socket.LocalSocketMessageInfo) => {
        const uintArray = new Uint8Array(value.message);
        let messageView = '';
        for (let i = 0; i < uintArray.length; i++) {
          messageView += String.fromCharCode(uintArray[i]);
        }
        console.info('total: ' + JSON.stringify(value));
        console.info('message information: ' + messageView);
      });

      connection.on('error', (err: Object) => {
        console.error("err:" + JSON.stringify(err));
      })

      // Send data to the client.
      let sendOpt : socket.LocalSendOptions = {
        data: 'Hello world!'
      };
      connection.send(sendOpt).then(() => {
        console.info('send success');
      }).catch((err: Object) => {
        console.info('send failed: ' + JSON.stringify(err));
      })

      // Close the connection between the client and the server.
      connection.close().then(() => {
        console.info('close success');
      }).catch((err: Object) => {
        console.error('close failed: ' + JSON.stringify(err));
      });

      // Unsubscribe from events of the LocalSocketConnection object.
      connection.off('message');
      connection.off('error');
    });
    ```

5.  Disable listening for events of the **LocalSocketServer** object.

    ```ts
    // Unsubscribe from events of the LocalSocketServer object.
    server.off('connect');
    server.off('error');
    ```

## Implementing Encrypted Data Transmission over TLS Socket Connections

To implement the TLS socket process (two-way authentication) on the client, perform the following steps:

1. Import the required socket module.

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Create a TLSSocket connection. A **TLSSocket** object is returned.

    ```ts
    // Create a TLS socket connection (for two-way authentication). A TLSSocketConnection object is returned.
    let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance();
    ```

3. Bind the server IP address and port number. Ensure that the bind operation is successful before subscribing to events of the **TLSSocket** object.

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    // Bind the local IP address and port number.
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 4512;
    tlsTwoWay.bind(ipAddress, (err: BusinessError) => {
      if (err) {
        console.error('bind fail');
        return;
      }
      console.info('bind success');
      // Subscribe to events of the TLSSocket object after successful binding.
      tlsTwoWay.on('message', (value: SocketInfo) => {
        console.info("on message");
        let buffer = value.message;
        let dataView = new DataView(buffer);
        let str = "";
        for (let i = 0; i < dataView.byteLength; ++i) {
          str += String.fromCharCode(dataView.getUint8(i));
        }
        console.info("on connect received:" + str);
      });
      tlsTwoWay.on('connect', () => {
        console.info("on connect");
      });
      tlsTwoWay.on('close', () => {
        console.info("on close");
      });
    });
    ```

4. Upload the client CA certificate and digital certificate for two-way authentication and establish a connection. After the connection is established successfully, you can then send data over it.

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

    // Establish a connection. After the connection is established successfully, you can then send data over it.
    tlsTwoWay.connect(tlsTwoWayConnectOption).then(() => {
      console.info("connect successfully");
      // Send data.
      tlsTwoWay.send("xxxx").then(() => {
        console.info("send successfully");
      }).catch((err: BusinessError) => {
        console.error("send failed " + JSON.stringify(err));
      });
    }).catch((err: BusinessError) => {
      console.error("connect failed " + JSON.stringify(err));
    });
    ```

5. Enable the TLS socket connection to be automatically closed after use.

    ```ts
    // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
    tlsTwoWay.close((err: BusinessError) => {
      if (err) {
        console.error("close callback error = " + err);
      } else {
        console.info("close success");
      }
      tlsTwoWay.off('message');
      tlsTwoWay.off('connect');
      tlsTwoWay.off('close');
    });
    ```

To implement the TLS socket process (one-way authentication) on the client, perform the following steps:

1. Import the required socket module.

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Create a TLSSocket connection. A **TLSSocket** object is returned.

    ```ts
    // Create a TLS socket connection (for one-way authentication). A TLSSocketConnection object is returned.
    let tlsOneWay: socket.TLSSocket = socket.constructTLSSocketInstance(); // One way authentication
    ```

3. Bind the server IP address and port number. Ensure that the bind operation is successful before subscribing to events of the **TLSSocket** object.

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }
    // Bind the local IP address and port number.
    let ipAddress : socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 5445;
    tlsOneWay.bind(ipAddress, (err:BusinessError) => {
      if (err) {
        console.error('bind fail');
        return;
      }
      console.info('bind success');
      // Subscribe to events of the TLSSocketConnection object.
      tlsOneWay.on('message', (value: SocketInfo) => {
        console.info("on message");
        let buffer = value.message;
        let dataView = new DataView(buffer);
        let str = "";
        for (let i = 0; i < dataView.byteLength; ++i) {
          str += String.fromCharCode(dataView.getUint8(i));
        }
        console.info("on connect received:" + str);
      });
      tlsOneWay.on('connect', () => {
        console.info("on connect");
      });
      tlsOneWay.on('close', () => {
        console.info("on close");
      });
    });
    ```

4. Upload the CA certificate of the client, and establish a connection.

    ```ts
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 8789;
    let tlsOneWaySecureOption : socket.TLSSecureOptions = {} as socket.TLSSecureOptions;
    tlsOneWaySecureOption.ca = ["xxxx", "xxxx"];
    tlsOneWaySecureOption.cipherSuite = "AES256-SHA256";

    let tlsOneWayConnectOptions: socket.TLSConnectOptions = {} as socket.TLSConnectOptions;
    tlsOneWayConnectOptions.address = ipAddress;
    tlsOneWayConnectOptions.secureOptions = tlsOneWaySecureOption;

    // Establish a connection. After the connection is established successfully, you can then send data over it.
    tlsOneWay.connect(tlsOneWayConnectOptions).then(() => {
      console.info("connect successfully");
      // Send data.
      tlsOneWay.send("xxxx").then(() => {
        console.info("send successfully");
      }).catch((err: BusinessError) => {
        console.error("send failed " + JSON.stringify(err));
      });
    }).catch((err: BusinessError) => {
      console.error("connect failed " + JSON.stringify(err));
    });
    ```

5. Enable the TLS socket connection to be automatically closed after use.

    ```ts
    // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
    tlsOneWay.close((err: BusinessError) => {
      if (err) {
        console.error("close callback error = " + err);
      } else {
        console.info("close success");
      }
      tlsOneWay.off('message');
      tlsOneWay.off('connect');
      tlsOneWay.off('close');
    });
    ```

## Implementing Encrypted Data Transmission by Upgrading a TCP Socket Connection to a TLS Socket Connection

The following uses two-way authentication as an example to describe how to upgrade TCP Socket to TLS Socket on a client:

1. Import the required socket module.

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Create a TCP socket connection. For details, see [Transmitting Data over TCP Socket or UDP Socket Connections](#transmitting-data-over-tcp-socket-or-udp-socket-connections).

    ```ts
    // Create a TCP socket connection. A TCPSocket object is returned.
    let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
    ```

3. (Optional) Subscribe to TCP socket connection events.

    ```ts
    class SocketInfo {
      message: ArrayBuffer = new ArrayBuffer(1);
      remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
    }

    tcp.on('message', (value: SocketInfo) => {
      console.info("on message");
      let buffer = value.message;
      let dataView = new DataView(buffer);
      let str = "";
      for (let i = 0; i < dataView.byteLength; ++i) {
        str += String.fromCharCode(dataView.getUint8(i));
      }
      console.info("on connect received:" + str);
    });
    tcp.on('connect', () => {
      console.info("on connect");
    });
    ```

4. Bind the local IP address and port. After the binding is successful, connect to the specified IP address and port of the server. After the connection is successful, use the **TCPSocket** object to create a **TLSSocket** object, enable two-way authentication, and upload the client CA certificate and digital certificate to establish a TLS socket connection. If the connection is no longer needed, close the connection and unsubscribe from related events.

    ```ts
    // Bind the local IP address and port number.
    let ipAddress: socket.NetAddress = {} as socket.NetAddress;
    ipAddress.address = "192.168.xxx.xxx";
    ipAddress.port = 1234;
    tcp.bind(ipAddress, (err: BusinessError) => {
      if (err) {
        console.error('bind fail');
        return;
      }
      console.info('bind success');

      // Connect to the specified IP address and port of the server.
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
        console.info('connect success');

        // After TCP socket connection is established, upgrade it to a TLS socket connection.
        let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance(tcp);
        // Subscribe to events of the TLSSocket object.
        tlsTwoWay.on('message', (value: SocketInfo) => {
          console.info("tls on message");
          let buffer = value.message;
          let dataView = new DataView(buffer);
          let str = "";
          for (let i = 0; i < dataView.byteLength; ++i) {
            str += String.fromCharCode(dataView.getUint8(i));
          }
          console.info("tls on connect received:" + str);
        });
        tlsTwoWay.on('connect', () => {
          console.info("tls on connect");
        });
        tlsTwoWay.on('close', () => {
          console.info("tls on close");
        });

        // Configure the destination address and certificate of the TLSSocket object.
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

        // Establish a TLS socket connection.
        tlsTwoWay.connect(tlsTwoWayConnectOption, () => {
          console.info("tls connect success");

          // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
          tlsTwoWay.close((err: BusinessError) => {
            if (err) {
              console.error("tls close callback error = " + err);
            } else {
              console.info("tls close success");
            }
            tlsTwoWay.off('message');
            tlsTwoWay.off('connect');
            tlsTwoWay.off('close');
          });
        });
      });
    });
    ```

## Implementing Encrypted Data Transmission over TLS Socket Server Connections

The TLS socket connection process on the server is as follows:

1. Import the required socket module.

    ```ts
    import { socket } from '@kit.NetworkKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Create a TLS socket server connection.

    ```ts
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

    tlsServer.listen(tlsConnectOptions).then(() => {
      console.info("listen callback success");
    }).catch((err: BusinessError) => {
      console.error("failed" + err);
    });
    ```

4. Subscribe to the **connect** events of the **TLSSocketServer** object. After receiving a client connection, obtain the **TLSSocketConnection** object through the callback. Through this object, you can subscribe to events of the **TLSSocketConnection** object and send data to the client. If the TLS socket connection is no longer needed, close the connection and unsubscribe from related events.

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
      console.info('on message message: ' + JSON.stringify(messageView));
      console.info('remoteInfo: ' + JSON.stringify(value.remoteInfo));
    }
    tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
      client.on('message', callback);

      // Send data.
      client.send('Hello, client!').then(() => {
        console.info('send success');
      }).catch((err: BusinessError) => {
        console.error('send fail');
      });

      // Close the connection.
      client.close().then(() => {
        console.info('close success');
      }).catch((err: BusinessError) => {
        console.error('close fail');
      });

      // You can pass the callback of the on function if you want to unsubscribe from a certain type of events. If you do not pass the callback, you will unsubscribe from all events.
      client.off('message', callback);
      client.off('message');
    });
    ```

5. // Unsubscribe from events of the TLSSocketServer object.

    ```ts
    // Unsubscribe from events of the TLSSocketServer object.
    tlsServer.off('connect');
    ```

