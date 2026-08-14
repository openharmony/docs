# App Window Development (Stage Model)

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=19d0e8dbccdd9765ceafae62e52b988d19566645 translatedAt=2026-08-11T10:11:26.460Z pushedAt=2026-08-11T10:57:11.365Z -->

## Basic Concepts

- Window immersive: the ability to control system windows such as the status bar and navigation bar, reducing the abruptness of system UI elements like the status bar and navigation bar, thereby delivering an optimal user experience. The immersive capability takes effect only when the app main window is in full-screen mode. Generally, auxiliary windows of an app (such as subwindows and global floating windows) and the app main window in free window mode cannot use the immersive capability.

- Global floating window: a special type of app auxiliary window that can remain displayed in the foreground even after the app main window and the corresponding UIAbility are moved to the background. Global floating windows can be used to continue displaying UI in a small window after an app is moved to the background. Before creating a global floating window, an app must apply for the corresponding permission.

## When to Use

In the stage model, typical scenarios for managing app windows include:

- Setting the main window properties and target page of the app

- Setting the subwindow properties and target page of the app

- Experiencing the immersive window feature

- Setting a global floating window

- Listening for interactive and non-interactive window events

The specific development methods are described below.

## Available APIs

The common APIs involved in the above scenarios are shown in the following table. For more API descriptions, see [@ohos.window (Window)](../reference/apis-arkui/arkts-apis-window.md).

