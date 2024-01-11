# @ohos.worker (启动一个Worker)

Worker是与主线程并行的独立线程。创建Worker的线程称之为宿主线程，Worker自身的线程称之为Worker线程。创建Worker传入的url文件在Worker线程中执行，可以处理耗时操作但不可以直接操作UI。

Worker主要作用是为应用程序提供一个多线程的运行环境，可满足应用程序在执行过程中与主线程分离，在后台线程中运行一个脚本操作耗时操作，极大避免类似于计算密集型或高延迟的任务阻塞主线程的运行。由于Worker一旦被创建则不会主动被销毁，若不处于任务状态一直运行，在一定程度上会造成资源的浪费，应及时关闭空闲的Worker。

Worker的上下文对象和主线程的上下文对象是不同的，Worker线程不支持UI操作。

Worker使用过程中的相关注意点请查[Worker注意事项](../../arkts-utils/worker-introduction.md#worker注意事项)

> **说明：**
>
> 本模块首批接口从API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import worker from '@ohos.worker';
```

## 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称                              | 类型                                                         | 可读 | 可写 | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| workerPort<sup>9+</sup>           | [ThreadWorkerGlobalScope](#threadworkerglobalscope9)         | 是   | 是   | worker线程用于与宿主线程通信的对象。          |
## WorkerOptions

Worker构造函数的选项信息，用于为Worker添加其他信息。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 必填 | 说明 |
| ---- | -------- | ---- | ---- | -------------- |
| type | "classic" \| "module" | 是   | 否 | Worker执行脚本的模式类型，暂不支持module类型，默认值为"classic"。 |
| name | string   | 是   | 否 | Worker的名称，默认值为 undefined 。 |

## Event

事件的基础类。

**系统能力：** SystemCapability.Utils.Lang

## WorkerEventTarget<sup>9+</sup>

Worker监听事件基础类。

**系统能力：** SystemCapability.Utils.Lang

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

## MessageEvents<sup>9+</sup>

消息类，持有Worker线程间传递的数据。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明               |
| ---- | ---- | ---- | ---- | ------------------ |
| data | any  | 是   | 否   | 线程间传递的数据。 |

## PostMessageOptions

明确数据传递过程中需要转移所有权对象的类，传递所有权的对象必须是ArrayBuffer，发送它的上下文中将会变为不可用，仅在接收方可用。

**系统能力：** SystemCapability.Utils.Lang

| 名称     | 类型     | 可读 | 可写 | 说明                              |
| -------- | -------- | ---- | ---- | --------------------------------- |
| transfer | Object[] | 是   | 是   | ArrayBuffer数组，用于传递所有权。该数组中不可传入null。 |

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

```ts
// main thread
import worker from '@ohos.worker';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts")
```

```ts
// worker.ts
import worker from '@ohos.worker';

const workerPort = worker.workerPort
workerPort.onerror = () => {
    console.log("worker.ts onerror")
}
```

## ThreadWorkerGlobalScope<sup>9+</sup>

Worker线程用于与宿主线程通信的类，通过postMessage接口发送消息给宿主线程、close接口销毁Worker线程。ThreadWorkerGlobalScope类继承[GlobalScope<sup>9+</sup>](#globalscope9)。

### postMessage<sup>9+</sup>

postMessage(messageObject: Object, transfer: ArrayBuffer[]): void

Worker线程通过转移对象所有权的方式向宿主线程发送消息。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| message  | Object        | 是   | 发送至宿主线程的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |
| transfer | ArrayBuffer[] | 是   | 表示可转移的ArrayBuffer实例对象数组，该数组中对象的所有权会被转移到宿主线程，在Worker线程中将会变为不可用，仅在宿主线程中可用，数组不可传入null。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                |
| -------- | ----------------------------------------- |
| 10200004 | Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**示例：**

```ts
// main thread
import worker, { MessageEvents } from '@ohos.worker';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
workerInstance.postMessage("hello world");
workerInstance.onmessage = (e: MessageEvents): void => {
    console.log("receive data from worker.ts");
}
```

```ts
// worker.ts
import worker, { MessageEvents } from '@ohos.worker';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
    let buffer = new ArrayBuffer(8);
    workerPort.postMessage(buffer, [buffer]);
}
```

### postMessage<sup>9+</sup>

postMessage(messageObject: Object, options?: PostMessageOptions): void

Worker线程通过转移对象所有权或者拷贝数据的方式向宿主线程发送消息。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | 是   | 发送至宿主线程的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |
| options | [PostMessageOptions](#postmessageoptions) | 否   | 当填入该参数时，与传入ArrayBuffer[]的作用一致，该数组中对象的所有权会被转移到宿主线程，在Worker线程中将会变为不可用，仅在宿主线程中可用。<br/>若不填入该参数，默认设置为 undefined，通过拷贝数据的方式传输信息到宿主线程。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                |
| -------- | ----------------------------------------- |
| 10200004 | Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**示例：**

```ts
// main thread
import worker, { MessageEvents } from '@ohos.worker';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
workerInstance.postMessage("hello world");
workerInstance.onmessage = (e: MessageEvents): void => {
    console.log("receive data from worker.ts");
}
```

```ts
// worker.ts
import worker, { MessageEvents } from '@ohos.worker';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
    workerPort.postMessage("receive data from main thread");
}
```

### onmessage<sup>9+</sup>

onmessage?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) =&gt; void

ThreadWorkerGlobalScope的onmessage属性表示Worker线程收到来自其宿主线程通过postMessage接口发送的消息时被调用的事件处理程序，处理程序在Worker线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                                                 | 必填 | 说明                     |
| ------ | ---------------------------------------------------- | ---- | ------------------------ |
| this   | [ThreadWorkerGlobalScope](#threadworkerglobalscope9) | 是   | 指向调用者对象。         |
| ev     | [MessageEvents](#messageevents9)                     | 是   | 收到宿主线程发送的数据。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                   |
| -------- | -------------------------------------------- |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**示例：**

```ts
// main thread
import worker from '@ohos.worker';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
workerInstance.postMessage("hello world");
```

```ts
// worker.ts
import worker, { MessageEvents } from '@ohos.worker';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
    console.log("receive main thread message");
}
```

### onmessageerror<sup>9+</sup>

onmessageerror?: (this: ThreadWorkerGlobalScope, ev: MessageEvents) =&gt; void

ThreadWorkerGlobalScope的onmessageerror属性表示当Worker对象接收到一条无法被反序列化的消息时被调用的事件处理程序，处理程序在Worker线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                             | 必填 | 说明       |
| ------ | -------------------------------- | ---- | ---------- |
| this   | [ThreadWorkerGlobalScope](#threadworkerglobalscope9) | 是   | 指向调用者对象。         |
| ev     | [MessageEvents](#messageevents9) | 是   | 异常数据。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                   |
| -------- | -------------------------------------------- |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**示例：**

```ts
// main thread
import worker from '@ohos.worker';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
```

```ts
// worker.ts
import worker from '@ohos.worker';

