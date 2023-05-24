# ProcessData

The **ProcessData** module defines process data. If a lifecycle change listener is registered by calling [registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8), the **onProcessCreated** callback in [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md) is invoked when the lifecycle of an application or ability changes.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import appManager from '@ohos.application.appManager';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name                    | Type    | Readable| Writable| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid         | number   | Yes  | No  | Process ID.                   |
| bundleName  | string   | Yes  | No | Bundle name of the application.                 |
| uid         | number   | Yes  | No  | UID of the application.                 |
| isContinuousTask<sup>9+</sup>         | boolean   | Yes  | No  | Whether the task is a continuous task. The value **true** means that the task is a continuous task, and **false** means the opposite.                |
| isKeepAlive<sup>9+</sup>         | boolean   | Yes  | No  | Whether the process is a resident task. The value **true** means that the process is a resident, and **false** means the opposite.                  |
| state<sup>9+</sup>       | number   | Yes  | No  | Application state. The value can be **0** (newly created), **2** (foreground), **4** (background), or **5** (terminated).    |

**Example**
```ts
import appManager from '@ohos.application.appManager';

let applicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log('onForegroundApplicationChanged appStateData: ' +  JSON.stringify(appStateData));
    },
    onAbilityStateChanged(abilityStateData) {
        console.log('onAbilityStateChanged onAbilityStateChanged: ' +  JSON.stringify(abilityStateData));
    },
    onProcessCreated(processData) {
        console.log('onProcessCreated onProcessCreated: '  +  JSON.stringify(processData));
    },
    onProcessDied(processData) {
        console.log('onProcessDied onProcessDied: '  +  JSON.stringify(processData));
    },
    onProcessStateChanged(processData) {
        console.log('onProcessStateChanged processData.pid : ' +  JSON.stringify(processData.pid));
        console.log('onProcessStateChanged processData.bundleName : ' +  JSON.stringify(processData.bundleName));
        console.log('onProcessStateChanged processData.uid : ' +  JSON.stringify(processData.uid));
        console.log('onProcessStateChanged processData.isContinuousTask : ' +  JSON.stringify(processData.isContinuousTask));
        console.log('onProcessStateChanged processData.isKeepAlive : ' +  JSON.stringify(processData.isKeepAlive));
    }
};
let observerCode = appManager.registerApplicationStateObserver(applicationStateObserver);
```
