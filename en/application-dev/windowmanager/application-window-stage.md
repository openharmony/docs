# Application Window Development (Stage Mode)


## Basic Concepts

- Immersive window: System windows such as the status bar and navigation bar are controlled in such a way that they are unobtrusive on the entire screen, thereby engaging users more deeply with the content displayed.
  The immersive window feature is valid only when the main window of an application is displayed in full-screen mode. It does not apply to a main window in free window mode or a subwindow (for example, a dialog box or a floating window).

- Floating window: a special application window that can still be displayed in the foreground when the main window and corresponding ability are running the background.
  The floating window can be used to continue playing a video in a small window after the application returns to the background, or offer a quick entry (for example, bubbles) to a specific application. Before creating a floating window, an application must apply for the required permission.


## When to Use

In the stage model, you can perform the following operations during application window development:

- Setting the properties and content of the main window of an application

- Setting the properties and content of the subwindow of an application

- Experiencing the immersive window feature

- Setting a floating window


## Available APIs

The table below lists the common APIs used for application window development. For details about more APIs, see [Window](../reference/apis/js-apis-window.md).

| Instance| API| Description|
| -------- | -------- | -------- |
| WindowStage | getMainWindow(callback: AsyncCallback&lt;Window&gt;): void | Obtains the main window of this window stage.<br>This API can be used only in the stage model.|
| WindowStage | loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads the page content to the main window in this window stage.<br>This API can be used only in the stage model.|
| WindowStage | createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void | Creates a subwindow.<br>This API can be used only in the stage model.|
| Window static method| create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void | Creates a subwindow.<br>- **ctx**: application context.<br>- **type**: window type.|
| Window | loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads the page content to this window.|
| Window | setBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void | Sets the background color for this window.|
| Window | setBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | Sets the brightness for this window.|
| Window | setTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void | Sets whether this window is touchable.|
| Window | moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves this window.|
| Window | resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Changes the window size.|
| Window | setFullScreen(isFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void | Sets whether to enable the full-screen mode for this window.|
| Window | setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void | Sets whether to enable the full-screen mode for the window layout. |
| Window | setSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | Sets whether to display the status bar and navigation bar in this window.|
| Window | setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void | Sets the properties of the status bar and navigation bar in this window.<br>**systemBarProperties**: properties of the status bar and navigation bar.|
| Window | show(callback: AsyncCallback\<void>): void | Shows this window.|
| Window | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Enables listening for click events outside this window.|
| Window | destroy(callback: AsyncCallback&lt;void&gt;): void | Destroys this window.|


## Setting the Main Window of an Application

In the stage model, the main window of an application is created and maintained by an **Ability** instance. In the **onWindowStageCreate** callback of the **Ability** instance, use **WindowStage** to obtain the main window of the application and set its properties.


### How to Develop

1. Obtain the main window.

   Call **getMainWindow** to obtain the main window of the application.

2. Set the properties of the main window.

   You can set multiple properties of the main window, such as the background color, brightness, and whether the main window is touchable. The code snippet below uses the **touchable** property as an example.

3. Load content for the main window.

   Call **loadContent** to load the page content to the main window.

```ts
import Ability from '@ohos.application.Ability'

class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        // 1. Obtain the main window of the application.
        let windowClass = null;
        windowStage.getMainWindow((err, data) => {
            if (err.code) {
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
            // 2. Set the touchable property of the main window.
            let isTouchable = true;
            windowClass.setTouchable(isTouchable, (err, data) => {
                if (err.code) {
                    console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in setting the window to be touchable. Data:' + JSON.stringify(data));
            })
        })
        // 3. Load the page content to the main window.
        windowStage.loadContent("pages/page2", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }
};
```


## Setting a Subwindow of an Application

You can create an application subwindow, such as a dialog box, and set its properties.


### How to Develop

1. Create or obtain a subwindow.

   Call **createSubWindow** to create a subwindow.

   Call **getSubWindow** to obtain a subwindow.

2. Set the properties of the subwindow.

   After the subwindow is created, you can set its properties, such as the size, position, background color, and brightness.

3. Load content for the subwindow and show it.

   Call **loadContent** and **show** to load and display the content in the subwindow.

4. Destroy the subwindow.

   When the subwindow is no longer needed, you can call **destroy** to destroy it.

   ```ts
   import Ability from '@ohos.application.Ability'
   
   class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
           // 1. Create a subwindow.
           let sub_windowClass = null;
           windowStage.createSubWindow("mySubWindow", (err, data) => {
               if (err.code) {
                   console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
                   return;
               }
               sub_windowClass = data;
               console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
               // 1. Obtain an available subwindow.
               windowStage.getSubWindow((err, data) => {
                   if (err.code) {
                       console.error('Failed to obtain the subWindow. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in obtaining the subWindow. Data: ' + JSON.stringify(data));
                   sub_windowClass = data;
               });
               // 2. Set the position, size, and other properties of the subwindow.
               sub_windowClass.moveTo(300, 300, (err, data) => {
                   if (err.code) {
                       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in moving the window. Data: ' + JSON.stringify(data));
               });
               sub_windowClass.resetSize(500, 1000, (err, data) => {
                   if (err.code) {
                       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in changing the window size. Data: ' + JSON.stringify(data));
               });
               // 3. Load the page content to the subwindow.
               sub_windowClass.loadContent("pages/page3", (err, data) => {
                   if (err.code) {
                       console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
                   // 3. Show the subwindow.
                   sub_windowClass.show((err, data) => {
                       if (err.code) {
                           console.error('Failed to show the window. Cause:' + JSON.stringify(err));
                           return;
                       }
                       console.info('Succeeded in showing the window. Data: ' + JSON.stringify(data));
                   });
               });
               // 4. Destroy the subwindow when a click event outside the window is detected.
               sub_windowClass.on('touchOutside', () => {
                   console.info('touch outside');
                   sub_windowClass.destroy((err, data) => {
                       if (err.code) {
                           console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
                           return;
                       }
                       console.info('Succeeded in destroying the window. Data: ' + JSON.stringify(data));
                   });
               });
           })
       }
   };
   ```


## Experiencing the Immersive Window Feature

To create a better video watching and gaming experience, you can use the immersive window feature to hide the system windows, including the status bar and navigation bar. To achieve this effect, you can use the immersive window feature, which is available only for the main window of an application.


### How to Develop

1. Obtain the main window.

   Call **getMainWindow** to obtain the main window of the application.

2. Implement the immersive effect. You can use any of the following methods:
   - Method 1: Call **setFullScreen** to set the main window to be displayed in full screen. In this case, the navigation bar and status bar are hidden.
   - Method 2: Call **setSystemBarEnable** to hide the navigation bar and status bar.
   - Method 3: Call **setLayoutFullScreen** to enable the full-screen mode for the main window layout. Call **setSystemProperties** to set the opacity, background color, text color, and highlighted icon of the navigation bar and status bar to ensure that their display effect is consistent with that of the main window.

3. Load content for the immersive window and show it.

   Call **loadContent** to load the content to the immersive window.

   ```ts
   import Ability from '@ohos.application.Ability'
   
   class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
           // 1. Obtain the main window of the application.
           let windowClass = null;
           windowStage.getMainWindow((err, data) => {
               if (err.code) {
                   console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
                   return;
               }
               windowClass = data;
               console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
   
               // 2. Use method 1 to implement the immersive effect.
               let isFullScreen = true;
               windowClass.setFullScreen(isFullScreen, (err, data) => {
                   if (err.code) {
                       console.error('Failed to enable the full-screen mode. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
               });
               // 2. Use method 2 to implement the immersive effect.
               let names = [];
               windowClass.setSystemBarEnable(names, (err, data) => {
                   if (err.code) {
                       console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in setting the system bar to be visible. Data: ' + JSON.stringify(data));
               });
               // 2. Use method 3 to implement the immersive effect.
               let isLayoutFullScreen = true;
               windowClass.setLayoutFullScreen(isLayoutFullScreen, (err, data) => {
                   if (err.code) {
                       console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in setting the window layout to full-screen mode. Data: ' + JSON.stringify(data));
               });
               let sysBarProps = {
                   statusBarColor: '#ff00ff',
                   navigationBarColor: '#00ff00',
                   // The following properties are supported since API version 8.
                   statusBarContentColor: '#ffffff',
                   navigationBarContentColor: '#ffffff'
               };
               windowClass.setSystemBarProperties(sysBarProps, (err, data) => {
                   if (err.code) {
                       console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in setting the system bar properties. Data: ' + JSON.stringify(data));
               });
           })
           // 3. Load the page content to the immersive window.
           windowStage.loadContent("pages/page2", (err, data) => {
               if (err.code) {
                   console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                   return;
               }
               console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
           });
       }
   };
   ```


## Setting a Floating Window

A floating window is created based on an existing task. It is always displayed in the foreground, even if the task used for creating the floating window is switched to the background. You can create a floating window and set its properties.


### How to Develop

1. Apply for permissions.

   To create a floating window (of the **WindowType.TYPE_FLOAT** type), you must configure the **ohos.permission.SYSTEM_FLOAT_WINDOW** permission in the **requestPermissions** field of the **module.json5** file. For details about the file, see [Application Package Structure Configuration File](../quick-start/stage-structure.md).

   > **NOTE**
   >
   > If the task for creating the floating window is reclaimed by the system, the floating window will no longer be displayed. If you want the floating window to be displayed in such a case, apply for a [continuous task](../task-management/background-task-overview.md).

   ```json
   {
     "module": {
       "requestPermissions":[
         {
           "name" : "ohos.permission.SYSTEM_FLOAT_WINDOW",
           "usedScene": {
             "abilities": [
               "MainAbility"
             ],
             "when":"inuse"
           }
         }
       ]
     }
   }
   ```

2. Create a floating window.

   Call **window.create** to create a floating window.

3. Set properties for the floating window.

   After the floating window is created, you can set its properties, such as the size, position, background color, and brightness.

4. Load content for the floating window and show it.

   Call **loadContent** and **show** to load and display the content in the floating window.

5. Destroy the floating window.

   When the floating window is no longer needed, you can call **destroy** to destroy it.

   ```ts
   import Ability from '@ohos.application.Ability'
   import ExtensionContext from '@ohos.application.ServiceExtensionAbility';
   import window from '@ohos.window';
   
   class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
           // 2. Create a floating window.
           let windowClass = null;
           window.create(this.context, "floatWindow", window.WindowType.TYPE_FLOAT, (err, data) => {
               if (err.code) {
                   console.error('Failed to create the floatWindow. Cause: ' + JSON.stringify(err));
                   return;
               }
               console.info('Succeeded in creating the floatWindow. Data: ' + JSON.stringify(data));
               windowClass = data;
               // 3. Set the position, size, and properties of the floating window.
               windowClass.moveTo(300, 300, (err, data) => {
                   if (err.code) {
                       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in moving the window. Data: ' + JSON.stringify(data));
               });
               windowClass.resetSize(500, 1000, (err, data) => {
                   if (err.code) {
                       console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in changing the window size. Data: ' + JSON.stringify(data));
               });
               // 4. Load the page content to the floating window.
               windowClass.loadContent("pages/page4", (err, data) => {
                   if (err.code) {
                       console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                       return;
                   }
                   console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
                   // 4. Show the floating window.
                   windowClass.show((err, data) => {
                       if (err.code) {
                           console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
                           return;
                       }
                       console.info('Succeeded in showing the window. Data: ' + JSON.stringify(data));
                   });
               });
               // 5. Destroy the floating window when a click event outside the window is detected.
               windowClass.on('touchOutside', () => {
                   console.info('touch outside');
                   windowClass.destroy((err, data) => {
                       if (err.code) {
                           console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
                           return;
                       }
                       console.info('Succeeded in destroying the window. Data: ' + JSON.stringify(data));
                   });
               });
           });
       }
   };
   ```