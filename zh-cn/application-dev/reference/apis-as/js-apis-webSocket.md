# @ohos.net.webSocket (WebSocket连接)

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


使用WebSocket建立服务器与客户端的双向连接，需要先通过<span name="createWebSocket">[createWebSocket](#websocketcreatewebsocket)</span>方法创建<span name="WebSocket">[WebSocket](#websocket)</span>对象，然后通过<span name="connect">[connect](#connected)</span>方法连接到服务器。
当连接成功后，客户端会收到<span name="open">[open](#onopen)</span>事件的回调，之后客户端就可以通过<span name="sended">[send](#send)</span>方法与服务器进行通信。
当服务器发信息给客户端时，客户端会收到<span name="message">[message](#onmessage)</span>事件的回调。当客户端不要此连接时，可以通过调用<span name="closed">[close](#close)</span>方法主动断开连接，之后客户端会收到<span name="closes">[close](#onclose)</span>事件的回调。

若在上述任一过程中发生错误，客户端会收到<span name="error">[error](#onerror)</span>事件的回调。

## 导入模块

```ts
import webSocket from '@ohos.net.webSocket';
```

## 完整示例

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let defaultIpAddress = "ws://";
let ws = webSocket.createWebSocket();
ws.on('open', (err:BusinessError, value: Object) => {
  if (err != undefined) {
    console.log(JSON.stringify(err));
    return;
  }
  // 当收到on('open')事件时，可以通过send()方法与服务器进行通信
  ws.send("Hello, server!", (err: BusinessError, value: boolean) => {
    if (!err) {
      console.log("send success");
    } else {
      console.log("send fail, err:" + JSON.stringify(err));
    }
  });
});
ws.on('message',(BusinessError<void>, value: string | ArrayBuffer) => {
  console.log("on message, message:" + value);
  // 当收到服务器的`bye`消息时（此消息字段仅为示意，具体字段需要与服务器协商），主动断开连接
  if (value === 'bye') {
    ws.close((err: BusinessError, value: boolean) => {
      if (!err) {
        console.log("close success");
      } else {
        console.log("close fail, err is " + JSON.stringify(err));
      }
    });
  }
});
ws.on('close', (err: BusinessError, value: webSocket.CloseResult) => {
  console.log("on close, code is " + value.code + ", reason is " + value.reason);
});
ws.on('error', (err: BusinessError) => {
  console.log("on error, error:" + JSON.stringify(err));
});
ws.connect(defaultIpAddress, (err: BusinessError, value: boolean) => {
  if (!err) {
    console.log("connect success");
  } else {
    console.log("connect fail, err:" + JSON.stringify(err));
  }
  ws.close((err: BusinessError) => {
    if (!err) {
      console.log("close success");
    } else {
      console.log("close fail, err is " + JSON.stringify(err));
    }
  });
});
```

## <span name="websocketcreatewebsocket">webSocket.createWebSocket<sup>6+</sup></span>

createWebSocket(): WebSocket

创建一个WebSocket，里面包括建立连接、关闭连接、发送数据和订阅/取消订阅WebSocket连接的打开事件、接收到服务器消息事件、关闭事件和错误事件。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                | 说明                                                         |
| :---------------------------------- | :----------------------------------------------------------- |
| [WebSocket](#websocket) | 返回一个WebSocket对象，里面包括connect、send、close、on和off方法。 |

**示例：**

```ts
let ws: webSocket = webSocket.createWebSocket();
```

## <span name="websocket">WebSocket<sup>6+</sup></span>

在调用WebSocket的方法前，需要先通过[webSocket.createWebSocket](#websocketcreatewebsocket)创建一个WebSocket。

### <span name="send">send<sup>6+</sup></span>

send(data: string | ArrayBuffer, callback: AsyncCallback\<boolean\>): void

通过WebSocket连接发送数据，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                     | 必填 | 说明         |
| -------- | ------------------------ | ---- | ------------ |
| data     | string \| ArrayBuffer | 是   | 发送的数据。<br>API 6及更早版本仅支持string类型。API 8起同时支持string和ArrayBuffer类型。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。   |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err: BusinessError, value: boolean) => {
  ws.send("Hello, server!", (err: BusinessError, value: boolean) => {
    if (!err) {
      console.log("send success");
    } else {
      console.log("send fail, err:" + JSON.stringify(err))
    }
  });
});
```

### send<sup>6+</sup>

send(data: string | ArrayBuffer): Promise\<boolean\>

通过WebSocket连接发送数据，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| data     | string \| ArrayBuffer | 是   | 发送的数据。<br>API 6及更早版本仅支持string类型。API 8起同时支持string和ArrayBuffer类型。 |

**返回值：**

| 类型               | 说明                              |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | 以Promise形式返回发送数据的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
let url = "ws://"
ws.connect(url, (err: BusinessError, value: boolean) => {
  let promise = ws.send("Hello, server!");
  promise.then((value: boolean) => {
    console.log("send success")
  }).catch((err:string) => {
    console.log("send fail, error:" + JSON.stringify(err))
  });
});
```

### <span name="close">close<sup>6+</sup></span>

close(callback: AsyncCallback\<boolean\>): void

关闭WebSocket连接，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                     | 必填 | 说明       |
| -------- | ------------------------ | ---- | ---------- |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
ws.close((err: BusinessError) => {
  if (!err) {
    console.log("close success")
  } else {
    console.log("close fail, err is " + JSON.stringify(err))
  }
});
```

### close<sup>6+</sup>

close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean\>): void

根据可选参数code和reason，关闭WebSocket连接，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                  |
| -------- | ------------------------ | ---- | ----------------------------------------------------- |
| options  | WebSocketCloseOptions    | 是   | 参考[WebSocketCloseOptions](#websocketcloseoptions)。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。                                            |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();

let options: webSocket.WebSocketCloseOptions | undefined;
if (options != undefined) {
    options.code = 1000
    options.reason = "your reason"
}
ws.close(options, (err: BusinessError) => {
    if (!err) {
        console.log("close success")
    } else {
        console.log("close fail, err is " + JSON.stringify(err))
    }
});
```

### close<sup>6+</sup>

close(options?: WebSocketCloseOptions): Promise\<boolean\>

根据可选参数code和reason，关闭WebSocket连接，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名  | 类型                  | 必填 | 说明                                                  |
| ------- | --------------------- | ---- | ----------------------------------------------------- |
| options | WebSocketCloseOptions | 否   | 参考[WebSocketCloseOptions](#websocketcloseoptions)。 |

**返回值：**

| 类型               | 说明                              |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | 以Promise形式返回关闭连接的结果。 |

**错误码：**

| 错误码ID | 错误信息                 |
| ------- | ----------------------- |
| 401     | Parameter error.        |
| 201     | Permission denied.      |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';

let ws = webSocket.createWebSocket();
let options: webSocket.WebSocketCloseOptions | undefined;
if (options != undefined) {
    options.code = 1000
    options.reason = "your reason"
}
let promise = ws.close();
promise.then((value: boolean) => {
    console.log("close success")
}).catch((err:string) => {
    console.log("close fail, err is " + JSON.stringify(err))
});
```

### <span name="onopen">on('open')<sup>6+</sup></span>

on(type: 'open', callback: AsyncCallback\<Object\>): void

订阅WebSocket的打开事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                          |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | 是   | 'open'：WebSocket的打开事件。 |
| callback | AsyncCallback\<Object\> | 是   | 回调函数。                    |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError, Callback } from '@ohos.base';

let ws= webSocket.createWebSocket();
class OutValue {
  status: number = 0
  message: string = ""
}
ws.on('open', (err: BusinessError, value: Object) => {
  console.log("on open, status:" + (value as OutValue).status + ", message:" + (value as OutValue).message);
});
```

### <span name="onmessage">on('message')<sup>6+</sup></spam>

on(type: 'message', callback: AsyncCallback\<string | ArrayBuffer\>): void

订阅WebSocket的接收到服务器消息事件，使用callback方式作为异步方法。每个消息最大长度为4K，超过4K自动分片。

> **说明：**
> AsyncCallback中的数据可以是字符串(API 6)或ArrayBuffer(API 8)。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                         |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | 是   | 'message'：WebSocket的接收到服务器消息事件。 |
| callback | AsyncCallback\<string \| ArrayBuffer <sup>8+</sup>\> | 是   | 回调函数。                                   |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
ws.on('message', (err: BusinessError<void>, value: string | ArrayBuffer) => {
  console.log("on message, message:" + value);
});
```

### <span name="onclose">on('close')<sup>6+</sup></span>

on(type: 'close', callback: AsyncCallback\<CloseResult\>): void

订阅WebSocket的关闭事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | 是   | 'close'：WebSocket的关闭事件。 |
| callback | AsyncCallback\<CloseResult\> | 是   | 回调函数。<br>close：close错误码，reason：错误码说明 |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
ws.on('close', (err: BusinessError, value: webSocket.CloseResult) => {
  console.log("on close, code is " + value.code + ", reason is " + value.reason);
});
```

### <span name="onerror">on('error')<sup>6+</sup></span>

on(type: 'error', callback: ErrorCallback): void

订阅WebSocket的Error事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                            |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | 是   | 'error'：WebSocket的Error事件。 |
| callback | ErrorCallback | 是   | 回调函数。<br>常见错误码：200 |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';
import { BusinessError } from '@ohos.base';

let ws = webSocket.createWebSocket();
ws.on('error', (err: BusinessError) => {
  console.log("on error, error:" + JSON.stringify(err))
});
```

### on('dataEnd')<sup>11+</sup>

on(type: 'dataEnd', callback: Callback\<void\>): void

订阅WebSocket的数据接收结束事件，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   |       类型        | 必填 |                  说明                   |
| -------- | ---------------- | ---- | --------------------------------------- |
| type     | string           | 是   | 'dataEnd'：WebSocket的数据接收结束事件。 |
| callback | Callback\<void\> | 是   | 回调函数。                              |

**示例：**

```ts
import webSocket from '@ohos.net.webSocket';

let ws = webSocket.createWebSocket();
ws.on('dataEnd', () => {
  console.log("on dataEnd")
});
```

## WebSocketCloseOptions

关闭WebSocket连接时，可选参数的类型和说明。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | 否   | 错误码，关闭WebSocket连接时的可选参数，可根据实际情况来填。默认值为1000。 |
| reason | string | 否   | 原因值，关闭WebSocket连接时的可选参数，可根据实际情况来填。默认值为空字符串（""）。 |

## CloseResult<sup>10+</sup>

关闭WebSocket连接时，订阅close事件得到的关闭结果。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | 是   | 错误码，订阅close事件得到的关闭连接的错误码。 |
| reason | string | 是   | 原因值，订阅close事件得到的关闭连接的错误原因。 |

## close错误码说明

发送给服务端的错误码可以自行定义，下面的列表仅供参考。

**系统能力**：SystemCapability.Communication.NetStack

| 值        | 说明               |
| :-------- | :----------------- |
| 1000      | 正常关闭           |
| 1001      | 服务器主动关闭     |
| 1002      | 协议错误           |
| 1003      | 无法处理的数据类型 |
| 1004~1015 | 保留值             |
