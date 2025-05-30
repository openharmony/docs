# @ohos.graphics.uiEffect (效果级联)(系统接口)

本模块提供组件效果的一些基础能力，包括模糊、边缘像素扩展、提亮等。效果被分为Filter和VisualEffect大类，同类效果可以级联在一个效果大类的实例下。在实际开发中，模糊可用于背景虚化，提亮可用于亮屏显示等。

- [Filter](#filter)：用于添加指定Filter效果到组件上。
- [VisualEffect](#visualeffect)：用于添加指定VisualEffect效果到组件上。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 页面仅包含本模块的系统接口，其他公开接口参见[ohos.graphics.uiEffect (效果级联)](js-apis-uiEffect.md)。

## 导入模块

```ts
import { uiEffect } from "@kit.ArkGraphics2D";
```
## uiEffect.createBrightnessBlender
createBrightnessBlender(param: BrightnessBlenderParam): BrightnessBlender

创建BrightnessBlender实例用于给组件添加提亮效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                              | 必填 | 说明                        |
| ------ | ------------------------------------------------- | ---- | --------------------------- |
| param  | [BrightnessBlenderParam](#brightnessblenderparam) | 是   | 实现提亮效果的参数。 |

**返回值：**

| 类型                                     | 说明                     |
| ---------------------------------------- | ----------------------- |
| [BrightnessBlender ](#brightnessblender) | 返回设置了提亮效果参数的BrightnessBlender。 |

**示例：**

```ts
let blender : uiEffect.BrightnessBlender =
  uiEffect.createBrightnessBlender({cubicRate:1.0, quadraticRate:1.0, linearRate:1.0, degree:1.0, saturation:1.0,
    positiveCoefficient:[2.3, 4.5, 2.0], negativeCoefficient:[0.5, 2.0, 0.5], fraction:0.0})
```

## Filter
Filter效果类，用于将相应的效果添加到指定的组件上。在调用Filter的方法前，需要先通过[createFilter](js-apis-uiEffect.md#uieffectcreatefilter)创建一个Filter实例。

### pixelStretch
pixelStretch(stretchSizes: Array\<number\>, tileMode: TileMode): Filter

将边缘像素扩展效果添加至组件上。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| stretchSizes  | Array\<number\>         | 是   | 上下左右四个方向边缘像素扩展的百分比比例，取值范围为[-1, 1]。<br/>正值表示向外扩展，上下左右四个方向分别用指定原图比例的边缘像素填充。负值表示内缩，但是最终图像大小不变。<br/>注意四个方向对应的参数需统一为非正值或非负值。|
| tileMode      | [TileMode](#tilemode) | 是   | 边缘像素扩展的像素填充模式。 |


**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了边缘像素扩展效果的Filter。 |

**示例：**

```ts
filter.pixelStretch([0.2, 0.2, 0.2, 0.2], uiEffect.TileMode.CLAMP)
```

### waterRipple
waterRipple(progress: number, waveCount: number, x: number, y: number, rippleMode: WaterRippleMode): Filter

将水波纹效果添加至组件上。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| progress  | number         | 是   | 表示水波纹的进度，取值范围为[0, 1]。<br/>水波纹进度越趋向于1，水波纹展示越完全。<br/>超出取值范围水波纹不会出现效果。|
| waveCount      | number | 是   | 水波纹波动时波纹的个数，取值范围为[1, 3]。<br/>水波纹的个数只能取整数，如果为浮点数或超出取值范围，水波纹不会出现效果。 |
| x      | number | 是   | 水波纹中心在屏幕中第一次出现的x轴位置。<br/>水波纹对屏幕进行归一化处理，左上角的坐标为（0, 0），右上角坐标为（1, 0）。<br/>当x取值为负值时，代表在屏幕左侧。|
| y      | number | 是   | 水波纹中心在屏幕中第一次出现的y轴位置。<br/>水波纹对屏幕进行归一化处理，左上角的坐标为（0, 0），左下角坐标为（0, 1）。<br/>当y取值为负值时，代表在屏幕上方。 |
| rippleMode      | [WaterRippleMode](#waterripplemode) | 是   | 水波纹的场景模式。|


**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了水波纹效果的Filter。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202  | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.waterRipple(0.5, 2, 0.5, 0.5, uiEffect.WaterRippleMode.SMALL2SMALL)
```

### flyInFlyOutEffect
flyInFlyOutEffect(degree: number, flyMode: FlyMode): Filter

将飞入飞出形变效果添加至组件上。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| degree  | number         | 是   | 表示控制飞入飞出形变的程度，取值范围为[0, 1]。<br/>越靠近1，变形程度越明显。<br/>超出取值范围形变不会出现效果。|
| flyMode      | [FlyMode](#flymode) | 是   | 飞入飞出的场景模式。<br/>BOTTOM表示从设备底部飞入飞出形变场景。<br/>TOP表示从设备顶部飞入飞出形变场景。 |


**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了飞入飞出形变效果的Filter。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202  | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.flyInFlyOutEffect(0.5, uiEffect.FlyMode.TOP)
```

### distort<sup>13+</sup>
distort(distortionK: number): Filter

将透镜畸变效果添加至组件上。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| distortionK  | number         | 是   | 畸变系数，表示透镜畸变的程度，取值范围为[-1, 1]。畸变系数设置小于-1的值时，按值为-1处理；设置大于1的值时，按值为1处理。|

![zh-ch_image_Add_Distort.png](./figures/zh-ch_image_Add_Distort.png)
如上图是对图片组件分别设置畸变参数为-1，0，0.5，1的绘制结果。畸变参数小于0时，效果为桶形畸变；大于0时，效果为枕形畸变；越接近0时，畸变程度越小，等于0时，没有畸变效果。

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了透镜畸变效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.distort(-0.5)
```


### radiusGradientBlur<sup>19+</sup>
radiusGradientBlur(value: number, options: LinearGradientBlurOptions): Filter

为组件内容添加半径线性渐变模糊效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| value  | number         | 是   | 模糊半径，模糊半径越大越模糊。取值范围为[0, 128]。模糊半径设置为0时不模糊；模糊半径设置小于0的值时，按值为0处理；设置大于128的值时，按值为128处理。|
| options  | [LinearGradientBlurOptions](../apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#lineargradientbluroptions12对象说明)         | 是   | 线性渐变参数，包含两个部分fractionStops和direction。|

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了半径线性渐变模糊效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.radiusGradientBlur(20, {fractionStops: [[0, 0], [0.5, 0.2], [1.0, 1.0]], direction: GradientDirection.Bottom})
```

### bezierWarp<sup>20+</sup>
bezierWarp(controlPoints: Array<common2D.Point>): Filter

将贝塞尔曲线变形的效果添加至组件上。该效果通过在图层边界上创建封闭的贝塞尔曲线，实现对图像的精准扭曲和形状调整。贝塞尔曲线共有四段，首尾顺次相连，每段包含一个顶点和两个切点。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| controlPoints  | Array<[common2D.Point](js-apis-graphics-common2D.md#point12)>| 是   | 12个贝塞尔形变控制点，更改控制点的位置可改变形成边缘的曲线的形状，从而扭曲图像。控制点坐标为0-1坐标系，且坐标值可大于1或小于0。|

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了贝塞尔曲线变形效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import uiEffect from '@ohos.graphics.uiEffect'
import {common2D} from '@kit.ArkGraphics2D'
@Entry
@Component
struct BezierWarpExample {
  @State valueBezier: Array<common2D.Point> = [
    {x: 0, y: 0}, {x: 1/3, y: 0}, {x: 2/3, y: 0},     // top edge
    {x: 0.5, y: 0}, {x: 0.5, y: 1/3}, {x: 1, y: 2/3}, // right edge
    {x: 1, y: 1}, {x: 2/3, y: 1}, {x: 1/3, y: 1},     // bottom edge
    {x: 0, y: 1}, {x: 0, y: 2/3}, {x: 0, y: 1/3}]     // left edge

  build() {
    Column() {
      Image('test.jpg')
        .foregroundFilter(uiEffect.createFilter().bezierWarp(this.valueBezier))
    }
  }
}
```

### colorGradient<sup>20+</sup>
colorGradient(colors: Array\<Color>, positions: Array\<common2D.Point>, strengths: Array\<number>, alphaMask?: Mask): Filter

为组件内容添加颜色渐变效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| colors  | Array\<[Color](#color20)>         | 是   | 颜色数组，多个颜色的渐变。数组长度取值范围[0, 12], 每一个颜色值取值范围为大于等于0。数组长度等于0或大于12时无效果，colors、positions和strengths的数组长度不相等时无效果。|
| positions  | Array\<[common2D.Point](js-apis-graphics-common2D.md#point12)>         | 是   | 位置数组，颜色对应的分布位置。数组长度取值范围[0, 12]。数组长度等于0或大于12时无效果，colors、positions和strengths的数组长度不相等时无效果。|
| strengths  | Array\<number>         | 是   | 强度数组，颜色对应的扩散强度。数组长度取值范围[0, 12], 每一个强度值取值范围为大于等于0。数组长度等于0或大于12时无效果，colors、positions和strengths的数组长度不相等时无效果。|
| alphaMask  | [Mask](#mask20)         | 否   | 遮罩alpha，颜色对应的alpha显示遮罩。设置为null或者不设置时，默认图片全部都有颜色渐变效果。|

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了颜色渐变效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.colorGradient([{red: 1.0, green: 0.8, blue: 0.5, alpha: 0.8}, {red: 1.0, green: 1.5, blue: 0.5, alpha: 1.0}], [{x: 0.2, y: 0.2}, {x: 0.8, y: 0.6}], [0.3, 0.3], uiEffect.Mask.createRippleMask({x: 0.5, y: 0.5}, 0.5, 0.5, 0.5))
```

### edgeLight<sup>20+</sup>
edgeLight(alpha: number, color?: Color, mask?: Mask, bloom?: boolean): Filter

为组件内容检测边缘，并添加边缘高亮效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| alpha  | number         | 是   | 指定描边高光透明度，越大描边越明显。取值范围为[0, 1]。设置为0时无描边；设置小于0的值时，按值为0处理；设置大于1的值时，按值为1处理。|
| color  | [Color](#color20) | 否   | 指定描边高光颜色，设置为null或者不设置时，默认使用原图颜色。如果有值，使用指定颜色。设置不为null时，Color中的alpha不发挥作用，仅使用rgb。|
| mask  | [Mask](#mask20) | 否   | 指定描边高光强度。设置为null或者不设置时，默认图片全部都有描边高光效果。|
| bloom  | boolean | 否   | 指定描边是否发光。设置为true时，有描边和发光效果；设置为false时，只有描边效果无发光效果；不设置时，默认为true。小于16*16的图片默认只有描边效果，无发光效果，此参数失去作用。 |

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了描边高光效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
uiEffect.createFilter().edgeLight(1.0, {red: 1.0, green: 0.78, blue: 0.57, alpha: 1.0}, null)
```

### displacementDistort<sup>20+</sup>
displacementDistort(displacementMap: Mask, factor?: [number, number]): Filter

为组件内容添加扭曲效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| mask  | [Mask](#mask20) | 是   | 指定扭曲程度。与factor相乘后共同决定扭曲程度。|
| factor  | [number, number] | 否   | 指定水平、竖直方向扭曲程度系数，越大扭曲程度越明显，取值范围为[0.0, 10.0]。设置为null或者不设置时，默认值为1.0。设置为0时无扭曲；设置小于0的值时按0处理；设置大于10的值时，按值为10处理。与mask相乘后共同决定扭曲程度。 |

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了扭曲效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
uiEffect.createFilter().displacementDistort(uiEffect.Mask.createRippleMask({x: 0.5, y: 1.0}, 1.2, 0.3, 0.0), [1.0, 1.0])
```

### maskDispersion<sup>20+</sup>
maskDispersion(dispersionMask: Mask, alpha: number, rFactor?: [number, number], gFactor?: [number, number], bFactor?: [number, number]): Filter

为组件内容添加由置换贴图控制的色散效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| dispersionMask  | [Mask](#mask20)         | 是   | 置换贴图，用于控制色散的强度、方向和透明度。当前仅支持PixelMapMask类型的置换贴图。|
| alpha  | number         | 是   | 色散整体透明度，透明度越小效果越透明。取值范围为[0, 1.0]。透明度设置为0时色散效果不生效；透明度设置小于0的值时，按值为0处理；设置大于1.0的值时，按值为1.0处理。|
| rFactor  | [number, number]         | 否   | X/Y方向上R通道的色散基础偏移，偏移越大红色色散效果越明显。每个方向上的取值范围为[-1.0, 1.0]。偏移设置小于-1.0的值时，按值为-1.0处理；设置大于1.0的值时，按值为1.0处理。|
| gFactor  | [number, number]         | 否   | X/Y方向上G通道的色散基础偏移，偏移越大绿色色散效果越明显。取值范围同rFactor。|
| bFactor  | [number, number]         | 否   | X/Y方向上B通道的色散基础偏移，偏移越大蓝色色散效果越明显。取值范围同rFactor。|

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了由置换贴图控制的色散效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.maskDispersion(mask, 0.5, [0.15, -0.15], [0.0, 0.0], [-0.15, 0.15])
```

## TileMode
像素填充模式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| CLAMP  | 0 | 截断。 |
| REPEAT | 1 | 重复。 |
| MIRROR | 2 | 镜像。 |
| DECAL  | 3 | 透明。 |

## WaterRippleMode
水波纹场景模式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| SMALL2MEDIUM_RECV  | 0 | 手机碰2in1设备（接收端）。 |
| SMALL2MEDIUM_SEND  | 1 | 手机碰2in1设备（发送端）。 |
| SMALL2SMALL | 2 | 手机碰手机。 |
| MINI_RECV<sup>17+</sup> | 3 | 2in1设备与其它设备共享（键鼠共享场景）。 |

## FlyMode
飞入飞出形变场景模式枚举。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称   | 值 | 说明 |
| ------ | - | ---- |
| BOTTOM  | 0 | 从底部进行飞入飞出形变。 |
| TOP  | 1 | 从顶部进行飞入飞出形变。 |

## VisualEffect
VisualEffect效果类，用于将相应的效果添加到指定的组件上。在调用VisualEffect的方法前，需要先通过[createEffect](js-apis-uiEffect.md#uieffectcreateeffect)创建一个VisualEffect实例。

### backgroundColorBlender
backgroundColorBlender(blender: BrightnessBlender): VisualEffect

将混合器添加至组件上以改变组件背景颜色，具体的更改效果由输入决定，目前仅支持提亮混合器。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                      | 必填 | 说明                       |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| blender | [BrightnessBlender](#brightnessblender) | 是   | 用于混合背景颜色的blender。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [VisualEffect](#visualeffect) | 返回添加了背景颜色更改效果的VisualEffect。 |

**示例：**

```ts
let blender : uiEffect.BrightnessBlender =
  uiEffect.createBrightnessBlender({cubicRate:1.0, quadraticRate:1.0, linearRate:1.0, degree:1.0, saturation:1.0,
    positiveCoefficient:[2.3, 4.5, 2.0], negativeCoefficient:[0.5, 2.0, 0.5], fraction:0.0})
visualEffect.backgroundColorBlender(blender)
```

## Blender<sup>13+</sup>

type Blender = BrightnessBlender

混合器类型，用于描述混合效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [BrightnessBlender](#brightnessblender) | 具有提亮效果的混合器。 |

## BrightnessBlender
提亮混合器，用于将提亮效果添加到指定的组件上。在调用BrightnessBlender前，需要先通过[createBrightnessBlender](#uieffectcreatebrightnessblender)创建一个BrightnessBlender实例。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称                | 类型                        | 只读 | 可选 | 说明                                                              |
| ------------------- | -------------------------- | ---- | ---- | ---------------------------------------------------------------- |
| cubicRate           | number                     | 否   | 否   | 灰度调整的三阶系数。<br/>取值范围[-20, 20]。                        |
| quadraticRate       | number                     | 否   | 否   | 灰度调整的二阶系数。<br/>取值范围[-20, 20]。                        |
| linearRate          | number                     | 否   | 否   | 灰度调整的线性系数。<br/>取值范围[-20, 20]。                        |
| degree              | number                     | 否   | 否   | 灰度调整的比例。<br/>取值范围[-20, 20]。                            |
| saturation          | number                     | 否   | 否   | 提亮的基准饱和度。<br/>取值范围[0, 20]。                            |
| positiveCoefficient | [number, number, number]   | 否   | 否   | 基于基准饱和度的RGB正向调整参数。<br/>每个number的取值范围[-20, 20]。 |
| negativeCoefficient | [number, number, number]   | 否   | 否   | 基于基准饱和度的RGB负向调整参数。<br/>每个number的取值范围[-20, 20]。 |
| fraction            | number                     | 否   | 否   | 提亮效果的混合比例。<br/>取值范围[0, 1]，超出边界会在实现时自动截断。  |

## Color<sup>20+</sup>

RGBA格式的颜色描述。

**系统能力：** SystemCapability.Graphics.Drawing

| 名称  | 类型   | 只读 | 可选 | 说明                                     |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| red   | number | 是   | 是   | 颜色的R分量（红色）。值大于等于0，当值小于0时无效。 |
| green | number | 是   | 是   | 颜色的G分量（绿色）。值大于等于0，当值小于0时无效。|
| blue  | number | 是   | 是   | 颜色的B分量（蓝色）。值大于等于0，当值小于0时无效。 |
| alpha | number | 是   | 是   | 颜色的A分量（透明度）。值大于等于0，当值小于0时无效。 |

## Mask<sup>20+</sup>
Mask效果类，作为[Filter](#filter)以及[VisualEffect](#visualeffect)的输入使用。

### createRippleMask<sup>20+</sup>
static createRippleMask(center: common2D.Point, radius: number, width: number, offset?: number): Mask

通过输入波环圆心的位置、半径和宽度创建波环遮罩效果Mask实例，具体的效果由输入的参数决定。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                      | 必填 | 说明                       |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| center | [common2D.Point](js-apis-graphics-common2D.md#point12) | 是 | 设置波环圆心在屏幕上的位置，[0, 0]为屏幕左上角，[1, 1]为屏幕的右下角。<br/>取值范围[-10, 10]，超出边界会在实现时自动截断。 |
| radius | number | 是 | 设置波环的半径，半径为1等于屏幕的高度。<br/>取值范围[0, 10]，超出边界会在实现时自动截断。 |
| width | number | 是 | 设置波环的宽度。<br/>取值范围[0, 10]，超出边界会在实现时自动截断。 |
| offset | number | 否 | 设置波峰位置的偏移。<br/>默认值为0，表示波峰在波环的正中心；<br/>-1.0表示波峰在波环的最内侧；<br/>1.0表示波峰在波环的最外侧。<br/>取值范围[-1, 1]，超出边界会在实现时自动截断。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [Mask](#mask20) | 返回具有波环遮罩效果的Mask。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
  let mask = uiEffect.Mask.createRippleMask({x:0.5, y:1.0}, 0.5, 0.3, 0.0);
```

### createPixelMapMask<sup>20+</sup>
static createPixelMapMask(pixelMap: image.PixelMap, srcRect: common2D.Rect, dstRect: common2D.Rect, fillColor?: Color): Mask

通过输入的[pixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)pixelMap的待绘制区域、挂载节点的绘制区域和绘制区域外填充的颜色创建具有缩放效果的Mask实例，具体的效果由输入的参数决定。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                      | 必填 | 说明                       |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是   | image模块创建的PixelMap实例。可通过图片解码或直接创建获得，具体可见[图片开发指导](../../media/image/image-overview.md)。   |
| srcRect | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是   | pixelMap的待绘制区域，各元素取值范围为[0, 1]，小于0的转为0，大于1的转为1。图片最左侧和最上侧对应位置0，最右侧和最下侧对应位置1。right需大于left，bottom需大于top。 |
| dstRect | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是   | pixelMap在mask挂载的节点上的绘制区域，各元素取值范围为[0, 1]，小于0的转为0，大于1的转为1。节点最左侧和最上侧对应位置0，最右侧和最下侧对应位置1。right需大于left，bottom需大于top。 |
| fillColor | [Color](#color20) | 否   |  节点上在pixelMap绘制区域之外的区域填充的颜色，各元素取值范围为[0, 1]，默认透明色，小于0的转为0，大于1的转为1。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [Mask](#mask20) | 返回具有pixelMap缩放效果的Mask。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { image } from "@kit.ImageKit";
import { uiEffect, common2D } from "@kit.ArkGraphics2D";

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
  let srcRect : common2D.Rect = {
    left: 0,
    top: 0,
    right: 1,
    bottom: 1
  }
  let dstRect : common2D.Rect = {
    left: 0,
    top: 0,
    right: 1,
    bottom: 1
  }
  let fillColor : uiEffect.Color = {
    red: 0,
    green: 0,
    blue: 0,
    alpha: 1
  }
  let mask = uiEffect.Mask.createPixelMapMask(pixelMap, srcRect, dstRect, fillColor);
})
```

## BrightnessBlenderParam
BrightnessBlender参数列表。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 名称                | 类型                        | 只读 | 可选 | 说明                                                              |
| ------------------- | -------------------------- | ---- | ---- | ---------------------------------------------------------------- |
| cubicRate           | number                     | 否   | 否   | 灰度调整的三阶系数。<br/>取值范围[-20, 20]。                        |
| quadraticRate       | number                     | 否   | 否   | 灰度调整的二阶系数。<br/>取值范围[-20, 20]。                        |
| linearRate          | number                     | 否   | 否   | 灰度调整的线性系数。<br/>取值范围[-20, 20]。                        |
| degree              | number                     | 否   | 否   | 灰度调整的比例。<br/>取值范围[-20, 20]。                            |
| saturation          | number                     | 否   | 否   | 提亮的基准饱和度。<br/>取值范围[0, 20]。                            |
| positiveCoefficient | [number, number, number]   | 否   | 否   | 基于基准饱和度的RGB正向调整参数。<br/>每个number的取值范围[-20, 20]。 |
| negativeCoefficient | [number, number, number]   | 否   | 否   | 基于基准饱和度的RGB负向调整参数。<br/>每个number的取值范围[-20, 20]。 |
| fraction            | number                     | 否   | 否   | 提亮效果的混合比例。<br/>取值范围[0, 1]，超出边界会在实现时自动截断。  |