| Instance Name | API Name | Description |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| WindowStage    | getMainWindow(callback: AsyncCallback&lt;Window&gt;): void   | Obtains the main window of this `WindowStage` instance.<br/>This API can be used only in the stage model. |
| WindowStage    | loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads a specific page for the main window of this `WindowStage`.<br>Here, `path` is the path of the page content to be loaded into the window. This path must be added to the `main_pages.json` file of the project.<br/>This API can be used only in the stage model. |
| WindowStage    | createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void | Creates a subwindow.<br/>This API can be used only in the stage model. |
| WindowStage    | on(eventType: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void | Enables listening for `WindowStage` lifecycle changes.<br/>This API can be used only in the stage model. |
| window static method | createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | Creates a subwindow or system window.<br/>-`config`: parameters for creating the window. |
| Window         | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads specific page content for the window based on the path of a page in the current project.<br>Here, `path` is the path of the page content to be loaded into the window. In the stage model, this path must be added to the `main_pages.json` file of the project. |
| Window         | setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | Sets the screen brightness value. |
| Window         | setWindowTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void | Sets whether the window is touchable. The value `true` indicates touchable, and `false` indicates not touchable. |
| Window         | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves the current window position. |
| Window         | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Resizes the current window. |
| Window         | setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt; | Sets whether the layout of the main window or subwindow is immersive. The value `true` indicates immersive layout, and `false` indicates non-immersive layout. |
| Window         | setWindowSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | <!--RP4-->Sets the visibility mode of the status bar and three-key navigation bar of the main window. The status bar is controlled by `status`, and the three-key navigation bar is controlled by `navigation`<!--RP4End-->.<br>For example, if this parameter is set to `['status',&nbsp;'navigation']`, both are displayed; if it is set to `[]`, neither is displayed. |
| Window         | setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt; | Sets the properties of the navigation bar and status bar in the window.<br/>`systemBarProperties`: a collection of properties for the navigation bar and status bar. |
| Window         | showWindow(callback: AsyncCallback\<void>): void             | Shows the current window. |
| Window         | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Enables listening for tap events outside the current window area. |
| Window         | destroyWindow(callback: AsyncCallback&lt;void&gt;): void     | Destroys the current window. |

## Setting the Main Window of an App

In the stage model, the main window is created and its lifecycle maintained by `UIAbility`. In the `onWindowStageCreate` callback of `UIAbility`, you can obtain the app main window through `WindowStage` to set its properties and perform other operations. You can also set properties of the app main window in the app configuration file, such as the maximum window width `maxWindowWidth`. For details, see [abilities tag in the module.json5 Configuration File](../quick-start/module-configuration-file.md#abilities).

### How to Develop

1. Obtain the app main window.

   Obtain the app main window through the `getMainWindow` API.

2. Set main window properties.

   You can set multiple properties of the main window, such as the background color, brightness value, and whether it is touchable. You can select the corresponding API as needed. The code snippet below uses the **touchable** property as an example.

3. Load the corresponding target page for the main window.

   Use the `loadContent` API to load the target page of the main window.

<!-- @[create_main_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/CreateMainWindow/entry/src/main/ets/entryability/EntryAbility.ets) -->

``` TypeScript
import { UIAbility} from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0X0000;
const TAG: string = '[Sample_CreatMainWindow]';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 1. Obtain the main window of the app.
    let windowClass: window.Window | null = null;
    windowStage.getMainWindow((err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        hilog.error(DOMAIN, TAG, `Failed to obtain the main window. Code:${err.code}, message:${err.message}`);
        return;
      }
      windowClass = data;
      hilog.info(DOMAIN, TAG, `Succeeded in obtaining the main window. Result:${data}`);
      // 2. Set the main window properties. For example, set the touchable property.
      let isTouchable: boolean = true;
      windowClass.setWindowTouchable(isTouchable, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          hilog.error(DOMAIN, TAG, `Failed to set the window to be touchable. Cause: ${JSON.stringify(err)}`);
          return;
        }
        hilog.info(DOMAIN, TAG, `Succeeded in setting the window to be touchable.`);
      })
    })
    // 3. Load the target page for the main window.
    windowStage.loadContent('pages/Index', (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        hilog.error(DOMAIN, TAG, `Failed to load the content. Cause: ${JSON.stringify(err)}`);
        return;
      }
      hilog.info(DOMAIN, TAG, `Succeeded in loading the content.`);
    });
  }
};
```

## Setting an App Subwindow

You can create subwindows as needed, such as dialogs, and perform operations like setting their properties.

> **NOTE**
> The following scenarios are not recommended for using subwindows. You are advised to prioritize using the control [overlay](../reference/apis-arkui/arkui-ts/ts-universal-attributes-overlay.md) capability.
> - On mobile devices (tablets in non-freeform mode and phones), subwindows cannot extend beyond the main window range when the main window is in multi-window floating window mode or split-screen mode, which is consistent with controls.
> - In split-screen window and freeform window modes, controls have a better real-time following capability than subwindows when the main window position and size change.
> - On some device platforms, due to actual system configuration restrictions, subwindows only have the system's default animation effects and rounded corner shadows, which apps cannot set, resulting in low flexibility.

### How to Develop

1. Create an app subwindow.

   Create an app subwindow through the `createSubWindow` API.

   After being created, a subwindow uses the [immersive layout](../windowmanager/immersive-window-feature.md#immersive-layout) by default.

2. Set subwindow properties.

   After the subwindow is created, you can change its size, position, and other properties, as well as set properties such as the window background color and brightness based on the app's needs.

   Before calling `showWindow`, you are advised to set the size and position of the subwindow.

   If the subwindow size is not set, after `showWindow` is called:

   + In the [freeform window](./window-terminology.md#freeform-window) state, the default subwindow size is the size of the current physical screen.<!--RP3--><!--RP3End-->

   + In the non-freeform window state, the default subwindow size is the size of the main window.

3. Load and display the specific content of the subwindow.

   Load and display the specific content of the subwindow through the `setUIContent` and `showWindow` APIs.

4. Destroy the subwindow.

   When a subwindow is no longer needed, you can destroy it using the `destroyWindow` API based on the specific implementation logic.

The following is the complete sample code for creating a subwindow directly in **onWindowStageCreate**:

<!-- @[create_sub_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/CreateSubWindow/entry/src/main/ets/entryability/EntryAbility.ets) -->

``` TypeScript
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0X0000;
const TAG: string = '[Sample_CreatSubWindow]';

let windowStage_: window.WindowStage | null = null;
let sub_windowClass: window.Window | null = null;

export default class EntryAbility extends UIAbility {
  showSubWindow() {
    // 1. Create the application subwindow.
    if (windowStage_ == null) {
      hilog.error(DOMAIN, TAG, `Failed to create the subwindow. Cause: windowStage_ is null`);
    } else {
      windowStage_.createSubWindow('mySubWindow', (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          hilog.error(DOMAIN, TAG, `Failed to create the subwindow. Cause: ${JSON.stringify(err)}`);
          return;
        }
        sub_windowClass = data;
        if (!sub_windowClass) {
          hilog.error(DOMAIN, TAG, `sub_windowClass is null`);
          return;
        }
        hilog.info(DOMAIN, TAG, `Succeeded in creating the subwindow. Data: ${JSON.stringify(data)}`);
        // 2. After the subwindow is created, set its position, size, and related properties.
        sub_windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, TAG, `Failed to move the window. Cause: ${JSON.stringify(err)}`);
            return;
          }
          hilog.info(DOMAIN, TAG, `Succeeded in moving the window.`);
        });
        sub_windowClass.resize(500, 500, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, TAG, `Failed to change the window size. Cause: ${JSON.stringify(err)}`);
            return;
          }
          hilog.info(DOMAIN, TAG, `Succeeded in changing the window size.`);
        });
        // 3. Load the target page for the subwindow.
        sub_windowClass.setUIContent('pages/Index', (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.info(DOMAIN, TAG, `Failed to load the content. Cause: ${JSON.stringify(err)}`);
            return;
          }
          hilog.info(DOMAIN, TAG, `Succeeded in loading the content.`);
          if (!sub_windowClass) {
            hilog.error(DOMAIN, TAG, `sub_windowClass is null`);
            return;
          }
          // 4. Show the subwindow.
          sub_windowClass.showWindow((err: BusinessError) => {
            let errCode: number = err.code;
            if (errCode) {
              hilog.error(DOMAIN, TAG, `Failed to show the window. Cause: ${JSON.stringify(err)}`);
              return;
            }
            hilog.info(DOMAIN, TAG, `Succeeded in showing the window.`);
          });
        });
      })
    }
  }

  destroySubWindow() {
    if (!sub_windowClass) {
      hilog.error(DOMAIN, TAG, `sub_windowClass is null`);
      return;
    }
    // 5. Destroy the subwindow. When the subwindow is no longer needed, destroy it by calling destroy based on the specific implementation logic.
    sub_windowClass.destroyWindow((err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        hilog.error(DOMAIN, TAG, `Failed to destroy the window. Cause: ${JSON.stringify(err)}`);
        return;
      }
      hilog.info(DOMAIN, TAG, `Succeeded in destroying the window.`);
    });
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage_ = windowStage;
    // You can create a subwindow at an appropriate time, such as on a button click event on the main window. It is not mandatory to call this in onWindowStageCreate; this is only for demonstration.
    this.showSubWindow();
  }

  onWindowStageDestroy() {
    // You can destroy a subwindow at an appropriate time, such as when clicking the close button on the subwindow. It is not mandatory to call this in onWindowStageDestroy; this is only for demonstration.
    this.destroySubWindow();
  }
};
```

Additionally, you can create a subwindow by clicking a button on a page. The complete sample code is as follows:

<!-- @[create_sub_window2_entryability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/CreateSubWindow2/entry/src/main/ets/entryability/EntryAbility.ets) -->

``` TypeScript
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0X0000;
const TAG: string = '[Sample_CreatSubWindow2]';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(DOMAIN, TAG, `Failed to load the content. Cause: ${JSON.stringify(err)}`);
        return;
      }
      hilog.info(DOMAIN, TAG, `Succeeded in loading the content.`);
    });

    // Pass windowStage to the Index page.
    AppStorage.setOrCreate('windowStage', windowStage);
  }
}
```

<!-- @[create_sub_window2_index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/CreateSubWindow2/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Index.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0X0000;
const TAG : string = '[Sample_CreatSubWindow2]';

let windowStage_: window.WindowStage | undefined = undefined;
let sub_windowClass: window.Window | undefined = undefined;
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  private createSubWindow(){
    // Obtain the windowStage.
    windowStage_ = AppStorage.get('windowStage');
    // 1. Create the application subwindow.
    if (windowStage_ == null) {
      hilog.error(DOMAIN, TAG, `Failed to create the subwindow. Cause: windowStage_ is null`);
    } else {
      windowStage_.createSubWindow('mySubWindow', (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          hilog.error(DOMAIN, TAG, `Failed to create the subwindow. Cause: ${JSON.stringify(err)}`);
          return;
        }
        sub_windowClass = data;
        if (!sub_windowClass) {
          hilog.error(DOMAIN, TAG, `sub_windowClass is null`);
          return;
        }
        hilog.info(DOMAIN, TAG, `Succeeded in creating the subwindow. Data: ${JSON.stringify(data)}`);
        // 2. After the subwindow is created, set its position, size, and related properties.
        sub_windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, TAG, `Failed to move the window. Cause: ${JSON.stringify(err)}`);
            return;
          }
          hilog.info(DOMAIN, TAG, `Succeeded in moving the window.`);
        });
        sub_windowClass.resize(500, 500, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, TAG, `Failed to change the window size. Cause: ${JSON.stringify(err)}`);
            return;
          }
          hilog.info(DOMAIN, TAG, `Succeeded in changing the window size.`);
        });
        // 3. Load the target page for the subwindow.
        sub_windowClass.setUIContent('pages/SubWindow', (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, TAG, `Failed to load the content. Cause: ${JSON.stringify(err)}`);
            return;
          }
          hilog.info(DOMAIN, TAG, `Succeeded in loading the content.`);
          if (!sub_windowClass) {
            hilog.error(DOMAIN, TAG, `sub_windowClass is null`);
            return;
          }
          // 3. Show the subwindow.
          sub_windowClass.showWindow((err: BusinessError) => {
            let errCode: number = err.code;
            if (errCode) {
              hilog.error(DOMAIN, TAG, `Failed to show the window. Cause: ${JSON.stringify(err)}`);
              return;
            }
            hilog.info(DOMAIN, TAG, `Succeeded in showing the window.`);
          });
        });
      })
    }
  }
  private destroySubWindow(){
    if (!sub_windowClass) {
      hilog.error(DOMAIN, TAG, `sub_windowClass is null`);
      return;
    }
    // 4. Destroy the subwindow. When the subwindow is no longer needed, destroy it by calling the destroy method based on the specific implementation logic.
    sub_windowClass.destroyWindow((err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        hilog.error(DOMAIN, TAG, `Failed to destroy the window. Cause: ${JSON.stringify(err)}`);
        return;
      }
      hilog.info(DOMAIN, TAG, `Succeeded in destroying the window.`);
    });
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button(){
          Text('CreateSubWindow')
            .fontSize(24)
            .fontWeight(FontWeight.Normal)
        }.width(220).height(68)
        .margin({left:10, top:60})
        .onClick(() => {
          this.createSubWindow()
        })
        Button(){
          Text('destroySubWindow')
            .fontSize(24)
            .fontWeight(FontWeight.Normal)
        }.width(220).height(68)
        .margin({left:10, top:60})
        .onClick(() => {
          this.destroySubWindow()
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

<!-- @[create_sub_window2_subwindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/CreateSubWindow2/entry/src/main/ets/pages/SubWindow.ets) -->

``` TypeScript
// subWindow.ets
@Entry
@Component
struct SubWindow {
  @State message: string = 'Hello subWindow';
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
    .backgroundColor('#0D9FFB')
  }
}
```

## Experiencing the Immersive Window Feature

In scenarios such as watching videos or playing games, users often prefer to hide unnecessary system windows like the status bar and navigation bar for a better immersive experience. In such cases, the window immersive mode (which applies only to the app main window) can be used to achieve the desired effect. Starting from API version 10, the immersive window is configured to full-screen size by default, with the layout controlled by the component module. The status bar and navigation bar have transparent backgrounds with black text. When the app window calls the `setWindowLayoutFullScreen` API, setting it to `true` means the component module controls an immersive full-screen layout that ignores the status bar and navigation bar, while setting it to `false` means the component module controls a non-immersive full-screen layout that avoids the status bar and navigation bar.

> **NOTE**
>
> Currently, immersive UI development supports only window-level configuration, not page-level configuration. If page-level switching is required, you can set the immersive mode at the beginning of the page lifecycle, for example, in `onPageShow`, and restore the default settings when the page exits, for example, in `onPageHide`.

### How to Develop

1. Obtain the app main window.

   Obtain the app main window through the `getMainWindow` API.

2. Implement the immersive effect. There are two methods:

   - Method 1: When the app main window is a full-screen window, call the `setWindowSystemBarEnable` API to hide the navigation bar and status bar, thereby achieving the immersive effect.

   - Method 2: Call the `setWindowLayoutFullScreen` API to set the app main window to full-screen layout; then call the `setWindowSystemBarProperties` API to set properties such as transparency, background/text color, and highlighted icons of the navigation bar and status bar, so as to keep them consistent with the main window display and achieve an immersive effect.

3. Load and display the specific content of the immersive window.

   Use the `loadContent` API to load the specific content of the immersive window.

<!-- @[set_window_system_bar_enable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/SetWindowSystemBarEnable/entry/src/main/ets/entryability/EntryAbility.ets) -->

``` TypeScript
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0X0000;
const TAG: string = '[Sample_SetWindowSystemBarEnable]';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 1. Obtain the app main window.
    let windowClass: window.Window | null = null;
    windowStage.getMainWindow((err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        hilog.error(DOMAIN, TAG, `Failed to obtain the main window. Cause: ${JSON.stringify(err)}`);
        return;
      }
      windowClass = data;
      hilog.info(DOMAIN, TAG, `Succeeded in obtaining the main window. Data: ${JSON.stringify(data)}`);

      // 2. Implement the immersive effect. Method 1: Hide the navigation bar and status bar.
      let names: 'status'[] | 'navigation'[] = [];
      windowClass.setWindowSystemBarEnable(names)
        .then(() => {
          hilog.info(DOMAIN, TAG, `Succeeded in setting the system bar to be visible.`);
        })
        .catch((err: BusinessError) => {
          hilog.error(DOMAIN, TAG, `Failed to set the system bar to be visible. Cause: ${JSON.stringify(err)}`);
        });
      // 2. Implement the immersive effect. Method 2: Set the window to full-screen layout, and configure properties such as the transparency, background/text color, and highlighted icons of the navigation bar and status bar to maintain visual consistency with the main window.
      let isLayoutFullScreen = true;
      windowClass.setWindowLayoutFullScreen(isLayoutFullScreen)
        .then(() => {
          hilog.info(DOMAIN, TAG, `Succeeded in setting the window layout to full-screen mode.`);
        })
        .catch((err: BusinessError) => {
          hilog.error(DOMAIN, TAG, `Failed to set the window layout to full-screen mode. Cause: ${JSON.stringify(err)}`);
        });
      let sysBarProps: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // The following two properties are supported since API version 8.
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#ffffff'
      };
      windowClass.setWindowSystemBarProperties(sysBarProps)
        .then(() => {
          hilog.info(DOMAIN, TAG, `Succeeded in setting the system bar properties.`);
        })
        .catch((err: BusinessError) => {
          hilog.error(DOMAIN, TAG, `Failed to set the system bar properties. Cause: ${JSON.stringify(err)}`);
        });
    })
    // 3. Load the target page for the immersive window.
    windowStage.loadContent('pages/Index', (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        hilog.error(DOMAIN, TAG, `Failed to load the content. Cause: ${JSON.stringify(err)}`);
        return;
      }
      hilog.info(DOMAIN, TAG, `Succeeded in loading the content.`);
    });
  }
};
```

## Setting a Global Floating Window (Restricted)

A global floating window allows you to create a window that remains displayed in the foreground on top of an existing task. Even if the task that creates the global floating window is moved to the background, the global floating window can still be displayed in the foreground. Typically, a global floating window is positioned above all app windows. Developers can create a global floating window and perform operations such as setting its properties.

### How to Develop

<!--RP1-->

**Prerequisites:** To create a window of the `WindowType.TYPE_FLOAT` type, i.e., a global floating window, you need to request the `ohos.permission.SYSTEM_FLOAT_WINDOW` permission. This permission is restricted. For details about how to request the permission, see [Applying for Restricted Permissions](../security/AccessToken/declare-permissions-in-acl.md).

<!--RP1End-->

1. Create a global floating window.

   Create a window of the global floating window type by calling the `window.createWindow` API.

2. Set properties such as the size and position of the global floating window.

   After the global floating window is created, you can change its size, position, and other properties, as well as set properties such as the window background color and brightness based on app requirements.

3. Load and display the specific content of the global floating window.

   Load and display the specific content of the global floating window through the `setUIContent` and `showWindow` APIs.

4. Destroy the global floating window.

When a global floating window is no longer needed, you can destroy it using the `destroyWindow` API based on the specific implementation logic.

<!-- @[create_float_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/CreateFloatWindow/entry/src/main/ets/entryability/EntryAbility.ets) -->

``` TypeScript
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0X0000;
const TAG: string = '[Sample_CreatFloatWindow]';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 1. Create a global floating window.
    let windowClass: window.Window | null = null;
    let config: window.Configuration = {
      name: 'floatWindow', windowType: window.WindowType.TYPE_FLOAT, ctx: this.context
    };
    window.createWindow(config, (err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        hilog.error(DOMAIN, TAG, `Failed to create the floatWindow. Cause: ${JSON.stringify(err)}`);
        return;
      }
      hilog.info(DOMAIN, TAG, `Succeeded in creating the floatWindow. Data: ${JSON.stringify(data)}`);
      windowClass = data;
      // 2. After the global floating window is created, set its position, size, and related properties.
      windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          hilog.error(DOMAIN, TAG, `Failed to move the window. Cause: ${JSON.stringify(err)}`);
          return;
        }
        hilog.info(DOMAIN, TAG, `Succeeded in moving the window.`);
      });
      windowClass.resize(500, 500, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          hilog.error(DOMAIN, TAG, `Failed to change the window size. Cause: ${JSON.stringify(err)}`);
          return;
        }
        hilog.info(DOMAIN, TAG, `Succeeded in changing the window size.`);
      });
      // 3. Load the target page for the global floating window.
      windowClass.setUIContent('pages/Index', (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          hilog.error(DOMAIN, TAG, `Failed to load the content. Cause: ${JSON.stringify(err)}`);
          return;
        }
        hilog.info(DOMAIN, TAG, `Succeeded in loading the content.`);
        // 3. Show the global floating window.
        (windowClass as window.Window).showWindow((err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            hilog.error(DOMAIN, TAG, `Failed to show the window. Cause: ${JSON.stringify(err)}`);
            return;
          }
          hilog.info(DOMAIN, TAG, `Succeeded in showing the window.`);
        });
      });
      // 4. Destroy the global floating window. When the global floating window is no longer needed, use destroy to destroy it based on the specific implementation logic.
    });
  }
};
```

## Listening for Interactive and Non-interactive Window Events

During foreground display, an app may enter certain non-interactive scenarios, a typical one being entering the multitasking screen. In such cases, some apps may need to pause a service that is currently interacting with the user, such as a video app pausing a playing video or a camera pausing the preview stream. When the app returns to the foreground from multitasking, it becomes interactive again, and the suspended business needs to be resumed, such as resuming video playback or the camera preview stream.

### How to Develop

After creating a **WindowStage** object, you can listen for the `'windowStageEvent'` event type to monitor events such as the window entering the foreground, background, foreground interactive, and foreground non-interactive states. The app can perform corresponding service processing based on these reported event states.

<!-- @[listen_window_stage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/ListenWindowStage/entry/src/main/ets/entryability/EntryAbility.ets) -->

``` TypeScript
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0X0000;
const TAG: string = '[Sample_ListenWindowStage]';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // ...
    try {
      windowStage.on('windowStageEvent', (data) => {
        hilog.info(DOMAIN, TAG, `Succeeded in enabling the listener for window stage event changes. Data: ${JSON.stringify(data)}`);

        // Select the corresponding processing based on the event state type.
        if (data === window.WindowStageEventType.SHOWN) {
          hilog.info(DOMAIN, TAG, `current window stage event is SHOWN`);
          // The application enters the foreground and is in the interactive state by default.
          // ...
        } else if (data === window.WindowStageEventType.HIDDEN) {
          hilog.info(DOMAIN, TAG, `current window stage event is HIDDEN`);
          // The application enters the background and is in the non-interactive state by default.
          // ...
        } else if (data === window.WindowStageEventType.PAUSED) {
          hilog.info(DOMAIN, TAG, `current window stage event is PAUSED`);
          // The foreground application enters multi-task mode and switches to the non-interactive state.
          // ...
        } else if (data === window.WindowStageEventType.RESUMED) {
          hilog.info(DOMAIN, TAG, `current window stage event is RESUMED`);
          // Restore the interactive state when returning to the foreground from the recent tasks screen.
          // ...
        }

        // ...
      });
    } catch (exception) {
      hilog.error(DOMAIN, TAG, `Failed to enable the listener for window stage event changes. Cause: ${JSON.stringify(exception)}`);
    }
  }
}
```

## Samples

The following samples are provided for window development (stage model):

- [`Window`: Multi-device Typical Page (Settings) (API9)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Settings)

- [Global Floating Window (ArkTS) (API10) (Full SDK)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowRatio)

- [Window Management (ArkTS) (API12) (Full SDK)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowManage)