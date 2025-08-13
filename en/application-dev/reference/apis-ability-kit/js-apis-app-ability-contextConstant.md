# @ohos.app.ability.contextConstant (Context-related Constants)

The ContextConstant module defines context-related enums. Currently, it defines only the enum of encryption levels.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { contextConstant } from '@kit.AbilityKit';
```

## AreaMode

Enumerates the data encryption levels.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name | Value| Description                                                                                                                  |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| EL1 | 0 | Device-level encryption. Directories with this encryption level are accessible after the device is powered on.<br>**Atomic service API**: This API can be used in atomic services since API version 11.   |
| EL2 | 1 | User-level encryption. Directories with this encryption level are accessible only after the device is powered on and the password is entered (for the first time).<br>**Atomic service API**: This API can be used in atomic services since API version 11.      |
| EL3<sup>11+<sup> | 2 | User-level encryption. The file permissions vary according to their scenarios.<br>- An open file is always readable and writable regardless of whether the screen is locked.<br>- When the screen is locked, a closed file cannot be opened, read, or written. When the screen is unlocked, such a file can be opened, read, and written.<br>- When the screen is locked, a file can be created and then opened and written but not read. When the screen is unlocked, a file can be created and then opened, read, and written.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| EL4<sup>11+<sup> | 3 | User-level encryption. The file permissions vary according to their scenarios.<br>- When the screen is locked, an open file is not readable or writable. When the screen is unlocked, such a file is readable and writable.<br>- When the screen is locked, a closed file cannot be opened, read, or written. When the screen is unlocked, such a file can be opened, read, and written.<br>- When the screen is locked, a file cannot be created. When the screen is unlocked, a file can be created and then opened, read, and written.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| EL5<sup>12+<sup> | 4 | Application-level encryption. The file permissions vary according to their scenarios.<br>- An open file is always readable and writable regardless of whether the screen is locked.<br>When the screen is locked, a closed file can be opened, read, and written only if the reserved key is obtained by calling [Access](js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess). When the screen is unlocked, such a file can be opened, read, and written.<br>A file can be created and then opened, read, and written regardless of whether the screen is locked.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|


## ProcessMode<sup>12+</sup>

Enumerates the process modes. It takes effect only on 2-in-1 devices and tablets.

As a property of [StartOptions](js-apis-app-ability-startOptions.md), **ProcessMode** takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1) and is used to specify the process mode of the target ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name | Value| Description                                                                                                                  |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| NEW_PROCESS_ATTACH_TO_PARENT | 1 | A new process is created, the ability is started on the process, and the process exits along with the parent process.<br>**Constraints**:<br>In this mode, the target ability and caller must be in the same application.                    |
| NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM | 2 | A new process is created, the ability is started on the process, and the process is bound to the status bar icon.<br>**Constraints**:<br>In this mode, the target ability and caller must be in the same application, and the application must have an icon in the status bar.                 |
| ATTACH_TO_STATUS_BAR_ITEM | 3 | The ability is started, and the process of the ability is bound to the status bar icon.<br>**Constraints**:<br>In this mode, the target ability and caller must be in the same application, and the application must have an icon in the status bar.                 |

**Example**

  ```ts
  import { UIAbility, Want, StartOptions, contextConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'MainAbility2'
      };
      let options: StartOptions = {
        processMode: contextConstant.ProcessMode.NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM,
        startupVisibility: contextConstant.StartupVisibility.STARTUP_HIDE
      };

      try {
        this.context.startAbility(want, options, (err: BusinessError) => {
          if (err.code) {
            // Process service logic errors.
            console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
            return;
          }
          // Carry out normal service processing.
          console.info('startAbility succeed');
        });
      } catch (err) {
        // Process input parameter errors.
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`startAbility failed, code is ${code}, message is ${message}`);
      }
    }
  }
  ```

## StartupVisibility<sup>12+</sup>

Enumerates the visibility statuses of an ability after it is started. It takes effect only on 2-in-1 devices and tablets.

As a property of [StartOptions](js-apis-app-ability-startOptions.md), **StartupVisibility** takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1) and specifies the visibility of the target ability after it is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name | Value| Description                                                                                                                  |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| STARTUP_HIDE | 0 | The target ability is hidden after it is started in the new process. The **onForeground** lifecycle of the ability is not invoked.       |
| STARTUP_SHOW | 1 | The target ability is displayed normally after it is started in the new process.    |

**Example**

  See [ContextConstant.ProcessMode](#processmode12).

## Scenarios<sup>20+</sup>

Enumerates the scenarios where the [onNewWant](./js-apis-app-ability-uiAbility.md#onnewwant) lifecycle callback is not triggered. It is used in the [setOnNewWantSkipScenarios](./js-apis-inner-application-uiAbilityContext.md#setonnewwantskipscenarios20) API.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name | Value| Description                                                                                                                  |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| SCENARIO_MOVE_MISSION_TO_FRONT | 0x00000001 | <!--RP1-->A scenario where the system API [missionManager.moveMissionToFront](./js-apis-app-ability-missionManager-sys.md#missionmanagermovemissiontofront-2) is called to move the UIAbility to the foreground.<!--RP1End-->        |
| SCENARIO_SHOW_ABILITY | 0x00000002 | A scenario where the [showAbility](./js-apis-inner-application-uiAbilityContext.md#showability12) API is called to move the UIAbility to the foreground.    |
| SCENARIO_BACK_TO_CALLER_ABILITY_WITH_RESULT | 0x00000004 | A scenario where the [backToCallerAbilityWithResult](./js-apis-inner-application-uiAbilityContext.md#backtocallerabilitywithresult12) API is called to move the UIAbility to the foreground.    |

**Example**

```ts
import { AbilityConstant, contextConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let scenarios: number = contextConstant.Scenarios.SCENARIO_MOVE_MISSION_TO_FRONT |
      contextConstant.Scenarios.SCENARIO_SHOW_ABILITY |
      contextConstant.Scenarios.SCENARIO_BACK_TO_CALLER_ABILITY_WITH_RESULT;

    try {
      this.context.setOnNewWantSkipScenarios(scenarios).then(() => {
        // Carry out normal service processing.
        console.info('setOnNewWantSkipScenarios succeed');
      }).catch((err: BusinessError) => {
        // Process service logic errors.
        console.error(`setOnNewWantSkipScenarios failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`setOnNewWantSkipScenarios failed, code is ${code}, message is ${message}`);
    }
  }
}
```
