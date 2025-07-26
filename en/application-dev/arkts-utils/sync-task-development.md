# Synchronous Task Development (TaskPool and Worker)


Synchronous tasks involve coordinating execution across multiple threads to ensure that tasks run in a specific order and adhere to certain rules, such as using locks to prevent data races.


To implement synchronous tasks, you must consider the collaboration and synchronization between multiple threads and ensure data integrity and correct program execution.

TaskPool is well-suited for individual, independent tasks. Therefore, it is recommended for scenarios where synchronous tasks are relatively independent, such as a series of static methods or methods implemented using a singleton pattern. Conversely, if synchronous tasks are interdependent, Worker is the better choice.


## Using TaskPool for Independent Synchronous Tasks

TaskPool is recommended in the following scenarios:

- Tasks that are scheduled independently.
                        
- Tasks that are implemented using static methods.

- Singleton handles or class objects used across threads.

> **NOTE**
>
> Due to the memory isolation feature of the [actor model](multi-thread-concurrency-overview.md#actor-model) between threads, regular singletons cannot be shared across threads. This issue can be solved by exporting singletons through sendable modules.

1. Define a concurrent function to implement service logic.

2. Create a [task](../reference/apis-arkts/js-apis-taskpool.md#task), and execute the task using the [execute()](../reference/apis-arkts/js-apis-taskpool.md#taskpoolexecute-1) interface.

3. Perform operations on the task result.

In the following example, the service logic uses TaskPool to call related synchronous methods. First, define the concurrent function **taskpoolFunc**, which must be decorated with [@Concurrent](taskpool-introduction.md#concurrent-decorator). Then, define the function **mainFunc**, which creates tasks, executes them, and processes the results returned by the tasks.


```ts
// Index.ets code
import { taskpool} from '@kit.ArkTS';

// Step 1: Define a concurrent function to implement service logic.
@Concurrent
async function taskpoolFunc(num: number): Promise<number> {
  // Implement the corresponding functionality based on the service logic.
  let tmpNum: number = num + 100;
  return tmpNum;
}

async function mainFunc(): Promise<void> {
  // Step 2: Create and execute a task.
  let task1: taskpool.Task = new taskpool.Task(taskpoolFunc, 1);
  let res1: number = await taskpool.execute(task1) as number;
  let task2: taskpool.Task = new taskpool.Task(taskpoolFunc, res1);
  let res2: number = await taskpool.execute(task2) as number;
  // Step 3: Perform operations on the result returned by the task.
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
<!-- @[taskpool_handle_sync_task](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/SyncTaskDevelopment.ets) -->


## Using Worker for Interdependent Synchronous Tasks

When a series of synchronous tasks needs to be scheduled using the same handle, or when they depend on a specific class object that cannot be shared across different task pools, Worker is the appropriate choice.

1. Create a Worker object in the UI main thread and receive messages from the Worker thread. DevEco Studio supports generation of Worker templates with a single click. In the corresponding {moduleName} directory, right-click anywhere and choose **New > Worker** to automatically generate the Worker template files and configuration information.

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
                  // Receive results from the Worker thread.
                }
                w.onAllErrors = (): void => {
                  // Receive error messages from the Worker thread.
                }
                // Send a Set message to the Worker thread.
                w.postMessage({'type': 0, 'data': 'data'})
                // Send a Get message to the Worker thread.
                w.postMessage({'type': 1})
                // ...
                // Destroy the thread based on actual service requirements.
                w.terminate()
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```
    <!-- @[worker_handle_associated_sync_task](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/SyncTaskDevelopment.ets) -->


2. Bind the Worker object in the Worker thread and process the synchronous task logic.

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
    <!-- @[worker_handle_associated_sync_task](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/workers/handle.ts) -->
    
    ```ts
    // MyWorker.ts code
    import { worker, ThreadWorkerGlobalScope, MessageEvents } from '@kit.ArkTS';
    import Handle from './handle'  // Import the handle.
    
    let workerPort : ThreadWorkerGlobalScope = worker.workerPort;
    
    // Handle that cannot be transferred. All operations depend on this handle.
    let handler: Handle = new Handle()
    
    // onmessage() logic of the Worker thread.
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
    <!-- @[worker_handle_associated_sync_task](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/workers/MyWorker2.ts) -->
