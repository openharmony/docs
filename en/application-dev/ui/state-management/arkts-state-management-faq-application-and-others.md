# In-App State Management and Other FAQs
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zany_pink-->
<!--Designer: @zhangboren-->
<!--Tester: @zhangwenhan12-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=62b5c3450a87bdc5e575e58aa760685da7a65e8a translatedAt=2026-07-01T11:08:12.900Z pushedAt=2026-07-01T11:11:01.918Z -->

This section describes the common problems of in-app state management and other common problems.

## Errors Caused by Using ArkUI Decorators in Concurrent Threads

### Lazy Loading of Files Containing Decorators

State management decorators are restricted to being used in the UI thread and cannot be used in [concurrent threads](../../arkts-utils/multi-thread-concurrency-overview.md) in which the ArkUI framework is not loaded. Since the complete ArkUI framework logic is not loaded in concurrent threads, the state management decorators defined in the framework are not loaded into the concurrent threads. If the state management decorator is used in concurrent threads, "ReferenceError: xxx is not defined" is displayed. In the following example, although concurrent threads do not actually use the class decorated with [\@Observed](./arkts-observed-and-objectlink.md), the error message "ReferenceError: Observed is not defined" is displayed. This is because when concurrent threads parse file dependencies layer by layer, they eventually load the **Observed.ets** file where the \@Observed decorator is defined, thus triggering this error.

**Incorrect Usage**

<!-- @[lazy_import_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/LazyImportNeg.ets) -->

``` TypeScript
// src/main/ets/pages/LazyImportNeg.ets
import { ErrorEvent, worker, MessageEvents } from '@kit.ArkTS';

@Entry
@Component
struct Index {
  build() {
    Button('New Worker')
      .onClick(() => {
        // Create a Worker object.
        const newWorker = new worker.ThreadWorker('../workers/LazyImportWorkerNeg.ets');

        // Register the onmessage callback to capture the message sent by the Worker thread through the workerPort.postMessage API. This callback is executed in the host thread.
        newWorker.onmessage = (e: MessageEvents) => {
          let data: string = e.data;
          console.info('newWorker onmessage is: ', data);
        };

        // Register the onAllErrors callback to capture global exceptions generated during the onmessage callback, timer callback, and file execution of the Worker thread. This callback is executed in the host thread.
        newWorker.onAllErrors = (err: ErrorEvent) => {
          console.error('workerInstance onAllErrors message is: ' + err.message);
        };

        // Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the host thread.
        newWorker.onmessageerror = () => {
          console.error('workerInstance onmessageerror');
        };

        // Register the onexit callback. When the Worker object is destroyed, this callback is invoked and executed in the host thread.
        newWorker.onexit = (e: number) => {
          // When the Worker object exits normally, the code is 0. When the Worker object exits abnormally, the code is 1.
          console.info('workerInstance onexit code is: ', e);
        };

        // Send a message to the Worker thread.
        newWorker.postMessage('[Main] message from the main thread');
      })
  }
}
```

<!-- @[lazy_import_worker_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/workers/LazyImportWorkerNeg.ets) --> 

``` TypeScript
// src/main/ets/workers/LazyImportWorkerNeg.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { testWithoutObserved } from '../pages/LazyImportFuncNeg';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

// Register the onmessage callback. When the Worker thread receives a message from the host thread through the postMessage interface, this callback is invoked and executed in the Worker thread.
workerPort.onmessage = (e: MessageEvents) => {
  // Call the testWithoutObserved function.
  testWithoutObserved();
  let data: string = e.data;
  console.info('workerPort onmessage is: ', data);

  // Send a message to the host thread.
  workerPort.postMessage('[Worker] message from the workerPort');
};

// Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the Worker thread.
workerPort.onmessageerror = () => {
  console.error('workerPort onmessageerror');
};

// Register the onerror callback. When an exception occurs during the execution of the Worker thread, this callback is invoked and executed in the Worker thread.
workerPort.onerror = (err: ErrorEvent) => {
  console.error('workerPort onerror err is: ', err.message);
};
```

