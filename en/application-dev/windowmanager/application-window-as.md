# Managing App Windows (Atomic Service)

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=58ff40ad92758153f7b55166a9e6e0a0e9be5d28 translatedAt=2026-07-10T07:15:25.590Z pushedAt=2026-07-13T02:01:29.685Z -->

## When to Use

Typical scenarios for managing app windows include:

- Setting the main window attributes and target page of the app

- Setting the sub window attributes and target page of the app

- Listening for window non-interactive and interactive events

The specific development methods are described below.

## API Description

The common APIs involved in the above scenarios are shown in the following table. For more API descriptions, see [@ohos.window (Window)](../reference/apis-arkui/arkts-apis-window.md).

| Instance Name | API Name                                                    | Description                                                  |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| WindowStage   | getMainWindow(callback: AsyncCallback&lt;Window&gt;): void   | Obtains the main window of this `WindowStage` instance.<br/>This API can be used only in the stage model. |
| WindowStage   | loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads a specific page for the main window of this `WindowStage`.<br>Here, `path` is the path of the page content to be loaded into the window. This path must be added to the `main_pages.json` file of the project.<br/>This API can be used only in the stage model. |
| WindowStage   | createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void | Creates a sub window.<br/>This API can be used only in the stage model. |
| WindowStage   | on(type: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void | Enables listening for `WindowStage` lifecycle changes.<br/>This API can be used only in the stage model. |
| Window        | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads specific page content for the window based on the path of a page in the current project.<br>Here, `path` is the path of the page content to be loaded into the window. In the stage model, this path must be added to the `main_pages.json` file of the project. |
| Window        | setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void | Sets whether the window is in privacy mode.                  |
| Window        | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves the current window position.                           |
| Window        | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Resizes the current window.                                  |
| Window        | showWindow(callback: AsyncCallback\<void>): void             | Shows the current window.                                    |
| Window        | destroyWindow(callback: AsyncCallback&lt;void>): void        | Destroys the current window.                                 |

## Setting the App Main Window

The app main window is created and its lifecycle maintained by `UIAbility`. In the `onWindowStageCreate` callback of `UIAbility`, you can obtain the app main window through `WindowStage` to set its attributes and perform other operations. You can also set attributes of the app main window in the app configuration file, such as the maximum window width `maxWindowWidth`. For details, see [module.json5 Configuration File](../quick-start/module-configuration-file.md#abilities).

### How to Develop

**Prerequisites:** `setWindowPrivacyMode` sets the window privacy mode, which is applicable to scenarios where screen capture and screen recording are prohibited. To use this API, you need to request the `ohos.permission.PRIVACY_WINDOW` permission. For the configuration method, see the requestPermissions field in the [Configuration File](../quick-start/module-configuration-file.md#tags-in-the-configuration-file).

1. Obtain the app main window.

   Obtain the app main window through the `getMainWindow` API.

2. Set the window privacy mode attribute.

   Use the `setWindowPrivacyMode` API to set the main window to privacy mode, so that the window content cannot be captured or recorded. This API can be used in scenarios where screenshots and screen recording are prohibited.

3. Load the corresponding target page for the main window.

   Use the `loadContent` API to load the target page of the main window.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 1. Obtain the app main window.
    let windowClass: window.Window | null = null;
    windowStage.getMainWindow((err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
        return;
      }
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
      // 2. Set the window to privacy mode.
      let isPrivacyMode: boolean = true;
      try {
        windowClass.setWindowPrivacyMode(isPrivacyMode, (err: BusinessError) => {
          const errCode: number = err.code;
          if(errCode) {
            console.error('Failed to set the window to privacy mode. Cause:' +
          JSON.stringify(err));
            return;
          }
          console.info('Succeeded in setting the window to privacy mode.');
        });
      } catch (exception) {
        console.error('Failed to set the window to privacy mode. Cause:' +
      JSON.stringify(exception));
      }
    })
    // 3. Load the corresponding target page for the main window.
    windowStage.loadContent("pages/page2", (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in loading the content.');
    });
  }
};
```

## Setting an App Sub Window

You can create app sub windows as needed, such as dialogs, and perform operations like setting their attributes.

> **NOTE**
> The following scenarios are not recommended for using sub windows. It is advised to prioritize using the control [overlay](../reference/apis-arkui/arkui-ts/ts-universal-attributes-overlay.md) capability.  
> - On mobile devices (tablets in non-freeform mode and phones), sub windows cannot extend beyond the main window range when the main window is in floating window or split-screen mode, which is consistent with controls.  
> - In split-screen window and freeform window modes, controls have a better real-time following capability than sub windows when the main window position and size change.  
> - On some device platforms, due to actual system configuration restrictions, sub windows only have the system's default animation effects and rounded corner shadows, which apps cannot set, resulting in low flexibility.

### How to Develop

1. Create an app sub window.

   Create an app sub window through the `createSubWindow` API.

2. Set sub window attributes.

   After the sub window is created, you can change its size, position, and other attributes, as well as set the window background color, brightness, and other properties as needed by the app.

3. Load and display the specific content of the sub window.

   Load and display the specific content of the sub window through the `setUIContent` and `showWindow` APIs.

4. Destroy the sub window.

   When a sub window is no longer needed, you can destroy it using the `destroyWindow` API based on the specific implementation logic.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let windowStage_: window.WindowStage | null = null;
let sub_windowClass: window.Window | null = null;

export default class EntryAbility extends UIAbility {
  showSubWindow() {
    // 1. Create an app sub window.
    if (windowStage_ == null) {
      console.error('Failed to create the subwindow. Cause: windowStage_ is null');
    } else {
      windowStage_.createSubWindow("mySubWindow", (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
          return;
        }
        sub_windowClass = data;
        if (!sub_windowClass) {
          console.error('sub_windowClass is null');
          return;
        }
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        // 2. After the sub window is created, set its position, size, and related properties.
        sub_windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to move the window. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in moving the window.');
        });
        sub_windowClass.resize(500, 500, (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in changing the window size.');
        });
        // 3. Load the corresponding target page for the sub window.
        sub_windowClass.setUIContent("pages/page3", (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in loading the content.');
          if (!sub_windowClass) {
            console.error('sub_windowClass is null');
            return;
          }
          // 3. Show the sub window.
          sub_windowClass.showWindow((err: BusinessError) => {
            let errCode: number = err.code;
            if (errCode) {
              console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
              return;
            }
            console.info('Succeeded in showing the window.');
          });
        });
      })
    }
  }

  destroySubWindow() {
    if (!sub_windowClass) {
      console.error('sub_windowClass is null');
      return;
    }
    // 4. Destroy the sub window. When the sub window is no longer needed, you can destroy it using `destroy` based on the specific implementation logic.
    sub_windowClass.destroyWindow((err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in destroying the window.');
    });
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage_ = windowStage;
    // Developers can create a sub window at an appropriate time, such as upon a button click event on the main window. It does not necessarily need to be called in `onWindowStageCreate`; this is only for demonstration.
    this.showSubWindow();
  }

  onWindowStageDestroy() {
    // The developer can destroy the sub window at an appropriate time, such as when a close button on the sub window is clicked. It does not necessarily need to be called in onWindowStageDestroy; this is only for demonstration.
    this.destroySubWindow();
  }
};
```

