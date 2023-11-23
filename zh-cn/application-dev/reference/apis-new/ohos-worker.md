# @ohos.worker    
Worker是与主线程并行的独立线程。创建Worker的线程称之为宿主线程，Worker自身的线程称之为Worker线程。创建Worker传入的url文件在Worker线程中执行，可以处理耗时操作但不可以直接操作UI。<span style="letter-spacing: 0px;">Worker主要作用是为应用程序提供一个多线程的运行环境，可满足应用程序在执行过程中与主线程分离，在后台线程中运行一个脚本操作耗时操作，极大避免类似于计算密集型或高延迟的任务阻塞主线程的运行。由于Worker一旦被创建则不会主动被销毁，若不处于任务状态一直运行，在一定程度上会造成资源的浪费，应及时关闭空闲的Worker。</span>  
Worker的上下文对象和主线程的上下文对象是不同的，Worker线程不支持UI操作。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import worker from '@ohos.worker'    
```  
    
## WorkerOptions    
Worker构造函数的选项信息，用于为Worker添加其他信息。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | 'classic' \| 'module' | false | false | Worker执行脚本的模式类型，暂不支持module类型，默认值为"classic"。 |  
| name | string | false | false | Worker的名称，默认值为 undefined 。 |  
| shared | boolean | false | false | 表示Worker共享功能，此接口暂不支持。 |  
    
## Event    
事件类。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | string | true | true | 指定事件的类型。 |  
| timeStamp | number | true | true | 事件创建时的时间戳（精度为毫秒），暂未支持。 |  
    
## ErrorEvent    
错误事件类，用于表示Worker执行过程中出现异常的详细信息，ErrorEvent类继承[Event](#event)。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| message | string | true | true | 异常发生的错误信息。 |  
| filename | string | true | true | 出现异常所在的文件。 |  
| lineno | number | true | true | 异常所在的行数。 |  
| colno | number | true | true | 异常所在的列数。 |  
| error | Object | true | true | 异常类型。 |  
    
## MessageEvent    
消息类，持有Worker线程间传递的数据。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| data | T | true | true | 线程间传递的数据。 |  
    
## MessageEvents<sup>(9+)</sup>    
消息类，持有Worker线程间传递的数据。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| data<sup>(9+)</sup> |  | true | true | 线程间传递的数据。 |  
    
## PostMessageOptions    
明确数据传递过程中需要转移所有权对象的类，传递所有权的对象必须是ArrayBuffer，发送它的上下文中将会变为不可用，仅在接收方可用。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| transfer | Object[] | false | false | ArrayBuffer数组，用于传递所有权。该数组中不可传入null。 |  
    
## EventListener<sup>(deprecated)</sup>    
事件监听类。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.WorkerEventListener替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### null<sup>(deprecated)</sup>    
回调的事件类。  
 **调用形式：**     
- (evt: Event): void | Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.WorkerEventListener.(event:。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| evt<sup>(deprecated)</sup> | Event | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| void | Promise<void> | 无返回值或者以Promise形式返回。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.addEventListener("alert", ()=>{    console.log("alert listener callback");})    
```    
  
    
## WorkerEventListener<sup>(9+)</sup>    
事件监听类。  
 **系统能力:**  SystemCapability.Utils.Lang    
### null<sup>(9+)</sup>  
 **调用形式：**     
    
- (event: Event): void | Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | Event | true | 事件监听类。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| void | Promise<void> | 无返回值或者以Promise形式返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200005 | The invoked API is not supported in workers. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.addEventListener("alert", ()=>{    console.log("alert listener callback");})    
```    
  
    
## MessageType  
 **系统能力:**  SystemCapability.Utils.Lang    
    
| 取值范围 | 说明 |  
| --------| --------|  
| message |  |  
| messageerror |  |  
    
## EventTarget<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.WorkerEventTarget替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### addEventListener<sup>(deprecated)</sup>    
向Worker添加一个事件监听，该接口与[on<sup>(deprecated)</sup>](#ondeprecated)接口功能一致。  
 **调用形式：**     
- addEventListener(type: string, listener: EventListener): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.WorkerEventTarget.addEventListener。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 监听的事件类型。 |  
| listener<sup>(deprecated)</sup> | EventListener | true | 回调的事件。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.addEventListener("alert", ()=>{    console.log("alert listener callback");})    
```    
  
    
### dispatchEvent<sup>(deprecated)</sup>    
分发定义在Worker的事件。  
 **调用形式：**     
