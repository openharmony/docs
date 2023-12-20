# @ohos.net.socket (Socket连接)

本模块提供利用Socket进行数据传输的能力，支持TCPSocket、UDPSocket、WebSocket和TLSSocket。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import socket from '@ohos.net.socket';
```

## socket.constructUDPSocketInstance

constructUDPSocketInstance(): UDPSocket

创建一个UDPSocket对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                               | 说明                    |
| :--------------------------------- | :---------------------- |
| [UDPSocket](#udpsocket) | 返回一个UDPSocket对象。 |

**示例：**

```ts
import socket from '@ohos.net.socket';
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
```

## UDPSocket

UDPSocket连接。在调用UDPSocket的方法前，需要先通过[socket.constructUDPSocketInstance](#socketconstructudpsocketinstance)创建UDPSocket对象。

### bind

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

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 1234
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
```

### bind

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

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr).then(() => {
  console.log('bind success');
}).catch((err: BusinessError) => {
  console.log('bind fail');
});
```

### send

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

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

let sendOptions: socket.UDPSendOptions = {
  data: 'Hello, server!',
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  }
}
udp.send(sendOptions, (err: BusinessError) => {
  if (err) {
    console.log('send fail');
    return;
  }
  console.log('send success');
});
```

### send

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

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

let sendOptions: socket.UDPSendOptions = {
  data: 'Hello, server!',
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  }
}
udp.send(sendOptions).then(() => {
  console.log('send success');
}).catch((err: BusinessError) => {
  console.log('send fail');
});
```

### close

close(callback: AsyncCallback\<void\>): void

关闭UDPSocket连接。使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。 |

**示例：**

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.close((err: BusinessError) => {
  if (err) {
    console.log('close fail');
    return;
  }
  console.log('close success');
})
```

### close

close(): Promise\<void\>

关闭UDPSocket连接。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                                       |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | 以Promise形式返回关闭UDPSocket连接的结果。 |

**示例：**

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.close().then(() => {
  console.log('close success');
}).catch((err: BusinessError) => {
  console.log('close fail');
});
```

### getState

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

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  udp.getState((err: BusinessError, data: socket.SocketStateBase) => {
    if (err) {
      console.log('getState fail');
      return;
    }
    console.log('getState success:' + JSON.stringify(data));
  })
})
```

### getState

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

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  udp.getState().then((data: socket.SocketStateBase) => {
    console.log('getState success:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.log('getState fail' + JSON.stringify(err));
  });
});
```

### setExtraOptions

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

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  let udpextraoptions: socket.UDPExtraOptions = {
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: false,
    socketTimeout: 6000,
    broadcast: true
  }
  udp.setExtraOptions(udpextraoptions, (err: BusinessError) => {
    if (err) {
      console.log('setExtraOptions fail');
      return;
    }
    console.log('setExtraOptions success');
  })
})
```

### setExtraOptions

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

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';

let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
udp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
  let udpextraoptions: socket.UDPExtraOptions = {
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: false,
    socketTimeout: 6000,
    broadcast: true
  }
  udp.setExtraOptions(udpextraoptions).then(() => {
    console.log('setExtraOptions success');
  }).catch((err: BusinessError) => {
    console.log('setExtraOptions fail');
  });
})
```

### on('message')

on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

订阅UDPSocket连接的接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback\<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}\> | 是   | 回调函数。                                |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let messageView = '';
udp.on('message', (value: SocketInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let messageView = '';
let callback = (value: SocketInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
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

### on('listening' | 'close')

on(type: 'listening' | 'close', callback: Callback\<void\>): void

订阅UDPSocket连接的数据包消息事件或关闭事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅的事件类型。<br />- 'listening'：数据包消息事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 是   | 回调函数。                                                   |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.on('listening', () => {
  console.log("on listening success");
});
udp.on('close', () => {
  console.log("on close success");
});
```

### off('listening' | 'close')

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
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

### on('error')

on(type: 'error', callback: ErrorCallback): void

订阅UDPSocket连接的error事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
udp.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let udp: socket.UDPSocket = socket.constructUDPSocketInstance();
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
udp.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('error', callback);
udp.off('error');
```

## NetAddress

目标地址信息。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | 是   | 本地绑定的ip地址。                                           |
| port    | number | 否   | 端口号 ，范围0~65535。如果不指定系统随机分配端口。           |
| family  | number | 否   | 网络协议类型，可选类型：<br />- 1：IPv4<br />- 2：IPv6<br />默认为1。 |

## UDPSendOptions

UDPSocket发送参数。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  | 类型                               | 必填 | 说明           |
| ------- | ---------------------------------- | ---- | -------------- |
| data    | string \| ArrayBuffer                          | 是   | 发送的数据。   |
| address | [NetAddress](#netaddress) | 是   | 目标地址信息。 |

## UDPExtraOptions

UDPSocket连接的其他属性。

**系统能力**：SystemCapability.Communication.NetStack

| 名称            | 类型    | 必填 | 说明                             |
| ----------------- | ------- | ---- | -------------------------------- |
| broadcast         | boolean | 否   | 是否可以发送广播。默认为false。  |
| receiveBufferSize | number  | 否   | 接收缓冲区大小（单位：Byte），默认为0。   |
| sendBufferSize    | number  | 否   | 发送缓冲区大小（单位：Byte），默认为0。   |
| reuseAddress      | boolean | 否   | 是否重用地址。默认为false。      |
| socketTimeout     | number  | 否   | 套接字超时时间，单位毫秒（ms），默认为0。 |

## SocketStateBase

Socket的状态信息。

**系统能力**：SystemCapability.Communication.NetStack

| 名称      | 类型    | 必填 | 说明       |
| ----------- | ------- | ---- | ---------- |
| isBound     | boolean | 是   | 是否绑定。 |
| isClose     | boolean | 是   | 是否关闭。 |
| isConnected | boolean | 是   | 是否连接。 |

## SocketRemoteInfo

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

## socket.constructMulticastSocketInstance<sup>11+</sup>

constructMulticastSocketInstance(): MulticastSocket

创建一个MulticastSocket对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                               | 说明                    |
  | :--------------------------------- | :---------------------- |
| [MulticastSocket](#multicastsocket) | 返回一个MulticastSocket对象。 |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
```
## MulticastSocket<sup>11+</sup>

