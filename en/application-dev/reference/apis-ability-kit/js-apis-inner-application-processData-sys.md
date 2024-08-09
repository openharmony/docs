# ProcessData (System API)

The **ProcessData** module defines process data. If a lifecycle change listener is registered by calling [registerApplicationStateObserver](js-apis-application-appManager-sys.md#appmanagerregisterapplicationstateobserver), the **onProcessCreated** callback in [ApplicationStateObserver](js-apis-inner-application-applicationStateObserver-sys.md) is invoked when the lifecycle of an application or ability changes.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name                    | Type    | Read-only | Mandatory | Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid         | number   | No  | Yes  | Process ID.                   |
| bundleName  | string   | No  | Yes | Bundle name of the application.                 |
| uid         | number   | No  | Yes  | UID of the application.                 |
| isContinuousTask<sup>9+</sup>         | boolean   | No  | Yes  | Whether the task is a continuous task. The value **true** means that the task is a continuous task, and **false** means the opposite.                |
| isKeepAlive<sup>9+</sup>         | boolean   | No  | Yes  | Whether the process is a resident task. The value **true** means that the process is a resident, and **false** means the opposite.                  |
| state<sup>9+</sup>       | number   | No  | Yes  | Application state. The options are as follows:<br>**0**: newly created.<br>**1**: ready.<br>**2**: running in the foreground.<br>**4**: running in the background.<br>**5**: terminated.    |

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
