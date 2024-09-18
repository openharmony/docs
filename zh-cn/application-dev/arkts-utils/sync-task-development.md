# 同步任务开发指导 (TaskPool和Worker)


同步任务是指在多个线程之间协调执行的任务，其目的是确保多个任务按照一定的顺序和规则执行，例如使用锁来防止数据竞争。


同步任务的实现需要考虑多个线程之间的协作和同步，以确保数据的正确性和程序的正确执行。

由于TaskPool偏向于单个独立的任务，因此当各个同步任务之间相对独立时推荐使用TaskPool，例如一系列导入的静态方法，或者单例实现的方法。如果同步任务之间有关联性，则需要使用Worker，例如无法单例创建的类对象实现的方法。


## 使用TaskPool处理同步任务

当调度独立的任务，或者一系列任务为静态方法实现，或者可以通过单例构造唯一的句柄或类对象，可在不同任务线程之间使用时，推荐使用TaskPool。

> **说明：**
>
> 由于[Actor模型](actor-model-development-samples.md#actor并发模型对比内存共享并发模型)不同线程间内存隔离的特性，普通单例无法在不同线程间使用。可以通过共享模块导出单例解决该问题。

1. 定义并发函数，内部调用同步方法。

2. 创建任务[Task](../reference/apis-arkts/js-apis-taskpool.md#task)，通过[execute()](../reference/apis-arkts/js-apis-taskpool.md#taskpoolexecute-1)接口执行该任务，并对任务返回的结果进行操作。

3. 执行并发操作。

模拟一个包含同步调用的单实例类。


```ts
// Handle.ets 代码
"use shared"

@Sendable
export default class Handle {
  private static instance: Handle = new Handle();
  static getInstance(): Handle {
    // 返回单例对象
    return Handle.instance;
  }

  static syncGet(): void {
    // 同步Get方法
  }

  static syncSet(num: number): number {
    // 模拟同步步骤1
    console.info("taskpool: this is 1st print!");
    // 模拟同步步骤2
    console.info("taskpool: this is 2nd print!");
    return ++num;
  }

  static syncSet2(num: number): number {
    // 模拟同步步骤1
    console.info("taskpool: this is syncSet2 1st print!");
    // 模拟同步步骤2
    console.info("taskpool: this is syncSet2 2nd print!");
    return ++num;
  }
}
```


如下示例中业务使用TaskPool调用相关同步方法的代码，首先定义并发函数func，需要注意必须使用[@Concurrent装饰器](../arkts-utils/arkts-concurrent.md#concurrent装饰器声明并校验并发函数)装饰该函数；其次定义函数asyncGet，该函数功能为创建任务，执行对应任务并打印其返回的结果；最后在主线程调用函数asyncGet，观察其执行过程。


```ts
// Index.ets代码
import { taskpool} from '@kit.ArkTS';
import Handle from './Handle'; // 返回静态句柄

// 步骤1: 定义并发函数，内部调用同步方法
@Concurrent
async function func(num: number): Promise<number> {
  // 调用静态类对象中实现的同步等待调用
  // 先调用syncSet方法并将其结果作为syncSet2的参数，模拟同步调用逻辑
  let tmpNum: number = Handle.syncSet(num);
  console.info("this is Child_Thread")
  return Handle.syncSet2(tmpNum);
}

// 步骤2: 创建任务并执行
async function asyncGet(): Promise<void> {
  // 创建task、task2并传入函数func
  let task: taskpool.Task = new taskpool.Task(func, 1);
  let task2: taskpool.Task = new taskpool.Task(func, 2);
  // 执行task、task2任务，await保证其同步执行
  let res: number = await taskpool.execute(task) as number;
  let res2: number = await taskpool.execute(task2) as number;
  // 打印任务结果
  console.info("taskpool: task res is: " + res);
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
            // 步骤3: 执行并发操作
            asyncGet();
            let num: number = Handle.syncSet(100);
            console.info("this is Main_Thread!")
          })
      }
      .width('100%')
      .height('100%')
    }
  }
}
```


## 使用Worker处理关联的同步任务

当一系列同步任务需要使用同一个句柄调度，或者需要依赖某个类对象调度，无法在不同任务池之间共享时，需要使用Worker。

1. 在主线程中创建Worker对象，同时接收Worker线程发送回来的消息。

    ```ts
    // Index.ets
    import { worker } from '@kit.ArkTS';
    
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
                let w: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/MyWorker.ts');
                w.onmessage = (): void => {
                  // 接收Worker子线程的结果
                }
                w.onerror = (): void => {
                  // 接收Worker子线程的错误信息
                }
                // 向Worker子线程发送Set消息
                w.postMessage({'type': 0, 'data': 'data'})
                // 向Worker子线程发送Get消息
                w.postMessage({'type': 1})
                // ...
                // 根据实际业务，选择时机以销毁线程
                w.terminate()
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```


2. 在Worker线程中绑定Worker对象，同时处理同步任务逻辑。

    ```ts
    // handle.ts代码
    export default class Handle {
      syncGet() {
        return;
      }
    
      syncSet(num: number) {
        return;
      }
    }
    ```
    
    ```ts
    // MyWorker.ts代码
    import { worker, ThreadWorkerGlobalScope, MessageEvents } from '@kit.ArkTS';
    import Handle from './handle';  // 返回句柄
    
    let workerPort : ThreadWorkerGlobalScope = worker.workerPort;
    
    // 无法传输的句柄，所有操作依赖此句柄
    let handler: Handle = new Handle()
    
    // Worker线程的onmessage逻辑
    workerPort.onmessage = (e : MessageEvents): void => {
     switch (e.data.type as number) {
      case 0:
       handler.syncSet(e.data.data);
       workerPort.postMessage('success set');
       break;
      case 1:
       handler.syncGet();
       workerPort.postMessage('success get');
       break;
     }
    }
    ```
