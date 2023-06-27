# @ohos.net.socket (Socket连接)

本模块提供利用Socket进行数据传输的能力，支持TCPSocket、UDPSocket、WebSocket和TLSSocket。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import socket from '@ohos.net.socket';
```

## socket.constructUDPSocketInstance<sup>7+</sup>

constructUDPSocketInstance(): UDPSocket

创建一个UDPSocket对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                               | 说明                    |
| :--------------------------------- | :---------------------- |
| [UDPSocket](#udpsocket) | 返回一个UDPSocket对象。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
```

## UDPSocket<sup>7+</sup>

UDPSocket连接。在调用UDPSocket的方法前，需要先通过[socket.constructUDPSocketInstance](#socketconstructudpsocketinstance)创建UDPSocket对象。

### bind<sup>7+</sup>

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

绑定IP地址和端口，端口可以指定或由系统随机分配。使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                   |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |
| callback | AsyncCallback\<void\>              | 是   | 回调函数。                                             |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1}, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
})
```

### bind<sup>7+</sup>

bind(address: NetAddress): Promise\<void\>

绑定IP地址和端口，端口可以指定或由系统随机分配。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                               | 必填 | 说明                                                   |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress) | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**返回值：**

| 类型            | 说明                                       |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | 以Promise形式异步返回UDPSocket绑定的结果。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let promise = udp.bind({ address: '192.168.xx.xxx', port: 8080, family: 1 });
promise.then(() => {
  console.log('bind success');
}).catch(err => {
  console.log('bind fail');
});
```

### send<sup>7+</sup>

send(options: UDPSendOptions, callback: AsyncCallback\<void\>): void

通过UDPSocket连接发送数据。使用callback方式作为异步方法。

发送数据前，需要先调用[UDPSocket.bind()](#bind)绑定IP地址和端口。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPSendOptions](#udpsendoptions) | 是   | UDPSocket发送参数，参考[UDPSendOptions](#udpsendoptions)。 |
| callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.send({
  data: 'Hello, server!',
  address: {
    address: '192.168.xx.xxx',
    port: xxxx,
    family: 1
  }
}, err => {
  if (err) {
    console.log('send fail');
    return;
  }
  console.log('send success');
})
```

### send<sup>7+</sup>

send(options: UDPSendOptions): Promise\<void\>

通过UDPSocket连接发送数据。使用Promise方式作为异步方法。

发送数据前，需要先调用[UDPSocket.bind()](#bind)绑定IP地址和端口。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                                                         |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [UDPSendOptions](#udpsendoptions) | 是   | UDPSocket发送参数，参考[UDPSendOptions](#udpsendoptions)。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**返回值：**

| 类型            | 说明                                           |
| :-------------- | :--------------------------------------------- |
| Promise\<void\> | 以Promise形式返回UDPSocket连接发送数据的结果。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let promise = udp.send({
  data: 'Hello, server!',
  address: {
    address: '192.168.xx.xxx',
    port: xxxx,
    family: 1
  }
});
promise.then(() => {
  console.log('send success');
}).catch(err => {
  console.log('send fail');
});
```

### close<sup>7+</sup>

close(callback: AsyncCallback\<void\>): void

关闭UDPSocket连接。使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.close(err => {
  if (err) {
    console.log('close fail');
    return;
  }
  console.log('close success');
})
```

### close<sup>7+</sup>

close(): Promise\<void\>

关闭UDPSocket连接。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                                       |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | 以Promise形式返回关闭UDPSocket连接的结果。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let promise = udp.close();
promise.then(() => {
  console.log('close success');
}).catch(err => {
  console.log('close fail');
});
```

### getState<sup>7+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

获取UDPSocket状态。使用callback方式作为异步方法。

> **说明：**
> bind方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback<[SocketStateBase](#socketstatebase)> | 是   | 回调函数。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1}, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  udp.getState((err, data) => {
    if (err) {
      console.log('getState fail');
      return;
    }
    console.log('getState success:' + JSON.stringify(data));
  })
})
```

### getState<sup>7+</sup>

getState(): Promise\<SocketStateBase\>

获取UDPSocket状态。使用Promise方式作为异步方法。

> **说明：**
> bind方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                             | 说明                                       |
| :----------------------------------------------- | :----------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)\> | 以Promise形式返回获取UDPSocket状态的结果。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let promise = udp.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 });
promise.then(err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  let promise = udp.getState();
  promise.then(data => {
    console.log('getState success:' + JSON.stringify(data));
  }).catch(err => {
    console.log('getState fail');
  });
});
```

### setExtraOptions<sup>7+</sup>

setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void\>): void

设置UDPSocket连接的其他属性。使用callback方式作为异步方法。

> **说明：**
> bind方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPExtraOptions](#udpextraoptions) | 是   | UDPSocket连接的其他属性，参考[UDPExtraOptions](#udpextraoptions)。 |
| callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  udp.setExtraOptions({
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: false,
    socketTimeout: 6000,
    broadcast: true
  }, err => {
    if (err) {
      console.log('setExtraOptions fail');
      return;
    }
    console.log('setExtraOptions success');
  })
})
```

### setExtraOptions<sup>7+</sup>

setExtraOptions(options: UDPExtraOptions): Promise\<void\>

设置UDPSocket连接的其他属性。使用Promise方式作为异步方法。

> **说明：**
> bind方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                                                         |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [UDPExtraOptions](#udpextraoptions) | 是   | UDPSocket连接的其他属性，参考[UDPExtraOptions](#udpextraoptions)。 |

**返回值：**

| 类型            | 说明                                                 |
| :-------------- | :--------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回设置UDPSocket连接的其他属性的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let promise = udp.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 });
promise.then(() => {
  console.log('bind success');
  let promise1 = udp.setExtraOptions({
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: false,
    socketTimeout: 6000,
    broadcast: true
  });
  promise1.then(() => {
    console.log('setExtraOptions success');
  }).catch(err => {
    console.log('setExtraOptions fail');
  });
}).catch(err => {
  console.log('bind fail');
});
```

