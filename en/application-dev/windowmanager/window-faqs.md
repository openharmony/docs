# Window Development FAQs

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @JUGaaab-->
<!--Designer: @ki_ja-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=e5f4a12518daa36e56bebaf91a68665e9bbab092 translatedAt=2026-08-11T10:12:17.065Z pushedAt=2026-08-11T11:30:31.757Z -->

## How to Launch Application B During the Startup of Application A

**Solution**

Application A can call the [on('windowStageEvent')](../reference/apis-arkui/arkts-apis-window-WindowStage.md#onwindowstageevent9) API to listen for the [WindowStageEvent.ACTIVE](../reference/apis-arkui/arkts-apis-window-e.md#windowstageeventtype9) event and then call the [startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability) API to launch application B.

**Code Example**

```ts
// applicationA EntryAbility.ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want, StartOptions } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage): void {
        let want: Want = {
            deviceId: '',
            bundleName: 'com.example.applicationB',
            abilityName: 'EntryAbility'
        };

        let options: StartOptions = {
            displayId: 0
        };

        windowStage.on('windowStageEvent', (data) => {
            let eventType: window.WindowStageEventType = data;
            // Listen for application A switching to the ACTIVE state.
            if (eventType === window.WindowStageEventType.ACTIVE) {
                try {
                    // Launch application B.
                    this.context.startAbility(want, options, (err: BusinessError) => {
                        if (err.code) {
                            // Handle service logic errors.
                            console.error(`Failed to start ability, code is ${err.code}, message is ${err.message}.`);
                            return;
                        }
                        // Carry out normal service processing.
                        console.info('Succeeded in starting Ability.');
                    });
                } catch (err) {
                    // Handle input parameter errors.
                    let code = (err as BusinessError).code;
                    let message = (err as BusinessError).message;
                    console.error(`Failed to start ability, code is ${code}, message is ${message}.`);
                }
            }
        });
    }
}
```

## How to Dynamically Obtain the Window Width and Height

In application development, dynamically obtaining the window width and height is mainly used to implement responsive layout to adapt to devices of different sizes or window status changes (such as split-screen, maximization, restoration, and drag resizing).

You are advised to use [getMainWindowSync()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#getmainwindowsync9), [getMainWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#getmainwindow9-1), or [getSubWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#getsubwindow9-1) to obtain the window instance (**windowClass**), and then call the [getWindowProperties()](../reference/apis-arkui//arkts-apis-window-Window.md#getwindowproperties9) API through the instance to obtain the **WindowProperties** attribute. You can obtain the window width and height based on the attribute. The sample code is as follows:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // Obtain the main window of the application.
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      let properties = windowClass.getWindowProperties();
      let rect = properties.windowRect;
      let windowWidth = rect.width;  // Window width, in px.
      let windowHeight = rect.height; // Window height, in px.
      console.info(`Window Size: ${windowWidth} x ${windowHeight}`);
    } catch (exception) {
      console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(exception));
    }
  }
}
```

## How to Obtain the Soft Keyboard Height

The fixed soft keyboard is a specific type of avoid area, which corresponds to the **TYPE_KEYBOARD** type in [AvoidAreaType](../reference/apis-arkui/arkts-apis-window-e.md#avoidareatype7). You can use [getWindowAvoidArea()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowavoidarea9) and [on('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onavoidareachange9) to dynamically listen for changes in the soft keyboard avoid area height.

You can also use the [on('keyboardHeightChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onkeyboardheightchange7) API to listen for changes in the soft keyboard height. Unlike the avoid area, the callback of this API returns only the height (number) of the soft keyboard, while the [on('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onavoidareachange9) callback returns the entire soft keyboard area ([Rect](../reference/apis-arkui/arkts-apis-window-i.md#rect7)).

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    // Obtain the main window.
    let windowClass: window.Window = windowStage.getMainWindowSync();
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      // Obtain the height of the soft keyboard avoid area.
      let keyboardHeight = windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_KEYBOARD).bottomRect.height;
      // Dynamically listen for changes in the soft keyboard avoid area height.
      windowClass.on('avoidAreaChange', (data) => {
        if (data.type == window.AvoidAreaType.TYPE_KEYBOARD) {
          keyboardHeight = data.area.bottomRect.height;
        }
      });
    } catch (exception) {
      console.error(`Failed to enable the listener for system avoid area changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## How to Obtain the Height of the PC's Default System Title Bar

