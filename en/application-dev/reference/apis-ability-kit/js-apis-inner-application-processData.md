# ProcessData
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The module defines process data. If a lifecycle change listener is registered by calling [on](js-apis-app-ability-appManager.md#appmanageronapplicationstate14), the **onProcessCreated** callback in [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver.md) is invoked when the lifecycle of an application or ability changes.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name        | Type    | Read-Only| Optional| Description                      |
| ------------| ---------| ---- | ---- | ------------------------- |
| pid         | number   | No  | No| Process ID.                   |
| bundleName  | string   | No  | No| Bundle name of the application.                 |
| uid         | number   | No  | No|UID of the application.                 |
| isContinuousTask | boolean   | No  | No| Whether the task is a continuous task. **true** if yes, **false** otherwise.                |
| isKeepAlive      | boolean   | No  | No|Whether the process is a resident task. **true** if yes, **false** otherwise.                  |
| state       | number   | No  |  No|Application state. The options are as follows:<br>**0**: newly created.<br>**1**: ready.<br>**2**: running in the foreground.<br>**4**: running in the background.<br>**5**: terminated.    |

**Example**
```ts
import { appManager } from '@kit.AbilityKit';

let observerCode = appManager.on('applicationState', {
  onForegroundApplicationChanged(appStateData) {
    console.log(`onForegroundApplicationChanged, appStateData: ${JSON.stringify(appStateData)}.`);
  },
  onAbilityStateChanged(abilityStateData) {
    console.log(`onAbilityStateChanged, abilityStateData: ${JSON.stringify(abilityStateData)}.`);
  },
  onProcessCreated(processData) {
    console.log(`onProcessCreated, processData: ${JSON.stringify(processData)}.`);
  },
  onProcessDied(processData) {
    console.log(`onProcessDied, processData: ${JSON.stringify(processData)}.`);
  },
  onProcessStateChanged(processData) {
    console.log(`onProcessStateChanged, processData.pid : ${JSON.stringify(processData.pid)}.`);
    console.log(`onProcessStateChanged, processData.bundleName : ${JSON.stringify(processData.bundleName)}.`);
    console.log(`onProcessStateChanged, processData.uid : ${JSON.stringify(processData.uid)}.`);
    console.log(`onProcessStateChanged, processData.isContinuousTask : ${JSON.stringify(processData.isContinuousTask)}.`);
    console.log(`onProcessStateChanged, processData.isKeepAlive : ${JSON.stringify(processData.isKeepAlive)}.`);
  },
  onAppStarted(appStateData) {
    console.log(`onAppStarted, appStateData: ${JSON.stringify(appStateData)}.`);
  },
  onAppStopped(appStateData) {
    console.log(`onAppStopped, appStateData: ${JSON.stringify(appStateData)}.`);
  }
});
```
