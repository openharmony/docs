# ApplicationStateObserver (System API)

The ApplicationStateObserver module defines an observer to listen for application state changes. It can be used as an input parameter in [on](js-apis-app-ability-appManager-sys.md#appmanageronapplicationstate) to listen for lifecycle changes of the current application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Properties

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                            | Type                   | Readable| Writable| Description  |
| -------------------------------- | ---------------------- | ---- | ---- | ------------------ |
| onForegroundApplicationChanged   | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the foreground or background state of an application changes. The parameter type passed in is [AppStateData](js-apis-inner-application-appStateData-sys.md).|
| onAbilityStateChanged            | AsyncCallback\<void>   | Yes  | No | Callback invoked when the ability state changes. The parameter type passed in is [AbilityStateData](js-apis-inner-application-abilityStateData-sys.md).  |
| onProcessCreated                 | AsyncCallback\<void>   | Yes  | No  | Callback invoked when a process is created. The parameter type passed in is [ProcessData](js-apis-inner-application-processData-sys.md).         |
| onProcessDied                     | AsyncCallback\<void>   | Yes  | No  | Callback invoked when a process is destroyed. The parameter type passed in is [ProcessData](js-apis-inner-application-processData-sys.md).         |
| onProcessStateChanged<sup>9+</sup> | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the process state is changed. The parameter type passed in is [ProcessData](js-apis-inner-application-processData-sys.md).       |
| onAppStarted<sup>12+</sup>       | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the first process of the application is created. The parameter type passed in is [AppStateData](js-apis-inner-application-appStateData-sys.md).    |
| onAppStopped<sup>12+</sup>       | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the last process of the application is destroyed. The parameter type passed in is [AppStateData](js-apis-inner-application-appStateData-sys.md).    |

**Example**
```ts
import { appManager } from '@kit.AbilityKit';

let applicationStateObserver: appManager.ApplicationStateObserver = {
  onForegroundApplicationChanged(appStateData) {
    console.log(`onForegroundApplicationChanged appStateData: ${JSON.stringify(appStateData)}`);
  },
  onAbilityStateChanged(abilityStateData) {
    console.log(`onAbilityStateChanged onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
  onProcessCreated(processData) {
    console.log(`onProcessCreated onProcessCreated: ${JSON.stringify(processData)}`);
  },
  onProcessDied(processData) {
    console.log(`onProcessDied onProcessDied: ${JSON.stringify(processData)}`);
  },
  onProcessStateChanged(processData) {
    console.log(`onProcessStateChanged onProcessStateChanged: ${JSON.stringify(processData)}`);
  },
  onAppStarted(appStateData) {
    console.log(`onAppStarted appStateData: ${JSON.stringify(appStateData)}`);
  },
  onAppStopped(appStateData) {
    console.log(`onAppStopped appStateData: ${JSON.stringify(appStateData)}`);
  }
};
let observerCode = appManager.on('applicationState', applicationStateObserver);
```
