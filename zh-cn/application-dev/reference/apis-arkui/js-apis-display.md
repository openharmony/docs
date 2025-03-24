# @ohos.display (屏幕属性)

屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息，获取所有显示设备的信息以及监听显示设备的插拔行为。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { display } from '@kit.ArkUI';
```

## DisplayState

显示设备的状态枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PORTRAIT | 0 | 表示设备当前以竖屏方式显示。|
| LANDSCAPE | 1 | 表示设备当前以横屏方式显示。 |
| PORTRAIT_INVERTED | 2 | 表示设备当前以反向竖屏方式显示。|
| LANDSCAPE_INVERTED | 3 | 表示设备当前以反向横屏方式显示。|

## DisplaySourceMode<sup>18+</sup>

屏幕显示内容的显示模式枚举。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NONE | 0 | 表示设备当前未使用。|
| MAIN | 1 | 表示设备当前为主屏。 |
| MIRROR | 2 | 表示设备当前为镜像显示模式。|
| EXTEND | 3 | 表示设备当前为扩展显示模式。|
| ALONE | 4 | 表示设备当前为异源显示模式。|

## FoldStatus<sup>10+</sup>

当前可折叠设备的折叠状态枚举。如果是双折轴设备，则在充电口朝下的状态下，从右到左分别是折轴一和折轴二。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| FOLD_STATUS_UNKNOWN<sup>10+</sup> | 0 | 表示设备当前折叠状态未知。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_EXPANDED<sup>10+</sup> | 1 | 表示设备当前折叠状态为完全展开。如果是双折轴设备，则表示折轴一折叠状态为完全展开，折轴二折叠状态为折叠。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_FOLDED<sup>10+</sup> | 2 | 表示设备当前折叠状态为折叠。如果是双折轴设备，则表示折轴一折叠状态为折叠，折轴二折叠状态为折叠。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_HALF_FOLDED<sup>10+</sup> | 3 | 表示设备当前折叠状态为半折叠。半折叠指完全展开和折叠之间的状态。如果是双折轴设备，则表示折轴一折叠状态为半折叠，折轴二折叠状态为折叠。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_EXPANDED_WITH_SECOND_EXPANDED<sup>15+</sup> | 11 | 表示双折轴设备折轴一折叠状态为完全展开，折轴二折叠状态为完全展开。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_EXPANDED_WITH_SECOND_HALF_FOLDED<sup>15+</sup> | 21 | 表示双折轴设备折轴一折叠状态为完全展开，折轴二折叠状态为半折叠。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_FOLDED_WITH_SECOND_EXPANDED<sup>15+</sup> | 12 | 表示双折轴设备折轴一折叠状态为折叠，折轴二折叠状态为完全展开。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_FOLDED_WITH_SECOND_HALF_FOLDED<sup>15+</sup> | 22 | 表示双折轴设备折轴一折叠状态为折叠，折轴二折叠状态为半折叠。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_HALF_FOLDED_WITH_SECOND_EXPANDED<sup>15+</sup> | 13 | 表示双折轴设备折轴一折叠状态为半折叠，折轴二折叠状态为完全展开。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。|
| FOLD_STATUS_HALF_FOLDED_WITH_SECOND_HALF_FOLDED<sup>15+</sup> | 23 | 表示双折轴设备折轴一折叠状态为半折叠，折轴二折叠状态为半折叠。<br/>**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。|

>**说明：**<br>
> 只有一个折轴的产品包含FOLD_STATUS_EXPANDED、FOLD_STATUS_FOLDED、FOLD_STATUS_HALF_FOLDED三种折叠状态。
> 具有两个折轴的产品包含上表所示九种折叠状态。<br>
> FOLD_STATUS_UNKNOWN是一种不可用的折叠状态。

## FoldDisplayMode<sup>10+</sup>

可折叠设备的显示模式枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| FOLD_DISPLAY_MODE_UNKNOWN | 0 | 表示设备当前折叠显示模式未知。|
| FOLD_DISPLAY_MODE_FULL | 1 | 表示设备当前全屏显示。 |
| FOLD_DISPLAY_MODE_MAIN | 2 | 表示设备当前主屏幕显示。|
| FOLD_DISPLAY_MODE_SUB | 3 | 表示设备当前子屏幕显示。|
| FOLD_DISPLAY_MODE_COORDINATION | 4 | 表示设备当前双屏协同显示。|

>**说明：**<br>
>&bullet; 对于内外屏均可作为主屏幕使用的折叠产品，内屏显示状态为FOLD_DISPLAY_MODE_FULL，外屏显示状态为FOLD_DISPLAY_MODE_MAIN。<br>
>&bullet; 对于外屏只有简单的辅助显示作用的折叠产品，内屏显示状态为FOLD_DISPLAY_MODE_MAIN，外屏显示状态为FOLD_DISPLAY_MODE_SUB。

## FoldCreaseRegion<sup>10+</sup>

折叠折痕区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 可读 | 可写 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| displayId   | number   | 是   | 否   | 显示器ID，用于识别折痕所在的屏幕。 |
| creaseRects    | Array\<[Rect](#rect9)>   | 是   | 否   | 折痕区域。 |

## Rect<sup>9+</sup>

矩形区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 可读 | 可写 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | 是   | 是   | 矩形区域的左边界，单位为px，该参数应为整数。 |
| top    | number   | 是   | 是   | 矩形区域的上边界，单位为px，该参数应为整数。 |
| width  | number   | 是   | 是   | 矩形区域的宽度，单位为px，该参数应为整数。   |
| height | number   | 是   | 是   | 矩形区域的高度，单位为px，该参数应为整数。   |

## WaterfallDisplayAreaRects<sup>9+</sup>

瀑布屏曲面部分显示区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型      | 可读 | 可写 | 说明               |
| ------ | ------------- | ---- | ---- | ------------------ |
| left   | [Rect](#rect9) | 是   | 否   | 瀑布曲面区域的左侧矩形区域。 |
| top    | [Rect](#rect9) | 是   | 否   | 瀑布曲面区域的顶部矩形区域。 |
| right  | [Rect](#rect9) | 是   | 否   | 瀑布曲面区域的右侧矩形区域。 |
| bottom | [Rect](#rect9) | 是   | 否   | 瀑布曲面区域的底部矩形区域。 |

## CutoutInfo<sup>9+</sup>

挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                        | 类型      | 可读 | 可写 | 说明               |
| --------------------------- | ------------- | ---- | ---- | ------------------ |
| boundingRects                | Array\<[Rect](#rect9)> | 是   | 否   | 挖孔、刘海等区域的边界矩形。如果没有挖孔、刘海等区域，数组返回为空。 |
| waterfallDisplayAreaRects   | [WaterfallDisplayAreaRects](#waterfalldisplayarearects9) | 是 | 否 | 瀑布屏曲面部分显示区域。 |

## DisplayPhysicalResolution<sup>12+</sup>
折叠设备的显示模式以及对应的物理屏幕分辨率信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                        | 类型      | 只读 | 可选 | 说明               |
| --------------------------- | ------------- | ---- | ---- | ------------------ |
| foldDisplayMode             | [FoldDisplayMode](#folddisplaymode10) | 是   | 否   | 折叠设备的显示模式。 |
| physicalWidth   | number | 是 | 否 | 折叠设备的宽度，单位为px，该参数应为大于0的整数。|
| physicalHeight  | number | 是 | 否 | 折叠设备的高度，单位为px，该参数应为大于0的整数。|

## ScreenShape<sup>18+</sup>

显示设备的屏幕形状枚举。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| RECTANGLE | 0 | 表示设备屏幕形状为矩形。|
| ROUND | 1 | 表示设备屏幕形状为圆形。|

## VirtualScreenConfig<sup>16+</sup>

创建虚拟屏幕的参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称      | 类型 | 只读 | 可选 | 说明                       |
| --------- | -------- | ---- | ---- |--------------------------|
| name      | string   | 否   | 否   | 指定虚拟屏幕的名称，用户可自行定义。               |
| width     | number   | 否   | 否   | 指定虚拟屏幕的宽度，单位为px，该参数应为正整数。 |
| height    | number   | 否   | 否   | 指定虚拟屏幕的高度，单位为px，该参数应为正整数。 |
| density   | number   | 否   | 否   | 指定虚拟屏幕的密度，单位为px，该参数为浮点数。 |
| surfaceId | string   | 否   | 否   | 指定虚拟屏幕的surfaceId，用户可自行定义。        |

## display.getDisplayByIdSync<sup>12+</sup>

getDisplayByIdSync(displayId: number): Display

根据displayId获取对应的display对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- |----------|
| displayId     | number                    | 是   | 屏幕id。该参数仅支持整数输入，该参数大于等于0。需要确保displayId准确才能成功获取到对应结果。可以通过[WindowProperties](js-apis-window.md#windowproperties)的displayId属性获取到准确的displayId作为入参。 |

**返回值：**

| 类型                           | 说明                                           |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | 返回displayId对应的display对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2. Incorrect parameter types. 3. Parameter verification failed.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;

try {
  // 可以通过WindowProperties的displayId属性获取到准确的displayId作为入参
  let displayId = 0; 
  displayClass = display.getDisplayByIdSync(displayId);
} catch (exception) {
  console.error(`Failed to get display. Code: ${exception.code}, message: ${exception.message}`);
}
```

