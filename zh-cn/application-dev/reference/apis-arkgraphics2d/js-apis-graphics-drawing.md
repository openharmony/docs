# @ohos.graphics.drawing (绘制模块)

drawing模块提供了基本的绘制能力，如绘制矩形、圆形、点、直线、自定义Path、字体等等。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块采用屏幕物理像素单位px。

## 导入模块

```ts
import drawing from '@ohos.graphics.drawing'
```

## BlendMode

混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在4个颜色通道（红、绿、蓝、透明度）上是相同的。 对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。

为简洁起见，我们使用以下缩写：

s : source 源的缩写。 d : destination 目标的缩写。 sa : source alpha 源透明度的缩写。 da : destination alpha 目标透明度的缩写。

计算结果用如下缩写表示：

r : 如果4个通道的计算方式相同，用r表示。 ra : 如果只操作透明度通道，用ra表示。 rc : 如果操作3个颜色通道，用rc表示。

以黄色矩形为源图像，蓝色圆形为目标图像，各混合模式枚举生成的效果示意图请参考下表。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称        | 值   | 说明                                                         | 示意图   | 
| ----------- | ---- | ------------------------------------------------------------ | -------- |
| CLEAR       | 0    | 清除模式，r = 0。                                            | ![CLEAR](./figures/zh-ch_image_BlendMode_Clear.png) |
| SRC         | 1    | r = s（result的4个通道，都等于source的4个通道，即结果等于源。） | ![SRC](./figures/zh-ch_image_BlendMode_Src.png) |
| DST         | 2    | r = d（result的4个通道，都等于destination的4个通道，即结果等于目标。） | ![DST](./figures/zh-ch_image_BlendMode_Dst.png) |
| SRC_OVER    | 3    | r = s + (1 - sa) * d                                         | ![SRC_OVER](./figures/zh-ch_image_BlendMode_SrcOver.png) |
| DST_OVER    | 4    | r = d + (1 - da) * s                                         | ![DST_OVER](./figures/zh-ch_image_BlendMode_DstOver.png) |
| SRC_IN      | 5    | r = s * da                                                   | ![SRC_IN](./figures/zh-ch_image_BlendMode_SrcIn.png) |
| DST_IN      | 6    | r = d * sa                                                   | ![DST_IN](./figures/zh-ch_image_BlendMode_DstIn.png) |
| SRC_OUT     | 7    | r = s * (1 - da)                                             | ![SRC_OUT](./figures/zh-ch_image_BlendMode_SrcOut.png) |
| DST_OUT     | 8    | r = d * (1 - sa)                                             | ![DST_OUT](./figures/zh-ch_image_BlendMode_DstOut.png) |
| SRC_ATOP    | 9    | r = s * da + d * (1 - sa)                                    | ![SRC_ATOP](./figures/zh-ch_image_BlendMode_SrcATop.png) |
| DST_ATOP    | 10   | r = d * sa + s * (1 - da)                                    | ![DST_ATOP](./figures/zh-ch_image_BlendMode_DstATop.png) |
| XOR         | 11   | r = s * (1 - da) + d * (1 - sa)                              | ![XOR](./figures/zh-ch_image_BlendMode_Xor.png) |
| PLUS        | 12   | r = min(s + d, 1)                                            | ![PLUS](./figures/zh-ch_image_BlendMode_Plus.png) |
| MODULATE    | 13   | r = s * d                                                    | ![MODULATE](./figures/zh-ch_image_BlendMode_Modulate.png) |
| SCREEN      | 14   | 滤色模式，r = s + d - s * d                                  | ![SCREEN](./figures/zh-ch_image_BlendMode_Screen.png) |
| OVERLAY     | 15   | 叠加模式                                                     | ![OVERLAY](./figures/zh-ch_image_BlendMode_Overlay.png) |
| DARKEN      | 16   | 变暗模式，rc = s + d - max(s * da, d * sa), ra = s + (1 - sa) * d | ![DARKEN](./figures/zh-ch_image_BlendMode_Darken.png) |
| LIGHTEN     | 17   | 变亮模式，rc = s + d - min(s * da, d * sa), ra = s + (1 - sa) * d | ![LIGHTEN](./figures/zh-ch_image_BlendMode_Lighten.png) |
| COLOR_DODGE | 18   | 颜色减淡模式                                                 | ![COLOR_DODGE](./figures/zh-ch_image_BlendMode_ColorDodge.png) |
| COLOR_BURN  | 19   | 颜色加深模式                                                 | ![COLOR_BURN](./figures/zh-ch_image_BlendMode_ColorBurn.png) |
| HARD_LIGHT  | 20   | 强光模式                                                     | ![HARD_LIGHT](./figures/zh-ch_image_BlendMode_HardLight.png) |
| SOFT_LIGHT  | 21   | 柔光模式                                                     | ![SOFT_LIGHT](./figures/zh-ch_image_BlendMode_SoftLight.png) |
| DIFFERENCE  | 22   | 差值模式，rc = s + d - 2 * (min(s * da, d * sa)), ra = s + (1 - sa) * d | ![DIFFERENCE](./figures/zh-ch_image_BlendMode_Difference.png) |
| EXCLUSION   | 23   | 排除模式，rc = s + d - two(s * d), ra = s + (1 - sa) * d     | ![EXCLUSION](./figures/zh-ch_image_BlendMode_Exclusion.png) |
| MULTIPLY    | 24   | 正片叠底，r = s * (1 - da) + d * (1 - sa) + s * d            | ![MULTIPLY](./figures/zh-ch_image_BlendMode_Multiply.png) |
| HUE         | 25   | 色相模式                                                     | ![HUE](./figures/zh-ch_image_BlendMode_Hue.png) |
| SATURATION  | 26   | 饱和度模式                                                   | ![SATURATION](./figures/zh-ch_image_BlendMode_Saturation.png) |
| COLOR       | 27   | 颜色模式                                                     | ![COLOR](./figures/zh-ch_image_BlendMode_Color.png) |
| LUMINOSITY  | 28   | 亮度模式                                                     | ![LUMINOSITY](./figures/zh-ch_image_BlendMode_Luminosity.png) |

