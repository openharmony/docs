# Worker Introduction

With the Worker module, you can provide a multithreaded environment for an application, so that the application can perform a time-consuming operation in a background thread. This greatly prevents a computing-intensive or high-latency task from blocking the running of the main thread. For details about the APIs and their usage, see [Worker](../reference/apis-arkts/js-apis-worker.md).


## Worker Operating Mechanism

**Figure 1** Worker operating mechanism

![worker](figures/worker.png)

The thread that creates the worker thread is referred to as the host thread (not necessarily the main thread, since a worker thread can also create another worker thread). A worker thread is also named an actor thread. Each worker thread has an instance independent from the host thread, including the infrastructure, objects, and code segments. Memory overhead exists when each worker thread is started, and therefore the number of worker threads needs to be limited. The worker thread communicates with the host thread by means of message exchange. They use the serialization technique to exchange commands and data.


## Precautions for Worker

- A worker thread can be created manually or automatically. In manual creation mode, you must also perform related configurations. For details, see [Precautions for Creating a Worker Thread](#precautions-for-creating-a-worker-thread).
- The URL of the worker thread file passed in to the constructor function varies according to the version in use. For details, see [Precautions for File URLs](#precautions-for-file-urls).
- After a worker thread is created, you must manually manage its lifecycle. A maximum of 64 worker threads can run simultaneously. For details, see [Lifecycle Precautions](#lifecycle-precautions).
- The context objects in different threads are different. Therefore, **Worker** threads can use only thread-safe libraries, rather than UI-related non-thread-safe libraries.
- A maximum of 16 MB data can be serialized.
- You must register the **onerror** API in the main thread to listen for worker thread errors, which might cause a JavaScript crash.
- Worker thread files cannot be used across HAPs.
- Before referencing the HAR or HSP, configure the dependency on the HAR or HSP. For details, see (https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-har-import-V5).
- [AppStorage](../quick-start/arkts-appstorage.md) cannot be used in the worker thread.


### Precautions for Creating a Worker Thread

The worker thread file must be stored in the ***{moduleName}*/src/main/ets/** directory. Otherwise, it will not be packed into the application. A worker thread can be created manually or automatically.

- Manual creation: Manually create the directory and file, and configure the related field in **build-profile.json5** so that the file can be packed into the application.

  Stage model:

  ```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/workers/worker.ets"
      ]
    }
  }
  ```

  FA model:

  ```json
  "buildOption": {
    "sourceOption": {
      "workers": [
        "./src/main/ets/MainAbility/workers/worker.ets"
      ]
    }
  }
  ```

- Automatic creation: DevEco Studio supports one-click generation of worker threads. Right-click any position in the {moduleName} directory and choose **New > Worker** to generate the template file and configuration information of the worker thread. You do not need to configure the field in **build-profile.json5**.


### Precautions for File URLs

  Before calling an API of the Worker module, you must create a **Worker** instance. The constructor function varies in different API versions, and the URL of the worker thread file must be passed in to **scriptURL** of the function.

```ts
// Import the worker module.
import { worker } from '@kit.ArkTS';

// Use the following function in API version 9 and later versions:
const worker1: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/worker.ets');
// Use the following function in API version 8 and earlier versions:
const worker2: worker.Worker = new worker.Worker('entry/ets/workers/worker.ets');
```


#### File URL Rules in the Stage Model

The requirements for **scriptURL** in the constructor function are as follows:

- **scriptURL** consists of {moduleName}/ets and {relativePath}.
- {relativePath} is the relative path of the worker thread file to the ***{moduleName}*/src/main/ets/** directory.

(1) Loading a worker thread file of an ability

To load the worker thread file of an ability, use the URL {moduleName}/ets/{relativePath}.

```ts
import { worker } from '@kit.ArkTS';

// URL of the worker thread file: "entry/src/main/ets/workers/worker.ets"
const workerStage1: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/worker.ets');

// URL of the worker thread file: "phone/src/main/ets/ThreadFile/workers/worker.ets"
const workerStage2: worker.ThreadWorker = new worker.ThreadWorker('phone/ets/ThreadFile/workers/worker.ets');
```

(2) Loading a worker thread file in [HSP](../quick-start/in-app-hsp.md)

To load the worker thread file in HSP, use the URL {moduleName}/ets/{relativePath}.

```ts
import { worker } from '@kit.ArkTS';

// URL of the worker thread file: "hsp/src/main/ets/workers/worker.ets"
const workerStage3: worker.ThreadWorker = new worker.ThreadWorker('hsp/ets/workers/worker.ets');
```

(3) Loading a worker thread file in [HAR](../quick-start/har-package.md)

The worker thread file in the HAR may be loaded in either of the following cases:

- @ path loading mode: All types of modules load the worker thread file in the local HAR. The URL is @{moduleName}/ets/{relativePath}.

- Relative path loading mode: The local HAR loads the worker thread file in the package. The URL is the relative path of the file where the Worker object is created to the worker thread file.

>**NOTE**
>
>When **useNormalizedOHMUrl** is enabled (the **useNormalizedOHMUrl** field of the **strictMode** attribute in the **build-profile.json5** file at the same level as the entry in the project directory is set to **true**) or the HAR is packed into a third-party package, the worker thread file in the HAR can be loaded using a relative path.

```ts
import { worker } from '@kit.ArkTS';

// @ Path loading mode
// URL of the worker thread file: "har/src/main/ets/workers/worker.ets"
const workerStage4: worker.ThreadWorker = new worker.ThreadWorker('@har/ets/workers/worker.ets');

// Relative path loading mode:
// URL of the worker thread file: "har/src/main/ets/workers/worker.ets"
// URL of the file where the Worker object is created: "har/src/main/ets/components/mainpage/MainPage.ets"
const workerStage5: worker.ThreadWorker = new worker.ThreadWorker('../../workers/worker.ets');
```


#### File URL Rules in the FA Model

  **scriptURL** in the constructor function is the relative path between the worker thread file and "{moduleName}/src/main/ets/MainAbility".

```ts
import { worker } from '@kit.ArkTS';

// The following three scenarios are involved.

// Scenario 1: URL of the worker thread file: "{moduleName}/src/main/ets/MainAbility/workers/worker.ets"
const workerFA1: worker.ThreadWorker = new worker.ThreadWorker("workers/worker.ets", {name:"first worker in FA model"});

// Scenario 2: URL of the worker thread file: "{moduleName}/src/main/ets/workers/worker.ets"
const workerFA2: worker.ThreadWorker = new worker.ThreadWorker("../workers/worker.ets");

// Scenario 3: URL of the worker thread file: "{moduleName}/src/main/ets/MainAbility/ThreadFile/workers/worker.ets"
const workerFA3: worker.ThreadWorker = new worker.ThreadWorker("ThreadFile/workers/worker.ets");
```


### Lifecycle Precautions

- Creating and terminating worker threads consume performance. Therefore, you are advised to manage available workers and reuse them. The worker threads keep running even when they are idle. When a worker thread is not required, call [terminate()](../reference/apis-arkts/js-apis-worker.md#terminate9) or [close()](../reference/apis-arkts/js-apis-worker.md#close9) to terminate it. If a worker thread is terminated or being terminated, an error is thrown when it is called.


- The number of worker threads is determined by the memory management policy. The required memory threshold is the smaller one between 1.5 GB and 60% of the physical memory of the device. If the memory is sufficient, a maximum of 64 worker threads can run simultaneously. If excess worker threads are to be created, the system displays the error message "Worker initialization failure, the number of workers exceeds the maximum." The number of actually running worker threads is dynamically adjusted based on the memory usage. Once the accumulated memory usage of all worker threads and main threads exceeds the threshold, Out of Memory (OOM) error occurs, and applications may crash.


## Cross-HAR package loading worker

1. For details about how to create a har, see [Developing a Static Shared Package](../quick-start/har-package.md).

2. Create the Worker thread file in the har file.

   ```ts
   // worker.ets
   workerPort.onmessage = (e: MessageEvents) => {
     console.info("worker thread receive message: ", e.data);
     workerPort.postMessage('worker thread post message to main thread');
   }
   ```

3. Configure the dependency of the HAR package in the oh-package.json5 file of the entry module.

   ```ts
   // Configure the dependency of the HAR package in the entry module.
   {
     "name": "entry",
     "version": "1.0.0",
     "description": "Please describe the basic information.",
     "main": "",
     "author": "",
     "license": "",
     "dependencies": {
       "har": "file:../har"
     }
   }
   ```

4. Load the worker thread file in the HAR package in the entry module.

   ```ts
   // Index.ets
   import { worker } from '@kit.ArkTS';

   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';

     build() {
       RelativeContainer() {
         Text(this.message)
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: '__container__', align: VerticalAlign.Center },
             middle: { anchor: '__container__', align: HorizontalAlign.Center }
           })
           .onClick(() => {
             // Use @ to identify the path loading mode and load the Worker thread file in the har.
             let workerInstance = new worker.ThreadWorker('@har/ets/workers/worker.ets');
             workerInstance.onmessage = () => {
               console.info('main thread onmessage');
             };
             workerInstance.postMessage('hello world');
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```


## Multi-level worker lifecycle management
Multi-level Workers can be created (that is, a hierarchical thread relationship is formed by creating child Workers through the parent Worker), and the lifecycle of Worker threads is managed by users. Therefore, the lifecycle of multi-level Workers must be correctly managed. If the child Worker is not stopped when the parent Worker is destroyed, unexpected results may occur. You are advised to ensure that the lifecycle of the child Worker is always within the lifecycle of the parent Worker and destroy all child Workers before destroying the parent Worker.


### Recommended Example

```ts
// Create a worker thread (parent worker) in the main thread and create a worker thread (child worker) in the worker thread.
// main thread
import { worker, MessageEvents, ErrorEvent } from '@kit.ArkTS';

// Create a Worker instance in the main thread.
const parentworker = new worker.ThreadWorker("entry/ets/workers/parentworker.ets");

parentworker.onmessage = (e: MessageEvents) => {
  console.info ("The main thread receives the parent worker thread information" + e.data);
}

parentworker.onexit = () => {
  console.info ("The parent worker exits.");
}

parentworker.onerror = (err: ErrorEvent) => {
  console.info ("The main thread receives an error from the parent worker." + err);
}

parentworker.postMessage ("The main thread sends a message to the parentworker. Recommended example");
```

```ts
// parentworker.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';

// Create an object in the worker thread for communicating with the main thread.
const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e : MessageEvents) => {
  if (e.data = = "The main thread sends a message to the parent worker.-Recommended example") {
    let childworker = new worker.ThreadWorker("entry/ets/workers/childworker.ets");

    childworker.onmessage = (e: MessageEvents) => {
      console.info ("The parent Worker receives information from the child Worker" + e.data);
      if (e.data = = "The child worker sends information to the parent worker.") {
        workerPort.postMessage ("The parent worker sends information to the main thread.");
      }
    }

    childworker.onexit = () => {
      console.info ("The child worker exits.");
      // Destroy the parent Worker after the child Worker exits.
      workerPort.close();
    }

    childworker.onerror = (err: ErrorEvent) => {
      console.info ("An error occurred on the child Worker." + err);
    }

    childworker.postMessage ("The parent Worker sends information to the child Worker. Recommended example");
  }
}
```

```ts
// childworker.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';

// Create an object in the worker thread for communicating with the main thread.
const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
  if (e.data = = "The parent Worker sends information to the child Worker. Recommended example.") {
    // Service logic of the sub-worker thread...
    console.info ("The service execution is complete, and the child Worker is destroyed.");
    workerPort.close();
  }
}
```


### Examples Not Recommended

It is not recommended that a child Worker send messages to the parent Worker after the parent Worker is destroyed.

```ts
// main thread
import { worker, MessageEvents, ErrorEvent } from '@kit.ArkTS';

const parentworker = new worker.ThreadWorker("entry/ets/workers/parentworker.ets");

parentworker.onmessage = (e: MessageEvents) => {
  console.info("The main thread receives the parent worker information" + e.data);
}

parentworker.onexit = () => {
  console.info("The parent worker exits.");
}

parentworker.onerror = (err: ErrorEvent) => {
  console.info("The main thread receives an error from the parent worker." + err);
}

parentworker.postMessage ("The main thread sends a message to the parent worker.");
```

```ts
// parentworker.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e : MessageEvents) => {
  console.info("The parent worker receives information from the main thread." + e.data);

  let childworker = new worker.ThreadWorker("entry/ets/workers/childworker.ets")

  childworker.onmessage = (e: MessageEvents) => {
    console.info("The parent Worker receives information from the child Worker" + e.data);
  }

  childworker.onexit = () => {
    console.info("The child worker exits.");
    workerPort.postMessage("The parent worker sends information to the main thread.");
  }

  childworker.onerror = (err: ErrorEvent) => {
    console.info("An error occurred on the child Worker." + err);
  }

  childworker.postMessage("The parent worker sends information to the child worker.");

  // Destroy the parent Worker after the child Worker is created.
  workerPort.close();
}
```

```ts
// childworker.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
  console.info("The child Worker receives the message" + e.data);

  // After the parent Worker is destroyed, the child Worker sends information to the parent Worker. The behavior is unpredictable.
  workerPort.postMessage("The child Worker sends information to the parent Worker.");
  setTimeout(() => {
    workerPort.postMessage("The child Worker sends information to the parent Worker.");
  }, 1000);
}
```

You are not advised to create a child Worker in the parent Worker thread before and after the parent Worker initiates the synchronous call of the destruction operation. You are not advised to create a child Worker in the parent Worker thread if you are not sure whether the parent Worker initiates a destruction operation. That is, ensure that the parent Worker thread is always alive before the child Worker thread is successfully created.

```ts
// main thread
import { worker, MessageEvents, ErrorEvent } from '@kit.ArkTS';

const parentworker = new worker.ThreadWorker("entry/ets/workers/parentworker.ets");

parentworker.onmessage = (e: MessageEvents) => {
  console.info("The main thread receives the parent worker information" + e.data);
}

parentworker.onexit = () => {
  console.info("The parent worker exits.");
}

parentworker.onerror = (err: ErrorEvent) => {
  console.info("The main thread receives an error from the parent worker." + err);
}

parentworker.postMessage("The main thread sends a message to the parent worker.");
```

```ts
// parentworker.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e : MessageEvents) => {
  console.info("The parent worker receives information from the main thread." + e.data);

  // Create a child Worker after the parent Worker is destroyed. The behavior is unpredictable.
  workerPort.close();
  let childworker = new worker.ThreadWorker("entry/ets/workers/childworker.ets");

  // Destroy the parent Worker before the child Worker thread confirms that the creation is successful. The behavior is unpredictable.
  // let childworker = new worker.ThreadWorker("entry/ets/workers/childworker.ets");
  // workerPort.close();

  childworker.onmessage = (e: MessageEvents) => {
    console.info("The parent Worker receives information from the child Worker" + e.data);
  }

  childworker.onexit = () => {
    console.info("The child worker exits.");
    workerPort.postMessage("The parent worker sends information to the main thread.");
  }

  childworker.onerror = (err: ErrorEvent) => {
    console.info("An error occurred on the child Worker." + err);
  }

  childworker.postMessage("The parent worker sends information to the child worker.");
}
```

```ts
// childworker.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
  console.info("The child Worker receives the message" + e.data);
}
```
