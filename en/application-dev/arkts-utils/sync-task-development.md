# Synchronous Task Development (TaskPool and Worker)


Synchronous tasks are executed in order among multiple threads. Synchronization primitives, such as locks, are used by these tasks for coordination between each other.


To implement synchronous tasks, you must consider the collaboration and synchronization between multiple threads and ensure the correctness of data and program execution.

If synchronous tasks are independent of each other, you are advised to use **TaskPool**, which focuses on single independent tasks. For example, a series of imported static methods or methods implemented in singletons are independent. If synchronous tasks are associated with each other, use **Worker**, for example, methods implemented in class objects (not singleton class objects).


## Using TaskPool to Process Independent Synchronous Tasks

**TaskPool** is recommended for scheduling independent tasks. Typical independent tasks are those using static methods. If a unique handle or class object constructed using a singleton points to multiple tasks and these tasks can be used between different worker threads, you can also use **TaskPool**.

> **NOTE**
>
> Due to memory isolation between different threads in the [Actor model](actor-model-development-samples.md), common singletons cannot be used across threads. This issue can be solved by exporting a singleton through the sendable module.

1. Define a concurrency function that internally calls the synchronous methods.

2. Create a [task](../reference/apis-arkts/js-apis-taskpool.md#task), call [execute()](../reference/apis-arkts/js-apis-taskpool.md#taskpoolexecute-1) to execute the task, and perform operations on the result returned by the task.

3. Perform concurrent operations.

Simulate a singleton class that contains synchronous calls.


```ts
// Handle.ets code
"use shared"

@Sendable
export default class Handle {
  private static instance: Handle = new Handle();
  static getInstance(): Handle {
    // Return a singleton object.
    return Handle.instance;
  }

  static syncGet(): void {
    // Synchronous getter.
  }

  static syncSet(num: number): number {
    // Simulate synchronization step 1.
    console.info("taskpool: this is 1st print!");
    // Simulate synchronization step 2.
    console.info("taskpool: this is 2nd print!");
    return ++num;
  }

  static syncSet2(num: number): number {
    // Simulate synchronization step 1.
    console.info("taskpool: this is syncSet2 1st print!");
    // Simulate synchronization step 2.
    console.info("taskpool: this is syncSet2 2nd print!");
    return ++num;
  }
}
```


In the following example, **TaskPool** is used to call related synchronous methods. Specifically, define the concurrent function **func**, which is decorated using the [@Concurrent decorator](../arkts-utils/arkts-concurrent.md). Then define the **asyncGet** function, which is used to create a task, execute the task, and print the returned result. Finally, call the **asyncGet** function in the main thread and observe the execution process.


```ts
// Index.ets code
import { taskpool} from '@kit.ArkTS';
import Handle from './Handle'; // Return a static handle.

// Step 1: Define a concurrency function that internally calls the synchronous methods.
@Concurrent
async function func(num: number): Promise<number> {
  // Call the synchronous wait implemented in a static class object.
  // Call syncSet and use its result as an input parameter of syncSet2 to simulate the synchronous call logic.
  let tmpNum: number = Handle.syncSet(num);
  console.info("this is Child_Thread")
  return Handle.syncSet2(tmpNum);
}

// Step 2: Create and execute a task.
async function asyncGet(): Promise<void> {
  // Create task and task2 and pass in the function func.
  let task: taskpool.Task = new taskpool.Task(func, 1);
  let task2: taskpool.Task = new taskpool.Task(func, 2);
  // Execute task and task2 synchronously by using await.
  let res: number = await taskpool.execute(task) as number;
  let res2: number = await taskpool.execute(task2) as number;
  // Print the task result.
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
            // Step 3: Perform concurrent operations.
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


## Using Worker to Process Associated Synchronous Tasks

Use **Worker** when you want to schedule a series of synchronous tasks using the same handle or depending on the same class object.

1. Create a **Worker** object in the main thread and receive messages from the worker thread.

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
