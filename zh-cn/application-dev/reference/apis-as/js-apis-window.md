# @ohos.window (窗口)

窗口提供管理窗口的一些基础能力，包括对当前窗口的创建、销毁、各属性设置，以及对各窗口间的管理调度。

该模块提供以下窗口相关的常用功能：

- [Window](#window)：当前窗口实例，窗口管理器管理的基本单元。
- [WindowStage](#windowstage9)：窗口管理器。管理各个基本窗口单元。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import window from '@ohos.window';
```

## AvoidAreaType<sup>7+</sup>

窗口内容需要规避区域的类型枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                                    | 值   | 说明                                                         |
| --------------------------------------- | ---- | ------------------------------------------------------------ |
| TYPE_SYSTEM                             | 0    | 表示系统默认区域。一般包括状态栏、导航栏，各设备系统定义可能不同。 |
| TYPE_CUTOUT                             | 1    | 表示刘海屏区域。                                             |
| TYPE_SYSTEM_GESTURE<sup>9+</sup>        | 2    | 表示手势区域。                                               |
| TYPE_KEYBOARD<sup>9+</sup>              | 3    | 表示软键盘区域。                                             |
| TYPE_NAVIGATION_INDICATOR<sup>11+</sup> | 4    | 表示导航条区域。                                             |

## Rect<sup>7+</sup>

窗口矩形区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型   | 可读 | 可写 | 说明                                         |
| ------ | ------ | ---- | ---- | -------------------------------------------- |
| left   | number | 是   | 是   | 矩形区域的左边界，单位为px，该参数为整数。   |
| top    | number | 是   | 是   | 矩形区域的上边界，单位为px，该参数应为整数。 |
| width  | number | 是   | 是   | 矩形区域的宽度，单位为px，该参数应为整数。   |
| height | number | 是   | 是   | 矩形区域的高度，单位为px，该参数应为整数。   |

## AvoidArea<sup>7+</sup>

窗口内容规避区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                 | 类型           | 可读 | 可写 | 说明                                              |
| -------------------- | -------------- | ---- | ---- | ------------------------------------------------- |
| visible<sup>9+</sup> | boolean        | 是   | 是   | 规避区域是否可见。true表示可见；false表示不可见。 |
| leftRect             | [Rect](#rect7) | 是   | 是   | 屏幕左侧的矩形区。                                |
| topRect              | [Rect](#rect7) | 是   | 是   | 屏幕顶部的矩形区。                                |
| rightRect            | [Rect](#rect7) | 是   | 是   | 屏幕右侧的矩形区。                                |
| bottomRect           | [Rect](#rect7) | 是   | 是   | 屏幕底部的矩形区。                                |

## Size<sup>7+</sup>

窗口大小。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型   | 可读 | 可写 | 说明                                 |
| ------ | ------ | ---- | ---- | ------------------------------------ |
| width  | number | 是   | 是   | 窗口宽度，单位为px，该参数应为整数。 |
| height | number | 是   | 是   | 窗口高度，单位为px，该参数应为整数。 |

## WindowProperties

窗口属性。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                                  | 类型                       | 可读 | 可写 | 说明                                                         |
| ------------------------------------- | -------------------------- | ---- | ---- | ------------------------------------------------------------ |
| windowRect<sup>7+</sup>               | [Rect](#rect7)             | 是   | 是   | 窗口尺寸。                                                   |
| brightness                            | number                     | 是   | 是   | 屏幕亮度。该参数为浮点数，可设置的亮度范围为[0.0, 1.0]，其取1.0时表示最大亮度值。如果窗口没有设置亮度值，表示亮度跟随系统，此时获取到的亮度值为-1。 |
| isKeepScreenOn                        | boolean                    | 是   | 是   | 屏幕是否常亮，默认为false。true表示常亮；false表示不常亮。   |

## Orientation<sup>9+</sup>

窗口显示方向类型枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                               | 值   | 说明                               |
| ---------------------------------- | ---- | ---------------------------------- |

| PORTRAIT                           | 1    | 表示竖屏显示模式。                 |
| AUTO_ROTATION                      | 5    | 表示传感器自动旋转模式。           |
| AUTO_ROTATION_PORTRAIT             | 6    | 表示传感器自动竖向旋转模式。       |
| AUTO_ROTATION_LANDSCAPE            | 7    | 表示传感器自动横向旋转模式。       |
| AUTO_ROTATION_RESTRICTED           | 8    | 表示受开关控制的自动旋转模式。     |
| AUTO_ROTATION_PORTRAIT_RESTRICTED  | 9    | 表示受开关控制的自动竖向旋转模式。 |
| AUTO_ROTATION_LANDSCAPE_RESTRICTED | 10   | 表述受开关控制的自动横向旋转模式。 |
| LOCKED                             | 11   | 表示锁定模式。                     |

## WindowEventType<sup>10+</sup>

窗口生命周期。

| 名称                           | 值   | 说明                                                         |
| ------------------------------ | ---- | ------------------------------------------------------------ |
| WINDOW_SHOWN                   | 1    | 切到前台。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core。 |
| WINDOW_ACTIVE                  | 2    | 获焦状态。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core。 |
| WINDOW_INACTIVE                | 3    | 失焦状态。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core。 |
| WINDOW_HIDDEN                  | 4    | 切到后台。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core。 |
| WINDOW_DESTROYED<sup>11+</sup> | 7    | 窗口销毁。<br> **系统能力：** SystemCapability.Window.SessionManager。 |

## SpecificSystemBar<sup>11+</sup>

当前支持显示或隐藏的系统栏类型。

**系统能力：** SystemCapability.Window.SessionManager

| 名称                | 类型   | 说明         |
| ------------------- | ------ | ------------ |
| status              | string | 状态栏。     |
| navigation          | string | 导航栏。     |
| navigationIndicator | string | 底部导航条。 |

## window.findWindow<sup>9+</sup>

findWindow(name: string): Window

查找name所对应的窗口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| name   | string | 是   | 窗口id。 |

**返回值：**

| 类型              | 说明                 |
| ----------------- | -------------------- |
| [Window](#window) | 当前查找的窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
let windowClass: window.Window | undefined = undefined;
try {
  windowClass = window.findWindow('alertWindow');
} catch (exception) {
  console.error('Failed to find the Window. Cause: ' + JSON.stringify(exception));
}
```

## Window

当前窗口实例，窗口管理器管理的基本单元。

下列API示例中都需先使用[findWindow()](#windowfindwindow9)获取到Window实例，再通过此实例调用对应方法。

### showWindow<sup>9+</sup>

showWindow(callback: AsyncCallback&lt;void&gt;): void

显示当前窗口，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
windowClass.showWindow((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in showing the window.');
});
```

### showWindow<sup>9+</sup>

showWindow(): Promise&lt;void&gt;

显示当前窗口，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.showWindow();
promise.then(() => {
  console.info('Succeeded in showing the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
});
```

### destroyWindow<sup>9+</sup>

destroyWindow(callback: AsyncCallback&lt;void&gt;): void

销毁当前窗口，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
windowClass.destroyWindow((err) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in destroying the window.');
});
```

### destroyWindow<sup>9+</sup>

destroyWindow(): Promise&lt;void&gt;

销毁当前窗口，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let windowClass: window.Window = window.findWindow("test");
let promise = windowClass.destroyWindow();
promise.then(() => {
  console.info('Succeeded in destroying the window.');
}).catch((err: BusinessError) => {
  console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
});
```

### moveWindowTo<sup>9+</sup>

moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

移动窗口位置，使用callback异步回调。

全屏模式窗口不支持该操作。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| x        | number                    | 是   | 窗口在x轴方向移动的值，值为正表示右移，单位为px，该参数仅支持整数输入。 |
| y        | number                    | 是   | 窗口在y轴方向移动的值，值为正表示下移，单位为px，该参数仅支持整数输入。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to move the window. Cause:' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in moving the window.');
  });
} catch (exception) {
  console.error('Failed to move the window. Cause:' + JSON.stringify(exception));
}
```

### moveWindowTo<sup>9+</sup>

moveWindowTo(x: number, y: number): Promise&lt;void&gt;

移动窗口位置，使用Promise异步回调。

全屏模式窗口不支持该操作。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| x      | number | 是   | 窗口在x轴方向移动的值，值为正表示右移，单位为px，该参数仅支持整数输入。 |
| y      | number | 是   | 窗口在y轴方向移动的值，值为正表示下移，单位为px，该参数仅支持整数输入。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let windowClass: window.Window = window.findWindow("test");
  let promise = windowClass.moveWindowTo(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
  }).catch((err: BusinessError) => {
    console.error('Failed to move the window. Cause: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to move the window. Cause:' + JSON.stringify(exception));
}
```