const workerPort = worker.workerPort;
workerPort.onmessageerror = () => {
    console.log("worker.ts onmessageerror")
}
```

### close<sup>9+</sup>

close(): void

销毁Worker线程，终止Worker接收消息。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                      |
| -------- | ------------------------------- |
| 10200004 | Worker instance is not running. |

**示例：**

```ts
// main thread
import worker from '@ohos.worker';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
```

```ts
// worker.ts
import worker, { MessageEvents } from '@ohos.worker';

const workerPort = worker.workerPort;
workerPort.onmessage = (e: MessageEvents): void => {
    workerPort.close()
}
```

## ThreadWorker<sup>9+</sup>

使用以下方法前，均需先构造ThreadWorker实例，ThreadWorker类继承[WorkerEventTarget](#workereventtarget9)。

### constructor<sup>9+</sup>

constructor(scriptURL: string, options?: WorkerOptions)

ThreadWorker构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | 是   | Worker执行脚本的路径。<br/>在FA和Stage模型下，DevEco Studio新建Worker工程路径分别存在以下两种情况：<br/>(a) worker脚本所在目录与pages目录同级。<br/>(b) worker脚本所在目录与pages目录不同级。 |
| options   | [WorkerOptions](#workeroptions) | 否   | Worker构造的选项。                                           |

**返回值：**

| 类型         | 说明                                                         |
| ------------ | ------------------------------------------------------------ |
| ThreadWorker | 执行ThreadWorker构造函数生成的ThreadWorker对象，失败则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200003 | Worker initialization failure. |
| 10200007 | The worker file patch is invalid path. |

**示例：**

```ts
import worker from '@ohos.worker';

// worker线程创建
// FA模型-目录同级（entry模块下，workers目录与pages目录同级）
const workerFAModel01 = new worker.ThreadWorker("workers/worker.ts", {name:"first worker in FA model"});
// FA模型-目录不同级（entry模块下，workers目录与pages目录的父目录同级）
const workerFAModel02 = new worker.ThreadWorker("../workers/worker.ts");

