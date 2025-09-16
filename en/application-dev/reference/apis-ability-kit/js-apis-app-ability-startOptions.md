# @ohos.app.ability.StartOptions (Optional Parameters of startAbility)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @dsz2025; @yangxuguang-huawei; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

StartOptions can be used as an input parameter for APIs used to start a UIAbility (for example, [startAbility()](js-apis-inner-application-uiAbilityContext.md#startability-1)). It specifies the options for starting the target UIAbility, including but not limited to the window mode and the display where the target UIAbility is started.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { StartOptions } from '@kit.AbilityKit';
```

## StartOptions

StartOptions is used to specify the options for starting a UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| windowMode<sup>12+<sup> | number | No| Yes| Window mode for the UIAbility upon startup. For details, see [WindowMode](./js-apis-app-ability-abilityConstant.md#windowmode12).|
| displayId | number | No| Yes| Display ID, which is an integer greater than or equal to -1.<br>- The value **-1** means the current screen.<br>- The value **0** means the primary screen.<br>- A positive integer means a specific screen with that ID.<br>**NOTE**<br>Starting from API version 14, the default value is **-1**, indicating the current screen.<br>In versions earlier than API version 14, the default value is **0**, indicating the primary screen.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| withAnimation<sup>11+</sup> | boolean | No| Yes| Whether animation effects are used for the UIAbility upon startup. **true** if used, **false** otherwise.<br>**Constraints**:<br>1. This property takes effect only on 2-in-1 devices and tablets.<br>2. The caller and target must be the same application.|
| windowLeft<sup>11+</sup> | number | No| Yes| Position of the left edge of the window, in px. The value range is [0, maxWindowWidth]. If a negative value is passed, the system will default to **0**. When configuring this field, you are advised to also configure **windowTop**.|
| windowTop<sup>11+</sup> | number | No| Yes| Position of the top edge of the window, in px. The value range is [0, maxWindowHeight]. If a negative value is passed, the system will default to **0**. When configuring this field, you are advised to also configure **windowLeft**.|
| windowWidth<sup>11+</sup> | number | No| Yes| Window width, in px. The value range is [minWindowWidth, maxWindowWidth].|
| windowHeight<sup>11+</sup> | number | No| Yes| Window height, in px. The value range is [minWindowHeight, maxWindowHeight].|
| processMode<sup>12+</sup> | [contextConstant.ProcessMode](js-apis-app-ability-contextConstant.md#processmode12) | No| Yes| Process mode of the UIAbility after it is started.<br>**Constraints**:<br>1. This property takes effect only on 2-in-1 devices and tablets.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1).<br>3. **processMode** and **startupVisibility** must be set in pair.|
| startupVisibility<sup>12+</sup> | [contextConstant.StartupVisibility](js-apis-app-ability-contextConstant.md#startupvisibility12) | Yes| No| Visibility status of the UIAbility after it is started. If the target UIAbility is set to invisible, the window of the target UIAbility is not displayed in the foreground, there is no icon in the dock, and the **onForeground** lifecycle of the target UIAbility is not triggered.<br>**Constraints**:<br>1. This property takes effect only on 2-in-1 devices and tablets.<br>2. This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1).<br>3. **processMode** and **startupVisibility** must be set in pair.|
| startWindowIcon<sup>14+</sup> | [image.PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) | No| Yes|  Icon displayed on the starting window for the UIAbility of the current application upon startup. If this property is not set, the value of **startWindowIcon** in the **module.json5** file is used by default.<br>**Constraints**:<br>- This property does not take effect for the UIAbility of another application.<br>- This property takes effect only on 2-in-1 devices and tablets.<br>- This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1).<br>- The maximum size of an image used as the startup icon is 600 MB.|
| startWindowBackgroundColor<sup>14+</sup> | string | No| Yes|  Background color of the window for the UIAbility of the current application upon startup. The value is in ARGB format, for example, **#E5FFFFFF**. If this property is not set, the value of **startWindowBackground** in the **module.json5** file is used by default.<br>**Constraints**:<br>- This property does not take effect for the UIAbility of another application.<br>- This property takes effect only on 2-in-1 devices and tablets.<br>- This property takes effect only in [UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1).|
| supportWindowModes<sup>14+</sup> | Array\<[bundleManager.SupportWindowMode](./js-apis-bundleManager.md#supportwindowmode)> | No| Yes|  Window mode supported by the UIAbility when it is started. The supported window mode specifies whether to display the maximize, minimize, or split-screen button. If this property is not set, the value of **supportWindowMode** configured under [abilities](../../quick-start/module-configuration-file.md#abilities) in the [module.json5](../../quick-start/module-configuration-file.md) file corresponding to the UIAbility is used by default.<br>- **FULL_SCREEN**: full-screen mode.<br>- **FLOATING**: floating window mode.<br>- **SPLIT**: split-screen mode. Generally, **FULL_SCREEN** or **FLOATING** must be used together. You are not advised to configure only **SPLIT**. If only **SPLIT** is configured, the window on 2-in-1 devices is in floating window mode by default and can transition to the split-screen mode, and the window on tablets is in full-screen mode by default and can transition to the split-screen mode.<br>**Constraints**:<br><!--RP1-->This property takes effect only on 2-in-1 devices and tablets.<!--RP1End-->|
| minWindowWidth<sup>17+</sup> | number | No| Yes| Minimum width of the window, in px. You can call [getWindowLimits](../apis-arkui/arkts-apis-window-Window.md#getwindowlimits11) to obtain the size limit of the current window.<br>**Constraints**:<br>It takes effect only on 2-in-1 devices and tablets.|
| minWindowHeight<sup>17+</sup> | number | No| Yes| Minimum height of the window, in px. You can call [getWindowLimits](../apis-arkui/arkts-apis-window-Window.md#getwindowlimits11) to obtain the size limit of the current window.<br>**Constraints**:<br>It takes effect only on 2-in-1 devices and tablets.|
| maxWindowWidth<sup>17+</sup> | number | No| Yes| Maximum width of the window, in px. You can call [getWindowLimits](../apis-arkui/arkts-apis-window-Window.md#getwindowlimits11) to obtain the size limit of the current window.<br>**Constraints**:<br>It takes effect only on 2-in-1 devices and tablets.|
| maxWindowHeight<sup>17+</sup> | number | No| Yes| Maximum height of the window, in px. You can call [getWindowLimits](../apis-arkui/arkts-apis-window-Window.md#getwindowlimits11) to obtain the size limit of the current window.<br>**Constraints**:<br>It takes effect only on 2-in-1 devices and tablets.|
| completionHandler<sup>20+</sup> | [CompletionHandler](js-apis-app-ability-completionHandler.md) | No| Yes| Operation class used to handle the result of an application launch request.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| hideStartWindow<sup>20+</sup> | boolean | No| Yes| Whether to hide the starting window for the UIAbility of the current application upon startup. For details about the starting window and its specifications, see [StartWindow](../../quick-start/module-configuration-file.md#startwindow).<br>**Constraints**:<br>1. This property takes effect only on tablets in free windows mode and 2-in-1 devices.<br>2. This property applies only for an attempt to launch the UIAbility of the current application.|
| windowCreateParams<sup>20+</sup> | [window.WindowCreateParams](../apis-arkui/arkts-apis-window-i.md#windowcreateparams20) | No| Yes| Parameters for the window for the UIAbility upon startup.|

**Example**

  ```ts
  import { UIAbility, Want, StartOptions, bundleManager, CompletionHandler } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { image } from '@kit.ImageKit';
  import { window } from '@kit.ArkUI';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'EntryAbility'
      };

      let completionHandler: CompletionHandler = {
        onRequestSuccess: (elementName: bundleManager.ElementName, message: string): void => {
          console.info(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start succeeded: ${message}`);
        },
        onRequestFailure: (elementName: bundleManager.ElementName, message: string): void => {
          console.error(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start failed: ${message}`);
        }
      };

      let color = new ArrayBuffer(512 * 512 * 4); // Create an ArrayBuffer object to store image pixels. The size of the object is (height * width * 4) bytes.
      let imagePixelMap: image.PixelMap;
      let windowParam: window.WindowCreateParams = {};
      let bufferArr = new Uint8Array(color);
      for (let i = 0; i < bufferArr.length; i += 4) {
        bufferArr[i] = 255;
        bufferArr[i+1] = 0;
        bufferArr[i+2] = 122;
        bufferArr[i+3] = 255;
      }
      image.createPixelMap(color, {
        editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 512, width: 512 }
      }).then((data) => {
        imagePixelMap = data;
        let options: StartOptions = {
          displayId: 0,
          startWindowIcon: imagePixelMap,
          startWindowBackgroundColor: '#E510FFFF',
          supportWindowModes: [
            bundleManager.SupportWindowMode.FULL_SCREEN,
            bundleManager.SupportWindowMode.SPLIT,
            bundleManager.SupportWindowMode.FLOATING
          ],
          minWindowWidth: 320,
          minWindowHeight: 240,
          maxWindowWidth: 2560,
          maxWindowHeight: 2560,
          completionHandler: completionHandler,
          hideStartWindow: true,
          windowCreateParams: windowParam
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