MulticastSocket连接。在调用MulticastSocket的方法前，需要先通过[socket.constructMulticastSocketInstance](#socketconstructmulticastsocketinstance)创建MulticastSocket对象。

### addMembership<sup>11+</sup>

addMembership(multicastAddress: NetAddress, callback: AsyncCallback\<void\>): void;

加入多播组。使用callback方法作为异步方法。

> **说明：**
> 多播使用的IP地址属于特定的范围（例如224.0.0.0到239.255.255.255）。
> 加入多播组后，既可以是发送端，也可以是接收端，相互之间以广播的形式传递数据，不区分客户端或服务端。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名             | 类型                           | 必填 | 说明                                       |
| ----------------- | ----------------------------- | ---- | ----------------------------------------- |
| multicastAddress  | [NetAddress](#netaddress)     |  是  | 目标地址信息，参考[NetAddress](#netaddress)。 |
| callback          | AsyncCallback\<void\>         |  是  | 回调函数。                                  |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301022 | Invalid argument.       |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
multicast.addMembership(addr, (err) => {
  if (err) {
    console.log('add membership fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('add membership success');
})
```

### addMembership<sup>11+</sup>

addMembership(multicastAddress: NetAddress): Promise\<void\>;

加入多播组。使用Promise方法作为异步方法。。

> **说明：**
> 多播使用的IP地址属于特定的范围（例如224.0.0.0到239.255.255.255）。
> 加入多播组后，既可以是发送端，也可以是接收端，相互之间以广播的形式传递数据，不区分客户端或服务端。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名             | 类型                           | 必填 | 说明                                           |
| ----------------- | ----------------------------- | ---- | --------------------------------------------  |
| multicastAddress  | [NetAddress](#netaddress)     |  是  | 目标地址信息，参考[NetAddress](#netaddress)。 |

**返回值：**

| 类型            | 说明                                               |
| :-------------- | :-----------------------------------------------  |
| Promise\<void\> | 以Promise形式返回MulticastSocket加入多播组的行为结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301022 | Invalid argument.       |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructLocalSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
multicast.addMembership(addr).then(() => {
  console.log('addMembership success');
}).catch((err) => {
  console.log('addMembership fail');
});
```

### dropMembership<sup>11+</sup>

dropMembership(multicastAddress: NetAddress, callback: AsyncCallback\<void\>): void;

退出多播组。使用callback方法作为异步方法。

> **说明：**
> 多播使用的IP地址属于特定的范围（例如224.0.0.0到239.255.255.255）。
> 从已加入的多播组中退出，必须在加入多播组之后退出才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名             | 类型                           | 必填 | 说明                                         |
| ----------------- | ----------------------------- | ---- | ------------------------------------------- |
| multicastAddress  | [NetAddress](#netaddress)     |  是  | 目标地址信息，参考[NetAddress](#netaddress)。   |
| callback          | AsyncCallback\<void\>         |  是  | 回调函数。                                    |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
multicast.dropMembership(addr, (err) => {
  if (err) {
    console.log('drop membership fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('drop membership success');
})
```

### dropMembership<sup>11+</sup>

dropMembership(multicastAddress: NetAddress): Promise\<void\>;

退出多播组。使用Promise方法作为异步方法。。

> **说明：**
> 多播使用的IP地址属于特定的范围（例如224.0.0.0到239.255.255.255）。
> 从已加入的多播组中退出，必须在加入多播组之后退出才有效。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名             | 类型                                   | 必填 | 说明                                           |
| ----------------- | ------------------------------------- | ---- | --------------------------------------------  |
| multicastAddress  | [NetAddress](#netaddress) |  是  | 目标地址信息，参考[NetAddress](#netaddress)。     |

**返回值：**

| 类型            | 说明                                              |
| :-------------- | :----------------------------------------------- |
| Promise\<void\> | 以Promise形式返回MulticastSocket加入多播组的执行结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructLocalSocketInstance();
let addr: socket.NetAddress = {
  address: '239.255.0.1',
  port: 8080
}
multicast.dropMembership(addr).then(() => {
  console.log('drop membership success');
}).catch((err) => {
  console.log('drop membership fail');
});
```

### setMulticastTTL<sup>11+</sup>

setMulticastTTL(ttl: number, callback: AsyncCallback\<void\>): void;

设置多播通信时数据包在网络传输过程中路由器最大跳数。使用callback方法作为异步方法。

> **说明：**
> 用于限制数据包在网络中传输时能够经过的最大路由器跳数的字段，TTL (Time to live)。
> 范围为 0～255，默认值为 1 。
> 如果一个多播数据包的 TTL 值为 1，那么它只能被直接连接到发送者的主机接收。如果 TTL 被设置为一个较大的值，那么数据包就能够被传送到更远的网络范围内。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名         | 类型                   | 必填 | 说明                         |
| ------------- | --------------------- | ---- | ----------------------------- |
| ttl           | number                |  是  | ttl设置数值，类型为数字number。 |
| callback      | AsyncCallback\<void\> |  是  | 回调函数。                     |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301022 | Invalid argument.       |
| 2301088 | Not a socket.           |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let ttl = 8
multicast.setMulticastTTL(ttl, (err) => {
  if (err) {
    console.log('set ttl fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('set ttl success');
})
```

### setMulticastTTL<sup>11+</sup>

setMulticastTTL(ttl: number): Promise\<void\>;

设置多播通信时数据包在网络传输过程中路由器最大跳数。使用Promise方法作为异步方法。。

> **说明：**
> 用于限制数据包在网络中传输时能够经过的最大路由器跳数的字段，TTL (Time to live)。
> 范围为 0～255，默认值为 1 。
> 如果一个多播数据包的 TTL 值为 1，那么它只能被直接连接到发送者的主机接收。如果 TTL 被设置为一个较大的值，那么数据包就能够被传送到更远的网络范围内。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名         | 类型                   | 必填 | 说明                           |
| ------------- | ---------------------- | ---- | ------------------------------ |
| ttl           | number                 |  是  | ttl设置数值，类型为数字Number。 |

**返回值：**

| 类型            | 说明                                             |
| :-------------- | :---------------------------------------------- |
| Promise\<void\> | 以Promise形式返回MulticastSocket设置TTL数值的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructLocalSocketInstance();
multicast.setMulticastTTL(8).then(() => {
  console.log('set ttl success');
}).catch((err) => {
  console.log('set ttl failed');
});
```

### getMulticastTTL<sup>11+</sup>

getMulticastTTL(callback: AsyncCallback\<number\>): void;

获取数据包在网络传输过程中路由器最大跳数(TTL)的值。使用callback方法作为异步方法。

> **说明：**
> 用于限制数据包在网络中传输时能够经过的最大路由器跳数的字段，TTL (Time to live)。
> 范围为 0～255，默认值为 1 。
> 如果一个多播数据包的 TTL 值为 1，那么它只能被直接连接到发送者的主机接收。如果 TTL 被设置为一个较大的值，那么数据包就能够被传送到更远的网络范围内。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名         | 类型                     | 必填 | 说明                         |
| ------------- | ----------------------- | ---- | --------------------------- |
| callback      | AsyncCallback\<number\> |  是  | 回调函数。                    |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.getMulticastTTL((err, value) => {
  if (err) {
    console.log('set ttl fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('set ttl success, value: ' + JSON.stringify(value));
})
```

### getMulticastTTL<sup>11+</sup>

getMulticastTTL(): Promise\<number\>;

获取数据包在网络传输过程中路由器最大跳数(TTL)的值。使用Promise方法作为异步方法。

> **说明：**
> 用于限制数据包在网络中传输时能够经过的最大路由器跳数的字段，TTL (Time to live)。
> 范围为 0～255，默认值为 1 。
> 如果一个多播数据包的 TTL 值为 1，那么它只能被直接连接到发送者的主机接收。如果 TTL 被设置为一个较大的值，那么数据包就能够被传送到更远的网络范围内。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

无                                                            

**返回值：**

| 类型               | 说明                        |
| :--------------   | --------------------------- |
| Promise\<number\> | 以Promise形式返回当前TTL数值。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructLocalSocketInstance();
multicast.getMulticastTTL().then((value) => {
  console.log('ttl: ', JSON.stringify(value));
}).catch((err) => {
  console.log('set ttl failed');
});
```

### setLoopbackMode<sup>11+</sup>

setLoopbackMode(flag: boolean, callback: AsyncCallback\<void\>): void;

设置多播通信中的环回模式标志位。使用callback方法作为异步方法。

> **说明：**
> 用于设置环回模式，开启或关闭两种状态，默认为开启状态。
> 如果一个多播通信中环回模式设置值为 true，那么它允许主机在本地循环接收自己发送的多播数据包。如果为 false，则主机不会接收到自己发送的多播数据包。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名         | 类型                  | 必填 | 说明                         |
| ------------- | --------------------- | ---- | ---------------------------- |
| flag          | boolean               |  是  | ttl设置数值，类型为boolen 。  |
| callback      | AsyncCallback\<void\> |  是  | 回调函数。                    |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.setLoopbackMode(false, (err) => {
  if (err) {
    console.log('set loopback mode fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('set loopback mode success');
})
```

### setLoopbackMode<sup>11+</sup>

setLoopbackMode(flag: boolean): Promise\<void\>;

设置多播通信中的环回模式标志位。使用callback方法作为异步方法。

> **说明：**
> 用于设置环回模式，开启或关闭两种状态，默认为开启状态。
> 如果一个多播通信中环回模式设置值为 true，那么它允许主机在本地循环接收自己发送的多播数据包。如果为 false，则主机不会接收到自己发送的多播数据包。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名         | 类型                   | 必填 | 说明                             |
| ------------- | ---------------------- | ---- | -------------------------------- |
| flag          | boolean                |  是  | 环回模式标志位，类型为数字boolean。|

**返回值：**

| 类型            | 说明                                             |
| :-------------- | :---------------------------------------------- |
| Promise\<void\> | 以Promise形式返回MulticastSocket设置环回模式的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructLocalSocketInstance();
multicast.setLoopbackMode(false).then(() => {
  console.log('set loopback mode success');
}).catch((err) => {
  console.log('set loopback mode failed');
});
```

### getLoopbackMode<sup>11+</sup>

getLoopbackMode(callback: AsyncCallback\<boolean\>): void;

获取多播通信中的环回模式状态。使用Promise方法作为异步方法。

> **说明：**
> 用于获取当前环回模式开启或关闭的状态。
> 如果获取的属性值为 true，表示环回模式是开启的状态，允许主机在本地循环接收自己发送的多播数据包。如果为 false，则表示环回模式是关闭的状态，主机不会接收到自己发送的多播数据包。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名         | 类型                     | 必填 | 说明                         |
| ------------- | ----------------------- | ---- | --------------------------- |
| callback      | AsyncCallback\<number\> |  是  | 回调函数。                    |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
multicast.getLoopbackMode((err, value) => {
  if (err) {
    console.log('get loopback mode fail, err: ' + JSON.stringify(err));
    return;
  }
  console.log('get loopback mode success, value: ' + JSON.stringify(value));
})
```

### getLoopbackMode<sup>11+</sup>

getLoopbackMode(): Promise\<boolean\>;

获取多播通信中的环回模式状态。使用Promise方法作为异步方法。

> **说明：**
> 用于获取当前环回模式开启或关闭的状态。
> 如果获取的属性值为 true，表示环回模式是开启的状态，允许主机在本地循环接收自己发送的多播数据包。如果为 false，则表示环回模式是关闭的状态，主机不会接收到自己发送的多播数据包。
> 在调用addMembership之后，调用此接口才有效。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

无                                                            

**返回值：**

| 类型                | 说明                        |
| :----------------  | --------------------------- |
| Promise\<boolean\> | 以Promise形式返回当前TTL数值。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |
| 2301088 | Not a socket.           |
| 2301098 | Address in use.         |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructLocalSocketInstance();
multicast.getLoopbackMode().then((value) => {
  console.log('loopback mode: ', JSON.stringify(value));
}).catch((err) => {
  console.log('get loopback mode failed');
});
```

### send<sup>11+</sup>

send(options: UDPSendOptions, callback: AsyncCallback\<void\>): void

发送数据。使用callback方式作为异步方法。

发送数据前，需要先调用[MulticastSocket.addMembership()](#addmembership11)加入多播组。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPSendOptions](#udpsendoptions) | 是   | UDPSocket发送参数，参考[UDPSendOptions](#udpsendoptions)。 |
| callback | AsyncCallback\<void\>             | 是   | 回调函数。                                                   |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let sendOptions: socket.UDPSendOptions = {
  data: 'Hello, server!',
  address: {
    address: '239.255.0.1',
    port: 8080
  }
}
multicast.send(sendOptions, (err) => {
  if (err) {
    console.log('send fail');
    return;
  }
  console.log('send success');
});
```

### send<sup>11+</sup>

send(options: UDPSendOptions): Promise\<void\>

发送数据。使用Promise方式作为异步方法。

发送数据前，需要先调用[MulticastSocket.addMembership()](#addmembership11)加入多播组。

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

| 类型            | 说明                              |
| :-------------- | :------------------------------- |
| Promise\<void\> | 以Promise形式返回发送数据的执行结果。 |

**示例：**

```ts
import socket from '@ohos.net.socket';
import { BusinessError } from '@ohos.base';
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let sendOptions: socket.UDPSendOptions = {
  data: 'Hello, server!',
  address: {
    address: '239.255.0.1',
    port: 8080
  }
}
multicast.send(sendOptions).then(() => {
  console.log('send success');
}).catch((err: BusinessError) => {
  console.log('send fail');
});
```

### on('message')<sup>11+</sup>

on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

订阅MulticastSocket接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                                                    | 必填 | 说明                                 |
| -------- | ------------------------------------------------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                                                                | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback\<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}\> | 是   | 回调函数。                            |

**示例：**

```ts
import socket from "@ohos.net.socket";
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let messageView = '';
multicast.on('message', (value: SocketInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')<sup>11+</sup>

off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

取消订阅消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                                                              | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 否   | 回调函数。                            |

**示例：**

```ts
import socket from "@ohos.net.socket";
class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let multicast: socket.MulticastSocket = socket.constructMulticastSocketInstance();
let messageView = '';
let callback = (value: SocketInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
multicast.on('message', callback);
udp.off('message');
```

## socket.constructTCPSocketInstance<sup>7+</sup>

constructTCPSocketInstance(): TCPSocket

创建一个TCPSocket对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                               | 说明                    |
  | :--------------------------------- | :---------------------- |
| [TCPSocket](#tcpsocket) | 返回一个TCPSocket对象。 |

**示例：**

```ts
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
```

## TCPSocket

TCPSocket连接。在调用TCPSocket的方法前，需要先通过[socket.constructTCPSocketInstance](#socketconstructtcpsocketinstance)创建TCPSocket对象。

### bind

bind(address: NetAddress, callback: AsyncCallback\<void\>): void

绑定IP地址和端口，端口可以指定为0由系统随机分配或指定为其它非0端口。使用callback方法作为异步方法。

> **说明：**
> bind方法如果因为端口冲突而执行失败，则会由系统随机分配端口号。
> TCP客户端可先调用该接口(tcp.bind)显式绑定IP地址和端口号，再调用tcp.connect完成与服务端的连接；也可直接调用tcp.connect由系统自动绑定IP地址和端口号，完成与服务端的连接。
> bind的IP为'localhost'或'127.0.0.1'时，只允许本地回环接口的连接，即服务端和客户端运行在同一台机器上。

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tcp.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
})
```

### bind

bind(address: NetAddress): Promise\<void\>

绑定IP地址和端口，端口可以指定为0由系统随机分配或指定为其它非0端口。使用Promise方法作为异步方法。

> **说明：**
> bind方法如果因为端口冲突而执行失败，则会由系统随机分配端口号。
> TCP客户端可先调用该接口(tcp.bind)显式绑定IP地址和端口号，再调用tcp.connect完成与服务端的连接；也可直接调用tcp.connect由系统自动绑定IP地址和端口号，完成与服务端的连接。
> bind的IP为'localhost'或'127.0.0.1'时，只允许本地回环接口的连接，即服务端和客户端运行在同一台机器上。

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tcp.bind(bindAddr).then(() => {
  console.log('bind success');
}).catch((err: BusinessError) => {
  console.log('bind fail');
});
```

### connect

connect(options: TCPConnectOptions, callback: AsyncCallback\<void\>): void

连接到指定的IP地址和端口。使用callback方法作为异步方法。

> **说明：**
> 在没有执行tcp.bind的情况下，也可以直接调用该接口完成与TCP服务端的连接

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions, (err: BusinessError) => {
  if (err) {
    console.log('connect fail');
    return;
  }
  console.log('connect success');
})
```

### connect

connect(options: TCPConnectOptions): Promise\<void\>

连接到指定的IP地址和端口。使用promise方法作为异步方法。

> **说明：**
> 在没有执行tcp.bind的情况下，也可以直接调用该接口完成与TCP服务端的连接。

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success')
}).catch((err: BusinessError) => {
  console.log('connect fail');
});
```

### send

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpSendOptions: socket.TCPSendOptions = {
    data: 'Hello, server!'
  }
  tcp.send(tcpSendOptions, (err: BusinessError) => {
    if (err) {
      console.log('send fail');
      return;
    }
    console.log('send success');
  })
})
```

### send

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpSendOptions: socket.TCPSendOptions = {
    data: 'Hello, server!'
  }
  tcp.send(tcpSendOptions).then(() => {
    console.log('send success');
  }).catch((err: BusinessError) => {
    console.log('send fail');
  });
})
```

### close

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

tcp.close((err: BusinessError) => {
  if (err) {
    console.log('close fail');
    return;
  }
  console.log('close success');
})
```

### close

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

```ts
import socket from "@ohos.net.socket";
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

tcp.close().then(() => {
  console.log('close success');
}).catch((err: BusinessError) => {
  console.log('close fail');
});
```

### getRemoteAddress

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  tcp.getRemoteAddress((err: BusinessError, data: socket.NetAddress) => {
    if (err) {
      console.log('getRemoteAddressfail');
      return;
    }
    console.log('getRemoteAddresssuccess:' + JSON.stringify(data));
  })
});
```

### getRemoteAddress

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success');
  tcp.getRemoteAddress().then(() => {
    console.log('getRemoteAddress success');
  }).catch((err: BusinessError) => {
    console.log('getRemoteAddressfail');
  });
}).catch((err: BusinessError) => {
  console.log('connect fail');
});
```

### getState

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  tcp.getState((err: BusinessError, data: socket.SocketStateBase) => {
    if (err) {
      console.log('getState fail');
      return;
    }
    console.log('getState success:' + JSON.stringify(data));
  });
});
```

### getState

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();

let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions).then(() => {
  console.log('connect success');
  tcp.getState().then(() => {
    console.log('getState success');
  }).catch((err: BusinessError) => {
    console.log('getState fail');
  });
}).catch((err: BusinessError) => {
  console.log('connect fail');
});
```

### getSocketFd<sup>10+</sup>

getSocketFd(callback: AsyncCallback\<number\>): void

获取TCPSocket的文件描述符。使用callback方式作为异步方法。

> **说明：**
> bind或connect方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<number\> | 是   | 回调函数，当成功时，返回socket的文件描述符，失败时，返回undefined。 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '0.0.0.0'
}
tcp.bind(bindAddr)
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions)
tcp.getSocketFd((err: BusinessError, data: number) => {
  console.info("getSocketFd failed: " + err);
  console.info("tunenlfd: " + data);
})
```
### getSocketFd<sup>10+</sup>

getSocketFd(): Promise\<number\>

获取TCPSocket的文件描述符。使用Promise方式作为异步方法。

> **说明：**
> bind或connect方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                             | 说明                                       |
| :----------------------------------------------- | :----------------------------------------- |
| Promise\<number\> | 以Promise形式返回socket的文件描述符。 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '0.0.0.0'
}
tcp.bind(bindAddr)
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions)
tcp.getSocketFd().then((data: number) => {
  console.info("tunenlfd: " + data);
})
```

### setExtraOptions

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpExtraOptions: socket.TCPExtraOptions = {
    keepAlive: true,
    OOBInline: true,
    TCPNoDelay: true,
    socketLinger: { on: true, linger: 10 },
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: true,
    socketTimeout: 3000
  }
  tcp.setExtraOptions(tcpExtraOptions, (err: BusinessError) => {
    if (err) {
      console.log('setExtraOptions fail');
      return;
    }
    console.log('setExtraOptions success');
  });
});
```

### setExtraOptions

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let tcpconnectoptions: socket.TCPConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  timeout: 6000
}
tcp.connect(tcpconnectoptions, () => {
  console.log('connect success');
  let tcpExtraOptions: socket.TCPExtraOptions = {
    keepAlive: true,
    OOBInline: true,
    TCPNoDelay: true,
    socketLinger: { on: true, linger: 10 },
    receiveBufferSize: 1000,
    sendBufferSize: 1000,
    reuseAddress: true,
    socketTimeout: 3000
  }
  tcp.setExtraOptions(tcpExtraOptions).then(() => {
    console.log('setExtraOptions success');
  }).catch((err: BusinessError) => {
    console.log('setExtraOptions fail');
  });
});
```

### on('message')

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

订阅TCPSocket连接的接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 是   | 回调函数。                                |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let messageView = '';
tcp.on('message', (value: SocketInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
});
```

### off('message')

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let messageView = '';
let callback = (value: SocketInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
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

### on('connect' | 'close')

on(type: 'connect' | 'close', callback: Callback\<void\>): void

订阅TCPSocket的连接事件或关闭事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅的事件类型。<br />- 'connect'：连接事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 是   | 回调函数。                                                   |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
tcp.on('connect', () => {
  console.log("on connect success")
});
tcp.on('close', () => {
  console.log("on close success")
});
```

### off('connect' | 'close')

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
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

### on('error')

on(type: 'error', callback: ErrorCallback): void

订阅TCPSocket连接的error事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
tcp.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcp: socket.TCPSocket = socket.constructTCPSocketInstance();
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tcp.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('error', callback);
tcp.off('error');
```

## TCPConnectOptions

TCPSocket连接的参数。

**系统能力**：SystemCapability.Communication.NetStack

| 名称  | 类型                               | 必填 | 说明                       |
| ------- | ---------------------------------- | ---- | -------------------------- |
| address | [NetAddress](#netaddress) | 是   | 绑定的地址以及端口。       |
| timeout | number                             | 否   | 超时时间，单位毫秒（ms）。 |

## TCPSendOptions

TCPSocket发送请求的参数。

**系统能力**：SystemCapability.Communication.NetStack

| 名称   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| data     | string\| ArrayBuffer  | 是   | 发送的数据。                                                 |
| encoding | string | 否   | 字符编码(UTF-8，UTF-16BE，UTF-16LE，UTF-16，US-AECII，ISO-8859-1)，默认为UTF-8。 |

## TCPExtraOptions

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

## socket.constructTCPSocketServerInstance<sup>10+</sup>

constructTCPSocketServerInstance(): TCPSocketServer

创建一个TCPSocketServer对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                | 说明                          |
| :---------------------------------- | :---------------------------- |
| [TCPSocketServer](#tcpsocketserver10) | 返回一个TCPSocketServer对象。 |

**示例：**

```ts
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
```

## TCPSocketServer<sup>10+</sup>

TCPSocketServer连接。在调用TCPSocketServer的方法前，需要先通过[socket.constructTCPSocketServerInstance](#socketconstructtcpsocketserverinstance10)创建TCPSocketServer对象。

### listen<sup>10+</sup>

listen(address: NetAddress, callback: AsyncCallback\<void\>): void

绑定IP地址和端口，端口可以指定或由系统随机分配。监听并接受与此套接字建立的TCPSocket连接。该接口使用多线程并发处理客户端的数据。使用callback方法作为异步方法。

> **说明：**
> 服务端使用该方法完成bind，listen，accept操作，bind方法失败会由系统随机分配端口号。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                          |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| address  | [NetAddress](#netaddress) | 是   | 目标地址信息。 |
| callback | AsyncCallback\<void\>     | 是   | 回调函数。                                    |

**错误码：**

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable try again. |
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
```

### listen<sup>10+</sup>

listen(address: NetAddress): Promise\<void\>

绑定IP地址和端口，端口可以指定或由系统随机分配。监听并接受与此套接字建立的TCPSocket连接。该接口使用多线程并发处理客户端的数据。使用Promise方法作为异步方法。

> **说明：**
> 服务端使用该方法完成bind，listen，accept操作，bind方法失败会由系统随机分配端口号。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                      | 必填 | 说明                                          |
| ------- | ------------------------- | ---- | --------------------------------------------- |
| address | [NetAddress](#netaddress) | 是   | 目标地址信息。 |

**返回值：**

| 类型            | 说明                                                         |
| :-------------- | :----------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回, 成功返回空，失败返回错误码错误信息。|

**错误码：**

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable try again. |
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr).then(() => {
  console.log('listen success');
}).catch((err: BusinessError) => {
  console.log('listen fail');
});
```

### getState<sup>10+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

获取TCPSocketServer状态。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                               | 必填 | 说明       |
| -------- | -------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback<[SocketStateBase](#socketstatebase)> | 是   | 回调函数。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
tcpServer.getState((err: BusinessError, data: socket.SocketStateBase) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
})
```

### getState<sup>10+</sup>

getState(): Promise\<SocketStateBase\>

获取TCPSocketServer状态。使用Promise方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                         | 说明                                       |
| :------------------------------------------- | :----------------------------------------- |
| Promise<[SocketStateBase](#socketstatebase)> | 以Promise形式返回获取TCPSocket状态的结果。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})
tcpServer.getState().then((data: socket.SocketStateBase) => {
  console.log('getState success' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

设置TCPSocketServer连接的其他属性。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | 是   | TCPSocketServer连接的其他属性。 |
| callback | AsyncCallback\<void\>               | 是   | 回调函数。                                                   |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 },
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tcpServer.setExtraOptions(tcpExtraOptions, (err: BusinessError) => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

设置TCPSocketServer连接的其他属性，使用Promise方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                | 必填 | 说明                                                         |
| ------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPExtraOptions](#tcpextraoptions) | 是   | TCPSocketServer连接的其他属性。 |

**返回值：**

| 类型            | 说明                                                       |
| :-------------- | :--------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let listenAddr: socket.NetAddress = {
  address:  '192.168.xx.xxx',
  port: 8080,
  family: 1
}
tcpServer.listen(listenAddr, (err: BusinessError) => {
  if (err) {
    console.log("listen fail");
    return;
  }
  console.log("listen success");
})

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 },
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tcpServer.setExtraOptions(tcpExtraOptions).then(() => {
  console.log('setExtraOptions success');
}).catch((err: BusinessError) => {
  console.log('setExtraOptions fail');
});
```

### on('connect')<sup>10+</sup>

on(type: 'connect', callback: Callback\<TCPSocketConnection\>): void

订阅TCPSocketServer的连接事件。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                  |
| -------- | ------------------------------- | ---- | ------------------------------------- |
| type     | string                          | 是   | 订阅的事件类型。'connect'：连接事件。 |
| callback | Callback<[TCPSocketConnection](#tcpsocketconnection10)> | 是   | 回调函数。                            |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (data: socket.TCPSocketConnection) => {
  console.log(JSON.stringify(data))
});
```

### off('connect')<sup>10+</sup>

off(type: 'connect', callback?: Callback\<TCPSocketConnection\>): void

取消订阅TCPSocketServer的连接事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                  |
| -------- | ------------------------------- | ---- | ------------------------------------- |
| type     | string                          | 是   | 订阅的事件类型。'connect'：连接事件。 |
| callback | Callback<[TCPSocketConnection](#tcpsocketconnection10)> | 否   | 回调函数。                            |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = (data: socket.TCPSocketConnection) => {
  console.log('on connect message: ' + JSON.stringify(data));
}
tcpServer.on('connect', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcpServer.off('connect', callback);
tcpServer.off('connect');
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅TCPSocketServer连接的error事件。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅TCPSocketServer连接的error事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tcpServer.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcpServer.off('error', callback);
tcpServer.off('error');
```

## TCPSocketConnection<sup>10+</sup>

TCPSocketConnection连接，即TCPSocket客户端与服务端的连接。在调用TCPSocketConnection的方法前，需要先获取TCPSocketConnection对象。

> **说明：**
> 客户端与服务端成功建立连接后，才能通过返回的TCPSocketConnection对象调用相应的接口。

**系统能力**：SystemCapability.Communication.NetStack

### 属性

| 名称     | 类型   | 必填 | 说明                                      |
| -------- | ------ | ---- | ----------------------------------------- |
| clientId | number | 是   | 客户端与TCPSocketServer建立连接的id。 |

### send<sup>10+</sup>

send(options: TCPSendOptions, callback: AsyncCallback\<void\>): void

通过TCPSocketConnection连接发送数据。使用callback方式作为异步方法。

> **说明：**
> 与客户端建立连接后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPSendOptions](#tcpsendoptions) | 是   | TCPSocketConnection发送请求的参数。 |
| callback | AsyncCallback\<void\>             | 是   | 回调函数。                                                   |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  let tcpSendOption: socket.TCPSendOptions = {
    data: 'Hello, client!'
  }
  client.send(tcpSendOption, () => {
    console.log('send success');
  });
});
```

### send<sup>10+</sup>

send(options: TCPSendOptions): Promise\<void\>

通过TCPSocketConnection连接发送数据。使用Promise方式作为异步方法。

> **说明：**
> 与客户端建立连接后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                         |
| ------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| options | [TCPSendOptions](#tcpsendoptions) | 是   | TCPSocketConnection发送请求的参数。 |

**返回值：**

| 类型            | 说明                                                         |
| :-------------- | :----------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  let tcpSendOption: socket.TCPSendOptions = {
    data: 'Hello, client!'
  }
  client.send(tcpSendOption).then(() => {
    console.log('send success');
  }).catch((err: BusinessError) => {
    console.log('send fail');
  });
});
```

### close<sup>10+</sup>

close(callback: AsyncCallback\<void\>): void

关闭一个与TCPSocket建立的连接。使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.close((err: BusinessError) => {
    if (err) {
      console.log('close fail');
      return;
    }
    console.log('close success');
  });
});
```

### close<sup>10+</sup>

close(): Promise\<void\>

关闭一个与TCPSocket建立的连接。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                                         |
| :-------------- | :------------------------------------------- |
| Promise\<void\> | 以Promise形式返回，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 201      | Permission denied.     |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.close().then(() => {
  	console.log('close success');
  }).catch((err: BusinessError) => {
  	console.log('close fail');
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

获取对端Socket地址。使用callback方式作为异步方法。

> **说明：**
> 与客户端建立连接后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明       |
| -------- | ---------------------------------------- | ---- | ---------- |
| callback | AsyncCallback<[NetAddress](#netaddress)> | 是   | 回调函数。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.getRemoteAddress((err: BusinessError, data: socket.NetAddress) => {
    if (err) {
      console.log('getRemoteAddress fail');
      return;
    }
    console.log('getRemoteAddress success:' + JSON.stringify(data));
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(): Promise\<NetAddress\>

获取对端Socket地址。使用Promise方式作为异步方法。

> **说明：**
> 与客户端建立连接后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                               | 说明                                        |
| :--------------------------------- | :------------------------------------------ |
| Promise<[NetAddress](#netaddress)> | 以Promise形式返回获取对端socket地址的结果。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 201      | Permission denied.              |
| 2300002  | System internal error.          |
| 2303188  | Socket operation on non-socket. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.getRemoteAddress().then(() => {
    console.log('getRemoteAddress success');
  }).catch((err: BusinessError) => {
    console.log('getRemoteAddress fail');
  });
});
```

### on('message')<sup>10+</sup>

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

订阅TCPSocketConnection连接的接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 是   | 回调函数。message：接收到的消息；remoteInfo：socket连接信息。                                |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();

class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('message', (value: SocketInfo) => {
    let messageView = '';
    for (let i: number = 0; i < value.message.byteLength; i++) {
      let messages: number = value.message[i]
      let message = String.fromCharCode(messages);
      messageView += message;
    }
    console.log('on message message: ' + JSON.stringify(messageView));
    console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
  });
});
```

### off('message')<sup>10+</sup>

off(type: 'message', callback?: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

取消订阅TCPSocketConnection连接的接收消息事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 否   | 回调函数。message：接收到的消息；remoteInfo：socket连接信息。                                |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let callback = (value: SocketInfo) => {
  let messageView = '';
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('message', callback);
  // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
  client.off('message', callback);
  client.off('message');
});
```

### on('close')<sup>10+</sup>

on(type: 'close', callback: Callback\<void\>): void

订阅TCPSocketConnection的关闭事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | 是   | 订阅的事件类型。'close'：关闭事件。 |
| callback | Callback\<void\> | 是   | 回调函数。                          |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('close', () => {
    console.log("on close success")
  });
});
```

### off('close')<sup>10+</sup>

off(type: 'close', callback?: Callback\<void\>): void

取消订阅TCPSocketConnection的关闭事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | 是   | 订阅的事件类型。'close'：关闭事件。 |
| callback | Callback\<void\> | 否   | 回调函数。                          |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
let callback = () => {
  console.log("on close success");
}
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('close', callback);
  // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
  client.off('close', callback);
  client.off('close');
});
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅TCPSocketConnection连接的error事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('error', (err: BusinessError) => {
    console.log("on error, err:" + JSON.stringify(err))
  });
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅TCPSocketConnection连接的error事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
let tcpServer: socket.TCPSocketServer = socket.constructTCPSocketServerInstance();
tcpServer.on('connect', (client: socket.TCPSocketConnection) => {
  client.on('error', callback);
  // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
  client.off('error', callback);
  client.off('error');
});
```

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

```ts
import socket from "@ohos.net.socket";
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr).then(() => {
  console.log('bind success');
}).catch((err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
tls.getState((err: BusinessError, data: socket.SocketStateBase) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});
tls.getState().then(() => {
  console.log('getState success');
}).catch((err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 },
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tls.setExtraOptions(tcpExtraOptions, (err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let bindAddr: socket.NetAddress = {
  address: '192.168.xx.xxx',
  port: 8080
}
tls.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 },
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tls.setExtraOptions(tcpExtraOptions).then(() => {
  console.log('setExtraOptions success');
}).catch((err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let messageView = '';
tls.on('message', (value: SocketInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
class SocketInfo {
  message: ArrayBuffer = new ArrayBuffer(1);
  remoteInfo: socket.SocketRemoteInfo = {} as socket.SocketRemoteInfo;
}
let messageView = '';
let callback = (value: SocketInfo) => {
  for (let i: number = 0; i < value.message.byteLength; i++) {
    let messages: number = value.message[i]
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.on('error', (err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
let callback = (err: BusinessError) => {
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
| callback | AsyncCallback\<void\>                  | 是   | 回调函数，成功无返回，失败返回错误码，错误信息。|

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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance();  // Two way authentication
let bindAddr: socket.NetAddress = {
  address: '0.0.0.0',
}
tlsTwoWay.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}

tlsTwoWay.connect(tlsConnectOptions, (err: BusinessError) => {
  console.error("connect callback error" + err);
});

let tlsOneWay: socket.TLSSocket = socket.constructTLSSocketInstance(); // One way authentication
tlsOneWay.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

let tlsOneWayConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    ca: ["xxxx", "xxxx"],
    cipherSuite: "AES256-SHA256"
  }
}
tlsOneWay.connect(tlsOneWayConnectOptions, (err: BusinessError) => {
  console.error("connect callback error" + err);
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsTwoWay: socket.TLSSocket = socket.constructTLSSocketInstance();  // Two way authentication
let bindAddr: socket.NetAddress = {
  address: '0.0.0.0',
}
tlsTwoWay.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}

tlsTwoWay.connect(tlsConnectOptions).then(() => {
  console.log("connect successfully");
}).catch((err: BusinessError) => {
  console.log("connect failed " + JSON.stringify(err));
});

let tlsOneWay: socket.TLSSocket = socket.constructTLSSocketInstance(); // One way authentication
tlsOneWay.bind(bindAddr, (err: BusinessError) => {
  if (err) {
    console.log('bind fail');
    return;
  }
  console.log('bind success');
});

let tlsOneWayConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    ca: ["xxxx", "xxxx"],
    cipherSuite: "AES256-SHA256"
  }
}
tlsOneWay.connect(tlsOneWayConnectOptions).then(() => {
  console.log("connect successfully");
}).catch((err: BusinessError) => {
  console.log("connect failed " + JSON.stringify(err));
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getRemoteAddress((err: BusinessError, data: socket.NetAddress) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getRemoteAddress().then(() => {
  console.log('getRemoteAddress success');
}).catch((err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getCertificate((err: BusinessError, data: socket.X509CertRawData) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
import util from "@ohos.util";

let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getCertificate().then((data: socket.X509CertRawData) => {
  const decoder = util.TextDecoder.create();
  const str = decoder.decodeWithStream(data.data);
  console.log("getCertificate: " + str);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getRemoteCertificate((err: BusinessError, data: socket.X509CertRawData) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getRemoteCertificate().then((data: socket.X509CertRawData) => {
  console.log(data);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getProtocol((err: BusinessError, data: string) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getProtocol().then((data: string) => {
  console.log(data);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getCipherSuite((err: BusinessError, data: Array<string>) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getCipherSuite().then((data: Array<string>) => {
  console.log('getCipherSuite success:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error("failed" + err);
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getSignatureAlgorithms((err: BusinessError, data: Array<string>) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.getSignatureAlgorithms().then((data: Array<string>) => {
  console.log("getSignatureAlgorithms success" + data);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.send("xxxx", (err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.send("xxxx").then(() => {
  console.log("send success");
}).catch((err: BusinessError) => {
  console.error("failed" + err);
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.close((err: BusinessError) => {
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

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tls: socket.TLSSocket = socket.constructTLSSocketInstance();
tls.close().then(() => {
  console.log("close success");
}).catch((err: BusinessError) => {
  console.error("failed" + err);
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

## socket.constructTLSSocketServerInstance<sup>10+</sup>

constructTLSSocketServerInstance(): TLSSocketServer

创建并返回一个TLSSocketServer对象。

**系统能力**：SystemCapability.Communication.NetStack

**返回值:**

| 类型                                  | 说明                          |
| :------------------------------------ | :---------------------------- |
| [TLSSocketServer](#tlssocketserver10) | 返回一个TLSSocketServer对象。 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
```

## TLSSocketServer<sup>10+</sup>

TLSSocketServer连接。在调用TLSSocketServer的方法前，需要先通过[socket.constructTLSSocketServerInstance](#socketconstructtlssocketserverinstance10)创建TLSSocketServer对象。

### listen<sup>10+</sup>

listen(options: TLSConnectOptions, callback: AsyncCallback\<void\>): void

绑定IP地址和端口，在TLSSocketServer上bind成功之后，监听客户端的连接，创建和初始化TLS会话，实现建立连接过程，加载证书秘钥并验证，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                             |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------ |
| options  | [TLSConnectOptions](#tlsconnectoptions9) | 是   | TLSSocketServer连接所需要的参数。                |
| callback | AsyncCallback\<void\>                     | 是   | 回调函数，成功返回空，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable try again. |
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |
| 2303501  | SSL is null.                                |
| 2303502  | Error in tls reading.                       |
| 2303503  | Error in tls writing                        |
| 2303505  | Error occurred in the tls system call.      |
| 2303506  | Error clearing tls connection.              |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();

let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions, (err: BusinessError) => {
  console.log("listen callback error" + err);
});
```

### listen<sup>10+</sup>

listen(options: TLSConnectOptions): Promise\<void\>

绑定IP地址和端口，在TLSSocketServer上bind成功之后，监听客户端的连接，并创建和初始化TLS会话，实现建立连接过程，加载证书秘钥并验证，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                     | 必填 | 说明               |
| ------- | ---------------------------------------- | ---- | ------------------ |
| options | [TLSConnectOptions](#tlsconnectoptions9) | 是   | 连接所需要的参数。 |

**返回值：**

| 类型            | 说明                                                      |
| --------------- | --------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回，成功返回空，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 401      | Parameter error.                            |
| 201      | Permission denied.                          |
| 2300002  | System internal error.                      |
| 2303109  | Bad file number.                            |
| 2303111  | Resource temporarily unavailable try again. |
| 2303198  | Address already in use.                     |
| 2303199  | Cannot assign requested address.            |
| 2303501  | SSL is null.                                |
| 2303502  | Error in tls reading.                       |
| 2303503  | Error in tls writing                        |
| 2303505  | Error occurred in the tls system call.      |
| 2303506  | Error clearing tls connection.              |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();

let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
```

### getState<sup>10+</sup>

getState(callback: AsyncCallback\<SocketStateBase\>): void

在TLSSocketServer的listen成功之后，获取TLSSocketServer状态。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[SocketStateBase](#socketstatebase)> | 是   | 回调函数。成功返回TLSSocketServer状态，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getState((err: BusinessError, data: socket.SocketStateBase) => {
  if (err) {
    console.log('getState fail');
    return;
  }
  console.log('getState success:' + JSON.stringify(data));
});
```

### getState<sup>10+</sup>

getState(): Promise\<SocketStateBase\>

在TLSSocketServer的listen成功之后，获取TLSSocketServer状态。使用Promise方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                           | 说明                                                         |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise\<[SocketStateBase](#socketstatebase)> | 以Promise形式返回获取TLSSocketServer状态的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getState().then(() => {
  console.log('getState success');
}).catch((err: BusinessError) => {
  console.log('getState fail');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void\>): void

在TLSSocketServer的listen成功之后，设置TLSSocketServer连接的其他属性。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                             |
| -------- | ------------------------------------ | ---- | ------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | 是   | TLSSocketServer连接的其他属性。                  |
| callback | AsyncCallback\<void\>                | 是   | 回调函数。成功返回空，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 },
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tlsServer.setExtraOptions(tcpExtraOptions, (err: BusinessError) => {
  if (err) {
    console.log('setExtraOptions fail');
    return;
  }
  console.log('setExtraOptions success');
});
```

### setExtraOptions<sup>10+</sup>

setExtraOptions(options: TCPExtraOptions): Promise\<void\>

在TLSSocketServer的listen成功之后，设置TLSSocketServer连接的其他属性，使用Promise方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                 | 必填 | 说明                            |
| ------- | ------------------------------------ | ---- | ------------------------------- |
| options | [TCPExtraOptions](#tcpextraoptions) | 是   | TLSSocketServer连接的其他属性。 |

**返回值：**

| 类型            | 说明                                                      |
| :-------------- | :-------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回，成功返回空，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});

let tcpExtraOptions: socket.TCPExtraOptions = {
  keepAlive: true,
  OOBInline: true,
  TCPNoDelay: true,
  socketLinger: { on: true, linger: 10 },
  receiveBufferSize: 1000,
  sendBufferSize: 1000,
  reuseAddress: true,
  socketTimeout: 3000
}
tlsServer.setExtraOptions(tcpExtraOptions).then(() => {
  console.log('setExtraOptions success');
}).catch((err: BusinessError) => {
  console.log('setExtraOptions fail');
});
```

### getCertificate<sup>10+</sup>

getCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

在TLSSocketServer通信连接成功之后，获取本地的数字证书，使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                     |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------------- |
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\> | 是   | 回调函数，成功返回本地的证书，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 2303501  | SSL is null.           |
| 2303504  | Error looking up x509. |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
import util from "@ohos.util";

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getCertificate((err: BusinessError, data: socket.X509CertRawData) => {
  if (err) {
    console.log("getCertificate callback error = " + err);
  } else {
    const decoder = util.TextDecoder.create();
    const str = decoder.decodeWithStream(data.data);
    console.log("getCertificate callback: " + str);
  }
});
```

### getCertificate<sup>10+</sup>

getCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

在TLSSocketServer通信连接之后，获取本地的数字证书，使用Promise方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                            | 说明                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | 以Promise形式返回本地的数字证书的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 2303501  | SSL is null.           |
| 2303504  | Error looking up x509. |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
import util from "@ohos.util";

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getCertificate().then((data: socket.X509CertRawData) => {
  const decoder = util.TextDecoder.create();
  const str = decoder.decodeWithStream(data.data);
  console.log("getCertificate: " + str);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### getProtocol<sup>10+</sup>

getProtocol(callback: AsyncCallback\<string\>): void

在TLSSocketServer通信连接成功之后，获取通信的协议版本，使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                 |
| -------- | ----------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback\<string\> | 是   | 回调函数，返回通信的协议。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303505  | Error occurred in the tls system call. |
| 2300002  | System internal error.                 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getProtocol((err: BusinessError, data: string) => {
  if (err) {
    console.log("getProtocol callback error = " + err);
  } else {
    console.log("getProtocol callback = " + data);
  }
});
```

### getProtocol<sup>10+</sup>

getProtocol():Promise\<string\>

在TLSSocketServer通信连接成功之后，获取通信的协议版本，使用Promise方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型              | 说明                                                    |
| ----------------- | ------------------------------------------------------- |
| Promise\<string\> | 以Promise形式返回通信的协议。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 2303501  | SSL is null.                           |
| 2303505  | Error occurred in the tls system call. |
| 2300002  | System internal error.                 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.getProtocol().then((data: string) => {
  console.log(data);
}).catch((err: BusinessError) => {
  console.error("failed" + err);
});
```

### on('connect')<sup>10+</sup>

on(type: 'connect', callback: Callback\<TLSSocketConnection\>): void

订阅TLSSocketServer的连接事件。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                  |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------- |
| type     | string                                                  | 是   | 订阅的事件类型。'connect'：连接事件。 |
| callback | Callback<[TLSSocketConnection](#tlssocketconnection10)> | 是   | 回调函数。                            |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.on('connect', (data: socket.TLSSocketConnection) => {
  console.log(JSON.stringify(data))
});
```

### off('connect')<sup>10+</sup>

off(type: 'connect', callback?: Callback\<TLSSocketConnection\>): void

取消订阅TLSSocketServer的连接事件。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                  |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------- |
| type     | string                                                  | 是   | 订阅的事件类型。'connect'：连接事件。 |
| callback | Callback<[TLSSocketConnection](#tlssocketconnection10)> | 否   | 回调函数。                            |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});

let callback = (data: socket.TLSSocketConnection) => {
  console.log('on connect message: ' + JSON.stringify(data));
}
tlsServer.on('connect', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tlsServer.off('connect', callback);
tlsServer.off('connect');
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅TLSSocketServer连接的error事件。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});
tlsServer.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err))
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅TLSSocketServer连接的error事件。使用callback方式作为异步方法。

> **说明：**
> listen方法调用成功后，才可调用此方法。
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed: " + JSON.stringify(err));
});

let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tlsServer.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tlsServer.off('error', callback);
tlsServer.off('error');
```

## TLSSocketConnection<sup>10+</sup>

TLSSocketConnection连接，即TLSSocket客户端与服务端的连接。在调用TLSSocketConnection的方法前，需要先获取TLSSocketConnection对象。

> **说明：**
> 客户端与服务端成功建立连接后，才能通过返回的TLSSocketConnection对象调用相应的接口。

**系统能力**：SystemCapability.Communication.NetStack

### 属性

| 名称     | 类型   | 必填 | 说明                                  |
| -------- | ------ | ---- | ------------------------------------- |
| clientId | number | 是   | 客户端与TLSSocketServer建立连接的id。 |

### send<sup>10+</sup>

send(data: string, callback: AsyncCallback\<void\>): void

在TLSSocketServer通信连接成功之后，向客户端发送消息，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                             |
| -------- | --------------------- | ---- | ------------------------------------------------ |
| data     | string                | 是   | TLSSocketServer发送数据所需要的参数。            |
| callback | AsyncCallback\<void\> | 是   | 回调函数，成功返回空，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303503  | Error in tls writing.                  |
| 2303505  | Error occurred in the tls system call. |
| 2303506  | Error clearing tls connection.         |
| 2300002  | System internal error.                 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.send('Hello, client!', (err: BusinessError) => {
    if (err) {
      console.log('send fail');
      return;
    }
    console.log('send success');
  });
});
```

### send<sup>10+</sup>

send(data: string): Promise\<void\>

在TLSSocketServer通信连接成功之后，向服务端发送消息，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名 | 类型   | 必填 | 说明                                  |
| ------ | ------ | ---- | ------------------------------------- |
| data   | string | 是   | TLSSocketServer发送数据所需要的参数。 |

**返回值：**

| 类型            | 说明                                                      |
| --------------- | --------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回，成功返回空，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303503  | Error in tls writing.                  |
| 2303505  | Error occurred in the tls system call. |
| 2303506  | Error clearing tls connection.         |
| 2300002  | System internal error.                 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.send('Hello, client!').then(() => {
    console.log('send success');
  }).catch((err: BusinessError) => {
    console.log('send fail');
  });
});
```

### close<sup>10+</sup>

close(callback: AsyncCallback\<void\>): void

在与TLSSocketServer通信连接成功之后，断开连接，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                             |
| -------- | --------------------- | ---- | ------------------------------------------------ |
| callback | AsyncCallback\<void\> | 是   | 回调函数，成功返回空，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303505  | Error occurred in the tls system call. |
| 2303506  | Error clearing tls connection.         |
| 2300002  | System internal error.                 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.close((err: BusinessError) => {
    if (err) {
      console.log('close fail');
      return;
    }
    console.log('close success');
  });
});
```

### close<sup>10+</sup>

close(): Promise\<void\>

在与TLSSocketServer通信连接成功之后，断开连接，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                                                      |
| --------------- | --------------------------------------------------------- |
| Promise\<void\> | 以Promise形式返回，成功返回空。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 2303501  | SSL is null.                           |
| 2303505  | Error occurred in the tls system call. |
| 2303506  | Error clearing tls connection.         |
| 2300002  | System internal error.                 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.close().then(() => {
    console.log('close success');
  }).catch((err: BusinessError) => {
    console.log('close fail');
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(callback: AsyncCallback\<NetAddress\>): void

在TLSSocketServer通信连接成功之后，获取对端Socket地址。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[NetAddress](#netaddress)\> | 是   | 回调函数。成功返回对端的socket地址，失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 401      | Parameter error.                |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getRemoteAddress((err: BusinessError, data: socket.NetAddress) => {
    if (err) {
      console.log('getRemoteAddress fail');
      return;
    }
    console.log('getRemoteAddress success:' + JSON.stringify(data));
  });
});
```

