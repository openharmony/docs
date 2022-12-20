# 屏幕属性
屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息，获取所有显示设备的信息以及监听显示设备的插拔行为。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import display from '@ohos.display';
```


## DisplayState

用于表示显示设备的状态。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| STATE_UNKNOWN | 0 | 表示显示设备状态未知。|
| STATE_OFF | 1 | 表示显示设备状态为关闭。 |
| STATE_ON | 2 | 表示显示设备状态为开启。|
| STATE_DOZE | 3 | 表示显示设备为低电耗模式。|
| STATE_DOZE_SUSPEND | 4 | 表示显示设备为睡眠模式，CPU为挂起状态。 |
| STATE_VR | 5 | 表示显示设备为VR模式。|
| STATE_ON_SUSPEND | 6 | 表示显示设备为开启状态，CPU为挂起状态。 |


## Display

描述display对象的属性。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| id | number | 是 | 否 | 显示设备的id号。|
| name | string | 是 | 否 | 显示设备的名称。|
| alive | boolean | 是 | 否 | 显示设备是否启用。|
| state | [DisplayState](#displaystate) | 是 | 否 | 显示设备的状态。|
| refreshRate | number | 是 | 否 | 显示设备的刷新率。|
| rotation | number | 是 | 否 | 显示设备的屏幕旋转角度。|
| width | number | 是 | 否 | 显示设备的宽度，单位为像素。|
| height | number | 是 | 否 | 显示设备的高度，单位为像素。|
| densityDPI | number | 是 | 否 | 显示设备的屏幕密度，表示每英寸点数。一般取值160、480等。|
| densityPixels | number | 是 | 否 | 显示设备的逻辑密度，是与像素单位无关的缩放系数。一般取值1、3等。|
| scaledDensity | number | 是 | 否 | 显示设备的显示字体的缩放因子。通常与densityPixels相同。|
| xDPI | number | 是 | 否 | x方向中每英寸屏幕的确切物理像素值。 |
| yDPI | number | 是 | 否 | y方向中每英寸屏幕的确切物理像素值。|


## display.getDefaultDisplay

getDefaultDisplay(callback: AsyncCallback&lt;Display&gt;): void

获取当前默认的display对象。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Display](#display)&gt; | 是 | 回调函数。返回当前默认的display对象。 |

**示例：**

```js
var displayClass = null;
display.getDefaultDisplay((err, data) => {
    if (err.code) {
        console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
    displayClass = data;
});
```

## display.getDefaultDisplay

getDefaultDisplay(): Promise&lt;Display&gt;

获取当前默认的display对象。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

  | 类型                               | 说明                                           |
  | ---------------------------------- | ---------------------------------------------- |
  | Promise&lt;[Display](#display)&gt; | Promise对象。返回当前默认的display对象。 |

**示例：**

```js
var displayClass = null;
let promise = display.getDefaultDisplay();
promise.then((data) => {
    displayClass = data;
    console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to obtain the default display object. Code:  ' + JSON.stringify(err));
});
```

## display.getAllDisplay

getAllDisplay(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

获取当前所有的display对象。

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

## display.getAllDisplay

getAllDisplay(): Promise&lt;Array&lt;Display&gt;&gt;

获取当前所有的display对象。

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

## display.on('add'|'remove'|'change')

on(type: 'add'|'remove'|'change', callback: Callback&lt;number&gt;): void

开启监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置监听类型。<br/>-&nbsp;type为"add"，表示监听增加显示设备。<br/>-&nbsp;type为"remove"，表示监听移除显示设备。<br/>-&nbsp;type为"change"，表示监听改变显示设备。 |
  | callback | Callback&lt;number&gt; | 是 | 回调函数。返回监听到的显示设备的id。 |

**示例：**

```js
var callback = (data) => {
    console.info('Listening enabled. Data: ' + JSON.stringify(data))
}
display.on("add", callback);
  ```

## display.off('add'|'remove'|'change')

off(type: 'add'|'remove'|'change', callback?: Callback&lt;number&gt;): void

关闭监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置监听类型。<br/>-&nbsp;type为"add"，表示监听增加显示设备。<br/>-&nbsp;type为"remove"，表示监听移除显示设备。<br/>-&nbsp;type为"change"，表示监听改变显示设备。 |
  | callback | Callback&lt;number&gt; | 否 | 回调函数。返回监听到的显示设备的id。 |

**示例：**
```js
display.off("remove");
```