## Path

由直线、圆弧、二阶贝塞尔、三阶贝塞尔组成的复合几何路径。

### moveTo

moveTo(x: number, y: number) : void

用于设置自定义路径的起始点位置。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| x      | number | 是   | 起始点的x轴坐标，该参数为浮点数。 |
| y      | number | 是   | 起始点的y轴坐标，该参数为浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
```

### lineTo

lineTo(x: number, y: number) : void

用于添加一条从路径的最后点位置到目标点位置的线段。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| x      | number | 是   | 目标点的x轴坐标，该参数为浮点数。 |
| y      | number | 是   | 目标点的y轴坐标，该参数为浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.lineTo(10, 15);
```

### arcTo

arcTo(x1: number, y1: number, x2: number, y2: number, startDeg: number, sweepDeg: number): void

用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆， 然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型   | 必填 | 说明                       |
| -------- | ------ | ---- | -------------------------- |
| x1       | number | 是   | 矩形左上角的x坐标，该参数为浮点数。 |
| y1       | number | 是   | 矩形左上角的y坐标，该参数为浮点数。 |
| x2       | number | 是   | 矩形右下角的x坐标，该参数为浮点数。 |
| y2       | number | 是   | 矩形右下角的y坐标，该参数为浮点数。 |
| startDeg | number | 是   | 起始角度，单位为度，该参数为浮点数。 |
| sweepDeg | number | 是   | 扫描度数，单位为度，该参数为浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.arcTo(10, 15, 10, 10, 10, 10);
```

### quadTo

quadTo(ctrlX: number, ctrlY: number, endX: number, endY: number): void

用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                  |
| ------ | ------ | ---- | --------------------- |
| ctrlX  | number | 是   | 控制点的x坐标，该参数为浮点数。 |
| ctrlY  | number | 是   | 控制点的y坐标，该参数为浮点数。 |
| endX   | number | 是   | 目标点的x坐标，该参数为浮点数。 |
| endY   | number | 是   | 目标点的y坐标，该参数为浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.quadTo(10, 15, 10, 10);
```