### getRemoteAddress<sup>10+</sup>

getRemoteAddress(): Promise\<NetAddress\>

在TLSSocketServer通信连接成功之后，获取对端Socket地址。使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                 | 说明                                                         |
| :----------------------------------- | :----------------------------------------------------------- |
| Promise\<[NetAddress](#netaddress)> | 以Promise形式返回获取对端socket地址的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 2303188  | Socket operation on non-socket. |
| 2300002  | System internal error.          |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getRemoteAddress().then((data: socket.NetAddress) => {
    console.log('getRemoteAddress success:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error("failed" + err);
  });
});
```

### getRemoteCertificate<sup>10+</sup>

getRemoteCertificate(callback: AsyncCallback\<[X509CertRawData](#x509certrawdata9)\>): void

在TLSSocketServer通信连接成功之后，获取对端的数字证书，该接口只适用于客户端向服务端发送证书时，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                 |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback\<[X509CertRawData](#x509certrawdata9)\> | 是   | 回调函数，返回对端的证书。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 2303501  | SSL is null.           |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
import util from "@ohos.util";

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getRemoteCertificate((err: BusinessError, data: socket.X509CertRawData) => {
    if (err) {
      console.log("getRemoteCertificate callback error: " + err);
    } else {
      const decoder = util.TextDecoder.create();
      const str = decoder.decodeWithStream(data.data);
      console.log("getRemoteCertificate callback: " + str);
    }
  });
});
```

