# @ohos.app.ability.AbilityConstant (AbilityConstant) (System API)

The **AbilityConstant** module defines the enums of the window types in the UIAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.AbilityConstant (AbilityConstant)](js-apis-app-ability-abilityConstant.md).

## Modules to Import

```ts
import { AbilityConstant } from '@kit.AbilityKit';
```

## WindowMode

Enumerates the window modes in which an ability can be displayed at startup. It can be used in **startAbility()** to specify the window mode when the ability is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name                       | Value| Description                |
| ---                         | --- | ---                  |
| WINDOW_MODE_UNDEFINED       | 0   | Undefined window mode.      |
| WINDOW_MODE_FLOATING        | 102 | The ability is displayed in a floating window.|

**Example**

```ts
import { UIAbility, StartOptions, Want, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let option: StartOptions = {
  windowMode: AbilityConstant.WindowMode.WINDOW_MODE_FULLSCREEN
};

// Ensure that the context is obtained.
class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.startAbility(want, option).then(() => {
      console.log('Succeed to start ability.');
    }).catch((error: BusinessError) => {
      console.error('Failed to start ability with error: ${JSON.stringify(error)}');
    });
  }
}
```
