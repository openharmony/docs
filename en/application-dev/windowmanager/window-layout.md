# Window Layout

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @yyuehao-->
<!--Designer: @yyuehao-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=58ff40ad92758153f7b55166a9e6e0a0e9be5d28 translatedAt=2026-07-13T09:33:48.568Z pushedAt=2026-07-14T07:10:30.060Z -->

## When to Use

Window layout refers to the capability of setting and managing the position and size attributes of windows. Through the window layout capability, you can flexibly control the display form of app windows on the screen, achieving diverse UI presentation effects.

Window layout mainly includes the following capabilities:

- [Managing window size or aspect ratio limits](#managing-the-window-size-or-aspect-ratio-limits): By setting the minimum/maximum size constraints and aspect ratio limits of a window, the adjustable range and display ratio of the window can be constrained.

- [Adjusting the window position and size](#adjusting-the-window-position-and-size): Set the position coordinates of a window on the screen and the width and height dimensions of the window, and provide query and listening capabilities for window position and size changes.

Proper use of window layout capabilities helps developers:

- Adapt to different screen sizes and window modes.

- Optimize the responsive layout design of apps.

- Achieve personalized window display effects for apps.

- Provide a better multi-window interaction experience.

## Managing the Window Size or Aspect Ratio Limits

By managing window size constraints or aspect ratio limits, you can restrict the adjustable range and display ratio of a window, preventing an excessively large or small window from affecting the user experience.

### Window Size Constraints

[WindowLimits](../reference/apis-arkui/arkts-apis-window-i.md#windowlimits11) represents the minimum and maximum size constraints of a window, including the minimum window height (**minWindowHeight**), maximum height (**maxWindowHeight**), minimum width (**minWindowWidth**), and maximum width (**maxWindowWidth**). You can use the [getWindowLimits()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowlimits11) and [getWindowLimitsVP()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowlimitsvp22) APIs to query the current size constraints of a window.

The system provides multiple configuration methods for window size constraints. The final effective result of the window size constraints is obtained by taking the intersection of the following configurations, listed in descending order of priority:

| Configuration Method | Priority | Unit | Effective Timing | When to Use |
| -------- | -------- | -------- | -------- | -------- |
| Call [setWindowLimits()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowlimits11) API with the input parameter **windowLimits**<br/>Call [setWindowLimits()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowlimits15) API with the input parameters **windowLimits** and **isForcible** | Highest (setting during runtime) | px or vp<br/>(specified via **pixelUnit**) | Takes effect dynamically after the window is created | When window size constraints need to be dynamically adjusted based on runtime state, such as automatic adaptation based on content or adjustments after user interaction |
| Set via [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions) when calling the [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability-1) API | Medium (set at startup) | vp | Takes effect when the ability starts | When window size constraints need to be specified at startup, such as specifying the window size range when launching another app |
| Configured via the [abilities](../quick-start/module-configuration-file.md#abilities) tag in the [module.json5 configuration file](../quick-start/module-configuration-file.md) | Low (static configuration) | vp | Takes effect after the app is installed | When window size constraints need to be preset, serving as the default configuration for the app<br/>This takes effect for the main window corresponding to the current UIAbility. |
| Default system constraints | Low (system default) | vp | Takes effect after the app is installed | When the app does not need to specify window size constraints and follows the system default constraints (the system default constraints vary based on different products and window types). |

### Window Content Aspect Ratio Limit

The window aspect ratio limit applies to the following typical scenarios:

- Video playback apps need to maintain a fixed display ratio such as 16:9 or 4:3.

- Image browsing apps need to maintain the original aspect ratio of images.

- Gaming apps need to maintain a fixed aspect ratio.

Currently, apps can call the following APIs to set the aspect ratio limit for the window content area.

| API | Function | Applicable Scenario | Effective Scope |
| -------- | -------- | -------- | -------- |
| [setAspectRatio()](../reference/apis-arkui/arkts-apis-window-Window.md#setaspectratio10) | Sets the aspect ratio of the window content layout (excluding decorations such as borders and title bars). This ratio parameter is persisted by default. | - Configuring the same content aspect ratio for multiple launch instances of the same app. When a main window of the same app calls this API and the aspect ratio takes effect, subsequently opened main windows will continue to use this aspect ratio. | Main window in [Free Window](freeform-window-overview.md#freeform-window) state |
| [setContentAspectRatio()](../reference/apis-arkui/arkts-apis-window-Window.md#setcontentaspectratio21) | Sets the aspect ratio of the window content layout (excluding decorations such as borders and title bars).<br/>The window width and height will adjust according to changes in the window border decoration size or visibility, and it supports configuring whether this ratio parameter is persisted. | - Customizing the main window title bar size and visibility<br/>- Setting the aspect ratio for a single main window individually | Main window in [Free Window](freeform-window-overview.md#freeform-window) state |

Sample

<!-- @[aspectRatio](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AdjustLayout/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Index.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import hilog from '@ohos.hilog';

const DOMAIN = 0x0000;
const TAG = 'IndexPage';

// ...
  /**
   Step 2: Set the specified aspect ratio for the main window.
   */
  private setWindowAspectRatioEnabled(enabled: boolean): void {
    const mainWindow = this.getMainWindow();
    if (!mainWindow) {
      this.resultText = 'Main window not found';
      return;
    }
    if (enabled) {
      const ratio = 1.5;
      // Set the aspect ratio limit for the layout content.
      mainWindow.setAspectRatio(ratio)
        .then(() => {
          AppStorage.setOrCreate('WINDOW_ASPECT_RATIO_ENABLED', enabled);
          this.resultText = 'Aspect ratio limit enabled';
        })
        .catch((err: Error) => {
          const businessError = err as BusinessError;
          this.resultText = `Failed to set aspect ratio limit: ${JSON.stringify(businessError)}`;
          hilog.error(DOMAIN, TAG, `set aspect ratio failed: ${JSON.stringify(businessError)}`);
        });
    } else {
      // Cancel the aspect ratio limit for the layout content.
      mainWindow.resetAspectRatio()
        .then(() => {
          AppStorage.setOrCreate('WINDOW_ASPECT_RATIO_ENABLED', enabled);
          this.resultText = 'Aspect ratio limit disabled';
        })
        .catch((err: Error) => {
          const businessError = err as BusinessError;
          this.resultText = `Failed to reset aspect ratio limit: ${JSON.stringify(businessError)}`;
          hilog.error(DOMAIN, TAG, `reset aspect ratio failed: ${JSON.stringify(businessError)}`);
        });
    }
  }
```

## Adjusting the Window Position and Size

### Setting the Initial Position and Size of the Main Window at Startup

The initial position and size of an app window at startup can be set. This is available through the following two methods.

- When an app is launched by calling [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability-1), the initial position and size of the main window can be set via [StartOptions](../reference/apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions).

  The related attributes and their meanings are as follows:

  | Attribute | Description |
  | -------- | -------- |
  | windowLeft | Offset of the window along the x-axis, with the top-left corner of the screen specified by **displayId** as the origin. Unit: px. A positive value indicates the window is to the right of the origin, and a negative value indicates it is to the left. |
  | windowTop | Offset of the window along the y-axis, with the top-left corner of the screen specified by **displayId** as the origin. Unit: px. A positive value indicates the window is below the origin, and a negative value indicates it is above. |
  | windowWidth | Width of the window, in px. The value range is [minWindowWidth, maxWindowWidth], where the unit of the range is vp. |
  | windowHeight | Height of the window, in px. The value range is [minWindowHeight, maxWindowHeight], where the unit of the range is vp. |

  > **NOTE**
  > 
  > - This configuration method takes effect only in the [freefrom window](freeform-window-overview.md#freeform-window) state.
  > 
  > - This configuration method has a higher priority than the configuration method via the [module.json5 configuration file](../quick-start/module-configuration-file.md).
  > 
  > - The window size value range is constrained by **minWindowWidth**/**maxWindowWidth** and **minWindowHeight**/**maxWindowHeight**. The current window size constraints can be obtained through the [getWindowLimits()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowlimits11) API.
  > 
  > - It is recommended to configure both **windowLeft** and **windowTop**. When the window position exceeds the specified screen area, the system will constrain the window to remain visible within the screen bounds.

- Configure the default size and position of the app's main window through the [metadata tag](window-config-m.md#metadata) under the [abilities](../quick-start/module-configuration-file.md#abilities) in the [module.json5 configuration file](../quick-start/module-configuration-file.md).

  The values and their meanings of **name** are described as follows:

  | Value | Description | Remarks |
  | -------- | -------- | -------- |
  | "ohos.ability.window.height" | Default height of the main window. | Unit: vp. |
  | "ohos.ability.window.width" | Default width of the main window. | Unit: vp. |
  | "ohos.ability.window.left" | Default position of the main window on the x-axis. | Configuration format: Alignment +/- offset. Alignment options include **center**, **left**, and **right**, with **left** as the default; the offset can be omitted when it is **0**. |
  | "ohos.ability.window.top" | Default position of the main window on the y-axis. | Configuration format: Alignment +/- offset. Alignment options include **center**, **top**, and **bottom**, with **top** as the default; if both the alignment and offset are omitted, the default z-order is applied. |

### Dynamically Adjusting the Window Position and Size

After a window is created, you can dynamically adjust its position and size through APIs.

- Adjust the window position: The **moveWindowTo()** APIs can be used to adjust the window position. Currently, multiple move APIs are provided for adjusting the window position in different coordinate system scenarios.

  > **NOTE**
  > 
  > - It is not recommended to use the following APIs in window modes other than the floating window mode (that is, the window mode is **window.WindowStatusType.FLOATING**, which can be obtained through [getWindowStatus()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowstatus12)).
  > 
  > - When using the following move APIs, if the title bar of the main window or subwindow is moved out of the visible area of the screen, the system will automatically bounce the window back to ensure the title bar remains visible.

  | API | Coordinate System Origin | Description |
  | -------- | -------- | -------- |
  | [moveWindowTo()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowto9-1) | [Freeform window](freeform-window-overview.md#freeform-window): The origin is the top-left vertex of the screen.<br/>Non-[freeform window](freeform-window-overview.md#freeform-window): when moving a subwindow or modal window, the origin is the top-left vertex of the parent window; when moving other windows, the origin is the top-left vertex of the screen | Moves the window position. The call returns upon success, and the final effective result cannot be obtained immediately after the return. |
  | [moveWindowToAsync()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoasync12) with input parameters **x** and **y**<br/>[moveWindowToAsync()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoasync15) with input parameters **x**, **y**, **moveConfiguration** | [Freeform window](freeform-window-overview.md#freeform-window): The origin is the top-left vertex of the screen.<br/>Non-[freeform window](freeform-window-overview.md#freeform-window): The origin is the top-left vertex of the main window. | Moves the window position. The call returns after the operation takes effect. |
  | [moveWindowToGlobal()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoglobal15) with input parameters **x** and **y**<br/>[moveWindowToGlobal()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoglobal15) with input parameters **x**, **y**, and **moveConfiguration** | Top-left vertex of the target screen | Moves the window position based on screen coordinates. The call returns after the operation takes effect. |
  | [moveWindowToGlobalDisplay()](../reference/apis-arkui/arkts-apis-window-Window.md#movewindowtoglobaldisplay20) | Top-left vertex of the main screen (global coordinate system) | Moves the window position based on the [global coordinate system](window-terminology.md#global-coordinate-system). |

- Adjust the window size: Use the [resize()](../reference/apis-arkui/arkts-apis-window-Window.md#resize9-1) and [resizeAsync()](../reference/apis-arkui/arkts-apis-window-Window.md#resizeasync12) APIs to dynamically adjust the window size at runtime.  

  | API | Description |
  | -------- | -------- |
  | [resize()](../reference/apis-arkui/arkts-apis-window-Window.md#resize9-1) | Changes the current window size based on the top-left vertex of the window. Returns immediately after the call succeeds, and the final effective result cannot be obtained immediately after this API returns. |
  | [resizeAsync()](../reference/apis-arkui/arkts-apis-window-Window.md#resizeasync12) | Changes the current window size based on the top-left vertex of the window. Returns after the call takes effect, and the final effective result can be obtained immediately. |

  > **NOTE**
  > 
  > - The window has size constraints [WindowLimits](../reference/apis-arkui/arkts-apis-window-i.md#windowlimits11), and the set size will be subject to these constraints.
  > 
  > - The above APIs take effect only when the window is in floating window mode (that is, the window mode is **window.WindowStatusType.FLOATING**, which can be obtained through [getWindowStatus()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowstatus12)).
  > 
  > - In non-[freeform window](freeform-window-overview.md#freeform-window) state, the call does not take effect for the main window.

  Sample

  <!-- @[sub_move_resize](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AdjustLayout/entry/src/main/ets/entryability/EntryAbility.ets) -->

  ``` TypeScript
  // EntryAbility.ets
  import { UIAbility } from '@kit.AbilityKit';
  import { window, display } from '@kit.ArkUI';
  import { BusinessError } from '@kit.BasicServicesKit';
  import hilog from '@ohos.hilog';
  
  const DOMAIN = 0x0000;
  const TAG = 'Sample_AdjustLayout';
  
  // ...
    /**
     * Create a subwindow and adjust its position and size.
     */
    private createSubWindow(windowStage: window.WindowStage): void {
      if (!this.mainWindow) {
        return;
      }
      const mainRect = this.mainWindow.getWindowProperties().windowRect;
      const subWidth = 600;
      const subHeight = 300;
      const margin = 24;
  
      // Calculate subwindow position: place at the bottom-right corner of the main window
      const subX = Math.max(
        mainRect.left + margin,
        mainRect.left + mainRect.width - subWidth - margin
      );
  
      const subY = Math.max(
        mainRect.top + margin,
        mainRect.top + mainRect.height - subHeight - margin
      );
  
      // Create a subwindow.
      windowStage.createSubWindow('DemoSubWindow').then((subWindow: window.Window) => {
        hilog.info(DOMAIN, TAG, 'createSubWindow success');
  
        this.subWindow = subWindow;
        AppStorage.setOrCreate<window.Window>('SUB_WINDOW', subWindow);
        AppStorage.setOrCreate<window.Size>('WINDOW_SIZE', {
          width: subWidth,
          height: subHeight
        });
  
        // Register the subwindow size change listener.
        this.registerSubWindowRectChange(subWindow);
        // Set the subwindow size.
        this.subWindow!.resizeAsync(subWidth, subHeight);
        // Move the subwindow position.
        this.subWindow!.moveWindowToAsync(subX, subY);
        // Set the subwindow to be draggable by default.
        this.subWindow!.enableDrag(true);
        // Load the subwindow content page.
        this.loadSubWindowContent(this.subWindow!);
      }).catch((err: Error) => {
        const businessError = err as BusinessError;
        hilog.error(DOMAIN, TAG, `createSubWindow failed: ${JSON.stringify(businessError)}`);
      });
    }
  ```

### Changing the Window Position and Size by Dragging

Currently, the following two window dragging capabilities are provided.

- You can use [startMoving()](../reference/apis-arkui/arkts-apis-window-Window.md#startmoving14) or [startMoving()](../reference/apis-arkui/arkts-apis-window-Window.md#startmoving15) with an offset parameter to enable window drag movement. After this API is successfully called, the window will follow the mouse or touch point movement.

  > **NOTE**
  > 
  > - The **startMoving()** API must be called within the callback of the [onTouch](../reference/apis-arkui/arkui-ts/ts-universal-events-touch.md#ontouch) event, and it takes effect only when the event type is **TouchType.Down**.
  > 
  > - The system automatically stops dragging the window when the user releases the mouse or touch point. Developers can also actively stop it by calling the [stopMoving()](../reference/apis-arkui/arkts-apis-window-Window.md#stopmoving15) API.
  > 
  > - When calling the [startMoving()](../reference/apis-arkui/arkts-apis-window-Window.md#startmoving15) API with an **offset** parameter, you can specify the precise position of the cursor within the window during dragging, achieving a more natural dragging experience.

  Applicable scenario:

  - When customizing the window title bar, add drag movement capability to the title bar area.

  - Implement a custom draggable area for the window.

  Sample:

  <!-- @[startMoving](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AdjustLayout/entry/src/main/ets/pages/SubWindowPage.ets) -->

  ``` TypeScript
  import { window } from '@kit.ArkUI';
  import { BusinessError } from '@kit.BasicServicesKit';
  import hilog from '@ohos.hilog';
  
  const DOMAIN = 0x0000;
  const TAG = 'Sample_AdjustLayout';
  
  @Entry
  @Component
  struct SubWindowPage {
    @StorageProp('WINDOW_SIZE') windowSize: window.Size = {
      width: 600,
      height: 300
    };
  
    @StorageLink('SUB_WINDOW_VISIBILITY_ENABLED') showSubWindowEnabled: boolean = false;
    @StorageProp('SUB_WINDOW_RESIZE_ENABLED') resizeEnabled: boolean = true;
    @StorageProp('SUB_WINDOW_MOVE_ENABLED') moveEnabled: boolean = true;
  
    private isCompact(): boolean {
      return this.windowSize.width < 500 || this.windowSize.height < 240;
    }
  
    /**
     * Enable system drag-and-move for the sub-window via startMoving
     */
    private startMoveSubWindow(): void {
      const subWindow = AppStorage.get<window.Window>('SUB_WINDOW');
      if (!subWindow) {
        return;
      }
      subWindow.startMoving().then(() => {
        hilog.info(DOMAIN, TAG, 'startMoving success');
      }).catch((err: Error) => {
        const businessError = err as BusinessError;
        hilog.error(DOMAIN, TAG, `startMoving failed: ${JSON.stringify(businessError)}`);
      });
    }
  
    build() {
      Column() {
        Row() {
          Text(this.moveEnabled ? 'Sub Window - Move Enabled' : 'Sub Window - Move Disabled')
            .fontSize(14)
            .fontWeight(FontWeight.Bold)
            .fontColor(Color.White)
          Blank()
          Text(`${this.windowSize.width} × ${this.windowSize.height}`)
            .fontSize(12)
            .fontColor('#DDE7FF')
        }
        .height(44)
        .width('100%')
        .padding({ left: 16, right: 16 })
        .backgroundColor(this.moveEnabled ? '#2F5BEA' : '#666666')
        .onTouch((event: TouchEvent) => {
          if (event.type === TouchType.Down && this.moveEnabled) {
            this.startMoveSubWindow();
          }
        })
  
        Column() {
          Text('Current sub-window size')
            .fontSize(16)
            .fontWeight(FontWeight.Bold)
  
          Text(`width = ${this.windowSize.width}px`)
            .fontSize(14)
            .margin({ top: 8 })
  
          Text(`height = ${this.windowSize.height}px`)
            .fontSize(14)
            .margin({ top: 4 })
  
          Text(this.resizeEnabled ? 'Resize drag: enabled' : 'Size drag: off')
            .fontSize(13)
            .fontColor('#666666')
            .margin({ top: 12 })
  
          Text(this.moveEnabled ? 'Position drag: on' : 'Position drag: off')
            .fontSize(13)
            .fontColor('#666666')
            .margin({ top: 4 })
  
          if (this.isCompact()) {
            Text('Compact Layout')
              .fontSize(18)
              .fontWeight(FontWeight.Bold)
              .margin({ top: 16 })
          } else {
            Row() {
              Column() {
                Text('Left Panel')
                  .fontSize(18)
                  .fontWeight(FontWeight.Bold)
              }
              .width('45%')
              .height(80)
              .justifyContent(FlexAlign.Center)
              .backgroundColor('#EEF3FF')
  
              Column() {
                Text('Right Panel')
                  .fontSize(18)
                  .fontWeight(FontWeight.Bold)
              }
              .width('55%')
              .height(80)
              .justifyContent(FlexAlign.Center)
              .backgroundColor('#FFFFFF')
            }
            .width('100%')
            .margin({ top: 16 })
          }
        }
        .width('100%')
        .layoutWeight(1)
        .justifyContent(FlexAlign.Center)
        .alignItems(HorizontalAlign.Center)
      }
      .width('100%')
      .height('100%')
      .backgroundColor('#FFFFFF')
      .border({
        width: 4,
        color: '#FF4D4F',
        radius: 0
      })
    }
  }
  ```

- [enableDrag()](../reference/apis-arkui/arkts-apis-window-Window.md#enabledrag20) can be used to enable/disable window dragging. When enabled, the window can be dragged and resized via mouse or touch operations. 

  > **NOTE**
  > 
  > During drag resizing, the window size is subject to [WindowLimits](../reference/apis-arkui/arkts-apis-window-i.md#windowlimits11) constraints.

  <!-- @[enableDrag](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AdjustLayout/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  // Index.ets
  import { window } from '@kit.ArkUI';
  import { BusinessError } from '@kit.BasicServicesKit';
  import hilog from '@ohos.hilog';
  
  const DOMAIN = 0x0000;
  const TAG = 'IndexPage';
  
  // ...
    /**
     Control the drag resize capability of the subwindow through enableDrag
     */
    private setSubWindowResizeEnabled(enabled: boolean): void {
      const subWindow = this.getSubWindow();
      if (!subWindow) {
        this.resultText = 'Subwindow not created';
        return;
      }
  
      subWindow.enableDrag(enabled)
        .then(() => {
          AppStorage.setOrCreate<boolean>('SUB_WINDOW_RESIZE_ENABLED', enabled);
          this.resultText = enabled ? 'Subwindow drag resize enabled' : 'Subwindow drag resize disabled';
        })
        .catch((err: Error) => {
          const businessError = err as BusinessError;
          this.resultText = `Failed to set drag resize: ${JSON.stringify(businessError)}`;
          hilog.error(DOMAIN, TAG, `set resize drag failed: ${JSON.stringify(businessError)}`);
        });
    }
  ```

### Sensing the Window Position and Size Changes

Apps can sense changes in window position and size by actively querying, registering event listeners, or declaring environment variables, and then respond accordingly.

Currently, the following APIs are available for querying and listening to window position and size changes:

| API | Return Value Type | Description |
| -------- | -------- | -------- |
| [on('windowSizeChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowsizechange7) | [Size](../reference/apis-arkui/arkts-apis-window-i.md#size7) | Listens to window size changes, in px. |
| [on('windowRectChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowrectchange12) | [RectChangeOptions](../reference/apis-arkui/arkts-apis-window-i.md#rectchangeoptions12) | Listens to window rectangle (window position and window size) changes, returns the corresponding values and the reason for the change, in px. |
| [on('rectChangeInGlobalDisplay')](../reference/apis-arkui/arkts-apis-window-Window.md#onrectchangeinglobaldisplay20) | [RectChangeOptions](../reference/apis-arkui/arkts-apis-window-i.md#rectchangeoptions12) | Listens to window rectangle (window position and window size) changes in the [global coordinate system](window-terminology.md#global-coordinate-system), returns the corresponding values and the reason for the change, in px. |
| [getWindowProperties()](../reference/apis-arkui/arkts-apis-window-Window.md#getwindowproperties9) | [WindowProperties](../reference/apis-arkui/arkts-apis-window-i.md#windowproperties) | Obtains the properties of the current window. The properties related to window position and size are:<br/>windowRect: The position and size of the window, relative to the current screen coordinate system.<br/>drawableRect: The size of the drawable area within the window, where the left and top boundaries are calculated relative to the top-left vertex of the window. globalDisplayRect: The position and size of the window, relative to the [global coordinate system](window-terminology.md#global-coordinate-system). |

Apps can also sense window position and size changes by using environment variables. Environment variables are a global state management mechanism. In multi-device development scenarios, you can use the [@Env](../reference/apis-arkui/arkui-ts/ts-env-system-property.md) decorator to listen for changes in system environment variables and make corresponding scenario judgments based on them, thereby reducing adaptation logic and repetitive development across different devices. For details, see [@Env: Environment Variables](../ui/arkts-env-system-property.md).

Environment variables allow components to perceive and respond to window size changes. When the window size changes, components that declare and use environment variables for layout can achieve responsive layout effects.

| Environment Variable | Return Type | Description |
| -------- | -------- | -------- |
| SystemProperties.WINDOW_SIZE | window.SizeInVP | Window size, in vp. It contains **width** and **height** attributes. |
| SystemProperties.WINDOW_SIZE_PX | window.Size | Window size, in px. It contains **width** and **height** attributes. |