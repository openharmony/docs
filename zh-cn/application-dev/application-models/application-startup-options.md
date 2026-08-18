# 应用启动设置

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @ccllee1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->


在应用开发中，启动应用（通常指启动UIAbility组件）是开发者的常见任务。例如，从商城应用跳转到支付应用进行付款，从聊天应用启动视频应用播放视频，或者在应用间跳转时需要指定特定的窗口模式等场景。

通过[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)，开发者可以在启动UIAbility时灵活控制其启动行为，包括窗口模式、窗口位置、启动动效、启动页样式、窗口尺寸限制等多个方面，从而满足不同设备形态和用户场景的需求。

## 指定窗口模式启动应用

在某些场景下，开发者需要指定UIAbility以特定的窗口模式启动。例如：

- 在平板设备上，商品详情窗口以分屏模式启动，充分利用大屏优势。
- 在PC/2in1设备上，打开文档时以全屏模式启动，提供沉浸式体验。
- 在视频应用中，打开视频播放UIAbility时，希望以悬浮窗形式显示，方便用户同时查看简介和播放界面。

**开发步骤如下：**

1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的windowMode，指定窗口模式。windowMode的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。如果未指定windowMode，UIAbility将以系统默认的窗口展示形态启动。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_windowMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/StartWithSpecifiedWindowMode/src/main/ets/pages/Index.ets) --> 


