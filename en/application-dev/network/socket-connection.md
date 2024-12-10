# Socket Connection

## Overview

The Socket Connection module allows an application to transmit data over a socket connection through the TCP, UDP, Multicast, or TLS protocol.

## Basic Concepts

- Socket: An abstraction of endpoints for bidirectional communication between application processes running on different hosts in a network.
- TCP: Transmission Control Protocol, which is a byte stream–based transport layer communication protocol that is connection-oriented and reliable.
- UDP: User Datagram Protocol, which is a simple datagram-oriented transport layer communication protocol.
- Multicast: A UDP-based communication mode that implements broadcast communication between all devices in a group.
- LocalSocket: An inter-process communication (IPC) mechanism that implements communication between processes on a device without using a network.
- TLS: Transport Layer Security, which is a protocol that ensures the data confidentiality and integrity between communication programs.

## When to Use

Applications transmit data over TCP, UDP, Multicast, or TLS socket connections. The main application scenarios are as follows:

- Implementing data transmission over TCP socket or UDP socket connections
- Implementing data transmission over TCP socket server connections
- Implementing data transmission over multicast socket connections
- Implementing data transmission over local socket connections
- Implementing data transmission over local socket server connections
- Implementing encrypted data transmission over TLS socket connections
- Implementing encrypted data transmission over TLS socket server connections

## Available APIs

For the complete list of APIs and example code, see [Socket Connection](../reference/apis-network-kit/js-apis-socket.md).

Socket connection functions are mainly implemented by the **socket** module. The following table describes the related APIs.

| API                            | Description                                                                         |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| constructUDPSocketInstance()       | Creates a **UDPSocket** object.                                                     |
| constructTCPSocketInstance()       | Creates a **TCPSocket** object.                                                     |
| constructTCPSocketServerInstance() | Creates a **TCPSocketServer** object.                                               |
| constructMulticastSocketInstance() | Creates a **MulticastSocket** object.                                               |
| constructLocalSocketInstance()       | Creates a **LocalSocket** object.                                                 |
| constructLocalSocketServerInstance() | Creates a **LocalSocketServer** object.                                           |
| listen()                           | Subscribes to **connect** events from the client. This API is supported only for TCP and local socket connections.            |
| bind()                             | Binds an IP address to a port, or binds the address of a local socket.                                       |
| send()                             | Sends data.                                                                    |
| close()                            | Closes a socket connection.                                                                    |
| getState()                         | Obtains the status of a socket connection.                                                            |
| connect()                          | Connects to the specified IP address and port, or connects to a local socket. This API is supported only for TCP and local socket connections.         |
| getRemoteAddress()                 | Obtains the peer address of the socket connection. This function is supported only for TCP. The **connect** API must have been called before you use this API.                  |
| setExtraOptions()                  | Sets other properties of the socket connection.                                                  |
| getExtraOptions()                  | Obtains other properties of a socket connection. This API is supported only for local socket connections.                           |
| addMembership()                    | Adds a member to the specified multicast group. This API is supported only for multicast socket connections.                                |
| dropMembership()                   | Drops a member from the specified multicast group. This API is supported only for multicast socket connections.                                |
| setMulticastTTL()                  | Sets the time to live (TTL) for multicast packets. This API is supported only for multicast socket connections.                                   |
| getMulticastTTL()                  | Obtains the TTL for multicast packets. This API is supported only for multicast socket connections.                                   |
| setLoopbackMode()                  | Sets the loopback mode flag for multicast communication. This API is supported only for multicast socket connections.      |
| getLoopbackMode()                  | Obtains the loopback mode flag for multicast communication. This API is supported only for multicast socket connections.                              |
| on(type:&nbsp;'message')           | Subscribes to **message** events of a socket connection.                                              |
| off(type:&nbsp;'message')          | Unsubscribes from **message** events of a socket connection.                                          |
| on(type:&nbsp;'close')             | Subscribes to **close** events of a socket connection.                                                  |
| off(type:&nbsp;'close')            | Unsubscribes from **close** events of a socket connection.                                              |
| on(type:&nbsp;'error')             | Subscribes to **error** events of a socket connection.                                               |
| off(type:&nbsp;'error')            | Unsubscribes from **error** events of a socket connection.                                           |
| on(type:&nbsp;'listening')         | Subscribes to **listening** events of a socket connection. This API is supported only for UDP socket connections.                          |
| off(type:&nbsp;'listening')        | Unsubscribes from **listening** events of a socket connection. This API is supported only for UDP socket connections.                      |
| on(type:&nbsp;'connect')           | Subscribes to **message** events of a socket connection. This API is supported only for TCP and local socket connections.                           |
| off(type:&nbsp;'connect')          | Unsubscribes from **message** events of a socket connection. This API is supported only for TCP and local socket connections.                        |

