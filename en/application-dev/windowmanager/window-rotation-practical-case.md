# Window Rotation Practical Cases

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @lizihao_73-->
<!--Designer: @wambers584-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=eb297c120685014d3e534d0011425fa2c96518e7 translatedAt=2026-08-11T10:12:49.868Z pushedAt=2026-08-12T02:49:08.103Z -->

Window rotation provides a rich set of rotation policies, enabling apps to adapt their orientation in various scenarios.

When developing an app, developers need to consider the rotation policy experience across multiple device types. To help developers get started quickly, adaptation examples are provided for the following typical scenarios.

## Rotation Policy Configuration for Differentiated Device Adaptation

Currently, there is a wide variety of device forms, including bar phones, foldables, tri-fold devices, wide-fold devices, and more. If an app's rotation policy is adapted for only one type of device, the experience on other devices may be degraded. To eliminate the extra adaptation effort caused by new device types, a device-type-independent approach must be adopted for configuring rotation policies.

You can analyze the rotation requirements across different device forms based on your service requirements. If a single policy (such as **FOLLOW_DESKTOP** or **AUTO_ROTATION_UNSPECIFIED**) meets the requirements, it is recommended to use a single policy. If a single policy is insufficient, the breakpoint mechanism can be referenced to achieve differentiated adaptation.

For example, on a tri-fold device, portrait display is expected in the folded state, portrait display in the M state, and landscape display in the G state; on a tablet, landscape display is expected; on a bar phone, portrait display is expected. In this scenario, the [WidthBreakpoint](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#widthbreakpoint13) breakpoint mechanism can be used to achieve differentiated adaptation.

The sample code is as follows:

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
    // It is recommended to use a single policy such as "FOLLOW_DESKTOP" to handle device differentiation. If a single policy cannot meet the requirements, refer to the breakpoint mechanism to mask device differences.
    // This is a special example. In principle, for an app that supports landscape mode, the rotation policy should allow rotation in all four directions. This example is provided solely to illustrate how to use breakpoints.
    // 600 is a boundary value of the width breakpoint enum, and 0.8 is a boundary value of the aspect ratio breakpoint enum.
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

## Landscape/Portrait Switching for Video Apps

Landscape/portrait switching for video apps refers to the scenario where the details page of the playback UI is displayed in portrait mode, and users can switch the page to landscape mode via a full-screen button for a better viewing experience.

You can implement landscape/portrait switching for the video playback UI in the following two ways:

- Set the main window orientation by [calling the setPreferredOrientation() API of window management](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-landscape-and-portrait-development#section188583141719).

- Set the video window orientation by navigating to a page with a different display orientation. For implementation details, see [Implementing Landscape/Portrait Mode Switching Through Page Redirection](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-landscape-and-portrait-development#section161651074615).

## Converting Between Screen Orientation and Window Orientation

There are three related but distinct concepts: screen [orientation](../reference/apis-arkui/js-apis-display.md#attributes), screen [rotation](../reference/apis-arkui/js-apis-display.md#attributes), and window [orientation](../reference/apis-arkui/arkts-apis-window-i.md#rotationchangeinfo19).

In multi-device and multi-form-factor scenarios (such as foldable phones, tablets, and external displays), the screen rotation (physical angle) and screen orientation (logical portrait/landscape state) do not always have a one-to-one correspondence.

The following table shows the mapping among screen angle, screen orientation, and window orientation for a bar phone:

| Screen Angle | Screen Orientation | Window Orientation |
| -------- | -------- | -------- |
| 0 | PORTRAIT | PORTRAIT |
| 90 | LANDSCAPE | LANDSCAPE_INVERTED |
| 180 | PORTRAIT_INVERTED | PORTRAIT_INVERTED |
| 270 | LANDSCAPE_INVERTED | LANDSCAPE |

Correspondence between screen angle, screen orientation, and window orientation in the tri-fold fully expanded state (under certain features, the actual behavior may differ from the table below; refer to the actual performance):

| Screen Angle | Screen Orientation | Window Orientation |
| -------- | -------- | -------- |
| 90 | PORTRAIT | PORTRAIT |
| 180 | LANDSCAPE | LANDSCAPE_INVERTED |
| 270 | PORTRAIT_INVERTED | PORTRAIT_INVERTED |
| 0 | LANDSCAPE_INVERTED | LANDSCAPE |

The definitions of screen orientation and window orientation in the landscape direction are not consistent. For example, on a bar phone, the landscape window orientation corresponds to the inverted landscape screen orientation, while the inverted landscape window orientation corresponds to the landscape screen orientation. Screen angle and screen orientation are also not always in a one-to-one correspondence. For instance, in the tri-fold fully expanded state, when the screen angle is **0**, the screen orientation is not portrait but inverted landscape. If you directly use [display.rotation](../reference/apis-arkui/js-apis-display.md#attributes) or [display.orientation](../reference/apis-arkui/js-apis-display.md#attributes) to determine the actual display direction of a window, app display orientation misalignment may occur. Therefore, the window orientation cannot be determined simply by the screen orientation or rotation.

If you want to accurately know the current window orientation to select a rotation policy (for example, locking the current orientation on a video playback page), it is recommended to first obtain [display.rotation](../reference/apis-arkui/js-apis-display.md#attributes) or [display.orientation](../reference/apis-arkui/js-apis-display.md#attributes), and then use [convertOrientationAndRotation()](../reference/apis-arkui/arkts-apis-window-Window.md#convertorientationandrotation23) to convert the screen orientation to the window orientation. The following is a specific example:

1. Obtain the target screen orientation. Call [getDefaultDisplaySync()](../reference/apis-arkui/js-apis-display.md#displaygetdefaultdisplaysync9) to obtain the **Display** object of the target screen, and then obtain the screen orientation through [display.orientation](../reference/apis-arkui/js-apis-display.md#attributes).

2. Convert the screen orientation to the window orientation. Call [convertOrientationAndRotation()](../reference/apis-arkui/arkts-apis-window-Window.md#convertorientationandrotation23) to convert [display.orientation](../reference/apis-arkui/js-apis-display.md#attributes) to the window [orientation](../reference/apis-arkui/arkts-apis-window-i.md#rotationchangeinfo19).

3. Convert the window orientation to a rotation policy. The window orientation must be further converted to the window [orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9), which represents the rotation policy recognized by the system, before it can be passed to **setPreferredOrientation()**.

4. Call [setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1) to set the rotation policy and lock the display orientation.

<!-- @[quick_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/ConvertOrientationAndRotationSample/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { display, window } from '@kit.ArkUI';

@Entry
@Component
struct SpecificSceneSetOrientationIndex {
  mainWindow: window.Window = AppStorage.get('mainWindow_SetOrientation') as window.Window;
  setOrientationByDisplay() {
    try {
      // 1. Obtain the current default Display.
      const disp = display.getDefaultDisplaySync();
      const displayOrientation = disp.orientation; // Current screen orientation (0/1/2/3).

      console.info('Current display orientation = ' + displayOrientation);
      // 2. Convert displayOrientation to windowOrientation.
      let windowOrientation: number =
        this.mainWindow.convertOrientationAndRotation(
          window.RotationInfoType.DISPLAY_ORIENTATION,
          window.RotationInfoType.WINDOW_ORIENTATION,
          displayOrientation
        );
      // 3. Map windowOrientation to window.Orientation.
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
      // 4. Set the rotation policy to lock the window orientation.
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