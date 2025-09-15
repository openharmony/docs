# Common Concurrency Issues
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

## Troubleshooting for Non-Executing Tasks in the TaskPool

If a task in a TaskPool is not executed, perform the following steps to quickly locate the fault:

1. Check whether the **taskpool.execute** API is called.

   When the **taskpool.execute** API is called, HiLog prints a TaskPool call state log (**Task Allocation: taskId:**).
   If this log is missing, **taskpool.execute** is not actually called. Check whether the service logic preceding this API has been completed.

   ```ts
   import { taskpool } from '@kit.ArkTS';
   
   @Concurrent
   function createTask(a: number, b:number): number {
     let sum = a + b;
     return sum;
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
               console.info("test start");
               // Other service logic
               // ...
               let task: taskpool.Task = new taskpool.Task(createTask, 1, 2);
               taskpool.execute(task);
               // ...
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   
   // If "test start" is printed in the console but the Task Allocation: taskId: log is missing, taskpool.execute is not executed. Check the preceding service logic.
   ```

2. Check whether the task in the TaskPool is executed.

   Calling the **taskpool.execute** API will print a call state log **Task Allocation: taskId:**.
   After locating the **Task Allocation: taskId:** log for the target task, search for the ID following **taskId** in the log. Under normal circumstances, an execution state log (**Task Perform: name:**) and an end state log (**Task PerformTask End: taskId:**) should be printed.

   1.  If the call state log exists but the execution state log is missing, it may be because a preceding task has blocked the worker thread of the TaskPool, rendering it unavailable for subsequent tasks to execute. You should check the service logic or use trace to further pinpoint the issue.

   2. If the call state log and execution state log exist but the end state log is missing, check whether there are blocking operations in the service logic of the custom TaskPool task.

   3. If there is a significant time gap between the call state log and the execution state log, and your application is concerned about the timing of task execution, continue the analysis as follows:

      1. Check whether there is a backlog of a large number of TaskPool tasks that have not been executed. If a large number of tasks are submitted in a short period (resulting in numerous call state logs), subsequent tasks have to wait for the preceding tasks to complete. At this point, check the TaskPool's scaling situation. If the number of worker threads of the TaskPool has already been scaled up to near the upper limit (the **maxThreads** field in log snippet 2) before the call state log is printed, it may be due to too many tasks being submitted in a short time. You should prioritize important and time-sensitive tasks by setting appropriate priorities.

      2. Check whether the preceding tasks in the TaskPool are inherently time-consuming or have experienced blocking. If the preceding tasks are time-consuming, your application should address this by setting appropriate priorities. If the preceding tasks have encountered unexpected blocking (which is resolved after a period), check the service logic.

   ```ts
   // HiLog log snippet (simulation), in the following format. The specific value is determined by the application.
   // Log 1: A large number of tasks are submitted.
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   taskpool:: Task Allocation: taskId: , priority: , executeState:
   ...
   // Log 2: scaling log
   taskpool:: maxThreads: , created num: , total num:
   // Log 3: execution state log
   taskpool:: Task Perform: name: , taskId: , priority:
   ```

3. Check whether exceptions occur during task execution in the TaskPool.

   1. If a JavaScript exception occurs during task execution, the TaskPool catches the JavaScript exception and returns the exception information through **taskpool.execute().catch((e:Error)=>{})**. Review the exception information and rectify the fault.

      ```ts
      import { taskpool } from '@kit.ArkTS';
      
      @Concurrent
      function createTask(a: number, b:number) {
        let sum = a + b;
        return sum;
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
                  console.info("test start");
                  // Other service logic
                  // ...
                  let task: taskpool.Task = new taskpool.Task(createTask, 1, 2);
                  taskpool.execute(task).then((res: object)=>{
                    // Handle the result after task execution.
                    // ...
                  }).catch((e: Error)=>{
                    // Handle the exception after task failure.
                    // ...
                  })
                  // ...
                })
            }
            .width('100%')
          }
          .height('100%')
        }
      }
      ```

   2. If the .catch branch does not return any exception information, but the application's functionality implemented through the tasks is malfunctioning, check whether there are blocking operations in the task logic that cause the function exceptions.

