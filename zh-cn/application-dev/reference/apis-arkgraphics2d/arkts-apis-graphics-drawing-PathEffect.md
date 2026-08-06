# Class (PathEffect)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

路径效果对象，用于创建多种路径效果，包括虚线、圆角、离散、叠加和组合路径效果等。可通过[Pen.setPathEffect](arkts-apis-graphics-drawing-Pen.md#setpatheffect12)将其应用到画笔上，从而在绘制路径时改变路径的渲染样式。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API version 12开始支持。
>
> - 本模块使用屏幕物理像素单位px。
>
> - 本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

## 导入模块

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## createDashPathEffect<sup>12+</sup>

static createDashPathEffect(intervals: Array\<number>, phase: number): PathEffect

创建将路径变为虚线的路径效果对象，通过指定ON/OFF长度数组生成规则间距的虚线。当需要自定义形状作为虚线段填充时，可使用[createPathDashEffect](#createpathdasheffect18)。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名     | 类型           | 必填    | 说明                                               |
| ---------- | ------------- | ------- | -------------------------------------------------- |
| intervals  | Array\<number> | 是      | 表示虚线的ON（实线部分）和OFF（空白部分）长度的数组，数组元素个数必须是偶数且>=2，数组元素为正整数。单位为物理像素px。|
| phase      | number         | 是      | 绘制时的偏移量，用于调整虚线图案沿路径的起始位置，该参数为浮点数，偏移量会相对于intervals定义的虚线模式产生位移效果。单位为物理像素px。                                     |

**返回值：**

| 类型                      | 说明                   |
| ------------------------- | --------------------- |
| [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 返回创建的虚线路径效果对象，可通过[Pen.setPathEffect](arkts-apis-graphics-drawing-Pen.md#setpatheffect12)将其应用到画笔上以改变路径渲染样式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { common2D, drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let intervals = [10, 5];
    let effect = drawing.PathEffect.createDashPathEffect(intervals, 5);
  }
}
```

## createPathDashEffect<sup>18+</sup>

static createPathDashEffect(path: Path, advance: number, phase: number, style: PathDashStyle): PathEffect

创建一个虚线路径效果对象，通过路径描述的形状生成。与[createDashPathEffect](#createdashpatheffect12)使用intervals数组指定ON/OFF长度创建规则间距虚线不同，本接口通过Path指定虚线段的图形形状。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名     | 类型           | 必填    | 说明                                               |
| ---------- | ------------- | ------- | -------------------------------------------------- |
| path  | [Path](arkts-apis-graphics-drawing-Path.md) | 是 | 通过该路径生成一个图形，用来填充每个虚线段。|
| advance | number | 是 | 虚线段的步长，取值范围>0，否则会抛错误码。单位为物理像素px。 |
| phase | number | 是 | 表示虚线段内图形在虚线步长范围内的偏移量，该参数为浮点数，效果为先对偏移量取绝对值，然后对步长取模。单位为物理像素px。 |
| style | [PathDashStyle](arkts-apis-graphics-drawing-e.md#pathdashstyle18) | 是 | 指定虚线效果的样式，决定虚线段图形在路径上的变换方式。 |

**返回值：**

| 类型                      | 说明                   |
| ------------------------- | --------------------- |
| [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 返回创建的虚线路径效果对象，可通过[Pen.setPathEffect](arkts-apis-graphics-drawing-Pen.md#setpatheffect12)将其应用到画笔上以改变路径渲染样式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3. Parameter verification failed. |

**示例：**

```ts
import { RenderNode, DrawContext } from '@kit.ArkUI';
import { common2D, drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let pen = new drawing.Pen();
    const penColor: common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
    pen.setColor(penColor);
    pen.setStrokeWidth(10);
    pen.setAntiAlias(true);

    const path = new drawing.Path();
    path.moveTo(100, 100);
    path.lineTo(150, 50);
    path.lineTo(200, 100);

    const dashShapePath = new drawing.Path();
    dashShapePath.moveTo(0, 0);
    dashShapePath.lineTo(10, 0);
    dashShapePath.lineTo(20, 10);
    dashShapePath.lineTo(0, 10);

    let pathEffect: drawing.PathEffect = drawing.PathEffect.createPathDashEffect(dashShapePath, 50, -30,
        drawing.PathDashStyle.MORPH);
    pen.setPathEffect(pathEffect);

    canvas.attachPen(pen);
    canvas.drawPath(path);
    canvas.detachPen();
  }
}
```

## createSumPathEffect<sup>18+</sup>

static createSumPathEffect(firstPathEffect: PathEffect, secondPathEffect: PathEffect): PathEffect

创建一个叠加的路径效果。与[createComposePathEffect](#createcomposepatheffect18)不同，此接口会分别对两个参数的效果各自独立进行表现，然后将两个效果简单重叠显示。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名     | 类型           | 必填    | 说明                                               |
| ---------- | ------------- | ------- | -------------------------------------------------- |
| firstPathEffect | [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 是 | 表示第一个路径效果。 |
| secondPathEffect | [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 是 | 表示第二个路径效果。 |

**返回值：**

| 类型                      | 说明                   |
| ------------------------- | --------------------- |
| [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 返回创建的叠加路径效果对象，可通过[Pen.setPathEffect](arkts-apis-graphics-drawing-Pen.md#setpatheffect12)将其应用到画笔上以改变路径渲染样式。 |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let intervals = [10, 5];
    let firstPathEffect = drawing.PathEffect.createDashPathEffect(intervals, 5);
    let secondPathEffect = drawing.PathEffect.createDashPathEffect(intervals, 10);
    let effect = drawing.PathEffect.createSumPathEffect(firstPathEffect, secondPathEffect);
  }
}
```

## createCornerPathEffect<sup>12+</sup>

static createCornerPathEffect(radius: number): PathEffect

创建将路径的夹角变成指定半径的圆角的路径效果对象。该效果会在路径的每个夹角处插入指定半径的弧线段，将原有的尖锐转角替换为平滑的圆角过渡。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名     | 类型           | 必填    | 说明                                               |
| ---------- | ------------- | ------- | -------------------------------------------------- |
| radius     | number        | 是      | 圆角的半径，取值范围>0，该参数为浮点数。单位为物理像素px。                |

**返回值：**

| 类型                      | 说明                   |
| ------------------------- | --------------------- |
| [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 返回创建的圆角路径效果对象，可通过[Pen.setPathEffect](arkts-apis-graphics-drawing-Pen.md#setpatheffect12)将其应用到画笔上以改变路径渲染样式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let effect = drawing.PathEffect.createCornerPathEffect(30);
  }
}
```

## createDiscretePathEffect<sup>18+</sup>

static createDiscretePathEffect(segLength: number, dev: number, seedAssist?: number): PathEffect

创建将路径打散为离散线段并对端点进行随机偏移的路径效果对象。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名     | 类型           | 必填    | 说明                                               |
| ---------- | ------------- | ------- | -------------------------------------------------- |
| segLength  | number        | 是      | 路径中每进行一次打散操作的长度，该参数为浮点数，传入负数或0时无效果。单位为物理像素px。 |
| dev        | number        | 是      | 绘制时每个离散线段端点的最大移动偏离量，该偏离量为浮点数。单位为物理像素px。 |
| seedAssist | number        | 否      | 用于生成离散效果的伪随机种子，影响路径打散的随机分布模式。当需要可复现的离散效果时传入指定种子值；当不需要特定随机分布模式时可省略此参数，省略时默认值为0。该参数为32位无符号整数。超出范围时，该参数值按32位无符号整数溢出回绕规则处理。 |

**返回值：**

| 类型                      | 说明                   |
| ------------------------- | --------------------- |
| [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 返回创建的离散路径效果对象，可通过[Pen.setPathEffect](arkts-apis-graphics-drawing-Pen.md#setpatheffect12)将其应用到画笔上以改变路径渲染样式。 |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let effect = drawing.PathEffect.createDiscretePathEffect(100, -50, 0);
  }
}
```

## createComposePathEffect<sup>18+</sup>

static createComposePathEffect(outer: PathEffect, inner: PathEffect): PathEffect

创建组合路径效果对象，首先应用内部路径效果，然后应用外部路径效果。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                        | 必填 | 说明                             |
| ------ | --------------------------- | ---- | -------------------------------- |
| outer  | [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 是   | 组合路径效果中的外部路径效果，在内部路径效果应用之后进行叠加处理，决定最终呈现的叠加效果。 |
| inner  | [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 是   | 组合路径效果中的内部路径效果，首先应用于原始路径，作为第一层效果处理，随后再由外部路径效果进行叠加。 |

**返回值：**

| 类型                      | 说明                   |
| ------------------------- | --------------------- |
| [PathEffect](arkts-apis-graphics-drawing-PathEffect.md) | 返回创建的组合路径效果对象，可通过[Pen.setPathEffect](arkts-apis-graphics-drawing-Pen.md#setpatheffect12)将其应用到画笔上以改变路径渲染样式。 |

**示例：**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let outerPathEffect = drawing.PathEffect.createCornerPathEffect(100);
    let innerPathEffect = drawing.PathEffect.createCornerPathEffect(10);
    let effect = drawing.PathEffect.createComposePathEffect(outerPathEffect, innerPathEffect);
  }
}
```