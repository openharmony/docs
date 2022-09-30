# TLSSocket

TLS Socket通信是对Socket通信的拓展。在Socket通信的基础上添加了一层安全性保护，提供了更高的安全性，分为三个子模块，包括密钥，证书，通信。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import socket from '@ohos.net.tlssocket'
```

## socket.constructTLSSocketInstance

constructTLSSocketInstance(): TLSSocket

创建并返回一个TLSSocket对象。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**示例：**

```js
let tlssocket = socket.constructTLSSocketInstance();
```

## tlssocket.connect

connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void

在TLSSocket上进行通信连接，并创建和初始化TLS会话，实现建立连接过程，启动与服务器的TLS/SSL握手，实现数据传输功能，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型                                   | 必填 | 说明 |
| -------- | ---------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions) | 是   | 连接所需要的参数。|
| callback | AsyncCallback\<void>                  | 是   | 回调函数，成功无返回，失败返回对应错误码。 |

**示例：**

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

在TLSSocket上进行通信连接，并创建和初始化TLS会话，实现建立连接过程，启动与服务器的TLS/SSL握手，实现数据传输功能，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                   | 必填 | 说明 |
| -------- | --------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions) | 是   | 连接所需要的参数。|

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void>                              | 以Promise形式返回，成功无返回，失败返回对应错误码。 |

**示例：**

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

在TLSSocket通信连接之后，获取本地的数字证书，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                   | 必填 | 说明 |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string>                  | 是   | 回调函数，返回本地的证书。|

**示例：**

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

在TLSSocket通信连接之后，获取本地的数字证书，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                  |
| -------------- | -------------------- |
| Promise\<string> | 以Promise形式返回本地的数字证书。 |

**示例：**

```js
tlssocket.getCertificate().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.getRemoteCertificate

getRemoteCertificate(callback: AsyncCallback\<string>): void;

在TLSSocket通信连接之后，获取对等方的数字证书，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名    | 类型                                    | 必填  | 说明           |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string>                  | 是   | 回调函数，返回对等方的证书。 |

**示例：**

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

在TLSSocket通信连接之后，获取对等方的数字证书，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                  |
| -------------- | -------------------- |
| Promise\<string> | 以Promise形式返回对等方的数字证书。 |

**示例：**

```js
tlssocket.getRemoteCertificate().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.getProtocol

getProtocol(callback: AsyncCallback\<string>): void;

在TLSSocket通信连接之后，获取通信的协议，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                       | 必填 | 说明           |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string>                  | 是   | 回调函数，返回通信的协议。       |

**示例：**

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

在TLSSocket通信连接之后，获取通信的协议，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                  |
| -------------- | -------------------- |
| Promise\<string> | 以Promise形式返回通信的协议。 |

**示例：**

```js
tlssocket.getProtocol().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.getCipherSuites

getCipherSuites(callback: AsyncCallback\<Array\<string>>): void;

在TLSSocket通信连接之后，获取通信双方支持的加密套件，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明 |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string>>          | 是   | 回调函数，返回通信双方支持的加密套件。  |

**示例：**

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

在TLSSocket通信连接之后，获取通信双方支持的加密套件，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                    | 说明                  |
| ---------------------- | --------------------- |
| Promise\<Array\<string>> | 以Promise形式返回通信双方支持的加密套件。 |

**示例：**

```js
tlssocket.getCipherSuites().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.getSignatureAlgorithms

getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;

在TLSSocket通信连接之后，获取通信双方支持的签名算法，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                   | 必填 | 说明            |
| -------- | -------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string>>         | 是   | 回调函数，返回双方支持的签名算法。  |

**示例：**

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

在TLSSocket通信连接之后，获取通信双方支持的签名算法，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                    | 说明                  |
| ---------------------- | -------------------- |
| Promise\<Array\<string>> | 以Promise形式返回获取到的双方支持的签名算法。 |

**示例：**

```js
tlssocket.getSignatureAlgorithms().then(data => {
  console.info(data);
}).catch(err => {
  console.error(err);
});
```

## tlssocket.close

close(callback: AsyncCallback\<void>): void;

在TLSSocket通信连接之后，断开连接，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名    | 类型                          | 必填 | 说明            |
| -------- | -----------------------------| ---- | ---------------|
| callback | AsyncCallback\<void>         | 是   | 回调函数,返回TLSSocket关闭连接的结果。  |

**示例：**

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

在TLSSocket通信连接之后，断开连接，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型           | 说明                  |
| -------------- | -------------------- |
| Promise\<void> | 以Promise形式返回,返回TLSSocket关闭连接的结果。 |

**示例：**

```js
tlssocket.close().then(() =>
  console.log("close success");
}).catch(err => {
  console.error(err);
});
```

## TLSConnectOptions

TLS连接的操作。

**系统能力**：SystemCapability.Communication.NetStack

| 参数名          | 类型                                   | 说明            |
| -------------- | ------------------------------------- | -------------- |
| address        | [NetAddress](#netaddress)             | 网关地址。       |
| secureOptions  | [TLSSecureOptions](#tlssecureoptions) | TLS安全相关操作。|
| ALPNProtocols  | Array\<string>                         | ALPN协议。      |

## NetAddress

网络地址。

**系统能力**：SystemCapability.Communication.NetStack

| 参数名  | 类型   | 说明                           |
| ------- | ------ | ---------------------------- |
| address | string | 地址。                        |
| family  | number | IPv4 = 1，IPv6 = 2，默认IPv4。 |
| port    | number | 端口，取值范围\[0, 65535]。     |

## TLSSecureOptions

TLS安全相关操作。

**系统能力**：SystemCapability.Communication.NetStack

| 参数名                 | 类型                    | 说明                   |
| --------------------- | ---------------------- | ---------------------- |
| ca                    | string \| Array\<string> | ca证书。              |
| cert                  | string                 | 本地数字证书。           |
| key                   | string                 | 本地数字证书私钥。        |
| passwd                | string                 | 密码。                  |
| protocols             | string                 | 协议名。                |
| useRemoteCipherPrefer | boolean                | 优先使用对等方的密码套件。 |
| signatureAlgorithms   | string                 | 设置签名算法。           |
| cipherSuites          | string                 | 加密套件。              |