### resize<sup>9+</sup>

resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

改变当前窗口大小，使用callback异步回调。

应用主窗口与子窗口存在大小限制，默认宽度范围：[320, 2560]，默认高度范围：[240, 2560]，单位为vp。
应用主窗口与子窗口的最小宽度与最小高度可由产品端进行配置，配置后的最小宽度与最小高度以产品段配置值为准。

系统窗口存在大小限制，宽度范围：[0, 2560]，高度范围：[0, 2560]，单位为vp。

设置的宽度与高度受到此约束限制，规则：
若所设置的窗口宽/高尺寸小于窗口最小宽/高限值，则窗口最小宽/高限值生效；
若所设置的窗口宽/高尺寸大于窗口最大宽/高限值，则窗口最大宽/高限值生效。

全屏模式窗口不支持该操作。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                             |
| -------- | ------------------------- | ---- | ------------------------------------------------ |
| width    | number                    | 是   | 目标窗口的宽度，单位为px，该参数仅支持整数输入。 |
| height   | number                    | 是   | 目标窗口的高度，单位为px，该参数仅支持整数输入。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                       |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.resize(500, 1000, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in changing the window size.');
  });
} catch (exception) {
  console.error('Failed to change the window size. Cause:' + JSON.stringify(exception));
}
```

### resize<sup>9+</sup>

resize(width: number, height: number): Promise&lt;void&gt;

改变当前窗口大小，使用Promise异步回调。

应用主窗口与子窗口存在大小限制，默认宽度范围：[320, 2560]，默认高度范围：[240, 2560]，单位为vp。
应用主窗口与子窗口的最小宽度与最小高度可由产品端进行配置，配置后的最小宽度与最小高度以产品段配置值为准。

系统窗口存在大小限制，宽度范围：[0, 2560]，高度范围：[0, 2560]，单位为vp。

设置的宽度与高度受到此约束限制，规则：
若所设置的窗口宽/高尺寸小于窗口最小宽/高限值，则窗口最小宽/高限值生效；
若所设置的窗口宽/高尺寸大于窗口最大宽/高限值，则窗口最大宽/高限值生效。

全屏模式窗口不支持该操作。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                             |
| ------ | ------ | ---- | ------------------------------------------------ |
| width  | number | 是   | 目标窗口的宽度，单位为px，该参数仅支持整数输入。 |
| height | number | 是   | 目标窗口的高度，单位为px，该参数仅支持整数输入。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let windowClass: window.Window = window.findWindow("test");
  let promise = windowClass.resize(500, 1000);
  promise.then(() => {
    console.info('Succeeded in changing the window size.');
  }).catch((err: BusinessError) => {
    console.error('Failed to change the window size. Cause: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to change the window size. Cause: ' + JSON.stringify(exception));
}
```


