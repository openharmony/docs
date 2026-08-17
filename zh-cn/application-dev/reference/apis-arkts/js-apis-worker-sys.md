# @ohos.worker (启动一个Worker)(系统接口)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @huanghello-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

Worker是与宿主线程并行的独立线程。创建Worker的线程称为宿主线程，Worker自身的线程称为Worker线程。创建Worker传入的URL文件在Worker线程中执行，可以处理耗时操作但不可以直接操作UI。

Worker的主要作用是为应用程序提供多线程运行环境，使应用程序在执行过程中与宿主线程分离，在后台线程中运行脚本处理耗时操作，避免计算密集型或高延迟任务阻塞宿主线程。由于Worker一旦创建不会主动销毁，若不处于任务状态会一直运行，造成资源浪费，应及时销毁空闲的Worker。

Worker的上下文对象和UI主线程的上下文对象是不同的，Worker线程不支持UI操作。

请查看[Worker注意事项](../../arkts-utils/worker-introduction.md)，了解Worker使用过程中的相关注意点。

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

RestrictedWorker主要用于提供受限的Worker线程运行环境，该线程运行环境中只允许导入Worker模块，不允许导入其他API。

### constructor<sup>11+</sup>

constructor(scriptURL: string, options?: WorkerOptions)

RestrictedWorker构造函数。使用其他方法前，均需先构造RestrictedWorker实例。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| scriptURL | string                          | 是   | Worker线程文件的路径，路径规则详细参考[文件路径注意事项](../../arkts-utils/worker-introduction.md#文件路径注意事项)。 |
| options   | [WorkerOptions](js-apis-worker.md#workeroptions) | 否   | 构造RestrictedWorker时的选项。type默认值为'classic'，name默认'undefined'，shared默认'undefined'，priority默认'MEDIUM'。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200003 | Worker initialization failure. |
| 10200007 | The worker file path is invalid. |

**示例：**

此处以在[Stage模型](../../application-models/stage-model-development-overview.md)中Ability加载Worker文件为例，使用Library加载Worker线程文件的场景参考[文件路径注意事项](../../arkts-utils/worker-introduction.md#文件路径注意事项)。

以下为宿主线程创建RestrictedWorker的示例代码：

```ts
import { worker } from '@kit.ArkTS';

// 主要说明以下两种场景：

// 场景1： worker文件所在路径："entry/src/main/ets/workers/worker.ets"
const workerStageModel01 = new worker.RestrictedWorker('entry/ets/workers/worker.ets', {name: 'first worker in Stage model'});

// 场景2： worker文件所在路径："testworkers/src/main/ets/ThreadFile/workers/worker.ets"
const workerStageModel02 = new worker.RestrictedWorker('testworkers/ets/ThreadFile/workers/worker.ets');
```

受限的Worker线程文件只允许导入Worker模块，不允许导入任何其他API，以下为受限Worker线程文件的示例代码：

```ts
// 受限worker线程文件
import { worker, MessageEvents } from '@kit.ArkTS';

//import { process } from '@kit.ArkTS'; // 受限Worker线程内不允许导入除了worker之外的API。

const workerPort = worker.workerPort;

workerPort.onmessage = (e: MessageEvents): void => {
  console.info('worker:: This is worker thread.');
  //console.info('worker:: worker tid: ' + process.tid) // 执行process.tid，宿主线程会有对应的TypeError报出。
}
```