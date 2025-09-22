# Functions
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { window } from '@kit.ArkUI';
```

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration, callback: AsyncCallback&lt;Window&gt;): void

Creates a child window or system window. This API uses an asynchronous callback to return the result.

In non-[freeform window](../../windowmanager/window-terminology.md#freeform-window) mode, the child window created uses an [immersive layout](../../windowmanager/window-terminology.md#immersive-layout) by default.

In freeform window mode, the child window created uses an immersive layout when [decorEnabled](arkts-apis-window-i.md#configuration9) is set to **false**, and it uses a non-immersive layout when this parameter is set to **true**.

**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW (required only when the window type is **window.WindowType.TYPE_FLOAT**.)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------------------- | -- | --------------------------------- |
| config   | [Configuration](arkts-apis-window-i.md#configuration9)       | Yes| Parameters used for creating the window.  |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | Yes| Callback used to return the window created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. createWindow can not work correctly due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300006 | This window context is abnormal. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    let windowClass: window.Window | undefined = undefined;
    let config: window.Configuration = {
      name: "test",
      windowType: window.WindowType.TYPE_DIALOG,
      ctx: this.context
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));
        windowClass.resize(500, 1000);
      });
    } catch (exception) {
      console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration): Promise&lt;Window&gt;

Creates a child window or system window. This API uses a promise to return the result.

In non-[freeform window](../../windowmanager/window-terminology.md#freeform-window) mode, the child window created uses an [immersive layout](../../windowmanager/window-terminology.md#immersive-layout) by default.

In freeform window mode, the child window created uses an immersive layout when [decorEnabled](arkts-apis-window-i.md#configuration9) is set to **false**, and it uses a non-immersive layout when this parameter is set to **true**.

**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW (required only when the window type is **window.WindowType.TYPE_FLOAT**.)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | -------------------------------- | -- | ------------------ |
| config | [Configuration](arkts-apis-window-i.md#configuration9) | Yes| Parameters used for creating the window.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------ |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the window created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. createWindow can not work correctly due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300006 | This window context is abnormal. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    let config: window.Configuration = {
      name: "test",
      windowType: window.WindowType.TYPE_DIALOG,
      ctx: this.context
    };
    try {
      window.createWindow(config).then((value:window.Window) => {
        console.info('Succeeded in creating the window. Data: ' + JSON.stringify(value));
        value.resize(500, 1000);
      }).catch((err:BusinessError)=> {
        console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## window.findWindow<sup>9+</sup>

findWindow(name: string): Window

Finds a window based on the name.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| name   | string | Yes  | Window name. When searching for a child window or system window, use the window name in [Configuration](arkts-apis-window-i.md#configuration9). When searching for the main window, use [getWindowName](arkts-apis-uicontext-uicontext.md#getwindowname12) to obtain the window name of the current instance.|

**Return value**

| Type| Description|
| ----------------- | ------------------- |
| [Window](arkts-apis-window-Window.md) | Window found. If the window with the specified name does not exist, an empty object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
let windowClass: window.Window | undefined = undefined;
try {
  windowClass = window.findWindow('test');
} catch (exception) {
  console.error(`Failed to find the Window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getLastWindow<sup>9+</sup>

getLastWindow(ctx: BaseContext, callback: AsyncCallback&lt;Window&gt;): void

Obtains the topmost layer child window of the current application. This API uses an asynchronous callback to return the result.