### getWindowProperties<sup>9+</sup>

getWindowProperties(): WindowProperties

获取当前窗口的属性，返回WindowProperties。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                  | 说明           |
| ------------------------------------- | -------------- |
| [WindowProperties](#windowproperties) | 当前窗口属性。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  let properties = windowClass.getWindowProperties();
} catch (exception) {
  console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(exception));
}
```

### getWindowAvoidArea<sup>9+</sup>

getWindowAvoidArea(type: AvoidAreaType): AvoidArea

获取窗口内容规避的区域；如系统栏区域、刘海屏区域、手势区域、软键盘区域等与窗口内容重叠时，需要窗口内容避让的区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                             | 必填 | 说明             |
| ------ | -------------------------------- | ---- | ---------------- |
| type   | [AvoidAreaType](#avoidareatype7) | 是   | 表示规避区类型。 |

**返回值：**

| 类型                     | 说明               |
| ------------------------ | ------------------ |
| [AvoidArea](#avoidarea7) | 窗口内容规避区域。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
let type = window.AvoidAreaType.TYPE_SYSTEM;
try {
  let windowClass: window.Window = window.findWindow("test");
  let avoidArea = windowClass.getWindowAvoidArea(type);
} catch (exception) {
  console.error('Failed to obtain the area. Cause:' + JSON.stringify(exception));
}
```
### setSpecificSystemBarEnabled<sup>11+</sup>

setSpecificSystemBarEnabled(name: SpecificSystemBar, enable: boolean): Promise&lt;void&gt;

设置窗口全屏模式时导航栏、状态栏、底部导航条的显示和隐藏，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型                                      | 必填 | 说明                                                         |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| name   | [SpecificSystemBar](#specificsystembar11) | 是   | 设置窗口全屏模式时，显示或隐藏的系统栏类型。                 |
| enable | boolean                                   | 是   | 设置窗口全屏模式时状态栏、导航栏或底部导航条是否显示，true表示显示 false表示隐藏。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
// 此处以隐藏底部导航条为例
import { BusinessError } from '@ohos.base';

try {
  let windowClass: window.Window = window.findWindow("test");
  let promise = windowClass.setSpecificSystemBarEnabled('navigationIndicator', false);
  promise.then(() => {
    console.info('Succeeded in setting the system bar to be invisible.');
  }).catch((err: BusinessError) => {
    console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(exception));
}
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

设置窗口的显示方向属性，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                         | 必填 | 说明                 |
| ----------- | ---------------------------- | ---- | -------------------- |
| Orientation | [Orientation](#orientation9) | 是   | 窗口显示方向的属性。 |
| callback    | AsyncCallback&lt;void&gt;    | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let orientation = window.Orientation.AUTO_ROTATION;
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.setPreferredOrientation(orientation, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to set window orientation. Cause: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in setting window orientation.');
  });
} catch (exception) {
  console.error('Failed to set window orientation. Cause: ' + JSON.stringify(exception));
}
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation): Promise&lt;void&gt;

