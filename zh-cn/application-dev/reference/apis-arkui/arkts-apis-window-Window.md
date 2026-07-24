# Interface (Window)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

当前窗口实例，窗口管理器管理的基本单元。

下列API示例中都需先使用[getLastWindow()](arkts-apis-window-f.md#windowgetlastwindow9)、[createWindow()](arkts-apis-window-f.md#windowcreatewindow9)、[findWindow()](arkts-apis-window-f.md#windowfindwindow9)中的任一方法获取到Window实例（windowClass），再通过此实例调用对应方法。

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 针对系统能力SystemCapability.Window.SessionManager，请先使用[canIUse()](../common/js-apis-syscap.md#caniuse)接口判断当前设备是否支持此syscap及对应接口。
>
> - 本模块接口被调用时，若出现参数校验失败、权限校验失败、系统状态异常等情况，会抛出错误。建议调用本模块接口时在最外层通过try-catch捕获错误，避免调用失败导致应用崩溃。

## 导入模块

```ts
import { window } from '@kit.ArkUI';
```

## showWindow<sup>9+</sup>

showWindow(callback: AsyncCallback&lt;void&gt;): void

显示当前窗口，使用callback异步回调，支持系统窗口、应用子窗口、模态窗和全局悬浮窗，或将已显示的应用主窗口层级提升至顶部。

> **说明：**
>
> 调用该接口前，建议先通过[loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)方法或者[setUIContent](arkts-apis-window-Window.md#setuicontent9-1)方法完成页面加载。如果应用主窗口没有完成页面加载，直接调用该接口，界面会一直显示启动界面；如果系统窗口、应用子窗口、模态窗和全局悬浮窗没有完成页面加载，直接调用该接口，窗口会处于前台，但不可见。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------- | -- | --------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error('Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      console.info('Succeeded in loading the content.');
      try {
        // 创建子窗
        windowStage.createSubWindow("testSubWindow").then((subWindow) => {
          if (subWindow == null) {
            console.error('Failed to create the subWindow. Cause: The data is empty');
            return;
          }
          subWindow.setUIContent('pages/Index', (err) => {
            if (err.code) {
              console.error('Failed to load the subWindow content. Cause: %{public}s', JSON.stringify(err));
              return;
            }
            console.info('Succeeded in loading the subWindow content.');
            try {
              subWindow.showWindow((err: BusinessError) => {
                const errCode: number = err.code;
                if (errCode) {
                  console.error(`Failed to show the window. Error code: ${err.code}, message: ${err.message}`);
                  return;
                }
                console.info('Succeeded in showing the window.');
              });
            } catch (exception) {
              console.error(`Failed to show the window. Cause code: ${exception.code}, message: ${exception.message}`);
            }
          })
        });
      } catch (exception) {
        console.error(`Failed to create the sub window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
  });
  }
}
```

## showWindow<sup>9+</sup>

showWindow(): Promise&lt;void&gt;

显示当前窗口，使用Promise异步回调，支持系统窗口、应用子窗口、模态窗和全局悬浮窗，或将已显示的应用主窗口层级提升至顶部。

> **说明：**
>
> 调用该接口前，建议优先通过[loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)方法或者[setUIContent](arkts-apis-window-Window.md#setuicontent9-1)方法完成页面加载。如果应用主窗口没有完成页面加载，直接调用该接口，界面会一直显示启动界面；如果系统窗口、应用子窗口、模态窗和全局悬浮窗没有完成页面加载，直接调用该接口，窗口会处于前台，但不可见。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
// EntryAbility.ets

import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error('Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      console.info('Succeeded in loading the content.');
      try {
        // 创建子窗
        windowStage.createSubWindow("testSubWindow").then((subWindow) => {
          if (subWindow == null) {
            console.error('Failed to create the subWindow. Cause: The data is empty');
            return;
          }
          subWindow.setUIContent('pages/Index', (err) => {
            if (err.code) {
              console.error('Failed to load the subWindow content. Cause: %{public}s', JSON.stringify(err));
              return;
            }
            console.info('Succeeded in loading the subWindow content.');
            try {
              let promise = subWindow.showWindow();
              promise.then(() => {
                console.info('Succeeded in showing the window.');
              }).catch((err: BusinessError) => {
                console.error(`Failed to show the window. Error code: ${err.code}, message: ${err.message}`);
              });
            } catch (exception) {
              console.error(`Failed to show window. Cause code: ${exception.code}, message: ${exception.message}`);
            }
          });
        });
      } catch (exception) {
        console.error(`Failed to create the sub window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## showWindow<sup>20+</sup>

showWindow(options: ShowWindowOptions): Promise&lt;void&gt;

显示当前窗口或将已显示的应用主窗口的层级提升至顶部，支持传入参数来控制窗口显示的行为，使用Promise异步回调。

仅支持除TYPE_DIALOG类型的窗口和模态子窗口（即使用setSubWindowModal启用了子窗的模态属性）之外的应用子窗口、应用主窗、全局悬浮窗以及系统窗口。

> **说明：**
>
> 调用该接口前，建议优先通过[loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)方法或者[setUIContent](arkts-apis-window-Window.md#setuicontent9-1)方法完成页面加载。如果应用主窗口没有完成页面加载，直接调用该接口，界面会一直显示启动界面；如果系统窗口、应用子窗口和全局悬浮窗没有完成页面加载，直接调用该接口，窗口会处于前台，但不可见。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------- | -- | --------- |
| options | [ShowWindowOptions](arkts-apis-window-i.md#showwindowoptions20) | 是 | 显示子窗口或系统窗口时的参数。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Function showWindow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Modal subwindow and dialog window can not set focusOnShow. |
| 1300016 | Parameter validation error. Possible cause: 1. The value of the parameter is out of the allowed range; 2. The length of the parameter exceeds the allowed length; 3. The parameter format is incorrect. |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error('Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      console.info('Succeeded in loading the content.');
      // 创建子窗
      try {
        windowStage.createSubWindow('subWindow').then((data) => {
          if (data == null) {
            console.error('Failed to create the subWindow. Cause: The data is empty');
            return;
          }
          data.setUIContent('pages/Index', (err) => {
            if (err.code) {
              console.error('Failed to load the subWindow content. Cause: %{public}s', JSON.stringify(err));
              return;
            }
            console.info('Succeeded in loading the subWindow content.');
            let options: window.ShowWindowOptions = {
              focusOnShow: false
            };
            try {
              data.showWindow(options).then(() => {
                console.info('Succeeded in showing window');
              }).catch((err: BusinessError) => {
                console.error(`Failed to show window. Error code: ${err.code}, message: ${err.message}`);
              });
            } catch (exception) {
              console.error(`Failed to show window. Cause code: ${exception.code}, message: ${exception.message}`);
            }
          });
        });
      } catch (exception) {
        console.error(`Failed to create the sub window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## destroyWindow<sup>9+</sup>

destroyWindow(callback: AsyncCallback&lt;void&gt;): void

销毁当前窗口，使用callback异步回调，支持系统窗口及应用子窗口，全局悬浮窗和模态窗。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------- | -- | --------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.              |
| 1300003 | This window manager service works abnormally.<br/>适用版本：9                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.destroyWindow((err) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in destroying the window.');
});
```

## destroyWindow<sup>9+</sup>

destroyWindow(): Promise&lt;void&gt;

销毁当前窗口，使用Promise异步回调，支持系统窗口及应用子窗口，全局悬浮窗和模态窗。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.              |
| 1300003 | This window manager service works abnormally.<br/>适用版本：9                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.destroyWindow();
promise.then(() => {
  console.info('Succeeded in destroying the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## moveWindowTo<sup>9+</sup>

moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

移动窗口位置，使用callback异步回调。调用成功即返回，但返回后无法立即获取最终生效结果。如需立即获取，请使用[moveWindowToAsync()](#movewindowtoasync12)。

> **说明：**
>
> - 不建议在除自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，WindowStatusType可通过[getWindowStatus()](#getwindowstatus12)获取）外的其他窗口模式下使用。
>
> - 在[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，窗口相对于屏幕左上顶点移动；在非自由窗口状态下，窗口相对于父窗口左上顶点移动。
>
> - 若需在非自由窗口状态下实现相对于屏幕左上顶点的移动，请使用[moveWindowToGlobal()](#movewindowtoglobal15)。
>
> - 该方法对非自由窗口状态下的主窗口无效。
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，若主窗口或子窗口的标题栏移出屏幕可视区域，系统将自动回弹窗口，确保标题栏保持可见。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------- | -- | --------------------------------------------- |
| x        | number                    | 是 | 窗口在x轴方向移动到的坐标位置，单位为px，值为正表示在原点右侧，值为负表示在原点左侧。该参数仅支持整数输入，浮点数输入将向下取整。|
| y        | number                    | 是 | 窗口在y轴方向移动到的坐标位置，单位为px，值为正表示在原点下方，值为负表示在原点上方。该参数仅支持整数输入，浮点数输入将向下取整。|
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in moving the window.');
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## moveWindowTo<sup>9+</sup>

moveWindowTo(x: number, y: number): Promise&lt;void&gt;

移动窗口位置，使用Promise异步回调。调用成功即返回，但返回后无法立即获取最终生效结果。如需立即获取，请使用[moveWindowToAsync()](#movewindowtoasync12)。

> **说明：**
>
> - 不建议在除自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，WindowStatusType可通过[getWindowStatus()](#getwindowstatus12)获取）外的其他窗口模式下使用。
>
> - 在[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，窗口相对于屏幕左上顶点移动；在非自由窗口状态下，窗口相对于父窗口左上顶点移动。
>
> - 若需在非自由窗口状态下实现相对于屏幕左上顶点的移动，请使用[moveWindowToGlobal()](#movewindowtoglobal15)。
>
> - 该方法对非自由窗口状态下的主窗口无效。
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，若主窗口或子窗口的标题栏移出屏幕可视区域，系统将自动回弹窗口，确保标题栏保持可见。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | ----- | -- | --------------------------------------------- |
| x | number | 是 | 窗口在x轴方向移动到的坐标位置，单位为px，值为正表示在原点右侧，值为负表示在原点左侧。该参数仅支持整数输入，浮点数输入将向下取整。|
| y | number | 是 | 窗口在y轴方向移动到的坐标位置，单位为px，值为正表示在原点下方，值为负表示在原点上方。该参数仅支持整数输入，浮点数输入将向下取整。|

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.moveWindowTo(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## moveWindowToAsync<sup>12+</sup>

moveWindowToAsync(x: number, y: number): Promise&lt;void&gt;

移动窗口位置，使用Promise异步回调。调用生效后返回，回调中可使用[getWindowProperties()](#getwindowproperties9)（见示例）立即获取最终生效结果。

该接口仅在窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，窗口模式可通过[getWindowStatus()](#getwindowstatus12)获取）时调用生效，在其他窗口模式下调用返回错误码1300010错误码。

在自由悬浮窗口模式下，不同类型窗口的移动行为如下：

| 窗口类型 | [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态 | 非自由窗口状态 |
|---------|---------------|-----------------|
| 主窗口 | 相对于屏幕移动 | 调用不生效不报错 |
| 应用子窗口/模态窗 | 相对于屏幕移动 | 相对于主窗口移动 |
| 系统窗口/全局悬浮窗 | 相对于屏幕移动 | 相对于屏幕移动 |

> **说明：**
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，若主窗口或子窗口的标题栏移出屏幕可视区域，系统将自动回弹窗口，确保标题栏保持可见。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | ----- | -- | --------------------------------------------- |
| x | number | 是 | 窗口在x轴方向移动到的坐标位置，单位为px，值为正表示位置在x轴右侧；值为负表示位置在x轴左侧；值为0表示位置在x轴坐标原点。该参数仅支持整数输入，浮点数输入将向下取整。 |
| y | number | 是 | 窗口在y轴方向移动到的坐标位置，单位为px，值为正表示位置在y轴下侧；值为负表示位置在y轴上侧；值为0表示位置在y轴坐标原点。该参数仅支持整数输入，浮点数输入将向下取整。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. The window type is not supported for this operation.|
| 1300003 | This window manager service works abnormally. |
| 1300010 | The operation in the current window status is invalid. Possible cause: The window status is not FLOATING. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  let promise = windowClass.moveWindowToAsync(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## moveWindowToAsync<sup>15+</sup>

moveWindowToAsync(x: number, y: number, moveConfiguration?: MoveConfiguration): Promise&lt;void&gt;

移动窗口位置，支持配置moveConfiguration参数指定窗口移动的目标屏幕ID，使用Promise异步回调。调用生效后返回，回调中可使用[getWindowProperties()](#getwindowproperties9)（见示例）立即获取最终生效结果。

该接口仅在窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，窗口模式可通过[getWindowStatus()](#getwindowstatus12)获取）时调用生效，在其他窗口模式下调用返回错误码1300010错误码。

在自由悬浮窗口模式下，不同类型窗口的移动行为如下：

| 窗口类型 | [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态 | 非自由窗口状态 |
|---------|---------------|-----------------|
| 主窗口 | 相对于屏幕移动 | 调用不生效不报错 |
| 应用子窗口/模态窗 | 相对于屏幕移动 | 相对于主窗口移动 |
| 系统窗口/全局悬浮窗 | 相对于屏幕移动 | 相对于屏幕移动 |

> **说明：**
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，若主窗口或子窗口的标题栏移出屏幕可视区域，系统将自动回弹窗口，确保标题栏保持可见。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | ----- | -- | --------------------------------------------- |
| x | number | 是 | 窗口在x轴方向移动的值，值为正表示右移，单位为px，该参数应该为整数，非整数输入将向下取整。 |
| y | number | 是 | 窗口在y轴方向移动的值，值为正表示下移，单位为px，该参数应该为整数，非整数输入将向下取整。 |
| moveConfiguration | [MoveConfiguration](arkts-apis-window-i.md#moveconfiguration15) | 否 | 窗口移动选项，仅支持主屏和扩展屏，未设置将默认保持为当前屏幕。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. The window type is not supported for this operation. |
| 1300003 | This window manager service works abnormally. |
| 1300010 | The operation in the current window status is invalid. Possible cause: The window status is not FLOATING. |

**示例：**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let moveConfiguration: window.MoveConfiguration = {
    displayId: 0
  };
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  let promise = windowClass.moveWindowToAsync(300, 300, moveConfiguration);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## moveWindowToGlobal<sup>13+</sup>

moveWindowToGlobal(x: number, y: number): Promise&lt;void&gt;

基于屏幕坐标移动窗口位置，使用Promise异步回调。调用生效后返回，回调中可使用[getWindowProperties()](#getwindowproperties9)（见示例）立即获取最终生效结果。

该接口仅在窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，窗口模式可通过[getWindowStatus()](#getwindowstatus12)获取）时调用生效，在其他窗口模式下调用返回错误码1300010错误码。

> **说明：**
>
> - 主窗处于自由悬浮窗口模式时，在非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下调用不生效不报错。
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，若主窗口或子窗口的标题栏移出屏幕可视区域，系统将自动回弹窗口，确保标题栏保持可见。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | ----- | -- | --------------------------------------------- |
| x | number | 是 | 表示以屏幕左上角为起点，窗口在x轴方向移动的值，单位为px。值为正表示右移，值为负表示左移。该参数仅支持整数输入，浮点数输入将向下取整。 |
| y | number | 是 | 表示以屏幕左上角为起点，窗口在y轴方向移动的值，单位为px。值为正表示下移，值为负表示上移。该参数仅支持整数输入，浮点数输入将向下取整。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. The window type is not supported for this operation.|
| 1300003 | This window manager service works abnormally. |
| 1300010 | The operation in the current window status is invalid. Possible cause: The window status is not FLOATING. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  let promise = windowClass.moveWindowToGlobal(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## moveWindowToGlobal<sup>15+</sup>

moveWindowToGlobal(x: number, y: number, moveConfiguration?: MoveConfiguration): Promise&lt;void&gt;

基于屏幕坐标移动窗口位置，支持配置moveConfiguration参数指定窗口移动的目标屏幕ID，使用Promise异步回调。调用生效后返回，回调中可使用[getWindowProperties()](#getwindowproperties9)（见示例）立即获取最终生效结果。

该接口仅在窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，窗口模式可通过[getWindowStatus()](#getwindowstatus12)获取）时调用生效，在其他窗口模式下调用返回错误码1300010错误码。

> **说明：**
>
> - 主窗处于自由悬浮窗口模式时，在非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下调用不生效不报错。
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，若主窗口或子窗口的标题栏移出屏幕可视区域，系统将自动回弹窗口，确保标题栏保持可见。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | ----- | -- | --------------------------------------------- |
| x | number | 是 | 表示以目标屏幕左上角为起点，窗口在x轴方向移动的值，单位为px。值为正表示右移，值为负表示左移。该参数应该为整数，非整数输入将向下取整。 |
| y | number | 是 | 表示以目标屏幕左上角为起点，窗口在y轴方向移动的值，单位为px。值为正表示下移，值为负表示上移。该参数应该为整数，非整数输入将向下取整。 |
| moveConfiguration | [MoveConfiguration](arkts-apis-window-i.md#moveconfiguration15) | 否 | 窗口移动选项，仅支持主屏和扩展屏，未设置将默认保持为当前屏幕。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. The window type is not supported for this operation. |
| 1300003 | This window manager service works abnormally. |
| 1300010 | The operation in the current window status is invalid. Possible cause: The window status is not FLOATING. |

**示例：**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let moveConfiguration: window.MoveConfiguration = {
    displayId: 0
  };
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  let promise = windowClass.moveWindowToGlobal(300, 300, moveConfiguration);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## moveWindowToGlobalDisplay<sup>20+</sup>

moveWindowToGlobalDisplay(x: number, y: number): Promise&lt;void&gt;

基于[全局坐标系](../../windowmanager/window-terminology.md#global-coordinate-system全局坐标系)移动窗口位置，使用Promise异步回调。

该接口仅在窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，窗口模式可通过[getWindowStatus()](#getwindowstatus12)获取）时调用生效，在其他窗口模式下调用返回错误码1300010错误码。

> **说明：**
>
> - 主窗处于自由悬浮窗口模式时，在非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下调用不生效不报错。
> 
> - 窗口移动后，如果窗口跨越多个屏幕，窗口将归属于与其重叠面积最大的屏幕。
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，若主窗口或子窗口的标题栏移出屏幕可视区域，系统将自动回弹窗口，确保标题栏保持可见。回弹规格详情请参考：[窗口回弹规格](https://developer.huawei.com/consumer/cn/doc/design-guides/window-0000002321868010#section142701449114818)。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | ----- | -- | --------------------------------------------- |
| x | number | 是 | 表示以主屏幕左上角为起点，窗口在x轴方向移动的值，单位为px。值为正表示右移，值为负表示左移。该参数应该为整数，非整数输入将向下取整。 |
| y | number | 是 | 表示以主屏幕左上角为起点，窗口在y轴方向移动的值，单位为px。值为正表示下移，值为负表示上移。该参数应该为整数，非整数输入将向下取整。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300010 | The operation in the current window status is invalid. Possible cause: The window status is not FLOATING. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.moveWindowToGlobalDisplay(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the window in global display.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window in global display. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window in global display. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## clientToGlobalDisplay<sup>20+</sup>

clientToGlobalDisplay(winX: number, winY: number): Position

将相对于当前窗口左上角的坐标转换为相对于主屏幕左上角的全局坐标。

不支持在经过显示缩放的窗口中调用，例如手机或平板设备在非自由多窗模式下的智慧多窗悬浮窗场景。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | ----- | -- | --------------------------------------------- |
| winX | number | 是 | 表示以当前窗口左上角为原点的x轴方向偏移量，单位为px。值为正表示在原点右侧，值为负表示在原点左侧。该参数应为整数，非整数输入将向下取整。 |
| winY | number | 是 | 表示以当前窗口左上角为原点的y轴方向偏移量，单位为px。值为正表示在原点下方，值为负表示在原点上方。该参数应为整数，非整数输入将向下取整。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| [Position](arkts-apis-window-i.md#position20) | 返回转换后的坐标。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300010 | The operation in the current window status is invalid. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

```ts
try {
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  let position = windowClass.clientToGlobalDisplay(100, 100);
  console.info(`Succeeded in converting the position in the current window to the position in global display. Position: ` + JSON.stringify(position));
} catch (exception) {
  console.error(`Failed to convert the position. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## globalDisplayToClient<sup>20+</sup>

globalDisplayToClient(globalDisplayX: number, globalDisplayY: number): Position

将相对于主屏幕左上角的全局坐标转换为相对于当前窗口左上角的坐标。

不支持在经过显示缩放的窗口中调用，例如手机或平板设备在非自由多窗模式下的智慧多窗悬浮窗场景。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | ----- | -- | --------------------------------------------- |
| globalDisplayX | number | 是 | 表示以当前主屏幕左上角为原点的x轴方向偏移量，单位为px。值为正表示在原点右侧，值为负表示在原点左侧。该参数应为整数，非整数输入将向下取整。 |
| globalDisplayY | number | 是 | 表示以当前主屏幕左上角为原点的y轴方向偏移量，单位为px。值为正表示在原点下方，值为负表示在原点上方。该参数应为整数，非整数输入将向下取整。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| [Position](arkts-apis-window-i.md#position20) | 返回转换后的坐标。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300010 | The operation in the current window status is invalid. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

```ts
try {
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  let position = windowClass.globalDisplayToClient(100, 100);
  console.info(`Succeeded in converting in the position in global display to the position in the current window. Position: ` + JSON.stringify(position));
} catch (exception) {
  console.error(`Failed to convert the position. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## resize<sup>9+</sup>

resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

基于窗口左上角顶点改变当前窗口大小，使用callback异步回调。

调用成功即返回，该接口返回后无法立即获取最终生效结果，如需立即获取，建议使用接口[resizeAsync()](#resizeasync12)。

窗口存在大小限制[WindowLimits](arkts-apis-window-i.md#windowlimits11)，具体尺寸限制范围可以通过[getWindowLimits](#getwindowlimits11)接口进行查询。

调用该接口设置的宽度与高度受到此限制约束，规则：

若所设置的窗口宽/高尺寸小于窗口最小宽/高限制值，则窗口最小宽/高限制值生效，系统窗口和全局悬浮窗设置最小值不受窗口最小宽/高限制值限制；

若所设置的窗口宽/高尺寸大于窗口最大宽/高限制值，则窗口最大宽/高限制值生效。

该接口仅在窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，窗口模式可通过[getWindowStatus()](#getwindowstatus12)获取）时调用生效，在其他窗口模式下调用返回1300002错误码。

> **说明：**
>
> - 主窗口处于自由悬浮窗口模式时，在非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下调用不报错不生效。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------- | -- | ------------------------ |
| width    | number                    | 是 | 当前窗口的目标宽度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码401）。实际设置的大小受窗口配置的最小/最大宽度限制，超出限制时自动修正为边界值。|
| height   | number                    | 是 | 当前窗口的目标高度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码401）。实际设置的大小受窗口配置的最小/最大高度限制，超出限制时自动修正为边界值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error; 3. Invalid window status type. Only supports windows in floating window mode. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  windowClass.resize(500, 1000, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in changing the window size.');
  });
} catch (exception) {
  console.error(`Failed to change the window size. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## resize<sup>9+</sup>

resize(width: number, height: number): Promise&lt;void&gt;

基于窗口左上角顶点改变当前窗口大小，使用Promise异步回调。

调用成功即返回，该接口返回后无法立即获取最终生效结果，如需立即获取，建议使用接口[resizeAsync()](#resizeasync12)。

窗口存在大小限制[WindowLimits](arkts-apis-window-i.md#windowlimits11)，具体尺寸限制范围可以通过[getWindowLimits](#getwindowlimits11)接口进行查询。

调用该接口设置的宽度与高度受到此限制约束，规则：

若所设置的窗口宽/高尺寸小于窗口最小宽/高限制值，则窗口最小宽/高限制值生效，系统窗口和全局悬浮窗设置最小值不受窗口最小宽/高限制值限制；

若所设置的窗口宽/高尺寸大于窗口最大宽/高限制值，则窗口最大宽/高限制值生效。

该接口仅在窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，窗口模式可通过[getWindowStatus()](#getwindowstatus12)获取）时调用生效，在其他窗口模式下调用返回1300002错误码。

> **说明：**
>
> - 主窗口处于自由悬浮窗口模式时，在非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下调用不报错不生效。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | -- | ------------------------ |
| width  | number | 是 | 当前窗口的目标宽度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码401）。实际设置的大小受窗口配置的最小/最大宽度限制，超出限制时自动修正为边界值。 |
| height | number | 是 | 当前窗口的目标高度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码401）。实际设置的大小受窗口配置的最小/最大高度限制，超出限制时自动修正为边界值。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error; 3. Invalid window status type. Only supports windows in floating window mode. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.resize(500, 1000);
  promise.then(() => {
    console.info('Succeeded in changing the window size.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to change the window size. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## resizeAsync<sup>12+</sup>

resizeAsync(width: number, height: number): Promise&lt;void&gt;

基于窗口左上角顶点改变当前窗口大小，使用Promise异步回调。

调用生效后返回，回调中可使用[getWindowProperties()](#getwindowproperties9)（见示例）立即获取最终生效结果。

窗口存在大小限制[WindowLimits](arkts-apis-window-i.md#windowlimits11)，具体尺寸限制范围可以通过[getWindowLimits](#getwindowlimits11)接口进行查询。

调用该接口设置的宽度与高度受到此限制约束，规则：

若所设置的窗口宽/高尺寸小于窗口最小宽/高限制值，则窗口最小宽/高限制值生效，系统窗口和全局悬浮窗设置最小值不受窗口最小宽/高限制值限制；

若所设置的窗口宽/高尺寸大于窗口最大宽/高限制值，则窗口最大宽/高限制值生效。

该接口仅在窗口为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING，窗口模式可通过[getWindowStatus()](#getwindowstatus12)获取）时调用生效，否则抛出错误码1300010。

> **说明：**
>
> - 主窗口处于自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）时，在非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下调用不生效不报错。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | -- | ------------------------ |
| width  | number | 是 | 当前窗口的目标宽度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码401）。实际设置的大小受窗口配置的最小/最大宽度限制，超出限制时自动修正为边界值。 |
| height | number | 是 | 当前窗口的目标高度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码401）。实际设置的大小受窗口配置的最小/最大高度限制，超出限制时自动修正为边界值。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: Invalid parameter range.  |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.  Possible cause: 1. The window is not created or destroyed. 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300010 | The operation in the current window status is invalid. Possible cause: The window status is not FLOATING.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  let promise = windowClass.resizeAsync(500, 1000);
  promise.then(() => {
    console.info('Succeeded in changing the window size.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to change the window size. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getWindowProperties<sup>9+</sup>

getWindowProperties(): WindowProperties

获取当前窗口的属性。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------------------------------------- | ------------- |
| [WindowProperties](arkts-apis-window-i.md#windowproperties) | 当前窗口属性。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
try {
  let properties = windowClass.getWindowProperties();
} catch (exception) {
  console.error(`Failed to obtain the window properties. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getWindowDensityInfo<sup>15+</sup>

getWindowDensityInfo(): WindowDensityInfo

获取当前窗口所在屏幕的系统显示大小缩放系数、系统默认显示大小缩放系数和自定义显示大小缩放系数信息。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------------------------------------- | ------------- |
| [WindowDensityInfo](arkts-apis-window-i.md#windowdensityinfo15) | 当前窗口的显示大小缩放系数信息。当返回值为[-1, -1, -1]时，表示当前设备不支持使用该接口。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
try {
  let densityInfo = windowClass.getWindowDensityInfo();
} catch (exception) {
  console.error(`Failed to obtain the window densityInfo. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowContainerColor<sup>20+</sup>

setWindowContainerColor(activeColor: string, inactiveColor: string): void

设置主窗口容器在焦点态和非焦点态时的背景色。在Stage模型下，该接口需在调用[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)后使用。

窗口容器背景色覆盖整个窗口区域，包括标题栏和内容区域。内容区域背景色默认跟随系统深浅色，当同时使用该接口和[setWindowBackgroundColor()](#setwindowbackgroundcolor9)设置背景色时，内容区域显示窗口背景色，标题栏显示窗口容器背景色。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码；从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在2in1和Tablet设备中可正常调用，在其他设备中返回801错误码。

**需要权限：** ohos.permission.SET_WINDOW_TRANSPARENT

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | -- | ----------------------------------------------------------------------- |
| activeColor | string | 是 | 窗口容器处于焦点态时的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。|
| inactiveColor | string | 是 | 窗口容器处于非焦点态时的背景色，为十六进制RGB颜色或ARGB颜色（透明度固定为`'FF'`），不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004 | Unauthorized operation.                      |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent("pages/page2", (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
      // 获取应用主窗口。
      let windowClass: window.Window | undefined = undefined;
      windowStage.getMainWindow((err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        let activeColor: string = '#00000000';
        let inactiveColor: string = '#FF000000';
        try {
          windowClass.setWindowContainerColor(activeColor, inactiveColor);
          console.info('Succeeded in setting window container color.');
        } catch (exception) {
          console.error(`Failed to set the window container color. Cause code: ${exception.code}, message: ${exception.message}`);
        };
      });
    });
  }
}
```

## setWindowContainerModalColor

setWindowContainerModalColor(activeColor: string, inactiveColor: string): void

设置主窗口容器在焦点态和非焦点态时的背景色。该接口需在调用[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)后使用。

窗口容器背景色覆盖整个窗口区域，包括标题栏和内容区域。内容区域背景色默认跟随系统深浅色，当同时使用该接口和[setWindowBackgroundColor()](#setwindowbackgroundcolor9)设置背景色时，内容区域显示窗口背景色，标题栏显示窗口容器背景色。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**需要权限：** ohos.permission.SET_WINDOW_ALPHA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | -- | ----------------------------------------------------------------------- |
| activeColor | string | 是 | 窗口容器处于焦点态时的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。|
| inactiveColor | string | 是 | 窗口容器处于非焦点态时的背景色，为十六进制RGB颜色或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required or a non-system application calls the API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent("pages/Index", (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
      // 获取应用主窗口。
      let windowClass: window.Window | undefined = undefined;
      windowStage.getMainWindow((err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        let activeColor: string = '#00000000';
        let inactiveColor: string = '#FF000000';
        try {
          windowClass.setWindowContainerModalColor(activeColor, inactiveColor);
          console.info('Succeeded in setting window container color.');
        } catch (exception) {
          console.error(`Failed to set the window container color. Cause code: ${exception.code}, message: ${exception.message}`);
        };
      });
    });
  }
}
```

## getGlobalRect<sup>13+</sup>

getGlobalRect(): Rect

获取窗口在其所在物理屏幕上的真实显示区域，同步接口。

在某些设备上，窗口显示时可能经过了缩放，此接口可以获取缩放后窗口在屏幕上的真实位置和大小。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| [Rect](arkts-apis-window-i.md#rect7) | 四元组分别表示距离屏幕左上角的x坐标、距离屏幕左上角的y坐标、缩放后的窗口宽度和缩放后的窗口高度。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Failed to convert result into JS value object. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  // windowClass通过getLastWindow()、createWindow()或findWindow()获取
  let rect = windowClass.getGlobalRect();
  console.info(`Succeeded in getting window rect: ` + JSON.stringify(rect));
} catch (exception) {
  console.error(`Failed to get window rect. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getWindowAvoidArea<sup>9+</sup>

getWindowAvoidArea(type: AvoidAreaType): AvoidArea

获取当前窗口避让区域。

全局悬浮窗、模态窗或系统窗口：
- 仅在调用[setSystemAvoidAreaEnabled](#setsystemavoidareaenabled18)方法使能后，才能通过此接口获取避让区域。

该接口一般适用于两种场景：
- 在[onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate)方法中，获取应用启动时的初始布局避让区域时可调用该接口。
- 当应用内子窗需要临时显示，对显示内容做布局避让时可调用该接口。

> **说明：**
>
> TV 设备不显示状态栏。若未显式设置状态栏隐藏，调用该接口仍可获取状态栏对应的避让区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- |----------------------------------| -- | ------------------------------------------------------------ |
| type | [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | 是 | 表示避让区域类型。 |

**返回值：**

| 类型 | 说明 |
|--------------------------| ----------------- |
| [AvoidArea](arkts-apis-window-i.md#avoidarea7) | 窗口内容避让区域。当获取到的避让区域值全为0，表示避让区域为空。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Convert avoid area failed. |

**示例：**

```ts
let type = window.AvoidAreaType.TYPE_SYSTEM;
try {
  let avoidArea = windowClass.getWindowAvoidArea(type);
} catch (exception) {
  console.error(`Failed to obtain the area. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getWindowAvoidAreaIgnoringVisibility<sup>22+</sup>

getWindowAvoidAreaIgnoringVisibility(type: AvoidAreaType): AvoidArea

获取当前应用窗口的避让区域，即使避让区域当前处于不可见状态。

全局悬浮窗、模态窗或系统窗口：
- 仅在调用[setSystemAvoidAreaEnabled](#setsystemavoidareaenabled18)方法使能后，才能通过此接口获取避让区域。

> **说明：**
>
> TV 设备不显示状态栏。若未显式设置状态栏隐藏，调用该接口仍可获取状态栏对应的避让区域。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- |----------------------------------| -- | ------------------------------------------------------------ |
| type | [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | 是 | 表示避让区域类型。不支持获取软键盘类型的避让区域，传入TYPE_KEYBOARD时，返回1300016错误码。 |

**返回值：**

| 类型 | 说明 |
|--------------------------| ----------------- |
| [AvoidArea](arkts-apis-window-i.md#avoidarea7) | 窗口内容避让区域。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Convert avoid area failed. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: Invalid parameter range.|

**示例：**

```ts
let type = window.AvoidAreaType.TYPE_SYSTEM;
try {
  let avoidArea = windowClass.getWindowAvoidAreaIgnoringVisibility(type);
} catch (exception) {
  console.error(`Failed to obtain the area. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setSystemAvoidAreaEnabled<sup>18+</sup>

setSystemAvoidAreaEnabled(enabled: boolean): Promise&lt;void&gt;

创建全局悬浮窗、模态窗或WindowType窗口类型为系统窗口时，调用该接口使能后才可以通过[getWindowAvoidArea()](#getwindowavoidarea9)获取窗口避让区信息或通过[on('avoidAreaChange')](#onavoidareachange9)监听窗口避让区变化。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- |----------------------------------| -- | ------------------------------------------------------------ |
| enabled | boolean | 是 | 是否可以获取到避让区。<br> true表示可以获取避让区；false表示不可以获取避让区。默认值是false。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. Possible cause: The device does not support the API itself. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only global floating windows, dialog windows, or Window Type as system windows are supported.|

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error('Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      console.info('Succeeded in loading the content.');
      let windowClass: window.Window | undefined = undefined;
      let config: window.Configuration = {
        name: "test",
        windowType: window.WindowType.TYPE_DIALOG,
        decorEnabled: true,
        ctx: this.context
      };
      try {
        window.createWindow(config, (err: BusinessError, data) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to create the system window. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          windowClass = data;
          windowClass.setUIContent("pages/Test");
          let enabled = true;
          let promise = windowClass.setSystemAvoidAreaEnabled(enabled);
          promise.then(() => {
            let type = window.AvoidAreaType.TYPE_SYSTEM;
            let avoidArea = windowClass?.getWindowAvoidArea(type);
          }).catch((err: BusinessError) => {
            console.error(`Failed to obtain the system window avoid area. Cause code: ${err.code}, message: ${err.message}`);
          });
        });
      } catch (exception) {
        console.error(`Failed to create the system window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## isSystemAvoidAreaEnabled<sup>18+</sup>

isSystemAvoidAreaEnabled(): boolean

获取全局悬浮窗、模态窗或WindowType为系统类型的窗口是否可以获取窗口内容的避让区[AvoidArea](arkts-apis-window-i.md#avoidarea7)。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------------------------------------- | ------------- |
| boolean | 是否可以获取窗口内容的避让区。<br> true表示可以获取避让区；false表示不可以获取避让区。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Create js value failed. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error('Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      console.info('Succeeded in loading the content.');
      let windowClass: window.Window | undefined = undefined;
      let config: window.Configuration = {
        name: "test",
        windowType: window.WindowType.TYPE_DIALOG,
        decorEnabled: true,
        ctx: this.context
      };
      try {
        window.createWindow(config, (err: BusinessError, data) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to create the system window. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          windowClass = data;
          windowClass.setUIContent("pages/Test");
          let promise = windowClass.setSystemAvoidAreaEnabled(true);
          promise.then(() => {
            let enabled = windowClass?.isSystemAvoidAreaEnabled();
          }).catch((err: BusinessError) => {
            console.error(`Failed to obtain the system window avoid area enable. Cause code: ${err.code}, message: ${err.message}`);
          });
        });
      } catch (exception) {
        console.error(`Failed to create the system window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setTitleAndDockHoverShown<sup>14+</sup>

setTitleAndDockHoverShown(isTitleHoverShown?: boolean, isDockHoverShown?: boolean): Promise&lt;void&gt;

设置主窗口进入全屏模式时鼠标Hover到热区上是否显示窗口标题栏和dock栏，使用Promise异步回调。

**系统能力**：SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isTitleHoverShown    | boolean | 否   | 是否显示窗口标题栏。<br>true表示显示窗口标题栏；false表示不显示窗口标题栏。默认值是true。</br> |
| isDockHoverShown    | boolean | 否   | 是否显示dock栏。<br>true表示显示dock栏；false表示不显示dock栏。默认值是true。</br> |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported.|

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // 加载主窗口对应的页面。
    windowStage.loadContent('pages/Index', (err) => {
      let mainWindow: window.Window | undefined = undefined;
      // 获取应用主窗口。
      windowStage.getMainWindow().then(
        data => {
          if (!data) {
            console.error('Failed to get main window. Cause: The data is undefined.');
            return;
          }
          mainWindow = data;
          console.info(`Succeeded in obtaining the main window. Data: ${JSON.stringify(data)}`);
          // 调用maximize接口，设置窗口进入全屏模式。
          mainWindow.maximize(window.MaximizePresentation.ENTER_IMMERSIVE);
          // 调用setTitleAndDockHoverShown接口，隐藏标题栏和dock栏。
          mainWindow.setTitleAndDockHoverShown(false, false);
        }
      ).catch((err: BusinessError) => {
          if(err.code){
            console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          }
      });
    });
  }
}
```

## setWindowLayoutFullScreen<sup>9+</sup>

setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

设置应用主窗口或应用子窗口的布局是否为[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)，使用Promise异步回调。其余窗口调用不生效也不报错。

沉浸式布局生效时，布局不避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件可能产生与其重叠的情况。

非沉浸式布局生效时，布局避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件不会与其重叠。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**设备行为差异：**

在OpenHarmony 5.0.2之前，该接口在所有设备中可正常调用。

从OpenHarmony 5.0.2开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错，切换到非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态时生效；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------------ | ------- | -- | ------------------------------------------------------------------------------------------------ |
| isLayoutFullScreen | boolean | 是 | 窗口的布局是否为沉浸式布局（该沉浸式布局状态栏、<!--RP15-->三键导航栏<!--RP15End-->仍然显示）。true表示沉浸式布局；false表示非沉浸式布局。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isLayoutFullScreen = true;
      try {
        let promise = windowClass.setWindowLayoutFullScreen(isLayoutFullScreen);
        promise.then(() => {
          console.info('Succeeded in setting the window layout to full-screen mode.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the window layout to full-screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setImmersiveModeEnabledState<sup>12+</sup>

setImmersiveModeEnabledState(enabled: boolean): void

设置当前窗口是否开启[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)，该调用不会改变窗口模式和窗口大小。仅主窗口和子窗口可调用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**设备行为差异：**

在OpenHarmony 5.0.2之前，该接口在所有设备中可正常调用。

从OpenHarmony 5.0.2开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| enabled    | boolean | 是   | 是否开启沉浸式布局。<br>true表示开启，false表示关闭。</br> |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal IPC error. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows and subwindows are supported. |

**示例：**

```ts
try {
  let enabled = false;
  windowClass.setImmersiveModeEnabledState(enabled);
} catch (exception) {
  console.error(`Failed to set the window immersive mode enabled status. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getImmersiveModeEnabledState<sup>12+</sup>

getImmersiveModeEnabledState(): boolean

查询当前窗口是否开启[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)。

仅支持主窗和子窗调用。

返回值与[setImmersiveModeEnabledState()](#setimmersivemodeenabledstate12)以及[setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9)设置结果一致，若未调用上述两个接口则默认返回false。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**
| 类型     | 说明                                                                                 |
| ------- | ------------------------------------------------------------------------------------ |
| boolean | 是否设置开启沉浸式布局。</br>true表示开启沉浸式布局，false表示关闭沉浸式布局。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------------- |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows and subwindows are supported. |

**示例：**

```ts
try {
  let isEnabled = windowClass.getImmersiveModeEnabledState();
} catch (exception) {
  console.error(`Failed to get the window immersive mode enabled status. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setFloatNavigationAvoidAreaEnabled

setFloatNavigationAvoidAreaEnabled(enabled: boolean): Promise\<void>

设置当前窗口是否支持获取三键导航类型的避让区域。未调用此接口设置前，系统默认不支持获取三键导航类型的避让区域。使用Promise异步回调。

调用该接口使能后才可以通过[getWindowAvoidArea()](#getwindowavoidarea9)获取到[TYPE_FLOAT_NAVIGATION](arkts-apis-window-e.md#avoidareatype7)避让类型对应的避让区域或通过[on('avoidAreaChange')](#onavoidareachange9)监听TYPE_FLOAT_NAVIGATION避让类型对应的避让区域的变化。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| enabled    | boolean | 是   | 是否支持获取三键导航类型的避让区域。<br>true表示支持，false表示不支持。</br> |

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Create js value failed. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  let enabled = false;
  windowClass.setFloatNavigationAvoidAreaEnabled(enabled);
} catch (exception) {
  console.error(`Failed to set the window float navigation avoid area enabled status. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## isFloatNavigationAvoidAreaEnabled

isFloatNavigationAvoidAreaEnabled(): boolean

查询当前窗口是否支持获取三键导航类型的避让区域。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型             | 说明              |
| -------------- | --------------- |
| boolean | 是否支持获取三键导航类型的避让区域。<br>true表示支持，false表示不支持。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Create js value failed. |

**示例：**

```ts
try {
  let isEnabled = windowClass.isFloatNavigationAvoidAreaEnabled();
} catch (exception) {
  console.error(`Failed to check if the window is enabled float navigation avoid area. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## isImmersiveLayout<sup>20+</sup>

isImmersiveLayout(): boolean

查询当前窗口是否处于[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)。

**系统能力**：SystemCapability.Window.SessionManager

**返回值：**
| 类型     | 说明                                                                                 |
| ------- | ------------------------------------------------------------------------------------ |
| boolean | 是否处于沉浸式布局。true表示处于沉浸式布局，false表示不处于沉浸式布局。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------------- |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
try {
  let isEnabled = windowClass.isImmersiveLayout();
} catch (exception) {
  console.error(`Failed to check if the window layout is in immersive mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowDelayRaiseOnDrag<sup>19+</sup>

setWindowDelayRaiseOnDrag(isEnabled: boolean): void

设置窗口是否使能延迟抬升，仅主窗和子窗可设置。

不调用此接口或传入false，主窗和子窗在鼠标左键按下时，默认立即抬升。

调用此接口使能延迟抬升后，在跨窗拖拽场景，可拖拽组件所在窗口在鼠标左键按下时不会立即抬升，直到鼠标左键抬起。

**系统能力**：SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用； 在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isEnabled    | boolean | 是   | 是否使能延迟抬升。<br>true表示使能窗口延迟抬升；false表示不使能窗口延迟抬升。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported.function setWindowDelayRaiseOnDrag can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
try {
  windowClass.setWindowDelayRaiseOnDrag(true);
} catch (exception) {
  console.error(`Failed to set window delay raise. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setDragKeyFramePolicy<sup>20+</sup>

setDragKeyFramePolicy(keyFramePolicy: KeyFramePolicy): Promise&lt;KeyFramePolicy&gt;

设置主窗口拖拽的关键帧策略，并使用Promise处理异步回调。

非主窗口调用时，返回1300004错误码。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在PC/2in1设备可正常调用，在其他设备中返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在PC/2in1设备、其他设备的电脑模式中可正常调用；在其他设备和其他模式中不生效不报错。

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| keyFramePolicy | [KeyFramePolicy](arkts-apis-window-i.md#keyframepolicy20)  | 是   | 用于设置拖拽的关键帧策略。 |

**返回值：**

| 类型                                  | 说明                      |
| ------------------------------------- | ------------------------- |
| Promise&lt;[KeyFramePolicy](arkts-apis-window-i.md#keyframepolicy20)&gt; | Promise对象，返回实际生效的关键帧策略。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| ------- | --------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range; 2. The parameter format is incorrect.|

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let keyFramePolicy: window.KeyFramePolicy = {
        enable: true
      }
      try {
        let promise = windowClass.setDragKeyFramePolicy(keyFramePolicy);
        promise.then((ret: window.KeyFramePolicy) => {
          console.info(`Succeeded in setting key frame: ${JSON.stringify(ret)}`);
        }).catch((err: BusinessError) => {
          console.error(`Failed to set key frame. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set key frame. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setWindowSystemBarEnable<sup>9+</sup>

setWindowSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

<!--RP14-->设置主窗口状态栏、三键导航栏的可见模式，状态栏通过status控制、三键导航栏通过navigation控制<!--RP14End-->，使用Promise异步回调。

调用生效后返回并不表示状态栏、<!--RP15-->三键导航栏<!--RP15End-->的显示或隐藏已完成。主窗口在非全屏/最大化模式（自由悬浮窗口模式、分屏等场景）下配置不生效，进入全屏/最大化模式后配置生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：**

在OpenHarmony 5.0.0之前，该接口在所有设备中可正常调用。

从OpenHarmony 5.0.0开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| names | Array<'status'\|'navigation'> | 是 | 设置窗口全屏/最大化模式时状态栏、<!--RP15-->三键导航栏<!--RP15End-->是否显示。<br>例如，需全部显示，该参数设置为['status',&nbsp;'navigation']；设置为[]，则不显示。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// 此处以状态栏等均不显示为例
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let names: Array<'status' | 'navigation'> = [];
      try {
        let promise = windowClass.setWindowSystemBarEnable(names);
        promise.then(() => {
          console.info('Succeeded in setting the system bar to be invisible.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the system bar to be invisible. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setSpecificSystemBarEnabled<sup>11+</sup>

setSpecificSystemBarEnabled(name: SpecificSystemBar, enable: boolean, enableAnimation?: boolean): Promise&lt;void&gt;

设置主窗口状态栏、<!--RP15-->三键导航栏<!--RP15End-->的显示或隐藏，使用Promise异步回调。

调用生效后返回并不表示状态栏、<!--RP15-->三键导航栏<!--RP15End-->的显示或隐藏已完成。子窗口调用后不生效。主窗口在非全屏/最大化模式（自由悬浮窗口模式、分屏等场景）下配置不生效，进入全屏/最大化模式后配置生效。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**设备行为差异：**

在OpenHarmony 5.0.0之前，该接口在所有设备中可正常调用。

从OpenHarmony 5.0.0开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| name  | [SpecificSystemBar](arkts-apis-window-t.md#specificsystembar11) | 是 | 设置窗口全屏模式时，显示或隐藏的系统栏类型。 |
| enable  | boolean | 是 | 设置窗口全屏模式时状态栏或<!--RP15-->三键导航栏<!--RP15End-->是否显示，true表示显示， false表示隐藏。|
| enableAnimation<sup>12+</sup>  | boolean | 否 | 设置状态栏或<!--RP15-->三键导航栏<!--RP15End-->显示状态变化时是否使用动画，true表示使用， false表示不使用，默认值为false。|

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// 此处以隐藏状态栏为例
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';


export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let promise = windowClass.setSpecificSystemBarEnabled('status', false);
        promise.then(() => {
          console.info('Succeeded in setting the system bar to be invisible.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the system bar to be invisible. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setWindowSystemBarProperties<sup>9+</sup>

setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

设置主窗口<!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性，使用Promise异步回调。

子窗口调用后不生效。主窗口在非全屏/最大化模式（自由悬浮窗口模式、分屏等场景）下配置不生效，进入全屏/最大化模式后配置生效。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| systemBarProperties | [SystemBarProperties](arkts-apis-window-i.md#systembarproperties) | 是   | <!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let SystemBarProperties: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // 以下两个属性从API Version8开始支持
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#00ffff'
      };
      try {
        let promise = windowClass.setWindowSystemBarProperties(SystemBarProperties);
        promise.then(() => {
          console.info('Succeeded in setting the system bar properties.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the system bar properties. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## getWindowSystemBarProperties<sup>12+</sup>

getWindowSystemBarProperties(): SystemBarProperties

获取主窗口<!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------------------------------------- | ------------- |
| [SystemBarProperties](arkts-apis-window-i.md#systembarproperties) | 当前<!--Del-->三键导航栏、<!--DelEnd-->状态栏属性。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. Possible cause: Create js object failed. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |


**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let systemBarProperty = windowClass.getWindowSystemBarProperties();
        console.info('Success in obtaining system bar properties. Property: ' + JSON.stringify(systemBarProperty));
      } catch (err) {
        console.error(`Failed to get system bar properties. Code: ${err.code}, message: ${err.message}`);
      }
    });
  }
};
```

## setStatusBarColor<sup>18+</sup>

setStatusBarColor(color: ColorMetrics): Promise&lt;void&gt;

设置主窗口状态栏的文字颜色，使用Promise异步回调。

子窗口不支持设置状态栏文字颜色，调用无效果。主窗口在非全屏/最大化模式（自由悬浮窗口模式、分屏等场景）下配置不生效，进入全屏/最大化模式后配置生效。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| color | [ColorMetrics](js-apis-arkui-graphics.md#colormetrics12) | 是   | 要设置的状态栏文字颜色值。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported on this device. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal task error. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics, window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let promise = windowClass.setStatusBarColor(ColorMetrics.numeric(0x112233));
        promise.then(() => {
          console.info('Succeeded in setting the status bar color.');
        }).catch((err: BusinessError) => {
          console.error(`Set the status bar color failed. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the status bar color. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## getStatusBarProperty<sup>18+</sup>

getStatusBarProperty(): StatusBarProperty

获取主窗口状态栏的属性，如状态栏文字颜色。

子窗口不支持查询，调用会返回错误码1300004。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------------------------------------- | ------------- |
| [StatusBarProperty](arkts-apis-window-i.md#statusbarproperty18) | 当前状态栏属性，如状态栏颜色。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let statusBarProperty = windowClass.getStatusBarProperty();
        console.info('Succeeded in obtaining system bar properties. Property: ' + JSON.stringify(statusBarProperty));
      } catch (err) {
        console.error(`Failed to get system bar properties. Code: ${err.code}, message: ${err.message}`);
      }
    });
  }
};
```

## getWindowStateSnapshot<sup>23+</sup>

getWindowStateSnapshot(): Promise&lt;string&gt;

获取当前窗口的设备形态信息，比如是否处于[电脑模式](../../windowmanager/window-terminology.md#pc-mode电脑模式)，是否支持自由窗口等，使用Promise异步回调，仅限测试使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ------------------------------------- | ------------- |
| Promise&lt;string&gt; | 返回当前窗口的设备形态信息，是JSON对象序列化后的结果，使用时需要先反序列化成JSON对象。返回示例：`{"isPcMode":false,"isSupportFreeWindowMode":true,"systemUiVisible":"1100"}`。<br/>返回值包含的不同字段的含义如下： <br/>- isPcMode：表示当前设备是否处于[电脑模式](../../windowmanager/window-terminology.md#pc-mode电脑模式)，true表示处于[电脑模式](../../windowmanager/window-terminology.md#pc-mode电脑模式)，false表示不处于[电脑模式](../../windowmanager/window-terminology.md#pc-mode电脑模式)。当前在PC/2in1设备上返回true。<br/>- isSupportFreeWindowMode：表示当前设备是否支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)，true表示支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)，false表示不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)。<br/>- systemUiVisible：表示系统UI的显隐状态，是由0和1组成的长度为4的字符串，其中0表示隐藏，1表示显示。从左到右，第一位表示状态栏的显隐状态，第二位表示导航条的显隐状态，<!--RP17-->第三位在OpenHarmony设备上暂不支持，默认值为0，第四位表示三键导航栏的显隐状态。<!--RP17End-->|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801      | Capability not supported. Failed to call the api due to limited device capabilities. Possible cause: The device does not support the api itself. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. Possible cause: The internal services of the window are not started normally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.getWindowStateSnapshot().then((data) => {
    let jsonObj: object = JSON.parse(data);
    console.info(`Succeeded, data=${data}, isPcMode=${jsonObj["isPcMode"]}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed. Cause code: ${err.code}, cancel message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Panic. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

设置主窗口的显示方向属性，使用callback异步回调。相关横竖屏开发实践查询[横竖屏切换](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-landscape-and-portrait-development)。非主窗口调用后不生效不报错。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**设备行为差异：**

- 设备支持sensor旋转且未处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态：立即生效。
- 设备支持sensor旋转且处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态：调用不生效不报错，切换到非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效。
- 其他情况：不生效不报错。

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| orientation         | [Orientation](arkts-apis-window-e.md#orientation9)                | 是   | 窗口显示方向的属性。         |
| callback            | AsyncCallback&lt;void&gt;                   | 是   | 回调函数。该回调函数返回调用结果是否成功，非应用旋转动效结束。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                              |
|---------|-------------------------------------------------------------------------------------------------------------------|
| 401     | Parameter error. Possible cause: Invalid parameter value range.                                                   |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let orientation = window.Orientation.AUTO_ROTATION;
      try {
        windowClass.setPreferredOrientation(orientation, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set window orientation. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting window orientation.');
        });
      } catch (exception) {
        console.error(`Failed to set window orientation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation): Promise&lt;void&gt;

设置主窗口的显示方向属性，使用Promise异步回调。非主窗口调用后不生效不报错。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**设备行为差异：**

- 设备支持sensor旋转且未处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态：立即生效。
- 设备支持sensor旋转且处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态：调用不生效不报错，切换到非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效。
- 其他情况：不生效不报错。

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| orientation         | [Orientation](arkts-apis-window-e.md#orientation9)                | 是   | 窗口显示方向的属性。       |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                              |
|---------|-------------------------------------------------------------------------------------------------------------------|
| 401     | Parameter error. Possible cause: Invalid parameter value range.                                                   |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let orientation = window.Orientation.AUTO_ROTATION;
      try {
        let promise = windowClass.setPreferredOrientation(orientation);
        promise.then(() => {
          console.info('Succeeded in setting the window orientation.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window orientation. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set window orientation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setPreferredOrientationWithResult

setPreferredOrientationWithResult(orientation: Orientation): Promise&lt;OrientationResult&gt;

设置主窗口的显示方向属性，通过Promise异步返回显示方向的执行结果。非主窗口调用后不生效，OrientationResult返回window.[OrientationExecutionResult](arkts-apis-window-e.md#orientationexecutionresult).ORIENTATION_IGNORED。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**设备行为差异：**

- 设备支持sensor旋转且未处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态：立即生效。
- 设备支持sensor旋转且处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态：调用不生效，切换到非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效。
- 其他情况：不生效不报错。

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| orientation         | [Orientation](arkts-apis-window-e.md#orientation9)                | 是   | 窗口显示方向的属性。       |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[OrientationResult](arkts-apis-window-i.md#orientationresult)&gt; | Promise对象。设置窗口显示方向的执行结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                              |
|---------|-------------------------------------------------------------------------------------------------------------------|
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003  | This window manager service works abnormally.                |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let orientation = window.Orientation.LANDSCAPE;
      try {
        windowClass.setPreferredOrientationWithResult(orientation).then((result: window.OrientationResult) => {
          console.info(`Succeeded in setting the window orientation. Result: ${JSON.stringify(result)}`);
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window orientation. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set window orientation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## getPreferredOrientation<sup>12+</sup>

getPreferredOrientation(): Orientation

获取窗口的显示方向属性。未指定方向时，返回window.Orientation.UNSPECIFIED。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
|------------------------------| ------------------ |
| [Orientation](arkts-apis-window-e.md#orientation9) | 窗口显示方向的属性。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                              |
|---------|-------------------------------------------------------------------------------------------------------------------|
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let orientation = windowClass.getPreferredOrientation();
      } catch (exception) {
        console.error(`Failed to get window orientation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
};
```

## getUIContext<sup>10+</sup>

getUIContext(): UIContext

获取UIContext实例。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型       | 说明                   |
| ---------- | ---------------------- |
| [UIContext](arkts-apis-uicontext-uicontext.md) | 返回UIContext实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window, UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 为主窗口加载对应的目标页面。
    windowStage.loadContent("pages/page2", (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
      // 获取应用主窗口。
      let windowClass: window.Window | undefined = undefined;
      windowStage.getMainWindow((err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        // 获取UIContext实例。
        let uiContext: UIContext | null = null;
        uiContext = windowClass.getUIContext();
      });
    });
  }
};
```

## setUIContent<sup>9+</sup>

setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void

根据当前工程中指定的某个页面路径为窗口加载具体页面内容，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------- | -- | -------------------- |
| path     | string                    | 是 | 要加载到窗口中的页面内容的路径，Stage模型下该路径需添加到工程的main_pages.json文件中，FA模型下该路径需添加到工程的config.json文件中。不支持相对路径写法，需与main_pages.json或config.json中的src取值保持一致。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。          |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally.<br/>适用版本：9                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.setUIContent('pages/page2/page3', (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in loading the content.');
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setUIContent<sup>9+</sup>

setUIContent(path: string): Promise&lt;void&gt;

根据当前工程中指定的某个页面路径为窗口加载具体页面内容，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ------ | -- | ------------------ |
| path | string | 是 | 要加载到窗口中的页面内容的路径，Stage模型下该路径需添加到工程的main_pages.json文件中，FA模型下该路径需添加到工程的config.json文件中。不支持相对路径写法，需与main_pages.json或config.json中的src取值保持一致。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.              |
| 1300003 | This window manager service works abnormally.<br/>适用版本：9                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.setUIContent('pages/page2/page3');
  promise.then(() => {
    console.info('Succeeded in loading the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

根据当前工程中指定的页面路径为窗口加载具体页面内容，通过LocalStorage传递状态属性给加载的页面，使用callback异步回调。

建议在UIAbility启动过程中使用该接口，重复调用将先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

当前UI的执行上下文可能不明确，所以不建议在本接口的回调函数中做UI相关的操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                         |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | 是   | 要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。不支持相对路径写法，需与main_pages.json中的src取值保持一致。 |
| storage  | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | 是   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |
| callback | AsyncCallback&lt;void&gt;                       | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter.|
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.    |
| 1300003 | This window manager service works abnormally.<br/>适用版本：9                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent('pages/page2', storage, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in loading the content.');
});
```

## loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage): Promise&lt;void&gt;

根据当前工程中指定的页面路径为窗口加载具体页面内容，通过LocalStorage传递状态属性给加载的页面，使用Promise异步回调。

建议在UIAbility启动过程中使用该接口，重复调用将先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

当前UI的执行上下文可能不明确，所以不建议在本接口的回调函数中做UI相关的操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                                            | 必填 | 说明                                                         |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | 是   | 要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。不支持相对路径写法，需与main_pages.json中的src取值保持一致。 |
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | 是   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter.|
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.    |
| 1300003 | This window manager service works abnormally.<br/>适用版本：9                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
let promise = windowClass.loadContent('pages/page2', storage);
promise.then(() => {
  console.info('Succeeded in loading the content.');
}).catch((err: BusinessError) => {
  console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
});
```

## loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

根据指定路由页面名称为当前窗口加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，通过LocalStorage传递状态属性至加载页面，使用callback异步回调。

建议在UIAbility启动过程中使用该接口，重复调用该接口将先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

当前UI的执行上下文可能不明确，所以不建议在本接口的回调函数中做UI相关的操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name     | string                                                  | 是   | 命名路由页面的名称。                                             |
| storage  | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | 是   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |
| callback | AsyncCallback&lt;void&gt;                               | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed.    |
| 1300003  | This window manager service works abnormally.                |

**示例：**
<!--code_no_check-->
```ts
// EntryAbility.ets

import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // 导入命名路由页面

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let storage: LocalStorage = new LocalStorage();
    let newValue: Number = 121;
    storage.setOrCreate('storageSimpleProp', newValue);
    try {
      let windowClass: window.Window = windowStage.getMainWindowSync();
      if (!windowClass) {
        console.error('Failed to get main window.');
        return;
      }
      windowClass.loadContentByName(Index.entryName, storage, (err: BusinessError) => {
        const errCode: number = err?.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err?.code}, message: ${err?.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Index {
  @State message: string = 'Hello World'
  @LocalStorageLink('storageSimpleProp') storageSimpleProp: number = 1;
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

## loadContentByName<sup>11+</sup>

loadContentByName(name: string, callback: AsyncCallback&lt;void&gt;): void

根据指定路由页面名称为当前窗口加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，使用callback异步回调。

建议在UIAbility启动过程中使用该接口，重复调用该接口将先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

当前UI的执行上下文可能不明确，所以不建议在本接口的回调函数中做UI相关的操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                      | 必填 | 说明             |
| -------- | ------------------------- | ---- | ---------------- |
| name     | string                    | 是   | 命名路由页面的名称。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。       |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally.                |

**示例：**
<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // 导入命名路由页面

try {
  (windowClass as window.Window).loadContentByName(Index.entryName, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in loading the content.');
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName})
@Component
export struct Index {
  @State message: string = 'Hello World'
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

## loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage?: LocalStorage): Promise&lt;void&gt;

根据指定路由页面名称为当前窗口加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，通过LocalStorage传递状态属性至加载页面，使用Promise异步回调。

建议在UIAbility启动过程中使用该接口，重复调用该接口将先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

当前UI的执行上下文可能不明确，所以不建议在本接口的回调函数中做UI相关的操作。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name    | string                                                  | 是   | 命名路由页面的名称。                                             |
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | 否   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性，默认值为空。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed.    |
| 1300003  | This window manager service works abnormally.                |

**示例：**
<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // 导入命名路由页面

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
try {
  let promise = (windowClass as window.Window).loadContentByName(Index.entryName, storage);
  promise.then(() => {
    console.info('Succeeded in loading the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Index {
  @State message: string = 'Hello World'
  @LocalStorageLink('storageSimpleProp') storageSimpleProp: number = 1;
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

## isWindowShowing<sup>9+</sup>

isWindowShowing(): boolean

判断当前窗口是否已显示。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------- | ------------------------------------------------------------------ |
| boolean | 当前窗口是否已显示。true表示当前窗口已显示，false则表示当前窗口未显示。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
try {
  let data = windowClass.isWindowShowing();
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
} catch (exception) {
  console.error(`Failed to check whether the window is showing. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('windowSizeChange')<sup>7+</sup>

on(type:  'windowSizeChange', callback: Callback&lt;Size&gt;): void

开启窗口尺寸变化的监听。仅在主线程调用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

> **说明：**
>
> 窗口拖动或窗口拖拽缩放后，无论窗口大小是否发生变化，均会通知应用windowSizeChange回调。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowSizeChange'，即窗口尺寸变化事件。 |
| callback | Callback&lt;[Size](arkts-apis-window-i.md#size7)&gt; | 是   | 回调函数。返回当前的窗口尺寸。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
try {
  windowClass.on('windowSizeChange', (data) => {
    console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('windowSizeChange')<sup>7+</sup>

off(type: 'windowSizeChange', callback?: Callback&lt;Size&gt;): void

关闭窗口尺寸变化的监听。仅在主线程调用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                     |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | 是   | 监听事件，固定为'windowSizeChange'，即窗口尺寸变化事件。 |
| callback | Callback&lt;[Size](arkts-apis-window-i.md#size7)&gt; | 否   | 回调函数。返回当前的窗口尺寸。如果传入参数，则关闭该监听。如果未传入参数，则关闭窗口尺寸变化的监听。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**示例：**

```ts
const callback = (size: window.Size) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('windowSizeChange', callback);
  // 关闭指定callback的监听
  windowClass.off('windowSizeChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('windowSizeChange');
} catch (exception) {
  console.error(`Failed to disable the listener for window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('avoidAreaChange')<sup>9+</sup>

on(type: 'avoidAreaChange', callback: Callback&lt;AvoidAreaOptions&gt;): void

开启当前应用窗口系统避让区域变化的监听。

全局悬浮窗、模态窗或系统窗口：
- 仅在调用[setSystemAvoidAreaEnabled](#setsystemavoidareaenabled18)方法使能后，才能通过此接口获取避让区域。

<!--RP7-->常见的触发避让区回调的场景如下：应用窗口在全屏模式、悬浮模式、分屏模式之间的切换；应用窗口旋转；可折叠设备在屏幕折叠状态发生变化；应用窗口在多设备之间的流转。<!--RP7End-->

> **说明：**
>
> TV 设备不显示状态栏。若未显式设置状态栏隐藏，调用该接口仍可获取状态栏对应的避让区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                  |
| -------- |----------------------------------| ---- |--------------------------------------|
| type     | string                           | 是   | 监听事件，固定为'avoidAreaChange'，即系统避让区变化事件。 |
| callback | Callback&lt;[AvoidAreaOptions](arkts-apis-window-i.md#avoidareaoptions12)&gt; | 是   | 回调函数。返回当前避让区以及避让区类型。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
try {
  windowClass.on('avoidAreaChange', (data) => {
    console.info('Succeeded in enabling the listener for system avoid area changes. type:' +
    JSON.stringify(data.type) + ', area: ' + JSON.stringify(data.area));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for system avoid area changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('avoidAreaChange')<sup>9+</sup>

off(type: 'avoidAreaChange', callback?: Callback&lt;AvoidAreaOptions&gt;): void

关闭当前窗口系统避让区变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                |
| -------- |----------------------------------|------|------------------------------------|
| type     | string                           | 是   | 监听事件，固定为'avoidAreaChange'，即系统避让区变化事件。 |
| callback | Callback&lt;[AvoidAreaOptions](arkts-apis-window-i.md#avoidareaoptions12)&gt; | 否   | 回调函数。返回当前避让区以及避让区类型。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有系统避让区变化的监听。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed. |

**示例：**

```ts
interface Param {
  type: window.AvoidAreaType,
  area: window.AvoidArea
}
const callback = (data: Param) => {
  // ...
}
try {
  windowClass.on('avoidAreaChange', callback);

  windowClass.off('avoidAreaChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('avoidAreaChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for system avoid area changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('keyboardHeightChange')<sup>7+</sup>

on(type: 'keyboardHeightChange', callback: Callback&lt;number&gt;): void

开启固定态软键盘高度变化的监听。当软键盘从本窗口唤出且与窗口有重叠区域时，通知键盘高度变化。从API version 10开始，有关将软键盘设置为固定态或悬浮态的方法，请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                        |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | 是   | 监听事件，固定为'keyboardHeightChange'，即键盘高度变化事件。 |
| callback | Callback&lt;number&gt; | 是   | 回调函数。返回当前的键盘高度。返回值为整数，单位为px。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.on('keyboardHeightChange', (data) => {
    console.info('Succeeded in enabling the listener for keyboard height changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for keyboard height changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('keyboardHeightChange')<sup>7+</sup>

off(type: 'keyboardHeightChange', callback?: Callback&lt;number&gt;): void

关闭固定态软键盘高度变化的监听，使应用程序不再接收键盘高度变化的通知。从API version 10开始，有关将软键盘设置为固定态或悬浮态的方法，请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'keyboardHeightChange'，即键盘高度变化事件。 |
| callback | Callback&lt;number&gt; | 否   | 回调函数。返回当前的键盘高度，返回值为整数，单位为px。若传入参数，则关闭该监听；未传入参数，则关闭所有固定态软键盘高度变化的监听。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (height: number) => {
  // ...
}
try {
  windowClass.on('keyboardHeightChange', callback);

  windowClass.off('keyboardHeightChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('keyboardHeightChange');
} catch (exception) {
  console.error(`Failed to disable the listener for keyboard height changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('keyboardWillShow')<sup>20+</sup>

on(type: 'keyboardWillShow', callback: Callback&lt;KeyboardInfo&gt;): void

开启固定态软键盘即将开始显示的监听。此监听在固定态软键盘即将开始显示或软键盘由悬浮态切换为固定态时触发，仅对当前拉起或隐藏固定态软键盘的应用窗口生效。对于虚拟屏上应用拉起输入法键盘到主屏上，输入法键盘显隐通知只会给主屏上获焦窗口，而不是虚拟屏上应用窗口。

改变软键盘为固定态或者悬浮态方法详细介绍请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和PC/2in1设备上可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名   | 类型                | 必填 | 说明                                        |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | 是   | 监听事件，固定为'keyboardWillShow'，即固定态软键盘即将开始显示的事件。 |
| callback | Callback&lt;[KeyboardInfo](arkts-apis-window-i.md#keyboardinfo18)&gt; | 是   | 回调函数。返回软键盘窗口信息。                    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardWillShow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  console.info(`Keyboard will show animation. keyboardInfo: ` + JSON.stringify(keyboardInfo));
}
try {
  windowClass.on('keyboardWillShow', callback);
  console.info(`Register keyboard will show animation success`);
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('keyboardWillShow')<sup>20+</sup>

off(type: 'keyboardWillShow', callback?: Callback&lt;KeyboardInfo&gt;): void

关闭固定态软键盘即将开始显示的监听。改变输入法窗口为固定态或者悬浮态方法详细介绍请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和PC/2in1设备上可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'keyboardWillShow'，即固定态软键盘即将开始显示的事件。 |
| callback | Callback&lt;[KeyboardInfo](arkts-apis-window-i.md#keyboardinfo18)&gt; | 否   |  回调函数。返回软键盘窗口信息。若传入参数，则关闭该监听。如果未传入参数，则关闭所有固定态软键盘即将开始显示的监听。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardWillShow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  console.info(`Keyboard will show animation. keyboardInfo: ` + JSON.stringify(keyboardInfo));
}
try {
  windowClass.on('keyboardWillShow', callback);
  windowClass.off('keyboardWillShow', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('keyboardWillShow');
  console.info(`Unregister keyboard will show animation success`);
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('keyboardWillHide')<sup>20+</sup>

on(type: 'keyboardWillHide', callback: Callback&lt;KeyboardInfo&gt;): void

开启固定态软键盘即将开始隐藏的监听。此监听在固定态软键盘即将开始隐藏或软键盘由固定态切换为悬浮态时触发，仅对当前拉起或隐藏固定态软键盘的应用窗口生效。对于虚拟屏上应用拉起输入法键盘到主屏上，输入法键盘显隐通知只会给主屏上获焦窗口，而不是虚拟屏上应用窗口。

改变软键盘为固定态或者悬浮态方法详细介绍请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和PC/2in1设备上可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名   | 类型                | 必填 | 说明                                        |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | 是   | 监听事件，固定为'keyboardWillHide'，即固定态软键盘即将开始隐藏的事件。 |
| callback | Callback&lt;[KeyboardInfo](arkts-apis-window-i.md#keyboardinfo18)&gt; | 是   | 回调函数。返回软键盘窗口信息。                    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardWillHide can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  console.info(`Keyboard will hide animation. keyboardInfo: ` + JSON.stringify(keyboardInfo));
}
try {
  windowClass.on('keyboardWillHide', callback);
  console.info(`Register keyboard will hide animation success`);
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('keyboardWillHide')<sup>20+</sup>

off(type: 'keyboardWillHide', callback?: Callback&lt;KeyboardInfo&gt;): void

关闭固定态软键盘即将开始隐藏的监听。改变输入法窗口为固定态切换至悬浮态方法详细介绍请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和PC/2in1设备上可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'keyboardWillHide'，即固定态软键盘即将开始隐藏的事件。 |
| callback | Callback&lt;[KeyboardInfo](arkts-apis-window-i.md#keyboardinfo18)&gt; | 否   |  回调函数。返回软键盘窗口信息。若传入参数，则关闭该监听。如果未传入参数，则关闭所有固定态软键盘即将开始隐藏的监听。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardWillHide can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  console.info(`Keyboard will hide animation. keyboardInfo: ` + JSON.stringify(keyboardInfo));
}
try {
  windowClass.on('keyboardWillHide', callback);
  windowClass.off('keyboardWillHide', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('keyboardWillHide');
  console.info(`Unregister keyboard will hide animation success`);
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('keyboardDidShow')<sup>18+</sup>

on(type: 'keyboardDidShow', callback: Callback&lt;KeyboardInfo&gt;): void

开启固定态软键盘显示动画完成的监听。此监听在固定态软键盘显示动画完成或软键盘由悬浮态切换至固定态时触发，仅对当前拉起或隐藏固定态软键盘的应用窗口生效。对于虚拟屏上应用拉起输入法键盘到主屏上，输入法键盘显隐通知只会给主屏上获焦窗口，而不是虚拟屏上应用窗口。

改变软键盘为固定态或者悬浮态方法详细介绍请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和PC/2in1设备上可正常调用，在其他设备中不报错不生效。

**参数：**

| 参数名   | 类型                | 必填 | 说明                                        |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | 是   | 监听事件，固定为'keyboardDidShow'，即固定态软键盘显示动画完成事件。 |
| callback | Callback&lt;[KeyboardInfo](arkts-apis-window-i.md#keyboardinfo18)&gt; | 是   | 回调函数。返回软键盘窗口信息。                    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardDidShow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.on('keyboardDidShow', (keyboardInfo) => {
    console.info('keyboard show animation completion. keyboardInfo: ' + JSON.stringify(keyboardInfo));
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('keyboardDidShow')<sup>18+</sup>

off(type: 'keyboardDidShow', callback?: Callback&lt;KeyboardInfo&gt;): void

关闭固定态软键盘显示动画完成的监听。改变输入法窗口为固定态或者悬浮态方法详细介绍请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和PC/2in1设备上可正常调用，在其他设备中不报错不生效。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'keyboardDidShow'，即固定态软键盘显示动画完成事件。 |
| callback | Callback&lt;[KeyboardInfo](arkts-apis-window-i.md#keyboardinfo18)&gt; | 否   |  回调函数。返回软键盘窗口信息。若传入参数，则关闭该监听。如果未传入参数，则关闭所有固定态软键盘显示动画完成的监听。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardDidShow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  // ...
}
try {
  windowClass.on('keyboardDidShow', callback);
  windowClass.off('keyboardDidShow', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('keyboardDidShow');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('keyboardDidHide')<sup>18+</sup>

on(type: 'keyboardDidHide', callback: Callback&lt;KeyboardInfo&gt;): void

开启固定态软键盘隐藏动画完成的监听。此监听在固定态软键盘隐藏动画完成或软键盘由固定态切换至悬浮态时触发，仅对当前拉起或隐藏固定态软键盘的应用窗口生效。对于虚拟屏上应用拉起输入法键盘到主屏上，输入法键盘显隐通知只会给主屏上获焦窗口，而不是虚拟屏上应用窗口。

改变软键盘为固定态或者悬浮态方法详细介绍请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和PC/2in1设备上可正常调用，在其他设备中不报错不生效。

**参数：**

| 参数名   | 类型                | 必填 | 说明                                        |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | 是   | 监听事件，固定为'keyboardDidHide'，即固定态软键盘隐藏动画完成事件。 |
| callback | Callback&lt;[KeyboardInfo](arkts-apis-window-i.md#keyboardinfo18)&gt; | 是   | 回调函数。返回软键盘窗口信息。                    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardDidHide can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.on('keyboardDidHide', (keyboardInfo) => {
    console.info('keyboard hide animation completion. keyboardInfo: ' + JSON.stringify(keyboardInfo));
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('keyboardDidHide')<sup>18+</sup>

off(type: 'keyboardDidHide', callback?: Callback&lt;KeyboardInfo&gt;): void

关闭固定态软键盘隐藏动画完成的监听。改变输入法窗口为固定态切换至悬浮态方法详细介绍请参见[changeFlag](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10)。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和PC/2in1设备上可正常调用，在其他设备中不报错不生效。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'keyboardDidHide'，即固定态软键盘隐藏动画完成事件。 |
| callback | Callback&lt;[KeyboardInfo](arkts-apis-window-i.md#keyboardinfo18)&gt; | 否   |  回调函数。返回软键盘窗口信息。若传入参数，则关闭该监听。如果未传入参数，则关闭所有固定态软键盘隐藏动画完成的监听。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardDidHide can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  // ...
}
try {
  windowClass.on('keyboardDidHide', callback);
  windowClass.off('keyboardDidHide', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('keyboardDidHide');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('touchOutside')<sup>11+</sup>

on(type: 'touchOutside', callback: Callback&lt;void&gt;): void

开启本窗口区域范围外的点击事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                | 必填 | 说明                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'touchOutside'，即本窗口范围外的点击事件。 |
| callback | Callback&lt;void&gt; | 是   | 回调函数。当点击事件发生在本窗口范围之外的回调。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
try {
  windowClass.on('touchOutside', () => {
    console.info('touch outside');
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('touchOutside')<sup>11+</sup>

off(type: 'touchOutside', callback?: Callback&lt;void&gt;): void

关闭本窗口区域范围外的点击事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- |----------------------| ---- |--------------------------------------|
| type     | string               | 是   | 监听事件，固定为'touchOutside'，即本窗口范围外的点击事件。 |
| callback | Callback&lt;void&gt; | 否   | 回调函数。当点击事件发生在本窗口范围之外的回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口区域范围外的点击事件的监听。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**示例：**

```ts
const callback = () => {
  // ...
}
try {
  windowClass.on('touchOutside', callback);
  windowClass.off('touchOutside', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('touchOutside');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('screenshot')<sup>9+</sup>

on(type: 'screenshot', callback: Callback&lt;void&gt;): void

开启截屏事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'screenshot'，即截屏事件，对控制中心截屏、hdc命令截屏、整屏截屏接口生效。 |
| callback | Callback&lt;void&gt; | 是   | 回调函数。发生截屏事件时的回调。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
try {
  windowClass.on('screenshot', () => {
    console.info('screenshot happened');
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('screenshot')<sup>9+</sup>

off(type: 'screenshot', callback?: Callback&lt;void&gt;): void

关闭截屏事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'screenshot'，即截屏事件。 |
| callback | Callback&lt;void&gt; | 否   | 回调函数。发生截屏事件时的回调。若传入参数，则关闭该监听。若未传入参数，则关闭所有截屏事件的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**示例：**

```ts
let callback = () => {
  console.info('screenshot happened');
};
try {
  windowClass.on('screenshot', callback);
  windowClass.off('screenshot', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('screenshot');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('screenshotAppEvent')<sup>20+</sup>

on(type: 'screenshotAppEvent', callback: Callback&lt;ScreenshotEventType&gt;): void

开启屏幕截屏事件类型的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'screenshotAppEvent'，即屏幕截屏的事件类型，对控制中心截屏、快捷键截屏以及滚动截屏生效。 |
| callback | Callback&lt;[ScreenshotEventType](arkts-apis-window-e.md#screenshoteventtype20)&gt; | 是   | 回调函数。返回触发的截屏事件类型。                 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (eventType: window.ScreenshotEventType) => {
  console.info(`screenshotAppEvent happened. Event: ${eventType}`);
}
try {
  windowClass.on('screenshotAppEvent', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('screenshotAppEvent')<sup>20+</sup>

off(type: 'screenshotAppEvent', callback?: Callback&lt;ScreenshotEventType&gt;): void

关闭屏幕截屏事件类型的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'screenshotAppEvent'，即屏幕截屏的事件类型。 |
| callback | Callback&lt;[ScreenshotEventType](arkts-apis-window-e.md#screenshoteventtype20)&gt; | 否   | 回调函数。返回触发的截屏事件类型。若传入参数，则关闭该监听。若未传入参数，则关闭所有窗口截图事件的监听。                 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (eventType: window.ScreenshotEventType) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('screenshotAppEvent', callback);
  // 关闭指定callback的监听
  windowClass.off('screenshotAppEvent', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('screenshotAppEvent');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('dialogTargetTouch')<sup>10+</sup>

on(type: 'dialogTargetTouch', callback: Callback&lt;void&gt;): void

开启模态窗口所遮盖窗口的点击或触摸事件的监听，除模态窗口以外其他窗口调用此接口不生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                          |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'dialogTargetTouch'，即模态窗口所遮盖窗口的点击或触摸事件。 |
| callback | Callback&lt;void&gt;| 是   | 回调函数。当点击或触摸事件发生在模态窗口所遮盖窗口的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
try {
  windowClass.on('dialogTargetTouch', () => {
    console.info('touch dialog target');
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('dialogTargetTouch')<sup>10+</sup>

off(type: 'dialogTargetTouch', callback?: Callback&lt;void&gt;): void

关闭模态窗口目标窗口的点击事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                          |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'dialogTargetTouch'，即模态窗口目标窗口的点击事件。 |
| callback | Callback&lt;void&gt;      | 否   | 回调函数。当点击事件发生在模态窗口目标窗口的回调。若传入参数，则关闭该监听。若未传入参数，则关闭所有模态窗口目标窗口的点击事件的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**示例：**

```ts
const callback = () => {
  // ...
}
try {
  windowClass.on('dialogTargetTouch', callback);
  windowClass.off('dialogTargetTouch', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('dialogTargetTouch');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('windowEvent')<sup>10+</sup>

on(type: 'windowEvent', callback: Callback&lt;WindowEventType&gt;): void

开启窗口生命周期状态变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | 是   | 监听事件，固定为'windowEvent'，即窗口生命周期状态变化事件。 |
| callback | Callback&lt;[WindowEventType](arkts-apis-window-e.md#windoweventtype10)&gt; | 是   | 回调函数。返回当前的窗口生命周期状态。                 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
try {
  windowClass.on('windowEvent', (data) => {
    console.info('Window event happened. Event:' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('windowEvent')<sup>10+</sup>

off(type: 'windowEvent', callback?: Callback&lt;WindowEventType&gt;): void

关闭窗口生命周期状态变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- |------------------------------------------------------------|
| type     | string                                                     | 是   | 监听事件，固定为'windowEvent'，即窗口生命周期状态变化事件。                       |
| callback | Callback&lt;[WindowEventType](arkts-apis-window-e.md#windoweventtype10)&gt; | 否   | 回调函数。返回当前的窗口生命周期状态。若传入参数，则关闭该监听。若未传入参数，则关闭窗口所有生命周期状态变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**示例：**

```ts
const callback = (windowEventType: window.WindowEventType) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('windowEvent', callback);
  // 关闭指定callback的监听
  windowClass.off('windowEvent', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('windowEvent');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('displayIdChange')<sup>14+</sup>

on(type: 'displayIdChange', callback: Callback&lt;number&gt;): void

开启本窗口所处屏幕变化事件的监听。比如，当前窗口移动到其他屏幕时，可以从此接口监听到这个行为（非实时通知，如跨屏拖拽时需要抬手后才会触发回调通知）。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 监听事件，固定为'displayIdChange'，即本窗口所处屏幕变化的事件。 |
| callback | Callback&lt;number&gt;   | 是   | 回调函数。当本窗口所处屏幕发生变化后的回调。回调函数返回number类型参数，表示窗口所处屏幕的displayId。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |

**示例：**

```ts
try {
  windowClass.on('displayIdChange', (data) => {
    console.info('Window displayId changed, displayId=' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
## off('displayIdChange')<sup>14+</sup>

off(type: 'displayIdChange', callback?: Callback&lt;number&gt;): void

关闭本窗口所处屏幕变化事件的监听。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                     | 是   | 监听事件，固定为'displayIdChange'，即本窗口所处屏幕变化的事件。 |
| callback | Callback&lt;number&gt;    | 否   | 回调函数。当本窗口所处屏幕发生变化时的回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口所处屏幕变化事件的回调。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |

**示例：**

```ts
const callback = (displayId: number) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('displayIdChange', callback);
  // 关闭指定callback的监听
  windowClass.off('displayIdChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('displayIdChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('windowVisibilityChange')<sup>11+</sup>

on(type: 'windowVisibilityChange', callback: Callback&lt;boolean&gt;): void

开启本窗口可见状态变化事件的监听。本接口返回的可见性与肉眼所见的可见性可能存在区别，如以下场景：
- 非主窗口的阴影区域（可分别通过[setWindowShadowEnabled](arkts-apis-window-Window.md#setwindowshadowenabled20)和[setWindowShadowRadius](arkts-apis-window-Window.md#setwindowshadowradius17)设置是否显示阴影以及对应的阴影半径）被挡住也算遮挡，此时肉眼所见虽是完全可见，但实际返回的是部分可见。
- 上层窗口带有透明效果时（包括完全不透明之外的所有透明程度）不会遮挡下层窗口，此时下层窗口是可见的。
- 窗口通过[setWindowMask](arkts-apis-window-Window.md#setwindowmask12)接口设置异形窗口蒙层时，不会影响窗口可见状态计算，窗口仍可见，即使掩码全部设置为0，窗口依然按照其原本矩形大小参与可见状态计算。
- 大多数处于动画效果下的窗口也不会遮挡住下层窗口，比如在手机设备上拖动智慧多窗悬浮窗时返回的下层窗口依然是可见的。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 监听事件，固定为'windowVisibilityChange'，即本窗口可见状态变化的事件。 |
| callback | Callback&lt;boolean&gt;   | 是   | 回调函数。当本窗口可见状态发生变化后的回调。回调函数返回boolean类型参数，当返回参数为true时表示窗口可见，否则表示窗口不可见。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  windowClass.on('windowVisibilityChange', (boolean) => {
    console.info('Window visibility changed, isVisible=' + boolean);
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('windowVisibilityChange')<sup>11+</sup>

off(type: 'windowVisibilityChange', callback?: Callback&lt;boolean&gt;): void

关闭本窗口可见状态变化事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                     | 是   | 监听事件，固定为'windowVisibilityChange'，即本窗口可见状态变化的事件。 |
| callback | Callback&lt;boolean&gt;    | 否   | 回调函数。当本窗口可见状态发生变化时的回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口可见状态变化事件的回调。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (bool: boolean) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('windowVisibilityChange', callback);
  // 关闭指定callback的监听
  windowClass.off('windowVisibilityChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('windowVisibilityChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('occlusionStateChanged')<sup>22+</sup>

on(type: 'occlusionStateChanged', callback: Callback&lt;OcclusionState&gt;): void

开启窗口可见性状态变化事件的监听。本接口返回的可见性与肉眼所见的可见性可能存在区别，如以下场景：
- 非主窗口的阴影区域（可分别通过[setWindowShadowEnabled](arkts-apis-window-Window.md#setwindowshadowenabled20)和[setWindowShadowRadius](arkts-apis-window-Window.md#setwindowshadowradius17)设置是否显示阴影以及对应的阴影半径）被挡住也算遮挡，此时肉眼所见虽是完全可见，但实际返回的是部分可见。
- 上层窗口带有透明效果时（包括完全不透明之外的所有透明程度）不会遮挡下层窗口，此时下层窗口是可见的。
- 窗口通过[setWindowMask](arkts-apis-window-Window.md#setwindowmask12)接口设置异形窗口蒙层时，不会影响窗口可见状态计算，窗口仍可见，即使掩码全部设置为0，窗口依然按照其原本矩形大小参与可见状态计算。
- 大多数处于动画效果下的窗口也不会遮挡住下层窗口，比如在手机设备上拖动智慧多窗悬浮窗时返回的下层窗口依然是可见的。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'occlusionStateChanged'，即窗口可见性变化事件。 |
| callback | Callback&lt;[OcclusionState](arkts-apis-window-e.md#occlusionstate22)&gt; | 是   | 窗口可见性变化时的回调函数。详情见[可见性状态](arkts-apis-window-e.md#occlusionstate22)。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  let callback: Callback<window.OcclusionState> = (data: window.OcclusionState) => {
    console.info(`Window occlusion state changed: ${data}`);
  };
  windowClass.on('occlusionStateChanged', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('occlusionStateChanged')<sup>22+</sup>

off(type: 'occlusionStateChanged', callback?: Callback&lt;OcclusionState&gt;): void

关闭窗口可见性状态变化事件的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'occlusionStateChanged'，即窗口可见性变化事件。 |
| callback | Callback&lt;[OcclusionState](arkts-apis-window-e.md#occlusionstate22)&gt; | 否   | 若传入参数，则关闭该监听。若未传入参数，则关闭所有窗口可见性变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  let callback: Callback<window.OcclusionState> = (data: window.OcclusionState) => {
    console.info(`Window occlusion state changed: ${data}`);
  };
  // 通过on接口开启监听
  windowClass.on('occlusionStateChanged', callback);
  // 关闭指定callback的监听
  windowClass.off('occlusionStateChanged', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('occlusionStateChanged');
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('frameMetricsMeasured')<sup>22+</sup>

on(type: 'frameMetricsMeasured', callback: Callback&lt;FrameMetrics&gt;): void

开启窗口帧率指标变化事件的监听。该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

应用注册帧率变化监听后，只有当客户端UI内容发生重绘时（如页面切换、和可响应组件交互、设置背景色和透明度等），才会触发注册的回调。但当同时使用该接口和[postFrameCallback](arkts-apis-uicontext-uicontext.md#postframecallback12)、[postDelayedFrameCallback](arkts-apis-uicontext-uicontext.md#postdelayedframecallback12)、[displaySync.on('frame')](../apis-arkgraphics2d/js-apis-graphics-displaySync.md#onframe)中的任意一个时，即使无UI内容重绘，也可能触发回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件类型，固定为'frameMetricsMeasured'，即窗口帧率指标变化事件。 |
| callback | Callback&lt;[FrameMetrics](arkts-apis-window-i.md#framemetrics22)&gt; | 是  | 窗口帧率指标变化时的回调函数。详情见帧率指标[FrameMetrics](arkts-apis-window-i.md#framemetrics22)。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**示例：**

```ts
try {
  let callback: Callback<window.FrameMetrics> = (data: window.FrameMetrics) => {
    console.info(`Window frame metrics changed: ${JSON.stringify(data)}`);
  };
  windowClass.on('frameMetricsMeasured', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('frameMetricsMeasured')<sup>22+</sup>

off(type: 'frameMetricsMeasured', callback?: Callback&lt;FrameMetrics&gt;): void

关闭窗口帧率指标变化事件的监听。该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件类型，固定为'frameMetricsMeasured'，即窗口帧率指标变化事件。 |
| callback | Callback&lt;[FrameMetrics](arkts-apis-window-i.md#framemetrics22)&gt; | 否  | 若传入参数，则关闭该监听。若未传入参数，则关闭所有窗口帧率指标变化的监听。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**示例：**

```ts
try {
  let callback: Callback<window.FrameMetrics> = (data: window.FrameMetrics) => {
    console.info(`Window frame metrics changed: ${JSON.stringify(data)}`);
  };
  // 通过on接口开启监听
  windowClass.on('frameMetricsMeasured', callback);
  // 关闭指定callback的监听
  windowClass.off('frameMetricsMeasured', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('frameMetricsMeasured');
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('systemDensityChange')<sup>15+</sup>

on(type: 'systemDensityChange', callback: Callback&lt;number&gt;): void

开启本窗口所处屏幕的系统显示大小缩放系数变化事件的监听。比如，当调整窗口所处屏幕的显示大小缩放系数时，可以从此接口监听到这个行为。

在接口回调函数中，建议直接使用返回值进行vp和px的转换。例如，若返回值为density，计算px可使用vp * density = px。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 监听事件，固定为'systemDensityChange'，即本窗口所处屏幕的系统显示大小缩放系数变化的事件。 |
| callback | Callback&lt;number&gt;   | 是   | 回调函数。当本窗口所处屏幕的系统显示大小缩放系数发生变化后的回调。回调函数返回number类型参数，表示当前窗口所处屏幕的系统显示大小缩放系数。                               |

**错误码：**


以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |

**示例：**

```ts
const callback = (density: number) => {
  console.info('System density changed, density=' + JSON.stringify(density));
  // 通过回调返回值计算px
  let vp = 100;
  let px = vp * density;
}
try {
  windowClass.on('systemDensityChange', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
## off('systemDensityChange')<sup>15+</sup>

off(type: 'systemDensityChange', callback?: Callback&lt;number&gt;): void

关闭本窗口所处屏幕的系统显示大小缩放系数变化事件的监听。

在接口回调函数中，建议直接使用返回值进行vp和px的转换。例如，若返回值为density，计算px可使用vp * density = px。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                     | 是   | 监听事件，固定为'systemDensityChange'，即本窗口所处屏幕的系统显示大小缩放系数变化的事件。 |
| callback | Callback&lt;number&gt;    | 否   | 回调函数。当本窗口所处屏幕的系统显示大小缩放系数发生变化后的回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口所处屏幕的系统显示大小缩放系数变化事件的回调。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |

**示例：**

```ts
const callback = (density: number) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('systemDensityChange', callback);
  // 关闭指定callback的监听
  windowClass.off('systemDensityChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('systemDensityChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('noInteractionDetected')<sup>12+</sup>

on(type: 'noInteractionDetected', timeout: number, callback: Callback&lt;void&gt;): void

开启本窗口在指定超时时间内无交互事件的监听，交互事件支持物理键盘输入事件和屏幕触控点击事件，不支持软键盘输入事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 监听事件，固定为'noInteractionDetected'，即本窗口在指定超时时间内无交互的事件。 |
| timeout     | number                    | 是   | 指定本窗口在多长时间内无交互即回调，单位为秒(s)。该参数仅支持整数输入，负数和小数为非法参数。 |
| callback | Callback&lt;void&gt;      | 是   | 回调函数。当本窗口在指定超时时间内无交互事件时的回调。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed; |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  windowClass.on('noInteractionDetected', 60, () => {
    console.info('no interaction in 60s');
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('noInteractionDetected')<sup>12+</sup>

off(type: 'noInteractionDetected', callback?: Callback&lt;void&gt;): void

关闭本窗口在指定超时时间内无交互事件的监听，交互事件支持物理键盘输入事件和屏幕触控点击事件，不支持软键盘输入事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                     | 是   | 监听事件，固定为'noInteractionDetected'，即本窗口在指定超时时间内无交互的事件。 |
| callback | Callback&lt;void&gt;    | 否   | 回调函数，当本窗口在指定超时时间内无交互事件时的回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口在指定超时时间内无交互事件的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed; |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = () => {
  // ...
}
try {
  windowClass.on('noInteractionDetected', 60, callback);
  windowClass.off('noInteractionDetected', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('noInteractionDetected');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('windowStatusChange')<sup>11+</sup>

on(type:  'windowStatusChange', callback: Callback&lt;WindowStatusType&gt;): void

开启窗口模式变化的监听，当窗口windowStatus发生变化时进行通知（此时窗口属性可能还没有更新，如果需要在收到windowStatus变化通知时能够立即获取到变化后的窗口大小、位置，建议使用[on('windowStatusDidChange')](arkts-apis-window-Window.md#onwindowstatusdidchange20)）。

使用当前接口开启监听后，在调用maximize、recover方法时会收到多次回调，如需获取去重后的回调，可使用[on('windowStatusDidChange')](#onwindowstatusdidchange20)。

> **说明：**
>
> 在[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，应用的[targetAPIVersion](../../quick-start/app-configuration-file.md#配置文件标签)设置小于14时，在窗口最大化状态（窗口铺满整个屏幕，2in1设备会有dock栏和状态栏，Tablet设备会有状态栏）时返回值对应为WindowStatusType::FULL_SCREEN。应用的[targetAPIVersion](../../quick-start/app-configuration-file.md#配置文件标签)设置大于等于14时，在窗口最大化状态（窗口铺满整个屏幕，2in1设备会有dock栏和状态栏，Tablet设备会有状态栏）时返回值对应为WindowStatusType::MAXIMIZE。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowStatusChange'，即窗口模式变化事件。 |
| callback | Callback&lt;[WindowStatusType](arkts-apis-window-e.md#windowstatustype11)&gt; | 是   | 回调函数。返回当前的窗口模式。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
try {
    windowClass.on('windowStatusChange', (WindowStatusType) => {
        console.info('Succeeded in enabling the listener for window status changes. Data: ' + JSON.stringify(WindowStatusType));
    });
} catch (exception) {
    console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('windowStatusChange')<sup>11+</sup>

off(type: 'windowStatusChange', callback?: Callback&lt;WindowStatusType&gt;): void

关闭窗口模式变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                     |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | 是   | 监听事件，固定为'windowStatusChange'，即窗口模式变化事件。 |
| callback | Callback&lt;[WindowStatusType](arkts-apis-window-e.md#windowstatustype11)&gt; | 否   | 回调函数。返回当前的窗口模式。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有窗口模式变化的监听。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |

**示例：**

```ts
const callback = (windowStatusType: window.WindowStatusType) => {
    // ...
}
try {
    windowClass.on('windowStatusChange', callback);
    windowClass.off('windowStatusChange', callback);
    // 如果通过on开启多个callback进行监听，同时关闭所有监听：
    windowClass.off('windowStatusChange');
} catch (exception) {
    console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('windowStatusDidChange')<sup>20+</sup>

on(type: 'windowStatusDidChange', callback: Callback&lt;WindowStatusType&gt;): void

开启窗口模式变化的监听，当窗口windowStatus发生变化后进行通知（此时窗口[Rect](arkts-apis-window-i.md#rect7)属性已经完成更新）。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowStatusDidChange'，即窗口模式变化完成事件。 |
| callback | Callback&lt;[WindowStatusType](arkts-apis-window-e.md#windowstatustype11)&gt; | 是   | 回调函数。返回当前的窗口模式。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**示例：**

```ts
try {
    windowClass.on('windowStatusDidChange', (WindowStatusType) => {
        console.info(`Succeeded in enabling the listener for window status changes. Data: ${JSON.stringify(WindowStatusType)}`);
    });
} catch (exception) {
    console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('windowStatusDidChange')<sup>20+</sup>

off(type: 'windowStatusDidChange', callback?: Callback&lt;WindowStatusType&gt;): void

关闭窗口模式变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                     |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | 是   | 监听事件，固定为'windowStatusDidChange'，即窗口模式变化完成事件。 |
| callback | Callback&lt;[WindowStatusType](arkts-apis-window-e.md#windowstatustype11)&gt; | 否   | 回调函数。返回当前的窗口模式。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有窗口模式变化的监听。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**示例：**

```ts
const callback = (windowStatusType: window.WindowStatusType) => {
    // ...
}
try {
    windowClass.on('windowStatusDidChange', callback);
    windowClass.off('windowStatusDidChange', callback);
    // 如果通过on开启多个callback进行监听，同时关闭所有监听：
    windowClass.off('windowStatusDidChange');
} catch (exception) {
    console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowGrayScale<sup>12+</sup>

setWindowGrayScale(grayScale: number): Promise&lt;void&gt;

设置窗口灰阶，使用Promise异步回调。该接口需要在调用[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)使窗口加载页面内容后调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明                                     |
| --------- | ------ | -- | ---------------------------------------- |
| grayScale | number | 是 | 窗口灰阶。该参数为浮点数，取值范围为[0.0, 1.0]。0.0表示窗口图像无变化，1.0表示窗口图像完全转为灰度图像，0.0至1.0之间时效果呈线性变化。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass?.setUIContent('pages/Index', (error: BusinessError) => {
  if (error.code) {
    console.error(`Failed to set the content. Cause code: ${error.code}`);
    return;
  }
  console.info('Succeeded in setting the content.');
  let grayScale: number = 0.5;
  try {
    if (canIUse("SystemCapability.Window.SessionManager")) {
      let promise = windowClass?.setWindowGrayScale(grayScale);
      promise?.then(() => {
        console.info('Succeeded in setting the grayScale.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the grayScale. Cause code: ${err.code}, message: ${err.message}`);
      });
    }
  } catch (exception) {
    console.error(`Failed to set the grayScale. Cause code: ${exception.code}, message: ${exception.message}`);
  }
});
```

## on('windowTitleButtonRectChange')<sup>11+</sup>

on(type: 'windowTitleButtonRectChange', callback: Callback&lt;TitleButtonRect&gt;): void

开启窗口标题栏上的最小化、最大化、关闭按钮矩形区域变化的监听，对存在标题栏和三键区的窗口形态生效。如果使用Stage模型，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'windowTitleButtonRectChange'，即标题栏上的最小化、最大化、关闭按钮矩形区域变化事件。 |
| callback | Callback&lt;[TitleButtonRect](arkts-apis-window-i.md#titlebuttonrect11)&gt; | 是   | 回调函数。返回当前标题栏上的最小化、最大化、关闭按钮矩形区域。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
windowClass.setUIContent('pages/WindowPage').then(() => {
  try {
    windowClass?.on('windowTitleButtonRectChange', (titleButtonRect) => {
      console.info('Succeeded in enabling the listener for window title buttons area changes. Data: ' + JSON.stringify(titleButtonRect));
    });
  } catch (exception) {
    console.error(`Failed to enable the listener for window title buttons area changes. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

## off('windowTitleButtonRectChange')<sup>11+</sup>

off(type: 'windowTitleButtonRectChange', callback?: Callback&lt;TitleButtonRect&gt;): void

关闭窗口标题栏上的最小化、最大化、关闭按钮矩形区域变化的监听，对存在标题栏和三键区的窗口形态生效。如果使用Stage模型，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'windowTitleButtonRectChange'，即标题栏上的最小化、最大化、关闭按钮矩形区域变化事件。 |
| callback | Callback&lt;[TitleButtonRect](arkts-apis-window-i.md#titlebuttonrect11)&gt; | 否   | 回调函数。返回当前标题栏上的最小化、最大化、关闭按钮矩形区域。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有标题栏上的最小化、最大化、关闭按钮矩形区域变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
windowClass.setUIContent('pages/WindowPage').then(() => {
    const callback = (titleButtonRect: window.TitleButtonRect) => {
        // ...
    }
  try {
    // 通过on接口开启监听
    windowClass?.on('windowTitleButtonRectChange', callback);
    // 关闭指定callback的监听
    windowClass?.off('windowTitleButtonRectChange', callback);
    // 如果通过on开启多个callback进行监听，同时关闭所有监听：
    windowClass?.off('windowTitleButtonRectChange');
  } catch (exception) {
    console.error(`Failed to disable the listener for window title buttons area changes. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

## on('windowRectChange')<sup>12+</sup>

on(type:  'windowRectChange', callback: Callback&lt;RectChangeOptions&gt;): void

开启窗口矩形（窗口位置及窗口大小）变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowRectChange'，即窗口矩形变化事件。 |
| callback | Callback&lt;[RectChangeOptions](arkts-apis-window-i.md#rectchangeoptions12)&gt; | 是   | 回调函数。返回当前窗口矩形变化值及变化原因。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  windowClass.on('windowRectChange', (data: window.RectChangeOptions) => {
      console.info(`Succeeded in enabling the listener for window rect changes. Data: ${JSON.stringify(data)}`);
  });
} catch (exception) {
  console.error(`Failed to disable the listener for window rect changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('windowRectChange')<sup>12+</sup>

off(type: 'windowRectChange', callback?: Callback&lt;RectChangeOptions&gt;): void

关闭窗口矩形（窗口位置及窗口大小）变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | 是   | 监听事件，固定为'windowRectChange'，即窗口矩形变化事件。     |
| callback | Callback&lt;[RectChangeOptions](arkts-apis-window-i.md#rectchangeoptions12)&gt; | 否   | 回调函数。返回当前的窗口矩形及变化原因。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有窗口矩形变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (rectChangeOptions: window.RectChangeOptions) => {
  // ...
}

try {
  windowClass.on('windowRectChange', callback);
  windowClass.off('windowRectChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('windowRectChange');
} catch (exception) {
  console.error(`Failed to disable the listener for window rect changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('rectChangeInGlobalDisplay')<sup>20+</sup>

on(type: 'rectChangeInGlobalDisplay', callback: Callback&lt;RectChangeOptions&gt;): void

开启[全局坐标系](../../windowmanager/window-terminology.md#global-coordinate-system全局坐标系)下窗口矩形（窗口位置及窗口大小）变化的监听事件。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'rectChangeInGlobalDisplay'，即全局坐标系下窗口矩形变化事件。 |
| callback | Callback&lt;[RectChangeOptions](arkts-apis-window-i.md#rectchangeoptions12)&gt; | 是   | 回调函数。返回当前窗口矩形变化值及变化原因。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (rectChangeOptions: window.RectChangeOptions) => {
  console.info(`Succeeded in enabling the listener for window rect changes in global display. Data: ` + JSON.stringify(rectChangeOptions));
}

try {
  windowClass.on('rectChangeInGlobalDisplay', callback);
} catch (exception) {
  console.error(`Failed to enable the listener for window rect changes in global display. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('rectChangeInGlobalDisplay')<sup>20+</sup>

off(type: 'rectChangeInGlobalDisplay', callback?: Callback&lt;RectChangeOptions&gt;): void

关闭[全局坐标系](../../windowmanager/window-terminology.md#global-coordinate-system全局坐标系)下窗口矩形（窗口位置及窗口大小）变化的监听事件。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | 是   | 监听事件，固定为'rectChangeInGlobalDisplay'，即全局坐标系下窗口矩形变化事件。     |
| callback | Callback&lt;[RectChangeOptions](arkts-apis-window-i.md#rectchangeoptions12)&gt; | 否   | 回调函数。返回当前的窗口矩形及变化原因。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有全局坐标系下窗口矩形变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (rectChangeOptions: window.RectChangeOptions) => {
  // ...
}

try {
  windowClass.on('rectChangeInGlobalDisplay', callback);
  windowClass.off('rectChangeInGlobalDisplay', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('rectChangeInGlobalDisplay');
} catch (exception) {
  console.error(`Failed to disable the listener for window rect changes in global display. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('subWindowClose')<sup>12+</sup>

on(type:  'subWindowClose', callback: Callback&lt;void&gt;): void

开启子窗口关闭事件的监听。此监听仅在点击系统提供的右上角关闭按钮关闭子窗时触发，其余关闭方式不触发回调。

当重复注册窗口关闭事件的监听时，最后一次注册成功的监听事件生效。

该接口触发的窗口关闭事件监听回调函数是同步执行，子窗口的异步关闭事件监听参考[on('windowWillClose')](#onwindowwillclose15)方法。

如果存在[on('windowWillClose')](#onwindowwillclose15)监听事件，只响应[on('windowWillClose')](#onwindowwillclose15)接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**
该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备调用不报错不生效，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不报错不生效。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'subWindowClose'，即子窗口关闭事件。 |
| callback | Callback&lt;void&gt; | 是   | 回调函数。当点击子窗口右上角关闭按钮事件发生时的回调。该回调函数不返回任何参数。回调函数内部逻辑的返回值决定当前子窗是否继续关闭，如果返回boolean类型的true表示不关闭子窗，返回false或者其他非boolean类型表示关闭子窗。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |

**示例：**

```ts
const callback = () => {
  // ...
  return true;
}
try {
  windowClass.on('subWindowClose', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('subWindowClose')<sup>12+</sup>

off(type: 'subWindowClose', callback?: Callback&lt;void&gt;): void

关闭子窗口关闭事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | 是   | 监听事件，固定为'subWindowClose'，即子窗口关闭事件。     |
| callback | Callback&lt;void&gt; | 否   | 回调函数。当点击子窗口右上角关闭按钮事件发生时的回调。该回调函数不返回任何参数。回调函数内部逻辑的返回值决定当前子窗是否继续关闭，如果返回boolean类型的true表示不关闭子窗，返回false或者其他非boolean类型表示关闭子窗。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有子窗口关闭的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |

**示例：**

```ts
const callback = () => {
  // ...
  return true;
}
try {
  windowClass.on('subWindowClose', callback);
  windowClass.off('subWindowClose', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('subWindowClose');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('windowWillClose')<sup>15+</sup>

on(type: 'windowWillClose', callback: Callback&lt;void, Promise&lt;boolean&gt;&gt;): void

开启主窗口或子窗口关闭事件的监听。此监听仅能通过系统提供的窗口标题栏关闭按键触发，其余关闭窗口的方式不触发回调。

该接口触发的回调函数是异步执行。子窗口的同步关闭事件监听参考[on('subWindowClose')](#onsubwindowclose12)方法。主窗口的同步关闭事件监听参考[on('windowStageClose')](arkts-apis-window-WindowStage.md#onwindowstageclose14)方法。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备调用不报错不生效，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备调用不报错不生效。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowWillClose'，即窗口关闭事件。 |
| callback | Callback&lt;void, Promise&lt;boolean&gt;&gt; | 是   | 回调函数。当点击窗口系统提供的右上角关闭按钮事件发生时的回调。该回调函数不返回任何参数。回调函数内部逻辑需要有Promise&lt;boolean&gt;类型的返回值。在返回的Promise函数里，执行resolve(true) 方法表示不关闭当前窗口，执行resolve(false) 方法或者reject方法均表示关闭当前窗口。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type, not called from mainWindow or subWindow. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = () => {
      // ...
      return new Promise<boolean>((resolve, reject) => {
        // 是否关闭该窗口
        let result: boolean = true;
        resolve(result);
      });
    }
    try {
      let windowClass = windowStage.getMainWindowSync();
      windowClass.on('windowWillClose', callback);
    } catch (exception) {
      console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## off('windowWillClose')<sup>15+</sup>

off(type: 'windowWillClose', callback?: Callback&lt;void, Promise&lt;boolean&gt;&gt;): void

用于关闭主窗口或子窗口关闭事件的监听。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备调用不报错不生效，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备调用不报错不生效。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowWillClose'，即窗口关闭事件。 |
| callback | Callback&lt;void, Promise&lt;boolean&gt;&gt; | 否   | 回调函数。当点击窗口系统提供的右上角关闭按钮事件发生时的回调。该回调函数不返回任何参数。回调函数内部逻辑需要有Promise&lt;boolean&gt;类型的返回值。在返回的Promise函数里，执行resolve(true) 方法表示不关闭当前窗口，执行resolve(false) 方法或者reject方法均表示关闭当前窗口。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type, not called from mainWindow or subWindow. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      const callback = () => {
        // ...
        return new Promise<boolean>((resolve, reject) => {
          // 是否关闭该窗口
          let result: boolean = true;
          resolve(result);
        });
      }
      let windowClass = windowStage.getMainWindowSync();
      windowClass.on('windowWillClose', callback);
      windowClass.off('windowWillClose', callback);
      // 如果通过on开启多个callback进行监听，同时关闭所有监听：
      windowClass.off('windowWillClose');
    } catch (exception) {
      console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## on('windowHighlightChange')<sup>15+</sup>

on(type: 'windowHighlightChange', callback: Callback&lt;boolean&gt;): void

开启窗口激活态变化事件的监听。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowHighlightChange'，即窗口激活态变化事件。 |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。当本窗口的激活态发生变化时的回调。回调函数返回boolean类型参数。当返回参数为true表示激活态；false表示非激活态。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  windowClass.on('windowHighlightChange', (data: boolean) => {
    console.info(`Window highlight Change: ${data}`);
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('windowHighlightChange')<sup>15+</sup>

off(type: 'windowHighlightChange', callback?: Callback&lt;boolean&gt;): void

关闭窗口激活态变化事件的监听。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | 是   | 监听事件，固定为'windowHighlightChange'，即窗口激活态变化事件。     |
| callback | Callback&lt;boolean&gt; | 否   | 回调函数。当本窗口的激活态发生变化时的回调。若传入参数，则关闭该监听。若未传入参数，则关闭所有窗口激活态变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (data: boolean) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('windowHighlightChange', callback);
  // 关闭指定callback的监听
  windowClass.off('windowHighlightChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('windowHighlightChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('rotationChange')<sup>19+</sup>

on(type: 'rotationChange', callback: RotationChangeCallback&lt;RotationChangeInfo, RotationChangeResult | void&gt;): void

开启窗口旋转变化的监听。[RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19)中窗口旋转事件类型为窗口即将旋转时，必须返回[RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19)。窗口旋转事件类型为窗口旋转结束时返回[RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19)不生效。

该函数只允许在主线程注册。同一个窗口多次注册同类型回调函数，只生效最新注册的同类型回调函数返回值。系统提供了超时保护机制，若20ms内窗口未返回[RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19)，系统不处理该返回值。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

针对PC/2in1设备：在API version 23之前，调用该接口会返回801错误码；从API version 23开始，可正常调用该接口且立即生效。

针对非PC/2in1且支持sensor旋转但不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备：可正常调用且立即生效。

针对非PC/2in1且支持sensor旋转，支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备：当处于非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态时可正常调用该接口且立即生效；当处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态时，调用该接口时不生效也不报错，切换到非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下生效。

针对其他设备：调用该接口不生效也不报错。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'rotationChange'，即窗口旋转变化事件。 |
| callback | RotationChangeCallback&lt;[RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19), [RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19) \| void&gt; | 是 | 回调函数。返回窗口旋转信息[RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19)，应用返回当前窗口变化结果[RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19)。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

function calculateRect(info: window.RotationChangeInfo): window.Rect {
  // calculate result with info
  let rect: window.Rect = {
    left: 0,
    top: 0,
    width: 500,
    height: 600,
  };
  return rect;
}

function callback(info: window.RotationChangeInfo): window.RotationChangeResult | void {
  let result: window.RotationChangeResult = {
    rectType: window.RectType.RELATIVE_TO_SCREEN,
    windowRect: {
      left: 0,
      top: 0,
      width: 0,
      height: 0,
    }
  };

  if (info.type === window.RotationChangeType.WINDOW_WILL_ROTATE) {
    result.rectType = window.RectType.RELATIVE_TO_SCREEN;
    result.windowRect = calculateRect(info);
    return result;
  } else {
    // do something after rotate
    return;
  }
}

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    let windowClass: window.Window | undefined = undefined;
    let config: window.Configuration = {
      name: 'test',
      windowType: window.WindowType.TYPE_DIALOG,
      ctx: this.context
    };

    try {
      window.createWindow(config, (err: BusinessError, data: window.Window) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        try {
          windowClass.on('rotationChange', callback);
        } catch (exception) {
          console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
        }
        windowClass.resize(500, 1000);
      });
    } catch (exception) {
      console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## off('rotationChange')<sup>19+</sup>

off(type: 'rotationChange', callback?: RotationChangeCallback&lt;RotationChangeInfo, RotationChangeResult | void&gt;): void

关闭窗口旋转变化的监听。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

针对PC/2in1设备：在API version 23之前，调用该接口会返回801错误码；从API version 23开始，可正常调用该接口且立即生效。

针对非PC/2in1且支持sensor旋转但不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备：可正常调用且立即生效。

针对非PC/2in1且支持sensor旋转，支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备：当处于非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态时可正常调用该接口且立即生效；当处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态时，调用该接口时不生效也不报错，切换到非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下生效。

针对其他设备：调用该接口不生效也不报错。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | 是   | 监听事件，固定为'rotationChange'，即窗口旋转变化事件。     |
| callback | RotationChangeCallback&lt;[RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19), [RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19) \| void&gt; | 否   | 回调函数。如果传入参数，则关闭该监听。如果未传入参数，则关闭该窗口的所有监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (info: window.RotationChangeInfo): window.RotationChangeResult | void => {
  // ...
  return;
}
try {
  windowClass.off('rotationChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听。
  windowClass.off('rotationChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## on('uiExtensionSecureLimitChange')<sup>20+</sup>

on(eventType: 'uiExtensionSecureLimitChange', callback: Callback&lt;boolean&gt;): void

开启窗口内uiExtension安全限制变化事件的监听, 建议在窗口创建后立即监听。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| eventType     | string                         | 是   | 监听事件，固定为'uiExtensionSecureLimitChange'，即窗口内uiExtension安全限制变化事件。 |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。当窗口内uiExtension安全限制变化时触发回调。当返回参数为true表示窗口内uiExtension开启了隐藏不安全窗口；当返回参数为false表示窗口内uiExtension关闭了隐藏不安全窗口。若窗口内存在多个uiExtension，当返回参数为true表示窗口内至少一个uiExtension开启了隐藏不安全窗口；当返回参数为false表示窗口内所有uiExtension关闭了隐藏不安全窗口。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported.Function on('uiExtensionSecureLimitChange') can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  windowClass.on('uiExtensionSecureLimitChange', (data: boolean) => {
    console.info(`Window secure limit Change: ${data}`);
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('uiExtensionSecureLimitChange')<sup>20+</sup>

off(eventType: 'uiExtensionSecureLimitChange', callback?: Callback&lt;boolean&gt;): void

关闭窗口内uiextension安全限制变化事件的监听。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| eventType     | string                         | 是   | 监听事件，固定为'uiExtensionSecureLimitChange'，即窗口内uiExtension安全限制变化事件。     |
| callback | Callback&lt;boolean&gt; | 否   | 回调函数。若传入参数，则关闭该监听。若未传入参数，则关闭所有窗口安全限制变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported.Function off('uiExtensionSecureLimitChange') can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (data: boolean) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('uiExtensionSecureLimitChange', callback);
  // 关闭指定callback的监听
  windowClass.off('uiExtensionSecureLimitChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('uiExtensionSecureLimitChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## isWindowSupportWideGamut<sup>9+</sup>

isWindowSupportWideGamut(callback: AsyncCallback&lt;boolean&gt;): void

判断当前窗口是否支持广色域模式，使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---------------------------- | -- | -------------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示当前窗口支持广色域模式，返回false表示当前窗口不支持广色域模式。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.isWindowSupportWideGamut((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to check whether the window support WideGamut. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in checking whether the window support WideGamut Data: ${data}`);
});
```

## isWindowSupportWideGamut<sup>9+</sup>

isWindowSupportWideGamut(): Promise&lt;boolean&gt;

判断当前窗口是否支持广色域模式，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型 | 说明 |
| ---------------------- | ------------------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前窗口支持广色域模式，返回false表示当前窗口不支持广色域模式。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.isWindowSupportWideGamut();
promise.then((data) => {
  console.info(`Succeeded in checking whether the window support WideGamut. Data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the window support WideGamut. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setWindowColorSpace<sup>9+</sup>

setWindowColorSpace(colorSpace:ColorSpace, callback: AsyncCallback&lt;void&gt;): void

设置当前窗口的色域模式，使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---------- | ------------------------- | -- | ----------- |
| colorSpace | [ColorSpace](arkts-apis-window-e.md#colorspace8) | 是 | 色域模式。 |
| callback   | AsyncCallback&lt;void&gt; | 是 | 回调函数。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.setWindowColorSpace(window.ColorSpace.WIDE_GAMUT, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set window colorspace. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting window colorspace.');
  });
} catch (exception) {
  console.error(`Failed to set window colorspace. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowColorSpace<sup>9+</sup>

setWindowColorSpace(colorSpace:ColorSpace): Promise&lt;void&gt;

设置当前窗口的色域模式，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---------- | ------------------------- | -- | ------------- |
| colorSpace | [ColorSpace](arkts-apis-window-e.md#colorspace8) | 是 | 色域模式。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.setWindowColorSpace(window.ColorSpace.WIDE_GAMUT);
  promise.then(() => {
    console.info('Succeeded in setting window colorspace.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window colorspace. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set window colorspace. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getWindowColorSpace<sup>9+</sup>

getWindowColorSpace(): ColorSpace

获取当前窗口的色域模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型 | 说明 |
| ------------------------- | ------------- |
| [ColorSpace](arkts-apis-window-e.md#colorspace8) | 当前色域模式。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let colorSpace = windowClass.getWindowColorSpace();
  console.info(`Succeeded in getting the window color space. ColorSpace: ${colorSpace}`);
} catch (exception) {
  console.error(`Failed to get the window color space. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowBackgroundColor<sup>9+</sup>

setWindowBackgroundColor(color: string | ColorMetrics): void

设置窗口的背景色。

未调用该接口时，窗口在浅色模式默认背景色为`'#FFF0F0F0'`，在深色模式默认背景色为`'#FF1A1A1A'`。

Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | -- | ----------------------------------------------------------------------- |
| color | string \| [ColorMetrics](js-apis-arkui-graphics.md#colormetrics12)<sup>18+</sup> | 是 | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。<br>从API version 18开始，此参数支持ColorMetrics类型。|

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics } from '@kit.ArkUI';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent("pages/page2", storage, (err: BusinessError) => {
  let errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in loading the content.');
  let color1: string = '#00FF33';
  let color2: ColorMetrics = ColorMetrics.numeric(0xff112233);
  try {
    windowClass?.setWindowBackgroundColor(color1);
    windowClass?.setWindowBackgroundColor(color2);
  } catch (exception) {
    console.error(`Failed to set the background color. Cause code: ${exception.code}, message: ${exception.message}`);
  };
});
```

## setWindowShadowEnabled<sup>20+</sup>

setWindowShadowEnabled(enable: boolean): Promise&lt;void&gt;

设置主窗口是否显示阴影，使用Promise异步回调。未调用该接口时，主窗口默认显示阴影。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**
- 在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。
- 从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在2in1和Tablet设备中可正常调用，在Tablet设备时仅在开启[自由多窗模式](../../windowmanager/window-terminology.md#free-multi-window-mode自由多窗模式)或[电脑模式](../../windowmanager/window-terminology.md#pc-mode电脑模式)下生效，在其他设备中返回801错误码。

**需要权限：** ohos.permission.SET_WINDOW_TRANSPARENT

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ------ | -- | ----------------------------------------------------------------------- |
| enable  | boolean | 是 | 设置主窗口是否显示阴影。true表示显示阴影，false表示不显示阴影。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                      |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent("pages/page2", (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
      // 获取应用主窗口。
      let windowClass: window.Window | undefined = undefined;
      windowStage.getMainWindow((err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        let enable = true;
        let promise = windowClass.setWindowShadowEnabled(enable);
        promise.then(() => {
          console.info('Succeeded in setting window shadow.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window shadow. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    });
  }
}
```

## setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

主窗口设置窗口亮度。当窗口处于前台且获焦时，窗口亮度生效。使用callback异步回调。

设置主窗口亮度只会影响当前设备内置屏的屏幕亮度，无法修改外接屏、[虚拟屏](../../displaymanager/display-terminology.md#虚拟屏)（如投屏所在的屏幕）的屏幕亮度（内置屏和外接屏具体请见[实体屏](../../displaymanager/display-terminology.md#实体屏)）。

当接口入参为-1时，窗口亮度恢复为系统屏幕亮度（可以通过控制中心或快捷键调整）。

当窗口退至后台时，窗口亮度失效，可以通过控制中心或快捷键调整。不建议连续调用或窗口退至后台时调用此接口，否则可能产生时序问题。

**设备行为差异：**
- 针对TV设备：当前接口不生效也不报错。
- 针对非2in1设备（不包含TV设备）：
  - 在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，当前窗口的窗口亮度生效时，控制中心调整系统屏幕亮度不生效。
  - 从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，当前窗口的窗口亮度生效时，控制中心可以调整系统屏幕亮度，同时会将当前窗口恢复为系统屏幕亮度。
- 针对2in1设备：
  - 在OpenHarmony 5.0.2之前，窗口设置屏幕亮度生效时，控制中心或快捷键调整系统屏幕亮度不生效。
  - 从OpenHarmony 5.0.2开始，窗口亮度与系统屏幕亮度保持一致，可以通过本接口、控制中心或者快捷键设置系统屏幕亮度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明                                        |
| ---------- | ------------------------- | -- |-------------------------------------------|
| brightness | number                    | 是 | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示恢复成设置窗口亮度前的系统控制中心亮度。 |
| callback   | AsyncCallback&lt;void&gt; | 是 | 回调函数。                                     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (loadError: BusinessError) => {
      if (loadError.code) {
        console.error(`Failed to load the content. Cause code: ${loadError.code}, message: ${loadError.message}`);
        return;
      }
      let windowClass: window.Window | undefined = undefined;
      windowStage.getMainWindow((err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        let brightness: number = 1.0;
        try {
          windowClass.setWindowBrightness(brightness, (err: BusinessError) => {
            const errCode: number = err.code;
            if (errCode) {
              console.error(`Failed to set the brightness. Cause code: ${err.code}, message: ${err.message}`);
              return;
            }
            console.info('Succeeded in setting the brightness.');
          });
        } catch (exception) {
          console.error(`Failed to set the brightness. Cause code: ${exception.code}, message: ${exception.message}`);
        }
      });
    });
  }
}
```

## setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number): Promise&lt;void&gt;

主窗口设置窗口亮度。当窗口处于前台且获焦时，窗口亮度生效。使用Promise异步回调。

设置主窗口亮度只会影响当前设备内置屏的屏幕亮度，无法修改外接屏、[虚拟屏](../../displaymanager/display-terminology.md#虚拟屏)（如投屏所在的屏幕）的屏幕亮度（内置屏和外接屏具体请见[实体屏](../../displaymanager/display-terminology.md#实体屏)）。

当接口入参为-1时，窗口亮度恢复为系统屏幕亮度（可以通过控制中心或快捷键调整）。

当窗口退至后台时，窗口亮度失效，可以通过控制中心或快捷键调整。不建议连续调用或窗口退至后台时调用此接口，否则可能产生时序问题。

**设备行为差异：**
- 针对TV设备：当前接口不生效也不报错。
- 针对非2in1设备（不包含TV设备）：
  - 在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，当前窗口的窗口亮度生效时，控制中心调整系统屏幕亮度不生效。
  - 从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，当前窗口的窗口亮度生效时，控制中心可以调整系统屏幕亮度，同时会将当前窗口恢复为系统屏幕亮度。
- 针对2in1设备：
  - 在OpenHarmony 5.0.2之前，窗口设置屏幕亮度生效时，控制中心或快捷键调整系统屏幕亮度不生效。
  - 从OpenHarmony 5.0.2开始，窗口亮度与系统屏幕亮度保持一致，可以通过本接口、控制中心或者快捷键设置系统屏幕亮度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明                                     |
| ---------- | ------ | -- |----------------------------------------|
| brightness | number | 是 | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示恢复成设置窗口亮度前的系统控制中心亮度。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (loadError: BusinessError) => {
      if (loadError.code) {
        console.error(`Failed to load the content. Cause code: ${loadError.code}, message: ${loadError.message}`);
        return;
      }
      let windowClass: window.Window | undefined = undefined;
      windowStage.getMainWindow((err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        let brightness: number = 1.0;
        try {
          let promise = windowClass.setWindowBrightness(brightness);
          promise.then(() => {
            console.info('Succeeded in setting the brightness.');
          }).catch((err: BusinessError) => {
            console.error(`Failed to set the brightness. Cause code: ${err.code}, message: ${err.message}`);
          });
        } catch (exception) {
          console.error(`Failed to set the brightness. Cause code: ${exception.code}, message: ${exception.message}`);
        }
      });
    });
  }
}
```

## setWindowFocusable<sup>9+</sup>

setWindowFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否具有获得焦点的能力，使用callback异步回调。

从API version 22开始，调用[createVirtualScreen](js-apis-display.md#displaycreatevirtualscreen16)接口创建虚拟屏，并设置supportsFocus配置项为false时，位于该虚拟屏的窗口无法调用该接口修改窗口的可获焦能力，如果调用，会抛出1300002错误码。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----------- | ------------------------- | -- | ------------------------------------------------------- |
| isFocusable | boolean                   | 是 | 窗口是否可获焦。true表示支持；false表示不支持。设置为false时，该窗口不支持绑定输入法和接收键盘事件，如需处理输入逻辑，建议参考[不可获焦窗口中输入框与输入法交互指南](../../inputmethod/use-inputmethod-in-not-focusable-window.md)。|
| callback    | AsyncCallback&lt;void&gt; | 是 | 回调函数。                                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocusable: boolean = true;
try {
  windowClass.setWindowFocusable(isFocusable, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the window to be focusable. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the window to be focusable.');
  });
} catch (exception) {
  console.error(`Failed to set the window to be focusable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowFocusable<sup>9+</sup>

setWindowFocusable(isFocusable: boolean): Promise&lt;void&gt;

设置窗口是否具有获得焦点的能力，使用Promise异步回调。

从API version 22开始，调用[createVirtualScreen](js-apis-display.md#displaycreatevirtualscreen16)接口创建虚拟屏，并设置supportsFocus配置项为false时，位于该虚拟屏的窗口无法调用该接口修改窗口的可获焦能力，如果调用，会抛出1300002错误码。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----------- | ------- | -- | -------------------------------------------------------- |
| isFocusable | boolean | 是 | 窗口是否可获焦。true表示支持；false表示不支持。设置为false时，该窗口不支持绑定输入法和接收键盘事件，如需处理输入逻辑，建议参考[不可获焦窗口中输入框与输入法交互指南](../../inputmethod/use-inputmethod-in-not-focusable-window.md)。|

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocusable: boolean = true;
try {
  let promise = windowClass.setWindowFocusable(isFocusable);
  promise.then(() => {
    console.info('Succeeded in setting the window to be focusable.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to be focusable. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window to be focusable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowKeepScreenOn<sup>9+</sup>

setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

设置当前窗口位于前台时当前设备的屏幕是否为常亮状态，异源虚拟屏下不生效。使用callback异步回调。

仅在必要场景（导航、视频播放、绘画、游戏等场景）下，设置该属性为true；退出上述场景后，应当重置该属性为false；其他场景（无屏幕互动、音频播放等）下，不使用该接口；系统检测到非规范使用该接口时，可能会恢复自动灭屏功能。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------------- | ------------------------- | -- | ---------------------------------------------------- |
| isKeepScreenOn | boolean                   | 是 | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。  |
| callback       | AsyncCallback&lt;void&gt; | 是 | 回调函数。                                            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isKeepScreenOn: boolean = true;
try {
  windowClass.setWindowKeepScreenOn(isKeepScreenOn, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the screen to be always on.');
  });
} catch (exception) {
  console.error(`Failed to set the screen to be always on. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowKeepScreenOn<sup>9+</sup>

setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt;

设置当前窗口位于前台时当前设备的屏幕是否为常亮状态，异源虚拟屏下不生效。使用Promise异步回调。

仅在必要场景（导航、视频播放、绘画、游戏等场景）下，设置该属性为true；退出上述场景后，应当重置该属性为false；其他场景（无屏幕互动、音频播放等）下，不使用该接口；系统检测到非规范使用该接口时，可能会恢复自动灭屏功能。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------------- | ------- | -- | --------------------------------------------------- |
| isKeepScreenOn | boolean | 是 | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isKeepScreenOn: boolean = true;
try {
  let promise = windowClass.setWindowKeepScreenOn(isKeepScreenOn);
  promise.then(() => {
    console.info('Succeeded in setting the screen to be always on.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the screen to be always on. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowPrivacyMode<sup>9+</sup>

setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为隐私模式，使用callback异步回调。

设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。

隐私模式窗口退后台后在多任务卡片中显示为白色蒙层或隐私蒙层。

未调用此接口时，窗口默认不开启隐私模式，可以被截屏或录屏。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**需要权限：** ohos.permission.PRIVACY_WINDOW

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------- | ------------------------- | -- | ------------------------------------------------------ |
| isPrivacyMode | boolean                   | 是 | 窗口是否为隐私模式。true表示为隐私模式，false表示为非隐私模式。  |
| callback      | AsyncCallback&lt;void&gt; | 是 | 回调函数。                                              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. Possible cause: Need ohos.permission.PRIVACY_WINDOW permission. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isPrivacyMode: boolean = true;
try {
  windowClass.setWindowPrivacyMode(isPrivacyMode, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the window to privacy mode. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the window to privacy mode.');
  });
} catch (exception) {
  console.error(`Failed to set the window to privacy mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowPrivacyMode<sup>9+</sup>

setWindowPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

设置窗口是否为隐私模式，使用Promise异步回调。

设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。

隐私模式窗口退后台后在多任务卡片中显示为白色蒙层或隐私蒙层。

未调用此接口时，窗口默认不开启隐私模式，可以被截屏或录屏。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**需要权限：** ohos.permission.PRIVACY_WINDOW

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------- | ------- | -- | ----------------------------------------------------- |
| isPrivacyMode | boolean | 是 | 窗口是否为隐私模式。true表示为隐私模式，false表示为非隐私模式。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. Possible cause: Need ohos.permission.PRIVACY_WINDOW permission. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isPrivacyMode: boolean = true;
try {
  let promise = windowClass.setWindowPrivacyMode(isPrivacyMode);
  promise.then(() => {
    console.info('Succeeded in setting the window to privacy mode.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to privacy mode. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window to privacy mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowTouchable<sup>9+</sup>

setWindowTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为可点击状态，使用callback异步回调。

当窗口处于可点击状态时，若用户点击命中该窗口，事件将发送给该窗口处理。当窗口处于不可点击状态时，透传点击事件，传递给下层窗口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----------- | ------------------------- | -- | ----------------------------------------------- |
| isTouchable | boolean                   | 是 | 窗口是否为可点击状态。true表示可点击；false表示不可点击。 |
| callback    | AsyncCallback&lt;void&gt; | 是 | 回调函数。                                        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isTouchable = true;
try {
  windowClass.setWindowTouchable(isTouchable, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the window to be touchable. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the window to be touchable.');
  });
} catch (exception) {
  console.error(`Failed to set the window to be touchable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowTouchable<sup>9+</sup>

setWindowTouchable(isTouchable: boolean): Promise&lt;void&gt;

设置窗口是否为可点击状态，使用Promise异步回调。

当窗口处于可点击状态时，若用户点击命中该窗口，事件将发送给该窗口处理。当窗口处于不可点击状态时，透传点击事件，传递给下层窗口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----------- | ------- | -- | ----------------------------------------------- |
| isTouchable | boolean | 是 | 窗口是否为可点击状态。true表示可点击；false表示不可点击。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isTouchable: boolean = true;
try {
  let promise = windowClass.setWindowTouchable(isTouchable);
  promise.then(() => {
    console.info('Succeeded in setting the window to be touchable.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to be touchable. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window to be touchable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## snapshot<sup>9+</sup>

snapshot(callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取窗口截图，使用callback异步回调。若当前窗口设置为隐私模式（可通过[setWindowPrivacyMode](#setwindowprivacymode9)接口设置），截图结果为白屏。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                 |
| ----------- | ------------------------- | ---- | -------------------- |
| callback    | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | 是   | 回调函数。  |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Get pixelMap failed; 3. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

windowClass.snapshot((err: BusinessError, pixelMap: image.PixelMap) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to snapshot window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
  pixelMap.release(); // PixelMap使用完后及时释放内存
});
```

## snapshot<sup>9+</sup>

snapshot(): Promise&lt;image.PixelMap&gt;

获取当前窗口截图。若当前窗口设置为隐私模式（可通过[setWindowPrivacyMode](#setwindowprivacymode9)接口设置），截图结果为白屏。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise对象。返回当前窗口截图。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Get pixelMap failed; 3. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let promise = windowClass.snapshot();
promise.then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
  pixelMap.release(); // PixelMap使用完后及时释放内存
}).catch((err: BusinessError) => {
  console.error(`Failed to snapshot window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## snapshotSync<sup>20+</sup>

snapshotSync(): image.PixelMap

获取当前窗口截图，此接口为同步接口。若当前窗口设置为隐私模式（[setWindowPrivacyMode](#setwindowprivacymode9)接口设置），截图结果为白屏。

Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 返回当前窗口截图。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Create pixelMap failed. |
| 1300018 | Timeout. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

try {
  let pixelMap = windowClass.snapshotSync();
  console.info(`Succeeded in snapshotting window`);
  pixelMap.release(); // PixelMap使用完后及时释放内存
} catch (exception) {
  console.error(`Failed to snapshot window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## snapshotIgnorePrivacy<sup>18+</sup>

snapshotIgnorePrivacy(): Promise&lt;image.PixelMap&gt;

获取当前窗口截图。即使当前窗口设置为隐私模式（可通过[setWindowPrivacyMode](#setwindowprivacymode9)接口设置），仍可调用本接口返回当前窗口截图。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise对象。返回当前窗口截图。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Function snapshotIgnorePrivacy can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Create pixelMap failed; 3. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let promise = windowClass.snapshotIgnorePrivacy();
promise.then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
  pixelMap.release(); // PixelMap使用完后及时释放内存
}).catch((err: BusinessError) => {
  console.error(`Failed to snapshot window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setAspectRatio<sup>10+</sup>

setAspectRatio(ratio: number): Promise&lt;void&gt;

设置窗口内容布局（不含边框和标题栏等装饰）的比例，使用Promise异步回调。

> **说明：**
>
> - 通过其他接口如[resize](#resize9)、[resizeAsync](#resizeasync12)设置窗口大小时，不受ratio约束。
>
> - 仅主窗可设置，且仅在自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）下生效。此比例参数将持久化保存，关闭应用或重启设备后，切换到自由悬浮窗口模式时，设置的比例仍然生效。
>
> - 当同一应用的某个主窗口调用此接口设置宽高比生效后，后续打开的主窗口均会沿用该宽高比。若需为单个主窗口单独设置宽高比，请使用[setContentAspectRatio](#setcontentaspectratio21)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名             | 类型    | 必填 | 说明                                        |
| ------------------ | ------- | ---- |-------------------------------------------|
| ratio | number | 是   | 窗口内容布局（不含边框和标题栏等装饰）的宽高比。该参数为浮点数，受窗口最大最小尺寸限制，比例值下限为最小宽度/最大高度，上限为最大宽度/最小高度。窗口最大最小尺寸由[WindowLimits](arkts-apis-window-i.md#windowlimits11)和系统限制的交集决定，系统限制优先级高于[WindowLimits](arkts-apis-window-i.md#windowlimits11)。ratio的有效范围会随[WindowLimits](arkts-apis-window-i.md#windowlimits11)变化而变化。如果先设置了[WindowLimits](arkts-apis-window-i.md#windowlimits11)，后设置的ratio与其冲突，会返回错误码；如果先设置了ratio，后设置的[WindowLimits](arkts-apis-window-i.md#windowlimits11)与其冲突，窗口的宽高比可能会不跟随设置的宽高比（ratio）。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: Invalid parameter range. |
| 1300002 | This window state is abnormal.               |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |

**示例：**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {

  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      let ratio = 1.0;
      let promise = windowClass.setAspectRatio(ratio);
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

## setAspectRatio<sup>10+</sup>

setAspectRatio(ratio: number, callback: AsyncCallback&lt;void&gt;): void

设置窗口内容布局（不含边框和标题栏等装饰）的比例，使用callback异步回调。

> **说明：**
>
> - 通过其他接口如[resize](#resize9)、[resizeAsync](#resizeasync12)设置窗口大小时，不受ratio约束。
>
> - 仅主窗可设置，且仅在自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）下生效。此比例参数将持久化保存，关闭应用或重启设备后，切换到自由悬浮窗口模式时，设置的比例仍然生效。
>
> - 当同一应用的某个主窗口调用此接口设置宽高比生效后，后续打开的主窗口均会沿用该宽高比。若需为单个主窗口单独设置宽高比，请使用[setContentAspectRatio](#setcontentaspectratio21)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名             | 类型    | 必填 | 说明                                         |
| ------------------ | ------- | ---- |--------------------------------------------|
| ratio | number | 是   | 窗口内容布局（不含边框和标题栏等装饰）的宽高比。该参数为浮点数，受窗口最大最小尺寸限制，比例值下限为最小宽度/最大高度，上限为最大宽度/最小高度。窗口最大最小尺寸由[WindowLimits](arkts-apis-window-i.md#windowlimits11)和系统限制的交集决定，系统限制优先级高于[WindowLimits](arkts-apis-window-i.md#windowlimits11)。ratio的有效范围会随[WindowLimits](arkts-apis-window-i.md#windowlimits11)变化而变化。如果先设置了[WindowLimits](arkts-apis-window-i.md#windowlimits11)，后设置的ratio与其冲突，会返回错误码；如果先设置了ratio，后设置的[WindowLimits](arkts-apis-window-i.md#windowlimits11)与其冲突，窗口的宽高比可能会不跟随设置的宽高比（ratio）。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                      |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: Invalid parameter range. |
| 1300002 | This window state is abnormal.               |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |

**示例：**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {

  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    if (!windowClass) {
      console.info('Failed to load the content. Cause: windowClass is null');
    }
    try {
      let ratio = 1.0;
      windowClass.setAspectRatio(ratio, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to set the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in setting the aspect ratio of window.');
      });
    } catch (exception) {
      console.error(`Failed to set the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}

```

## setContentAspectRatio<sup>21+</sup>

setContentAspectRatio(ratio: number, isPersistent?: boolean, needUpdateRect?: boolean): Promise&lt;void&gt;

设置窗口内容布局（不含边框和标题栏等装饰）的比例，使用Promise异步回调。

> **说明：**
>
> - 根据相同的ratio参数调整窗口宽高时，窗口宽高会跟随窗口边框装饰尺寸或可见性变化而调整。
>
> - 通过[setWindowDecorVisible](#setwindowdecorvisible11)将窗口标题栏设置为不可见时，窗口内容区域将占据原本标题栏的高度空间。
>
> - 通过其他接口如[resize](#resize9)、[resizeAsync](#resizeasync12)设置窗口大小时，不受ratio约束。
>
> - 仅主窗可设置，且仅在自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）下生效。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明                                        |
| --- | ------- | ---- |-------------------------------------------|
| ratio | number | 是   | 窗口内容布局（不含边框和标题栏等装饰）的宽高比。该参数为浮点数，受窗口最大最小尺寸限制，比例值下限为最小宽度/最大高度，上限为最大宽度/最小高度。窗口最大最小尺寸由[WindowLimits](arkts-apis-window-i.md#windowlimits11)和系统限制的交集决定，系统限制优先级高于[WindowLimits](arkts-apis-window-i.md#windowlimits11)。ratio的有效范围会随[WindowLimits](arkts-apis-window-i.md#windowlimits11)变化而变化。如果先设置了[WindowLimits](arkts-apis-window-i.md#windowlimits11)，后设置的ratio与其冲突，会返回错误码；如果先设置了ratio，后设置的[WindowLimits](arkts-apis-window-i.md#windowlimits11)与其冲突，窗口的宽高比可能会不跟随设置的宽高比（ratio）。|
| isPersistent | boolean | 否 | 是否持久化保存该比例参数。<br/>如为`true`，比例参数会持久化保存，销毁窗口、关闭应用或重启设备后，当再次切换到自由悬浮窗口模式时仍然生效。可通过[resetAspectRatio](#resetaspectratio10)清除持久化保存的比例参数。<br/>如为`false`，比例参数仅对当前窗口生效，窗口销毁后清除该数据。<br/>默认值为`true`。|
| needUpdateRect | boolean | 否 | 是否立即根据当前比例更新窗口大小。<br/>如为`true`，立即根据当前比例更新窗口大小。<br/>如为`false`，窗口将在拖拽缩放时根据当前比例更新，也可以使用[resize](#resize9)或[resizeAsync](#resizeasync12)进行主动更新。<br/>默认值为`true`。|

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. 2. Invalid parameter length. |

**示例：**

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

## resetAspectRatio<sup>10+</sup>

resetAspectRatio(): Promise&lt;void&gt;

取消设置窗口内容布局的比例，使用Promise异步回调。

仅主窗可设置，调用后将清除持久化存储的比例信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300004 | Unauthorized operation.                      |

**示例：**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {

  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    if (!windowClass) {
      console.info('Failed to load the content. Cause: windowClass is null');
    }
    try {
      let promise = windowClass.resetAspectRatio();
      promise.then(() => {
        console.info('Succeeded in resetting aspect ratio of window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to reset the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to reset the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## resetAspectRatio<sup>10+</sup>

resetAspectRatio(callback: AsyncCallback&lt;void&gt;): void

取消设置窗口内容布局的比例，使用callback异步回调。

仅主窗可设置，调用后将清除持久化存储的比例信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名             | 类型    | 必填 | 说明                                                         |
| ------------------ | ------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300004 | Unauthorized operation.                      |

**示例：**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {

  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    if (!windowClass) {
      console.info('Failed to load the content. Cause: windowClass is null');
    }
    try {
      windowClass.resetAspectRatio((err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to reset the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in resetting aspect ratio of window.');
      });
    } catch (exception) {
      console.error(`Failed to reset the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## minimize<sup>11+</sup>

minimize(callback: AsyncCallback&lt;void&gt;): void

此接口根据调用对象不同，实现不同的功能：

- 当调用对象为主窗口时，实现最小化功能，可在多任务中还原，在PC/2in1设备上可通过Dock栏或使用[restore()](#restore14)进行还原。

- 当调用对象为子窗口或全局悬浮窗时，实现隐藏功能，可以使用[showWindow()](#showwindow9)进行还原。

该接口仅支持主窗口、子窗口或全局悬浮窗，其他窗口调用返回1300002错误码，使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error; 3.Invalid window type. Only main windows, subwindows, and float windows are supported. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.minimize((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to minimize the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in minimizing the window.');
});
```

## minimize<sup>11+</sup>

minimize(): Promise&lt;void&gt;

此接口根据调用对象不同，实现不同的功能：

- 当调用对象为主窗口时，实现最小化功能，可在多任务中还原，在PC/2in1设备上可通过Dock栏或使用[restore()](#restore14)进行还原。

- 当调用对象为子窗口或全局悬浮窗时，实现隐藏功能，可以使用[showWindow()](#showwindow9)进行还原。

该接口仅支持主窗口、子窗口或全局悬浮窗，其他窗口调用返回1300002错误码，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error; 3.Invalid window type. Only main windows, subwindows, and float windows are supported. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.minimize();
promise.then(() => {
  console.info('Succeeded in minimizing the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to minimize the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## maximize<sup>12+</sup>
maximize(presentation?: MaximizePresentation): Promise&lt;void&gt;

实现最大化功能。主窗口可调用此接口实现最大化功能；子窗口需在创建时设置子窗口参数maximizeSupported为true，再调用此接口可实现最大化功能。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错。

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| presentation  | [MaximizePresentation](arkts-apis-window-e.md#maximizepresentation12) | 否 | 主窗口或子窗口最大化时的布局枚举。默认值window.MaximizePresentation.ENTER_IMMERSIVE，即默认最大化时进入全屏模式。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Function maximize can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.    |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows and maximizable subwindows are supported.       |
| 1300005 | This window stage is abnormal.<br>适用版本：12-19 |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let promise = windowClass.maximize();
      // let promise = windowClass.maximize(window.MaximizePresentation.ENTER_IMMERSIVE);
      promise.then(() => {
        console.info('Succeeded in maximizing the window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to maximize the window. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
};
```

## maximize<sup>22+</sup>

maximize(presentation?: MaximizePresentation, acrossDisplay?: boolean): Promise&lt;void&gt;

实现最大化功能。主窗口可调用此接口实现最大化功能；子窗口需在创建时设置子窗口参数maximizeSupported为true，再调用此接口可实现最大化功能。在具备折叠功能的2in1设备上，支持控制悬停态（参考[折叠屏悬停态最佳实践](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-folded-hover)）下主窗口的瀑布流模式行为，即窗口在悬停态下最大化时是否跨上下两个半屏显示。使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错。

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| presentation | [MaximizePresentation](arkts-apis-window-e.md#maximizepresentation12) | 否 | 主窗口或子窗口最大化时的布局枚举。默认值window.MaximizePresentation.ENTER_IMMERSIVE，即默认最大化时进入全屏模式。 |
| acrossDisplay | boolean | 否 | 控制悬停态下主窗口在最大化时的瀑布流模式行为。默认值为`undefined`。<br>仅主窗口可设置此参数，非主窗口调用时返回错误码`1300004`。<br>取值为`true`时：<br>- 悬停态下，窗口将直接进入瀑布流模式；<br>- 展开态下，窗口进入最大化，并在悬停态下保持瀑布流模式。<br>取值为`false`时：<br>- 悬停态下，窗口将退出瀑布流模式，进入单面最大化（即窗口最大化时只在上半屏或下半屏显示）；<br>- 展开态下，窗口进入最大化，并在悬停态下退出瀑布流模式。<br>取值为`undefined`时，不修改窗口瀑布流模式行为：<br>- 悬停态下，窗口进入单面最大化；<br>- 展开态下，窗口进入最大化，并在悬停态下默认保持瀑布流模式。<br>**设备行为差异：** 仅在具备折叠功能的2in1设备可正常调用；在其他设备上调用不生效。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Function maximize can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.    |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows and maximizable subwindows are supported.       |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      let mainWindow = windowStage.getMainWindowSync();
      mainWindow.maximize(window.MaximizePresentation.ENTER_IMMERSIVE, true)
        .then(() => {
          console.info('Window maximized successfully.');
        })
        .catch((err: BusinessError) => {
          console.error(`Failed to maximize the window. Cause code: ${err.code}, message: ${err.message}`);
        });
    });
  }
};
```

## maximizeWithOptions

maximizeWithOptions(maximizeOptions?: MaximizeOptions): Promise&lt;void&gt;

实现窗口的最大化功能。主窗口可调用此接口实现最大化功能；子窗口需在创建时设置子窗口参数maximizeSupported为true，再调用此接口可实现最大化功能。支持配置最大化布局策略、折叠屏跨屏策略以及截图动画参数。使用Promise异步回调。

> **说明：**
>
> - 不传入maximizeOptions参数时，各字段取默认值，行为等同于调用[maximize()](#maximize12)并使用默认值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错。

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| maximizeOptions  | [MaximizeOptions](arkts-apis-window-i.md#maximizeoptions) | 否 | 最大化配置选项。不传入时，行为等同于调用[maximize()](#maximize12)并使用默认值。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: 1. Invalid window type. Only main windows and maximizable subwindows are supported; 2. The acrossDisplay parameter only supports main windows; 3. The snapshotAnimationConfig parameter only supports main windows. |
| 1300016 | Parameter error. Possible cause: Invalid parameter range. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      let mainWindow = windowStage.getMainWindowSync();
      let maximizeOptions: window.MaximizeOptions = {
        maximizePresentation: window.MaximizePresentation.ENTER_IMMERSIVE,
        acrossDisplayPresentation: window.AcrossDisplayPresentation.FOLLOW_ACROSS_DISPLAY_SETTING,
        snapshotAnimationConfig: {
          duration: 200,
          delay: 30
        }
      };
      mainWindow.maximizeWithOptions(maximizeOptions)
        .then(() => {
          console.info('Window maximized successfully.');
        })
        .catch((err: BusinessError) => {
          console.error(`Failed to maximize the window. Cause code: ${err.code}, message: ${err.message}`);
        });
    });
  }
};
```

## setResizeByDragEnabled<sup>14+</sup>
setResizeByDragEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

禁止/使能通过拖拽方式缩放主窗口或启用标题栏的子窗口的功能。使用callback异步回调。

> **说明：**
>
> - 针对主窗口，仅在[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下生效，非自由窗口状态下不生效也不报错，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| enable  | boolean | 是 | 设置窗口是否使能通过拖拽进行缩放，true表示使能，false表示禁止。 |
| callback  | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  let enabled = false;
  windowClass.setResizeByDragEnabled(enabled, (err) => {
    if (err.code) {
      console.error(`Failed to set the function of disabling the resize by drag window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in setting the function of disabling the resize by drag window.`);
  });
} catch (exception) {
  console.error(`Failed to set the function of disabling the resize by drag window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setResizeByDragEnabled<sup>14+</sup>
setResizeByDragEnabled(enable: boolean): Promise&lt;void&gt;

禁止/使能通过拖拽方式缩放主窗口或启用标题栏的子窗口的功能。使用Promise异步回调。

> **说明：**
>
> - 针对主窗口，仅在[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下生效，非自由窗口状态下不生效不报错。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| enable  | boolean | 是 | 设置窗口是否使能通过拖拽进行缩放，true表示使能，false表示禁止。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enabled = false;
  let promise = windowClass.setResizeByDragEnabled(enabled);
  promise.then(() => {
    console.info(`Succeeded in setting the function of disabling the resize by drag window.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the function of disabling the resize by drag window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the function of disabling the resize by drag window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## recover<sup>11+</sup>

recover(): Promise&lt;void&gt;

将主窗口从全屏、最大化、分屏模式下还原为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING），并恢复到进入该模式之前的大小和位置，已经是自由悬浮窗口模式不可再还原。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error; 3. The window does not support floating mode. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let windowClass = windowStage.getMainWindowSync();
      if (!windowClass) {
        console.error('Failed to get main window.');
        return;
      }
      let promise = windowClass.recover();
      promise.then(() => {
        console.info('Succeeded in recovering the window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to recover the window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to recover the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## recover

recover(snapshotAnimationConfig: WindowSnapshotAnimationConfig): Promise&lt;void&gt;

将主窗口从全屏、最大化或者分屏模式下还原为自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING），并恢复到进入该模式之前的大小和位置，已经是自由悬浮窗口模式时不可再还原，支持配置截图动画参数。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| snapshotAnimationConfig  | [WindowSnapshotAnimationConfig](arkts-apis-window-i.md#windowsnapshotanimationconfig) | 是 | 截图动画配置。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error; 3. The window does not support floating mode. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: 1. The snapshotAnimationConfig parameter only supports main windows. |
| 1300016 | Parameter error. Possible cause: Invalid parameter range. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let windowClass = windowStage.getMainWindowSync();
      if (!windowClass) {
        console.error('Failed to get main window.');
        return;
      }
      let snapshotAnimationConfig: window.WindowSnapshotAnimationConfig = {
        duration: 200,
        delay: 30
      };
      let promise = windowClass.recover(snapshotAnimationConfig);
      promise.then(() => {
        console.info('Succeeded in recovering the window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to recover the window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to recover the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## restore<sup>14+</sup>

restore(): Promise&lt;void&gt;

主窗口为最小化状态且UIAbility生命周期为onForeground时，将主窗口从最小化状态，恢复到前台显示，并恢复到进入最小化状态之前的大小和位置。主窗口为前台状态时，仅抬升主窗口层级。使用Promise异步回调。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在PC/2in1设备、其他设备的[电脑模式](../../windowmanager/window-terminology.md#pc-mode电脑模式)下可正常调用，在其他设备和其他模式下返回801错误码。

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 801          | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002      | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.    |
| 1300003      | This window manager service works abnormally.                |
| 1300004      | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported.                 |

**示例**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      let windowClass = windowStage.getMainWindowSync();
      // 调用minimize, 使主窗最小化
      windowClass.minimize();
      // 设置延时函数延时5秒钟后对主窗进行恢复。
      setTimeout(()=>{
        // 调用restore()函数对主窗进行恢复。
        let promise = windowClass.restore();
        promise.then(() => {
          console.info('Succeeded in restoring the window.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to restore the window. Cause code: ${err.code}, message: ${err.message}`);
        });
      }, 5000);
    } catch (exception) {
      console.error(`Failed to restore the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## restoreMainWindow<sup>23+</sup>

restoreMainWindow(wantParameters?: Record<string, Object>): Promise&lt;void&gt;

将当前窗口的主窗口恢复到前台显示，如果主窗口已处于前台，则会抬升主窗层级。此接口仅适用于类型为[TYPE_FLOAT](./arkts-apis-window-e.md#windowtype7)的窗口，并且需在窗口触发过[DOWN](./arkui-ts/ts-appendix-enums.md#touchtype)事件后才能调用。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------- | -- | ------------------------ |
| wantParameters | Record&lt;string, Object&gt; | 否 | 拉起窗口时会给主窗传递的自定义参数，主窗会在触发[onNewWant](../apis-ability-kit/js-apis-app-ability-abilityLifecycleCallback.md#onnewwant12)回调时收到。默认值为空，代表不向主窗传入任何自定义参数。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 801          | Capability not supported. Failed to call the API due to limited device capabilities.            |
| 1300002      | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error.   |
| 1300003      | This window manager service works abnormally.      |
| 1300004      | Unauthorized operation. Possible cause: 1. The window is not float window. 2. The window is not at foreground or has never been clicked. 3. The window cannot find main window.   |
| 1300007      | Restore parent main window failed. Possible cause: 1. The main window is in PAUSED lifecycle state. 2. The main window is in background during recent. |

**示例：**

<!--no-check-->
```ts
// Float.ets
import { window } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit';
import { JSON } from '@kit.ArkTS';

@Entry
@Component
struct Float {
  build() {
    Button('CreateFloatWindow').onClick(() => {
      this.createFloatWindow();
    })
  }

  private createFloatWindow() {
    let windowClass: window.Window | undefined = undefined;
    let config: window.Configuration = {
      name: 'testFloatWindow',
      title: 'floatWindow',
      windowType: window.WindowType.TYPE_FLOAT,
      ctx: this.getUIContext()?.getHostContext(),
      decorEnabled: true,
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        console.info(`succeeded in creating the window. Data: ${JSON.stringify(data)}`);
        windowClass.resize(500, 1600).then(() => {
          console.info('Succeeded in changing the window size.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
        });
        windowClass.setUIContent("pages/FloatWindowInfo").then(() => {
          console.info('Succeeded in loading the content.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        });
        windowClass.showWindow().then(() => {
          console.info("showWindow success");
        }).catch((err: BusinessError) => {
          console.error(`showWindow err: ${JSON.stringify(err)}`);
        });
        windowClass.moveWindowToAsync(20, 200).then(() => {
          console.info('Succeeded in moving the window.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (exception) {
      console.error(`failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```
<!--no-check-->
```ts
// FloatWindowInfo.ets
import { window } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct FloatWindowInfo {
  @State subWindow: window.Window | undefined = undefined;
  @State windowId: number = -1;
  async aboutToAppear(): Promise<void> {
    this.subWindow = window.findWindow('testFloatWindow');
    this.windowId = this.subWindow?.getWindowProperties()?.id;
  }

  build() {
    Column() {
      Text('Hello')
    }
    .width('100%')
    .height('100%')
    .onTouch((event: TouchEvent) => {
      // 保证有Down事件产生，实际调用时机可由开发者决定
      if (event.type === TouchType.Down) {
        let param: Record<string, Object> = {
          "info": "helloworld",
        };
        try {
          let promise = this.subWindow?.restoreMainWindow(param);
          promise?.then(() => {
            console.info('Succeeded in restoring the main window.');
          }).catch((err: BusinessError) => {
            console.error(`Failed to restore the main window. Cause code: ${err.code}, message: ${err.message}`);
          });
        } catch (exception) {
          console.error(`Failed to restore the main window. Cause code: ${exception.code}, message: ${exception.message}`);
        }
      }
    })
  }
}
```

## getWindowLimits<sup>11+</sup>

getWindowLimits(): WindowLimits

获取当前应用窗口的尺寸限制，单位为物理像素px。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                          | 说明           |
| ----------------------------- | ------------------ |
| [WindowLimits](arkts-apis-window-i.md#windowlimits11) | 当前窗口尺寸限制。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| :------- | :----------------------------- |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
try {
  let windowLimits = windowClass.getWindowLimits();
} catch (exception) {
  console.error(`Failed to obtain the window limits of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getWindowLimitsVP<sup>22+</sup>

getWindowLimitsVP(): WindowLimits

获取当前应用窗口的尺寸限制，单位为虚拟像素vp。

对于系统窗口和全局悬浮窗，默认窗口宽高的系统限制最小值为1px，通过此接口获取到的1vp，是计算取整后的值。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                          | 说明           |
| ----------------------------- | ------------------ |
| [WindowLimits](arkts-apis-window-i.md#windowlimits11) | 当前窗口尺寸限制。 |

**错误码：**

错误码详情请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| :------- | :----------------------------- |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
try {
  let windowLimits: window.WindowLimits = windowClass.getWindowLimitsVP();
} catch (exception) {
  console.error(`Failed to obtain the window limits. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowLimits<sup>11+</sup>

setWindowLimits(windowLimits: WindowLimits): Promise&lt;WindowLimits&gt;

设置当前窗口的尺寸限制，使用Promise异步回调。

默认存在一个系统尺寸限制，系统尺寸限制由产品配置决定，不可修改。

未调用setWindowLimits配置过WindowLimits时，使用[getWindowLimits](#getwindowlimits11)或[getWindowLimitsVP](#getwindowlimitsvp22)可获取系统限制。

> **说明：**
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，处于自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）的窗口在尺寸变化时受[WindowLimits](arkts-apis-window-i.md#windowlimits11)约束。触发场景包括：应用主动改变窗口大小（如调用[resize()](#resize9)）；系统调节窗口大小（如分辨率变化、显示大小缩放系数变化）；用户拖拽缩放窗口。
>
> - 非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，主窗口尺寸不受[WindowLimits](arkts-apis-window-i.md#windowlimits11)约束，其他类型窗口仍受[WindowLimits](arkts-apis-window-i.md#windowlimits11)约束。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名       | 类型                          | 必填 | 说明                           |
| :----------- | :---------------------------- | :--- | :----------------------------- |
| windowLimits | [WindowLimits](arkts-apis-window-i.md#windowlimits11) | 是   | 目标窗口的尺寸限制，单位为px或vp。 |

**返回值：**

| 类型                                         | 说明                                |
| :------------------------------------------- | :---------------------------------- |
| Promise&lt;[WindowLimits](arkts-apis-window-i.md#windowlimits11)&gt; | Promise对象。返回设置后的尺寸限制，为入参与系统尺寸限制的交集。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| :------- | :-------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let windowLimits: window.WindowLimits = {
    maxWidth: 1500,
    maxHeight: 1000,
    minWidth: 500,
    minHeight: 400
  };
  let promise = windowClass.setWindowLimits(windowLimits);
    promise.then((data) => {
    console.info('Succeeded in changing the window limits. Cause:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to change the window limits. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to change the window limits. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowLimits<sup>15+</sup>

setWindowLimits(windowLimits: WindowLimits, isForcible: boolean): Promise&lt;WindowLimits&gt;

设置当前窗口的尺寸限制，使用Promise异步回调。

默认存在一个系统尺寸限制，系统尺寸限制由产品配置决定，不可修改。

未调用setWindowLimits配置过WindowLimits时，使用[getWindowLimits](#getwindowlimits11)或[getWindowLimitsVP](#getwindowlimitsvp22)可获取系统限制。

> **说明：**
>
> - [自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，处于自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）的窗口在尺寸变化时受[WindowLimits](arkts-apis-window-i.md#windowlimits11)约束。触发场景包括：应用主动改变窗口大小（如调用[resize()](#resize9)）；系统调节窗口大小（如分辨率变化、显示大小缩放系数变化）；用户拖拽缩放窗口。
>
> - 非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，主窗口尺寸不受[WindowLimits](arkts-apis-window-i.md#windowlimits11)约束，其他类型窗口仍受[WindowLimits](arkts-apis-window-i.md#windowlimits11)约束。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP2-->OpenHarmony 6.0<!--RP2End-->之前，该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

从<!--RP2-->OpenHarmony 6.0<!--RP2End-->开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在Phone、Tablet、PC/2in1设备可正常调用，在其他设备调用返回801错误码。主窗在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备调用不报错不生效，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效。

**参数：**

| 参数名       | 类型                          | 必填 | 说明                           |
| :----------- | :---------------------------- | :--- | :----------------------------- |
| windowLimits | [WindowLimits](arkts-apis-window-i.md#windowlimits11) | 是   | 目标窗口的尺寸限制，单位为px或vp。 |
| isForcible | boolean | 是   | 是否强制设置窗口的尺寸限制。<br>入参[windowLimits](arkts-apis-window-i.md#windowlimits11)的单位为vp时：无论设置true还是false，都按照false处理，窗口宽高的最小值和最大值都取决于系统限制。<br>入参[windowLimits](arkts-apis-window-i.md#windowlimits11)的单位为px时：设置为true，表示窗口宽高最小值以系统限制值和40vp两者中的低数值为准，窗口宽高的最大值仍取决于系统限制；设置为false，表示窗口宽高的最小值和最大值都取决于系统限制。|

**返回值：**

| 类型                                         | 说明                                |
| :------------------------------------------- | :---------------------------------- |
| Promise&lt;[WindowLimits](arkts-apis-window-i.md#windowlimits11)&gt; | Promise对象。返回设置后的窗口尺寸限制。<br>入参[windowLimits](arkts-apis-window-i.md#windowlimits11)的单位为vp时，返回入参与系统默认窗口尺寸限制的交集。<br>入参[windowLimits](arkts-apis-window-i.md#windowlimits11)的单位为px时，isForcible为false则返回入参与系统默认窗口尺寸限制的交集；isForcible为true则返回入参与[系统限制的最小值与40vp两者中的低数值，系统限制的最大值]的交集。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| :------- | :-------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let windowLimits: window.WindowLimits = {
    maxWidth: 1500,
    maxHeight: 1000,
    minWidth: 100,
    minHeight: 100
  };
  let promise = windowClass.setWindowLimits(windowLimits, true);
  promise.then((data) => {
    console.info(`Succeeded in changing the window limits. Cause: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to change the window limits. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to change the window limits. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowMask<sup>12+</sup>

setWindowMask(windowMask: Array&lt;Array&lt;number&gt;&gt;): Promise&lt;void&gt;

设置异形窗口的掩码，使用Promise异步回调。异形窗口为非常规形状的窗口，掩码用于描述异形窗口的形状。此接口仅限子窗和全局悬浮窗可用。

当异形窗口大小发生变化时，实际的显示内容为掩码大小和窗口大小的交集部分。

异形窗口蒙层设置不会影响窗口可见状态(可通过[on('windowVisibilityChange')](arkts-apis-window-Window.md#onwindowvisibilitychange11)或[on('occlusionStateChanged')](arkts-apis-window-Window.md#onocclusionstatechanged22)监听）计算。即使掩码全部设置为0，窗口仍可见，窗口依然按照其原本矩形大小参与可见状态计算。

该接口只在多个线程操作同一个窗口时可能返回错误码1300002。窗口被销毁场景下错误码返回401。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名       | 类型                          | 必填 | 说明                           |
| :----------- | :---------------------------- | :--- | :----------------------------- |
| windowMask | Array&lt;Array&lt;number&gt;&gt; | 是   | 异形窗口的掩码，该参数仅支持宽高为窗口宽高、取值为整数0和整数1的二维数组输入，整数0代表所在像素透明，整数1代表所在像素不透明，宽高不符合的二维数组或二维数组取值不为整数0和整数1的二维数组为非法参数。 |

**返回值：**

| 类型                                         | 说明                                |
| :------------------------------------------- | :---------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| :------- | :-------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003  | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only subwindows and float windows are supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let maskWidth = windowClass.getWindowProperties().windowRect.width;
  let maskHeight = windowClass.getWindowProperties().windowRect.height;
  let windowMask = Array<Array<number>>(maskHeight).fill([]).map((_, row) => {
    let array = Array<number>(maskWidth);
    for (let i = 0 ; i < maskWidth; i++) {
      array[i] = (i + row) > (maskWidth + maskHeight) / 2 ? 1 : 0;
    }
    return array;
  });
  let promise = windowClass.setWindowMask(windowMask);
  promise.then(() => {
    console.info('Succeeded in setting the window mask.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window mask. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window mask. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowMaskWithAlpha

setWindowMaskWithAlpha(windowMask: Uint8Array, maskWidth: number, maskHeight: number): Promise&lt;void&gt;

通过按像素顺序排列的Alpha数组设置异形窗口的掩码，像素顺序以窗口左上角为像素起点，同行内从左到右依次排列，从上至下逐行排列。使用Promise异步回调。异形窗口为非常规形状的窗口，掩码用于描述异形窗口的形状。此接口仅限子窗和全局悬浮窗可用。

当异形窗口大小发生变化时，实际的显示内容为掩码大小和窗口大小的交集部分。

异形窗口蒙层设置不会影响窗口可见状态（可通过[on('windowVisibilityChange')](arkts-apis-window-Window.md#onwindowvisibilitychange11)或[on('occlusionStateChanged')](arkts-apis-window-Window.md#onocclusionstatechanged22)监听）计算。即使掩码全部设置为0，窗口仍可见，窗口依然按照其原本矩形大小参与可见状态计算。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名       | 类型                          | 必填 | 说明                           |
| :----------- | :---------- | :--- | :----------------------------- |
| windowMask   | Uint8Array  | 是   | 异形窗口的掩码，为按像素顺序排列的Alpha数组，该数组中每个元素代表对应像素的透明度，取值范围[0, 255]，0表示完全透明，255表示完全不透明，数组长度等于maskWidth乘以maskHeight。 |
| maskWidth    | number      | 是   | 表示异形窗口掩码的宽度，必须等于窗口宽度。 |
| maskHeight   | number      | 是   | 表示异形窗口掩码的高度，必须等于窗口高度。 |

**返回值：**

| 类型                                         | 说明                                |
| :------------------------------------------- | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| :------- | :-------------------------------------------- |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003  | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only subwindows and float windows are supported. |
| 1300016  | Parameter error. Possible cause: 1. The maskWidth is not equal to the window width or the maskHeight is not equal to the window height. 2. The length of windowMask is not equal to maskWidth multiplied by maskHeight. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let maskWidth = windowClass.getWindowProperties().windowRect.width;
  let maskHeight = windowClass.getWindowProperties().windowRect.height;
  let windowMask = new Uint8Array(maskWidth * maskHeight);
  for (let i = 0 ; i < maskHeight; i++) {
    for (let j = 0 ; j < maskWidth; j++) {
      windowMask[i * maskWidth + j] = (i + j) > (maskWidth + maskHeight) / 2 ? 255 : 0;
    }
  }
  windowClass.setWindowMaskWithAlpha(windowMask, maskWidth, maskHeight).then(() => {
    console.info('Succeeded in setting the window mask.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window mask. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window mask. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## clearWindowMask<sup>24+</sup>

clearWindowMask(): Promise&lt;void&gt;

清除异形窗口的掩码使其恢复为矩形窗口，使用Promise异步回调。异形窗口为非常规形状的窗口，掩码用于描述异形窗口的形状。此接口仅限子窗和全局悬浮窗可用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                                         | 说明                                |
| :------------------------------------------- | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| :------- | :-------------------------------------------- |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities.                               |
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error. 3. The window has not set window mask yet.  |
| 1300003  | This window manager service works abnormally.                                                                      |
| 1300004  | Unauthorized operation.  Possible cause: Invalid window type. Only subwindows and float windows are supported.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let maskWidth = windowClass.getWindowProperties().windowRect.width;
  let maskHeight = windowClass.getWindowProperties().windowRect.height;
  let windowMask = Array<Array<number>>(maskHeight).fill([]).map((_, row) => {
    let array = Array<number>(maskWidth);
    for (let i = 0 ; i < maskWidth; i++) {
      array[i] = (i + row) > (maskWidth + maskHeight) / 2 ? 1 : 0;
    }
    return array;
  });
  windowClass.setWindowMask(windowMask).then(() => {
    console.info('Succeeded in setting the window mask.');
    windowClass?.clearWindowMask().then(() => {
      console.info('Succeeded in clearing the window mask.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to clear window mask. Cause code: ${err.code}, message: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window mask. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set or clear the window mask. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setTouchableAreas

setTouchableAreas(rects: Array&lt;Rect&gt;): Promise&lt;void&gt;

设置当前窗口的可触摸区域，使用Promise异步回调。

默认情况下，整个窗口区域都是可触摸的；可触摸区域外的触摸事件将被透传至下层。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**需要权限：** ohos.permission.SET_WINDOW_TOUCH_AREAS

**设备行为差异：**

在PC/2in1设备、其他设备的[电脑模式](../../windowmanager/window-terminology.md#pc-mode电脑模式)下，当窗口的大小或位置发生变化后，通过该接口设置的可触摸区域不会被重置；在其他设备和其他模式下，当窗口的大小或位置发生变化后，通过该接口设置的可触摸区域会被重置，需调用此接口重新设置。

**参数：**

| 参数名       | 类型                          | 必填 | 说明                           |
| :----------- | :---------------------------- | :--- | :----------------------------- |
| rects | Array&lt;[Rect](arkts-apis-window-i.md#rect7)&gt; | 是   | 窗口可触摸区域。可触摸区域最大个数不能超过10个，否则抛错误码1300016，且范围不能超出窗口区域。 |

**返回值：**

| 类型                                         | 说明                                |
| :------------------------------------------- | :---------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| :------- | :-------------------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required or a non-system application calls the API. |
| 1300002  | This window state is abnormal.    |
| 1300003  | This window manager service works abnormally.                                                                      |
| 1300016 | Parameter error. Possible cause: Invalid parameter range. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const touchableRects: Array<window.Rect> = [
  { left: 100, top: 100, width: 200, height: 200 },
  { left: 0, top: 50, width: 150, height: 200 }
];
try {
  windowClass.setTouchableAreas(touchableRects).then(() => {
    console.info('Succeeded in setting the touchable areas.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the touchable areas. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set touchable areas. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## keepKeyboardOnFocus<sup>11+</sup>

keepKeyboardOnFocus(keepKeyboardFlag: boolean): void

当前窗口获焦时是否保留由其他窗口创建的软键盘，支持系统窗口、应用子窗口、模态窗和全局悬浮窗。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名           | 类型    | 必填 | 说明                                                         |
| ---------------- | ------- | ---- | ------------------------------------------------------------ |
| keepKeyboardFlag | boolean | 是   | 是否保留其他窗口创建的软键盘。true表示保留；false表示不保留。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                                     |
| ------- |--------------------------------------------------------------------------------------------------------------------------|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.             |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.                                     |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.                                   |
| 1300004 | Unauthorized operation. Possible cause: Only float windows, subwindows, dialog windows, or window type as system windows are supported. |

**示例：**

```ts
try {
  windowClass.keepKeyboardOnFocus(true);
} catch (exception) {
  console.error(`Failed to keep keyboard onFocus. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowDecorVisible<sup>11+</sup>

setWindowDecorVisible(isVisible: boolean): void

设置窗口标题栏是否可见，对存在标题栏和三键区的窗口形态生效。Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

设置窗口标题栏不可见后，当主窗口进入全屏沉浸状态时，此时鼠标Hover到上方窗口标题栏热区上会显示悬浮标题栏。若想禁用悬浮标题栏显示，请使用[setTitleAndDockHoverShown()](#settitleanddockhovershown14)接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| isVisible | boolean | 是   | 设置标题栏是否可见，true为可见，false为隐藏。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004  | Unauthorized operation. <br>适用版本：11-19 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent("pages/page2", storage, (err: BusinessError) => {
  let errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in loading the content.');
  let isVisible = false;
  // 调用setWindowDecorVisible接口
  try {
      windowClass?.setWindowDecorVisible(isVisible);
  } catch (exception) {
      console.error(`Failed to set the visibility of window decor. Cause code: ${exception.code}, message: ${exception.message}`);
  }
});
```

## getWindowDecorVisible<sup>18+</sup>

getWindowDecorVisible(): boolean

查询窗口标题栏是否可见。如果使用Stage模型，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| boolean | 返回当前窗口标题栏是否可见，true表示可见，false表示不可见。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
let isVisible: boolean | undefined = undefined;
windowClass.setUIContent('pages/WindowPage').then(() => {
  try {
    isVisible = windowClass?.getWindowDecorVisible();
  } catch (exception) {
    console.error(`Failed to get the window decor visibility. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

## setWindowTitle<sup>15+</sup>

setWindowTitle(titleName: string): Promise&lt;void&gt;

设置窗口标题，使用Promise异步回调。如果使用Stage模型，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**
 - 对于主窗口：
   - 本接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；
   - 在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不报错不生效，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效；
   - 在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回1300002或801错误码。

 - 对于显示标题栏的子窗口（即创建子窗口时设置[SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11)中的decorEnabled为true）：
   - 在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；
   - 在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不报错不生效，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效；
   - 在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回1300002或801错误码。

 - 对于不显示标题栏的子窗口（即创建子窗口时设置[SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11)中的decorEnabled为false），调用本接口将返回1300002或801错误码。

**参数：**

| 参数名    | 类型     | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| titleName | string  | 是   | 窗口标题。标题显示区域最右端不超过系统三键区域最左端，超过部分以省略号表示。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let title = "title";
  windowClass.setWindowTitle(title).then(() => {
    console.info('Succeeded in setting the window title.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window title. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window title. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowTitleMoveEnabled<sup>14+</sup>

setWindowTitleMoveEnabled(enabled: boolean): void

禁止/使能主窗或子窗标题栏默认移动窗口和双击最大化的功能，当禁用标题栏默认移动窗口和双击最大化的功能时，可使用[startMoving()](#startmoving14)在应用热区中发起拖拽移动，使用[maximize()](#maximize12)实现最大化功能。如果使用Stage模型，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名    | 类型     | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| enabled    | boolean | 是   | 是否使能标题栏默认移动窗口和双击最大化功能，true表示使能，false表示不使能。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004  | Unauthorized operation.        |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      windowStage.loadContent("pages/Index").then(() =>{
        let windowClass = windowStage.getMainWindowSync();
        let enabled = false;
        windowClass.setWindowTitleMoveEnabled(enabled);
        console.info(`Succeeded in setting the the window title move enabled: ${enabled}`);
      });
    } catch (exception) {
      console.error(`Failed to set the window title move enabled. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## setSubWindowModal<sup>12+</sup>

setSubWindowModal(isModal: boolean): Promise&lt;void&gt;

设置子窗的模态属性是否启用，使用Promise异步回调。

启用子窗口模态属性后，其父级窗口不能响应用户操作，直到子窗口关闭或者子窗口的模态属性被禁用。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用该接口不生效也不报错。子窗之外的窗口调用该接口时会返回1300004错误码。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| isModal | boolean | 是   | 设置子窗口模态属性是否启用，true为启用，false为不启用。 |


**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300003  | This window manager service works abnormally.<br>适用版本：20+ |
| 1300004  | Unauthorized operation.        |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    // 创建子窗
    try {
      let subWindow = windowStage.createSubWindow("testSubWindow");
      subWindow.then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        let promise = windowClass.setSubWindowModal(true);
        promise.then(() => {
          console.info('Succeeded in setting subwindow modal');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set subwindow modal. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## setSubWindowModal<sup>14+</sup>

setSubWindowModal(isModal: boolean, modalityType: ModalityType): Promise&lt;void&gt;

设置子窗的模态属性是否启用，并设置其模态类型，使用Promise异步回调。

当子窗口模态类型为[WINDOW_MODALITY](arkts-apis-window-e.md#modalitytype14)时，其父级窗口不能响应用户操作，直到子窗口关闭或者子窗口的模态类型被禁用。

当子窗口模态类型为[APPLICATION_MODALITY](arkts-apis-window-e.md#modalitytype14)时，其父级窗口与该应用其他实例的窗口不能响应用户操作，直到子窗口关闭或者子窗口的模态类型被禁用。

此接口仅支持设置子窗口模态类型，当需要禁用子窗口模态属性时，建议使用[setSubWindowModal<sup>12+</sup>](#setsubwindowmodal12)。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用该接口不生效也不报错。子窗之外的窗口调用该接口时会返回1300004错误码。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| isModal | boolean | 是   | 设置子窗口模态属性是否启用，true为启用，false为不启用。当前仅支持设置为true，为false将返回401错误码。 |
| modalityType | [ModalityType](arkts-apis-window-e.md#modalitytype14) | 是   | 子窗口模态类型。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                         |
| -------- |--------------------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities.                         |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed.                       |
| 1300003  | This window manager service works abnormally. <br>适用版本：20+                                                               |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only subwindows are supported.                  |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    // 创建子窗
    try {
      let subWindow = windowStage.createSubWindow("testSubWindow");
      subWindow.then((data) => {
        if (!data) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        let promise = windowClass.setSubWindowModal(true, window.ModalityType.WINDOW_MODALITY);
        promise.then(() => {
          console.info('Succeeded in setting subwindow modal');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set subwindow modal. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## setWindowDecorHeight<sup>11+</sup>

setWindowDecorHeight(height: number): void

设置窗口的标题栏高度，对存在标题栏和三键区的窗口形态生效。如果使用Stage模型，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

当主窗口进入全屏沉浸状态时，此时鼠标Hover到窗口标题栏热区时，会显示悬浮标题栏，悬浮标题栏高度固定为37vp。

由于系统像素转换可能存在精度误差，设置后调用[getWindowDecorHeight()](#getwindowdecorheight11)获取的值可能与设置的值存在1vp的差异。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备调用不报错不生效，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备调用不报错不生效。

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| height | number | 是   |设置的窗口标题栏高度，仅支持具有窗口标题栏的窗口。该参数为整数，浮点数输入将向下取整，取值范围为[37,112]，范围外为非法参数，单位为vp。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: Invalid parameter range. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
windowClass.setUIContent('pages/WindowPage').then(() => {
  let height: number = 50;
  try {
    windowClass?.setWindowDecorHeight(height);
    console.info(`Succeeded in setting the height of window decor: ${height}`);
  } catch (exception) {
    console.error(`Failed to set the height of window decor. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

## setDecorButtonStyle<sup>14+</sup>

setDecorButtonStyle(dectorStyle: DecorButtonStyle): void

设置标题栏按钮样式，仅对主窗和子窗生效。如果使用Stage模型，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在OpenHarmony 5.1.0之前，该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

从OpenHarmony 5.1.0开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| dectorStyle | [DecorButtonStyle](arkts-apis-window-i.md#decorbuttonstyle14)  | 是   | 要设置的标题栏按钮样式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows and subwindows are supported. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { ConfigurationConstant } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      windowStage.loadContent("pages/Index").then(() =>{
        let windowClass = windowStage.getMainWindowSync();
        let colorMode : ConfigurationConstant.ColorMode = ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT;
        let style: window.DecorButtonStyle = {
          colorMode: colorMode,
          buttonBackgroundSize: 28,
          spacingBetweenButtons: 12,
          closeButtonRightMargin: 20,
          buttonIconSize: 20,
          buttonBackgroundCornerRadius: 4
        };
        windowClass.setDecorButtonStyle(style);
        console.info(`Succeeded in setting the style of button. Data: ${JSON.stringify(style)}`);
      });
    } catch (exception) {
      console.error(`Failed to set the style of button. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## getDecorButtonStyle<sup>14+</sup>

getDecorButtonStyle(): DecorButtonStyle

获取标题栏按钮样式，仅对主窗和子窗生效。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在OpenHarmony 5.1.0之前，该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

从OpenHarmony 5.1.0开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**返回值：**

| 类型                                  | 说明                                                         |
| ------------------------------------- | ------------------------------------------------------------ |
| [DecorButtonStyle](arkts-apis-window-i.md#decorbuttonstyle14) | 返回当前窗口标题栏上的按钮样式，窗口标题栏按钮区域位于窗口的右上角。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**示例：**

```ts
try {
  let decorButtonStyle = windowClass.getDecorButtonStyle();
  console.info(`Succeeded in getting the style of button. Data: ${JSON.stringify(decorButtonStyle)}`);
} catch (exception) {
  console.error(`Failed to get the style of button. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getWindowDecorHeight<sup>11+</sup>

getWindowDecorHeight(): number

对存在标题栏和三键区的窗口形态生效，用于获取窗口的标题栏高度。如果使用Stage模型，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

由于系统像素转换可能存在精度误差，调用[setWindowDecorHeight()](#setwindowdecorheight11)设置的值与获取的值可能存在1vp的差异。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错。

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 返回的窗口标题栏高度。该参数为整数，取值范围为[37,112]，单位为vp。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
windowClass.setUIContent('pages/WindowPage').then(() => {
  try {
    let height = windowClass?.getWindowDecorHeight();
    console.info(`Succeeded in getting the height of window decor: ${height}`);
  } catch (exception) {
    console.error(`Failed to get the height of window decor. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

## getTitleButtonRect<sup>11+</sup>

getTitleButtonRect(): TitleButtonRect

获取主窗口或启用标题栏的子窗口的标题栏上的最小化、最大化、关闭按钮矩形区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                                  | 说明                                                         |
| ------------------------------------- | ------------------------------------------------------------ |
| [TitleButtonRect](arkts-apis-window-i.md#titlebuttonrect11) | 标题栏上的最小化、最大化、关闭按钮矩形区域，该区域位置坐标相对窗口右上角。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let titleButtonArea = windowClass.getTitleButtonRect();
        console.info('Succeeded in obtaining the area of title buttons. Data: ' + JSON.stringify(titleButtonArea));
      } catch (exception) {
        console.error(`Failed to get the area of title buttons. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## getWindowStatus<sup>12+</sup>

getWindowStatus(): WindowStatusType

获取当前应用窗口的模式。

> **说明：**
>
> 在[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，应用的[targetAPIVersion](../../quick-start/app-configuration-file.md#配置文件标签)设置小于14时，在窗口最大化状态（窗口铺满整个屏幕，2in1设备会有dock栏和状态栏，Tablet设备会有状态栏）时返回值对应为WindowStatusType::FULL_SCREEN。应用的[targetAPIVersion](../../quick-start/app-configuration-file.md#配置文件标签)设置大于等于14时，在窗口最大化状态（窗口铺满整个屏幕，2in1设备会有dock栏和状态栏，Tablet设备会有状态栏）时返回值对应为WindowStatusType::MAXIMIZE。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                           | 说明                                   |
| ------------------------------ | ----------------------------------------|
| [WindowStatusType](arkts-apis-window-e.md#windowstatustype11) | 当前窗口模式。                              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
try {
  let windowStatusType = windowClass.getWindowStatus();
} catch (exception) {
  console.error(`Failed to obtain the window status of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setSupportedWindowModes

setSupportedWindowModes(supportedWindowModes: Array<bundleManager.SupportWindowMode>): Promise&lt;void&gt;

设置主窗或子窗支持的窗口模式，使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持且处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用生效；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错，切换为[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下生效；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| supportedWindowModes | Array&lt;[bundleManager.SupportWindowMode](../apis-ability-kit/js-apis-bundleManager.md#supportwindowmode)&gt; | 是   | 设置窗口支持的窗口模式。<br>- FULL_SCREEN：全屏模式。<br>- FLOATING：支持自由悬浮窗口模式。<br>- SPLIT：分屏模式。主窗不支持仅配置SPLIT，需要配合FULL_SCREEN或FLOATING一起使用；子窗不支持配置SPLIT。<br>说明：对于主窗来说，此参数数组中的取值不应该与该UIAbility对应的[module.json5配置文件](../../quick-start/module-configuration-file.md)中[abilities标签](../../quick-start/module-configuration-file.md#abilities标签)的supportWindowMode字段取值或者[StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions)的supportWindowModes属性取值冲突。当取值冲突时，最终以该参数设置的窗口支持模式为准。|

**返回值：**

| 类型 | 说明 |
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error.|
| 1300003  | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. Possible cause: 1. Only main windows and subwindows are supported. 2. Not supported when subwindows are set to follow the main window. |
| 1300016  | Parameter error. Possible cause: 1. When called on a main window, the parameter should not only contain SPLIT. 2. When called on a sub window, the parameter should not contain SPLIT. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility, bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.getMainWindow().then((windowClass) => {
      try {
        let promise = windowClass.setSupportedWindowModes([
          bundleManager.SupportWindowMode.FULL_SCREEN,
          bundleManager.SupportWindowMode.SPLIT,
          bundleManager.SupportWindowMode.FLOATING
        ]);
        promise.then(() => {
          console.info('Succeeded in setting window support modes');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set window support modes. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set window support modes. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## isFocused<sup>12+</sup>

isFocused(): boolean

判断当前窗口是否已获焦。为获取准确的获焦状态，需要在[WindowEventType](arkts-apis-window-e.md#windoweventtype10)生命周期处于WINDOW_ACTIVE之后调用。

可使用[on('windowEvent')](#onwindowevent10)监听对应状态变更，再执行对应具体业务。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ------- | ------------------------------------------------------------------ |
| boolean | 当前窗口是否已获焦。true表示当前窗口已获焦，false则表示当前窗口未获焦。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

```ts
try {
  let focus = windowClass.isFocused();
  console.info(`Succeeded in checking whether the window is focused. Data: ${focus}`);
} catch (exception) {
  console.error(`Failed to check whether the window is focused. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## createSubWindowWithOptions<sup>12+</sup>

createSubWindowWithOptions(name: string, options: SubWindowOptions): Promise&lt;Window&gt;

创建子窗口，使用Promise异步回调。

- 可以在主窗口下创建子窗口（包括[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)、非独立子窗）。
- 可以在子窗口下创建子窗口（只能创建非独立子窗，否则返回1300004错误码）。
- 可以在全局悬浮窗下创建子窗口（只能创建非独立子窗，否则返回1300004错误码）。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回undefined。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| name   | string | 是   | 子窗口的名字。 |
| options  | [SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11) | 是   | 子窗口参数。decorEnabled为true时，子窗口为非[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)；decorEnabled为false时，子窗口为沉浸式布局。|

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前Window下创建的子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error; 3. The subWindow has been created and can not be created again. 4. It is not allowed to create non-secure window when secure extension exists. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: 1. Invalid window type. Only main windows, subwindows, and floating windows are supported; 2. When SubWindowOptions.zLevelAboveParentLoosened is true, only main windows are supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let options : window.SubWindowOptions = {
    title: 'title',
    decorEnabled: true,
    isModal: true
  };
  let promise = windowClass.createSubWindowWithOptions('mySubWindow', options);
  promise.then((data) => {
    console.info(`Succeeded in creating the subwindow. Data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setParentWindow<sup>19+</sup>

setParentWindow(windowId: number): Promise&lt;void&gt;

更改子窗口的父窗口，该父窗口仅支持同进程下的主窗口、子窗口或全局悬浮窗，使用Promise异步回调。

如果该子窗口处于获焦状态，且新的父窗口处于前台，则会抬升父窗口的层级。

如果该子窗口处于获焦状态，且新的父窗口的子窗口存在层级更高的模态子窗口，则焦点会转移给该模态子窗口。

针对[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)，仅支持迁移至主窗口下，否则返回1300009错误码。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| windowId  | number | 是   | 父窗口id，该参数应为整数。推荐使用[getWindowProperties()](#getwindowproperties9)方法获取父窗口id属性。|

**返回值：**

| 类型                | 说明                     |
| ------------------- | ------------------------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only subwindows are supported. |
| 1300009 | The parent window is invalid. Possible cause: The parent window does not exist or has been destroyed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowClass: window.Window = window.findWindow("subWindow");
  let newParentWindow: window.Window = window.findWindow("newParentWindow");
  let newParentWindowId: number = newParentWindow.getWindowProperties().id;
  let promise = windowClass.setParentWindow(newParentWindowId);
  promise.then(() => {
    console.info('Succeeded in setting the new parent window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the new parent window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the new parent window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## getParentWindow<sup>19+</sup>

getParentWindow(): Window

获取子窗口的父窗口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在各设备均可正常调用。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ----------------- | ------------------- |
| [Window](arkts-apis-window-Window.md) | 子窗口的父窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed.    |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type, not called from subwindow. |
| 1300009 | The parent window is invalid. |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("subWindow");
  let parentWindow: window.Window = windowClass.getParentWindow();
  let properties = parentWindow.getWindowProperties();
  console.info(`Succeeded in obtaining parent window properties. Property: ${JSON.stringify(properties)}`);
} catch (exception) {
  console.error(`Failed to get the parent window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowTitleButtonVisible<sup>14+</sup>

setWindowTitleButtonVisible(isMaximizeButtonVisible: boolean, isMinimizeButtonVisible: boolean, isCloseButtonVisible?: boolean): void

设置标题栏上的最大化、最小化、关闭按钮是否可见。

仅支持主窗和[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)，其他窗口调用时将返回1300004错误码。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| isMaximizeButtonVisible | boolean | 是   | 设置最大化按钮是否可见，true为可见，false为隐藏。如果最大化按钮隐藏，那么在最大化场景下，也隐藏对应的还原按钮。 |
| isMinimizeButtonVisible | boolean | 是   | 设置最小化按钮是否可见，true为可见，false为隐藏。 |
| isCloseButtonVisible | boolean | 否   | 设置关闭按钮是否可见，true为可见，false为隐藏，默认值true。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004  | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // 加载主窗口对应的页面
    windowStage.loadContent('pages/Index', (err) => {
      let mainWindow: window.Window | undefined = undefined;
      // 获取应用主窗口。
      windowStage.getMainWindow().then(
        data => {
          if (!data) {
            console.error('Failed to get main window. Cause: The data is undefined.');
            return;
          }
          mainWindow = data;
          console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
          // 调用setWindowTitleButtonVisible接口，隐藏主窗标题栏最大化、最小化、关闭按钮。
          mainWindow.setWindowTitleButtonVisible(false, false, false);
        }
      ).catch((err: BusinessError) => {
          if(err.code){
            console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          }
      });
    });
  }
}
```

## setWindowTopmost<sup>14+</sup>

setWindowTopmost(isWindowTopmost: boolean): Promise&lt;void&gt;

应用主窗口调用，用于实现将窗口置于其他应用窗口之上不被遮挡，使用Promise异步回调。

应用可通过自定义快捷键实现主窗口的置顶和取消置顶。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**需要权限：** ohos.permission.WINDOW_TOPMOST

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| isWindowTopmost | boolean | 是   | 设置主窗口置顶，true为置顶，false为取消置顶。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API.  |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |

**示例：**

```ts
// Index.ets
import { window } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined;
let keyUpEventAry: string[] = [];

@Entry
@Component
struct Index {
  private context = (this.getUIContext()?.getHostContext() as common.UIAbilityContext);
  private windowStage = this.context.windowStage;

  build() {
    RelativeContainer() {
      Button("窗口置顶")
        .onClick(() => {
          try {
            windowClass = this.windowStage.getMainWindowSync();
            // true:窗口置顶，false:取消窗口置顶
            let isWindowTopmost: boolean = true;
            let promiseTopmost = windowClass.setWindowTopmost(isWindowTopmost);
            promiseTopmost.then(() => {
              console.info('Succeeded in setting the main window to be topmost.');
            }).catch((err: BusinessError) => {
              console.error(`Failed to set the main window to be topmost. Cause code: ${err.code}, message: ${err.message}`);
            });
          } catch (exception) {
            console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`)
          }
        })
    }
    .height('100%')
    .width('100%')
    .onKeyEvent((event) => {
      if(event) {
        if(event.type === KeyType.Down) {
          keyUpEventAry = [];
        }
        if(event.type === KeyType.Up) {
          keyUpEventAry.push(event.keyText);
          // 自定义快捷键 ctrl+T 执行主窗口置顶、取消置顶的操作
          if(windowClass && keyUpEventAry.includes('KEYCODE_CTRL_LEFT') && keyUpEventAry.includes('KEYCODE_T')) {
            let isWindowTopmost: boolean = false;
            windowClass.setWindowTopmost(isWindowTopmost);
          }
        }
      }
    })
  }
}
```

## raiseToAppTop<sup>14+</sup>

raiseToAppTop(): Promise&lt;void&gt;

应用子窗口调用，提升应用子窗口到顶层，只在当前应用同一个父窗口下的相同类型子窗范围内生效，对于自定义了zLevel属性的子窗口，只在当前应用同一个父窗口下相同zLevel值的子窗范围内生效。使用Promise异步回调。

使用该接口需要先创建子窗口，并确保该子窗口调用[showWindow()](#showwindow9)并执行完毕。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用该接口不生效也不报错。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    // 创建子窗
    windowStage.createSubWindow('testSubWindow').then((subWindow) => {
      if (subWindow == null) {
        console.error('Failed to create the subWindow. Cause: The data is empty');
        return;
      }
      subWindow.showWindow().then(() => {
        subWindow.raiseToAppTop().then(() => {
          console.info('Succeeded in raising window to app top');
        }).catch((err: BusinessError)=>{
          console.error(`Failed to raise window to app top. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    });
  }
}
```

## setRaiseByClickEnabled<sup>14+</sup>

setRaiseByClickEnabled(enable: boolean): Promise&lt;void&gt;

禁止/使能子窗点击抬升功能。使用Promise异步回调。

通常来说，点击一个子窗口，会将该子窗口显示抬升到应用内同一个父窗口下同类型子窗口的最上方，如果设置为false，那么点击子窗口的时候，不会将该子窗口进行抬升，而是保持不变。

使用该接口需要先创建子窗口，并确保该子窗口调用[showWindow()](#showwindow9)并执行完毕。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | 是   | 设置子窗口点击抬升功能是否使能，true表示使能，false表示禁止。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    // 创建子窗
    windowStage.createSubWindow("testSubWindow").then((subWindow) => {
      if (subWindow == null) {
        console.error('Failed to create the subWindow. Cause: The data is empty');
        return;
      }
      subWindow.showWindow().then(() => {
        try {
          let enabled = false;
          subWindow.setRaiseByClickEnabled(enabled).then(() => {
            console.info('Succeeded in disabling the raise-by-click function.');
          }).catch((err: BusinessError) => {
            console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
          });
        } catch (err) {
          console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
        }
      });
    });
  }
}
```

## enableLandscapeMultiWindow<sup>12+</sup>

enableLandscapeMultiWindow(): Promise&lt;void&gt;

应用部分界面支持横向布局时，在进入该界面时使能，使能后可支持进入横向[智慧多窗](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/multi-window-intro)。不建议竖向布局界面使用。

此接口只对应用主窗口生效，且需要在module.json5配置文件中[abilities](../../quick-start/module-configuration-file.md#abilities标签)标签中配置[preferMultiWindowOrientation](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/multi-window-support)属性为"landscape_auto"。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal task error. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let promise = windowClass.enableLandscapeMultiWindow();
      promise.then(() => {
        console.info('Succeeded in making multi-window become landscape.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to make multi-window become landscape. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

## disableLandscapeMultiWindow<sup>12+</sup>

disableLandscapeMultiWindow(): Promise&lt;void&gt;

应用部分界面支持横向布局时，在退出该界面时去使能，去使能后不支持进入横向[智慧多窗](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/multi-window-intro)。

此接口只对应用主窗口生效，且需要在module.json5配置文件中[abilities](../../quick-start/module-configuration-file.md#abilities标签)标签中配置[preferMultiWindowOrientation](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/multi-window-support)属性为"landscape_auto"。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. Possible cause: Internal task error. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let promise = windowClass.disableLandscapeMultiWindow();
      promise.then(() => {
        console.info('Succeeded in making multi-window become not landscape.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to make multi-window become not landscape. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

## setDialogBackGestureEnabled<sup>12+</sup>

setDialogBackGestureEnabled(enabled: boolean): Promise&lt;void&gt;

设置模态窗口是否响应手势返回事件，非模态窗口调用返回错误码。

**系统能力**：SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| enabled    | boolean | 是   | 是否响应手势返回事件。<br>true表示响应手势返回事件，触发onBackPress回调；false表示不响应手势返回事件，不触发onBackPress回调。</br> |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only dialog windows are supported.|

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
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
        windowClass.setUIContent("pages/Index");
        let enabled = true;
        let promise = windowClass.setDialogBackGestureEnabled(enabled);
        promise.then(() => {
          console.info('Succeeded in setting dialog window to respond back gesture.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set dialog window to respond back gesture. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (exception) {
      console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

```ts
// ets/pages/Index.ets
@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
    .height('100%')
    .width('100%')
  }

  onBackPress(): boolean | void {
    console.info('Succeeded in setting dialog window to respond back gesture.');
    return true;
  }
}
```

## enableDrag<sup>20+</sup>

enableDrag(enable: boolean): Promise&lt;void&gt;

使能/禁止拖拽窗口，仅对系统窗口、应用子窗口、全局悬浮窗和模态窗口生效。使用Promise异步回调。

使能后，将允许通过鼠标操作或触摸对窗口进行拉伸操作。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---------------------------- | -- | --------- |
| enable| boolean | 是 | 是否允许拖拽。<br>true表示允许，false表示不允许。</br> |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.enableDrag(true).then(() => {
    console.info('succeeded in setting window draggable');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window draggable. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set window draggable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## startMoving<sup>14+</sup>

startMoving(): Promise&lt;void&gt;

开始移动窗口，使用Promise异步回调。

[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，对系统窗口、应用主窗口、应用子窗口、全局悬浮窗和模态窗口生效。非自由窗口状态下，仅对系统窗口、应用子窗口、全局悬浮窗和模态窗口生效，应用主窗口调用该接口返回801或1300004错误码。

仅在[onTouch](arkui-ts/ts-universal-events-touch.md#ontouch)事件（其中，事件类型必须为TouchType.Down）的回调方法中调用此接口才会有移动效果，成功调用此接口后，窗口将跟随鼠标或触摸点移动。

在点击拖拽场景下，若不期望在按下时触发拖拽事件，则可以在事件类型为[TouchType.Move](./arkui-ts/ts-appendix-enums.md#touchtype)（需要保证当前行为已经触发TouchType.Down事件）时调用此接口，触发移动效果。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type, main windows are not supported in non-free window mode. |

**示例：**

```ts
// Index.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private isTouchDown: boolean = false;
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Red)
          .onTouch((event: TouchEvent) => {
            if(event.type == TouchType.Down){
              this.isTouchDown = true;
            } else if (event.type === TouchType.Move && this.isTouchDown) {
              try {
                let context = this.getUIContext()?.getHostContext();
                if (!context) {
                  console.error('Failed to get host context.');
                  return;
                }
                window.getLastWindow(context).then((data)=>{
                  if (!data) {
                    console.error('Failed to get last window.');
                    return;
                  }
                  let windowClass: window.Window = data;
                  windowClass.startMoving().then(() => {
                    console.info('Succeeded in starting moving window.')
                  }).catch((err: BusinessError) => {
                    console.error(`Failed to start moving. Cause code: ${err.code}, message: ${err.message}`);
                  });
                });
              } catch (exception) {
                console.error(`Failed to start moving window. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            } else {
              this.isTouchDown = false;
            }
          })
      }.width('100%')
    }.height('100%').width('100%')
  }
}
```

## startMoving<sup>15+</sup>

startMoving(offsetX: number, offsetY: number): Promise&lt;void&gt;

指定鼠标在窗口内的位置并移动窗口，使用Promise异步回调。

在同应用内窗口分合后，且鼠标保持按下状态直接移动新窗口，如果此时鼠标快速移动，窗口移动时鼠标可能会在窗口外。可以使用本接口指定窗口移动时鼠标在窗口内的位置，先移动窗口到鼠标位置，再开始移动窗口。

仅在[onTouch](arkui-ts/ts-universal-events-touch.md#ontouch)事件（其中，事件类型必须为TouchType.Down）的回调方法中调用此接口才会有移动效果，成功调用此接口后，窗口将跟随鼠标移动。

在点击拖拽场景下，若不期望在按下时触发拖拽事件，则可以在事件类型为[TouchType.Move](./arkui-ts/ts-appendix-enums.md#touchtype)（需要保证当前行为已经触发TouchType.Down事件）时调用此接口，触发移动效果。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名     | 类型       | 必填     | 说明                                                 |
| --------- | --------- | ------- |----------------------------------------------------|
| offsetX | number | 是 | 窗口移动时预期鼠标位置相对窗口左上角的x轴偏移量，单位为px，该参数仅支持整数输入，浮点数向下取整。负值为非法参数，大于窗口宽度为非法参数，窗口宽度可以在窗口属性[WindowProperties](arkts-apis-window-i.md#windowproperties)中获取。 |
| offsetY | number | 是 | 窗口移动时预期鼠标位置相对窗口左上角的y轴偏移量，单位为px，该参数仅支持整数输入，浮点数向下取整。负值为非法参数，大于窗口高度为非法参数，窗口高度可以在窗口属性[WindowProperties](arkts-apis-window-i.md#windowproperties)中获取。 |

**返回值：**

| 类型                | 说明                         |
| ------------------- |----------------------------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ---- | -------------------------------------------- |
| 401 | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**示例：**

```ts
// Index.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  private isTouchDown: boolean = false;
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Red)
          .onTouch((event: TouchEvent) => {
            if(event.type == TouchType.Down){
              this.isTouchDown = true;
            } else if (event.type === TouchType.Move && this.isTouchDown) {
              try {
                let context = this.getUIContext()?.getHostContext();
                if (!context) {
                  console.error('Failed to get host context.');
                  return;
                }
                window.getLastWindow(context).then((data)=>{
                  let windowClass: window.Window = data;
                  windowClass.startMoving(100, 50).then(() => {
                    console.info('Succeeded in starting moving window.')
                  }).catch((err: BusinessError) => {
                    console.error(`Failed to start moving. Cause code: ${err.code}, message: ${err.message}`);
                  });
                });
              } catch (exception) {
                console.error(`Failed to start moving window. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            } else {
              this.isTouchDown = false;
            }
          })
      }.width('100%')
    }.height('100%').width('100%')
  }
}
```

## stopMoving<sup>15+</sup>

stopMoving(): Promise&lt;void&gt;

在窗口拖拽移动过程中，通过此接口来停止窗口移动，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                | 说明                      |
| ------------------- | -------------------------|
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------------------------- |
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
    try {
      let windowClass = windowStage.getMainWindowSync();
      windowClass.on('windowRectChange', (data: window.RectChangeOptions) => {
        if (data.reason === window.RectChangeReason.MOVE) {
          windowClass.stopMoving().then(() => {
            console.info('Succeeded in stopping moving window.')
          }).catch((err: BusinessError) => {
            console.error(`Failed to stop moving. Cause code: ${err.code}, message: ${err.message}`);
          });
        }
      });
    } catch (exception) {
      console.error(`Failed to stop moving window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## setGestureBackEnabled<sup>13+<sup>

setGestureBackEnabled(enabled: boolean): Promise&lt;void&gt;

设置当前窗口是否启用手势侧滑返回功能，仅主窗可以调用成功，其他类型的窗口调用返回1300004错误码。

开启此功能后，仅当窗口处于全屏模式且位于前台获焦状态下才会生效。

禁用此功能后，当前应用会禁用手势热区，侧滑返回功能失效；切换到其他应用或者回到桌面后，手势热区恢复，侧滑返回功能正常。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在2in1、其他设备的电脑模式中调用会返回801错误码，在其他设备和其他模式中可正常调用。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名     | 类型       | 必填     | 说明                                           |
| ---------- | --------- | -------- | --------------------------------------------- |
| enabled    | boolean   | 是       | true时开启返回手势功能，false时禁用返回手势功能。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally.                                                                |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;

      // 设置当前窗口禁用返回手势功能
      try {
        let gestureBackEnabled: boolean = false;
        let promise = windowClass.setGestureBackEnabled(gestureBackEnabled);
        promise.then(() => {
          console.info(`Succeeded in setting gesture back disabled`);
        }).catch((err: BusinessError) => {
          console.error(`Failed to set gesture back disabled, Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch(exception) {
        console.error(`Failed to set gesture back disabled, Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## isGestureBackEnabled<sup>13+<sup>

isGestureBackEnabled(): boolean

获取当前窗口是否启用返回手势功能，仅主窗可以调用成功，其他类型的窗口调用返回1300004错误码。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在2in1、其他设备的电脑模式中调用会返回801错误码，在其他设备和其他模式中可正常调用。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                | 说明                                           |
| ------------------- | --------------------------------------------- |
| boolean             | 是否已经启用返回手势。true表示已启用返回手势功能，false表示已禁用返回手势功能。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;

      // 获取当前窗口是否禁用返回手势功能
      try {
        let gestureBackEnabled: boolean = windowClass.isGestureBackEnabled();
        console.info(`Succeeded in obtaining gesture back enabled status: ${gestureBackEnabled}`);
      } catch (exception) {
        console.error(`Failed to get gesture back enabled status. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setSeparationTouchEnabled<sup>23+</sup>

setSeparationTouchEnabled(enabled: boolean): Promise&lt;void&gt;

设置当前窗口是否支持事件分离状态，使用Promise异步回调。默认场景下为true，支持事件分离状态。

当enable为true，支持事件分离状态下：

- 所有手指点击产生的事件均会发送给其手指命中的窗口。

当enable为false，不支持事件分离状态下：

- 当第一根手指点击持续命中该窗口未抬起时，后续其他手指无论是否点击命中该窗口，其产生的事件均会分发给该窗口。

- 当第一根手指点击未保持持续命中该窗口时，后续其他手指即使点击命中该窗口，其产生的事件也不会分发给该窗口，该事件会被系统丢弃。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型    | 必填 | 说明                 |
| ----------- | ------- | ---- | -------------------- |
| enabled | boolean | 是   | 窗口是否支持事件分离状态。true表示支持；false表示不支持。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801      | Capability not supported. Function can not work because the current device does not support this ability. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally. Possible cause: Internal IPC error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let enabled = false;
try {
  let promise = windowClass.setSeparationTouchEnabled(enabled);
  promise.then(() => {
    console.info('Succeeded in setting the window to be separationTouchEnabled.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to be separationTouchEnabled. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the separationTouchEnabled. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## isSeparationTouchEnabled<sup>23+</sup>

isSeparationTouchEnabled():boolean

获取当前窗口是否支持事件分离的状态。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager


**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| boolean          |  当前窗口是否支持事件分离。</br>true表示支持窗口事件分离，false表示不支持窗口事件分离。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801      | Capability not supported. Function can not work because the current device does not support this ability. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally.        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isSeparationTouchEnabled = windowClass.isSeparationTouchEnabled();
  console.info(`Succeeded in getting the window separationTouchEnabled status: ${isSeparationTouchEnabled}`);
} catch (exception) {
  console.error(`Failed to get the window separationTouchEnabled status.. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setReceiveDragEventEnabled<sup>23+</sup>

setReceiveDragEventEnabled(enabled: boolean): Promise&lt;void&gt;

设置当前窗口是否能接收[拖拽事件](./arkui-ts/ts-universal-events-drag-drop.md)，使用Promise异步回调。

默认场景下为true，能够接收拖拽事件。

当enable为false，当前窗口不能接收拖拽事件。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型    | 必填 | 说明                 |
| ----------- | ------- | ---- | -------------------- |
| enabled | boolean | 是   | 窗口是否能接收拖拽事件。true表示能够接收拖拽事件；false表示不能接收拖拽事件。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801      | Capability not supported. Function can not work because the current device does not support this ability. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally. Possible cause: Internal IPC error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let enabled = false;
try {
  let promise = windowClass.setReceiveDragEventEnabled(enabled);
  promise.then(() => {
    console.info('Succeeded in setting the window to be WindowReceiveDragEventEnabled.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to be the window ReceiveDragEventEnabled. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window ReceiveDragEventEnabled. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## isReceiveDragEventEnabled<sup>23+</sup>

isReceiveDragEventEnabled():boolean

获取当前窗口是否能接收[拖拽事件](./arkui-ts/ts-universal-events-drag-drop.md)的状态。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager


**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| boolean          |  当前窗口是否能接收拖拽事件的状态。</br>true表示能接收拖拽事件的状态，false表示不能接收拖拽事件的状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801      | Capability not supported. Function can not work because the current device does not support this ability. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally.        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isReceiveDragEventEnabled = windowClass.isReceiveDragEventEnabled();
  console.info(`Succeeded in getting the window receiveDragEvent status: ${isReceiveDragEventEnabled}`);
} catch (exception) {
  console.error(`Failed to get the window receiveDragEvent status. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowShadowRadius<sup>17+</sup>

setWindowShadowRadius(radius: number): void

设置子窗或全局悬浮窗窗口边缘阴影的模糊半径。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 

在OpenHarmony 5.1.0之前，该接口在Tablet设备、PC/2in1设备中可正常调用，在其他设备中返回801错误码。

从OpenHarmony 5.1.0开始，该接口在Phone设备、Tablet设备和PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                          |
| ------- | ------ | ---- |-------------------------------------------------------------|
| radius  | number | 是   | 表示窗口边缘阴影的模糊半径。该参数为浮点数，单位为px，取值范围为[0.0, +∞)，取值为0.0时表示关闭窗口边缘阴影。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                               |
|---------|--------------------------------------------------------------------------------------------------------------------|
| 401     | Parameter error. Possible cause: The shadow radius is less than zero.                                              |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.                               |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.  |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only subwindows and float windows are supported.      |

**示例：**

```ts
try {
  windowClass.setWindowShadowRadius(4.0);
} catch (exception) {
  console.error(`Failed to set shadow. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowCornerRadius<sup>17+</sup>

setWindowCornerRadius(cornerRadius: number): Promise&lt;void&gt;

设置子窗或全局悬浮窗的圆角半径值，使用Promise异步回调。

圆角半径值过大将会导致三键（最大化、最小化、关闭按钮）位置被裁切，且会导致热区不易识别，请根据窗口大小设置合适的圆角半径值。

在调用此接口之前调用[getWindowCornerRadius()](#getwindowcornerradius17)接口可以获得窗口默认圆角半径值。

**系统能力**：SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP16-->OpenHarmony 6.0<!--RP16End-->之前，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

从<!--RP16-->OpenHarmony 6.0<!--RP16End-->开始，该接口在Phone设备、Tablet设备和PC/2in1设备下可正常调用，在其他设备中返回801错误码。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                 |
| ----------- | ------- | ---- |----------------------------------------------------|
| cornerRadius | number | 是   | 表示窗口圆角的半径值。该参数为浮点数，单位为vp，取值范围为[0.0, +∞)，取值为0.0时表示没有窗口圆角。 |

**返回值：**

| 类型 | 说明 |
| ---------------------- | ------------------------------------------------------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                              |
|---------|-------------------------------------------------------------------------------------------------------------------|
| 401     | Parameter error. Possible cause: The corner radius is less than zero.                                             |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.                              |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally.                                                                     |
| 1300004 | Unauthorized operation.                                                                                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.setWindowCornerRadius(1.0);
  promise.then(() => {
    console.info('Succeeded in setting window corner radius.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window corner radius. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set corner radius. Cause code: ${exception.code}, message: ${exception.message}`);
}

```

## getWindowCornerRadius<sup>17+</sup>

getWindowCornerRadius(): number

该接口用于获取子窗或全局悬浮窗的圆角半径值，在未调用[setWindowCornerRadius()](#setwindowcornerradius17)接口设置窗口圆角半径值时，调用此接口可获取窗口默认圆角半径值。

**系统能力**：SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在Phone、Tablet、PC/2in1设备中可正常调用，在其他设备中返回801错误码。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型 | 说明 |
| ---------------------- | ------------------------------------------------------------------------------------ |
| number | 当前子窗或全局悬浮窗的圆角半径值，单位为vp。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                              |
|---------|-------------------------------------------------------------------------------------------------------------------|
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.                              |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only subwindows and float windows are supported.     |

**示例：**

```ts
try {
  let cornerRadius = windowClass.getWindowCornerRadius();
} catch (exception) {
  console.error(`Failed to get corner radius. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setExclusivelyHighlighted<sup>15+<sup>

setExclusivelyHighlighted(exclusivelyHighlighted: boolean): Promise&lt;void&gt;

设置窗口独占激活态属性。独占激活态表示窗口获焦时，会导致当前父子窗口链中处于激活态的其他窗口失去激活态。使用Promise异步回调。

此接口对主窗、模态窗不生效。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----------- | ------- | -- | -------------------------------------------------------- |
| exclusivelyHighlighted | boolean | 是 | 窗口是否独占激活态。true表示独占激活态；false表示不独占激活态。  |

**返回值：**

| 类型 | 说明 |
| ---------------------- | ------------------------------------------------------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities.                         |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003  | This window manager service works abnormally.                                                                |
| 1300004  | Unauthorized operation.                                                                                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let exclusivelyHighlighted: boolean = true;
try {
  let promise = windowClass.setExclusivelyHighlighted(exclusivelyHighlighted);
  promise.then(() => {
    console.info('Succeeded in setting the window to be exclusively highlight.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to be exclusively highlight. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window to be exclusively highlight. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## isWindowHighlighted<sup>18+<sup>

isWindowHighlighted(): boolean

获取当前窗口是否为激活态。为准确获取激活态，需要在[WindowEventType](arkts-apis-window-e.md#windoweventtype10)生命周期处于WINDOW_ACTIVE之后调用。

可使用[on('windowHighlightChange')](#onwindowhighlightchange15)监听对应状态变更，再执行对应具体业务。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                | 说明                                           |
| ------------------- | --------------------------------------------- |
| boolean             | 当前窗口是否为激活态。true表示当前窗口为激活态，false表示当前窗口非激活态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities.                         |
| 1300002  | This window state is abnormal  Possible cause: The window is not created or destroyed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isHighlighted = windowClass.isWindowHighlighted();
  console.info(`Succeeded in getting the window highlight status: ${isHighlighted}`);
} catch (exception) {
  console.error(`Failed to get the window highlight status.. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setFollowParentMultiScreenPolicy<sup>17+<sup>

setFollowParentMultiScreenPolicy(enabled: boolean): Promise&lt;void&gt;

设置子窗口在其父窗口处于拖拽移动或拖拽缩放过程时，该子窗口是否支持跨多个屏幕同时显示。使用Promise异步回调。

通过监听父窗口大小位置变化，对子窗口调用[moveWindowTo()](#movewindowto9)等接口实现子窗口跟随父窗口布局时，此时子窗口默认不支持跨多个屏幕同时显示。

对子窗口调用此接口后可以使能子窗口在跟随父窗口布局过程中跨多个屏幕同时显示。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 

在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在Phone、Tablet、PC/2in1设备可正常调用，在其他设备调用返回801错误码。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----------- | ------- | -- | -------------------------------------------------------- |
| enabled | boolean | 是 | 设置子窗口在其父窗口处于拖拽移动或拖拽缩放过程时，该子窗口是否支持跨多个屏幕同时显示。true表示支持；false表示不支持。  |

**返回值：**

| 类型 | 说明 |
| ---------------------- | ------------------------------------------------------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported.Function setFollowParentMultiScreenPolicy can not work correctly due to limited device capabilities.|
| 1300002  | This window state is abnormal.                                                                               |
| 1300003  | This window manager service works abnormally.                                                                |
| 1300004  | Unauthorized operation.                                                                                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowClass: window.Window = window.findWindow("subWindow");
  let enabled: boolean = true;
  let promise = windowClass?.setFollowParentMultiScreenPolicy(enabled);
  promise.then(() => {
    console.info('Succeeded in setting the sub window supports multi-screen simultaneous display')
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the sub window supports multi-screen simultaneous display. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the sub window supports multi-screen simultaneous display. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setFollowParentWindowLayoutEnabled<sup>17+</sup>

setFollowParentWindowLayoutEnabled(enabled: boolean): Promise&lt;void&gt;

设置子窗或模态窗口（即WindowType为TYPE_DIALOG的窗口）的布局信息（position和size）是否跟随主窗，使用Promise异步回调。

1、只支持主窗的一级子窗或模态窗口使用该接口。其中非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用此接口时，将返回1300004错误码。

2、当子窗或模态窗口调用该接口后，立即使其布局信息与主窗完全一致并保持，除非传入false再次调用该接口，否则效果将持续。

3、当子窗或模态窗口调用该接口后，再调用moveTo、resize等修改布局信息的接口将不生效。

4、当子窗或模态窗口不再使用该功能后，不保证子窗或模态窗口的布局信息（position和size）为确定的值，需要应用重新进行设置。

该接口调用生效后，[setRelativePositionToParentWindowEnabled()](#setrelativepositiontoparentwindowenabled20)接口调用不生效。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型  | 必填  | 说明  |
| --- | --- | --- | --- |
| enabled | boolean | 是   | 设置是否启用跟随主窗布局。true表示启用，false表示不启用。|

**返回值：**

| 类型  | 说明  |
| --- | --- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| --- | --- |
| 401 | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error. 3. The subwindow level is more than one. 4. The subwindow is following its parent window's position.|
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only subwindows and dialog windows are supported. |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (loadError) => {
      if (loadError.code) {
        console.error(`Failed to load the content. Cause code: ${loadError.code}, message: ${loadError.message}`);
        return;
      }
      console.info("Succeeded in loading the content.");
      windowStage.createSubWindow("subWindow").then((subWindow: window.Window) => {
        if (subWindow == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        subWindow.setFollowParentWindowLayoutEnabled(true).then(() => {
          console.info("after set follow parent window layout")
        }).catch((error: BusinessError) => {
          console.error(`setFollowParentWindowLayoutEnabled failed. ${error.code} ${error.message}`);
        })
      }).catch((error: BusinessError) => {
        console.error(`createSubWindow failed. ${error.code} ${error.message}`);
      })
    });
  }
}
```

## setRelativePositionToParentWindowEnabled<sup>20+<sup>

setRelativePositionToParentWindowEnabled(enabled: boolean, anchor?: WindowAnchor, offsetX?: number, offsetY?: number): Promise&lt;void&gt;

用于设置一级子窗是否支持与主窗保持相对位置不变。使用Promise异步回调。

该相对位置通过一级子窗与主窗之间锚点的偏移量表示，子窗和主窗使用的窗口锚点相同。

1. 只支持一级子窗调用该接口，子窗需处于自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）。

2. 当子窗调用该接口后，立即使其显示位置跟随主窗并保持相对位置不变，除非传入false再次调用该接口，否则效果将持续。

3. 当子窗调用该接口后，再调用[moveWindowTo()](#movewindowto9)、[maximize()](#maximize12)修改窗口位置或大小的接口将不生效。

该接口调用生效后，[setFollowParentWindowLayoutEnabled()](#setfollowparentwindowlayoutenabled17)接口调用不生效。

[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用此接口时，将返回1300004错误码。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP1-->OpenHarmony 6.1<!--RP1End-->之前，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备（Phone设备除外，在Phone设备上调用该接口会返回801错误码）上可正常调用；在支持并不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不报错不生效；在不支持自由窗口的设备中返回801错误码。

从<!--RP1-->OpenHarmony 6.1<!--RP1End-->开始，该接口在Phone、Tablet、2in1设备上可调用且不报错（当设备处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态时可正常调用此接口并生效；当设备不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态时调用此接口不生效不报错，设备切换到自由窗口状态时生效）；在其他设备中调用返回801错误码。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----------- | ------- | -- | -------------------------------------------------------- |
| enabled | boolean | 是 | 一级子窗是否支持与主窗保持相对位置不变。true表示支持；false表示不支持。  |
| anchor | [WindowAnchor](arkts-apis-window-e.md#windowanchor20) | 否 | 一级子窗与主窗保持相对位置不变时的窗口锚点枚举。该参数仅在enabled为true时生效，默认值为window.WindowAnchor.TopStart，即默认锚点为窗口左上角。  |
| offsetX | number | 否 | 一级子窗锚点与主窗锚点位置的x轴偏移量，单位为px。该参数仅在enabled为true时生效，仅支持整数输入，浮点数向下取整，默认值为0。  |
| offsetY | number | 否 | 一级子窗锚点与主窗锚点位置的y轴偏移量，单位为px。该参数仅在enabled为true时生效，仅支持整数输入，浮点数向下取整，默认值为0。  |

**返回值：**

| 类型 | 说明 |
| ---------------------- | ------------------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 801      | Capability not supported.Function setRelativePositionToParentWindowEnabled can not work correctly due to limited device capabilities.|
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.                    |
| 1300003  | This window manager service works abnormally.                                                                |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only subwindows are supported.                                            |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (loadError: BusinessError) => {
      if (loadError.code) {
        console.error(`Failed to load the content. Cause code: ${loadError.code}, message: ${loadError.message}`);
        return;
      }
      console.info("Succeeded in loading the content.");
      windowStage.createSubWindow("subWindow").then((subWindow: window.Window) => {
        if (subWindow == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        subWindow.setRelativePositionToParentWindowEnabled(true).then(() => {
          console.info("after set relative position to parent window enabled");
        }).catch((error: BusinessError) => {
          console.error(`setRelativePositionToParentWindowEnabled failed. ${error.code} ${error.message}`);
        })
      }).catch((error: BusinessError) => {
        console.error(`createSubWindow failed. ${error.code} ${error.message}`);
      })
    });
  }
}
```

## setWindowTransitionAnimation<sup>20+</sup>

setWindowTransitionAnimation(transitionType: WindowTransitionType, animation: TransitionAnimation): Promise&lt;void&gt;

给特定场景下的窗口增加转场动画。

当前只支持在应用主窗下使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用，在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名         | 类型                                            | 必填 | 说明                                   |
| -------------- | ----------------------------------------------- | ---- | -------------------------------------- |
| transitionType | [WindowTransitionType](arkts-apis-window-e.md#windowtransitiontype20) | 是   | 本次转场动画场景。当前只支持销毁场景。 |
| animation      | [TransitionAnimation](arkts-apis-window-i.md#transitionanimation20)   | 是   | 本次转场动画配置。                     |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                              |
|---------|-------------------------------------------------------------------------------------------------------------------|
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.                              |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally.                                                                     |
| 1300004 | Unauthorized operation.                                                                                           |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range; 2. Invalid parameter length.                         |

**示例：**

```typescript
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        const animationConfig: window.WindowAnimationConfig = {
          duration: 1000,
          curve: window.WindowAnimationCurve.LINEAR,
        };
        const transitionAnimation: window.TransitionAnimation = {
          opacity: 0.5,
          config: animationConfig
        };
        let promise = windowClass.setWindowTransitionAnimation(window.WindowTransitionType.DESTROY, transitionAnimation);
        promise.then((data) => {
          console.info('Succeeded in setting window transition animation. Cause:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
          console.error(`Failed to set window transition animation. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to obtain the window status of window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    })
  }
}
```

## getWindowTransitionAnimation<sup>20+</sup>

getWindowTransitionAnimation(transitionType: WindowTransitionType): TransitionAnimation | undefined

获取特定场景下的窗口转场动画配置。

当前只支持在应用主窗下使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用，在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名         | 类型                                            | 必填 | 说明                                   |
| -------------- | ----------------------------------------------- | ---- | -------------------------------------- |
| transitionType | [WindowTransitionType](arkts-apis-window-e.md#windowtransitiontype20) | 是   | 本次转场动画场景。当前只支持销毁场景。 |

**返回值：**

| 类型                                          | 说明                       |
| --------------------------------------------- | -------------------------- |
| [TransitionAnimation](arkts-apis-window-i.md#transitionanimation20) \| undefined | 对应场景下的转场动画配置。当未使用过[setWindowTransitionAnimation](#setwindowtransitionanimation20)接口时，返回undefined。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID   | 错误信息                                                                                                                |
|---------|---------------------------------------------------------------------------------------------------------------------|
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.                                |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.   |
| 1300003 | This window manager service works abnormally.                                                                       |
| 1300004 | Unauthorized operation.                                                                                             |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range.                                                        |

**示例：**

```typescript
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let transitionAnimationResult = windowClass.getWindowTransitionAnimation(window.WindowTransitionType.DESTROY);
        console.info('Succeeded in getting window transition animation: ' + JSON.stringify(transitionAnimationResult));
      } catch (exception) {
        console.error(`Failed to obtain the window transition animation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    })
  }
}
```

## setSubWindowZLevel<sup>18+</sup>

setSubWindowZLevel(zLevel: number): Promise&lt;void&gt;

设置当前子窗口层级级别，设置了模态属性的子窗不支持。使用Promise异步回调。

通过该接口改变子窗口的显示层级时，不会发生焦点切换。推荐使用[shiftAppWindowFocus()](arkts-apis-window-f.md#windowshiftappwindowfocus11)进行焦点切换。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用该接口不生效也不报错。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**设备行为差异：** 该接口在Phone、Tablet、PC/2in1设备可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名       | 类型                          | 必填 | 说明                           |
| :----------- | :---------------------------- | :--- | :----------------------------- |
| zLevel | number | 是   | 子窗口层级级别。默认值为0，取值范围为[-10000, 10000]，该参数仅支持整数输入，浮点数输入将向下取整。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| ------- | --------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801     | Capability not supported. Function setSubWindowZLevel can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only non-modal subwindows are supported. |
| 1300009 | The parent window is invalid.                 |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let zLevel: number = 1;
    // 创建子窗
    try {
      windowStage.createSubWindow('testSubWindow').then((subWindow) => {
        if (subWindow == null) {
          console.error('Failed to create the sub window. Cause: The sub window is null');
          return;
        }
        subWindow.setSubWindowZLevel(zLevel).then(() => {
          console.info('Succeeded in setting sub window zLevel.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set sub window zLevel. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (err) {
      console.error(`Failed to create the sub window or set zLevel. Cause code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

## getSubWindowZLevel<sup>18+</sup>

getSubWindowZLevel(): number

获取当前子窗口层级级别。不支持主窗、系统窗调用。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用该接口不生效也不报错，返回默认值0。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**设备行为差异：** 该接口在Phone、Tablet、PC/2in1设备可正常调用，在其他设备中返回801错误码。

**返回值：**

| 类型                | 说明                                           |
| ------------------- | --------------------------------------------- |
| number             | 当前子窗口层级级别。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 801      | Capability not supported. Function getSubWindowZLevel can not work correctly due to limited device capabilities. |
| 1300002  | This window state is abnormal.                                                                               |
| 1300004  | Unauthorized operation.                                                                                |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let subWindowZLevel = -1;
    // 创建子窗
    windowStage.createSubWindow('testSubWindow').then((subWindow) => {
      if (subWindow == null) {
        console.error('Failed to create the sub window. Cause: The sub window is null');
        return;
      }
      try {
        subWindowZLevel = subWindow.getSubWindowZLevel();
        console.info(`Succeeded in obtaining sub window zLevel: ${subWindowZLevel}`);
      } catch (err) {
        console.error(`Failed to obtain the sub window zLevel. Cause code: ${err.code}, message: ${err.message}`);
      }
    });
  }
}
```

## isInFreeWindowMode<sup>22+</sup>

isInFreeWindowMode(): boolean

查询当前窗口是否为[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)模式。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| boolean | 返回true表示在自由窗口模式，false表示非自由窗口模式。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002  | This window state is abnormal.                       |
| 1300003  | This window manager service works abnormally.        |

**示例：**

```ts
let isInFreeWindowMode: boolean = windowClass.isInFreeWindowMode();
console.info(`isInFreeWindowMode: ${isInFreeWindowMode}`);
```

## on('freeWindowModeChange')<sup>22+</sup>

on(type: 'freeWindowModeChange', callback: Callback&lt;boolean&gt;): void

开启自由窗口模式变化事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'freeWindowModeChange'，即自由窗口模式变化事件。 |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。返回当前窗口是否在自由窗口模式，true表示是自由窗口模式，false表示非自由窗口模式。                           |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002  | This window state is abnormal.                       |
| 1300003  | This window manager service works abnormally.        |

**示例：**

```ts
try {
  windowClass.on('freeWindowModeChange', (data) => {
    console.info('Succeeded in enabling the listener for free window mode changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for free window mode changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## off('freeWindowModeChange')<sup>22+</sup>

off(type: 'freeWindowModeChange', callback?: Callback&lt;boolean&gt;): void

关闭自由窗口模式变化事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                     |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | 是   | 监听事件，固定为'freeWindowModeChange'，即自由窗口模式变化事件。 |
| callback | Callback&lt;boolean&gt; | 否   | 回调函数。返回当前窗口是否在自由窗口模式。如果传入参数，则关闭该监听。如果未传入参数，则关闭自由窗口模式变化事件的监听。                           |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1300002  | This window state is abnormal.                       |
| 1300003  | This window manager service works abnormally.        |

**示例：**

```ts
const callback = (isInFreeWindowMode: boolean) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('freeWindowModeChange', callback);
  // 关闭指定callback的监听
  windowClass.off('freeWindowModeChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听
  windowClass.off('freeWindowModeChange');
} catch (exception) {
  console.error(`Failed to disable the listener for free window mode change. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## convertOrientationAndRotation<sup>23+</sup>

convertOrientationAndRotation(from: RotationInfoType, to: RotationInfoType, value: number): number

提供窗口方向、屏幕方向和屏幕角度互相转换的能力。

窗口方向指窗口所在屏幕的方向，以窗口模块对横竖屏的定义方式表示，窗口的方向分别用0、1、2和3表示竖屏、反向横屏、反向竖屏和横屏四个方向，其对横竖屏的定义与[RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19)和枚举类[Orientation](arkts-apis-window-e.md#orientation9)中对横竖屏的定义一致，如Orientation设置为LANDSCAPE时，窗口方向为横屏。

> **说明：**
>
> 示意图和表格展示了直板机窗口方向、屏幕方向和屏幕角度的关系。
>
>  ![orientationAndRotation](figures/orientationAndRotation.PNG)
>
  | 屏幕角度 | 屏幕方向 | 窗口方向 |
  | -------  | ------- | ------- |
  | 0        | PORTRAIT  | PORTRAIT   |
  | 90       | LANDSCAPE | LANDSCAPE_INVERTED |
  | 180      | PORTRAIT_INVERTED | PORTRAIT_INVERTED |
  | 270      | LANDSCAPE_INVERTED | LANDSCAPE |

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone和Tablet设备可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                    |
| -------- | ----------------------------- | ---- | ------------------------------------------------------ |
| from     | [RotationInfoType](arkts-apis-window-e.md#rotationinfotype23)  | 是   | 待转换的值的类型。 |
| to       | [RotationInfoType](arkts-apis-window-e.md#rotationinfotype23)  | 是   | 目标值的类型。 |
| value    | number               | 是   | 待转换的值。该参数为整数，浮点数输入将向下取整，取值范围为[0, 3]，范围外为非法参数（抛出错误码[401](../errorcode-universal.md#401-参数检查失败)）。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| number | 返回目标类型的转换值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.    |
| 1300003  | This window manager service works abnormally.        |

**示例：**

```ts
try {
  let originalValue: number = 0;
  let fromType: window.RotationInfoType = window.RotationInfoType.WINDOW_ORIENTATION;
  let toType: window.RotationInfoType = window.RotationInfoType.DISPLAY_ORIENTATION;
  let convertedValue: number = windowClass.convertOrientationAndRotation(fromType, toType, originalValue);
  console.info(`Convert ${originalValue} of type: ${fromType} to ${convertedValue} of type: ${toType}`);
} catch (exception) {
  console.error(`Failed to convert orientation and rotation between window and display. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## setWindowSystemBarProperties<sup>(deprecated)</sup>

setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

设置主窗口<!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性，使用callback异步回调，<!--RP5-->该接口在PC/2in1设备上调用不生效。<!--RP5End-->

子窗口调用后不生效。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃，建议使用[setWindowSystemBarProperties()](#setwindowsystembarproperties9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| systemBarProperties | [SystemBarProperties](arkts-apis-window-i.md#systembarproperties) | 是   | <!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性。 |
| callback            | AsyncCallback&lt;void&gt;                   | 是   | 回调函数。             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities.                         |
| 1300002  | This window state is abnormal.                                                                               |
| 1300003  | This window manager service works abnormally.                                                                |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let SystemBarProperties: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // 以下两个属性从API Version8开始支持
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#00ffff'
      };
      try {
        windowClass.setWindowSystemBarProperties(SystemBarProperties, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the system bar properties.');
        });
      } catch (exception) {
        console.error(`Failed to set the system bar properties. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setWindowSystemBarEnable<sup>(deprecated)</sup>

setWindowSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

<!--RP14-->设置主窗口状态栏、三键导航栏的可见模式，状态栏通过status控制、三键导航栏通过navigation控制<!--RP14End-->，使用callback异步回调。<br>从API version 12开始，<!--RP5-->该接口在PC/2in1设备上调用不生效。<!--RP5End-->

调用生效后返回并不表示状态栏、<!--RP15-->三键导航栏<!--RP15End-->的显示或隐藏已完成。子窗口调用后不生效。非全屏模式（自由悬浮窗口模式、分屏等场景）下配置不生效。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃，建议使用[setWindowSystemBarEnable()](#setwindowsystembarenable9)替代。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                                                                                                          |
| -------- | ----------------------------- | ---- | --------------------------------------------------------------------------------------------------------------------------------------------- |
| names    | Array<'status'\|'navigation'> | 是   | 设置窗口全屏模式时状态栏和<!--RP15-->三键导航栏<!--RP15End-->是否显示。<br>例如，需全部显示，该参数设置为['status',&nbsp;'navigation']；设置为[]，则不显示。 |
| callback | AsyncCallback&lt;void&gt;     | 是   | 回调函数。                                                                                                                                    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal.                                                                               |
| 1300003  | This window manager service works abnormally.                                                                |

**示例：**

```ts
// 此处以状态栏等均不显示为例
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let names: Array<'status' | 'navigation'> = [];
      try {
        windowClass.setWindowSystemBarEnable(names, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the system bar to be invisible.');
        });
      } catch (exception) {
        console.error(`Failed to set the system bar to be invisible. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## setWindowLayoutFullScreen<sup>(deprecated)</sup>

setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置主窗口或子窗口的布局是否为[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)，使用callback异步回调。系统窗口调用不生效。

沉浸式布局生效时，布局不避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件可能产生与其重叠的情况。

非沉浸式布局生效时，布局避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件不会与其重叠。

> **说明：**
>
> 从API version 9开始支持，从API version 12开始废弃，建议使用[setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**设备行为差异：**

在OpenHarmony 5.0.2之前，该接口在所有设备中可正常调用。

从OpenHarmony 5.0.2开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用不生效也不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用。

**参数：**

| 参数名             | 类型                      | 必填 | 说明                                                                                                          |
| ------------------ | ------------------------- | ---- | ------------------------------------------------------------------------------------------------------------- |
| isLayoutFullScreen | boolean                   | 是   | 窗口的布局是否为沉浸式布局（该沉浸式布局状态栏、<!--RP15-->三键导航栏<!--RP15End-->仍然显示）。true表示沉浸式布局；false表示非沉浸式布局。 |
| callback           | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                                                                    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                                                                                     |
| -------- | ------------------------------------------------------------------------------------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal. Possible cause: The window is not created or destroyed.                                                                               |
| 1300003  | This window manager service works abnormally.                                                                |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isLayoutFullScreen = true;
      try {
        windowClass.setWindowLayoutFullScreen(isLayoutFullScreen, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the window layout to full-screen mode.');
        });
      } catch (exception) {
        console.error(`Failed to set the window layout to full-screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## show<sup>(deprecated)</sup>

show(callback: AsyncCallback&lt;void&gt;): void

显示当前窗口，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[showWindow()](#showwindow9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.show((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to show the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in showing the window.');
});
```

## show<sup>(deprecated)</sup>

show(): Promise&lt;void&gt;

显示当前窗口，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[showWindow()](#showwindow9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.show();
promise.then(() => {
  console.info('Succeeded in showing the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## destroy<sup>(deprecated)</sup>

destroy(callback: AsyncCallback&lt;void&gt;): void

销毁当前窗口，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[destroyWindow()](#destroywindow9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.destroy((err: BusinessError) => {
  const errCode: number = err.code;
  if (err.code) {
    console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in destroying the window.');
});
```

## destroy<sup>(deprecated)</sup>

destroy(): Promise&lt;void&gt;

销毁当前窗口，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[destroyWindow()](#destroywindow9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.destroy();
promise.then(() => {
  console.info('Succeeded in destroying the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## moveTo<sup>(deprecated)</sup>

moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

移动窗口位置，使用callback异步回调。

全屏模式窗口不支持该操作。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[moveWindowTo()](#movewindowto9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                              |
| -------- | ------------------------- | ---- | ------------------------------------------------- |
| x        | number                    | 是   | 窗口在x轴方向移动到的坐标位置，单位为px，值为正表示位置在x轴右侧；值为负表示位置在x轴左侧；值为0表示位置在x轴坐标原点。该参数仅支持整数输入，浮点数输入将向下取整。 |
| y        | number                    | 是   | 窗口在y轴方向移动到的坐标位置，单位为px，值为正表示位置在y轴下侧；值为负表示位置在y轴上侧；值为0表示位置在x轴坐标原点。该参数仅支持整数输入，浮点数输入将向下取整。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.moveTo(300, 300, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in moving the window.');
});
```

## moveTo<sup>(deprecated)</sup>

moveTo(x: number, y: number): Promise&lt;void&gt;

移动窗口位置，使用Promise异步回调。

全屏模式窗口不支持该操作。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[moveWindowTo()](#movewindowto9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                              |
| ------ | ------ | ---- | ------------------------------------------------- |
| x      | number | 是   | 窗口在x轴方向移动到的坐标位置，单位为px，值为正表示位置在x轴右侧；值为负表示位置在x轴左侧；值为0表示位置在x轴坐标原点。该参数仅支持整数输入，浮点数输入将向下取整。 |
| y      | number | 是   | 窗口在y轴方向移动到的坐标位置，单位为px，值为正表示位置在y轴下侧；值为负表示位置在y轴上侧；值为0表示位置在y轴坐标原点。该参数仅支持整数输入，浮点数输入将向下取整。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.moveTo(300, 300);
promise.then(() => {
  console.info('Succeeded in moving the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

## resetSize<sup>(deprecated)</sup>

resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

基于窗口左上角顶点改变当前窗口大小，使用callback异步回调。

应用主窗口与子窗口存在大小限制，默认宽度范围：[320, 1920]，默认高度范围：[240, 1920]，单位为vp。

应用主窗口与子窗口的最小宽度与最小高度可由产品端进行配置，配置后的最小宽度与最小高度以产品段配置值为准，具体尺寸限制范围可以通过[getWindowLimits](#getwindowlimits11)接口进行查询。

系统窗口存在大小限制，宽度范围：(0, 1920]，高度范围：(0, 1920]，单位为vp。

设置的宽度与高度受到此限制约束，规则：

若所设置的窗口宽/高尺寸小于窗口最小宽/高限制值，则窗口最小宽/高限制值生效；

若所设置的窗口宽/高尺寸大于窗口最大宽/高限制值，则窗口最大宽/高限制值生效。

全屏模式窗口不支持该操作。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[resize()](#resize9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                       |
| -------- | ------------------------- | ---- | -------------------------- |
| width    | number                    | 是   | 当前窗口的目标宽度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码[401](../errorcode-universal.md#401-参数检查失败)）。 |
| height   | number                    | 是   | 当前窗口的目标高度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码[401](../errorcode-universal.md#401-参数检查失败)）。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.resetSize(500, 1000, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in changing the window size.');
});
```

## resetSize<sup>(deprecated)</sup>

resetSize(width: number, height: number): Promise&lt;void&gt;

基于窗口左上角顶点改变当前窗口大小，使用Promise异步回调。

应用主窗口与子窗口存在大小限制，默认宽度范围：[320, 1920]，默认高度范围：[240, 1920]，单位为vp。

应用主窗口与子窗口的最小宽度与最小高度可由产品端进行配置，配置后的最小宽度与最小高度以产品段配置值为准，具体尺寸限制范围可以通过[getWindowLimits](#getwindowlimits11)接口进行查询。

系统窗口存在大小限制，宽度范围：(0, 1920]，高度范围：(0, 1920]，单位为vp。

设置的宽度与高度受到此限制约束，规则：

若所设置的窗口宽/高尺寸小于窗口最小宽/高限制值，则窗口最小宽/高限制值生效；

若所设置的窗口宽/高尺寸大于窗口最大宽/高限制值，则窗口最大宽/高限制值生效。

全屏模式窗口不支持该操作。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[resize()](#resize9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| width  | number | 是   | 当前窗口的目标宽度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码[401](../errorcode-universal.md#401-参数检查失败)）。 |
| height | number | 是   | 当前窗口的目标高度，单位为px，该参数仅支持整数输入，浮点数输入将向下取整，负值为非法参数（抛出错误码[401](../errorcode-universal.md#401-参数检查失败)）。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.resetSize(500, 1000);
promise.then(() => {
  console.info('Succeeded in changing the window size.');
}).catch((err: BusinessError) => {
  console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
});
```

## getProperties<sup>(deprecated)</sup>

getProperties(callback: AsyncCallback&lt;WindowProperties&gt;): void

获取当前窗口的属性，使用callback异步回调，返回WindowProperties。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getWindowProperties()](#getwindowproperties9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                         |
| -------- | ---------------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;[WindowProperties](arkts-apis-window-i.md#windowproperties)&gt; | 是   | 回调函数。返回当前窗口属性。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.getProperties((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain the window properties. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
});
```

## getProperties<sup>(deprecated)</sup>

getProperties(): Promise&lt;WindowProperties&gt;

获取当前窗口的属性，使用Promise异步回调，返回WindowProperties。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[getWindowProperties()](#getwindowproperties9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                                 | 说明                            |
| ---------------------------------------------------- | ------------------------------- |
| Promise&lt;[WindowProperties](arkts-apis-window-i.md#windowproperties)&gt; | Promise对象。返回当前窗口属性。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.getProperties();
promise.then((data) => {
  console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the window properties. Cause code: ${err.code}, message: ${err.message}`);
});
```

## getAvoidArea<sup>(deprecated)</sup>

getAvoidArea(type: AvoidAreaType, callback: AsyncCallback&lt;AvoidArea&gt;): void

获取当前窗口内容规避的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与窗口内容重叠时，需要窗口内容避让的区域。

全局悬浮窗、模态窗或系统窗口：
- 仅在调用[setSystemAvoidAreaEnabled](#setsystemavoidareaenabled18)方法使能后，才能通过此接口获取避让区域。

> **说明：**
>
> - TV 设备不显示状态栏。若未显式设置状态栏隐藏，调用该接口仍可获取状态栏对应的避让区域。
> - 从API version 7开始支持，从API version 9开始废弃，建议使用[getWindowAvoidArea()](#getwindowavoidarea9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                         |
| -------- |-----------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)              | 是   | 表示避让区类型。|
| callback | AsyncCallback&lt;[AvoidArea](arkts-apis-window-i.md#avoidarea7)&gt; | 是   | 回调函数。返回窗口内容避让区域。当获取到的避让区域值全为0，表示避让区域为空。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let type = window.AvoidAreaType.TYPE_SYSTEM;
windowClass.getAvoidArea(type, (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain the area. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
});
```

## getAvoidArea<sup>(deprecated)</sup>

getAvoidArea(type: AvoidAreaType): Promise&lt;AvoidArea&gt;

获取当前窗口内容规避的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与窗口内容重叠时，需要窗口内容避让的区域。

全局悬浮窗、模态窗或系统窗口：
- 仅在调用[setSystemAvoidAreaEnabled](#setsystemavoidareaenabled18)方法使能后，才能通过此接口获取避让区域。

> **说明：**
>
> - TV设备不显示状态栏。若未显式设置状态栏隐藏，调用该接口仍可获取状态栏对应的避让区域。
> - 从API version 7开始支持，从API version 9开始废弃，建议使用[getWindowAvoidArea()](#getwindowavoidarea9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                               | 必填 | 说明                                                         |
| ------ |----------------------------------| ---- | ------------------------------------------------------------ |
| type   | [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | 是   | 表示避让区类型。 |

**返回值：**

| 类型                                      | 说明                                |
|-----------------------------------------| ----------------------------------- |
| Promise&lt;[AvoidArea](arkts-apis-window-i.md#avoidarea7)&gt; | Promise对象。返回窗口内容避让区域。当获取到的避让区域值全为0，表示避让区域为空。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let type = window.AvoidAreaType.TYPE_SYSTEM;
let promise = windowClass.getAvoidArea(type);
promise.then((data) => {
  console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the area. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setFullScreen<sup>(deprecated)</sup>

setFullScreen(isFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置主窗口或子窗口的布局是否为全屏布局，使用callback异步回调。

全屏布局生效时，布局不避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件可能产生与其重叠的情况。

非全屏布局生效时，布局避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件不会与其重叠。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowSystemBarEnable()](#setwindowsystembarenable9)和[setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                                           |
| ------------ | ------------------------- | ---- | ---------------------------------------------- |
| isFullScreen | boolean                   | 是   | 是否设为全屏布局（该全屏布局影响状态栏、<!--RP15-->三键导航栏<!--RP15End-->显示）。true表示全屏；false表示非全屏。 |
| callback     | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                     |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isFullScreen: boolean = true;
      windowClass.setFullScreen(isFullScreen, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to enable the full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in enabling the full-screen mode.');
      });
    });
  }
}
```

## setFullScreen<sup>(deprecated)</sup>

setFullScreen(isFullScreen: boolean): Promise&lt;void&gt;

设置主窗口或子窗口的布局是否为全屏布局，使用Promise异步回调。

全屏布局生效时，布局不避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件可能产生与其重叠的情况。

非全屏布局生效时，布局避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件不会与其重叠。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowSystemBarEnable()](#setwindowsystembarenable9)和[setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型    | 必填 | 说明                                           |
| ------------ | ------- | ---- | ---------------------------------------------- |
| isFullScreen | boolean | 是   | 是否设为全屏布局（该全屏布局影响状态栏、<!--RP15-->三键导航栏<!--RP15End-->显示）。true表示全屏；false表示非全屏。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isFullScreen: boolean = true;
      let promise = windowClass.setFullScreen(isFullScreen);
      promise.then(() => {
        console.info('Succeeded in enabling the full-screen mode.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to enable the full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

## setLayoutFullScreen<sup>(deprecated)</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置主窗口或子窗口的布局是否为[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)，使用callback异步回调。

沉浸式布局生效时，布局不避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件可能产生与其重叠的情况。

非沉浸式布局生效时，布局避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件不会与其重叠。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名             | 类型                      | 必填 | 说明                                                         |
| ------------------ | ------------------------- | ---- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean                   | 是   | 窗口的布局是否为沉浸式布局（该沉浸式布局不影响状态栏、<!--RP15-->三键导航栏<!--RP15End-->显示）。true表示沉浸式布局；false表示非沉浸式布局。 |
| callback           | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isLayoutFullScreen: boolean = true;
      windowClass.setLayoutFullScreen(isLayoutFullScreen, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in setting the window layout to full-screen mode.');
      });
    });
  }
}
```

## setLayoutFullScreen<sup>(deprecated)</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

设置主窗口或子窗口的布局是否为[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)，使用Promise异步回调。

沉浸式布局生效时，布局不避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件可能产生与其重叠的情况。

非沉浸式布局生效时，布局避让状态栏与<!--RP15-->三键导航栏<!--RP15End-->，组件不会与其重叠。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名             | 类型    | 必填 | 说明                                                         |
| ------------------ | ------- | ---- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean | 是   | 窗口的布局是否为沉浸式布局（该沉浸式布局不影响状态栏、<!--RP15-->三键导航栏<!--RP15End-->显示）。true表示沉浸式布局；false表示非沉浸式布局。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isLayoutFullScreen: boolean = true;
      let promise = windowClass.setLayoutFullScreen(isLayoutFullScreen);
      promise.then(() => {
        console.info('Succeeded in setting the window layout to full-screen mode.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

## setSystemBarEnable<sup>(deprecated)</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

<!--RP14-->设置主窗口状态栏、三键导航栏的可见模式，状态栏通过status控制、三键导航栏通过navigation控制<!--RP14End-->，使用callback异步回调。<br>从API version 12开始，<!--RP5-->该接口在PC/2in1设备上调用不生效。<!--RP5End-->

调用生效后返回并不表示状态栏、<!--RP15-->三键导航栏<!--RP15End-->的显示或隐藏已完成。子窗口调用后不生效。非全屏模式（自由悬浮窗口模式、分屏等场景）下配置不生效。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowSystemBarEnable()](#setwindowsystembarenable9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| names    | Array<'status'\|'navigation'> | 是   | 设置窗口全屏模式时状态栏和<!--RP15-->三键导航栏<!--RP15End-->是否显示。<br>例如，需全部显示，该参数设置为['status',&nbsp;'navigation']；设置为[]，则不显示。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |


**示例：**

```ts
// 此处以状态栏等均不显示为例
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let names: Array<'status' | 'navigation'> = [];
      windowClass.setSystemBarEnable(names, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in setting the system bar to be invisible.');
      });
    });
  }
}
```

## setSystemBarEnable<sup>(deprecated)</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

<!--RP14-->设置主窗口状态栏、三键导航栏的可见模式，状态栏通过status控制、三键导航栏通过navigation控制<!--RP14End-->，使用Promise异步回调。<br>从API version 12开始，<!--RP5-->该接口在PC/2in1设备上调用不生效。<!--RP5End-->

调用生效后返回并不表示状态栏、<!--RP15-->三键导航栏<!--RP15End-->的显示或隐藏已完成。子窗口调用后不生效。非全屏模式（自由悬浮窗口模式、分屏等场景）下配置不生效。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowSystemBarEnable()](#setwindowsystembarenable9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型  | 必填 | 说明                                                         |
| ------ | ---------------------------- | ---- | ------------------------ |
| names  | Array<'status'\|'navigation'> | 是   | 设置窗口全屏模式时状态栏和<!--RP15-->三键导航栏<!--RP15End-->是否显示。<br>例如，需全部显示，该参数设置为['status',&nbsp;'navigation']；设置为[]，则不显示。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**示例：**

```ts
// 此处以状态栏等均不显示为例
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let names: Array<'status' | 'navigation'> = [];
      let promise = windowClass.setSystemBarEnable(names);
      promise.then(() => {
        console.info('Succeeded in setting the system bar to be invisible.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

## setSystemBarProperties<sup>(deprecated)</sup>

setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

设置主窗口<!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性，使用callback异步回调，<!--RP5-->该接口在PC/2in1设备上调用不生效。<!--RP5End-->

子窗口调用后不生效。非全屏模式（自由悬浮窗口模式、分屏等场景）下配置不生效。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowSystemBarProperties()](#setwindowsystembarproperties9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| systemBarProperties | [SystemBarProperties](arkts-apis-window-i.md#systembarproperties) | 是   | <!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性。 |
| callback            | AsyncCallback&lt;void&gt;                   | 是   | 回调函数。             |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let SystemBarProperties: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // 以下两个属性从API Version8开始支持
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#00ffff'
      };
      windowClass.setSystemBarProperties(SystemBarProperties, (err) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in setting the system bar properties.');
      });
    });
  }
}
```

## setSystemBarProperties<sup>(deprecated)</sup>

setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

设置主窗口<!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性，使用Promise异步回调，<!--RP5-->该接口在PC/2in1设备上调用不生效。<!--RP5End-->

子窗口调用后不生效。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowSystemBarProperties()](#setwindowsystembarproperties9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| systemBarProperties | [SystemBarProperties](arkts-apis-window-i.md#systembarproperties) | 是   | <!--Del-->三键导航栏、<!--DelEnd-->状态栏的属性。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let SystemBarProperties: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // 以下两个属性从API Version8开始支持
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#00ffff'
      };
      let promise = windowClass.setSystemBarProperties(SystemBarProperties);
      promise.then(() => {
        console.info('Succeeded in setting the system bar properties.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

## loadContent<sup>(deprecated)</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

为当前窗口加载具体页面内容，使用callback异步回调。

建议在UIAbility启动过程中使用该接口，多次调用该接口会先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

当前UI的执行上下文可能不明确，所以不建议在本接口的回调函数中做UI相关的操作。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setUIContent()](#setuicontent9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| path     | string                    | 是   | 要加载到窗口中的页面内容的路径，Stage模型下该路径需添加到工程的main_pages.json文件中，FA模型下该路径需添加到工程的config.json文件中。不支持相对路径写法，需与main_pages.json或config.json中的src取值保持一致。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.loadContent('pages/page2/page3', (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in loading the content.');
});
```

## loadContent<sup>(deprecated)</sup>

loadContent(path: string): Promise&lt;void&gt;

为当前窗口加载具体页面内容，使用Promise异步回调。

建议在UIAbility启动过程中使用该接口，多次调用该接口会先销毁旧的页面内容（即UIContent）再加载新的页面内容，请谨慎使用。

当前UI的执行上下文可能不明确，所以不建议在本接口的回调函数中做UI相关的操作。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setUIContent()](#setuicontent9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| path   | string | 是   | 要加载到窗口中的页面内容的路径，Stage模型下该路径需添加到工程的main_pages.json文件中，FA模型下该路径需添加到工程的config.json文件中。不支持相对路径写法，需与main_pages.json或config.json中的src取值保持一致。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.loadContent('pages/page2/page3');
promise.then(() => {
  console.info('Succeeded in loading the content.');
}).catch((err: BusinessError) => {
  console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
});
```

## isShowing<sup>(deprecated)</sup>

isShowing(callback: AsyncCallback&lt;boolean&gt;): void

判断当前窗口是否已显示，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[isWindowShowing()](#iswindowshowing9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前窗口已显示，返回false表示当前窗口未显示。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.isShowing((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to check whether the window is showing. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
});
```

## isShowing<sup>(deprecated)</sup>

isShowing(): Promise&lt;boolean&gt;

判断当前窗口是否已显示，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[isWindowShowing()](#iswindowshowing9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前窗口已显示，返回false表示当前窗口未显示。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.isShowing();
promise.then((data) => {
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the window is showing. Cause code: ${err.code}, message: ${err.message}`);
});
```

## on('systemAvoidAreaChange')<sup>(deprecated)</sup>

on(type: 'systemAvoidAreaChange', callback: Callback&lt;AvoidArea&gt;): void

开启当前窗口系统避让区变化的监听。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[on('avoidAreaChange')](#onavoidareachange9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'systemAvoidAreaChange'，即系统避让区变化事件。 |
| callback | Callback&lt;[AvoidArea](arkts-apis-window-i.md#avoidarea7)&gt; | 是   | 回调函数。返回当前避让区。                             |


**示例：**

```ts
windowClass.on('systemAvoidAreaChange', (data) => {
  console.info('Succeeded in enabling the listener for system avoid area changes. Data: ' + JSON.stringify(data));
});
```

## off('systemAvoidAreaChange')<sup>(deprecated)</sup>

off(type: 'systemAvoidAreaChange', callback?: Callback&lt;AvoidArea&gt;): void

关闭当前窗口系统避让区变化的监听。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[off('avoidAreaChange')](#offavoidareachange9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'systemAvoidAreaChange'，即系统避让区变化事件。 |
| callback | Callback&lt;[AvoidArea](arkts-apis-window-i.md#avoidarea7)&gt; | 否   | 回调函数。返回当前避让区。若传入参数，则关闭该监听。若未传入参数，则关闭所有系统避让区变化的监听。           |

**示例：**

```ts
const callback = (avoidArea: window.AvoidArea) => {
  // ...
}
windowClass.on('systemAvoidAreaChange', callback);
windowClass.off('systemAvoidAreaChange', callback);
// 如果通过on开启多个callback进行监听，同时关闭所有监听：
windowClass.off('systemAvoidAreaChange');
```

## isSupportWideGamut<sup>(deprecated)</sup>

isSupportWideGamut(callback: AsyncCallback&lt;boolean&gt;): void

判断当前窗口是否支持广色域模式，使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[isWindowSupportWideGamut()](#iswindowsupportwidegamut9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前窗口支持广色域模式，返回false表示当前窗口不支持广色域模式。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.isSupportWideGamut((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to check whether the window support WideGamut. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in checking whether the window support WideGamut Data: ' + JSON.stringify(data));
});
```

## isSupportWideGamut<sup>(deprecated)</sup>

isSupportWideGamut(): Promise&lt;boolean&gt;

判断当前窗口是否支持广色域模式，使用Promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[isWindowSupportWideGamut()](#iswindowsupportwidegamut9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前窗口支持广色域模式，返回false表示当前窗口不支持广色域模式。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.isSupportWideGamut();
promise.then((data) => {
  console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the window support WideGamut. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setColorSpace<sup>(deprecated)</sup>

setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback&lt;void&gt;): void

设置当前窗口的色域模式，使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[setWindowColorSpace()](#setwindowcolorspace9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明         |
| ---------- | ------------------------- | ---- | ------------ |
| colorSpace | [ColorSpace](arkts-apis-window-e.md#colorspace8) | 是   | 色域模式。 |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。   |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set window colorspace. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting window colorspace.');
});
```

## setColorSpace<sup>(deprecated)</sup>

setColorSpace(colorSpace:ColorSpace): Promise&lt;void&gt;

设置当前窗口的色域模式，使用Promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[setWindowColorSpace()](#setwindowcolorspace9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明           |
| ---------- | ------------------------- | ---- | -------------- |
| colorSpace | [ColorSpace](arkts-apis-window-e.md#colorspace8) | 是   | 色域模式。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT);
promise.then(() => {
  console.info('Succeeded in setting window colorspace.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set window colorspace. Cause code: ${err.code}, message: ${err.message}`);
});
```

## getColorSpace<sup>(deprecated)</sup>

getColorSpace(callback: AsyncCallback&lt;ColorSpace&gt;): void

获取当前窗口色域模式，使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getWindowColorSpace()](#getwindowcolorspace9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                                       |
| -------- | ---------------------------------------------- | ---- | ---------------------------------------------------------- |
| callback | AsyncCallback&lt;[ColorSpace](arkts-apis-window-e.md#colorspace8)&gt; | 是   | 回调函数。当获取成功，err为undefined，data为当前色域模式。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.getColorSpace((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to get window colorspace. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in getting window colorspace. Cause:' + JSON.stringify(data));
});
```

## getColorSpace<sup>(deprecated)</sup>

getColorSpace(): Promise&lt;ColorSpace&gt;

获取当前窗口色域模式，使用Promise异步回调。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getWindowColorSpace()](#getwindowcolorspace9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                     | 说明                            |
| ---------------------------------------- | ------------------------------- |
| Promise&lt;[ColorSpace](arkts-apis-window-e.md#colorspace8)&gt; | Promise对象。返回当前色域模式。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.getColorSpace();
promise.then((data) => {
  console.info('Succeeded in getting window color space. Cause:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to get window colorspace. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setBackgroundColor<sup>(deprecated)</sup>

setBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void

设置窗口的背景色，使用callback异步回调。Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowBackgroundColor()](#setwindowbackgroundcolor9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| color    | string                    | 是   | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let color: string = '#00ff33';
windowClass.setBackgroundColor(color, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the background color. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the background color.');
});
```

## setBackgroundColor<sup>(deprecated)</sup>

setBackgroundColor(color: string): Promise&lt;void&gt;

设置窗口的背景色，使用Promise异步回调。Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowBackgroundColor()](#setwindowbackgroundcolor9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| color  | string | 是   | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let color: string = '#00ff33';
let promise = windowClass.setBackgroundColor(color);
promise.then(() => {
  console.info('Succeeded in setting the background color.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the background color. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setBrightness<sup>(deprecated)</sup>

setBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

允许应用窗口设置屏幕亮度值，使用callback异步回调。

当前屏幕亮度规格：窗口设置屏幕亮度生效时，控制中心不可以调整系统屏幕亮度，窗口恢复默认系统亮度之后，控制中心可以调整系统屏幕亮度。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowBrightness()](#setwindowbrightness9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明                                    |
| ---------- | ------------------------- | ---- |---------------------------------------|
| brightness | number                    | 是   | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示恢复成设置窗口亮度前的系统控制中心亮度。 |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let brightness: number = 1;
windowClass.setBrightness(brightness, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the brightness. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the brightness.');
});
```

## setBrightness<sup>(deprecated)</sup>

setBrightness(brightness: number): Promise&lt;void&gt;

允许应用窗口设置屏幕亮度值，使用Promise异步回调。

当前屏幕亮度规格：窗口设置屏幕亮度生效时，控制中心不可以调整系统屏幕亮度，窗口恢复默认系统亮度之后，控制中心可以调整系统屏幕亮度。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowBrightness()](#setwindowbrightness9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                       |
| ---------- | ------ | ---- |------------------------------------------|
| brightness | number | 是   | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示恢复成设置窗口亮度前的系统控制中心亮度。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let brightness: number = 1;
let promise = windowClass.setBrightness(brightness);
promise.then(() => {
  console.info('Succeeded in setting the brightness.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the brightness. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setDimBehind<sup>(deprecated)</sup>

setDimBehind(dimBehindValue: number, callback: AsyncCallback&lt;void&gt;): void

窗口叠加时，设备有子窗口的情况下设置靠后的窗口的暗度值，使用callback异步回调。

> **说明：**
>
> 该接口不支持使用。从API version 7开始支持，从API version 9开始废弃。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型                      | 必填 | 说明                                     |
| -------------- | ------------------------- | ---- |----------------------------------------|
| dimBehindValue | number                    | 是   | 表示靠后的窗口的暗度值，取值范围为[0.0, 1.0]，取1.0时表示最暗。 |
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.setDimBehind(0.5, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the dimness. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the dimness.');
});
```

## setDimBehind<sup>(deprecated)</sup>

setDimBehind(dimBehindValue: number): Promise&lt;void&gt;

窗口叠加时，设备有子窗口的情况下设置靠后的窗口的暗度值，使用Promise异步回调。

> **说明：**
>
> 该接口不支持使用。从API version 7开始支持，从API version 9开始废弃。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型   | 必填 | 说明                                               |
| -------------- | ------ | ---- | -------------------------------------------------- |
| dimBehindValue | number | 是   | 表示靠后的窗口的暗度值，取值范围为0-1，1表示最暗。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.setDimBehind(0.5);
promise.then(() => {
  console.info('Succeeded in setting the dimness.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the dimness. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setFocusable<sup>(deprecated)</sup>

setFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置使用点击或其他方式使该窗口获焦的场景时，该窗口是否支持窗口焦点从操作前的获焦窗口切换到该窗口，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowFocusable()](#setwindowfocusable9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                         |
| ----------- | ------------------------- | ---- | ---------------------------- |
| isFocusable | boolean                   | 是   | 点击时是否支持切换焦点窗口。true表示支持；false表示不支持。设置为false时，该窗口不支持绑定输入法和接收键盘事件，如需处理输入逻辑，建议参考[不可获焦窗口中输入框与输入法交互指南](../../inputmethod/use-inputmethod-in-not-focusable-window.md)。|
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。                   |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocusable: boolean = true;
windowClass.setFocusable(isFocusable, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the window to be focusable. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the window to be focusable.');
});
```

## setFocusable<sup>(deprecated)</sup>

setFocusable(isFocusable: boolean): Promise&lt;void&gt;

设置使用点击或其他方式使该窗口获焦的场景时，该窗口是否支持窗口焦点从点击前的获焦窗口切换到该窗口，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowFocusable()](#setwindowfocusable9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                         |
| ----------- | ------- | ---- | ---------------------------- |
| isFocusable | boolean | 是   | 点击时是否支持切换焦点窗口。true表示支持；false表示不支持。设置为false时，该窗口不支持绑定输入法和接收键盘事件，如需处理输入逻辑，建议参考[不可获焦窗口中输入框与输入法交互指南](../../inputmethod/use-inputmethod-in-not-focusable-window.md)。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocusable: boolean = true;
let promise = windowClass.setFocusable(isFocusable);
promise.then(() => {
  console.info('Succeeded in setting the window to be focusable.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the window to be focusable. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setKeepScreenOn<sup>(deprecated)</sup>

setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

设置屏幕是否为常亮状态，使用callback异步回调。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowKeepScreenOn()](#setwindowkeepscreenon9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型                      | 必填 | 说明                     |
| -------------- | ------------------------- | ---- | ------------------------ |
| isKeepScreenOn | boolean                   | 是   | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。 |
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。               |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isKeepScreenOn: boolean = true;
windowClass.setKeepScreenOn(isKeepScreenOn, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the screen to be always on.');
});
```

## setKeepScreenOn<sup>(deprecated)</sup>

setKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt;

设置屏幕是否为常亮状态，使用Promise异步回调。

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃，建议使用[setWindowKeepScreenOn()](#setwindowkeepscreenon9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型    | 必填 | 说明                     |
| -------------- | ------- | ---- | ------------------------ |
| isKeepScreenOn | boolean | 是   | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isKeepScreenOn: boolean = true;
let promise = windowClass.setKeepScreenOn(isKeepScreenOn);
promise.then(() => {
  console.info('Succeeded in setting the screen to be always on.');
}).catch((err: BusinessError) => {
  console.info(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置是否允许可点击子窗口之外的区域，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。
>
> 从API version 9开始，系统默认允许点击子窗口之外的区域，此接口不再支持使用，也不再提供替代接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                      | 必填 | 说明             |
| --------- | ------------------------- | ---- | ---------------- |
| touchable | boolean                   | 是   | 设置是否可点击。true表示可点击；false表示不可点击。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.setOutsideTouchable(true, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the area to be touchable. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the area to be touchable.');
});
```

## setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean): Promise&lt;void&gt;

设置是否允许可点击子窗口之外的区域，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。
>
> 从API version 9开始，系统默认允许点击子窗口之外的区域，此接口不再支持使用，也不再提供替代接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型    | 必填 | 说明             |
| --------- | ------- | ---- | ---------------- |
| touchable | boolean | 是   | 设置是否可点击。true表示可点击；false表示不可点击。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.setOutsideTouchable(true);
promise.then(() => {
  console.info('Succeeded in setting the area to be touchable.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the area to be touchable. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setPrivacyMode<sup>(deprecated)</sup>

setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为隐私模式，使用callback异步回调。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。此接口可用于禁止截屏/录屏的场景。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowPrivacyMode()](#setwindowprivacymode9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型                      | 必填 | 说明                 |
| ------------- | ------------------------- | ---- | -------------------- |
| isPrivacyMode | boolean                   | 是   | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。 |
| callback      | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isPrivacyMode: boolean = true;
windowClass.setPrivacyMode(isPrivacyMode, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the window to privacy mode. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the window to privacy mode.');
});
```

## setPrivacyMode<sup>(deprecated)</sup>

setPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

设置窗口是否为隐私模式，使用Promise异步回调。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。此接口可用于禁止截屏/录屏的场景。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowPrivacyMode()](#setwindowprivacymode9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型    | 必填 | 说明                 |
| ------------- | ------- | ---- | -------------------- |
| isPrivacyMode | boolean | 是   | 窗口是否为隐私模式。true表示模式开启；false表示模式关闭。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isPrivacyMode: boolean = true;
let promise = windowClass.setPrivacyMode(isPrivacyMode);
promise.then(() => {
  console.info('Succeeded in setting the window to privacy mode.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the window to privacy mode. Cause code: ${err.code}, message: ${err.message}`);
});
```

## setTouchable<sup>(deprecated)</sup>

setTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为可触状态，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowTouchable()](#setwindowtouchable9)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                 |
| ----------- | ------------------------- | ---- | -------------------- |
| isTouchable | boolean                   | 是   | 窗口是否为可触状态。true表示可触；false表示不可触。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isTouchable = true;
windowClass.setTouchable(isTouchable, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the window to be touchable. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the window to be touchable.');
});
```

## setTouchable<sup>(deprecated)</sup>

setTouchable(isTouchable: boolean): Promise&lt;void&gt;

设置窗口是否为可触状态，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[setWindowTouchable()](#setwindowtouchable9-1)替代。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                 |
| ----------- | ------- | ---- | -------------------- |
| isTouchable | boolean | 是   | 窗口是否为可触状态。true表示可触；false表示不可触。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isTouchable = true;
let promise = windowClass.setTouchable(isTouchable);
promise.then(() => {
  console.info('Succeeded in setting the window to be touchable.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the window to be touchable. Cause code: ${err.code}, message: ${err.message}`);
});
```
