# Socket Connection

## Introduction

The Socket Connection module allows an application to transmit data over a Socket connection through the TCP, UDP, or TLS protocol.

## Basic Concepts

- Socket: An abstraction of endpoints for bidirectional communication between application processes running on different hosts in a network.
- TCP: Transmission Control Protocol, which is a byte stream–based transport layer communication protocol that is connection-oriented and reliable.
- UDP: User Datagram Protocol, which is a simple datagram-oriented transport layer communication protocol.
- TLS: Transport Layer Security, which is a protocol that ensures the data confidentiality and integrity between communication programs.

## When to Use

Applications transmit data over TCP, UDP, or TLSSocket connections. The main application scenarios are as follows:

- Implementing data transmission over TCP/UDPSocket connections
- Implementing encrypted data transmission over TLSSocket connections

## Available APIs

For the complete list of APIs and example code, see [Socket Connection](../reference/apis/js-apis-socket.md).

Socket connection functions are mainly implemented by the **socket** module. The following table describes the related APIs.

| API| Description|
| -------- | -------- |
| constructUDPSocketInstance() | Creates a **UDPSocket** object.|
| constructTCPSocketInstance() | Creates a **TCPSocket** object.|
| bind() | Binds the IP address and port number.|
| send() | Sends data.|
| close() | Closes a Socket connection.|
| getState() | Obtains the Socket connection status.|
| connect() | Connects to the specified IP address and port. This function is supported only for TCP.|
| getRemoteAddress() | Obtains the peer address of the Socket connection. This function is supported only for TCP. The **connect** API must have been called before you use this API.|
| on(type:&nbsp;'message') | Subscribes to **message** events of the Socket connection.|
| off(type:&nbsp;'message') | Unsubscribes from **message** events of the Socket connection.|
| on(type:&nbsp;'close') | Subscribes to **close** events of the Socket connection.|
| off(type:&nbsp;'close') | Unsubscribes from **close** events of the Socket connection.|
| on(type:&nbsp;'error') | Subscribes to **error** events of the Socket connection.|
| off(type:&nbsp;'error') | Unsubscribes from **error** events of the Socket connection.|
| on(type:&nbsp;'listening') | Subscribes to **listening** events of the UDPSocket connection. |
| off(type:&nbsp;'listening') | Unsubscribes from **listening** events of the UDPSocket connection. |
| on(type:&nbsp;'connect') | Subscribes to **connect** events of the TCPSocket connection. |
| off(type:&nbsp;'connect') | Unsubscribes from **connect** events of the TCPSocket connection.|

TLSSocket connection functions are mainly provided by the **tls_socket** module. The following table describes the related APIs.

| API| Description|
| -------- | -------- |
| constructTLSSocketInstance() | Creates a **TLSSocket** object.|
| bind() | Binds the IP address and port number.|
| close(type:&nbsp;'error') | Closes a Socket connection.|
| connect() | Sets up a connection to the specified IP address and port number.|
| getCertificate() | Obtains an object representing the local certificate.|
| getCipherSuite() | Obtains a list containing information about the negotiated cipher suite.|
| getProtocol() | Obtains a string containing the SSL/TLS protocol version negotiated for the current connection.|
| getRemoteAddress() | Obtains the peer address of the TLSSocket connection.|
| getRemoteCertificate() | Obtains an object representing a peer certificate.|
| getSignatureAlgorithms() | Obtains a list containing signature algorithms shared between the server and client, in descending order of priority.|
| getState() | Obtains the TLSSocket connection status.|
| off(type:&nbsp;'close') | Unsubscribes from **close** events of the TLSSocket connection.|
| off(type:&nbsp;'error') | Unsubscribes from **error** events of the TLSSocket connection.|
| off(type:&nbsp;'message') | Unsubscribes from **message** events of the TLSSocket connection.|
| on(type:&nbsp;'close') | Subscribes to **close** events of the TLSSocket connection.|
| on(type:&nbsp;'error') | Subscribes to **error** events of the TLSSocket connection.|
| on(type:&nbsp;'message') | Subscribes to **message** events of the TLSSocket connection.|
| send() | Sends data.|
| setExtraOptions() | Sets other properties of the TLSSocket connection.|

## Transmitting Data over TCP/UDPSocket Connections

The implementation is similar for UDPSocket and TCPSocket connections. The following uses data transmission over a TCPSocket connection as an example.

1. Import the required **socket** module.

2. Create a **TCPSocket** object.

3. (Optional) Subscribe to TCPSocket connection events.

4. Bind the IP address and port number. The port number can be specified or randomly allocated by the system.

5. Set up a connection to the specified IP address and port number.

6. Send data.

7. Enable the TCPSocket connection to be automatically closed after use.

```js
import socket from '@ohos.net.socket'

// Create a TCPSocket object.
let tcp = socket.constructTCPSocketInstance();

// Subscribe to TCPSocket connection events.
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

// Bind the local IP address and port number.
let bindAddress = {
  address: '192.168.xx.xx',
  port: 1234, // Bound port, for example, 1234.
  family: 1
};
tcp.bind(bindAddress, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');

  // Set up a connection to the specified IP address and port number.
  let connectAddress = {
    address: '192.168.xx.xx',
    port: 5678, // Connection port, for example, 5678.
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

    // Send data.
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

// Enable the TCPSocket connection to be automatically closed after use. Then, disable listening for TCPSocket connection events.
setTimeout(() => {
  tcp.close((err) => {
    console.log('close socket.')
  });
  tcp.off('message');
  tcp.off('connect');
  tcp.off('close');
}, 30 * 1000);
```

## Implementing encrypted data transmission over TLSSocket connections

### How to Develop

TLSSocket connection process on the client:

1. Import the required **socket** module.

2. Bind the IP address and port number of the server.

3. For two-way authentication, upload the client CA certificate and digital certificate. For one-way authentication, upload the client CA certificate.

4. Create a **TLSSocket** object.

5. (Optional) Subscribe to TLSSocket connection events.

6. Send data.

7. Enable the TLSSocket connection to be automatically closed after use.

```js
import socket from '@ohos.net.socket'

// Create a TLSSocket connection (for two-way authentication).
let tlsTwoWay = socket.constructTLSSocketInstance();

// Subscribe to TLSSocket connection events.
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

// Bind the local IP address and port number.
tlsTwoWay.bind({ address: '192.168.xxx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

// Set the communication parameters.
let options = {
  ALPNProtocols: ["spdy/1", "http/1.1"],

  // Set up a connection to the specified IP address and port number.
  address: {
    address: "192.168.xx.xxx",
    port: xxxx, // Port
    family: 1,
  },

  // Set the parameters used for authentication during communication.
  secureOptions: {
    key: "xxxx",                            // Key
    cert: "xxxx",                           // Digital certificate
    ca: ["xxxx"],                           // CA certificate
    passwd: "xxxx",                         // Password for generating the key
    protocols: [socket.Protocol.TLSv12],    // Communication protocol
    useRemoteCipherPrefer: true,            // Whether to preferentially use the peer cipher suite
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",    // Signature algorithm
    cipherSuite: "AES256-SHA256",           // Cipher suite
  },
};

// Set up a connection.
tlsTwoWay.connect(options, (err, data) => {
  console.error(err);
  console.log(data);
});

// Enable the TCPSocket connection to be automatically closed after use. Then, disable listening for TCPSocket connection events.
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

// Create a TLSSocket connection (for one-way authentication).
let tlsOneWay = socket.constructTLSSocketInstance(); // One way authentication

// Subscribe to TLSSocket connection events.
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

// Bind the local IP address and port number.
tlsOneWay.bind({ address: '192.168.xxx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

// Set the communication parameters.
let oneWayOptions = {
  address: {
    address: "192.168.xxx.xxx",
    port: xxxx,
    family: 1,
  },
  secureOptions: {
    ca: ["xxxx","xxxx"],            // CA certificate
    cipherSuite: "AES256-SHA256",   // Cipher suite
  },
};

// Set up a connection.
tlsOneWay.connect(oneWayOptions, (err, data) => {
  console.error(err);
  console.log(data);
});

// Enable the TCPSocket connection to be automatically closed after use. Then, disable listening for TCPSocket connection events.
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
