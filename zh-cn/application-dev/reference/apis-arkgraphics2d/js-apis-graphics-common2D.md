# @ohos.graphics.common2D (2D图形通用数据类型)
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

本模块定义了一些2D图形领域的通用数据类型，包括颜色、矩形区域、坐标点等，适用于2D图形绘制等场景，为开发者提供了通用的图形数据结构，便于进行图形计算和渲染操作。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块使用屏幕物理像素单位px。

## 导入模块

```ts
import { common2D } from '@kit.ArkGraphics2D';
```

## Color

ARGB格式的颜色描述。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称  | 类型   | 只读 | 可选 | 说明                                     |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| alpha | number | 否   | 否   | 颜色的A分量（透明度），值是0~255的整数。 |
| red   | number | 否   | 否   | 颜色的R分量（红色），值是0~255的整数。 |
| green | number | 否   | 否   | 颜色的G分量（绿色），值是0~255的整数。 |
| blue  | number | 否   | 否   | 颜色的B分量（蓝色），值是0~255的整数。 |

## Rect

矩形区域，通过左上角点和右下角点两个坐标点定义。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 类型   | 只读 | 可选 | 说明                           |
| ------ | ------ | ---- | ---- | ------------------------------ |
| left   | number | 否   | 否   | 矩形区域的左上角横坐标，浮点数。单位为物理像素px。 |
| top    | number | 否   | 否   | 矩形区域的左上角纵坐标，浮点数。单位为物理像素px。 |
| right  | number | 否   | 否   | 矩形区域的右下角横坐标，浮点数。单位为物理像素px。 |
| bottom | number | 否   | 否   | 矩形区域的右下角纵坐标，浮点数。单位为物理像素px。 |

## Point<sup>12+</sup>

坐标点。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 类型   | 只读 | 可选 | 说明                           |
| ------ | ------ | ---- | ---- | ------------------------------ |
| x      | number | 否   | 否   | 横坐标，浮点数。单位为物理像素px。               |
| y      | number | 否   | 否   | 纵坐标，浮点数。单位为物理像素px。               |

## Color4f<sup>20+</sup>

ARGB格式的颜色描述，颜色分量值为0.0~1.0的浮点数。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称  | 类型   | 只读 | 可选 | 说明                                     |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| alpha | number | 否   | 否   | 颜色的A分量（透明度），值是0.0~1.0的浮点数。 |
| red   | number | 否   | 否   | 颜色的R分量（红色），值是0.0~1.0的浮点数。 |
| green | number | 否   | 否   | 颜色的G分量（绿色），值是0.0~1.0的浮点数。 |
| blue  | number | 否   | 否   | 颜色的B分量（蓝色），值是0.0~1.0的浮点数。 |

## Point3d<sup>12+</sup>

三维的坐标点。继承自[Point](#point12)。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称   | 类型   | 只读 | 可选 | 说明                           |
| ------ | ------ | ---- | ---- | ------------------------------ |
| z      | number | 否   | 否   | z轴坐标，浮点数。单位为物理像素px。               |