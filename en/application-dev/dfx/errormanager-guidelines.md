# Development of Error Manager

## When to Use

If coding specification issues or errors exist in the code of an application, the application may encounter unexpected errors, for example, uncaught exceptions or application lifecycle timeouts, while it is running. In such a case, the application may exit unexpectedly. Error logs, however, are usually stored on users' local storage, making it inconvenient to locate faults. With the APIs provided by the **errorManager** module, your application will be able to report related errors and logs to your service platform for fault locating before it exits.

## Available APIs

Application error management APIs are provided by the **errorManager** module. For details about how to import the module to use related APIs, see [Development Example](#development-example).

**Table 1** Description of application error management APIs

| API                                                      | Description                                                |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| on(type: "error", observer: ErrorObserver): number       | Registers an observer for application errors. A callback will be invoked when an application error is detected. This API works in a synchronous manner. The return value is the SN of the registered observer.|
| off(type: "error", observerId: number,  callback: AsyncCallback\<void\>): void | Unregisters an observer in callback mode. The number passed to this API is the SN of the registered observer. |
| off(type: "error", observerId: number): Promise\<void\> | Unregisters an observer in promise mode. The number passed to this API is the SN of the registered observer. |

When an asynchronous callback is used, the return value can be processed directly in the callback. If a promise is used, the return value can also be processed in the promise in a similar way. For details about the result codes, see [Result Codes for Unregistering an Observer](#result codes-for-unregistering-an-observer).


**Table 2** Description of the ErrorObserver API

| API                        | Description                                                        |
| ------------------------------ | ------------------------------------------------------------ |
| onUnhandledException(errMsg: string): void | Called when an application generates an uncaught exception after being registered.|


### Result Codes for Unregistering an Observer

| Result Code| Description                       |
| ------ | ---------------------------  |
| 0      |  Normal.                         |
| -1     | Input number not exist.             |
| -2     | Invalid parameter.      |

## Development Example
```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import errorManager from '@ohos.app.ability.errorManager';

let registerId = -1;
let callback = {
    onUnhandledException: function (errMsg) {
        console.log(errMsg);
    }
}

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        console.log("[Demo] EntryAbility onCreate")
        registerId = errorManager.on("error", callback);
        globalThis.abilityWant = want;
    }

    onDestroy() {
        console.log("[Demo] EntryAbility onDestroy")
        errorManager.off("error", registerId, (result) => {
            console.log("[Demo] result " + result.code + ";" + result.message)
        });
    }

    onWindowStageCreate(windowStage) {
        // Main window is created for this ability.
        console.log("[Demo] EntryAbility onWindowStageCreate")

        windowStage.loadContent("pages/index", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data))
        });
    }

    onWindowStageDestroy() {
        // Main window is destroyed to release UI resources.
        console.log("[Demo] EntryAbility onWindowStageDestroy")
    }

    onForeground() {
        // Ability is brought to the foreground.
        console.log("[Demo] EntryAbility onForeground")
    }

    onBackground() {
        // Ability is brought back to the background.
        console.log("[Demo] EntryAbility onBackground")
    }
};
```