If no child window exists or the child window is not displayed by calling [showWindow()](arkts-apis-window-Window.md#showwindow9), the main window of the application is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------------------- | -- | ---------------------------------------- |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes| Current application context.|
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | Yes| Callback used to return the topmost layer window obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Top window or main window is null or destroyed.  |
| 1300006 | This window context is abnormal. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err: BusinessError) => {
      if (err.code) {
        console.error(`Failed to load content for main window. Cause code: ${err.code}, message: ${err.message}`);
      }
      windowStage.createSubWindow('TestSubWindow').then((subWindow) => {
        let storage: LocalStorage = new LocalStorage();
        subWindow.loadContent('pages/Index', storage, (err: BusinessError) => {
          if (err.code) {
            console.error(`Failed to load content for sub window. Cause code: ${err.code}, message: ${err.message}`);
          }
          subWindow.showWindow().then(() => {
            try {
              window.getLastWindow(this.context, (err: BusinessError, topWindow) => {
                const errCode: number = err.code;
                if (errCode) {
                  console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
                  return;
                }
                console.info(`Succeeded in obtaining the top window. Window id: ${topWindow.getWindowProperties().id}`);
              });
            } catch (exception) {
              console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`);
            }
          });
        });
      });
    });
  }
  //...
}
```

## window.getLastWindow<sup>9+</sup>

getLastWindow(ctx: BaseContext): Promise&lt;Window&gt;

Obtains the topmost layer child window of the current application. This API uses a promise to return the result.

If no child window exists or the child window is not displayed by calling [showWindow()](arkts-apis-window-Window.md#showwindow9), the main window of the application is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the topmost layer window obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Top window or main window is null or destroyed.   |
| 1300006 | This window context is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err: BusinessError) => {
      if (err.code) {
        console.error(`Failed to load content for main window. Cause code: ${err.code}, message: ${err.message}`);
      }
      windowStage.createSubWindow('TestSubWindow').then((subWindow) => {
        let storage: LocalStorage = new LocalStorage();
        subWindow.loadContent('pages/Index', storage, (err: BusinessError) => {
          if (err.code) {
            console.error(`Failed to load content for sub window. Cause code: ${err.code}, message: ${err.message}`);
          }
          subWindow.showWindow().then(() => {
            try {
              window.getLastWindow(this.context).then((topWindow) => {
                console.info(`Succeeded in obtaining the top window. Window id: ${topWindow.getWindowProperties().id}`);
              }).catch((err: BusinessError) => {
                console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
              });
            } catch (exception) {
              console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`);
            }
          });
        });
      });
    });
  }
  //...
}
```

## window.shiftAppWindowFocus<sup>11+</sup>
shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise&lt;void&gt;

Shifts the window focus from the source window to the target window in the same application. The window focus can be shifted within the main window and child windows.

Ensure that the target window can gain focus (configurable by calling [setWindowFocusable()](arkts-apis-window-Window.md#setwindowfocusable9)) and that [showWindow()](arkts-apis-window-Window.md#showwindow9) has been successfully executed.

> **NOTE**
>
> Before calling **shiftAppWindowFocus()**, ensure that the target window has called [loadContent()](arkts-apis-window-Window.md#loadcontent9) or [setUIContent()](arkts-apis-window-Window.md#setuicontent9) and these operations have been effective. Otherwise, an invisible window may gain focus, causing function exceptions or affecting user experience.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type  | Mandatory | Description                   |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | Yes   | ID of the source window, which is having the focus. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID.|
| targetWindowId | number | Yes   | ID of the target window. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| ------- | --------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // ...
    console.info('onWindowStageCreate');
    let mainWindow: window.Window | undefined = undefined;
    let subWindow: window.Window | undefined = undefined;
    let mainWindowId: number = -1;
    let subWindowId: number = -1;

    try {
      windowStage.loadContent('pages/Index', (err) => {
        if (err.code) {
          console.error(`Failed to load content for main window. Cause code: ${err.code}, message: ${err.message}`);
        }
        // Obtain the main window and ID of the application.
        windowStage.getMainWindow().then((data) => {
          if (data == null) {
            console.error('Failed to obtain the main window. Cause: The data is empty');
            return;
          }
          mainWindow = data;
          mainWindowId = mainWindow.getWindowProperties().id;
          console.info('Succeeded in obtaining the main window');
        }).catch((err: BusinessError) => {
          console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        });

        // Create or obtain a child window and its ID. In this case, the child window has focus.
        windowStage.createSubWindow('testSubWindow').then((data) => {
          if (data == null) {
            console.error('Failed to obtain the sub window. Cause: The data is empty');
            return;
          }
          subWindow = data;
          subWindowId = subWindow.getWindowProperties().id;
          subWindow.resize(500, 500);
          subWindow.showWindow();
          subWindow.setUIContent('pages/Index');

          // Listen for the window status and ensure that the window is ready.
          subWindow.on("windowEvent", (windowEvent) => {
            if (windowEvent == window.WindowEventType.WINDOW_ACTIVE) {
              // Switch the focus.
              window.shiftAppWindowFocus(subWindowId, mainWindowId).then(() => {
                console.info('Succeeded in shifting app window focus');
              }).catch((err: BusinessError) => {
                console.error(`Failed to shift app window focus. Cause code: ${err.code}, message: ${err.message}`);
              });
            }
          });
        });
      });
    } catch (exception) {
      console.error(`Failed to shift app focus. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## window.shiftAppWindowPointerEvent<sup>15+</sup>
shiftAppWindowPointerEvent(sourceWindowId: number, targetWindowId: number): Promise&lt;void&gt;

Transfers a mouse input event from one window to another within the same application. This API works only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode and takes effect only for the main window and its child windows. This API uses a promise to return the result.

To transfer mouse input events, the source window must call this API within the callback of the [onTouch](arkui-ts/ts-universal-events-touch.md#ontouch) event (the event type must be **TouchType.Down**). After a successful call, the system sends a **TouchType.Up** event to the source window and a **TouchType.Down** event to the target window.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name         | Type  | Mandatory | Description                   |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | Yes   | ID of the source window. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID.           |
| targetWindowId | number | Yes   | ID of the target window. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID.            |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| ------- | --------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**Example**

```ts
// ets/pages/Index.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
struct Index {
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Blue)
          .onTouch((event: TouchEvent) => {
            if (event.type === TouchType.Down) {
              try {
                let sourceWindowId = 1;
                let targetWindowId = 2;
                let promise = window.shiftAppWindowPointerEvent(sourceWindowId, targetWindowId);
                promise.then(() => {
                  console.info('Succeeded in shifting app window pointer event');
                }).catch((err: BusinessError) => {
                  console.error(`Failed to shift app window pointer event. Cause code: ${err.code}, message: ${err.message}`);
                });
              } catch (exception) {
                console.error(`Failed to shift app pointer event. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            }
          })
      }.width('100%')
    }.height('100%').width('100%')
  }
}
```

## window.shiftAppWindowTouchEvent<sup>20+</sup>
shiftAppWindowTouchEvent(sourceWindowId: number, targetWindowId: number, fingerId: number): Promise&lt;void&gt;

Transfers a touchscreen input event from one window to another within the same application. This API works only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode and takes effect only for the main window and its child windows. This API uses a promise to return the result.

To transfer touchscreen input events, the source window must call this API within the callback of the [onTouch](arkui-ts/ts-universal-events-touch.md#ontouch) event (the event type must be **TouchType.Down**). After a successful call, the system sends a **TouchType.Up** event to the source window and a **TouchType.Down** event to the target window.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name         | Type  | Mandatory | Description                   |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | Yes   | ID of the source window. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID. The value must be an integer greater than 0. If it is less than or equal to 0, error code 1300016 is returned.           |
| targetWindowId | number | Yes   | ID of the target window. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID. The value must be an integer greater than 0. If it is less than or equal to 0, error code 1300016 is returned.            |
| fingerId | number | Yes   | Unique ID of the finger in the touchscreen input event. You are advised to use the **touches** attribute in the [TouchEvent](arkui-ts/ts-universal-events-touch.md#touchevent) object to obtain the ID. This parameter must be an integer greater than or equal to 0. If the value is less than 0, error code 1300016 is returned.            |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| ------- | --------------------------------------------- |
| 801     | Capability not supported. Function shiftAppWindowTouchEvent can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range.|

**Example**

```ts
// ets/pages/Index.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
struct Index {
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Blue)
          .onTouch((event: TouchEvent) => {
            // The source window touch event type must be TouchType.Down.
            if (event.type === TouchType.Down) {
              try {
                let sourceWindowId = 1;
                let targetWindowId = 2;
                let promise = window.shiftAppWindowTouchEvent(sourceWindowId, targetWindowId, event.touches[0].id);
                promise.then(() => {
                  console.info(`Succeeded in shifting app window touch event`);
                }).catch((err: BusinessError) => {
                  console.error(`Failed to shift app window touch event. Cause code: ${err.code}, message: ${err.message}`);
                });
              } catch (exception) {
                console.error(`Failed to shift app touch event. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            }
          })
      }.width('100%')
    }.height('100%').width('100%')
  }
}
```

## window.getWindowsByCoordinate<sup>14+</sup>

getWindowsByCoordinate(displayId: number, windowNumber?: number, x?: number, y?: number): Promise&lt;Array&lt;Window&gt;&gt;

Obtains visible windows at the specified coordinates within the current application, sorted by their current layer order. The window at the topmost layer corresponds to index 0 of the array. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type  | Mandatory| Description                                                                       |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| displayId   | number| Yes | ID of the display where the windows are located. The value must be an integer. If a non-integer is passed, the decimal part is ignored. The value can be obtained from [WindowProperties](arkts-apis-window-i.md#windowproperties).|
| windowNumber    | number| No | Number of windows to obtain. The value must be an integer greater than 0. If a non-integer is passed, the decimal part is ignored. If this parameter is not set or is less than or equal to 0, all windows that meet the conditions are returned.                                 |
| x    | number | No | X coordinate, with the top-left corner of the screen used as the origin. The value must be a non-negative integer. If a non-integer is passed, the decimal part is ignored. If this parameter is not set or is less than 0, all visible windows are returned.                                        |
| y    | number| No | Y coordinate, with the top-left corner of the screen used as the origin. The value must be a non-negative integer. If a non-integer is passed, the decimal part is ignored. If this parameter is not set or is less than 0, all visible windows are returned.                                        |

**Return value**

| Type                            | Description                     |
| -------------------------------- |-------------------------|
| Promise&lt;Array&lt;[Window](arkts-apis-window-Window.md)&gt;&gt; | Promise used to return an array of window objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID   | Error Message|
|----------| ------------------------------ |
| 401      | Parameter error. Possible cause: Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let displayId = 0;
  window.getWindowsByCoordinate(displayId).then((data) => {
    console.info(`Succeeded in getting windows. Data: ${data}`);
    for (let window of data) {
      // do something with window
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get window from point. Cause code: ${err.code}, message: ${err.message}`);
  });
  window.getWindowsByCoordinate(displayId, 2, 500, 500).then((data) => {
    console.info(`Succeeded in getting windows. Data: ${data}`);
    for (let window of data) {
      // do something with window
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to get window from point. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to get window from point. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getAllWindowLayoutInfo<sup>15+</sup>

getAllWindowLayoutInfo(displayId: number): Promise&lt;Array&lt;WindowLayoutInfo&gt;&gt;

Obtains the layout information array of all windows visible on a display. The layout information is arranged based on the current window stacking order, and the topmost window in the hierarchy is at index 0 of the array. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type  | Mandatory| Description                                                                       |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| displayId   | number| Yes | ID of the display where the windows are located. The value must be an integer and can be obtained from [WindowProperties](arkts-apis-window-i.md#windowproperties).|

**Return value**

| Type                            | Description                     |
| -------------------------------- |-------------------------|
| Promise&lt;Array&lt;[WindowLayoutInfo](arkts-apis-window-i.md#windowlayoutinfo15)&gt;&gt; | Promise used to return an array of window layout information objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID   | Error Message|
|----------| ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported. function getAllWindowLayoutInfo can not work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let displayId = 0;
  let promise = window.getAllWindowLayoutInfo(displayId);
  promise.then((data) => {
    console.info('Succeeded in obtaining all window layout info. Data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain all window layout info. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to obtain all window layout info. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getVisibleWindowInfo<sup>18+</sup>

getVisibleWindowInfo(): Promise&lt;Array&lt;WindowInfo&gt;&gt;

Obtains information about visible main windows on the current screen. Visible main windows are main windows that are not returned to the background. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Required permissions**: ohos.permission.VISIBLE_WINDOW_INFO

**Return value**

| Type| Description|
| ------------------- | ----------------------- |
| Promise&lt;Array&lt;[WindowInfo](arkts-apis-window-i.md#windowinfo18)&gt;&gt; | Promise used to return the information about visible windows.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 801     | Capability not supported. Function getVisibleWindowInfo can not work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = window.getVisibleWindowInfo();
  promise.then((data) => {
    data.forEach(windowInfo=>{
      console.info(`left:${windowInfo.rect.left}`);
      console.info(`top:${windowInfo.rect.top}`);
      console.info(`width:${windowInfo.rect.width}`);
      console.info(`height:${windowInfo.rect.height}`);
      console.info(`windowId:${windowInfo.windowId}`);
      console.info(`windowStatusType:${windowInfo.windowStatusType}`);
      console.info(`abilityName:${windowInfo.abilityName}`);
      console.info(`bundleName:${windowInfo.bundleName}`);
      console.info(`isFocused:${windowInfo.isFocused}`);
    })
  }).catch((err: BusinessError) => {
    console.error('Failed to getWindowInfo. Cause: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error(`Failed to get visible window info. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getGlobalWindowMode<sup>20+</sup>

getGlobalWindowMode(displayId?: number): Promise&lt;number&gt;

Obtains the window mode of the window that is in the foreground lifecycle on the specified screen. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type      | Mandatory                | Description                                                                             |
| ------ | ---------- |--------------------|------------------------------------------------------------------------------------|
| displayId   | number| No | Optional display ID, which is used to obtain the window mode information on the corresponding screen. This parameter must be an integer greater than or equal to 0. If it is less than 0, error code 1300016 is returned. If this parameter is not passed or is set to null or undefined, all screens are queried. If a non-integer is passed, the decimal part is ignored. If the specified screen does not exist, the return value is 0. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the display ID of the window.                                                   |

**Return value**

| Type                            | Description                     |
| -------------------------------- |-------------------------|
| Promise&lt;number&gt; | Promise used to return the window mode. Each binary bit represents a window mode. For details about the supported window modes, see [GlobalWindowMode](arkts-apis-window-e.md#globalwindowmode20). The return value is the result of a bitwise OR operation on the corresponding window mode values. For example, if there are full-screen, floating, and PiP windows on the specified screen, the return value is `0b1\|0b100\|0b1000 = 13`.| | |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID   | Error Message|
|----------| ------------------------------ |
| 801      | Capability not supported. function getGlobalWindowMode can not work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**Example**
```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let displayId = 0;
  let promise = window.getGlobalWindowMode(displayId);
  promise.then((data) => {
    console.info(`Succeeded in obtaining global window mode. Data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain global window mode. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to obtain global window mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setWatermarkImageForAppWindows<sup>21+</sup>

setWatermarkImageForAppWindows(pixelMap: image.PixelMap | undefined): Promise&lt;void&gt;

Sets a watermark image for windows in the current application process. This API uses a promise to return the result. This API must be called after [loadContent()](arkts-apis-window-Window.md#loadcontent9) or [setUIContent()](arkts-apis-window-Window.md#setuicontent9) takes effect.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                                                         | Mandatory| Description                                                                                                          |
| -------- | ----------------------------------------------------------------------------- | ---- | -------------------------------------------------------------------------------------------------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) \| undefined | Yes  | If this parameter is set to **image.PixelMap**, a watermark image is set. If this parameter is set to **undefined**, the watermark is removed.<br>If the width and height of the image both surpass the window and screen sizes, error code 1300016 is returned.<br>If the width or height of the image goes beyond the window dimensions, the excess part is trimmed.<br>If the width or height of the image falls short of the window dimensions, the shortfall is automatically repeated to complete the image.|

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                                                                                                 |
| --------- | ------------------------------------------------------------------------------------------------------------------------- |
| 801       | Capability not supported. Function setWatermarkImageForAppWindows can not work correctly due to limited device capabilities. |
| 1300003   | This window manager service works abnormally.                                                                             |
| 1300016   | Parameter error. Possible cause: 1. Invalid parameter range.                                                              |

**Example**

```ts
import { image } from "@kit.ImageKit";
import { BusinessError } from "@kit.BasicServicesKit";

let color: ArrayBuffer = new ArrayBuffer(96);
let initializationOptions: image.InitializationOptions = {
  editable: true,
  pixelFormat: image.PixelMapFormat.RGBA_8888,
  size: {
    height: 4,
    width: 6,
  },
};
image.createPixelMap(color, initializationOptions).then((pixelMap: image.PixelMap) => {
  console.info("Succeeded in creating pixelmap.");
  try {
    let promise = window.setWatermarkImageForAppWindows(pixelMap);
    promise.then(() => {
        console.info("Succeeded in setting watermark image.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to set watermark image. Cause code: ${err.code}, message: ${err.message}`);
    });
  } catch (exception) {
    console.error(`Failed to set watermark image. Exception code: ${exception.code}, message: ${exception.message}`);
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to create PixelMap. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.setStartWindowBackgroundColor<sup>20+</sup>

setStartWindowBackgroundColor(moduleName: string, abilityName: string, color: ColorMetrics): Promise&lt;void&gt;

Sets the background color of the splash screen of the UIAbility based on the specified module name and ability name within the same bundle name. This API uses a promise to return the result.

This API takes effect for all processes of the same bundle name, for example, in multi-instance or clone scenarios.

**Atomic service API**: This API can be used in atomic services since API version 20.
 
**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                         | Mandatory| Description                                                    |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| moduleName     | string                        | Yes  | Module name of the UIAbility. The value is a string of 0 to 200 bytes. Only the module names within the same application can be set. The module name is specified in the **name** field of the [module.json5 file](../../quick-start/module-configuration-file.md#tags-in-the-configuration-file).|
| abilityName     | string                        | Yes  | Name of the UIAbility. The value is a string of 0 to 200 bytes. Only the ability names within the same application can be set. The UIAbility name is specified in the **name** field under [abilities in the module.json5 file](../../quick-start/module-configuration-file.md#abilities).|
| color | [ColorMetrics](js-apis-arkui-graphics.md#colormetrics12) | Yes  | Background color of the splash screen.                      |

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported.function setStartWindowBackgroundColor can not to work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics, window } from '@kit.ArkUI';

try {
  let promise = window.setStartWindowBackgroundColor("entry", "EntryAbility", ColorMetrics.numeric(0xff000000));
  promise.then(() => {
    console.log('Succeeded in setting the starting window color.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the starting window color. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the starting window color. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.create<sup>(deprecated)</sup>

create(id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Creates a child window. This API uses an asynchronous callback to return the result.

The child window created uses an [immersive layout](../../windowmanager/window-terminology.md#immersive-layout) by default.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | Yes  | Window name, that is, the value of name in [Configuration](arkts-apis-window-i.md#configuration9).|
| type     | [WindowType](arkts-apis-window-e.md#windowtype7)              | Yes  | Window type.                          |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | Yes  | Callback used to return the child window created.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
window.create('test', window.WindowType.TYPE_APP, (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to create the subWindow. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  windowClass = data;
  console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));
});
```

## window.create<sup>(deprecated)</sup>

create(id: string, type: WindowType): Promise&lt;Window&gt;

Creates a child window. This API uses a promise to return the result.

The child window created uses an [immersive layout](../../windowmanager/window-terminology.md#immersive-layout) by default.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9-1) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| id     | string                    | Yes  | Window name, that is, the value of name in [Configuration](arkts-apis-window-i.md#configuration9).  |
| type   | [WindowType](arkts-apis-window-e.md#windowtype7) | Yes  | Window type.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the child window created.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let promise = window.create('test', window.WindowType.TYPE_APP);
promise.then((data) => {
  windowClass = data;
  console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to create the subWindow. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.create<sup>(deprecated)</sup>

create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Creates a system window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------ |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.                |
| id       | string                                                  | Yes  | Window name, that is, the value of name in [Configuration](arkts-apis-window-i.md#configuration9).  |
| type     | [WindowType](arkts-apis-window-e.md#windowtype7)                              | Yes  | Window type.                          |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt;                  | Yes  | Callback used to return the child window created.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
window.create(globalThis.getContext(), 'test', window.WindowType.TYPE_SYSTEM_ALERT, (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  windowClass = data;
  console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));
  windowClass.resetSize(500, 1000);
});
```

## window.create<sup>(deprecated)</sup>

create(ctx: BaseContext, id: string, type: WindowType): Promise&lt;Window&gt;

Creates a system window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.|
| id     | string                    | Yes  | Window name, that is, the value of name in [Configuration](arkts-apis-window-i.md#configuration9).|
| type   | [WindowType](arkts-apis-window-e.md#windowtype7) | Yes  | Window type.                                                  |

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the child window created.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let promise = window.create(globalThis.getContext(), 'test', window.WindowType.TYPE_SYSTEM_ALERT);
promise.then((data) => {
  windowClass = data;
  console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to create the Window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.find<sup>(deprecated)</sup>

find(id: string, callback: AsyncCallback&lt;Window&gt;): void

Finds a window based on the ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [findWindow()](#windowfindwindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | Yes  | Window name, that is, the value of name in [Configuration](arkts-apis-window-i.md#configuration9).|
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | Yes  | Callback used to return the window found.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
window.find('test', (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to find the Window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  windowClass = data;
  console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));
});
```

## window.find<sup>(deprecated)</sup>

find(id: string): Promise&lt;Window&gt;

Finds a window based on the ID. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [findWindow()](#windowfindwindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| id     | string | Yes  | Window name, that is, the value of name in [Configuration](arkts-apis-window-i.md#configuration9).|

**Return value**

| Type                            | Description                                 |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the window found.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let promise = window.find('test');
promise.then((data) => {
  windowClass = data;
  console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to find the Window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.getTopWindow<sup>(deprecated)</sup>

getTopWindow(callback: AsyncCallback&lt;Window&gt;): void

Obtains the top window of the current application. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getLastWindow()](#windowgetlastwindow9) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                        |
| -------- | -------------------------------------- | ---- | -------------------------------------------- |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | Yes  | Callback used to return the top window obtained.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
window.getTopWindow((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  windowClass = data;
  console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
});
```

## window.getTopWindow<sup>(deprecated)</sup>

getTopWindow(): Promise&lt;Window&gt;

Obtains the top window of the current application. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getLastWindow()](#windowgetlastwindow9-1) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                            | Description                                           |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the top window obtained.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let promise = window.getTopWindow();
promise.then((data)=> {
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError)=>{
    console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.getTopWindow<sup>(deprecated)</sup>

getTopWindow(ctx: BaseContext, callback: AsyncCallback&lt;Window&gt;): void

Obtains the top window of the current application. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getLastWindow()](#windowgetlastwindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)                            | Yes  | Current application context.|
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | Yes  | Callback used to return the top window obtained.                |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage:window.WindowStage){
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      window.getTopWindow(this.context, (err: BusinessError, data) => {
        const errCode: number = err.code;
        if(errCode){
          console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
          return ;
        }
        windowClass = data;
        console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
      });
    } catch(error){
      console.error(`Failed to obtain the top window. Cause code: ${error.code}, message: ${error.message}`);
    }
  }
}
```

## window.getTopWindow<sup>(deprecated)</sup>

getTopWindow(ctx: BaseContext): Promise&lt;Window&gt;

Obtains the top window of the current application. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getLastWindow()](#windowgetlastwindow9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.|

**Return value**

| Type                            | Description                                           |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the top window obtained.|

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage:window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    let promise = window.getTopWindow(this.context);
    promise.then((data) => {
      windowClass = data;
      console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
    }).catch((error: BusinessError) => {
      console.error(`Failed to obtain the top window. Cause code: ${error.code}, message: ${error.message}`);
    });
  }
}
```
