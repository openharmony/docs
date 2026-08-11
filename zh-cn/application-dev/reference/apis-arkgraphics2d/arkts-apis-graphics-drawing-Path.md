# Class (Path)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

Path是Drawing模块提供的复合几何路径类，由直线、圆弧、圆锥曲线、二阶贝塞尔、三阶贝塞尔等基本图元组成，支持路径的构造、变换、布尔运算、SVG路径解析与转换、测量与片段截取等能力。未设置填充类型时，默认填充类型为WINDING，可通过[setFillType](#setfilltype12)修改。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块使用屏幕物理像素单位px。
>
> - 本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

## 导入模块

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## constructor<sup>12+</sup>

constructor()

构造一个路径。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
```

## constructor<sup>12+</sup>

constructor(path: Path)

构造一个已有路径的副本。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| path | [Path](arkts-apis-graphics-drawing-Path.md) | 是   | 待复制的路径对象。                 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(0, 700);
path.lineTo(700, 0);
path.close();
let path1: drawing.Path = new drawing.Path(path);
```

## set<sup>20+</sup>

set(src: Path): void

使用指定路径替换当前路径的内容，使当前路径与指定路径完全一致。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| src | [Path](arkts-apis-graphics-drawing-Path.md) | 是   | 用于替换当前路径内容的源路径对象。                 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';
let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(0, 700);
path.lineTo(700, 0);
path.close();
let path1: drawing.Path = new drawing.Path();
path1.set(path);
```

## moveTo

moveTo(x: number, y: number) : void

设置自定义路径的起始点位置。与[rMoveTo](#rmoveto12)使用相对坐标不同，moveTo使用绝对坐标设置起始点。当路径起点固定时，推荐使用moveTo；当路径需要基于当前位置动态构建时，推荐使用[rMoveTo](#rmoveto12)。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| x      | number | 是   | 起始点的x轴坐标，该参数为浮点数。单位为物理像素px。 |
| y      | number | 是   | 起始点的y轴坐标，该参数为浮点数。单位为物理像素px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.moveTo(10, 10);
```

## lineTo

lineTo(x: number, y: number) : void

添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| x      | number | 是   | 目标点的x轴坐标，该参数为浮点数。单位为物理像素px。 |
| y      | number | 是   | 目标点的y轴坐标，该参数为浮点数。单位为物理像素px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.moveTo(10, 10);
path.lineTo(10, 15);
```

## arcTo

arcTo(x1: number, y1: number, x2: number, y2: number, startDeg: number, sweepDeg: number): void

给路径添加一段弧线。绘制弧线的方式为角度弧：首先指定一个矩形边界，取其内切椭圆；然后指定起始角度和扫描度数；最后从起始角度扫描截取椭圆周长的一部分，即为绘制的弧线。另外会默认添加一条从路径最后点位置（若路径没有内容则默认值为 (0, 0)）到弧线起始点位置的线段。若不需要自动添加连接线段，请使用[addArc](#addarc12)。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型   | 必填 | 说明                       |
| -------- | ------ | ---- | -------------------------- |
| x1       | number | 是   | 矩形左上角的x坐标，该参数为浮点数。单位为物理像素px。 |
| y1       | number | 是   | 矩形左上角的y坐标，该参数为浮点数。单位为物理像素px。 |
| x2       | number | 是   | 矩形右下角的x坐标，该参数为浮点数。单位为物理像素px。 |
| y2       | number | 是   | 矩形右下角的y坐标，该参数为浮点数。单位为物理像素px。 |
| startDeg | number | 是   | 起始的角度。角度的起始方向（0°）为x轴正方向。单位为度。 |
| sweepDeg | number | 是   | 扫描的度数，为正数时顺时针扫描，为负数时逆时针扫描。实际扫描的度数为该入参对360取模的结果。单位为度。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.moveTo(10, 10);
path.arcTo(10, 15, 10, 10, 10, 10);
```

## quadTo

quadTo(ctrlX: number, ctrlY: number, endX: number, endY: number): void

添加从路径最后点位置（若路径没有内容则默认值为 (0, 0)）到目标点位置的二阶贝塞尔曲线。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                  |
| ------ | ------ | ---- | --------------------- |
| ctrlX  | number | 是   | 控制点的x坐标，该参数为浮点数。单位为物理像素px。 |
| ctrlY  | number | 是   | 控制点的y坐标，该参数为浮点数。单位为物理像素px。 |
| endX   | number | 是   | 目标点的x坐标，该参数为浮点数。单位为物理像素px。 |
| endY   | number | 是   | 目标点的y坐标，该参数为浮点数。单位为物理像素px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.moveTo(10, 10);
path.quadTo(10, 15, 10, 10);
```

## conicTo<sup>12+</sup>

conicTo(ctrlX: number, ctrlY: number, endX: number, endY: number, weight: number): void

在当前路径上添加一条路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的圆锥曲线，其控制点为 (ctrlX, ctrlY)，目标点为 (endX, endY)。与[quadTo](#quadto)相比，conicTo通过权重参数可更灵活地控制曲线形状：权重为1时效果与quadTo相同，权重不为1时可精确表示圆弧、椭圆弧等圆锥曲线段。仅需标准二次贝塞尔曲线时推荐使用quadTo，需要精确表示圆弧或灵活控制曲线形状时推荐使用conicTo。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                  |
| ------ | ------ | ---- | --------------------- |
| ctrlX  | number | 是   | 控制点的x坐标，该参数为浮点数。单位为物理像素px。 |
| ctrlY  | number | 是   | 控制点的y坐标，该参数为浮点数。单位为物理像素px。 |
| endX   | number | 是   | 目标点的x坐标，该参数为浮点数。单位为物理像素px。 |
| endY   | number | 是   | 目标点的y坐标，该参数为浮点数。单位为物理像素px。 |
| weight | number | 是   | 表示曲线权重，决定了曲线的形状。值越大，曲线越接近控制点。小于等于0时，效果与[lineTo](#lineto)相同；值为1时，效果与[quadTo](#quadto)相同。该参数为浮点数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.conicTo(200, 400, 100, 200, 0);
```

## cubicTo

cubicTo(ctrlX1: number, ctrlY1: number, ctrlX2: number, ctrlY2: number, endX: number, endY: number): void

添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的三阶贝塞尔曲线。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                        |
| ------ | ------ | ---- | --------------------------- |
| ctrlX1 | number | 是   | 第一个控制点的x坐标，该参数为浮点数。单位为物理像素px。 |
| ctrlY1 | number | 是   | 第一个控制点的y坐标，该参数为浮点数。单位为物理像素px。 |
| ctrlX2 | number | 是   | 第二个控制点的x坐标，该参数为浮点数。单位为物理像素px。 |
| ctrlY2 | number | 是   | 第二个控制点的y坐标，该参数为浮点数。单位为物理像素px。 |
| endX   | number | 是   | 目标点的x坐标，该参数为浮点数。单位为物理像素px。 |
| endY   | number | 是   | 目标点的y坐标，该参数为浮点数。单位为物理像素px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.moveTo(10, 10);
path.cubicTo(100, 100, 80, 150, 300, 150);
```

## rMoveTo<sup>12+</sup>

rMoveTo(dx: number, dy: number): void

设置一个相对于当前路径最后点位置（若路径没有内容则默认为 (0, 0)）的路径起始点位置。与[moveTo](#moveto)使用绝对坐标不同，rMoveTo使用相对于当前路径最后点位置的偏移量。当路径需要基于当前位置动态构建时，推荐使用相对坐标方法（如rMoveTo、rLineTo等）；当路径起点固定时，推荐使用绝对坐标方法。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| dx     | number | 是   | 路径新起始点相对于当前路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| dy     | number | 是   | 路径新起始点相对于当前路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.rMoveTo(10, 10);
```

## rLineTo<sup>12+</sup>

rLineTo(dx: number, dy: number): void

使用相对位置添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。与[lineTo](#lineto)使用绝对坐标不同，rLineTo使用相对于当前路径最后点位置的偏移量来指定目标点。当路径需要基于当前位置动态构建时，推荐使用相对坐标方法；当目标点位置固定时，推荐使用绝对坐标方法。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| dx     | number | 是   | 目标点相对于当前路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| dy     | number | 是   | 目标点相对于当前路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.rLineTo(400, 200);
```

## rQuadTo<sup>12+</sup>

rQuadTo(dx1: number, dy1: number, dx2: number, dy2: number): void

使用相对位置添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。与[quadTo](#quadto)使用绝对坐标不同，rQuadTo使用相对于当前路径最后点位置的偏移量在当前路径上添加二阶贝塞尔曲线。当路径需要基于当前位置动态构建时，推荐使用相对坐标方法；当路径目标点固定时，推荐使用绝对坐标方法。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                  |
| ------ | ------ | ---- | --------------------- |
| dx1  | number | 是   | 控制点相对于路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| dy1  | number | 是   | 控制点相对于路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| dx2   | number | 是   | 目标点相对于路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| dy2   | number | 是   | 目标点相对于路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.rQuadTo(100, 0, 0, 200);
```

## rConicTo<sup>12+</sup>

rConicTo(ctrlX: number, ctrlY: number, endX: number, endY: number, weight: number): void

使用相对位置添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的圆锥曲线。与[conicTo](#conicto12)使用绝对坐标不同，rConicTo使用相对于当前路径最后点位置的偏移量在当前路径上添加圆锥曲线。当路径需要基于当前位置动态构建时，推荐使用相对坐标方法；当路径目标点固定时，推荐使用绝对坐标方法。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                  |
| ------ | ------ | ---- | --------------------- |
| ctrlX  | number | 是   | 控制点相对于路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| ctrlY  | number | 是   | 控制点相对于路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| endX   | number | 是   | 目标点相对于路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| endY   | number | 是   | 目标点相对于路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| weight | number | 是   | 表示曲线权重，决定了曲线的形状，越大越接近控制点。若小于等于0则等同于使用[rLineTo](#rlineto12)添加一条到结束点的线段，若为1则等同于[rQuadTo](#rquadto12)，该参数为浮点数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.rConicTo(200, 400, 100, 200, 0);
```

## rCubicTo<sup>12+</sup>

rCubicTo(ctrlX1: number, ctrlY1: number, ctrlX2: number, ctrlY2: number, endX: number, endY: number): void

使用相对位置添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的三阶贝塞尔曲线。与[cubicTo](#cubicto)使用绝对坐标不同，rCubicTo使用相对于当前路径最后点位置的偏移量在当前路径上添加三阶贝塞尔曲线。当路径需要基于当前位置动态构建时，推荐使用相对坐标方法；当路径目标点固定时，推荐使用绝对坐标方法。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                        |
| ------ | ------ | ---- | --------------------------- |
| ctrlX1 | number | 是   | 第一个控制点相对于路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| ctrlY1 | number | 是   | 第一个控制点相对于路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| ctrlX2 | number | 是   | 第二个控制点相对于路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| ctrlY2 | number | 是   | 第二个控制点相对于路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| endX   | number | 是   | 目标点相对于路径最后点位置的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| endY   | number | 是   | 目标点相对于路径最后点位置的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.rCubicTo(200, 0, 0, 200, -20, 0);
```

## addArc<sup>12+</sup>

addArc(rect: common2D.Rect, startAngle: number, sweepAngle: number): void

向路径添加一段圆弧。与[arcTo](#arcto)相比，addArc不会自动添加从路径最后点到弧线起点的连接线段，且通过common2D.Rect对象指定矩形边界。若需要自动连接弧线起点，请使用arcTo；若仅需添加独立弧线，可使用addArc。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| rect        | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是    | 包含弧的椭圆的矩形边界。      |
| startAngle   | number | 是   | 弧的起始角度，单位为度，0°为x轴正方向，该参数为浮点数。当对90取余接近于0且sweepAngle不在(-360, 360)区间内时，将添加整个椭圆而非圆弧。 |
| sweepAngle   | number | 是   | 扫描角度，单位为度。正数表示顺时针方向，负数表示逆时针方向。当参数不在(-360, 360)区间内且startAngle对90取余接近于0时，将添加整个椭圆而非圆弧；其余情况下实际扫描角度为该入参对360取余的结果。该参数为浮点数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
const rect: common2D.Rect = {left:100, top:100, right:500, bottom:500};
path.addArc(rect, 90, 180);
```

## addCircle<sup>12+</sup>

addCircle(x: number, y: number, radius: number, pathDirection?: PathDirection): void

按指定方向，向路径添加圆形，圆的起点位于(x + radius, y)。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| x   | number | 是   | 表示圆心的x轴坐标，该参数为浮点数。单位为物理像素px。 |
| y   | number | 是   | 表示圆心的y轴坐标，该参数为浮点数。单位为物理像素px。 |
| radius   | number | 是   | 表示圆形的半径，取值范围>0，该参数为浮点数，小于等于0时不会有任何效果。单位为物理像素px。 |
| pathDirection   | [PathDirection](arkts-apis-graphics-drawing-e.md#pathdirection12)  | 否   | 表示路径方向。不传入时默认为顺时针方向。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts

import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.addCircle(100, 200, 50, drawing.PathDirection.CLOCKWISE);
```

## addOval<sup>12+</sup>

addOval(rect: common2D.Rect, start: number, pathDirection?: PathDirection): void

按指定方向，将矩形的内切椭圆添加到路径中。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| rect        | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是    | 椭圆的矩形边界。      |
| start   | number | 是   | 表示椭圆初始点的索引，取值范围为不小于0的整数，0、1、2、3分别对应椭圆的上端点、右端点、下端点、左端点，大于等于4时会对4取余。 |
| pathDirection   | [PathDirection](arkts-apis-graphics-drawing-e.md#pathdirection12)  | 否   | 表示路径方向。不传入时默认为顺时针方向。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed.|

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
const rect: common2D.Rect = {left:100, top:100, right:500, bottom:500};
path.addOval(rect, 5, drawing.PathDirection.CLOCKWISE);
```

## addRect<sup>12+</sup>

addRect(rect: common2D.Rect, pathDirection?: PathDirection): void

按指定方向，将矩形添加到路径中，添加的路径的起始点为矩形左上角。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| rect        | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是    | 向路径中添加的矩形轮廓，rect参数需为有效的common2D.Rect对象，left需小于right、top需小于bottom。      |
| pathDirection   | [PathDirection](arkts-apis-graphics-drawing-e.md#pathdirection12)  | 否   | 表示路径方向。不传入时默认为顺时针方向。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed.|

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
const rect: common2D.Rect = {left:100, top:100, right:500, bottom:500};
path.addRect(rect, drawing.PathDirection.CLOCKWISE);
```

## addRoundRect<sup>12+</sup>

addRoundRect(roundRect: RoundRect, pathDirection?: PathDirection): void

按指定方向，向路径添加圆角矩形轮廓。路径添加方向为顺时针时，起始点位于圆角矩形左下方圆角与左边界的交点；路径添加方向为逆时针时，起始点位于圆角矩形左上方圆角与左边界的交点。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| roundRect        | [RoundRect](arkts-apis-graphics-drawing-RoundRect.md) | 是    | 向路径中添加的圆角矩形对象，需为有效的RoundRect对象。      |
| pathDirection   | [PathDirection](arkts-apis-graphics-drawing-e.md#pathdirection12)  | 否   | 表示路径方向。不传入时默认为顺时针方向。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed.|

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
const rect: common2D.Rect = {left:100, top:100, right:500, bottom:500};
let roundRect = new drawing.RoundRect(rect, 50, 50);
path.addRoundRect(roundRect, drawing.PathDirection.CLOCKWISE);
```

## addPath<sup>12+</sup>

addPath(path: Path, matrix?: Matrix | null): void

对源路径进行矩阵变换后，将其添加到当前路径中。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| path        | [Path](arkts-apis-graphics-drawing-Path.md) | 是    | 要添加到当前路径的源路径对象，经过矩阵变换后将被追加到当前路径中。      |
| matrix   | [Matrix](arkts-apis-graphics-drawing-Matrix.md) \| null  | 否   | 表示矩阵对象，用于对源路径进行变换（如旋转、缩放、平移等）。当需要对源路径进行几何变换后再添加到当前路径时传入此参数；当仅需原样添加源路径时可不传入，不传入时默认为单位矩阵（即不进行任何变换）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
let matrix = new drawing.Matrix();
const rect: common2D.Rect = {left:100, top:100, right:500, bottom:500};
let roundRect = new drawing.RoundRect(rect, 50, 50);
path.addRoundRect(roundRect, drawing.PathDirection.CLOCKWISE);
let dstPath = new drawing.Path();
dstPath.addPath(path, matrix);
```

## transform<sup>12+</sup>

transform(matrix: Matrix): void

对路径进行矩阵变换。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| matrix   | [Matrix](arkts-apis-graphics-drawing-Matrix.md)  | 是   | 表示对路径进行矩阵变换所使用的矩阵对象，该矩阵定义了变换的具体参数（如缩放比例、旋转角度、平移距离等），路径中的所有点将按照该矩阵进行变换。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
let matrix = new drawing.Matrix();
matrix.setScale(1.5, 1.5, 10, 10);
const rect: common2D.Rect = {left:100, top:100, right:500, bottom:500};
let roundRect = new drawing.RoundRect(rect, 50, 50);
path.addRoundRect(roundRect, drawing.PathDirection.CLOCKWISE);
path.transform(matrix);
```

## contains<sup>12+</sup>

contains(x: number, y: number): boolean

判断指定坐标点是否被路径包含，判定规则参考[PathFillType](arkts-apis-graphics-drawing-e.md#pathfilltype12)。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| x      | number | 是   | x轴上坐标点，该参数为浮点数。单位为物理像素px。 |
| y      | number | 是   | y轴上坐标点，该参数为浮点数。单位为物理像素px。 |

**返回值：**

| 类型    | 说明           |
| ------- | -------------- |
| boolean | 返回指定坐标点是否在路径内。true表示点在路径内，false表示点不在路径内。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
let rect : common2D.Rect = {left: 50, top: 50, right: 250, bottom: 250};
path.addRect(rect, drawing.PathDirection.CLOCKWISE);
console.info('test contains: ' + path.contains(0, 0));
console.info('test contains: ' + path.contains(60, 60));
```

## setLastPoint<sup>20+</sup>

setLastPoint(x: number, y: number): void

修改路径最后点位置。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| x      | number | 是   | 指定点的x轴坐标，该参数为浮点数。0表示坐标原点，负数表示位于坐标原点左侧，正数表示位于坐标原点右侧。单位为物理像素px。 |
| y      | number | 是   | 指定点的y轴坐标，该参数为浮点数。0表示坐标原点，负数表示位于坐标原点上侧，正数表示位于坐标原点下侧。单位为物理像素px。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';
const path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(0, 700);
let isEmpty = path.isEmpty();
console.info('isEmpty:', isEmpty);
path.reset();
isEmpty = path.isEmpty();
console.info('isEmpty:', isEmpty);
path.setLastPoint(50, 50);
isEmpty = path.isEmpty();
console.info('isEmpty:', isEmpty);
```

## getLastPoint

getLastPoint(): common2D.Point

获取路径最后点位置的坐标。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                                               | 说明                   |
| -------------------------------------------------- | ---------------------- |
| [common2D.Point](js-apis-graphics-common2D.md#point12) | 路径最后点位置坐标。如果路径为空，则返回undefined。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';
const path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(100, 100);
let lastPoint = path.getLastPoint();
console.info('lastPoint.x:', lastPoint?.x);
console.info('lastPoint.y:', lastPoint?.y);
```

## setFillType<sup>12+</sup>

setFillType(pathFillType: PathFillType): void

设置路径的填充类型，决定路径内部区域的定义方式。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名         | 类型                                       | 必填   | 说明                  |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| pathFillType   | [PathFillType](arkts-apis-graphics-drawing-e.md#pathfilltype12)  | 是   | 表示路径填充类型，决定路径内部区域的定义方式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed.|

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.setFillType(drawing.PathFillType.WINDING);
```

## getFillType<sup>20+</sup>

getFillType(): PathFillType

获取路径的填充类型。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                                               | 说明                   |
| -------------------------------------------------- | ---------------------- |
| [PathFillType](arkts-apis-graphics-drawing-e.md#pathfilltype12) | 路径的填充类型，决定路径内部区域的定义方式。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';
const path = new drawing.Path();
path.setFillType(drawing.PathFillType.WINDING);
let type = path.getFillType();
console.info('type :' + type);
```

## getBounds<sup>12+</sup>

getBounds(): common2D.Rect

获取包含路径的最小矩形边界。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                                               | 说明                   |
| -------------------------------------------------- | ---------------------- |
| [common2D.Rect](js-apis-graphics-common2D.md#rect) | 包含路径的最小矩形区域。 |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.lineTo(50, 40);
let rect : common2D.Rect = {left: 0, top: 0, right: 0, bottom: 0};
rect = path.getBounds();
console.info('test rect.left: ' + rect.left);
console.info('test rect.top: ' + rect.top);
console.info('test rect.right: ' + rect.right);
console.info('test rect.bottom: ' + rect.bottom);
```

## addPolygon<sup>12+</sup>

addPolygon(points: Array\<common2D.Point>, close: boolean): void

通过坐标点列表添加多条连续的线段。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| points | Array\<[common2D.Point](js-apis-graphics-common2D.md#point12)>   | 是   | 多边形各顶点的坐标点数组，按数组顺序依次连接各点形成连续线段。 |
| close  | boolean                                                        | 是   | 表示是否将路径闭合，即是否添加路径起始点到终点的连线。true表示将路径闭合，false表示不将路径闭合。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let pointsArray = new Array<common2D.Point>();
const point1: common2D.Point = { x: 200, y: 200 };
const point2: common2D.Point = { x: 400, y: 200 };
const point3: common2D.Point = { x: 100, y: 400 };
const point4: common2D.Point = { x: 300, y: 400 };
pointsArray.push(point1);
pointsArray.push(point2);
pointsArray.push(point3);
pointsArray.push(point4);
const path = new drawing.Path();
path.addPolygon(pointsArray, false);
```

## offset<sup>12+</sup>

offset(dx: number, dy: number): Path

将路径沿x轴方向偏移dx距离、沿y轴方向偏移dy距离，并保存在返回的路径对象中。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| dx     | number        | 是   | x轴方向偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。单位为物理像素px。 |
| dy     | number        | 是   | y轴方向偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。单位为物理像素px。 |

**返回值：**

| 类型   | 说明                |
| ------ | ------------------ |
| [Path](arkts-apis-graphics-drawing-Path.md) | 返回当前路径偏移(dx,dy)后生成的新路径对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
path.moveTo(200, 200);
path.lineTo(300, 300);
const dstPath = path.offset(200, 200);
```

## op<sup>12+</sup>

op(path: Path, pathOp: PathOp): boolean

将当前路径与path按照指定的路径操作类型进行合并，并将合并结果保存在当前路径中。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| path    | [Path](arkts-apis-graphics-drawing-Path.md) | 是   | 路径对象，用于与当前路径合并。 |
| pathOp  | [PathOp](arkts-apis-graphics-drawing-e.md#pathop12)   | 是    | 路径操作类型枚举，用于指定两条路径的布尔运算方式。    |

**返回值：**

| 类型   | 说明                |
| ------ | ------------------ |
| boolean | 返回路径合并是否成功的结果。true表示合并成功，false表示合并失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const path = new drawing.Path();
const path2 = new drawing.Path();
path.addCircle(100, 200, 100, drawing.PathDirection.CLOCKWISE);
console.info('get pathOp: ', path2.op(path, drawing.PathOp.DIFFERENCE));
```

## close

close(): void

闭合路径，会添加一条从路径最后点位置到起始点位置的线段。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.moveTo(10, 10);
path.cubicTo(10, 10, 10, 10, 15, 15);
path.close();
```

## reset

reset(): void

重置自定义路径数据。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.moveTo(10, 10);
path.cubicTo(10, 10, 10, 10, 15, 15);
path.reset();
```

## rewind<sup>20+</sup>

rewind(): void

将路径内添加的各类点/线清空，但是保留内存空间。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';
let path = new drawing.Path();
path.moveTo(10, 10);
path.lineTo(20, 20);
path.rewind();
let empty = path.isEmpty();
console.info('empty : ', empty);
```

## isEmpty<sup>20+</sup>

isEmpty(): boolean

判断路径是否为空。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型  | 说明 |
| ------ | ---- |
| boolean | 路径是否为空。true表示当前路径为空，false表示路径不为空。|

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';
let path = new drawing.Path();
path.moveTo(10, 10);
path.lineTo(20, 20);
let isEmpty = path.isEmpty();
console.info('isEmpty:', isEmpty);
```

## isRect<sup>20+</sup>

isRect(rect: common2D.Rect | null): boolean

判断路径是否构成矩形。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) \| null | 是   | 矩形对象，作为出参使用，路径构成矩形时，会被改写为路径表示的矩形，否则不会改变。可以为null，表示无需获取路径表示的矩形。 |

**返回值：**

| 类型  | 说明 |
| ------ | ---- |
| boolean | 返回路径是否构成矩形。true表示路径构成矩形，false表示路径不构成矩形。|

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.moveTo(10, 10);
path.lineTo(20, 10);
let isRect = path.isRect(null);
console.info('isRect: ', isRect);
let rect: common2D.Rect = { left : 100, top : 100, right : 400, bottom : 500 };
path.lineTo(20, 20);
path.lineTo(10, 20);
path.lineTo(10, 10);
isRect = path.isRect(rect);
console.info('isRect: ', isRect);
```

## getLength<sup>12+</sup>

getLength(forceClosed: boolean): number

获取路径长度。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名| 类型  | 必填| 说明     |
| ----- | ------ | ---- | --------- |
| forceClosed  | boolean | 是  | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。|

**返回值：**

| 类型  | 说明 |
| ------ | ---- |
| number | 路径长度。单位为物理像素px。|

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path = new drawing.Path();
path.arcTo(20, 20, 180, 180, 180, 90);
let len = path.getLength(false);
console.info('path length = ' + len);
```

## getPositionAndTangent<sup>12+</sup>

getPositionAndTangent(forceClosed: boolean, distance: number, position: common2D.Point, tangent: common2D.Point): boolean

获取路径起始点指定距离处的坐标点和切线值。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| forceClosed | boolean | 是   | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。                 |
| distance | number | 是   | 表示与路径起始点的距离，小于0时会被视作0，大于路径长度时会被视作路径长度。该参数为浮点数。单位为物理像素px。               |
| position | [common2D.Point](js-apis-graphics-common2D.md#point12) | 是   | 存储获取到的距离路径起始点distance处的点的坐标。                  |
| tangent | [common2D.Point](js-apis-graphics-common2D.md#point12) | 是   | 存储获取到的距离路径起始点distance处的点的切线值，tangent.x表示该点切线的余弦值，tangent.y表示该点切线的正弦值。                 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean |表示是否成功获取距离路径起始点distance处的点的坐标和切线值的结果。true表示获取成功，false表示获取失败，position和tangent不会被改变。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(0, 700);
path.lineTo(700, 0);
let position: common2D.Point = { x: 0.0, y: 0.0 };
let tangent: common2D.Point = { x: 0.0, y: 0.0 };
if (path.getPositionAndTangent(false, 0.1, position, tangent)) {
  console.info('getPositionAndTangent-----position:  ' + position.x);
  console.info('getPositionAndTangent-----position:  ' + position.y);
  console.info('getPositionAndTangent-----tangent:  ' + tangent.x);
  console.info('getPositionAndTangent-----tangent:  ' + tangent.y);
}
```

## getSegment<sup>18+</sup>

getSegment(forceClosed: boolean, start: number, stop: number, startWithMoveTo: boolean, dst: Path): boolean

截取路径的片段并追加到目标路径上。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| forceClosed | boolean | 是   | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。                 |
| start | number | 是   | 表示与路径起始点的距离，距离路径起始点start距离的位置即为截取路径片段的起始点，小于0时会被视作0，大于等于stop时会截取失败。该参数为浮点数。单位为物理像素px。               |
| stop | number | 是   | 表示与路径起始点的距离，距离路径起始点stop距离的位置即为截取路径片段的终点，小于等于start时会截取失败，大于路径长度时会被视作路径长度。该参数为浮点数。单位为物理像素px。                  |
| startWithMoveTo | boolean | 是   | 表示是否在目标路径执行[moveTo](#moveto)移动到截取路径片段的起始点位置。true表示执行moveTo；false表示不执行moveTo。                |
| dst | [Path](arkts-apis-graphics-drawing-Path.md) | 是   | 目标路径，截取成功时会将得到的路径片段追加到目标路径上，截取失败时不做改变。               |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean |表示是否成功截取路径片段。true表示截取成功，false表示截取失败。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(0, 700);
path.lineTo(700, 0);
let dstPath: drawing.Path = new drawing.Path();
console.info('getSegment-----result:  ' + path.getSegment(true, 10.0, 20.0, true, dstPath));
```

## isClosed<sup>12+</sup>

isClosed(): boolean

获取路径是否闭合。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean | 表示当前路径是否闭合，true表示闭合，false表示不闭合。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(0, 700);
if (path.isClosed()) {
  console.info('path is closed.');
} else {
  console.info('path is not closed.');
}
```

## getMatrix<sup>12+</sup>

getMatrix(forceClosed: boolean, distance: number, matrix: Matrix, flags: PathMeasureMatrixFlags): boolean

在路径上距离起始点distance处，获取一个变换矩阵，用于表示该点的坐标和朝向。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| forceClosed | boolean | 是   | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。                  |
| distance | number | 是   | 表示与路径起始点的距离，小于0时会被视作0，大于路径长度时会被视作路径长度。该参数为浮点数。单位为物理像素px。                  |
| matrix | [Matrix](arkts-apis-graphics-drawing-Matrix.md) | 是   | 用于存储获取到的变换矩阵的矩阵对象，该矩阵表示路径上指定距离处的坐标位置和朝向信息。                  |
| flags | [PathMeasureMatrixFlags](arkts-apis-graphics-drawing-e.md#pathmeasurematrixflags12) | 是   | 矩阵信息维度枚举，用于指定获取的矩阵包含哪些维度信息。                  |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean | 返回是否成功获取变换矩阵的结果。true表示成功，false表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(0, 700);
let matrix = new drawing.Matrix();
if (path.getMatrix(false, 10, matrix, drawing.PathMeasureMatrixFlags.GET_TANGENT_MATRIX)) {
  console.info('path.getMatrix return true');
} else {
  console.info('path.getMatrix return false');
}
```

## buildFromSvgString<sup>12+</sup>

buildFromSvgString(str: string): boolean

解析SVG字符串表示的路径。支持标准SVG路径数据命令（如M、L、C、Q、A、Z及其相对坐标形式等），解析失败时返回false。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| str | string | 是   | SVG路径数据格式的字符串，用于描述绘制路径。支持M/m、L/l、H/h、V/v、C/c、S/s、Q/q、T/t、A/a、Z/z等SVG路径命令，具体语法请参考SVG路径数据规范。传入不符合SVG路径格式的字符串时，解析失败，接口返回false。                 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean | 返回是否成功解析SVG字符串的结果。true表示解析成功，false表示解析失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: Mandatory parameters are left unspecified. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
let svgString: string = "M150 100 L75 300 L225 300 Z";
if (path.buildFromSvgString(svgString)) {
  console.info('buildFromSvgString return true');
} else {
  console.info('buildFromSvgString return false');
}
```

## convertToSvgString

convertToSvgString(): string

将路径转换为SVG字符串。输出的字符串遵循SVG路径数据规范映射。

**系统能力：** SystemCapability.Graphics.Drawing

**模型约束：** 此接口仅可在Stage模型下使用。

**起始版本：** 26.0.0

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| string | 转换后的SVG字符串，以SVG路径格式描述当前路径的几何形状。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(0, 700);
path.close();
let svgString = path.convertToSvgString();
console.info('svgString: ', svgString);
```

## getPointData

getPointData(): Array\<common2D.Point>

获取路径的点数据。

在路径（path）图元中，点数据以数值序列的形式存在，与verb指令一一对应，用来精确指定绘图操作的几何坐标位置。

点数据的主要类型包括：

终点坐标：与[moveTo](#moveto)、[lineTo](#lineto)等指令配合，定义线段或移动的目标位置。

控制点坐标：与曲线指令配合，用于定义贝塞尔曲线的形状（如三次曲线需要两个控制点和一个终点）。

闭合点：通常不单独提供坐标，由[close](#close)指令隐式使用路径起点。

**系统能力：** SystemCapability.Graphics.Drawing

**模型约束：** 此接口仅可在Stage模型下使用。

**起始版本：** 26.0.0

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
|  Array\<[common2D.Point](js-apis-graphics-common2D.md#point12)> | 返回路径的点数据数组，每个元素为common2D.Point对象，其x、y坐标为浮点数。理论取值范围为全体实数，但实际受限于渲染坐标系的有效范围（如-2^31到2^31-1或屏幕可见区域）；超出范围可能导致图形不可见或裁剪。|

**示例：**
```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(100, 100);
path.quadTo(150, 150, 200, 100);
let pointData: Array<common2D.Point> = path.getPointData();
console.info('pointData size: ', pointData.length);
console.info('pointData[0].x: ', pointData[0].x);
console.info('pointData[0].y: ', pointData[0].y);
```

## getVerbData

getVerbData(): Array\<PathIteratorVerb>

获取路径的指令数据。

在路径（path）图元中，指令数据verb用于描述路径构造过程中的基本绘图动作。

指令数据以枚举的形式存在，每个取值对应一种几何操作类型，例如：

[moveTo](#moveto)：将当前绘图点移至指定坐标，不产生线段。

[lineTo](#lineto)：从当前点向指定点绘制直线段。

[close](#close)：将当前点与路径起点相连，形成封闭区域。

**系统能力：** SystemCapability.Graphics.Drawing

**模型约束：** 此接口仅可在Stage模型下使用。

**起始版本：** 26.0.0

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
|Array\<[PathIteratorVerb](arkts-apis-graphics-drawing-e.md#pathiteratorverb18)>| 返回路径的指令数据数组，每个数组元素对应为路径中的基本绘图动作类型，与点数据一一对应。|

**示例：**
```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(100, 100);
path.close();
let verbData: Array<drawing.PathIteratorVerb> = path.getVerbData();
console.info('verbData size: ', verbData.length);
console.info('verbData[0]: ', verbData[0]);
console.info('verbData[1]: ', verbData[1]);
```

## getConicWeightData

getConicWeightData(): Array\<number>

获取路径的圆锥曲线权重数据。

在路径（path）图元中，圆锥曲线数据采用有理贝塞尔曲线（Rational Bézier Curve）形式表示，其中每个控制点附带一个权重值（weight）。权重属于曲线定义的几何参数。

主要作用如下：

形状调控：权重值越大，曲线越靠近对应控制点；权重为1时退化为标准贝塞尔曲线；权重为0时该控制点不起作用。

精确表示圆锥曲线：通过组合权重与二次贝塞尔曲线，可以精确表示圆弧、椭圆弧、抛物线等圆锥曲线段，无需使用分段逼近或专用椭圆弧指令。

数据组织：权重通常以数组形式与点数据并列，按顺序对应每个控制点，与相应的指令verb（如[conicTo](#conicto12)）配合使用。

**系统能力：** SystemCapability.Graphics.Drawing

**模型约束：** 此接口仅可在Stage模型下使用。

**起始版本：** 26.0.0

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| Array\<number> | 类型为浮点数，取值范围≥0。取值为0.0时，该控制点完全无效，曲线不经过此点，曲线实际由其余控制点定义。取值为1.0时，该控制点对应的曲线变为标准贝塞尔曲线，此时权重不产生额外形变效果。取值大于1时，权重值越大，曲线越靠近该控制点；小于1.0但大于0.0时，曲线则相对远离该控制点。|

**示例：**
```ts
import { drawing } from '@kit.ArkGraphics2D';
let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.conicTo(100, 100, 200, 0, 0.5);
let conicWeightData: Array<number> = path.getConicWeightData();
console.info('conicWeightData size: ', conicWeightData.length);
console.info('conicWeightData[0]: ', conicWeightData[0]);
```


## getPathIterator<sup>18+</sup>

getPathIterator(): PathIterator

返回该路径的操作迭代器。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| [PathIterator](arkts-apis-graphics-drawing-PathIterator.md) | 路径的迭代器对象，用于遍历路径中的绘图指令和点数据，可通过迭代器逐条获取路径的verb指令及对应的坐标点。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
let iter = path.getPathIterator();
```

## approximate<sup>20+</sup>

approximate(acceptableError: number): Array\<number>

将当前路径转化为由连续直线段构成的近似路径。

> **说明：**
>
> - 当acceptableError为0时，曲线路径被极度细分，会严重影响性能和内存消耗，不建议设置误差值为0。
> - 当acceptableError远大于路径尺寸时，路径会极度简化，仅保留路径的起止点等少量关键点，可能会丢失原有形状。
> - 对于椭圆等曲线，当acceptableError过大时，拟合结果通常只包含椭圆的分段贝塞尔曲线的起止点，椭圆形会被极度简化为多边形。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| acceptableError | number | 是 | 表示路径上每条线段的可接受误差，取值范围≥0，该参数为浮点数，小于0时报错。单位为物理像素px。 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| Array\<number> | 返回包含近似路径的点的数组，至少包含两个点。每个点由三个值组成：<br>1. 该点所在的位置距离路径起点的长度比例值，范围为[0.0, 1.0]。<br>2. 点的x坐标。<br>3. 点的y坐标。 |

**错误码：**

以下错误码的详细介绍请参见[图形绘制与显示错误码](errorcode-drawing.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 25900001 | Parameter error.Possible causes: Incorrect parameter range. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(100, 100);
path.lineTo(500, 500);
let points: number[] = path.approximate(0.5);
for (let i = 0; i < points.length; i += 3) {
  console.info('PathApproximate Fraction =' + points[i] + ', X =' + points[i + 1] + ', Y =' + points[i + 2] + '\n');
}
```

## interpolate<sup>20+</sup>

interpolate(other: Path, weight: number, interpolatedPath: Path): boolean

根据给定的权重，在当前路径和另一条路径之间进行插值，并将结果存储在目标路径对象中。两条路径点数相同即可插值成功，目标路径按照当前路径的指令结构进行创建。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| other | [Path](arkts-apis-graphics-drawing-Path.md) | 是 | 表示另一条路径对象。 |
| weight | number | 是 | 表示插值权重，取值范围为[0.0, 1.0]。该参数为浮点数。 |
| interpolatedPath | [Path](arkts-apis-graphics-drawing-Path.md) | 是 | 表示用于存储插值结果的目标路径对象。 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean | 返回插值操作是否成功的结果。true表示插值成功，false表示插值失败。 |

**错误码：**

以下错误码的详细介绍请参见[图形绘制与显示错误码](errorcode-drawing.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 25900001 | Parameter error.Possible causes: Incorrect parameter range. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(50, 50);
path.lineTo(100, 100);
path.lineTo(200, 200);
let other: drawing.Path = new drawing.Path();
other.moveTo(80, 80);
other.lineTo(300, 300);
let interpolatedPath: drawing.Path = new drawing.Path();
if (path.interpolate(other, 0.0, interpolatedPath)) {
  console.info('interpolate return true');
} else {
  console.info('interpolate return false');
}
```

## isInterpolate<sup>20+</sup>

isInterpolate(other: Path): boolean

判断当前路径与另一条路径在结构和操作顺序上是否完全一致，以确定两条路径是否兼容插值。若路径中包含圆锥曲线（Conic）操作，则对应操作的权重值也必须一致，才能视为兼容插值。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| other | [Path](arkts-apis-graphics-drawing-Path.md) | 是 | 表示另一条路径对象。 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean | 返回当前路径与另一条路径是否兼容插值的结果。true表示兼容插值，false表示不兼容插值。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(100, 100);
let other: drawing.Path = new drawing.Path();
other.moveTo(0, 1);
other.lineTo(200, 200);
if (path.isInterpolate(other)) {
  console.info('isInterpolate return true');
} else {
  console.info('isInterpolate return false');
}
```

## isEqual

isEqual(path: Path): boolean

判断当前路径与另一条路径是否相等。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| path | [Path](arkts-apis-graphics-drawing-Path.md) | 是 | 另一条路径对象。 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean | 返回当前路径与另一条路径是否相等的结果。true表示路径相等，false表示路径不相等。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.moveTo(0, 0);
path.lineTo(100, 100);
let other: drawing.Path = new drawing.Path();
other.moveTo(0, 0);
other.lineTo(100, 100);
if (path.isEqual(other)) {
  console.info('isEqual return true');
} else {
  console.info('isEqual return false');
}
```

## isInverseFillType<sup>23+</sup>

isInverseFillType(): boolean

检查当前路径填充类型是否是反向填充类型。例如填充类型WINDING、EVEN_ODD不是反向类型，INVERSE_WINDING、INVERSE_EVEN_ODD是反向类型。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| boolean | 检查当前路径填充类型是否是反向填充类型。true表示是反向填充类型，false表示不是反向填充类型。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.setFillType(drawing.PathFillType.WINDING);
if (path.isInverseFillType()) {
  console.info('path is inverse FillType.');
} else {
  console.info('path is not inverse FillType.');
}
```

## toggleInverseFillType<sup>23+</sup>

toggleInverseFillType(): void

切换路径的填充类型为反向类型。例如，使用WINDING填充类型时，经过取反后填充类型为INVERSE_WINDING，而使用EVEN_ODD填充类型时，经过取反后填充类型为INVERSE_EVEN_ODD，反之亦然。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let path: drawing.Path = new drawing.Path();
path.setFillType(drawing.PathFillType.WINDING);
path.toggleInverseFillType();
console.info('path fillType = ', path.getFillType());
```
