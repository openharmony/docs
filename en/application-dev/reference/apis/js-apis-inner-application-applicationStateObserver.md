# ApplicationStateObserver

The **ApplicationStateObserver** module defines an observer to listen for application state changes. It can be used as an input parameter in [registerApplicationStateObserver](js-apis-application-appManager.md#appmanagerregisterapplicationstateobserver8) to listen for lifecycle changes of the current application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import appManager from '@ohos.app.ability.appManager';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name                    |                      | Type    | Readable| Writable| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- | ------------------------- |
| onForegroundApplicationChanged         | [AppStateData](js-apis-inner-application-appStateData.md) | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the foreground or background state of an application changes.                   |
| onAbilityStateChanged  | [AbilityStateData](js-apis-inner-application-abilityStateData.md) | AsyncCallback\<void>   | Yes  | No | Callback invoked when the ability state changes.                 |
| onProcessCreated        | [ProcessData](js-apis-inner-application-processData.md) | AsyncCallback\<void>   | Yes  | No  | Callback invoked when a process is created.                 |
| onProcessDied         | [ProcessData](js-apis-inner-application-processData.md) | AsyncCallback\<void>   | Yes  | No  | Callback invoked when a process is destroyed.                 |
| onProcessStateChanged<sup>9+</sup>         | [ProcessData](js-apis-inner-application-processData.md) | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the process state is changed.                 |

**Example**
```ts
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
};
let observerCode = appManager.registerApplicationStateObserver(applicationStateObserver);
```
