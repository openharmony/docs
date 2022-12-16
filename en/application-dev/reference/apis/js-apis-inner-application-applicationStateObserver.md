# ApplicationStateObserver

The **ApplicationStateObserver** module defines the listener to observe the application state.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name                    | Type    | Readable| Writable| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| onForegroundApplicationChanged<sup>8+</sup>         | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the foreground or background state of an application changes.                   |
| onAbilityStateChanged<sup>8+</sup>  | AsyncCallback\<void>   | Yes  | No | Callback invoked when the ability state changes.                 |
| onProcessCreated<sup>8+</sup>         | AsyncCallback\<void>   | Yes  | No  | Callback invoked when a process is created.                 |
| onProcessDied<sup>8+</sup>         | AsyncCallback\<void>   | Yes  | No  | Callback invoked when a process is destroyed.                 |
| onProcessStateChanged<sup>8+</sup>         | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the process state is changed.                 |

**Example**
```ts
import appManager from "@ohos.application.appManager"

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
        console.log('onProcessStateChanged onProcessStateChanged: ' +  JSON.stringify(processData));
    }
}
let observerCode = appManager.registerApplicationStateObserver(applicationStateObserver);
```