设置窗口的显示方向属性，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                         | 必填 | 说明                 |
| ----------- | ---------------------------- | ---- | -------------------- |
| Orientation | [Orientation](#orientation9) | 是   | 窗口显示方向的属性。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let orientation = window.Orientation.AUTO_ROTATION;
try {
  let windowClass: window.Window = window.findWindow("test");
  let promise = windowClass.setPreferredOrientation(orientation);
  promise.then(() => {
    console.info('Succeeded in setting the window orientation.');
  }).catch((err: BusinessError) => {
    console.error('Failed to set the window orientation. Cause: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to set window orientation. Cause: ' + JSON.stringify(exception));
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

根据当前工程中某个页面的路径为窗口加载具体页面内容，通过LocalStorage传递状态属性给加载的页面，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                                  | 是   | 要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。 |
| storage  | [LocalStorage](../../quick-start/arkts-localstorage.md) | 是   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |
| callback | AsyncCallback&lt;void&gt;                               | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = window.findWindow("test");
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('storageSimpleProp', 121);
    try {
      if (!windowClass) {
        console.info('Failed to load the content. Cause: windowClass is null');
      }
      else {
        (windowClass as window.Window).loadContent('pages/page2', storage, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in loading the content.');
        });
      }
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage): Promise&lt;void&gt;

根据当前工程中某个页面的路径为窗口加载具体页面内容，通过LocalStorage传递状态属性给加载的页面，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                                  | 是   | 要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。 |
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | 是   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = window.findWindow("test");
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('storageSimpleProp', 121);
    try {
      if (!windowClass) {
        console.info('Failed to load the content. Cause: windowClass is null');
      }
      else {
        let promise = (windowClass as window.Window).loadContent('pages/page2', storage);
        promise.then(() => {
          console.info('Succeeded in loading the content.');
        }).catch((err: BusinessError) => {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
        });
      }
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```

### getUIContext<sup>10+</sup>

getUIContext(): UIContext

获取UIContext实例。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                                | 说明                    |
| --------------------------------------------------- | ----------------------- |
| [UIContext](./js-apis-arkui-UIContext.md#uicontext) | 返回UIContext实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';
import { UIContext } from '@ohos.arkui.UIContext';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 为主窗口加载对应的目标页面。
    windowStage.loadContent("pages/page2", (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in loading the content.');
      // 获取应用主窗口。
      let windowClass: window.Window = window.findWindow("test");
      windowStage.getMainWindow((err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
          return;
        }
        windowClass = data;
        console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        // 获取UIContext实例。
        let uiContext: UIContext | null = null;
        uiContext = windowClass.getUIContext();
      })
    });
  }
};
```

### setUIContent<sup>9+</sup>

setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void

根据当前工程中某个页面的路径为窗口加载具体页面内容，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | 是   | 要加载到窗口中的页面内容的路径，Stage模型下该路径需添加到工程的main_pages.json文件中，FA模型下该路径需添加到工程的config.json文件中。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.setUIContent('pages/page2/page2', (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in loading the content.');
  });
} catch (exception) {
  console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
}
```

### setUIContent<sup>9+</sup>

setUIContent(path: string): Promise&lt;void&gt;

根据当前工程中某个页面的路径为窗口加载具体页面内容，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 要加载到窗口中的页面内容的路径，Stage模型下该路径需添加到工程的main_pages.json文件中，FA模型下该路径需添加到工程的config.json文件中。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let windowClass: window.Window = window.findWindow("test");
  let promise = windowClass.setUIContent('pages/page2/page2');
  promise.then(() => {
    console.info('Succeeded in loading the content.');
  }).catch((err: BusinessError) => {
    console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to load the content. Cause: ' + JSON.stringify(exception));
}
```

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

为当前窗口加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，通过LocalStorage传递状态属性给加载的页面，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name     | string                                                  | 是   | 命名路由页面的名称。                                         |
| storage  | [LocalStorage](../../quick-start/arkts-localstorage.md) | 是   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |
| callback | AsyncCallback&lt;void&gt;                               | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
// ets/entryability/EntryAbility.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';
import * as Index from '../pages/Index'; // 导入命名路由页面

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('storageSimpleProp', 121);
    try {
      if (!windowClass) {
        console.info('Failed to load the content. Cause: windowClass is null');
      } else {
        (windowClass as window.Window).loadContentByName(Index.entryName, storage, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in loading the content.');
        });
      }
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, storage : LocalStorage.getShared()})
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

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, callback: AsyncCallback&lt;void&gt;): void

