# @ohos.net.webSocket (WebSocket连接)

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


使用WebSocket建立服务器与客户端的双向连接，需要先通过[createWebSocket](#websocketcreatewebsocket6)方法创建[WebSocket](#websocket6)对象，然后通过[connect](#connect6)方法连接到服务器。
当连接成功后，客户端会收到[open](#onopen6)事件的回调，之后客户端就可以通过[send](#send6)方法与服务器进行通信。
当服务器发信息给客户端时，客户端会收到[message](#onmessage6)事件的回调。当客户端不要此连接时，可以通过调用[close](#close6)方法主动断开连接，之后客户端会收到[close](#onclose6)事件的回调。

若在上述任一过程中发生错误，客户端会收到[error](#onerror6)事件的回调。

## 导入模块

```ts
import { webSocket } from '@kit.NetworkKit';
```

## 完整示例

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
ws.on('message',(error: BusinessError, value: string | ArrayBuffer) => {
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
ws.connect(defaultIpAddress, {
  header:{
      name1: 'value1',
      name2: 'value2',
      name3: 'value3'
  },
  proxy: {
      host: '192.168.0.150',
      port: 8888,
      exclusionList: []
  },
  protocol: 'my-protocol',
  }, (err: BusinessError, value: boolean) => {
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

## webSocket.createWebSocket<sup>6+</sup>

createWebSocket(): WebSocket

创建一个WebSocket，里面包括建立连接、关闭连接、发送数据和订阅/取消订阅WebSocket连接的打开事件、接收到服务器消息事件、关闭事件和错误事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**返回值：**

| 类型                                | 说明                                                         |
| :---------------------------------- | :----------------------------------------------------------- |
| [WebSocket](#websocket6) | 返回一个WebSocket对象，里面包括connect、send、close、on和off方法。 |

**示例：**

```ts
let ws: webSocket.WebSocket = webSocket.createWebSocket();
```

## WebSocket<sup>6+</sup>

在调用WebSocket的方法前，需要先通过[webSocket.createWebSocket](#websocketcreatewebsocket6)创建一个WebSocket。

### connect<sup>6+</sup>

connect(url: string, callback: AsyncCallback\<boolean\>): void

根据URL地址，建立一个WebSocket连接，使用callback方式作为异步方法。

> **说明：**
> 可通过监听error事件获得该接口的执行结果，错误发生时会得到错误码：200。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**注意：**URL地址长度不能超过1024个字符，否则会连接失败。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                         |
| -------- | ------------------------ | ---- | ---------------------------- |
| url      | string                   | 是   | 建立WebSocket连接的URL地址。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。                   |

**错误码：**

| 错误码ID              | 错误信息                                   |
| --------------------- | ------------------------------------------ |
| 401                   | Parameter error.                           |
| 201                   | Permission denied.                         |
| 2302001<sup>12+</sup> | Websocket url error.                       |
| 2302002<sup>12+</sup> | Websocket certificate file does not exist. |
| 2302003<sup>12+</sup> | Websocket connection already exists.       |
| 2302998<sup>12+</sup> | It is not allowed to access this domain.   |
| 2302999<sup>10+</sup> | Websocket other unknown error.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[webSocket错误码](errorcode-net-webSocket.md)。

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
let url = "ws://";
ws.connect(url, (err: BusinessError, value: boolean) => {
  if (!err) {
    console.log("connect success");
  } else {
    console.log("connect fail, err:" + JSON.stringify(err));
  }
});
```

### connect<sup>6+</sup>

connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean\>): void

根据URL地址和header，建立一个WebSocket连接，使用callback方式作为异步方法。

> **说明：**
> 可通过监听error事件获得该接口的执行结果，错误发生时会得到错误码：200。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**注意：**URL地址长度不能超过1024个字符，否则会连接失败。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                    |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| url      | string                   | 是   | 建立WebSocket连接的URL地址。                            |
| options  | WebSocketRequestOptions  | 是   | 参考[WebSocketRequestOptions](#websocketrequestoptions)。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。                                              |

**错误码：**

| 错误码ID              | 错误信息                                   |
| --------------------- | ------------------------------------------ |
| 401                   | Parameter error.                           |
| 201                   | Permission denied.                         |
| 2302001<sup>12+</sup> | Websocket url error.                       |
| 2302002<sup>12+</sup> | Websocket certificate file does not exist. |
| 2302003<sup>12+</sup> | Websocket connection already exists.       |
| 2302998<sup>12+</sup> | It is not allowed to access this domain.   |
| 2302999<sup>10+</sup> | Websocket other unknown error.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[webSocket错误码](errorcode-net-webSocket.md)。

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
let options: webSocket.WebSocketRequestOptions | undefined;
if (options !=undefined) {
  options.header = {
     name1: "value1",
     name2: "value2",
     name3: "value3"
  };
  options.caPath = "";
}
let url = "ws://"
ws.connect(url, options, (err: BusinessError, value: Object) => {
  if (!err) {
    console.log("connect success");
  } else {
    console.log("connect fail, err:" + JSON.stringify(err))
  }
});
```

### connect<sup>6+</sup>

connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean\>

根据URL地址和header，建立一个WebSocket连接，使用Promise方式作为异步方法。

> **说明：**
> 可通过监听error事件获得该接口的执行结果，错误发生时会得到错误码：200。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**注意：**URL地址长度不能超过1024个字符，否则会连接失败。

**参数：**

| 参数名  | 类型                    | 必填 | 说明                                                    |
| ------- | ----------------------- | ---- | ------------------------------------------------------- |
| url     | string                  | 是   | 建立WebSocket连接的URL地址。                            |
| options | WebSocketRequestOptions | 否   | 参考[WebSocketRequestOptions](#websocketrequestoptions)。 |

**返回值：**

| 类型               | 说明                              |
| :----------------- | :-------------------------------- |
| Promise\<boolean\> | 以Promise形式返回建立连接的结果。 |

**错误码：**

| 错误码ID              | 错误信息                                   |
| --------------------- | ------------------------------------------ |
| 401                   | Parameter error.                           |
| 201                   | Permission denied.                         |
| 2302001<sup>12+</sup> | Websocket url error.                       |
| 2302002<sup>12+</sup> | Websocket certificate file does not exist. |
| 2302003<sup>12+</sup> | Websocket connection already exists.       |
| 2302998<sup>12+</sup> | It is not allowed to access this domain.   |
| 2302999<sup>10+</sup> | Websocket other unknown error.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[webSocket错误码](errorcode-net-webSocket.md)。

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
let url = "ws://"
let promise = ws.connect(url);
promise.then((value: boolean) => {
  console.log("connect success")
}).catch((err:string) => {
  console.log("connect fail, error:" + JSON.stringify(err))
});
```

### send<sup>6+</sup>

send(data: string | ArrayBuffer, callback: AsyncCallback\<boolean\>): void

通过WebSocket连接发送数据，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
let url = "ws://"
class OutValue {
  status: number = 0
  message: string = ""
}
ws.connect(url, (err: BusinessError, value: boolean) => {
    if (!err) {
      console.log("connect success");
    } else {
      console.log("connect fail, err:" + JSON.stringify(err))
    }
});
ws.on('open', (err: BusinessError, value: Object) => {
  console.log("on open, status:" + (value as OutValue).status + ", message:" + (value as OutValue).message);
    ws.send("Hello, server!", (err: BusinessError, value: boolean) => {
    if (!err) {
      console.log("send success");
    } else {
      console.log("send fail, err:" + JSON.stringify(err))
    }
  });
});
```

> **说明**
>
> send接口必须在监听到open事件后才可以调用。

### send<sup>6+</sup>

send(data: string | ArrayBuffer): Promise\<boolean\>

通过WebSocket连接发送数据，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
let url = "ws://"
class OutValue {
  status: number = 0
  message: string = ""
}
ws.connect(url, (err: BusinessError, value: boolean) => {
    if (!err) {
      console.log("connect success");
    } else {
      console.log("connect fail, err:" + JSON.stringify(err))
    }
});

ws.on('open', (err: BusinessError, value: Object) => {
  console.log("on open, status:" + (value as OutValue).status + ", message:" + (value as OutValue).message);
  let promise = ws.send("Hello, server!");
  promise.then((value: boolean) => {
    console.log("send success")
  }).catch((err:string) => {
    console.log("send fail, error:" + JSON.stringify(err))
  });
});
```

> **说明**
>
> send接口必须在监听到open事件后才可以调用。

### close<sup>6+</sup>

close(callback: AsyncCallback\<boolean\>): void

关闭WebSocket连接，使用callback方式作为异步方法。

**需要权限**：ohos.permission.INTERNET

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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
import { webSocket } from '@kit.NetworkKit';

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

### on('open')<sup>6+</sup>

on(type: 'open', callback: AsyncCallback\<Object\>): void

订阅WebSocket的打开事件，使用callback方式作为异步方法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                          |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | 是   | 'open'：WebSocket的打开事件。 |
| callback | AsyncCallback\<Object\> | 是   | 回调函数。                    |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError, Callback } from '@kit.BasicServicesKit';

let ws= webSocket.createWebSocket();
class OutValue {
  status: number = 0
  message: string = ""
}
ws.on('open', (err: BusinessError, value: Object) => {
  console.log("on open, status:" + (value as OutValue).status + ", message:" + (value as OutValue).message);
});
```

### off('open')<sup>6+</sup>

off(type: 'open', callback?: AsyncCallback\<Object\>): void

取消订阅WebSocket的打开事件，使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                          |
| -------- | ----------------------- | ---- | ----------------------------- |
| type     | string                  | 是   | 'open'：WebSocket的打开事件。 |
| callback | AsyncCallback\<Object\> | 否   | 回调函数。                    |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
class OutValue {
  status: number = 0
  message: string = ""
}
let callback1 = (err: BusinessError, value: Object) => {
 console.log("on open, status:" + ((value as OutValue).status + ", message:" + (value as OutValue).message));
}
ws.on('open', callback1);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅
ws.off('open', callback1);
```

### on('message')<sup>6+</sup>

on(type: 'message', callback: AsyncCallback\<string | ArrayBuffer\>): void

订阅WebSocket的接收到服务器消息事件，使用callback方式作为异步方法。每个消息最大长度为4K，超过4K自动分片。

> **说明：**
> AsyncCallback中的数据可以是字符串(API 6)或ArrayBuffer(API 8)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                         |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | 是   | 'message'：WebSocket的接收到服务器消息事件。 |
| callback | AsyncCallback\<string \| ArrayBuffer <sup>8+</sup>\> | 是   | 回调函数。                                   |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
ws.on('message', (err: BusinessError<void>, value: string | ArrayBuffer) => {
  console.log("on message, message:" + value);
});
```

### off('message')<sup>6+</sup>

off(type: 'message', callback?: AsyncCallback\<string | ArrayBuffer\>): void

取消订阅WebSocket的接收到服务器消息事件，使用callback方式作为异步方法。每个消息最大长度为4K，超过4K自动分片。

> **说明：**
> AsyncCallback中的数据可以是字符串(API 6)或ArrayBuffer(API 8)。
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                         |
| -------- | --------------------------------------------------- | ---- | -------------------------------------------- |
| type     | string                                              | 是   | 'message'：WebSocket的接收到服务器消息事件。 |
| callback | AsyncCallback\<string \|ArrayBuffer <sup>8+</sup>\> | 否   | 回调函数。                                   |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('message');
```

### on('close')<sup>6+</sup>

on(type: 'close', callback: AsyncCallback\<CloseResult\>): void

订阅WebSocket的关闭事件，使用callback方式作为异步方法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | 是   | 'close'：WebSocket的关闭事件。 |
| callback | AsyncCallback\<CloseResult\> | 是   | 回调函数。<br>close：close错误码，reason：错误码说明 |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
ws.on('close', (err: BusinessError, value: webSocket.CloseResult) => {
  console.log("on close, code is " + value.code + ", reason is " + value.reason);
});
```

### off('close')<sup>6+</sup>

off(type: 'close', callback?: AsyncCallback\<CloseResult\>): void

取消订阅WebSocket的关闭事件，使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| type     | string                                          | 是   | 'close'：WebSocket的关闭事件。 |
| callback | AsyncCallback\<CloseResult\> | 否   | 回调函数。<br>close：close错误码，reason：错误码说明 |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('close');
```

### on('error')<sup>6+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅WebSocket的Error事件，使用callback方式作为异步方法。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                            |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | 是   | 'error'：WebSocket的Error事件。 |
| callback | ErrorCallback | 是   | 回调函数。<br>常见错误码：200 |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let ws = webSocket.createWebSocket();
ws.on('error', (err: BusinessError) => {
  console.log("on error, error:" + JSON.stringify(err))
});
```

### off('error')<sup>6+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅WebSocket的Error事件，使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   | 类型          | 必填 | 说明                            |
| -------- | ------------- | ---- | ------------------------------- |
| type     | string        | 是   | 'error'：WebSocket的Error事件。 |
| callback | ErrorCallback | 否   | 回调函数。                      |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('error');
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
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.on('dataEnd', () => {
  console.log("on dataEnd")
});
```

### off('dataEnd')<sup>11+</sup>

off(type: 'dataEnd', callback?: Callback\<void\>): void

取消订阅WebSocket的数据接收结束事件，使用callback方式作为异步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   |        类型       | 必填 |                说明                    |
| -------- | ---------------- | ---- | -------------------------------------- |
| type     | string           | 是   | 'dataEnd'：WebSocket的数据接收结束事件。|
| callback | Callback\<void\> | 否   | 回调函数。                             |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('dataEnd');
```

### on('headerReceive')<sup>12+</sup>

on(type: 'headerReceive', callback: Callback\<ResponseHeaders\>): void

订阅HTTP Response Header事件，使用callback方式作为同步方法。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   |        类型       | 必填 |                说明                    |
| -------- | ---------------- | ---- | -------------------------------------- |
| type     | string           | 是   | 'headerReceive'：WebSocket的headerReceive事件。|
| callback | Callback\<ResponseHeaders\> | 是   | 回调函数,返回订阅事件。                             |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.on('headerReceive', (data) => {
  console.log("on headerReceive " + JSON.stringify(data));
});
```

### off('headerReceive')<sup>12+</sup>

off(type: 'headerReceive', callback?: Callback\<ResponseHeaders\>): void

取消订阅HTTP Response Header事件，使用callback方式作为同步方法。

> **说明：**
> 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。

**系统能力**：SystemCapability.Communication.NetStack

**参数：**

| 参数名   |        类型       | 必填 |                说明                    |
| -------- | ---------------- | ---- | -------------------------------------- |
| type     | string           | 是   | 'headerReceive'：WebSocket的headerReceive事件。|
| callback | Callback\<ResponseHeaders\> | 否   | 回调函数,返回订阅事件。                           |

**示例：**

```ts
import { webSocket } from '@kit.NetworkKit';

let ws = webSocket.createWebSocket();
ws.off('headerReceive');
```

## WebSocketRequestOptions

建立WebSocket连接时，可选参数的类型和说明。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型 |  只读  | 可选 | 说明                                                         |
| ------ | ------ |------ | ---- | ------------------------------------------------------------ |
| header | Object |  否  |  是   | 建立WebSocket连接可选参数，代表建立连接时携带的HTTP头信息。参数内容自定义，也可以不指定。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| caPath<sup>11+</sup> | string |  否  |  是  | 如果设置了此参数，系统将使用用户指定路径的CA证书，(开发者需保证该路径下CA证书的可访问性)，否则将使用系统预设CA证书，系统预设CA证书位置：/etc/ssl/certs/cacert.pem。证书路径为沙箱映射路径（开发者可通过Global.getContext().filesDir获取应用沙箱路径）。目前仅支持格式为pem的文本证书。 |
| clientCert<sup>11+</sup> | [ClientCert](#clientcert11) |   否  |  是   | 支持传输客户端证书。 |
| proxy<sup>12+</sup> | ProxyConfiguration |  否  | 是 | 通信过程中的代理信息，默认使用系统网络代理。 |
| protocol<sup>12+</sup> | string |  否  | 是 | 自定义Sec-WebSocket-Protocol字段，默认为""。              |

## ClientCert<sup>11+</sup>

客户端证书类型。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| certPath   | string  | 是   | 证书路径。 |
| keyPath | string | 是   | 证书秘钥的路径。 |
| keyPassword | string | 否   | 证书秘钥的密码。 |

## ProxyConfiguration<sup>12+</sup>
type ProxyConfiguration = 'system' | 'no-proxy' | HttpProxy

网络代理配置信息

**系统能力**：SystemCapability.Communication.NetStack

|  类型   | 说明                      |
| ------  |------------------------- |
| 'system'   |  使用系统默认网络代理。 |
| 'no-proxy' |  不使用网络代理。 |
| [HttpProxy](js-apis-net-connection.md#httpproxy10)  | 使用指定的网络代理。 |

## WebSocketCloseOptions

关闭WebSocket连接时，可选参数的类型和说明。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | 否   | 错误码，关闭WebSocket连接时的可选参数，可根据实际情况来填。默认值为1000。 |
| reason | string | 否   | 原因值，关闭WebSocket连接时的可选参数，可根据实际情况来填。默认值为空字符串（""）。 |

## CloseResult<sup>10+</sup>

关闭WebSocket连接时，订阅close事件得到的关闭结果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetStack

| 名称 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| code   | number | 是   | 错误码，订阅close事件得到的关闭连接的错误码。 |
| reason | string | 是   | 原因值，订阅close事件得到的关闭连接的错误原因。 |

## ResponseHeaders<sup>12+</sup>
type ResponseHeaders = {[k: string]: string | string[] | undefined;}

服务器发送的响应头。

**系统能力**：SystemCapability.Communication.NetStack

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| {[k:string]:string \| string[] \| undefined} | header数据类型为键值对、字符串或者undefined |

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