TLS socket connection functions are mainly provided by the **tls_socket** module. The following table describes the related APIs.

| API                      | Description                                                  |
| ---------------------------- | ---------------------------------------------------------- |
| constructTLSSocketInstance() | Creates a **TLSSocket** object.                                 |
| bind()                       | Binds the IP address and port number.                                    |
| close(type:&nbsp;'error')    | Closes a socket connection.                                                |
| connect()                    | Sets up a connection to the specified IP address and port number.                              |
| getCertificate()             | Obtains an object representing the local certificate.                                  |
| getCipherSuite()             | Obtains a list containing information about the negotiated cipher suite.                        |
| getProtocol()                | Obtains a string containing the SSL/TLS protocol version negotiated for the current connection.         |
| getRemoteAddress()           | Obtains the peer address of the TLS socket connection.                           |
| getRemoteCertificate()       | Obtains an object representing a peer certificate.                                  |
| getSignatureAlgorithms()     | Obtains a list containing signature algorithms shared between the server and client, in descending order of priority.|
| getState()                   | Obtains the status of a TLS socket connection.                               |
| off(type:&nbsp;'close')      | Unsubscribes from **close** events of a TLS socket connection.                       |
| off(type:&nbsp;'error')      | Unsubscribes from **error** events of a TLS socket connection.                    |
| off(type:&nbsp;'message')    | Unsubscribes from **message** events of a TLS socket connection.                   |
| on(type:&nbsp;'close')       | Subscribes to **close** events of a TLS socket connection.                           |
| on(type:&nbsp;'error')       | Subscribes to **error** events of a TLS socket connection.                        |
| on(type:&nbsp;'message')     | Subscribes to **message** events of a TLS socket connection.                       |
| send()                       | Sends data.                                                |
| setExtraOptions()            | Sets other properties of the TLS socket connection.                           |

## Transmitting Data over TCP Socket or UDP Socket Connections

The implementation is similar for UDP socket and TCP socket connections. The following uses data transmission over a TCP socket connection as an example.

1. Import the required **socket** module.

2. Create a TCP socket connection. A **TCPSocketConnction** object is returned.

3. (Optional) Subscribe to events of the **TCPSocketConnction** object.

4. Bind the IP address and port number. The port number can be specified or randomly allocated by the system.

5. Set up a connection to the specified IP address and port number.

6. Send data over the connection.

7. Enable the TCP socket connection to be automatically closed after use.

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
// Create a TCP socket connection. A TCPSocket object is returned.
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
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

// Bind the local IP address and port number.
let ipAddress : socket.NetAddress = {} as socket.NetAddress;
ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 1234;
tcp.bind(ipAddress, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');

  // Set up a connection to the specified IP address and port number.
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
    tcp.send(tcpSendOptions).then(() => {
      console.log('send success');
    }).catch((err: BusinessError) => {
      console.log('send fail');
    });
  }).catch((err: BusinessError) => {
    console.log('connect fail');
  });
});

// Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
setTimeout(() => {
  tcp.close().then(() => {
    console.log('close success');
  }).catch((err: BusinessError) => {
    console.log('close fail');
  });
  tcp.off('message');
  tcp.off('connect');
  tcp.off('close');
}, 30 * 1000);
```

## Transmitting Data over TCP Socket Server Connections

The TCP socket server connection process is described as follows:

1. Import the required **socket** module.
2. Create a TCP socket server connection. A **TCPSocketServer** object is returned.
3. Bind the local IP address and port, and listen for and accept TCP socket connections established over the socket.
4. Subscribe to **connect** events of the **TCPSocketServer** object to listen for client connection status changes.
5. Set up a connection between the client and the server. A **TCPSocketConnection** object is returned.
6. Subscribe to events of the **TCPSocketConnection** object, and send data to the client through the **TCPSocketConnection** object.
7. Close the connection between the client and the server.
8. Unsubscribe from events of the **TCPSocketConnection** and **TCPSocketServer** objects.

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Create a TCP socket server connection. A TCPSocketServer object is returned.
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
// Bind the local IP address and port number for listening.

let ipAddress : socket.NetAddress = {} as socket.NetAddress;
ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 4651;
tcpServer.listen(ipAddress).then(() => {
  console.log('listen success');
}).catch((err: BusinessError) => {
  console.log('listen fail');
});

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
// Subscribe to connect events of the TCPSocketServer object.
tcpServer.on("connect", (client: socket.TCPSocketConnection) => {
  // Subscribe to events of the TCPSocketConnection object.
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

  // Send data to the client.
  let tcpSendOptions : socket.TCPSendOptions = {} as socket.TCPSendOptions;
  tcpSendOptions.data = 'Hello, client!';
  client.send(tcpSendOptions).then(() => {
    console.log('send success');
  }).catch((err: Object) => {
    console.error('send fail: ' + JSON.stringify(err));
  });

  // Close the connection between the client and the server.
  client.close().then(() => {
    console.log('close success');
  }).catch((err: BusinessError) => {
    console.log('close fail');
  });

  // Unsubscribe from events of the TCPSocketConnection object.
  setTimeout(() => {
    client.off("message");
    client.off("close");
  }, 10 * 1000);
});

// Unsubscribe from events of the TCPSocketServer object.
setTimeout(() => {
  tcpServer.off("connect");
}, 30 * 1000);
```

## Transmitting Data over Multicast Socket Connections

1. Import the required **socket** module.

2. Create a **MulticastSocket** object.

3. Specify a **MulticastSocket** object by the IP address and port number, and add it to the multicast group.

4. Subscribe to **message** events.

5. Send data in broadcast mode. All **MulticastSocket** objects in the same multicast group for which **message** event listening has been enabled will receive the data.

6. Unsubscribe from **message** events.

7. Drop the **MulticastSocket** object from the multicast group.

```ts
import { socket } from '@kit.NetworkKit';

// Create a MulticastSocket object.
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();

let addr : socket.NetAddress = {
  address: '239.255.0.1',
  port: 32123,
  family: 1
}

// Add the MulticastSocket object to a multicast group.
multicast.addMembership(addr).then(() => {
  console.log('addMembership success');
}).catch((err: Object) => {
  console.log('addMembership fail');
});

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

// Send data over the connection.
multicast.send({ data:'Hello12345', address: addr }).then(() => {
  console.log('send success');
}).catch((err: Object) => {
  console.log('send fail, ' + JSON.stringify(err));
});

// Unsubscribe from message events.
multicast.off('message')

// Drop the MulticastSocket object from the multicast group.
multicast.dropMembership(addr).then(() => {
  console.log('drop membership success');
}).catch((err: Object) => {
  console.log('drop membership fail');
});
```

## Transmitting Data over Local Socket Connections

1. Import the required **socket** module.

2. Call **constructLocalSocketInstance** to create a **LocalSocket** object.

3. Subscribe to **message** events of the **LocalSocket** object and other events (optional).

4. Connect to server based on the specified address of the local socket file.

5. Send data over the connection. 

6. If the socket connection is no longer needed, unsubscribe from message events and close the connection.

