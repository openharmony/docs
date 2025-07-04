# @ohos.window (窗口)(系统接口)

窗口提供管理窗口的一些基础能力，包括对当前窗口的创建、销毁、各属性设置，以及对各窗口间的管理调度。

该模块提供以下窗口相关的常用功能：

- [Window](arkts-apis-window-Window.md)：当前窗口实例，窗口管理器管理的基本单元。
- [WindowStage](#windowstage9)：窗口管理器。管理各个基本窗口单元。

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.window (窗口)](arkts-apis-window.md)。

## 导入模块

```ts
import { window } from '@kit.ArkUI';
```

## WindowType<sup>7+</sup>


窗口类型枚举。


| 名称                                  | 值 | 说明                                                                                     |
|-------------------------------------| ------ |----------------------------------------------------------------------------------------|
| TYPE_INPUT_METHOD<sup>(deprecated)</sup>      | 2      | 表示输入法窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**说明：** 从API version 9开始支持，从API version 13开始废弃，无替代窗口类型，输入法相关控制都请调用[输入法框架侧接口](../../inputmethod/inputmethod-application-guide.md)执行。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_STATUS_BAR<sup>9+</sup>        | 3      | 表示状态栏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_PANEL<sup>9+</sup>             | 4      | 表示通知栏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_KEYGUARD<sup>9+</sup>          | 5      | 表示锁屏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_VOLUME_OVERLAY<sup>9+</sup>    | 6      | 表示音量条。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_NAVIGATION_BAR<sup>9+</sup>    | 7      | 表示导航栏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_WALLPAPER<sup>9+</sup>         | 9      | 表示壁纸。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_DESKTOP<sup>9+</sup>           | 10      | 表示桌面。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_LAUNCHER_RECENT<sup>9+</sup>   | 11      | 表示多任务中心。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_LAUNCHER_DOCK<sup>9+</sup>     | 12      | 表示桌面Dock栏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_VOICE_INTERACTION<sup>9+</sup> | 13      | 表示智慧语音。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_POINTER<sup>9+</sup>           | 14      | 表示鼠标。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_FLOAT_CAMERA<sup>9+</sup>      | 15      | 表示相机类型悬浮窗。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_SCREENSHOT<sup>9+</sup>        | 17      | 表示截屏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_SYSTEM_TOAST<sup>11+</sup>     | 18      | 表示顶层提示窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_DIVIDER<sup>11+</sup>          | 19      | 表示分屏条。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_GLOBAL_SEARCH<sup>11+</sup>    | 20      | 表示全局搜索窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_HANDWRITE<sup>12+</sup>        | 21      | 表示手写笔窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_WALLET_SWIPE_CARD<sup>15+</sup>| 22      | 表示钱包刷卡窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_SCREEN_CONTROL<sup>15+</sup>   | 23      | 表示锁定触控的顶层窗口，用于拦截屏幕触摸和点击事件。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_FLOAT_NAVIGATION<sup>17+</sup> | 24      | 表示悬浮的三键导航窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_DYNAMIC<sup>20+</sup> | 25      | 表示可设置窗口层级的系统窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_MUTISCREEN_COLLABORATION<sup>20+</sup> | 26      | 表示多屏协同窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |

## Configuration<sup>9+</sup>

创建子窗口或系统窗口时的参数。

