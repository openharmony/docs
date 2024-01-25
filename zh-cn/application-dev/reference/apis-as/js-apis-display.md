# @ohos.display (屏幕属性)

屏幕属性提供管理显示设备的一些基础能力，包括获取默认显示设备的信息。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import display from '@ohos.display';
```

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

## Display
屏幕实例。描述display对象的属性和方法。

下列API示例中都需先使用[getDefaultDisplaySync()](#displaygetdefaultdisplaysync9)获取到Display实例，再通过此实例调用对应方法。

### 属性

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型 | 可读 | 可写 | 说明                                                                                                            |
| -------- | -------- | -------- | -------- |---------------------------------------------------------------------------------------------------------------|
| rotation | number | 是 | 否 | 显示设备的屏幕顺时针旋转角度。<br>值为0时，表示显示设备屏幕顺时针旋转为0°；<br>值为1时，表示显示设备屏幕顺时针旋转为90°；<br>值为2时，表示显示设备屏幕顺时针旋转为180°；<br>值为3时，表示显示设备屏幕顺时针旋转为270°。 |
| width | number | 是 | 否 | 显示设备的宽度，单位为px，该参数应为整数。                                                                                        |
| height | number | 是 | 否 | 显示设备的高度，单位为px，该参数应为整数。                                                                                        |
| densityPixels | number | 是 | 否 | 显示设备的逻辑密度，是像素单位无关的缩放系数。该参数为浮点数，一般取值1.0、3.0等。                                                                  |

