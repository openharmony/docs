# @ohos.graphics.uiEffect (Cascading Effect) (System API)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hanamaru-->
<!--Designer: @comicchang-->
<!--Tester: @gcw_fsLqk7gL-->
<!--Adviser: @ge-yafang-->

The uiEffect module provides basic capabilities to apply an effect, for example, blur, pixel stretch, and brightness, to a component. Effects are classified into filters and visual effects. Effects of the same category can be cascaded in an effect instance of the corresponding category. In actual development, the blur effect can be used for background blurring, and the brightness effect can be used for screen-on display.

- [Filter](#filter): applies a filter to a component.
- [VisualEffect](#visualeffect): applies a visual effect to a component.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [ohos.graphics.uiEffect (Cascading Effect)](js-apis-uiEffect.md).

## Modules to Import

```ts
import { uiEffect } from "@kit.ArkGraphics2D";
```
## uiEffect.createBrightnessBlender
createBrightnessBlender(param: BrightnessBlenderParam): BrightnessBlender

Creates a **BrightnessBlender** instance, which can be used to apply the brightness effect to a component.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name | Type                                             | Mandatory| Description                       |
| ------ | ------------------------------------------------- | ---- | --------------------------- |
| param  | [BrightnessBlenderParam](#brightnessblenderparam) | Yes  | Parameters that implement the brightness effect.|

**Return value**

| Type                                    | Description                    |
| ---------------------------------------- | ----------------------- |
| [BrightnessBlender](#brightnessblender) | **BrightnessBlender** instance with the brightness effect.|

**Example**

```ts
let blender : uiEffect.BrightnessBlender =
  uiEffect.createBrightnessBlender({cubicRate:1.0, quadraticRate:1.0, linearRate:1.0, degree:1.0, saturation:1.0,
    positiveCoefficient:[2.3, 4.5, 2.0], negativeCoefficient:[0.5, 2.0, 0.5], fraction:0.0})
```

## uiEffect.createHdrBrightnessBlender<sup>20+</sup>
createHdrBrightnessBlender(param: BrightnessBlenderParam): HdrBrightnessBlender

Creates an [HdrBrightnessBlender](#hdrbrightnessblender20) instance to add the HDR brightness effect to a component.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name | Type                                             | Mandatory| Description                       |
| ------ | ------------------------------------------------- | ---- | --------------------------- |
| param  | [BrightnessBlenderParam](#brightnessblenderparam) | Yes  | Parameters that implement the brightness effect.|

**Return value**

| Type                                    | Description                    |
| ---------------------------------------- | ----------------------- |
| [HdrBrightnessBlender](#hdrbrightnessblender20) | Returns a BrightnessBlender with the brightness effect set (HDR supported).|

**Example**

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
A class that can apply a filter to a component. Before calling any API in **Filter**, you must use [createFilter](js-apis-uiEffect.md#uieffectcreatefilter) to create a **Filter** instance.

### pixelStretch
pixelStretch(stretchSizes: Array\<number\>, tileMode: TileMode): Filter

Applies the pixel stretch effect onto the component.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| stretchSizes  | Array\<number\>         | Yes  | Ratio based on which the pixels grow towards the top, bottom, left, and right edges. The value range is [-1, 1].<br>A positive value indicates outward stretching, and the upper, lower, left, and right edges are filled with edge pixels of the specified original image ratio. A negative value indicates inward stretching, but the image size remains unchanged:<br>The values for the four directions must be all positive or all negative.|
| tileMode      | [TileMode](#tilemode) | Yes  | Pixel tiling mode for pixel stretch.|


**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | **Filter** instance with the pixel stretch effect.|

**Example**

```ts
filter.pixelStretch([0.2, 0.2, 0.2, 0.2], uiEffect.TileMode.CLAMP)
```

### waterRipple
waterRipple(progress: number, waveCount: number, x: number, y: number, rippleMode: WaterRippleMode): Filter

Applies the ripple effect onto the component.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| progress  | number         | Yes  | Progress of the ripple. The value range is [0, 1].<br>The closer the value is to 1, the more fully the ripple effect is displayed.<br>If a value outside this range is provided, no ripple effect will be displayed.|
| waveCount      | number | Yes  | Number of ripples that form when the ripple effect. The value range is [1, 3].<br>The value must be an integer. Ripples will not be displayed if a floating point number or a value outside this range is provided.|
| x      | number | Yes  | X coordinate on the screen that marks the center of the ripple when the ripple effect is initially triggered.<br>The ripples are normalized across the screen, with the coordinates of the upper left corner set to (0, 0) and the upper right corner set to (1, 0).<br>A negative number indicates that the center of the ripple is located to the left of the screen's center.|
| y      | number | Yes  | Y coordinate on the screen that marks the center of the ripple when the ripple effect is initially triggered.<br>The ripples are normalized across the screen, with the coordinates of the upper left corner set to (0, 0) and the lower left corner set to (0, 1).<br>A negative number indicates that the center of the ripple is located above the screen's center.|
| rippleMode      | [WaterRippleMode](#waterripplemode) | Yes  | Scene mode of the ripple effect.|


**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | **Filter** instance with the ripple effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202  | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
filter.waterRipple(0.5, 2, 0.5, 0.5, uiEffect.WaterRippleMode.SMALL2SMALL)
```

### flyInFlyOutEffect
flyInFlyOutEffect(degree: number, flyMode: FlyMode): Filter

Applies fly-in and fly-out animations onto the component.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| degree  | number         | Yes  | Degree of control over deformation of the fly-in and fly-out animations. The value range is [0, 1].<br>A value closer to 1 results in more obvious deformation.<br>If a value outside this range is provided, no fly-in and fly-out animations will be displayed.|
| flyMode      | [FlyMode](#flymode) | Yes  | Scene mode of the fly-in and fly-out animations.<br>**BOTTOM** means that the fly-in and fly-out animations occur from the bottom of the screen,<br>and **TOP** means that the fly-in and fly-out animations occur from the top of the screen.|


**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | **Filter** instance with the fly-in and fly-out animations.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202  | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
filter.flyInFlyOutEffect(0.5, uiEffect.FlyMode.TOP)
```

### distort<sup>13+</sup>
distort(distortionK: number): Filter

Applies the lens distortion effect onto the component.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| distortionK  | number         | Yes  | Distortion coefficient, indicating the degree of lens distortion. The value range is [-1, 1]. A value less than -1 evaluates to the value **-1**. A value greater than 1 evaluates to the value **1**.|

![image_Add_Distort.png](./figures/image_Add_Distort.png)
The preceding figure shows the rendering results when different distortion coefficients (-1, 0, 0.5, and 1) are applied onto an **Image** component. A negative distortion value results in a barrel distortion, whereas a positive value results in a pincushion distortion. As the distortion value approaches 0, the intensity of the distortion decreases, and at exactly 0, there is no distortion effect.

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | **Filter** instance with lens distortion effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
filter.distort(-0.5)
```


### radiusGradientBlur<sup>19+</sup>
radiusGradientBlur(value: number, options: LinearGradientBlurOptions): Filter

Adds a radius linear gradient blur effect to the component content.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| value  | number         | Yes  | Blur radius. A larger value indicates a blurrier effect. The value ranges from 0 to 128. If the blur radius is set to 0, the blur effect is not applied. If the blur radius is set to a value less than 0, the value 0 is used. If the blur radius is set to a value greater than 128, the value 128 is used.|
| options  | [LinearGradientBlurOptions](../apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#lineargradientbluroptions12)        | Yes  | Linear gradient parameters, which include fractionStops and direction.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter with the radius linear gradient blur effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Adds the Bezier curve deformation effect to a component. This effect is implemented by creating a closed Bezier curve on the layer boundary to accurately distort and adjust the shape of an image. A Bezier curve consists of four segments that are connected in sequence. Each segment contains one vertex and two tangents.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| controlPoints  | Array<[common2D.Point](js-apis-graphics-common2D.md#point12)>| Yes  | 12 Bezier deformation control points. The shape of the curve formed on the edge can be changed by changing the position of the control points to distort the image. The control point coordinates are in the 0-1 coordinate system, and the coordinate values can be greater than 1 or less than 0.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter with the Bezier curve deformation effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Adds a color gradient effect to the component content.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| colors  | Array\<[Color](#color20)>         | Yes  | Color array, which is used to specify the gradient of multiple colors. The array length ranges from 0 to 12. Each color value must be greater than or equal to 0. If the array length is 0 or greater than 12, the effect is not displayed. If the array lengths of colors, positions, and strengths are different, the effect is not displayed.|
| positions  | Array\<[common2D.Point](js-apis-graphics-common2D.md#point12)>         | Yes  | Position array, which indicates the distribution position corresponding to the color. The array length ranges from 0 to 12. If the array length is 0 or greater than 12, the effect is not displayed. If the array lengths of colors, positions, and strengths are different, the effect is not displayed.|
| strengths  | Array\<number>         | Yes  | Strength array, which indicates the diffusion strength corresponding to the color. The array length ranges from 0 to 12. The strength value ranges from 0 to a positive number. If the array length is 0 or greater than 12, the effect is not displayed. If the array lengths of colors, positions, and strengths are different, the effect is not displayed.|
| alphaMask  | [Mask](#mask20)         | No  | Mask alpha, which indicates the alpha display mask corresponding to the color. If this parameter is not set, all component content has the color gradient effect by default.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter with the color gradient effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Adds a 3D lighting effect to the component content.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| lightPosition | [common2D.Point3d](js-apis-graphics-common2D.md#point3d12) | Yes| Position of the light source in the component space. [-1, -1, 0] indicates the upper left corner of the component, and [1, 1, 0] indicates the lower right corner of the component. The larger the z-axis component, the farther the light source is from the component plane and the larger the illumination area.<br> The value range of the x component is [–10, 10], the value range of the y component is [–10, 10], and the value range of the z component is [0, 10]. If the value is out of the range, the value will be automatically truncated.|
| lightColor | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes| Light source color. The value range of each element is [0, 1]. If the value is out of the range, the value will be automatically truncated.|
| lightIntensity | number | Yes| Light source strength. The value range is [0, 1]. A larger value indicates a brighter light source. If the value is out of the range, the value will be automatically truncated.|
| displacementMap | [Mask](#mask20) | No| This parameter does not take effect currently.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [filter](#filter) | Filter with the content lighting effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Detects the edge of the component content and adds an edge highlight effect.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| alpha  | number         | Yes  | Specifies the stroke highlight transparency. A larger value indicates a more obvious stroke. The value ranges from 0 to 1. If this parameter is set to 0, no stroke is displayed. If this parameter is set to a value less than 0, the value 0 is used. If this parameter is set to a value greater than 1, the value 1 is used.|
| color  | [Color](#color20) | No  | Highlighting color of the stroke. If this parameter is not set, the original color of the component content is used by default. If this parameter is set, the specified color is used. If this parameter is set to a value other than null, the alpha value in Color does not take effect, and only the RGB value takes effect.|
| mask  | [Mask](#mask20) | No  | Stroke highlighting strength. If this parameter is not set, all component content has the stroke highlighting effect by default.|
| bloom  | boolean | No  | Whether the stroke glows. If this parameter is set to true, the stroke and glow effects are displayed. If this parameter is set to false, only the stroke effect is displayed. If this parameter is not set, the default value true is used. For images smaller than 16 x 16, only the stroke effect is displayed by default, and the glow effect is not displayed. In this case, this parameter does not take effect.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter with the stroke highlighting effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Adds a distortion effect to the component content.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| mask  | [Mask](#mask20) | Yes  | Distortion degree. The distortion degree is determined by the product of this parameter and factor.|
| factor  | [number, number] | No  | Horizontal and vertical distortion degree coefficients. A larger absolute value indicates a more obvious distortion degree. The recommended value range is [–10.0, 10.0]. If this parameter is not set, the default value 1.0 is used. If this parameter is set to 0, no distortion effect is applied. The distortion degree is determined by the product of this parameter and mask.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter with the distortion effect applied.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Adds a dispersion effect that is controlled by a displacement map to the component content.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| dispersionMask  | [Mask](#mask20)         | Yes  | Displacement map, which is used to control the dispersion strength, direction, and transparency. You are advised to use the displacement map of the PixelMapMask type.|
| alpha  | number         | Yes  | Overall transparency of dispersion. The smaller the transparency, the more transparent the effect. The value range is [0, 1.0]. When the transparency is set to 0, the dispersion effect does not take effect. When the transparency is set to a value less than 0, the value 0 is used. When the transparency is set to a value greater than 1.0, the value 1.0 is used.|
| rFactor  | [number, number]         | No  | Basic dispersion offset of the R channel in the X/Y direction. The larger the offset, the more obvious the red dispersion effect. The value range in each direction is [-1.0, 1.0]. When the offset is set to a value less than -1.0, the value -1.0 is used. When the offset is set to a value greater than 1.0, the value 1.0 is used.|
| gFactor  | [number, number]         | No  | Basic dispersion offset of the G channel in the X/Y direction. The larger the offset, the more obvious the green dispersion effect. The value range is the same as that of rFactor.|
| bFactor  | [number, number]         | No  | Basic dispersion offset of the B channel in the X/Y direction. The larger the offset, the more obvious the blue dispersion effect. The value range is the same as that of rFactor.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter for which the dispersion effect controlled by the displacement map is mounted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Adds the high dynamic range (HDR) effect to the component content. Nested use is not recommended. If it is forcibly used, overexposure may occur.

The HDR effect takes effect only when the HDR rendering pipeline is enabled. In some scenarios, HDR cannot be enabled even if the HDR rendering pipeline is triggered. For example, the device hardware specifications do not support HDR.

The maximum brightening multiple supported by the device is the value obtained by dividing the maximum brightness of the device by the SDR reference white brightness of the device.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| ratio  | number         | Yes  | Brightening multiple. The value ranges from 1.0 to the maximum brightening multiple supported by the device. If the value is less than 1.0, the value 1.0 is used. If the value is equal to 1.0, no processing is performed. If the value is greater than 1.0, the HDR rendering pipeline is triggered. If the value is greater than the maximum brightening multiple supported by the device, the maximum brightening multiple supported by the device is used.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter with the HDR effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
filter.hdrBrightnessRatio(2.0)
```

### maskTransition<sup>20+</sup>
maskTransition(alphaMask: Mask, factor?: number, inverse?: boolean): Filter

Provides a transition effect based on [Mask](#mask20) for the component content.

You are not advised to use this effect when the screen size changes, for example, rotating the screen or opening and closing the foldable screen.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| alphaMask     | [Mask](#mask20)       | Yes  | Transition effect area specified by the mask.|
| factor        | number                | No  | Transition coefficient. The value ranges from 0.0 to 1.0. The default value is 1.0. A larger value of factor indicates that the image is closer to the transition page. If the value is out of the range, the value is automatically truncated to [0.0, 1.0].|
| inverse       | boolean               | No  | Whether to enable reverse transition. The value true indicates that reverse transition is enabled, and the value false indicates that reverse transition is disabled. The default value is false.|
 
**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter that mounts the transition effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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
      // Page before transition
      Image($r("app.media.before")).width("100%").height("100%")
        if (this.enterNewPage){
          // Page after transition
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

Provides lighting effects for components based on [Mask](#mask20) and parallel light.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| direction  | [common2D.Point3d](js-apis-graphics-common2D.md#point3d12)         | Yes  | Direction of the directional light.|
| color  | [Color](#color20)         | Yes  | Light color.|
| intensity  | number         | Yes  | Light intensity. The value must be a non-negative number.|
| mask  | [Mask](#mask20)         | No  | Displacement map, which is used to describe the three-dimensional details of a two-dimensional image surface. The normal map or height map is used to enhance the local details and lighting reflection effect. If the input is a height map, this parameter must be used together with factor. By default, this parameter is left empty, and the lighting effect of a plane without details is displayed globally.|
| factor  | number         | No  | Sampling scaling coefficient. The default value is null, indicating that the mask is used as the normal map for sampling. If the value is not null, the mask is used as the height map for sampling. The actual height value is the product of the sampling value of the mask and factor.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter that mounts the lighting effect controlled by the displacement map.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Provides a gradient blur effect for component content based on the [Mask](#mask20) object.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| radius  | number         | Yes  | Maximum blur radius. A larger value indicates a higher blur degree. The value ranges from 0 to 128. If the blur radius is set to 0, the blur effect is not applied. If the blur radius is set to a value less than 0, the blur radius is considered as 0. If the blur radius is set to a value greater than 128, the blur radius is considered as 128.|
| radiusMap  |  [Mask](#mask20)    | Yes  | Mask object that indicates the blur degree.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [Filter](#filter) | Filter object of the current effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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
Enumerates the pixel tiling modes.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

| Name  | Value| Description|
| ------ | - | ---- |
| CLAMP  | 0 | Clamp.|
| REPEAT | 1 | Repeat.|
| MIRROR | 2 | Mirror.|
| DECAL  | 3 | Decal.|

## WaterRippleMode
Enumerates the scene modes of the ripple effect.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

| Name  | Value| Description|
| ------ | - | ---- |
| SMALL2MEDIUM_RECV  | 0 | A phone taps against a 2-in-1 device (receiver).|
| SMALL2MEDIUM_SEND  | 1 | A phone taps against a 2-in-1 device (sender).|
| SMALL2SMALL | 2 | A phone taps against another phone.|
| MINI_RECV<sup>17+</sup> | 3 | 2in1 device sharing with other devices (keyboard and mouse sharing).|

## FlyMode
Enumerates the scene modes of fly-in and fly-out animations.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

| Name  | Value| Description|
| ------ | - | ---- |
| BOTTOM  | 0 | Fly-in and fly-out animations occur from the bottom of the screen.|
| TOP  | 1 | Fly-in and fly-out animations occur from the top of the screen.|

## VisualEffect
A class that can apply a visual effect to a component. Before calling any API in **VisualEffect**, you must use [createEffect](js-apis-uiEffect.md#uieffectcreateeffect) to create a **VisualEffect** instance.

### backgroundColorBlender
backgroundColorBlender(blender: BrightnessBlender): VisualEffect

Applies a blender to the component to change the background color of the component. The change effect is determined by the input. Currently, only the brightness blender is supported.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name | Type                                     | Mandatory| Description                      |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| blender | [BrightnessBlender](#brightnessblender) | Yes  | Blender used to change the background color.|

**Return value**

| Type                         | Description                                              |
| ----------------------------- | ------------------------------------------------- |
| [VisualEffect](#visualeffect) | **VisualEffect** instance with the background color change effect.|

**Example**

```ts
let blender : uiEffect.BrightnessBlender =
  uiEffect.createBrightnessBlender({cubicRate:1.0, quadraticRate:1.0, linearRate:1.0, degree:1.0, saturation:1.0,
    positiveCoefficient:[2.3, 4.5, 2.0], negativeCoefficient:[0.5, 2.0, 0.5], fraction:0.0})
visualEffect.backgroundColorBlender(blender)
```

### borderLight<sup>20+</sup>
borderLight(lightPosition: common2D.Point3d, lightColor: common2D.Color, lightIntensity: number, borderWidth: number): VisualEffect

Adds a 3D lighting effect to the border of a rounded rectangle component.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| lightPosition | [common2D.Point3d](js-apis-graphics-common2D.md#point3d12) | Yes| 3D position of the light source in the component space. [-1, -1, 0] indicates the upper left corner of the component, and [1, 1, 0] indicates the lower right corner of the component. A larger z-axis component indicates that the light source is farther away from the component plane and the illuminated area is larger.<br> The value range of the x-axis component is [–10, 10], the value range of the y-axis component is [–10, 10], and the value range of the z-axis component is [0, 10]. If the value is out of the range, the value will be automatically truncated.|
| lightColor | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes| Light source color. The value range of each element is [0, 1]. If the value is out of the range, the value will be automatically truncated.|
| lightIntensity | number | Yes| Light source strength. The value range is [0, 1]. A larger value indicates a brighter light source. If the value is out of the range, the value will be automatically truncated.|
| borderWidth | number | Yes| Lighting width of the component border. The value range is [0.0, 30.0]. If the value is out of the range, the value will be automatically truncated. If this parameter is set to 0.0, the component border is not illuminated. A larger value indicates a wider illuminated area.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [VisualEffect](#visualeffect) | VisualEffect object that has the border lighting effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
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

### colorGradient<sup>20+</sup>
colorGradient(colors: Array\<Color>, positions: Array\<common2D.Point>, strengths: Array\<number>, alphaMask?: Mask): VisualEffect

Adds a color gradient effect to a component.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name        | Type                 | Mandatory| Description                      |
| ------------- | --------------------- | ---- | ------------------------- |
| colors  | Array\<[Color](#color20)>         | Yes  | Color array, which is used to implement multi-color gradient. The array length ranges from 0 to 12. Each color value is greater than or equal to 0. If the array length is 0 or greater than 12, or the lengths of the colors, positions, and strengths arrays are inconsistent, no color gradient effect is displayed.|
| positions  | Array\<[common2D.Point](js-apis-graphics-common2D.md#point12)>         | Yes  | Position array, which indicates the position corresponding to the color. The array length ranges from 0 to 12. If the array length is 0 or greater than 12, or the lengths of the colors, positions, and strengths arrays are inconsistent, no color gradient effect is displayed.|
| strengths  | Array\<number>         | Yes  | Strength array, which indicates the strength corresponding to the color. The array length ranges from 0 to 12. Each strength value is greater than or equal to 0. If the array length is 0 or greater than 12, or the lengths of the colors, positions, and strengths arrays are inconsistent, no color gradient effect is displayed.|
| alphaMask  | [Mask](#mask20)         | No  | Alpha mask of the color. If this parameter is not set, the transparency of the color gradient effect is determined only by the colors parameter.|

**Return value**

| Type             | Description                              |
| ----------------- | --------------------------------- |
| [VisualEffect](#visualeffect) | Visual effect with the color gradient effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**
```ts
import { common2D, uiEffect } from "@kit.ArkGraphics2D"

@Entry
@Component
struct ColorGradientExample {
  build() {
    Stack() {
      Stack() {}
      .visualEffect(uiEffect.createEffect()
        .colorGradient(
          [
            {red: 1.0, green: 0.0, blue: 0.0, alpha: 1.0},
            {red: 0.0, green: 1.0, blue: 0.0, alpha: 1.0},
            {red: 0.0, green: 0.0, blue: 1.0, alpha: 1.0},
            {red: 1.0, green: 1.0, blue: 1.0, alpha: 1.0},
          ],
          [
            {x: 0.1, y: 0.1},
            {x: 0.1, y: 0.9},
            {x: 0.9, y: 0.1},
            {x: 0.9, y: 0.9},
          ],
          [12.4, 7.8, 7.8, 10.0],
          uiEffect.Mask.createRippleMask({x: 0.5, y: 0.5}, 0.2, 0.1)
        )
      )
      .width("1024px")
      .height("1024px")
    }
    .width("100%")
    .height("100%")
  }
}
```

## Blender<sup>13+</sup>

type Blender = BrightnessBlender | HdrBrightnessBlender

Defines the blender type, which is used to describe blending effects.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

| Type                         | Description                                              |
| ----------------------------- | ------------------------------------------------- |
| [BrightnessBlender](#brightnessblender) | Blender with a brightening effect.|
| [HdrBrightnessBlender](#hdrbrightnessblender20)<sup>20+</sup> | A brightness blender (HDR supported).|

## BrightnessBlender
A blender that can apply the brightness effect to a component. Before calling any API in **BrightnessBlender**, you must use [createBrightnessBlender](#uieffectcreatebrightnessblender) to create a **BrightnessBlender** instance.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

| Name               | Type                       | Read Only| Optional| Description                                                             |
| ------------------- | -------------------------- | ---- | ---- | ---------------------------------------------------------------- |
| cubicRate           | number                     | No  | No  | Third-order coefficient for grayscale adjustment.<br>The value range is [-20, 20].                       |
| quadraticRate       | number                     | No  | No  | Second-order coefficient for grayscale adjustment.<br>The value range is [-20, 20].                       |
| linearRate          | number                     | No  | No  | Linear coefficient for grayscale adjustment.<br>The value range is [-20, 20].                       |
| degree              | number                     | No  | No  | Grayscale adjustment ratio.<br>The value range is [-20, 20].                           |
| saturation          | number                     | No  | No  | Reference saturation for the brightness effect.<br>The value range is [0, 20].                           |
| positiveCoefficient | [number, number, number]   | No  | No  | RGB positive adjustment parameter based on the reference saturation.<br>The value range of each number is [-20, 20].|
| negativeCoefficient | [number, number, number]   | No  | No  | RGB negative adjustment parameter based on the reference saturation.<br>The value range of each number is [-20, 20].|
| fraction            | number                     | No  | No  | Blending ratio of the brightness effect.<br>The value range is [0, 1]. A value beyond the boundary will be automatically truncated during implementation. |

## HdrBrightnessBlender<sup>20+</sup>
HDR brightness blender (inherited from [BrightnessBlender](#brightnessblender)), which is used to add the brightness effect to a specified component. Before calling HdrBrightnessBlender, you need to create an HdrBrightnessBlender instance by calling [createHdrBrightnessBlender](#uieffectcreatehdrbrightnessblender20).

For details about the parameters of this blender, please refer to [BrightnessBlender](#brightnessblender).

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

## Color<sup>20+</sup>

RGBA color description.

**System capability**: SystemCapability.Graphics.Drawing

| Name | Type  | Read Only| Optional| Description                                    |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| red   | number | Yes  | Yes  | R component (red) of the color. The value must be greater than or equal to 0. If the value is less than 0, the value is invalid.|
| green | number | Yes  | Yes  | G component (green) of the color. The value must be greater than or equal to 0. If the value is less than 0, the value is invalid.|
| blue  | number | Yes  | Yes  | B component (blue) of the color. The value must be greater than or equal to 0. If the value is less than 0, the value is invalid.|
| alpha | number | Yes  | Yes  | A component (transparency) of the color. The value must be greater than or equal to 0. If the value is less than 0, the value is invalid.|

## Mask<sup>20+</sup>
Mask effect class, which is used as the input of [Filter](#filter) and [VisualEffect](#visualeffect).

### createRippleMask<sup>20+</sup>
static createRippleMask(center: common2D.Point, radius: number, width: number, offset?: number): Mask

Create a mask instance by setting the position, radius, and width of the center of the wave ring. The effect depends on the input parameters.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name | Type                                     | Mandatory| Description                      |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| center | [common2D.Point](js-apis-graphics-common2D.md#point12) | Yes| Sets the position of the wave ring center on the component. [0, 0] indicates the upper left corner of the component, and [1, 1] indicates the lower right corner of the component.<br>The value range is [–10, 10]. If the value is out of the range, the value will be automatically truncated during implementation.|
| radius | number | Yes| Sets the radius of the wave ring. If the radius is 1, the radius is equal to the height of the component.<br>The value range is [0, 10]. If the value is out of the range, the value will be automatically truncated during implementation.|
| width | number | Yes| Sets the width of the wave ring.<br>The value range is [0, 10]. If the value is out of the range, the value will be automatically truncated during implementation.|
| offset | number | No| Sets the offset of the wave peak position.<br>The default value is 0, indicating that the wave peak is at the center of the wave ring.<br>The value –1.0 indicates that the wave peak is at the innermost of the wave ring.<br>The value 1.0 indicates that the wave peak is at the outermost of the wave ring.<br>The value range is [–1, 1]. If the value is out of the range, the value will be automatically truncated during implementation.|

**Return value**

| Type                         | Description                                              |
| ----------------------------- | ------------------------------------------------- |
| [Mask](#mask20) | Returns a mask with the wave ring mask effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
  let mask = uiEffect.Mask.createRippleMask({x:0.5, y:1.0}, 0.5, 0.3, 0.0);
```

### createPixelMapMask<sup>20+</sup>
static createPixelMapMask(pixelMap: image.PixelMap, srcRect: common2D.Rect, dstRect: common2D.Rect, fillColor?: Color): Mask

Creates a mask instance with the scaling effect by using the drawing area of the input [pixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)pixelMap, drawing area of the mount node, and color of the area outside the drawing area. The effect is determined by the input parameters.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name | Type                                     | Mandatory| Description                      |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes  | **PixelMap** instance created by the image module. An instance can be obtained by decoding an image or directly created. For details, see [Image Overview](../../media/image/image-overview.md).  |
| srcRect | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Area to be drawn on the pixelMap. The leftmost and topmost positions of the image correspond to position 0, and the rightmost and bottommost positions correspond to position 1. right must be greater than left, and bottom must be greater than top.|
| dstRect | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Drawing area of the pixelMap on the node to which the mask is mounted. The leftmost and topmost positions of the node correspond to position 0, and the rightmost and bottommost positions correspond to position 1. right must be greater than left, and bottom must be greater than top.|
| fillColor | [Color](#color20) | No  |  Color of the area outside the drawing area of the pixelMap on the node. The value range of each element is [0, 1]. The default value is transparent. If the value is less than 0, the value is changed to 0. If the value is greater than 1, the value is changed to 1.|

**Return value**

| Type                         | Description                                              |
| ----------------------------- | ------------------------------------------------- |
| [Mask](#mask20) | Mask with the pixelMap scaling effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Creates an ellipse mask effect [Mask](#mask20) instance by specifying the center point, major and minor axes, and shape parameters of the ellipse. The effect is determined by the input parameters.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name | Type                                     | Mandatory| Description                      |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| center | [common2D.Point](js-apis-graphics-common2D.md#point12)  | Yes| Center point of the ellipse. [0, 0] indicates the upper left corner of the component, and [1, 1] indicates the lower right corner of the component.<br>The value range is [–10, 10]. The value can be a floating point number. If the value is out of the range, it will be automatically truncated during implementation.|
| radiusX | number  | Yes| Sets the major axis of an ellipse. The radius of 1 is equal to the height of the component.<br>The value range is [0, 10]. The value can be a floating point number. If the value is out of the range, it will be automatically truncated during implementation.|
| radiusY | number  | Yes| Sets the minor axis of an ellipse. The radius of 1 is equal to the height of the component.<br>The value range is [0, 10]. The value can be a floating point number. If the value is out of the range, it will be automatically truncated during implementation.|
| values | Array<[number, number]>     | Yes| A binary array stored in the array indicates the gradient: [RGBA color, position]. The four channels of the RGBA color use the same value, which can be considered as a grayscale value. The position indicates the distribution position of the RGBA color when the position is outward along the radial direction. The value range of the RGBA color and position is [0, 1]. The value can be a floating point number. If the value is less than 0, the value is changed to 0. If the value is greater than 1, the value is changed to 1.<br>The position parameter values must be strictly increasing. The number of binary arrays in the array must be greater than or equal to 2. The elements in the binary array cannot be empty. Otherwise, the ellipse distribution effect does not take effect.|

**Return value**

| Type                         | Description                                              |
| ----------------------------- | ------------------------------------------------- |
| [Mask](#mask20) | Returns the grayscale mask of the radial distribution effect of the ellipse.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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
        // The mask is used as the input parameter of the filter to implement the corresponding effect. The mask is a quarter circle ring in the upper left corner of the screen.
        .backgroundFilter(uiEffect.createFilter().edgeLight(1.0, null, mask))
    }
  }
}
```
### createWaveGradientMask<sup>20+</sup>
static createWaveGradientMask(center: common2D.Point, width: number, propagationRadius: number, blurRadius: number, turbulenceStrength?: number): Mask

Creates a single wave mask effect instance [Mask](#mask20) by specifying the center position of the wave source and single wave parameters.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

**Parameters**
| Name | Type                                     | Mandatory| Description                      |
| ------- | ---------------------------------------- | ---- | ------------------------- |
| center | [common2D.Point](js-apis-graphics-common2D.md#point12)  | Yes| Center point of the single wave source. [0, 0] indicates the upper left corner of the component, and [1, 1] indicates the lower right corner of the component.<br>The value range is [–10, 10]. The value can be a floating point number. If the value is out of the range, it will be automatically truncated during implementation.|
| width | number  | Yes| Width of the single wave ring.<br>The value range is [0, 5]. The value can be a floating point number. If the value is out of the range, it will be automatically truncated during implementation.|
| propagationRadius | number  | Yes| Outer diameter of the single wave ring.<br>The value range is [0, 10]. The value can be a floating point number. If the value is out of the range, it will be automatically truncated during implementation.|
| blurRadius | number  | Yes| Blur outer diameter of the single wave ring. If the blur radius is 0, the ring is a solid ring. Otherwise, the ring is a hollow ring.<br>The value range is [0, 5]. The value can be a floating point number. If the value is out of the range, it will be automatically truncated during implementation.|
| turbulenceStrength | number  | No| Turbulence intensity of the single wave ring. The default value is 0. If the intensity is 0, the ring is a regular ring. Otherwise, the ring edge is distorted due to turbulence.<br>The value range is [–1, 1]. The value can be a floating point number. If the value is out of the range, it will be automatically truncated during implementation.|

**Return value**

| Type                         | Description                                              |
| ----------------------------- | ------------------------------------------------- |
| [Mask](#mask20) | Grayscale mask of a single wave shape.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { uiEffect } from "@kit.ArkGraphics2D";
// center: [0.5, 0.5]; width: 0.01; propagationRadius: 0.5; blurRadius: 0.1; turbulenceStrength: 0.1
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
        // Use the mask as the filter parameter to implement the ripple effect that spreads from the center of the screen to the periphery.
        .backgroundFilter(uiEffect.createFilter().edgeLight(1.0, null, mask))
    }
  }
}
```
## BrightnessBlenderParam
Describes the parameters used for the brightness blender.

**System capability**: SystemCapability.Graphics.Drawing

**System API**: This is a system API.

| Name               | Type                       | Read Only| Optional| Description                                                             |
| ------------------- | -------------------------- | ---- | ---- | ---------------------------------------------------------------- |
| cubicRate           | number                     | No  | No  | Third-order coefficient for grayscale adjustment.<br>The value range is [-20, 20].                       |
| quadraticRate       | number                     | No  | No  | Second-order coefficient for grayscale adjustment.<br>The value range is [-20, 20].                       |
| linearRate          | number                     | No  | No  | Linear coefficient for grayscale adjustment.<br>The value range is [-20, 20].                       |
| degree              | number                     | No  | No  | Grayscale adjustment ratio.<br>The value range is [-20, 20].                           |
| saturation          | number                     | No  | No  | Reference saturation for the brightness effect.<br>The value range is [0, 20].                           |
| positiveCoefficient | [number, number, number]   | No  | No  | RGB positive adjustment parameter based on the reference saturation.<br>The value range of each number is [-20, 20].|
| negativeCoefficient | [number, number, number]   | No  | No  | RGB negative adjustment parameter based on the reference saturation.<br>The value range of each number is [-20, 20].|
| fraction            | number                     | No  | No  | Blending ratio of the brightness effect.<br>The value range is [0, 1]. A value beyond the boundary will be automatically truncated during implementation. |
