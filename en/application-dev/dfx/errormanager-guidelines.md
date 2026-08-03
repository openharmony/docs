# Development of Error Manager

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=f319e3e62d6356bf78f31e2e8f7ba3927caddf1e translatedAt=2026-07-29T10:47:54.653Z pushedAt=2026-07-29T11:05:24.194Z -->

## Overview

If coding specification issues or errors exist in the code of an application, the application may encounter unexpected errors, for example, uncaught exceptions, while it is running. In such a case, the application may exit unexpectedly. Error logs, however, are usually stored on users' local storage devices, making it inconvenient to locate faults. With the APIs provided by the errorManager module, the related errors and logs will be reported to your service platform for fault locating before application exits.

After the errorManager APIs are used to listen for exceptions and errors, the application does not exit. You are advised to add the synchronous exit operation after the callback is executed. If you only want to obtain error logs, you are advised to use [HiAppEvent](hiappevent-intro.md) to subscribe to events.

> **NOTE**
>
> Starting from API version 26.0.0, if catchable exceptions have already been listened for through the errorManager APIs, HiAppEvent cannot subscribe to [JsError crashes](hiappevent-watcher-crash-events.md#jserror).

## Available APIs

The errorManager APIs are provided by [@ohos.app.ability.errorManager(Error Management Module)](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md). Before using the APIs, you need to register an error observer and import it through **import**. For details, see [How to Develop](#how-to-develop).

**errorManager APIs**

| API| Description|
| -------- | -------- |
| on(type: "error", observer: ErrorObserver): number | Registers an observer for application errors. A callback will be invoked when an application error is detected. This API works in a synchronous manner. The return value is the serial number (SN) of the registered observer.|
| off(type: "error", observerId: number, callback: AsyncCallback&lt;void>): void | Unregisters an observer in callback mode. The number is the SN of the registered observer.|
| off(type: "error", observerId: number): Promise&lt;void> | Unregisters an observer in promise mode. The number is the SN of the registered observer.|
| on(type: 'globalErrorOccurred', observer: GlobalObserver): void | Registers a global observer for process errors. This is a synchronous API. When the system detects an application exception, the observer is called. (**Recommended**)<br>Note: This API is supported since API version 18.|
| off(type: 'globalErrorOccurred', observer?: GlobalObserver): void | Unregisters an observer in callback mode. (**Recommended**)<br>Note: This API is supported since API version 18.|
| on(type: 'globalUnhandledRejectionDetected', observer: GlobalObserver): void | Registers a global observer for process errors. This is a synchronous API. When the system detects an application promise exception, the observer is called. (**Recommended**)<br>Note: This API is supported since API version 18.|
| off(type: 'globalUnhandledRejectionDetected', observer?: GlobalObserver): void | Unregisters an observer in callback mode. (**Recommended**)<br>Note: This API is supported since API version 18.|
| on(type: 'loopObserver', timeout: number, observer: LoopObserver): void | Registers an observer for the message processing timeouts of the main thread.<br>This API can be called only in the main thread. A new observer will overwrite the previous one.|
| off(type: 'loopObserver', observer?: LoopObserver): void | Unregisters an observer for the message processing timeouts of the main thread in LoopObserver mode.|
| on(type: 'freeze', observer: FreezeObserver): void | Registers an observer for the main thread freeze event of the application. This API can be called only in the main thread. A new observer will overwrite the previous one.|
| off(type: 'freeze', observer?: FreezeObserver): void | Unregisters an observer for the message processing timeouts of the main thread in FreezeObserver mode.<br>Note: This API is supported since API version 18.|
| setDefaultErrorHandler(defaultHandler?: ErrorHandler): ErrorHandler | Sets a default error handler. This API can be called only in the main thread. When the **JS_CRASH** exception occurs, chain callback is supported and the return value is the last registered handler.<br>Note: This API is supported since API version 21.|
| setDefaultResourceUsageObserver(defaultObserver?: ResourceUsageObserver): ResourceUsageObserver; | Called only on the main thread. When app resource usage exceeds the baseline, chained callbacks are supported. The return value is the previously registered resource usage observer. <br/>Note: This API is supported since API version 24. |
| setDefaultFreezeObserver(defaultObserver?: FreezeObserver) : FreezeObserver | Called only on the main thread. When an APP_FREEZE exception occurs, chained callbacks are supported. The return value is the previously registered handler.<br/>**NOTE**<br/>This API is supported since API version 26.0.0.<br/>**Model restriction:** This API can be used only in the stage model. |

When an asynchronous callback is used, the next step can be processed in the callback.

When a promise is used, the return value can also be processed in the promise. For details about the result codes, see [Result Codes for Unregistering an Observer](#result-codes-for-unregistering-an-observer).

**ErrorObserver APIs**

| API| Description|
| -------- | -------- |
| onUnhandledException(errMsg: string): void | Called when an uncaught exception is reported after the application is registered.|
| onException?(errObject: Error): void | System callback. After the app registers, this callback is invoked when an exception occurs in the app and is reported to the JS layer. |

**LoopObserver APIs**

| API| Description|
| -------- | -------- |
| onLoopTimeOut?(timeout: number): void | Called when the message processing of the main thread times out.|

### Result Codes for Unregistering an Observer

| Result Code| Description|
| -------- | -------- |
| 0 | Normal.|
| -1 | Input **number** not exist.|
| -2 | Invalid parameter.|

## How to Develop

> **NOTE**
>
> You are advised to add a synchronous exit operation at the end of the exception callback to prevent multiple exception callbacks.

### Listening for a Single Thread

 Import the header files.

<!-- @[index_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

 Add an observer.

<!-- @[error_observer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
let observer: errorManager.ErrorObserver = {
  onUnhandledException(errorMsg) {
    console.error('testErrorManage','onUnhandledException, errorMsg: ', errorMsg);
  },
  onException(errorObj) {
    console.error('testErrorManage','onException, name: ', errorObj.name);
    console.error('testErrorManage','onException, message: ', errorObj.message);
    if (typeof(errorObj.stack) === 'string') {
      console.error('testErrorManage','onException, stack: ', errorObj.stack);
    }
  }
};
```

 Add a trigger button.

<!-- @[onclick_error_observer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
Button('Listening for a single thread').onClick(()=>{
  let observerId = -1;
  try {
    observerId = errorManager.on('error', observer);
  } catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error('testErrorManage',`error: ${code}, ${message}`);
  }
  // Construct a fault scenario.
  throw new Error('test errorObserver msg');
}).position({x:50, y:50});
```

### Listening for Process Exceptions

 Import the header files.

<!-- @[index_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

 Add an observer.

<!-- @[error_func](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
function errorFunc(observer: errorManager.GlobalError) {
  console.error('testErrorManage','result name :' + observer.name);
  console.error('testErrorManage','result message :' + observer.message);
  console.error('testErrorManage','result stack :' + observer.stack);
  console.error('testErrorManage','result instanceName :' + observer.instanceName);
  console.error('testErrorManage','result instanceType :' + observer.instanceType);
};
```

 Add a trigger button.

<!-- @[onclick_error_func](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
Button('Listening for process exceptions').onClick(()=>{
  try {
    errorManager.on('globalErrorOccurred', errorFunc);
  } catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error('testErrorManage',`error: ${code}, ${message}`);
  }
  // Construct a fault scenario.
  throw new Error('test errorFunc msg');
}).position({x:50, y:100});
```

### Listening for Process Promise Exceptions

 Import the header files.

<!-- @[index_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

 Add an observer.

<!-- @[promise_func](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
function promiseFunc(observer: errorManager.GlobalError) {
  console.error('testErrorManage','result name :' + observer.name);
  console.error('testErrorManage','result message :' + observer.message);
  console.error('testErrorManage','result stack :' + observer.stack);
  console.error('testErrorManage','result instanceName :' + observer.instanceName);
  console.error('testErrorManage','result instanceType :' + observer.instanceType);
};

async function promiseFuncOne() {
  throw new Error('process promise exception');
};
```

 Add a trigger button.

<!-- @[onclick_promise_func](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
Button('Listening for process promise exceptions').onClick(()=>{
  try {
    errorManager.on('globalUnhandledRejectionDetected', promiseFunc);
  } catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error('testErrorManage',`error: ${code}, ${message}`);
  }
  // Construct a fault scenario.
  new Promise<string>(() => {
    promiseFuncOne();
  }).then(() => {
    throw new Error('test promiseFuncOne msg');
  });
}).position({x:50, y:200});
```

### Listening for Main Thread Freeze Exceptions

 Import the header files.

<!-- @[index_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

 Add an observer.

<!-- @[freeze_call_back](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
function freezeCallback() {
  console.error('testErrorManage','freezecallback');
};
```

 Add a trigger button.

<!-- @[onclick_freeze_call_back](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
Button('Listening for main thread freeze exceptions').onClick(()=>{
  try {
    errorManager.on('freeze', freezeCallback);
  } catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error('testErrorManage',`error: ${code}, ${message}`);
  }
  // Construct a fault scenario.
  let date = Date.now();
  while (Date.now() - date < 15000) {
  };
}).position({x:50, y:300});
```

### Listening for Main Thread Timeouts

 Import the header files.

<!-- @[index_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

 Add an observer.

<!-- @[loop_observer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
let loopObserver: errorManager.LoopObserver = {
  onLoopTimeOut(timeout: number) {
    console.error('testErrorManage','Duration timeout: ' + timeout);
  }
};
```

 Add a trigger button.

<!-- @[onclick_loop_observer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
Button('Listening for main thread timeouts').onClick(()=>{
  try {
    errorManager.on('loopObserver', 1, loopObserver);
  } catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error('testErrorManage',`error: ${code}, ${message}`);
  }
  // Construct a fault scenario.
  let date = Date.now();
  while (Date.now() - date < 4000) {
  };
}).position({x:50, y:150});
```

### Listening for Process Promise Exceptions

 Import the header files.

<!-- @[index_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
```

 Add an observer.

<!-- @[unhandled_rejection_observer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
let promise1 = new Promise<void>(() => {}).then(() => {
  throw new Error('uncaught error');
});

let unhandledrejectionObserver: errorManager.UnhandledRejectionObserver = (reason: Error, promise: Promise<void>) => {
  if (promise === promise1) {
    console.error('testErrorManage','promise1 is rejected');
  }
  console.error('testErrorManage','reason.name: ', reason.name);
  console.error('testErrorManage','reason.message: ', reason.message);
  if (reason.stack) {
    console.error('testErrorManage','reason.stack: ', reason.stack);
  }
};

async function promiseFuncTwo() {
  throw new Error('process promise unhandled rejection exception');
};
```

 Add a trigger button.

<!-- @[onclick_unhandled_rejection_observer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->   

``` TypeScript
Button('Listening for process promise exceptions').onClick(()=>{
  try {
    errorManager.on('unhandledRejection', unhandledrejectionObserver);
  } catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error('testErrorManage',`error: ${code}, ${message}`);
  }
  // Construct a fault scenario.
  new Promise<string>(() => {
    promiseFuncTwo();
  }).then(() => {
    throw new Error('test promiseFuncTwo msg');
  });
}).position({x:50, y:250});
```

### Chaining Error Handlers

 Define the first error handler and register the method. If no pre-handler is available, the process exits.

<!-- @[first_error_handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/FirstErrorHandler.ets) -->  

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { process } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

let firstHandler: errorManager.ErrorHandler;
const firstErrorHandler: errorManager.ErrorHandler = (reason: Error) => {
    // Implement the logic of the first custom error handler.
    console.info('[FirstHandler] First uncaught exception handler invoked.');
    if (firstHandler) {
        firstHandler(reason);
    } else {
        // You are advised to add a null check. If the value is null, use a synchronous exit approach.
        const processManager = new process.ProcessManager();
        processManager.exit(0);
    }  
};

export function setFirstErrorHandler() {
    try {
        firstHandler = errorManager.setDefaultErrorHandler(firstErrorHandler);
    } catch (paramError) {
        let code = (paramError as BusinessError).code;
        let message = (paramError as BusinessError).message;
        console.error('setFirstErrorHandler',`error: ${code}, ${message}`);
    }
    console.info('Registered First Error Handler');
}
```

 Define the second error handler and register the method to implement a chain call.

<!-- @[second_error_handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/SecondErrorHandler.ets) -->  

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { process } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

let secondHandler: errorManager.ErrorHandler;
const secondErrorHandler: errorManager.ErrorHandler = (reason: Error) => {
    // Implement the logic of the second custom error handler.
    console.info('[SecondHandler] Second uncaught exception handler invoked.');
    if (secondHandler) {
        secondHandler(reason);
    } else {
        const processManager = new process.ProcessManager();
        processManager.exit(0);
    }
};

export function setSecondErrorHandler() {
    try {
        secondHandler = errorManager.setDefaultErrorHandler(secondErrorHandler);
    } catch (paramError) {
        let code = (paramError as BusinessError).code;
        let message = (paramError as BusinessError).message;
        console.error('setSecondErrorHandler',`error: ${code}, ${message}`);
    }
    console.info('Registered Second Error Handler');
}
```

 Import the header files.

<!-- @[error_handler_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { setFirstErrorHandler } from './FirstErrorHandler';
import { setSecondErrorHandler } from './SecondErrorHandler';
```

 Add the constructor for chaining error handlers.

<!-- @[test_error_handlers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
function testErrorHandlers() {
  setFirstErrorHandler();
  setSecondErrorHandler();
  throw new Error('Test uncaught exception!');
}
```

 Trigger the test through the button for the main component, register two handlers, and throw an error to verify the handler chain.

<!-- @[onclick_error_Handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
Button ('Chaining error handlers').onClick(()=>{
  testErrorHandlers();
}).position({x:50, y:350});
```

### Freeze Handler Chain of Responsibility Pattern Scenario

 Define the first freeze handler and its registration method. The process exits when there is no preceding handler.

<!-- @[first_freeze_handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/FirstFreezeHandler.ets) -->  

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let firstHandler: errorManager.FreezeObserver = () => {};
const firstFreezeHandler: errorManager.FreezeObserver = () => {
    // Custom logic for the first FreezeHandler.
    console.info('[FirstHandler] First freeze handler invoked.');
    if (firstHandler) {
        firstHandler();
    } else {
        console.info('[FirstHandler] First freeze handler end.');
    }
};

export function setFirstFreezeHandler() {
    try {
        firstHandler = errorManager.setDefaultFreezeObserver(firstFreezeHandler);
    } catch (paramError) {
        let code = (paramError as BusinessError).code;
        let message = (paramError as BusinessError).message;
        console.error('setFirstFreezeHandler',`error: ${code}, ${message}`);
    }
    console.info('Registered First freeze Handler.');
}
```

 Define the second freeze handler and its registration method to form a chained call.

<!-- @[second_freeze_handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/SecondFreezeHandler.ets) -->  

``` TypeScript
import { errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let secondHandler: errorManager.FreezeObserver = () => {};
const secondFreezeHandler: errorManager.FreezeObserver = () => {
    // Custom logic for the second FreezeHandler.
    console.info('[SecondHandler] Second freeze handler invoked.');
    if (secondHandler) {
        secondHandler();
    } else {
        console.info('[SecondHandler] Second freeze handler end.');
    }
};

export function setSecondFreezeHandler() {
    try {
        secondHandler = errorManager.setDefaultFreezeObserver(secondFreezeHandler);
    } catch (paramError) {
        let code = (paramError as BusinessError).code;
        let message = (paramError as BusinessError).message;
        console.error('setSecondFreezeHandler',`error: ${code}, ${message}`);
    }
    console.info('Registered Second freeze Handler.');
}
```

 Import the header files.

<!-- @[freeze_handler_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
import { setFirstFreezeHandler } from './FirstFreezeHandler';
import { setSecondFreezeHandler } from './SecondFreezeHandler';
```

 Add a function for constructing the scenario fault.

<!-- @[test_timeout_handlers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
function waitTime() {
  // Construct a fault scenario.
  let date = Date.now();
  while (Date.now() - date < 15000) {
  };
}
```

 Add the constructor for the freeze handler chain of responsibility pattern.

<!-- @[test_freeze_handlers](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
function testFreezeHandlers() {
  setFirstFreezeHandler();
  setSecondFreezeHandler();
  waitTime();
}
```

 The main component triggers the test through a button, registers two handlers, and calls the scenario fault construction function to verify the processing chain.

<!-- @[onclick_freeze_Handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/ErrorManage/ErrorManage/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
Button('freeze handler chain of responsibility pattern scenario').onClick(()=>{
  testFreezeHandlers();
}).position({x:50, y:400});
```