### getRemoteCertificate<sup>10+</sup>

getRemoteCertificate():Promise\<[X509CertRawData](#x509certrawdata9)\>

在TLSSocketServer通信连接成功之后，获取对端的数字证书，该接口只适用于客户端向服务端发送证书时，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                            | 说明                                                         |
| ----------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[X509CertRawData](#x509certrawdata9)\> | 以Promise形式返回对端的数字证书的结果。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 2303501  | SSL is null.           |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
import util from "@ohos.util";

let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getRemoteCertificate().then((data: socket.X509CertRawData) => {
    const decoder = util.TextDecoder.create();
    const str = decoder.decodeWithStream(data.data);
    console.log("getRemoteCertificate success: " + str);
  }).catch((err: BusinessError) => {
    console.error("failed" + err);
  });
});
```

### getCipherSuite<sup>10+</sup>

getCipherSuite(callback: AsyncCallback\<Array\<string\>\>): void

在TLSSocketServer通信连接成功之后，获取通信双方协商后的加密套件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<Array\<string\>\> | 是   | 回调函数，返回通信双方支持的加密套件。 失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 401      | Parameter error.                       |
| 2303501  | SSL is null.                           |
| 2303502  | Error in tls reading.                  |
| 2303505  | Error occurred in the tls system call. |
| 2300002  | System internal error.                 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getCipherSuite((err: BusinessError, data: Array<string>) => {
    if (err) {
      console.log("getCipherSuite callback error = " + err);
    } else {
      console.log("getCipherSuite callback = " + data);
    }
  });
});
```

