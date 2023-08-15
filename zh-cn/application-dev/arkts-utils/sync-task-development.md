# 同步任务开发指导


同步任务是指在多个线程之间协调执行的任务，其目的是确保多个任务按照一定的顺序和规则执行，例如使用锁来防止数据竞争。


同步任务的实现需要考虑多个线程之间的协作和同步，以确保数据的正确性和程序的正确执行。

由于TaskPool偏向于单个独立的任务，因此当各个同步任务之间相对独立时推荐使用TaskPool，例如一系列导入的静态方法，或者单例实现的方法。如果同步任务之间有关联性，则需要使用Worker，例如无法单例创建的类对象实现的方法。


## 使用TaskPool处理同步任务

当调度独立的同步任务，或者一系列同步任务为静态方法实现，或者可以通过单例构造唯一的句柄或类对象，可在不同任务池之间使用时，推荐使用TaskPool。

1. 定义并发函数，内部调用同步方法。

2. 创建任务，并通过TaskPool执行，再对异步结果进行操作。创建[Task](../reference/apis/js-apis-taskpool.md#task)，并通过[execute()](../reference/apis/js-apis-taskpool.md#taskpoolexecute-1)接口执行同步任务。

3. 执行并发操作。

模拟一个包含同步调用的单实例类。


```ts
// Handle.ts 代码
export default class Handle {
  static getInstance() {
    // 返回单例对象
  }

  static syncGet() {
    // 同步Get方法
    return;
  }

  static syncSet(num: number) {
    // 同步Set方法
    return;
  }
}
```

业务使用TaskPool调用相关同步方法的代码。


```ts
// Index.ets代码
import taskpool from '@ohos.taskpool';
import Handle from './Handle'; // 返回静态句柄

// 步骤1: 定义并发函数，内部调用同步方法
@Concurrent
function func(num: number) {
  // 调用静态类对象中实现的同步等待调用
  Handle.syncSet(num);
  // 或者调用单例对象中实现的同步等待调用
  Handle.getInstance().syncGet();
  return true;
}

// 步骤2: 创建任务并执行
async function asyncGet() {
  // 创建task并传入函数func
  let task = new taskpool.Task(func, 1);
  // 执行task任务，获取结果res
  let res = await taskpool.execute(task);
  // 对同步逻辑后的结果进行操作
  console.info(String(res));
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
          .onClick(() => {
            // 步骤3: 执行并发操作
            asyncGet();
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

   ```js
   import worker from '@ohos.worker';

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
               let w = new worker.ThreadWorker('entry/ets/workers/MyWorker.ts');
               w.onmessage = function (d) {
                 // 接收Worker子线程的结果
               }
               w.onerror = function (d) {
                 // 接收Worker子线程的错误信息
               }
               // 向Worker子线程发送Set消息
               w.postMessage({'type': 0, 'data': 'data'})
               // 向Worker子线程发送Get消息
               w.postMessage({'type': 1})
               // 销毁线程
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

   ```js
   // handle.ts代码
   export default class Handle {
     syncGet() {
       return;
     }

     syncSet(num: number) {
       return;
     }
   }

   // Worker.ts代码
   import worker, { ThreadWorkerGlobalScope, MessageEvents } from '@ohos.worker';
   import Handle from './handle.ts'  // 返回句柄

   var workerPort : ThreadWorkerGlobalScope = worker.workerPort;

   // 无法传输的句柄，所有操作依赖此句柄
   var handler = new Handle()

   // Worker线程的onmessage逻辑
   workerPort.onmessage = function(e : MessageEvents) {
     switch (e.data.type) {
       case 0:
         handler.syncSet(e.data.data);
         workerPort.postMessage('success set');
       case 1:
         handler.syncGet();
         workerPort.postMessage('success get');
     }
   }
   ```
