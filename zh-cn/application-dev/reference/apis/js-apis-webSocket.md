# WebSocket连接<a name="ZH-CN_TOPIC_0000001216545901"></a>

-   [导入模块](#s56d19203690d4782bfc74069abb6bd71)
-   [权限列表](#section11257113618419)
-   [完整示例](#section20761171275912)
-   [webSocket.createWebSocket](#section375081875219)
-   [WebSocket](#section16411174314593)
    -   [connect](#section1377525513113)
    -   [connect](#section18952991528)
    -   [connect](#section10573126422)
    -   [send](#section156451414213)
    -   [send](#section137609541324)
    -   [close](#section202411451433)
    -   [close](#section10491513437)
    -   [close](#section118451219536)
    -   [on\('open'\)](#section923017271834)
    -   [off\('open'\)](#section207051331730)
    -   [on\('message'\)](#section1066819418488)
    -   [off\('message'\)](#section1467019413484)
    -   [on\('close'\)](#section169378107484)
    -   [off\('close'\)](#section993911074812)
    -   [on\('error'\)](#section2997161484815)
    -   [off\('error'\)](#section13999114164815)

-   [WebSocketRequestOptions](#section11251233123910)
-   [WebSocketCloseOptions](#section12262183471518)
-   [close错误码说明](#section1635681416477)

>![](public_sys-resources/icon-note.gif) **说明：** 
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>当前暂时不支持WebSocket，预计在MR版本支持。

使用WebSocket建立服务器与客户端的双向连接，需要先通过[createWebSocket](#section375081875219)方法创建[WebSocket](#section16411174314593)对象，然后通过[connect](WebSocket连接.md)方法连接到服务器。当连接成功后，客户端会收到[open](#section923017271834)事件的回调，之后客户端就可以通过[send](#section156451414213)方法与服务器进行通信。当服务器发信息给客户端时，客户端会收到[message](#section1066819418488)事件的回调。当客户端不要此连接时，可以通过调用[close](#section202411451433)方法主动断开连接，之后客户端会收到[close](#section169378107484)事件的回调。

若在上述任一过程中发生错误，客户端会收到[error](#section2997161484815)事件的回调。


## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import webSocket from '@ohos.net.webSocket';
```

## 权限列表<a name="section11257113618419"></a>

需要ohos.permission.INTERNET权限。

## 完整示例<a name="section20761171275912"></a>

```
import webSocket from '@ohos.net.webSocket';

var defaultIpAddress = "ws://";
let ws = webSocket.createWebSocket();
ws.on('open', (err, value) => {
    console.log("on open, status:" + value.status + ", message:" + value.message);
    // 当收到on('open')事件时，可以通过send()方法与服务器进行通信
    ws.send("Hello, server!", (err, value) => {
        if (!err) {
            console.log("send success");
        } else {
            console.log("send fail, err:" + JSON.stringify(err));
        }
    });
});
ws.on('message', (err, value) => {
    console.log("on message, message:" + value);
    // 当收到服务器的`bye`消息时（此消息字段仅为示意，具体字段需要与服务器协商），主动断开连接
    if (value === 'bye') {
        ws.close((err, value) => {
            if (!err) {
                console.log("close success");
            } else {
                console.log("close fail, err is " + JSON.stringify(err));
            }
        });
    }
});
ws.on('close', (err, value) => {
    console.log("on close, code is " + value.code + ", reason is " + value.reason);
});
ws.on('error', (err) => {
    console.log("on error, error:" + JSON.stringify(err));
});
ws.connect(defaultIpAddress, (err, value) => {
    if (!err) {
        console.log("connect success");
    } else {
        console.log("connect fail, err:" + JSON.stringify(err));
    }
});
```

## webSocket.createWebSocket<a name="section375081875219"></a>

createWebSocket\(\): WebSocket

创建一个WebSocket，里面包括建立连接、关闭连接、发送数据和订阅/取消订阅WebSocket连接的打开事件、接收到服务器消息事件、关闭事件和错误事件。

**返回值：**

| 类型                                | 说明                                                         |
| :---------------------------------- | :----------------------------------------------------------- |
| [WebSocket](#section16411174314593) | 返回一个WebSocket对象，里面包括connect、send、close、on和off方法。 |

**示例：**

```
let ws = webSocket.createWebSocket();
```


## WebSocket<a name="section16411174314593"></a>

在调用WebSocket的方法前，需要先通过[webSocket.createWebSocket](#section375081875219)创建一个WebSocket。

### connect<a name="section1377525513113"></a>

connect\(url: string, callback: AsyncCallback<boolean\>\): void

根据URL地址，建立一个WebSocket连接，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                         |
| -------- | ------------------------ | ---- | ---------------------------- |
| url      | string                   | 是   | 建立WebSocket连接的URL地址。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。                   |


**示例：**

```
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err, value) => {
	if (!err) {
		console.log("connect success");
	} else {
		console.log("connect fail, err:" + JSON.stringify(err))
	}
});
```


### connect<a name="section18952991528"></a>

connect\(url: string, options: WebSocketRequestOptions, callback: AsyncCallback<boolean\>\): void

根据URL地址和header，建立一个WebSocket连接，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                    |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| url      | string                   | 是   | 建立WebSocket连接的URL地址。                            |
| options  | WebSocketRequestOptions  | 是   | 参考[WebSocketRequestOptions](#section11251233123910)。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。                                              |


**示例：**

```
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, {
	header: {
		"key": "value",
		"key2": "value2"
	}
}, (err, value) => {
	if (!err) {
		console.log("connect success");
	} else {
		console.log("connect fail, err:" + JSON.stringify(err))
	}
});
```


### connect<a name="section10573126422"></a>

connect\(url: string, options?: WebSocketRequestOptions\): Promise<boolean\>

根据URL地址和header，建立一个WebSocket连接，使用Promise方式作为异步方法。

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                                    |
| ------- | ----------------------- | ---- | ------------------------------------------------------- |
| url     | string                  | 是   | 建立WebSocket连接的URL地址。                            |
| options | WebSocketRequestOptions | 否   | 参考[WebSocketRequestOptions](#section11251233123910)。 |

**返回值：**

| 类型               | 说明                              |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | 以Promise形式返回建立连接的结果。 |

**示例：**

```
let ws = webSocket.createWebSocket();
let url = "ws://"
let promise = ws.connect(url);
promise.then((value) => {
	console.log("connect success")
}).catch((err) => {
	console.log("connect fail, error:" + JSON.stringify(err))
});
```


### send<a name="section156451414213"></a>

send\(data: string | ArrayBuffer, callback: AsyncCallback<boolean\>\): void

通过WebSocket连接发送数据，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型                     | 必填 | 说明         |
| -------- | ------------------------ | ---- | ------------ |
| data     | string \| ArrayBuffer <sup>8+</sup> | 是   | 发送的数据。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。   |

**示例：**

```
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err, value) => {
	ws.send("Hello, server!", (err, value) => {
		if (!err) {
			console.log("send success");
		} else {
			console.log("send fail, err:" + JSON.stringify(err))
		}
	});
});
```


### send<a name="section137609541324"></a>

send\(data: string | ArrayBuffer\): Promise<boolean\>

通过WebSocket连接发送数据，使用Promise方式作为异步方法。

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| data     | string \| ArrayBuffer <sup>8+</sup> | 是   | 发送的数据。 |

**返回值：**

| 类型               | 说明                              |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | 以Promise形式返回发送数据的结果。 |

**示例：**

```
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err, value) => {
	let promise = ws.send("Hello, server!");
	promise.then((value) => {
		console.log("send success")
	}).catch((err) => {
		console.log("send fail, error:" + JSON.stringify(err))
	});
});
```


### close<a name="section202411451433"></a>

close\(callback: AsyncCallback<boolean\>\): void

关闭WebSocket连接，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型                     | 必填 | 说明       |
| -------- | ------------------------ | ---- | ---------- |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。 |

**示例：**

```
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.close((err, value) => {
	if (!err) {
		console.log("close success")
	} else {
		console.log("close fail, err is " + JSON.stringify(err))
	}
});
```


### close<a name="section10491513437"></a>

close\(options: WebSocketCloseOptions, callback: AsyncCallback<boolean\>\): void

根据可选参数code和reason，关闭WebSocket连接，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                  |
| -------- | ------------------------ | ---- | ----------------------------------------------------- |
| options  | WebSocketCloseOptions    | 是   | 参考[WebSocketCloseOptions](#section12262183471518)。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。                                            |

**示例：**

```
let ws = webSocket.createWebSocket();
let url = "ws://"
ws.close({
	code: 1000,
	reason: "your reason"
}, (err, value) => {
	if (!err) {
		console.log("close success")
	} else {
		console.log("close fail, err is " + JSON.stringify(err))
	}
});
```


### close<a name="section118451219536"></a>

close\(options?: WebSocketCloseOptions\): Promise<boolean\>

根据可选参数code和reason，关闭WebSocket连接，使用Promise方式作为异步方法。

**参数：**

| 参数名  | 类型                  | 必填 | 说明                                                  |
| ------- | --------------------- | ---- | ----------------------------------------------------- |
| options | WebSocketCloseOptions | 否   | 参考[WebSocketCloseOptions](#section12262183471518)。 |

**返回值：**

| 类型               | 说明                              |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | 以Promise形式返回关闭连接的结果。 |

**示例：**

```
let ws = webSocket.createWebSocket();
let url = "ws://"
let promise = ws.close({
	code: 1000,
	reason: "your reason"
});
promise.then((value) => {
	console.log("close success")
}).catch((err) => {
	console.log("close fail, err is " + JSON.stringify(err))
});
```


### on\('open'\)<a name="section923017271834"></a>

on\(type: 'open', callback: AsyncCallback<Object\>\): void

订阅WebSocket的打开事件，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                          |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | 是   | 'open'：WebSocket的打开事件。 |
| callback | AsyncCallback\<Object\> | 是   | 回调函数。                    |


**示例：**

```
let ws = webSocket.createWebSocket();
ws.on('open', (err, value) => {
	console.log("on open, status:" + value.status + ", message:" + value.message);
});
```


### off\('open'\)<a name="section207051331730"></a>

off\(type: 'open', callback?: AsyncCallback<Object\>\): void

取消订阅WebSocket的打开事件，使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                          |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | 是   | 'open'：WebSocket的打开事件。 |
| callback | AsyncCallback\<Object\> | 否   | 回调函数。                    |

**示例：**

```
let ws = webSocket.createWebSocket();
let callback1 = (err, value) => {
	console.log("on open, status:" + value.status + ", message:" + value.message);
}
ws.on('open', callback1);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅
ws.off('open', callback1);
```


### on\('message'\)<a name="section1066819418488"></a>

on\(type: 'message', callback: AsyncCallback<string | ArrayBuffer\>\): void

订阅WebSocket的接收到服务器消息事件，使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>AsyncCallback中的数据可以是字符串\(API 6\)或ArrayBuffer\(API 8\)。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                         |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | 是   | 'message'：WebSocket的接收到服务器消息事件。 |
| callback | AsyncCallback\<string \| ArrayBuffer <sup>8+</sup>\> | 是   | 回调函数。                                   |


**示例：**

```
let ws = webSocket.createWebSocket();
ws.on('message', (err, value) => {
	console.log("on message, message:" + value);
});
```


### off\('message'\)<a name="section1467019413484"></a>

off\(type: 'message', callback?: AsyncCallback<string | ArrayBuffer\>\): void

取消订阅WebSocket的接收到服务器消息事件，使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>AsyncCallback中的数据可以是字符串\(API 6\)或ArrayBuffer\(API 8\)。
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                         |
| -------- | --------------------------------------------------- | ---- | -------------------------------------------- |
| type     | string                                              | 是   | 'message'：WebSocket的接收到服务器消息事件。 |
| callback | AsyncCallback\<string \|ArrayBuffer <sup>8+</sup>\> | 否   | 回调函数。                                   |

**示例：**

```
let ws = webSocket.createWebSocket();
ws.off('message');
```


### on\('close'\)<a name="section169378107484"></a>

on\(type: 'close', callback: AsyncCallback<\{ code: number, reason: string \}\>\): void

订阅WebSocket的关闭事件，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | 是   | 'close'：WebSocket的关闭事件。 |
| callback | AsyncCallback<{ code: number, reason: string }> | 是   | 回调函数。                     |

**示例：**

```
let ws = webSocket.createWebSocket();
ws.on('close', (err, value) => {
	console.log("on close, code is " + value.code + ", reason is " + value.reason);
});
```


### off\('close'\)<a name="section993911074812"></a>

off\(type: 'close', callback?: AsyncCallback<\{ code: number, reason: string \}\>\): void

取消订阅WebSocket的关闭事件，使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | 是   | 'close'：WebSocket的关闭事件。 |
| callback | AsyncCallback<{ code: number, reason: string }> | 否   | 回调函数。                     |


**示例：**

```
let ws = webSocket.createWebSocket();
ws.off('close');
```


### on\('error'\)<a name="section2997161484815"></a>

on\(type: 'error', callback: ErrorCallback\): void

订阅WebSocket的Error事件，使用callback方式作为异步方法。

**参数：**

| 参数名   | 类型          | 必填 | 说明                            |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | 是   | 'error'：WebSocket的Error事件。 |
| callback | ErrorCallback | 是   | 回调函数。                      |


**示例：**

```
let ws = webSocket.createWebSocket();
ws.on('error', (err) => {
	console.log("on error, error:" + JSON.stringify(err))
});
```


### off\('error'\)<a name="section13999114164815"></a>

off\(type: 'error', callback?: ErrorCallback\): void

取消订阅WebSocket的Error事件，使用callback方式作为异步方法。

>![](public_sys-resources/icon-note.gif) **说明：** 
>可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**参数：**

| 参数名   | 类型          | 必填 | 说明                            |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | 是   | 'error'：WebSocket的Error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                      |

**示例：**

```
let ws = webSocket.createWebSocket();
ws.off('error');
```


## WebSocketRequestOptions<a name="section11251233123910"></a>

建立WebSocket连接时，可选参数的类型和说明。

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| header | Object | 否   | 建立WebSocket连接可选参数，代表建立连接时携带的HTTP头信息。参数内容自定义，也可以不指定。 |


## WebSocketCloseOptions<a name="section12262183471518"></a>

关闭WebSocket连接时，可选参数的类型和说明。

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | 否   | 错误码，关闭WebSocket连接时的可选参数，可根据实际情况来填。默认值为1000。 |
| reason | string | 否   | 原因值，关闭WebSocket连接时的可选参数，可根据实际情况来填。默认值为空字符串（""）。 |

## close错误码说明<a name="section1635681416477"></a>

发送给服务端的错误码可以自行定义，下面的列表仅供参考。

| 值        | 说明               |
| :-------- | :----------------- |
| 1000      | 正常关闭           |
| 1001      | 服务器主动关闭     |
| 1002      | 协议错误           |
| 1003      | 无法处理的数据类型 |
| 1004~1015 | 保留值             |

