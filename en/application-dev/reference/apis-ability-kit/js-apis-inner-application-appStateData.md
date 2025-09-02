# AppStateData
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The module defines the application state data, which can be obtained through [appManager.on('applicationState')](./js-apis-app-ability-appManager.md#appmanageronapplicationstate14).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                     | Type  | Mandatory | Description      |
| ------------------------- | ------ | ---- | --------- |
| bundleName  | string | Yes  | Bundle name.|
| uid          | number | Yes  | UID of the application.  |
| state        | number | Yes  | Application state.<br>**0**: The application is being initialized.<br>**1**: The application has been initialized and is ready.<br>**2**: The application is running in the foreground.<br>**3**: The application is having the focus. (This state is reserved.)<br>**4**: The application is running in the background.<br>**5**: The application has exited.|
| isSplitScreenMode | boolean | Yes| Whether the application is in split-screen mode.<br>**true**: The application is in split-screen mode.<br>**false**: The application is not in split-screen mode.|
| isFloatingWindowMode | boolean | Yes| Whether the application is in floating window mode.<br>**true**: The application is in floating window mode.<br>**false**: The application is not in floating window mode.|

**Example**

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let applicationStateObserver: appManager.ApplicationStateObserver = {
  onForegroundApplicationChanged(appStateData) {
    console.log(`[appManager] onForegroundApplicationChanged: ${JSON.stringify(appStateData)}`);
    console.log(`appStateData.bundleName: ${appStateData.bundleName}`);
    console.log(`appStateData.uid: ${appStateData.uid}`);
    console.log(`appStateData.state: ${appStateData.state}`);
    console.log(`appStateData.isSplitScreenMode: ${appStateData.isSplitScreenMode}`);
    console.log(`appStateData.isFloatingWindowMode: ${appStateData.isFloatingWindowMode}`);
  },
  onAbilityStateChanged(abilityStateData) {
    console.log(`[appManager] onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
  onProcessCreated(processData) {
    console.log(`[appManager] onProcessCreated: ${JSON.stringify(processData)}`);
  },
  onProcessDied(processData) {
    console.log(`[appManager] onProcessDied: ${JSON.stringify(processData)}`);
  },
  onProcessStateChanged(processData) {
    console.log(`[appManager] onProcessStateChanged: ${JSON.stringify(processData)}`);
  },
  onAppStarted(appStateData) {
    console.log(`[appManager] onAppStarted: ${JSON.stringify(appStateData)}`);
  },
  onAppStopped(appStateData) {
    console.log(`[appManager] onAppStopped: ${JSON.stringify(appStateData)}`);
  }
};

try {
  const observerId = appManager.on('applicationState', applicationStateObserver);
  console.log(`[appManager] observerCode: ${observerId}`);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`[appManager] error: ${code}, ${message}`);
}
```