<!-- @[lazy_import_function_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/LazyImportFuncNeg.ets) --> 

``` TypeScript
// src/main/ets/pages/LazyImportFuncNeg.ets
import { innerTest } from './LazyImportObservedNeg';

export function testWithObserved(): void {
  innerTest();
  console.info('ImportObserved::testWithObserved call');
}

export function testWithoutObserved(): void {
  console.info('ImportObserved::testWithoutObserved call');
}
```

<!-- @[lazy_import_observed_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/LazyImportObservedNeg.ets) --> 

``` TypeScript
// src/main/ets/pages/LazyImportObservedNeg.ets
export function innerTest(): void {
  console.info('Observed::innerTest call');
}

@Observed
export class Person {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
```

Use [lazy import](../../arkts-utils/arkts-lazy-import.md) for lazy loading of files with decorators. Child threads will not load the corresponding files.

**Correct Usage**

<!-- @[lazy_import_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/LazyImportPos.ets) --> 

``` TypeScript
// src/main/ets/pages/LazyImportPos.ets
import { ErrorEvent, worker, MessageEvents } from '@kit.ArkTS';

@Entry
@Component
struct Index {
  build() {
    Button('New Worker')
      .onClick(() => {
        // Create a Worker object.
        const newWorker = new worker.ThreadWorker('../workers/LazyImportWorkerPos.ets');

        // Register the onmessage callback to capture the message sent by the Worker thread through the workerPort.postMessage API. This callback is executed in the host thread.
        newWorker.onmessage = (e: MessageEvents) => {
          let data: string = e.data;
          console.info('newWorker onmessage is: ', data);
        };

        // Register the onAllErrors callback to capture global exceptions generated during the onmessage callback, timer callback, and file execution of the Worker thread. This callback is executed in the host thread.
        newWorker.onAllErrors = (err: ErrorEvent) => {
          console.error('workerInstance onAllErrors message is: ' + err.message);
        };

        // Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the host thread.
        newWorker.onmessageerror = () => {
          console.error('workerInstance onmessageerror');
        };

        // Register the onexit callback. When the Worker object is destroyed, this callback is invoked and executed in the host thread.
        newWorker.onexit = (e: number) => {
          // When the Worker object exits normally, the code is 0. When the Worker object exits abnormally, the code is 1.
          console.info('workerInstance onexit code is: ', e);
        };

        // Send a message to the Worker thread.
        newWorker.postMessage('[Main] message from the main thread');
      })
  }
}
```

<!-- @[lazy_import_worker_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/workers/LazyImportWorkerPos.ets) -->

``` TypeScript
// src/main/ets/workers/LazyImportWorkerPos.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { testWithoutObserved } from '../pages/LazyImportFuncPos';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

// Register the onmessage callback. When the Worker thread receives a message from the host thread through the postMessage interface, this callback is invoked and executed in the Worker thread.
workerPort.onmessage = (e: MessageEvents) => {
  // Call the testWithoutObserved function.
  testWithoutObserved();
  let data: string = e.data;
  console.info('workerPort onmessage is: ', data);

  // Send a message to the host thread.
  workerPort.postMessage('[Worker] message from the workerPort');
};

// Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the Worker thread.
workerPort.onmessageerror = () => {
  console.error('workerPort onmessageerror');
};

// Register the onerror callback. When an exception occurs during the execution of the Worker thread, this callback is invoked and executed in the Worker thread.
workerPort.onerror = (err: ErrorEvent) => {
  console.error('workerPort onerror err is: ', err.message);
};
```

<!-- @[lazy_import_function_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/LazyImportFuncPos.ets) -->

``` TypeScript
// src/main/ets/pages/LazyImportFuncPos.ets
// Use lazy import for lazy loading of files with decorators.
import lazy { innerTest } from './LazyImportObservedPos';

export function testWithObserved(): void {
  innerTest();
  console.info('ImportObserved::testWithObserved call');
}

export function testWithoutObserved(): void {
  console.info('ImportObserved::testWithoutObserved call');
}
```

