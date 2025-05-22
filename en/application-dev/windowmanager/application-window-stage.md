# Application Window Development (Stage Model)


## Basic Concepts

- Immersive window: a window display mode where the system windows (generally the status bar and navigation bar) are hidden to allow users to fully engage with the content.

  The immersive window feature is applicable only to the main window of an application in full-screen mode. It does not apply to a main window in freeform window mode or a child window (for example, a dialog box or a floating window).

- Floating window: a special application window that can still be displayed in the foreground when the main window and corresponding ability are running in the background.
  
  The floating window can be used to continue playing a video after the application is switched to the background, or offer a quick entry (for example, bubbles) to the application. Before creating a floating window, an application must apply for the required permission.


## When to Use

In the stage model, you can perform the following operations during application window development:

- Setting the properties and content of the main window of an application

- Setting the properties and content of the child window of an application

- Experiencing the immersive window feature

- Setting a floating window

- Listening for interactive and non-interactive window events

## Available APIs

The table below lists the common APIs used for application window development. For details about more APIs, see [Window](../reference/apis-arkui/js-apis-window.md).

| Instance        | API                                                      | Description                                                        |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| WindowStage    | getMainWindow(callback: AsyncCallback&lt;Window&gt;): void   | Obtains the main window of this window stage.<br>This API can be used only in the stage model.|
| WindowStage    | loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads content to the main window in this window stage.<br>**path**: path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project.<br>This API can be used only in the stage model.|
| WindowStage    | createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void | Creates a child window.<br>This API can be used only in the stage model.            |
| WindowStage    | on(type: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void | Subscribes to window stage lifecycle change events.<br>This API can be used only in the stage model.|
| Window static method| createWindow(config: Configuration, callback: AsyncCallback\<Window>): void | Creates a child window or system window.<br>**config**: parameters used for creating the window.            |
| Window         | setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void | Loads the content of a page, with its path in the current project specified, to this window.<br>**path**: path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project in the stage model.                                    |
| Window         | setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void | Sets the brightness for this window.                                            |
| Window         | setWindowTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void | Sets whether this window is touchable.                                    |
| Window         | moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void | Moves this window.                                          |
| Window         | resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void | Changes the window size.                                          |
| Window         | setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt; | Sets whether to enable the full-screen mode for the window layout.                                 |
| Window         | setWindowSystemBarEnable(names: Array&lt;'status'\|'navigation'&gt;): Promise&lt;void&gt; | Sets whether to display the status bar and navigation bar in this window.                                |
| Window         | setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt; | Sets the properties of the status bar and navigation bar in this window.<br>**systemBarProperties**: properties of the status bar and navigation bar.|
| Window         | showWindow(callback: AsyncCallback\<void>): void             | Shows this window.                                              |
| Window         | on(type: 'touchOutside', callback: Callback&lt;void&gt;): void | Subscribes to touch events outside this window.                          |
| Window         | destroyWindow(callback: AsyncCallback&lt;void&gt;): void     | Destroys this window.                                              |


## Setting the Main Window of an Application

In the stage model, the main window of an application is created and maintained by a **UIAbility** instance. In the **onWindowStageCreate** callback of the **UIAbility** instance, use **WindowStage** to obtain the main window of the application and set its properties. You can also set the properties (for example, **maxWindowWidth**) in the [abilities tag of the module.json5 file](../quick-start/module-configuration-file.md#abilities).

### How to Develop

1. Obtain the main window.

   Call **getMainWindow** to obtain the main window of the application.

2. Set the properties of the main window.

   You can set multiple properties of the main window, such as the background color, brightness, and whether the main window is touchable. The code snippet below uses the **touchable** property as an example.

3. Load content to the main window.

   Call **loadContent** to load content to the main window.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 1. Obtain the main window of the application.
    let windowClass: window.Window | null = null;
    windowStage.getMainWindow((err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
        return;
      }
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
      // 2. Set the touchable property of the main window.
      let isTouchable: boolean = true;
      windowClass.setWindowTouchable(isTouchable, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in setting the window to be touchable.');
      })
    })
    // 3. Load content to the main window.
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

## Setting a Child Window of an Application

You can create an application child window, such as a dialog box, and set its properties.

> **NOTE**
>
> Due to the following limitations, using child windows is not recommended in mobile device scenarios. Instead, you are advised to use the [overlay](../reference/apis-arkui/arkui-ts/ts-universal-attributes-overlay.md) capability of components. 
> - Child windows on mobile devices are constrained within the main window's boundaries, mirroring the limitations of components. 
> - In split-screen or freeform window mode, components, when compared with child windows, offer better real-time adaptability to changes in the main window's position and size. 
> - On certain platforms, system configurations may restrict child windows to default system animations and rounded shadows, offering no customization options for applications and thereby limiting their versatility.

