# Class (Brush)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

画刷对象，用于设置图形的填充样式，包括颜色、抗锯齿、混合模式、颜色滤波器、蒙版滤波器、着色器效果、阴影层效果及图像滤波器等，并支持获取颜色、透明度、抗锯齿等属性及重置画刷为初始状态。

画刷需通过Canvas的[attachBrush](arkts-apis-graphics-drawing-Canvas.md#attachbrush)方法绑定到画布后生效，绘制完成后通过[detachBrush](arkts-apis-graphics-drawing-Canvas.md#detachbrush)方法解绑；画刷用于图形填充，画笔（Pen）用于图形描边，详见[Pen](arkts-apis-graphics-drawing-Pen.md)。

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

构造一个新的画刷对象。默认配置：新建画刷默认抗锯齿关闭、混合模式为SRC_OVER，且未设置颜色滤波器、蒙版滤波器、着色器效果、阴影层效果和图像滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
```

## constructor<sup>12+</sup>

constructor(brush: Brush)

复制构造一个新的画刷对象。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型        | 必填 | 说明              |
| ------| ----------- | ---- | ---------------- |
| brush     | [Brush](arkts-apis-graphics-drawing-Brush.md) | 是   | 待复制的画刷对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
const brushColor: common2D.Color = { alpha: 255, red: 0, green: 255, blue: 0 };
brush.setColor(brushColor);
const newBrush = new drawing.Brush(brush);
```

## setColor

setColor(color: common2D.Color) : void

设置画刷的颜色。设置的颜色将作为图形填充的基础颜色，在未设置ShaderEffect时以该颜色进行渲染填充。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                 | 必填 | 说明             |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | 是   | ARGB格式的颜色，每个颜色通道的取值范围为[0, 255]的整数，传入范围内的浮点数会向下取整。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
const brush = new drawing.Brush();
brush.setColor(color);
```

## setColor<sup>12+</sup>

setColor(alpha: number, red: number, green: number, blue: number): void

设置画刷的颜色。性能优于[setColor](#setcolor)接口，推荐使用本接口。

**系统能力：** SystemCapability.Graphics.Drawing
 
**参数：**

| 参数名 | 类型    | 必填 | 说明                                               |
| ------ | ------ | ---- | -------------------------------------------------- |
| alpha  | number | 是   | ARGB格式颜色的透明度通道值，取值范围为[0, 255]的整数，传入范围内的浮点数会向下取整。 |
| red    | number | 是   | ARGB格式颜色的红色通道值，取值范围为[0, 255]的整数，传入范围内的浮点数会向下取整。   |
| green  | number | 是   | ARGB格式颜色的绿色通道值，取值范围为[0, 255]的整数，传入范围内的浮点数会向下取整。   |
| blue   | number | 是   | ARGB格式颜色的蓝色通道值，取值范围为[0, 255]的整数，传入范围内的浮点数会向下取整。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setColor(255, 255, 0, 0);
```

## setColor<sup>18+</sup>

setColor(color: number) : void

设置画刷的颜色。与[setColor](#setcolor)的区别是支持通过16进制ARGB数值直接设置颜色。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                 | 必填 | 说明             |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | number | 是   | 16进制ARGB格式的颜色，以32位无符号整数表示，格式为0xAARRGGBB，其中AA为透明度通道，RR为红色通道，GG为绿色通道，BB为蓝色通道，取值范围均为0x00到0xFF，整体取值范围为[0x00000000, 0xFFFFFFFF]。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setColor(0xffff0000);
```

## setColor4f<sup>20+</sup>

setColor4f(color4f: common2D.Color4f, colorSpace: colorSpaceManager.ColorSpaceManager \| null): void

设置画刷的颜色以及标准色域。与[setColor](#setcolor)的区别是可以单独设置色域，适用于需要单独设置色域的场景。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                                                 | 必填 | 说明             |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color4f  | [common2D.Color4f](js-apis-graphics-common2D.md#color4f20) | 是   | ARGB格式的颜色，每个颜色通道的值是0.0-1.0之间的浮点数，大于1.0时，取1.0，小于0.0时，取0.0。颜色值在colorSpace参数指定的色域下进行映射。|
| colorSpace  | [colorSpaceManager.ColorSpaceManager](js-apis-colorSpaceManager.md#colorspacemanager) \| null | 是   | 标准色域对象，需通过[colorSpaceManager.create()](js-apis-colorSpaceManager.md#colorspacemanagercreate)方法创建，与color4f配合使用，决定color4f颜色值的映射色域。null表示使用sRGB色域。|

**示例：**

```ts
import { common2D, drawing, colorSpaceManager } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let colorSpace = colorSpaceManager.create(colorSpaceManager.ColorSpace.BT2020_HLG);
let color4f: common2D.Color4f = { alpha: 1, red: 0.5, green: 0.4, blue: 0.7 };
brush.setColor4f(color4f, colorSpace);
```

## getColor<sup>12+</sup>

getColor(): common2D.Color

获取画刷的颜色。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型           | 说明            |
| -------------- | -------------- |
| common2D.Color | 返回画刷的颜色，为ARGB格式的颜色对象，包含alpha、red、green、blue四个通道值，每个通道取值范围为[0, 255]的整数。 |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
const brush = new drawing.Brush();
brush.setColor(color);
let currentColor = brush.getColor();
```

## getColor4f<sup>20+</sup>

getColor4f(): common2D.Color4f

获取画刷的颜色，与[getColor](#getcolor12)的区别是返回值类型为浮点数，适用于需要浮点数类型的场景。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型           | 说明            |
| -------------- | -------------- |
| [common2D.Color4f](js-apis-graphics-common2D.md#color4f20) | 返回画刷的颜色，为浮点数格式的ARGB颜色对象，每个通道值为[0.0, 1.0]之间的浮点数。 |

**示例：**

```ts
import { common2D, drawing, colorSpaceManager } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let colorSpace = colorSpaceManager.create(colorSpaceManager.ColorSpace.BT2020_HLG);
let color4f: common2D.Color4f = { alpha: 1, red: 0.5, green: 0.4, blue: 0.7 };
brush.setColor4f(color4f, colorSpace);
let color = brush.getColor4f();
```

## getHexColor<sup>18+</sup>

getHexColor(): number

获取画刷颜色的16进制ARGB格式值。与[getColor](#getcolor12)的区别是返回值类型为16进制ARGB格式的32位无符号整数。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型           | 说明            |
| -------------- | -------------- |
| number | 返回画刷的颜色，以16进制ARGB格式的32位无符号整数表示。 |

**示例：**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
let brush = new drawing.Brush();
brush.setColor(color);
let hexColor: number = brush.getHexColor();
console.info('getHexColor: ', hexColor.toString(16));
```

## setAntiAlias

setAntiAlias(aa: boolean) : void

设置画刷是否开启抗锯齿。开启后，图形边缘显示更平滑。未调用此接口设置时，系统默认关闭抗锯齿。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型    | 必填 | 说明                                              |
| ------ | ------- | ---- | ------------------------------------------------- |
| aa     | boolean | 是   | 表示是否开启抗锯齿，true表示开启，false表示关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setAntiAlias(true);
```

## isAntiAlias<sup>12+</sup>

isAntiAlias(): boolean

获取画刷是否开启抗锯齿属性。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型    | 说明                       |
| ------- | ------------------------- |
| boolean | 返回画刷是否开启抗锯齿属性，true表示开启，false表示关闭。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let isAntiAlias = brush.isAntiAlias();
```

## setAlpha

setAlpha(alpha: number) : void

设置画刷的透明度。调用setAlpha后，渲染时以setAlpha设置的透明度为准，覆盖setColor中Color对象的alpha通道值。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| alpha  | number | 是   | 用于表示透明度的取值范围为[0, 255]的整数，传入范围内的浮点数会向下取整。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setAlpha(128);
```

## getAlpha<sup>12+</sup>

getAlpha(): number

获取画刷的透明度。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型   | 说明              |
| ------ | ---------------- |
| number | 返回画刷的透明度，取值范围为[0, 255]的整数。 |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let alpha = brush.getAlpha();
```

## setColorFilter

setColorFilter(filter: ColorFilter | null) : void

设置画刷的颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                        | 必填 | 说明         |
| ------ | --------------------------- | ---- | ------------ |
| filter | [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) \| null | 是   | 颜色滤波器，用于对绘制内容进行颜色调整（如伽马校正、颜色矩阵变换等）。null表示清空颜色滤波器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
brush.setColorFilter(colorFilter);
```

## setMaskFilter<sup>12+</sup>

setMaskFilter(filter: MaskFilter | null): void

设置画刷的蒙版滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                       | 必填 | 说明      |
| ------ | ------------------------- | ---- | --------- |
| filter | [MaskFilter](arkts-apis-graphics-drawing-MaskFilter.md) \| null | 是   | 蒙版滤波器，用于对绘制图形边缘进行模糊处理等场景。null表示清空蒙版滤波器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { RenderNode, DrawContext } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const brush = new drawing.Brush();
    let maskFilter = drawing.MaskFilter.createBlurMaskFilter(drawing.BlurType.OUTER, 10);
    brush.setMaskFilter(maskFilter);
  }
}
```

## setShaderEffect<sup>12+</sup>

setShaderEffect(shaderEffect: ShaderEffect | null): void

设置画刷的着色器效果。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名  | 类型                       | 必填 | 说明         |
| ------- | ------------------------- | ---- | ------------ |
| shaderEffect  | [ShaderEffect](arkts-apis-graphics-drawing-ShaderEffect.md) \| null | 是   | 着色器效果对象，用于实现渐变填充、图案填充等复杂绘制效果。null表示清空着色器效果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let shaderEffect = drawing.ShaderEffect.createLinearGradient({x: 100, y: 100}, {x: 300, y: 300}, [0xFF00FF00, 0xFFFF0000], drawing.TileMode.REPEAT);
brush.setShaderEffect(shaderEffect);
```

## setShadowLayer<sup>12+</sup>

setShadowLayer(shadowLayer: ShadowLayer | null): void

设置画刷的阴影层效果。当前仅在通过Canvas的[drawTextBlob](arkts-apis-graphics-drawing-Canvas.md#drawtextblob)等方法绘制文字时生效。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名  | 类型                       | 必填 | 说明      |
| ------- | ------------------------- | ---- | --------- |
| shadowLayer  | [ShadowLayer](arkts-apis-graphics-drawing-ShadowLayer.md) \| null | 是   | 阴影层对象，用于给画刷添加阴影效果。null表示清空阴影层效果。该阴影层效果仅在绘制文字时生效。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**示例：**

```ts
import { RenderNode, DrawContext } from '@kit.ArkUI';
import { common2D, drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let font = new drawing.Font();
    font.setSize(60);

    let textBlob = drawing.TextBlob.makeFromString('hello', font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    let pen = new drawing.Pen();
    pen.setStrokeWidth(2.0);

    let penColor : common2D.Color = {alpha: 0xFF, red: 0xFF, green: 0x00, blue: 0x00};
    pen.setColor(penColor);
    canvas.attachPen(pen);
    canvas.drawTextBlob(textBlob, 100, 100);
    canvas.detachPen();

    let color : common2D.Color = {alpha: 0xFF, red: 0x00, green: 0xFF, blue: 0x00};
    let shadowLayer = drawing.ShadowLayer.create(3, -3, 3, color);
    pen.setShadowLayer(shadowLayer);
    canvas.attachPen(pen);
    canvas.drawTextBlob(textBlob, 100, 200);
    canvas.detachPen();

    let brush = new drawing.Brush();
    let brushColor : common2D.Color = {alpha: 0xFF, red: 0xFF, green: 0x00, blue: 0x00};
    brush.setColor(brushColor);
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 300, 100);
    canvas.detachBrush();

    brush.setShadowLayer(shadowLayer);
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 300, 200);
    canvas.detachBrush();
  }
}
```

## setBlendMode

setBlendMode(mode: BlendMode) : void

设置画刷的混合模式。未调用此接口设置时，系统默认的混合模式为SRC_OVER。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型                    | 必填 | 说明             |
| ------ | ----------------------- | ---- | ---------------- |
| mode   | [BlendMode](arkts-apis-graphics-drawing-e.md#blendmode) | 是   | 颜色的混合模式，用于控制绘制时源颜色与已有目标颜色的混合方式。未调用此接口设置时，系统默认的混合模式为SRC_OVER。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setBlendMode(drawing.BlendMode.SRC);
```

## setImageFilter<sup>12+</sup>

setImageFilter(filter: ImageFilter | null): void

设置画刷的图像滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| filter    | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) \| null | 是   | 图像滤波器，用于对绘制内容进行模糊、锐化等图像处理。null表示清空图像滤波器。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types. | 

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let brush = new drawing.Brush();
let imageFilter = drawing.ImageFilter.createBlurImageFilter(5, 10, drawing.TileMode.DECAL);
brush.setImageFilter(imageFilter);
brush.setImageFilter(null);
```

## getColorFilter<sup>12+</sup>

getColorFilter(): ColorFilter

获取画刷的颜色滤波器。

**系统能力：** SystemCapability.Graphics.Drawing

**返回值：**

| 类型                        | 说明               |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | 返回画刷的颜色滤波器，用于对绘制内容进行颜色调整，如伽马校正、颜色矩阵变换等。 |

**示例：**

```ts 
import { drawing } from '@kit.ArkGraphics2D';

let brush = new drawing.Brush();
let colorFilter = drawing.ColorFilter.createSRGBGammaToLinear();
brush.setColorFilter(colorFilter);
let currentFilter = brush.getColorFilter();   
```

## reset<sup>12+</sup>

reset(): void

重置当前画刷为初始状态，清除已设置的颜色、透明度、抗锯齿、颜色滤波器、蒙版滤波器、着色器效果、阴影层效果、混合模式和图像滤波器等属性。初始状态的具体取值：抗锯齿关闭、混合模式为SRC_OVER，且未设置颜色滤波器、蒙版滤波器、着色器效果、阴影层效果和图像滤波器。如需使用上述属性，需要重新调用对应的set接口进行设置。

**系统能力：** SystemCapability.Graphics.Drawing

**示例：**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.reset();
```