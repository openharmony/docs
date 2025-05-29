# Development of Error Manager

## Overview

If coding specification issues or errors exist in the code of an application, the application may encounter unexpected errors, for example, uncaught exceptions or application lifecycle timeouts, while it is running. In such a case, the application may exit unexpectedly. Error logs, however, are usually stored on users' local storage, making it inconvenient to locate faults. With the APIs provided by the **errorManager** module, the related errors and logs will be reported to your service platform for fault locating before application exits.

After the errormanager API is used to listen for exceptions and errors, the application does not exit. You are advised to add the synchronous exit operation after the callback is executed. If you only want to obtain error logs, you are advised to use [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md).

## Available APIs

Application error management APIs are provided by the [errorManager](../reference/apis-ability-kit/js-apis-app-ability-errorManager.md#) module. For details about how to import the module, see [Development Example](#development-example).

**Application Error Management APIs**

| API                                                      | Description                                                |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| on(type: "error", observer: ErrorObserver): number       | Registers an observer for application errors. A callback will be invoked when an application error is detected. This API works in a synchronous manner. The return value is the serial number (SN) of the registered observer. |
| off(type: "error", observerId: number,  callback: AsyncCallback\<void\>): void | Unregisters an observer in callback mode. The number is the SN of the registered observer. |
| off(type: "error", observerId: number): Promise\<void\> | Unregisters an observer in promise mode. The number is the SN of the registered observer. |
| on(type: 'globalErrorOccurred', observer: GlobalObserver): void       | Registers a global observer for process errors. When the system detects an application exception, the observer is called. (**Recommended**) |
| off(type: 'globalErrorOccurred', observer?: GlobalObserver): void | Unregisters the previously registered callback observer. (**Recommended**) |
| on(type: 'globalUnhandledRejectionDetected', observer: GlobalObserver): void       | Registers a global observer for process errors. When the system detects an application promise exception, the observer is called. (**Recommended**) |
| off(type: 'globalUnhandledRejectionDetected', observer?: GlobalObserver): void | Unregisters the previously registered callback observer. (**Recommended**) |
| on(type: 'loopObserver', timeout: number, observer: LoopObserver): void<sup>12+</sup> | Registers an observer for the message processing duration of the main thread. A callback will be invoked if a main thread jank event occurs. This API can be called only in the main thread. A new observer will overwrite the previous one. |
| off(type: 'loopObserver', observer?: LoopObserver): void<sup>12+</sup> | Unregisters the observer for message processing timeouts of the main thread. |
| on(type: 'freeze', observer: FreezeObserver): void<sup>18+</sup> | Registers an observer for the main thread freeze event of the application. This API can be called only in the main thread. A new observer will overwrite the previous one. |
| off(type: 'freeze', observer?: FreezeObserver): void<sup>18+</sup> | Unregisters an observer for the main thread freeze event of the application. This API can be called only in the main thread. |

When an asynchronous callback is used, the return value can be processed directly in the callback. If a promise is used, the return value can also be processed in the promise in a similar way. For details about the result codes, see [Result Codes for Unregistering an Observer](#result-codes-for-unregistering-an-observer).


**ErrorObserver APIs**

| API                        | Description                                                        |
| ------------------------------ | ------------------------------------------------------------ |
| onUnhandledException(errMsg: string): void | Called when an uncaught exception is reported after the application is registered.|
| onException?(errObject: Error): void | Called when an application exception is reported to the JavaScript layer after the application is registered.|


**LoopObserver APIs**

| API                        | Description                                                        |
| ------------------------------ | ------------------------------------------------------------ |
| onLoopTimeOut?(timeout: number): void<sup>12+</sup> | Called when the message processing of the main thread times out.|


### Result Codes for Unregistering an Observer

| Result Code| Description                       |
| ------ | ---------------------------  |
| 0      |  Normal.                         |
| -1     | Input number not exist.             |
| -2     | Invalid parameter.      |

## Development Example

> **NOTE**
> 
> You are advised to add a synchronous exit function at the end of the exception callback. Otherwise, multiple exception callbacks may be invoked.

### Listening for A Single Thread

```ts
import { AbilityConstant, errorManager, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import process from '@ohos.process';

let registerId = -1;
let callback: errorManager.ErrorObserver = {
    onUnhandledException: (errMsg) => {
        console.log(errMsg);
    },
    onException: (errorObj) => {
        console.log('onException, name: ', errorObj.name);
        console.log('onException, message: ', errorObj.message);
        if (typeof(errorObj.stack) === 'string') {
            console.log('onException, stack: ', errorObj.stack);
        }
        //After the callback is executed, exit the process synchronously to avoid triggering exceptions for multiple times.
        let pro = new process.ProcessManager();
        pro.exit(0);
    }
}

let abilityWant: Want;

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("[Demo] EntryAbility onCreate");
        registerId = errorManager.on("error", callback);
        abilityWant = want;
    }

    onDestroy() {
        console.log("[Demo] EntryAbility onDestroy");
        errorManager.off("error", registerId, (result) => {
            console.log("[Demo] result " + result.code + ";" + result.message);
        });
    }

    onWindowStageCreate(windowStage: window.WindowStage) {
        // Main window is created, set main page for this ability
        console.log("[Demo] EntryAbility onWindowStageCreate");

        windowStage.loadContent("pages/index", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }

    onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        console.log("[Demo] EntryAbility onWindowStageDestroy");
    }

    onForeground() {
        // Ability has brought to foreground
        console.log("[Demo] EntryAbility onForeground");
    }

    onBackground() {
        // Ability has back to background
        console.log("[Demo] EntryAbility onBackground");
    }
};
```

### Listening for Process Exceptions

```ts
import { AbilityConstant, errorManager, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import process from '@ohos.process';

function errorFunc(observer: errorManager.GlobalError) {
    console.log("[Demo] result name :" + observer.name);
    console.log("[Demo] result message :" + observer.message);
    console.log("[Demo] result stack :" + observer.stack);
    console.log("[Demo] result instanceName :" + observer.instanceName);
    console.log("[Demo] result instaceType :" + observer.instanceType);
    //After the callback is executed, exit the process synchronously to avoid triggering exceptions for multiple times.
    let pro = new process.ProcessManager();
    pro.exit(0);
}

let abilityWant: Want;

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("[Demo] EntryAbility onCreate");
        errorManager.on("globalErrorOccurred", errorFunc);
        abilityWant = want;
    }

    onDestroy() {
        console.log("[Demo] EntryAbility onDestroy");
        errorManager.off("globalErrorOccurred", errorFunc);
    }

    onWindowStageCreate(windowStage: window.WindowStage) {
        // Main window is created, set main page for this ability
        console.log("[Demo] EntryAbility onWindowStageCreate");

        windowStage.loadContent("pages/index", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }

    onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        console.log("[Demo] EntryAbility onWindowStageDestroy");
    }

    onForeground() {
        // Ability has brought to foreground
        console.log("[Demo] EntryAbility onForeground");
    }

    onBackground() {
        // Ability has back to background
        console.log("[Demo] EntryAbility onBackground");
    }
};
```

### Listening for Process Promise Exceptions

```ts
import { AbilityConstant, errorManager, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import process from '@ohos.process';

function promiseFunc(observer: errorManager.GlobalError) {
    console.log("[Demo] result name :" + observer.name);
    console.log("[Demo] result message :" + observer.message);
    console.log("[Demo] result stack :" + observer.stack);
    console.log("[Demo] result instanceName :" + observer.instanceName);
    console.log("[Demo] result instaceType :" + observer.instanceType);
    //After the callback is executed, exit the process synchronously to avoid triggering exceptions for multiple times.
    let pro = new process.ProcessManager();
    pro.exit(0);
}


let abilityWant: Want;

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("[Demo] EntryAbility onCreate");
        errorManager.on("globalUnhandledRejectionDetected", errorFunc);
        abilityWant = want;
    }

    onDestroy() {
        console.log("[Demo] EntryAbility onDestroy");
        errorManager.off("globalUnhandledRejectionDetected", errorFunc);
    }

    onWindowStageCreate(windowStage: window.WindowStage) {
        // Main window is created, set main page for this ability
        console.log("[Demo] EntryAbility onWindowStageCreate");

        windowStage.loadContent("pages/index", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }

    onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        console.log("[Demo] EntryAbility onWindowStageDestroy");
    }

    onForeground() {
        // Ability has brought to foreground
        console.log("[Demo] EntryAbility onForeground");
    }

    onBackground() {
        // Ability has back to background
        console.log("[Demo] EntryAbility onBackground");
    }
};
```

### Listening for Main Thread Freeze Exceptions

```ts
import { AbilityConstant, errorManager, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import process from '@ohos.process';

// Define freezeCallback
function freezeCallback() {
    console.log("freezecallback");
}


let abilityWant: Want;

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("[Demo] EntryAbility onCreate");
        errorManager.on("freeze", freezeCallback);
        abilityWant = want;
    }

    onDestroy() {
        console.log("[Demo] EntryAbility onDestroy");
        errorManager.off("freeze", freezeCallback);
    }

    onWindowStageCreate(windowStage: window.WindowStage) {
        // Main window is created, set main page for this ability
        console.log("[Demo] EntryAbility onWindowStageCreate");

        windowStage.loadContent("pages/index", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }

    onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        console.log("[Demo] EntryAbility onWindowStageDestroy");
    }

    onForeground() {
        // Ability has brought to foreground
        console.log("[Demo] EntryAbility onForeground");
    }

    onBackground() {
        // Ability has back to background
        console.log("[Demo] EntryAbility onBackground");
    }
};
```
