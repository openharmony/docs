# Application Window Development (FA Model)

## Basic Concepts

Immersive window: a window display mode where the system windows (generally the status bar and navigation bar) are hidden to allow users to fully engage with the content.

The immersive window feature is applicable only to the main window of an application in full-screen mode. It does not apply to a main window in any other mode or a child window (for example, a dialog box or a floating window).

> **NOTE**
>
> Currently, immersive UI development supports window-level configuration, but not page-level configuration. If page redirection is required, you can set the immersive mode at the beginning of the page lifecycle, for example, in the **onPageShow** callback, and then restore the default settings when the page exits, for example, in the **onPageHide** callback.

## When to Use

In the FA model, you can perform the following operations during application window development:

- Setting the properties and content of the child window of an application

- Experiencing the immersive window feature

## Available APIs

The table below lists the common APIs used for application window development. For details about more APIs, see [Window](../reference/apis-arkui/arkts-apis-window.md).

| Instance        | API                                                      | Description                                                        |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Window static method| createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | Creates a child window.<br>**config**: parameters used for creating the window.              |
| Window static method| findWindow(name: string): Window                             | Finds a window based on the name.                                    |
| Window         | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads the content of a page, with its path in the current project specified, to this window.<br>**path**: path of the page from which the content will be loaded. The path is configured in the **config.json** file of the project in the FA model.                                |
| Window         | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves this window.                                              |
| Window         | setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | Sets the brightness for this window.                                            |
| Window         | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Changes the window size.                                          |
| Window         | setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt; | Sets whether to enable the full-screen mode for the window layout.                                 |
| Window         | setWindowSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | Sets whether to display the status bar and navigation bar in this window.                                |
| Window         | setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt; | Sets the properties of the status bar and navigation bar in this window.<br>**systemBarProperties**: properties of the status bar and navigation bar.|
| Window         | showWindow(callback: AsyncCallback\<void>): void             | Shows this window.                                              |
| Window         | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Enables listening for touch events outside this window.                          |
| Window         | destroyWindow(callback: AsyncCallback&lt;void&gt;): void     | Destroys this window.                                              |


## Setting the Child Window of an Application

You can create a child window, such as a dialog box, and set its properties.

> **NOTE**
>
> In the following scenarios, you are not advised to use child windows. Instead, consider using the [overlay](../reference/apis-arkui/arkui-ts/ts-universal-attributes-overlay.md) capability of components first. 
> - On mobile devices (tablets in non-freeform mode and phones), child windows cannot extend beyond the boundaries of the main window when it is in floating or split-screen mode, just like components. 
> - In split-screen or freeform window mode, components, when compared with child windows, offer better real-time adaptability to changes in the main window's position and size. 
> - On certain platforms, system configurations may restrict child windows to default system animations and rounded shadows, offering no customization options for applications and thereby limiting their versatility.

### How to Develop

1. Create or obtain a child window.

   - Call **window.createWindow** to create a child window.
   - Call **window.findWindow** to find an available child window.

   ```ts
   import { window } from '@kit.ArkUI';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let windowClass: window.Window | null = null;
   // Method 1: Create a child window.
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
   // Method 2: Find a child window.
   try {
     windowClass = window.findWindow('subWindow');
   } catch (exception) {
     console.error('Failed to find the Window. Cause: ' + JSON.stringify(exception));
   }
   ```

2. Set the properties of the child window.

   After the child window is created, you can set its properties, such as the size, position, background color, and brightness.

   ```ts
   // Move the child window.
   windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in moving the window.');
   });
   // Change the size of the child window.
   windowClass.resize(500, 500, (err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in changing the window size.');
   });
   ```

3. Load content to and show the child window.

   Call **setUIContent** to load content to the child window and **showWindow** to show the child window.

   ```ts
   // Load content to the child window.
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
     // Show the child window.
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

4. Destroy the child window.

   When the child window is no longer needed, you can call **destroyWindow** to destroy it.

   ```ts
   // Call destroy() to destroy the child window when it is no longer needed.
   windowClass.destroyWindow((err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to destroy the subwindow. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in destroying the subwindow.');
   });
   ```

## Experiencing the Immersive Window Feature

To create a better video watching and gaming experience, you can use the immersive window feature to hide the status bar and navigation bar. This feature is available only for the main window of an application. Since API version 10, the immersive window has the same size as the full screen by default; its layout is controlled by the component module; the background color of its status bar and navigation bar is transparent, and the text color is black. When an application window calls **setWindowLayoutFullScreen**, with **true** passed in, an immersive window layout is used. If **false** is passed in, a non-immersive window layout is used.


### How to Develop

1. Obtain the main window.

   > **NOTE**
   >
   > The immersive window feature can be implemented only after the main window is obtained.
   >
   > Ensure that the top window of the application is the main window. You can use **window.getLastWindow** to obtain the main window.

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

2. Implement the immersive effect. You can use either of the following methods:

   - Method 1: When the main window of the application is a full-screen window, call **setWindowSystemBarEnable** to hide the status bar and navigation bar.
   - Method 2: Call **setWindowLayoutFullScreen** to enable the full-screen mode for the main window layout. Call **setWindowSystemBarProperties** to set the opacity, background color, text color, and highlighted icon of the status bar and navigation bar to create a display effect consistent with that of the main window.

   ```ts
   // Implement the immersive effect by hiding the status bar and navigation bar.
   let names: Array<'status' | 'navigation'> = [];
   mainWindowClass.setWindowSystemBarEnable(names)
    .then(() => {
      console.info('Succeeded in setting the system bar to be visible.');
    })
    .catch((err: BusinessError) => {
      console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
    });
   // Implement the immersive effect by setting the properties of the status bar and navigation bar.
    
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
     // The following properties are supported since API version 8.
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

3. Load content to and show the immersive window.

   Call **setUIContent** to load content to the immersive window and **showWindow** to show the window.

   ```ts
   // Load content to the immersive window.
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
