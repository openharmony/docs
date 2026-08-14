# Application Window Development (FA Model)

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=d92a834fa37fa220b93af036aac498daf001d662 translatedAt=2026-08-11T10:10:31.776Z pushedAt=2026-08-12T02:23:28.840Z -->

## Basic Concepts

Window immersive capability: the ability to control system windows such as the status bar and navigation bar, reducing the visual abruptness of these system UI elements to deliver an optimal user experience.

The immersive capability takes effect only when the main window of an application (app for short) is used as a full-screen window. Generally, auxiliary windows such as app subwindows, global floating windows, and modal windows, as well as the app main window in free window mode, cannot use the immersive capability.

> **NOTE**
>
> Currently, immersive UI development supports only window-level configuration, not page-level configuration. If page-level switching is required, you can set the immersive mode at the beginning of the page lifecycle, for example, in **onPageShow**, and then restore the default settings when the page exits, for example, in **onPageHide**.

## When to Use

In the FA model, typical scenarios for managing app windows include:

- Setting the subwindow attributes and target page of the app

- Experience window immersive capabilities.

The specific development methods are described below.

## APIs

The common APIs involved in the above scenarios are shown in the following table. For more API descriptions, see [@ohos.window (Window)](../reference/apis-arkui/arkts-apis-window.md).

| Instance Name | API Name | Description |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| window static method | createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | Creates a subwindow.<br>-`config`: used for creating the window. |
| window static method | findWindow(name: string): Window | Finds the window corresponding to `name`. |
| Window | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads specific page content for the window based on the path of a page in the current project.<br>Here, `path` is the path of the page content to be loaded into the window. In the FA model, this path must be added to the `config.json` file of the project. |
| Window | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves the current window position. |
| Window | setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | Sets the screen brightness value. |
| Window | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Changes the current window size. |
| Window | setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt; | Sets whether the layout of the main window or subwindow is an immersive layout. The value **true** indicates an immersive layout, and **false** indicates a non-immersive layout. |
| Window | setWindowSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | <!--RP1-->Sets the display modes for the status bar and the three‑button navigation bar of the main window.<!--RP1End--> The status bar is managed via the status setting, while the navigation bar is managed via the navigation setting. <br>For example, if this parameter is set to `['status',&nbsp;'navigation']`, all are shown; if set to `[]`, none are shown. |
| Window | setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt; | Sets the properties of the navigation bar and status bar within the window..<br>`systemBarProperties`: A collection of properties for the navigation bar and status bar. |
| Window | showWindow(callback: AsyncCallback\<void>): void | Shows the current window. |
| Window | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Enables listening for tap events outside the current window area. |
| Window | destroyWindow(callback: AsyncCallback\<void>): void | Destroys the current window. |

## Setting an App Subwindow

You can create app subwindows as needed, such as dialogs, and perform operations like setting their attributes.

> **NOTE**
> The following scenarios are not recommended for using subwindows. You are advised to prioritize using the control [overlay](../reference/apis-arkui/arkui-ts/ts-universal-attributes-overlay.md) capability.
> - On mobile devices (tablets in non-freeform mode and phones), subwindows cannot extend beyond the main window range when the main window is in multi-window floating window mode or split-screen mode, which is consistent with controls.
> - In split-screen window and freeform window modes, controls have a better real-time following capability than subwindows when the main window position and size change.
> - On some device platforms, due to actual system configuration restrictions, subwindows only have the system's default animation effects and rounded corner shadows, which apps cannot set, resulting in low flexibility.

### How to Develop