<!-- @[lazy_import_observed_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/LazyImportObservedPos.ets) -->

``` TypeScript
// src/main/ets/pages/LazyImportObservedPos.ets
export function innerTest(): void {
  console.info('Observed::innerTest call');
}

@Observed
export class Person {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
```

### Isolation of the Decorator Usage

When state management decorators are defined in the file where the functions called in child threads are located, the corresponding file is also loaded during the loading process, and a "ReferenceError" is printed. Since the called functions and the definitions of state management decorators exist in the same file, the lazy loading method cannot solve this problem. In this case, the called functions can be moved out of the file and defined separately.

**Incorrect Usage**

<!-- @[decorator_use_isolation_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/DecUseIsolationNeg.ets) -->

``` TypeScript
// src/main/ets/pages/DecUseIsolationNeg.ets
import { ErrorEvent, worker, MessageEvents } from '@kit.ArkTS';

@Entry
@Component
struct Index {
  build() {
    Button('New Worker')
      .onClick(() => {
        // Create a Worker object.
        const newWorker = new worker.ThreadWorker('../workers/UseIsolationWorkerNeg.ets');

        // Register the onmessage callback to capture the message sent by the Worker thread through the workerPort.postMessage API. This callback is executed in the host thread.
        newWorker.onmessage = (e: MessageEvents) => {
          let data: string = e.data;
          console.info('newWorker onmessage is: ', data);
        };

        // Register the onAllErrors callback to capture global exceptions generated during the onmessage callback, timer callback, and file execution of the Worker thread. This callback is executed in the host thread.
        newWorker.onAllErrors = (err: ErrorEvent) => {
          console.error('workerInstance onAllErrors message is: ' + err.message);
        };

        // Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the host thread.
        newWorker.onmessageerror = () => {
          console.error('workerInstance onmessageerror');
        };

        // Register the onexit callback. When the Worker object is destroyed, this callback is invoked and executed in the host thread.
        newWorker.onexit = (e: number) => {
          // When the Worker object exits normally, the code is 0. When the Worker object exits abnormally, the code is 1.
          console.info('workerInstance onexit code is: ', e);
        };

        // Send a message to the Worker thread.
        newWorker.postMessage('[Main] message from the main thread');
      })
  }
}
```

<!-- @[use_isolation_worker_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/workers/UseIsolationWorkerNeg.ets) -->

``` TypeScript
// src/main/ets/workers/UseIsolationWorkerNeg.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { testWithObserved } from '../pages/UseIsolationFuncNeg';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

// Register the onmessage callback. When the Worker thread receives a message from the host thread through the postMessage interface, this callback is invoked and executed in the Worker thread.
workerPort.onmessage = (e: MessageEvents) => {
  // Call the testWithObserved function.
  testWithObserved();
  let data: string = e.data;
  console.info('workerPort onmessage is: ', data);

  // Send a message to the host thread.
  workerPort.postMessage('[Worker] message from the workerPort');
};

// Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the Worker thread.
workerPort.onmessageerror = () => {
  console.error('workerPort onmessageerror');
};

// Register the onerror callback. When an exception occurs during the execution of the Worker thread, this callback is invoked and executed in the Worker thread.
workerPort.onerror = (err: ErrorEvent) => {
  console.error('workerPort onerror err is: ', err.message);
};
```

<!-- @[use_isolation_function_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/UseIsolationFuncNeg.ets) -->

``` TypeScript
// src/main/ets/pages/UseIsolationFuncNeg.ets
import { innerTest } from './UseIsolationObservedNeg';

export function testWithObserved(): void {
  innerTest();
  console.info('ImportObserved::testWithObserved call');
}

export function testWithoutObserved(): void {
  console.info('ImportObserved::testWithoutObserved call');
}
```