- dispatchEvent(event: Event): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.WorkerEventTarget.dispatchEvent。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(deprecated)</sup> | Event | true | 需要分发的事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 分发的结果，false表示分发失败。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");  
workerInstance.dispatchEvent({type:"eventType", timeStamp:0}); //timeStamp暂未支持。```分发事件（dispatchEvent）可与监听接口（on、once、addEventListener）搭配使用，示例如下：<span style="letter-spacing: 0px;">const workerInstance = new worker.Worker("workers/worker.ts");</span>  
  
//用法一:workerInstance.on("alert_on", (e)=>{    console.log("alert listener callback");})workerInstance.once("alert_once", (e)=>{    console.log("alert listener callback");})workerInstance.addEventListener("alert_add", (e)=>{    console.log("alert listener callback");})  
//once接口创建的事件执行一次便会删除。workerInstance.dispatchEvent({type:"alert_once", timeStamp:0});//timeStamp暂未支持。//on接口创建的事件可以一直被分发，不能主动删除。workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});//addEventListener接口创建的事件可以一直被分发，不能主动删除。workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});  
//用法二://event类型的type支持自定义，同时存在"message"/"messageerror"/"error"特殊类型，如下所示//当type = "message"，onmessage接口定义的方法同时会执行。//当type = "messageerror"，onmessageerror接口定义的方法同时会执行。//当type = "error"，onerror接口定义的方法同时会执行。//若调用removeEventListener接口或者off接口取消事件时，能且只能取消使用addEventListener/on/once创建的事件。  
workerInstance.addEventListener("message", (e)=>{    console.log("message listener callback");})workerInstance.onmessage = function(e) {    console.log("onmessage : message listener callback");}//调用dispatchEvent分发“message”事件，addEventListener和onmessage中定义的方法都会被执行。workerInstance.dispatchEvent({type:"message", timeStamp:0});    
```    
  
    
### removeEventListener<sup>(deprecated)</sup>    
删除Worker的事件监听，该接口与[off<sup>(deprecated)</sup>](#offdeprecated)接口功能一致。  
 **调用形式：**     
- removeEventListener(type: string, callback?: EventListener): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.WorkerEventTarget.removeEventListener。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 需要删除的监听事件类型。 |  
| callback<sup>(deprecated)</sup> | EventListener | false | 删除的回调事件。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.addEventListener("alert", ()=>{    console.log("alert listener callback");})workerInstance.removeEventListener("alert");    
```    
  
    
### removeAllListener<sup>(deprecated)</sup>    
删除Worker所有的事件监听。  
 **调用形式：**     
