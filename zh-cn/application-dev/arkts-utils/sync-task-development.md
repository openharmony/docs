# 同步任务开发指导 (TaskPool和Worker)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--SE: @weng-changcheng-->
<!--TSE: @kirl75; @zsw_zhushiwei-->


同步任务用于在多个线程间协调执行，确保任务按特定顺序和规则进行，如使用锁防止数据竞争。


同步任务的实现需要考虑多个线程之间的协作和同步，以确保数据的正确性和程序的正确执行。

当同步任务之间相对独立时，推荐使用TaskPool，例如一系列导入的静态方法或单例实现的方法。如果同步任务之间有关联性，则需要使用Worker。


## 使用TaskPool处理同步任务

以下场景推荐使用TaskPool。

- 调度相互独立的任务。
                        
- 静态方法实现的任务。

- 单例构造的句柄或者类对象跨线程使用。

> **说明：**
>
> 由于[Actor模型](multi-thread-concurrency-overview.md#actor模型)不同线程间内存隔离的特性，普通单例无法在不同线程间使用。可以通过共享模块导出单例解决该问题。

1. 定义并发函数，实现业务逻辑。

2. 创建任务[Task](../reference/apis-arkts/js-apis-taskpool.md#task)，通过[execute()](../reference/apis-arkts/js-apis-taskpool.md#taskpoolexecute-1)接口执行该任务。

3. 对任务返回的结果进行操作。

如下示例中业务使用TaskPool调用相关同步方法的代码，首先定义并发函数taskpoolFunc，需要注意必须使用[@Concurrent装饰器](taskpool-introduction.md#concurrent装饰器)装饰该函数；其次定义函数mainFunc，该函数功能为创建任务，执行任务并处理任务返回的结果。


```ts
// Index.ets
import { taskpool} from '@kit.ArkTS';

// 步骤1: 定义并发函数，实现业务逻辑
@Concurrent
async function taskpoolFunc(num: number): Promise<number> {
  // 根据业务逻辑实现相应的功能
  let tmpNum: number = num + 100;
  return tmpNum;
}

async function mainFunc(): Promise<void> {
  // 步骤2: 创建任务并执行
  let task1: taskpool.Task = new taskpool.Task(taskpoolFunc, 1);
  let res1: number = await taskpool.execute(task1) as number;
  let task2: taskpool.Task = new taskpool.Task(taskpoolFunc, res1);
  let res2: number = await taskpool.execute(task2) as number;
  // 步骤3: 对任务返回的结果进行操作
  console.info("taskpool: task res1 is: " + res1);
  console.info("taskpool: task res2 is: " + res2);
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(async () => {
            mainFunc();
          })
      }
      .width('100%')
      .height('100%')
    }
  }
}
```
<!-- @[taskpool_handle_sync_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/SyncTaskDevelopment.ets) -->


## 使用Worker处理关联的同步任务

当一系列同步任务需要使用同一个句柄调度，或者需要依赖某个类对象调度，且无法在不同任务池之间共享时，需要使用Worker。

1. 在UI主线程中创建Worker对象并接收Worker线程发送的消息。DevEco Studio支持一键生成Worker。在{moduleName}目录下任意位置，点击鼠标右键 > New > Worker，即可生成Worker的模板文件及配置信息。

    ```ts
    // Index.ets
    import { MessageEvents, worker } from '@kit.ArkTS';
    
    @Entry
    @Component
    struct Index {
      @State message: string = 'Hello World';
    
      build() {
        Row() {
          Column() {
            Text(this.message)
              .fontSize(50)
              .fontWeight(FontWeight.Bold)
              .onClick(() => {
                let w: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');
                // 向Worker子线程发送Set消息
                w.postMessage({'type': 0, 'data': 10});
                // 向Worker子线程发送Get消息
                w.postMessage({'type': 1});
                // 接收Worker子线程的结果
                w.onmessage = (e: MessageEvents): void => {
                  // 接收Worker子线程的结果
                  console.info('main thread onmessage, ' + e.data);
                  // 销毁Worker
                  w.terminate();
                }
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```
    <!-- @[worker_handle_associated_sync_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/SyncTaskDevelopment.ets) -->


2. 在Worker线程中绑定Worker对象，同时处理同步任务逻辑。

    ```ts
    // handle.ts代码，与Worker.ets在同级目录下
    export default class Handle {
      id: number = 0;
    
      syncGet(): number {
        return this.id;
      }
    
      syncSet(num: number): boolean {
        this.id = num;
        return true;
      }
    }
    ```
    <!-- @[worker_handle_associated_sync_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/workers/handle.ts) -->
    
    ```ts
    // Worker.ets
    import { worker, ThreadWorkerGlobalScope, MessageEvents } from '@kit.ArkTS';
    // 返回句柄
    import Handle from './handle'; 
    
    let workerPort : ThreadWorkerGlobalScope = worker.workerPort;
    
    // 无法传输的句柄，所有操作依赖此句柄
    let handler: Handle = new Handle();
    
    // Worker线程的onmessage逻辑
    workerPort.onmessage = (e : MessageEvents): void => {
      switch (e.data.type as number) {
        case 0:
          let result: boolean = false;
          result = handler.syncSet(e.data.data);
          console.info("worker: result is " + result);
          workerPort.postMessage('the result of syncSet() is ' + result);
          break;
        case 1:
          let num: number = 0;
          num = handler.syncGet();
          console.info("worker: num is " + num);
          workerPort.postMessage('the result of syncGet() is ' + num);
          break;
      }
    }
    ```
    <!-- @[worker_handle_associated_sync_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/workers/MyWorker2.ts) -->