### getCipherSuite<sup>10+</sup>

getCipherSuite(): Promise\<Array\<string\>\>

在TLSSocketServer通信连接成功之后，获取通信双方协商后的加密套件，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                       | 说明                                                         |
| -------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<string\>\> | 以Promise形式返回通信双方支持的加密套件。失败返回错误码，错误信息。 |

**错误码：**

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 2303501  | SSL is null.                           |
| 2303502  | Error in tls reading.                  |
| 2303505  | Error occurred in the tls system call. |
| 2300002  | System internal error.                 |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getCipherSuite().then((data: Array<string>) => {
    console.log('getCipherSuite success:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error("failed" + err);
  });
});
```

### getSignatureAlgorithms<sup>10+</sup>

getSignatureAlgorithms(callback: AsyncCallback\<Array\<string\>\>): void

在TLSSocketServer通信连接成功之后，获取通信双方协商后签名算法，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                             | 必填 | 说明                               |
| -------- | -------------------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<Array\<string\>\> | 是   | 回调函数，返回双方支持的签名算法。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401      | Parameter error.       |
| 2303501  | SSL is null.           |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getSignatureAlgorithms((err: BusinessError, data: Array<string>) => {
    if (err) {
      console.log("getSignatureAlgorithms callback error = " + err);
    } else {
      console.log("getSignatureAlgorithms callback = " + data);
    }
  });
});
```