### cubicTo

cubicTo(ctrlX1: number, ctrlY1: number, ctrlX2: number, ctrlY2: number, endX: number, endY: number): void

用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                        |
| ------ | ------ | ---- | --------------------------- |
| ctrlX1 | number | 是   | 第一个控制点的x坐标，该参数为浮点数。 |
| ctrlY1 | number | 是   | 第一个控制点的y坐标，该参数为浮点数。 |
| ctrlX2 | number | 是   | 第二个控制点的x坐标，该参数为浮点数。 |
| ctrlY2 | number | 是   | 第二个控制点的y坐标，该参数为浮点数。 |
| endX   | number | 是   | 目标点的x坐标，该参数为浮点数。 |
| endY   | number | 是   | 目标点的y坐标，该参数为浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.cubicTo(10, 10, 10, 10, 15, 15);
```

### close

close(): void

用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。

**系统能力**：SystemCapability.Graphics.Drawing

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.cubicTo(10, 10, 10, 10, 15, 15);
path.close();
```

### reset

reset(): void

用于重置自定义路径数据。

**系统能力**：SystemCapability.Graphics.Drawing

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.cubicTo(10, 10, 10, 10, 15, 15);
path.reset();
```

## Canvas

承载绘制内容与绘制状态的载体。

### constructor

constructor(pixelmap: image.PixelMap)

Canvas对象的构造函数。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明           |
| -------- | -------------------------------------------- | ---- | -------------- |
| pixelmap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是   | 构造函数入参。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
import image from '@ohos.multimedia.image';
const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  const canvas = new drawing.Canvas(pixelMap);
})
```

### drawRect

drawRect(rect: common2D.Rect): void

用于绘制一个矩形，默认使用黑色填充。

> **说明：**
>
> 矩形的左上角点的坐标值如果大于右下角的坐标值，可以绘制出矩形；如果左上角和右下角在同一x轴或者y轴，可以绘制出一条直线；如果左上角和右下角是同一点，不会绘制任何内容。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                               | 必填 | 说明           |
| ------ | -------------------------------------------------- | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是   | 绘制的矩形区域 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachPen();
  }
}
```

### drawCircle

drawCircle(x: number, y: number, radius: number): void

用于画一个圆形。如果半径小于等于零，则不绘制任何内容。默认使用黑色填充。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ------ | ------ | ---- | ------------------- |
| x      | number | 是   | 圆心的x坐标，该参数为浮点数。 |
| y      | number | 是   | 圆心的y坐标，该参数为浮点数。 |
| radius | number | 是   | 圆的半径，该参数为浮点数。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawCircle(10, 10, 2);
    canvas.detachPen();
  }
}
```

### drawImage

drawImage(pixelmap: image.PixelMap, left: number, top: number): void

用于画一张图片，图片的左上角坐标为(left, top)。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                            |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| pixelmap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是   | 图片的PixelMap                  |
| left     | number                                       | 是   | 图片位置的左上角x轴坐标，该参数为浮点数。 |
| top      | number                                       | 是   | 图片位置的左上角y轴坐标，该参数为浮点数。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import image from "@ohos.multimedia.image"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  pixelMap: image.PixelMap | null = null;

  async draw(context : DrawContext) {
    const canvas = context.canvas;
    if (this.pixelMap != null) {
      canvas.drawImage(this.pixelMap, 0, 0);
    }
  }
}
```

### drawColor

drawColor(color: common2D.Color, blendMode?: BlendMode): void

绘制背景颜色。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名    | 类型                                                 | 必填 | 说明                             |
| --------- | ---------------------------------------------------- | ---- | -------------------------------- |
| color     | [common2D.Color](js-apis-graphics-common2D.md#color) | 是   | 颜色值，整数。                   |
| blendMode | [BlendMode](#blendmode)                              | 否   | 颜色混合模式，默认模式为SRC_OVER |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let color: common2D.Color = {
      alpha : 255,
      red: 0,
      green: 10,
      blue: 10
    }
    canvas.drawColor(color, drawing.BlendMode.CLEAR);
  }
}
```

