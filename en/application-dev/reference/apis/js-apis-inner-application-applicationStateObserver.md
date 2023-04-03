# ApplicationStateObserver

The **ApplicationStateObserver** module defines an observer to listen for application state changes. It can be used as an input parameter in [registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8) to listen for lifecycle changes of the current application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name                    |                      | Type    | Readable| Writable| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- | ------------------------- |
| onForegroundApplicationChanged<sup>8+</sup>         | [AppStateData](js-apis-inner-application-appStateData.md) | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the foreground or background state of an application changes.                   |
| onAbilityStateChanged<sup>8+</sup>  | [AbilityStateData](js-apis-inner-application-abilityStateData.md) | AsyncCallback\<void>   | Yes  | No | Callback invoked when the ability state changes.                 |
| onProcessCreated<sup>8+</sup>         | [ProcessData](js-apis-inner-application-processData.md) | AsyncCallback\<void>   | Yes  | No  | Callback invoked when a process is created.                 |
| onProcessDied<sup>8+</sup>         | [ProcessData](js-apis-inner-application-processData.md) | AsyncCallback\<void>   | Yes  | No  | Callback invoked when a process is destroyed.                 |
| onProcessStateChanged<sup>8+</sup>         | [ProcessData](js-apis-inner-application-processData.md) | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the process state is changed.                 |

**Example**
```ts
import appManager from '@ohos.app.ability.appManager';

let applicationStateObserver = {
    onForegroundApplicationChanged(appStateData) {
        console.log('onForegroundApplicationChanged appStateData: ${JSON.stringify(appStateData)}');
    },
    onAbilityStateChanged(abilityStateData) {
        console.log('onAbilityStateChanged onAbilityStateChanged: ${JSON.stringify(abilityStateData)}');
    },
    onProcessCreated(processData) {
        console.log('onProcessCreated onProcessCreated: ${JSON.stringify(processData)}');
    },
    onProcessDied(processData) {
        console.log('onProcessDied onProcessDied: ${JSON.stringify(processData)}');
    },
    onProcessStateChanged(processData) {
        console.log('onProcessStateChanged onProcessStateChanged: ${JSON.stringify(processData)}');
    }
};
let observerCode = appManager.registerApplicationStateObserver(applicationStateObserver);
```