### getSignatureAlgorithms<sup>10+</sup>

getSignatureAlgorithms(): Promise\<Array\<string\>\>

在TLSSocketServer通信连接成功之后，获取通信双方协商后的签名算法，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                       | 说明                                          |
| -------------------------- | --------------------------------------------- |
| Promise\<Array\<string\>\> | 以Promise形式返回获取到的双方支持的签名算法。 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 2303501  | SSL is null.           |
| 2300002  | System internal error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.getSignatureAlgorithms().then((data: Array<string>) => {
    console.log("getSignatureAlgorithms success" + data);
  }).catch((err: BusinessError) => {
    console.error("failed" + err);
  });
});
```

### on('message')<sup>10+</sup>

on(type: 'message', callback: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

订阅TLSSocketConnection连接的接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 是   | 回调函数。                                |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
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
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('message', (value: SocketInfo) => {
    let messageView = '';
    for (let i: number = 0; i < value.message.byteLength; i++) {
      let messages: number = value.message[i]
      let message = String.fromCharCode(messages);
      messageView += message;
    }
    console.log('on message message: ' + JSON.stringify(messageView));
    console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
  });
});
```

### off('message')<sup>10+</sup>

off(type: 'message', callback?: Callback<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}\>): void

取消订阅TLSSocketConnection连接的接收消息事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 否   | 回调函数。                                |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
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
    let messages: number = value.message[i]
    let message = String.fromCharCode(messages);
    messageView += message;
  }
  console.log('on message message: ' + JSON.stringify(messageView));
  console.log('remoteInfo: ' + JSON.stringify(value.remoteInfo));
}
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('message', callback);
  // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
  client.off('message', callback);
  client.off('message');
});
```

### on('close')<sup>10+</sup>

on(type: 'close', callback: Callback\<void\>): void

订阅TLSSocketConnection的关闭事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | 是   | 订阅的事件类型。'close'：关闭事件。 |
| callback | Callback\<void\> | 是   | 回调函数。                          |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('close', () => {
    console.log("on close success")
  });
});
```

