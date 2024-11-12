# @ohos.app.ability.appRecovery (appRecovery)

The **appRecovery** module provides APIs for recovering faulty applications.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. In API version 9, only applications with a single ability in a process can be recovered. In API version 10, applications with multiple abilities in a process can be recovered.

## Modules to Import
```ts
import { appRecovery } from '@kit.AbilityKit';
```

## RestartFlag

Enumerates the application restart flags. This enum is used as an input parameter of [enableAppRecovery](#apprecoveryenableapprecovery).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| ALWAYS_RESTART   | 0    | The application is restarted in all cases.|
| RESTART_WHEN_JS_CRASH   | 0x0001    | The application is restarted in the case of JS_CRASH.|
| RESTART_WHEN_APP_FREEZE   | 0x0002    | The application is restarted in the case of APP_FREEZE.|
| NO_RESTART           | 0xFFFF    | The application is not restarted in any case.|

## SaveOccasionFlag

Enumerates the scenarios for saving the application state. This enum is used as an input parameter of [enableAppRecovery](#apprecoveryenableapprecovery).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| SAVE_WHEN_ERROR            | 0x0001    | Saving the application state when an application fault occurs.|
| SAVE_WHEN_BACKGROUND            | 0x0002    | Saving the application state when the application is switched to the background.|

## SaveModeFlag  

Enumerates the application state saving modes. This enum is used as an input parameter of [enableAppRecovery](#apprecoveryenableapprecovery).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| SAVE_WITH_FILE             | 0x0001    | The application state is saved and written to the local file cache.|
| SAVE_WITH_SHARED_MEMORY             | 0x0002    | The application state is saved in the memory. When the application exits due to a fault, it is written to the local file cache.|

## appRecovery.enableAppRecovery

enableAppRecovery(restart?: [RestartFlag](#restartflag), saveOccasion?: [SaveOccasionFlag](#saveoccasionflag), saveMode?: [SaveModeFlag](#savemodeflag)) : void

Enables application recovery. After this API is called, the first ability that is displayed when the application is started from the initiator can be restored.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| restart | [RestartFlag](#restartflag) | No| Whether the application is restarted upon a fault. By default, the application is restarted.|
| saveOccasion | [SaveOccasionFlag](#saveoccasionflag) | No| Scenario for saving the application state. By default, the state is saved when a fault occurs.|
| saveMode | [SaveModeFlag](#savemodeflag) | No| Application state saving mode. By default, the application state is written to the local file cache.|

**Example**
    
```ts
import { appRecovery, AbilityStage } from '@kit.AbilityKit';

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

restartApp(): void

Restarts the current process and starts the first ability that is displayed when the application is started. If the state of this ability is saved, the saved state data is passed into the **wantParam** property in the **want** parameter of the **onCreate** lifecycle callback of the ability.

In API version 10, the ability specified by [setRestartWant](#apprecoverysetrestartwant10) is started. If no ability is specified, the following rules are used:
- If the ability of the current application running in the foreground supports recovery, that ability is started.
- If multiple abilities that support recovery is running in the foreground, only the last ability is started.
- If no ability is running in the foreground, none of them is started.

This API can be used together with the APIs of [errorManager](js-apis-app-ability-errorManager.md). The interval between two restarts must be greater than one minute. If this API is called repeatedly within one minute, the application exits but does not restart. The behavior of automatic restart is the same as that of proactive restart.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core


**Example**
    
```ts
import { appRecovery, errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: errorManager.ErrorObserver = {
  onUnhandledException(errorMsg) {
    console.log('onUnhandledException, errorMsg: ', errorMsg);
    appRecovery.restartApp();
  }
};

try {
  errorManager.on('error', observer);
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```

## appRecovery.saveAppState

saveAppState(): boolean

Saves the application state. This API can be used together with the APIs of [errorManager](js-apis-app-ability-errorManager.md).

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Whether the application state is saved. The value **true** is returned if the application state is saved, and **false** is returned otherwise.|

**Example**
    
```ts
import { appRecovery, errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: errorManager.ErrorObserver = {
  onUnhandledException(errorMsg) {
    console.log('onUnhandledException, errorMsg: ', errorMsg);
    appRecovery.saveAppState();
  }
};

try {
  errorManager.on('error', observer);
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```

## appRecovery.saveAppState<sup>10+</sup>

saveAppState(context?: UIAbilityContext): boolean

Saves the ability state, which will be used for recovery. This API can be used together with the APIs of [errorManager](js-apis-app-ability-errorManager.md).

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)| No| Context of the target ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Whether the application state is saved. The value **true** is returned if the application state is saved, and **false** is returned otherwise.|

**Example**

```ts
import { appRecovery, errorManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: errorManager.ErrorObserver = {
  onUnhandledException(errorMsg) {
    console.log('onUnhandledException, errorMsg: ', errorMsg);
    appRecovery.saveAppState(this.context);
  }
};

try {
  errorManager.on('error', observer);
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```

## appRecovery.setRestartWant<sup>10+</sup>

setRestartWant(want: Want): void

Sets an ability that will be recovered. The ability must be a UIAbility in the current bundle.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)| Yes| Want of the target ability. You can set the **bundleName** and **abilityName** fields in **Want** to specify the ability.|

**Example**

```ts
import { appRecovery, Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  build() {
    Button ("Start to Recover Ability")
      .fontSize(40)
      .fontWeight(FontWeight.Bold)
      .onClick(()=> {
        // set restart want
        let want: Want = {
          bundleName: "ohos.samples.recovery",
          abilityName: "RecoveryAbility"
        };

        appRecovery.setRestartWant(want);
      })
  }
}
```
