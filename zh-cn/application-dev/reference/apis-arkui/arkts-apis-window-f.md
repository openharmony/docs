# Functions
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { window } from '@kit.ArkUI';
```

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration, callback: AsyncCallback&lt;Window&gt;): void

创建子窗口或者系统窗口，使用callback异步回调。

非[自由窗口](../../windowmanager/window-terminology.md#自由窗口)状态下，子窗口创建后默认是[沉浸式布局](../../windowmanager/window-terminology.md#沉浸式布局)。

自由窗口状态下，子窗口参数[decorEnabled](arkts-apis-window-i.md#configuration9)为false时，子窗口创建后为沉浸式布局；子窗口参数decorEnabled为true，子窗口创建后为非沉浸式布局。

**需要权限：** ohos.permission.SYSTEM_FLOAT_WINDOW（仅当创建窗口类型为window.WindowType.TYPE_FLOAT时需要申请）

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------------------------------------- | -- | --------------------------------- |
| config   | [Configuration](arkts-apis-window-i.md#configuration9)       | 是 | 创建窗口时的参数。   |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | 是 | 回调函数。返回当前创建的窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. createWindow can not work correctly due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300006 | This window context is abnormal. |
| 1300009 | The parent window is invalid. |

**示例：**

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

创建子窗口或者系统窗口，使用Promise异步回调。

非[自由窗口](../../windowmanager/window-terminology.md#自由窗口)状态下，子窗口创建后默认是[沉浸式布局](../../windowmanager/window-terminology.md#沉浸式布局)。

自由窗口状态下，子窗口参数[decorEnabled](arkts-apis-window-i.md#configuration9)为false时，子窗口创建后为沉浸式布局；子窗口参数decorEnabled为true，子窗口创建后为非沉浸式布局。

**需要权限：** ohos.permission.SYSTEM_FLOAT_WINDOW（仅当创建窗口类型为window.WindowType.TYPE_FLOAT时需要申请）

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | -------------------------------- | -- | ------------------ |
| config | [Configuration](arkts-apis-window-i.md#configuration9) | 是 | 创建窗口时的参数。 |

**返回值：**

| 类型 | 说明 |
| -------------------------------- | ------------------------------------ |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前创建的窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. createWindow can not work correctly due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300006 | This window context is abnormal. |
| 1300009 | The parent window is invalid. |

**示例：**

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

查找name所对应的窗口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| name   | string | 是   | 窗口名字，即[Configuration](arkts-apis-window-i.md#configuration9)中的name。 |

**返回值：**

| 类型 | 说明 |
| ----------------- | ------------------- |
| [Window](arkts-apis-window-Window.md) | 当前查找的窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**示例：**

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

获取当前应用内最上层显示的子窗口，使用callback异步回调。

若无应用子窗口或子窗口未调用[showWindow()](arkts-apis-window-Window.md#showwindow9)进行显示，则返回应用主窗口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------------------------------------- | -- | ---------------------------------------- |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 当前应用上下文信息。 |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | 是 | 回调函数。返回当前应用内最上层的窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Top window or main window is null or destroyed.  |
| 1300006 | This window context is abnormal. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.createSubWindow('TestSubWindow').then((subWindow) => {
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
  }
  //...
}
```

## window.getLastWindow<sup>9+</sup>

getLastWindow(ctx: BaseContext): Promise&lt;Window&gt;

获取当前应用内最上层显示的子窗口，使用Promise异步回调。

