# @ohos.display (屏幕属性)

屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息，获取所有显示设备的信息以及监听显示设备的插拔行为。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
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

## Rect<sup>9+</sup>

矩形区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 可读 | 可写 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | 是   | 是   | 矩形区域的左边界，单位为像素。 |
| top    | number   | 是   | 是   | 矩形区域的上边界，单位为像素。 |
| width  | number   | 是   | 是   | 矩形区域的宽度，单位为像素。   |
| height | number   | 是   | 是   | 矩形区域的高度，单位为像素。   |

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

```js
let displayClass = null;
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

```js
let displayClass = null;
display.getAllDisplays((err, data) => {
    displayClass = data;
    if (err.code) {
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

```js
let displayClass = null;
let promise = display.getAllDisplays();
promise.then((data) => {
    displayClass = data;
    console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err) => {
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
| id     | number                    | 是   | 显示设备的id。 |

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

```js
let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();

    let ret = undefined;
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

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听事件。<br/>- type为"add"，表示增加显示设备事件。例如：插入显示器。<br/>- type为"remove"，表示移除显示设备事件。例如：移除显示器。<br/>- type为"change"，表示改变显示设备事件。例如：显示器方向改变。 |
| callback | Callback&lt;number&gt; | 是 | 回调函数。返回监听到的显示设备的id。 |

**示例：**

```js
let callback = (data) => {
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
| callback | Callback&lt;number&gt; | 否 | 回调函数。返回监听到的显示设备的id。 |

**示例：**

```js
try {
    display.off("remove");
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

```js
let displayClass = null;
display.getDefaultDisplay((err, data) => {
    if (err.code) {
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

```js
let displayClass = null;
let promise = display.getDefaultDisplay();
promise.then((data) => {
    displayClass = data;
    console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
}).catch((err) => {
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

```js
display.getAllDisplay((err, data) => {
    if (err.code) {
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

```js
let promise = display.getAllDisplay();
promise.then((data) => {
    console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
});
```

## Display
屏幕实例。描述display对象的属性和方法。

下列API示例中都需先使用[getAllDisplays()](#displaygetalldisplays9)、[getDefaultDisplaySync()](#displaygetdefaultdisplaysync9)中的任一方法获取到Display实例，再通过此实例调用对应方法。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| id | number | 是 | 否 | 显示设备的id号。|
| name | string | 是 | 否 | 显示设备的名称。|
| alive | boolean | 是 | 否 | 显示设备是否启用。|
| state | [DisplayState](#displaystate) | 是 | 否 | 显示设备的状态。|
| refreshRate | number | 是 | 否 | 显示设备的刷新率。|
| rotation | number | 是 | 否 | 显示设备的屏幕旋转角度。<br>值为0时，表示显示设备屏幕旋转为0°；<br>值为1时，表示显示设备屏幕旋转为90°；<br>值为2时，表示显示设备屏幕旋转为180°；<br>值为3时，表示显示设备屏幕旋转为270°。|
| width | number | 是 | 否 | 显示设备的宽度，单位为像素。|
| height | number | 是 | 否 | 显示设备的高度，单位为像素。|
| densityDPI | number | 是 | 否 | 显示设备的屏幕密度，表示每英寸点数。一般取值160，480等。 |
| densityPixels | number | 是 | 否 | 显示设备的逻辑密度，是像素单位无关的缩放系数。一般取值1，3等。 |
| scaledDensity | number | 是 | 否 | 显示设备的显示字体的缩放因子。通常与densityPixels相同。 |
| xDPI | number | 是 | 否 | x方向中每英寸屏幕的确切物理像素值。 |
| yDPI | number | 是 | 否 | y方向中每英寸屏幕的确切物理像素值。|

### getCutoutInfo<sup>9+</sup>
getCutoutInfo(callback: AsyncCallback&lt;CutoutInfo&gt;): void

获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。使用callback异步回调。建议应用布局规避该区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;[CutoutInfo](#cutoutinfo9)&gt;   | 是   | 回调函数。返回描述不可用屏幕区域的CutoutInfo对象。。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();

    displayClass.getCutoutInfo((err, data) => {
        if (err.code) {
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

```js
let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();

    let promise = displayClass.getCutoutInfo();
    promise.then((data) => {
        console.info('Succeeded in getting cutoutInfo. Data: ' + JSON.stringify(data));
    }).catch((err) => {
        console.error('Failed to obtain all the display objects. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
}
```