// Stage模型-目录同级（entry模块下，workers目录与pages目录同级）
const workerStageModel01 = new worker.ThreadWorker('entry/ets/workers/worker.ts', {name:"first worker in Stage model"});
// Stage模型-目录不同级（entry模块下，workers目录是pages目录的子目录）
const workerStageModel02 = new worker.ThreadWorker('entry/ets/pages/workers/worker.ts');

// 理解Stage模型scriptURL的"entry/ets/workers/worker.ts"：
// entry: 为module.json5文件中module的name属性对应的值，ets: 表明当前使用的语言。
// scriptURL与worker文件所在的workers目录层级有关，与new worker所在文件无关。
```

同时，需在工程的模块级build-profile.json5文件的buildOption属性中添加配置信息，主要分为下面两种情况：

(1) 目录同级

FA模型:

```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/entryability/workers/worker.ts"
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

postMessage(message: Object, transfer: ArrayBuffer[]): void

宿主线程通过转移对象所有权的方式向Worker线程发送消息。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| message  | Object        | 是   | 发送至Worker的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |
| transfer | ArrayBuffer[] | 是   | 表示可转移的ArrayBuffer实例对象数组，该数组中对象的所有权会被转移到Worker线程，在宿主线程中将会变为不可用，仅在Worker线程中可用，数组不可传入null。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                |
| -------- | ----------------------------------------- |
| 10200004 | Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**示例：**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");

let buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```

### postMessage<sup>9+</sup>

postMessage(message: Object, options?: PostMessageOptions): void

宿主线程通过转移对象所有权或者拷贝数据的方式向Worker线程发送消息。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                                      | 必填 | 说明                                                         |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| message | Object                                    | 是   | 发送至Worker的数据，该数据对象必须是可序列化，序列化支持类型见[其他说明](#序列化支持类型)。 |
| options | [PostMessageOptions](#postmessageoptions) | 否   | 当填入该参数时，与传入ArrayBuffer[]的作用一致，该数组中对象的所有权会被转移到Worker线程，在宿主线程中将会变为不可用，仅在Worker线程中可用。<br>若不填入该参数，默认设置为 undefined，通过拷贝数据的方式传输信息到Worker线程。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                |
| -------- | ----------------------------------------- |
| 10200004 | Worker instance is not running.           |
| 10200006 | An exception occurred during serialization. |

**示例：**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");

workerInstance.postMessage("hello world");

let buffer = new ArrayBuffer(8);
workerInstance.postMessage(buffer, [buffer]);
```

### terminate<sup>9+</sup>

terminate(): void

销毁Worker线程，终止Worker接收消息。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                      |
| -------- | ------------------------------- |
| 10200004 | Worker instance is not running. |

**示例：**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
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

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                   |
| -------- | -------------------------------------------- |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**示例：**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
workerInstance.onexit = () => {
 console.log("onexit");
}

//onexit被执行两种方式：
// main thread：
workerInstance.terminate();

// worker线程：
//workerPort.close()
```

### onerror<sup>9+</sup>

onerror?: (err: ErrorEvent) =&gt; void

Worker对象的onerror属性表示Worker在执行过程中发生异常被调用的事件处理程序，处理程序在宿主线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| err    | [ErrorEvent](#errorevent) | 是   | 异常数据。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                   |
| -------- | -------------------------------------------- |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**示例：**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
workerInstance.onerror = () => {
    console.log("onerror");
}
```


### onmessage<sup>9+</sup>

onmessage?: (event: MessageEvents) =&gt; void

Worker对象的onmessage属性表示宿主线程接收到来自其创建的Worker通过workerPort.postMessage接口发送的消息时被调用的事件处理程序，处理程序在宿主线程中执行。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                             | 必填 | 说明                   |
| ------ | -------------------------------- | ---- | ---------------------- |
| event  | [MessageEvents](#messageevents9) | 是   | 收到的Worker消息数据。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                   |
| -------- | -------------------------------------------- |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**示例：**

```ts
import worker, { MessageEvents } from '@ohos.worker';

const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
workerInstance.onmessage = (e: MessageEvents): void => {
 // e : MessageEvents, 用法如下：
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

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息                                   |
| -------- | -------------------------------------------- |
| 10200004 | Worker instance is not running.              |
| 10200005 | The invoked API is not supported in workers. |

**示例：**

```ts
const workerInstance = new worker.ThreadWorker("entry/ets/workers/worker.ts");
workerInstance.onmessageerror= () => {
    console.log("onmessageerror");
}
```