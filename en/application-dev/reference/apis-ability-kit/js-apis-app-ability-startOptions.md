# @ohos.app.ability.StartOptions (StartOptions)

**StartOptions** is used as an input parameter of [startAbility()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1) to specify the window mode of an ability.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { StartOptions } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| windowMode<sup>12+<sup> | number | No| Yes| Window mode when the ability is started. For details, see [WindowMode](./js-apis-app-ability-abilityConstant.md#windowmode12).|
| displayId | number | No| Yes| Display ID mode. The default value is **0**, indicating the current display.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| withAnimation<sup>11+</sup> | boolean | No| Yes| Whether the ability has the animation effect.|
| windowLeft<sup>11+</sup> | number | No| Yes| Left position of the window.|
| windowTop<sup>11+</sup> | number | No| Yes| Top position of the window.|
| windowWidth<sup>11+</sup> | number | No| Yes| Width of the window.|
| windowHeight<sup>11+</sup> | number | No| Yes| Height of the window.|
| processMode<sup>12+</sup> | [contextConstant.ProcessMode](js-apis-app-ability-contextConstant.md#processmode12) | No| Yes| Process mode.<br>**Constraints**:<br>1. This property takes effect only on tablets.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>3. **processMode** and **startupVisibility** must be set in pair.|
| startupVisibility<sup>12+</sup> | [contextConstant.StartupVisibility](js-apis-app-ability-contextConstant.md#startupvisibility12) | Yes| No| Visibility of the ability after it is started.<br>**Constraints**:<br>1. This property takes effect only on tablets.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>3. **processMode** and **startupVisibility** must be set in pair.|
| startWindowIcon<sup>14+</sup> | [image.PixelMap](../../reference/apis-image-kit/js-apis-image.md#pixelmap7) | No| Yes|  Icon displayed on the launch page when the UIAbility is started in an application. If this property is not set, the value of **startWindowIcon** in the **module.json5** file is used by default.<br>**Constraints**:<br>1. This property takes effect only on tablets and 2-in-1 devices.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>3. The maximum size of an image is 600 MB.|
| startWindowBackgroundColor<sup>14+</sup> | string | No| Yes|  Background color of the launch page when the UIAbility is launched in an application. If this property is not set, the value of **startWindowBackground** in the **module.json5** file is used by default.<br>**Constraints**:<br>1. This property takes effect only on tablets and 2-in-1 devices.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).|
| supportWindowModes<sup>14+</sup> | Array\<[bundleManager.SupportWindowMode](./js-apis-bundleManager.md#supportwindowmode)> | No| Yes|  Whether to display the maximize, minimize, or split-screen button when the UIAbility is launched in an application. If this property is not set, the value of **supportWindowMode** in the **module.json5** file is used by default.<br>**Constraints**:<br>This property takes effect only on tablets and 2-in-1 devices.|
 
**Example**

  ```ts
  import { UIAbility, Want, StartOptions, bundleManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { image } from '@kit.ImageKit';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'EntryAbility'
      };

      let color = new ArrayBuffer(0);
      let imagePixelMap: image.PixelMap;
      image.createPixelMap(color, {
        size: {
          height: 100,
          width: 100
        }
      }).then((data) => {
        imagePixelMap = data;
        let options: StartOptions = {
          displayId: 0,
          startWindowIcon: imagePixelMap,
          startWindowBackgroundColor: '#00000000',
          supportWindowModes: [
            bundleManager.SupportWindowMode.FULL_SCREEN,
            bundleManager.SupportWindowMode.SPLIT,
            bundleManager.SupportWindowMode.FLOATING
          ]
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
      }).catch((err: BusinessError) => {
        console.error(`createPixelMap failed, code is ${err.code}, message is ${err.message}`);
      });
    }
  }
  ```