``` TypeScript
import { common, Want, AbilityConstant, StartOptions } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct StartWithSpecifiedWindowModeAbility {

  build() {
    Row() {
      Column() {
        Button("以分屏模式启动")
          .onClick(() => {
            // context为调用方UIAbility的UIAbilityContext
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.example.startoptions',
              abilityName: 'StartWithSpecifiedWindowModeAbility',
              parameters: {
                // 自定义信息
                info: '从StartWithSpecifiedWindowModeAbility启动'
              }
            };

            let options: StartOptions = {
              windowMode: AbilityConstant.WindowMode.WINDOW_MODE_SPLIT_SECONDARY // 以分屏模式拉起
            };

            context.startAbility(want, options).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


## 设置窗口显示模式

在某些场景下，开发者需要指定UIAbility窗口标题栏显示哪些窗口模式。例如：

- 需要控制窗口是否支持全屏模式。
- 需要控制窗口是否支持悬浮窗模式。
- 需要控制窗口是否支持分屏模式。

**开发步骤如下：**

1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的supportWindowModes，设置窗口显示模式。supportWindowModes的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_supportWindowModes](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/SupportWindowModes/src/main/ets/pages/Index.ets) --> 


``` TypeScript
import { common, Want, StartOptions, bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct SetWindowDisplayModeAbility {

  build() {
    Row() {
      Column() {
        Button("设置窗口显示模式")
          .onClick(() => {
            // context为调用方UIAbility的UIAbilityContext
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // 自定义信息
                info: '从EntryAbility启动'
              }
            };

            let options: StartOptions = {
              supportWindowModes: [
                bundleManager.SupportWindowMode.FULL_SCREEN,  // 支持全屏模式
              ]
            };

            context.startAbility(want, options).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 设置窗口分配比例

在某些场景下，开发者需要指定UIAbility在分屏模式下的窗口比例分配。例如，根据应用内容的重要程度，设置不同的分屏比例。

**开发步骤如下：**

1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 从API版本26.0.0开始，支持通过StartOptions的splitRatio字段设置窗口分配比例。splitRatio的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)和[SplitRatioPreference](../reference/apis-arkui/arkts-apis-window-e.md#splitratiopreference)。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_setSplitRatioAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/SetSplitRatioAbility/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { common, Want, StartOptions, AbilityConstant } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct SetSplitRatioAbility {

  build() {
    Row() {
      Column() {
        Button("以比例分屏启动")
          .onClick(() => {
            // context为调用方UIAbility的UIAbilityContext
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // 自定义信息
                info: '从EntryAbility启动'
              }
            };

            let options: StartOptions = {
              windowMode: AbilityConstant.WindowMode.WINDOW_MODE_SPLIT_SECONDARY, // 以分屏模式拉起
            };

            context.startAbility(want, options).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


## 指定显示屏幕启动应用

在多屏设备（如平板连接外接显示器、2in1设备等）上，开发者可能需要指定UIAbility在特定的屏幕上启动。例如：

- 在平板设备上，将视频播放功能启动到外接显示器上。
- 在2in1设备上，将辅助功能启动到副屏幕上。

**开发步骤如下：**

1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的displayId，指定要显示的屏幕。displayId的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_displayId](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/SpecifyDisplayScreen/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { common, Want, StartOptions } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct SpecifyDisplayScreen {

  build() {
    Row() {
      Column() {
        Button("在当前屏幕上启动")
          .onClick(() => {
            // context为调用方UIAbility的UIAbilityContext
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // 自定义信息
                info: '从EntryAbility启动'
              }
            };

            let options: StartOptions = {
              displayId: -1 // 在当前屏幕上启动
            };

            context.startAbility(want, options).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 控制应用启动时是否有动效

需要快速切换界面时，关闭动画以提升响应速度。

**开发步骤如下：**
1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的withAnimation，控制是否有启动动效。withAnimation的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_withAnimation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/ControlStartupAnimation/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { common, Want, StartOptions } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct ControlStartupAnimation {

  build() {
    Row() {
      Column() {
        Button("关闭启动动画")
          .onClick(() => {
            // context为调用方UIAbility的UIAbilityContext
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // 自定义信息
                info: '从EntryAbility启动'
              }
            };

            let options: StartOptions = {
              withAnimation: false // 关闭启动动画
            };

            context.startAbility(want, options).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 启动应用时设置窗口位置

在[自由窗口](../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，开发者可能需要指定UIAbility窗口的初始位置。例如：

- 在多窗口场景下，让新窗口出现在特定位置，避免遮挡其他重要内容。
- 在大屏设备上，为内容展示类应用设置较大的窗口尺寸。
- 在多窗口场景下，为辅助工具类应用设置较小的窗口尺寸。
- 将辅助窗口放置在屏幕边缘。

**开发步骤如下：**
1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的windowLeft、windowTop、windowWidth、windowHeight属性，设置窗口位置和尺寸。相关属性的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。建议同时配置windowLeft和windowTop字段。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_windowPosition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/SetWindowPosition/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { common, Want, StartOptions } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct SetWindowPosition {

  build() {
    Row() {
      Column() {
        Button("设置窗口位置")
          .onClick(() => {
            // context为调用方UIAbility的UIAbilityContext
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // 自定义信息
                info: '从EntryAbility启动'
              }
            };

            let options: StartOptions = {
              displayId: 0,
              windowLeft: 100,   // 距离屏幕左侧100px
              windowTop: 200,    // 距离屏幕顶部200px
              windowWidth: 800,  // 窗口宽度800px
              windowHeight: 600  // 窗口高度600px
            };

            context.startAbility(want, options).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 启动应用时设置窗口尺寸限制

在[自由窗口](../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，开发者可能需要限制UIAbility窗口的尺寸范围，防止用户将窗口调整得过大或过小。例如：

- 设置最小窗口尺寸，确保UI内容不会因为窗口太小而无法正常显示。
- 设置最大窗口尺寸，避免窗口在大屏设备上过大而影响使用体验。

**开发步骤如下：**
1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的minWindowWidth、minWindowHeight、maxWindowWidth、maxWindowHeight属性，设置窗口尺寸限制。相关属性的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。可以通过[getWindowLimitsVP](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowlimitsvp22)获取当前窗口的尺寸限制。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_windowSize](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/SetWindowSizeConstraints/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { common, Want, StartOptions } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct SetWindowSizeConstraintsAbility {

  build() {
    Row() {
      Column() {
        Button("设置ability的窗口尺寸")
          .onClick(() => {
            // context为调用方UIAbility的UIAbilityContext
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId为空表示本设备
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // 自定义信息
                info: '从EntryAbility启动'
              }
            };

            let options: StartOptions = {
              startWindowBackgroundColor: '#E510FFFF', // ARGB格式
              minWindowWidth: 320,   // 最小宽度320vp
              maxWindowWidth: 2560,  // 最大宽度2560vp
              minWindowHeight: 240,  // 最小高度240vp
              maxWindowHeight: 2560  // 最大高度2560vp
            };

            context.startAbility(want, options).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
            });
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 隐藏启动UIAbility

在某些场景下，开发者需要启动UIAbility但不希望其立即显示在前台。例如：启动一个用于后台监控的UIAbility，等待条件触发后再显示。

**开发步骤如下：**

1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的processMode和startupVisibility，设置进程模式和可见性。相关属性的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。
4. 调用startAbility接口，启动目标UIAbility。

> **说明:**
>
> 当设置目标UIAbility为不可见时：
> - 目标UIAbility的窗口不会显示在前台。
> - Dock栏不会有图标。
> - 目标UIAbility的onForeground生命周期不会被调用。

<!-- @[startOptions_startupVisibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/HideStartedUIAbility/src/main/ets/hidestarteduiabilityability/HideStartedUIAbilityAbility.ets) --> 

``` TypeScript
import { AbilityConstant, contextConstant, StartOptions, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;
const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;


export default class HideStartedUIAbilityAbility extends UIAbility {
  // ...

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');

    let want: Want = {
      deviceId: '', // deviceId为空表示本设备
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // 自定义信息
        info: '从EntryAbility启动'
      }
    };

    let options: StartOptions = {
      processMode: contextConstant.ProcessMode.NEW_PROCESS_ATTACH_TO_PARENT,
      startupVisibility: contextConstant.StartupVisibility.STARTUP_HIDE
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

  }

  // ...
}
```

## 设置启动页图标和背景色

开发者希望自定义UIAbility启动时显示的启动页图标和背景颜色。例如：

- 为特定功能UIAbility设置主题色一致的启动背景和专属图标，提升品牌识别度。
- 根据不同场景展示不同的启动页样式，增强视觉体验。

**开发步骤如下：**
1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的startWindowIcon和startWindowBackgroundColor，设置启动页图标和背景色。相关属性的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。
4. 调用startAbility接口，启动目标UIAbility。

> **说明:**
> 
> - 如果未配置startWindowIcon，则默认采用module.json5文件中startWindowIcon字段的配置。
> - 如果未配置startWindowBackgroundColor，则默认采用module.json5文件中startWindowBackground字段的配置。
> - 背景颜色为ARGB格式，如：`#E5FFFFFF`（透明度为E5，RGB值为FFFFFF）。

<!-- @[startOptions_bgColor_and_windowParam](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/SetBackgroundColor/src/main/ets/setbackgroundcolorability/SetBackgroundColorAbility.ets) --> 

``` TypeScript
import { AbilityConstant, StartOptions, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';

const DOMAIN = 0x0000;
const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class SetBackgroundColorAbility extends UIAbility {
  // ...

  async onForeground(): Promise<void> {
    // Ability has brought to foreground
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');

    let want: Want = {
      deviceId: '', // deviceId为空表示本设备
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // 自定义信息
        info: '从EntryAbility启动'
      }
    };

    // 创建PixelMap对象
    let color = new ArrayBuffer(512 * 512 * 4);
    let bufferArr = new Uint8Array(color);
    for (let i = 0; i < bufferArr.length; i += 4) {
      bufferArr[i] = 255;
      bufferArr[i+1] = 0;
      bufferArr[i+2] = 122;
      bufferArr[i+3] = 255;
    }

    let windowParam: window.WindowCreateParams = {};

    let options: StartOptions = {
      startWindowIcon: await image.createPixelMap(color, {
        editable: true,
        pixelFormat: image.PixelMapFormat.RGBA_8888,
        size: { height: 512, width: 512 }

      }),
      startWindowBackgroundColor: '#E510FFFF', // ARGB格式
      minWindowWidth: 320,
      minWindowHeight: 240,
      maxWindowWidth: 2560,
      maxWindowHeight: 2560,
      windowCreateParams: windowParam
    };

    this.context.startAbility(want, options).then(() => {
      hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
    }).catch((err: BusinessError) => {
      hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
    });

  }

  // ...
}
```


## 获取启动结果

在某些场景下，开发者需要获取UIAbility启动的结果，以便进行后续处理。例如：使用其他应用账号登录，需要知道拉起其他应用是否成功。

**开发步骤如下：**

1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的completionHandler，设置启动结果回调。completionHandler的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_completionHandler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/GetLaunchResult/src/main/ets/getlaunchresultability/GetLaunchResultAbility.ets) --> 

``` TypeScript
import { AbilityConstant, CompletionHandler, StartOptions, UIAbility, Want, bundleManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;
const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class GetLaunchResultAbility extends UIAbility {
  // ...

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');

    let want: Want = {
      deviceId: '', // deviceId为空表示本设备
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // 自定义信息
        info: '从EntryAbility启动'
      }
    };

    let completionHandler: CompletionHandler = {
      onRequestSuccess: (elementName: bundleManager.ElementName, message: string): void => {
        console.info(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start succeeded: ${message}`);
      },
      onRequestFailure: (elementName: bundleManager.ElementName, message: string): void => {
        console.error(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start failed: ${message}`);
      }
    };

    let options: StartOptions = {
      completionHandler: completionHandler
    };

    this.context.startAbility(want, options).then(() => {
      hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
    }).catch((err: BusinessError) => {
      hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
    });

  }

  // ...
}
```

## 隐藏启动页

在某些场景下，开发者希望启动UIAbility时不显示启动页，直接显示应用界面。例如：

- 快速切换功能时，避免启动页闪烁，提升体验流畅度。
- 应用界面加载速度很快时，不需要启动页过渡。

**开发步骤如下：**

1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的hideStartWindow，设置隐藏启动页。属性的说明参见[StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md)。
4. 调用startAbility接口，启动目标UIAbility。

> **说明:**
>
> 启动页介绍和规格详见[StartWindow](../quick-start/module-configuration-file.md#startwindow标签)。

<!-- @[startOptions_hidesplash](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/HideSplashScreen/src/main/ets/hidesplashscreenability/HideSplashScreenAbility.ets) -->

``` TypeScript
import { AbilityConstant, StartOptions, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;
const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class HideSplashScreenAbility extends UIAbility {
  // ...

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');

    let want: Want = {
      deviceId: '', // deviceId为空表示本设备
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // 自定义信息
        info: '从EntryAbility启动'
      }
    };

    let options: StartOptions = {
      hideStartWindow: true // 隐藏启动页
    };

    this.context.startAbility(want, options).then(() => {
      hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
    }).catch((err: BusinessError) => {
      hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
    });
  }

  // ...
}
```


## 设置窗口参数

在某些高级场景下，开发者需要更细粒度地控制UIAbility启动时的窗口参数。例如：窗口动效。

**开发步骤如下：**

1. 在启动UIAbility之前，需要先导入相关的模块。
2. 创建Want对象，指定要启动的UIAbility信息。UIAbilityContext的获取方式参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
3. 配置StartOptions的windowCreateParams，设置窗口参数。窗口参数配置详见[WindowCreateParams](../reference/apis-arkui/arkts-apis-window-i.md#windowcreateparams20)。
4. 调用startAbility接口，启动目标UIAbility。

<!-- @[startOptions_bgColor_and_windowParam](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/StartOptions/SetBackgroundColor/src/main/ets/setbackgroundcolorability/SetBackgroundColorAbility.ets) --> 

``` TypeScript
import { AbilityConstant, StartOptions, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';

const DOMAIN = 0x0000;
const TAG: string = '[StartAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class SetBackgroundColorAbility extends UIAbility {
  // ...

  async onForeground(): Promise<void> {
    // Ability has brought to foreground
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');

    let want: Want = {
      deviceId: '', // deviceId为空表示本设备
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // 自定义信息
        info: '从EntryAbility启动'
      }
    };

    // 创建PixelMap对象
    let color = new ArrayBuffer(512 * 512 * 4);
    let bufferArr = new Uint8Array(color);
    for (let i = 0; i < bufferArr.length; i += 4) {
      bufferArr[i] = 255;
      bufferArr[i+1] = 0;
      bufferArr[i+2] = 122;
      bufferArr[i+3] = 255;
    }

    let windowParam: window.WindowCreateParams = {};

    let options: StartOptions = {
      startWindowIcon: await image.createPixelMap(color, {
        editable: true,
        pixelFormat: image.PixelMapFormat.RGBA_8888,
        size: { height: 512, width: 512 }

      }),
      startWindowBackgroundColor: '#E510FFFF', // ARGB格式
      minWindowWidth: 320,
      minWindowHeight: 240,
      maxWindowWidth: 2560,
      maxWindowHeight: 2560,
      windowCreateParams: windowParam
    };

    this.context.startAbility(want, options).then(() => {
      hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in starting ability.');
    }).catch((err: BusinessError) => {
      hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${err.code}, message is ${err.message}`);
    });

  }

  // ...
}
```