### drawPixelMapMesh<sup>12+</sup>

drawPixelMapMesh(pixelmap: image.PixelMap, meshWidth: number, meshHeight: number, vertices: Array\<number>, vertOffset: number, colors: Array\<number>, colorOffset: number): void

在网格上绘制像素图，网格均匀分布在像素图上。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名      | 类型            | 必填 | 说明                            |
| ----------- | -------------  | ---- | ------------------------------- |
| pixelmap    | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是   | 用于绘制网格的像素图。 |
| meshWidth   | number         | 是   | 网格中的列数，大于0的整数。 |
| meshHeight  | number         | 是   | 网格中的行数，大于0的整数。 |
| vertices    | Array\<number> | 是   | 顶点数组，指定网格的绘制位置，浮点数组，大小必须为((meshWidth+1) * (meshHeight+1) + vertOffset) * 2。 |
| vertOffset  | number         | 是   | 绘图前要跳过的vert元素数，大于等于0的整数。 |
| colors      | Array\<number> | 是   | 颜色数组，在每个顶点指定一种颜色，整数数组，可为null，大小必须为(meshWidth+1) * (meshHeight+1) + colorOffset。 |
| colorOffset | number         | 是   | 绘制前要跳过的颜色元素数，大于等于0的整数。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import image from "@ohos.multimedia.image"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  pixelMap: image.PixelMap | null = null;

  async draw(context : DrawContext) {
    const canvas = context.canvas;
    if (this.pixelMap != null) {
      const brush = new drawing.Brush(); // 只支持brush，使用pen没有绘制效果。
      canvas.attachBrush(brush);
      let verts : Array<number> = [0, 0, 50, 0, 410, 0, 0, 180, 50, 180, 410, 180, 0, 360, 50, 360, 410, 360]; // 18
      canvas.drawPixelMapMesh(this.pixelMap, 2, 2, verts, 0, null, 0);
      canvas.detachBrush();
    }
  }
}
```

### drawPoint

drawPoint(x: number, y: number): void

用于绘制一个点。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ------ | ------ | ---- | ------------------- |
| x      | number | 是   | 点的x轴坐标，该参数为浮点数。 |
| y      | number | 是   | 点的y轴坐标，该参数为浮点数。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawPoint(10, 10);
    canvas.detachPen();
  }
}
```

### drawPath

drawPath(path: Path): void

用于绘制一个自定义路径，该路径包含了一组路径轮廓，每个路径轮廓可以是开放的或封闭的。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型          | 必填 | 说明               |
| ------ | ------------- | ---- | ------------------ |
| path   | [Path](#path) | 是   | 要绘制的路径对象。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    let path = new drawing.Path();
    path.moveTo(10,10);
    path.cubicTo(10, 10, 10, 10, 15, 15);
    path.close();
    canvas.attachPen(pen);
    canvas.drawPath(path);
    canvas.detachPen();
  }
}
```

### drawLine

drawLine(x0: number, y0: number, x1: number, y1: number): void

用于画一条直线段，从指定的起点到指点的终点。如果直线段的起点和终点是同一个点，无法绘制。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| x0     | number | 是   | 线段起点的X坐标，该参数为浮点数。 |
| y0     | number | 是   | 线段起点的Y坐标，该参数为浮点数。 |
| x1     | number | 是   | 线段终点的X坐标，该参数为浮点数。 |
| y1     | number | 是   | 线段终点的Y坐标，该参数为浮点数。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawLine(0, 0, 20, 20);
    canvas.detachPen();
  }
}
```

### drawTextBlob

drawTextBlob(blob: TextBlob, x: number, y: number): void

