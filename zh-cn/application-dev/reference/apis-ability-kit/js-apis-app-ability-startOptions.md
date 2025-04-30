# @ohos.app.ability.StartOptions (StartOptions)

StartOptions可以作为[startAbility()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)的入参，用于指定目标Ability的窗口模式。

> **说明：**
>
> - 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { StartOptions } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| windowMode<sup>12+<sup> | number | 否 | 是 | 启动Ability时的窗口模式，详见[WindowMode](./js-apis-app-ability-abilityConstant.md#windowmode12)。 |
| displayId | number | 否 | 是 | 屏幕ID模式。默认是0，表示当前屏幕。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| withAnimation<sup>11+</sup> | boolean | 否 | 是 | 启动Ability时是否具有动画效果。true表示具有动画效果，false表示不具有动画效果。<br>**约束：**<br>1.该功能仅在2in1和tablet设备上生效。<br>2.调用方与目标方必须为同一应用。 |
| windowLeft<sup>11+</sup> | number | 否 | 是 | 窗口左边的位置，单位为px。取值范围为[0, maxWindowWidth]。如果设置为负值，系统会默认设置为0。配置该字段时，建议同时配置windowTop。 |
| windowTop<sup>11+</sup> | number | 否 | 是 | 窗口顶部的位置，单位为px。取值范围为[0, maxWindowHeight]。如果设置为负值，系统会默认设置为0。配置该字段时，建议同时配置windowLeft。 |
| windowWidth<sup>11+</sup> | number | 否 | 是 | 窗口的宽度，单位为px。取值范围为[minWindowWidth, maxWindowWidth]。 |
| windowHeight<sup>11+</sup> | number | 否 | 是 | 窗口的高度，单位为px。取值范围为[minWindowHeight, maxWindowHeight]。 |
| processMode<sup>12+</sup> | [contextConstant.ProcessMode](js-apis-app-ability-contextConstant.md#processmode12) | 否 | 是 | 进程模式。<br>**约束：**<br>1.该功能仅在2in1和tablet设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)中生效。<br>3.processMode和startupVisibility必须同时设置。 |
| startupVisibility<sup>12+</sup> | [contextConstant.StartupVisibility](js-apis-app-ability-contextConstant.md#startupvisibility12) | 是 | 否 | Ability启动后的可见性。<br>**约束：**<br>1.该功能仅在2in1和tablet设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)中生效。<br>3.processMode和startupVisibility必须同时设置。 |
| startWindowIcon<sup>14+</sup> | [image.PixelMap](../../reference/apis-image-kit/js-apis-image.md#pixelmap7) | 否 | 是 |  在应用内启动UIAbility时，启动页所显示的图标。如果未配置该字段，则默认采用module.json5文件中startWindowIcon字段的配置。<br>**约束：**<br>1.该功能仅在2in1和tablet设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)中生效。<br>3.图片数据大小限制为600M。|
| startWindowBackgroundColor<sup>14+</sup> | string | 否 | 是 |  在应用内启动UIAbility时，启动页所显示的背景颜色。固定为ARGB格式, 如：`#E5FFFFFF`。如果未配置该字段，则默认采用module.json5文件中startWindowBackground字段的配置。<br>**约束：**<br>1.该功能仅在2in1和tablet设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)中生效。 |
| supportWindowModes<sup>14+</sup> | Array\<[bundleManager.SupportWindowMode](./js-apis-bundleManager.md#supportwindowmode)> | 否 | 是 |  在应用内启动UIAbility时，指定窗口是否显示最大化/窗口化/分屏按键。如果未配置该字段，则默认采用该UIAbility对应的[module.json5配置文件](../../quick-start/module-configuration-file.md)中[abilities标签](../../quick-start/module-configuration-file.md#abilities标签)的supportWindowMode字段取值。<br>- FULL_SCREEN：支持全屏模式。<br>- FLOATING：支持悬浮窗模式。<br>- SPLIT：支持分屏模式。通常需要配合FULL_SCREEN或FLOATING一起使用，不建议只配置SPLIT。当仅配置SPLIT时，2in1设备上的窗口默认为悬浮窗模式，支持进入分屏模式；tablet设备上的窗口默认为全屏模式，支持进入分屏模式。 <br>**约束：**<br><!--RP1-->该功能仅在2in1和tablet设备上生效。<!--RP1End-->|
| minWindowWidth<sup>17+</sup> | number | 否 | 是 | 窗口最小的宽度，单位为px，可以通过[getWindowLimits](../apis-arkui/js-apis-window.md#getwindowlimits11)获得当前窗口的尺寸限制。<br>**约束：**<br/>仅在2in1和tablet设备上生效。 |
| minWindowHeight<sup>17+</sup> | number | 否 | 是 | 窗口最小的高度，单位为px，可以通过[getWindowLimits](../apis-arkui/js-apis-window.md#getwindowlimits11)获得当前窗口的尺寸限制。<br>**约束：**<br/>仅在2in1和tablet设备上生效。 |
| maxWindowWidth<sup>17+</sup> | number | 否 | 是 | 窗口最大的宽度，单位为px，可以通过[getWindowLimits](../apis-arkui/js-apis-window.md#getwindowlimits11)获得当前窗口的尺寸限制。<br>**约束：**<br/>仅在2in1和tablet设备上生效。 |
| maxWindowHeight<sup>17+</sup> | number | 否 | 是 | 窗口最大的高度，单位为px，可以通过[getWindowLimits](../apis-arkui/js-apis-window.md#getwindowlimits11)获得当前窗口的尺寸限制。<br>**约束：**<br/>仅在2in1和tablet设备上生效。 |

**示例：**

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
          ],
          minWindowWidth: 320,
          minWindowHeight: 240,
          maxWindowWidth: 2560,
          maxWindowHeight: 2560
        };

        try {
          this.context.startAbility(want, options, (err: BusinessError) => {
            if (err.code) {
              // 处理业务逻辑错误
              console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
              return;
            }
            // 执行正常业务
            console.info('startAbility succeed');
          });
        } catch (err) {
          // 处理入参错误异常
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
