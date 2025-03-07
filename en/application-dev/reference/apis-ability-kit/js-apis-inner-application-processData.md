# ProcessData

The ProcessData module defines process data. If a lifecycle change listener is registered by calling [on](js-apis-app-ability-appManager.md#appmanageronapplicationstate), the **onProcessCreated** callback in [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md) is invoked when the lifecycle of an application or ability changes.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                    | Type    | Mandatory| Description                      |
| ----------------------- | ---------| ---- | ------------------------- |
| pid         | number   | Yes  | Process ID.                   |
| bundleName  | string   | Yes  | Bundle name of the application.                 |
| uid         | number   | Yes  | UID of the application.                 |
| isContinuousTask | boolean   | Yes  | Whether the task is a continuous task. The value **true** means that the task is a continuous task, and **false** means the opposite.                |
| isKeepAlive      | boolean   | Yes  | Whether the process is a resident task. The value **true** means that the process is a resident, and **false** means the opposite.                  |
| state       | number   | Yes  | Application state. The options are as follows:<br>**0**: newly created.<br>**1**: ready.<br>**2**: running in the foreground.<br>**4**: running in the background.<br>**5**: terminated.    |

**Example**
```ts
import { appManager } from '@kit.AbilityKit';

let observerCode = appManager.on('applicationState', {
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
    console.log(`onProcessStateChanged processData.pid : ${JSON.stringify(processData.pid)}`);
    console.log(`onProcessStateChanged processData.bundleName : ${JSON.stringify(processData.bundleName)}`);
    console.log(`onProcessStateChanged processData.uid : ${JSON.stringify(processData.uid)}`);
    console.log(`onProcessStateChanged processData.isContinuousTask : ${JSON.stringify(processData.isContinuousTask)}`);
    console.log(`onProcessStateChanged processData.isKeepAlive : ${JSON.stringify(processData.isKeepAlive)}`);
  },
  onAppStarted(appStateData) {
    console.log(`onAppStarted appStateData: ${JSON.stringify(appStateData)}`);
  },
  onAppStopped(appStateData) {
    console.log(`onAppStopped appStateData: ${JSON.stringify(appStateData)}`);
  }
});
```
