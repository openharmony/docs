# @ohos.net.webSocket    
使用WebSocket建立服务器与客户端的双向连接，需要先通过[createWebSocket](#websocketcreatewebsocket)方法创建[WebSocket](#websocket)对象，然后通过[connect](#connect)方法连接到服务器。  
当连接成功后，客户端会收到[open](#onopen)事件的回调，之后客户端就可以通过[send](#send)方法与服务器进行通信。  
当服务器发信息给客户端时，客户端会收到[message](#onmessage)事件的回调。当客户端不要此连接时，可以通过调用[close](#close)方法主动断开连接，之后客户端会收到[close](#onclose)事件的回调。  
  
若在上述任一过程中发生错误，客户端会收到[error](#onerror)事件的回调。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import webSocket from '@ohos.net.webSocket'    
```  
    
## createWebSocket    
创建一个WebSocket，里面包括建立连接、关闭连接、发送数据和订阅/取消订阅WebSocket连接的打开事件、接收到服务器消息事件、关闭事件和错误事件。  
 **调用形式：**     
- createWebSocket(): WebSocket  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| WebSocket | 返回一个WebSocket对象，里面包括connect、send、close、on和off方法。 |  
    
 **示例代码：**   
```js    
let ws: webSocket = webSocket.createWebSocket();    
```    
  
    
## WebSocketRequestOptions    
建立WebSocket连接时，可选参数的类型和说明。  
 **系统能力:**  SystemCapability.Communication.NetStack    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetStack    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| header | Object | false | false | 建立WebSocket连接可选参数，代表建立连接时携带的HTTP头信息。参数内容自定义，也可以不指定。 |  
    
## WebSocketCloseOptions    
关闭WebSocket连接时，可选参数的类型和说明。  
 **系统能力:**  SystemCapability.Communication.NetStack    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetStack    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| code | number | false | false | 错误码，关闭WebSocket连接时的可选参数，可根据实际情况来填。默认值为1000。 |  
| reason | string | false | false | 原因值，关闭WebSocket连接时的可选参数，可根据实际情况来填。默认值为空字符串（""）。 |  
    
## CloseResult<sup>(10+)</sup>    
关闭WebSocket连接时，订阅close事件得到的关闭结果。  
 **系统能力:**  SystemCapability.Communication.NetStack    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetStack    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| code<sup>(10+)</sup> | number | false | true | 错误码，订阅close事件得到的关闭连接的错误码。 |  
| reason<sup>(10+)</sup> | string | false | true |  原因值，订阅close事件得到的关闭连接的错误原因。 |  
    
## WebSocket    
在调用WebSocket的方法前，需要先通过[webSocket.createWebSocket](#websocketcreatewebsocket)创建一个WebSocket。  
 **系统能力:**  SystemCapability.Communication.NetStack    
### connect    
根据URL地址，建立一个WebSocket连接  
 **调用形式：**     
    
- connect(url: string, callback: AsyncCallback\<boolean>): void    
起始版本： 6    
- connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void    
起始版本： 6    
- connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack  
 **需要权限：** ohos.permission.INTERNET    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| url | string | true | 建立WebSocket连接的URL地址。 |  
| options | WebSocketRequestOptions | true | 参考[WebSocketRequestOptions](#websocketrequestoptions)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | 以Promise形式返回建立连接的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 201 | Permission denied. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError } from '@ohos.base';  
  
let ws = webSocket.createWebSocket();  
let url = "ws://"  
ws.connect(url, (err: BusinessError, value: boolean) => {  
  if (!err) {  
    console.log("connect success");  
  } else {  
    console.log("connect fail, err:" + JSON.stringify(err))  
  }  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError } from '@ohos.base';  
  
let ws = webSocket.createWebSocket();  
let header: Map<string, string>  
header.set("key", "value")  
header.set("key2", "value2")  
let url = "ws://"  
ws.connect(url, header as webSocket.WebSocketRequestOptions, (err: BusinessError, value: Object) => {  
  if (!err) {  
    console.log("connect success");  
  } else {  
    console.log("connect fail, err:" + JSON.stringify(err))  
  }  
});  
    
```    
  
    
### send    
通过WebSocket连接发送数据  
 **调用形式：**     
    
- send(data: string | ArrayBuffer, callback: AsyncCallback\<boolean>): void    
起始版本： 6    
- send(data: string | ArrayBuffer): Promise\<boolean>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack  
 **需要权限：** ohos.permission.INTERNET    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | string | true | 发送的数据。<br>API 6及更早版本仅支持string类型。API 8起同时支持string和ArrayBuffer类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | 以Promise形式返回发送数据的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 201 | Permission denied. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
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
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
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
  
    
### close    
关闭WebSocket连接  
 **调用形式：**     
    
- close(callback: AsyncCallback\<boolean>): void    
起始版本： 6    
- close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void    
起始版本： 6    
- close(options?: WebSocketCloseOptions): Promise\<boolean>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack  
 **需要权限：** ohos.permission.INTERNET    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | WebSocketCloseOptions | true | 参考[WebSocketCloseOptions](#websocketcloseoptions)。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<boolean> | 以Promise形式返回关闭连接的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 201 | Permission denied. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
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
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError } from '@ohos.base';  
  
let ws = webSocket.createWebSocket();  
  
let options: webSocket.WebSocketCloseOptions  
options.code = 1000  
options.reason = "your reason"  
ws.close(options, (err: BusinessError) => {  
  if (!err) {  
    console.log("close success")  
  } else {  
    console.log("close fail, err is " + JSON.stringify(err))  
  }  
});  
    
```    
  
    
### on('open')    
订阅WebSocket的打开事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'open', callback: AsyncCallback\<Object>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 'open'：WebSocket的打开事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError, Callback } from '@ohos.base';  
  
let ws= webSocket.createWebSocket();  
class OutValue {  
  status: number = 0  
  message: string = ""  
}  
ws.on('open', (err: BusinessError, value: OutValue) => {  
  console.log("on open, status:" + value.status + ", message:" + value.message);  
});  
    
```    
  
    
### off('open')    
取消订阅WebSocket的打开事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'open', callback?: AsyncCallback\<Object>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  'open'：WebSocket的打开事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError } from '@ohos.base';  
  
let ws = webSocket.createWebSocket();  
class OutValue {  
  status: number = 0  
  message: string = ""  
}  
let callback1 = (err: BusinessError, value: OutValue) => {  
  console.log("on open, status:" + value.status + ", message:" + value.message);  
}  
ws.on('open', callback1);  
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅  
ws.off('open', callback1);  
    
```    
  
    
### on('message')    
订阅WebSocket的接收到服务器消息事件，使用callback方式作为异步方法。每个消息最大长度为4K，超过4K自动分片。  
 **调用形式：**     
    
- on(type: 'message', callback: AsyncCallback\<string | ArrayBuffer>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 'message'：WebSocket的接收到服务器消息事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError } from '@ohos.base';  
  
let ws = webSocket.createWebSocket();  
ws.on('message', (err: BusinessError, value: string) => {  
  console.log("on message, message:" + value);  
});  
    
```    
  
    
### off('message')    
取消订阅WebSocket的接收到服务器消息事件，使用callback方式作为异步方法。每个消息最大长度为4K，超过4K自动分片。  
 **调用形式：**     
    
- off(type: 'message', callback?: AsyncCallback\<string | ArrayBuffer>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  'message'：WebSocket的接收到服务器消息事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';  
let ws = webSocket.createWebSocket();ws.off('message');    
```    
  
    
### on('close')    
订阅WebSocket的关闭事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'close', callback: AsyncCallback\<CloseResult>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 'close'：WebSocket的关闭事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br>close：close错误码，reason：错误码说明 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError } from '@ohos.base';  
  
let ws = webSocket.createWebSocket();  
ws.on('close', (err: BusinessError, value: webSocket.CloseResult) => {  
  console.log("on close, code is " + value.code + ", reason is " + value.reason);  
});  
    
```    
  
    
### off('close')    
取消订阅WebSocket的关闭事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'close', callback?: AsyncCallback\<CloseResult>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 'close'：WebSocket的关闭事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br>close：close错误码，reason：错误码说明 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';  
let ws = webSocket.createWebSocket();ws.off('close');    
```    
  
    
### on('error')    
订阅WebSocket的Error事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'error', callback: ErrorCallback): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  'error'：WebSocket的Error事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br>常见错误码：200 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError } from '@ohos.base';  
  
let ws = webSocket.createWebSocket();  
ws.on('error', (err: BusinessError) => {  
  console.log("on error, error:" + JSON.stringify(err))  
});  
    
```    
  
    
### off('error')    
取消订阅WebSocket的Error事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'error', callback?: ErrorCallback): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  'error'：WebSocket的Error事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
### on('dataEnd')<sup>(11+)</sup>    
订阅WebSocket的数据接收结束事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'dataEnd', callback: Callback\<void>): void    
起始版本： 11  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 'dataEnd'：WebSocket的数据接收结束事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';  
import { BusinessError } from '@ohos.base';  
  
let ws = webSocket.createWebSocket();  
ws.on('dataEnd', (err: BusinessError) => {  
  console.log("on dataEnd, error:" + JSON.stringify(err))  
});  
    
```    
  
    
### off('dataEnd')<sup>(11+)</sup>    
取消订阅WebSocket的数据接收结束事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'dataEnd', callback?: Callback\<void>): void    
起始版本： 11  
  
 **系统能力:**  SystemCapability.Communication.NetStack    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 'dataEnd'：WebSocket的数据接收结束事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
示例callback：  
```js    
import webSocket from '@ohos.net.webSocket';let ws = webSocket.createWebSocket();ws.off('dataEnd');    
```    
  