| 名称 | 类型 | 必填 | 说明                       |
| ---------- | --------- | ---- | -------------- |
| zIndex<sup>20+</sup>       | number | 否 | 当前系统窗口的层级，仅在[WindowType](#windowtype7)为TYPE_DYNAMIC时生效。<br>**系统能力：** SystemCapability.Window.SessionManager |

## WindowMode<sup>7+</sup>

窗口模式枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| UNDEFINED  | 1    | 表示APP未定义窗口模式。       |
| FULLSCREEN | 2    | 表示APP全屏模式。             |
| PRIMARY    | 3    | 表示APP分屏多窗口主要模式。   |
| SECONDARY  | 4    | 表示APP分屏多窗口次要模式。   |
| FLOATING   | 5    | 表示APP自由悬浮形式窗口模式。 |

## WindowLayoutMode<sup>9+</sup>

窗口布局模式枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| WINDOW_LAYOUT_MODE_CASCADE  | 0    | 表示使用层叠布局模式。       |
| WINDOW_LAYOUT_MODE_TILE | 1    | 表示使用平铺布局模式。             |


## BlurStyle<sup>9+</sup>

窗口模糊类型枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称    | 值   | 说明                 |
| ------- | ---- | -------------------- |
| OFF     | 0    | 表示关闭模糊。       |
| THIN    | 1    | 表示较薄的模糊类型。 |
| REGULAR | 2    | 表示适中的模糊类型。 |
| THICK   | 3    | 表示较厚的模糊类型。 |

## AnimationType<sup>20+</sup>

窗口动画类型枚举。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称    | 值   | 说明                       |
| ------- | ---- | -------------------------- |
| FADE_IN | 1    | 表示窗口动画类型为淡入。淡入动画在窗口显示过程中生效。 |

## SystemBarRegionTint<sup>8+</sup>

单个导航栏或状态栏回调信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称            | 类型                  | 可读 | 可写 | 说明                                                         |
| --------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type            | [WindowType](#windowtype7) | 是   | 否   | 当前属性改变的系统栏类型，仅支持类型为导航栏、状态栏的系统栏。 |
| isEnable        | boolean                   | 是   | 否   | 当前系统栏是否显示。true表示显示；false表示不显示。 |
| region          | [Rect](arkts-apis-window-i.md#rect7)             | 是   | 否   | 当前系统栏的位置及大小。                                     |
| backgroundColor | string                    | 是   | 否   | 系统栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |
| contentColor    | string                    | 是   | 否   | 系统栏文字颜色。                                             |

## SystemBarTintState<sup>8+</sup>

当前系统栏回调信息集合。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 类型                                            | 可读 | 可写 | 说明                         |
| ---------- | --------------------------------------------------- | ---- | ---- | ---------------------------- |
| displayId  | number                                              | 是   | 否   | 当前物理屏幕id，该参数应为整数。             |
| regionTint | Array<[SystemBarRegionTint](#systembarregiontint8)> | 是   | 否   | 当前已改变的所有系统栏信息。 |

## ScaleOptions<sup>9+</sup>

缩放参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 只读 | 必填 | 说明                                         |
| ------ | -------- | ---- | ---- | --------------------------------------------|
| x      | number   | 否   | 否   | X轴的缩放参数。该参数为浮点数，默认值为1.0。                   |
| y      | number   | 否   | 否   | Y轴的缩放参数。该参数为浮点数，默认值为1.0。                   |
| pivotX | number   | 否   | 否   | 缩放中心点X轴坐标。该参数为浮点数，默认值为0.5， 取值范围[0.0, 1.0]。 |
| pivotY | number   | 否   | 否   | 缩放中心点Y轴坐标。该参数为浮点数，默认值为0.5， 取值范围[0.0, 1.0]。 |

## RotateOptions<sup>9+</sup>

旋转参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 只读 | 可选 | 说明                                          |
| ------ | -------- | ---- |---- |---------------------------------------------|
| x      | number   | 否   | 是  | 绕X轴的旋转角度。该参数为浮点数，默认值为0.0。                   |
| y      | number   | 否   | 是  | 绕Y轴的旋转角度。该参数为浮点数，默认值为0.0。                   |
| z      | number   | 否   | 是  | 绕Z轴的旋转角度。该参数为浮点数，默认值为0.0。                   |
| pivotX | number   | 否   | 是  | 旋转中心点X轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。 |
| pivotY | number   | 否   | 是  | 旋转中心点Y轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。  |

## TranslateOptions<sup>9+</sup>

平移参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型 | 只读 | 可选 | 说明                         |
| ---- | -------- | ---- | ---- | ---------------------------- |
| x    | number   | 否   | 是  | X轴的平移参数。该参数为浮点数，默认值为0.0，单位为px。 |
| y    | number   | 否   | 是  | Y轴的平移参数。该参数为浮点数，默认值为0.0，单位为px。 |
| z    | number   | 否   | 是  | Z轴的平移参数。该参数为浮点数，默认值为0.0，单位为px。 |


## StartAnimationSystemParams<sup>20+</sup>

启动动画配置。

不同应用间跳转场景不生效，仍保持系统默认动效。

仅在手机设备或平板设备的非自由多窗模式下生效。

仅对全屏应用生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type             | [AnimationType](#animationtype20)                 | 否   | 否   | 窗口动画类型。|
| animationConfig  | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20) | 否   | 是   | 窗口动画参数配置。默认动画曲线为WindowAnimationCurve.LINEAR，duration为0。          |

## WindowCreateParams<sup>20+</sup>

应用启动时的窗口参数配置。

**系统能力：** SystemCapability.Window.SessionManager
| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| systemAnimationsParams             | [StartAnimationSystemParams](#startanimationsystemparams20)                 | 否   | 是   | 启动动画参数配置。默认值为undefined，若不配置将保持系统默认动效。|

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number, callback: AsyncCallback&lt;void&gt;): void

最小化某显示设备下的所有窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | 是   | 显示设备[Display](js-apis-display.md#display)的ID号，该参数仅支持整数输入。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();

try {
  window.minimizeAll(displayClass.id, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to minimize all windows. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in minimizing all windows.');
  });
} catch (exception) {
  console.error(`Failed to minimize all windows. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number): Promise&lt;void&gt;

最小化某显示设备下的所有窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | 是   | 显示设备[Display](js-apis-display.md#display)的ID号，该参数仅支持整数输入。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();

try {
  let promise = window.minimizeAll(displayClass.id);
  promise.then(() => {
    console.info('Succeeded in minimizing all windows.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to minimize all windows. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to minimize all windows. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.toggleShownStateForAllAppWindows<sup>9+</sup>
toggleShownStateForAllAppWindows(callback: AsyncCallback&lt;void&gt;): void

多窗口快速切换时隐藏或者恢复应用窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。     |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

window.toggleShownStateForAllAppWindows((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to toggle shown state for all app windows. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in toggling shown state for all app windows.');
});
```

## window.toggleShownStateForAllAppWindows<sup>9+</sup>
toggleShownStateForAllAppWindows(): Promise&lt;void&gt;

多窗口快速切换时隐藏或者恢复应用窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = window.toggleShownStateForAllAppWindows();
promise.then(() => {
  console.info('Succeeded in toggling shown state for all app windows.');
}).catch((err: BusinessError) => {
  console.error(`Failed to toggle shown state for all app windows. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.setWindowLayoutMode<sup>9+</sup>
setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback&lt;void&gt;): void

设置窗口布局模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmode9)                  | 是   | 设置的窗口布局模式。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set window layout mode. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting window layout mode.');
  });
} catch (exception) {
  console.error(`Failed to set window layout mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setWindowLayoutMode<sup>9+</sup>
setWindowLayoutMode(mode: WindowLayoutMode): Promise&lt;void&gt;

设置窗口布局模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmode9)                    | 是   | 设置的窗口布局模式。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE);
  promise.then(() => {
    console.info('Succeeded in setting window layout mode.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window layout mode. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set window layout mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.on('systemBarTintChange')<sup>8+</sup>

on(type: 'systemBarTintChange', callback: Callback&lt;SystemBarTintState&gt;): void

开启状态栏、导航栏属性变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | 是   | 监听事件，固定为'systemBarTintChange'，即导航栏、状态栏属性变化事件。 |
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | 是   | 回调函数。返回当前的状态栏、导航栏信息集合。                 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.               |

**示例：**

```ts
try {
  window.on('systemBarTintChange', (data) => {
    console.info('Succeeded in enabling the listener for systemBarTint changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for systemBarTint changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.off('systemBarTintChange')<sup>8+</sup>

off(type: 'systemBarTintChange', callback?: Callback&lt;SystemBarTintState &gt;): void

关闭状态栏、导航栏属性变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | 是   | 监听事件，固定为'systemBarTintChange'，即导航栏、状态栏属性变化事件。 |
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | 否   | 回调函数。返回当前的状态栏、导航栏信息集合。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有状态栏、导航栏属性变化的监听。                |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed.              |

**示例：**

```ts
const callback = (systemBarTintState: window.SystemBarTintState) => {
  // ...
}
try {
  window.on('systemBarTintChange', callback);

  window.off('systemBarTintChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  window.off('systemBarTintChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for systemBarTint changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.on('gestureNavigationEnabledChange')<sup>10+</sup>

on(type: 'gestureNavigationEnabledChange', callback: Callback&lt;boolean&gt;): void

添加手势导航启用状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                                          |
| -------- | ----------------------- | ---- | ----------------------------------------------------------------------------- |
| type     | string                  | 是   | 监听事件，固定为'gestureNavigationEnabledChange'，即手势导航启用状态变化事件。    |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。返回当前手势导航的启用状态。true表示手势导航状态变化为启用；false表示手势导航状态变化为禁用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  window.on('gestureNavigationEnabledChange', (data) => {
    console.info(`Succeeded in enabling the listener for gesture navigation status changes. Data: ${data}`);
  });
} catch (exception) {
  console.error(`Failed to enable the listener for gesture navigation status changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.off('gestureNavigationEnabledChange')<sup>10+</sup>

off(type: 'gestureNavigationEnabledChange', callback?: Callback&lt;boolean&gt;): void

移除手势导航启用状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                        |
| -------- | ----------------------- | -- | ------------------------------------------------------------ |
| type     | string                  | 是 | 监听事件，固定为'gestureNavigationEnabledChange'，即手势导航启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 否 | 已注册的回调函数。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有手势导航启用状态变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (bool: boolean) => {
  // ...
}
try {
  window.on('gestureNavigationEnabledChange', callback);
  window.off('gestureNavigationEnabledChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  window.off('gestureNavigationEnabledChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for gesture navigation status changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.on('waterMarkFlagChange')<sup>10+</sup>

on(type: 'waterMarkFlagChange', callback: Callback&lt;boolean&gt;): void

添加水印启用状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                                          |
| -------- | ----------------------- | ---- | ----------------------------------------------------------------------------- |
| type     | string                  | 是   | 监听事件，固定为'waterMarkFlagChange'，即水印启用状态变化事件。    |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。返回当前水印的启用状态。true表示当前已启用水印；false表示当前未启用水印。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
try {
  window.on('waterMarkFlagChange', (data) => {
    console.info(`Succeeded in enabling the listener for watermark flag changes. Data: ${data}`);
  });
} catch (exception) {
  console.error(`Failed to enable the listener for watermark flag changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.off('waterMarkFlagChange')<sup>10+</sup>

off(type: 'waterMarkFlagChange', callback?: Callback&lt;boolean&gt;): void

移除水印启用状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                        |
| -------- | ----------------------- | -- | ------------------------------------------------------------ |
| type     | string                  | 是 | 监听事件，固定为'waterMarkFlagChange'，即水印启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 否 | 已注册的回调函数。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有水印启用状态变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (bool: boolean) => {
  // ...
}
try {
  window.on('waterMarkFlagChange', callback);
  window.off('waterMarkFlagChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  window.off('waterMarkFlagChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for watermark flag changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setGestureNavigationEnabled<sup>10+</sup>
setGestureNavigationEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置手势导航启用状态。使用callback异步回调。系统出于安全的考虑，不会干预手势的禁用和恢复。应用调用本接口禁用手势后异常退出的情况下，如果想要恢复手势，需自行实现自动拉起机制并再次调用本接口恢复手势。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| enable   | boolean                  | 是   | 设置手势导航启用状态。true表示启用手势导航；false表示禁用手势导航。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  window.setGestureNavigationEnabled(true, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set gesture navigation enabled. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting gesture navigation enabled.');
  });
} catch (exception) {
  console.error(`Failed to set gesture navigation enabled. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setGestureNavigationEnabled<sup>10+</sup>
setGestureNavigationEnabled(enable: boolean): Promise&lt;void&gt;

设置手势导航启用状态。使用Promise异步回调。系统出于安全的考虑，不会干预手势的禁用和恢复。应用调用本接口禁用手势后异常退出的情况下，如果想要恢复手势，需自行实现自动拉起机制并再次调用本接口恢复手势。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型     | 必填  | 说明                 |
| ------ | ------- | ---- | -------------------- |
| enable | boolean | 是   | 设置手势导航启用状态。true表示启用手势导航；false表示禁用手势导航。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = window.setGestureNavigationEnabled(true);
  promise.then(() => {
    console.info('Succeeded in setting gesture navigation enabled.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set gesture navigation enabled. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set gesture navigation enabled. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setWaterMarkImage<sup>10+</sup>
setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置水印图片显示状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是 | 水印图片。可通过[createPixelMap](../apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8)接口获取。|
| enable   | boolean                  | 是   | 设置是否显示水印图片。true显示水印图片；false表示不显示水印图片。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;
let color: ArrayBuffer = new ArrayBuffer(0);
let initializationOptions: image.InitializationOptions = {
  size: {
    height: 100,
    width: 100
  }
};
image.createPixelMap(color, initializationOptions).then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelmap.');
  try {
    window.setWaterMarkImage(pixelMap, enable, (err: BusinessError) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to show watermark image. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in showing watermark image.');
    });
  } catch (exception) {
    console.error(`Failed to show watermark image. Cause code: ${exception.code}, message: ${exception.message}`);
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to create PixelMap. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.setWaterMarkImage<sup>10+</sup>
setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean): Promise&lt;void&gt;

设置水印图片显示状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                        | 必填  | 说明                 |
| ------ | --------------------------- | ---- | -------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是 | 水印图片。可通过[createPixelMap](../apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8)接口获取。|
| enable   | boolean                  | 是   | 设置是否显示水印图片。true显示水印图片；false表示不显示水印图片。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;
let color: ArrayBuffer = new ArrayBuffer(0);
let initializationOptions: image.InitializationOptions = {
  size: {
    height: 100,
    width: 100
  }
};
image.createPixelMap(color, initializationOptions).then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelmap.');
  try {
    let promise = window.setWaterMarkImage(pixelMap, enable);
    promise.then(() => {
      console.info('Succeeded in showing watermark image.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to show watermark image. Cause code: ${err.code}, message: ${err.message}`);
    });
  } catch (exception) {
    console.error(`Failed to show watermark image. Cause code: ${exception.code}, message: ${exception.message}`);
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to create PixelMap. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.getSnapshot<sup>12+</sup>

getSnapshot(windowId: number): Promise<image.PixelMap>

获取指定窗口相同尺寸截图，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**
| 参数名   | 类型   | 必填  | 说明         |
| -------- | ------ | ----- | ------------ |
| windowId | number | 是    | 窗口Id。可通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到相关窗口属性，其中属性id即对应为窗口ID。 |

**返回值：**
| 类型                    | 说明                            |
| ----------------------- | ------------------------------- |
| Promise<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)> | Promise对象。返回指定窗口截图。 |

**错误码：**
以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |
| 1300004  | This operation is not accessible.             |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

try {
  // 此处仅示意，请使用getWindowProperties获取对应窗口ID再进行使用
  let windowId: number = 40;
  let promise = window.getSnapshot(windowId);
  promise.then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in getting snapshot window. Pixel bytes number:' + pixelMap.getPixelBytesNumber());
    pixelMap.release();
  }).catch((err: BusinessError) =>{
    console.error(`Failed to get snapshot. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to get snapshot. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.notifyScreenshotEvent<sup>20+</sup>

notifyScreenshotEvent(eventType: ScreenshotEventType): Promise&lt;void&gt;

通知屏幕截屏的事件类型，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型   | 必填  | 说明         |
| -------- | ------ | ----- | ------------ |
| eventType | [ScreenshotEventType](arkts-apis-window-e.md#screenshoteventtype20) | 是    | 截屏事件类型。 |

**返回值：**

| 类型                    | 说明                            |
| ----------------------- | ------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300003  | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let eventType: window.ScreenshotEventType = window.ScreenshotEventType.SYSTEM_SCREENSHOT;
  let promise = window.notifyScreenshotEvent(eventType);
  promise.then(() => {
    console.info(`Succeeded in notifying screenshot event type.`);
  }).catch((err: BusinessError) =>{
    console.error(`Failed to notify screenshot event type. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to notify screenshot event type. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getTopNavDestinationName<sup>20+</sup>

getTopNavDestinationName(windowId: number): Promise&lt;string&gt;

获取指定的前台窗口当前栈顶[Navigation](arkui-ts/ts-basic-components-navigation.md)中的[NavDestination](arkui-ts/ts-basic-components-navdestination.md)名称，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                        |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| windowId   | number| 是  | 窗口Id，用于指定要查询的窗口。该参数应为大于0的整数，小于等于0时会返回错误码1300016，如果指定的窗口不存在或生命周期不在前台，返回错误码为1300002。|

**返回值：**

| 类型                             | 说明                      |
| -------------------------------- |-------------------------|
| Promise&lt;string&gt; | Promise对象。返回获取到的[NavDestination](arkui-ts/ts-basic-components-navdestination.md)名称。<br>对于[Navigation](arkui-ts/ts-basic-components-navigation.md)嵌套以及当前页面存在多个[Navigation](arkui-ts/ts-basic-components-navigation.md)的场景，查询的是后创建的[Navigation](arkui-ts/ts-basic-components-navigation.md)的信息。<br>如果页面没有[Navigation](arkui-ts/ts-basic-components-navigation.md)或者[Navigation](arkui-ts/ts-basic-components-navigation.md)中没有[NavDestination](arkui-ts/ts-basic-components-navdestination.md)，返回空字符串。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID    | 错误信息 |
|----------| ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**
```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowId = 10;
  let promise = window.getTopNavDestinationName(windowId);
  promise.then((data) => {
    console.info(`Succeeded, data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed, cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed, exception code: ${exception.code}, message: ${exception.message}`);
}
```

## Window

当前窗口实例，窗口管理器管理的基本单元。

下列API示例中都需先使用[getLastWindow()](arkts-apis-window-f.md#windowgetlastwindow9)、[createWindow()](arkts-apis-window-f.md#windowcreatewindow9)、[findWindow()](arkts-apis-window-f.md#windowfindwindow9)中的任一方法获取到Window实例（windowClass），再通过此实例调用对应方法。

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

隐藏当前窗口，使用callback异步回调，仅支持系统窗口与应用子窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.hide((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to hide the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in hiding the window.');
});
```

### hide<sup>7+</sup>

hide(): Promise&lt;void&gt;

隐藏当前窗口，使用Promise异步回调，仅支持系统窗口与应用子窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### hideWithAnimation<sup>9+</sup>

hideWithAnimation(callback: AsyncCallback&lt;void&gt;): void

隐藏当前窗口，过程中播放动画，使用callback异步回调，仅支持系统窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.hideWithAnimation((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to hide the window with animation. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in hiding the window with animation.');
});
```

### hideWithAnimation<sup>9+</sup>

hideWithAnimation(): Promise&lt;void&gt;

隐藏当前窗口，过程中播放动画，使用Promise异步回调，仅支持系统窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.hideWithAnimation();
promise.then(() => {
  console.info('Succeeded in hiding the window with animation.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide the window with animation. Cause code: ${err.code}, message: ${err.message}`);
});
```

### showWithAnimation<sup>9+</sup>

showWithAnimation(callback: AsyncCallback&lt;void&gt;): void

显示当前窗口，过程中播放动画，使用callback异步回调，仅支持系统窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.showWithAnimation((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to show the window with animation. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in showing the window with animation.');
});
```

### showWithAnimation<sup>9+</sup>

showWithAnimation(): Promise&lt;void&gt;

显示当前窗口，过程中播放动画，使用Promise异步回调，仅支持系统窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.showWithAnimation();
promise.then(() => {
  console.info('Succeeded in showing the window with animation.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show the window with animation. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setWindowMode<sup>9+</sup>

setWindowMode(mode: WindowMode, callback: AsyncCallback&lt;void&gt;): void

设置主窗口模式，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------------------------- | -- | --------- |
| mode     | [WindowMode](#windowmode7) | 是 | 窗口模式。 |
| callback | AsyncCallback&lt;void&gt;  | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
      let mode = window.WindowMode.FULLSCREEN;
      try {
        windowClass.setWindowMode(mode, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the window mode. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the window mode.');
        });
      } catch (exception) {
        console.error(`Failed to set the window mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setWindowMode<sup>9+</sup>

setWindowMode(mode: WindowMode): Promise&lt;void&gt;

设置主窗口模式，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------------------------- | -- | --------- |
| mode     | [WindowMode](#windowmode7) | 是 | 窗口模式。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
      let mode = window.WindowMode.FULLSCREEN;
      try {
        let promise = windowClass.setWindowMode(mode);
        promise.then(() => {
          console.info('Succeeded in setting the window mode.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window mode. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the window mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback&lt;void&gt;, callback: AsyncCallback&lt;void&gt;): void

绑定模态窗口与目标窗口并添加模态窗口销毁监听，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| token       | [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) | 是   | 目标窗口token值。 |
| deathCallback | Callback&lt;void&gt;        | 是   | 模态窗口销毁监听。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyDeathRecipient {
  onRemoteDied() {
    console.log('server died');
  }
}

class TestRemoteObject extends rpc.RemoteObject {
  constructor(descriptor: string) {
    super(descriptor);
  }

  addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
    return true;
  }

  removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
    return true;
  }

  isObjectDead(): boolean {
    return false;
  }
}

let token: TestRemoteObject = new TestRemoteObject('testObject');
let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = { name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context };
try {
  window.createWindow(config, (err: BusinessError, data) => {
    let errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    windowClass = data;
  });
  windowClass.bindDialogTarget(token, () => {
    console.info('Dialog Window Need Destroy.');
  }, (err: BusinessError) => {
    let errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in binding dialog target.');
  });
} catch (exception) {
  console.error(`Failed to bind dialog target. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback&lt;void&gt;): Promise&lt;void&gt;

绑定模态窗口与目标窗口并添加模态窗口销毁监听，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| token       | [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) | 是   | 目标窗口token值。 |
| deathCallback | Callback&lt;void&gt;        | 是   | 模态窗口销毁监听。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyDeathRecipient {
  onRemoteDied() {
    console.log('server died');
  }
}

class TestRemoteObject extends rpc.RemoteObject {
  constructor(descriptor: string) {
    super(descriptor);
  }

  addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
    return true;
  }

  removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
    return true;
  }

  isObjectDead(): boolean {
    return false;
  }
}

let token: TestRemoteObject = new TestRemoteObject('testObject');
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
  });
  let promise = windowClass.bindDialogTarget(token, () => {
    console.info('Dialog Window Need Destroy.');
  });
  promise.then(() => {
    console.info('Succeeded in binding dialog target.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to bind dialog target. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback&lt;void&gt;, callback: AsyncCallback&lt;void&gt;): void

绑定模态窗口与目标窗口并添加模态窗口销毁监听，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| requestInfo | [dialogRequest.RequestInfo](../apis-ability-kit/js-apis-app-ability-dialogRequest.md#requestinfo) | 是   | 目标窗口RequestInfo值。 |
| deathCallback | Callback&lt;void&gt;    | 是   | 模态窗口销毁监听。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { dialogRequest, Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ServiceExtAbility extends ServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest');
    let windowClass: window.Window | undefined = undefined;
    let config: window.Configuration = {
      name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
      });
      let requestInfo = dialogRequest.getRequestInfo(want)
      windowClass.bindDialogTarget(requestInfo, () => {
        console.info('Dialog Window Need Destroy.');
      }, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in binding dialog target.');
      });
    } catch (err) {
      console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`)
    }
  }
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback&lt;void&gt;): Promise&lt;void&gt;

绑定模态窗口与目标窗口并添加模态窗口销毁监听，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| requestInfo | [dialogRequest.RequestInfo](../apis-ability-kit/js-apis-app-ability-dialogRequest.md#requestinfo) | 是   | 目标窗口RequestInfo值。 |
| deathCallback | Callback&lt;void&gt;    | 是   | 模态窗口销毁监听。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { dialogRequest, Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ServiceExtAbility extends ServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest');
    let windowClass: window.Window | undefined = undefined;
    let config: window.Configuration = {
      name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
      });
      let requestInfo = dialogRequest.getRequestInfo(want)
      let promise = windowClass.bindDialogTarget(requestInfo, () => {
        console.info('Dialog Window Need Destroy.');
      });
      promise.then(() => {
        console.info('Succeeded in binding dialog target.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (err) {
      console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`)
    }
  }
}
```

### setWakeUpScreen<sup>9+</sup>

setWakeUpScreen(wakeUp: boolean): void

窗口唤醒屏幕。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型    | 必填 | 说明                         |
| ---------------- | ------- | ---- | ---------------------------- |
| wakeUp           | boolean | 是   | 是否设置唤醒屏幕。true表示唤醒；false表示不唤醒。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
let wakeUp: boolean = true;
try {
  windowClass.setWakeUpScreen(wakeUp);
} catch (exception) {
  console.error(`Failed to wake up the screen. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setSnapshotSkip<sup>9+</sup>
setSnapshotSkip(isSkip: boolean): void

截屏录屏或投屏是否忽略当前窗口。此接口一般用于禁止截屏/录屏/投屏的场景。

若要实现窗口始终在前台忽略截屏/录屏或投屏，在窗口从后台回到前台时，需要通过[on('windowEvent')](arkts-apis-window-Window.md#onwindowevent10)监听窗口生命周期变化，在后台状态时设置为false，而在前台状态时设置为true。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型    | 必填 | 说明                 |
| ------------- | ------- | ---- | -------------------- |
| isSkip | boolean | 是   | 截屏录屏是否忽略当前窗口，默认为false。<br>true表示忽略当前窗口，false表示不忽略当前窗口。</br> |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

```ts
let isSkip: boolean = true;
try {
  windowClass.setSnapshotSkip(isSkip);
} catch (exception) {
  console.error(`Failed to Skip. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback&lt;void&gt;): void

设置主窗口在分屏模式下是否被禁止移动，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                 |
| ----------- | ------------------------- | ---- | -------------------- |
| isForbidSplitMove | boolean                   | 是   | 窗口在分屏模式下是否被禁止移动。true表示禁止；false表示不禁止。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
      let isForbidSplitMove: boolean = true;
      try {
        windowClass.setForbidSplitMove(isForbidSplitMove, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to forbid window moving in split screen mode. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in forbidding window moving in split screen mode.');
        });
      } catch (exception) {
        console.error(`Failed to forbid window moving in split screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean): Promise&lt;void&gt;

设置主窗口在分屏模式下是否被禁止移动，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                 |
| ----------- | ------- | ---- | -------------------- |
| isForbidSplitMove | boolean | 是   | 窗口在分屏模式下是否被禁止移动。true表示禁止；false表示不禁止。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
      let isForbidSplitMove: boolean = true;
      try {
        let promise = windowClass.setForbidSplitMove(isForbidSplitMove);
        promise.then(() => {
          console.info('Succeeded in forbidding window moving in split screen mode.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to forbid window moving in split screen mode. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to forbid window moving in split screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### opacity<sup>9+</sup>

opacity(opacity: number): void

设置窗口不透明度。仅支持在[自定义系统窗口的显示与隐藏动画](../../windowmanager/system-window-stage.md#自定义系统窗口的显示与隐藏动画)中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                 |
| ------- | ------ | ---- |----------------------------------------------------|
| opacity | number | 是   | 不透明度。该参数为浮点数，取值范围为[0.0, 1.0]。0.0表示完全透明，1.0表示完全不透明。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.opacity(0.5);
} catch (exception) {
  console.error(`Failed to opacity. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### scale<sup>9+</sup>

scale(scaleOptions: ScaleOptions): void

设置窗口缩放参数。仅支持在[自定义系统窗口的显示与隐藏动画](../../windowmanager/system-window-stage.md#自定义系统窗口的显示与隐藏动画)中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                           | 必填 | 说明       |
| ------------ | ------------------------------ | ---- | ---------- |
| scaleOptions | [ScaleOptions](#scaleoptions9) | 是   | 缩放参数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
let obj: window.ScaleOptions = {
  x: 2.0,
  y: 1.0,
  pivotX: 0.5,
  pivotY: 0.5
};
try {
  windowClass.scale(obj);
} catch (exception) {
  console.error(`Failed to scale. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### rotate<sup>9+</sup>

rotate(rotateOptions: RotateOptions): void

设置窗口旋转参数。仅支持在[自定义系统窗口的显示与隐藏动画](../../windowmanager/system-window-stage.md#自定义系统窗口的显示与隐藏动画)中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明       |
| ------------- | -------------------------------- | ---- | ---------- |
| rotateOptions | [RotateOptions](#rotateoptions9) | 是   | 旋转参数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
let obj: window.RotateOptions = {
  x: 1.0,
  y: 1.0,
  z: 45.0,
  pivotX: 0.5,
  pivotY: 0.5
};
try {
  windowClass.rotate(obj);
} catch (exception) {
  console.error(`Failed to rotate. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### translate<sup>9+</sup>

translate(translateOptions: TranslateOptions): void

设置窗口平移参数。仅支持在[自定义系统窗口的显示与隐藏动画](../../windowmanager/system-window-stage.md#自定义系统窗口的显示与隐藏动画)中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型                                   | 必填 | 说明                 |
| ---------------- | -------------------------------------- | ---- | -------------------- |
| translateOptions | [TranslateOptions](#translateoptions9) | 是   | 平移参数，单位为px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
let obj: window.TranslateOptions = {
  x: 100.0,
  y: 0.0,
  z: 0.0
};
try {
  windowClass.translate(obj);
} catch (exception) {
  console.error(`Failed to translate. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### getTransitionController<sup>9+</sup>

 getTransitionController(): TransitionController

获取窗口属性转换控制器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                           | 说明             |
| ---------------------------------------------- | ---------------- |
| [TransitionController](#transitioncontroller9) | 属性转换控制器。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
let controller = windowClass.getTransitionController(); // 获取属性转换控制器
```

### setBlur<sup>9+</sup>

setBlur(radius: number): void

设置窗口模糊。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                               |
| ------ | ------ | ---- |--------------------------------------------------|
| radius | number | 是   | 表示窗口模糊的半径值。该参数为浮点数，单位为px，取值范围为[0, +∞)，取值为0.0时表示关闭窗口模糊。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setBlur(4.0);
} catch (exception) {
  console.error(`Failed to set blur. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setBackdropBlur<sup>9+</sup>

setBackdropBlur(radius: number): void

设置窗口背景模糊。
窗口背景是指窗口覆盖的下层区域，与窗口大小相同。
需要通过[setWindowBackgroundColor](arkts-apis-window-Window.md#setwindowbackgroundcolor9)将窗口内容背景设置成透明，否则无法看到模糊效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                    |
| ------ | ------ | ---- |-------------------------------------------------------|
| radius | number | 是   | 表示窗口背景模糊的半径值。该参数为浮点数，单位为px，取值范围为[0.0, +∞)，取值为0.0表示关闭窗口背景模糊。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setWindowBackgroundColor('#00FFFFFF');
  windowClass.setBackdropBlur(4.0);
} catch (exception) {
  console.error(`Failed to set backdrop blur. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setBackdropBlurStyle<sup>9+</sup>

setBackdropBlurStyle(blurStyle: BlurStyle): void

设置窗口背景模糊类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型      | 必填 | 说明                   |
| --------- | --------- | ---- | ---------------------- |
| blurStyle | [BlurStyle](#blurstyle9) | 是   | 表示窗口背景模糊类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setBackdropBlurStyle(window.BlurStyle.THIN);
} catch (exception) {
  console.error(`Failed to set backdrop blur style. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setShadow<sup>9+</sup>

setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void

设置窗口边缘阴影。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                          |
| ------- | ------ | ---- |-------------------------------------------------------------|
| radius  | number | 是   | 表示窗口边缘阴影的模糊半径。该参数为浮点数，单位为px，取值范围为[0.0, +∞)，取值为0.0时表示关闭窗口边缘阴影。     |
| color   | string | 否   | 表示窗口边缘阴影的颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |
| offsetX | number | 否   | 表示窗口边缘阴影的X轴的偏移量。该参数为浮点数，单位为px。                              |
| offsetY | number | 否   | 表示窗口边缘阴影的Y轴的偏移量。该参数为浮点数，单位为px。                              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setShadow(4.0, '#FF00FF00', 2, 3);
} catch (exception) {
  console.error(`Failed to set shadow. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setCornerRadius<sup>9+</sup>

setCornerRadius(cornerRadius: number): void

设置窗口圆角半径。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                 |
| ----------- | ------- | ---- |----------------------------------------------------|
| cornerRadius | number | 是   | 表示窗口圆角的半径值。该参数为浮点数，单位为px，取值范围为[0.0, +∞)，取值为0.0时表示没有窗口圆角。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setCornerRadius(4.0);
} catch (exception) {
  console.error(`Failed to set corner radius. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setTouchableAreas<sup>12+</sup>

setTouchableAreas(rects: Array&lt;Rect&gt;): void

实现设置窗口可触摸区域；不设置时默认整个窗口区域可触摸；设置窗口可触摸区域后，区域外触摸事件将被透传；如果窗口区域发生变化需要重新设置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| rects | Array<[Rect](arkts-apis-window-i.md#rect7)> | 是   | 窗口可触摸区域。可触摸区域最大个数不能超过10个，且范围不能超出窗口区域。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |                       |

**示例：**

```ts
try {
  windowClass.setTouchableAreas([{left: 100, top: 100, width: 200, height:200},
    {left: 400, top: 100, width: 200, height:200}]);
} catch (exception) {
  console.error(`Failed to set touchable areas. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### raiseToAppTop<sup>10+</sup>

raiseToAppTop(callback: AsyncCallback&lt;void&gt;): void

提升应用子窗口到应用顶层。使用callback异步回调。

使用该接口需要先创建子窗口，并确保该子窗口调用[showWindow()](arkts-apis-window-Window.md#showwindow9)并执行完毕。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
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
        subWindow.raiseToAppTop((err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to raise the window to app top. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in raising the window to app top.');
        });
      });
    });
  }
}
```

### setWaterMarkFlag<sup>10+</sup>

setWaterMarkFlag(enable: boolean): Promise&lt;void&gt;

为当前窗口添加或删除安全水印标志，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型     | 必填 | 说明                                            |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | 是   | 是否对窗口添加标志位。true表示添加，false表示删除。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The display device is abnormal.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enable = true;
  let promise = windowClass.setWaterMarkFlag(enable);
  promise.then(() => {
    console.info('Succeeded in setting water mark flag of window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set water mark flag of window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set water mark flag of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWaterMarkFlag<sup>10+</sup>

setWaterMarkFlag(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

为当前窗口添加或删除安全水印标志，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                              |
| -------- | ------------------------- | ---  | ----------------------------------------------- |
| enable   | boolean                   | 是   | 是否对窗口添加标志位。true表示添加，false表示删除。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The display device is abnormal.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enable: boolean = true;
  windowClass.setWaterMarkFlag(enable, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set water mark flag of window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting water mark flag of window.');
  });
} catch (exception) {
  console.error(`Failed to set water mark flag of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setHandwritingFlag<sup>12+</sup>

setHandwritingFlag(enable: boolean): Promise&lt;void&gt;

为当前窗口添加或移除手写标志，添加该标志后窗口只响应手写笔事件，不响应触屏事件。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型     | 必填 | 说明                                            |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | 是   | 是否对窗口添加标志位。true表示添加，false表示移除。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enable = true;
  let promise = windowClass.setHandwritingFlag(enable);
  promise.then(() => {
    console.info('Succeeded in setting handwriting flag of window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set handwriting flag of window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set handwriting flag of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### raiseAboveTarget<sup>10+</sup>

raiseAboveTarget(windowId: number, callback: AsyncCallback&lt;void&gt;): void

将同一个主窗口下的子窗口抬升到目标子窗口之上。使用callback异步回调。

使用该接口需要确保要抬升的子窗口和目标子窗口都已创建完成，分别调用[showWindow()](arkts-apis-window-Window.md#showwindow9)并执行完毕。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | 是   | 目标子窗口的id，通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到[properties](arkts-apis-window-i.md#windowproperties)后，再通过properties.id获取。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Mandatory parameters are left unspecified. |
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
    let windowClass: window.Window;
    // 创建子窗
    try {
      windowStage.createSubWindow("testSubWindow").then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        windowClass.showWindow().then(() => {
          // windowClass的获取需放在targetWindow之上
          let targetWindow: window.Window = windowClass;
          let properties = targetWindow.getWindowProperties();
          let targetId = properties.id;
          windowClass.raiseAboveTarget(targetId, (err: BusinessError) => {
            if (err.code) {
              console.error(`Failed to raise the subWindow to target subWindow top. Cause code: ${err.code}, message: ${err.message}`);
              return;
            }
            console.info('Succeeded in raising the subWindow to target subWindow top.');
          });
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### raiseAboveTarget<sup>10+</sup>

raiseAboveTarget(windowId: number): Promise&lt;void&gt;

将同一个主窗下的子窗口提升到目标子窗口之上。使用Promise异步回调。

使用该接口需要确保要抬升的子窗口和目标子窗口都已创建完成，分别调用[showWindow()](arkts-apis-window-Window.md#showwindow9)并执行完毕。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | 是   | 目标子窗口的id，通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到[properties](arkts-apis-window-i.md#windowproperties)后，再通过properties.id获取。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Mandatory parameters are left unspecified. |
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
    let windowClass: window.Window;
    // 创建子窗
    try {
      windowStage.createSubWindow("testSubWindow").then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        windowClass.showWindow().then(() => {
          // windowClass的获取需放在targetWindow之上
          let targetWindow: window.Window = windowClass;
          let properties = targetWindow.getWindowProperties();
          let targetId = properties.id;
          windowClass.raiseAboveTarget(targetId).then(()=> {
            console.info('Succeeded in raising the subWindow to target subWindow top.');
          }).catch((err: BusinessError)=>{
            console.error(`Failed to raise the subWindow to target subWindow top. Cause code: ${err.code}, message: ${err.message}`);
          });
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setRaiseByClickEnabled<sup>10+</sup>

setRaiseByClickEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

禁止/使能子窗口点击抬升功能。使用callback异步回调。

通常来说，点击一个子窗口，会将该子窗口显示到最上方，如果设置为false，那么点击子窗口的时候，不会将该子窗口显示到最上方，而是保持不变。

使用该接口需要先创建子窗口，并确保该子窗口调用[showWindow()](arkts-apis-window-Window.md#showwindow9)并执行完毕。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | 是   | 设置子窗口点击抬升功能是否使能，true表示使能，false表示禁止。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
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
          subWindow.setRaiseByClickEnabled(enabled, (err) => {
          if (err.code) {
            console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in disabling the raise-by-click function.');
          });
        } catch (err) {
          console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
        }
      });
    });
  }
}
```

### hideNonSystemFloatingWindows<sup>11+</sup>

hideNonSystemFloatingWindows(shouldHide: boolean, callback: AsyncCallback&lt;void&gt;): void

设置是否隐藏非系统级悬浮窗口，仅在非2in1设备生效。使用callback异步回调。

非系统级悬浮窗口是指非系统应用创建的悬浮窗口。默认情况下，一个系统应用主窗口可以与非系统级悬浮窗口共同显示，即该主窗口可以被上层的非系统级悬浮窗口遮挡，如果设置为true，则所有的非系统级悬浮窗口会被隐藏，此时该主窗口就不会被上层的非系统级悬浮窗口遮挡了。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型                      | 必填 | 说明       |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | 是   | 指示是否隐藏非系统级的悬浮窗口，true表示隐藏，false表示不隐藏。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 加载主窗口对应的页面
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });

    // 获取应用主窗口。
    let mainWindow: window.Window | undefined = undefined;
    windowStage.getMainWindow((err, data) => {
      if (err.code) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      mainWindow = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));

      let shouldHide = true;
      try {
        // 调用带callback参数的hideNonSystemFloatingWindows接口
        mainWindow.hideNonSystemFloatingWindows(shouldHide, (err) => {
          if (err.code) {
            console.error(`Failed to hide the non-system floating windows. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in hiding the non-system floating windows.');
        });
      } catch (exception) {
        console.error(`Failed to hide the non-system floating windows. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### hideNonSystemFloatingWindows<sup>11+</sup>

hideNonSystemFloatingWindows(shouldHide: boolean): Promise&lt;void&gt;

设置是否隐藏非系统级悬浮窗口，仅在非2in1设备生效。使用callback异步回调。

非系统级悬浮窗口是指非系统应用创建的悬浮窗口。默认情况下，一个系统应用主窗口可以与非系统级悬浮窗口共同显示，即该主窗口可以被上层的非系统级悬浮窗口遮挡，如果设置为true，则所有的非系统级悬浮窗口会被隐藏，此时该主窗口就不会被上层的非系统级悬浮窗口遮挡了。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型                      | 必填 | 说明       |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | 是   | 指示是否隐藏非系统级的悬浮窗口，true表示隐藏，false表示不隐藏。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 加载主窗口对应的页面
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });

    // 获取应用主窗口。
    let mainWindow: window.Window | undefined = undefined;
    windowStage.getMainWindow((err, data) => {
      if (err.code) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      mainWindow = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));

      let shouldHide = true;
      try {
        // 调用hideNonSystemFloatingWindows接口，获取promise对象
        let promise = mainWindow.hideNonSystemFloatingWindows(shouldHide);
        promise.then(()=> {
          console.info('Succeeded in hiding the non-system floating windows.');
        }).catch((err: BusinessError)=>{
          console.error(`Failed to hide the non-system floating windows. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to hide the non-system floating windows. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### isMainWindowFullScreenAcrossDisplays<sup>20+</sup>

isMainWindowFullScreenAcrossDisplays(): Promise&lt;boolean&gt;

判断当前窗口的主窗口是否是跨多块屏幕使用全屏模式显示，使用Promise异步回调，仅支持主窗口与应用子窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前窗口的主窗口跨多块屏幕使用全屏模式显示，返回false表示当前窗口的主窗口未跨多块屏幕使用全屏模式显示。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.isMainWindowFullScreenAcrossDisplays();
  promise.then((data: boolean)=> {
      console.info(`Succeeded in using isMainWindowFullScreenAcrossDisplays function. Data: ${data}`);
  }).catch((err: BusinessError)=>{
      console.error(`Failed to use isMainWindowFullScreenAcrossDisplays function. code:${err.code}, message:${err.message}.`);
  });
} catch (exception) {
  console.error(`Failed to use isMainWindowFullScreenAcrossDisplays function. Cause code: ${exception.code}, message: ${exception.message}.`);
}
```

### on('mainWindowFullScreenAcrossDisplaysChanged')<sup>20+</sup>

on(type: 'mainWindowFullScreenAcrossDisplaysChanged', callback: Callback&lt;boolean&gt;): void

监听本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 监听事件，固定为'mainWindowFullScreenAcrossDisplaysChanged'，即本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化。 |
| callback | Callback&lt;boolean&gt;   | 是   | 回调函数。即本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化回调。true表示主窗口进入跨多块屏幕使用全屏模式显示状态，false表示主窗口退出跨多块屏幕使用全屏模式显示状态。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**示例：**

```ts
const callback = (mainWindowFullScreenAcrossDisplaysChanged: boolean) => {
  console.info(`main window across displays changed. Data: ${mainWindowFullScreenAcrossDisplaysChanged}`);
}
try {
  windowClass.on('mainWindowFullScreenAcrossDisplaysChanged', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
### off('mainWindowFullScreenAcrossDisplaysChanged')<sup>20+</sup>

off(type: 'mainWindowFullScreenAcrossDisplaysChanged', callback?: Callback&lt;boolean&gt;): void

取消监听本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                    | 是   | 监听事件，固定为'mainWindowFullScreenAcrossDisplaysChanged'，即本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化。 |
| callback | Callback&lt;boolean&gt;    | 否   | 回调函数。即本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化回调。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**示例：**

```ts
const callback = (mainWindowFullScreenAcrossDisplaysChanged: boolean) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('mainWindowFullScreenAcrossDisplaysChanged', callback);
  // 关闭指定callback的监听
  windowClass.off('mainWindowFullScreenAcrossDisplaysChanged', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('mainWindowFullScreenAcrossDisplaysChanged');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setTopmost<sup>12+</sup>

setTopmost(isTopmost: boolean): Promise&lt;void&gt;

系统应用主窗口调用，实现将窗口置于所有应用窗口之上不被遮挡，使用Promise异步回调。

仅对2in1设备的悬浮窗口生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| isTopmost | boolean | 是   | 是否将系统应用主窗口置顶，true表示置顶，false表示取消置顶。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // ...
    windowStage.getMainWindow().then((mainWindow) => {
      let isTopmost: boolean = true;
      mainWindow.setTopmost(isTopmost).then(() => {
        console.info('Succeeded in setting the main window to be topmost.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the main window to be topmost. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### setSingleFrameComposerEnabled<sup>11+</sup>

setSingleFrameComposerEnabled(enable: boolean): Promise&lt;void&gt;

禁止/使能单帧合成渲染节点的功能。使用Promise异步回调。

单帧合成渲染节点的功能主要用于跟手性要求较高的场景，使能该功能之后可以降低渲染节点的上屏延时。通过setSingleFrameComposerEnabled接口，如果enable设置为true，则使能单帧合成渲染节点的功能，否则禁止单帧合成渲染节点的功能。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | 是   | 设置单帧合成渲染节点的功能是否使能，true表示使能，false表示禁止。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let enable = true;
try {
  let promise = windowClass.setSingleFrameComposerEnabled(enable);
  promise.then(()=> {
      console.info('Succeeded in enabling the single-frame-composer function.');
  }).catch((err: BusinessError)=>{
      console.error(`Failed to enable the single-frame-composer function. code:${err.code}, message:${err.message}.`);
  });
} catch (exception) {
  console.error(`Failed to enable the single-frame-composer function. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setTitleButtonVisible<sup>12+</sup>

setTitleButtonVisible(isMaximizeVisible: boolean, isMinimizeVisible: boolean, isSplitVisible: boolean): void

设置主窗标题栏上的最大化、最小化、分屏按钮是否可见。

此接口仅支持2in1设备且仅对在当前场景下可见的标题栏按钮（最大化、最小化、分屏）生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| isMaximizeVisible | boolean | 是   | 设置最大化按钮是否可见，true为可见，false为隐藏。 |
| isMinimizeVisible | boolean | 是   | 设置最小化按钮是否可见，true为可见，false为隐藏。 |
| isSplitVisible | boolean | 是   | 设置分屏按钮是否可见，true为可见，false为隐藏。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300004  | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // 加载主窗口对应的页面
    windowStage.loadContent('pages/Index', (err) => {
      let mainWindow: window.Window | undefined = undefined;
      // 获取应用主窗口。
      windowStage.getMainWindow().then(
        data => {
          mainWindow = data;
          console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
          // 调用setTitleButtonVisible接口，隐藏主窗标题栏最大化、最小化、分屏按钮。
          mainWindow.setTitleButtonVisible(false, false, false);
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

### setWindowType<sup>(deprecated)</sup>

setWindowType(type: WindowType, callback: AsyncCallback&lt;void&gt;): void

设置窗口类型，使用callback异步回调。

**系统接口：** 此接口为系统接口。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| type     | [WindowType](#windowtype7) | 是   | 窗口类型。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let type = window.WindowType.TYPE_SYSTEM_ALERT;
windowClass.setWindowType(type, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the window type. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the window type.');
});
```

### setWindowType<sup>(deprecated)</sup>

setWindowType(type: WindowType): Promise&lt;void&gt;

设置窗口类型，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| type   | [WindowType](#windowtype7) | 是   | 窗口类型。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let type = window.WindowType.TYPE_SYSTEM_ALERT;
let promise = windowClass.setWindowType(type);
promise.then(() => {
  console.info('Succeeded in setting the window type.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the window type. Cause code: ${err.code}, message: ${err.message}`);
});
```

### requestFocus<sup>13+</sup>

requestFocus(isFocused: boolean): Promise&lt;void&gt;

支持当前窗口主动请求获焦/失焦，使用Promise异步回调。调用成功即返回，该接口返回值不代表最终获焦/失焦生效结果。可使用[on('windowEvent')](arkts-apis-window-Window.md#onwindowevent10)监听窗口获焦/失焦状态。

获焦请求发送后，窗口获焦结果受到窗口可获焦属性及窗口可见状态的限制。获焦成功的窗口需满足以下约束：1.窗口支持获焦；2.窗口可见（窗口已显示，未销毁且未退至后台）。

失焦请求发送后，窗口无条件失焦。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| isFocused | boolean | 是   | 是否获取焦点，true表示请求获焦，false表示请求失焦。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocused: boolean = true;
let promise = windowClass.requestFocus(isFocused);
promise.then(() => {
  console.info('Succeeded in requesting focus.');
}).catch((err: BusinessError) => {
  console.error(`Failed to request focus. Cause code: ${err.code}, message: ${err.message}`);
});
```

## SubWindowOptions<sup>11+</sup>

子窗口创建参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称      | 类型  | 只读 | 可选 | 说明         |
| ---------- | ---- | ---- | ---- | ----------- |
| isTopmost<sup>12+</sup>  | boolean | 否 | 是 | 子窗口是否启用置顶属性。true表示子窗口置顶，false表示子窗口不置顶。不设置，则默认为false。       |

## WindowStage<sup>9+</sup>

窗口管理器。管理各个基本窗口单元，即[Window](arkts-apis-window-Window.md)实例。

下列API示例中都需在[onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate)函数中使用WindowStage的实例调用对应方法。

### disableWindowDecor<sup>9+</sup>

disableWindowDecor(): void

禁止窗口装饰。

禁止窗口装饰后，当主窗口进入全屏沉浸状态时，此时鼠标Hover到上方窗口标题栏热区上会显示悬浮标题栏。若想禁用悬浮标题栏显示，请使用[setTitleAndDockHoverShown()](arkts-apis-window-Window.md#settitleanddockhovershown14)接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('disableWindowDecor');
    windowStage.disableWindowDecor();
  }
};
```

### setShowOnLockScreen<sup>9+</sup>

setShowOnLockScreen(showOnLockScreen: boolean): void

设置应用显示在锁屏之上。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型    | 必填 | 说明                         |
| ---------------- | ------- | ---- | ---------------------------- |
| showOnLockScreen | boolean | 是   | 是否设置应用显示在锁屏之上。true表示显示在锁屏之上；false表示不显示在锁屏之上。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.setShowOnLockScreen(true);
    } catch (exception) {
      console.error(`Failed to show on lockscreen. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### setImageForRecent<sup>20+</sup>

setImageForRecent(imgResourceId: number, value: ImageFit): Promise&lt;void&gt;

设置应用在多任务中显示的图片，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| imgResourceId | number | 是   | 应用自定义图片的资源id，图片资源需放在resources/base/media目录下，通过`$r`资源访问方式获取对应图片的资源id，这里以获取startIcon图片的资源id为例给出示意：`$r("app.media.startIcon").id`。|
| value | [ImageFit](arkui-ts/ts-appendix-enums.md#imagefit) | 是 | 应用自定义图片的填充方式。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. 2. Invalid parameter length. 3. Incorrect parameter format. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    let imgResourceId = $r("app.media.startIcon").id
    try {
      let promise = windowStage.setImageForRecent(imgResourceId, ImageFit.Fill);
      promise.then(() => {
        console.info(`Succeeded in setting image for recent`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to set image for recent. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set image for recent.`);
    }
  }
};
```

## TransitionContext<sup>9+</sup>

属性转换的上下文信息。

**系统接口：** 此接口为系统接口。

### 属性

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称                  | 类型          | 可读 | 可写 | 说明             |
| --------------------- | ----------------- | ---- | ---- | ---------------- |
| toWindow<sup>9+</sup> | [Window](arkts-apis-window-Window.md) | 是   | 是   | 动画的目标窗口。 |

### completeTransition<sup>9+</sup>

completeTransition(isCompleted: boolean): void

设置属性转换的最终完成状态。该函数需要在动画函数[animateTo()](arkui-ts/ts-explicit-animation.md)执行后设置。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| isCompleted | boolean | 是   | 窗口属性转换是否完成。true表示完成本次转换；false表示撤销本次转换。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**示例：**

```ts
(context: window.TransitionContext) => {
  let toWindow: window.Window = context.toWindow;
  this.getUIContext()?.animateTo({
    duration: 1000, // 动画时长
    tempo: 0.5, // 播放速率
    curve: Curve.EaseInOut, // 动画曲线
    delay: 0, // 动画延迟
    iterations: 1, // 播放次数
    playMode: PlayMode.Normal, // 动画模式
  }, () => {
    let obj: window.TranslateOptions = {
      x: 100.0,
      y: 0.0,
      z: 0.0
    };
    toWindow.translate(obj);
    console.info('toWindow translate end');
  }
  );
  try {
    context.completeTransition(true)
  } catch (exception) {
    console.error(`toWindow translate fail. Cause code: ${exception.code}, message: ${exception.message}`);
  }
  console.info('complete transition end');
};
```

## TransitionController<sup>9+</sup>

属性转换控制器。使用其子接口之前得先创建系统窗口，参照示例代码。

**系统接口：** 此接口为系统接口。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = {
  name: "systemTypeWindow",
  windowType: window.WindowType.TYPE_PANEL, //根据需要自选系统窗口类型
  ctx: this.context
};
let promise = window.createWindow(config);
promise.then((data) => {
  windowClass = data;
  console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to create the Window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### animationForShown<sup>9+</sup>

animationForShown(context: TransitionContext): void

窗口显示时的自定义动画配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                 |
| ------- | ---------------------------------------- | ---- | -------------------- |
| context | [TransitionContext](#transitioncontext9) | 是   | 属性转换时的上下文。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**示例：**

```ts
// xxx.ts
export class AnimationConfig {
  private animationForShownCallFunc_: Function = undefined;
  ShowWindowWithCustomAnimation(windowClass: window.Window, callback) {
    if (!windowClass) {
      console.error('windowClass is undefined');
      return false;
    }
    this.animationForShownCallFunc_ = callback;
    let controller: window.TransitionController = windowClass.getTransitionController();
    controller.animationForShown = (context : window.TransitionContext)=> {
      this.animationForShownCallFunc_(context);
    };
    windowClass.showWithAnimation(()=>{
      console.info('Show with animation success');
    });
  }
}
```

```ts
// xxx.ets
let animationConfig = new AnimationConfig();
let systemTypeWindow = window.findWindow("systemTypeWindow"); // 此处需要获取一个系统类型窗口。
try {
  animationConfig?.ShowWindowWithCustomAnimation(systemTypeWindow, (context : window.TransitionContext)=>{
    console.info('complete transition end');
    let toWindow = context.toWindow;
    this.getUIContext()?.animateTo({
      duration: 1000, // 动画时长
      tempo: 0.5, // 播放速率
      curve: Curve.EaseInOut, // 动画曲线
      delay: 0, // 动画延迟
      iterations: 1, // 播放次数
      playMode: PlayMode.Normal, // 动画模式
      onFinish: () => {
        console.info('onFinish in animation');
        context.completeTransition(true)
      }
    }, () => {
      let obj : window.TranslateOptions = {
        x : 100.0,
        y : 0.0,
        z : 0.0
      };
      toWindow.translate(obj); // 设置动画过程中的属性转换
      console.info('toWindow translate end in animation');
    });
    console.info('complete transition end');
  });
} catch (error) {
  console.error(`ShowWindowWithCustomAnimation error code: ${error.code}, message: ${error.message}`);
}
```

### animationForHidden<sup>9+</sup>

animationForHidden(context: TransitionContext): void

窗口隐藏时的自定义动画配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                 |
| ------- | ---------------------------------------- | ---- | -------------------- |
| context | [TransitionContext](#transitioncontext9) | 是   | 属性转换时的上下文。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**示例：**

```ts
// xxx.ts
export class AnimationConfig {
  private animationForHiddenCallFunc_: Function = undefined;
  HideWindowWithCustomAnimation(windowClass: window.Window, callback) {
    if (!windowClass) {
      console.error('windowClass is undefined');
      return false;
    }
    this.animationForHiddenCallFunc_ = callback;
    let controller: window.TransitionController = windowClass.getTransitionController();
    controller.animationForHidden = (context : window.TransitionContext)=> {
      this.animationForHiddenCallFunc_(context);
    };
    windowClass.hideWithAnimation(()=>{
      console.info('hide with animation success');
    });
  }
}
```

```ts
// xxx.ets
let animationConfig = new AnimationConfig();
let systemTypeWindow = window.findWindow("systemTypeWindow"); // 此处需要获取一个系统类型窗口。
try {
  animationConfig?.HideWindowWithCustomAnimation(systemTypeWindow, (context : window.TransitionContext)=>{
    console.info('complete transition end');
    let toWindow = context.toWindow;
    this.getUIContext()?.animateTo({
      duration: 1000, // 动画时长
      tempo: 0.5, // 播放速率
      curve: Curve.EaseInOut, // 动画曲线
      delay: 0, // 动画延迟
      iterations: 1, // 播放次数
      playMode: PlayMode.Normal, // 动画模式
      onFinish: () => {
        console.info('onFinish in animation');
        context.completeTransition(true)
      }
    }, () => {
      let obj : window.TranslateOptions = {
        x : 100.0,
        y : 0.0,
        z : 0.0
      };
      toWindow.translate(obj); // 设置动画过程中的属性转换
      console.info('toWindow translate end in animation');
    });
    console.info('complete transition end');
  });
} catch (error) {
  console.error(`HideWindowWithCustomAnimation error code: ${error.code}, message: ${error.message}` );
}
```

## ExtensionWindowAttribute<sup>14+</sup>

扩展窗口的属性枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称      | 值 | 说明         |
| ---------- | ----- | ----------- |
| SYSTEM_WINDOW  | 0 | 系统窗口。|
| SUB_WINDOW  | 1 | 子窗口。|

## SystemWindowOptions<sup>14+</sup>

系统窗口的创建参数。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型                      | 只读  |可选 | 说明       |
| ------ | ------------------------- | ---- | ---- |---------- |
| windowType   | [WindowType](#windowtype7) | 否   | 否   | 窗口类型。无默认类型，不配置会导致窗口创建失败。不支持TYPE_DIALOG类型。 |

## ExtensionWindowConfig<sup>14+</sup>

创建扩展窗口时需要配置的参数。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型                      | 只读  |可选 | 说明       |
| ------ | ------------------------- | ---- | ---- |---------- |
| windowName   | string | 否 | 否  | 窗口名。 |
| windowAttribute   | [ExtensionWindowAttribute](#extensionwindowattribute14) | 否 | 否   | 窗口的属性。用于配置创建的窗口是子窗口还是系统窗口。当windowAttribute配置为SUB_WINDOW时须配置subWindowOptions，当windowAttribute配置为SYSTEM_WINDOW时须配置systemWindowOptions，否则创建窗口失败。|
| windowRect   | [Rect](arkts-apis-window-i.md#rect7) | 否 | 否   | 窗口矩形区域。 |
| subWindowOptions   | [SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11) | 否 | 是 | 创建子窗口的参数。无默认参数，当windowAttribute配置为SUB_WINDOW时必选，否则会导致窗口创建失败。 |
| systemWindowOptions   | [SystemWindowOptions](#systemwindowoptions14) | 否 | 是 | 创建系统窗口的参数。无默认参数，当windowAttribute配置为SYSTEM_WINDOW时必选，否则会导致窗口创建失败。 |