用于绘制一段文字。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                  | 必填 | 说明                                       |
| ------ | --------------------- | ---- | ------------------------------------------ |
| blob   | [TextBlob](#textblob) | 是   | TextBlob对象。                             |
| x      | number                | 是   | 所绘制出的文字基线（下图蓝线）的左端点（下图红点）的横坐标，该参数为浮点数。 |
| y      | number                | 是   | 所绘制出的文字基线（下图蓝线）的左端点（下图红点）的纵坐标，该参数为浮点数。 |

![zh-ch_image_Text_Blob.png](figures/zh-ch_image_Text_Blob.png)

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    const font = new drawing.Font();
    font.setSize(20);
    const textBlob = drawing.TextBlob.makeFromString("Hello, drawing", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 20, 20);
    canvas.detachBrush();
  }
}
```

### attachPen

attachPen(pen: Pen): void

绑定画笔给画布，画布将使用画笔的样式和颜色去绘制图形形状的轮廓。

> **说明：**
>
> 执行该方法后，若pen的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型        | 必填 | 说明       |
| ------ | ----------- | ---- | ---------- |
| pen    | [Pen](#pen) | 是   | 画笔对象。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachPen();
  }
}
```

### attachBrush

attachBrush(brush: Brush): void

绑定画刷给画布，画布将使用画刷的样式和颜色去绘制图形形状，并在其内部进行填充。

> **说明：**
>
> 执行该方法后，若brush的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型            | 必填 | 说明       |
| ------ | --------------- | ---- | ---------- |
| brush  | [Brush](#brush) | 是   | 画刷对象。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachBrush(brush);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachBrush();
  }
}
```

### detachPen

detachPen(): void

用于去除掉画布中的画笔，画布将不再使用画笔去绘制图形形状的轮廓。

**系统能力**：SystemCapability.Graphics.Drawing

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachPen();
  }
}
```

### detachBrush

detachBrush(): void

用于去除掉画布中的画刷，画布将不再使用画刷去绘制图形形状，也不会进行填充。

**系统能力**：SystemCapability.Graphics.Drawing

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachBrush(brush);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachBrush();
  }
}
```

## TextBlobRunBuffer

描述一行文字中具有相同属性的连续字形。

**系统能力**：SystemCapability.Graphics.Drawing

| 名称      | 类型   | 可读 | 可写 | 说明                      |
| --------- | ------ | ---- | ---- | ------------------------- |
| glyph     | number | 是   | 是   | 存储文字的索引，该参数为整数，传入浮点类型时向下取整。 |
| positionX | number | 是   | 是   | 文本的起点x轴坐标，该参数为浮点数。 |
| positionY | number | 是   | 是   | 文本的起点y轴坐标，该参数为浮点数。 |

## TextEncoding

文本的编码类型枚举。

**系统能力**：SystemCapability.Graphics.Drawing

| 名称                   | 值   | 说明                           |
| ---------------------- | ---- | ------------------------------ |
| TEXT_ENCODING_UTF8     | 0    | 使用1个字节表示UTF-8或ASCII。  |
| TEXT_ENCODING_UTF16    | 1    | 使用2个字节表示大部分unicode。 |
| TEXT_ENCODING_UTF32    | 2    | 使用4个字节表示全部unicode。   |
| TEXT_ENCODING_GLYPH_ID | 3    | 使用2个字节表示glyph index。   |

## TextBlob

由一个或多个具有相同字体的字符组成的字块。

### makeFromString

static makeFromString(text: string, font: Font, encoding?: TextEncoding): TextBlob

将string类型的值转化成TextBlob对象。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                          | 必填 | 说明                                   |
| -------- | ----------------------------- | ---- | -------------------------------------- |
| text     | string                        | 是   | 绘制字形的文本内容。                   |
| font     | [Font](#font)                 | 是   | 文本大小、字体、文本比例等。           |
| encoding | [TextEncoding](#textencoding) | 否   | 编码类型，默认值为TEXT_ENCODING_UTF8。 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| [TextBlob](#textblob) | TextBlob对象。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    const font = new drawing.Font();
    font.setSize(20);
    const textBlob = drawing.TextBlob.makeFromString("drawing", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 20, 20);
    canvas.detachBrush();
  }
}
```

### makeFromRunBuffer

