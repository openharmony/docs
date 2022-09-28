# Socket连接

>![](public_sys-resources/icon-note.gif) **说明：** 
>
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```js
import socket from '@ohos.net.socket';
```

## socket.constructUDPSocketInstance

constructUDPSocketInstance\(\): UDPSocket

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


## UDPSocket

UDPSocket连接。在调用UDPSocket的方法前，需要先通过[socket.constructUDPSocketInstance](#socketconstructudpsocketinstance)创建UDPSocket对象。

### bind

bind\(address: NetAddress, callback: AsyncCallback<void\>\): void

绑定IP地址和端口，端口可以指定或由系统随机分配。使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                   |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |
| callback | AsyncCallback\<void\>              | 是   | 回调函数。                                             |

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


### bind

bind\(address: NetAddress\): Promise<void\>

绑定IP地址和端口，端口可以指定或由系统随机分配。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                               | 必填 | 说明                                                   |
| ------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address | [NetAddress](#netaddress) | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |


**返回值：**

| 类型            | 说明                                       |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | 以Promise形式异步返回UDPSocket绑定的结果。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let promise = udp.bind({address: '192.168.xx.xxx', port: 8080, family: 1});
promise .then(() => {
  console.log('bind success');
}).catch(err => {
  console.log('bind fail');
});
```


### send

send\(options: UDPSendOptions, callback: AsyncCallback<void\>\): void

通过UDPSocket连接发送数据。使用callback方式作为异步方法。

发送数据前，需要先调用[UDPSocket.bind()](#bind)绑定IP地址和端口。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPSendOptions](#udpsendoptions) | 是   | UDPSocket发送参数，参考[UDPSendOptions](#udpsendoptions)。 |
| callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.send({
  data:'Hello, server!',
  address: {
	address:'192.168.xx.xxx',
	port:xxxx,
	family:1
  }
}, err=> {
	if (err) {
	  console.log('send fail');
	  return;
	}
	console.log('send success');
})
```


### send

send\(options: UDPSendOptions\): Promise<void\>

通过UDPSocket连接发送数据。使用Promise方式作为异步方法。

发送数据前，需要先调用[UDPSocket.bind()](#bind)绑定IP地址和端口。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                                                         |
| ------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [UDPSendOptions](#udpsendoptions) | 是   | UDPSocket发送参数，参考[UDPSendOptions](#udpsendoptions)。 |

**返回值：**

| 类型            | 说明                                           |
| :-------------- | :--------------------------------------------- |
| Promise\<void\> | 以Promise形式返回UDPSocket连接发送数据的结果。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let promise = udp.send({
  data:'Hello, server!',
  address: {
	address:'192.168.xx.xxx',
	port:xxxx,
	family:1
  }
});
promise.then(() => {
  console.log('send success');
}).catch(err => {
  console.log('send fail');
});
```


### close

close\(callback: AsyncCallback<void\>\): void

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


### close

close\(\): Promise<void\>

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


### getState

getState\(callback: AsyncCallback<SocketStateBase\>\): void

获取UDPSocket状态。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#bind)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback<[SocketStateBase](#socketstatebase)> | 是   | 回调函数。 |

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


### getState

getState\(\): Promise<SocketStateBase\>

获取UDPSocket状态。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#bind)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                             | 说明                                       |
| :----------------------------------------------- | :----------------------------------------- |
| Promise<[SocketStateBase](#socketstatebase)> | 以Promise形式返回获取UDPSocket状态的结果。 |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1}, err => {
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
})
```


### setExtraOptions

setExtraOptions\(options: UDPExtraOptions, callback: AsyncCallback<void\>\): void

设置UDPSocket连接的其他属性。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#bind)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [UDPExtraOptions](#udpextraoptions) | 是   | UDPSocket连接的其他属性，参考[UDPExtraOptions](#udpextraoptions)。 |
| callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |


**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.bind({address:'192.168.xx.xxx', port:xxxx, family:1}, err=> {
  if (err) {
	console.log('bind fail');
	return;
  }
  console.log('bind success');
  udp.setExtraOptions({
	receiveBufferSize:1000,
	sendBufferSize:1000,
	reuseAddress:false,
	socketTimeout:6000,
	broadcast:true
  }, err=> {
	if (err) {
	  console.log('setExtraOptions fail');
	  return;
	}
	console.log('setExtraOptions success');
  })
})
```


### setExtraOptions

setExtraOptions\(options: UDPExtraOptions\): Promise<void\>

设置UDPSocket连接的其他属性。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#bind)方法调用成功后，才可调用此方法。

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

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let promise = udp.bind({address:'192.168.xx.xxx', port:xxxx, family:1});
promise.then(() => {
  console.log('bind success');
  let promise1 = udp.setExtraOptions({
	receiveBufferSize:1000,
	sendBufferSize:1000,
	reuseAddress:false,
	socketTimeout:6000,
	broadcast:true
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


### on\('message'\)

on\(type: 'message', callback: Callback<\{message: ArrayBuffer, remoteInfo: SocketRemoteInfo\}\>\): void

订阅UDPSocket连接的接收消息事件。使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 是   | 回调函数。                                |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
udp.on('message', value => {
	console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
});
```


### off\('message'\)

off\(type: 'message', callback?: Callback<\{message: ArrayBuffer, remoteInfo: SocketRemoteInfo\}\>\): void

取消订阅UDPSocket连接的接收消息事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 否   | 回调函数。                                |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let callback = value =>{
	console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
}
udp.on('message', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('message', callback);
udp.off('message');
```


### on\('listening' | 'close'\)

on\(type: 'listening' | 'close', callback: Callback<void\>\): void

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
	console.log("on close success" );
});
```


### off\('listening' | 'close'\)

off\(type: 'listening' | 'close', callback?: Callback<void\>\): void

取消订阅UDPSocket连接的数据包消息事件或关闭事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅事件类型。<br />- 'listening'：数据包消息事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 否   | 回调函数。                                                   |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let callback1 = () =>{
	console.log("on listening, success");
}
udp.on('listening', callback1);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('listening', callback1);
udp.off('listening');
let callback2 = () =>{
	console.log("on close, success");
}
udp.on('close', callback2);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('close', callback2);
udp.off('close');
```


### on\('error'\)

on\(type: 'error', callback: ErrorCallback\): void

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


### off\('error'\)

off\(type: 'error', callback?: ErrorCallback\): void

取消订阅UDPSocket连接的error事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**示例：**

```js
let udp = socket.constructUDPSocketInstance();
let callback = err =>{
	console.log("on error, err:" + JSON.stringify(err));
}
udp.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
udp.off('error', callback);
udp.off('error');
```


## NetAddress

目标地址信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | 是   | 本地绑定的ip地址。                                           |
| port    | number | 否   | 端口号 ，范围0~65535。如果不指定系统随机分配端口。           |
| family  | number | 否   | 网络协议类型，可选类型：<br />- 1：IPv4<br />- 2：IPv6<br />默认为1。 |

## UDPSendOptions

UDPSocket发送参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 参数名  | 类型                               | 必填 | 说明           |
| ------- | ---------------------------------- | ---- | -------------- |
| data    | string \| ArrayBuffer<sup>7+</sup>                          | 是   | 发送的数据。   |
| address | [NetAddress](#netaddress) | 是   | 目标地址信息。 |

## UDPExtraOptions

UDPSocket连接的其他属性。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 参数名            | 类型    | 必填 | 说明                             |
| ----------------- | ------- | ---- | -------------------------------- |
| broadcast         | boolean | 否   | 是否可以发送广播。默认为false。  |
| receiveBufferSize | number  | 否   | 接收缓冲区大小（单位：Byte）。   |
| sendBufferSize    | number  | 否   | 发送缓冲区大小（单位：Byte）。   |
| reuseAddress      | boolean | 否   | 是否重用地址。默认为false。      |
| socketTimeout     | number  | 否   | 套接字超时时间，单位毫秒（ms）。 |

## SocketStateBase

Socket的状态信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 参数名      | 类型    | 必填 | 说明       |
| ----------- | ------- | ---- | ---------- |
| isBound     | boolean | 是   | 是否绑定。 |
| isClose     | boolean | 是   | 是否关闭。 |
| isConnected | boolean | 是   | 是否连接。 |

## SocketRemoteInfo

Socket的连接信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| address | string | 是   | 本地绑定的ip地址。                                           |
| family  | string | 是   | 网络协议类型，可选类型：<br />- IPv4<br />- IPv6<br />默认为IPv4。 |
| port    | number | 是   | 端口号，范围0~65535。                                        |
| size    | number | 是   | 服务器响应信息的字节长度。                                   |

## socket.constructTCPSocketInstance

constructTCPSocketInstance\(\): TCPSocket

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


## TCPSocket

TCPSocket连接。在调用TCPSocket的方法前，需要先通过[socket.constructTCPSocketInstance](#socketconstructtcpsocketinstance)创建TCPSocket对象。

### bind

bind\(address: NetAddress, callback: AsyncCallback<void\>\): void

绑定IP地址和端口，端口可以指定或由系统随机分配。使用callback方法作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                   |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------ |
| address  | [NetAddress](#netaddress) | 是   | 目标地址信息，参考[NetAddress](#netaddress)。 |
| callback | AsyncCallback\<void\>              | 是   | 回调函数。                                             |


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


### bind

bind\(address: NetAddress\): Promise<void\>

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

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.bind({address: '192.168.xx.xxx', port: xxxx, family: 1});
promise.then(() => {
  console.log('bind success');
}).catch(err => {
  console.log('bind fail');
});
```


### connect

connect\(options: TCPConnectOptions, callback: AsyncCallback<void\>\): void

连接到指定的IP地址和端口。使用callback方法作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPConnectOptions](#tcpconnectoptions) | 是   | TCPSocket连接的参数，参考[TCPConnectOptions](#tcpconnectoptions)。 |
| callback | AsyncCallback\<void\>                    | 是   | 回调函数。                                                   |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000}, err => {
  if (err) {
	console.log('connect fail');
	return;
  }
  console.log('connect success');
})
```


### connect

connect\(options: TCPConnectOptions\): Promise<void\>

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

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
promise.then(() => {
  console.log('connect success')
}).catch(err => {
  console.log('connect fail');
});
```


### send

send\(options: TCPSendOptions, callback: AsyncCallback<void\>\): void

通过TCPSocket连接发送数据。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[connect](#connect)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPSendOptions](#tcpsendoptions) | 是   | TCPSocket发送请求的参数，参考[TCPSendOptions](#tcpsendoptions)。 |
| callback | AsyncCallback\<void\>                   | 是   | 回调函数。                                                   |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
promise.then(() => {
  console.log('connect success');
  tcp.send({
	data:'Hello, server!'
  },err => {
	if (err) {
	  console.log('send fail');
	  return;
	}
	console.log('send success');
  })
}).catch(err => {
  console.log('connect fail');
});
```


### send

send\(options: TCPSendOptions\): Promise<void\>

通过TCPSocket连接发送数据。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[connect](#connect)方法调用成功后，才可调用此方法。

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

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise1 = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
promise1.then(() => {
  console.log('connect success');
  let promise2 = tcp.send({
	data:'Hello, server!'
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


### close

close\(callback: AsyncCallback<void\>\): void

关闭TCPSocket连接。使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。 |


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


### close

close\(\): Promise<void\>

关闭TCPSocket连接。使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型            | 说明                                       |
| :-------------- | :----------------------------------------- |
| Promise\<void\> | 以Promise形式返回关闭TCPSocket连接的结果。 |

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


### getRemoteAddress

getRemoteAddress\(callback: AsyncCallback<NetAddress\>\): void

获取对端Socket地址。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[connect](#connect)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                              | 必填 | 说明       |
| -------- | ------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback<[NetAddress](#netaddress)> | 是   | 回调函数。 |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
promise.then(() => {
  console.log('connect success');
  tcp.getRemoteAddress((err, data) => {
	if (err) {
	  console.log('getRemoteAddressfail');
	  return;
	}
	console.log('getRemoteAddresssuccess:' + JSON.stringify(data));
  })
}).catch(err => {
  console.log('connect fail');
});
```


### getRemoteAddress

getRemoteAddress\(\): Promise<NetAddress\>

获取对端Socket地址。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[connect](#connect)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                        | 说明                                        |
| :------------------------------------------ | :------------------------------------------ |
| Promise<[NetAddress](#netaddress)> | 以Promise形式返回获取对端socket地址的结果。 |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise1 = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
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


### getState

getState\(callback: AsyncCallback<SocketStateBase\>\): void

获取TCPSocket状态。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#bind)或[connect](#connect)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback<[SocketStateBase](#socketstatebase)> | 是   | 回调函数。 |


**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
promise.then(() => {
  console.log('connect success');
  tcp.getState((err, data) => {
	if (err) {
	  console.log('getState fail');
	  return;
	}
	console.log('getState success:' + JSON.stringify(data));
  });
}).catch(err => {
  console.log('connect fail');
});
```


### getState

getState\(\): Promise<SocketStateBase\>

获取TCPSocket状态。使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#bind)或[connect](#connect)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                             | 说明                                       |
| :----------------------------------------------- | :----------------------------------------- |
| Promise<[SocketStateBase](#socketstatebase)> | 以Promise形式返回获取TCPSocket状态的结果。 |


**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
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


### setExtraOptions

setExtraOptions\(options: TCPExtraOptions, callback: AsyncCallback<void\>\): void

设置TCPSocket连接的其他属性。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#bind)或[connect](#connect)方法调用成功后，才可调用此方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [TCPExtraOptions](#tcpextraoptions) | 是   | TCPSocket连接的其他属性，参考[TCPExtraOptions](#tcpextraoptions)。 |
| callback | AsyncCallback\<void\>                     | 是   | 回调函数。                                                   |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
promise.then(() => {
  console.log('connect success');
  tcp.setExtraOptions({
	keepAlive: true,
	OOBInline: true,
	TCPNoDelay: true,
	socketLinger: { on:true, linger:10 },
	receiveBufferSize: 1000,
	sendBufferSize: 1000,
	reuseAddress: true,
	socketTimeout: 3000,
  },err => {
	if (err) {
	  console.log('setExtraOptions fail');
	  return;
	}
	console.log('setExtraOptions success');
  });
}).catch(err => {
  console.log('connect fail');
});
```


### setExtraOptions

setExtraOptions\(options: TCPExtraOptions\): Promise<void\>

设置TCPSocket连接的其他属性，使用Promise方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>[bind](#bind)或[connect](#connect)方法调用成功后，才可调用此方法。

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


**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let promise = tcp.connect({ address: {address: '192.168.xx.xxx', port: xxxx, family: 1} , timeout: 6000});
promise.then(() => {
  console.log('connect success');
  let promise1 = tcp.setExtraOptions({
	keepAlive: true,
	OOBInline: true,
	TCPNoDelay: true,
	socketLinger: { on:true, linger:10 },
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


### on\('message'\)

on\(type: 'message', callback: Callback<\{message: ArrayBuffer, remoteInfo: SocketRemoteInfo\}\>\): void

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
tcp.on('message', value => {
	console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo)
});
```


### off\('message'\)

off\(type: 'message', callback?: Callback<\{message: ArrayBuffer, remoteInfo: SocketRemoteInfo\}\>\): void

取消订阅TCPSocket连接的接收消息事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 订阅的事件类型。'message'：接收消息事件。 |
| callback | Callback<{message: ArrayBuffer, remoteInfo: [SocketRemoteInfo](#socketremoteinfo)}> | 否   | 回调函数。                                |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let callback = value =>{
	console.log("on message, message:" + value.message + ", remoteInfo:" + value.remoteInfo);
}
tcp.on('message', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('message', callback);
tcp.off('message');
```


### on\('connect' | 'close'\)

on\(type: 'connect' | 'close', callback: Callback<void\>\): void

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
tcp.on('close', data => {
	console.log("on close success")
});
```


### off\('connect' | 'close'\)

off\(type: 'connect' | 'close', callback?: Callback<void\>\): void

取消订阅TCPSocket的连接事件或关闭事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                         |
| -------- | ---------------- | ---- | ------------------------------------------------------------ |
| type     | string           | 是   | 订阅的事件类型。<br />- 'connect'：连接事件。<br />- 'close'：关闭事件。 |
| callback | Callback\<void\> | 否   | 回调函数。                                                   |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let callback1 = () =>{
	console.log("on connect success");
}
tcp.on('connect', callback1);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('connect', callback1);
tcp.off('connect');
let callback2 = () =>{
	console.log("on close success");
}
tcp.on('close', callback2);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('close', callback2);
tcp.off('close');
```


### on\('error'\)

on\(type: 'error', callback: ErrorCallback\): void

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


### off\('error'\)

off\(type: 'error', callback?: ErrorCallback\): void

取消订阅TCPSocket连接的error事件。使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 订阅的事件类型。'error'：error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                           |

**示例：**

```js
let tcp = socket.constructTCPSocketInstance();
let callback = err =>{
	console.log("on error, err:" + JSON.stringify(err));
}
tcp.on('error', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
tcp.off('error', callback);
tcp.off('error');
```


## TCPConnectOptions

TCPSocket连接的参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 参数名  | 类型                               | 必填 | 说明                       |
| ------- | ---------------------------------- | ---- | -------------------------- |
| address | [NetAddress](#netaddress) | 是   | 绑定的地址以及端口。       |
| timeout | number                             | 否   | 超时时间，单位毫秒（ms）。 |

## TCPSendOptions

TCPSocket发送请求的参数。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| data     | string\| ArrayBuffer<sup>7+</sup>  | 是   | 发送的数据。                                                 |
| encoding | string | 否   | 字符编码(UTF-8，UTF-16BE，UTF-16LE，UTF-16，US-AECII，ISO-8859-1)，默认为UTF-8。 |

## TCPExtraOptions

TCPSocket连接的其他属性。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetStack。

| 参数名            | 类型    | 必填 | 说明                                                         |
| ----------------- | ------- | ---- | ------------------------------------------------------------ |
| keepAlive         | boolean | 否   | 是否保持连接。默认为false。                                  |
| OOBInline         | boolean | 否   | 是否为OOB内联。默认为false。                                 |
| TCPNoDelay        | boolean | 否   | TCPSocket连接是否无时延。默认为false。                       |
| socketLinger      | Object  | 是   | socket是否继续逗留。<br />- on：是否逗留（true：逗留；false：不逗留）。<br />- linger：逗留时长，单位毫秒（ms），取值范围为0~65535。<br />当入参on设置为true时，才需要设置。 |
| receiveBufferSize | number  | 否   | 接收缓冲区大小（单位：Byte）。                               |
| sendBufferSize    | number  | 否   | 发送缓冲区大小（单位：Byte）。                               |
| reuseAddress      | boolean | 否   | 是否重用地址。默认为false。                                  |
| socketTimeout     | number  | 否   | 套接字超时时间，单位毫秒（ms）。                             |
