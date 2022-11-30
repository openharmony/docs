# 启动一个Worker

Worker是与主线程并行的独立线程。创建Worker的线程称之为宿主线程，Worker自身的线程称之为Worker线程。创建Worker传入的url文件在Worker线程中执行，可以处理耗时操作但不可以直接操作UI。
> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br/>
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import worker from '@ohos.worker';
```


## 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称                              | 类型                                                      | 可读 | 可写 | 说明                                                         |
| --------------------------------- | --------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| workerPort<sup>9+</sup>           | [ThreadWorkerGlobalScope](#threadworkerglobalscope9)      | 是   | 是   | worker线程用于与宿主线程通信的对象。                         |
| parentPort<sup>(deprecated)</sup> | [DedicatedWorkerGlobalScope](#dedicatedworkerglobalscope) | 是   | 是   | worker线程用于与宿主线程通信的对象。<br/>此属性从API version 7开始支持,从API version 9 开始被废弃。<br/>建议使用workerPort<sup>9+</sup>替代。 |


## WorkerOptions

Worker构造函数的选项信息，用于为Worker添加其他信息。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明           |
| ---- | -------- | ---- | ---- | -------------- |
| type | "classic" \| "module" | 是   | 是   | Worker执行脚本的模式类型，默认为classic类型，暂不支持module类型。 |
| name | string   | 是   | 是   | Worker的名称。 |
| shared | boolean | 是   | 是   | 暂不支持共享Worker功能。 |


## ThreadWorker<sup>9+</sup>

使用以下方法前，均需先构造Worker实例，Worker类继承[WorkerEventTarget](#workereventtarget9)。

### constructor<sup>9+</sup>

constructor(scriptURL: string, options?: WorkerOptions)

Worker构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | 是   | Worker执行脚本的路径。<br/>在FA和Stage模型下，DevEco Studio新建Worker工程路径分别存在以下两种情况：<br/>(a) worker脚本所在目录与pages目录同级。<br/>(b) worker脚本所在目录与pages目录不同级。 |
| options   | [WorkerOptions](#workeroptions) | 否   | Worker构造的选项。                                           |

**返回值：**

| 类型   | 说明                                                      |
| ------ | --------------------------------------------------------- |
| Worker | 执行Worker构造函数生成的Worker对象，失败则返回undefined。 |

**示例：**

```js
import worker from '@ohos.worker';
// worker线程创建

// FA模型-目录同级
const workerFAModel01 = new worker.ThreadWorker("workers/worker.js", {name:"first worker in FA model"});
// FA模型-目录不同级（以workers目录放置pages目录前一级为例）
const workerFAModel02 = new worker.ThreadWorker("../workers/worker.js");

// Stage模型-目录同级
const workerStageModel01 = new worker.ThreadWorker('entry/ets/workers/worker.ts', {name:"first worker in Stage model"});
// Stage模型-目录不同级（以workers目录放置pages目录后一级为例）
const workerStageModel02 = new worker.ThreadWorker('entry/ets/pages/workers/worker.ts');

// 理解Stage模型scriptURL的"entry/ets/workers/worker.ts"：
// entry: 为module.json5文件中module的name属性对应的值；
// ets: 表明当前使用的语言。
```

同时，需在工程的模块级build-profile.json5文件的buildOption属性中添加配置信息，主要分为下面两种情况：

(1) 目录同级

FA模型:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/MainAbility/workers/worker.ts"
      ]
    }
  }
```

Stage模型:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ts"
      ]
    }
  }
```

(2) 目录不同级

FA模型:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ts"
      ]
    }
  }
```

Stage模型:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/pages/workers/worker.ts"
      ]
    }
  }
```


### postMessage<sup>9+</sup>

postMessage(message: Object, options?: PostMessageOptions): void

向Worker线程发送数据，数据类型必须是序列化所支持的类型。序列化支持类型见其他说明。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | 是   | 发送至Worker的数据。                                         |
| options | [PostMessageOptions](#postmessageoptions) | 否   | 可转移对象是&nbsp;ArrayBuffer&nbsp;的实例对象。transferList数组中不可传入null。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");

workerInstance.postMessage("hello world");

var buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```


### on<sup>9+</sup>

on(type: string, listener: WorkerEventListener): void

向Worker添加一个事件监听。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                   |
| -------- | -------------------------------------------- | ---- | ---------------------- |
| type     | string                                       | 是   | 监听的事件类型。       |
| listener | [WorkerEventListener](#workereventlistener9) | 是 | 回调的事件。回调事件。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.on("alert", (e)=>{
    console.log("alert listener callback");
})
```


### once<sup>9+</sup>

once(type: string, listener: WorkerEventListener): void

向Worker添加一个事件监听，事件监听只执行一次便自动删除。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                   |
| -------- | -------------------------------------------- | ---- | ---------------------- |
| type     | string                                       | 是   | 监听的事件类型。       |
| listener | [WorkerEventListener](#workereventlistener9) | 是 | 回调的事件。回调事件。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.once("alert", (e)=>{
    console.log("alert listener callback");
})
```


### off<sup>9+</sup>

off(type: string, listener?: WorkerEventListener): void

删除类型为type的事件监听。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                         |
| -------- | -------------------------------------------- | ---- | ---------------------------- |
| type     | string                                       | 是   | 需要删除的事件类型。         |
| listener | [WorkerEventListener](#workereventlistener9) | 否 | 回调的事件。删除的回调事件。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.off("alert");
```


### terminate<sup>9+</sup>

terminate(): void

销毁Worker线程，终止Worker接收消息。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.terminate();
```


### onexit<sup>9+</sup>

onexit?: (code: number) =&gt; void

Worker对象的onexit属性表示Worker销毁时被调用的事件处理程序，处理程序在宿主线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | Worker退出的code。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.onexit = function(e) {
    console.log("onexit");
}
```


### onerror<sup>9+</sup>

onerror?: (err: ErrorEvent) =&gt; void

Worker对象的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在宿主线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| err    | [ErrorEvent](#errorevent) | 是   | 异常数据。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.onerror = function(e) {
    console.log("onerror");
}
```


### onmessage<sup>9+</sup>

onmessage?: (event: MessageEvents) =&gt; void

Worker对象的onmessage属性表示宿主线程接收到来自其创建的Worker通过parentPort.postMessage接口发送的消息时被调用的事件处理程序，处理程序在宿主线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                             | 必填 | 说明                   |
| ------ | -------------------------------- | ---- | ---------------------- |
| event  | [MessageEvents](#messageevents9) | 是   | 收到的Worker消息数据。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.onmessage = function(e) {
    // e : MessageEvent<T>, 用法如下：
    // let data = e.data;
    console.log("onmessage");
}
```


### onmessageerror<sup>9+</sup>

onmessageerror?: (event: MessageEvents) =&gt; void

Worker对象的onmessageerror属性表示当Worker对象接收到一条无法被序列化的消息时被调用的事件处理程序，处理程序在宿主线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                             | 必填 | 说明       |
| ------ | -------------------------------- | ---- | ---------- |
| event  | [MessageEvents](#messageevents9) | 是   | 异常数据。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.onmessageerror= function(e) {
    console.log("onmessageerror");
}
```


## WorkerEventTarget<sup>9+</sup>

### addEventListener<sup>9+</sup>

addEventListener(type: string, listener: WorkerEventListener): void

向Worker添加一个事件监听。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                                         | 必填 | 说明             |
| -------- | -------------------------------------------- | ---- | ---------------- |
| type     | string                                       | 是   | 监听的事件类型。 |
| listener | [WorkerEventListener](#workereventlistener9) | 是   | 回调的事件。     |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


### removeEventListener<sup>9+</sup>

removeEventListener(type: string, callback?: WorkerEventListener): void

删除Worker的事件监听。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                         |
| -------- | -------------------------------------------- | ---- | ---------------------------- |
| type     | string                                       | 是   | 需要删除的监听事件类型。     |
| callback | [WorkerEventListener](#workereventlistener9) | 否 | 回调的事件。删除的回调事件。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.removeEventListener("alert");
```


### dispatchEvent<sup>9+</sup>

dispatchEvent(event: Event): boolean

分发定义在Worker的事件。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型            | 必填 | 说明             |
| ------ | --------------- | ---- | ---------------- |
| event  | [Event](#event) | 是   | 需要分发的事件。 |

**返回值：**

| 类型    | 说明                            |
| ------- | ------------------------------- |
| boolean | 分发的结果，false表示分发失败。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.dispatchEvent({type: "alert"});
```


### removeAllListener<sup>9+</sup>

removeAllListener(): void

删除Worker所有的事件监听。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.removeAllListener();
```


## ThreadWorkerGlobalScope<sup>9+</sup>

Worker线程用于与宿主线程通信的类，通过postMessage接口发送消息给宿主线程、close接口销毁Worker线程。ThreadWorkerGlobalScope类继承[GlobalScope<sup>9+</sup>](#globalscope9)。


### postMessage<sup>9+</sup>

postMessage(messageObject: Object, options?: PostMessageOptions): void

Worker线程向宿主线程发送消息。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | 是   | 发送至宿主线程的数据。                                       |
| options | [PostMessageOptions](#postmessageoptions) | 否   | 可转移对象是ArrayBuffer的实例对象。transferList数组中不可传入null。 |

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.postMessage("hello world");
workerInstance.onmessage = function(e) {
    // let data = e.data;
    console.log("receive data from worker.js");
}
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
parentPort.onmessage = function(e){
    // let data = e.data;
    parentPort.postMessage("receive data from main.js");
}
```


### close<sup>9+</sup>

close(): void

销毁Worker线程，终止Worker接收消息。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
parentPort.onmessage = function(e) {
    parentPort.close()
}
```


### onmessage<sup>9+</sup>

onmessage?: (event: MessageEvents) =&gt; void

DedicatedWorkerGlobalScope的onmessage属性表示Worker线程收到来自其宿主线程通过postMessage接口发送的消息时被调用的事件处理程序，处理程序在Worker线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                             | 必填 | 说明                     |
| ------ | -------------------------------- | ---- | ------------------------ |
| event  | [MessageEvents](#messageevents9) | 是   | 收到宿主线程发送的数据。 |

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.postMessage("hello world");
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
parentPort.onmessage = function(e) {
    console.log("receive main.js message");
}
```


### onmessageerror<sup>9+</sup>

onmessageerror?: (event: MessageEvents) =&gt; void

DedicatedWorkerGlobalScope的onmessageerror属性表示当Worker对象接收到一条无法被反序列化的消息时被调用的事件处理程序，处理程序在Worker线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                             | 必填 | 说明       |
| ------ | -------------------------------- | ---- | ---------- |
| event  | [MessageEvents](#messageevents9) | 是   | 异常数据。 |

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
parentPort.onmessageerror= function(e) {
    console.log("worker.js onmessageerror")
}
```


## WorkerEventListener<sup>9+</sup>

(event: Event): void | Promise&lt;void&gt;

事件监听类。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型            | 必填 | 说明           |
| ------ | --------------- | ---- | -------------- |
| event  | [Event](#event) | 是   | 回调的事件类。 |

**返回值：**

| 类型                                  | 说明                            |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | 无返回值或者以Promise形式返回。 |

**示例：**

```js
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


## GlobalScope<sup>9+</sup>

Worker线程自身的运行环境，GlobalScope类继承[WorkerEventTarget](#workereventtarget9)。

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型                                                         | 可读 | 可写 | 说明                                  |
| ---- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------- |
| name | string                                                       | 是   | 否   | Worker的名字，new&nbsp;Worker时指定。 |
| self | [GlobalScope](#globalscope9)&nbsp;&amp;&nbsp;typeof&nbsp;globalThis | 是   | 否   | GlobalScope本身。                     |


### onerror<sup>9+</sup>

onerror?: (ev: ErrorEvent) =&gt; void

GlobalScope的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在Worker线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| ev     | [ErrorEvent](#errorevent) | 是   | 异常数据。 |

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js")
```

```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort
parentPort.onerror = function(e){
    console.log("worker.js onerror")
}
```

## MessageEvents<sup>9+</sup>

消息类，持有Worker线程间传递的数据。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明               |
| ---- | ---- | ---- | ---- | ------------------ |
| data | any  | 是   | 否   | 线程间传递的数据。 |

## Worker<sup>(deprecated)</sup>


使用以下方法前，均需先构造Worker实例，Worker类继承[EventTarget](#eventtarget)。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker<sup>9+</sup>](#threadworker9)替代。

### constructor<sup>(deprecated)</sup>

constructor(scriptURL: string, options?: WorkerOptions)

Worker构造函数。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.constructor<sup>9+</sup>](#constructor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | 是   | Worker执行脚本的路径。<br/>在FA和Stage模型下，DevEco Studio新建Worker工程路径分别存在以下两种情况：<br/>(a) worker脚本所在目录与pages目录同级。<br/>(b) worker脚本所在目录与pages目录不同级。 |
| options   | [WorkerOptions](#workeroptions) | 否   | Worker构造的选项。                                           |

**返回值：**

| 类型   | 说明                                                      |
| ------ | --------------------------------------------------------- |
| Worker | 执行Worker构造函数生成的Worker对象，失败则返回undefined。 |

**示例：**

```js
import worker from '@ohos.worker';
// worker线程创建

// FA模型-目录同级
const workerFAModel01 = new worker.Worker("workers/worker.js", {name:"first worker in FA model"});
// FA模型-目录不同级（以workers目录放置pages目录前一级为例）
const workerFAModel02 = new worker.Worker("../workers/worker.js");

// Stage模型-目录同级
const workerStageModel01 = new worker.Worker('entry/ets/workers/worker.ts', {name:"first worker in Stage model"});
// Stage模型-目录不同级（以workers目录放置pages目录后一级为例）
const workerStageModel02 = new worker.Worker('entry/ets/pages/workers/worker.ts');

// 理解Stage模型scriptURL的"entry/ets/workers/worker.ts"：
// entry: 为module.json5文件中module的name属性对应的值；
// ets: 表明当前使用的语言。
```
同时，需在工程的模块级build-profile.json5文件的buildOption属性中添加配置信息，主要分为下面两种情况：

(1) 目录同级

FA模型:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/MainAbility/workers/worker.ts"
      ]
    }
  }
```
Stage模型:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ts"
      ]
    }
  }
```
(2) 目录不同级

FA模型:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ts"
      ]
    }
  }
```
Stage模型:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/pages/workers/worker.ts"
      ]
    }
  }
```
### postMessage<sup>(deprecated)</sup>

postMessage(message: Object, options?: PostMessageOptions): void

向Worker线程发送数据，数据类型必须是序列化所支持的类型。序列化支持类型见其他说明。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.postMessage<sup>9+</sup>](#postmessage9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | 是   | 发送至Worker的数据。                                         |
| options | [PostMessageOptions](#postmessageoptions) | 否   | 可转移对象是&nbsp;ArrayBuffer&nbsp;的实例对象。transferList数组中不可传入null。 |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");

workerInstance.postMessage("hello world");

var buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```


### on<sup>(deprecated)</sup>

on(type: string, listener: EventListener): void

向Worker添加一个事件监听。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.on<sup>9+</sup>](#on9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                            | 必填 | 说明             |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | 是   | 监听的事件类型。 |
| listener | [EventListener](#eventlistener) | 是   | 回调事件。       |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.on("alert", (e)=>{
    console.log("alert listener callback");
})
```


### once<sup>(deprecated)</sup>

once(type: string, listener: EventListener): void

向Worker添加一个事件监听，事件监听只执行一次便自动删除。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.once<sup>9+</sup>](#once9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                            | 必填 | 说明             |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | 是   | 监听的事件类型。 |
| listener | [EventListener](#eventlistener) | 是   | 回调事件。       |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.once("alert", (e)=>{
    console.log("alert listener callback");
})
```