static makeFromRunBuffer(pos: Array\<TextBlobRunBuffer>, font: Font, bounds?: common2D.Rect): TextBlob

基于RunBuffer信息创建一个Textblob对象。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                               | 必填 | 说明                           |
| ------ | -------------------------------------------------- | ---- | ------------------------------ |
| pos    | Array\<[TextBlobRunBuffer](#textblobrunbuffer)>    | 是   | TextBlobRunBuffer数组。        |
| font   | [Font](#font)                                      | 是   | 文本大小、字体、文本比例等。   |
| bounds | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 否   | 可选，如果不设置，则无边界框。 |

**返回值：**

| 类型                  | 说明           |
| --------------------- | -------------- |
| [TextBlob](#textblob) | TextBlob对象。 |

**示例：**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const font = new drawing.Font();
    font.setSize(20);
    let runBuffer : Array<drawing.TextBlobRunBuffer> = [
      { glyph: 65, positionX: 0, positionY: 0 },
      { glyph: 227, positionX: 14.9, positionY: 0 },
      { glyph: 283, positionX: 25.84, positionY: 0 },
      { glyph: 283, positionX: 30.62, positionY: 0 },
      { glyph: 299, positionX: 35.4, positionY: 0}
    ];
    const textBlob = drawing.TextBlob.makeFromRunBuffer(runBuffer, font, null);
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 20, 20);
    canvas.detachBrush();
  }
}
```

### bounds

bounds(): common2D.Rect

获取文字边界框的矩形区域。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                                               | 说明                   |
| -------------------------------------------------- | ---------------------- |
| [common2D.Rect](js-apis-graphics-common2D.md#rect) | 文字边界框的矩形区域。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const font = new drawing.Font();
font.setSize(20);
const textBlob = drawing.TextBlob.makeFromString("drawing", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
let bounds = textBlob.bounds();
```

## Typeface

字体，如宋体、楷体等。

### getFamilyName

getFamilyName(): string

获取字体的系列名称。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 返回字体的系列名称。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const font = new drawing.Font();
let typeface = font.getTypeface();
let familyName = typeface.getFamilyName();
```

## Font

描述字形绘制时所使用的属性，如大小、字体等。

### enableSubpixel

enableSubpixel(isSubpixel: boolean): void

使能字体亚像素级别的文字绘制，显示效果平滑。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名     | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isSubpixel | boolean | 是   | 表示是否使能字体亚像素级别的文字绘制。true表示使能，false表示不使能。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.enableSubpixel(true);
```

### enableEmbolden

enableEmbolden(isEmbolden: boolean): void

使能字体粗体。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名     | 类型    | 必填 | 说明                                                  |
| ---------- | ------- | ---- | ----------------------------------------------------- |
| isEmbolden | boolean | 是   | 表示是否使能字体粗体。true表示使能，false表示不使能。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.enableEmbolden(true);
```

### enableLinearMetrics

enableLinearMetrics(isLinearMetrics: boolean): void

使能字形的线性缩放。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名          | 类型    | 必填 | 说明                                                        |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| isLinearMetrics | boolean | 是   | 表示是否使能字形的线性缩放。true表示使能，false表示不使能。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.enableLinearMetrics(true);
```

### setSize

setSize(textSize: number): void

设置字体大小，如果字体大小小于等于零，则无效。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型   | 必填 | 说明             |
| -------- | ------ | ---- | ---------------- |
| textSize | number | 是   | 字体大小，该参数为浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.setSize(5);
```

### getSize

getSize(): number

获取字体大小。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明             |
| ------ | ---------------- |
| number | 字体大小，浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.setSize(5);
let fontSize = font.getSize();
```

### setTypeface

setTypeface(typeface: Typeface): void

