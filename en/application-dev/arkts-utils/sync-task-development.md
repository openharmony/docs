# Synchronous Task Development (TaskPool and Worker)


Synchronous tasks are executed in order among multiple threads. Synchronization primitives, such as locks, are used by these tasks for coordination between each other.


To implement synchronous tasks, you must consider the collaboration and synchronization between multiple threads and ensure the correctness of data and program execution.

If synchronous tasks are independent of each other, you are advised to use **TaskPool**, which focuses on single independent tasks. For example, a series of imported static methods or methods implemented in singletons are independent. If synchronous tasks are associated with each other, use **Worker**, for example, methods implemented in class objects (not singleton class objects).


## Using TaskPool to Process Independent Synchronous Tasks

**TaskPool** is recommended for scheduling independent tasks. Typical independent tasks are those using static methods. If a unique handle or class object constructed using a singleton points to multiple tasks and these tasks can be used between different worker threads, you can also use **TaskPool**.

> **NOTE**
>
> Due to the memory isolation feature between different threads in the [Actor model](multi-thread-concurrency-overview.md#actor-model), common singletons cannot be used between different threads. This issue can be solved by exporting a singleton through the sendable module.

1. Define concurrent functions to implement service logic.

2. Create a task [Task](../reference/apis-arkts/js-apis-taskpool.md#task) and execute the task through the [execute()](../reference/apis-arkts/js-apis-taskpool.md#taskpoolexecute-1) interface.

3. Perform operations on the task result.

In the following example, the service uses TaskPool to call the code of the related synchronization method. Define the concurrent function taskpoolFunc first. Note that the function must be decorated by the [@Concurrent decorator](taskpool-introduction.md#concurrent-decorator). Define the mainFunc function. This function is used to create and execute a task and perform operations on the returned result of the task.


```ts
// Index.ets code
import { taskpool} from '@kit.ArkTS';

// Step 1: Define a concurrent function to implement the service logic.
@Concurrent
async function taskpoolFunc(num: number): Promise<number> {
  // Implement the corresponding function based on the service logic.
  let tmpNum: number = num + 100;
  return tmpNum;
}

async function mainFunc(): Promise<void> {
  // Step 2: Create and execute a task.
  let task1: taskpool.Task = new taskpool.Task(taskpoolFunc, 1);
  let res1: number = await taskpool.execute(task1) as number;
  let task2: taskpool.Task = new taskpool.Task(taskpoolFunc, res1);
  let res2: number = await taskpool.execute(task2) as number;
  // Step 3: Perform operations on the returned task result.
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


## Using Worker to Process Associated Synchronous Tasks

Use **Worker** when you want to schedule a series of synchronous tasks using the same handle or depending on the same class object.

1. Create a **Worker** object in the main thread and receive messages from the worker thread. DevEco Studio supports one-click Worker generation. Right-click any position in the {moduleName} directory and choose New > Worker from the shortcut menu to automatically generate the Worker template file and configuration information.

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
                  // Receive the result of the worker thread.
                }
                w.onerror = (): void => {
                  // Receive error information of the worker thread.
                }
                // Send a Set message to the worker thread.
                w.postMessage({'type': 0, 'data': 'data'})
                // Send a Get message to the worker thread.
                w.postMessage({'type': 1})
                // ...
                // Select a time to destroy the thread based on the actual situation.
                w.terminate()
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```


2. Bind the **Worker** object in the worker thread and process the synchronous task logic.

    ```ts
    // handle.ts code
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
    // MyWorker.ts code
    import { worker, ThreadWorkerGlobalScope, MessageEvents } from '@kit.ArkTS';
    import Handle from './handle'  // Return a handle.
    
    let workerPort : ThreadWorkerGlobalScope = worker.workerPort;
    
    // Handle that cannot be transferred. All operations depend on this handle.
    let handler: Handle = new Handle()
    
    // onmessage() logic of the worker thread.
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