## display.getAllDisplayPhysicalResolution<sup>12+</sup>

getAllDisplayPhysicalResolution(): Promise&lt;Array&lt;DisplayPhysicalResolution&gt;&gt;

获取当前折叠设备的显示模式以及对应的物理屏幕分辨率信息对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[DisplayPhysicalResolution](#displayphysicalresolution12)&gt;&gt; | Promise对象。返回当前所有的DisplayPhysicalResolution对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let promise = display.getAllDisplayPhysicalResolution();
promise.then((resolutionObjects) => {
  console.info('Obtaining physical resolution length: ' + resolutionObjects.length);
  for (let i = 0; i < resolutionObjects.length; i++) {
     console.info(`resolutionObjects[${i}].foldDisplayMode: ${resolutionObjects[i].foldDisplayMode}`);
     console.info(`resolutionObjects[${i}].physicalWidth: ${resolutionObjects[i].physicalWidth}`); 
     console.info(`resolutionObjects[${i}].physicalHeight: ${resolutionObjects[i].physicalHeight}`); 
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain physical resolution. Code: ${err.code}, message: ${err.message}`);
});
```

## display.getDefaultDisplaySync<sup>9+</sup>

getDefaultDisplaySync(): Display

获取当前默认的display对象。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                           | 说明                                           |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | 返回默认的display对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;

displayClass = display.getDefaultDisplaySync();
```

## display.getPrimaryDisplaySync<sup>14+</sup>

getPrimaryDisplaySync(): Display

获取主屏信息。除2in1之外的设备获取的是设备自带屏幕的Display对象；2in1设备外接屏幕时获取的是当前主屏幕的Display对象；2in1设备没有外接屏幕时获取的是自带屏幕的Display对象。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                           | 说明                                           |
| ------------------------------| ----------------------------------------------|
| [Display](#display) | 当前设备主屏幕的Display对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;

displayClass = display.getPrimaryDisplaySync();
```

## display.getAllDisplays<sup>9+</sup>

getAllDisplays(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

获取当前所有的display对象，使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ---------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Display](#display)&gt;&gt; | 是 | 回调函数。返回当前所有的display对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: Array<display.Display> = [];
display.getAllDisplays((err: BusinessError, data: Array<display.Display>) => {
  displayClass = data;
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
});
```

## display.getAllDisplays<sup>9+</sup>

getAllDisplays(): Promise&lt;Array&lt;Display&gt;&gt;

获取当前所有的display对象，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Display](#display)&gt;&gt; | Promise对象。返回当前所有的display对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: Array<display.Display> =[];
let promise: Promise<Array<display.Display>> = display.getAllDisplays();
promise.then((data: Array<display.Display>) => {
  displayClass = data;
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
});
```

## display.on('add'|'remove'|'change')

on(type: 'add'|'remove'|'change', callback: Callback&lt;number&gt;): void

开启显示设备变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                                                                                              |
| -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------------------------|
| type | string | 是 | 监听事件。<br/>- type为"add"，表示增加显示设备事件。例如：插入显示器。<br/>- type为"remove"，表示移除显示设备事件。例如：移除显示器。<br/>- type为"change"，表示改变显示设备事件。例如：显示器方向改变。 |
| callback | Callback&lt;number&gt; | 是 | 回调函数。返回监听到的显示设备的id，该参数应为整数。                                                                                                     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<number> = (data: number) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};

display.on("add", callback);
```

## display.off('add'|'remove'|'change')

off(type: 'add'|'remove'|'change', callback?: Callback&lt;number&gt;): void

关闭显示设备变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听事件。<br/>- type为"add"，表示增加显示设备事件。例如：插入显示器。<br/>- type为"remove"，表示移除显示设备事件。例如：移除显示器。<br/>- type为"change"，表示改变显示设备事件。例如：显示器方向改变。 |
| callback | Callback&lt;number&gt; | 否 | 需要取消注册的回调函数。返回监听到的显示设备的id，该参数应为整数。若无此参数，则取消注册当前type类型事件监听的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**示例：**

```ts

// 如果通过on注册多个callback，同时关闭所有callback监听
display.off("remove");

let callback: Callback<number> = (data: number) => {
  console.info('Succeeded in unregistering the callback for display remove. Data: ' + JSON.stringify(data))
};
// 关闭传入的callback监听
display.off('remove', callback);
```

## display.isFoldable<sup>10+</sup>
isFoldable(): boolean

检查设备是否可折叠。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| boolean | boolean对象，返回当前设备是否可折叠的结果。false表示不可折叠，true表示可折叠。|

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let ret: boolean = false;
ret = display.isFoldable();
```

## display.getFoldStatus<sup>10+</sup>
getFoldStatus(): FoldStatus

获取可折叠设备的当前折叠状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldStatus](#foldstatus10) | FoldStatus对象，返回当前可折叠设备的折叠状态。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let data: display.FoldStatus = display.getFoldStatus();
console.info('Succeeded in obtaining fold status. Data: ' + JSON.stringify(data));
```

## display.getFoldDisplayMode<sup>10+</sup>
getFoldDisplayMode(): FoldDisplayMode

获取可折叠设备的显示模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldDisplayMode](#folddisplaymode10) | FoldDisplayMode对象，返回当前可折叠设备的显示模式。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let data: display.FoldDisplayMode = display.getFoldDisplayMode();
console.info('Succeeded in obtaining fold display mode. Data: ' + JSON.stringify(data));
```

## display.getCurrentFoldCreaseRegion<sup>10+</sup>
getCurrentFoldCreaseRegion(): FoldCreaseRegion

在当前显示模式下获取折叠折痕区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| [FoldCreaseRegion](#foldcreaseregion10) | FoldCreaseRegion对象，返回设备在当前显示模式下的折叠折痕区域。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let data: display.FoldCreaseRegion = display.getCurrentFoldCreaseRegion();
console.info('Succeeded in obtaining current fold crease region. Data: ' + JSON.stringify(data));
```

## display.on('foldStatusChange')<sup>10+</sup>

on(type: 'foldStatusChange', callback: Callback&lt;FoldStatus&gt;): void

开启折叠设备折叠状态变化的监听。

本接口监听设备物理折叠状态的变化，如果要监听屏幕显示模式的变化，需要使用[display.on('foldDisplayModeChange')](#displayonfolddisplaymodechange10)接口。

两者存在差异，时序上物理折叠状态变化在前，底层会根据物理折叠状态匹配屏幕显示模式状态。

若需监听当前显示内容是显示在折叠设备的内屏还是外屏，请使用[display.on('foldDisplayModeChange')](#displayonfolddisplaymodechange10)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'foldStatusChange'，表示折叠设备折叠状态发生变化。 |
| callback | Callback&lt;[FoldStatus](#foldstatus10)&gt; | 是   | 回调函数。表示折叠设备折叠状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';

/**
 * 注册监听的callback参数要采用对象传递.
 * 若使用匿名函数注册，每次调用会创建一个新的底层对象，引起内存泄漏问题。
*/
let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
display.on('foldStatusChange', callback);
```

## display.off('foldStatusChange')<sup>10+</sup>

off(type: 'foldStatusChange', callback?: Callback&lt;FoldStatus&gt;): void

关闭折叠设备折叠状态变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'foldStatusChange'，表示折叠设备折叠状态发生变化。 |
| callback | Callback&lt;[FoldStatus](#foldstatus10)&gt; | 否   | 需要取消注册的回调函数。表示折叠设备折叠状态。若无此参数，则取消注册折叠状态变化监听的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts

// 如果通过on注册多个callback，同时关闭所有callback监听
display.off('foldStatusChange');

let callback: Callback<display.FoldStatus> = (data: display.FoldStatus) => {
  console.info('unregistering FoldStatus changes callback. Data: ' + JSON.stringify(data));
};
// 关闭传入的callback监听
display.off('foldStatusChange', callback);
```

## display.on('foldAngleChange')<sup>12+</sup>

on(type: 'foldAngleChange', callback: Callback&lt;Array&lt;number&gt;&gt;): void

开启折叠设备折叠角度变化的监听。如果是双折轴设备，则有两个角度值；在充电口朝下的状态下，从右到左分别是折轴一和折轴二。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是 | 监听事件，固定为'foldAngleChange'，表示折叠设备折叠角度发生变化。|
| callback | Callback&lt;Array&lt;number&gt;&gt; | 是 | 回调函数。表示折叠设备屏幕折叠角度值（0度~180度）。如果是双折轴设备，则数组返回两个角度值，第一个值是折轴一的折叠角度值，第二个值是折轴二的折叠角度值。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<Array<number>> = (angles: Array<number>) => {
  console.info('Listening fold angles length: ' + angles.length);
};
display.on('foldAngleChange', callback);
```

## display.off('foldAngleChange')<sup>12+</sup>

off(type: 'foldAngleChange', callback?: Callback&lt;Array&lt;number&gt;&gt;): void

关闭折叠设备折叠角度变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |-------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                    | 是  | 监听事件，固定为'foldAngleChange'表示折叠设备折叠角度发生变化。|
| callback | Callback&lt;Array&lt;number&gt;&gt; | 否  | 需要取消注册的回调函数。表示折叠设备屏幕折叠角度值（0度~180度）。若无此参数，则取消注册折叠角度变化监听的所有回调函数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
display.off('foldAngleChange');
```

## display.on('captureStatusChange')<sup>12+</sup>

on(type: 'captureStatusChange', callback: Callback&lt;boolean&gt;): void

开启屏幕截屏、投屏、录屏状态变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |-------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是 | 监听事件，固定为'captureStatusChange'表示设备截屏、投屏或者录屏状态发生变化。|
| callback | Callback&lt;boolean&gt; | 是 | 回调函数。表示设备截屏、投屏、录屏状态发生变化。true表示设备开始截屏、投屏或者录屏，false表示结束截屏、投屏、录屏。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<boolean> = (captureStatus: boolean) => {
  console.info('Listening capture status: ' + captureStatus);
};
display.on('captureStatusChange', callback);
```

## display.off('captureStatusChange')<sup>12+</sup>

off(type: 'captureStatusChange', callback?: Callback&lt;boolean&gt;): void

关闭屏幕截屏、投屏、录屏状态变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |-------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是 | 监听事件，固定为'captureStatusChange'表示设备截屏、投屏、录屏状态发生变化。|
| callback | Callback&lt;boolean&gt; | 否 | 需要取消注册的回调函数。表示设备截屏、投屏、录屏状态发生变化。true表示设备开始截屏、投屏或者录屏，false表示结束截屏、投屏、录屏。若无此参数，则取消注册截屏、投屏、录屏状态变化监听的所有回调函数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
display.off('captureStatusChange');
```

## display.isCaptured<sup>12+</sup>
isCaptured(): boolean

检查设备是否正在截屏、投屏、录屏。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型 | 说明 |
| ----------------------------------------------- | ------------------------------------------------------- |
| boolean | boolean值，返回当前设备是否有截屏、投屏或者录屏。true表示有截屏、投屏、录屏，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { display } from '@kit.ArkUI';

let ret: boolean = false;
ret = display.isCaptured();
```

## display.on('foldDisplayModeChange')<sup>10+</sup>

on(type: 'foldDisplayModeChange', callback: Callback&lt;FoldDisplayMode&gt;): void

开启折叠设备屏幕显示模式变化的监听。

本接口监听设备屏幕显示模式的变化，如果要监听设备物理折叠状态的变化，需要使用[display.on('foldStatusChange')](#displayonfoldstatuschange10)接口。

两者存在差异，时序上物理折叠状态变化在前，底层会根据物理折叠状态匹配屏幕显示模式状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'foldDisplayModeChange'，表示折叠设备屏幕显示模式发生变化。 |
| callback | Callback&lt;[FoldDisplayMode](#folddisplaymode10)&gt; | 是   | 回调函数。表示折叠设备屏幕显示模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';

/**
 * 注册监听的callback参数要采用对象传递.
 * 若使用匿名函数注册，每次调用会创建一个新的底层对象，引起内存泄漏问题。
*/
let callback: Callback<display.FoldDisplayMode> = (data: display.FoldDisplayMode) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
}; 
display.on('foldDisplayModeChange', callback);
```

## display.off('foldDisplayModeChange')<sup>10+</sup>

off(type: 'foldDisplayModeChange', callback?: Callback&lt;FoldDisplayMode&gt;): void

关闭折叠设备屏幕显示模式变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'foldDisplayModeChange'，表示折叠设备屏幕显示模式发生变化。 |
| callback | Callback&lt;[FoldDisplayMode](#folddisplaymode10)&gt; | 否   | 需要取消注册的回调函数。表示折叠设备屏幕显示模式。若无此参数，则取消注册屏幕显示模式变化监听的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts

// 如果通过on注册多个callback，同时关闭所有callback监听
display.off('foldDisplayModeChange');

let callback: Callback<display.FoldDisplayMode> = (data: display.FoldDisplayMode) => {
  console.info('unregistering FoldDisplayMode changes callback. Data: ' + JSON.stringify(data));
};
// 关闭传入的callback监听
display.off('foldDisplayModeChange', callback);
```


## display.getDefaultDisplay<sup>(deprecated)</sup>

getDefaultDisplay(callback: AsyncCallback&lt;Display&gt;): void

获取当前默认的display对象，使用callback异步回调。

> **说明：**
> 
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[getDefaultDisplaySync()](#displaygetdefaultdisplaysync9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[Display](#display)&gt; | 是 | 回调函数。返回当前默认的display对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
display.getDefaultDisplay((err: BusinessError, data: display.Display) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain the default display object. Code: ${err.code}, message: ${err.message}`);
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
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[getDefaultDisplaySync()](#displaygetdefaultdisplaysync9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                               | 说明                                           |
| ---------------------------------- | ---------------------------------------------- |
| Promise&lt;[Display](#display)&gt; | Promise对象。返回当前默认的display对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
let promise: Promise<display.Display> = display.getDefaultDisplay();
promise.then((data: display.Display) => {
  displayClass = data;
  console.info('Succeeded in obtaining the default display object. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the default display object. Code: ${err.code}, message: ${err.message}`);
});
```

## display.getAllDisplay<sup>(deprecated)</sup>

getAllDisplay(callback: AsyncCallback&lt;Array&lt;Display&gt;&gt;): void

获取当前所有的display对象，使用callback异步回调。

> **说明：**
> 
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[getAllDisplays()](#displaygetalldisplays9)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                            |
| -------- | ---------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Display](#display)&gt;&gt; | 是   | 回调函数。返回当前所有的display对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

display.getAllDisplay((err: BusinessError, data: Array<display.Display>) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
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
> 从API version 7开始支持，从API version 9开始废弃，推荐使用[getAllDisplays()](#displaygetalldisplays9-1)。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                            | 说明                                                    |
| ----------------------------------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[Display](#display)&gt;&gt; | Promise对象。返回当前所有的display对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise: Promise<Array<display.Display>> = display.getAllDisplay();
promise.then((data: Array<display.Display>) => {
  console.info('Succeeded in obtaining all the display objects. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
});
```

## display.createVirtualScreen<sup>16+</sup>

createVirtualScreen(config:VirtualScreenConfig): Promise&lt;number&gt;

创建虚拟屏幕，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**需要权限**：ohos.permission.ACCESS_VIRTUAL_SCREEN

**参数：**

| 参数名  | 类型                                        | 必填 | 说明                     |
| ------- | ------------------------------------------- | ---- | ------------------------ |
| config | [VirtualScreenConfig](#virtualscreenconfig16) | 是   | 用于创建虚拟屏幕的参数。|

**返回值：**

| 类型                             | 说明                                  |
| -------------------------------- | ------------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回创建的虚拟屏幕ID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801     | Capability not supported.function createVirtualScreen can not work correctly due to limited device capabilities. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenConfig {
  name : string = '';
  width : number = 0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
}

let config : VirtualScreenConfig = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: ''
};

display.createVirtualScreen(config).then((screenId: number) => {
  console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(screenId));
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code:${err.code},message is ${err.message}`);
});
```

## display.destroyVirtualScreen<sup>16+</sup>

destroyVirtualScreen(screenId:number): Promise&lt;void&gt;

销毁虚拟屏幕，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**需要权限**：ohos.permission.ACCESS_VIRTUAL_SCREEN

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| screenId | number | 是   | 屏幕id，与创建的虚拟屏幕id保持一致，即使用createVirtualScreen()接口成功创建对应虚拟屏幕时的返回值，该参数仅支持整数输入。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801     | Capability not supported.function destroyVirtualScreen can not work correctly due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenId: number = 1;
display.destroyVirtualScreen(screenId).then(() => {
  console.info('Succeeded in destroying the virtual screen.');
}).catch((err: BusinessError) => {
  console.error(`Failed to destroy the virtual screen.Code:${err.code},message is ${err.message}`);
});
```

## display.setVirtualScreenSurface<sup>16+</sup>

setVirtualScreenSurface(screenId:number, surfaceId: string): Promise&lt;void&gt;

设置虚拟屏幕的surfaceId，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**需要权限**：ohos.permission.ACCESS_VIRTUAL_SCREEN

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| screenId  | number | 是   | 屏幕id，与创建的虚拟屏幕id保持一致，即使用createVirtualScreen()接口成功创建对应虚拟屏幕时的返回值，该参数仅支持整数输入。    |
| surfaceId | string | 是   | 代表虚拟屏幕的surface标识符，surfaceId值可自行定义。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801     | Capability not supported.function setVirtualScreenSurface can not work correctly due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenId: number = 1;
let surfaceId: string = '2048';
display.setVirtualScreenSurface(screenId, surfaceId).then(() => {
  console.info('Succeeded in setting the surface for the virtual screen.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the surface for the virtual screen. Code:${err.code},message is ${err.message}`);
});
```

## display.makeUnique<sup>16+</sup>

makeUnique(screenId:number): Promise&lt;void&gt;

将屏幕设置为异源模式，使用Promise异步回调。

**系统能力：** SystemCapability.Window.SessionManager

**需要权限**：ohos.permission.ACCESS_VIRTUAL_SCREEN

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| screenId  | number | 是   | 要设置成异源模式的屏幕id。其中id应为大于等于0的整数，否则返回401错误码。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 801     | Capability not supported.function makeUnique can not work correctly due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenId: number = 0;
display.makeUnique(screenId).then(() => {
  console.info('Succeeded in making unique screens.');
}).catch((err: BusinessError) => {
  console.error(`Failed to make unique screens. Code:${err.code},message is ${err.message}`);
});
```

## Display
屏幕实例。描述display对象的属性和方法。

下列API示例中都需先使用[getAllDisplays()](#displaygetalldisplays9)、[getDefaultDisplaySync()](#displaygetdefaultdisplaysync9)中的任一方法获取到Display实例，再通过此实例调用对应方法。

### 属性

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型 | 只读 | 可选 | 说明                                                                                                            |
| -------- | -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------|
| id | number | 是 | 否 | 显示设备的id号，该参数应为大于等于0的整数。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                             |
| name | string | 是 | 否 | 显示设备的名称。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                      |
| alive | boolean | 是 | 否 | 显示设备是否启用。true表示设备启用，false表示设备未启用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                     |
| state | [DisplayState](#displaystate) | 是 | 否 | 显示设备的状态。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                      |
| refreshRate | number | 是 | 否 | 显示设备的刷新率，该参数应为整数，单位为hz。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                             |
| rotation | number | 是 | 否 | 显示设备的屏幕顺时针旋转角度。<br>值为0时，表示显示设备屏幕顺时针旋转为0°；<br>值为1时，表示显示设备屏幕顺时针旋转为90°；<br>值为2时，表示显示设备屏幕顺时针旋转为180°；<br>值为3时，表示显示设备屏幕顺时针旋转为270°。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| width | number | 是 | 否 | 显示设备的屏幕宽度，单位为px，该参数应为整数。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                        |
| height | number | 是 | 否 | 显示设备的屏幕高度，单位为px，该参数应为整数。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                        |
| densityDPI | number | 是 | 否 | 显示设备屏幕的物理像素密度，表示每英寸上的像素点数。该参数为浮点数，单位为px。一般取值160.0、480.0等，实际能取到的值取决于不同设备设置里提供的可选值。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                   |
| orientation<sup>10+</sup> | [Orientation](#orientation10) | 是 | 否 | 表示屏幕当前显示的方向。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                  |
| densityPixels | number | 是 | 否 | 显示设备逻辑像素的密度，代表物理像素与逻辑像素的缩放系数，计算方式为：![densityPixels](figures/densityPixels.jpg)<br>该参数为浮点数，受densityDPI范围限制，取值范围在[0.5，4.0]。一般取值1.0、3.0等，实际取值取决于不同设备提供的densityDPI。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                  |
| scaledDensity | number | 是 | 否 | 显示设备的显示字体的缩放因子。该参数为浮点数，通常与densityPixels相同。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                    |
| xDPI | number | 是 | 否 | x方向中每英寸屏幕的确切物理像素值，该参数为浮点数。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                    |
| yDPI | number | 是 | 否 | y方向中每英寸屏幕的确切物理像素值，该参数为浮点数。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                    |
| colorSpaces<sup>11+</sup> | Array<[colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md)> | 是 | 否 | 显示设备支持的所有色域类型。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                |
| hdrFormats<sup>11+</sup> | Array<[hdrCapability.HDRFormat](../apis-arkgraphics2d/js-apis-hdrCapability.md)> | 是 | 否 | 显示设备支持的所有HDR格式。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                               |
| availableWidth<sup>12+</sup> | number | 是 | 否 | 2in1设备上屏幕的可用区域宽度，单位为px，该参数为大于0的整数。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                    |
| availableHeight<sup>12+</sup> | number | 是 | 否 | 2in1设备上屏幕的可用区域高度，单位为px，该参数为大于0的整数。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                    |
| screenShape<sup>18+</sup> | [ScreenShape](#screenshape18) | 是 | 是 | 显示设备的屏幕形状，默认值为RECTANGLE。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 
| sourceMode<sup>18+</sup> | [DisplaySourceMode](#displaysourcemode18) | 是 | 是 | 屏幕显示内容的显示模式枚举。<br/>**系统能力：** SystemCapability.Window.SessionManager <br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                    |
| x<sup>18+</sup> | number | 是 | 是 | 屏幕左上角相对于原点的x轴坐标，原点为主屏左上角，单位为px，该参数为整数。<br/>**系统能力：** SystemCapability.Window.SessionManager<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                    |
| y<sup>18+</sup> | number | 是 | 是 | 屏幕左上角相对于原点的y轴坐标，原点为主屏左上角，单位为px，该参数为整数。<br/>**系统能力：** SystemCapability.Window.SessionManager<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。                                                                                    |


### getCutoutInfo<sup>9+</sup>
getCutoutInfo(callback: AsyncCallback&lt;CutoutInfo&gt;): void

获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。使用callback异步回调。建议应用布局规避该区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;[CutoutInfo](#cutoutinfo9)&gt;   | 是   | 回调函数。返回描述不可用屏幕区域的CutoutInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();

displayClass.getCutoutInfo((err: BusinessError, data: display.CutoutInfo) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to get cutoutInfo. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in getting cutoutInfo. data: ' + JSON.stringify(data));
});
```
### getCutoutInfo<sup>9+</sup>
getCutoutInfo(): Promise&lt;CutoutInfo&gt;

获取挖孔屏、刘海屏、瀑布屏等不可用屏幕区域信息。使用Promise异步回调。建议应用布局规避该区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[CutoutInfo](#cutoutinfo9)&gt; | Promise对象。返回描述不可用屏幕区域的CutoutInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();
let promise: Promise<display.CutoutInfo> = displayClass.getCutoutInfo();
promise.then((data: display.CutoutInfo) => {
  console.info('Succeeded in getting cutoutInfo. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain all the display objects. Code: ${err.code}, message: ${err.message}`);
});
```

### getAvailableArea<sup>12+</sup>
getAvailableArea(): Promise&lt;Rect&gt;

获取当前设备屏幕的可用区域，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;[Rect](#rect9)&gt; | Promise对象。返回当前屏幕可用矩形区域。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  let promise = displayClass.getAvailableArea();
  promise.then((data) => {
    console.info('Succeeded get the available area in this display. data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to get the available area in this display. Code: ${err.code}, message: ${err.message}`);
  })
} catch (exception) {
  console.error(`Failed to obtain the default display object. Code: ${exception.code}, message: ${exception.message}`);
}
```

### on('availableAreaChange')<sup>12+</sup>
on(type: 'availableAreaChange', callback: Callback&lt;Rect&gt;): void

开启当前设备屏幕的可用区域监听。当前设备屏幕有可用区域变化时，触发回调函数，返回可用区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件。固定为'availableAreaChange'，表示屏幕可用区域变更。 |
| callback | Callback&lt;[Rect](#rect9)&gt; | 是   | 回调函数。返回改变后的可用区域。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let callback: Callback<display.Rect> = (data: display.Rect) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  displayClass.on("availableAreaChange", callback);
} catch (exception) {
  console.error(`Failed to register callback. Code: ${exception.code}, message: ${exception.message}`);
}
```

### off('availableAreaChange')<sup>12+</sup>

off(type: 'availableAreaChange', callback?: Callback&lt;Rect&gt;): void

关闭当前设备屏幕可用区域变化的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                    |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | 是   | 监听事件，固定为'availableAreaChange'，表示屏幕可用区域变更。 |
| callback | Callback&lt;[Rect](#rect9)&gt; | 否   | 需要取消注册的回调函数。返回改变后的可用区域。若无此参数，则取消注册屏幕可用区域变化监听的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { Callback } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let callback: Callback<display.Rect> = (data: display.Rect) => {
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();
  displayClass.off("availableAreaChange", callback);
} catch (exception) {
  console.error(`Failed to unregister callback. Code: ${exception.code}, message: ${exception.message}`);
}
```