# 窗口

窗口提供管理窗口的一些基础能力，包括对当前窗口的创建、销毁、各属性设置，以及对各窗口间的管理调度。

该模块提供以下窗口相关的常用功能：

- [Window](#window)：当前窗口实例，窗口管理器管理的基本单元。
- [WindowStage](#windowstage9)：窗口管理器。管理各个基本窗口单元。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import window from '@ohos.window';
```

## WindowType<sup>7+</sup>

窗口类型枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称              | 值 | 说明               |
| ----------------- | ------ | ------------------ |
| TYPE_APP          | 0      | 表示应用子窗口。<br>**模型约束：** 此接口仅可在FA模型下使用。 |
| TYPE_SYSTEM_ALERT | 1      | 表示系统告警窗口。 |
| TYPE_INPUT_METHOD<sup>9+</sup> | 2      | 表示输入法窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_STATUS_BAR<sup>9+</sup>   | 3      | 表示状态栏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_PANEL<sup>9+</sup>        | 4      | 表示通知栏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_KEYGUARD<sup>9+</sup>     | 5      | 表示锁屏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_VOLUME_OVERLAY<sup>9+</sup> | 6      | 表示音量条。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_NAVIGATION_BAR<sup>9+</sup> | 7      | 表示导航栏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_FLOAT<sup>9+</sup> | 8      | 表示悬浮窗。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**需要权限：** ohos.permission.SYSTEM_FLOAT_WINDOW |
| TYPE_WALLPAPER<sup>9+</sup> | 9      | 表示壁纸。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_DESKTOP<sup>9+</sup> | 10      | 表示桌面。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_LAUNCHER_RECENT<sup>9+</sup> | 11      | 表示多任务中心。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_LAUNCHER_DOCK<sup>9+</sup> | 12      | 表示桌面Dock栏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_VOICE_INTERACTION<sup>9+</sup> | 13      | 表示智慧语音。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_POINTER<sup>9+</sup> | 14      | 表示鼠标。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_FLOAT_CAMERA<sup>9+</sup> | 15      | 表示相机类型悬浮窗。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**需要权限：** ohos.permission.SYSTEM_FLOAT_WINDOW |
| TYPE_DIALOG<sup>9+</sup>  | 16      | 表示模态窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |
| TYPE_SCREENSHOT<sup>9+</sup>  | 17      | 表示截屏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。 |

## AvoidAreaType<sup>7+</sup>

窗口内容需要规避区域的类型枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                             | 值   | 说明                                                         |
| -------------------------------- | ---- | ------------------------------------------------------------ |
| TYPE_SYSTEM                      | 0    | 表示系统默认区域。一般包括状态栏、导航栏和Dock栏，各设备系统定义可能不同。 |
| TYPE_CUTOUT                      | 1    | 表示刘海屏区域。                                             |
| TYPE_SYSTEM_GESTURE<sup>9+</sup> | 2    | 表示手势区域。                                               |
| TYPE_KEYBOARD<sup>9+</sup>       | 3    | 表示软键盘区域。                                             |

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

## SystemBarProperties

状态栏、导航栏的属性。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                                   | 参数类型 | 可读 | 可写 | 必填 | 说明                                                         |
| -------------------------------------- | -------- | ---- | ---- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   | 否   | 是   | 否   | 状态栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。默认值：`#0x66000000`。 |
| isStatusBarLightIcon<sup>7+</sup>      | boolean  | 否   | 是   | 否   | 状态栏图标是否为高亮状态。true表示高亮；false表示不高亮。默认值：false。 |
| statusBarContentColor<sup>8+</sup>     | string   | 否   | 是   | 否   | 状态栏文字颜色。当设置此属性后， `isStatusBarLightIcon`属性设置无效。默认值：`0xE5FFFFFF。` |
| navigationBarColor                     | string   | 否   | 是   | 否   | 导航栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。默认值：`#0x66000000。` |
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  | 否   | 是   | 否   | 导航栏图标是否为高亮状态。true表示高亮；false表示不高亮。默认值：false。 |
| navigationBarContentColor<sup>8+</sup> | string   | 否   | 是   | 否   | 导航栏文字颜色。当设置此属性后， `isNavigationBarLightIcon`属性设置无效。默认值：`#0xE5FFFFFF。` |

## Orientation<sup>9+</sup>

窗口显示方向类型枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                                  | 值   | 说明                          |
| ------------------------------------- | ---- | ----------------------------- |
| UNSPECIFIED                           | 0    | 表示未定义方向模式，由系统判定。 |
| PORTRAIT                              | 1    | 表示竖屏显示模式。             |
| LANDSCAPE                             | 2    | 表示横屏显示模式。   |
| PORTRAIT_INVERTED                     | 3    | 表示反向竖屏显示模式。   |
| LANDSCAPE_INVERTED                    | 4    | 表示反向横屏显示模式。 |
| AUTO_ROTATION                         | 5    | 表示传感器自动旋转模式。 |
| AUTO_ROTATION_PORTRAIT                | 6    | 表示传感器自动竖向旋转模式。 |
| AUTO_ROTATION_LANDSCAPE               | 7    | 表示传感器自动横向旋转模式。 |
| AUTO_ROTATION_RESTRICTED              | 8    | 表示受开关控制的自动旋转模式。 |
| AUTO_ROTATION_PORTRAIT_RESTRICTED     | 9    | 表示受开关控制的自动竖向旋转模式。 |
| AUTO_ROTATION_LANDSCAPE_RESTRICTED    | 10   | 表述受开关控制的自动横向旋转模式。 |
| LOCKED                                | 11   | 表示锁定模式。 |

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

## SystemBarRegionTint<sup>8+</sup>

单个导航栏或状态栏回调信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称            | 参数类型                  | 可读 | 可写 | 说明                                                         |
| --------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type            | [WindowType](#windowtype7) | 是   | 否   | 当前属性改变的系统栏类型，仅支持类型为导航栏、状态栏的系统栏。 |
| isEnable        | boolean                   | 是   | 否   | 当前系统栏是否显示。                                         |
| region          | [Rect](#rect7)             | 是   | 否   | 当前系统栏的位置及大小。                                     |
| backgroundColor | string                    | 是   | 否   | 系统栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |
| contentColor    | string                    | 是   | 否   | 系统栏文字颜色。                                             |

## SystemBarTintState<sup>8+</sup>

当前系统栏回调信息集合。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 参数类型                                            | 可读 | 可写 | 说明                         |
| ---------- | --------------------------------------------------- | ---- | ---- | ---------------------------- |
| displayId  | number                                              | 是   | 否   | 当前物理屏幕id。             |
| regionTint | Array<[SystemBarRegionTint](#systembarregiontint8)> | 是   | 否   | 当前已改变的所有系统栏信息。 |

## Rect<sup>7+</sup>

窗口矩形区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 参数类型 | 可读 | 可写 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | 是   | 是   | 矩形区域的左边界。 |
| top    | number   | 是   | 是   | 矩形区域的上边界。 |
| width  | number   | 是   | 是   | 矩形区域的宽度。   |
| height | number   | 是   | 是   | 矩形区域的高度。   |

## AvoidArea<sup>7+</sup>

窗口内容规避区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 参数类型      | 可读 | 可写 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| visible<sup>9+</sup>    | boolean       | 是   | 是   | 规避区域是否可见。 |
| leftRect   | [Rect](#rect7) | 是   | 是   | 屏幕左侧的矩形区。 |
| topRect    | [Rect](#rect7) | 是   | 是   | 屏幕顶部的矩形区。 |
| rightRect  | [Rect](#rect7) | 是   | 是   | 屏幕右侧的矩形区。 |
| bottomRect | [Rect](#rect7) | 是   | 是   | 屏幕底部的矩形区。 |

## Size<sup>7+</sup>

窗口大小。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 参数类型 | 可读 | 可写 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | 是   | 是   | 窗口宽度。 |
| height | number   | 是   | 是   | 窗口高度。 |

## WindowProperties

窗口属性。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                                  | 参数类型                  | 可读 | 可写 | 说明                                                         |
| ------------------------------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| windowRect<sup>7+</sup>               | [Rect](#rect7)             | 是   | 是   | 窗口尺寸。                                                   |
| type<sup>7+</sup>                     | [WindowType](#windowtype7) | 是   | 是   | 窗口类型。                                                   |
| isFullScreen                          | boolean                   | 是   | 是   | 是否全屏，默认为false。                                      |
| isLayoutFullScreen<sup>7+</sup>       | boolean                   | 是   | 是   | 窗口是否为沉浸式，默认为false。                              |
| focusable<sup>7+</sup>                | boolean                   | 是   | 否   | 窗口是否可聚焦，默认为true。                                 |
| touchable<sup>7+</sup>                | boolean                   | 是   | 否   | 窗口是否可触摸，默认为true。                                 |
| brightness                            | number                    | 是   | 是   | 屏幕亮度， 取值范围为0~1，1表示最大亮度值。                  |
| dimBehindValue<sup>(deprecated)</sup> | number                    | 是   | 是   | 靠后窗口的暗度值，取值范围为0~1，1表示最暗。<br>- **说明：** 从API version 9开始废弃。<br>- 从 API version 7开始支持 |
| isKeepScreenOn                        | boolean                   | 是   | 是   | 屏幕是否常亮，默认为false。                                  |
| isPrivacyMode<sup>7+</sup>            | boolean                   | 是   | 是   | 隐私模式，默认为false。                                      |
| isRoundCorner<sup>(deprecated)</sup>  | boolean                   | 是   | 是   | 窗口是否为圆角。默认为false。<br>- **说明：** 从API version 9开始废弃。<br/>- 从 API version 7开始支持 |
| isTransparent<sup>7+</sup>            | boolean                   | 是   | 是   | 窗口是否透明。默认为false。                                  |
| id<sup>9+</sup>                       | number                    | 是   | 否   | 窗口ID，默认值为0.0。                                                  |

## ColorSpace<sup>8+</sup>

色域模式。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 默认值 | 说明           |
| ---------- | ------ | -------------- |
| DEFAULT    | 0      | 默认色域模式。 |
| WIDE_GAMUT | 1      | 广色域模式。   |

## ScaleOptions<sup>9+</sup>

缩放参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称   | 参数类型 | 可读 | 可写 | 说明                                               |
| ------ | -------- | ---- | ---- | -------------------------------------------------- |
| x      | number   | 否   | 是   | X轴的缩放参数，默认值为1.0。                       |
| y      | number   | 否   | 是   | Y轴的缩放参数，默认值为1.0。                       |
| pivotX | number   | 否   | 是   | 缩放中心点X轴坐标，默认值为0.5， 取值范围0.0~1.0。 |
| pivotY | number   | 否   | 是   | 缩放中心点Y轴坐标，默认值为0.5， 取值范围0.0~1.0。 |

## RotateOptions<sup>9+</sup>

旋转参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称   | 参数类型 | 可读 | 可写 | 说明                                               |
| ------ | -------- | ---- | ---- | -------------------------------------------------- |
| x      | number   | 否   | 是   | 绕X轴的旋转角度，默认值为0.0。                     |
| y      | number   | 否   | 是   | 绕Y轴的旋转角度，默认值为0.0。                     |
| z      | number   | 否   | 是   | 绕Z轴的旋转角度，默认值为0.0。                     |
| pivotX | number   | 否   | 是   | 旋转中心点X轴坐标，默认值为0.5， 取值范围0.0~1.0。 |
| pivotY | number   | 否   | 是   | 旋转中心点Y轴坐标，默认值为0.5， 取值范围0.0~1.0。 |

## TranslateOptions<sup>9+</sup>

平移参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明                         |
| ---- | -------- | ---- | ---- | ---------------------------- |
| x    | number   | 否   | 是   | X轴的平移参数，默认值为0.0。 |
| y    | number   | 否   | 是   | Y轴的平移参数，默认值为0.0。 |
| z    | number   | 否   | 是   | Z轴的平移参数，默认值为0.0。 |

## window.create<sup>7+</sup>

create(id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

创建子窗口，使用callback异步回调。

**模型约束：** 此接口仅可在FA模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                 |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | 是   | 窗口id。                             |
| type     | [WindowType](#windowtype7)              | 是   | 窗口类型。                           |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前创建的子窗口对象。 |

**示例：**

```js
let windowClass = null;
window.create('first', window.WindowType.TYPE_APP,(err,data) => {
    if(err.code){
        console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));
});
```

## window.create<sup>7+</sup>

create(id: string, type: WindowType): Promise&lt;Window&gt;

创建子窗口，使用Promise异步回调。

**模型约束：** 此接口仅可在FA模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| id     | string                    | 是   | 窗口id。   |
| type   | [WindowType](#windowtype7) | 是   | 窗口类型。 |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise对象。返回当前创建的子窗口对象。 |

**示例：**

```js
let windowClass = null;
let promise = window.create('first', window.WindowType.TYPE_APP);
promise.then((data)=> {
    windowClass = data;
    console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
});
```

## window.create<sup>8+</sup>

create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

创建子窗口，使用callback异步回调，其中Context详见[Context](js-apis-Context.md)。

从API version 9开始，当Context为[ServiceExtensionContext](js-apis-service-extension-context.md)时，创建系统窗口，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| ctx      | Context                                | 是   | 当前应用上下文信息。<br>API version 8的Context定义见[Context](js-apis-Context.md)。<br>API version 9的Context定义见[Context](js-apis-service-extension-context.md)。 |
| id       | string                                 | 是   | 窗口id。                                                     |
| type     | [WindowType](#windowtype7)              | 是   | 窗口类型。                                                   |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前创建的子窗口对象。                         |

**示例：**

```js
let windowClass = null;
 window.create(this.context, 'alertWindow', window.WindowType.TYPE_SYSTEM_ALERT, (err, data) => {
    if (err.code) {
        console.error('Failed to create the window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));
    windowClass.resetSize(500, 1000);
});
```

## window.create<sup>8+</sup>

create(ctx: Context, id: string, type: WindowType): Promise&lt;Window&gt;

创建子窗口，使用Promise异步回调，其中Context详见[Context](js-apis-Context.md)。

从API version 9开始，当Context为[ServiceExtensionContext](js-apis-service-extension-context.md)时，创建系统窗口，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明                                                         |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| ctx    | Context                   | 是   | 当前应用上下文信息。<br/>API version 8的Context定义见[Context](js-apis-Context.md)。<br/>API version 9的Context定义见[Context](js-apis-service-extension-context.md)。 |
| id     | string                    | 是   | 窗口id。                                                     |
| type   | [WindowType](#windowtype7) | 是   | 窗口类型。                                                   |

**返回值：**

| 类型                             | 说明                                    |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise对象。返回当前创建的子窗口对象。 |

**示例：**

```js
let windowClass = null;
let promise = window.create(this.context, 'alertWindow', window.WindowType.TYPE_SYSTEM_ALERT);
promise.then((data)=> {
    windowClass = data;
    console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to create the Window. Cause:' + JSON.stringify(err));
});
```

## window.find<sup>7+</sup>

find(id: string, callback: AsyncCallback&lt;Window&gt;): void

查找id所对应的窗口，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                 |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | 是   | 窗口id。                             |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前查找到的窗口对象。 |

**示例：**

```js
let windowClass = null;
 window.find('alertWindow', (err, data) => {
   if (err.code) {
       console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
       return;
   }
   windowClass = data;
   console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));
});
```

## window.find<sup>7+</sup>

find(id: string): Promise&lt;Window&gt;

查找id所对应的窗口，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| id     | string | 是   | 窗口id。 |

**返回值：**

| 类型                             | 说明                                  |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise对象。返回当前查找的窗口对象。 |

**示例：**

```js
let windowClass = null;
let promise = window.find('alertWindow');
promise.then((data)=> {
 	windowClass = data;
    console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
});
```

## window.getTopWindow

getTopWindow(callback: AsyncCallback&lt;Window&gt;): void

获取当前应用内最后显示的窗口，使用callback异步回调。

**模型约束：** 此接口仅可在FA模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                         |
| -------- | -------------------------------------- | ---- | -------------------------------------------- |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前应用内最后显示的窗口对象。 |

**示例：**

```js
let windowClass = null;
window.getTopWindow((err, data) => {
    if (err.code) {
        console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
});
```

## window.getTopWindow

getTopWindow(): Promise&lt;Window&gt;

获取当前应用内最后显示的窗口，使用Promise异步回调。

**模型约束：** 此接口仅可在FA模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                             | 说明                                            |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise对象。返回当前应用内最后显示的窗口对象。 |

**示例：**

```js
let windowClass = null;
let promise = window.getTopWindow();
promise.then((data)=> {
 	windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
})
```

## window.getTopWindow<sup>8+</sup>

getTopWindow(ctx: Context, callback: AsyncCallback&lt;Window&gt;): void

获取当前应用内最后显示的窗口，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| ctx      | Context                                | 是   | 当前应用上下文信息。<br>API version 8的Context定义见[Context](js-apis-Context.md)。<br>API version 9的Context定义见[Context](js-apis-ability-context.md)。 |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前应用内最后显示的窗口对象。                 |

**示例：**

```js
let windowClass = null;
window.getTopWindow(this.context, (err, data) => {
    if (err.code) {
        console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
});
```

## window.getTopWindow<sup>8+</sup>

getTopWindow(ctx: Context): Promise&lt;Window&gt;

获取当前应用内最后显示的窗口，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| ctx    | Context | 是   | 当前应用上下文信息。<br/>API version 8的Context定义见[Context](js-apis-Context.md)。<br/>API version 9的Context定义见[Context](js-apis-ability-context.md)。 |

**返回值：**

| 类型                             | 说明                                            |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise对象。返回当前应用内最后显示的窗口对象。 |

**示例：**

```js
let windowClass = null;
let promise = window.getTopWindow(this.context);
promise.then((data)=> {
 	windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
})
```

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number, callback: AsyncCallback&lt;void&gt;): void

最小化某显示设备下的所有窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | 是   | 显示设备[Display](js-apis-display.md#display)的ID号 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。     |

**示例：**

```js
import display from '@ohos.display'
import window from '@ohos.window'

let displayClass = null;
display.getDefaultDisplay((err, data) => {
    if(err.code) {
        return;
    }
    displayClass = data;
    window.minimizeAll(displayClass.id, (err, data) => {
        if(err.code) {
            console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in minimizing all windows.');
    });
});
```

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number): Promise&lt;void&gt;

最小化某显示设备下的所有窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | 是   | 显示设备[Display](js-apis-display.md#display)的ID号 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
import display from '@ohos.display'
import window from '@ohos.window'

let displayClass = null;
display.getDefaultDisplay((err, data) => {
    if(err.code) {
        return;
    }
    displayClass = data;
    let promise = window.minimizeAll(displayClass.id);
    promise.then((data)=> {
        console.info('Succeeded in minimizing all windows.');
    }).catch((err)=>{
        console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(err));
    })
});
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

**示例：**

```js
window.toggleShownStateForAllAppWindows((err, data) => {
    if (err.code) {
        console.error('Failed to toggle shown state for all app windows. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in toggling shown state for all app windows.');
})
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

**示例：**

```js
let promise = window.toggleShownStateForAllAppWindows();
promise.then((data)=> {
    console.info('Succeeded in toggling shown state for all app windows. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to toggle shown state for all app windows. Cause: ' + JSON.stringify(err));
})
```

## window.setWindowLayoutMode<sup>9+</sup>
setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback&lt;void&gt;): void

设置窗口布局模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmode9)                  | 是   | 设置的窗口布局模式 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。     |

**示例：**

```js
window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE, (data) => {
    console.info('Succeeded in setting window layout mode. Data: ' + JSON.stringify(data));
});
```

## window.setWindowLayoutMode<sup>9+</sup>
setWindowLayoutMode(mode: WindowLayoutMode): Promise&lt;void&gt;

设置窗口布局模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmode9)                    | 是   | 设置的窗口布局模式 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE);
promise.then((data)=> {
    console.info('Succeeded in setting window layout mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(err));
})
```

## on('systemBarTintChange')<sup>8+</sup>

on(type: 'systemBarTintChange', callback: Callback&lt;SystemBarTintState&gt;): void

开启状态栏、导航栏属性变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | 是   | 监听事件，固定为'systemBarTintChange'，即导航栏、状态栏属性变化事件。 |
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | 是   | 回调函数。返回当前的状态栏、导航栏信息集合。                 |

**示例：**

```js
window.on('systemBarTintChange', (data) => {
    console.info('Succeeded in enabling the listener for systemBarTint changes. Data: ' + JSON.stringify(data));
});
```

## off('systemBarTintChange')<sup>8+</sup>

off(type: 'systemBarTintChange', callback?: Callback&lt;SystemBarTintState &gt;): void

关闭状态栏、导航栏属性变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | 是   | 监听事件，固定为'systemBarTintChange'，即导航栏、状态栏属性变化事件。 |
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | 否   | 回调函数。返回当前的状态栏、导航栏信息集合。                 |

**示例：**

```js
window.off('systemBarTintChange');
```

## Window

当前窗口实例，窗口管理器管理的基本单元。

下列API示例中都需先使用[getTopWindow()](#windowgettopwindow)、[create()](#windowcreate7)、[find()](#windowfind7)中的任一方法获取到Window实例，再通过此实例调用对应方法。

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

隐藏当前窗口，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
windowClass.hide((err, data) => {
    if (err.code) {
        console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in hiding the window. data: ' + JSON.stringify(data));
})
```

### hide<sup>7+</sup>

hide(): Promise&lt;void&gt;

隐藏当前窗口，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.hide();
promise.then((data)=> {
    console.info('Succeeded in hiding the window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
})
```

### hideWithAnimation<sup>9+</sup>

hideWithAnimation(callback: AsyncCallback&lt;void&gt;): void

隐藏当前窗口，过程中播放动画，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
windowClass.hideWithAnimation((err, data) => {
    if (err.code) {
        console.error('Failed to hide the window with animation. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in hiding the window with animation. data: ' + JSON.stringify(data));
})
```

### hideWithAnimation<sup>9+</sup>

hideWithAnimation(): Promise&lt;void&gt;

隐藏当前窗口，过程中播放动画，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.hideWithAnimation();
promise.then((data)=> {
    console.info('Succeeded in hiding the window with animation. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to hide the window with animation. Cause: ' + JSON.stringify(err));
})
```

### show<sup>7+</sup>

show(callback: AsyncCallback&lt;void&gt;): void

显示当前窗口，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
windowClass.show((err, data) => {
    if (err.code) {
        console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in showing the window. Data: ' + JSON.stringify(data));
})
```

### show<sup>7+</sup>

show(): Promise&lt;void&gt;

显示当前窗口，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.show();
promise.then((data)=> {
    console.info('Succeeded in showing the window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
})
```

### showWithAnimation<sup>9+</sup>

showWithAnimation(callback: AsyncCallback&lt;void&gt;): void

显示当前窗口，过程中播放动画，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
windowClass.showWithAnimation((err, data) => {
    if (err.code) {
        console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in showing the window with animation. Data: ' + JSON.stringify(data));
})
```

### showWithAnimation<sup>9+</sup>

showWithAnimation(): Promise&lt;void&gt;

显示当前窗口，过程中播放动画，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.showWithAnimation();
promise.then((data)=> {
    console.info('Succeeded in showing the window with animation. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));
})
```

### destroy<sup>7+</sup>

destroy(callback: AsyncCallback&lt;void&gt;): void

销毁当前窗口，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
windowClass.destroy((err, data) => {
    if (err.code) {
        console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in destroying the window. Data: ' + JSON.stringify(data));
})
```

### destroy<sup>7+</sup>

destroy(): Promise&lt;void&gt;

销毁当前窗口，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.destroy();
promise.then((data)=> {
    console.info('Succeeded in destroying the window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
})
```

### moveTo<sup>7+</sup>

moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

移动窗口位置，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                              |
| -------- | ------------------------- | ---- | ------------------------------------------------- |
| x        | number                    | 是   | 窗口在x轴方向移动的值，值为正表示右移，单位为px。 |
| y        | number                    | 是   | 窗口在y轴方向移动的值，值为正表示下移，单位为px。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                        |

**示例：**

```js
windowClass.moveTo(300, 300, (err, data)=>{
    if (err.code) {
        console.error('Failed to move the window. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in moving the window. Data: ' + JSON.stringify(data));

});
```

### moveTo<sup>7+</sup>

moveTo(x: number, y: number): Promise&lt;void&gt;

移动窗口位置，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                              |
| ------ | ------ | ---- | ------------------------------------------------- |
| x      | number | 是   | 窗口在x轴方向移动的值，值为正表示右移，单位为px。 |
| y      | number | 是   | 窗口在y轴方向移动的值，值为正表示下移，单位为px。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.moveTo(300, 300);
promise.then((data)=> {
    console.info('Succeeded in moving the window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to move the window. Cause: ' + JSON.stringify(err));
})
```

### resetSize<sup>7+</sup>

resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

改变当前窗口大小，使用callback异步回调。

应用主窗口与子窗口存在大小限制，宽度范围：[320,2560]，高度范围：[240,2560]，单位为vp。

系统窗口存在大小限制，宽度范围：[0,2560]，高度范围：[0,2560]，单位为vp。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                       |
| -------- | ------------------------- | ---- | -------------------------- |
| width    | number                    | 是   | 目标窗口的宽度，单位为px。 |
| height   | number                    | 是   | 目标窗口的高度，单位为px。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                 |

**示例：**

```js
windowClass.resetSize(500, 1000, (err, data) => {
    if (err.code) {
        console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in changing the window size. Data: ' + JSON.stringify(data));
});
```

### resetSize<sup>7+</sup>

resetSize(width: number, height: number): Promise&lt;void&gt;

改变当前窗口大小，使用Promise异步回调。

应用主窗口与子窗口存在大小限制，宽度范围：[320,2560]，高度范围：[240,2560]，单位为vp。

系统窗口存在大小限制，宽度范围：[0,2560]，高度范围：[0,2560]，单位为vp。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| width  | number | 是   | 目标窗口的宽度，单位为px。 |
| height | number | 是   | 目标窗口的高度，单位为px。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.resetSize(500, 1000);
promise.then((data)=> {
    console.info('Succeeded in changing the window size. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to change the window size. Cause: ' + JSON.stringify(err));
});
```

### setWindowType<sup>(deprecated)</sup>

setWindowType(type: WindowType, callback: AsyncCallback&lt;void&gt;): void

设置窗口类型，使用callback异步回调。

**系统接口：** 此接口为系统接口。

> **说明：** 从API version 9开始废弃。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| type     | [WindowType](#windowtype7) | 是   | 窗口类型。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
let type = window.WindowType.TYPE_APP;
windowClass.setWindowType(type, (err, data) => {
  if (err.code) {
      console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
      return;
  }
  console.info('Succeeded in setting the window type. Data: ' + JSON.stringify(data));
});
```

### setWindowType<sup>(deprecated)</sup>

setWindowType(type: WindowType): Promise&lt;void&gt;

设置窗口类型，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

> **说明：** 从API version 9开始废弃。
>
> 从 API version 7开始支持。

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

```js
let type = window.WindowType.TYPE_APP;
let promise = windowClass.setWindowType(type);
promise.then((data)=> {
    console.info('Succeeded in setting the window type. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
});
```

### getProperties

getProperties(callback: AsyncCallback&lt;WindowProperties&gt;): void

获取当前窗口的属性，使用callback异步回调，返回WindowProperties。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                         |
| -------- | ---------------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;[WindowProperties](#windowproperties)&gt; | 是   | 回调函数。返回当前窗口属性。 |

**示例：**

```js
windowClass.getProperties((err, data) => {
    if (err.code) {
        console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
});
```

### getProperties

getProperties(): Promise&lt;WindowProperties&gt;

获取当前窗口的属性，使用Promise异步回调，返回WindowProperties。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                                 | 说明                            |
| ---------------------------------------------------- | ------------------------------- |
| Promise&lt;[WindowProperties](#windowproperties)&gt; | Promise对象。返回当前窗口属性。 |

**示例：**

```js
let promise = windowClass.getProperties();
promise.then((data)=> {
    console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
});
```

### getAvoidArea<sup>7+</sup>

getAvoidArea(type: [AvoidAreaType](#avoidareatype7), callback: AsyncCallback&lt;[AvoidArea](#avoidarea7)&gt;): void

获取窗口内容规避的区域，如系统的系统栏区域、凹凸区域。使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                         |
| -------- |-----------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | [AvoidAreaType](#avoidareatype7)              | 是   | 表示规避区类型。type为TYPE_SYSTEM，表示系统默认区域。type为TYPE_CUTOUT，表示刘海屏区域。type为TYPE_SYSTEM_GESTURE，表示手势区域。type为TYPE_KEYBOARD，表示软键盘区域。 |
| callback | AsyncCallback&lt;[AvoidArea](#avoidarea7)&gt; | 是   | 回调函数。返回窗口内容规避区域。                             |

**示例：**

```js
let type = window.AvoidAreaType.TYPE_SYSTEM;
windowClass.getAvoidArea(type, (err, data) => {
    if (err.code) {
        console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
});
```

### getAvoidArea<sup>7+</sup>

getAvoidArea(type: [AvoidAreaType](#avoidareatype7)): Promise&lt;[AvoidArea](#avoidarea7)&gt;

获取窗口内容规避的区域，如系统的系统栏区域、凹凸区域。使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                               | 必填 | 说明                                                         |
| ------ |----------------------------------| ---- | ------------------------------------------------------------ |
| type   | [AvoidAreaType](#avoidareatype7) | 是   | 表示规避区类型。type为TYPE_SYSTEM，表示系统默认区域。type为TYPE_CUTOUT，表示刘海屏区域。type为TYPE_SYSTEM_GESTURE，表示手势区域。type为TYPE_KEYBOARD，表示软键盘区域。 |

**返回值：**

| 类型                                      | 说明                                |
|-----------------------------------------| ----------------------------------- |
| Promise&lt;[AvoidArea](#avoidarea7)&gt; | Promise对象。返回窗口内容规避区域。 |

**示例：**

```js
let type = window.AvoidAreaType.TYPE_SYSTEM;
let promise = windowClass.getAvoidArea(type);
promise.then((data)=> {
    console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
});
```

### setFullScreen

setFullScreen(isFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置是否为全屏状态，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                                           |
| ------------ | ------------------------- | ---- | ---------------------------------------------- |
| isFullScreen | boolean                   | 是   | 是否设为全屏状态，且全屏状态隐藏状态栏导航栏。 |
| callback     | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                     |

**示例：**

```js
let isFullScreen = true;
windowClass.setFullScreen(isFullScreen, (err, data) => {
    if (err.code) {
        console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
});
```

### setFullScreen

setFullScreen(isFullScreen: boolean): Promise&lt;void&gt;

设置是否为全屏状态，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型    | 必填 | 说明                                           |
| ------------ | ------- | ---- | ---------------------------------------------- |
| isFullScreen | boolean | 是   | 是否设为全屏状态，且全屏状态隐藏状态栏导航栏。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let isFullScreen = true;
let promise = windowClass.setFullScreen(isFullScreen);
promise.then((data)=> {
    console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
});
```

### setLayoutFullScreen<sup>7+</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口的布局是否为全屏显示状态，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名             | 类型                      | 必填 | 说明                                                         |
| ------------------ | ------------------------- | ---- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean                   | 是   | 窗口的布局是否为全屏显示状态，且全屏状态下状态栏、导航栏仍然显示。 |
| callback           | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
let isLayoutFullScreen= true;
windowClass.setLayoutFullScreen(isLayoutFullScreen, (err, data) => {
    if (err.code) {
        console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window layout to full-screen mode. Data: ' + JSON.stringify(data));
});
```

### setLayoutFullScreen<sup>7+</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

设置窗口的布局是否为全屏显示状态，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名             | 类型    | 必填 | 说明                                                         |
| ------------------ | ------- | ---- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean | 是   | 窗口的布局是否为全屏显示状态，且全屏状态下状态栏、导航栏仍然显示。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let isLayoutFullScreen = true;
let promise = windowClass.setLayoutFullScreen(isLayoutFullScreen);
promise.then((data)=> {
    console.info('Succeeded in setting the window layout to full-screen mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
});
```

### setSystemBarEnable<sup>7+</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

设置导航栏、状态栏的可见模式，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| names    | Array                     | 是   | 设置状态栏和导航栏是否显示。<br>例如，需全部显示，该参数设置为['status',&nbsp;'navigation']；不设置，则默认不显示。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
// 此处以不显示导航栏、状态栏为例
let names = [];
windowClass.setSystemBarEnable(names, (err, data) => {
    if (err.code) {
        console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the system bar to be invisible. Data: ' + JSON.stringify(data));
});
```

### setSystemBarEnable<sup>7+</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

设置导航栏、状态栏的可见模式，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型  | 必填 | 说明                                                         |
| ------ | ----- | ---- | ------------------------------------------------------------ |
| names  | Array | 是   | 设置状态栏和导航栏是否显示。<br>例如，需全部显示，该参数设置为['status',&nbsp;'navigation']；不设置，则默认不显示。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
// 此处以不显示导航栏、状态栏为例
let names = [];
let promise = windowClass.setSystemBarEnable(names);
promise.then((data)=> {
    console.info('Succeeded in setting the system bar to be invisible. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));
});
```

### setSystemBarProperties

setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

设置窗口内导航栏、状态栏的属性，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| SystemBarProperties | [SystemBarProperties](#systembarproperties) | 是   | 导航栏、状态栏的属性。 |
| callback            | AsyncCallback&lt;void&gt;                   | 是   | 回调函数。             |

**示例：**

```js
let SystemBarProperties={
    statusBarColor: '#ff00ff',
    navigationBarColor: '#00ff00',
    //以下两个属性从API Version8开始支持
    statusBarContentColor:'#ffffff',
    navigationBarContentColor:'#00ffff'
};
windowClass.setSystemBarProperties(SystemBarProperties, (err, data) => {
    if (err.code) {
        console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the system bar properties. Data: ' + JSON.stringify(data));
});
```

### setSystemBarProperties

setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

设置窗口内导航栏、状态栏的属性，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| SystemBarProperties | [SystemBarProperties](#systembarproperties) | 是   | 导航栏、状态栏的属性。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let SystemBarProperties={
    statusBarColor: '#ff00ff',
    navigationBarColor: '#00ff00',
    //以下两个属性从API Version8开始支持
    statusBarContentColor:'#ffffff',
    navigationBarContentColor:'#00ffff'
};
let promise = windowClass.setSystemBarProperties(SystemBarProperties);
promise.then((data)=> {
    console.info('Succeeded in setting the system bar properties. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
});
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

设置窗口的显示方向属性，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| Orientation         | [Orientation](#orientation9)                | 是   | 窗口显示方向的属性。         |
| callback            | AsyncCallback&lt;void&gt;                   | 是   | 回调函数。             |

**示例：**

```js
let orientation = window.Orientation.AUTO_ROTATION;
windowClass.setPreferredOrientation(orientation, (err, data) => {
    if (err.code) {
        console.error('Failed to set window orientation. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting window orientation. Data: ' + JSON.stringify(data));
});
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation): Promise&lt;void&gt;

设置窗口的显示方向属性，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名              | 类型                                        | 必填 | 说明                   |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| Orientation         | [Orientation](#orientation9)                | 是   | 窗口显示方向的属性。       |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let orientation = window.Orientation.AUTO_ROTATION;
let promise = windowClass.setPreferredOrientation(orientation);
promise.then((data)=> {
    console.info('Succeeded in setting the window orientation. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window orientation. Cause: ' + JSON.stringify(err));
});
```

### loadContent<sup>7+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

为当前窗口加载具体页面内容，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| path     | string                    | 是   | 设置加载页面的路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```js
windowClass.loadContent('pages/page2/page2', (err, data) => {
   if (err.code) {
         console.error('Failed to load the content. Cause:' + JSON.stringify(err));
         return;
   }
  console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
});
```

### loadContent<sup>7+</sup>

loadContent(path: string): Promise&lt;void&gt;

为当前窗口加载具体页面内容，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| path   | string | 是   | 设置加载页面的路径。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.loadContent('pages/page2/page2');
promise.then((data)=> {
    console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
});
```
### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

为当前窗口加载与LocalStorage相关联的具体页面内容，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                         |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | 是   | 设置加载页面的路径。                                         |
| storage  | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | 是   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。 |
| callback | AsyncCallback&lt;void&gt;                       | 是   | 回调函数。                                                   |

**示例：**

```ts
class myAbility extends Ability {
    storage : LocalStorage
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate('storageSimpleProp',121);
        console.log('onWindowStageCreate');
        windowStage.loadContent('pages/page2',this.storage,(err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage): Promise&lt;void&gt;

为当前窗口加载与LocalStorage相关联的具体页面内容，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                            | 必填 | 说明                                                         |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | 是   | 设置加载页面的路径。                                         |
| storage | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | 是   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
class myAbility extends Ability {
    storage : LocalStorage
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate('storageSimpleProp',121);
        console.log('onWindowStageCreate');
        let windowClass = null;
        let promise = windowStage.loadContent('pages/page2',this.storage);
        promise.then((data)=> {
            windowClass = data;
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
        })
    }
}
```
### isShowing<sup>7+</sup>

isShowing(callback: AsyncCallback&lt;boolean&gt;): void

判断当前窗口是否已显示，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前窗口已显示，返回false则表示当前窗口未显示。 |

**示例：**

```js
windowClass.isShowing((err, data) => {
    if (err.code) {
        console.error('Failed to check whether the window is showing. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
});
```

### isShowing<sup>7+</sup>

isShowing(): Promise&lt;boolean&gt;

判断当前窗口是否已显示，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前窗口已显示，返回false则表示当前窗口未显示。 |

**示例：**

```js
let promise = windowClass.isShowing();
promise.then((data)=> {
    console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to check whether the window is showing. Cause: ' + JSON.stringify(err));
});
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

```js
windowClass.on('windowSizeChange', (data) => {
    console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
});
```

### off('windowSizeChange')<sup>7+</sup>

off(type: 'windowSizeChange', callback?: Callback&lt;Size &gt;): void

关闭窗口尺寸变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                                     |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | 是   | 监听事件，固定为'windowSizeChange'，即窗口尺寸变化事件。 |
| callback | Callback&lt;[Size](#size)&gt; | 否   | 回调函数。返回当前的窗口尺寸。                           |

**示例：**

```js
windowClass.off('windowSizeChange');
```

### on('systemAvoidAreaChange')<sup>(deprecated)</sup>

on(type: 'systemAvoidAreaChange', callback: Callback&lt;[AvoidArea](#avoidarea7)&gt;): void

开启系统规避区变化的监听。
> **说明：** 从API version 9开始废弃，推荐使用[on('avoidAreaChange')](#onavoidareachange9)。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'systemAvoidAreaChange'，即系统规避区变化事件。 |
| callback | Callback&lt;[AvoidArea](#avoidarea7)&gt; | 是   | 回调函数。返回当前规避区。                             |

**示例：**

```js
windowClass.on('systemAvoidAreaChange', (data) => {
    console.info('Succeeded in enabling the listener for system avoid area changes. Data: ' + JSON.stringify(data));
});
```

### off('systemAvoidAreaChange')<sup>(deprecated)</sup>

off(type: 'systemAvoidAreaChange', callback?: Callback&lt;[AvoidArea](#avoidarea7)&gt;): void

关闭系统规避区变化的监听。
> **说明：** 从API version 9开始废弃，推荐使用[off('avoidAreaChange')](#offavoidareachange9)。
>
> 从 API version 7开始支持。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'systemAvoidAreaChange'，即系统规避区变化事件。 |
| callback | Callback&lt;[AvoidArea](#avoidarea7)&gt; | 否   | 回调函数。返回当前规避区。                            |

**示例：**

```js
windowClass.off('systemAvoidAreaChange');
```


### on('avoidAreaChange')<sup>9+</sup>

on(type: 'avoidAreaChange', callback: Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt;): void

开启系统规避区变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                               | 必填 | 说明                                   |
| -------- |------------------------------------------------------------------| ---- |--------------------------------------|
| type     | string                                                           | 是   | 监听事件，固定为'avoidAreaChange'，即系统规避区变化事件。 |
| callback | Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt; | 是   | 回调函数。返回当前规避区以及规避区类型。|

**示例：**

```js
windowClass.on('avoidAreaChange', (data) => {
    console.info('Succeeded in enabling the listener for system avoid area changes. type:'  + JSON.stringify(data.type) + ', area: ' + JSON.stringify(data.area));
});
```

### off('avoidAreaChange')<sup>9+</sup>

off(type: 'avoidAreaChange', callback: Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt;): void

关闭系统规避区变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                                          | 必填  | 说明                                 |
| -------- |-----------------------------------------------------------------------------|-----|------------------------------------|
| type     | string                                                                      | 是   | 监听事件，固定为'avoidAreaChange'，即系统规避区变化事件。 |
| callback | Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt; | 否   | 回调函数。返回当前规避区以及规避区类型。|

**示例：**

```js
windowClass.off('avoidAreaChange');
```

### on('keyboardHeightChange')<sup>7+</sup>

on(type: 'keyboardHeightChange', callback: Callback&lt;number&gt;): void

开启键盘高度变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'keyboardHeightChange'，即键盘高度变化事件。 |
| callback | Callback<number&gt; | 是   | 回调函数。返回当前的键盘高度。                               |

**示例：**

```js
windowClass.on('keyboardHeightChange', (data) => {
    console.info('Succeeded in enabling the listener for keyboard height changes. Data: ' + JSON.stringify(data));
});
```

### off('keyboardHeightChange')<sup>7+</sup>

off(type: 'keyboardHeightChange', callback?: Callback&lt;number&gt;): void

关闭键盘高度变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'keyboardHeightChange'，即键盘高度变化事件。 |
| callback | Callback&lt;number&gt; | 否   | 回调函数。返回当前的键盘高度。                               |

**示例：**

```js
windowClass.off('keyboardHeightChange');
```

### on('touchOutside')<sup>9+</sup>

on(type: 'touchOutside', callback: Callback&lt;void&gt;): void

开启本窗口区域范围外的点击事件的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'touchOutside'，即本窗口范围外的点击事件。 |
| callback | Callback<void&gt; | 是   | 回调函数。当点击事件发生在本窗口范围之外的回调。                               |

**示例：**

```js
windowClass.on('touchOutside', () => {
    console.info('touch outside');
});
```

### off('touchOutside')<sup>9+</sup>

off(type: 'touchOutside', callback?: Callback&lt;void&gt;): void

关闭本窗口区域范围外的点击事件的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'touchOutside'，即本窗口范围外的点击事件。 |
| callback | Callback&lt;number&gt; | 否   | 回调函数。当点击事件发生在本窗口范围之外的回调。                               |

**示例：**

```js
windowClass.off('touchOutside');
```

### on('screenshot')<sup>9+</sup>

on(type: 'screenshot', callback: Callback&lt;void&gt;): void

开启截屏事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'screenshot'，即截屏事件。 |
| callback | Callback&lt;void&gt; | 是   | 回调函数。发生截屏事件时的回调。                               |

**示例：**

```js
windowClass.on('screenshot', () => {
    console.info('screenshot happened');
});
```

### off('screenshot')<sup>9+</sup>

off(type: 'screenshot', callback?: Callback&lt;void&gt;): void

关闭截屏事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'screenshot'，即截屏事件。 |
| callback | Callback&lt;void&gt; | 否   | 回调函数。发生截屏事件时的回调。 |

**示例：**

```js
let callback = ()=>{
    console.info('screenshot happened');
}
windowClass.on('screenshot', callback)
windowClass.off('screenshot', callback)

// 如果通过on开启多个callback进行监听，同时关闭所有监听：
windowClass.off('screenshot');
```

### on('dialogTargetTouch')<sup>9+</sup>

on(type: 'dialogTargetTouch', callback: Callback&lt;void&gt;): void

开启模态窗口目标窗口的点击事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                          |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | 是   | 监听事件，固定为'dialogTargetTouch'，即模态窗口目标窗口的点击事件。 |
| callback | Callback&lt;void&gt;| 是   | 回调函数。当点击事件发生在模态窗口目标窗口的回调。 |

**示例：**

```js
windowClass.on('dialogTargetTouch', () => {
    console.info('touch dialog target');
});
```

### off('dialogTargetTouch')<sup>9+</sup>

off(type: 'dialogTargetTouch', callback?: Callback&lt;void&gt;): void

关闭模态窗口目标窗口的点击事件的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                          |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'dialogTargetTouch'，即模态窗口目标窗口的点击事件。 |
| callback | Callback&lt;void&gt;      | 否   | 回调函数。当点击事件发生在模态窗口目标窗口的回调。 |

**示例：**

```js
windowClass.off('dialogTargetTouch');
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback&lt;void&gt;, callback: AsyncCallback&lt;void&gt;): void

绑定模态窗口与目标窗口并添加模态窗口销毁监听，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| token       | [rpc.RemoteObject](js-apis-rpc.md#remoteobject) | 是   | 目标窗口token值。 |
| deathCallback | Callback&lt;void&gt;        | 是   | 模态窗口销毁监听。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

```js
class MyDeathRecipient {
    onRemoteDied() {
        console.log('server died');
    }
}
class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor) {
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
let token = new TestRemoteObject('testObject');
windowClass.bindDialogTarget(token, () => {
    console.info('Dialog Window Need Destroy.');
}, (err, data) => {
    if (err.code) {
        console.error('Failed to bind dialog target. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in binding dialog target. Data:' + JSON.stringify(data));
});
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback&lt;void&gt;): Promise&lt;void&gt;

绑定模态窗口与目标窗口并添加模态窗口销毁监听，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| token       | [rpc.RemoteObject](js-apis-rpc.md#remoteobject) | 是   | 目标窗口token值。 |
| deathCallback | Callback&lt;void&gt;        | 是   | 模态窗口销毁监听。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
class MyDeathRecipient {
    onRemoteDied() {
        console.log('server died');
    }
}
class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor) {
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
let token = new TestRemoteObject('testObject');
let promise = windowClass.bindDialogTarget(token, () => {
    console.info('Dialog Window Need Destroy.');
});
promise.then((data)=> {
    console.info('Succeeded in binding dialog target. Data:' + JSON.stringify(data));
}).catch((err)=>{
        console.error('Failed to bind dialog target. Cause:' + JSON.stringify(err));
});
```

### isSupportWideGamut<sup>8+</sup>

isSupportWideGamut(callback: AsyncCallback&lt;boolean&gt;): void

判断当前窗口是否支持广色域模式，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前窗口支持广色域模式，返回false则表示当前窗口不支持广色域模式。 |

**示例：**

```js
windowClass.isSupportWideGamut((err, data) => {
    if (err.code) {
        console.error('Failed to check whether the window support WideGamut. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in checking whether the window support WideGamut Data: ' + JSON.stringify(data));
})
```

### isSupportWideGamut<sup>8+</sup>

isSupportWideGamut(): Promise&lt;boolean&gt;

判断当前窗口是否支持广色域模式，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前窗口支持广色域模式，返回false则表示当前窗口不支持广色域模式。 |

**示例：**

```js
let promise = windowClass.isSupportWideGamut();
promise.then((data)=> {
    console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to check whether the window support WideGamut. Cause: ' + JSON.stringify(err));
});
```

### setColorSpace<sup>8+</sup>

setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback&lt;void&gt;): void

设置当前窗口为广色域模式或默认色域模式，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明         |
| ---------- | ------------------------- | ---- | ------------ |
| colorSpace | [ColorSpace](#colorspace) | 是   | 设置色域模式 |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。   |

**示例：**

```js
windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT, (err, data) => {
    if (err.code) {
        console.error('Failed to set window colorspace. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting window colorspace. Data: ' + JSON.stringify(data));
})
```

### setColorSpace<sup>8+</sup>

setColorSpace(colorSpace:ColorSpace): Promise&lt;void&gt;

设置当前窗口为广色域模式或默认色域模式，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明           |
| ---------- | ------------------------- | ---- | -------------- |
| colorSpace | [ColorSpace](#colorspace) | 是   | 设置色域模式。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT);
promise.then((data)=> {
    console.info('Succeeded in setting window colorspace. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set window colorspace. Cause: ' + JSON.stringify(err));
});
```

### getColorSpace<sup>8+</sup>

getColorSpace(callback: AsyncCallback&lt;ColorSpace&gt;): void

获取当前窗口色域模式，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                           | 必填 | 说明                                                       |
| -------- | ---------------------------------------------- | ---- | ---------------------------------------------------------- |
| callback | AsyncCallback&lt;[ColorSpace](#colorspace)&gt; | 是   | 回调函数。当获取成功，err为undefined，data为当前色域模式。 |

**示例：**

```js
windowClass.getColorSpace((err, data) => {
    if (err.code) {
        console.error('Failed to get window colorspace. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in getting window colorspace. Cause:' + JSON.stringify(data));
})
```

### getColorSpace<sup>8+</sup>

getColorSpace(): Promise&lt;ColorSpace&gt;

获取当前窗口色域模式，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                     | 说明                            |
| ---------------------------------------- | ------------------------------- |
| Promise&lt;[ColorSpace](#colorspace)&gt; | Promise对象。返回当前色域模式。 |

**示例：**

```js
let promise = windowClass.getColorSpace();
promise.then((data)=> {
    console.info('Succeeded in getting window color space. Cause:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to get window colorspace. Cause: ' + JSON.stringify(err));
});
```

### setBackgroundColor

setBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void

设置窗口的背景色，使用callback异步回调。Stage模型下，该接口需要在[loadContent](#loadcontent9)之后使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| color    | string                    | 是   | 需要设置的背景色，为十六进制颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
let color = '#00ff33';
windowClass.setBackgroundColor(color, (err, data) => {
    if (err.code) {
        console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the background color. Data: ' + JSON.stringify(data));
});
```

### setBackgroundColor

setBackgroundColor(color: string): Promise&lt;void&gt;

设置窗口的背景色，使用Promise异步回调。Stage模型下，该接口需要在[loadContent](#loadcontent9)之后使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| color  | string | 是   | 需要设置的背景色，为十六进制颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let color = '#00ff33';
let promise = windowClass.setBackgroundColor(color);
promise.then((data)=> {
    console.info('Succeeded in setting the background color. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));
});
```

### setWakeUpScreen()<sup>9+</sup>

setWakeUpScreen(wakeUp: boolean): void;

窗口唤醒屏幕。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型    | 必填 | 说明                         |
| ---------------- | ------- | ---- | ---------------------------- |
| wakeUp           | boolean | 是   | 是否设置唤醒屏幕。 |

**示例：**

```js
let wakeUp = true;
windowClass.setWakeUpScreen(wakeUp);
```

### setBrightness

setBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

设置屏幕亮度值，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明                                 |
| ---------- | ------------------------- | ---- | ------------------------------------ |
| brightness | number                    | 是   | 屏幕亮度值，值为0-1之间。1表示最亮。 |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。                           |

**示例：**

```js
let brightness = 1;
windowClass.setBrightness(brightness, (err, data) => {
    if (err.code) {
        console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the brightness. Data: ' + JSON.stringify(data));
});
```

### setBrightness

setBrightness(brightness: number): Promise&lt;void&gt;

设置屏幕亮度值，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                 |
| ---------- | ------ | ---- | ------------------------------------ |
| brightness | number | 是   | 屏幕亮度值，值为0-1之间。1表示最亮。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let brightness = 1;
let promise = windowClass.setBrightness(brightness);
promise.then((data)=> {
    console.info('Succeeded in setting the brightness. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
});
```

### setDimBehind<sup>(deprecated)</sup>

setDimBehind(dimBehindValue: number, callback: AsyncCallback&lt;void&gt;): void

窗口叠加时，设备有子窗口的情况下设置靠后的窗口的暗度值，使用callback异步回调。

> **说明：** 该接口不支持使用。
>
> 从API version 9开始废弃。从API Version 7开始支持。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型                      | 必填 | 说明                                               |
| -------------- | ------------------------- | ---- | -------------------------------------------------- |
| dimBehindValue | number                    | 是   | 表示靠后的窗口的暗度值，取值范围为0-1，1表示最暗。 |
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                         |

**示例：**

```js
windowClass.setDimBehind(0.5, (err, data) => {
    if (err.code) {
        console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the dimness. Data:' + JSON.stringify(data));
});
```

### setDimBehind<sup>(deprecated)</sup>

setDimBehind(dimBehindValue: number): Promise&lt;void&gt;

窗口叠加时，设备有子窗口的情况下设置靠后的窗口的暗度值，使用Promise异步回调。

> **说明：** 该接口不支持使用。
>
> 从API version 9开始废弃。从API Version 7开始支持。

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

```js
let promise = windowClass.setDimBehind(0.5);
promise.then((data)=> {
    console.info('Succeeded in setting the dimness. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));
});
```

### setFocusable<sup>7+</sup>

setFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置点击时是否支持切换焦点窗口，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                         |
| ----------- | ------------------------- | ---- | ---------------------------- |
| isFocusable | boolean                   | 是   | 点击时是否支持切换焦点窗口。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。                   |

**示例：**

```js
let isFocusable= true;
windowClass.setFocusable(isFocusable, (err, data) => {
    if (err.code) {
        console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to be focusable. Data: ' + JSON.stringify(data));
});
```

### setFocusable<sup>7+</sup>

setFocusable(isFocusable: boolean): Promise&lt;void&gt;

设置点击时是否支持切换焦点窗口，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                         |
| ----------- | ------- | ---- | ---------------------------- |
| isFocusable | boolean | 是   | 点击时是否支持切换焦点窗口。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let isFocusable= true;
let promise = windowClass.setFocusable(isFocusable);
promise.then((data)=> {
    console.info('Succeeded in setting the window to be focusable. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window to be focusable. Cause: ' + JSON.stringify(err));
});
```

### setKeepScreenOn

setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

设置屏幕是否为常亮状态，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型                      | 必填 | 说明                     |
| -------------- | ------------------------- | ---- | ------------------------ |
| isKeepScreenOn | boolean                   | 是   | 设置屏幕是否为常亮状态。 |
| callback       | AsyncCallback&lt;void&gt; | 是   | 回调函数。               |

**示例：**

```js
let isKeepScreenOn = true;
windowClass.setKeepScreenOn(isKeepScreenOn, (err, data) => {
    if (err.code) {
        console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the screen to be always on. Data: ' + JSON.stringify(data));
});
```

### setKeepScreenOn

setKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt;

设置屏幕是否为常亮状态，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名         | 类型    | 必填 | 说明                     |
| -------------- | ------- | ---- | ------------------------ |
| isKeepScreenOn | boolean | 是   | 设置屏幕是否为常亮状态。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let isKeepScreenOn = true;
let promise = windowClass.setKeepScreenOn(isKeepScreenOn);
promise.then((data) => {
    console.info('Succeeded in setting the screen to be always on. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.info('Failed to set the screen to be always on. Cause:  ' + JSON.stringify(err));
});
```

### setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置是否允许可点击子窗口之外的区域，使用callback异步回调。

> **说明：** 该接口不支持使用。
>
> 从API version 9开始废弃。从API Version 7开始支持。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                      | 必填 | 说明             |
| --------- | ------------------------- | ---- | ---------------- |
| touchable | boolean                   | 是   | 设置是否可点击。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。       |

**示例：**

```js
windowClass.setOutsideTouchable(true, (err, data) => {
    if (err.code) {
        console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the area to be touchable. Data: ' + JSON.stringify(data));
})
```

### setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean): Promise&lt;void&gt;

设置是否允许可点击子窗口之外的区域，使用Promise异步回调。。

> **说明：** 该接口不支持使用。
>
> 从API version 9开始废弃。从 API version 7开始支持。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型    | 必填 | 说明             |
| --------- | ------- | ---- | ---------------- |
| touchable | boolean | 是   | 设置是否可点击。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let promise = windowClass.setOutsideTouchable(true);
promise.then((data)=> {
    console.info('Succeeded in setting the area to be touchable. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));
});
```

### setPrivacyMode<sup>7+</sup>

setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为隐私模式，使用callback异步回调。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型                      | 必填 | 说明                 |
| ------------- | ------------------------- | ---- | -------------------- |
| isPrivacyMode | boolean                   | 是   | 窗口是否为隐私模式。 |
| callback      | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```js
let isPrivacyMode = true;
windowClass.setPrivacyMode(isPrivacyMode, (err, data) => {
    if (err.code) {
        console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to privacy mode. Data:' + JSON.stringify(data));

});
```

### setPrivacyMode<sup>7+</sup>

setPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

设置窗口是否为隐私模式，使用Promise异步回调。设置为隐私模式的窗口，窗口内容将无法被截屏或录屏。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型    | 必填 | 说明                 |
| ------------- | ------- | ---- | -------------------- |
| isPrivacyMode | boolean | 是   | 窗口是否为隐私模式。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let isPrivacyMode = true;
let promise = windowClass.setPrivacyMode(isPrivacyMode);
promise.then((data)=> {
    console.info('Succeeded in setting the window to privacy mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window to privacy mode. Cause: ' + JSON.stringify(err));
});
```

### setSnapshotSkip<sup>9+</sup>
setSnapshotSkip(isSkip: boolean): void

截屏录屏是否忽略当前窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型    | 必填 | 说明                 |
| ------------- | ------- | ---- | -------------------- |
| isSkip | boolean | 是   | 截屏录屏是否忽略当前窗口，默认为false。<br>true表示忽略当前窗口，false表示不忽略当前窗口。</br> |
```js
let isSkip = true;
windowClass.setSnapshotSkip(isSkip);
```

### setTouchable<sup>7+</sup>

setTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口是否为可触状态，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                 |
| ----------- | ------------------------- | ---- | -------------------- |
| isTouchable | boolean                   | 是   | 窗口是否为可触状态。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```js
let isTouchable = true;
windowClass.setTouchable(isTouchable, (err, data) => {
    if (err.code) {
        console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to be touchable. Data:' + JSON.stringify(data));

});
```

### setTouchable<sup>7+</sup>

setTouchable(isTouchable: boolean): Promise&lt;void&gt;

设置窗口是否为可触状态，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                 |
| ----------- | ------- | ---- | -------------------- |
| isTouchable | boolean | 是   | 窗口是否为可触状态。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let isTouchable = true;
let promise = windowClass.setTouchable(isTouchable);
promise.then((data)=> {
    console.info('Succeeded in setting the window to be touchable. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window to be touchable. Cause: ' + JSON.stringify(err));
});
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback&lt;void&gt;): void

设置窗口在分屏模式下是否被禁止移动，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                 |
| ----------- | ------------------------- | ---- | -------------------- |
| isForbidSplitMove | boolean                   | 是   | 窗口在分屏模式下是否被禁止移动。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```js
let isForbidSplitMove = true;
windowClass.setForbidSplitMove(isForbidSplitMove, (err, data) => {
    if (err.code) {
        console.error('Failed to forbid window moving in split screen mode. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in forbidding window moving in split screen mode. Data:' + JSON.stringify(data));

});
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean): Promise&lt;void&gt;

设置窗口在分屏模式下是否被禁止移动，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                 |
| ----------- | ------- | ---- | -------------------- |
| isForbidSplitMove | boolean | 是   | 窗口在分屏模式下是否被禁止移动。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let isForbidSplitMove = true;
let promise = windowClass.setForbidSplitMove(isForbidSplitMove);
promise.then((data)=> {
    console.info('Succeeded in forbidding window moving in split screen mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to forbid window moving in split screen mode. Cause: ' + JSON.stringify(err));
});
```

### snapshot<sup>9+</sup>

snapshot(callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取窗口截图，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                 |
| ----------- | ------------------------- | ---- | -------------------- |
| callback    | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 是   | 回调函数。  |

**示例：**

```js
windowClass.snapshot((err, data) => {
    if (err.code) {
        console.error('Failed to snapshot window. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
    data.release(); // PixelMap使用完后及时释放内存
});
```

### snapshot<sup>9+</sup>

snapshot(): Promise&lt;image.PixelMap&gt;

获取窗口截图，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise对象。返回当前窗口截图。 |

**示例：**

```js
let promise = windowClass.snapshot();
promise.then((pixelMap)=> {
    console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
    pixelMap.release(); // PixelMap使用完后及时释放内存
}).catch((err)=>{
    console.error('Failed to snapshot window. Cause:' + JSON.stringify(err));
});
```

### setBlur<sup>9+</sup>

setBlur(radius: number): void

设置窗口模糊。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| radius | number | 是   | 表示窗口模糊的半径值，取值范围为大于等于0，0表示关闭窗口模糊。 |

**示例：**

```js
windowClass.setBlur(4.0);
```

### setBackdropBlur<sup>9+</sup>

setBackdropBlur(radius: number): void

设置窗口背景模糊。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| radius | number | 是   | 表示窗口背景模糊的半径值，取值范围为大于等于0，0表示关闭窗口背景模糊。 |

**示例：**

```js
windowClass.setBackdropBlur(4.0);
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

**示例：**

```js
windowClass.setBackdropBlurStyle(window.BlurType.THIN);
```

### setShadow<sup>9+</sup>

setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void

设置窗口边缘阴影。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| radius  | number | 是   | 表示窗口边缘阴影的模糊半径，取值范围为大于等于0，0表示关闭窗口边缘阴影。 |
| color   | string | 否   | 表示窗口边缘阴影的颜色，为十六进制颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`。 |
| offsetX | number | 否   | 表示窗口边缘阴影的X轴的偏移量，单位为px。                    |
| offsetY | number | 否   | 表示窗口边缘阴影的Y轴的偏移量，单位为px。                    |

**示例：**

```js
windowClass.setShadow(4.0, '#FF00FF00', 2, 3);
```

### setCornerRadius<sup>9+</sup>

setCornerRadius(cornerRadius: number): void

设置窗口圆角半径。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                 |
| ----------- | ------- | ---- | -------------------- |
| radius | number | 是   | 表示窗口圆角的半径值，取值范围为大于等于0，0表示没有窗口圆角。 |

**示例：**

```js
windowClass.setCornerRadius(4.0);
```

### opacity<sup>9+</sup>

opacity(opacity: number): void

设置窗口透明度。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                  |
| ------- | ------ | ---- | --------------------- |
| opacity | number | 是   | 透明度，范围0.0~1.0。 |

**示例：**

```js
windowClass.opacity(0.5);
```

### scale<sup>9+</sup>

scale(scaleOptions: ScaleOptions): void

设置窗口缩放参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                           | 必填 | 说明       |
| ------------ | ------------------------------ | ---- | ---------- |
| scaleOptions | [ScaleOptions](#scaleoptions9) | 是   | 缩放参数。 |

**示例：**

```js
let obj : window.ScaleOptions = {
  x : 2.0,
  y : 1.0,
  pivotX = 0.5;
  pivotY = 0.5;
}
windowClass.scale(obj);
```

### rotate<sup>9+</sup>

rotate(rotateOptions: RotateOptions): void

设置窗口旋转参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明       |
| ------------- | -------------------------------- | ---- | ---------- |
| rotateOptions | [RotateOptions](#rotateoptions9) | 是   | 旋转参数。 |

**示例：**

```js
let obj : window.RotateOptions = {
  x : 1.0,
  y : 1.0,
  z : 45.0,
  pivotX = 0.5;
  pivotY = 0.5;
}
windowClass.rotate(obj);
```

### translate<sup>9+</sup>

translate(translateOptions: TranslateOptions): void

设置窗口平移参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型                                   | 必填 | 说明       |
| ---------------- | -------------------------------------- | ---- | ---------- |
| translateOptions | [TranslateOptions](#translateoptions9) | 是   | 平移参数。 |

**示例：**

```js
let obj : window.TranslateOptions = {
  x : 100.0,
  y : 0.0,
  z : 0.0
}
windowClass.translate(obj);
```

###  getTransitionController<sup>9+</sup>

 getTransitionController(): TransitionController

获取窗口属性转换控制器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                           | 说明             |
| ---------------------------------------------- | ---------------- |
| [TransitionController](#transitioncontroller9) | 属性转换控制器。 |

**示例：**

```js
let controller = windowClass.getTransitionController(); // 获取属性转换控制器
controller.animationForHidden = (context : window.TransitionContext) => {
	let toWindow = context.toWindow
 	animateTo({
    	duration: 1000, // 动画时长
        tempo: 0.5, // 播放速率
        curve: Curve.EaseInOut, // 动画曲线
        delay: 0, // 动画延迟
        iterations: 1, // 播放次数
        playMode: PlayMode.Normal, // 动画模式
        onFinish: ()=> {
            context.completeTransition(true)
        }    
      }, () => {
        let obj : window.TranslateOptions = {
          x : 100.0,
          y : 0.0,
          z : 0.0
        }
        toWindow.translate(obj); // 设置动画过程中的属性转换
        console.info('toWindow translate end');
      }
    )
    console.info('complete transition end');
}
windowClass.hideWithAnimation((err, data) => {
    if (err.code) {
        console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in showing the window with animation. Data: ' + JSON.stringify(data));
})
```

## WindowStageEventType<sup>9+</sup>

WindowStage生命周期。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 默认值 | 说明       |
| ---------- | ------ | ---------- |
| FOREGROUND | 1      | 切到前台。 |
| ACTIVE     | 2      | 获焦状态。 |
| INACTIVE   | 3      | 失焦状态。 |
| BACKGROUND | 4      | 切到后台。 |

## WindowStage<sup>9+</sup>

窗口管理器。管理各个基本窗口单元，即[Window](#window)实例。

下列API示例中都需在[onWindowStageCreate()](js-apis-application-ability.md#abilityonwindowstagecreate)函数中使用WindowStage的实例调用对应方法。

### getMainWindow<sup>9+</sup>

getMainWindow(callback: AsyncCallback&lt;Window&gt;): void

获取该WindowStage实例下的主窗口，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                          |
| -------- | -------------------------------------- | ---- | --------------------------------------------- |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前WindowStage下的主窗口对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        windowStage.getMainWindow((err, data) => {
            if (err.code) {
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        });
    }
}
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

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        let promise = windowStage.getMainWindow();
        promise.then((data)=> {
        windowClass = data;
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
        });
    }
}
```
### createSubWindow<sup>9+</sup>

createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void

创建该WindowStage实例下的子窗口，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                          |
| -------- | -------------------------------------- | ---- | --------------------------------------------- |
| name     | String                                 | 是   | 子窗口的名字。                                |
| callback | AsyncCallback&lt;[Window](#window)&gt; | 是   | 回调函数。返回当前WindowStage下的子窗口对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        windowStage.createSubWindow('mySubWindow', (err, data) => {
            if (err.code) {
                console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
            windowClass.resetSize(500, 1000);
        });
    }
}
```
### createSubWindow<sup>9+</sup>

createSubWindow(name: string): Promise&lt;Window&gt;

创建该WindowStage实例下的子窗口，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| name   | String | 是   | 子窗口的名字。 |

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](#window)&gt; | Promise对象。返回当前WindowStage下的子窗口对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        let promise = windowStage.createSubWindow('mySubWindow');
        promise.then((data)=> {
            windowClass = data;
            console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
        })
    }
}
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

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        windowStage.getSubWindow((err, data) => {
            if (err.code) {
                console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
        });
    }
}
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

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        let promise = windowStage.getSubWindow();
        promise.then((data)=> {
            windowClass = data;
            console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));
        })
    }
}
```
### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

为当前WindowStage的主窗口加载与LocalStorage相关联的具体页面内容，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                         |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | 是   | 设置加载页面的路径。                                         |
| storage  | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | 是   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。 |
| callback | AsyncCallback&lt;void&gt;                       | 是   | 回调函数。                                                   |

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    storage : LocalStorage
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate('storageSimpleProp',121);
        console.log('onWindowStageCreate');
        windowStage.loadContent('pages/page2',this.storage,(err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage?: LocalStorage): Promise&lt;void&gt;

为当前WindowStage的主窗口加载与LocalStorage相关联的具体页面内容，使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                            | 必填 | 说明                                                         |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | 是   | 设置加载页面的路径。                                         |
| storage | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | 否   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    storage : LocalStorage
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate('storageSimpleProp',121);
        console.log('onWindowStageCreate');
        let windowClass = null;
        let promise = windowStage.loadContent('pages/page2',this.storage);
        promise.then((data)=> {
            windowClass = data;
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
        })
    }
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

为当前WindowStage的主窗口加载具体页面内容，使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| path     | string                    | 是   | 设置加载页面的路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        windowStage.loadContent('pages/page2', (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
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

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        windowStage.on('windowStageEvent', (data) => {
            console.info('Succeeded in enabling the listener for window stage event changes. Data: ' + JSON.stringify(data));
        });
    }
}
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
| callback | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | 否   | 回调函数。返回当前的WindowStage生命周期状态。                |

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        windowStage.off('windowStageEvent');
    }
}
```

### disableWindowDecor()<sup>9+</sup>

disableWindowDecor(): void

禁止窗口装饰。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('disableWindowDecor');
        windowStage.disableWindowDecor();
    }
}
```

### setShowOnLockScreen()<sup>9+</sup>

setShowOnLockScreen(showOnLockScreen: boolean): void

设置应用显示在锁屏之上。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型    | 必填 | 说明                         |
| ---------------- | ------- | ---- | ---------------------------- |
| showOnLockScreen | boolean | 是   | 是否设置应用显示在锁屏之上。 |

**示例：**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        windowStage.setShowOnLockScreen(true);
    }
}
```
## TransitionContext<sup>9+</sup>

属性转换的上下文信息。

### 属性

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称                  | 参数类型          | 可读 | 可写 | 说明             |
| --------------------- | ----------------- | ---- | ---- | ---------------- |
| toWindow<sup>9+</sup> | [Window](#window) | 是   | 是   | 动画的目标窗口。 |

### completeTransition<sup>9+</sup>

completeTransition(isCompleted: boolean): void

设置属性转换的最终完成状态。该函数需要在动画函数[animateTo()](../arkui-ts/ts-explicit-animation.md)执行后设置。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| isCompleted | boolean | 是   | 窗口属性转换是否完成。true：完成本次转换；false：撤销本次转换。 |

**示例：**

```js
let controller = windowClass.getTransitionController();
controller.animationForShown = (context : window.TransitionContext) => {
	let toWindow = context.toWindow
 	animateTo({
    	duration: 1000, // 动画时长
        tempo: 0.5, // 播放速率
        curve: Curve.EaseInOut, // 动画曲线
        delay: 0, // 动画延迟
        iterations: 1, // 播放次数
        playMode: PlayMode.Normal, // 动画模式
      }, () => {
        let obj : window.TranslateOptions = {
          x : 100.0,
          y : 0.0,
          z : 0.0
        }
        toWindow.translate(obj);
        console.info('toWindow translate end');
      }
    )
    context.completeTransition(true)
    console.info('complete transition end');
}
```

## TransitionController<sup>9+</sup>

属性转换控制器。

### animationForShown<sup>9+</sup>

animationForShown(context: TransitionContext): void

窗口显示时的自定义动画配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                 |
| ------- | ---------------------------------------- | ---- | -------------------- |
| context | [TransitionContext](#transitioncontext9) | 是   | 属性转换时的上下文。 |

**示例：**

```js
let controller = windowClass.getTransitionController();
controller.animationForShown = (context : window.TransitionContext) => {
	let toWindow = context.toWindow
 	animateTo({
    	duration: 1000, // 动画时长
        tempo: 0.5, // 播放速率
        curve: Curve.EaseInOut, // 动画曲线
        delay: 0, // 动画延迟
        iterations: 1, // 播放次数
        playMode: PlayMode.Normal, // 动画模式
        onFinish: ()=> {
            context.completeTransition(true)
        }  
      }, () => {
        let obj : window.TranslateOptions = {
          x : 100.0,
          y : 0.0,
          z : 0.0
        }
        toWindow.translate(obj);
        console.info('toWindow translate end');
      }
    )
    console.info('complete transition end');
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

**示例：**

```js
let controller = windowClass.getTransitionController();
controller.animationForHidden = (context : window.TransitionContext) => {
	let toWindow = context.toWindow
 	animateTo({
    	duration: 1000, // 动画时长
        tempo: 0.5, // 播放速率
        curve: Curve.EaseInOut, // 动画曲线
        delay: 0, // 动画延迟
        iterations: 1, // 播放次数
        playMode: PlayMode.Normal, // 动画模式
        onFinish: ()=> {
            context.completeTransition(true)
        }  
      }, () => {
        let obj : window.TranslateOptions = {
          x : 100.0,
          y : 0.0,
          z : 0.0
        }
        toWindow.translate(obj);
        console.info('toWindow translate end');
      }
    )
    console.info('complete transition end');
}
```