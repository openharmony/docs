# App Startup Settings

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @ccllee1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=19050225e664e6cdf992c6f93572590dc5afb573 translatedAt=2026-08-18T01:33:07.699Z pushedAt=2026-08-18T11:10:23.662Z -->

In app development, starting an app (usually starting a UIAbility component) is a common task for developers. For example, you may need to jump from a shopping app to a payment app to make a payment, start a video app from a chat app to play a video, or specify a particular window mode when jumping between apps.

## Relationship Between Apps, Processes, and UIAbility Components

An app can run in one or more processes, and a process can run one or more [UIAbility](./uiability-overview.md) component instances. An app developed by a third-party developer must contain at least one [UIAbility](./uiability-overview.md) component; otherwise, there is no UI to display to users.

For users, only the [UIAbility](./uiability-overview.md) component is visible. Starting the first UIAbility component in an app means starting the app. In the following sections, starting an app refers to starting a UIAbility.

Through [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md), developers can flexibly control the startup behavior when starting a UIAbility, including the window mode, window position, startup animation, startup page style, and window size limits, to meet the requirements of different device forms and user scenarios.

## Starting an App in a Specified Window Mode

In some scenarios, developers need to specify that a UIAbility starts in a particular window mode. For example:

- On a tablet, the product details window starts in split-screen mode to make full use of the large screen.

- On a PC/2-in-1 device, opening a document starts it in full-screen mode to provide an immersive experience.

- In a video app, when opening the video playback UIAbility, you may want it to be displayed as a floating window so that users can view the introduction and the playback interface at the same time.

**The development steps are as follows:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object to specify the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure the windowMode of StartOptions to specify the window mode. For details about windowMode, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md). If windowMode is not specified, the UIAbility starts in the system default window display form.