### off('close')<sup>10+</sup>

off(type: 'close', callback?: Callback\<void\>): void

取消订阅TLSSocketConnection的关闭事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                |
| -------- | ---------------- | ---- | ----------------------------------- |
| type     | string           | 是   | 订阅的事件类型。'close'：关闭事件。 |
| callback | Callback\<void\> | 否   | 回调函数。                          |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

let callback = () => {
  console.log("on close success");
}
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('close', callback);
  // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
  client.off('close', callback);
  client.off('close');
});
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅TLSSocketConnection连接的error事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                           |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('error', (err: BusinessError) => {
    console.log("on error, err:" + JSON.stringify(err))
  });
});
```

### off('error')<sup>10+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅TLSSocketConnection连接的error事件。使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**错误码：**

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例：**

```ts
import socket from "@ohos.net.socket";
import { BusinessError } from '@ohos.base';
let tlsServer: socket.TLSSocketServer = socket.constructTLSSocketServerInstance();
let tlsConnectOptions: socket.TLSConnectOptions = {
  address: {
    address: '192.168.xx.xxx',
    port: 8080
  },
  secureOptions: {
    key: "xxxx",
    cert: "xxxx",
    ca: ["xxxx"],
    password: "xxxx",
    protocols: socket.Protocol.TLSv12,
    useRemoteCipherPrefer: true,
    signatureAlgorithms: "rsa_pss_rsae_sha256:ECDSA+SHA256",
    cipherSuite: "AES256-SHA256"
  },
  ALPNProtocols: ["spdy/1", "http/1.1"]
}
tlsServer.listen(tlsConnectOptions).then(() => {
  console.log("listen callback success");
}).catch((err: BusinessError) => {
  console.log("failed" + err);
});

let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
}
tlsServer.on('connect', (client: socket.TLSSocketConnection) => {
  client.on('error', callback);
  // 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
  client.off('error', callback);
  client.off('error');
});
```

