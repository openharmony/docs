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
| withAnimation<sup>11+</sup> | boolean | No| Yes| Whether animation effects are used when the ability is started. The value **true** means that animation effects are used, and **false** means the opposite.<br>**Constraints**:<br>1. This property takes effect only on 2-in-1 devices and tablets.<br>2. The caller and target must be the same application.|
| windowLeft<sup>11+</sup> | number | No| Yes| Position of the left edge of the window, in px. The value range is [0, maxWindowWidth]. If a negative value is passed, the system will default to **0**. When configuring this field, you are advised to also configure **windowTop**.|
| windowTop<sup>11+</sup> | number | No| Yes| Position of the top edge of the window, in px. The value range is [0, maxWindowHeight]. If a negative value is passed, the system will default to **0**. When configuring this field, you are advised to also configure **windowLeft**.|
| windowWidth<sup>11+</sup> | number | No| Yes| Window width, in px. The value range is [minWindowWidth, maxWindowWidth].|
| windowHeight<sup>11+</sup> | number | No| Yes| Window height, in px. The value range is [minWindowHeight, maxWindowHeight].|
| processMode<sup>12+</sup> | [contextConstant.ProcessMode](js-apis-app-ability-contextConstant.md#processmode12) | No| Yes| Process mode.<br>**Constraints**:<br>1. This property takes effect only on 2-in-1 devices and tablets.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>3. **processMode** and **startupVisibility** must be set in pair.|
| startupVisibility<sup>12+</sup> | [contextConstant.StartupVisibility](js-apis-app-ability-contextConstant.md#startupvisibility12) | Yes| No| Visibility of the ability after it is started.<br>**Constraints**:<br>1. This property takes effect only on 2-in-1 devices and tablets.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>3. **processMode** and **startupVisibility** must be set in pair.|
| startWindowIcon<sup>14+</sup> | [image.PixelMap](../../reference/apis-image-kit/js-apis-image.md#pixelmap7) | No| Yes|  Icon displayed on the launch page when the UIAbility is started in an application. If this property is not set, the value of **startWindowIcon** in the **module.json5** file is used by default.<br>**Constraints**:<br>1. This property takes effect only on 2-in-1 devices and tablets.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).<br>3. The maximum size of an image is 600 MB.|
| startWindowBackgroundColor<sup>14+</sup> | string | No| Yes|  Background color of the launch page when the UIAbility is launched in an application. The value is in ARGB format, for example, **#E5FFFFFF**. If this property is not set, the value of **startWindowBackground** in the **module.json5** file is used by default.<br>**Constraints**:<br>1. This property takes effect only on 2-in-1 devices and tablets.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1).|
| supportWindowModes<sup>14+</sup> | Array\<[bundleManager.SupportWindowMode](./js-apis-bundleManager.md#supportwindowmode)> | No| Yes|  Whether to display the maximize, minimize, or split-screen button when the UIAbility is launched in an application. If this property is not set, the value of **supportWindowMode** configured under [abilities](../../quick-start/module-configuration-file.md#abilities) in the [module.json5 file](../../quick-start/module-configuration-file.md) corresponding to the UIAbility is used by default.<br>- **FULL_SCREEN**: full-screen mode.<br>- **FLOATING**: floating window mode.<br>- **SPLIT**: split-screen mode. Generally, **FULL_SCREEN** or **FLOATING** must be used together. You are not advised to configure only **SPLIT**. If only **SPLIT** is configured, the window on 2-in-1 devices is in floating window mode by default and can transition to the split-screen mode, and the window on tablets is in full-screen mode by default and can transition to the split-screen mode.<br>**Constraints**:<br><!--RP1-->This property takes effect only on 2-in-1 devices and tablets.<!--RP1End-->|
| minWindowWidth<sup>17+</sup> | number | No| Yes| Minimum width of the window, in px. You can call [getWindowLimits](../apis-arkui/js-apis-window.md#getwindowlimits11) to obtain the size limit of the current window.<br>**Constraints**:<br>It takes effect only on 2-in-1 devices and tablets.|
| minWindowHeight<sup>17+</sup> | number | No| Yes| Minimum height of the window, in px. You can call [getWindowLimits](../apis-arkui/js-apis-window.md#getwindowlimits11) to obtain the size limit of the current window.<br>**Constraints**:<br>It takes effect only on 2-in-1 devices and tablets.|
| maxWindowWidth<sup>17+</sup> | number | No| Yes| Maximum width of the window, in px. You can call [getWindowLimits](../apis-arkui/js-apis-window.md#getwindowlimits11) to obtain the size limit of the current window.<br>**Constraints**:<br>It takes effect only on 2-in-1 devices and tablets.|
| maxWindowHeight<sup>17+</sup> | number | No| Yes| Maximum height of the window, in px. You can call [getWindowLimits](../apis-arkui/js-apis-window.md#getwindowlimits11) to obtain the size limit of the current window.<br>**Constraints**:<br>It takes effect only on 2-in-1 devices and tablets.|
| completionHandler<sup>20+</sup> | [CompletionHandler](js-apis-app-ability-completionHandler.md) | No| Yes| Class for handling the results of application launching requests.|

**Example**

  ```ts
  import { UIAbility, Want, StartOptions, bundleManager, CompletionHandler } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { image } from '@kit.ImageKit';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'EntryAbility'
      };

      let completionHandler: CompletionHandler = {
        onRequestSuccess: (elementName: bundleManager.ElementName, message: string): void => {
          console.log(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start succeeded: ${message}`);
        },
        onRequestFailure: (elementName: bundleManager.ElementName, message: string): void => {
          console.log(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start failed: ${message}`);
        }
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
          ],
          minWindowWidth: 320,
          minWindowHeight: 240,
          maxWindowWidth: 2560,
          maxWindowHeight: 2560,
          completionHandler: completionHandler
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