### on('message')<sup>7+</sup>

on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

订阅UDPSocket连接的接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback\<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}\> | 是   | 回调函数。                                |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let messageView = '';
udp.on('message', value => {
  for (var i = 0; i < value.message.length; i++) {
    let messages = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')<sup>7+</sup>

off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

取消订阅UDPSocket连接的接收消息事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 否   | 回调函数。                                |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let messageView = '';
let callback = value => {
  for (var i = 0; i < value.message.length; i++) {
    let messages = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
udp.on('message', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('message', callback);
udp.off('message');
```

### on('listening' | 'close')<sup>7+</sup>

on(type: 'listening' | 'close', callback: Callback\<void\>): void

订阅UDPSocket连接的数据包消息事件或关闭事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅的事件类型。<br />- 'listening'：数据包消息事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 是   | 回调函数。                                                   |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.on('listening', () => {
  console.log("on listening success");
});
udp.on('close', () => {
  console.log("on close success");
});
```

### off('listening' | 'close')<sup>7+</sup>

off(type: 'listening' | 'close', callback?: Callback\<void\>): void

取消订阅UDPSocket连接的数据包消息事件或关闭事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅事件类型。<br />- 'listening'：数据包消息事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 否   | 回调函数。                                                   |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let callback1 = () => {
  console.log("on listening, success");
}
udp.on('listening', callback1);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('listening', callback1);
udp.off('listening');
let callback2 = () => {
  console.log("on close, success");
}
udp.on('close', callback2);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('close', callback2);
udp.off('close');
```

### on('error')<sup>7+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅UDPSocket连接的error事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.on('error', err => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>7+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅UDPSocket连接的error事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let callback = err => {
  console.log("on error, err:" + JSON.stringify(err));
}
udp.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('error', callback);
udp.off('error');
```

## NetAddress<sup>7+</sup>

目标地址信息。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | 是   | 本地绑定的ip地址。                                           |
| port    | number | 否   | 端口号 ，范围0~65535。如果不指定系统随机分配端口。           |
| family  | number | 否   | 网络协议类型，可选类型：<br />- 1：IPv4<br />- 2：IPv6<br />默认为1。 |

## UDPSendOptions<sup>7+</sup>

UDPSocket发送参数。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  | 类型                               | 必填 | 说明           |
| ------- | ---------------------------------- | ---- | -------------- |
| data    | string \| ArrayBuffer<sup>7+</sup>                          | 是   | 发送的数据。   |
| address | [NetAddress](#netaddress) | 是   | 目标地址信息。 |

## UDPExtraOptions<sup>7+</sup>

UDPSocket连接的其他属性。

**系统能力**：SystemCapability.Communication.NetStack

| 名称            | 类型    | 必填 | 说明                             |
| ----------------- | ------- | ---- | -------------------------------- |
| broadcast         | boolean | 否   | 是否可以发送广播。默认为false。  |
| receiveBufferSize | number  | 否   | 接收缓冲区大小（单位：Byte），默认为0。   |
| sendBufferSize    | number  | 否   | 发送缓冲区大小（单位：Byte），默认为0。   |
| reuseAddress      | boolean | 否   | 是否重用地址。默认为false。      |
| socketTimeout     | number  | 否   | 套接字超时时间，单位毫秒（ms），默认为0。 |

## SocketStateBase<sup>7+</sup>

Socket的状态信息。

**系统能力**：SystemCapability.Communication.NetStack

| 名称      | 类型    | 必填 | 说明       |
| ----------- | ------- | ---- | ---------- |
| isBound     | boolean | 是   | 是否绑定。 |
| isClose     | boolean | 是   | 是否关闭。 |
| isConnected | boolean | 是   | 是否连接。 |

## SocketRemoteInfo<sup>7+</sup>

Socket的连接信息。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | 是   | 本地绑定的ip地址。                                           |
| family  | string | 是   | 网络协议类型，可选类型：<br />- IPv4<br />- IPv6<br />默认为IPv4。 |
| port    | number | 是   | 端口号，范围0~65535。                                        |
| size    | number | 是   | 服务器响应信息的字节长度。                                   |

## UDP 错误码说明

UDP 其余错误码映射形式为：2301000 + Linux内核错误码。

错误码的详细介绍参见[Socket错误码](../errorcodes/errorcode-net-socket.md)

## socket.constructTCPSocketInstance<sup>7+</sup>

constructTCPSocketInstance(): TCPSocket

创建一个TCPSocket对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                               | 说明                    |
  | :--------------------------------- | :---------------------- |
| [TCPSocket](#tcpsocket) | 返回一个TCPSocket对象。 |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
```

## TCPSocket<sup>7+</sup>

TCPSocket连接。在调用TCPSocket的方法前，需要先通过[socket.constructTCPSocketInstance](#socketconstructtcpsocketinstance)创建TCPSocket对象。

### bind<sup>7+</sup>

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

绑定IP地址和端口，端口可以指定或由系统随机分配。使用callback方法作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                   |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |
| callback | AsyncCallback\<void\>              | 是   | 回调函数。                                             |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
tcp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1}, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
})
```

### bind<sup>7+</sup>

bind(address: NetAddress): Promise\<void\>

绑定IP地址和端口，端口可以指定或由系统随机分配。使用Promise方法作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                               | 必填 | 说明                                                   |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress) | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |

**返回值：**

| 类型            | 说明                                                     |
| :-------------- | :------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回TCPSocket绑定本机的IP地址和端口的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 });
promise.then(() => {
  console.log('bind success');
}).catch(err => {
  console.log('bind fail');
});
```

### connect<sup>7+</sup>

connect(options: TCPConnectOptions, callback: AsyncCallback\<void\>): void

连接到指定的IP地址和端口。使用callback方法作为异步方法。

> **说明：**
> bind方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPConnectOptions](#tcpconnectoptions) | 是   | TCPSocket连接的参数，参考[TCPConnectOptions](#tcpconnectoptions)。 |
| callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 }, err => {
  if (err) {
    console.log('connect fail');
    return;
  }
  console.log('connect success');
})
```

### connect<sup>7+</sup>

connect(options: TCPConnectOptions): Promise\<void\>

连接到指定的IP地址和端口。使用promise方法作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                                                         |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPConnectOptions](#tcpconnectoptions) | 是   | TCPSocket连接的参数，参考[TCPConnectOptions](#tcpconnectoptions)。 |

**返回值：**

| 类型            | 说明                                                       |
| :-------------- | :--------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回TCPSocket连接到指定的IP地址和端口的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 });
promise.then(() => {
  console.log('connect success')
}).catch(err => {
  console.log('connect fail');
});
```

### send<sup>7+</sup>

send(options: TCPSendOptions, callback: AsyncCallback\<void\>): void

通过TCPSocket连接发送数据。使用callback方式作为异步方法。

> **说明：**
> connect方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPSendOptions](#tcpsendoptions) | 是   | TCPSocket发送请求的参数，参考[TCPSendOptions](#tcpsendoptions)。 |
| callback | AsyncCallback\<void\>                   | 是   | 回调函数。                                                   |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 }, () => {
  console.log('connect success');
  tcp.send({
    data: 'Hello, server!'
    //此处省略encoding， 默认为utf-8编码格式
  }, err => {
    if (err) {
      console.log('send fail');
      return;
    }
    console.log('send success');
  })
})
```

### send<sup>7+</sup>

send(options: TCPSendOptions): Promise\<void\>

通过TCPSocket连接发送数据。使用Promise方式作为异步方法。

> **说明：**
> connect方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                    | 必填 | 说明                                                         |
| ------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPSendOptions](#tcpsendoptions) | 是   | TCPSocket发送请求的参数，参考[TCPSendOptions](#tcpsendoptions)。 |

**返回值：**

| 类型            | 说明                                               |
| :-------------- | :------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回通过TCPSocket连接发送数据的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise1 = tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 });
promise1.then(() => {
  console.log('connect success');
  let promise2 = tcp.send({
    data: 'Hello, server!'
  });
  promise2.then(() => {
    console.log('send success');
  }).catch(err => {
    console.log('send fail');
  });
}).catch(err => {
  console.log('connect fail');
});
```

### close<sup>7+</sup>

close(callback: AsyncCallback\<void\>): void

关闭TCPSocket连接。使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
tcp.close(err => {
  if (err) {
    console.log('close fail');
    return;
  }
  console.log('close success');
})
```

### close<sup>7+</sup>

close(): Promise\<void\>

关闭TCPSocket连接。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                                       |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | 以Promise形式返回关闭TCPSocket连接的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.close();
promise.then(() => {
  console.log('close success');
}).catch(err => {
  console.log('close fail');
});
```

### getRemoteAddress<sup>7+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

获取对端Socket地址。使用callback方式作为异步方法。

> **说明：**
> connect方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                              | 必填 | 说明       |
| -------- | ------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback<[NetAddress](#netaddress)> | 是   | 回调函数。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 }, () => {
  console.log('connect success');
  tcp.getRemoteAddress((err, data) => {
    if (err) {
      console.log('getRemoteAddressfail');
      return;
    }
    console.log('getRemoteAddresssuccess:' + JSON.stringify(data));
  })
});
```

### getRemoteAddress<sup>7+</sup>

getRemoteAddress(): Promise\<NetAddress\>

获取对端Socket地址。使用Promise方式作为异步方法。

> **说明：**
> connect方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                        | 说明                                        |
| :------------------------------------------ | :------------------------------------------ |
| Promise<[NetAddress](#netaddress)> | 以Promise形式返回获取对端socket地址的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise1 = tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 });
promise1.then(() => {
  console.log('connect success');
  let promise2 = tcp.getRemoteAddress();
  promise2.then(() => {
    console.log('getRemoteAddress success');
  }).catch(err => {
    console.log('getRemoteAddressfail');
  });
}).catch(err => {
  console.log('connect fail');
});
```

### getState<sup>7+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

获取TCPSocket状态。使用callback方式作为异步方法。

> **说明：**
> bind或connect方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback<[SocketStateBase](#socketstatebase)> | 是   | 回调函数。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 }, () => {
  console.log('connect success');
  tcp.getState((err, data) => {
    if (err) {
      console.log('getState fail');
      return;
    }
    console.log('getState success:' + JSON.stringify(data));
  });
});
```

### getState<sup>7+</sup>

getState(): Promise\<SocketStateBase\>

获取TCPSocket状态。使用Promise方式作为异步方法。

> **说明：**
> bind或connect方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                             | 说明                                       |
| :----------------------------------------------- | :----------------------------------------- |
| Promise<[SocketStateBase](#socketstatebase)> | 以Promise形式返回获取TCPSocket状态的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 });
promise.then(() => {
  console.log('connect success');
  let promise1 = tcp.getState();
  promise1.then(() => {
    console.log('getState success');
  }).catch(err => {
    console.log('getState fail');
  });
}).catch(err => {
  console.log('connect fail');
});
```

### setExtraOptions<sup>7+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

设置TCPSocket连接的其他属性。使用callback方式作为异步方法。

> **说明：**
> bind或connect方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | 是   | TCPSocket连接的其他属性，参考[TCPExtraOptions](#tcpextraoptions)。 |
| callback | AsyncCallback\<void\>                     | 是   | 回调函数。                                                   |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 }, () => {
  console.log('connect success');
  tcp.setExtraOptions({
    keepAlive: true,
    OOBInline: true,
    TCPNoDelay: true,
    socketLinger: { on: true, linger: 10 },
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: true,
    socketTimeout: 3000,
  }, err => {
    if (err) {
      console.log('setExtraOptions fail');
      return;
    }
    console.log('setExtraOptions success');
  });
});
```

### setExtraOptions<sup>7+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

设置TCPSocket连接的其他属性，使用Promise方式作为异步方法。

> **说明：**
> bind或connect方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions) | 是   | TCPSocket连接的其他属性，参考[TCPExtraOptions](#tcpextraoptions)。 |

**返回值：**

| 类型            | 说明                                                 |
| :-------------- | :--------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回设置TCPSocket连接的其他属性的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: { address: '192.168.xx.xxx', port: xxxx, family: 1 }, timeout: 6000 });
promise.then(() => {
  console.log('connect success');
  let promise1 = tcp.setExtraOptions({
    keepAlive: true,
    OOBInline: true,
    TCPNoDelay: true,
    socketLinger: { on: true, linger: 10 },
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: true,
    socketTimeout: 3000,
  });
  promise1.then(() => {
    console.log('setExtraOptions success');
  }).catch(err => {
    console.log('setExtraOptions fail');
  });
}).catch(err => {
  console.log('connect fail');
});
```

### on('message')<sup>7+</sup>

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

订阅TCPSocket连接的接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 是   | 回调函数。                                |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let messageView = '';
tcp.on('message', value => {
  for (var i = 0; i < value.message.length; i++) {
    let messages = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')<sup>7+</sup>

off(type: 'message', callback?: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

取消订阅TCPSocket连接的接收消息事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 否   | 回调函数。                                |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let messageView = '';
let callback = value => {
  for (var i = 0; i < value.message.length; i++) {
    let messages = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
tcp.on('message', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('message', callback);
tcp.off('message');
```

### on('connect' | 'close')<sup>7+</sup>

on(type: 'connect' | 'close', callback: Callback\<void\>): void

订阅TCPSocket的连接事件或关闭事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅的事件类型。<br />- 'connect'：连接事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 是   | 回调函数。                                                   |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
tcp.on('connect', () => {
  console.log("on connect success")
});
tcp.on('close', () => {
  console.log("on close success")
});
```

### off('connect' | 'close')<sup>7+</sup>

off(type: 'connect' | 'close', callback?: Callback\<void\>): void

取消订阅TCPSocket的连接事件或关闭事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅的事件类型。<br />- 'connect'：连接事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 否   | 回调函数。                                                   |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let callback1 = () => {
  console.log("on connect success");
}
tcp.on('connect', callback1);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('connect', callback1);
tcp.off('connect');
let callback2 = () => {
  console.log("on close success");
}
tcp.on('close', callback2);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('close', callback2);
tcp.off('close');
```

### on('error')<sup>7+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅TCPSocket连接的error事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
tcp.on('error', err => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>7+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅TCPSocket连接的error事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let callback = err => {
  console.log("on error, err:" + JSON.stringify(err));
}
tcp.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('error', callback);
tcp.off('error');
```

## TCPConnectOptions<sup>7+</sup>

TCPSocket连接的参数。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  | 类型                               | 必填 | 说明                       |
| ------- | ---------------------------------- | ---- | -------------------------- |
| address | [NetAddress](#netaddress) | 是   | 绑定的地址以及端口。       |
| timeout | number                             | 否   | 超时时间，单位毫秒（ms）。 |

## TCPSendOptions<sup>7+</sup>

TCPSocket发送请求的参数。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| data     | string\| ArrayBuffer<sup>7+</sup>  | 是   | 发送的数据。                                                 |
| encoding | string | 否   | 字符编码(UTF-8，UTF-16BE，UTF-16LE，UTF-16，US-AECII，ISO-8859-1)，默认为UTF-8。 |

## TCPExtraOptions<sup>7+</sup>

TCPSocket连接的其他属性。

**系统能力**：SystemCapability.Communication.NetStack

| 名称            | 类型    | 必填 | 说明                                                         |
| ----------------- | ------- | ---- | ------------------------------------------------------------ |
| keepAlive         | boolean | 否   | 是否保持连接。默认为false。                                  |
| OOBInline         | boolean | 否   | 是否为OOB内联。默认为false。                                 |
| TCPNoDelay        | boolean | 否   | TCPSocket连接是否无时延。默认为false。                       |
| socketLinger      | Object  | 是   | socket是否继续逗留。<br />- on：是否逗留（true：逗留；false：不逗留）。<br />- linger：逗留时长，单位毫秒（ms），取值范围为0~65535。<br />当入参on设置为true时，才需要设置。 |
| receiveBufferSize | number  | 否   | 接收缓冲区大小（单位：Byte），默认为0。                               |
| sendBufferSize    | number  | 否   | 发送缓冲区大小（单位：Byte），默认为0。                               |
| reuseAddress      | boolean | 否   | 是否重用地址。默认为false。                                  |
| socketTimeout     | number  | 否   | 套接字超时时间，单位毫秒（ms），默认为0。                             |

## TCP 错误码说明

TCP 其余错误码映射形式为：2301000 + Linux内核错误码。

错误码的详细介绍参见[Socket错误码](../errorcodes/errorcode-net-socket.md)

## socket.constructTLSSocketInstance<sup>9+</sup>

constructTLSSocketInstance(): TLSSocket

创建并返回一个TLSSocket对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值:**

| 类型                               | 说明                    |
| :--------------------------------- | :---------------------- |
| [TLSSocket](#tlssocket9) | 返回一个TLSSocket对象。 |

**示例：**

```js
let tls = socket.constructTLSSocketInstance();
```

## TLSSocket<sup>9+</sup>

TLSSocket连接。在调用TLSSocket的方法前，需要先通过[socket.constructTLSSocketInstance](#socketconstructtlssocketinstance9)创建TLSSocket对象。

### bind<sup>9+</sup>

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

绑定IP地址和端口。使用callback方法作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                   |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |
| callback | AsyncCallback\<void\>              | 是   | 回调函数。成功返回TLSSocket绑定本机的IP地址和端口的结果。 失败返回错误码，错误信息。|

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2303198 | Address already in use. |
| 2300002 | System internal error.  |

**示例：**

```js
tls.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
```

### bind<sup>9+</sup>

bind(address: NetAddress): Promise\<void\>

绑定IP地址和端口。使用Promise方法作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                               | 必填 | 说明                                                   |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress)          | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |

**返回值：**

| 类型            | 说明                                                     |
| :-------------- | :------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回TLSSocket绑定本机的IP地址和端口的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2303198 | Address already in use. |
| 2300002 | System internal error.  |

**示例：**

```js
let promise = tls.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 });
promise.then(() => {
  console.log('bind success');
}).catch(err => {
  console.log('bind fail');
});
```

### getState<sup>9+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

在TLSSocket的bind成功之后，获取TLSSocket状态。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase)> | 是   | 回调函数。成功返回TLSSocket状态，失败返回错误码,错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**示例：**

```js
let promise = tls.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
tls.getState((err, data) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
});
```

### getState<sup>9+</sup>

getState(): Promise\<SocketStateBase\>

在TLSSocket的bind成功之后，获取TLSSocket状态。使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                             | 说明                                       |
| :----------------------------------------------- | :----------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)> | 以Promise形式返回获取TLSSocket状态的结果。失败返回错误码，错误信息。|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**示例：**

```js
let promiseBind = tls.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 });
promiseBind.then(() => {
  console.log('bind success');
}).catch((err) => {
  console.log('bind fail');
});
let promise = tls.getState();
promise.then(() => {
  console.log('getState success');
}).catch(err => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>9+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

在TLSSocket的bind成功之后，设置TCPSocket连接的其他属性。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | 是   | TCPSocket连接的其他属性，参考[TCPExtraOptions](#tcpextraoptions)。 |
| callback | AsyncCallback\<void\>                     | 是   | 回调函数。成功返回设置TCPSocket连接的其他属性的结果，失败返回错误码，错误信息。|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.               |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**示例：**

```js
tls.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

tls.setExtraOptions({
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 },
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000,
}, err => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>9+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

在TLSSocket的bind成功之后，设置TCPSocket连接的其他属性，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions) | 是   | TCPSocket连接的其他属性，参考[TCPExtraOptions](#tcpextraoptions)。 |

**返回值：**

| 类型            | 说明                                                 |
| :-------------- | :--------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回设置TCPSocket连接的其他属性的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 401     | Parameter error.               |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**示例：**

```js
tls.bind({ address: '192.168.xx.xxx', port: xxxx, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let promise = tls.setExtraOptions({
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 },
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000,
});
promise.then(() => {
  console.log('setExtraOptions success');
}).catch(err => {
  console.log('setExtraOptions fail');
});
```

### on('message')<sup>9+</sup>

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;

订阅TLSSocket连接的接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback\<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}\> | 是   | 回调函数。message：接收到的消息；remoteInfo：socket连接信息。 |

**示例：**

```js
let tls = socket.constructTLSSocketInstance();
let messageView = '';
tls.on('message', value => {
  for (var i = 0; i < value.message.length; i++) {
    let messages = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')<sup>9+</sup>

off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

取消订阅TLSSocket连接的接收消息事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 否   | 回调函数。message：接收到的消息；remoteInfo：socket连接信息。 |

**示例：**

```js
let tls = socket.constructTLSSocketInstance();
let messageView = '';
let callback = value => {
  for (var i = 0; i < value.message.length; i++) {
    let messages = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
tls.on('message', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tls.off('message', callback);
```
### on('connect' | 'close')<sup>9+</sup>

on(type: 'connect' | 'close', callback: Callback\<void\>): void

订阅TLSSocket的连接事件或关闭事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅的事件类型。<br />- 'connect'：连接事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 是   | 回调函数。                                                   |

**示例：**

```js
let tls = socket.constructTLSSocketInstance();
tls.on('connect', () => {
  console.log("on connect success")
});
tls.on('close', () => {
  console.log("on close success")
});
```

### off('connect' | 'close')<sup>9+</sup>

off(type: 'connect' | 'close', callback?: Callback\<void\>): void

取消订阅TLSSocket的连接事件或关闭事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅的事件类型。<br />- 'connect'：连接事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 否   | 回调函数。                                                   |

**示例：**

```js
let tls = socket.constructTLSSocketInstance();
let callback1 = () => {
  console.log("on connect success");
}
tls.on('connect', callback1);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tls.off('connect', callback1);
tls.off('connect');
let callback2 = () => {
  console.log("on close success");
}
tls.on('close', callback2);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tls.off('close', callback2);
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅TLSSocket连接的error事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**示例：**

```js
let tls = socket.constructTLSSocketInstance();
tls.on('error', err => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>9+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅TLSSocket连接的error事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**示例：**

```js
let tls = socket.constructTLSSocketInstance();
let callback = err => {
  console.log("on error, err:" + JSON.stringify(err));
}
tls.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tls.off('error', callback);
```

### connect<sup>9+</sup>

connect(options: TLSConnectOptions, callback: AsyncCallback\<void\>): void

在TLSSocket上bind成功之后，进行通信连接，并创建和初始化TLS会话，实现建立连接过程，启动与服务器的TLS/SSL握手，实现数据传输功能，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                   | 必填 | 说明 |
| -------- | ---------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions9) | 是   | TLSSocket连接所需要的参数。|
| callback | AsyncCallback\<void>                  | 是   | 回调函数，成功无返回，失败返回错误码，错误信息。|

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303104 | Interrupted system call.                     |
| 2303109 | Bad file number.                             |
| 2303111 | Resource temporarily unavailable try again.  |
| 2303188 | Socket operation on non-socket.              |
| 2303191 | Protocol wrong type for socket.              |
| 2303198 | Address already in use.                      |
| 2303199 | Cannot assign requested address.             |
| 2303210 | Connection timed out.                        |
| 2303501 | SSL is null.                                 |
| 2303502 | Error in tls reading.                        |
| 2303503 | Error in tls writing                         |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**示例：**

```js
let tlsTwoWay = socket.constructTLSSocketInstance(); // Two way authentication
tlsTwoWay.bind({ address: '192.168.xxx.xxx', port: 8080, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let options = {
  ALPNProtocols: ["spdy/1", "http/1.1"],
  address: {
    address: "192.168.xx.xxx",
    port: 8080,
    family: 1,
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: [socket.Protocol.TLSv12],
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256",
  },
};
tlsTwoWay.connect(options, (err, data) => {
  console.error("connect callback error" + err);
  console.log(JSON.stringify(data));
});

let tlsOneWay = socket.constructTLSSocketInstance(); // One way authentication
tlsOneWay.bind({ address: '192.168.xxx.xxx', port: 8080, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let oneWayOptions = {
  address: {
    address: "192.168.xxx.xxx",
    port: 8080,
    family: 1,
  },
  secureOptions: {
    ca: ["xxxx", "xxxx"],
    cipherSuite: "AES256-SHA256",
  },
};
tlsOneWay.connect(oneWayOptions, (err, data) => {
  console.error("connect callback error" + err);
  console.log(JSON.stringify(data));
});
```

### connect<sup>9+</sup>

connect(options: TLSConnectOptions): Promise\<void\>

在TLSSocket上bind成功之后，进行通信连接，并创建和初始化TLS会话，实现建立连接过程，启动与服务器的TLS/SSL握手，实现数据传输功能，该连接包括两种认证方式，单向认证与双向认证，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                   | 必填 | 说明 |
| -------- | --------------------------------------| ----| --------------- |
| options  | [TLSConnectOptions](#tlsconnectoptions9) | 是   | 连接所需要的参数。|

**返回值：**

| 类型                                        | 说明                          |
| ------------------------------------------- | ----------------------------- |
| Promise\<void\>                              | 以Promise形式返回，成功无返回，失败返回错误码，错误信息。|

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303104 | Interrupted system call.                     |
| 2303109 | Bad file number.                             |
| 2303111 | Resource temporarily unavailable try again.  |
| 2303188 | Socket operation on non-socket.              |
| 2303191 | Protocol wrong type for socket.              |
| 2303198 | Address already in use.                      |
| 2303199 | Cannot assign requested address.             |
| 2303210 | Connection timed out.                        |
| 2303501 | SSL is null.                                 |
| 2303502 | Error in tls reading.                        |
| 2303503 | Error in tls writing                         |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**示例：**

```js
let tlsTwoWay = socket.constructTLSSocketInstance(); // Two way authentication
tlsTwoWay.bind({ address: '192.168.xxx.xxx', port: 8080, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let options = {
  ALPNProtocols: ["spdy/1", "http/1.1"],
  address: {
    address: "xxxx",
    port: 8080,
    family: 1,
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: [socket.Protocol.TLSv12],
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256",
  },
};
tlsTwoWay.connect(options).then(data => {
  console.log(JSON.stringify(data));
}).catch(err => {
  console.error(err);
});

let tlsOneWay = socket.constructTLSSocketInstance(); // One way authentication
tlsOneWay.bind({ address: '192.168.xxx.xxx', port: 8080, family: 1 }, err => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
let oneWayOptions = {
  address: {
    address: "192.168.xxx.xxx",
    port: 8080,
    family: 1,
  },
  secureOptions: {
    ca: ["xxxx", "xxxx"],
    cipherSuite: "AES256-SHA256",
  },
};
tlsOneWay.connect(oneWayOptions).then(data => {
  console.log(JSON.stringify(data));
}).catch(err => {
  console.error(err);
});
```

### getRemoteAddress<sup>9+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

在TLSSocket通信连接成功之后，获取对端Socket地址。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                              | 必填 | 说明       |
| -------- | ------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetAddress](#netaddress)\> | 是   | 回调函数。成功返回对端的socket地址，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**示例：**

```js
tls.getRemoteAddress((err, data) => {
  if (err) {
    console.log('getRemoteAddress fail');
    return;
  }
  console.log('getRemoteAddress success:' + JSON.stringify(data));
});
```

### getRemoteAddress<sup>9+</sup>

getRemoteAddress(): Promise\<NetAddress\>

在TLSSocket通信连接成功之后，获取对端Socket地址。使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                        | 说明                                        |
| :------------------------------------------ | :------------------------------------------ |
| Promise\<[NetAddress](#netaddress)> | 以Promise形式返回获取对端socket地址的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303188 | Socket operation on non-socket.|
| 2300002 | System internal error.         |

**示例：**

```js
let promise = tls.getRemoteAddress();
promise.then(() => {
  console.log('getRemoteAddress success');
}).catch(err => {
  console.log('getRemoteAddress fail');
});
```

### getCertificate<sup>9+</sup>

getCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

在TLSSocket通信连接成功之后，获取本地的数字证书，该接口只适用于双向认证时，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                   | 必填 | 说明 |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>    | 是   | 回调函数，成功返回本地的证书，失败返回错误码，错误信息。|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303504 | Error looking up x509.         |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getCertificate((err, data) => {
  if (err) {
    console.log("getCertificate callback error = " + err);
  } else {
    console.log("getCertificate callback = " + data);
  }
});
```

### getCertificate<sup>9+</sup>

getCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

在TLSSocket通信连接之后，获取本地的数字证书，该接口只适用于双向认证时，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                  |
| -------------- | -------------------- |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | 以Promise形式返回本地的数字证书的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303504 | Error looking up x509.         |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getCertificate().then(data => {
  console.log(data);
}).catch(err => {
  console.error(err);
});
```

### getRemoteCertificate<sup>9+</sup>

getRemoteCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

在TLSSocket通信连接成功之后，获取服务端的数字证书，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名    | 类型                                    | 必填  | 说明           |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>  | 是   | 回调函数，返回服务端的证书。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getRemoteCertificate((err, data) => {
  if (err) {
    console.log("getRemoteCertificate callback error = " + err);
  } else {
    console.log("getRemoteCertificate callback = " + data);
  }
});
```

### getRemoteCertificate<sup>9+</sup>

getRemoteCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

在TLSSocket通信连接成功之后，获取服务端的数字证书，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                  |
| -------------- | -------------------- |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | 以Promise形式返回服务端的数字证书的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getRemoteCertificate().then(data => {
  console.log(data);
}).catch(err => {
  console.error(err);
});
```

### getProtocol<sup>9+</sup>

getProtocol(callback: AsyncCallback\<string\>): void

在TLSSocket通信连接成功之后，获取通信的协议版本，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                       | 必填 | 说明           |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<string\>                  | 是   | 回调函数，返回通信的协议。失败返回错误码，错误信息。|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2303501 | SSL is null.                   |
| 2303505 | Error occurred in the tls system call. |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getProtocol((err, data) => {
  if (err) {
    console.log("getProtocol callback error = " + err);
  } else {
    console.log("getProtocol callback = " + data);
  }
});
```

### getProtocol<sup>9+</sup>

getProtocol():Promise\<string\>

在TLSSocket通信连接成功之后，获取通信的协议版本，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                  |
| -------------- | -------------------- |
| Promise\<string\> | 以Promise形式返回通信的协议。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303505 | Error occurred in the tls system call. |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getProtocol().then(data => {
  console.log(data);
}).catch(err => {
  console.error(err);
});
```

### getCipherSuite<sup>9+</sup>

getCipherSuite(callback: AsyncCallback\<Array\<string\>\>): void

在TLSSocket通信连接成功之后，获取通信双方协商后的加密套件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明 |
| -------- | ----------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string\>\>          | 是   | 回调函数，返回通信双方支持的加密套件。 失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303502 | Error in tls reading.          |
| 2303505 | Error occurred in the tls system call. |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getCipherSuite((err, data) => {
  if (err) {
    console.log("getCipherSuite callback error = " + err);
  } else {
    console.log("getCipherSuite callback = " + data);
  }
});
```

### getCipherSuite<sup>9+</sup>

getCipherSuite(): Promise\<Array\<string\>\>

在TLSSocket通信连接成功之后，获取通信双方协商后的加密套件，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                    | 说明                  |
| ---------------------- | --------------------- |
| Promise\<Array\<string\>\> | 以Promise形式返回通信双方支持的加密套件。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2303502 | Error in tls reading.          |
| 2303505 | Error occurred in the tls system call. |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getCipherSuite().then(data => {
  console.log('getCipherSuite success:' + JSON.stringify(data));
}).catch(err => {
  console.error(err);
});
```

### getSignatureAlgorithms<sup>9+</sup>

getSignatureAlgorithms(callback: AsyncCallback\<Array\<string\>\>): void

在TLSSocket通信连接成功之后，获取通信双方协商后签名算法，该接口只适配双向认证模式下，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                   | 必填 | 说明            |
| -------- | -------------------------------------| ---- | ---------------|
| callback | AsyncCallback\<Array\<string\>\>         | 是   | 回调函数，返回双方支持的签名算法。  |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getSignatureAlgorithms((err, data) => {
  if (err) {
    console.log("getSignatureAlgorithms callback error = " + err);
  } else {
    console.log("getSignatureAlgorithms callback = " + data);
  }
});
```

### getSignatureAlgorithms<sup>9+</sup>

getSignatureAlgorithms(): Promise\<Array\<string\>\>

在TLSSocket通信连接成功之后，获取通信双方协商后的签名算法，该接口只适配双向认证模式下，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                    | 说明                  |
| ---------------------- | -------------------- |
| Promise\<Array\<string\>\> | 以Promise形式返回获取到的双方支持的签名算法。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | ------------------------------ |
| 2303501 | SSL is null.                   |
| 2300002 | System internal error.         |

**示例：**

```js
tls.getSignatureAlgorithms().then(data => {
  console.log("getSignatureAlgorithms success" + data);
}).catch(err => {
  console.error(err);
});
```

### send<sup>9+</sup>

send(data: string, callback: AsyncCallback\<void\>): void

在TLSSocket通信连接成功之后，向服务端发送消息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名    | 类型                          | 必填 | 说明            |
| -------- | -----------------------------| ---- | ---------------|
|   data   | string                       | 是   | 发送的数据内容。   |
| callback | AsyncCallback\<void\>         | 是   | 回调函数,返回TLSSocket发送数据的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303501 | SSL is null.                                 |
| 2303503 | Error in tls writing.                         |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**示例：**

```js
tls.send("xxxx", (err) => {
  if (err) {
    console.log("send callback error = " + err);
  } else {
    console.log("send success");
  }
});
```

### send<sup>9+</sup>

send(data: string): Promise\<void\>

在TLSSocket通信连接成功之后，向服务端发送消息，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名    | 类型                          | 必填 | 说明            |
| -------- | -----------------------------| ---- | ---------------|
|   data   | string                       | 是   | 发送的数据内容。   |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 401     | Parameter error.                             |
| 2303501 | SSL is null.                                 |
| 2303503 | Error in tls writing.                         |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**返回值：**

| 类型           | 说明                  |
| -------------- | -------------------- |
| Promise\<void\> | 以Promise形式返回,返回TLSSocket发送数据的结果。失败返回错误码，错误信息。 |

**示例：**

```js
tls.send("xxxx").then(() => {
  console.log("send success");
}).catch(err => {
  console.error(err);
});
```

### close<sup>9+</sup>

close(callback: AsyncCallback\<void\>): void

在TLSSocket通信连接成功之后，断开连接，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名    | 类型                          | 必填 | 说明            |
| -------- | -----------------------------| ---- | ---------------|
| callback | AsyncCallback\<void\>         | 是   | 回调函数,成功返回TLSSocket关闭连接的结果。 失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 401 | Parameter error.                                 |
| 2303501 | SSL is null.                                 |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**示例：**

```js
tls.close((err) => {
  if (err) {
    console.log("close callback error = " + err);
  } else {
    console.log("close success");
  }
});
```

### close<sup>9+</sup>

close(): Promise\<void\>

在TLSSocket通信连接成功之后，断开连接，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型           | 说明                  |
| -------------- | -------------------- |
| Promise\<void\> | 以Promise形式返回,返回TLSSocket关闭连接的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 401 | Parameter error.                                 |
| 2303501 | SSL is null.                                 |
| 2303505 | Error occurred in the tls system call.       |
| 2303506 | Error clearing tls connection.               |
| 2300002 | System internal error.                       |

**示例：**

```js
tls.close().then(() => {
  console.log("close success");
}).catch((err) => {
  console.error(err);
});
```

## TLSConnectOptions<sup>9+</sup>

TLS连接的操作。

**系统能力**：SystemCapability.Communication.NetStack

| 名称          | 类型                                     | 必填 | 说明            |
| -------------- | ------------------------------------- | ---  |-------------- |
| address        | [NetAddress](#netaddress)             | 是  |  网关地址。       |
| secureOptions  | [TLSSecureOptions](#tlssecureoptions9) | 是 | TLS安全相关操作。|
| ALPNProtocols  | Array\<string\>                         | 否 | ALPN协议，支持["spdy/1", "http/1.1"]，默认为[]。      |

## TLSSecureOptions<sup>9+</sup>

TLS安全相关操作，其中ca证书为必选参数，其他参数为可选参数。当本地证书cert和私钥key不为空时，开启双向验证模式。cert和key其中一项为空时，开启单向验证模式。

**系统能力**：SystemCapability.Communication.NetStack

| 名称                 | 类型                                                    | 必填 | 说明                                |
| --------------------- | ------------------------------------------------------ | --- |----------------------------------- |
| ca                    | string \| Array\<string\>                               | 是 | 服务端的ca证书，用于认证校验服务端的数字证书。|
| cert                  | string                                                  | 否 | 本地客户端的数字证书。                 |
| key                   | string                                                  | 否 | 本地数字证书的私钥。                   |
| password                | string                                                  | 否 | 读取私钥的密码。                      |
| protocols             | [Protocol](#protocol9) \|Array\<[Protocol](#protocol9)\> | 否 | TLS的协议版本，默认为"TLSv1.2"。                  |
| useRemoteCipherPrefer | boolean                                                 | 否 | 优先使用对等方的密码套件。        |
| signatureAlgorithms   | string                                                 | 否 | 通信过程中的签名算法，默认为"" 。              |
| cipherSuite           | string                                                 | 否 | 通信过程中的加密套件，默认为"" 。              |

## Protocol<sup>9+</sup>

TLS通信的协议版本。

**系统能力**：SystemCapability.Communication.NetStack

| 名称      |    值    | 说明                |
| --------- | --------- |------------------ |
| TLSv12    | "TLSv1.2" | 使用TLSv1.2协议通信。 |
| TLSv13    | "TLSv1.3" | 使用TLSv1.3协议通信。 |

## X509CertRawData<sup>9+</sup>

存储证书的数据。

**系统能力**：SystemCapability.Communication.NetStack