为当前窗口加载[命名路由](../../ui/arkts-routing.md#命名路由)页面内容，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| name     | string                    | 是   | 命名路由页面的名称。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
// ets/entryability/EntryAbility.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';
import * as Index from '../pages/Index'; // 导入命名路由页面

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    try {
      if (!windowClass) {
        console.info('Failed to load the content. Cause: windowClass is null');
      } else {
        (windowClass as window.Window).loadContentByName(Index.entryName, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
          }
          console.info('Succeeded in loading the content.');
        });
      }
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```
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

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage?: LocalStorage): Promise&lt;void&gt;

为当前窗口加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，通过LocalStorage传递状态属性给加载的页面，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name    | string                                                  | 是   | 命名路由页面的名称。                                         |
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | 否   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
// ets/entryability/EntryAbility.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';
import * as Index from '../pages/Index'; // 导入命名路由页面

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // 获取应用主窗口
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('storageSimpleProp', 121);
    try {
      if (!windowClass) {
        console.info('Failed to load the content. Cause: windowClass is null');
      } else {
        let promise = (windowClass as window.Window).loadContentByName(Index.entryName, storage);
        promise.then(() => {
          console.info('Succeeded in loading the content.');
        }).catch((err: BusinessError) => {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
        });
      }
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, storage : LocalStorage.getShared()})
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


### isWindowShowing<sup>9+</sup>

isWindowShowing(): boolean

判断当前窗口是否已显示。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 当前窗口是否已显示。true表示当前窗口已显示，false则表示当前窗口未显示。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  let data = windowClass.isWindowShowing();
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
} catch (exception) {
  console.error('Failed to check whether the window is showing. Cause: ' + JSON.stringify(exception));
}
```

### on('windowSizeChange')<sup>7+</sup>

on(type:  'windowSizeChange', callback: Callback&lt;Size&gt;): void

