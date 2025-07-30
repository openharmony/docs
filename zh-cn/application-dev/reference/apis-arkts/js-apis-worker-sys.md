# @ohos.worker (启动一个Worker)(系统接口)
<!--Kit: ArkTS-->
<!--Subsystem: commonlibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

Worker是与主线程并行的独立线程。创建Worker的线程称之为宿主线程，Worker自身的线程称之为Worker线程。创建Worker传入的url文件在Worker线程中执行，可以处理耗时操作但不可以直接操作UI。

Worker主要作用是为应用程序提供一个多线程的运行环境，可满足应用程序在执行过程中与宿主线程分离，在后台线程中运行一个脚本操作耗时操作，极大避免类似于计算密集型或高延迟的任务阻塞宿主线程的运行。由于Worker一旦被创建则不会主动被销毁，若不处于任务状态一直运行，在一定程度上会造成资源的浪费，应及时关闭空闲的Worker。

Worker的上下文对象和UI主线程的上下文对象是不同的，Worker线程不支持UI操作。

Worker使用过程中的相关注意点请查[Worker注意事项](../../arkts-utils/worker-introduction.md#worker注意事项)。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.worker (启动一个Worker)](js-apis-worker.md)。

## 导入模块

```ts
import { worker } from '@kit.ArkTS';
```

## RestrictedWorker<sup>11+</sup>

RestrictedWorker类继承[ThreadWorker<sup>9+</sup>](js-apis-worker.md#threadworker9)，具有ThreadWorker中所有的方法。
RestrictedWorker主要作用是提供受限的Worker线程运行环境，该线程运行环境中只允许导入Worker模块，不允许导入其他API。

### constructor<sup>11+</sup>

constructor(scriptURL: string, options?: WorkerOptions)

RestrictedWorker构造函数。使用以下方法前，均需先构造RestrictedWorker实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | 是   | Worker线程文件的路径，路径规则详细参考[文件路径注意事项](../../arkts-utils/worker-introduction.md#文件路径注意事项)。 |
| options   | [WorkerOptions](js-apis-worker.md#workeroptions) | 否   | RestrictedWorker构造的选项。                                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200003 | Worker initialization failure. |
| 10200007 | The worker file patch is invalid path. |

**示例：**

此处以在Stage模型中Ability加载Worker文件为例，使用Library加载Worker线程文件的场景参考[文件路径注意事项](../../arkts-utils/worker-introduction.md#文件路径注意事项)。

受限的Worker线程文件只允许导入Worker模块，不允许导入任何其他API，以下为示例代码：

```ts
import { worker } from '@kit.ArkTS';

// 主要说明以下两种场景：

// 场景1： worker文件所在路径："entry/src/main/ets/workers/worker.ets"
const workerStageModel01 = new worker.RestrictedWorker('entry/ets/workers/worker.ets', {name:"first worker in Stage model"});

// 场景2： worker文件所在路径："testworkers/src/main/ets/ThreadFile/workers/worker.ets"
const workerStageModel02 = new worker.RestrictedWorker('testworkers/ets/ThreadFile/workers/worker.ets');
```

```ts
// 受限worker线程文件
import { worker, MessageEvents } from '@kit.ArkTS';

//import { process } from '@kit.ArkTS'; // 受限Worker线程内不允许导入除了worker之外的API。

const workerPort = worker.workerPort;

workerPort.onmessage = (e : MessageEvents) : void => {
  console.info("worker:: This is worker thread.");
  //console.info("worker:: worker tid: " + process.tid) // 执行process.tid，宿主线程会有对应的TypeError报出。
}
```