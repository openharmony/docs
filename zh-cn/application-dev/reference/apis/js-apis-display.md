# @ohos.display (屏幕属性)

屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息，获取所有显示设备的信息以及监听显示设备的插拔行为。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import display from '@ohos.display';
```

## DisplayState

显示设备的状态枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STATE_UNKNOWN | 0 | 表示显示设备状态未知。|
| STATE_OFF | 1 | 表示显示设备状态为关闭。 |
| STATE_ON | 2 | 表示显示设备状态为开启。|
| STATE_DOZE | 3 | 表示显示设备为低电耗模式。|
| STATE_DOZE_SUSPEND | 4 | 表示显示设备为睡眠模式，CPU为挂起状态。 |
| STATE_VR | 5 | 表示显示设备为VR模式。|
| STATE_ON_SUSPEND | 6 | 表示显示设备为开启状态，CPU为挂起状态。 |

## Orientation<sup>10+</sup>

显示设备当前显示的方向枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PORTRAIT | 0 | 表示设备当前以竖屏方式显示。|
| LANDSCAPE | 1 | 表示设备当前以横屏方式显示。 |
| PORTRAIT_INVERTED | 2 | 表示设备当前以反向竖屏方式显示。|
| LANDSCAPE_INVERTED | 3 | 表示设备当前以反向横屏方式显示。|

## FoldStatus<sup>10+</sup>

当前可折叠设备的折叠状态枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| FOLD_STATUS_UNKNOWN | 0 | 表示设备当前折叠状态未知。|
| FOLD_STATUS_EXPANDED | 1 | 表示设备当前折叠状态为完全展开。|
| FOLD_STATUS_FOLDED | 2 | 表示设备当前折叠状态为折叠。|
| FOLD_STATUS_HALF_FOLDED | 3 | 表示设备当前折叠状态为半折叠。半折叠指完全展开和折叠之间的状态。|

## FoldDisplayMode<sup>10+</sup>

可折叠设备的显示模式枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| FOLD_DISPLAY_MODE_UNKNOWN | 0 | 表示设备当前折叠显示模式未知。|
| FOLD_DISPLAY_MODE_FULL | 1 | 表示设备当前全屏显示。 |
| FOLD_DISPLAY_MODE_MAIN | 2 | 表示设备当前主屏幕显示。|
| FOLD_DISPLAY_MODE_SUB | 3 | 表示设备当前子屏幕显示。|
| FOLD_DISPLAY_MODE_COORDINATION | 4 | 表示设备当前双屏协同显示。|

## FoldCreaseRegion<sup>10+</sup>

折叠折痕区域。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 可读 | 可写 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| displayId   | number   | 是   | 否   | 显示器ID，用于识别折痕所在的屏幕。 |
| creaseRects    | Array\<[Rect](#rect9)>   | 是   | 否   | 折痕区域。 |

## Rect<sup>9+</sup>

矩形区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 可读 | 可写 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | 是   | 是   | 矩形区域的左边界，单位为像素，该参数应为整数。 |
| top    | number   | 是   | 是   | 矩形区域的上边界，单位为像素，该参数应为整数。 |
| width  | number   | 是   | 是   | 矩形区域的宽度，单位为像素，该参数应为整数。   |
| height | number   | 是   | 是   | 矩形区域的高度，单位为像素，该参数应为整数。   |

## WaterfallDisplayAreaRects<sup>9+</sup>

瀑布屏曲面部分显示区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型      | 可读 | 可写 | 说明               |
| ------ | ------------- | ---- | ---- | ------------------ |
| left   | [Rect](#rect9) | 是   | 否   | 瀑布曲面区域的左侧矩形区域。 |
| top    | [Rect](#rect9) | 是   | 否   | 瀑布曲面区域的顶部矩形区域。 |
| right  | [Rect](#rect9) | 是   | 否   | 瀑布曲面区域的右侧矩形区域。 |
| bottom | [Rect](#rect9) | 是   | 否   | 瀑布曲面区域的底部矩形区域。 |

## CutoutInfo<sup>9+</sup>

挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                        | 类型      | 可读 | 可写 | 说明               |
| --------------------------- | ------------- | ---- | ---- | ------------------ |
| boundingRects                | Array\<[Rect](#rect9)> | 是   | 否   | 挖孔、刘海等区域的边界矩形。 |
| waterfallDisplayAreaRects   | [WaterfallDisplayAreaRects](#waterfalldisplayarearects9) | 是 | 否 | 瀑布屏曲面部分显示区域。 |

## display.getDefaultDisplaySync<sup>9+</sup>

getDefaultDisplaySync(): Display

获取当前默认的display对象。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                           | 说明                                           |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | 返回默认的display对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import display from '@ohos.display';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```

