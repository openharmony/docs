# @ohos.app.ability.StartOptions (startAbility的可选参数)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @dsz2025; @yangxuguang-huawei; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

StartOptions可以作为启动UIAbility接口（例如[startAbility()](js-apis-inner-application-uiAbilityContext.md#startability-1)）的入参，用于指定目标UIAbility启动时的选项，包括但不局限于窗口模式、目标UIAbility启动时所在的屏幕等。

> **说明：**
>
> - 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { StartOptions } from '@kit.AbilityKit';
```

## StartOptions

StartOptions用于指定启动目标UIAbility时的选项。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| windowMode<sup>12+<sup> | number | 否 | 是 | 启动UIAbility时的窗口模式，详见[WindowMode](./js-apis-app-ability-abilityConstant.md#windowmode12)。 |
| displayId | number | 否 | 是 | 屏幕ID，取值为大于等于-1的整数。<br>- 取值为-1，表示当前屏幕。<br>- 取值为0，表示主屏幕。<br>- 取值为正整数，表示指定ID的屏幕。<br>**说明**：<br>从API version 14开始，默认值是-1，即当前屏幕。<br>在API version 14之前版本，默认值为0，即主屏幕。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| withAnimation<sup>11+</sup> | boolean | 否 | 是 | 启动UIAbility时是否具有动画效果。true表示具有动画效果，false表示不具有动画效果。<br>**约束：**<br>1.该功能仅在2in1和Tablet设备上生效。<br>2.调用方与目标方必须为同一应用。 |
| windowLeft<sup>11+</sup> | number | 否 | 是 | 窗口左边的位置，单位为px。取值范围为[0, maxWindowWidth]。如果设置为负值，系统会默认设置为0。配置该字段时，建议同时配置windowTop。 |
| windowTop<sup>11+</sup> | number | 否 | 是 | 窗口顶部的位置，单位为px。取值范围为[0, maxWindowHeight]。如果设置为负值，系统会默认设置为0。配置该字段时，建议同时配置windowLeft。 |
| windowWidth<sup>11+</sup> | number | 否 | 是 | 窗口的宽度，单位为px。取值范围为[minWindowWidth, maxWindowWidth]。 |
| windowHeight<sup>11+</sup> | number | 否 | 是 | 窗口的高度，单位为px。取值范围为[minWindowHeight, maxWindowHeight]。 |
| processMode<sup>12+</sup> | [contextConstant.ProcessMode](js-apis-app-ability-contextConstant.md#processmode12) | 否 | 是 | UIAbility启动后的进程模式。<br>**约束：**<br>1.该功能仅在2in1和Tablet设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1)中生效。<br>3.processMode和startupVisibility必须同时设置。 |
| startupVisibility<sup>12+</sup> | [contextConstant.StartupVisibility](js-apis-app-ability-contextConstant.md#startupvisibility12) | 否 | 是 | UIAbility启动后的可见性。当用户设置目标UIAbility为不可见时，目标UIAbility的窗口不会显示在前台，dock栏也不会有图标，同时目标UIAbility的onForeground生命周期不会被调用。<br>**约束：**<br>1.该功能仅在2in1和Tablet设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1)中生效。<br>3.processMode和startupVisibility必须同时设置。 |
| startWindowIcon<sup>14+</sup> | [image.PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) | 否 | 是 |  启动当前应用的UIAbility时，启动页所显示的图标。如果未配置该字段，则默认采用module.json5文件中startWindowIcon字段的配置。<br>**约束：**<br>- 启动其他应用的UIAbility时，该字段不生效。<br>- 该功能仅在2in1和Tablet设备上生效。<br>- 仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1)中生效。<br>- 图片数据大小限制为600MB。|
| startWindowBackgroundColor<sup>14+</sup> | string | 否 | 是 |  启动当前应用的UIAbility时，启动页所显示的背景颜色。固定为ARGB格式, 如：`#E5FFFFFF`。如果未配置该字段，则默认采用module.json5文件中startWindowBackground字段的配置。<br>**约束：**<br>- 启动其他应用的UIAbility时，该字段不生效。<br>- 该功能仅在2in1和Tablet设备上生效。<br>- 仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1)中生效。 |
| supportWindowModes<sup>14+</sup> | Array\<[bundleManager.SupportWindowMode](./js-apis-bundleManager.md#supportwindowmode)> | 否 | 是 |  启动UIAbility时，指定窗口是否显示最大化/窗口化/分屏按键。如果未配置该字段，则默认采用该UIAbility对应的[module.json5配置文件](../../quick-start/module-configuration-file.md)中[abilities标签](../../quick-start/module-configuration-file.md#abilities标签)的supportWindowMode字段取值。<br>- FULL_SCREEN：支持全屏模式。<br>- FLOATING：支持悬浮窗模式。<br>- SPLIT：支持分屏模式。通常需要配合FULL_SCREEN或FLOATING一起使用，不建议只配置SPLIT。当仅配置SPLIT时，2in1设备上的窗口默认为悬浮窗模式，支持进入分屏模式；Tablet设备上的窗口默认为全屏模式，支持进入分屏模式。 <br>**约束：**<br><!--RP1-->该功能仅在2in1和Tablet设备上生效。<!--RP1End-->|
| minWindowWidth<sup>17+</sup> | number | 否 | 是 | 窗口最小的宽度，单位为px，可以通过[getWindowLimits](../apis-arkui/arkts-apis-window-Window.md#getwindowlimits11)获得当前窗口的尺寸限制。<br>**约束：**<br/>仅在2in1和Tablet设备上生效。 |
| minWindowHeight<sup>17+</sup> | number | 否 | 是 | 窗口最小的高度，单位为px，可以通过[getWindowLimits](../apis-arkui/arkts-apis-window-Window.md#getwindowlimits11)获得当前窗口的尺寸限制。<br>**约束：**<br/>仅在2in1和Tablet设备上生效。 |
| maxWindowWidth<sup>17+</sup> | number | 否 | 是 | 窗口最大的宽度，单位为px，可以通过[getWindowLimits](../apis-arkui/arkts-apis-window-Window.md#getwindowlimits11)获得当前窗口的尺寸限制。<br>**约束：**<br/>仅在2in1和Tablet设备上生效。 |
| maxWindowHeight<sup>17+</sup> | number | 否 | 是 | 窗口最大的高度，单位为px，可以通过[getWindowLimits](../apis-arkui/arkts-apis-window-Window.md#getwindowlimits11)获得当前窗口的尺寸限制。<br>**约束：**<br/>仅在2in1和Tablet设备上生效。 |
| completionHandler<sup>20+</sup> | [CompletionHandler](js-apis-app-ability-completionHandler.md) | 否 | 是 | 拉起应用结果的操作类，用于处理拉起应用的结果。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |
| hideStartWindow<sup>20+</sup> | boolean | 否 | 是 | 启动当前应用的UIAbility时，控制是否隐藏窗口的启动页。启动页介绍和规格详见[StartWindow](../../quick-start/module-configuration-file.md#startwindow标签)。<br>**约束：**<br/>1.该功能仅在2in1设备和自由多窗模式下的Tablet设备上生效。<br>2.该功能仅在启动当前应用的UIAbility时生效。 |
| windowCreateParams<sup>20+</sup> | [window.WindowCreateParams](../apis-arkui/arkts-apis-window-i.md#windowcreateparams20) | 否 | 是 | 启动UIAbility时的窗口参数。 |

**示例：**

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

      let color = new ArrayBuffer(512 * 512 * 4); // 创建一个ArrayBuffer对象，用于存储图像像素。该对象的大小为（height * width * 4）字节。
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