## Troubleshooting for Slow Task Execution in the TaskPool

If there is a significant time gap between the call state log (e.g., **taskpool::add taskId:** or **taskpool::Task Allocation: taskId:**) and the execution state log (**taskpool::Task Perform: name:**), follow this guide for troubleshooting.

### Low-Priority Tasks Delayed by Many Medium-Priority Tasks

**Scenario Example 1**

An application creates a low-priority task that other service scenarios depend on for execution. Subsequently, the application creates many medium-priority tasks, causing the low-priority task to be executed later than planned, and other service scenarios fail to complete tasks at the scheduled time.

**Solution**

Executing tasks with low priority that have timing requirements is not a good choice. Applications should set reasonable task priorities based on service scenarios and properly combine task priorities.

**Scenario Example 2**

The application has a timing requirement for the execution of a certain task (referred to as taskA), with a detection mechanism for execution exceeding 5 seconds. The application sets taskA to medium priority and executes many other tasks with medium priority before taskA, which take 3 to 5 seconds each. These tasks occupy all existing and newly scaled-up threads, causing taskA to exceed 5 seconds from **taskpool.execute** to execution completion.

**Solution**

1. Analyze whether the execution duration (3 to 5 seconds) for other tasks are reasonable. 2. Adjust the priority of taskA.

### Tasks in Serial Queue Delayed by Slow Predecessors

**Scenario Example**

If the task is in a serial queue, check the execution of the preceding tasks in that serial queue. As shown in log snippet 1, the serial queue has four tasks, and the problem scenario corresponds to the fourth task. Log snippet 2 reveals that the second task took 2 seconds to execute, which is abnormal for the application's service logic.
```ts
// HiLog log snippet 1 (simulation)
// seqRunner has four tasks.
taskpool:: taskId 389508780288 in seqRunner 393913878464 immediately.
taskpool:: add taskId: 394062838784 to seqRunner 393913878464
taskpool:: add taskId: 393918679936 to seqRunner 393913878464
taskpool:: add taskId: 393918673408 to seqRunner 393913878464

// HiLog log snippet 2 (simulation)
// Check the second task. It takes 2s to complete.
18:28:28.223 taskpool:: taskId 394062838784 in seqRunner 393913878464 immediately.
18:28:28.224 taskpool:: Task Perform: name : , taskId : 394062838784, priority : 0
18:28:30.243 taskpool:: Task Perform End: taskId : 394062838784, performResult : Successful
```

**Solution**

Further check whether there are time-consuming operations in the service logic of the second task.

### ETS File Containing @Concurrent-Marked Methods Imports Too Many Modules

**Scenario Example**

The first execution of TaskPool tasks is slow, with a delay of several hundred milliseconds. The reason is that before deserialization in the child thread, all modules imported by the .ets file containing @Concurrent-marked methods are initialized, resulting in slow task scheduling. Use trace to further locate the issue. If there are many init module traces before successful deserialization, check whether the .ets file imports too many modules.

**Solution**

1. Split the @Concurrent methods into separate .ets files to reduce module initialization time. 2. Use [lazy import](arkts-lazy-import.md).

## Troubleshooting for TaskPool Serialization Failures

**Symptom**

1. JavaScript exception
   
   Reading the input parameters in serialization fails.

   ```ts
   // Versions earlier than API version 20
   Error message:An exception occurred during serialization, taskpool: failed to serialize arguments.

   // API version 20 and later
   Error message:An exception occurred during serialization, taskpool: failed to serialize arguments.
   Serialize error: Serialize don't support object type: 
   ```

   Failed to deserialize the return value.

   ```ts
   // Versions earlier than API version 20
   Error message:An exception occurred during serialization, taskpool: failed to serialize result.

   // API version 20 and later
   Error message:An exception occurred during serialization, taskpool: failed to serialize result.
   Serialize error: Serialize don't support object type: 
   ```

2. HiLog error log

   ```ts
   // Versions earlier than API version 20
   [ecmascript] Unsupport serialize object type: 
   [ecmascript] ValueSerialize: serialize data is incomplete

   // API version 20 and later
   [ecmascript] Serialize don't support object type: 
   [ecmascript] ValueSerialize: serialize data is incomplete
   ```

**Cause**

The input parameters and return value of the concurrent function used by the TaskPool to implement tasks do not meet the types supported by inter-thread communication. For details, see [Inter-thread Communication Objects](../reference/apis-arkts/js-apis-taskpool.md#sequenceable-data-types).  Further check whether the communication objects meet the requirements based on the object type printed in HiLog logs.

**Scenario Example**

1. The application throws an exception indicating input parameter serialization failure when starting a task because it passes an unsupported object type for inter-thread communication into the concurrent function. 
**Solution**: Check the input parameters of the concurrent function based on [Inter-thread Communication Objects](../reference/apis-arkts/js-apis-taskpool.md#sequenceable-data-types).

2. The application throws an exception indicating input parameter serialization failure when starting a task, and HiLog prints the error log **Unsupport serialize object type: Proxy**. (For API version 20 and later versions, the error log **Serialize error: Serialize don't support object type: Proxy** is printed.) Based on the error log, the application passes a proxy object into the concurrent function. The parameter uses the @State decorator, causing the original object to become a Proxy object, which is not a supported object type for inter-thread communication. 
**Solution**: TaskPool does not support complex types decorated with @State and @Prop. For details, see [Precautions for TaskPool](taskpool-introduction.md#precautions-for-taskpool). The application should remove the @State decorator.

3. The application throws an exception indicating return value serialization failure when executing a task. The code check shows that the return value of the concurrent function is an unsupported serialization type.
   
   ```ts
   // utils.ets
   @Concurrent
   export function printArgs(args: number) {
     return args;
   }

   // index.ets
   import { taskpool } from '@kit.ArkTS'
   import { BusinessError } from '@kit.BasicServicesKit'
   import { printArgs} from './utils'
   @Concurrent
   function createTask(a: number, b:number) {
     let sum = a + b;
     // task1: unsupported serialization type
     let task1: taskpool.Task = new taskpool.Task(printArgs, sum);
     return task1;
   }

   function executeTask() {
     // task
     let task: taskpool.Task = new taskpool.Task(createTask, 1, 2);
     taskpool.execute(task).then((res) => {
     }).catch((e: BusinessError) => {
       // Print the error message "Failed to serialize the returned result."
       console.error("execute task failed " + e.message);
     })
   }
   ```

   **Solution**: Create and execute task 1 within **.then**. Set the return value of the concurrent function to a serializable type.

   ```ts
   // utils.ets
   @Concurrent
   export function printArgs(args: number) {
     return args;
   }

   // index.ets
   import { taskpool } from '@kit.ArkTS'
   import { BusinessError } from '@kit.BasicServicesKit'
   import { printArgs} from './utils'
   @Concurrent
   function createTask(a: number, b:number) {
     // Supported serialization types
     let sum = a + b;
     return sum;
   }

   function executeTask() {
     // task
     let task: taskpool.Task = new taskpool.Task(createTask, 1, 2);
     taskpool.execute(task).then((res) => {
       // task1
       let task1: taskpool.Task = new taskpool.Task(printArgs, res);
     }).catch((e: BusinessError) => {
       console.error("execute task failed " + e.message);
     })
   }
   ```

## Using instanceof with Sendable Objects in Child Threads Returns False

When using the **instanceof** operator in a child thread, the application needs to mark the module exporting Sendable class A in the .ets file with the **use shared** directive to indicate that the module is a [shared module](../arkts-utils/arkts-sendable-module.md).

**Code Example**

```ts
// pages/index.ets
import { worker, ErrorEvent } from '@kit.ArkTS'
import { A } from './sendable'
const workerInstance = new worker.ThreadWorker('../workers/Worker.ets');
function testInstanceof() {
  let a = new A();
  if (a instanceof A) {
    // Print "test instanceof in main thread success".
    console.info("test instanceof in main thread success");
  } else {
    console.info("test instanceof in main thread failed");
  }
  workerInstance.postMessageWithSharedSendable(a);
  workerInstance.onerror = (err: ErrorEvent) => {
    console.error("worker err :" + err.message)
  }
}

testInstanceof()
```
```ts
// pages/sendable.ets
"use shared"
@Sendable
export class A {
    name: string = "name";
    printName(): string {
        return this.name;
    }
}
```
```ts
// workers/Worker.ets
import { A } from '../pages/sendable'
import { worker, ThreadWorkerGlobalScope, MessageEvents } from '@kit.ArkTS'

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;
workerPort.onmessage = (e: MessageEvents) => {
    let a : A = e.data as A;
    if (a instanceof A) {
        // Print "test instanceof in worker thread success".
        console.info("test instanceof in worker thread success");
    } else {
        console.info("test instanceof in worker thread failed");
    }
}
```

## Troubleshooting for JavaScript Exceptions Thrown by Sendable Features

Due to the fixed layout and the constraint that Sendable objects cannot hold non-Sendable objects, an inappropriate modification to Sendable objects may lead to the throwing of corresponding JavaScript exceptions. Follow this guide for troubleshooting.

### Type Mismatch Exception

**Symptom**

```ts
JavaScript exception: TypeError: Cannot set sendable property with mismatched type
```

**Cause and Solution**

ArkTS runtime strictly checks type consistency during property assignment. If the defined property type does not match the type of the passed object, the above JavaScript exception is thrown. Locate the corresponding service logic based on the JavaScript exception stack.

**Scenario Example**

1. A type mismatch exception is thrown when the application passes an instance of Sendable class A to a child thread. Based on the JavaScript stack, the problem occurs when creating an instance of class A. It is found that when the application is integrated with other modules, the other modules do not use Sendable class B to encapsulate the dataset.  
**Solution**: Use a Sendable class to re-encapsulate the data passed by other modules into the current module.

   ```ts
   @Sendable
   export class B {
     constructor() {}
   }

   @Sendable
   export class A {
     constructor(b: B) {
       this.b = b;
     }
     public b: B | undefined = undefined;
   }
   ```

2. A type mismatch exception is thrown when the application runs the assignment statement **this.g = g**. It is found that the property **g** uses the @State decorator, causing the original object to become a Proxy object, resulting in a type mismatch. 
**Solution**: Remove the @State decorator.

### Adding Property Exception

**Symptom**

```ts
JavaScript exception: TypeError: Cannot add property in prevent extensions
```

**Cause and Solution**

Since the layout of Sendable classes is fixed and does not allow adding or removing properties, adding a new property to a Sendable object will throw the above JavaScript exception. Locate the corresponding .ts file code line based on the JavaScript exception stack and check the relevant service logic.

**Scenario Example**

1. The application defines a Sendable class and a namespace with the same name in the same .ets file. An exception is thrown when the application attempts to add a new property. Since TS merges classes and namespaces with the same name, appending the exports of the namespace to the class with the same name effectively adds a new property to the Sendable class, causing the exception. 
**Solution**: Due to specification limitations, merging Sendable classes and namespaces with the same name is currently not supported.

2. An exception is thrown when the application attempts to add a new property while using the Sendable feature in a HAR. The exception code line is located in a .js file, and the Sendable feature is not supported in .js files, resulting in the exception. 
**Solution**: When using the Sendable feature in a HAR, [build TS files for the HAR](../quick-start/har-package.md#building-ts-files).

3. An exception is thrown when the application attempts to add a new property while using the Sendable feature in Local Test or Previewer. Since the Sendable feature is currently not supported in Local Test and Previewer, the exception is thrown. 
**Solution**: Due to specification limitations, this is currently not supported.

## What Is the Principle Behind ArkTS Promise?

Promise is the asynchronous concurrency capability provided by ArkTS and is a standard JavaScript syntax. For details, see [Promise](async-concurrency-overview.md#promise).

## Can TaskPool Threads Execute JavaScript Closure Functions That Do Not Require @Concurrent and @Sendable Decorators?

Task functions executed by the TaskPool must be decorated with @Concurrent. Since concurrent functions cannot access closures, they cannot call other regular functions within the same file. For details, see [Precautions for TaskPool](taskpool-introduction.md#precautions-for-taskpool). However, you can pass @Sendable-decorated regular functions and async functions as parameters to concurrent functions and call Sendable functions within the concurrent functions.

TaskPool threads do not support executing regular JavaScript closure functions. If necessary, you can use the [Worker](worker-introduction.md) concurrency capability to reconstruct your services.

## How Do I Save the Execution Result of a TaskPool Task to a Custom Data Structure?

**Symptom**

The execution function (concurrent function) of a TaskPool task can only use local variables and function parameters. How should I save its execution result of a TaskPool task to a custom data structure?

**Solution**

1. Custom Sendable class: [Sendable objects](arkts-sendable.md) can be shared across different threads. You can save the task execution results within these objects.

2. Returning results in **.then**: The execution result of a TaskPool task can be returned within **.then**. If the data to be saved is only used in the current thread, the execution result can be stored in a custom data structure within **.then**.

   ```ts
   // sendable.ets is in the same directory as Index.ets.
   @Sendable
   export class testClass {
     name: string = "test";
     setName(name: string) {
       this.name = name;
     }
     getName(): string {
       return this.name;
     }
   }   
   ```   

   ```ts
   // Index.ets
   import { taskpool } from '@kit.ArkTS'
   import { BusinessError } from '@kit.BasicServicesKit'
   import { testClass } from './sendable'
   
   @Concurrent
   function createTask(a: number): string {
     return `test${a}`;
   }
   function executeTask() {
     let testObject: testClass = new testClass();
     let task: taskpool.Task = new taskpool.Task(createTask, 1)
     taskpool.execute(task).then((res) => {
       testObject.setName(res as string);
       console.info('execute task success, name is ' + testObject.getName());
     }).catch((e: BusinessError) => {
       console.error('execute task error: ' + e.message);
     })
   }
   ```

## Sendable Class Cannot Be Loaded in a Child Thread

**Symptom**

The class decorated with **Sendable** and the class decorated with **Observed** are defined in the same .ets file. When the TaskPool child thread loads the Sendable class, the error message "SendableItem is not initialized" is displayed.

```ts
// Add the following code to Index.ets.
import { taskpool } from '@kit.ArkTS'
import { BusinessError } from '@kit.BasicServicesKit'
import { SendableItem } from './sendable'

@Concurrent
function createTask() {
  let data = new SendableItem();
}

function executeTask() {
  let task = new taskpool.Task(createTask);
  taskpool.execute(task).then((res) => {
    console.info('execute task success');
  }).catch((e: BusinessError) => {
    console.error('execute task error: ' + e.message);
  })
}

executeTask();
```

```ts
// sendable.ets
@Observed
export class NormalItem {
  age: number = 0;
}

@Sendable
export class SendableItem {
  name: string = '';
}
```

**Root Cause**

The Observed decorator can be used only in the UI thread. It cannot be directly or indirectly used in the child thread, Worker, or TaskPool. Otherwise, application malfunctions or even crashes may occur. Since the **sendable.ets** file defines a class decorated with the Observed decorator, this class may still be parsed and executed even if it is not explicitly invoked. When the parser encounters a UI decorator such as Observed, it will throw an exception: "Observed is not defined", which interrupts the parsing of other modules in the current file. The exception "SendableItem is not initialized" is thrown when the TaskPool child thread loads the Sendable class.

**Solution**

After the NormalItem class decorated with Observed is separated to a separate .ets file, and the TaskPool child thread loads the Sendable class SendableItem, the application runs as expected.

```ts
// Add the following code to Index.ets.
import { taskpool } from '@kit.ArkTS'
import { BusinessError } from '@kit.BasicServicesKit'
import { SendableItem } from './sendable'

@Concurrent
function createTask() {
  let data = new SendableItem();
}

function executeTask() {
  let task = new taskpool.Task(createTask);
  taskpool.execute(task).then((res) => {
    console.info('execute task success');
  }).catch((e: BusinessError) => {
    console.error('execute task error: ' + e.message);
  })
}

executeTask();
```

```ts
// sendable.ets
@Sendable
export class SendableItem {
  name: string = '';
}
```

```ts
// ui.ets
@Observed
export class NormalItem {
  age: number = 0;
}
```
