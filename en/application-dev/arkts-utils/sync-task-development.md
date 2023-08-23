# Synchronous Task Development


Synchronous tasks are executed in order among multiple threads. For example, as a synchronization primitive, locks prevent data contention.


To implement synchronous tasks, you must consider the collaboration and synchronization between multiple threads and ensure the correctness of data and the correct execution of programs.

If synchronous tasks are independent of each other, you are advised to use **TaskPool**, since it focuses on single independent tasks. For example, a series of imported static methods or methods implemented in singletons are independent. If synchronous tasks are associated with each other, use **Worker**, for example, methods implemented in class objects (not singleton class objects).


## Using TaskPool to Process Independent Synchronous Tasks

**TaskPool** is recommended for scheduling independent synchronous tasks. Typical synchronous tasks are those using static methods. If a unique handle or class object constructed using a singleton points to multiple tasks and these tasks can be used between different worker threads, you can also use **TaskPool**.

1. Define a concurrency function that internally calls the synchronous methods.

2. Create a task, execute the task through **TaskPool**, and perform operations on the asynchronous result. Create a [task](../reference/apis/js-apis-taskpool.md#task) and call [execute()](../reference/apis/js-apis-taskpool.md#taskpoolexecute-1) to execute the task synchronously.

3. Perform concurrent operations.

Simulate a singleton class that contains synchronous calls.


```ts
// handle.ts code
export default class Handle {
  static getInstance() {
    // Return a singleton object.
  }

  static syncGet() {
    // Synchronous getter.
    return;
  }

  static syncSet(num: number) {
    // Synchronous setter.
    return;
  }
}
```

Use **TaskPool** to call the related synchronous methods.


```ts
// Index.ets code
import taskpool from '@ohos.taskpool';
import Handle from './Handle'; // Return a static handle.

// Step 1: Define a concurrency function that internally calls the synchronous methods.
@Concurrent
function func(num: number) {
  // Call the synchronous wait implemented in a static class object.
  Handle.syncSet(num);
  // Alternatively, call the synchronous wait implemented in a singleton object.
  Handle.getInstance().syncGet();
  return true;
}

// Step 2: Create and execute a task.
async function asyncGet() {
  // Create a task and pass in the function func.
  let task = new taskpool.Task(func, 1);
  // Execute the task and obtain the result res.
  let res = await taskpool.execute(task);
  // Perform operations on the synchronous result.
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
            // Step 3: Perform concurrent operations.
            asyncGet();
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
                 // Receive the result of the worker thread.
               }
               w.onerror = function (d) {
                 // Receive error information of the worker thread.
               }
               // Send a Set message to the worker thread.
               w.postMessage({'type': 0, 'data': 'data'})
               // Send a Get message to the worker thread.
               w.postMessage({'type': 1})
               // Destroy the worker thread.
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

   ```js
   // handle.ts code
   export default class Handle {
     syncGet() {
       return;
     }

     syncSet(num: number) {
       return;
     }
   }

   // Worker.ts code
   import worker, { ThreadWorkerGlobalScope, MessageEvents } from '@ohos.worker';
   import Handle from './handle.ts' // Return a handle.

   var workerPort : ThreadWorkerGlobalScope = worker.workerPort;

   // Handle that cannot be transferred. All operations depend on this handle.
   var handler = new Handle()

   // onmessage() logic of the worker thread.
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