Call [getWindowDecorHeight()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowdecorheight11) to obtain the height of the title bar.

The example code is as follows:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    // Obtain the main window.
    let windowClass: window.Window = windowStage.getMainWindowSync();
    if (!windowClass) {
      console.info('windowClass is null');
    }
    windowClass.setUIContent('pages/WindowPage').then(() => {
      try {
        let height = windowClass?.getWindowDecorHeight();
        console.info(`Succeeded in getting the height of window decor: ${height}`);
      } catch (exception) {
        console.error(`Failed to get the height of window decor. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    })
  }
}
```

## How to Implement or Determine Immersive Window Layout

[Immersive layout](immersive-window-feature.md#immersive-layout) is a state that allows the app's layout area to extend to the entire window display area.

For a non-[freeform window](window-terminology.md#freeform-window), immersive layout can be set by calling [setWindowLayoutFullScreen()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowlayoutfullscreen9). For a freeform window, the visibility of the window title bar can be controlled through the [setWindowDecorVisible()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowdecorvisible11) API. When the title bar is hidden, the window is in immersive layout.

You can use [isImmersiveLayout()](../reference/apis-arkui/arkts-apis-window-Window.md#isimmersivelayout20) to check whether the window is in immersive layout.

The example code is as follows:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    // Obtain the main window.
    let windowClass: window.Window = windowStage.getMainWindowSync(); 
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      // Set the immersive layout.
      let promise = windowClass.setWindowLayoutFullScreen(true); 
      // Check whether the current window is in immersive layout.
      let isImmersiveLayout = windowClass.isImmersiveLayout();
      console.info(`isImmersiveLayout: ${isImmersiveLayout}`);
    } catch (exception) {
      console.error('Failed to obtain isImmersiveLayout. Cause: ' + JSON.stringify(exception));
    }
  }
}
```

## How to Hide the Status Bar and Bottom Navigation Area

Call [setSpecificSystemBarEnabled()](../reference/apis-arkui/arkts-apis-window-Window.md#setspecificsystembarenabled11) to hide the status bar and bottom navigation bar.

The example code is as follows:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    // Obtain the main window.
    let windowClass: window.Window = windowStage.getMainWindowSync();
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      // Hide the status bar.
      windowClass.setSpecificSystemBarEnabled('status', false);
      // Hide the bottom navigation area.
      windowClass.setSpecificSystemBarEnabled('navigationIndicator', false);
    } catch (exception) {
      console.error('Failed to set status bar or navigation indicator bar invisible. Cause: ' + JSON.stringify(exception));
    }
  }
}
```

## How to Obtain the Status Bar Height

The status bar is a specific avoid area type, which corresponds to the system bar (TYPE_SYSTEM) in [AvoidAreaType](../reference/apis-arkui/arkts-apis-window-e.md#avoidareatype7).

When the main window is displayed in full screen, you can obtain the [avoid area](../reference/apis-arkui/arkts-apis-window-i.md#avoidarea7) that includes a status bar through [getWindowAvoidArea()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowavoidarea9) to indirectly obtain the height of the status bar.

The example code is as follows:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // Obtain the main window of the application.
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      // Obtain the height of the status bar avoid area.
      let statusBarHeight = windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM).topRect.height;
    } catch (exception) {
      console.error(`Failed to get window avoid area. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## How to Set the Window Background to Transparent

To make the window background transparent, call [setWindowBackgroundColor](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbackgroundcolor9) and pass **'\#00XXXXXX'** (where *X* represents any hexadecimal digit) or a transparent [ColorMetrics](../reference/apis-arkui/js-apis-arkui-graphics.md#colormetrics12) value.

> **NOTE**
> 
> - On devices that support [freeform windows](window-terminology.md#freeform-window), a window container is available. Its background color covers the entire window, including both the title bar and the content area. Calling [setWindowBackgroundColor](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbackgroundcolor9) only sets the background color of the app content area, through which the window container background color is visible.
> 
> - On PC/2-in-1 and tablet devices, you can call [setWindowContainerColor()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowcontainercolor20) to make the container transparent. On other devices, setting the container background color is not supported.

The example code is as follows:

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics } from '@kit.ArkUI';
import { window } from '@kit.ArkUI';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent("pages/page2", storage, (err: BusinessError) => {
  let errCode: number = err.code;
  if (errCode) {
  console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
  return;
  }
  console.info('Succeeded in loading the content.');
  // Use the ARGB mode.
  let color1: string = '#0000FF33'; 
  // Use the ColorMetrics mode.
  let color2: ColorMetrics = ColorMetrics.numeric(0x00112233);  
  try {
    windowClass?.setWindowBackgroundColor(color1);
    windowClass?.setWindowBackgroundColor(color2);
  } catch (exception) {
    console.error(`Failed to set the background color. Cause code: ${exception.code}, message: ${exception.message}`);
  };
});
```

## How to Implement Landscape/Portrait Switching

Obtain the main window instance and call the [setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1) API to set the window orientation. For details, see [Window Rotation](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/window-rotation).

The example code is as follows:

```ts
import { BusinessError } from '@kit.BasicServicesKit'
import { common } from '@kit.AbilityKit'
import { window } from '@kit.ArkUI'

@Entry
@Component
struct OrientationTestView {
  private orientation: number =  1;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  private windowClass = (this.context as common.UIAbilityContext).windowStage.getMainWindowSync();
  setOrientation(orientation: number) {
    this.windowClass.setPreferredOrientation(orientation).then(() => {
      console.info('setWindowOrientation: ' + orientation + ' Succeeded.');
    }).catch((err: BusinessError) => {
      console.error('setWindowOrientation: ' + orientation + ' Failed. Cause: ' + JSON.stringify(err));
    })
  }
  build() {
    Column() {
      Button('changeOrientation')
        .onClick(() => {
          this.setOrientation(this.orientation++ % 4 + 1)
        })
    }
    .height('100%')
    .width('100%')
    .margin({'top' : 100})
  }
}
```

For more information, see:

- [Best Practice: Display Orientation Switching](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-landscape-and-portrait-development)

- [Orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9)

## How to Keep the Screen in Landscape/Portrait Mode Without Rotating with the Sensors

Set the application's rotation policy to LANDSCAPE via the [setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1) API to keep the application in landscape mode; set it to **PORTRAIT** to keep it in portrait mode; set it to **LOCKED** to lock the current application orientation without rotating with the screen (using LOCKED is not recommended as it may cause unexpected orientation changes).

To disable rotation for a single page (Navigation), you can set the [preferredOrientation](../reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#preferredorientation19) attribute of the component. If the attribute is set to a specific orientation such as landscape, portrait, reverse landscape, or reverse portrait, the page cannot be rotated to other directions.

## How to Obtain the Screen Orientation

Call [display.getDefaultDisplaySync()](../reference/apis-arkui/js-apis-display.md#displaygetdefaultdisplaysync9) to obtain the default display instance.

Then, obtain the [Orientation](../reference/apis-arkui/js-apis-display.md#orientation10) attribute of the instance to determine the screen orientation of the device.

The following table lists the values of the **Orientation** attribute.

| Name| Value| Description|
| -------- | -------- | -------- |
| PORTRAIT | 0 | The screen is in portrait mode.|
| LANDSCAPE | 1 | The screen is in landscape mode.|
| PORTRAIT_INVERTED | 2 | The screen is in reverse portrait mode.|
| LANDSCAPE_INVERTED | 3 | The screen is in reverse landscape mode.|

> **NOTE**
> 
> If you set the rotation policy to **LANDSCAPE** through the [setPreferredOrientation](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1) API, the [Orientation](../reference/apis-arkui/js-apis-display.md#orientation10) attribute obtained in the preceding steps is **LANDSCAPE_INVERTED**. This is because the window direction is different from the screen direction. You can also use [convertOrientationAndRotation()](../reference/apis-arkui/arkts-apis-window-Window.md#convertorientationandrotation23) to obtain the rotation result.

The example code is as follows:

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  let orientation = displayClass.Orientation;
} catch (exception) {
  console.error(`Failed to get default display. Code: ${exception.code}, message: ${exception.message}`);
}
```

## How to Set the Default Aspect Ratio of an Application in Landscape Mode

You are advised to use [setContentAspectRatio()](../reference/apis-arkui/arkts-apis-window-Window.md#setcontentaspectratio21) to set the aspect ratio of the window content layout.

> **NOTE**
> 
> - When you adjust the window width and height using the same **ratio** parameter, the window dimensions will adjust according to changes in the border decoration size or visibility.
> 
> - When the window title bar is set to invisible by using [setWindowDecorVisible](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowdecorvisible11), the window content area will occupy the height space originally taken by the title bar.
> 
> - When the window size is set by using other APIs such as [resize](../reference/apis-arkui/arkts-apis-window-Window.md#resize9-1) and [resizeAsync](../reference/apis-arkui/arkts-apis-window-Window.md#resizeasync12), the window size is not restricted by the ratio.
> 
> - This setting is available only for the main window and takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode).
> 
> - For versions earlier than API version 21, use [setAspectRatio()](../reference/apis-arkui/arkts-apis-window-Window.md#setaspectratio10) to set the window content layout.

The sample code snippet is as follows:

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      let windowClass = windowStage.getMainWindowSync();
      let ratio = 1.0;
      let promise = windowClass.setContentAspectRatio(ratio, true, true);
      promise.then(() => {
        console.info('Succeeded in setting aspect ratio of window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## How to Set the Display Modes Supported by a Window

During application development, it is recommended that the **supportWindowMode** field in the [abilities](../quick-start/module-configuration-file.md#abilities) tag within the [module.json5](../quick-start/module-configuration-file.md) configuration file be used to set the display mode supported by the window.

The options are as follows:

| Value| Description|
| -------- | -------- |
| "fullscreen" | Full screen.|
| "split" | Split screen.|
| "floating" | Floating window mode. |

> **NOTE**
> 
> - The **supportWindowMode** field is of the string array type and can be left unspecified. The default value is **["fullscreen", "split", "floating"]**.
> 
> - When both **fullscreen** and **split** are configured in the [freeform window](window-terminology.md#freeform-window) state, if the app's [targetAPIVersion](../quick-start/app-configuration-file.md#tags-in-the-configuration-file) is earlier than 15, the window starts in floating window mode. If the app's [targetAPIVersion](../quick-start/app-configuration-file.md#tags-in-the-configuration-file) is 15 or later, the window starts in fullscreen mode.

The following is a configuration example of the module.json5 file:

```json5
{
  "module": {
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ets",
        "description": "$string:EntryAbility_desc",
        "displayName": "$string:EntryAbility_displayName",
        "windowSize": {
          "minWidth": 320,
          "minHeight": 240
        },
        // Control the window modes supported.
        "supportWindowMode": ["fullscreen", "split", "floating"],
        "launchType": "standard",
        "excludeFromMissions": false
      }
    ]
  }
}
```

In addition to the preceding configuration methods, you can also configure the window modes supported by the application in the following ways:

- Use the [metadata](window-config-m.md) tag, with the name **'ohos.ability.window.supportWindowModeInFreeMultiWindow'**. This field takes effect only in free windows mode.

- When starting **UIAbility**, use the **supportWindowModes** field in [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions) to specify whether to display the maximum, windowed, or split-screen button.

- After startup, call the [setSupportedWindowModes()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#setsupportedwindowmodes15) API to dynamically change the window mode supported by the current main window.

> **NOTE**
> 
> Supported window modes in free windows mode can be configured using multiple methods. The configuration priority is:
>
> Configuration via the [setSupportedWindowModes](../reference/apis-arkui/arkts-apis-window-WindowStage.md#setsupportedwindowmodes15) API &gt; Configuration via the **SupportWindowMode** in [StartOption](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions) using **StartAbility** &gt; Configuration using metadata &gt; Configuration via the **SupportWindowMode** property under the [abilities](../quick-start/module-configuration-file.md#abilities) tag in **module.json5**

## How to Determine If the Current Window is in Floating Window Mode

In application development, there are two ways to determine whether an application is in floating window mode.

- Call [getWindowStatus()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowstatus12) to query the current window mode. If the value of **WindowStatusType** is **FLOATING**, the application is in floating window mode.

  The following table lists the return values and their meanings.

  | Name| Value| Description|
  | -------- | -------- | -------- |
  | UNDEFINED | 0 | The window mode is not defined.|
  | FULL_SCREEN | 1 | The window is in full screen mode. In the [freeform window](window-terminology.md#freeform-window) state, the window fills the entire screen, with no dock bar, title bar, or status bar displayed by default.<br>The display of the title bar and dock bar when hovering over the hot zone can be configured through [maximize()](../reference/apis-arkui/arkts-apis-window-Window.md#maximize12) and [setTitleAndDockHoverShown()](../reference/apis-arkui/arkts-apis-window-Window.md#settitleanddockhovershown14).<br>When both **maximize()** and **setTitleAndDockHoverShown()** are called, the effect set by the last call takes precedence.<br>In the non-[freeform window](window-terminology.md#freeform-window) state, the window fills the entire screen, with no title bar or dock bar displayed. Whether the status bar is displayed can be configured through [setSpecificSystemBarEnabled()](../reference/apis-arkui/arkts-apis-window-Window.md#setspecificsystembarenabled11). |
  | MAXIMIZE | 2 | The window is in maximized mode. On PC/2-in-1 devices, the window fills the entire screen, with the dock bar and status bar displayed. |
  | MINIMIZE | 3 | The application window is minimized.|
  | FLOATING | 4 | The application is displayed in a floating window.|
  | SPLIT_SCREEN | 5 | The application is displayed in split-screen mode.|

- Call the [on('windowStatusChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatuschange11) API to listen for window mode changes.

If an app needs to respond immediately when the window mode changes (for example, from fullscreen to floating window mode), this API can be used to listen for window mode changes and implement corresponding business adaptations.

  ```ts
  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  
  export default class EntryAbility extends UIAbility {
    // ...
    onWindowStageCreate(windowStage: window.WindowStage) {
      console.info('onWindowStageCreate');
      let windowClass: window.Window = windowStage.getMainWindowSync(); // Obtain the main window of the application.
      if (!windowClass) {
        console.info('windowClass is null');
      }
      try {
        // Register a listener for window status changes.
        windowClass.on('windowStatusChange', (windowStatusType: window.WindowStatusType) => {
          console.info(`status change, new status: ${windowStatusType}`);
        });
      } catch (error) {
        console.error(`status listen err: ${JSON.stringify(error)}`);
      }
      // Remember to unregister the listener at an appropriate time, for example, when the component is destroyed.
      // windowClass.off('windowStatusChange');
    }
  }
  ```

- Call the [on('windowStatusDidChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatusdidchange20) API to listen for window mode changes.

  After enabling the listener for window mode changes using this API, a notification is sent when the window's **windowStatus** changes (at which point the window's [Rect](../reference/apis-arkui/arkts-apis-window-i.md#rect7) property has already been updated).

  ```ts
  import { window } from '@kit.ArkUI';
  
  try {
    // Obtain the Window instance.
    windowClass.on('windowStatusDidChange', (WindowStatusType) => {
      console.info(`Succeeded in enabling the listener for window status changes. Data: ${JSON.stringify(WindowStatusType)}`);
    });
  } catch (exception) {
    console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
  }
  ```

> **NOTE**
> 
> Both [on('windowStatusChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatuschange11) and [on('windowStatusDidChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatusdidchange20) are called when the window status changes. [on('windowStatusChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatuschange11) does not ensure that the window attributes are updated when the callback is called. If your application needs to obtain the new window size and position immediately after receiving the window status change notification, you are advised to use [on('windowStatusDidChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowstatusdidchange20).

## How to Set the Global Floating Window Background to Transparent

To make the window background transparent, call [setWindowBackgroundColor](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbackgroundcolor9) and pass **'\#00XXXXXX'** (where X represents any hexadecimal digit) or a transparent [ColorMetrics](../reference/apis-arkui/js-apis-arkui-graphics.md#colormetrics12) value.

## How to Determine Whether an Application is Partially or Fully Obscured

Currently, there are two APIs for determining whether the current window is obscured:

- [on('windowVisibilityChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowvisibilitychange11): Listens for window visibility. If the callback returns **false**, the current window is completely obscured. If the callback returns **true**, the current window is visible, but it cannot be determined whether the window is partially or fully obscured.

- [on('occlusionStateChanged')](../reference/apis-arkui/arkts-apis-window-Window.md#onocclusionstatechanged22): Listens for window visibility. There are three visibility states: **0** (visible), **1** (partially visible), and **2** (invisible).

## How to Determine Whether the Free Windows Mode Is Enabled

Call the [isInFreeWindowMode()](../reference/apis-arkui/arkts-apis-window-Window.md#isinfreewindowmode22) API to check whether the freeform window mode is enabled. If the return value is **true**, the current window is in the freeform window mode. If the return value is **false**, the current window is not in the freeform window mode.

Call the [on('freeWindowModeChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onfreewindowmodechange22) API to listen for freeform window mode changes.

## How to Set a Privacy Window

The [setWindowPrivacyMode](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1) API can be called to set a window to privacy mode. When a window is in privacy mode, its content cannot be captured through screenshots or screen recording.

For the PiP and floating ball windows, their privacy mode follows the parent window.

To take a screenshot of a privacy window, you can use the [snapshotIgnorePrivacy()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshotignoreprivacy18) API.

## How to Implement a Blur Effect When the App Goes to the Background and Appears in the Multitasking Window

Your app can listen to the main window lifecycle state and store the state using [AppStorage](../ui/state-management/arkts-appstorage.md). When the state is the foreground non-interactive state or the background state, set the [foregroundBlurStyle](../reference/apis-arkui/arkui-ts/ts-universal-attributes-foreground-blur-style.md#foregroundblurstyle) attribute for the component.

The example code is as follows:

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });
    AppStorage.setOrCreate('windowStage', windowStage);
    windowStage.on('windowStageEvent', (data) => {
      console.info('Succeeded in enabling the listener for window stage event changes. Data : ' +
        JSON.stringify(data));
      // Perform corresponding processing based on the event state type.
      if (data == window.WindowStageEventType.SHOWN) {
        console.info('current window stage event is SHOWN');
        AppStorage.setOrCreate('interact', true);
        // When the app enters the foreground, it is in the interactive state by default.
        // ...
      } else if (data == window.WindowStageEventType.HIDDEN) {
        console.info('current window stage event is HIDDEN');
        AppStorage.setOrCreate('interact', false);
        // When the app enters the background, it is in the non-interactive state by default.
        // ...
      } else if (data == window.WindowStageEventType.PAUSED) {
        console.info('current window stage event is PAUSED');
        AppStorage.setOrCreate('interact', false);
        // When the foreground app enters the multitasking view and becomes non-interactive in the foreground, switch to the non-interactive state.
        // ...
      } else if (data == window.WindowStageEventType.RESUMED) {
        console.info('current window stage event is RESUMED');
        AppStorage.setOrCreate('interact', true);
        // When the app returns to the foreground from the multitasking view and becomes interactive again, restore the interactive state.
        // ...
      }
    });
  }
}
```

```ts
// ets/pages/Index.ets
@Entry
@Component
struct Index {
  @StorageLink('interact') interact: boolean = true;
  build() {
    Column() {
      Text('Text('Text Text')')
        .fontSize(60)
    }
    .foregroundBlurStyle(this.interact ? BlurStyle.NONE : BlurStyle.COMPONENT_ULTRA_THICK) // The blur level can be customized.
  }
}
```

## What Are the Position/Size Restrictions for APIs Such as resize and moveWindowTo

When calling the [resize()](../reference/apis-arkui/arkts-apis-window-Window.md#resize9-1) API to adjust the window size, the window size range is constrained by [WindowLimits](../reference/apis-arkui/arkts-apis-window-i.md#windowlimits11). The specific size limit range can be queried via the [getWindowLimits](https://developer.huawei.com/consumer/en/doc/harmonyos-references/arkts-apis-window-window#getwindowlimits11) API.

There is no restriction on the window position when [moveWindowTo()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowto9-1) is called to adjust the window position.

> **NOTE**
> 
> **Other restrictions on the resize API:**
> 
> - In the [freeform window](window-terminology.md#freeform-window) state, the API takes effect only when the window is in floating window mode (that is, the window mode is **window.WindowStatusType.FLOATING**, which can be obtained through [getWindowStatus()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowstatus12)). Otherwise, error code 1300002 is thrown.
> 
> - In the non-[freeform window](window-terminology.md#freeform-window) state, the API does not take effect for the main window.
> 
> **Other restrictions on the moveWindowTo API:**
> 
> - It is not recommended to use this API in window modes other than floating window mode (that is, the window mode is **window.WindowStatusType.FLOATING**, which can be obtained through [getWindowStatus()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowstatus12)).
> 
> - In the [freeform window](window-terminology.md#freeform-window) state, the window moves relative to the screen. In the non-freeform window state, the window moves relative to the parent window.
> 
> - To move the window relative to the screen in the non-freeform window state, use [moveWindowToGlobal()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoglobal15).
> 
> - In the non-[freeform window](window-terminology.md#freeform-window) state, the API does not take effect for the main window.

## How to Set or Remove Watermarks

<!--Del-->

Watermarks are classified into the following types by scope:

- Window-level watermark: You can call [setWaterMarkFlag()](../reference/apis-arkui/js-apis-window-sys.md#setwatermarkflag10) to add or remove a security watermark for the current window.

<!--DelEnd-->

- Process-level watermark: You can call [setWatermarkImageForAppWindows()](../reference/apis-arkui/arkts-apis-window-f.md#windowsetwatermarkimageforappwindows21) to set or cancel a process-level watermark, which takes effect for the windows of the current process, including the windows newly created by the process.

<!--Del-->

- Screen-level watermark: [window.setWaterMarkImage](../reference/apis-arkui/js-apis-window-sys.md#windowsetwatermarkimage10) can be called to set or remove a screen-level watermark.

<!--DelEnd-->

## How to Move a Created Window to an Extended Screen

- An application can call [moveWindowToGlobal()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoglobal15) to move the current window to an extended screen. You can specify the target extended screen by setting the API parameter [MoveConfiguration](../reference/apis-arkui/arkts-apis-window-i.md#moveconfiguration15).

- An application can also call [startMoving()](../reference/apis-arkui/arkts-apis-window-Window.md#startmoving14) to move the current window to the target screen using mouse or touch point dragging. The window moves along with the cursor or touch point only when this API is called in the callback of the [onTouch](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch) event (event type is **TouchType.Down**).

## How to Achieve a Semi-Transparent Background for a Child Window

For a child window, call [setWindowBackgroundColor](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbackgroundcolor9) and pass **'\#XXYYYYYY'** (where XX represents any non-zero hexadecimal value and Y represents any hexadecimal digit) or a semi-transparent [ColorMetrics](../reference/apis-arkui/js-apis-arkui-graphics.md#colormetrics12) value.

The example code is as follows:

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics } from '@kit.ArkUI';
import { window } from '@kit.ArkUI';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent("pages/page2", storage, (err: BusinessError) => {
  let errCode: number = err.code;
  if (errCode) {
  console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
  return;
  }
  console.info('Succeeded in loading the content.');
  let color1: string = '#8800FF33'; // Use the ARGB format.
  let color2: ColorMetrics = ColorMetrics.numeric(0x88112233);  // Use the ColorMetrics format.
  try {
    windowClass?.setWindowBackgroundColor(color1);
    windowClass?.setWindowBackgroundColor(color2);
  } catch (exception) {
    console.error(`Failed to set the background color. Cause code: ${exception.code}, message: ${exception.message}`);
  };
});
```

## How to Set Page-Level Brightness

Currently, brightness can be set only at the window level.

To achieve page-level brightness adjustment, an app can call [setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1) on the main window to adjust the brightness when entering a specific page, and call [setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1) with **-1** on the main window to restore the system screen brightness when exiting that page.

## How to Restore System Default Brightness

For phones and tablets, the app can call [setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1) with **-1** passed to restore the system default brightness.

For PCs and 2-in-1 devices, the window brightness and system brightness have been normalized. Therefore, after the [setWindowBrightness()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowbrightness9-1) API is called, the system brightness is directly changed. Currently, there is no method to restore the window brightness to the value before the call.

## How to Properly Obtain the Topmost Window

**Symptom**

When [getLastWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetlastwindow9) is called to obtain the topmost window of the app, a child window that is being destroyed is obtained.

**Possible Causes**

When [destroyWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#destroywindow9) is called to destroy a child window, [getLastWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetlastwindow9) is called before the destruction is complete, resulting in obtaining a child window that is being destroyed.

**Solution**

Before calling [getLastWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetlastwindow9) to obtain the topmost window of the app, ensure that operations such as child window destruction and window creation have been completed.

**Sample Code**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let lastWindow: window.Window | undefined = undefined;
// Not recommended approach.
try {
  // Obtain the window instance first.
  windowClass.destroyWindow();
  try {
    window.getLastWindow(this.context).then((topWindow) => {
      lastWindow = topWindow;
    }).catch((err: BusinessError) => {
      console.error(`Failed to obtain the last window. Cause code: ${err.code}, message: ${err.message}`);
    });
  } catch (exception) {
    console.error(`Failed to obtain the last window. Cause code: ${exception.code}, message: ${exception.message}`);
  }
} catch (exception) {
  console.error(`Failed to destroy. Cause code: ${exception.code}, message: ${exception.message}`);
};

// Recommended approach.
try {
  // Obtain the window instance first.
  windowClass.destroyWindow().then(() => {
    try {
      window.getLastWindow(this.context).then((topWindow) => {
        lastWindow = topWindow;
      }).catch((err: BusinessError) => {
        console.error(`Failed to obtain the last window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to obtain the last window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to destroy. Cause code: ${exception.code}, message: ${exception.message}`);
};
```

## Window Type (type Field) Returned by getWindowProperties Does Not Meet Expectations

**Symptom**

Due to historical reasons, when [getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9) is called in the main window scenario, the obtained window type, that is, [WindowType](../reference/apis-arkui/arkts-apis-window-e.md#windowtype7), is **TYPE_SYSTEM_ALERT** instead of **TYPE_MAIN**.

**Solution**

A new field will be provided in a future API version to fix this issue.

When creating a window within an app, the window type must be specified. You can directly perceive the window type and do not need to actively obtain it through this API.

## Avoid Area Data Obtained Through getWindowAvoidArea in Callbacks Such as on('windowSizeChange') Is Not Up-to-Date

**Symptom**

In window property change callbacks such as [on('windowSizeChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowsizechange7) and [on('windowRectChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowrectchange12), the avoid area data obtained through the [getWindowAvoidArea()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowavoidarea9) API is inaccurate.

**Possible Causes**

The update of the avoid area depends on both the update of window position/size properties and the update of the position/size of system UI elements (such as the status bar). When the window property update callback is triggered, the system UI elements may not have been updated yet. Therefore, the accurate avoid area cannot be obtained through the **getWindowAvoidArea()** API at this point.

**Solution**

Use the dedicated avoid area listener [on('avoidAreaChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onavoidareachange9) to listen for avoid area changes, and avoid actively obtaining the avoid area through the **getWindowAvoidArea()** API in other window property change event callbacks.

**Sample Code**

```ts
import { window } from '@kit.ArkUI';

// In the code, windowClass is assumed to be an obtained Window instance.

// Incorrect: Listen for the windowSizeChange event to proactively obtain the avoid area.
windowClass.on('windowSizeChange', () => {
  try {
    const systemAvoidArea = windowClass.getWindowAvoidArea(window.AvoidAreaType.TYPE_SYSTEM);  // The obtained avoid area is inaccurate.
  } catch (exception) {
    console.error(`Failed to get window avoid area. Cause code: ${exception.code}, message: ${exception.message}`);
  }
});

// Correct: Listen for the avoidAreaChange event.
windowClass.on('avoidAreaChange', (data) => {
  if (data.type === window.AvoidAreaType.TYPE_SYSTEM) {
    const systemAvoidArea = data.area;  // The data in the callback always contains the accurate avoid area.
  }
});
```