## Listening for Window Non-Interactive and Interactive Events

During foreground display, an app may enter certain non-interactive scenarios, a typical one being entering the multitasking screen. In such cases, some apps may need to pause a service that is currently interacting with the user, such as a video app pausing a playing video or a camera pausing the preview stream. When the app returns to the foreground from multitasking, it becomes interactive again, and the suspended business needs to be resumed, such as resuming video playback or the camera preview stream.

### How to Develop

After creating a **WindowStage** object, you can listen for the `'windowStageEvent'` event type to monitor events such as the window entering the foreground, background, foreground interactive, and foreground non-interactive states. The app can perform corresponding service processing based on these reported event states.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    try {
      windowStage.on('windowStageEvent', (data) => {
        console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
          JSON.stringify(data));

        // Select the corresponding processing based on the event state type.
        if (data == window.WindowStageEventType.SHOWN) {
          console.info('current window stage event is SHOWN');
          // The application enters the foreground and is in the interactive state by default.
          // ...
        } else if (data == window.WindowStageEventType.HIDDEN) {
          console.info('current window stage event is HIDDEN');
          // The application enters the background and is in the non-interactive state by default.
          // ...
        } else if (data == window.WindowStageEventType.PAUSED) {
          console.info('current window stage event is PAUSED');
          // The foreground app enters the multitasking view and switches to the non-interactive state.
          // ...
        } else if (data == window.WindowStageEventType.RESUMED) {
          console.info('current window stage event is RESUMED');
          // When returning to the foreground from the multitasking view, the interactive state is restored.
          // ...
        }

        // ...
      });
    } catch (exception) {
      console.error('Failed to enable the listener for window stage event changes. Cause:' +
        JSON.stringify(exception));
    }
  }
}
```