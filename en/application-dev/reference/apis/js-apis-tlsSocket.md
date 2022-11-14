# TLSSocket

The Transport Layer Security (TLS) protocol is designed to help protect the privacy of information at the transport layer. TLSSocket is an extension to socket communication. It provides higher security than socket communication by adding a security protection layer, which consists of the following submodules: key, certificate, and communication.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import socket from '@ohos.net.tlssocket'
```

## socket.constructTLSSocketInstance

constructTLSSocketInstance(): TLSSocket

Creates a **TLSSocket** object.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Example**

```js
let tlssocket = socket.constructTLSSocketInstance();
```

## tlssocket.connect

connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void

Sets up a TLSSocket connection, and creates and initializes a TLS session. During this process, a TLS/SSL handshake is performed between the application and the server to implement data transmission. This API uses an asynchronous callback to return the result.

**Parameters**

| Name  | Type                                  | Mandatory| Description|
| -------- | ---------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions) | Yes  | Parameters required for the connection.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the operation is successful, the return result is empty. If the operation fails, an error code is returned.|

**Example**

```js
let options = {
            ALPNProtocols: ["spdy/1", "http/1.1"],
            address: {
                address: "xxx",
                port: "xxxx",
                family: 1,
            },
            secureOptions: {
                key: "xxxx",
                cert: "xxxx",
                ca: ["xxxx"],
                passwd: "xxxx",
                protocols: "TlsV1_2",
                useRemoteCipherPrefer: true,
                signatureAlgorithms: SHA256,
                cipherSuites: AES256-SHA256,
            },
};

tlssocket.connect(options, (err, data) => {
    console.info(err);
    console.info(data);
});
```

## tlssocket.connect

connect(options: TLSConnectOptions): Promise\<void>;

Sets up a TLSSocket connection, and creates and initializes a TLS session. During this process, a TLS/SSL handshake is performed between the application and the server to implement data transmission. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description|
| -------- | --------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions) | Yes  | Parameters required for the connection.|

**Return value**

| Type                                       | Description                         |
| ------------------------------------------- | ----------------------------- |
| Promise\<void>                              | Promise used to return the result. If the operation is successful, the return result is empty. If the operation fails, an error code is returned.|

**Example**

```js
let options = {
            ALPNProtocols: ["spdy/1", "http/1.1"],
            address: {
                address: "xxxx",
                port: "xxxx",
                family: 1,
            },
            secureOptions: {
                key: "xxxx",
                cert: "xxxx",
                ca: ["xxxx"],
                passwd: "xxxx",
                protocols: "TlsV1_2",
                useRemoteCipherPrefer: true,
                signatureAlgorithms: SHA256,
                cipherSuites: AES256-SHA256,
            },
};

tlssocket.connect(options).then(data => {
    console.info(data);
}).catch(err => {
    console.error(err);
});
```

## tlssocket.getCertificate

getCertificate(callback: AsyncCallback\<string>): void;

Obtains the local digital certificate after a TLSSocket connection is established. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description|
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string>                  | Yes  | Callback used to return the result.|

**Example**

```js
tlssocket.getCertificate((err, data) => {
  if (err) {
    console.log("getCertificate callback error = " + err);
  } else {
    console.log("getCertificate callback = " + data);
  }
});
```

## tlssocket.getCertificate

getCertificate():Promise\<string>;

Obtains the local digital certificate after a TLSSocket connection is established. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                 |
| -------------- | -------------------- |
| Promise\<string> | Promise used to return the result.|

**Example**

```js
tlssocket.getCertificate().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.getRemoteCertificate

getRemoteCertificate(callback: AsyncCallback\<string>): void;

Obtains the remote digital certificate after a TLSSocket connection is established. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type                                   | Mandatory | Description          |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string>                  | Yes  | Callback used to return the result.|

**Example**

```js
tlssocket.getRemoteCertificate((err, data) => {
  if (err) {
    console.log("getRemoteCertificate callback error = " + err);
  } else {
    console.log("getRemoteCertificate callback = " + data);
  }
});
```

## tlssocket.getRemoteCertificate

getRemoteCertificate():Promise\<string>;

Obtains the remote digital certificate after a TLSSocket connection is established. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                 |
| -------------- | -------------------- |
| Promise\<string> | Promise used to return the result.|

**Example**

```js
tlssocket.getRemoteCertificate().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.getProtocol

getProtocol(callback: AsyncCallback\<string>): void;

Obtains the communication protocol after a TLSSocket connection is established. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                      | Mandatory| Description          |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string>                  | Yes  | Callback used to return the result.      |

**Example**

```js
tlssocket.getProtocol((err, data) => {
  if (err) {
    console.log("getProtocol callback error = " + err);
  } else {
    console.log("getProtocol callback = " + data);
  }
});
```

## tlssocket.getProtocol

getProtocol():Promise\<string>;

Obtains the communication protocol after a TLSSocket connection is established. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type           | Description                 |
| -------------- | -------------------- |
| Promise\<string> | Promise used to return the result.|

**Example**

```js
tlssocket.getProtocol().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.getCipherSuites

getCipherSuites(callback: AsyncCallback\<Array\<string>>): void;

Obtains the cipher suites supported by both parties after a TLSSocket connection is established. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                    | Mandatory| Description|
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string>>          | Yes  | Callback used to return the result. |

**Example**

```js
tlssocket.getCipherSuites((err, data) => {
  if (err) {
    console.log("getCipherSuites callback error = " + err);
  } else {
    console.log("getCipherSuites callback = " + data);
  }
});
```

## tlssocket.getCipherSuites

getCipherSuites(): Promise\<Array\<string>>;

Obtains the cipher suites supported by both parties after a TLSSocket connection is established. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                   | Description                 |
| ---------------------- | --------------------- |
| Promise\<Array\<string>> | Promise used to return the result.|

**Example**

```js
tlssocket.getCipherSuites().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.getSignatureAlgorithms

getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;

Obtains the signing algorithms supported by both parties after a TLSSocket connection is established. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name  | Type                                  | Mandatory| Description           |
| -------- | -------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string>>         | Yes  | Callback used to return the result.  |

**Example**

```js
tlssocket.getSignatureAlgorithms((err, data) => {
  if (err) {
    console.log("getSignatureAlgorithms callback error = " + err);
  } else {
    console.log("getSignatureAlgorithms callback = " + data);
  }
});
```

## tlssocket.getSignatureAlgorithms

getSignatureAlgorithms(): Promise\<Array\<string>>;

Obtains the signing algorithms supported by both parties after a TLSSocket connection is established. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type                   | Description                 |
| ---------------------- | -------------------- |
| Promise\<Array\<string>> | Promise used to return the result.|

**Example**

```js
tlssocket.getSignatureAlgorithms().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.close

close(callback: AsyncCallback\<void>): void;

Closes a TLSSocket connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Parameters**

| Name   | Type                         | Mandatory| Description           |
| -------- | -----------------------------| ---- | ---------------|
| callback | AsyncCallback\<void>         | Yes  | Callback used to return the result. |

**Example**

```js
tlssocket.close((err) => {
  if (err) {
    console.log("close callback error = " + err);
  } else {
    console.log("close success");
  }
});
```

## tlssocket.close

close(): Promise\<void>;

Closes a TLSSocket connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Communication.NetStack

**Return value**

| Type          | Description                 |
| -------------- | -------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
tlssocket.close().then(() =>
  console.log("close success");
}).catch(err => {
  console.error(err);
});
```

## TLSConnectOptions

Defines a TLSSocket connection.

**System capability**: SystemCapability.Communication.NetStack

| Name         | Type                                  | Description           |
| -------------- | ------------------------------------- | -------------- |
| address        | [NetAddress](#netaddress)             | Gateway address.      |
| secureOptions  | [TLSSecureOptions](#tlssecureoptions) | TLS security options.|
| ALPNProtocols  | Array\<string>                         | Application Layer Protocol Negotiation (ALPN) protocols.     |

## NetAddress

Defines a network address.

**System capability**: SystemCapability.Communication.NetStack

| Name | Type  | Description                          |
| ------- | ------ | ---------------------------- |
| address | string | Network address.                       |
| family  | number | Address family identifier. The value is **1** for IPv4 and **2** for IPv6. The default value is **1**.|
| port    | number | Port number. The value ranges from **0** to **65535**.    |

## TLSSecureOptions

Defines TLS security options.

**System capability**: SystemCapability.Communication.NetStack

| Name                | Type                   | Description                  |
| --------------------- | ---------------------- | ---------------------- |
| ca                    | string \| Array\<string> | CA certificate.             |
| cert                  | string                 | Local digital certificate.          |
| key                   | string                 | Private key of the local digital certificate.       |
| passwd                | string                 | Password.                 |
| protocols             | string                 | Protocols.               |
| useRemoteCipherPrefer | boolean                | Whether to use the remote cipher suite preferentially.|
| signatureAlgorithms   | string                 | Signing algorithms.          |
| cipherSuites          | string                 | Cipher suites.             |
