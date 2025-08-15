# @ohos.graphics.uiEffect (效果级联)(系统接口)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hanamaru-->
<!--Designer: @comicchang-->
<!--Tester: @gcw_fsLqk7gL-->
<!--Adviser: @ge-yafang-->

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
| [BrightnessBlender](#brightnessblender) | 返回设置了提亮效果参数的BrightnessBlender。 |

**示例：**

```ts
let blender : uiEffect.BrightnessBlender =
  uiEffect.createBrightnessBlender({cubicRate:1.0, quadraticRate:1.0, linearRate:1.0, degree:1.0, saturation:1.0,
    positiveCoefficient:[2.3, 4.5, 2.0], negativeCoefficient:[0.5, 2.0, 0.5], fraction:0.0})
```

## uiEffect.createHdrBrightnessBlender<sup>20+</sup>
createHdrBrightnessBlender(param: BrightnessBlenderParam): HdrBrightnessBlender

创建[HdrBrightnessBlender](#hdrbrightnessblender20)实例用于给组件添加支持HDR的提亮效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                              | 必填 | 说明                        |
| ------ | ------------------------------------------------- | ---- | --------------------------- |
| param  | [BrightnessBlenderParam](#brightnessblenderparam) | 是   | 实现提亮效果的参数。 |

**返回值：**

| 类型                                     | 说明                     |
| ---------------------------------------- | ----------------------- |
| [HdrBrightnessBlender](#hdrbrightnessblender20) | 返回具有提亮效果的混合器（支持HDR）。 |

**示例：**

```ts
import { uiEffect } from "@kit.ArkGraphics2D"

let blender : uiEffect.HdrBrightnessBlender =
  uiEffect.createHdrBrightnessBlender({cubicRate:1.0, quadraticRate:1.0, linearRate:1.0, degree:1.0, saturation:1.0,
    positiveCoefficient:[2.3, 4.5, 2.0], negativeCoefficient:[0.5, 2.0, 0.5], fraction:0.0})

@Entry
@Component
struct example {
  build() {
    RelativeContainer() {
      Image($r("app.media.screenshot"))
        .width("100%")
        .height("100%")
        .advancedBlendMode(blender)
    }
  }
}
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
import { uiEffect } from "@kit.ArkGraphics2D"

@Entry
@Component
struct RadiusGradientBlurExample {
  @State blurRadiusExample: number = 64
  @State linearGradientBlurOptionsExample: LinearGradientBlurOptions =
    {fractionStops: [[0.0, 0.0], [1.0, 1.0]], direction: GradientDirection.Bottom}

  build() {
    Column() {
      Image($rawfile('test.png'))
        .compositingFilter(uiEffect.createFilter().radiusGradientBlur(this.blurRadiusExample,
          this.linearGradientBlurOptionsExample))
    }
  }
}
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
| alphaMask  | [Mask](#mask20)         | 否   | 遮罩alpha，颜色对应的alpha显示遮罩。不设置时，默认组件内容全部有颜色渐变效果。|

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
import { common2D, uiEffect } from "@kit.ArkGraphics2D"

@Entry
@Component
struct ColorGradientExample {
  @State colorsExample: Array<uiEffect.Color> = [
    {red: 1.0, green: 0.8, blue: 0.5, alpha: 0.8},
    {red: 1.0, green: 1.5, blue: 0.5, alpha: 1.0}
  ]

  @State positionsExample: Array<common2D.Point> = [
    {x: 0.2, y: 0.2},
    {x: 0.8, y: 0.6}]

  @State strengthsExample: Array<number> = [0.3, 0.3]

  build() {
    Column() {
      Row()
        .width("100%")
        .height("100%")
        .backgroundFilter(uiEffect.createFilter().colorGradient(this.colorsExample, this.positionsExample, this.strengthsExample))
    }
  }
}
```

### contentLight<sup>20+</sup>
contentLight(lightPosition: common2D.Point3d, lightColor: common2D.Color, lightIntensity: number, displacementMap?: Mask): Filter

为组件内容添加3D光照效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| lightPosition | [common2D.Point3d](js-apis-graphics-common2D.md#point3d12) | 是 | 光源在组件空间的位置，[-1, -1, 0]为组件左上角，[1, 1, 0]为组件的右下角，z轴分量越大光源离组件平面越远，可照射区域越大。<br/> x分量取值范围[-10, 10]，y分量取值范围[-10, 10]，z分量取值范围[0, 10]，超出范围会自动截断。 |
| lightColor | [common2D.Color](js-apis-graphics-common2D.md#color) | 是 | 光源颜色，各元素取值范围为[0, 1]，超出范围会自动截断。 |
| lightIntensity | number | 是 | 光源强度，取值范围[0, 1]，数值越大光源亮度越大，超出范围会自动截断。|
| displacementMap | [Mask](#mask20) | 否 | 该参数暂不生效。 |

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [filter](#filter) | 返回了具有内容光照效果的filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { common2D, uiEffect } from '@kit.ArkGraphics2D'
@Entry
@Component
struct Index {
  @State point2:common2D.Point3d = {
    x:0,y:0,z:2
  }
  @State color2:common2D.Color = {
    red:1,green:1,blue:1,alpha:1
  }
  @State lightIntentsity2:number = 1

  build() {
    Column() {
      Stack() {
        Image($r('app.media.man'))
          .width('646px')
          .height('900px')
          .borderRadius(10)
          .foregroundFilter(uiEffect.createFilter().contentLight(this.point2, this.color2, this.lightIntentsity2))
      }
      .width('100%')
      .height('55%')
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .backgroundColor('#555')
  }
}
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
| color  | [Color](#color20) | 否   | 指定描边高光颜色，不设置时，将默认使用组件内容的原始颜色。如果有值，使用指定颜色。设置不为null时，Color中的alpha不发挥作用，仅使用rgb。|
| mask  | [Mask](#mask20) | 否   | 指定描边高光强度。不设置时，默认组件内容全部有描边高光效果。|
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
import { uiEffect } from "@kit.ArkGraphics2D"

@Entry
@Component
struct EdgeLightExample {
  @State colorExample: uiEffect.Color = {red: 0.0, green: 1.0, blue: 0.0, alpha: 1.0}
  
  @State maskExample: uiEffect.Mask = uiEffect.Mask.createRippleMask({x: 0.5, y: 0.5}, 0.2, 0.5, 0.5)
  
  build() {
    Stack() {
      Image($rawfile('test.png'))
      Row()  
        .width("100%")
        .height("100%")
        .backgroundFilter(uiEffect.createFilter().edgeLight(1.0, this.colorExample, this.maskExample, false))
    }
  }
}
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
| factor  | [number, number] | 否   | 指定水平、竖直方向扭曲程度系数，系数的绝对值越大，扭曲程度越明显，建议取值范围为[-10.0, 10.0]。不设置时，默认值为1.0。设置为0时，无扭曲效果。与mask相乘后共同决定扭曲程度。 |

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
import { uiEffect } from "@kit.ArkGraphics2D"

@Entry
@Component
struct DisplacementDistortExample {
  @State maskExample: uiEffect.Mask = uiEffect.Mask.createRippleMask({x: 0.5, y: 0.5}, 0.2, 0.3, 0.0)
  
  build() {
    Stack() {
      Image($rawfile('test.png'))
      Row()  
        .width("100%")
        .height("100%")
        .backgroundFilter(uiEffect.createFilter().displacementDistort(this.maskExample, [5.0, 5.0]))
    }
  }
}
```

### maskDispersion<sup>20+</sup>
maskDispersion(dispersionMask: Mask, alpha: number, rFactor?: [number, number], gFactor?: [number, number], bFactor?: [number, number]): Filter

为组件内容添加由置换贴图控制的色散效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| dispersionMask  | [Mask](#mask20)         | 是   | 置换贴图，用于控制色散的强度、方向和透明度。建议使用PixelMapMask类型的置换贴图。|
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
import {image} from '@kit.ImageKit'
import {common2D, uiEffect} from '@kit.ArkGraphics2D'
import {common} from '@kit.AbilityKit'

@Entry
@Component
struct MaskDispersion {
  @State pixelMap_: PixelMap | null = null
  @State src: common2D.Rect = { left: 0, top: 0, right: 1.0, bottom: 1.0 }
  @State dst: common2D.Rect = { left: 0, top: 0, right: 1.0, bottom: 1.0 }
  @State fillColor: uiEffect.Color = { red: 0, green: 0, blue: 0, alpha: 0 }

  onPageShow(): void {
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext
    context.resourceManager.getMediaContent($r("app.media.mask_alpha")).then(val => {
      let buffer = val.buffer.slice(0, val.buffer.byteLength)
      let imageSource = image.createImageSource(buffer);
      imageSource.createPixelMap().then(pixelMap => {
        this.pixelMap_ = pixelMap
      })
    })
  }
  
  build() {
    Stack() {
      Image($rawfile('test.png'))
      Row()  
        .width("100%")
        .height("100%")
        .backgroundFilter(uiEffect.createFilter().maskDispersion(
          uiEffect.Mask.createPixelMapMask(this.pixelMap_, this.src, this.dst, this.fillColor),
          1.0,
          [0.5, -0.5],
          [0.0, 0.0],
          [-0.5, 0.5]))
    }
  }
}
```

### hdrBrightnessRatio<sup>20+</sup>
hdrBrightnessRatio(ratio: number): Filter

为组件内容添加HDR（高动态范围成像）提亮效果。不建议嵌套使用，强行嵌套使用可能造成过曝现象。

提亮效果需要开启HDR渲染管线才能生效，某些场景下即使尝试触发HDR渲染管线也无法开启HDR，例如：设备硬件规格不支持HDR。

设备当前支持最大提亮倍数为设备当前的最大亮度除以设备SDR参考白亮度得到的值。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| ratio  | number         | 是   | 提亮倍数，取值范围为[1.0, 设备当前支持最大提亮倍数]。设置小于1.0的值时，按值为1.0处理；当值等于1.0时，不做任何处理；当值大于1.0时，会尝试触发HDR渲染管线，设置大于设备当前支持最大提亮倍数的值时，按值为设备当前支持最大提亮倍数处理。|

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了HDR提亮效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
filter.hdrBrightnessRatio(2.0)
```

### maskTransition<sup>20+</sup>
maskTransition(alphaMask: Mask, factor?: number, inverse?: boolean): Filter

为组件内容提供基于[Mask](#mask20)的转场效果。

不建议在屏幕尺寸发生改变的过程中使用此效果，如：旋转屏幕，折叠屏开合屏幕等。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| alphaMask     | [Mask](#mask20)       | 是   | 通过遮罩指定转场效果的作用区域。|
| factor        | number                | 否   | 转场过渡系数，取值范围为[0.0, 1.0]，默认值为1.0。factor值越大画面越接近转场后页面，超出范围自动截断到[0.0, 1.0]。 |
| inverse       | boolean               | 否   | 是否启用反向转场，true表示启用，false表示不启用，默认值为false。 |
 
**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了转场效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { uiEffect, common2D } from "@kit.ArkGraphics2D";

@Entry
@Component
struct Index {
  context = this.getUIContext()
  @State alpha: number = 0
  @State enterNewPage:boolean = false
  @State rippleMaskCenter: common2D.Point = {x:0.5, y:0.5}
  @State rippleMaskRadius: number = 0.1
  build() {
    Stack() {
      //转场前页面
      Image($r("app.media.before")).width("100%").height("100%")
        if (this.enterNewPage){
          //转场后页面
          Column().width("100%").height("100%").backgroundImage($r("app.media.after"))
            .backgroundFilter(uiEffect.createFilter()
              .maskTransition(
                uiEffect.Mask.createRadialGradientMask(this.rippleMaskCenter, this.rippleMaskRadius,this.rippleMaskRadius, [[1, 0], [1, 1]]),
                this.alpha))
            .onAppear(() => {
              this.context.animateTo({ duration: 1000 }, () => {
                this.rippleMaskRadius = 1.3
              })
              this.context.animateTo({ duration: 800 }, () => {
                this.alpha = 1
              })
            })
        }
    }.borderWidth(2)
    .onClick(()=>{
      this.enterNewPage=!this.enterNewPage;
      if (this.enterNewPage) {
        this.alpha=0;
        this.rippleMaskRadius=0.1;
      }
    })
  }
}
```

### directionLight<sup>20+</sup>
directionLight(direction: common2D.Point3d, color: Color, intensity: number, mask?: Mask, factor?: number): Filter

为组件内容提供基于[Mask](#mask20)和平行光的光照效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| direction  | [common2D.Point3d](js-apis-graphics-common2D.md#point3d12)         | 是   | 方向光的入射方向。|
| color  | [Color](#color20)         | 是   | 光照颜色。|
| intensity  | number         | 是   | 光照强度，非负数。|
| mask  | [Mask](#mask20)         | 否   | 置换贴图，用于描述二维图像表面的三维细节，通过法线或高度图增强局部细节和光照反射效果，若输入为高度图，须与factor参数配合使用。默认为空，表现为全局无细节的平面光照效果。|
| factor  | number         | 否   | 采样缩放系数。默认值为null，mask作为法线图采样；非默认值时，mask作为高度图采样，实际高度值为mask的采样值与factor的乘积。|

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回挂载了由置换贴图控制的光照效果的Filter。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { uiEffect, common2D } from "@kit.ArkGraphics2D";

@Entry
@Component
struct Index {
  @State rippleMaskCenter: common2D.Point = {x:0.5, y:0.5}
  @State rippleMaskRadius: number = 0.0
  @State rippleMaskWidth: number = 0.0
  @State color: Color = Color.Transparent

  build() {
    Column() {
      RelativeContainer() {
        Image($r("app.media.back")).width("100%").height("100%")
        Stack()
          .width("100%")
          .height("100%")
          .backgroundColor(this.color)
          .backgroundFilter(uiEffect.createFilter()
            .directionLight(
              {x:0, y:0, z:-1}, {red:2.0, green:2.0, blue:2.0, alpha:1.0}, 0.5,
              uiEffect.Mask.createRippleMask(this.rippleMaskCenter, this.rippleMaskRadius, this.rippleMaskWidth, 0.0)
              ))
          .onClick(() => {
            animateTo({duration: 1000}, () => {
              this.rippleMaskWidth = 1.0;
            })
          })
      }
    }.alignItems(HorizontalAlign.Center).borderWidth(2)
  }
}
```

### variableRadiusBlur<sup>20+</sup>
variableRadiusBlur(radius: number, radiusMap: Mask): Filter

为组件内容提供基于[Mask](#mask20)的渐变模糊效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| radius  | number         | 是   | 最大模糊半径，该值越大越模糊。取值范围为[0, 128]。模糊半径设置为0时不模糊；模糊半径设置小于0的值时，按值为0处理；设置大于128的值时，按值为128处理。|
| radiusMap  |  [Mask](#mask20)    | 是   | 代表模糊程度的Mask对象。|

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [Filter](#filter) | 返回当前效果的Filter对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { uiEffect } from "@kit.ArkGraphics2D";

@Entry
@Component
struct VariableRadiusBlurExample {
  @State maskExample: uiEffect.Mask = uiEffect.Mask.createRippleMask({x: 0.5, y: 0.5}, 0.2, 0.1)

  build() {
    Stack() {
      Image($rawfile('test.png'))
      Row()
        .width("100%")
        .height("100%")
        .backgroundFilter(uiEffect.createFilter().variableRadiusBlur(64, this.maskExample))
    }
  }
}
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

### borderLight<sup>20+</sup>
borderLight(lightPosition: common2D.Point3d, lightColor: common2D.Color, lightIntensity: number, borderWidth: number): VisualEffect

为圆角矩形组件边框添加3D光照效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名         | 类型                  | 必填 | 说明                       |
| ------------- | --------------------- | ---- | ------------------------- |
| lightPosition | [common2D.Point3d](js-apis-graphics-common2D.md#point3d12) | 是 | 光源在组件空间的3D位置，[-1, -1, 0]为组件左上角，[1, 1, 0]为组件的右下角，z轴分量越大，光源离组件平面越远，可照射区域越大。<br/> x轴分量取值范围[-10, 10]，y轴分量取值范围[-10, 10]，z轴分量取值范围[0, 10]，超出范围会自动截断。 |
| lightColor | [common2D.Color](js-apis-graphics-common2D.md#color) | 是 | 光源颜色，各元素取值范围为[0, 1]，超出范围会自动截断。 |
| lightIntensity | number | 是 | 光源强度，取值范围[0, 1]，数值越大光源亮度越大，超出范围会自动截断。|
| borderWidth | number | 是 | 组件边框的受光宽度，取值范围为[0.0, 30.0]，超出范围会自动截断。设置为0.0时，组件边框无光照效果，数值越大，光可照亮的区域越宽。 |

**返回值：**

| 类型              | 说明                               |
| ----------------- | --------------------------------- |
| [VisualEffect](#visualeffect) | 返回了具有边框光照效果的VisualEffect。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**
```ts
import { common2D, uiEffect } from '@kit.ArkGraphics2D'

@Entry
@Component
struct Index {
  @State point1:common2D.Point3d = {
    x:0,y:0,z:2
  }
  @State color1:common2D.Color = {
    red:1,green:1,blue:1,alpha:1
  }
  @State lightIntentsity1:number = 1
  @State bordrwidth:number = 20

  build() {
    Column() {
      Stack() {
        Image($r('app.media.man'))
          .width('646px')
          .height('900px')
          .borderRadius(10)
        Column()
          .width('646px')
          .height('900px')
          .borderRadius(10)
          .visualEffect(uiEffect.createEffect().borderLight(this.point1, this.color1, this.lightIntentsity1,
            this.bordrwidth))
      }
      .width('100%')
      .height('55%')
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .backgroundColor('#555')
  }
}
```

## Blender<sup>13+</sup>

type Blender = BrightnessBlender | HdrBrightnessBlender

混合器类型，用于描述混合效果。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [BrightnessBlender](#brightnessblender) | 具有提亮效果的混合器。 |
| [HdrBrightnessBlender](#hdrbrightnessblender20)<sup>20+</sup> | 具有提亮效果的混合器（支持HDR）。 |

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

## HdrBrightnessBlender<sup>20+</sup>
支持HDR的提亮混合器（继承自[BrightnessBlender](#brightnessblender)），用于将提亮效果添加到指定的组件上。在调用HdrBrightnessBlender前，需要先通过[createHdrBrightnessBlender](#uieffectcreatehdrbrightnessblender20)创建一个HdrBrightnessBlender实例。

该混合器参数可参考[BrightnessBlender](#brightnessblender)。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

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
| center | [common2D.Point](js-apis-graphics-common2D.md#point12) | 是 | 设置波环圆心在组件上的位置，[0, 0]为组件左上角，[1, 1]为组件的右下角。<br/>取值范围[-10, 10]，超出边界会在实现时自动截断。 |
| radius | number | 是 | 设置波环的半径，半径为1等于组件的高度。<br/>取值范围[0, 10]，超出边界会在实现时自动截断。 |
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

通过输入的[pixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)pixelMap的待绘制区域、挂载节点的绘制区域和绘制区域外填充的颜色创建具有缩放效果的Mask实例，具体的效果由输入的参数决定。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                      | 必填 | 说明                       |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是   | image模块创建的PixelMap实例。可通过图片解码或直接创建获得，具体可见[图片开发指导](../../media/image/image-overview.md)。   |
| srcRect | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是   | pixelMap的待绘制区域。图片最左侧和最上侧对应位置0，最右侧和最下侧对应位置1。right需大于left，bottom需大于top。 |
| dstRect | [common2D.Rect](js-apis-graphics-common2D.md#rect) | 是   | pixelMap在mask挂载的节点上的绘制区域。节点最左侧和最上侧对应位置0，最右侧和最下侧对应位置1。right需大于left，bottom需大于top。 |
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
import { BusinessError } from '@kit.BasicServicesKit'

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
}).catch((error: BusinessError)=>{
  console.error('Failed to create pixelmap. code is ${error.code}, message is ${error.message}');
})
```
### createRadialGradientMask<sup>20+</sup>
static createRadialGradientMask(center: common2D.Point, radiusX: number, radiusY: number, values: Array<[number, number]>): Mask

通过输入椭圆中心点的位置、长短轴和形状参数创建椭圆遮罩效果[Mask](#mask20)实例，具体的效果由输入的参数决定。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                      | 必填 | 说明                       |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| center | [common2D.Point](js-apis-graphics-common2D.md#point12)  | 是 | 设置椭圆的中心点，[0, 0]为组件左上角，[1, 1]为组件的右下角。<br/>取值范围[-10, 10]，可取浮点数，超出边界会在实现时自动截断。 |
| radiusX | number  | 是 | 设置椭圆的长轴，半径为1等于组件的高度。<br/>取值范围[0, 10]，可取浮点数，超出边界会在实现时自动截断。 |
| radiusY | number  | 是 | 设置椭圆的短轴，半径为1等于组件的高度。<br/>取值范围[0, 10]，可取浮点数，超出边界会在实现时自动截断。 |
| values | Array<[number, number]>     | 是 | 数组中保存的二元数组表示梯度：[RGBA颜色, 位置]。RGBA颜色四通道使用相同的值，可看作一个灰度值；位置表示沿径向方向向外时RGBA颜色对应的分布位置；RGBA颜色与位置的取值范围均为[0, 1]，可取浮点数，小于0的转为0，大于1的转为1。<br/>位置参数值须严格递增，Array数组中二元数组个数必须大于等于2，二元数组中的元素不能为空，否则该椭圆分布效果不生效。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [Mask](#mask20) | 返回椭圆形状的径向分布效果的灰度Mask。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import uiEffect from '@ohos.graphics.uiEffect'
// values: [[1.0, 0.5], [1.0, 1.0]] => color0: 1.0; color1: 1.0; position0: 0.5; position1: 1.0
let mask = uiEffect.Mask.createRadialGradientMask({x: 0.0, y: 0.0}, 0.5, 0.5, [[1.0, 0.5], [1.0, 1.0]]);
@Entry
@Component
struct RadialGradientMaskExample {
  build() {
    Stack() {
      Image('test.jpg')
      Column()
        .width('100%')
        .height('100%')
        // Mask作为Filter的入参实现对应的效果，该效果中Mask是在屏幕左上角的四分之一圆环
        .backgroundFilter(uiEffect.createFilter().edgeLight(1.0, null, mask))
    }
  }
}
```
### createWaveGradientMask<sup>20+</sup>
static createWaveGradientMask(center: common2D.Point, width: number, propagationRadius: number, blurRadius: number, turbulenceStrength?: number): Mask

输入波源中心位置、单波参数创建单波遮罩效果[Mask](#mask20)实例。

**系统能力：** SystemCapability.Graphics.Drawing

**系统接口：** 此接口为系统接口。

**参数：**
| 参数名  | 类型                                      | 必填 | 说明                       |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| center | [common2D.Point](js-apis-graphics-common2D.md#point12)  | 是 | 设置单波波源的中心点，[0, 0]为组件左上角，[1, 1]为组件的右下角。<br/>取值范围[-10, 10]，可取浮点数，超出边界会在实现时自动截断。 |
| width | number  | 是 | 设置单波圆环的宽度。<br/>取值范围[0, 5]，可取浮点数，超出边界会在实现时自动截断。 |
| propagationRadius | number  | 是 | 设置单波圆环的扩散外径。<br/>取值范围[0, 10]，可取浮点数，超出边界会在实现时自动截断。 |
| blurRadius | number  | 是 | 设置单波圆环的模糊外径，模糊半径为0则是实边圆环，否则是虚边圆环。<br/>取值范围[0, 5]，可取浮点数，超出边界会在实现时自动截断。 |
| turbulenceStrength | number  | 否 | 设置单波圆环的湍流强度，默认值为0，强度为0则是规则圆环，否则圆环边缘会湍流扭曲。<br/>取值范围[-1, 1]，可取浮点数，超出边界会在实现时自动截断。 |

**返回值：**

| 类型                          | 说明                                               |
| ----------------------------- | ------------------------------------------------- |
| [Mask](#mask20) | 返回单个水波形状的灰度Mask。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { uiEffect } from "@kit.ArkGraphics2D";
// center: [0.5, 0.5]；width: 0.01; propagationRadius: 0.5; blurRadius: 0.1; turbulenceStrength: 0.1
let mask = uiEffect.Mask.createWaveGradientMask({x: 0.5, y: 0.5}, 0.01, 0.5, 0.1, 0.1);
@Entry
@Component
struct WaveGradientMaskExample {
  build() {
    Stack() {
      Image('test.jpg')
      Column()
        .width('100%')
        .height('100%')
        // 将Mask作为Filter的参数，实现屏幕中心向四周扩散的水波形状效果。
        .backgroundFilter(uiEffect.createFilter().edgeLight(1.0, null, mask))
    }
  }
}
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