- removeAllListener(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.WorkerEventTarget.removeAllListener。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.addEventListener("alert", (e)=>{    console.log("alert listener callback");})workerInstance.removeAllListener();    
```    
  
    
## WorkerEventTarget<sup>(9+)</sup>    
处理Worker监听事件。  
 **系统能力:**  SystemCapability.Utils.Lang    
### addEventListener<sup>(9+)</sup>    
向Worker添加一个事件监听，该接口与[on<sup>9+</sup>](#on9)接口功能一致。  
 **调用形式：**     
- addEventListener(type: string, listener: WorkerEventListener): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听的事件类型。 |  
| listener | WorkerEventListener | true | 回调的事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200005 | The invoked API is not supported in workers. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.addEventListener("alert", (e)=>{    console.log("alert listener callback");})    
```    
  
    
### dispatchEvent<sup>(9+)</sup>    
分发定义在Worker的事件。  
 **调用形式：**     
- dispatchEvent(event: Event): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | Event | true | 需要分发的事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 分发的结果，false表示分发失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | orker instance is not running. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");  
workerInstance.dispatchEvent({type:"eventType", timeStamp:0}); //timeStamp暂未支持。```分发事件（dispatchEvent）可与监听接口（on、once、addEventListener）搭配使用，示例如下：import worker, { MessageEvents } from '@ohos.worker';  
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");  
//用法一:workerInstance.on("alert_on", (e)=>{    console.log("alert listener callback");})workerInstance.once("alert_once", (e)=>{    console.log("alert listener callback");})workerInstance.addEventListener("alert_add", (e)=>{    console.log("alert listener callback");})  
//once接口创建的事件执行一次便会删除。workerInstance.dispatchEvent({type:"alert_once", timeStamp:0});//timeStamp暂未支持。//on接口创建的事件可以一直被分发，不能主动删除。workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});//addEventListener接口创建的事件可以一直被分发，不能主动删除。workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});  
//用法二://event类型的type支持自定义，同时存在"message"/"messageerror"/"error"特殊类型，如下所示//当type = "message"，onmessage接口定义的方法同时会执行。//当type = "messageerror"，onmessageerror接口定义的方法同时会执行。//当type = "error"，onerror接口定义的方法同时会执行。//若调用removeEventListener接口或者off接口取消事件时，能且只能取消使用addEventListener/on/once创建的事件。  
workerInstance.addEventListener("message", (e)=>{    console.log("message listener callback");})workerInstance.onmessage = (e: MessageEvents): void => {    console.log("onmessage : message listener callback");}//调用dispatchEvent分发“message”事件，addEventListener和onmessage中定义的方法都会被执行。workerInstance.dispatchEvent({type:"message", timeStamp:0});    
```    
  
    
### removeEventListener<sup>(9+)</sup>    
删除Worker的事件监听，该接口与[off<sup>9+</sup>](#off9)接口功能一致。  
 **调用形式：**     
    
- removeEventListener(type: string, callback?: WorkerEventListener): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 需要删除的监听事件类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调的事件。删除的回调事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.addEventListener("alert", (e)=>{    console.log("alert listener callback");})workerInstance.removeEventListener("alert");    
```    
  
    
### removeAllListener<sup>(9+)</sup>    
删除Worker所有的事件监听。  
 **调用形式：**     
- removeAllListener(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200004 | Worker instance is not running. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.addEventListener("alert", (e)=>{    console.log("alert listener callback");})workerInstance.removeAllListener();    
```    
  
    
## WorkerGlobalScope<sup>(deprecated)</sup>    
Worker线程自身的运行环境，WorkerGlobalScope类继承[EventTarget](#eventtargetdeprecated)。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.GlobalScope替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.GlobalScope.name替代。系统能力：SystemCapability.Utils.Lang<br>Worker的名字，newWorker时指定。 |  
| onerror<sup>(deprecated)</sup> | (ev: ErrorEvent) => void | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.GlobalScope.onerror替代。系统能力：SystemCapability.Utils.Lang<br>WorkerGlobalScope的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在Worker线程中执行。 |  
| self | WorkerGlobalScope & typeof globalThis | true | true | WorkerGlobalScope本身。 |  
    
## GlobalScope<sup>(9+)</sup>    
Worker线程自身的运行环境，GlobalScope类继承[WorkerEventTarget](#workereventtarget9)。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(9+)</sup> | string | true | true | Worker的名字，newWorker时指定。 |  
| onerror<sup>(9+)</sup> | (ev: ErrorEvent) => void | false | false | GlobalScope的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在Worker线程中执行。 |  
| self<sup>(9+)</sup> | GlobalScope & typeof globalThis | true | true | GlobalScope本身。 |  
    
## DedicatedWorkerGlobalScope<sup>(deprecated)</sup>    
Worker线程用于与宿主线程通信的类，通过postMessage接口发送消息给宿主线程、close接口销毁Worker线程。DedicatedWorkerGlobalScope类继承[WorkerGlobalScope](#workerglobalscopedeprecated)。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.ThreadWorkerGlobalScope替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onmessage<sup>(deprecated)</sup> | (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.ThreadWorkerGlobalScope.onmessage替代。 |  
| onmessageerror<sup>(deprecated)</sup> | (this: DedicatedWorkerGlobalScope, ev: MessageEvent) => void | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.ThreadWorkerGlobalScope.onmessageerror替代。 |  
    
### close<sup>(deprecated)</sup>  
 **调用形式：**     
- close(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.ThreadWorkerGlobalScope.close。  
 **系统能力:**  SystemCapability.Utils.Lang    
### postMessage<sup>(deprecated)</sup>    
Worker线程通过转移对象所有权的方式向宿主线程发送消息。  
 **调用形式：**     
- postMessage(messageObject: Object, transfer: Transferable[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.ThreadWorkerGlobalScope.postMessage。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| messageObject<sup>(deprecated)</sup> | Object | true | 发送至宿主线程的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |  
| transfer<sup>(deprecated)</sup> | Transferable[] | true | 表示可转移的ArrayBuffer实例对象数组，该数组中对象的所有权会被转移到宿主线程，在Worker线程中将会变为不可用，仅在宿主线程中可用，数组不可传入null。 |  
    
 **示例代码1：**   
```ts    
// main threadimport worker, { MessageEvents } from '@ohos.worker';  
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.postMessage("hello world");workerInstance.onmessage = (e: MessageEvents): void => {    // let data = e.data;    console.log("receive data from worker.ts");}    
```    
  
    
 **示例代码2：**   
```ts    
import worker, { MessageEvents } from '@ohos.worker';  
const workerPort = worker.workerPort;workerPort.onmessage = (e: MessageEvents): void => {    // let data = e.data;    let buffer = new ArrayBuffer(5)    workerPort.postMessage(buffer, [buffer]);}    
```    
  
    
### postMessage    
Worker线程通过转移对象所有权的方式向宿主线程发送消息。  
 **调用形式：**     
- postMessage(messageObject: Object, options?: PostMessageOptions): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| messageObject | Object | true | 发送至宿主线程的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |  
| options | PostMessageOptions | false | 当填入该参数时，与传入ArrayBuffer[]的作用一致，该数组中对象的所有权会被转移到宿主线程，在Worker线程中将会变为不可用，仅在宿主线程中可用。<br/>若不填入该参数，默认设置为 undefined，通过拷贝数据的方式传输信息到宿主线程。 |  
    
 **示例代码1：**   
```ts    
// main threadimport worker, { MessageEvents } from '@ohos.worker';  
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.postMessage("hello world");workerInstance.onmessage = (e: MessageEvents): void => {    // let data = e.data;    console.log("receive data from worker.ts");}    
```    
  
    
 **示例代码2：**   
```ts    
import worker, { MessageEvents } from '@ohos.worker';  
const parentPort = worker.parentPort;parentPort.onmessage = (e: MessageEvents): void => {    // let data = e.data;    parentPort.postMessage("receive data from main thread");}    
```    
  
    
### postMessage<sup>(deprecated)</sup>    
Worker线程通过转移对象所有权的方式向宿主线程发送消息。  
 **调用形式：**     
- postMessage(messageObject: Object, transfer: ArrayBuffer[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| messageObject<sup>(deprecated)</sup> | Object | true | 发送至宿主线程的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |  
| transfer<sup>(deprecated)</sup> | ArrayBuffer[] | true | 表示可转移的ArrayBuffer实例对象数组，该数组中对象的所有权会被转移到宿主线程，在Worker线程中将会变为不可用，仅在宿主线程中可用，数组不可传入null。 |  
    
 **示例代码：**   
```ts    
// main threadimport worker, { MessageEvents } from '@ohos.worker';  
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.postMessage("hello world");workerInstance.onmessage = (e: MessageEvents): void => {    // let data = e.data;    console.log("receive data from worker.ts");}``````ts// worker.tsimport worker, { MessageEvents } from '@ohos.worker';  
const workerPort = worker.workerPort;workerPort.onmessage = (e: MessageEvents): void => {    // let data = e.data;    let buffer = new ArrayBuffer(5)    workerPort.postMessage(buffer, [buffer]);}    
```    
  
    
## ThreadWorkerGlobalScope<sup>(9+)</sup>    
Worker线程用于与宿主线程通信的类，通过postMessage接口发送消息给宿主线程、close接口销毁Worker线程。ThreadWorkerGlobalScope类继承[GlobalScope<sup>9+</sup>](#globalscope9)。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onmessage<sup>(9+)</sup> | (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void | false | false |  |  
| onmessageerror<sup>(9+)</sup> | (this: ThreadWorkerGlobalScope, ev: MessageEvents) => void | false | false |  |  
    
### close<sup>(9+)</sup>    
销毁Worker线程，终止Worker接收消息。  
 **调用形式：**     
- close(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200004 |  |  
    
 **示例代码：**   
```ts    
// main threadimport worker from '@ohos.worker';const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");  
// worker.tsimport worker, { MessageEvents } from '@ohos.worker';  
const workerPort = worker.workerPort;workerPort.onmessage = (e: MessageEvents): void => {    workerPort.close()}    
```    
  
    
### postMessage<sup>(9+)</sup>    
Worker线程通过转移对象所有权的方式向宿主线程发送消息。  
 **调用形式：**     
- postMessage(messageObject: Object, transfer: ArrayBuffer[]): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| messageObject | Object | true | 发送至宿主线程的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |  
| transfer | ArrayBuffer[] | true | 表示可转移的ArrayBuffer实例对象数组，该数组中对象的所有权会被转移到宿主线程，在Worker线程中将会变为不可用，仅在宿主线程中可用，数组不可传入null。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200006 | An exception occurred during serialization. |  
    
 **示例代码1：**   
```ts    
// main threadimport worker, { MessageEvents } from '@ohos.worker';  
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.postMessage("hello world");workerInstance.onmessage = (e: MessageEvents): void => {    console.log("receive data from worker.ts");}    
```    
  
    
 **示例代码2：**   
```ts    
// worker.tsimport worker, { MessageEvents } from '@ohos.worker';  
const workerPort = worker.workerPort;workerPort.onmessage = (e: MessageEvents): void => {    let buffer = new ArrayBuffer(8);    workerPort.postMessage(buffer, [buffer]);}    
```    
  
    
### postMessage<sup>(9+)</sup>    
Worker线程通过转移对象所有权的方式向宿主线程发送消息。  
 **调用形式：**     
- postMessage(messageObject: Object, options?: PostMessageOptions): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| messageObject | Object | true | 发送至宿主线程的数据，该数据对象必须是可序列化，序列化支持类型见 |  
| options | PostMessageOptions | false | 当填入该参数时，与传入ArrayBuffer[]的作用一致，该数组中对象的所有权会被转移到宿主线程，在Worker线程中将会变为不可用，仅在宿主线程中可用。<br/>若不填入该参数，默认设置为 undefined，通过拷贝数据的方式传输信息到宿主线程。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200006 | An exception occurred during serialization. |  
    
 **示例代码1：**   
```ts    
// main threadimport worker, { MessageEvents } from '@ohos.worker';  
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.postMessage("hello world");workerInstance.onmessage = (e: MessageEvents): void => {    console.log("receive data from worker.ts");}    
```    
  
    
 **示例代码2：**   
```ts    
import worker, { MessageEvents } from '@ohos.worker';  
const workerPort = worker.workerPort;workerPort.onmessage = (e: MessageEvents): void => {    workerPort.postMessage("receive data from main thread");}    
```    
  
    
 **常量：**     
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| parentPort<sup>(deprecated)</sup> | DedicatedWorkerGlobalScope |  | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.workerPort替代。<br>worker线程用于与宿主线程通信的对象。 |  
| workerPort<sup>(9+)</sup> | ThreadWorkerGlobalScope |  | worker线程用于与宿主线程通信的对象。<br/>此属性从API version 7开始支持,从API version 9 开始被废弃。<br/>建议使用workerPort<sup>9+</sup>替代。 |  
    
## ThreadWorker<sup>(9+)</sup>    
使用以下方法前，均需先构造ThreadWorker实例，ThreadWorker类继承[WorkerEventTarget](#workereventtarget9)。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onexit<sup>(9+)</sup> | (code: number) => void | false | false | Worker对象的onexit属性表示Worker销毁时被调用的事件处理程序，处理程序在宿主线程中执行。 |  
| onerror<sup>(9+)</sup> | (err: ErrorEvent) => void | false | false | Worker对象的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在宿主线程中执行。 |  
| onmessage<sup>(9+)</sup> | (event: MessageEvents) => void | false | false | Worker对象的onmessage属性表示宿主线程接收到来自其创建的Worker通过workerPort.postMessage接口发送的消息时被调用的事件处理程序，处理程序在宿主线程中执行。 |  
| onmessageerror<sup>(9+)</sup> | (event: MessageEvents) => void | false | false | Worker对象的onmessageerror属性表示当Worker对象接收到一条无法被序列化的消息时被调用的事件处理程序，处理程序在宿主线程中执行。 |  
    
### postMessage<sup>(9+)</sup>    
宿主线程通过转移对象所有权的方式向Worker线程发送消息。  
 **调用形式：**     
- postMessage(message: Object, transfer: ArrayBuffer[]): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | Object | true | 发送至Worker的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |  
| transfer | ArrayBuffer[] | true | 表示可转移的ArrayBuffer实例对象数组，该数组中对象的所有权会被转移到Worker线程，在宿主线程中将会变为不可用，仅在Worker线程中可用，数组不可传入null。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200006 | An exception occurred during serialization. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");  
let buffer = new ArrayBuffer(8);workerInstance.postMessage(buffer, [buffer]);    
```    
  
    
### postMessage<sup>(9+)</sup>    
宿主线程通过转移对象所有权或者拷贝数据的方式向Worker线程发送消息。  
 **调用形式：**     
- postMessage(message: Object, options?: PostMessageOptions): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | Object | true | 发送至Worker的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |  
| options | PostMessageOptions | false | 当填入该参数时，与传入ArrayBuffer[]的作用一致，该数组中对象的所有权会被转移到Worker线程，在宿主线程中将会变为不可用，仅在Worker线程中可用。<br>若不填入该参数，默认设置为 undefined，通过拷贝数据的方式传输信息到Worker线程。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200006 | An exception occurred during serialization. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");  
workerInstance.postMessage("hello world");  
let buffer = new ArrayBuffer(8);workerInstance.postMessage(buffer, [buffer]);    
```    
  
    
### on<sup>(9+)</sup>    
向Worker添加一个事件监听，该接口与[addEventListener<sup>9+</sup>](#addeventlistener9)接口功能一致。  
 **调用形式：**     
- on(type: string, listener: WorkerEventListener): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听的事件类型。 |  
| listener | WorkerEventListener | true | 回调的事件。回调事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200005 | The invoked API is not supported in workers. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.on("alert", (e)=>{    console.log("alert listener callback");})    
```    
  
    
### once<sup>(9+)</sup>    
向Worker添加一个事件监听，事件监听只执行一次便自动删除。  
 **调用形式：**     
- once(type: string, listener: WorkerEventListener): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听的事件类型。 |  
| listener | WorkerEventListener | true | 回调的事件。回调事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200005 | The invoked API is not supported in workers. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.once("alert", (e)=>{    console.log("alert listener callback");})    
```    
  
    
### off<sup>(9+)</sup>    
删除类型为type的事件监听，该接口与[removeEventListener<sup>9+</sup>](#removeeventlistener9)接口功能一致。  
 **调用形式：**     
- off(type: string, listener?: WorkerEventListener): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 需要删除的事件类型。 |  
| listener | WorkerEventListener | false | 回调的事件。删除的回调事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200005 | The invoked API is not supported in workers. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");//使用on接口、once接口或addEventListener接口创建“alert”事件，使用off接口删除事件。workerInstance.off("alert");    
```    
  
    
### terminate<sup>(9+)</sup>    
销毁Worker线程，终止Worker接收消息。  
 **调用形式：**     
- terminate(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200004 | Worker instance is not running. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.terminate();    
```    
  
    
### addEventListener<sup>(9+)</sup>    
向Worker添加一个事件监听，该接口与[on<sup>9+</sup>](#on9)接口功能一致。  
 **调用形式：**     
- addEventListener(type: string, listener: WorkerEventListener): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听的事件类型。 |  
| listener | WorkerEventListener | true | 回调的事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
| 10200005 | The invoked API is not supported in workers. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.addEventListener("alert", (e)=>{    console.log("alert listener callback");})    
```    
  
    
### dispatchEvent<sup>(9+)</sup>    
分发定义在Worker的事件。  
 **调用形式：**     
- dispatchEvent(event: Event): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | Event | true | 需要分发的事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 分发的结果，false表示分发失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
    
 **示例代码：**   
```null    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");  
workerInstance.dispatchEvent({type:"eventType", timeStamp:0}); //timeStamp暂未支持。```  
分发事件（dispatchEvent）可与监听接口（on、once、addEventListener）搭配使用，示例如下：import worker, { MessageEvents } from '@ohos.worker';  
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");  
//用法一:workerInstance.on("alert_on", (e)=>{    console.log("alert listener callback");})workerInstance.once("alert_once", (e)=>{    console.log("alert listener callback");})workerInstance.addEventListener("alert_add", (e)=>{    console.log("alert listener callback");})  
//once接口创建的事件执行一次便会删除。workerInstance.dispatchEvent({type:"alert_once", timeStamp:0});//timeStamp暂未支持。//on接口创建的事件可以一直被分发，不能主动删除。workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});workerInstance.dispatchEvent({type:"alert_on", timeStamp:0});//addEventListener接口创建的事件可以一直被分发，不能主动删除。workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});workerInstance.dispatchEvent({type:"alert_add", timeStamp:0});  
//用法二://event类型的type支持自定义，同时存在"message"/"messageerror"/"error"特殊类型，如下所示//当type = "message"，onmessage接口定义的方法同时会执行。//当type = "messageerror"，onmessageerror接口定义的方法同时会执行。//当type = "error"，onerror接口定义的方法同时会执行。//若调用removeEventListener接口或者off接口取消事件时，能且只能取消使用addEventListener/on/once创建的事件。  
workerInstance.addEventListener("message", (e)=>{    console.log("message listener callback");})workerInstance.onmessage = (e: MessageEvents): void => {    console.log("onmessage : message listener callback");}//调用dispatchEvent分发“message”事件，addEventListener和onmessage中定义的方法都会被执行。workerInstance.dispatchEvent({type:"message", timeStamp:0});    
```    
  
    
### removeEventListener<sup>(9+)</sup>  
 **调用形式：**     
    
- removeEventListener(type: string, callback?: WorkerEventListener): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 需要删除的监听事件类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调的事件。删除的回调事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200004 | Worker instance is not running. |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.addEventListener("alert", (e)=>{    console.log("alert listener callback");})workerInstance.removeEventListener("alert");    
```    
  
    
### removeAllListener<sup>(9+)</sup>  
 **调用形式：**     
- removeAllListener(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200004 |  |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");workerInstance.addEventListener("alert", (e)=>{    console.log("alert listener callback");})workerInstance.removeAllListener();    
```    
  
    
## Worker<sup>(deprecated)</sup>    
使用以下方法前，均需先构造Worker实例，Worker类继承[EventTarget](#eventtargetdeprecated)。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.ThreadWorker替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onexit<sup>(deprecated)</sup> | (code: number) => void | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.ThreadWorker.onexit替代。<br>Worker对象的onexit属性表示Worker销毁时被调用的事件处理程序，处理程序在宿主线程中执行。 |  
| onerror<sup>(deprecated)</sup> | (err: ErrorEvent) => void | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.ThreadWorker.onerror替代。<br>Worker对象的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在宿主线程中执行。 |  
| onmessage<sup>(deprecated)</sup> | (event: MessageEvent) => void | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.ThreadWorker.onmessage替代。<br>Worker对象的onmessage属性表示宿主线程接收到来自其创建的Worker通过parentPort.postMessage接口发送的消息时被调用的事件处理程序，处理程序在宿主线程中执行。 |  
| onmessageerror<sup>(deprecated)</sup> | (event: MessageEvent) => void | false | false | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.worker.ThreadWorker.onmessageerror替代。<br>Worker对象的onmessageerror属性表示当Worker对象接收到一条无法被序列化的消息时被调用的事件处理程序，处理程序在宿主线程中执行。 |  
    
### postMessage<sup>(deprecated)</sup>    
宿主线程通过转移对象所有权的方式向Worker线程发送消息。  
 **调用形式：**     
- postMessage(message: Object, transfer: ArrayBuffer[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.ThreadWorker.postMessage。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message<sup>(deprecated)</sup> | Object | true | 发送至Worker的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |  
| transfer<sup>(deprecated)</sup> | ArrayBuffer[] | true | 表示可转移的ArrayBuffer实例对象数组，该数组中对象的所有权会被转移到Worker线程，在宿主线程中将会变为不可用，仅在Worker线程中可用，数组不可传入null。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");  
let buffer = new ArrayBuffer(8);workerInstance.postMessage(buffer, [buffer]);    
```    
  
    
### postMessage    
宿主线程通过转移对象所有权或者拷贝数据的方式向Worker线程发送消息。  
 **调用形式：**     
- postMessage(message: Object, options?: PostMessageOptions): void  
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | Object | true | 发送至Worker的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |  
| options | PostMessageOptions | false | 当填入该参数时，与传入ArrayBuffer[]的作用一致，该数组中对象的所有权会被转移到Worker线程，在宿主线程中将会变为不可用，仅在Worker线程中可用。<br/>若不填入该参数，默认设置为 undefined，通过拷贝数据的方式传输信息到Worker线程。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");  
workerInstance.postMessage("hello world");  
let buffer = new ArrayBuffer(8);workerInstance.postMessage(buffer, [buffer]);    
```    
  
    
### on<sup>(deprecated)</sup>    
向Worker添加一个事件监听，该接口与[addEventListener<sup>(deprecated)</sup>](#addeventlistenerdeprecated)接口功能一致。  
 **调用形式：**     
- on(type: string, listener: EventListener): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.ThreadWorker.on。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 监听的事件类型。 |  
| listener<sup>(deprecated)</sup> | EventListener | true | 回调事件。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.on("alert", ()=>{    console.log("alert listener callback");})    
```    
  
    
### once<sup>(deprecated)</sup>    
向Worker添加一个事件监听，事件监听只执行一次便自动删除。  
 **调用形式：**     
- once(type: string, listener: EventListener): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.ThreadWorker.once。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 监听的事件类型。 |  
| listener<sup>(deprecated)</sup> | EventListener | true | 回调事件。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.once("alert", (e)=>{    console.log("alert listener callback");})    
```    
  
    
### off<sup>(deprecated)</sup>    
删除类型为type的事件监听，该接口与[removeEventListener<sup>(deprecated)</sup>](#removeeventlistenerdeprecated)接口功能一致。  
 **调用形式：**     
- off(type: string, listener?: EventListener): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.ThreadWorker.off。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 需要删除的事件类型。 |  
| listener<sup>(deprecated)</sup> | EventListener | false | 删除的回调事件。 |  
    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");//使用on接口、once接口或addEventListener接口创建“alert”事件，使用off接口删除事件。workerInstance.off("alert");    
```    
  
    
### terminate<sup>(deprecated)</sup>    
销毁Worker线程，终止Worker接收消息。  
 **调用形式：**     
- terminate(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.worker.ThreadWorker.terminate。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
const workerInstance = new worker.Worker("workers/worker.ts");workerInstance.terminate();    
```    
  
