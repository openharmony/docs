# 窗口旋转实践案例

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @lizihao_73-->
<!--Designer: @wambers584-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

窗口旋转提供了丰富的旋转策略，可以支持应用在各种场景下适配方向。

开发者在开发应用时，要兼顾应用的旋转策略在多种设备类型上的体验，为了帮助开发者快速上手，针对如下几个典型场景提供适配示例。

## 旋转策略配置适配差异化设备

当前设备形态多种多样，包括直板机、折叠机、三折叠、阔折叠等多类设备。如果应用的旋转策略仅按照其中一类设备适配，可能导致在其他设备上的体验下降。为了消除新增设备类型带来的额外适配工作，所以需要采用与设备类型无关的方式来配置旋转策略。

开发者可根据自身业务梳理不同设备形态下对旋转的诉求，如果单一策略（如：FOLLOW_DESKTOP、AUTO_ROTATION_UNSPECIFIED）能满足需求，推荐使用单一策略。若单一策略不能满足，可参考断点机制，实现差异化适配。

比如，在三折叠设备上，期望折叠态时竖屏显示，M态时竖屏显示，G态时横屏显示；在平板设备上，期望横屏显示；在直板机设备上，期望竖屏显示；在此场景下，可采用[WidthBreakpoint](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#widthbreakpoint13)断点机制实现差异化适配。

示例代码如下：

<!-- @[quick_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/DeviceDifferentiationSample/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { window } from '@kit.ArkUI'
import common from '@ohos.app.ability.common';
import { Callback } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State currentOrientation: string = 'UNSPECIFIED';
  private stage: window.WindowStage = (this.getUIContext().getHostContext() as common.UIAbilityContext).windowStage;
  private foldDisplayModeCallback: Callback<display.FoldDisplayMode> = (data: display.FoldDisplayMode) => {
    console.info(`Listening enabled. Data: ${data}`);
    this.getBreakPointAndSetOrientation();
  };

  aboutToAppear() {
    const ret = display.isFoldable();
    if (ret) {
      display.on('foldDisplayModeChange', this.foldDisplayModeCallback);
    } else {
      this.getBreakPointAndSetOrientation();
    }
  }

  aboutToDisappear() {
    display.off('foldDisplayModeChange', this.foldDisplayModeCallback);
  }

  private getBreakPointAndSetOrientation(): void {
    let displayInfo = display.getDefaultDisplaySync();
    let displayWidth = displayInfo.width;
    let displayHeight = displayInfo.height;
    let heightBp = displayHeight / displayWidth;
    if (displayWidth > displayHeight) {
      let temp = displayWidth;
      displayWidth = displayHeight;
      displayHeight = temp;
    }
    // 建议使用单一策略如"FOLLOW_DESKTOP"来应对设备的差异化，如单一策略无法满足需求，可参考断点机制，屏蔽设备差异
    // 此处是举的特殊示例，原则上支持横屏的应用，旋转策略应该是支持4个方向可旋转，此处是为了说明断点的使用方式，才举此例
    // 600为宽度断点枚举值其中的边界值， 0.8为高宽比断点枚举值其中的边界值
    if (displayWidth >= 600 && heightBp < 0.8) {
      this.stage.getMainWindowSync().setPreferredOrientation(window.Orientation.LANDSCAPE);
      this.currentOrientation = 'LANDSCAPE';
    } else {
      this.stage.getMainWindowSync().setPreferredOrientation(window.Orientation.PORTRAIT);
      this.currentOrientation = 'PORTRAIT';
    }
  }

  build() {
    RelativeContainer() {
      Text(this.currentOrientation)
        .fontWeight(600)
        .fontSize(30)
        .textAlign(TextAlign.Center)
        .position({ y: 300 })
        .width('100%')
    }
    .height('100%')
    .width('100%')
  }
}
```

## 视频类应用横竖屏切换

视频类应用横竖屏切换是指在视频类应用中，播放界面的详情页采用竖屏方式显示，用户可通过全屏按钮将页面切换至横屏方式显示，从而提供更佳的观看体验。

开发者可通过以下两种方式实现视频播放界面的横竖屏切换：

- 通过[调用窗口管理的setPreferredOrientation()接口](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-landscape-and-portrait-development#section188583141719)设置主窗口方向。

- 通过跳转到不同显示方向的页面来设置视频窗口方向。实现方式参考[通过页面跳转实现横竖屏切换](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-landscape-and-portrait-development#section161651074615)。

## 实现屏幕方向和窗口的orientation的相互转换

目前存在屏幕[orientation](../reference/apis-arkui/js-apis-display.md#属性)、屏幕[rotation](../reference/apis-arkui/js-apis-display.md#属性)和窗口[orientation](../reference/apis-arkui/arkts-apis-window-i.md#rotationchangeinfo19)概念，它们之间存在关联，但并不相同，可以参考[display.Orientation与display.rotation的关系](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-multi-device-window-direction#section5175174443718)。

在多设备、多形态的场景下（例如折叠屏手机、平板、外接显示器），屏幕的rotation（物理角度）和屏幕的orientation（逻辑横竖状态）并不总是一一对应。

直板机屏幕角度、屏幕方向、窗口方向对应关系：

| 屏幕角度 | 屏幕方向 | 窗口方向 |
| -------- | -------- | -------- |
| 0 | PORTRAIT | PORTRAIT |
| 90 | LANDSCAPE | LANDSCAPE_INVERTED |
| 180 | PORTRAIT_INVERTED | PORTRAIT_INVERTED |
| 270 | LANDSCAPE_INVERTED | LANDSCAPE |

三折叠全展开态屏幕角度、屏幕方向、窗口方向对应关系（在某些特性下，可能会与表中所述不一致，以实际表现为准）：

| 屏幕角度 | 屏幕方向 | 窗口方向 |
| -------- | -------- | -------- |
| 90 | PORTRAIT | PORTRAIT |
| 180 | LANDSCAPE | LANDSCAPE_INVERTED |
| 270 | PORTRAIT_INVERTED | PORTRAIT_INVERTED |
| 0 | LANDSCAPE_INVERTED | LANDSCAPE |

屏幕方向与窗口方向在横屏方向上的定义并不一致。比如在直板机上，窗口方向的横屏对应屏幕方向的反向横屏；窗口方向的反向横屏则对应屏幕方向的横屏。屏幕角度和屏幕方向也不总是一一对应。比如在三折叠全展开态上，屏幕角度为0时，屏幕方向并不是竖屏，而是反向横屏。如果开发者直接用[display.rotation](../reference/apis-arkui/js-apis-display.md#属性)或[display.orientation](../reference/apis-arkui/js-apis-display.md#属性)来判断窗口实际显示的方向，可能会出现应用显示方向错位的问题。因此，不能简单通过屏幕的orientation或rotation来判断窗口的orientation。

若开发者想准确知道当前窗口方向从而选择旋转策略（比如视频播放页面锁定当前方向），推荐获取到[display.rotation](../reference/apis-arkui/js-apis-display.md#属性)或[display.orientation](../reference/apis-arkui/js-apis-display.md#属性)后，再使用[convertOrientationAndRotation()](../reference/apis-arkui/arkts-apis-window-Window.md#convertorientationandrotation23)将屏幕方向转化为窗口方向，具体示例如下：

1. 获取目标屏幕方向。调用[getDefaultDisplaySync()](../reference/apis-arkui/js-apis-display.md#displaygetdefaultdisplaysync9)获取目标屏幕的Display对象，再通过其[display.orientation](../reference/apis-arkui/js-apis-display.md#属性)属性获取屏幕方向。

2. 将屏幕方向转换为窗口方向。调用[convertOrientationAndRotation()](../reference/apis-arkui/arkts-apis-window-Window.md#convertorientationandrotation23)可以把屏幕方向[display.orientation](../reference/apis-arkui/js-apis-display.md#属性)转换为窗口方向[orientation](../reference/apis-arkui/arkts-apis-window-i.md#rotationchangeinfo19)。

3. 将窗口方向转换为旋转策略。窗口方向还需要进一步转换为系统可识别的旋转策略窗口[Orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9)，才能传给setPreferredOrientation()。

4. 调用[setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1)接口设置旋转策略锁定显示方向。

<!-- @[quick_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/ConvertOrientationAndRotationSample/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { display, window } from '@kit.ArkUI';

@Entry
@Component
struct SpecificSceneSetOrientationIndex {
  mainWindow: window.Window = AppStorage.get('mainWindow_SetOrientation') as window.Window;
  setOrientationByDisplay() {
    try {
      // 1.获取当前默认Display
      const disp = display.getDefaultDisplaySync();
      const displayOrientation = disp.orientation; // 当前屏幕方向（0/1/2/3）

      console.info('Current display orientation = ' + displayOrientation);
      // 2.将displayOrientation转换为windowOrientation
      let windowOrientation: number =
        this.mainWindow.convertOrientationAndRotation(
          window.RotationInfoType.DISPLAY_ORIENTATION,
          window.RotationInfoType.WINDOW_ORIENTATION,
          displayOrientation
        );
      // 3.根据windowOrientation映射到window.Orientation
      let orientation: window.Orientation = window.Orientation.UNSPECIFIED;

      switch (windowOrientation) {
        case 0:
          orientation = window.Orientation.PORTRAIT;
          break;
        case 1:
          orientation = window.Orientation.LANDSCAPE_INVERTED;
          break;
        case 2:
          orientation = window.Orientation.PORTRAIT_INVERTED;
          break;
        case 3:
          orientation = window.Orientation.LANDSCAPE;
          break;
        default:
          throw new Error('Invalid orientation value');
      }
      // 4.设置旋转策略锁定窗口方向
      this.mainWindow.setPreferredOrientation(orientation, (err) => {
        if (err && err.code) {
          console.error('setPreferredOrientation failed: ' + JSON.stringify(err));
        }
      });
    } catch (exception) {
      console.error('Exception in setOrientationByDisplay: ' + JSON.stringify(exception));
    }
  }
  build() {
    Column() {
      Text('Lock the display orientation')
        .fontSize(17)
      Button('Set orientation from display')
        .onClick(() => {
          console.info('Click: Set orientation from display');
          this.setOrientationByDisplay();
        })
        .margin({ top: 20 })
    }
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
    .height('100%')
    .width('100%')
  }
}
```