设置字体。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                  | 必填 | 说明   |
| -------- | --------------------- | ---- | ------ |
| typeface | [Typeface](#typeface) | 是   | 字体。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.setTypeface(new drawing.Typeface());
```

### getTypeface

getTypeface(): Typeface

获取字体。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                  | 说明   |
| --------------------- | ------ |
| [Typeface](#typeface) | 字体。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
let typeface = font.getTypeface();
```

### getMetrics

getMetrics(): FontMetrics

获取与字体关联的FontMetrics属性。

**系统能力**：SystemCapability.Graphics.Drawing

**返回值：**

| 类型                        | 说明              |
| --------------------------- | ----------------- |
| [FontMetrics](#fontmetrics) | FontMetrics属性。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
let metrics = font.getMetrics();
```

### measureText

measureText(text: string, encoding: TextEncoding): number

测量文本的宽度。

> **说明：**
>
> 此接口用于测量原始字符串的文本宽度，若想测量排版后的文本宽度，建议使用[measure.measureText](../apis-arkui/js-apis-measure.md#measuremeasuretext)替代。

**系统能力**：SystemCapability.Graphics.Drawing

**参数：**

| 参数名   | 类型                          | 必填 | 说明       |
| -------- | ----------------------------- | ---- | ---------- |
| text     | string                        | 是   | 文本内容。 |
| encoding | [TextEncoding](#textencoding) | 是   | 编码格式。 |

**返回值：**

| 类型   | 说明             |
| ------ | ---------------- |
| number | 文本的宽度，浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.measureText("drawing", drawing.TextEncoding.TEXT_ENCODING_UTF8);
```

## FontMetrics

描述字形大小和布局的属性信息，同一种字体中的字符属性大致相同。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称    | 类型   | 可读 | 可写 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| top     | number | 是   | 是   | 文字最高处到基线之间的最大距离，浮点数。                         |
| ascent  | number | 是   | 是   | 文字最高处到基线之间的距离，浮点数。                             |
| descent | number | 是   | 是   | 基线到文字最低处之间的距离，浮点数。                             |
| bottom  | number | 是   | 是   | 基线到文字最低处之间的最大距离，浮点数。                         |
| leading | number | 是   | 是   | 行间距，从上一行文字descent到下一行文字ascent之间的距离，浮点数。 |

## ColorFilter

颜色滤波器。

### createBlendModeColorFilter

createBlendModeColorFilter(color: common2D.Color, mode: BlendMode) : ColorFilter

使用指定的颜色和混合模式创建颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                 | 必填 | 说明             |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | 是   | ARGB格式的颜色。 |
| mode   | [BlendMode](#blendmode)                              | 是   | 颜色的混合模式。 |

**返回值：**

| 类型                        | 说明               |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | 返回一个颜色滤波器 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
let colorFilter = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.SRC);
```

### createComposeColorFilter

createComposeColorFilter(outer: ColorFilter, inner: ColorFilter) : ColorFilter

创建一个先应用inner进行滤波，再应用outer进行滤波的组合颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                        | 必填 | 说明                             |
| ------ | --------------------------- | ---- | -------------------------------- |
| outer  | [ColorFilter](#colorfilter) | 是   | 组合滤波器中后生效的颜色滤波器。 |
| inner  | [ColorFilter](#colorfilter) | 是   | 组合滤波器中先生效的颜色滤波器。 |

**返回值：**

| 类型                        | 说明               |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | 返回一个颜色滤波器 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
let colorFilter1 = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.SRC);
let colorFilter2 = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.DST);
let colorFilter = drawing.ColorFilter.createComposeColorFilter(colorFilter1, colorFilter2);
```

### createLinearToSRGBGamma

createLinearToSRGBGamma() : ColorFilter

创建一个从线性颜色空间转换到SRGB颜色空间的颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                        | 说明               |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | 返回一个颜色滤波器 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
```

### createSRGBGammaToLinear

createSRGBGammaToLinear() : ColorFilter

创建一个从SRGB颜色空间转换到线性颜色空间的颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                        | 说明               |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | 返回一个颜色滤波器 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let colorFilter = drawing.ColorFilter.createSRGBGammaToLinear();
```

### createLumaColorFilter

createLumaColorFilter() : ColorFilter

创建一个将亮度与透明度相乘的颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                        | 说明               |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | 返回一个颜色滤波器 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
let colorFilter = drawing.ColorFilter.createLumaColorFilter();
```

## Pen

画笔对象，用于描述所绘制图形形状的轮廓信息。

### setColor

setColor(color: common2D.Color) : void

用于设置画笔的颜色。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                 | 必填 | 说明             |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | 是   | ARGB格式的颜色。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
const pen = new drawing.Pen();
pen.setColor(color);
```

### setStrokeWidth

setStrokeWidth(width: number) : void

用于设置画笔的线宽。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| width  | number | 是   | 表示线宽，该参数为浮点数。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setStrokeWidth(5);
```

### setAntiAlias

setAntiAlias(aa: boolean) : void

用于设置画笔是否开启反走样。开启后，可以使得图形的边缘在显示时更平滑。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型    | 必填 | 说明                                              |
| ------ | ------- | ---- | ------------------------------------------------- |
| aa     | boolean | 是   | 表示是否开启反走样。true表示开启，false表示关闭。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setAntiAlias(true);
```

### setAlpha

setAlpha(alpha: number) : void

用于设置画笔的透明度。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| alpha  | number | 是   | 用于表示透明度的[0, 255]区间内的整数值，传入浮点类型时向下取整。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setAlpha(128);
```

### setColorFilter

setColorFilter(filter: ColorFilter) : void

用于给画笔添加额外的颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                        | 必填 | 说明         |
| ------ | --------------------------- | ---- | ------------ |
| filter | [ColorFilter](#colorfilter) | 是   | 颜色滤波器。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
pen.setColorFilter(colorFilter);
```

### setBlendMode

setBlendMode(mode: BlendMode) : void

用于设置画笔的混合模式。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                    | 必填 | 说明             |
| ------ | ----------------------- | ---- | ---------------- |
| mode   | [BlendMode](#blendmode) | 是   | 颜色的混合模式。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setBlendMode(drawing.BlendMode.SRC);
```

### setDither

setDither(dither: boolean) : void

开启画笔的抖动绘制效果。抖动绘制可以使得绘制出的颜色更加真实。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| dither | boolean | 是   | 是否开启画笔的抖动绘制效果。true表示开启，false表示关闭。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setDither(true);
```

## Brush

画刷对象，用于描述所绘制图形的填充信息。

### setColor

setColor(color: common2D.Color) : void

用于设置画刷的颜色。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                 | 必填 | 说明             |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | 是   | ARGB格式的颜色。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
const brush = new drawing.Brush();
brush.setColor(color);
```

### setAntiAlias

setAntiAlias(aa: boolean) : void

用于设置画刷是否开启反走样。开启后，可以使得图形的边缘在显示时更平滑。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型    | 必填 | 说明                                              |
| ------ | ------- | ---- | ------------------------------------------------- |
| aa     | boolean | 是   | 表示是否开启反走样。true表示开启，false表示关闭。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const brush = new drawing.Brush();
brush.setAntiAlias(true);
```

### setAlpha

setAlpha(alpha: number) : void

用于设置画刷的透明度。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| alpha  | number | 是   | 用于表示透明度的[0, 255]区间内的整数值，传入浮点类型时向下取整。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const brush = new drawing.Brush();
brush.setAlpha(128);
```

### setColorFilter

setColorFilter(filter: ColorFilter) : void

用于给画刷添加额外的颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                        | 必填 | 说明         |
| ------ | --------------------------- | ---- | ------------ |
| filter | [ColorFilter](#colorfilter) | 是   | 颜色滤波器。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const brush = new drawing.Brush();
let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
brush.setColorFilter(colorFilter);
```

### setBlendMode

setBlendMode(mode: BlendMode) : void

用于设置画刷的混合模式。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                    | 必填 | 说明             |
| ------ | ----------------------- | ---- | ---------------- |
| mode   | [BlendMode](#blendmode) | 是   | 颜色的混合模式。 |

**示例：**

```ts
import drawing from "@ohos.graphics.drawing"
const brush = new drawing.Brush();
brush.setBlendMode(drawing.BlendMode.SRC);
```