1. Create/obtain a subwindow object.

   - A subwindow can be created using the `window.createWindow` API.

     In the non-[freeform window](../windowmanager/window-terminology.md#freeform-window) state, a subwindow uses [immersive layout](../windowmanager/immersive-window-feature.md#immersive-layout) by default after creation.

     In the freeform window state, when the subwindow parameter [decorEnabled](../reference/apis-arkui/arkts-apis-window-i.md#configuration9) is set to **false**, the subwindow uses immersive layout after creation; when **decorEnabled** is set to **true**, the subwindow uses non-immersive layout after creation.

   - You can also use the `window.findWindow` API to locate an already created window and obtain the subwindow.

   ```ts
   import { window } from '@kit.ArkUI';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let windowClass: window.Window | null = null;
   // Method 1: Create a subwindow.
   let config: window.Configuration = { name: "subWindow", windowType: window.WindowType.TYPE_APP };
   window.createWindow(config, (err: BusinessError, data) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error(`Failed to create the subWindow. Code:${err.code}, message:${err.message}`);
       return;
     }
     console.info('Succeeded in creating subWindow. Data: ' + JSON.stringify(data));
     windowClass = data;
     if (!windowClass) {
      console.error('windowClass is null');
      return;
     }
   });
   // Method 2: Find the subwindow.
   try {
     windowClass = window.findWindow('subWindow');
   } catch (exception) {
     console.error('Failed to find the Window. Cause: ' + JSON.stringify(exception));
   }
   ```

2. Set subwindow attributes.

   After the subwindow is created, you can change its size, position, and other attributes, as well as set attributes such as the window background color and brightness based on the app's needs.

   ```ts
   // Move the subwindow position.
   windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in moving the window.');
   });
   // Change the subwindow size.
   windowClass.resize(500, 500, (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in changing the window size.');
   });
   ```

3. Load and display the specific content of the subwindow.

Load and display the specific content of the subwindow through the `setUIContent` and `showWindow` APIs.

   ```ts
   // Load the corresponding target page for the subwindow.
   windowClass.setUIContent("pages/page2", (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in loading the content.');
     if (!windowClass) {
       console.error('windowClass is null');
       return;
     }
     // Display the subwindow.
     windowClass.showWindow((err: BusinessError) => {
       let errCode: number = err.code;
       if (errCode) {
         console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in showing the window.');
     });
   });
   ```

4. Destroy the subwindow.

When a subwindow is no longer needed, you can destroy it using the **destroyWindow** API based on the scenario-specific implementation logic.

   ```ts
   // When a subwindow is no longer needed, destroy it using the destroyWindow API based on the scenario-specific implementation logic.
   windowClass.destroyWindow((err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to destroy the subwindow. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in destroying the subwindow.');
   });
   ```

## Immersive Window Experience

In scenarios such as watching videos or playing games, users often prefer to hide unnecessary system windows such as the status bar and navigation bar for a better immersive experience. The window immersive capability (which applies only to the main window) can be used to achieve this effect. Starting from API version 10, an immersive window is configured to full-screen size by default, with its layout controlled by the component module. The status bar and navigation bar backgrounds are transparent, and the text color is black. When the app window calls the `setWindowLayoutFullScreen` API, setting it to `true` means the component module controls an immersive full-screen layout that ignores the status bar and navigation bar, while setting it to `false` means the component module controls a non-immersive full-screen layout that avoids the status bar and navigation bar.

### How to Develop

1. Obtain the main window object.

   > **NOTE**
   >
   > The immersive capability requires that the main window object has been successfully obtained.
   >
   > Ensure that the last displayed window in the app is the main window, and then use the `window.getLastWindow` API to obtain the main window.

   ```ts
   import { window } from '@kit.ArkUI';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let mainWindowClass: window.Window | null = null;
   
   // Obtain the main window.
   class BaseContext {
     stageMode: boolean = false;
   }
   
   let context: BaseContext = { stageMode: false };
   window.getLastWindow(context, (err: BusinessError, data) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to get the mainWindow. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in getting mainWindow. Data: ' + JSON.stringify(data));
     mainWindowClass = data;
     if (!mainWindowClass) {
      console.error('mainWindowClass is null');
      return;
     }
   });
   ```

2. Implement the immersive effect. There are two approaches:

   - Approach 1: When the app main window is a full-screen window, call the `setWindowSystemBarEnable` API to set the navigation bar and status bar to be hidden, thereby achieving the immersive effect.

   - Approach 2: Call the `setWindowLayoutFullScreen` API to set the app main window to an immersive layout. Then call the `setWindowSystemBarProperties` API to configure attributes such as transparency, background/text colors, and highlighted icons for the navigation bar and status bar, keeping them consistent with the main window display to achieve the immersive effect.

   ```ts
   // Implement the immersive effect. Approach 1: Set the navigation bar and status bar to be hidden.
   let names: Array<'status' | 'navigation'> = [];
   mainWindowClass.setWindowSystemBarEnable(names)
    .then(() => {
      console.info('Succeeded in setting the system bar to be visible.');
    })
    .catch((err: BusinessError) => {
      console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
    });
   // Implement the immersive effect.
   // Method 2: Set the window to full-screen layout, and configure attributes such as the transparency, background/text color, and highlighted icons of the status bar and navigation bar to stay consistent with the main window display.
   let isLayoutFullScreen: boolean = true;
   mainWindowClass.setWindowLayoutFullScreen(isLayoutFullScreen)
    .then(() => {
      console.info('Succeeded in setting the window layout to full-screen mode.');
    })
    .catch((err: BusinessError) => {
      console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
    });
   let sysBarProps: window.SystemBarProperties = {
     statusBarColor: '#ff00ff',
     navigationBarColor: '#00ff00',
     // The following two attributes are supported since API version 8.
     statusBarContentColor: '#ffffff',
     navigationBarContentColor: '#ffffff'
   };
   mainWindowClass.setWindowSystemBarProperties(sysBarProps)
    .then(() => {
      console.info('Succeeded in setting the system bar properties.');
    })
    .catch((err: BusinessError) => {
      console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
    });
   ```

3. Load and display the specific content of the immersive window.

   Load and display the specific content of the immersive window through the `setUIContent` and `showWindow` APIs.

   ```ts
   // Load the corresponding target page for the immersive window.
   mainWindowClass.setUIContent("pages/page3", (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in loading the content.');
     if (!mainWindowClass) {
      console.error('mainWindowClass is null');
      return;
     }
     // Show the immersive window.
     mainWindowClass.showWindow((err: BusinessError) => {
       let errCode: number = err.code;
       if (errCode) {
         console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in showing the window.');
     });
   });
   ```