<!-- @[use_isolation_observed_negative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/UseIsolationObservedNeg.ets) -->

``` TypeScript
// src/main/ets/pages/UseIsolationObservedNeg.ets
export function innerTest(): void {
  console.info('Observed::innerTest call');
}

@Observed
export class Person {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
```

**Correct Usage**

<!-- @[decorator_use_isolation_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/DecUseIsolationPos.ets) -->

``` TypeScript
// src/main/ets/pages/DecUseIsolationPos.ets
import { ErrorEvent, worker, MessageEvents } from '@kit.ArkTS';

@Entry
@Component
struct Index {
  build() {
    Button('New Worker')
      .onClick(() => {
        // Create a Worker object.
        const newWorker = new worker.ThreadWorker('../workers/UseIsolationWorkerPos.ets');

        // Register the onmessage callback to capture the message sent by the Worker thread through the workerPort.postMessage API. This callback is executed in the host thread.
        newWorker.onmessage = (e: MessageEvents) => {
          let data: string = e.data;
          console.info('newWorker onmessage is: ', data);
        };

        // Register the onAllErrors callback to capture global exceptions generated during the onmessage callback, timer callback, and file execution of the Worker thread. This callback is executed in the host thread.
        newWorker.onAllErrors = (err: ErrorEvent) => {
          console.error('workerInstance onAllErrors message is: ' + err.message);
        };

        // Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the host thread.
        newWorker.onmessageerror = () => {
          console.error('workerInstance onmessageerror');
        };

        // Register the onexit callback. When the Worker object is destroyed, this callback is invoked and executed in the host thread.
        newWorker.onexit = (e: number) => {
          // When the Worker object exits normally, the code is 0. When the Worker object exits abnormally, the code is 1.
          console.info('workerInstance onexit code is: ', e);
        };

        // Send a message to the Worker thread.
        newWorker.postMessage('[Main] message from the main thread');
      })
  }
}
```

<!-- @[use_isolation_worker_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/workers/UseIsolationWorkerPos.ets) -->

``` TypeScript
// src/main/ets/workers/UseIsolationWorkerPos.ets
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { testWithObserved } from '../pages/UseIsolationFuncPos';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

// Register the onmessage callback. When the Worker thread receives a message from the host thread through the postMessage interface, this callback is invoked and executed in the Worker thread.
workerPort.onmessage = (e: MessageEvents) => {
  // Call the testWithObserved function.
  testWithObserved();
  let data: string = e.data;
  console.info('workerPort onmessage is: ', data);

  // Send a message to the host thread.
  workerPort.postMessage('[Worker] message from the workerPort');
};

// Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the Worker thread.
workerPort.onmessageerror = () => {
  console.error('workerPort onmessageerror');
};

// Register the onerror callback. When an exception occurs during the execution of the Worker thread, this callback is invoked and executed in the Worker thread.
workerPort.onerror = (err: ErrorEvent) => {
  console.error('workerPort onerror err is: ', err.message);
};
```

<!-- @[use_isolation_function_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/UseIsolationFuncPos.ets) -->

``` TypeScript
// src/main/ets/pages/UseIsolationFuncPos.ets
import { innerTest } from './UseIsolationAdditionPos';

export function testWithObserved(): void {
  innerTest();
  console.info('ImportObserved::testWithObserved call');
}

export function testWithoutObserved(): void {
  console.info('ImportObserved::testWithoutObserved call');
}
```

<!-- @[use_isolation_addition_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/UseIsolationAdditionPos.ets) -->

``` TypeScript
// src/main/ets/pages/UseIsolationAdditionPos.ets
// Split the function and use the decorator for isolation.
export function innerTest(): void {
  console.info('Addition::innerTest call');
}
```

<!-- @[use_isolation_observed_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/StateManagementFAQApplication/entry/src/main/ets/pages/UseIsolationObservedPos.ets) -->

``` TypeScript
// src/main/ets/pages/UseIsolationObservedPos.ets
@Observed
export class Person {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}
```