### How to Develop

1. Create a child window.

   Call **createSubWindow** to create a child window.

2. Set the properties of the child window.

   After the child window is created, you can set its properties, such as the size, position, background color, and brightness.

3. Load content to and show the child window.

   Call **setUIContent** to load content to the child window and **showWindow** to show the child window.

4. Destroy the child window.

   When the child window is no longer needed, you can call **destroyWindow** to destroy it.

The code snippet for creating a child window in **onWindowStageCreate** is as follows:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let windowStage_: window.WindowStage | null = null;
let sub_windowClass: window.Window | null = null;

export default class EntryAbility extends UIAbility {
  showSubWindow() {
    // 1. Create a child window.
    if (windowStage_ == null) {
      console.error('Failed to create the subwindow. Cause: windowStage_ is null');
    }
    else {
      windowStage_.createSubWindow("mySubWindow", (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
          return;
        }
        sub_windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        // 2. Set the position, size, and other properties of the child window.
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
        // 3.1 Load content to the child window.
        sub_windowClass.setUIContent("pages/page3", (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in loading the content.');
          // 3.2 Show the child window.
          (sub_windowClass as window.Window).showWindow((err: BusinessError) => {
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
    // 4. Destroy the child window when it is no longer needed (depending on the service logic).
    (sub_windowClass as window.Window).destroyWindow((err: BusinessError) => {
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
    // Create a child window when it is needed, for example, when a touch event occurs in the main window. Calling onWindowStageCreate is not always necessary. The code here is for reference only.
    this.showSubWindow();
  }

  onWindowStageDestroy() {
    // Destroy the child window when it is no longer needed, for example, when the Close button in the child window is touched. Calling onWindowStageDestroy is not always necessary. The code here is for reference only.
    this.destroySubWindow();
  }
};
```

You can also click a button on a page to create a child window. The code snippet is as follows:

```ts
// EntryAbility.ets
onWindowStageCreate(windowStage: window.WindowStage) {
  windowStage.loadContent('pages/Index', (err) => {
    if (err.code) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in loading the content.');
  })

  // Transfer the window stage to the Index page.
  AppStorage.setOrCreate('windowStage', windowStage);
}
```

```ts
// Index.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let windowStage_: window.WindowStage | undefined = undefined;
let sub_windowClass: window.Window | undefined = undefined;
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  private CreateSubWindow(){
    // Obtain the window stage.
    windowStage_ = AppStorage.get('windowStage');
    // 1. Create a child window.
    if (windowStage_ == null) {
      console.error('Failed to create the subwindow. Cause: windowStage_ is null');
    }
    else {
      windowStage_.createSubWindow("mySubWindow", (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
          return;
        }
        sub_windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        // 2. Set the position, size, and other properties of the child window.
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
        // 3. Load content to the child window.
        sub_windowClass.setUIContent("pages/subWindow", (err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in loading the content.');
          // 3. Show the child window.
          (sub_windowClass as window.Window).showWindow((err: BusinessError) => {
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
  private destroySubWindow(){
    // 4. Destroy the child window when it is no longer needed (depending on the service logic).
    (sub_windowClass as window.Window).destroyWindow((err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in destroying the window.');
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
          this.CreateSubWindow()
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

```ts
// subWindow.ets
@Entry
@Component
struct SubWindow {
  @State message: string = 'Hello subWindow';
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Experiencing the Immersive Window Feature

To create a better video watching and gaming experience, you can use the immersive window feature to hide the status bar and navigation bar. This feature is available only for the main window of an application. Since API version 10, the immersive window has the same size as the full screen by default; its layout is controlled by the component module; the background color of its status bar and navigation bar is transparent, and the text color is black. When an application window calls **setWindowLayoutFullScreen**, with **true** passed in, an immersive window layout is used. If **false** is passed in, a non-immersive window layout is used.

> **NOTE**
>
> Currently, immersive UI development supports window-level configuration, but not page-level configuration. If page redirection is required, you can set the immersive mode at the beginning of the page lifecycle, for example, in the **onPageShow** callback, and then restore the default settings when the page exits, for example, in the **onPageHide** callback.

### How to Develop

1. Obtain the main window.

   Call **getMainWindow** to obtain the main window of the application.

2. Implement the immersive effect. You can use either of the following methods:

   - Method 1: When the main window of the application is a full-screen window, call **setWindowSystemBarEnable** to hide the status bar and navigation bar.

   - Method 2: Call **setWindowLayoutFullScreen** to enable the full-screen mode for the main window layout. Call **setWindowSystemBarProperties** to set the opacity, background color, text color, and highlighted icon of the status bar and navigation bar to create a display effect consistent with that of the main window.

3. Load content to the immersive window.

   Call **loadContent** to load content to the immersive window.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 1. Obtain the main window of the application.
    let windowClass: window.Window | null = null;
    windowStage.getMainWindow((err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
        return;
      }
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));

      // 2. Implement the immersive effect by hiding the status bar and navigation bar.
      let names: Array<'status' | 'navigation'> = [];
      windowClass.setWindowSystemBarEnable(names)
        .then(() => {
          console.info('Succeeded in setting the system bar to be visible.');
        })
        .catch((err: BusinessError) => {
          console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
        });
      // 2. Alternatively, implement the immersive effect by setting the properties of the status bar and navigation bar.
      let isLayoutFullScreen = true;
      windowClass.setWindowLayoutFullScreen(isLayoutFullScreen)
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
      windowClass.setWindowSystemBarProperties(sysBarProps)
        .then(() => {
          console.info('Succeeded in setting the system bar properties.');
        })
        .catch((err: BusinessError) => {
          console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
        });
    })
    // 3. Load content to the immersive window.
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

<!--RP2-->
## Setting a Floating Window<!--RP2End-->

A floating window is created based on an existing task. It is always displayed in the foreground, even if the task used for creating the floating window is switched to the background. Generally, the floating window is above all application windows. You can create a floating window and set its properties.


### How to Develop

<!--RP1-->
**Prerequisites**: To create a floating window (a window of the type **WindowType.TYPE_FLOAT**), you must request the **ohos.permission.SYSTEM_FLOAT_WINDOW** permission. For details, see [Requesting Permissions for system_basic Applications](../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).
<!--RP1End-->

1. Create a floating window.

   Call **window.createWindow** to create a floating window.

2. Set properties of the floating window.

   After the floating window is created, you can set its properties, such as the size, position, background color, and brightness.

3. Load content to and show the floating window.

   Call **setUIContent** to load content to the floating window and **showWindow** to show the window.

4. Destroy the floating window.

   When the floating window is no longer needed, you can call **destroyWindow** to destroy it.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 1. Create a floating window.
    let windowClass: window.Window | null = null;
    let config: window.Configuration = {
      name: "floatWindow", windowType: window.WindowType.TYPE_FLOAT, ctx: this.context
    };
    window.createWindow(config, (err: BusinessError, data) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to create the floatWindow. Cause: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in creating the floatWindow. Data: ' + JSON.stringify(data));
      windowClass = data;
      // 2. Set the position, size, and other properties of the floating window.
      windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to move the window. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in moving the window.');
      });
      windowClass.resize(500, 500, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in changing the window size.');
      });
      // 3.1 Load content to the floating window.
      windowClass.setUIContent("pages/page4", (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in loading the content.');
        // 3.2 Show the floating window.
        (windowClass as window.Window).showWindow((err: BusinessError) => {
          let errCode: number = err.code;
          if (errCode) {
            console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in showing the window.');
        });
      });
      // 4. Destroy the floating window when it is no longer needed (depending on the service logic).
      windowClass.destroyWindow((err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in destroying the window.');
      });
    });
  }
};
```

## Listening for Interactive and Non-Interactive Window Events

When running in the foreground, an application may switch between interactive and non-interactive states and process services depending on the state. For example, when the user opens the **Recents** screen, an application becomes non-interactive and pauses the service interaction with the user, such as video playback or camera preview; when the user switched back to the foreground, the application becomes interactive again, and the paused service needs to be resumed.

### How to Develop

After a **WindowStage** object is created, the application can listen for the **'windowStageEvent'** event to obtain window stage lifecycle changes, for example, whether the window stage is interactive or non-interactive in the foreground. The application can process services based on the reported event status.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    try {
      windowStage.on('windowStageEvent', (data) => {
        console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
          JSON.stringify(data));

        // Process services based on the event status.
        if (data == window.WindowStageEventType.SHOWN) {
          console.info('current window stage event is SHOWN');
          // The application enters the foreground and is interactive by default.
          // ...
        } else if (data == window.WindowStageEventType.HIDDEN) {
          console.info('current window stage event is HIDDEN');
          // The application enters the background and is non-interactive by default.
          // ...
        } else if (data == window.WindowStageEventType.PAUSED) {
          console.info('current window stage event is PAUSED');
          // The user opens the Recents screen when the application is running in the foreground, and the application becomes non-interactive.
          // ...
        } else if (data == window.WindowStageEventType.RESUMED) {
          console.info('current window stage event is RESUMED');
          // The user switches back from the Recents screen to the application, and the application becomes interactive.
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