### off<sup>(deprecated)</sup>

off(type: string, listener?: EventListener): void

删除类型为type的事件监听。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.off<sup>9+</sup>](#off9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                            | 必填 | 说明                 |
| -------- | ------------------------------- | ---- | -------------------- |
| type     | string                          | 是   | 需要删除的事件类型。 |
| listener | [EventListener](#eventlistener) | 否   | 删除的回调事件。     |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.off("alert");
```


### terminate<sup>(deprecated)</sup>

terminate(): void

销毁Worker线程，终止Worker接收消息。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.terminate<sup>9+</sup>](#terminate9)替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.terminate();
```


### onexit<sup>(deprecated)</sup>

onexit?: (code: number) =&gt; void

Worker对象的onexit属性表示Worker销毁时被调用的事件处理程序，处理程序在宿主线程中执行。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.onexit<sup>9+</sup>](#onexit9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | Worker退出的code。 |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onexit = function(e) {
    console.log("onexit");
}
```


### onerror<sup>(deprecated)</sup>

onerror?: (err: ErrorEvent) =&gt; void

Worker对象的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在宿主线程中执行。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.onerror<sup>9+</sup>](#onerror9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| err    | [ErrorEvent](#errorevent) | 是   | 异常数据。 |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onerror = function(e) {
    console.log("onerror");
}
```


### onmessage<sup>(deprecated)</sup>

onmessage?: (event: MessageEvent\<T>) =&gt; void

Worker对象的onmessage属性表示宿主线程接收到来自其创建的Worker通过parentPort.postMessage接口发送的消息时被调用的事件处理程序，处理程序在宿主线程中执行。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.onmessage<sup>9+</sup>](#onmessage9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                   |
| ------ | --------------------------------------- | ---- | ---------------------- |
| event  | [MessageEvent&lt;T&gt;](#messageeventt) | 是   | 收到的Worker消息数据。 |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onmessage = function(e) {
    // e : MessageEvent<T>, 用法如下：
    // let data = e.data;
    console.log("onmessage");
}
```


### onmessageerror<sup>(deprecated)</sup>

onmessageerror?: (event: MessageEvent\<T>) =&gt; void

Worker对象的onmessageerror属性表示当Worker对象接收到一条无法被序列化的消息时被调用的事件处理程序，处理程序在宿主线程中执行。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorker.onmessageerror<sup>9+</sup>](#onmessageerror9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                                    | 必填 | 说明       |
| ------ | --------------------------------------- | ---- | ---------- |
| event  | [MessageEvent&lt;T&gt;](#messageeventt) | 是   | 异常数据。 |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.onmessageerror= function(e) {
    console.log("onmessageerror");
}
```


## EventTarget<sup>(deprecated)</sup>
> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[WorkerEventTarget<sup>9+</sup>](#workereventtarget9)替代。

### addEventListener<sup>(deprecated)</sup>

addEventListener(type: string, listener: EventListener): void

向Worker添加一个事件监听。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[addEventListener<sup>9+</sup>](#addeventlistener9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                            | 必填 | 说明             |
| -------- | ------------------------------- | ---- | ---------------- |
| type     | string                          | 是   | 监听的事件类型。 |
| listener | [EventListener](#eventlistener) | 是   | 回调的事件。     |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


### removeEventListener<sup>(deprecated)</sup>

removeEventListener(type: string, callback?: EventListener): void

删除Worker的事件监听。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[removeEventListener<sup>9+</sup>](#removeeventlistener9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                            | 必填 | 说明                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| type     | string                          | 是   | 需要删除的监听事件类型。 |
| callback | [EventListener](#eventlistener) | 否   | 删除的回调事件。         |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.removeEventListener("alert");
```


### dispatchEvent<sup>(deprecated)</sup>

dispatchEvent(event: Event): boolean

分发定义在Worker的事件。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[dispatchEvent<sup>9+</sup>](#dispatchevent9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型            | 必填 | 说明             |
| ------ | --------------- | ---- | ---------------- |
| event  | [Event](#event) | 是   | 需要分发的事件。 |

**返回值：**

| 类型    | 说明                            |
| ------- | ------------------------------- |
| boolean | 分发的结果，false表示分发失败。 |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.dispatchEvent({type:"alert"});
```


### removeAllListener<sup>(deprecated)</sup>

removeAllListener(): void

删除Worker所有的事件监听。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[removeAllListener<sup>9+</sup>](#removealllistener9)替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.removeAllListener();
```


## DedicatedWorkerGlobalScope<sup>(deprecated)</sup>

Worker线程用于与宿主线程通信的类，通过postMessage接口发送消息给宿主线程、close接口销毁Worker线程。DedicatedWorkerGlobalScope类继承[WorkerGlobalScope](#workerglobalscope)。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9)替代。

### postMessage<sup>(deprecated)</sup>

postMessage(messageObject: Object, options?: PostMessageOptions): void

Worker线程向宿主线程发送消息。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9).postMessage<sup>9+</sup>替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | 是   | 发送至宿主线程的数据。                                       |
| options | [PostMessageOptions](#postmessageoptions) | 否   | 可转移对象是ArrayBuffer的实例对象。transferList数组中不可传入null。 |

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.postMessage("hello world");
workerInstance.onmessage = function(e) {
    // let data = e.data;
    console.log("receive data from worker.js");
}
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e){
    // let data = e.data;
    parentPort.postMessage("receive data from main.js");
}
```


### close<sup>(deprecated)</sup>

close(): void

销毁Worker线程，终止Worker接收消息。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9).close<sup>9+</sup>替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e) {
    parentPort.close()
}
```


### onmessage<sup>(deprecated)</sup>

onmessage?: (event: MessageEvent\<T>) =&gt; void

DedicatedWorkerGlobalScope的onmessage属性表示Worker线程收到来自其宿主线程通过postMessage接口发送的消息时被调用的事件处理程序，处理程序在Worker线程中执行。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9).onmessage<sup>9+</sup>替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                     |
| ------ | --------------------------------------- | ---- | ------------------------ |
| event  | [MessageEvent&lt;T&gt;](#messageeventt) | 是   | 收到宿主线程发送的数据。 |

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.postMessage("hello world");
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessage = function(e) {
    console.log("receive main.js message");
}
```


### onmessageerror<sup>(deprecated)</sup>

onmessageerror?: (event: MessageEvent\<T>) =&gt; void

DedicatedWorkerGlobalScope的onmessageerror属性表示当Worker对象接收到一条无法被反序列化的消息时被调用的事件处理程序，处理程序在Worker线程中执行。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[ThreadWorkerGlobalScope<sup>9+</sup>](#threadworkerglobalscope9).onmessageerror<sup>9+</sup>替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                              | 必填 | 说明       |
| ------ | --------------------------------- | ---- | ---------- |
| event  | [MessageEvent&lt;T&gt;](#messageeventt) | 是   | 异常数据。 |

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js");
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort;
parentPort.onmessageerror= function(e) {
    console.log("worker.js onmessageerror")
}
```


## PostMessageOptions

明确数据传递过程中需要转移所有权对象的类，传递所有权的对象必须是ArrayBuffer。

**系统能力：** SystemCapability.Utils.Lang

| 名称     | 类型     | 可读 | 可写 | 说明                              |
| -------- | -------- | ---- | ---- | --------------------------------- |
| transfer | Object[] | 是   | 是   | ArrayBuffer数组，用于传递所有权。 |


## Event

事件类。

**系统能力：** SystemCapability.Utils.Lang

| 名称      | 类型   | 可读 | 可写 | 说明                               |
| --------- | ------ | ---- | ---- | ---------------------------------- |
| type      | string | 是   | 否   | 指定事件的类型。                   |
| timeStamp | number | 是   | 否   | 事件创建时的时间戳（精度为毫秒）。 |


## EventListener<sup>(deprecated)</sup>

(evt: Event): void | Promise&lt;void&gt;

事件监听类。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[WorkerEventListener<sup>9+</sup>](#workereventlistener9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型            | 必填 | 说明           |
| ------ | --------------- | ---- | -------------- |
| evt    | [Event](#event) | 是   | 回调的事件类。 |

**返回值：**

| 类型                                  | 说明                            |
| ------------------------------------- | ------------------------------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | 无返回值或者以Promise形式返回。 |

**示例：**

```js
const workerInstance = new worker.Worker("workers/worker.js");
workerInstance.addEventListener("alert", (e)=>{
    console.log("alert listener callback");
})
```


## ErrorEvent

错误事件类，用于表示Worker执行过程中出现异常的详细信息，ErrorEvent类继承[Event](#event)。

**系统能力：** SystemCapability.Utils.Lang

| 名称     | 类型   | 可读 | 可写 | 说明                 |
| -------- | ------ | ---- | ---- | -------------------- |
| message  | string | 是   | 否   | 异常发生的错误信息。 |
| filename | string | 是   | 否   | 出现异常所在的文件。 |
| lineno   | number | 是   | 否   | 异常所在的行数。     |
| colno    | number | 是   | 否   | 异常所在的列数。     |
| error    | Object | 是   | 否   | 异常类型。           |


## MessageEvent\<T\>

消息类，持有Worker线程间传递的数据。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明               |
| ---- | ---- | ---- | ---- | ------------------ |
| data | T    | 是   | 否   | 线程间传递的数据。 |


## WorkerGlobalScope<sup>(deprecated)</sup>

Worker线程自身的运行环境，WorkerGlobalScope类继承[EventTarget](#eventtarget)。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[GlobalScope<sup>9+</sup>](#globalscope9)替代。

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型                                                         | 可读 | 可写 | 说明                                  |
| ---- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------- |
| name | string                                                       | 是   | 否   | Worker的名字，new&nbsp;Worker时指定。 |
| self | [WorkerGlobalScope](#workerglobalscope)&nbsp;&amp;&nbsp;typeof&nbsp;globalThis | 是   | 否   | WorkerGlobalScope本身。               |


### onerror<sup>(deprecated)</sup>

onerror?: (ev: ErrorEvent) =&gt; void

WorkerGlobalScope的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在Worker线程中执行。

> **说明：**<br/>
> 从API version 7 开始支持，从API version 9 开始废弃，建议使用[GlobalScope<sup>9+</sup>](#globalscope9).onerror替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| ev     | [ErrorEvent](#errorevent) | 是   | 异常数据。 |

**示例：**

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.Worker("workers/worker.js")
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.parentPort
parentPort.onerror = function(e){
    console.log("worker.js onerror")
}
```


## 其他说明

### 序列化支持类型
| Type               | 备注                                   | 是否支持 |
| ------------------ | -------------------------------------- | -------- |
| All Primitive Type | 不包括symbol                           | 是       |
| Date               |                                        | 是       |
| String             |                                        | 是       |
| RegExp             |                                        | 是       |
| Array              |                                        | 是       |
| Map                |                                        | 是       |
| Set                |                                        | 是       |
| Object             | 只支持Plain Object，不支持带function的 | 是       |
| ArrayBuffer        | 提供transfer能力                       | 是       |
| TypedArray         |                                        | 是       |

特例：传递通过自定义class创建出来的object时，不会发生序列化错误，但是自定义class的属性（如Function）无法通过序列化传递。
> **说明：**<br/>
> 以API version 9的FA工程为例。

```js
// main.js
import worker from '@ohos.worker';
const workerInstance = new worker.ThreadWorker("workers/worker.js");
workerInstance.postMessage("message from main to worker");
workerInstance.onmessage = function(d) {
  // 当worker线程传递obj2时，data即为obj2。data没有Init、SetName的方法
  let data = d.data;
}
```
```js
// worker.js
import worker from '@ohos.worker';
const parentPort = worker.workerPort;
class MyModel {
    name:"undefined"
    Init() {
        this.name = "MyModel"
    }
}
parentPort.onmessage = function(d) {
    console.log("worker.js onmessage");
    let data = d.data;
    let func1 = function() {
        console.log("post message is function");
    }
    let obj1 = {
        "index": 2,
        "name1": "zhangshan",
        setName() {
            this.index = 3;
        }
    }
    let obj2 = new MyModel();
    // parentPort.postMessage(func1); 传递func1发生序列化错误
    // parentPort.postMessage(obj1);  传递obj1发生序列化错误
    parentPort.postMessage(obj2);     // 传递obj2不会发生序列化错误
}
parentPort.onmessageerror = function(e) {
    console.log("worker.js onmessageerror");
}
parentPort.onerror = function(e) {
    console.log("worker.js onerror");
}
```

### 内存模型
Worker基于Actor并发模型实现。在Worker的交互流程中，JS主线程可以创建多个Worker子线程，各个Worker线程间相互隔离，并通过序列化传递对象，等到Worker线程完成计算任务，再把结果返回给主线程。 

Actor并发模型的交互原理：各个Actor并发地处理主线程任务，每个Actor内部都有一个消息队列及单线程执行模块，消息队列负责接收主线程及其他Actor的请求，单线程执行模块则负责串行地处理请求、向其他Actor发送请求以及创建新的Actor。由于Actor采用的是异步方式，各个Actor之间相互隔离没有数据竞争，因此Actor可以高并发运行。

### 注意事项
- Worker存在数量限制，当前支持最多同时存在7个Worker。
- 在API version 8及之前的版本，当Worker数量超出限制时，会抛出错误Error "Too many workers, the number of workers exceeds the maximum."。
- 从API version 9开始，当Worker数量超出限制时，会抛出错误BusinessError "Worker initialization failure, the number of workers exceeds the maximum"。
- 主动销毁Worker可以调用新创建Worker对象的terminate()或parentPort.close()方法。
- 自API version 9版本开始，若Worker处于已经销毁或正在销毁等非运行状态时，调用其功能接口，会抛出相应的BusinessError。
- Worker的创建和销毁耗费性能，建议管理已创建的Worker并重复使用。

## 完整示例
> **说明：**<br/>
> 以API version 9的工程为例。<br> API version 8及之前的版本仅支持FA模型，如需使用，注意更换构造Worker的接口和创建worker线程中与主线程通信的对象的两个方法。
### FA模型

```js
// main.js(同级目录为例)
import worker from '@ohos.worker';
// 主线程中创建Worker对象
const workerInstance = new worker.ThreadWorker("workers/worker.ts");
// 创建js和ts文件都可以
// const workerInstance = new worker.ThreadWorker("workers/worker.js");

// API version 9之前版本，worker对象的构造方法
// const workerInstance = new worker.Worker("workers/worker.js");

// 主线程向worker线程传递信息
workerInstance.postMessage("123");

// 主线程接收worker线程信息
workerInstance.onmessage = function(e) {
    // data：worker线程发送的信息
    let data = e.data;
    console.log("main.js onmessage");

    // 销毁Worker对象
    workerInstance.terminate();
}

// 在调用terminate后，执行回调onexit
workerInstance.onexit = function() {
    console.log("main.js terminate");
}
```
```js
// worker.ts
import worker from '@ohos.worker';

// 创建worker线程中与主线程通信的对象
const parentPort = worker.workerPort

// API version 9之前版本，创建worker线程中与主线程通信的对象
// const parentPort = worker.parentPort

// worker线程接收主线程信息
parentPort.onmessage = function(e) {
    // data：主线程发送的信息
    let data = e.data;
    console.log("worker.ts onmessage");

    // worker线程向主线程发送信息
    parentPort.postMessage("123")
}

// worker线程发生error的回调
parentPort.onerror= function(e) {
    console.log("worker.ts onerror");
}
```
build-profile.json5 配置 :
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/MainAbility/workers/worker.ts"
      ]
    }
  }
```
### Stage模型
```js
// main.js（以不同目录为例）
import worker from '@ohos.worker';

// 主线程中创建Worker对象
const workerInstance = new worker.ThreadWorker("entry/ets/pages/workers/worker.ts");
// 创建js和ts文件都可以
// const workerInstance = new worker.ThreadWorker("entry/ets/pages/workers/worker.js");

// 主线程向worker线程传递信息
workerInstance.postMessage("123");

// 主线程接收worker线程信息
workerInstance.onmessage = function(e) {
    // data：worker线程发送的信息
    let data = e.data;
    console.log("main.js onmessage");

    // 销毁Worker对象
    workerInstance.terminate();
}
// 在调用terminate后，执行onexit
workerInstance.onexit = function() {
    console.log("main.js terminate");
}
```
```js
// worker.ts
import worker from '@ohos.worker';

// 创建worker线程中与主线程通信的对象
const parentPort = worker.workerPort

// worker线程接收主线程信息
parentPort.onmessage = function(e) {
    // data：主线程发送的信息
    let data = e.data;
    console.log("worker.ts onmessage");

    // worker线程向主线程发送信息
    parentPort.postMessage("123")
}

// worker线程发生error的回调
parentPort.onerror= function(e) {
    console.log("worker.ts onerror");
}
```
build-profile.json5 配置:
```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/pages/workers/worker.ts"
      ]
    }
  }
```