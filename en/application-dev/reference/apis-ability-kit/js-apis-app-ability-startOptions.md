# @ohos.app.ability.StartOptions (StartOptions)

**StartOptions** is used as an input parameter of [startAbility()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1) to specify the window mode of an ability.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import StartOptions from '@ohos.app.ability.StartOptions';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| windowMode<sup>12+</sup> | [abilityConstant.windowMode](js-apis-app-ability-abilityConstant.md#abilityconstantwindowmode12)  | No| No| Window mode. The split-screen mode can be set when the ability is started within an application.|
| displayId | number | No| No| Display ID mode. The default value is **0**, indicating the current display.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| withAnimation<sup>11+</sup> | boolean | No| No| Whether the ability has the animation effect.|
| windowLeft<sup>11+</sup> | number | No| No| Left position of the window.|
| windowTop<sup>11+</sup> | number | No| No| Top position of the window.|
| windowWidth<sup>11+</sup> | number | No| No| Width of the window.|
| windowHeight<sup>11+</sup> | number | No| No| Height of the window.|
| processMode<sup>12+</sup> | [contextConstant.ProcessMode](js-apis-app-ability-contextConstant.md#contextconstantprocessmode12) | No| No| Process mode.<br>**Constraints**:<br>This attribute takes effect only on tablets.<br>This attribute takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>**processMode** and **startupVisibility** must be set in pair.|
| startupVisibility<sup>12+</sup> | [contextConstant.StartupVisibility](js-apis-app-ability-contextConstant.md#contextconstantstartupvisibility12) | No| No| Visibility of the ability after it is started in a new process.<br>**Constraints**:<br>This attribute takes effect only on tablets.<br>This attribute takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>**processMode** and **startupVisibility** must be set in pair.|
| windowFocused<sup>12+</sup> | boolean | No| No| Whether the window has focus. The default value is **true**, indicating that the window has focus.<br>**Constraints**:<br>This attribute takes effect only on tablets.<br>This attribute takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>This attribute takes effect only when the application to start is in cold start mode.|

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import Want from '@ohos.app.ability.Want';
  import StartOptions from '@ohos.app.ability.StartOptions';
  import { BusinessError } from '@ohos.base';

  export default class EntryAbility extends UIAbility {

    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'EntryAbility'
      };
      let options: StartOptions = {
        displayId: 0
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