若无应用子窗口或子窗口未调用[showWindow()](arkts-apis-window-Window.md#showwindow9)进行显示，则返回应用主窗口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用上下文信息。 |

**返回值：**

| 类型 | 说明 |
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前应用内最上层的窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Top window or main window is null or destroyed.   |
| 1300006 | This window context is abnormal. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.createSubWindow('TestSubWindow').then((subWindow) => {
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
  }
  //...
}
```

## window.shiftAppWindowFocus<sup>11+</sup>
shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise&lt;void&gt;

在同应用内将窗口焦点从源窗口转移到目标窗口，仅支持应用主窗和子窗的焦点转移。

目标窗口需确保可获焦属性为true（见[setWindowFocusable()](arkts-apis-window-Window.md#setwindowfocusable9)）,并确保调用[showWindow()](arkts-apis-window-Window.md#showwindow9)成功并执行完毕。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名          | 类型   | 必填  | 说明                    |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | 是    | 源窗口id，必须是获焦状态。|
| targetWindowId | number | 是    | 目标窗口id。             |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| ------- | --------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**示例：**

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
      // 获取应用主窗及ID
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

      // 创建或获取子窗及ID，此时子窗口获焦
      windowStage.createSubWindow('testSubWindow').then((data) => {
        if (data == null) {
          console.error('Failed to obtain the sub window. Cause: The data is empty');
          return;
        }
        subWindow = data;
        subWindowId = subWindow.getWindowProperties().id;
        subWindow.resize(500, 500);
        subWindow.showWindow();

        // 监听Window状态，确保已经就绪
        subWindow.on("windowEvent", (windowEvent) => {
          if (windowEvent == window.WindowEventType.WINDOW_ACTIVE) {
            // 切换焦点
            window.shiftAppWindowFocus(subWindowId, mainWindowId).then(() => {
              console.info('Succeeded in shifting app window focus');
            }).catch((err: BusinessError) => {
              console.error(`Failed to shift app window focus. Cause code: ${err.code}, message: ${err.message}`);
            });
          }
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

该接口仅在[自由窗口](../../windowmanager/window-terminology.md#自由窗口)状态下生效，用于在同应用内窗口分合场景下，将输入事件从源窗口转移到目标窗口，使用Promise异步回调，针对主窗和子窗生效。

源窗口需要处于鼠标按下状态，否则调用此接口将不生效。输入事件转移后，会向源窗口补发鼠标抬起事件，并且向目标窗口补发鼠标按下事件。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在2in1设备、Tablet设备中可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名          | 类型   | 必填  | 说明                    |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | 是    | 源窗口id。推荐使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)方法获取窗口id属性。            |
| targetWindowId | number | 是    | 目标窗口id。推荐使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)方法获取窗口id属性。             |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| ------- | --------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**示例：**

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

该接口仅在[自由窗口](../../windowmanager/window-terminology.md#自由窗口)状态下生效，主窗口和子窗口可正常调用，用于将触屏输入事件从源窗口转移到目标窗口。使用Promise异步回调。

源窗口仅在[onTouch](arkui-ts/ts-universal-events-touch.md#ontouch)事件（其中，事件类型必须为TouchType.Down）的回调方法中调用此接口才会有触屏输入事件转移效果，成功调用此接口后，系统会向源窗口补发触屏抬起（touch up）事件，并且向目标窗口补发触屏按下（touch down）事件。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在2in1设备、Tablet设备中可正常调用，在其它设备中返回801错误码。 

**参数：**

| 参数名          | 类型   | 必填  | 说明                    |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | 是    | 源窗口id。推荐使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)方法获取窗口id属性。该参数应为大于0的整数，小于等于0时会返回错误码1300016。            |
| targetWindowId | number | 是    | 目标窗口id。推荐使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)方法获取窗口id属性。该参数应为大于0的整数，小于等于0时会返回错误码1300016。             |
| fingerId | number | 是    | 触屏事件的fingerId。推荐使用[touchEvent](arkui-ts/ts-universal-events-touch.md#touchevent对象说明)事件中touches属性获取id。该参数应为大于等于0的整数，小于0时会返回错误码1300016。             |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| ------- | --------------------------------------------- |
| 801     | Capability not supported. Function shiftAppWindowTouchEvent can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range.|

**示例：**

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
            // 源窗口触屏事件类型必须为TouchType.Down
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

查询本应用指定坐标下的可见窗口数组，按当前窗口层级排列，层级最高的窗口对应数组下标为0，使用Promise异步回调。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                        |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| displayId   | number| 是  | 查询窗口所在的displayId，该参数应为整数，可以在窗口属性[WindowProperties](arkts-apis-window-i.md#windowproperties)中获取。 |
| windowNumber    | number| 否  | 查询的窗口数量，该参数应为大于0整数，未设置或小于等于0返回所有满足条件的窗口。                                  |
| x    | number | 否  | 查询的x坐标，该参数应为非负整数，未设置或小于0返回所有可见窗口。                                         |
| y    | number| 否  | 查询的y坐标，该参数应为非负整数，未设置或小于0返回所有可见窗口。                                         |

**返回值：**

| 类型                             | 说明                      |
| -------------------------------- |-------------------------|
| Promise&lt;Array&lt;[Window](arkts-apis-window-Window.md)&gt;&gt; | Promise对象。返回获取到的窗口对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID    | 错误信息 |
|----------| ------------------------------ |
| 401      | Parameter error. Possible cause: Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {

  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      let windowClass = windowStage.getMainWindowSync();
      let properties = windowClass.getWindowProperties();
      window.getWindowsByCoordinate(properties.displayId).then((data) => {
        console.info(`Succeeded in getting windows. Data: ${JSON.stringify(data)}`);
        for (let window of data) {
          // do something with window
        }
      }).catch((err: BusinessError) => {
        console.error(`Failed to get window from point. Cause code: ${err.code}, message: ${err.message}`);
      });
      window.getWindowsByCoordinate(properties.displayId, 2, 500, 500).then((data) => {
        console.info(`Succeeded in getting windows. Data: ${JSON.stringify(data)}`);
        for (let window of data) {
          // do something with window
        }
      }).catch((err: BusinessError) => {
        console.error(`Failed to get window from point. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to get window from point. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## window.getAllWindowLayoutInfo<sup>15+</sup>

getAllWindowLayoutInfo(displayId: number): Promise&lt;Array&lt;WindowLayoutInfo&gt;&gt;

获取指定屏幕上可见的窗口布局信息数组，按当前窗口层级排列，层级最高的对应数组index为0，使用Promise异步回调。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                        |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| displayId   | number| 是  | 需要获取窗口布局信息的displayId，该参数应为整数，且为当前实际存在屏幕的displayId，可以通过窗口属性[WindowProperties](arkts-apis-window-i.md#windowproperties)获取。 |

**返回值：**

| 类型                             | 说明                      |
| -------------------------------- |-------------------------|
| Promise&lt;Array&lt;[WindowLayoutInfo](arkts-apis-window-i.md#windowlayoutinfo15)&gt;&gt; | Promise对象。返回获取到的窗口布局信息对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID    | 错误信息 |
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

获取当前屏幕的可见主窗口（未退至后台的主窗口）信息。使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**需要权限：** ohos.permission.VISIBLE_WINDOW_INFO

**返回值：**

| 类型 | 说明 |
| ------------------- | ----------------------- |
| Promise&lt;Array&lt;[WindowInfo](arkts-apis-window-i.md#windowinfo18)&gt;&gt; | Promise对象，返回当前可见窗口的相关信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 801     | Capability not supported. Function getVisibleWindowInfo can not work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

获取指定屏幕上生命周期位于前台的窗口对应的窗口模式，使用Promise异步回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型       | 必填                 | 说明                                                                              |
| ------ | ---------- |--------------------|------------------------------------------------------------------------------------|
| displayId   | number| 否  | 可选的屏幕ID，用于获取对应屏幕上的窗口模式信息。该参数应为大于等于0的整数，小于0时会返回错误码1300016，不传或传值为null以及undefined则代表查询所有屏幕。如果指定的屏幕不存在，返回值为0，推荐使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)方法获取窗口所在屏幕id属性。                                                    |

**返回值：**

| 类型                             | 说明                      |
| -------------------------------- |-------------------------|
| Promise&lt;number&gt; | Promise对象。返回获取到的窗口模式。每一个二进制位代表一种窗口模式，当前支持的窗口模式见[GlobalWindowMode](arkts-apis-window-e.md#globalwindowmode20)，返回值为对应窗口模式值按位进行或运算的结果，比如，当前屏幕上存在全屏窗口、悬浮窗和画中画三种窗口，则返回值为`0b1\|0b100\|0b1000 = 13`。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID    | 错误信息 |
|----------| ------------------------------ |
| 801      | Capability not supported. function getGlobalWindowMode can not work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**
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

设置或取消本应用进程下窗口的水印图片，使用Promise异步回调。该接口需要在[loadContent()](arkts-apis-window-Window.md#loadcontent9)或[setUIContent()](arkts-apis-window-Window.md#setuicontent9)调用生效后使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                                                          | 必填 | 说明                                                                                                           |
| -------- | ----------------------------------------------------------------------------- | ---- | -------------------------------------------------------------------------------------------------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) \| undefined | 是   | 传入`image.PixelMap`表示设置水印图片，传入`undefined`表示取消水印显示。<br/>如果图片尺寸的宽和高同时超过窗口尺寸以及屏幕尺寸的宽和高，返回错误码1300016。<br/>如果图片尺寸的宽或高超过窗口尺寸的宽或高，超出窗口宽或高的部分会被裁剪。<br/>如果图片尺寸的宽或高小于窗口尺寸的宽或高，小于的部分会自动重复补充。|

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码 ID | 错误信息                                                                                                                  |
| --------- | ------------------------------------------------------------------------------------------------------------------------- |
| 801       | Capability not supported. Function setWatermarkImageForAppWindows can not work correctly due to limited device capabilities. |
| 1300003   | This window manager service works abnormally.                                                                             |
| 1300016   | Parameter error. Possible cause: 1. Invalid parameter range.                                                              |

**示例：**

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

设置同应用内指定mouduleName、abilityName对应UIAbility的启动页背景色，使用Promise异步回调。

该接口对同应用的所有进程生效，例如多实例或应用分身场景。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。
 
**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                     |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| moduleName     | string                        | 是   | 需要设置的UIAbility所属module的名字，moduleName的长度范围为0-200，仅支持设置当前同一应用包名内的moduleName。 |
| abilityName     | string                        | 是   | 需要设置的UIAbility名字，abilityName的长度范围为0-200，仅支持设置当前同一应用包名内的abilityName。 |
| color | [ColorMetrics](js-apis-arkui-graphics.md#colormetrics12) | 是   | 设置的启动页背景色。                       |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported.function setStartWindowBackgroundColor can not to work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

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

创建子窗口，使用callback异步回调。

子窗口创建后默认是[沉浸式布局](../../windowmanager/window-terminology.md#沉浸式布局)。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[createWindow()](#windowcreatewindow9)。

**模型约束：** 此接口仅可在FA模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                 |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | 是   | 窗口名字，即[Configuration](arkts-apis-window-i.md#configuration9)中的name。|
| type     | [WindowType](arkts-apis-window-e.md#windowtype7)              | 是   | 窗口类型。                           |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | 是   | 回调函数。返回当前创建的子窗口对象。 |


**示例：**

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

创建子窗口，使用Promise异步回调。

子窗口创建后默认是[沉浸式布局](../../windowmanager/window-terminology.md#沉浸式布局)。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[createWindow()](#windowcreatewindow9-1)。

**模型约束：** 此接口仅可在FA模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| id     | string                    | 是   | 窗口名字，即[Configuration](arkts-apis-window-i.md#configuration9)中的name。   |
| type   | [WindowType](arkts-apis-window-e.md#windowtype7) | 是   | 窗口类型。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前创建的子窗口对象。 |


**示例：**

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

创建系统窗口，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[createWindow()](#windowcreatewindow9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                 |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------ |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用上下文信息。                 |
| id       | string                                                  | 是   | 窗口名字，即[Configuration](arkts-apis-window-i.md#configuration9)中的name。   |
| type     | [WindowType](arkts-apis-window-e.md#windowtype7)                              | 是   | 窗口类型。                           |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt;                  | 是   | 回调函数。返回当前创建的子窗口对象。 |


**示例：**

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

创建系统窗口，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[createWindow()](#windowcreatewindow9-1)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明                                                         |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用上下文信息。 |
| id     | string                    | 是   | 窗口名字，即[Configuration](arkts-apis-window-i.md#configuration9)中的name。 |
| type   | [WindowType](arkts-apis-window-e.md#windowtype7) | 是   | 窗口类型。                                                   |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前创建的子窗口对象。 |


**示例：**

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

查找id所对应的窗口，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[findWindow()](#windowfindwindow9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                 |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | 是   | 窗口名字，即[Configuration](arkts-apis-window-i.md#configuration9)中的name。 |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | 是   | 回调函数。返回当前查找到的窗口对象。 |

**示例：**

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

查找id所对应的窗口，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[findWindow()](#windowfindwindow9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| id     | string | 是   | 窗口名字，即[Configuration](arkts-apis-window-i.md#configuration9)中的name。 |

**返回值：**

| 类型                             | 说明                                  |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前查找的窗口对象。 |

**示例：**

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

获取当前应用内最后显示的窗口，使用callback异步回调。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，推荐使用[getLastWindow()](#windowgetlastwindow9)。

**模型约束：** 此接口仅可在FA模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                         |
| -------- | -------------------------------------- | ---- | -------------------------------------------- |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | 是   | 回调函数。返回当前应用内最后显示的窗口对象。 |

**示例：**

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

获取当前应用内最后显示的窗口，使用Promise异步回调。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，推荐使用[getLastWindow()](#windowgetlastwindow9-1)。

**模型约束：** 此接口仅可在FA模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                             | 说明                                            |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前应用内最后显示的窗口对象。 |

**示例：**

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

获取当前应用内最后显示的窗口，使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，推荐使用[getLastWindow()](#windowgetlastwindow9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)                            | 是   | 当前应用上下文信息。 |
| callback | AsyncCallback&lt;[Window](arkts-apis-window-Window.md)&gt; | 是   | 回调函数。返回当前应用内最后显示的窗口对象。                 |

**示例：**

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

获取当前应用内最后显示的窗口，使用Promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，推荐使用[getLastWindow()](#windowgetlastwindow9-1)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前应用上下文信息。 |

**返回值：**

| 类型                             | 说明                                            |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前应用内最后显示的窗口对象。 |

**示例：**

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