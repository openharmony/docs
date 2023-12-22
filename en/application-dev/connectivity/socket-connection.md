# Socket Connection

## Overview

The Socket Connection module allows an application to transmit data over a socket connection through the TCP, UDP, or TLS protocol.

## Basic Concepts

- Socket: An abstraction of endpoints for bidirectional communication between application processes running on different hosts in a network.
- TCP: Transmission Control Protocol, which is a byte stream–based transport layer communication protocol that is connection-oriented and reliable.
- UDP: User Datagram Protocol, which is a simple datagram-oriented transport layer communication protocol.
- TLS: Transport Layer Security, which is a protocol that ensures the data confidentiality and integrity between communication programs.

## When to Use

Applications transmit data over TCP, UDP, or TLS socket connections. The main application scenarios are as follows:

- Implementing data transmission over TCP socket or UDP socket connections
- Implementing data transmission over TCP socket server connections
- Implementing encrypted data transmission over TLS socket connections

## Available APIs

For the complete list of APIs and example code, see [Socket Connection](../reference/apis/js-apis-socket.md).

Socket connection functions are mainly implemented by the **socket** module. The following table describes the related APIs.

| API                            | 描述                                                                          |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| constructUDPSocketInstance()       | Creates a **UDPSocket** object.                                                     |
| constructTCPSocketInstance()       | Creates a **TCPSocket** object.                                                     |
| constructTCPSocketServerInstance() | Creates a **TCPSocketServer** object.                                               |
| listen()                           | Listens for and accepts TCP socket connections established over the socket. (This API is applicable only to TCP.)   |
| bind()                             | Binds the IP address and port number.                                                          |
| send()                             | Sends data.                                                                    |
| close()                            | Closes a socket connection.                                                                    |
| getState()                         | Obtains the socket connection status.                                                            |
| connect()                          | Connects to the specified IP address and port. This function is supported only for TCP.                                     |
| getRemoteAddress()                 | Obtains the peer address of the socket connection. This function is supported only for TCP. The **connect** API must have been called before you use this API.                  |
| setExtraOptions()                  | Sets other properties of the socket connection.                                                  |
| on(type:&nbsp;'message')           | Subscribes to **message** events of the socket connection.                                              |
| off(type:&nbsp;'message')          | Unsubscribes from **message** events of the socket connection.                                          |
| on(type:&nbsp;'close')             | Subscribes to **close** events of the socket connection.                                                  |
| off(type:&nbsp;'close')            | Unsubscribes from **close** events of the socket connection.                                              |
| on(type:&nbsp;'error')             | Subscribes to **error** events of the socket connection.                                               |
| off(type:&nbsp;'error')            | Unsubscribes from **error** events of the socket connection.                                           |
| on(type:&nbsp;'listening')         | Subscribes to **listening** events of the UDP socket connection.                           |
| off(type:&nbsp;'listening')        | Unsubscribes from **listening** events of the UDP socket connection.                       |
| on(type:&nbsp;'connect')           | Subscribes to **connect** events of the TCP socket connection.                                     |
| off(type:&nbsp;'connect')          | Unsubscribes from **connect** events of the TCP socket connection.                                |

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
| getState()                   | Obtains the TLS socket connection status.                               |
| off(type:&nbsp;'close')      | Unsubscribes from **close** events of the TLS socket connection.                       |
| off(type:&nbsp;'error')      | Unsubscribes from **error** events of the TLS socket connection.                    |
| off(type:&nbsp;'message')    | Unsubscribes from **message** events of the TLS socket connection.                   |
| on(type:&nbsp;'close')       | Subscribes to **close** events of the TLS socket connection.                           |
| on(type:&nbsp;'error')       | Subscribes to **error** events of the TLS socket connection.                        |
| on(type:&nbsp;'message')     | Subscribes to **message** events of the TLS socket connection.                       |
| send()                       | Sends data.                                                |
| setExtraOptions()            | Sets other properties of the TLS socket connection.                           |

## Transmitting Data over TCP Socket or UDP Socket Connections

The implementation is similar for UDP socket and TCP socket connections. The following uses data transmission over a TCP socket connection as an example.

1. Import the required **socket** module.

2. Create a TCP socket connection. A **TCPSocket** object is returned.

3. (Optional) Subscribe to TCP socket connection events.

4. Bind the IP address and port number. The port number can be specified or randomly allocated by the system.

5. Sets up a connection to the specified IP address and port number.

6. Send data over the connection.

7. Enable the TCP socket connection to be automatically closed after use.

```js
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
// Create a TCP socket connection. A TCPSocket object is returned.
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

  tcp.connect(tcpConnect, (err: BusinessError) => {
    if (err) {
      console.log('connect fail');
      return;
    }
    console.log('connect success');
    // Send data over the connection.
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

// Enable the socket connection to be automatically closed after use. Then, unsubscribe from events of the connection.
setTimeout(() => {
  tcp.close((err: BusinessError) => {
    console.log('close socket.');
  });
  tcp.off('message');
  tcp.off('connect');
  tcp.off('close');
}, 30 * 1000);
```

## Transmitting Data over TCP Socket Server Connections

### How to Develop

The TCP socket server connection process is described as follows:

1. Import the required **socket** module.
2. Create a TCP socket server connection. A **TCPSocketServer** object is returned.
3. Bind the local IP address and port, and listen for and accept TCP socket connections established over the socket.
4. Subscribe to **connect** events of the **TCPSocketServer** object to listen for client connection status changes.
5. Set up a connection between the client and the server. A **TCPSocketConnection** object is returned.
6. Subscribe to events of the **TCPSocketConnection** object, and send data to the client through the **TCPSocketConnection** object.
7. Close the connection between the client and the server.
8. Unsubscribe from events of the **TCPSocketConnection** and **TCPSocketServer** objects.

```js
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';
// Create a TCP socket server connection. A TCPSocketServer object is returned.
let tcpServer = socket.constructTCPSocketServerInstance();
// Bind the local IP address and port number for listening.

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
  client.send(tcpSendOptions, (err: BusinessError) => {
    if (err) {
      console.log("send fail");
      return;
    }
    console.log("send success");
  });

  // Close the connection between the client and the server.
  client.close((err: BusinessError) => {
    if (err) {
      console.log("close fail");
      return;
    }
    console.log("close success");
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

## Implementing Encrypted Data Transmission over TLS Socket Connections

### How to Develop

The TLS socket connection process on the client is described as follows:

1. Import the required **socket** module.

2. Bind the IP address and port number of the server.

3. For two-way authentication, upload the client CA certificate and digital certificate. For one-way authentication, upload the client CA certificate.

4. Create a TLS socket connection. A **TLSsocket** object is returned.

5. (Optional) Subscribe to TLS socket connection events.

6. Send data over the connection.

7. Enable the TLS socket connection to be automatically closed after use.

```js
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
// Create a TLS socket connection (for two-way authentication). A TLSSocket object is returned.
let tlsTwoWay = socket.constructTLSSocketInstance();
// Subscribe to TLS socket connection events.
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
tlsTwoWay.connect(tlsTwoWayConnectOption, () => {
  console.error("connect function");
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

// Create a TLS socket connection (for one-way authentication). A TLSsocket object is returned.
let tlsOneWay = socket.constructTLSSocketInstance(); // One way authentication

// Subscribe to TLS socket connection events.
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
tlsOneWay.connect(tlsOneWayConnectOptions, () => {
  console.error("connect function");
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