开启窗口尺寸变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                     |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | 是   | 监听事件，固定为'windowSizeChange'，即窗口尺寸变化事件。 |
| callback | Callback&lt;[Size](#size7)&gt; | 是   | 回调函数。返回当前的窗口尺寸。                           |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.on('windowSizeChange', (data) => {
    console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error('Failed to enable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

### off('windowSizeChange')<sup>7+</sup>

off(type: 'windowSizeChange', callback?: Callback&lt;Size&gt;): void

关闭窗口尺寸变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                           | 必填 | 说明                                                         |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | 是   | 监听事件，固定为'windowSizeChange'，即窗口尺寸变化事件。     |
| callback | Callback&lt;[Size](#size7)&gt; | 否   | 回调函数。返回当前的窗口尺寸。如果传入参数，则关闭该监听。如果未传入参数，则关闭窗口尺寸变化的监听。 |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.off('windowSizeChange');
} catch (exception) {
  console.error('Failed to disable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

### on('avoidAreaChange')<sup>9+</sup>

on(type: 'avoidAreaChange', callback: Callback&lt;{ type: AvoidAreaType, area: AvoidArea}&gt;): void

开启系统规避区变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                      |
| -------- | ------------------------------------------------------------ | ---- | --------------------------------------------------------- |
| type     | string                                                       | 是   | 监听事件，固定为'avoidAreaChange'，即系统规避区变化事件。 |
| callback | Callback&lt;{ type: [AvoidAreaType](#avoidareatype7), area: [AvoidArea](#avoidarea7) }&gt; | 是   | 回调函数。返回当前规避区以及规避区类型。                  |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.on('avoidAreaChange', (data) => {
    console.info('Succeeded in enabling the listener for system avoid area changes. type:' +
    JSON.stringify(data.type) + ', area: ' + JSON.stringify(data.area));
  });
} catch (exception) {
  console.error('Failed to enable the listener for system avoid area changes. Cause: ' + JSON.stringify(exception));
}
```

### off('avoidAreaChange')<sup>9+</sup>

off(type: 'avoidAreaChange', callback?: Callback&lt;{ type: AvoidAreaType, area: AvoidArea }&gt;): void

关闭系统规避区变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'avoidAreaChange'，即系统规避区变化事件。    |
| callback | Callback&lt;{ type: [AvoidAreaType](#avoidareatype7), area: [AvoidArea](#avoidarea7) }&gt; | 否   | 回调函数。返回当前规避区以及规避区类型。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有系统规避区变化的监听。 |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.off('avoidAreaChange');
} catch (exception) {
  console.error('Failed to disable the listener for system avoid area changes. Cause: ' + JSON.stringify(exception));
}
```

### on('touchOutside')<sup>11+</sup>

on(type: 'touchOutside', callback: Callback&lt;void&gt;): void

开启本窗口区域范围外的点击事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                       |
| -------- | -------------------- | ---- | ---------------------------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'touchOutside'，即本窗口范围外的点击事件。 |
| callback | Callback&lt;void&gt; | 是   | 回调函数。当点击事件发生在本窗口范围之外的回调。           |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.on('touchOutside', () => {
    console.info('touch outside');
  });
} catch (exception) {
  console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));
}
```

### off('touchOutside')<sup>11+</sup>

off(type: 'touchOutside', callback?: Callback&lt;void&gt;): void

关闭本窗口区域范围外的点击事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 监听事件，固定为'touchOutside'，即本窗口范围外的点击事件。   |
| callback | Callback&lt;void&gt; | 否   | 回调函数。当点击事件发生在本窗口范围之外的回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口区域范围外的点击事件的监听。 |

**示例：**

```ts
try {
  let windowClass: window.Window = window.findWindow("test");
  windowClass.off('touchOutside');
} catch (exception) {
  console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));
}
```

### on('windowEvent')<sup>10+</sup>

on(type: 'windowEvent', callback: Callback&lt;WindowEventType&gt;): void

开启窗口生命周期变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                    |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | string                                                | 是   | 监听事件，固定为'windowEvent'，即窗口生命周期变化事件。 |
| callback | Callback&lt;[WindowEventType](#windoweventtype10)&gt; | 是   | 回调函数。返回当前的窗口生命周期状态。                  |

**示例：**

```ts
let windowClass: window.Window = window.findWindow("test");
try {
  windowClass.on('windowEvent', (data) => {
    console.info('Window event happened. Event:' + JSON.stringify(data));
  });
} catch (exception) {
  console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));
}
```

### off('windowEvent')<sup>10+</sup>

off(type: 'windowEvent', callback?: Callback&lt;WindowEventType &gt;): void

关闭窗口生命周期变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | 是   | 监听事件，固定为'windowEvent'，即窗口生命周期变化事件。      |
| callback | Callback&lt;[WindowEventType](#windoweventtype10)&gt; | 否   | 回调函数。返回当前的窗口生命周期状态。若传入参数，则关闭该监听。若未传入参数，则关闭所有窗口生命周期变化的监听。 |

**示例：**

```ts
let windowClass: window.Window = window.findWindow("test");
try {
  windowClass.off('windowEvent');
} catch (exception) {
  console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));
}
```

### setWindowBackgroundColor<sup>9+</sup>

setWindowBackgroundColor(color: string): void

设置窗口的背景色。Stage模型下，该接口需要在[loadContent()](#loadcontent9)或[setUIContent()](#setuicontent9)调用生效后使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| color  | string | 是   | 需要设置的背景色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |

**示例：**

```ts
let color: string = '#00ff33';
let windowClass: window.Window = window.findWindow("test");
try {
  windowClass.setWindowBackgroundColor(color);
} catch (exception) {
  console.error('Failed to set the background color. Cause: ' + JSON.stringify(exception));
}
```

### setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

设置屏幕亮度值，使用callback异步回调。

当前屏幕亮度规格：窗口设置屏幕亮度生效时，控制中心不可以调整系统屏幕亮度，窗口恢复默认系统亮度之后，控制中心可以调整系统屏幕亮度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明                                                         |
| ---------- | ------------------------- | ---- | ------------------------------------------------------------ |
| brightness | number                    | 是   | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。 |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let brightness: number = 1;
let windowClass: window.Window = window.findWindow("test");
try {
  windowClass.setWindowBrightness(brightness, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in setting the brightness.');
  });
} catch (exception) {
  console.error('Failed to set the brightness. Cause: ' + JSON.stringify(exception));
}
```

### setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number): Promise&lt;void&gt;

设置屏幕亮度值，使用Promise异步回调。

