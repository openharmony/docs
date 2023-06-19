# @ohos.app.ability.appRecovery (appRecovery)

The **appRecovery** module provides APIs for recovering faulty applications.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. In the current version, only applications with a single ability in a single process can be recovered.

## Modules to Import
```ts
import appRecovery from '@ohos.app.ability.appRecovery';
```

## appRecovery.RestartFlag

Enumerates the application restart flags. This enum is used as an input parameter of [enableAppRecovery](#apprecoveryenableapprecovery).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| ALWAYS_RESTART   | 0    | The application is restarted in all cases.|
| RESTART_WHEN_JS_CRASH   | 0x0001    | The application is restarted in the case of JS_CRASH. |
| RESTART_WHEN_APP_FREEZE   | 0x0002    | The application is restarted in the case of APP_FREEZE. |
| NO_RESTART           | 0xFFFF    | The application is not restarted in any case.|

## appRecovery.SaveOccasionFlag

Enumerates the scenarios for saving the application state. This enum is used as an input parameter of [enableAppRecovery](#apprecoveryenableapprecovery).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| SAVE_WHEN_ERROR            | 0x0001    | Saving the application state when an application fault occurs.|
| SAVE_WHEN_BACKGROUND            | 0x0002    | Saving the application state when the application is switched to the background.|

## appRecovery.SaveModeFlag  

Enumerates the application state saving modes. This enum is used as an input parameter of [enableAppRecovery](#apprecoveryenableapprecovery).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| SAVE_WITH_FILE             | 0x0001    | The application state is saved and written to the local file cache.|
| SAVE_WITH_SHARED_MEMORY             | 0x0002    | The application state is saved in the memory. When the application exits due to a fault, it is written to the local file cache.|

## appRecovery.enableAppRecovery

enableAppRecovery(restart?: [RestartFlag](#apprecoveryrestartflag), saveOccasion?: [SaveOccasionFlag](#apprecoverysaveoccasionflag), saveMode?: [SaveModeFlag](#apprecoverysavemodeflag)) : void;

Enables application recovery. After this API is called, the first ability that is displayed when the application is started from the initiator can be restored.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| restart | [RestartFlag](#apprecoveryrestartflag) | No| Whether the application is restarted upon a fault. By default, the application is not restarted.|
| saveOccasion | [SaveOccasionFlag](#apprecoverysaveoccasionflag) | No| Scenario for saving the application state. By default, the state is saved when a fault occurs.|
| saveMode | [SaveModeFlag](#apprecoverysavemodeflag) | No| Application state saving mode. By default, the application state is written to the local file cache.|

**Example**
    
```ts
import appRecovery from '@ohos.app.ability.appRecovery';
import AbilityStage from '@ohos.app.ability.AbilityStage';

export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        appRecovery.enableAppRecovery(
            appRecovery.RestartFlag.ALWAYS_RESTART,
            appRecovery.SaveOccasionFlag.SAVE_WHEN_ERROR,
            appRecovery.SaveModeFlag.SAVE_WITH_FILE
        );
    }
}
```

## appRecovery.restartApp

restartApp(): void;

Restarts the application. This API can be used together with APIs of [errorManager](js-apis-app-ability-errorManager.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core


**Example**
    
```ts
import appRecovery from '@ohos.app.ability.appRecovery';
import errorManager from '@ohos.app.ability.errorManager';

let observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ', errorMsg);
        appRecovery.restartApp();
    }
};

try {
    errorManager.on('error', observer);
} catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
}
```

## appRecovery.saveAppState

saveAppState(): boolean;

Saves the application state. This API can be used together with APIs of [errorManager](js-apis-app-ability-errorManager.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Whether the application state is saved. The value **true** is returned if the application state is saved, and **false** is returned otherwise.|

**Example**
    
```ts
import appRecovery from '@ohos.app.ability.appRecovery';
import errorManager from '@ohos.app.ability.errorManager';

let observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ', errorMsg);
        appRecovery.saveAppState();
    }
};

try {
    errorManager.on('error', observer);
} catch (paramError) {
    console.log('error: ' + paramError.code + ', ' + paramError.message);
}
```
