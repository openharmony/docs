# AppForegroundStateObserver (System API)

The AppForegroundStateObserver module defines the listener used to listen for application startup and exit state changes. It can be used as an input parameter of [on](js-apis-app-ability-appManager-sys.md#appmanageronappforegroundstate11) to listen for the state changes of all applications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Attributes

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                            | Type                   | Readable| Writable| Description  |
| -------------------------------- | ---------------------- | ---- | ---- | ------------------ |
| onAppStateChanged   | AsyncCallback\<void>   | Yes  | No  | Callback invoked when the startup or exit state of an application changes. The parameter type passed in is [AppStateData](js-apis-inner-application-appStateData-sys.md).|

**Example**
```ts
import { appManager } from '@kit.AbilityKit';

let observer: appManager.AppForegroundStateObserver = {
  onAppStateChanged(appStateData) {
    console.log(`onAppStateChanged appStateData: ${JSON.stringify(appStateData)}`);
  },
};
appManager.on('appForegroundState', observer);
```