当前屏幕亮度规格：窗口设置屏幕亮度生效时，控制中心不可以调整系统屏幕亮度，窗口恢复默认系统亮度之后，控制中心可以调整系统屏幕亮度。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                                         |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| brightness | number | 是   | 屏幕亮度值。该参数为浮点数，取值范围为[0.0, 1.0]或-1.0。1.0表示最亮，-1.0表示默认亮度。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let brightness: number = 1;
let windowClass: window.Window = window.findWindow("test");
try {
  let promise = windowClass.setWindowBrightness(brightness);
  promise.then(() => {
    console.info('Succeeded in setting the brightness.');
  }).catch((err: BusinessError) => {
    console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to set the brightness. Cause: ' + JSON.stringify(exception));
}
```

### setWindowKeepScreenOn<sup>9+</sup>

setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

设置屏幕是否为常亮状态，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型                      | 必填 | 说明                                                    |
| -------------- | ------------------------- | ---- | ------------------------------------------------------- |
| isKeepScreenOn | boolean                   | 是   | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。 |
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                              |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let isKeepScreenOn: boolean = true;
let windowClass: window.Window = window.findWindow("test");
try {
  windowClass.setWindowKeepScreenOn(isKeepScreenOn, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in setting the screen to be always on.');
  });
} catch (exception) {
  console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(exception));
}
```

### setWindowKeepScreenOn<sup>9+</sup>

setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt;

设置屏幕是否为常亮状态，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型    | 必填 | 说明                                                    |
| -------------- | ------- | ---- | ------------------------------------------------------- |
| isKeepScreenOn | boolean | 是   | 设置屏幕是否为常亮状态。true表示常亮；false表示不常亮。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let isKeepScreenOn: boolean = true;
let windowClass: window.Window = window.findWindow("test");
try {
  let promise = windowClass.setWindowKeepScreenOn(isKeepScreenOn);
  promise.then(() => {
    console.info('Succeeded in setting the screen to be always on.');
  }).catch((err: BusinessError) => {
    console.info('Failed to set the screen to be always on. Cause:  ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(exception));
}
```

## WindowStageEventType<sup>9+</sup>

WindowStage生命周期。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                  | 值   | 说明                                                         |
| --------------------- | ---- | ------------------------------------------------------------ |
| SHOWN                 | 1    | 切到前台。                                                   |
| ACTIVE                | 2    | 获焦状态。                                                   |
| INACTIVE              | 3    | 失焦状态。                                                   |
| HIDDEN                | 4    | 切到后台。                                                   |
| RESUMED<sup>11+</sup> | 5    | 前台可交互状态。前台应用进入多任务为不可交互状态，继续返回前台时恢复可交互状态。 |
| PAUSED<sup>11+</sup>  | 6    | 前台不可交互状态。前台应用进入多任务为不可交互状态，继续返回前台时恢复可交互状态。 |

## WindowStage<sup>9+</sup>

窗口管理器。管理各个基本窗口单元，即[Window](#window)实例。

下列API示例中都需在[onWindowStageCreate()](js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate)函数中使用WindowStage的实例调用对应方法。


### getMainWindow<sup>9+</sup>

getMainWindow(callback: AsyncCallback&lt;Window&gt;): void

获取该WindowStage实例下的主窗口，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                          |
| -------- | -------------------------------------- | ---- | --------------------------------------------- |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前WindowStage下的主窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
        return;
      }
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
    });
  }
};
```

### getMainWindow<sup>9+</sup>

getMainWindow(): Promise&lt;Window&gt;

获取该WindowStage实例下的主窗口，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](#window)&gt; | Promise对象。返回当前WindowStage下的主窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    let promise = windowStage.getMainWindow();
    promise.then((data) => {
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
    });
  }
};
```

### getMainWindowSync<sup>9+</sup>

getMainWindowSync(): Window

获取该WindowStage实例下的主窗口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型              | 说明                                |
| ----------------- | ----------------------------------- |
| [Window](#window) | 返回当前WindowStage下的主窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      let windowClass = windowStage.getMainWindowSync();
    } catch (exception) {
      console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(exception));
    }
  }
};
```

### createSubWindow<sup>9+</sup>

createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void

创建该WindowStage实例下的子窗口，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                          |
| -------- | -------------------------------------- | ---- | --------------------------------------------- |
| name     | string                                 | 是   | 子窗口的名字。                                |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前WindowStage下的子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      windowStage.createSubWindow('mySubWindow', (err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
          return;
        }
        windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        if (!windowClass) {
          console.info('Failed to load the content. Cause: windowClass is null');
        }
        else {
          (windowClass as window.Window).resize(500, 1000);
        }
      });

    } catch (exception) {
      console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(exception));
    }
  }
};
```
### createSubWindow<sup>9+</sup>

createSubWindow(name: string): Promise&lt;Window&gt;

创建该WindowStage实例下的子窗口，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| name   | string | 是   | 子窗口的名字。 |

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](#window)&gt; | Promise对象。返回当前WindowStage下的子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      let promise = windowStage.createSubWindow('mySubWindow');
      promise.then((data) => {
        windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
      });
    } catch (exception) {
      console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(exception));
    }
  }
};
```

### getSubWindow<sup>9+</sup>

getSubWindow(callback: AsyncCallback&lt;Array&lt;Window&gt;&gt;): void

获取该WindowStage实例下的所有子窗口，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                              |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Window](#window)&gt;&gt; | 是   | 回调函数。返回当前WindowStage下的所有子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window[] = [];
    windowStage.getSubWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));
        return;
      }
      windowClass = data;
      console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
    });
  }
};
```
### getSubWindow<sup>9+</sup>

getSubWindow(): Promise&lt;Array&lt;Window&gt;&gt;

获取该WindowStage实例下的所有子窗口，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                          | 说明                                                 |
| --------------------------------------------- | ---------------------------------------------------- |
| Promise&lt;Array&lt;[Window](#window)&gt;&gt; | Promise对象。返回当前WindowStage下的所有子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window[] = [];
    let promise = windowStage.getSubWindow();
    promise.then((data) => {
      windowClass = data;
      console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));
    })
  }
};
```
### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

