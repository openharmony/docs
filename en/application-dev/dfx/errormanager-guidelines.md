# Development of Error Manager

## When to Use

If coding specification issues or errors exist in the code of an application, the application may encounter unexpected errors, for example, uncaught exceptions or application lifecycle timeouts, while it is running. In such a case, the application may exit unexpectedly. Error logs, however, are usually stored on users' local storage, making it inconvenient to locate faults. With the APIs provided by the **errorManager** module, your application will be able to report related errors and logs to your service platform for fault locating before it exits.

## Available APIs

Application error management APIs are provided by the **errorManager** module. For details about how to import the module to use related APIs, see [Development Example](#development-example).

**Table 1** Description of application error management APIs

| API                                                      | Description                                                |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| registerErrorObserver(observer: ErrorObserver): number       | Registers an observer for application errors. A callback will be invoked when an application error is detected. This API works in a synchronous manner. The return value is the SN of the registered observer.|
| unregisterErrorObserver(observerId: number,  callback: AsyncCallback\<void\>): void | Unregisters an observer in callback mode. The number passed to this API is the SN of the registered observer. |
| unregisterErrorObserver(observerId: number): Promise\<void\> | Unregisters an observer in promise mode. The number passed to this API is the SN of the registered observer. |

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
import Ability from '@ohos.application.Ability'
import errorManager from '@ohos.application.errorManager'

var registerId = -1;
var callback = {
    onUnhandledException: function (errMsg) {
        console.log(errMsg);
    }
}
export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        console.log("[Demo] MainAbility onCreate")
        globalThis.abilityWant = want;
    }

    onDestroy() {
        console.log("[Demo] MainAbility onDestroy")
    }

    onWindowStageCreate(windowStage) {
        // Main window is created for this ability.
        console.log("[Demo] MainAbility onWindowStageCreate")

        globalThis.registerObserver = (() => {
            registerId = errorManager.registerErrorObserver(callback);
        })

        globalThis.unRegisterObserver = (() => {
            errorManager.unregisterErrorObserver(registerId, (result) => {
                console.log("[Demo] result " + result.code + ";" + result.message)
            });
        })

        windowStage.setUIContent(this.context, "pages/index", null)
    }

    onWindowStageDestroy() {
        // Main window is destroyed to release UI resources.
        console.log("[Demo] MainAbility onWindowStageDestroy")
    }

    onForeground() {
        // Ability is brought to the foreground.
        console.log("[Demo] MainAbility onForeground")
    }

    onBackground() {
        // Ability is brought back to the background.
        console.log("[Demo] MainAbility onBackground")
    }
};
```