```ts
import { socket } from '@kit.NetworkKit';

// Create a local socket connection. A LocalSocket object is returned.
let client: socket.LocalSocket = socket.constructLocalSocketInstance();
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

// Specify the address of local socket file to connect to the server.
let sandboxPath: string = getContext(this).filesDir + '/testSocket'
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
  client.send(sendOpt).then(() => {
  console.log('send success')
  }).catch((err: Object) => {
    console.log('send failed: ' + JSON.stringify(err))
  })
}).catch((err: Object) => {
  console.log('connect fail: ' + JSON.stringify(err));
});

// If the socket connection is no longer needed, unsubscribe from message events and close the connection.
client.off('message');
client.off('connect');
client.off('close');
client.close().then(() => {
  console.log('close client success')
}).catch((err: Object) => {
  console.log('close client err: ' + JSON.stringify(err))
})
```

## Transmitting Data over Local Socket Server Connections

The local socket connection process on the server is described as follows:

1. Import the required **socket** module.

2. Call **constructLocalSocketServerInstance** to create a **LocalSocketServer** object.

3. Bind the address of the local socket file.

4. Subscribe to **connect** events of the local socket client and other events (optional).

5. When the local socket client is connected, obtain the **LocalSocketConnection** object through the callback of the **connect** event.

6. Subscribe to **message** events of the **LocalSocketConnection** object and other events (optional).

7. Send messages to the local socket client through the **LocalSocketConnection** object.

8. When the communication ends, close the local socket connection.

9. Unsubscribe from events of the **LocalSocketConnection** and **LocalSocketServer** objects.

```ts
import { socket } from '@kit.NetworkKit';

// Create a local socket server connection. A LocalSocketServer object is returned.
let server: socket.LocalSocketServer = socket.constructLocalSocketServerInstance();
// Create and bind the local socket file testSocket for listening.
let sandboxPath: string = getContext(this).filesDir + '/testSocket'
let listenAddr: socket.LocalAddress = {
  address: sandboxPath
}
server.listen(listenAddr).then(() => {
  console.log("listen success");
}).catch((err: Object) => {
  console.log("listen fail: " + JSON.stringify(err));
});

// Subscribe to connect events of the LocalSocketServer object.
server.on('connect', (connection: socket.LocalSocketConnection) => {
  // Subscribe to events of the LocalSocketConnection object.
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
    console.log("err:" + JSON.stringify(err));
  })

  // Send data to the client.
  let sendOpt : socket.LocalSendOptions = {
    data: 'Hello world!'
  };
  connection.send(sendOpt).then(() => {
    console.log('send success');
  }).catch((err: Object) => {
    console.log('send failed: ' + JSON.stringify(err));
  })

  // Close the connection between the client and the server.
  connection.close().then(() => {
    console.log('close success');
  }).catch((err: Object) => {
    console.log('close failed: ' + JSON.stringify(err));
  });

  // Unsubscribe from events of the LocalSocketConnection object.
  connection.off('message');
  connection.off('error');
});

// Unsubscribe from events of the LocalSocketServer object.
server.off('connect');
server.off('error');
```

## Implementing Encrypted Data Transmission over TLS Socket Connections

The TLS socket connection process on the client is described as follows:

1. Import the required **socket** module.

2. Bind the IP address and port number of the server.

3. For two-way authentication, upload the client CA certificate and digital certificate. For one-way authentication, upload the client CA certificate.

4. Create a TLS socket connection. A **TLSSocketConnection** object is returned.

5. (Optional) Subscribe to events of the **TLSSocketConnection** object.

6. Send data over the connection.

7. Enable the TLS socket connection to be automatically closed after use.

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
// Create a TLS socket connection (for two-way authentication). A TLSSocketConnection object is returned.
let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance();
// Subscribe to events of the TLSSocketConnection object.
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

// Bind the local IP address and port number.
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

// Set up a connection.
tlsTwoWay.connect(tlsTwoWayConnectOption).then(() => {
  console.log("connect successfully");
}).catch((err: BusinessError) => {
  console.log("connect failed " + JSON.stringify(err));
});

// Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
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

// Create a TLS socket connection (for one-way authentication). A TLSSocketConnection object is returned.
let tlsOneWay: socket.TLSSocket = socket.constructTLSSocketInstance(); // One way authentication

// Subscribe to events of the TLSSocketConnection object.
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

// Bind the local IP address and port number.
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

// Set up a connection.
tlsOneWay.connect(tlsOneWayConnectOptions).then(() => {
  console.log("connect successfully");
}).catch((err: BusinessError) => {
  console.log("connect failed " + JSON.stringify(err));
});

// Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
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

## Implementing Encrypted Data Transmission by Upgrading a TCP Socket Connection to a TLS Socket Connection

The process of upgrading a TCP socket connection to a TLS socket connection is as follows:

1. Import the required **socket** module.

2. Create a TCP socket connection. For details, see [Transmitting Data over TCP Socket or UDP Socket Connections](#transmitting-data-over-tcp-socket-or-udp-socket-connections).

3. After the TCP socket connection is established, use the **TCPSocket** object to create a TLS socket connection. A **TLSSocket** object is returned.

4. For two-way authentication, upload the client CA certificate and digital certificate. For one-way authentication, upload the client CA certificate.

5. (Optional) Subscribe to events of the **TLSSocketConnection** object.

6. Send data over the connection.

7. Enable the TLS socket connection to be automatically closed after use.

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}

// Create a TCP socket connection. A TCPSocket object is returned.
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
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

// Bind the local IP address and port number.
let ipAddress: socket.NetAddress = {} as socket.NetAddress;
ipAddress.address = "192.168.xxx.xxx";
ipAddress.port = 1234;
tcp.bind(ipAddress, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');

  // Set up a connection to the specified IP address and port number.
  ipAddress.address = "192.168.xxx.xxx";
  ipAddress.port = 443;

  let tcpConnect: socket.TCPConnectOptions = {} as socket.TCPConnectOptions;
  tcpConnect.address = ipAddress;
  tcpConnect.timeout = 6000;

  tcp.connect(tcpConnect, (err: BusinessError) => {
    if (err) {
      console.log('connect fail');
      return;
    }
    console.log('connect success');

    // After TCP socket connection is established, upgrade it to a TLS socket connection.
    let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance(tcp);
    // Subscribe to events of the TLSSocket object.
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
      console.log("tls connect success");

      // Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
      tlsTwoWay.close((err: BusinessError) => {
        if (err) {
          console.log("tls close callback error = " + err);
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

## Implementing Encrypted Data Transmission over TLS Socket Server Connections

The TLS socket connection process on the server is described as follows:

1. Import the required **socket** module.

2. Start the service and bind the IP address and port number to set up a TLS socket connection. Then, create and initialize a TLS session, and load and verify the certificate key.

3. Subscribe to **connect** events of the **TLSSocketServer** object.

4. Obtain a **TLSSocketConnection** object through the callback when the client initiates a TLS socket connection.

5. Subscribe to events of the **TLSSocketConnection** object.

6. Send data over the connection.

7. Close the TLS socket connection if it is no longer needed.

8. Unsubscribe from events of the **TLSSocketConnection** and **TLSSocketServer** objects.

```ts
import { socket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();

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
  console.log("failed" + err);
});

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

  // Send data over the connection.
  client.send('Hello, client!').then(() => {
    console.log('send success');
  }).catch((err: BusinessError) => {
    console.log('send fail');
  });

  // Close the connection.
  client.close().then(() => {
    console.log('close success');
  }).catch((err: BusinessError) => {
    console.log('close fail');
  });

  // You can pass the callback of the on function if you want to unsubscribe from a certain type of events. If you do not pass the callback, you will unsubscribe from all events.
  client.off('message', callback);
  client.off('message');
});

// Unsubscribe from events of the TLSSocketServer object.
tlsServer.off('connect');
```