为当前WindowStage的主窗口加载具体页面内容，通过LocalStorage传递状态属性给加载的页面，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                                  | 是   | 要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。 |
| storage  | [LocalStorage](../../quick-start/arkts-localstorage.md) | 是   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |
| callback | AsyncCallback&lt;void&gt;                               | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    this.storage.setOrCreate('storageSimpleProp', 121);
    console.log('onWindowStageCreate');
    try {
      windowStage.loadContent('pages/page2', this.storage, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage?: LocalStorage): Promise&lt;void&gt;

为当前WindowStage的主窗口加载具体页面内容，通过LocalStorage传递状态属性给加载的页面，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                                  | 是   | 要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。 |
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | 否   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    this.storage.setOrCreate('storageSimpleProp', 121);
    console.log('onWindowStageCreate');
    try {
      let promise = windowStage.loadContent('pages/page2', this.storage);
      promise.then(() => {
        console.info('Succeeded in loading the content.');
      }).catch((err: BusinessError) => {
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));
      });
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
    ;
  }
};
```

### loadContent<sup>9+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

为当前WindowStage的主窗口加载具体页面内容，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | 是   | 要加载到窗口中的页面内容的路径，该路径需添加到工程的main_pages.json文件中。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.loadContent('pages/page2', (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

为当前WindowStage加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，通过LocalStorage传递状态属性给加载的页面，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name     | string                                                  | 是   | 命名路由页面的名称。                                         |
| storage  | [LocalStorage](../../quick-start/arkts-localstorage.md) | 是   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |
| callback | AsyncCallback&lt;void&gt;                               | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
// ets/entryability/EntryAbility.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';
import * as Index from '../pages/Index'; // 导入命名路由页面

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    this.storage.setOrCreate('storageSimpleProp', 121);
    try {
      windowStage.loadContentByName(Index.entryName, this.storage, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, storage : LocalStorage.getShared()})
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

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, callback: AsyncCallback&lt;void&gt;): void

为当前WindowStage加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| name     | string                    | 是   | 命名路由页面的名称。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
// ets/entryability/EntryAbility.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';
import * as Index from '../pages/Index'; // 导入命名路由页面

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.loadContentByName(Index.entryName, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error('Failed to load the content. Cause:' + JSON.stringify(err));
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```
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

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage?: LocalStorage): Promise&lt;void&gt;;

为当前WindowStage加载[命名路由](../../ui/arkts-routing.md#命名路由)页面，通过LocalStorage传递状态属性给加载的页面，使用promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型         | 必填 | 说明                                                         |
| ------- | ------------ | ---- | ------------------------------------------------------------ |
| name    | string       | 是   | 命名路由页面的名称。                                         |
| storage | LocalStorage | 否   | 页面级UI状态存储单元，这里用于为加载到窗口的页面内容传递状态属性。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
// ets/entryability/EntryAbility.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';
import * as Index from '../pages/Index'; // 导入命名路由页面

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    this.storage.setOrCreate('storageSimpleProp', 121);
    try {
      let promise = windowStage.loadContentByName(Index.entryName, this.storage);
      promise.then(() => {
        console.info('Succeeded in loading the content.');
      }).catch((err: BusinessError) => {
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));
      });
    } catch (exception) {
      console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
    }
  }
};
```
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, storage : LocalStorage.getShared()})
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

### on('windowStageEvent')<sup>9+</sup>

on(eventType: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void

开启WindowStage生命周期变化的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'windowStageEvent'，即WindowStage生命周期变化事件。 |
| callback | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | 是   | 回调函数。返回当前的WindowStage生命周期状态。                |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.on('windowStageEvent', (data) => {
        console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
        JSON.stringify(data));
      });
    } catch (exception) {
      console.error('Failed to enable the listener for window stage event changes. Cause:' +
      JSON.stringify(exception));
    }
  }
};
```

### off('windowStageEvent')<sup>9+</sup>

off(eventType: 'windowStageEvent', callback?: Callback&lt;WindowStageEventType&gt;): void

关闭WindowStage生命周期变化的监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 监听事件，固定为'windowStageEvent'，即WindowStage生命周期变化事件。 |
| callback | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | 否   | 回调函数。返回当前的WindowStage生命周期状态。若传入参数，则关闭该监听。若未传入参数，则关闭所有WindowStage生命周期变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](../errorcodes/errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 1300002  | This window state is abnormal. |
| 1300005  | This window stage is abnormal. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.off('windowStageEvent');
    } catch (exception) {
      console.error('Failed to disable the listener for window stage event changes. Cause:' +
      JSON.stringify(exception));
    }
  }
};
```