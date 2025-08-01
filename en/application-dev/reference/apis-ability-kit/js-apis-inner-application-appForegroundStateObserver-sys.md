# AppForegroundStateObserver (System API)

The module defines the listener used to listen for application startup and exit state changes. It can be used as an input parameter of [on](js-apis-app-ability-appManager-sys.md#appmanageronappforegroundstate11) to listen for the state changes of all applications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## AppForegroundStateObserver

### onAppStateChanged

onAppStateChanged(appStateData: AppStateData): void

Called when the application launch or exit state changes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name | Type| Mandatory| Description  |
| ------ | ---- | ---- | ----- |
| appStateData   | [AppStateData](js-apis-inner-application-appStateData.md)   | Yes | Application state data.|

**Example**
```ts
import { appManager } from '@kit.AbilityKit';

let observer: appManager.AppForegroundStateObserver = {
  onAppStateChanged(appStateData) {
    console.info(`onAppStateChanged appStateData: ${JSON.stringify(appStateData)}`);
  },
};
appManager.on('appForegroundState', observer);
```
