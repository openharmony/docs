# @ohos.app.ability.AbilityConstant (AbilityConstant)

The **AbilityConstant** module defines the ability-related enums, including the initial launch reasons, reasons for the last exit, ability continuation results, and window modes.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
```

## Attributes

## AbilityConstant.LaunchParam

Defines the parameters for starting an ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| launchReason | [LaunchReason](#abilityconstantlaunchreason)| Yes| Yes| Ability launch reason, which is an enumerated type.|
| lastExitReason | [LastExitReason](#abilityconstantlastexitreason) | Yes| Yes| Reason for the last exit, which is an enumerated type.|

## AbilityConstant.LaunchReason

Enumerates the initial ability launch reasons. You can use it together with [onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#uiabilityoncreate) of [Ability](js-apis-app-ability-uiAbility.md) to complete different operations.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.|
| START_ABILITY          | 1    | The ability is started by calling [startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability).|
| CALL | 2    | The ability is started by calling [startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybycall).|
| CONTINUATION           | 3    | The ability is started by means of cross-device migration.|
| APP_RECOVERY           | 4    | The ability is automatically started when the application is restored from a fault.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

class MyAbility extends UIAbility {
    onCreate(want, launchParam) {
        if (launchParam.launchReason === AbilityConstant.LaunchReason.START_ABILITY) {
            console.log('The ability has been started by the way of startAbility.');
        }
    }
}
```

## AbilityConstant.LastExitReason

Enumerates the reasons for the last exit. You can use it together with [onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#uiabilityoncreate) of [Ability](js-apis-app-ability-uiAbility.md) to complete different operations.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.|
| ABILITY_NOT_RESPONDING          | 1    | The ability does not respond.|
| NORMAL | 2    | The ability exits normally.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

class MyAbility extends UIAbility {
    onCreate(want, launchParam) {
        if (launchParam.lastExitReason === AbilityConstant.LastExitReason.ABILITY_NOT_RESPONDING) {
            console.log('The ability has exit last because the ability was not responding.');
        }
    }
}
```

## AbilityConstant.OnContinueResult 

Enumerates the ability continuation results. You can use it together with [onContinue(wantParam)](js-apis-app-ability-uiAbility.md#uiabilityoncontinue) of [Ability](js-apis-app-ability-uiAbility.md) to complete different operations.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | Continuation agreed.|
| REJECT           | 1    | Continuation denied.|
| MISMATCH  | 2    | Mismatch.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

class MyAbility extends UIAbility {
    onContinue(wantParam) {
        return AbilityConstant.OnContinueResult.AGREE;
    }
}
```

## AbilityConstant.WindowMode

Enumerates the window modes in which an ability can be displayed at startup. It can be used in **startAbility()** to specify the window mode when the ability is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name                       | Value| Description                |
| ---                         | --- | ---                  |
| WINDOW_MODE_UNDEFINED       | 0   | Undefined window mode.      |
| WINDOW_MODE_FULLSCREEN      | 1   | The ability is displayed in full screen.           |
| WINDOW_MODE_SPLIT_PRIMARY   | 100 | The left screen in horizontal direction or the upper screen in vertical direction is the primary window.  |
| WINDOW_MODE_SPLIT_SECONDARY | 101 | The right screen in horizontal direction or the lower screen in vertical direction is the secondary window.  |
| WINDOW_MODE_FLOATING        | 102 | The ability is displayed in a floating window.|

**Example**

```ts
let want = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility'
};
let option = {
    windowMode: AbilityConstant.WindowMode.WINDOW_MODE_FULLSCREEN
};

// Ensure that the context is obtained.
this.context.startAbility(want, option).then(()=>{
    console.log('Succeed to start ability.');
}).catch((error)=>{
    console.error('Failed to start ability with error: ${JSON.stringify(error)}');
});
```

## AbilityConstant.MemoryLevel

Enumerates the memory levels. You can use it in [onMemoryLevel(level)](js-apis-app-ability-ability.md#abilityonmemorylevel) of [Ability](js-apis-app-ability-ability.md) to complete different operations.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                        | Value| Description               |
| ---                         | --- | ---           |
| MEMORY_LEVEL_MODERATE       | 0   | Moderate memory usage.|
| MEMORY_LEVEL_LOW            | 1   | Low memory usage.  |
| MEMORY_LEVEL_CRITICAL       | 2   | High memory usage.  |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

class MyAbility extends UIAbility {
    onMemoryLevel(level) {
        if (level === AbilityConstant.MemoryLevel.MEMORY_LEVEL_CRITICAL) {
            console.log('The memory of device is critical, please release some memory.');
        }
    }
}
```

## AbilityConstant.OnSaveResult

Enumerates the result types for the operation of saving application data. You can use it in [onSaveState(reason, wantParam)](js-apis-app-ability-uiAbility.md#uiabilityonsavestate) of [Ability](js-apis-app-ability-uiAbility.md) to complete different operations.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALL_AGREE           | 0    | Always agreed to save the status.|
| CONTINUATION_REJECT           | 1    | Rejected to save the status in continuation.|
| CONTINUATION_MISMATCH  | 2    | Continuation mismatch.|
| RECOVERY_AGREE           | 3    | Agreed to restore the saved status.|
| RECOVERY_REJECT  | 4    | Rejected to restore the saved state.|
| ALL_REJECT  | 5    | Always rejected to save the status.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

class MyAbility extends UIAbility {
    onSaveState(reason, wantParam) {
        return AbilityConstant.OnSaveResult.ALL_AGREE;
    }
}
```

## AbilityConstant.StateType

Enumerates the scenarios for saving application data. You can use it in [onSaveState(reason, wantParam)](js-apis-app-ability-uiAbility.md#uiabilityonsavestate) of [Ability](js-apis-app-ability-uiAbility.md) to complete different operations.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| CONTINUATION           | 0    | Saving the status in continuation.|
| APP_RECOVERY           | 1    | Saving the status in application recovery.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

class MyAbility extends UIAbility {
    onSaveState(reason, wantParam) {
        if (reason === AbilityConstant.StateType.CONTINUATION) {
            console.log('Save the ability data when the ability continuation.');
        } 
        return AbilityConstant.OnSaveResult.ALL_AGREE;
    }
}
```