4. Call the startAbility API to start the target UIAbility.

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
        Button("Start in split-screen mode")
          .onClick(() => {
            // context is the UIAbilityContext of the caller UIAbility.
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId being empty indicates the local device.
              bundleName: 'com.example.startoptions',
              abilityName: 'StartWithSpecifiedWindowModeAbility',
              parameters: {
                // Custom information.
                info: 'Start from StartWithSpecifiedWindowModeAbility'
              }
            };

            let options: StartOptions = {
              windowMode: AbilityConstant.WindowMode.WINDOW_MODE_SPLIT_SECONDARY // Start in split-screen mode.
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

## Setting the Window Display Mode

In some scenarios, developers need to specify which window modes are displayed in the title bar of a UIAbility window. For example:

- Whether the window supports full-screen mode.

- Whether the window supports floating window mode.

- Whether the window supports split-screen mode.

**The development steps are as follows:**

1. Before starting the UIAbility, import the required modules.

2. Create a Want object and specify the information about the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure supportWindowModes of StartOptions to set the window display mode. For details about supportWindowModes, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md).

4. Call the startAbility interface to start the target UIAbility.

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
        Button("Set the window display mode")
          .onClick(() => {
            // context is the UIAbilityContext of the caller UIAbility
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // An empty deviceId indicates the local device
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // Custom information
                info: 'Start from EntryAbility'
              }
            };

            let options: StartOptions = {
              supportWindowModes: [
                bundleManager.SupportWindowMode.FULL_SCREEN,  // Support full-screen mode.
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

## Setting the Window Split Ratio

In certain scenarios, developers need to specify the window ratio allocation of a UIAbility in split-screen mode. For example, set different split ratios based on the importance of the app content.

**The development steps are as follows:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object and specify the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Starting from API version 26.0.0, you can set the window allocation ratio through the splitRatio field of StartOptions. For details about splitRatio, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md) and [SplitRatioPreference](../reference/apis-arkui/arkts-apis-window-e.md#splitratiopreference).

4. Call the startAbility interface to start the target UIAbility.

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
        Button("Start in split-screen mode by ratio")
          .onClick(() => {
            // context is the UIAbilityContext of the caller UIAbility
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // deviceId being empty indicates the local device
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // Custom information
                info: 'Start from EntryAbility'
              }
            };

            let options: StartOptions = {
              windowMode: AbilityConstant.WindowMode.WINDOW_MODE_SPLIT_SECONDARY, // Start in split-screen mode
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

## Starting an App on a Specified Display

On multi-screen devices (such as a tablet connected to an external display, a 2-in-1 device, and so on), developers may need to start a UIAbility on a specific screen. For example:

- On a tablet, start the video playback feature on an external display.

- On a 2-in-1 device, start the auxiliary feature on the secondary screen.

**The development steps are as follows:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object and specify the UIAbility information to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure the displayId of StartOptions to specify the screen to display. For details about displayId, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md).

4. Call the startAbility interface to start the target UIAbility.

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
        Button("Start on the current screen")
          .onClick(() => {
            // context is the UIAbilityContext of the caller UIAbility.
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // An empty deviceId indicates the local device.
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // Custom information.
                info: 'Start from EntryAbility.'
              }
            };

            let options: StartOptions = {
              displayId: -1 // Start on the current screen.
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

## Controlling Whether to Display Startup Animation

When you need to switch between UIs quickly, disable the animation to improve the response speed.

**Development steps:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object to specify the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure **withAnimation** in **StartOptions** to control whether there is a startup animation. For details about **withAnimation**, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md).

4. Call the **startAbility** API to start the target UIAbility.

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
        Button("Disable startup animation")
          .onClick(() => {
            // context is the UIAbilityContext of the caller UIAbility.
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // An empty deviceId indicates the local device.
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // Custom information
                info: 'Start from EntryAbility'
              }
            };

            let options: StartOptions = {
              withAnimation: false // Disable the startup animation.
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

## Setting the Window Position When Starting an App

In the [freeform window](../windowmanager/window-terminology.md#freeform-window) state, developers may need to specify the initial position of the UIAbility window. For example:

- In a multi-window scenario, place a new window at a specific position to avoid covering other important content.

- On large-screen devices, set a larger window size for content display apps.

- In a multi-window scenario, set a smaller window size for auxiliary tool apps.

- Place the auxiliary window at the edge of the screen.

**Development steps:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object and specify the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure the windowLeft, windowTop, windowWidth, and windowHeight properties of StartOptions to set the window position and size. For details about the related attributes, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md). You are advised to configure both the windowLeft and windowTop fields.

4. Call the startAbility API to start the target UIAbility.

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
        Button("Set the window position")
          .onClick(() => {
            // context is the UIAbilityContext of the caller UIAbility.
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // An empty deviceId indicates the local device.
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // Custom information.
                info: 'Start from EntryAbility'
              }
            };

            let options: StartOptions = {
              displayId: 0,
              windowLeft: 100,   // 100px from the left edge of the screen
              windowTop: 200,    // 200px from the top edge of the screen
              windowWidth: 800,  // Window width: 800px
              windowHeight: 600  // Window height: 600px
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

## Setting Window Size Limits When Starting an App

In the [freeform window](../windowmanager/window-terminology.md#freeform-window) state, developers may need to limit the size range of the UIAbility window to prevent users from resizing the window too large or too small. For example:

- Set a minimum window size to ensure that the UI content is not displayed improperly because the window is too small.

- Set a maximum window size to prevent the window from being too large on large-screen devices, which would affect the user experience.

**How to develop:**

1. Import the required modules before starting the UIAbility.

2. Create a Want object to specify the information about the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure the minWindowWidth, minWindowHeight, maxWindowWidth, and maxWindowHeight attributes of StartOptions to set the window size limits. For details about the related attributes, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md). You can call [getWindowLimitsVP](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowlimitsvp22) to obtain the size limits of the current window.

4. Call the startAbility interface to start the target UIAbility.

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
        Button("Set the window size of the ability.")
          .onClick(() => {
            // context is the UIAbilityContext of the calling UIAbility.
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;

            let want: Want = {
              deviceId: '', // An empty deviceId indicates the local device.
              bundleName: 'com.example.startoptions',
              abilityName: 'EntryAbility',
              parameters: {
                // Custom information.
                info: 'Start from EntryAbility.'
              }
            };

            let options: StartOptions = {
              startWindowBackgroundColor: '#E510FFFF', // ARGB format.
              minWindowWidth: 320,   // Minimum width 320vp
              maxWindowWidth: 2560,  // Maximum width 2560vp
              minWindowHeight: 240,  // Minimum height 240vp
              maxWindowHeight: 2560  // Maximum height 2560vp
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

## Hiding UIAbility at Startup

In some scenarios, developers need to start a UIAbility without immediately displaying it in the foreground. For example, start a UIAbility for background monitoring and display it only after a condition is triggered.

**Development steps:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object to specify the UIAbility to start. For the acquisition method of UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure processMode and startupVisibility in StartOptions to set the process mode and visibility. For details about the related attributes, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md).

4. Call the startAbility API to start the target UIAbility.

> **NOTE**
>
> When the target UIAbility is set to be invisible:
> - The window of the target UIAbility is not displayed in the foreground.
> - No icon is displayed in the Dock bar.
> - The onForeground lifecycle of the target UIAbility is not invoked.

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
      deviceId: '', // deviceId is empty, indicating the local device.
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // Custom information.
        info: 'Start from EntryAbility'
      }
    };

    let options: StartOptions = {
      processMode: contextConstant.ProcessMode.NEW_PROCESS_ATTACH_TO_PARENT,
      startupVisibility: contextConstant.StartupVisibility.STARTUP_HIDE
    };

    try {
      this.context.startAbility(want, options, (err: BusinessError) => {
        if (err.code) {
          // Handle the service logic error.
          console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        // Execute the normal service.
        console.info('startAbility succeed');
      });
    } catch (err) {
      // Handle the input parameter error exception.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startAbility failed, code is ${code}, message is ${message}`);
    }

  }

  // ...
}
```

## Setting the Startup Page Icon and Background Color

Developers may want to customize the startup page icon and background color displayed when a UIAbility starts. For example:

- Set a startup background and a dedicated icon that match the theme color for a UIAbility with a specific function, to improve brand recognition.

- Display different startup page styles in different scenarios to enhance the visual experience.

**The development steps are as follows:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object to specify the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure startWindowIcon and startWindowBackgroundColor of StartOptions to set the startup page icon and background color. For details about the related attributes, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md).

4. Call the startAbility interface to start the target UIAbility.

> **NOTE**
> 
> - If startWindowIcon is not configured, the configuration of the startWindowIcon field in the module.json5 file is used by default.
> - If startWindowBackgroundColor is not configured, the configuration of the startWindowBackground field in the module.json5 file is used by default.
> - The background color is in ARGB format, for example, `#E5FFFFFF` (with an alpha value of E5 and an RGB value of FFFFFF).

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
      deviceId: '', // An empty deviceId indicates the local device.
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // Custom information
        info: 'Start from EntryAbility'
      }
    };

    // Create a PixelMap object.
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
      startWindowBackgroundColor: '#E510FFFF', // ARGB format
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

## Obtaining the Startup Result

In some scenarios, developers need to obtain the result of starting a UIAbility for subsequent processing. For example, when logging in with another app's account, you need to know whether the other app was successfully started.

**How to Develop:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object and specify the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure the completionHandler of StartOptions to set the startup result callback. For details about completionHandler, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md).

4. Call the startAbility API to start the target UIAbility.

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
      deviceId: '', // deviceId is empty, indicating the local device.
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // Custom information.
        info: 'Started from EntryAbility.'
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

## Hiding the Startup Page

In some scenarios, developers want to start a UIAbility without displaying the startup page and directly show the app UI. For example:

- When quickly switching functions, avoid the startup page flickering to improve the smoothness of the experience.

- When the app UI loads quickly, no startup page transition is needed.

**The development steps are as follows:**

1. Import the required modules before starting the UIAbility.

2. Create a Want object to specify the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure hideStartWindow in StartOptions to hide the startup page. For details about the attributes, see [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md).

4. Call the startAbility API to start the target UIAbility.

> **NOTE**
>
> For details about the introduction and specifications of the startup page, see [StartWindow](../quick-start/module-configuration-file.md#startwindow).

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
      deviceId: '', // An empty deviceId indicates the local device.
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // Custom information.
        info: 'Started from EntryAbility'
      }
    };

    let options: StartOptions = {
      hideStartWindow: true // Hide the startup page.
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

## Setting Window Parameters

In some advanced scenarios, developers need finer-grained control over the window parameters when a UIAbility is started, for example, window animations.

**Development steps:**

1. Before starting the UIAbility, import the related modules.

2. Create a Want object and specify the information about the UIAbility to start. For details about how to obtain the UIAbilityContext, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

3. Configure windowCreateParams of StartOptions to set the window parameters. For details about the window parameter configuration, see [WindowCreateParams](../reference/apis-arkui/arkts-apis-window-i.md#windowcreateparams20).

4. Call the startAbility API to start the target UIAbility.

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
      deviceId: '', // deviceId being empty indicates the local device.
      bundleName: 'com.example.startoptions',
      abilityName: 'EntryAbility',
      parameters: {
        // Custom information.
        info: 'Start from EntryAbility.'
      }
    };

    // Create a PixelMap object.
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
      startWindowBackgroundColor: '#E510FFFF', // ARGB format.
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
<!--no_check-->