## display.getAllDisplays<sup>9+</sup>

getAllDisplays(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

获取当前所有的display对象，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Display](#display)&gt;&gt; | 是 | 回调函数。返回当前所有的display对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import display from '@ohos.display';

let displayClass: Array<display.Display> = [];
display.getAllDisplays((err: BusinessError, data: Array<display.Display>) => {
  displayClass = data;
  const errCode: number = err.code;
  if (errCode) {
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
});
```

## display.getAllDisplays<sup>9+</sup>

getAllDisplays(): Promise&lt;Array&lt;Display&gt;&gt;

获取当前所有的display对象，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Display](#display)&gt;&gt; | Promise对象。返回当前所有的display对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import display from '@ohos.display';

let displayClass: Array<display.Display> =[];
let promise: Promise<Array<display.Display>> = display.getAllDisplays();
promise.then((data: Array<display.Display>) => {
  displayClass = data;
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
});
```

## display.hasPrivateWindow<sup>9+</sup>

hasPrivateWindow(displayId: number): boolean

查询指定display对象上是否有可见的隐私窗口。可通过[setWindowPrivacyMode()](js-apis-window.md#setwindowprivacymode9)接口设置隐私窗口。隐私窗口内容将无法被截屏或录屏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- |----------|
| id     | number                    | 是   | 显示设备的id，该参数仅支持整数输入。 |

**返回值：**

| 类型                             | 说明                                                                    |
| -------------------------------- |-----------------------------------------------------------------------|
|boolean | 查询的display对象上是否有可见的隐私窗口。<br>true表示此display对象上有可见的隐私窗口，false表示此display对象上没有可见的隐私窗口。</br> |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import display from '@ohos.display';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  let ret: boolean = true;
  try {
    ret = display.hasPrivateWindow(displayClass.id);
  } catch (exception) {
    console.error('Failed to check has privateWindow or not. Code: ' + JSON.stringify(exception));
  }
  if (ret == undefined) {
    console.log("Failed to check has privateWindow or not.");
  }
  if (ret) {
    console.log("There has privateWindow.");
  } else if (!ret) {
    console.log("There has no privateWindow.");
  }
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```

## display.on('add'|'remove'|'change')

on(type: 'add'|'remove'|'change', callback: Callback&lt;number&gt;): void

开启显示设备变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                                                                                              |
| -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------------------------|
| type | string | 是 | 监听事件。<br/>- type为"add"，表示增加显示设备事件。例如：插入显示器。<br/>- type为"remove"，表示移除显示设备事件。例如：移除显示器。<br/>- type为"change"，表示改变显示设备事件。例如：显示器方向改变。 |
| callback | Callback&lt;number&gt; | 是 | 回调函数。返回监听到的显示设备的id，该参数应为整数。                                                                                                     |

**示例：**

```ts
import { Callback } from '@ohos.base';

let callback: Callback<number> = (data: number) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on("add", callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('add'|'remove'|'change')

off(type: 'add'|'remove'|'change', callback?: Callback&lt;number&gt;): void

关闭显示设备变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听事件。<br/>- type为"add"，表示增加显示设备事件。例如：插入显示器。<br/>- type为"remove"，表示移除显示设备事件。例如：移除显示器。<br/>- type为"change"，表示改变显示设备事件。例如：显示器方向改变。 |
| callback | Callback&lt;number&gt; | 否 | 回调函数。返回监听到的显示设备的id，该参数应为整数。 |

**示例：**

```ts
try {
  display.off("remove");
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.on('privateModeChange')<sup>10+</sup>

on(type: 'privateModeChange', callback: Callback&lt;boolean&gt;): void

开启屏幕隐私模式变化的监听。当屏幕前台有隐私窗口，则屏幕处于隐私模式，屏幕中的隐私窗口内容无法被截屏或录屏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'privateModeChange'，表示屏幕隐私模式状态发生变化。 |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。表示屏幕隐私模式是否改变。true表示屏幕由非隐私窗口模式变为隐私模式，false表示屏幕由隐私模式变为非隐私模式。 |

**示例：**

```ts
import { Callback } from '@ohos.base';

let callback: Callback<boolean> = (data: boolean) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on("privateModeChange", callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('privateModeChange')<sup>10+</sup>

off(type: 'privateModeChange', callback?: Callback&lt;boolean&gt;): void

关闭屏幕隐私模式变化的监听。当屏幕前台有隐私窗口，则屏幕处于隐私模式，屏幕中的隐私窗口内容无法被截屏或录屏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'privateModeChange'，表示屏幕隐私模式状态发生变化。 |
| callback | Callback&lt;boolean&gt; | 否   | 回调函数。表示屏幕隐私模式是否改变。true表示屏幕由非隐私模式变为隐私模式，false表示屏幕由隐私模式变为非隐私模式。 |

**示例：**

```ts
try {
  display.off("privateModeChange");
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.isFoldable<sup>10+</sup>
isFoldable(): boolean

检查设备是否可折叠。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| boolean | boolean对象，返回当前设备是否可折叠的结果。false表示不可折叠，true表示可折叠。|

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import display from '@ohos.display';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  let ret: boolean = false;
  try {
    ret = display.isFoldable();
  } catch (exception) {
    console.error('Failed to check is foldable or not. Code: ' + JSON.stringify(exception));
  }
  if (ret == undefined) {
    console.log("Failed to check is foldable or not.");
  }
  if (ret) {
    console.log("The device is foldable.");
  } else if (!ret) {
    console.log("The device is not foldable.");
  }
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```

## display.setFoldDisplayMode<sup>10+</sup>
setFoldDisplayMode(mode: FoldDisplayMode): void

更改可折叠设备的显示模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| mode     | [FoldDisplayMode](#folddisplaymode10)    | 是   | 可折叠设备的显示模式。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import display from '@ohos.display';

try {
  let mode: display.FoldDisplayMode = display.FoldDisplayMode.FOLD_DISPLAY_MODE_FULL;
  display.setFoldDisplayMode(mode);
} catch (exception) {
  console.error('Failed to change the fold display mode. Code: ' + JSON.stringify(exception));
}
```

## display.getFoldStatus<sup>10+</sup>
getFoldStatus(): FoldStatus

获取可折叠设备的当前折叠状态。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldStatus](#foldstatus10) | FoldStatus对象，返回当前可折叠设备的折叠状态。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import display from '@ohos.display';

try {
  display.getFoldStatus();
} catch (exception) {
  console.error('Failed to obtain the fold status. Code: ' + JSON.stringify(exception));
}
```

## display.getFoldDisplayMode<sup>10+</sup>
getFoldDisplayMode(): FoldDisplayMode

获取可折叠设备的显示模式。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldDisplayMode](#folddisplaymode10) | FoldDisplayMode对象，返回当前可折叠设备的显示模式。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import display from '@ohos.display';

try {
  display.getFoldDisplayMode();
} catch (exception) {
  console.error('Failed to obtain the fold display mode. Code: ' + JSON.stringify(exception));
}
```

## display.getCurrentFoldCreaseRegion<sup>10+</sup>
getCurrentFoldCreaseRegion(): FoldCreaseRegion

在当前显示模式下获取折叠折痕区域。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldCreaseRegion](#foldcreaseregion10) | FoldCreaseRegion对象，返回设备在当前显示模式下的折叠折痕区域。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import display from '@ohos.display';

try {
  display.getCurrentFoldCreaseRegion();
} catch (exception) {
  console.error('Failed to obtain the current fold crease region. Code: ' + JSON.stringify(exception));
}
```

## display.on('foldStatusChange')<sup>10+</sup>

on(type: 'foldStatusChange', callback: Callback&lt;FoldStatus&gt;): void

开启折叠设备折叠状态变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'foldStatusChange'，表示折叠设备折叠状态发生变化。 |
| callback | Callback&lt;[FoldStatus](#foldstatus10)&gt; | 是   | 回调函数。表示折叠设备折叠状态。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { Callback } from '@ohos.base';

let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on('foldStatusChange', callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('foldStatusChange')<sup>10+</sup>

off(type: 'foldStatusChange', callback?: Callback&lt;FoldStatus&gt;): void

关闭折叠设备折叠状态变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'foldStatusChange'，表示折叠设备折叠状态发生变化。 |
| callback | Callback&lt;[FoldStatus](#foldstatus10)&gt; | 否   | 回调函数。表示折叠设备的折叠状态。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
try {
  display.off('foldStatusChange');
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.on('foldDisplayModeChange')<sup>10+</sup>

on(type: 'foldDisplayModeChange', callback: Callback&lt;FoldDisplayMode&gt;): void

开启折叠设备屏幕显示模式变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'foldDisplayModeChange'，表示折叠设备屏幕显示模式发生变化。 |
| callback | Callback&lt;[FoldDisplayMode](#folddisplaymode10)&gt; | 是   | 回调函数。表示折叠设备屏幕显示模式。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { Callback } from '@ohos.base';

let callback: Callback<display.FoldDisplayMode> = (data: display.FoldDisplayMode) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on('foldDisplayModeChange', callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
}
```

## display.off('foldDisplayModeChange')<sup>10+</sup>

off(type: 'foldDisplayModeChange', callback?: Callback&lt;FoldDisplayMode&gt;): void

关闭折叠设备屏幕显示模式变化的监听。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'foldDisplayModeChange'，表示折叠设备屏幕显示模式发生变化。 |
| callback | Callback&lt;[FoldDisplayMode](#folddisplaymode10)&gt; | 否   | 回调函数。表示折叠设备屏幕显示模式。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
try {
  display.off('foldDisplayModeChange');
} catch (exception) {
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.getDefaultDisplay<sup>(deprecated)</sup>

getDefaultDisplay(callback: AsyncCallback&lt;Display&gt;): void

获取当前默认的display对象，使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃，推荐使用[getDefaultDisplaySync()](#displaygetdefaultdisplaysync9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[Display](#display)&gt; | 是 | 回调函数。返回当前默认的display对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let displayClass: display.Display | null = null;
display.getDefaultDisplay((err: BusinessError, data: display.Display) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
  displayClass = data;
});
```

## display.getDefaultDisplay<sup>(deprecated)</sup>

getDefaultDisplay(): Promise&lt;Display&gt;

获取当前默认的display对象，使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃，推荐使用[getDefaultDisplaySync()](#displaygetdefaultdisplaysync9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                               | 说明                                           |
| ---------------------------------- | ---------------------------------------------- |
| Promise&lt;[Display](#display)&gt; | Promise对象。返回当前默认的display对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let displayClass: display.Display | null = null;
let promise: Promise<display.Display> = display.getDefaultDisplay();
promise.then((data: display.Display) => {
  displayClass = data;
  console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
});
```

## display.getAllDisplay<sup>(deprecated)</sup>

getAllDisplay(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

获取当前所有的display对象，使用callback异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃，推荐使用[getAllDisplays()](#displaygetalldisplays9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                            |
| -------- | ---------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Display](#display)&gt;&gt; | 是   | 回调函数。返回当前所有的display对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

display.getAllDisplay((err: BusinessError, data: Array<display.Display>) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
});
```

## display.getAllDisplay<sup>(deprecated)</sup>

getAllDisplay(): Promise&lt;Array&lt;Display&gt;&gt;

获取当前所有的display对象，使用Promise异步回调。

> **说明：**
> 
> 从 API version 7开始支持，从API version 9开始废弃，推荐使用[getAllDisplays()](#displaygetalldisplays9-1)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                            | 说明                                                    |
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Display](#display)&gt;&gt; | Promise对象。返回当前所有的display对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let promise: Promise<Array<display.Display>> = display.getAllDisplay();
promise.then((data: Array<display.Display>) => {
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
});
```

## Display
屏幕实例。描述display对象的属性和方法。

下列API示例中都需先使用[getAllDisplays()](#displaygetalldisplays9)、[getDefaultDisplaySync()](#displaygetdefaultdisplaysync9)中的任一方法获取到Display实例，再通过此实例调用对应方法。

### 属性

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型 | 可读 | 可写 | 说明                                                                                                            |
| -------- | -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------|
| id | number | 是 | 否 | 显示设备的id号，该参数应为整数。                                                                                             |
| name | string | 是 | 否 | 显示设备的名称。                                                                                                      |
| alive | boolean | 是 | 否 | 显示设备是否启用。                                                                                                     |
| state | [DisplayState](#displaystate) | 是 | 否 | 显示设备的状态。                                                                                                      |
| refreshRate | number | 是 | 否 | 显示设备的刷新率，该参数应为整数。                                                                                             |
| rotation | number | 是 | 否 | 显示设备的屏幕顺时针旋转角度。<br>值为0时，表示显示设备屏幕顺时针旋转为0°；<br>值为1时，表示显示设备屏幕顺时针旋转为90°；<br>值为2时，表示显示设备屏幕顺时针旋转为180°；<br>值为3时，表示显示设备屏幕顺时针旋转为270°。 |
| width | number | 是 | 否 | 显示设备的宽度，单位为像素，该参数应为整数。                                                                                        |
| height | number | 是 | 否 | 显示设备的高度，单位为像素，该参数应为整数。                                                                                        |
| densityDPI | number | 是 | 否 | 显示设备的屏幕密度，表示每英寸点数。该参数为浮点数，一般取值160.0、480.0等。                                                                   |
| orientation<sup>10+</sup> | [Orientation](#orientation10) | 是 | 否 | 表示屏幕当前显示的方向。                                                                                                  |
| densityPixels | number | 是 | 否 | 显示设备的逻辑密度，是像素单位无关的缩放系数。该参数为浮点数，一般取值1.0、3.0等。                                                                  |
| scaledDensity | number | 是 | 否 | 显示设备的显示字体的缩放因子。该参数为浮点数，通常与densityPixels相同。                                                                    |
| xDPI | number | 是 | 否 | x方向中每英寸屏幕的确切物理像素值，该参数为浮点数。                                                                                    |
| yDPI | number | 是 | 否 | y方向中每英寸屏幕的确切物理像素值，该参数为浮点数。                                                                                    |
| colorSpaces<sup>11+</sup> | Array<colorSpaceManager.ColorSpace> | 是 | 否 | 显示设备支持的所有色域类型，关于色域类型的详细介绍请参见[色彩管理](js-apis-colorSpaceManager.md)。                                             |
| hdrFormats<sup>11+</sup> | Array<hdrCapability.HDRFormat> | 是 | 否 | 显示设备支持的所有HDR格式，关于HDR格式的详细介绍请参见[HDR能力](js-apis-hdrCapability.md)。                                              |

### getCutoutInfo<sup>9+</sup>
getCutoutInfo(callback: AsyncCallback&lt;CutoutInfo&gt;): void

获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。使用callback异步回调。建议应用布局规避该区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;[CutoutInfo](#cutoutinfo9)&gt;   | 是   | 回调函数。返回描述不可用屏幕区域的CutoutInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  displayClass.getCutoutInfo((err: BusinessError, data: display.CutoutInfo) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to get cutoutInfo. Code: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in getting cutoutInfo. data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```
### getCutoutInfo<sup>9+</sup>
getCutoutInfo(): Promise&lt;CutoutInfo&gt;

获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。使用Promise异步回调。建议应用布局规避该区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[CutoutInfo](#cutoutinfo9)&gt; | Promise对象。返回描述不可用屏幕区域的CutoutInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  let promise: Promise<display.CutoutInfo> = displayClass.getCutoutInfo();
  promise.then((data: display.CutoutInfo) => {
    console.info('Succeeded in getting cutoutInfo. Data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```
### hasImmersiveWindow<sup>11+</sup>
hasImmersiveWindow(callback: AsyncCallback&lt;boolean&gt;): void

判断当前屏幕是否包含沉浸式窗口，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;boolean&gt;   | 是   | 回调函数。返回true表示当前屏幕包含沉浸式窗口，false表示不包含。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import display from '@ohos.display'

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}

try {
  displayClass.hasImmersiveWindow((err: BusinessError, data) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in checking whether there is immersive window. data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(exception));
}
```
### hasImmersiveWindow<sup>11+</sup>
hasImmersiveWindow(): Promise&lt;boolean&gt;

判断当前屏幕是否包含沉浸式窗口，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前屏幕包含沉浸式窗口，false表示不包含。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import display from '@ohos.display'

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}

let promise = displayClass.hasImmersiveWindow();
promise.then((data) => {
  console.info('Succeeded in checking whether there is immersive window. data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(exception));
})
```
