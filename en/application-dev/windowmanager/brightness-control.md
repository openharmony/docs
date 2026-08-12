# Controlling Brightness and Always-On (ArkTS)

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=58ff40ad92758153f7b55166a9e6e0a0e9be5d28 translatedAt=2026-07-10T07:15:20.416Z pushedAt=2026-07-13T02:01:38.569Z -->

## When to Use

Brightness control is used to adjust the display brightness of an app window or device screen. You can dynamically adjust brightness based on page content characteristics, usage scenarios, and display requirements to improve page readability and content legibility. Brightness mainly includes [window brightness and display brightness](#window-brightness-and-display-brightness).

Always-on control is used to determine whether the screen remains lit for a period of time. It is suitable for scenarios that require continuous content display or long-term interactive visibility, preventing the system's automatic screen-off from affecting business processes.

## Window Brightness and Display Brightness

- **Window brightness**: Refers to the display brightness of the current app window. It only applies to the main window and does not directly modify the device's global brightness.  

   You can adjust the window brightness individually based on the display requirements of the current page to optimize the display effect within the app. The window brightness of the main window can be set by calling the [setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1) API.

  > **NOTE**
  > 
  > When using the [setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1) API to set the window brightness of the main window:
  > 
  > - When the main window is in the foreground and has focus, the window brightness takes effect (that is, the set brightness value becomes the actual display brightness of the current window). It only affects the brightness of the current device screen and cannot modify the screen brightness of virtual screens (such as the screen where the device is being cast).
  > 
  > - When the window moves to the background, the window brightness becomes invalid and can be adjusted through the control center or shortcut keys. It is not recommended to call this API consecutively or when the window has moved to the background, as this may cause timing issues.

- **Display brightness**: Refers to the global display brightness of the device screen. Its scope covers the entire screen and affects the display effect of the system UI and all app windows.  

  Display brightness can be adjusted through the **Control Center** or **Settings &gt; Display & brightness**. There is currently no API for directly setting the system display brightness, but when **-1** is passed to [setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1), the window brightness is restored to the system display brightness.

## Controlling Screen Always-On

Controlling screen always-on refers to calling the [setWindowKeepScreenOn()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowkeepscreenon9-1) API to set whether the device screen remains always-on when the current window is in the foreground. When a window set to always-on exists in the foreground, the device's automatic screen-off timeout capability will be disabled. This does not take effect on heterogenous virtual screens.

It is recommended to use this in scenarios where it is clear and necessary to keep the screen always-on, such as navigation, video playback, drawing, and gaming. In scenarios without screen interaction, pure audio playback, or other situations where the screen does not need to stay on continuously, setting screen always-on is not recommended.

When the window moves to the background, the system automatically releases the always-on lock held by that window. For video playback apps, when the audio or video stream is interrupted for a period of time, such as during pausing or network buffering, the system will also automatically release the always-on lock.

> **NOTE**
> 
> Keeping the screen always-on for extended periods in such scenarios may increase device power consumption and affect battery life. It is recommended to reasonably control the always-on duration based on the service requirements to ensure user experience.

The sample code is as follows:

<!--@[windowBrightness_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/windowBrightness/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript

import { window } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

@Entry
@Component
struct Index {
  @State brightnessValue: number = 0.5;
  @State keepScreenOn: boolean = false;
  @State statusText: string = 'Adjust window brightness or keep-screen-on.';

  private currentWindow?: window.Window = undefined;

  aboutToAppear(): void {
    void this.initWindow();
  }

  // Get the current app window, and then set the window brightness and always‑on state through the Window object.
  private async initWindow(): Promise<void> {
    try {
      const hostContext = this.getUIContext().getHostContext();
      if (!hostContext) {
        throw new Error('Host context is unavailable.');
      }

      const context = hostContext as common.UIAbilityContext;
      this.currentWindow = await window.getLastWindow(context);

      const windowId = this.currentWindow.getWindowProperties().id;
      this.statusText = `window ready, id=${windowId}`;
      hilog.info(DOMAIN, 'windowBrightness', this.statusText);
    } catch (err) {
      this.statusText = `initWindow failed: ${JSON.stringify(err)}`;
      hilog.error(DOMAIN, 'windowBrightness', this.statusText);
    }
  }

  // Ensure the window object is initialized before calling the API.
  private async ensureWindow(): Promise<boolean> {
    if (!this.currentWindow) {
      await this.initWindow();
    }

    if (!this.currentWindow) {
      this.statusText = 'current window is unavailable.';
      return false;
    }

    return true;
  }

  // Set the current window brightness. The value ranges from 0 to 1. Passing -1 restores the system display brightness.
  private async applyBrightness(): Promise<void> {
    if (!await this.ensureWindow()) {
      return;
    }

    try {
      await this.currentWindow!.setWindowBrightness(this.brightnessValue);
      this.statusText = `setWindowBrightness(${this.brightnessValue.toFixed(2)}) success`;
      hilog.info(DOMAIN, 'windowBrightness', this.statusText);
    } catch (err) {
      this.statusText = `setWindowBrightness failed: ${JSON.stringify(err)}`;
      hilog.error(DOMAIN, 'windowBrightness', this.statusText);
    }
  }

  // Set whether to keep the screen on when the current window is in the foreground.
  private async applyKeepScreenOn(value: boolean): Promise<void> {
    if (!await this.ensureWindow()) {
      return;
    }

    try {
      this.keepScreenOn = value;
      await this.currentWindow!.setWindowKeepScreenOn(value);
      this.statusText = `setWindowKeepScreenOn(${value}) success`;
      hilog.info(DOMAIN, 'windowBrightness', this.statusText);
    } catch (err) {
      this.statusText = `setWindowKeepScreenOn failed: ${JSON.stringify(err)}`;
      hilog.error(DOMAIN, 'windowBrightness', this.statusText);
    }
  }

  build() {
    Column({ space: 16 }) {
      Text('Brightness and Keep Screen On')
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
        .width('100%')
        .textAlign(TextAlign.Start)

      Text(`Brightness: ${this.brightnessValue.toFixed(2)}`)
        .width('100%')
        .fontSize(16)
        .textAlign(TextAlign.Start)

      Slider({
        value: this.brightnessValue,
        min: 0,
        max: 1,
        step: 0.01
      })
        .width('100%')
        .showTips(true)
        .onChange((value: number) => {
          this.brightnessValue = value;
        })

      Button('Apply Brightness')
        .width('100%')
        .onClick(() => {
          void this.applyBrightness();
        })

      Row() {
        Text(`Keep screen on: ${this.keepScreenOn}`)
          .layoutWeight(1)
          .fontSize(16)

        Toggle({ type: ToggleType.Switch, isOn: this.keepScreenOn })
          .onChange((value: boolean) => {
            void this.applyKeepScreenOn(value);
          })
      }
      .width('100%')

      Text(this.statusText)
        .width('100%')
        .fontSize(14)
        .textAlign(TextAlign.Start)
    }
    .width('100%')
    .height('100%')
    .padding(20)
    .alignItems(HorizontalAlign.Start)
  }
}
```