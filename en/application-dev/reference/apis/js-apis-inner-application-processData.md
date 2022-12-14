# ProcessData

The **ProcessData** module defines process data.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name                    | Type    | Readable| Writable| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid<sup>8+</sup>         | number   | Yes  | No  | Process ID.                   |
| bundleName<sup>8+</sup>  | string   | Yes  | No | Bundle name of the application.                 |
| uid<sup>8+</sup>         | number   | Yes  | No  | User ID.                 |
| isContinuousTask<sup>9+</sup>         | boolean   | Yes  | No  | Whether the process is a continuous task.                 |
| isKeepAlive<sup>9+</sup>         | boolean   | Yes  | No  | Whether the process remains active.                 |

**Example**
```ts
import appManager from '@ohos.application.appManager'

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
}
let observerCode = appManager.registerApplicationStateObserver(applicationStateObserver);
```
